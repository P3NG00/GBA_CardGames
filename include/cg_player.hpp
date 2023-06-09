#ifndef CG_PLAYER_HPP
#define CG_PLAYER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_random.h"

#include "cg_card_pile.hpp"
#include "cg_card_pile_sprite_handler.hpp"
#include "cg_card_type.hpp"
#include "cg_util.hpp"

class player
{
    // sprite handler for the player's hand
    card_pile_sprite_handler<CardPileHandMax> _pile_hand_sprite_handler;
    // cards in the player's hand
    card_pile<CardPileHandMax> _pile_hand = card_pile<CardPileHandMax>();
protected:
    player(bn::fixed_point position);
    int _card_index = 0;
public:
    virtual ~player() = default;
    virtual bn::optional<card_type> get_chosen_card();
    card_pile_sprite_handler<CardPileHandMax>& get_hand_sprite_handler();
    card_pile<CardPileHandMax>& get_hand();
    virtual void update(bn::random& random_obj);
    virtual void start_turn();
    virtual void end_turn();
};

#endif
