#include "cg_card_pile.hpp"

template<int Size>
card_pile<Size>::card_pile(bn::fixed x, bn::fixed y) :
    _cards(),
    _x(x),
    _y(y)
{
}

template<int Size>
void card_pile<Size>::add_card(card_type cardtype)
{
    card card_obj(cardtype, _x, _y);
    _cards.push_back(card_obj);
}

template<int Size>
void card_pile<Size>::clear()
{
    _cards.clear();
}

// IF UNABLE TO BUILD make sure that all different instances of card_pile<int> are defined below with their respective sizes
template class card_pile<16>;
