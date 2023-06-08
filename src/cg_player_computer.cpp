#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position) :
    player(position)
{
}

bn::optional<card_type> player_computer::get_chosen_card()
{
    const int choice_index = 0; // TODO implement ai choice
    card_type cardtype = get_hand().get_card_type(choice_index);
    get_hand().remove_card_type(choice_index);
    get_hand_sprite_handler().update_sprites();
    return cardtype;
}
