#ifndef CG_CARD_PILE_SPRITE_HANDLER_HPP
#define CG_CARD_PILE_SPRITE_HANDLER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"

#include "cg_card_pile.hpp"
#include "cg_util.hpp"

template<int Size>
class card_pile_sprite_handler
{
    bn::vector<bn::optional<bn::sprite_ptr>, Size> _sprites = bn::vector<bn::optional<bn::sprite_ptr>, Size>(Size, bn::optional<bn::sprite_ptr>());
    bn::fixed_point _position;
    card_pile<Size>* _card_pile_ptr;
public:
    card_pile_sprite_handler(bn::fixed_point position, card_pile<Size>* card_pile_ptr);
    bn::optional<bn::sprite_ptr> get_sprite(int index);
    void update_sprites();
};

#endif
