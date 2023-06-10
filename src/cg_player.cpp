#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y) :
    _pile_hand_display(position),
    _playfield_offset_y(playfield_offset_y)
{
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
    return _card_selected;
}

// returns if card was able to be played
bool player::play_selected_card()
{
    if (!_card_selected)
        return false;
    // check if card is able to be played
    // TODO
    // update card sprite
    bn::fixed_point card_position = position() + bn::fixed_point(0, _playfield_offset_y);
    _sprite_card_played = load_sprite(get_hand_display().get_card_type(_card_index), card_position);
    // remove card from hand
    get_hand_display().remove_card_type(_card_index);
    // update hand sprites
    get_hand_display().update_sprites();
    return true;
}

void player::update(bn::random&)
{
}

void player::start_turn()
{
}

void player::end_turn()
{
    _card_selected = false;
}
