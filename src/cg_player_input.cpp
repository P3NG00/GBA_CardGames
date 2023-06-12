#include "cg_player_input.hpp"

player_input::player_input(bn::fixed_point position, int playfield_offset_y, text_handler& texthandler) :
    player(position, playfield_offset_y, texthandler, false)
{
    _sprite_card_highlight.set_visible(false);
}

void player_input::update(bn::random&, card_pile<CardPileMax>& discard_pile, player& other_player)
{
    // handle moving card selection
    if (bn::keypad::left_pressed())
    {
        if (_card_index > 0)
            _card_index--;
        else
            _card_index = get_hand_display().count() - 1;
    }
    if (bn::keypad::right_pressed())
    {
        if (_card_index < get_hand_display().count() - 1)
            _card_index++;
        else
            _card_index = 0;
    }

    // update card highlight
    _sprite_card_highlight.set_x(get_hand_display().get_sprite(_card_index).value().x());

    if (bn::keypad::a_pressed())
        _play_selected_card(other_player);
    else if (bn::keypad::b_pressed())
        _discard_selected_card(discard_pile);
}

void player_input::start_turn()
{
    // fix out of bounds index
    if (_card_index >= get_hand_display().count())
        _card_index = get_hand_display().count() - 1;
    // show card highlight
    _sprite_card_highlight.set_visible(true);
}

void player_input::end_turn(text_handler& texthandler)
{
    player::end_turn(texthandler);
    // hide card highlight
    _sprite_card_highlight.set_visible(false);
}
