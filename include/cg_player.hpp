#ifndef CG_PLAYER_HPP
#define CG_PLAYER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "cg_card_pile.hpp"
#include "cg_card_pile_sprite_handler.hpp"
#include "cg_util.hpp"

class player
{
    card_pile_sprite_handler<CardPileHandMax> _pile_hand_sprite_handler;
    card_pile<CardPileHandMax> _pile_hand = card_pile<CardPileHandMax>();
protected:
    player(bn::fixed_point position);
public:
    virtual ~player() = default;
    card_pile_sprite_handler<CardPileHandMax>& get_hand_sprite_handler();
    card_pile<CardPileHandMax>& get_hand();
    virtual void update();
};

#endif
