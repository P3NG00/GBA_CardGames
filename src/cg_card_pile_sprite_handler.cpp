#include "cg_card_pile_sprite_handler.hpp"

template<int Size>
card_pile_sprite_handler<Size>::card_pile_sprite_handler(bn::fixed_point position, card_pile<Size>* card_pile_ptr) :
    _position(position),
    _card_pile_ptr(card_pile_ptr)
{
}

template<int Size>
bn::optional<bn::sprite_ptr> card_pile_sprite_handler<Size>::get_sprite(int index)
{
    return _sprites[index];
}

template<int Size>
void card_pile_sprite_handler<Size>::update_sprites()
{
    for (int i = 0; i < _card_pile_ptr->count(); i++)
    {
        if (_sprites[i].has_value())
            _sprites[i].reset();
        _sprites[i] = load_sprite(_card_pile_ptr->get_card_type(i), _position + bn::fixed_point(i * 16, 0));
    }
    for (int i = _card_pile_ptr->count(); i < Size; i++)
        _sprites[i].reset();
}

template class card_pile_sprite_handler<CardPileHandMax>;
