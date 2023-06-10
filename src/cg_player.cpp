#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y) :
    _pile_hand_display(position),
    _playfield_offset_y(playfield_offset_y)
{
}

void player::_play_selected_card()
{
    // check if card is able to be played
    card_type cardtype = get_hand_display().get_card_type(_card_index);
    // TODO return early if card is not able to be played in respective pile (roll, speed, milage)
    // update card sprite
    bn::fixed_point card_position = position() + bn::fixed_point(0, _playfield_offset_y);
    _sprite_card_played = load_sprite(cardtype, card_position);
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
    return _pile_hand_display;
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

void player::end_turn()
{
    _turn_done = false;
}
