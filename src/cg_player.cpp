#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y, text_handler& texthandler) :
    _pile_display_hand(position, true),
    _pile_display_safety(position + bn::fixed_point(16, _playfield_offset_y)),
    _card_display_roll(position + bn::fixed_point(-32, _playfield_offset_y)),
    _card_display_speed(position + bn::fixed_point(-16, _playfield_offset_y)),
    _playfield_offset_y(playfield_offset_y)
{
    _update_milage_text(texthandler);
}

void player::_update_milage_text(text_handler& texthandler)
{
    _text_milage_sprites.clear();
    bn::fixed_point text_position = position() + bn::fixed_point(32, _playfield_offset_y);
    texthandler.generate(text_position, bn::to_string<5>(_milage) + "M", _text_milage_sprites, bn::sprite_text_generator::alignment_type::RIGHT); // TODO make sure string size is correct
}

bool player::_handle_play_milage_card(int milage)
{
    if (_milage + milage <= 1000)
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
        // hazard cards // TODO handle playing hazard cards
        case card_type::HazardStop: {} break;
        case card_type::HazardSpeedLimit: {} break;
        case card_type::HazardOutOfGas: {} break;
        case card_type::HazardFlatTire: {} break;
        case card_type::HazardAccident: {} break;
        // remedy cards // TODO handle playing remedy cards
        case card_type::RemedyGo: {} break;
        case card_type::RemedyEndOfLimit: {} break;
        case card_type::RemedyGasoline: {} break;
        case card_type::RemedySpareTire: {} break;
        case card_type::RemedyRepairs: {} break;
        // safety cards // TODO handle playing safety cards
        case card_type::SafetyRightOfWay: {} break;
        case card_type::SafetyExtraTank: {} break;
        case card_type::SafetyPunctureProof: {} break;
        case card_type::SafetyDrivingAce: {} break;

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
