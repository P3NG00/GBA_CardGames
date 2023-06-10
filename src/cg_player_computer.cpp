#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position, int playfield_offset_y, bn::fixed selection_time_seconds) :
    player(position, playfield_offset_y),
    _selection_timer_frames(seconds_to_frames(selection_time_seconds))
{
}

void player_computer::update(bn::random& random_obj)
{
    // check selection timer
    if (_selection_timer > 0)
    {
        _selection_timer--;
        return;
    }
    // TODO implement difficulties
    _card_index = random_obj.get_int() % get_hand_display().count();
    _play_selected_card();
}

void player_computer::start_turn()
{
    // reset selection timer
    _selection_timer = _selection_timer_frames;
}
