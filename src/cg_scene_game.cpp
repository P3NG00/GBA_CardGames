#include "cg_scene_game.hpp"

scene_game::scene_game(bn::random& random_obj)
{
    const int CardTypesAmount = 19;
    const bn::array<bn::pair<int, card_type>, CardTypesAmount> card_type_amounts = {
        bn::pair<int, card_type>(10, card_type::Milage25),
        bn::pair<int, card_type>(10, card_type::Milage50),
        bn::pair<int, card_type>(10, card_type::Milage75),
        bn::pair<int, card_type>(12, card_type::Milage100),
        bn::pair<int, card_type>( 4, card_type::Milage200),
        bn::pair<int, card_type>( 5, card_type::HazardStop),
        bn::pair<int, card_type>( 4, card_type::HazardSpeedLimit),
        bn::pair<int, card_type>( 3, card_type::HazardOutOfGas),
        bn::pair<int, card_type>( 3, card_type::HazardFlatTire),
        bn::pair<int, card_type>( 3, card_type::HazardAccident),
        bn::pair<int, card_type>(14, card_type::RemedyGo),
        bn::pair<int, card_type>( 6, card_type::RemedyEndOfLimit),
        bn::pair<int, card_type>( 6, card_type::RemedyGasoline),
        bn::pair<int, card_type>( 6, card_type::RemedySpareTire),
        bn::pair<int, card_type>( 6, card_type::RemedyRepairs),
        bn::pair<int, card_type>( 1, card_type::SafetyRightOfWay),
        bn::pair<int, card_type>( 1, card_type::SafetyExtraTank),
        bn::pair<int, card_type>( 1, card_type::SafetyPunctureProof),
        bn::pair<int, card_type>( 1, card_type::SafetyDrivingAce),
    };
    for (int i = 0; i < CardTypesAmount; i++)
        for (int j = 0; j < card_type_amounts[i].first; j++)
            _pile_draw.add_card_type(card_type_amounts[i].second);
    // shuffle draw pile
    _pile_draw.shuffle(random_obj);
    // deal cards to players
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < PlayerCount; j++)
            _pile_draw.deal_card_to(_players[j]->get_hand());
    // update sprite handlers
    for (int i = 0; i < PlayerCount; i++)
        _players[i]->get_hand_sprite_handler().update_sprites();
}

void scene_game::update(bn::random& random_obj)
{
    // if new player starting turn...
    if (_index_player_last != _index_player_current)
    {
        // draw card // TODO make able to draw from discard
        _pile_draw.deal_card_to(_players[_index_player_current]->get_hand());
        // handle player start turn
        _players[_index_player_current]->start_turn();
        // update card sprites
        _players[_index_player_current]->get_hand_sprite_handler().update_sprites();
        // update last player index
        _index_player_last = _index_player_current;
    }
    // update player
    _players[_index_player_current]->update(random_obj);
    // move to next turn if player is done
    if (_players[_index_player_current]->is_turn_done())
    {
        // handle player end turn
        _players[_index_player_current]->end_turn();
        // increment player index
        _index_player_current = (_index_player_current + 1) % PlayerCount;
    }
    // TODO handle game logic
}
