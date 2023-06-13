#ifndef CG_CARD_PILE_HPP
#define CG_CARD_PILE_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_vector.h"

#include "cg_card_type.hpp"
#include "cg_util.hpp"

template<int Size>
class card_pile
{
protected:
    bn::vector<card_type, Size> _cards = bn::vector<card_type, Size>();
public:
    virtual ~card_pile() = default;
    bn::optional<card_type> get_top_card_type();
    card_type get_card_type(int index);
    int count();
    bool contains(card_type cardtype);
    template<int OtherSize> void deal_card_to(card_pile<OtherSize>& other_pile);
    virtual void add_card_type(card_type cardtype);
    virtual void remove_card_type(int index);
    void clear();
    void shuffle(bn::random& random_obj);
};

#endif
