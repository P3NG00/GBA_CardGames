#ifndef CG_PLAYER_HPP
#define CG_PLAYER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"

#include "cg_card_pile.hpp"
#include "cg_card_pile_display.hpp"
#include "cg_card_type.hpp"
#include "cg_util.hpp"

class player
{
    // cards in the player's hand
    card_pile_display<CardPileHandMax> _pile_hand_display;
    // most recently played card display
    bn::optional<bn::sprite_ptr> _sprite_card_played = bn::nullopt;
    bool _turn_done = false;
protected:
    player(bn::fixed_point position, int playfield_offset_y);
    void _play_selected_card();
    void _discard_selected_card(card_pile<CardPileMax>& discard_pile);
    int _playfield_offset_y;
    int _card_index = 0;
public:
    virtual ~player() = default;
    bn::fixed_point position();
    card_pile_display<CardPileHandMax>& get_hand_display();
    bool is_turn_done();
    virtual void update(bn::random& random_obj, card_pile<CardPileMax>& discard_pile);
    virtual void start_turn();
    virtual void end_turn();
};

#endif
