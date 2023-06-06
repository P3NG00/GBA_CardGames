#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_random.h"

#include "cg_card_pile.hpp"
#include "cg_constants.hpp"
#include "cg_player.hpp"
#include "cg_scene.hpp"

class scene_game : public scene
{
    card_pile<CardPileMax> _pile_draw = card_pile<CardPileMax>();
    card_pile<CardPileMax> _pile_discard = card_pile<CardPileMax>();
    player _player_main = player(bn::fixed_point(-48, 70), bn::fixed_point(16, 0));
    player _player_opponent = player(bn::fixed_point(-48, -70), bn::fixed_point(16, 0)); // TODO make hidden hands show as back of cards
protected:
    void update(bn::random& random_obj) override;
public:
    scene_game(bn::random& random_obj);
};

#endif
