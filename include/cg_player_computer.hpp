#ifndef CG_PLAYER_COMPUTER_HPP
#define CG_PLAYER_COMPUTER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "cg_player.hpp"

class player_computer : public player
{
public:
    player_computer(bn::fixed_point position);
    void update() override;
};

#endif
