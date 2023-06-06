#include "cg_card_pile.hpp"

template<int Size>
card_pile<Size>::card_pile(bn::fixed x, bn::fixed y) :
    _x(x),
    _y(y)
{
}

template<int Size>
void card_pile<Size>::add_card(card_type cardtype)
{
    bn::fixed offset_y = CARD_OFFSET(count());
    card card_obj(cardtype, _x, offset_y);
    _cards.push_back(card_obj);
}

template<int Size>
void card_pile<Size>::clear()
{
    _cards.clear();
}

template<int Size>
void card_pile<Size>::shuffle()
{
    for (int i = 0; i < _cards.size(); ++i)
    {
        int j = bn::max(0, bn::min(_cards.size() - 1, bn::abs(_random_obj.get_int() % _cards.size())));
        bn::optional<card> temp = _cards[i];
        _cards[i] = _cards[j];
        _cards[j] = temp;
    }
}

template<int Size>
void card_pile<Size>::update_card_positions()
{
    for (int i = 0; i < _cards.size(); ++i)
    {
        bn::fixed offset_y = CARD_OFFSET(i);
        _cards[i].value().set_position(_x, offset_y);
    }
}

template<int Size>
int card_pile<Size>::count()
{
    return _cards.size();
}

// IF UNABLE TO BUILD make sure that all different instances of card_pile<int> are defined below with their respective sizes
template class card_pile<106>;
