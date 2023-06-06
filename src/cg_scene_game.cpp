#include "cg_scene_game.hpp"

scene_game::scene_game() :
    _background(bn::regular_bg_items::background.create_bg(0, 0)),
    _pile_draw(0, -72, false)
{
    // add cards to draw pile
    int i;
    // milage
    for (i = 0; i < 10; i++)
    {
        _pile_draw.add_card(card_type::Milage25);
        _pile_draw.add_card(card_type::Milage50);
        _pile_draw.add_card(card_type::Milage75);
    }
    for (i = 0; i < 12; i++)
        _pile_draw.add_card(card_type::Milage100);
    for (i = 0; i < 4; i++)
        _pile_draw.add_card(card_type::Milage200);
    // hazards
    for (i = 0; i < 5; i++)
        _pile_draw.add_card(card_type::HazardStop);
    for (i = 0; i < 4; i++)
        _pile_draw.add_card(card_type::HazardSpeedLimit);
    for (i = 0; i < 3; i++)
    {
        _pile_draw.add_card(card_type::HazardOutOfGas);
        _pile_draw.add_card(card_type::HazardFlatTire);
        _pile_draw.add_card(card_type::HazardAccident);
    }
    // remedies
    for (i = 0; i < 14; i++)
        _pile_draw.add_card(card_type::RemedyGo);
    for (i = 0; i < 6; i++)
    {
        _pile_draw.add_card(card_type::RemedyEndOfLimit);
        _pile_draw.add_card(card_type::RemedyGasoline);
        _pile_draw.add_card(card_type::RemedySpareTire);
        _pile_draw.add_card(card_type::RemedyRepairs);
    }
    // safeties
    _pile_draw.add_card(card_type::SafetyRightOfWay);
    _pile_draw.add_card(card_type::SafetyExtraTank);
    _pile_draw.add_card(card_type::SafetyPunctureProof);
    _pile_draw.add_card(card_type::SafetyDrivingAce);
}

void scene_game::update()
{
    // TODO handle game logic
    if (bn::keypad::start_pressed())
    {
        _pile_draw.shuffle(_random_obj);
        _pile_draw.update_card_positions();
    }
}
