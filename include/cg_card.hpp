#ifndef CG_CARD_HPP
#define CG_CARD_HPP

#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

// milage
#include "bn_sprite_items_card_milage_25.h"
#include "bn_sprite_items_card_milage_50.h"
#include "bn_sprite_items_card_milage_75.h"
#include "bn_sprite_items_card_milage_100.h"
#include "bn_sprite_items_card_milage_200.h"
// hazard
#include "bn_sprite_items_card_hazard_stop.h"
// TODO #include "bn_sprite_items_card_hazard_speed_limit.h"
// TODO #include "bn_sprite_items_card_hazard_out_of_gas.h"
// TODO #include "bn_sprite_items_card_hazard_flat_tire.h"
// TODO #include "bn_sprite_items_card_hazard_accident.h"
// remedy
#include "bn_sprite_items_card_remedy_go.h"
// TODO #include "bn_sprite_items_card_remedy_end_of_limit.h"
// TODO #include "bn_sprite_items_card_remedy_gasoline.h"
// TODO #include "bn_sprite_items_card_remedy_spare_tire.h"
// TODO #include "bn_sprite_items_card_remedy_repairs.h"
// safety
// TODO #include "bn_sprite_items_card_safety_right_of_way.h"
// TODO #include "bn_sprite_items_card_safety_extra_tank.h"
// TODO #include "bn_sprite_items_card_safety_puncture_proof.h"
// TODO #include "bn_sprite_items_card_safety_driving_ace.h"

#include "cg_card_type.hpp"

class card
{
    bn::optional<bn::sprite_ptr> _sprite;
    card_type _cardtype;
public:
    card(card_type cardtype, bn::fixed x, bn::fixed y);
};

#endif
