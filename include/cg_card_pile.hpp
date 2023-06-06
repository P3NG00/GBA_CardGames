#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_fixed.h"
#include "bn_math.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_vector.h"

#include "cg_card.hpp"
#include "cg_card_type.hpp"

#define CARD_OFFSET(index) (_y + (_PileCardOffset * index))

template<int Size>
class card_pile
{
    bn::fixed _PileCardOffset = 8;
    bn::vector<bn::optional<card>, Size> _cards = bn::vector<bn::optional<card>, Size>();
    bn::fixed _x, _y;
    bool _active;
public:
    card_pile(bn::fixed x, bn::fixed y, bool active = true);
    void add_card(card_type cardtype);
    void clear();
    void shuffle(bn::random& random_obj);
    void update_card_positions();
    void set_active(bool active);
    bool is_active();
    int count();
};

#endif
