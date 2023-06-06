#include "cg_card.hpp"

#define LOAD_SPRITE(sprite_name) _sprite = bn::sprite_items::sprite_name.create_sprite(position.x(), position.y())

card::card(card_type cardtype, bn::fixed_point position) :
    _cardtype(cardtype)
{
    switch (cardtype)
    {
        // milage
        case card_type::Milage25:            LOAD_SPRITE(card_milage_25);             break;
        case card_type::Milage50:            LOAD_SPRITE(card_milage_50);             break;
        case card_type::Milage75:            LOAD_SPRITE(card_milage_75);             break;
        case card_type::Milage100:           LOAD_SPRITE(card_milage_100);            break;
        case card_type::Milage200:           LOAD_SPRITE(card_milage_200);            break;
        // hazard
        case card_type::HazardStop:          LOAD_SPRITE(card_hazard_stop);           break;
        case card_type::HazardSpeedLimit:    LOAD_SPRITE(card_hazard_speed_limit);    break;
        case card_type::HazardOutOfGas:      LOAD_SPRITE(card_hazard_out_of_gas);     break;
        case card_type::HazardFlatTire:      LOAD_SPRITE(card_hazard_flat_tire);      break;
        case card_type::HazardAccident:      LOAD_SPRITE(card_hazard_accident);       break;
        // remedy
        case card_type::RemedyGo:            LOAD_SPRITE(card_remedy_go);             break;
        case card_type::RemedyEndOfLimit:    LOAD_SPRITE(card_remedy_end_of_limit);   break;
        case card_type::RemedyGasoline:      LOAD_SPRITE(card_remedy_gasoline);       break;
        case card_type::RemedySpareTire:     LOAD_SPRITE(card_remedy_spare_tire);     break;
        case card_type::RemedyRepairs:       LOAD_SPRITE(card_remedy_repairs);        break;
        // safety
        case card_type::SafetyRightOfWay:    LOAD_SPRITE(card_safety_right_of_way);   break;
        case card_type::SafetyExtraTank:     LOAD_SPRITE(card_safety_extra_tank);     break;
        case card_type::SafetyPunctureProof: LOAD_SPRITE(card_safety_puncture_proof); break;
        case card_type::SafetyDrivingAce:    LOAD_SPRITE(card_safety_driving_ace);    break;
        default: return;
    }
}

bn::fixed_point card::get_position()
{
    return _sprite.value().position();
}

card_type card::get_card_type()
{
    return _cardtype;
}

bool card::is_active()
{
    return _sprite.value().visible();
}

void card::set_position(bn::fixed_point position)
{
    _sprite.value().set_position(position);
}

void card::set_active(bool active)
{
    _sprite.value().set_visible(active);
}
