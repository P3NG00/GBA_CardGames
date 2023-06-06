#include "cg_card.hpp"

#define LOAD_SPRITE(sprite_name) _sprite = bn::sprite_items::sprite_name.create_sprite(x, y)

card::card(card_type cardtype, bn::fixed x, bn::fixed y) :
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
        // TODO case card_type::HazardOutOfGas:      LOAD_SPRITE(card_hazard_out_of_gas);     break;
        // TODO case card_type::HazardFlatTire:      LOAD_SPRITE(card_hazard_flat_tire);      break;
        // TODO case card_type::HazardAccident:      LOAD_SPRITE(card_hazard_accident);       break;
        // remedy
        case card_type::RemedyGo:            LOAD_SPRITE(card_remedy_go);             break;
        // TODO case card_type::RemedyEndOfLimit:    LOAD_SPRITE(card_remedy_end_of_limit);   break;
        // TODO case card_type::RemedyGasoline:      LOAD_SPRITE(card_remedy_gasoline);       break;
        // TODO case card_type::RemedySpareTire:     LOAD_SPRITE(card_remedy_spare_tire);     break;
        // TODO case card_type::RemedyRepairs:       LOAD_SPRITE(card_remedy_repairs);        break;
        // safety
        // TODO case card_type::SafetyRightOfWay:    LOAD_SPRITE(card_safety_right_of_way);   break;
        // TODO case card_type::SafetyExtraTank:     LOAD_SPRITE(card_safety_extra_tank);     break;
        // TODO case card_type::SafetyPunctureProof: LOAD_SPRITE(card_safety_puncture_proof); break;
        // TODO case card_type::SafetyDrivingAce:    LOAD_SPRITE(card_safety_driving_ace);    break;
        default: return;
    }
}
