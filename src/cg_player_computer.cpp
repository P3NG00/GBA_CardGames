#include "cg_player_computer.hpp"

player_computer::player_computer(bn::fixed_point position) :
    player(position)
{
}

void player_computer::update(bn::random& random_obj)
{
    // TODO implement difficulties
    _card_index = random_obj.get_int() % get_hand().count();
}

bn::optional<card_type> player_computer::get_chosen_card()
{
    card_type cardtype = get_hand().get_card_type(_card_index);
    get_hand().remove_card_type(_card_index);
    get_hand_sprite_handler().update_sprites();
    return cardtype;
}
