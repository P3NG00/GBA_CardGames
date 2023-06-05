#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_vector.h"

#include "cg_card.hpp"
#include "cg_card_type.hpp"

template<int Size>
class card_pile
{
    bn::vector<bn::optional<card>, Size> _cards;
    bn::fixed _x, _y;
public:
    card_pile(bn::fixed x, bn::fixed y);
    void add_card(card_type cardtype);
    void clear();
};

#endif
