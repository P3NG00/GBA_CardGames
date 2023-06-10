#ifndef CG_SCENE_GAME_HPP
#define CG_SCENE_GAME_HPP

#include "bn_array.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"
#include "bn_utility.h"

#include "cg_card_pile.hpp"
#include "cg_card_pile_display.hpp"
#include "cg_card_type.hpp"
#include "cg_player.hpp"
#include "cg_player_computer.hpp"
#include "cg_player_input.hpp"
#include "cg_scene.hpp"
#include "cg_util.hpp"

class scene_game : public scene
{
    const bn::array<player*, 2> _players = {
        &_player_input,
        &_player_computer,
    };
    card_pile<CardPileMax> _pile_draw    = card_pile<CardPileMax>(); // TODO display back of card for drawing pile at (-8, 0)
    card_pile<CardPileMax> _pile_discard = card_pile<CardPileMax>(); // TODO display most recently discarded card at (8, 0)
    int _index_player_current =  0;
    int _index_player_last    = -1;
    player_input    _player_input;
    player_computer _player_computer;
protected:
    void update(bn::random& random_obj) override;
public:
    scene_game(bn::random& random_obj, bn::fixed cpu_selection_timer_seconds);
};

#endif
