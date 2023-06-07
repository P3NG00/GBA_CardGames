#ifndef CG_PLAYER_HPP
#define CG_PLAYER_HPP

#include "bn_fixed_point.h"

#include "cg_card_pile.hpp"
#include "cg_constants.hpp"

class player
{
    card_pile<CardPileHandMax> _pile_hand;
protected:
    player(bn::fixed_point position, bn::fixed_point offset_direction);
public:
    virtual ~player() = default;
    card_pile<CardPileHandMax>& get_hand();
    virtual void update();
};

#endif
