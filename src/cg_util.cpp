#include "cg_util.hpp"

#define SPRITE(sprite_name) bn::sprite_items::sprite_name.create_sprite(position)

bn::optional<bn::sprite_ptr> load_sprite(card_type cardtype, bn::fixed_point position)
{
    switch (cardtype)
    {
        // milage
        case card_type::Milage25:                      return SPRITE(card_milage_25);
        case card_type::Milage50:                      return SPRITE(card_milage_50);
        case card_type::Milage75:                      return SPRITE(card_milage_75);
        case card_type::Milage100:                     return SPRITE(card_milage_100);
        case card_type::Milage200:                     return SPRITE(card_milage_200);
        // hazard
        case card_type::HazardStop:                    return SPRITE(card_hazard_stop);
        case card_type::HazardSpeedLimit:              return SPRITE(card_hazard_speed_limit);
        case card_type::HazardOutOfGas:                return SPRITE(card_hazard_out_of_gas);
        case card_type::HazardFlatTire:                return SPRITE(card_hazard_flat_tire);
        case card_type::HazardAccident:                return SPRITE(card_hazard_accident);
        // remedy
        case card_type::RemedyGo:                      return SPRITE(card_remedy_go);
        case card_type::RemedyEndOfLimit:              return SPRITE(card_remedy_end_of_limit);
        case card_type::RemedyGasoline:                return SPRITE(card_remedy_gasoline);
        case card_type::RemedySpareTire:               return SPRITE(card_remedy_spare_tire);
        case card_type::RemedyRepairs:                 return SPRITE(card_remedy_repairs);
        // safety
        case card_type::SafetyRightOfWay:              return SPRITE(card_safety_right_of_way);
        case card_type::SafetyExtraTank:               return SPRITE(card_safety_extra_tank);
        case card_type::SafetyPunctureProof:           return SPRITE(card_safety_puncture_proof);
        case card_type::SafetyDrivingAce:              return SPRITE(card_safety_driving_ace);
        // safety (coup-fourré)
        case card_type::SafetyRightOfWayCoupFourre:    return SPRITE(card_safety_right_of_way_coup_fourre);
        case card_type::SafetyExtraTankCoupFourre:     return SPRITE(card_safety_extra_tank_coup_fourre);
        case card_type::SafetyPunctureProofCoupFourre: return SPRITE(card_safety_puncture_proof_coup_fourre);
        case card_type::SafetyDrivingAceCoupFourre:    return SPRITE(card_safety_driving_ace_coup_fourre);

        default: return bn::nullopt;
    }
}

int seconds_to_frames(bn::fixed seconds)
{
    return (seconds * bn::fixed(60.0)).round_integer();
}
