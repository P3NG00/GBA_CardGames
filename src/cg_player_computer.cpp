#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position, int playfield_offset_y) :
    player(position, playfield_offset_y)
{
}

void player_computer::update(bn::random& random_obj)
{
    // check selection timer
    if (_selection_timer > 0)
    {
        _selection_timer--;
        return;
    }
    // TODO implement difficulties
    _card_index = random_obj.get_int() % get_hand().count();
    _card_selected = true;
}

void player_computer::start_turn()
{
    // reset selection timer
    _selection_timer = SelectionTime;
}
