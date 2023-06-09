#include "cg_card_pile.hpp"

template<int Size>
bn::optional<card_type> card_pile<Size>::get_top_card_type()
{
    if (_cards.empty())
        return bn::nullopt;
    return _cards.back();
}

template<int Size>
card_type card_pile<Size>::get_card_type(int index)
{
    return _cards[index];
}

template<int Size>
int card_pile<Size>::count()
{
    return _cards.size();
}

template<int Size>
bool card_pile<Size>::contains(card_type cardtype)
{
    for (int i = 0; i < count(); i++)
    {
        if (get_card_type(i) == cardtype)
            return true;
    }
    return false;
}

template<int Size>
template<int OtherSize>
void card_pile<Size>::deal_card_to(card_pile<OtherSize>& other_pile)
{
    if (count() == 0)
        return;
    card_type cardtype = get_top_card_type().value();
    _cards.pop_back();
    other_pile.add_card_type(cardtype);
}

template<int Size>
void card_pile<Size>::add_card_type(card_type cardtype)
{
    _cards.push_back(cardtype);
}

template<int Size>
void card_pile<Size>::remove_card_type(int index)
{
    _cards.erase(_cards.begin() + index);
}

template<int Size>
void card_pile<Size>::clear()
{
    _cards.clear();
}

template<int Size>
void card_pile<Size>::shuffle(bn::random& random_obj)
{
    for (int i = 0; i < count(); i++)
    {
        int j = bn::max(0, bn::min(count() - 1, bn::abs(random_obj.get_int() % count())));
        card_type temp = _cards[i];
        _cards[i] = _cards[j];
        _cards[j] = temp;
    }
}

template class card_pile<CardPileMax>;       // max deck size
template class card_pile<CardPileHandMax>;   // max hand size
template class card_pile<CardPileSafetyMax>; // max safety pile size
template void card_pile<CardPileMax>::deal_card_to<CardPileHandMax>(card_pile<CardPileHandMax>&);
