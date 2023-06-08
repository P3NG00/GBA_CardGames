#include "cg_scene_game.hpp"

scene_game::scene_game(bn::random& random_obj)
{
    // milage
    for (int i = 0; i < 10; i++)
    {
        _pile_draw.add_card_type(card_type::Milage25);
        _pile_draw.add_card_type(card_type::Milage50);
        _pile_draw.add_card_type(card_type::Milage75);
    }
    for (int i = 0; i < 12; i++)
        _pile_draw.add_card_type(card_type::Milage100);
    for (int i = 0; i < 4; i++)
        _pile_draw.add_card_type(card_type::Milage200);
    // hazards
    for (int i = 0; i < 5; i++)
        _pile_draw.add_card_type(card_type::HazardStop);
    for (int i = 0; i < 4; i++)
        _pile_draw.add_card_type(card_type::HazardSpeedLimit);
    for (int i = 0; i < 3; i++)
    {
        _pile_draw.add_card_type(card_type::HazardOutOfGas);
        _pile_draw.add_card_type(card_type::HazardFlatTire);
        _pile_draw.add_card_type(card_type::HazardAccident);
    }
    // remedies
    for (int i = 0; i < 14; i++)
        _pile_draw.add_card_type(card_type::RemedyGo);
    for (int i = 0; i < 6; i++)
    {
        _pile_draw.add_card_type(card_type::RemedyEndOfLimit);
        _pile_draw.add_card_type(card_type::RemedyGasoline);
        _pile_draw.add_card_type(card_type::RemedySpareTire);
        _pile_draw.add_card_type(card_type::RemedyRepairs);
    }
    // safeties
    _pile_draw.add_card_type(card_type::SafetyRightOfWay);
    _pile_draw.add_card_type(card_type::SafetyExtraTank);
    _pile_draw.add_card_type(card_type::SafetyPunctureProof);
    _pile_draw.add_card_type(card_type::SafetyDrivingAce);
    // shuffle draw pile
    _pile_draw.shuffle(random_obj);
    // deal cards to players
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < PlayerCount; j++)
            _pile_draw.deal_card_to(_players[j]->get_hand());
    // TODO update sprites in better locations, this is here for testing
    for (int i = 0; i < PlayerCount; i++)
        _players[i]->get_hand_sprite_handler().update_sprites();
}

void scene_game::update(bn::random& random_obj)
{
    // TODO deal one card upon turn start
    // TODO handle player's turn
    _players[_current_player]->update();
    // TODO move to next turn if player is done
    // TODO handle game logic
}
