#include "cg_card.hpp"

#define LOAD_SPRITE(sprite_name) _sprite = bn::sprite_items::sprite_name.create_sprite(x, y)

card::card(card_type cardtype, bn::fixed x, bn::fixed y) :
    _cardtype(cardtype)
{
    switch (cardtype)
    {
        case card_type::Milage25:  LOAD_SPRITE(card_milage_25);  break;
        case card_type::Milage50:  LOAD_SPRITE(card_milage_50);  break;
        case card_type::Milage75:  LOAD_SPRITE(card_milage_75);  break;
        case card_type::Milage100: LOAD_SPRITE(card_milage_100); break;
        case card_type::Milage200: LOAD_SPRITE(card_milage_200); break;
        default: return;
    }
}
