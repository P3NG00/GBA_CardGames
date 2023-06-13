#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y, text_handler& texthandler, bool hidden) :
    _pile_display_hand(position, true, hidden),
    _pile_display_safety(position + bn::fixed_point(16, playfield_offset_y), false, false),
    _card_display_roll(position + bn::fixed_point(-32, playfield_offset_y)),
    _card_display_speed(position + bn::fixed_point(-16, playfield_offset_y)),
    _playfield_offset_y(playfield_offset_y)
{
    _update_milage_text(texthandler);
}

bool player::_handle_play_milage_card(int milage)
{
    // TODO check safeties
    // check speed limit
    if (_card_display_speed.get_card_type() == card_type::HazardSpeedLimit && milage > 50)
        return false;
    // check roll card
    if (_card_display_roll.get_card_type() != card_type::RemedyGo)
        return false;
    // check over milage limit
    if (_milage + milage > MilageLimit)
        return false;
    // update milage
    _milage += milage;
    return true;
}

void player::_update_milage_text(text_handler& texthandler)
{
    _text_milage_sprites.clear();
    bn::fixed_point text_position = position() + bn::fixed_point(32, _playfield_offset_y);
    texthandler.generate(text_position, bn::to_string<5>(_milage) + "M", _text_milage_sprites, bn::sprite_text_generator::alignment_type::RIGHT);
}

void player::_play_selected_card(player& other_player)
{
    // return early if cardtype not able to be played
    card_type cardtype = get_hand_display().get_card_type(_card_index);
    switch (cardtype)
    {
        // milage cards
        case card_type::Milage25:  { if (!_handle_play_milage_card( 25)) return; } break;
        case card_type::Milage50:  { if (!_handle_play_milage_card( 50)) return; } break;
        case card_type::Milage75:  { if (!_handle_play_milage_card( 75)) return; } break;
        case card_type::Milage100: { if (!_handle_play_milage_card(100)) return; } break;
        case card_type::Milage200: { if (!_handle_play_milage_card(200)) return; } break;
        // hazard cards
        case card_type::HazardStop: {
            // TODO check hazards and right of way safety
            if (other_player._card_display_roll.get_card_type() != card_type::RemedyGo)
                return;
            other_player._card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::HazardSpeedLimit: {
            // TODO check right of way safety
            if (other_player._card_display_speed.get_card_type() == card_type::HazardSpeedLimit)
                return;
            other_player._card_display_speed.update_card_type(cardtype);
        } break;
        case card_type::HazardOutOfGas: {
            // TODO check SafetyExtraTank
            if (other_player._card_display_roll.get_card_type().has_value() &&
                other_player._card_display_roll.get_card_type() != card_type::RemedyGo)
                return;
            other_player._card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::HazardFlatTire: {
            // TODO check SafetyPunctureProof
            if (other_player._card_display_roll.get_card_type().has_value() &&
                other_player._card_display_roll.get_card_type() != card_type::RemedyGo)
                return;
            other_player._card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::HazardAccident: {
            // TODO check SafetyRightOfWay
            if (other_player._card_display_roll.get_card_type().has_value() &&
                other_player._card_display_roll.get_card_type() != card_type::RemedyGo)
                return;
            other_player._card_display_roll.update_card_type(cardtype);
        } break;
        // remedy cards
        case card_type::RemedyGo: {
            // TODO (can Go be played if RightOfWay safety is played?)
            // check hazards & roll card
            if (_card_display_roll.get_card_type() == card_type::HazardOutOfGas ||
                _card_display_roll.get_card_type() == card_type::HazardFlatTire ||
                _card_display_roll.get_card_type() == card_type::HazardAccident ||
                _card_display_roll.get_card_type() == card_type::RemedyGo)
                return;
            _card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::RemedyEndOfLimit: {
            // TODO (can EndOfLimit be played if RightOfWay safety is played?)
            if (_card_display_speed.get_card_type() != card_type::HazardSpeedLimit)
                return;
            _card_display_speed.update_card_type(cardtype);
        } break;
        case card_type::RemedyGasoline: {
            // TODO (can Gasoline be played if ExtraTank safety is played?)
            if (_card_display_roll.get_card_type() != card_type::HazardOutOfGas)
                return;
            _card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::RemedySpareTire: {
            // TODO (can SpareTire be played if PunctureProof safety is played?)
            if (_card_display_roll.get_card_type() != card_type::HazardFlatTire)
                return;
            _card_display_roll.update_card_type(cardtype);
        } break;
        case card_type::RemedyRepairs: {
            // TODO (can Repairs be played if Accident safety is played?)
            if (_card_display_roll.get_card_type() != card_type::HazardAccident)
                return;
            _card_display_roll.update_card_type(cardtype);
        } break;
        // safety cards
        case card_type::SafetyRightOfWay:    { /* TODO SafetyRightOfWay    */ return; } break;
        case card_type::SafetyExtraTank:     { /* TODO SafetyExtraTank     */ return; } break;
        case card_type::SafetyPunctureProof: { /* TODO SafetyPunctureProof */ return; } break;
        case card_type::SafetyDrivingAce:    { /* TODO SafetyDrivingAce    */ return; } break;
        default: return;
    }
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

void player::update(bn::random&, card_pile<CardPileMax>&, player&)
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
