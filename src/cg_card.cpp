#include "cg_card.hpp"

#define LOAD_SPRITE(sprite_name) _sprite = bn::sprite_items::sprite_name.create_sprite(0, 0)

card::card(card_type cardtype)
{
    switch (cardtype)
    {
        case card_type::Milage25: LOAD_SPRITE(card_milage_25); break;
        case card_type::Milage50: LOAD_SPRITE(card_milage_50); break;
        default: return;
    }
}
