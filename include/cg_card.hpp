#ifndef CG_CARD_HPP
#define CG_CARD_HPP

#include "bn_assert.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_card_milage_25.h"

#include "cg_card_type.hpp"

class card
{
    bn::optional<bn::sprite_ptr> _sprite;
public:
    card(card_type cardtype);
};

#endif
