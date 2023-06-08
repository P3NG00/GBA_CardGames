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
    // deal one card upon turn start
    if (_index_player_last != _index_player_current)
    {
        _pile_draw.deal_card_to(_players[_index_player_current]->get_hand());
        _players[_index_player_current]->get_hand_sprite_handler().update_sprites();
        _index_player_last = _index_player_current;
    }
    // update player
    _players[_index_player_current]->update(random_obj);
    // move to next turn if player is done
    bn::optional<card_type> chosen_card = _players[_index_player_current]->get_chosen_card();
    if (chosen_card.has_value())
    {
        // TODO remove - deal to discard for testing display and updating sprites
        _pile_discard.add_card_type(chosen_card.value());
        _pile_discard_sprite_handler.update_sprites();
        // increment player index
        _index_player_current = (_index_player_current + 1) % PlayerCount;
    }
    // TODO handle game logic
}
