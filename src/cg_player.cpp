#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y, text_handler& texthandler) :
    _pile_display_hand(position, true),
    _pile_display_safety(position + bn::fixed_point(16, playfield_offset_y)),
    _card_display_roll(position + bn::fixed_point(-32, playfield_offset_y)),
    _card_display_speed(position + bn::fixed_point(-16, playfield_offset_y)),
    _playfield_offset_y(playfield_offset_y)
{
    _update_milage_text(texthandler);
}

void player::_update_milage_text(text_handler& texthandler)
{
    _text_milage_sprites.clear();
    bn::fixed_point text_position = position() + bn::fixed_point(32, _playfield_offset_y);
    texthandler.generate(text_position, bn::to_string<5>(_milage) + "M", _text_milage_sprites, bn::sprite_text_generator::alignment_type::RIGHT);
}

bool player::_handle_play_milage_card(int milage)
{
    // check roll card
    if (_card_display_roll.get_card_type() != card_type::RemedyGo)
        return false;
    // check over milage limit
    if (_milage + milage <= MilageLimit)
    {
        _milage += milage;
        return true;
    }
    return false;
}

bool player::_handle_play_selected_card()
{
    card_type cardtype = get_hand_display().get_card_type(_card_index);
    switch (cardtype)
    {
        // milage cards
        case card_type::Milage25:  return _handle_play_milage_card( 25);
        case card_type::Milage50:  return _handle_play_milage_card( 50);
        case card_type::Milage75:  return _handle_play_milage_card( 75);
        case card_type::Milage100: return _handle_play_milage_card(100);
        case card_type::Milage200: return _handle_play_milage_card(200);
        // hazard cards
        case card_type::HazardStop:       { /* TODO HazardStop       */ } break;
        case card_type::HazardSpeedLimit: { /* TODO HazardSpeedLimit */ } break;
        case card_type::HazardOutOfGas:   { /* TODO HazardOutOfGas   */ } break;
        case card_type::HazardFlatTire:   { /* TODO HazardFlatTire   */ } break;
        case card_type::HazardAccident:   { /* TODO HazardAccident   */ } break;
        // remedy cards
        case card_type::RemedyGo: {
            if (_card_display_roll.get_card_type() == card_type::RemedyGo)
                return false;
            _card_display_roll.update_card_type(cardtype);
            return true;
        } break;
        case card_type::RemedyEndOfLimit: { /* TODO RemedyEndOfLimit */ } break;
        case card_type::RemedyGasoline:   { /* TODO RemedyGasoline   */ } break;
        case card_type::RemedySpareTire:  { /* TODO RemedySpareTire  */ } break;
        case card_type::RemedyRepairs:    { /* TODO RemedyRepairs    */ } break;
        // safety cards
        case card_type::SafetyRightOfWay:    { /* TODO SafetyRightOfWay    */ } break;
        case card_type::SafetyExtraTank:     { /* TODO SafetyExtraTank     */ } break;
        case card_type::SafetyPunctureProof: { /* TODO SafetyPunctureProof */ } break;
        case card_type::SafetyDrivingAce:    { /* TODO SafetyDrivingAce    */ } break;

        default: return false;
    }
    return false;
}

void player::_play_selected_card()
{
    // check if card is able to be played
    if (!_handle_play_selected_card())
        return;
    // remove card from hand and update sprites
    get_hand_display().remove_card_type(_card_index);
    get_hand_display().update_sprites();
    // update turn status
    _turn_done = true;
}

void player::_discard_selected_card(card_pile<CardPileMax>& discard_pile)
{
    card_type cardtype = get_hand_display().get_card_type(_card_index);
    get_hand_display().remove_card_type(_card_index);
    get_hand_display().update_sprites();
    discard_pile.add_card_type(cardtype);
    _turn_done = true;
}

bn::fixed_point player::position()
{
    return get_hand_display().get_position();
}

card_pile_display<CardPileHandMax>& player::get_hand_display()
{
    return _pile_display_hand;
}

bool player::is_turn_done()
{
    return _turn_done;
}

void player::update(bn::random&, card_pile<CardPileMax>&)
{
}

void player::start_turn()
{
}

void player::end_turn(text_handler& texthandler)
{
    _update_milage_text(texthandler);
    _turn_done = false;
}
