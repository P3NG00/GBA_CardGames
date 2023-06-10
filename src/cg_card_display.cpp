#include "cg_card_display.hpp"

card_display::card_display(bn::fixed_point position) :
    _position(position)
{
}

void card_display::update_card_type(card_type cardtype)
{
    _card_type = cardtype;
    _card_sprite.reset();
    _card_sprite = load_sprite(cardtype, _position);
}
