#ifndef CG_PLAYER_INPUT_HPP
#define CG_PLAYER_INPUT_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_card_highlight.h"

#include "cg_card_pile.hpp"
#include "cg_player.hpp"
#include "cg_util.hpp"

class player_input : public player
{
    bn::sprite_ptr _sprite_card_highlight = bn::sprite_items::card_highlight.create_sprite(0, 53);
public:
    player_input(bn::fixed_point position, int playfield_offset_y);
    void update(bn::random& random_obj, card_pile<CardPileMax>& discard_pile);
    void start_turn() override;
    void end_turn() override;
};

#endif
