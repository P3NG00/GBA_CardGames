#ifndef CG_CARD_DISPLAY_HPP
#define CG_CARD_DISPLAY_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "cg_card_type.hpp"
#include "cg_util.hpp"

class card_display
{
    bn::optional<bn::sprite_ptr> _card_sprite = bn::nullopt;
    bn::optional<card_type> _card_type;
    bn::fixed_point _position;
public:
    card_display(bn::fixed_point position);
    void update_card_type(bn::optional<card_type> cardtype);
};

#endif
