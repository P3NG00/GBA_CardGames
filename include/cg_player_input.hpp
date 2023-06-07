#ifndef CG_PLAYER_INPUT_HPP
#define CG_PLAYER_INPUT_HPP

#include "bn_keypad.h"

#include "bn_sprite_items_card_highlight.h"

#include "cg_player.hpp"

class player_input : public player
{
    bn::sprite_ptr _sprite_card_highlight = bn::sprite_items::card_highlight.create_sprite(0, 53);
    int _card_index = 0;
public:
    player_input(bn::fixed_point position, bn::fixed_point offset_direction);
    void update() override;
};

#endif
