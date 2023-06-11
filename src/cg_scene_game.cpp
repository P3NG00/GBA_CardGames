#include "cg_scene_game.hpp"

scene_game::scene_game(bn::random& random_obj, text_handler& texthandler, bn::fixed cpu_selection_timer_seconds) :
    _player_input   (bn::fixed_point(0,  70), -34, texthandler),
    _player_computer(bn::fixed_point(0, -70),  34, texthandler, cpu_selection_timer_seconds) // TODO only show back of opponent's cards
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
        for (int j = 0; j < _players.size(); j++)
            _pile_draw.deal_card_to(_players[j]->get_hand_display());
    // update sprite handlers
    for (int i = 0; i < _players.size(); i++)
        _players[i]->get_hand_display().update_sprites();
}

void scene_game::update(bn::random& random_obj, text_handler& texthandler)
{
    // if new player starting turn...
    if (_index_player_last != _index_player_current)
    {
        // draw card // TODO make able to draw from discard
        _pile_draw.deal_card_to(_players[_index_player_current]->get_hand_display());
        // handle player start turn
        _players[_index_player_current]->start_turn();
        // update card sprites
        _players[_index_player_current]->get_hand_display().update_sprites();
        // update last player index
        _index_player_last = _index_player_current;
    }
    // update player
    _players[_index_player_current]->update(random_obj, _pile_discard);
    // move to next turn if player is done
    if (_players[_index_player_current]->is_turn_done())
    {
        // handle player end turn
        _players[_index_player_current]->end_turn(texthandler);
        // increment player index
        _index_player_current = (_index_player_current + 1) % _players.size();
        // update discard sprite
        _card_discard_display.update_card_type(_pile_discard.get_top_card_type());
    }
    // TODO handle game logic
    // TODO fix crash, handle running out of cards
}
