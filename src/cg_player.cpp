#include "cg_player.hpp"

player::player(bn::fixed_point position) :
    _pile_hand(position)
{
}

card_pile<CardPileHandMax>& player::get_hand()
{
    return _pile_hand;
}

void player::update()
{
}
