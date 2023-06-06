#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_regular_bg_ptr.h"

#include "bn_regular_bg_items_background.h"

#include "cg_card_pile.hpp"

class scene_game
{
    bn::random _random_obj;
    bn::regular_bg_ptr _background;
    card_pile<106> _pile_draw;
public:
    scene_game();
    void update();
};

#endif
