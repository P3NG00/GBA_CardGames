#include "cg_card_pile.hpp"

template<int Size>
card_pile<Size>::card_pile(bn::fixed x, bn::fixed y, bool active) :
    _x(x),
    _y(y),
    _active(active)
{
}

template<int Size>
void card_pile<Size>::add_card(card_type cardtype)
{
    bn::fixed offset_y = CARD_OFFSET(count());
    card card_obj(cardtype, _x, offset_y);
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
    // TODO make random's seed based on time when started the game scene from the main menu once that's implemented
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
    for (int i = 0; i < _cards.size(); ++i)
    {
        bn::fixed offset_y = CARD_OFFSET(i);
        _cards[i].value().set_position(_x, offset_y);
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
// e.g. cg_scene_game.hpp has 'card_pile<106> _pile_draw' so there must be a 'template class card_pile<106>' below
template class card_pile<106>;
