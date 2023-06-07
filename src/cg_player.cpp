#include "cg_player.hpp"

player::player(bn::fixed_point position, bn::fixed_point offset_direction) :
    _pile_hand(position, offset_direction)
{
}

card_pile<CardPileHandMax>& player::get_hand()
{
    return _pile_hand;
}

void player::update()
{
}
