#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position, int playfield_offset_y, text_handler& texthandler, bn::fixed selection_time_seconds) :
    player(position, playfield_offset_y, texthandler, true),
    _selection_timer_frames(seconds_to_frames(selection_time_seconds))
{
}

void player_computer::update(bn::random& random_obj, card_pile<CardPileMax>& discard_pile, player& other_player)
{
    // check selection timer
    if (_selection_timer > 0)
    {
        _selection_timer--;
        return;
    }
    // TODO replace below code and implement difficulties
    _card_index = random_obj.get_int() % get_hand_display().count();
    if (random_obj.get_int() % 4 == 0)
        _discard_selected_card(discard_pile);
    else
        _play_selected_card(other_player);
}

void player_computer::start_turn()
{
    // reset selection timer
    _selection_timer = _selection_timer_frames;
}
