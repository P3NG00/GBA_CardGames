#include "cg_player_input.hpp"

player_input::player_input(bn::fixed_point position) :
    player(position)
{
    _sprite_card_highlight.set_visible(false);
}

bn::optional<card_type> player_input::get_chosen_card()
{
    if (!bn::keypad::a_pressed())
        return bn::nullopt;
    card_type cardtype = get_hand().get_card_type(_card_index);
    get_hand().remove_card_type(_card_index);
    get_hand_sprite_handler().update_sprites();
    return cardtype;
}

void player_input::update(bn::random& random_obj)
{
    // handle moving card selection
    if (bn::keypad::left_pressed())
    {
        if (_card_index > 0)
            _card_index--;
        else
            _card_index = get_hand().count() - 1;
    }
    if (bn::keypad::right_pressed())
    {
        if (_card_index < get_hand().count() - 1)
            _card_index++;
        else
            _card_index = 0;
    }

    // update card highlight
    _sprite_card_highlight.set_x(get_hand_sprite_handler().get_sprite(_card_index).value().x());
}

void player_input::start_turn()
{
    // fix out of bounds index
    if (_card_index >= get_hand().count())
        _card_index = get_hand().count() - 1;
    _sprite_card_highlight.set_visible(true);
}

void player_input::end_turn()
{
    _sprite_card_highlight.set_visible(false);
}
