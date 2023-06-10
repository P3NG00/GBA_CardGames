#include "cg_card_pile_display.hpp"

template<int Size>
card_pile_display<Size>::card_pile_display(bn::fixed_point position) :
    _position(position)
{
}

template<int Size>
bn::optional<bn::sprite_ptr> card_pile_display<Size>::get_sprite(int index)
{
    return _sprites[index];
}

template<int Size>
bn::fixed_point card_pile_display<Size>::get_position()
{
    return _position;
}

template<int Size>
void card_pile_display<Size>::update_sprites()
{
    for (int i = 0; i < this->_cards.size(); i++)
    {
        if (_sprites[i].has_value())
            _sprites[i].reset();
        _sprites[i] = load_sprite(this->get_card_type(i), _position + bn::fixed_point(i * 16, 0));
    }
    for (int i = this->_cards.size(); i < Size; i++)
        _sprites[i].reset();
}

template class card_pile_display<CardPileMax>;     // max deck size
template class card_pile_display<CardPileHandMax>; // max hand size
