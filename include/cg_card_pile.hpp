#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_vector.h"

#include "cg_card.hpp"
#include "cg_card_type.hpp"

template<int Size>
class card_pile
{
    bn::vector<bn::optional<card>, Size> _cards = bn::vector<bn::optional<card>, Size>();
    bn::fixed_point _offset_direction;
    bn::fixed_point _position;
    bool _active;
    bn::fixed_point _get_offset(int index);
public:
    card_pile(bn::fixed_point position, bn::fixed_point offset_direction, bool active = true);
    card_pile();
    template<int OtherSize> void deal_card_to(card_pile<OtherSize>& other_pile);
    void add_card(card_type cardtype);
    void clear();
    void shuffle(bn::random& random_obj);
    void update_card_positions();
    void set_active(bool active);
    bool is_active();
    int count();
};

#endif
