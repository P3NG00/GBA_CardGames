#ifndef CG_CARD_HPP
#define CG_CARD_HPP

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_card_milage_25.h"
#include "bn_sprite_items_card_milage_50.h"
#include "bn_sprite_items_card_milage_75.h"
#include "bn_sprite_items_card_milage_100.h"
#include "bn_sprite_items_card_milage_200.h"

#include "cg_card_type.hpp"

class card
{
    bn::optional<bn::sprite_ptr> _sprite;
    card_type _cardtype;
public:
    card(card_type cardtype, bn::fixed x, bn::fixed y);
};

#endif
