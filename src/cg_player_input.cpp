#include "cg_player_input.hpp"

player_input::player_input(bn::fixed_point position, bn::fixed_point offset_direction) :
    player(position, offset_direction)
{
}

void player_input::update()
{
    // TODO handle selecting card
    if (bn::keypad::left_pressed())
    {
        if (_card_index > 0)
            _card_index--;
        else
            _card_index = get_hand().count() - 1;
    }
    if (bn::keypad::right_pressed())
    {
        if (_card_index < get_hand().count() - 1)
            _card_index++;
        else
            _card_index = 0;
    }
    // update card highlight
    _sprite_card_highlight.set_x(get_hand().get_card(_card_index).value().get_position().x());
}
