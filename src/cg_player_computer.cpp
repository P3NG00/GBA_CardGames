#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position) :
    player(position)
{
}

bn::optional<card_type> player_computer::get_chosen_card()
{
    if (_selection_timer > 0)
        return bn::nullopt;
    card_type cardtype = get_hand().get_card_type(_card_index);
    get_hand().remove_card_type(_card_index);
    get_hand_sprite_handler().update_sprites();
    return cardtype;
}

void player_computer::update(bn::random& random_obj)
{
    if (_selection_timer > 0)
    {
        _selection_timer--;
        return;
    }
    // TODO implement difficulties
    _card_index = random_obj.get_int() % get_hand().count();
}

void player_computer::start_turn()
{
    _selection_timer = SelectionTime;
}
