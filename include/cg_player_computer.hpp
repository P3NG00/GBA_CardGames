#ifndef CG_PLAYER_COMPUTER_HPP
#define CG_PLAYER_COMPUTER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_random.h"

#include "cg_player.hpp"
#include "cg_util.hpp"

class player_computer : public player
{
    const int _selection_timer_frames;
    int _selection_timer = 0;
public:
    player_computer(bn::fixed_point position, int playfield_offset_y, bn::fixed selection_time_seconds);
    void update(bn::random& random_obj);
    void start_turn() override;
};

#endif
