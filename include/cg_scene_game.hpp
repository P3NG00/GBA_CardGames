#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_regular_bg_ptr.h"

#include "bn_regular_bg_items_background.h"

#include "cg_card_pile.hpp"
#include "cg_scene.hpp"

class scene_game : public scene
{
    bn::random _random_obj;
    card_pile<106> _pile_draw;
    card_pile<7> _pile_hand;
protected:
    bool done() override;
    void update() override;
public:
    scene_game();
};

#endif
