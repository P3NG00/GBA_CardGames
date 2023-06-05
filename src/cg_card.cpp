#include "cg_card.hpp"

card::card(card_type cardtype)
{
    switch (cardtype)
    {
        case card_type::Milage25:
            _sprite = bn::sprite_items::card_milage_25.create_sprite(0, 0);
            break;
    }
}
