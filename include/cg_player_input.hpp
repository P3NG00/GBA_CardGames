#ifndef CG_PLAYER_INPUT_HPP
#define CG_PLAYER_INPUT_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_card_highlight.h"

#include "cg_player.hpp"

class player_input : public player
{
    bn::sprite_ptr _sprite_card_highlight = bn::sprite_items::card_highlight.create_sprite(0, 53);
public:
    player_input(bn::fixed_point position);
    void update(bn::random& random_obj);
    bn::optional<card_type> get_chosen_card() override;
};

#endif
