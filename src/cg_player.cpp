#include "cg_player.hpp"

player::player(bn::fixed_point position) :
    _pile_hand_sprite_handler(card_pile_sprite_handler<CardPileHandMax>(position, &_pile_hand))
{
}

card_pile_sprite_handler<CardPileHandMax>& player::get_hand_sprite_handler()
{
    return _pile_hand_sprite_handler;
}

card_pile<CardPileHandMax>& player::get_hand()
{
    return _pile_hand;
}

void player::update()
{
}
