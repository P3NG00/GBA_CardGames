#ifndef CG_PLAYER_COMPUTER_HPP
#define CG_PLAYER_COMPUTER_HPP

#include "cg_player.hpp"

class player_computer : public player
{
public:
    player_computer(bn::fixed_point position, bn::fixed_point offset_direction);
};

#endif
