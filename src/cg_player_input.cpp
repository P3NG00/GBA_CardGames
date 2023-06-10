#include "cg_player_input.hpp"

player_input::player_input(bn::fixed_point position, int playfield_offset_y) :
    player(position, playfield_offset_y)
{
    _sprite_card_highlight.set_visible(false);
}

void player_input::update(bn::random&)
{
    // handle moving card selection
    if (bn::keypad::left_pressed())
    {
        if (_card_index > 0)
            _card_index--;
        else
            _card_index = get_hand_display().count() - 1;
    }
    if (bn::keypad::right_pressed())
    {
        if (_card_index < get_hand_display().count() - 1)
            _card_index++;
        else
            _card_index = 0;
    }

    // update card highlight
    _sprite_card_highlight.set_x(get_hand_display().get_sprite(_card_index).value().x());

    _card_selected = bn::keypad::a_pressed();
}

void player_input::start_turn()
{
    // fix out of bounds index
    if (_card_index >= get_hand_display().count())
        _card_index = get_hand_display().count() - 1;
    // show card highlight
    _sprite_card_highlight.set_visible(true);
}

void player_input::end_turn()
{
    player::end_turn();
    // hide card highlight
    _sprite_card_highlight.set_visible(false);
}
