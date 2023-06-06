#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_random.h"

#include "cg_card_pile.hpp"
#include "cg_scene.hpp"

class scene_game : public scene
{
    card_pile<106> _pile_draw;
    card_pile<7> _pile_hand;
protected:
    bool done() override;
    void update(bn::random& random_obj) override;
public:
    scene_game(bn::random& random_obj);
};

#endif
