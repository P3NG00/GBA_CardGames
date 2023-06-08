#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_random.h"
#include "bn_vector.h"

#include "cg_card_type.hpp"
#include "cg_util.hpp"

template<int Size>
class card_pile
{
    bn::vector<card_type, Size> _cards = bn::vector<card_type, Size>();
public:
    card_type get_card_type(int index);
    int count();
    template<int OtherSize> void deal_card_to(card_pile<OtherSize>& other_pile);
    void add_card_type(card_type cardtype);
    void clear();
    void shuffle(bn::random& random_obj);
};

#endif
