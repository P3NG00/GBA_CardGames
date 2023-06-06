#ifndef CG_CARD_TYPE_HPP
#define CG_CARD_TYPE_HPP

enum card_type
{
    // milage cards
    Milage25,
    Milage50,
    Milage75,
    Milage100,
    Milage200,
    // hazard cards
    HazardStop,
    HazardSpeedLimit,
    HazardOutOfGas,
    HazardFlatTire,
    HazardAccident,
    // remedy cards
    RemedyGo,
    RemedyEndOfLimit,
    RemedyGasoline,
    RemedySpareTire,
    RemedyRepairs,
    // safety cards
    // TODO SafetyRightOfWay,
    // TODO SafetyExtraTank,
    // TODO SafetyPunctureProof,
    // TODO SafetyDrivingAce,
};

#endif
