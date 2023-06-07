#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position, bn::fixed_point offset_direction) :
    player(position, offset_direction)
{
}

void player_computer::update()
{
    // TODO implement ai choice
}
