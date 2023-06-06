#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_random.h"

#include "cg_card_pile.hpp"
#include "cg_constants.hpp"
#include "cg_scene.hpp"

class scene_game : public scene
{
    card_pile<CardPileMax> _pile_draw = card_pile<CardPileMax>();
    card_pile<CardPileMax> _pile_discard = card_pile<CardPileMax>();
    card_pile<CardPileHandMax> _pile_hand_player = card_pile<CardPileHandMax>(bn::fixed_point(-48, 70), bn::fixed_point(16, 0));
    card_pile<CardPileHandMax> _pile_hand_opponent = card_pile<CardPileHandMax>();
protected:
    void update(bn::random& random_obj) override;
public:
    scene_game(bn::random& random_obj);
};

#endif
