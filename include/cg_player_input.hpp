#ifndef CG_PLAYER_INPUT_HPP
#define CG_PLAYER_INPUT_HPP

#include "cg_player.hpp"

class player_input : public player
{
public:
    player_input(bn::fixed_point position, bn::fixed_point offset_direction);
};

#endif
