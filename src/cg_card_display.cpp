#include "cg_card_display.hpp"

card_display::card_display(bn::fixed_point position) :
    _position(position)
{
}

bn::optional<card_type> card_display::get_card_type()
{
    return _card_type;
}

void card_display::update_card_type(bn::optional<card_type> cardtype)
{
    _card_type = cardtype;
    _card_sprite.reset();
    if (cardtype.has_value())
        _card_sprite = load_sprite(cardtype.value(), _position);
}
