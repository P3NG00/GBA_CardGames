#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_optional.h"
#include "bn_vector.h"

#include "cg_card.hpp"

template<int Size>
class card_pile
{
    bn::vector<bn::optional<card>, Size> _cards;
    // TODO
};

#endif
