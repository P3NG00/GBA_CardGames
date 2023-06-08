#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_fixed_point.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"

#include "cg_card_pile.hpp"
#include "cg_card_pile_sprite_handler.hpp"
#include "cg_player.hpp"
#include "cg_player_computer.hpp"
#include "cg_player_input.hpp"
#include "cg_scene.hpp"
#include "cg_util.hpp"

const int PlayerCount = 2; // TODO make this adjustable, this is a temporary constant

class scene_game : public scene
{
    // TODO remove temporary display for discard pile for testing card selecting
    card_pile_sprite_handler<CardPileMax> _pile_discard_sprite_handler = card_pile_sprite_handler<CardPileMax>(bn::fixed_point(-112,  0), &_pile_discard);
    card_pile<CardPileMax> _pile_draw    = card_pile<CardPileMax>();
    card_pile<CardPileMax> _pile_discard = card_pile<CardPileMax>();
    int _index_player_current =  0;
    int _index_player_last    = -1;
    player_input    _player_input    = player_input   (bn::fixed_point(-48,  70));
    player_computer _player_computer = player_computer(bn::fixed_point(-48, -70));
    player* _players[PlayerCount] = {
        &_player_input,
        &_player_computer,
    };
protected:
    void update(bn::random& random_obj) override;
public:
    scene_game(bn::random& random_obj);
};

#endif
