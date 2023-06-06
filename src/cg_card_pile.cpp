#include "cg_card_pile.hpp"

template<int Size>
card_pile<Size>::card_pile(bn::fixed_point position, bn::fixed_point offset_direction, bool active) :
    _offset_direction(offset_direction),
    _position(position),
    _active(active)
{
}

template<int Size>
card_pile<Size>::card_pile() :
    card_pile(bn::fixed_point(0, 0), bn::fixed_point(0, 0), false)
{
}

template<int Size>
bn::fixed_point card_pile<Size>::_get_offset(int index)
{
    return _position + (_offset_direction * index);
}

template<int Size>
template<int OtherSize>
void card_pile<Size>::deal_card_to(card_pile<OtherSize>& other_pile)
{
    if (count() == 0)
        return;
    card card_obj = _cards.back().value();
    _cards.pop_back();
    other_pile.add_card(card_obj.get_card_type());
    update_card_positions();
    other_pile.update_card_positions();
}

template<int Size>
void card_pile<Size>::add_card(card_type cardtype)
{
    bn::fixed_point offset = _get_offset(count());
    card card_obj(cardtype, offset);
    if (!is_active())
        card_obj.set_active(false);
    _cards.push_back(card_obj);
}

template<int Size>
void card_pile<Size>::clear()
{
    _cards.clear();
}

template<int Size>
void card_pile<Size>::shuffle(bn::random& random_obj)
{
    for (int i = 0; i < _cards.size(); ++i)
    {
        int j = bn::max(0, bn::min(_cards.size() - 1, bn::abs(random_obj.get_int() % _cards.size())));
        bn::optional<card> temp = _cards[i];
        _cards[i] = _cards[j];
        _cards[j] = temp;
    }
}

template<int Size>
void card_pile<Size>::update_card_positions()
{
    if (!is_active())
        return;
    for (int i = 0; i < _cards.size(); ++i)
    {
        bn::fixed_point offset = _get_offset(i);
        _cards[i].value().set_position(offset);
    }
}

template<int Size>
void card_pile<Size>::set_active(bool active)
{
    if (_active == active)
        return;
    _active = active;
    for (int i = 0; i < _cards.size(); i++)
        _cards[i].value().set_active(active);
    if (active)
        update_card_positions();
}

template<int Size>
bool card_pile<Size>::is_active()
{
    return _active;
}

template<int Size>
int card_pile<Size>::count()
{
    return _cards.size();
}

// IF UNABLE TO BUILD make sure that all different instances of card_pile<int> are defined below with their respective sizes
// example: cg_scene_game.hpp has 'card_pile<106> _pile_draw' so there must be a 'template class card_pile<106>' below
template class card_pile<106>; // max deck size
template class card_pile<7>;   // max hand size
// example: I was getting the error below:
// undefined reference to 'void card_pile<106>::deal_card_to<7>(card_pile<7>&)'
// by adding the line below it fixed the build error
template void card_pile<106>::deal_card_to<7>(card_pile<7>&);
