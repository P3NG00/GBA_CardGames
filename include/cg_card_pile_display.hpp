#ifndef CG_CARD_PILE_DISPLAY_HPP
#define CG_CARD_PILE_DISPLAY_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"

#include "cg_card_pile.hpp"
#include "cg_util.hpp"

template<int Size>
class card_pile_display : public card_pile<Size>
{
    bn::vector<bn::optional<bn::sprite_ptr>, Size> _sprites = bn::vector<bn::optional<bn::sprite_ptr>, Size>(Size, bn::optional<bn::sprite_ptr>());
    bn::fixed_point _position;
    const bool _centered;
public:
    card_pile_display(bn::fixed_point position, bool centered = false);
    bn::optional<bn::sprite_ptr> get_sprite(int index);
    bn::fixed_point get_position();
    void update_sprites();
};

#endif
