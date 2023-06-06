#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"

#include "bn_regular_bg_items_background.h"

#include "cg_card_pile.hpp"

class scene_game
{
    bn::regular_bg_ptr _background;
    card_pile<16> _cardpile;
public:
    scene_game();
    void update();
};

#endif
