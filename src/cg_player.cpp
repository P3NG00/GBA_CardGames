#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y) :
    _pile_hand_sprite_handler(card_pile_sprite_handler<CardPileHandMax>(position, &_pile_hand)),
    _playfield_offset_y(playfield_offset_y)
{
}

bn::fixed_point player::position()
{
    return get_hand_sprite_handler().get_position();
}

card_pile_sprite_handler<CardPileHandMax>& player::get_hand_sprite_handler()
{
    return _pile_hand_sprite_handler;
}

card_pile<CardPileHandMax>& player::get_hand()
{
    return _pile_hand;
}

bool player::is_turn_done()
{
    return _card_selected;
}

// returns if card was able to be played
bool player::play_selected_card()
{
    if (!_card_selected)
        return false;
    // TODO check if card is able to be played
    bn::fixed_point card_position = position() + bn::fixed_point(0, _playfield_offset_y);
    _sprite_card_played = load_sprite(get_hand().get_card_type(_card_index), card_position);
    get_hand().remove_card_type(_card_index);
    get_hand_sprite_handler().update_sprites();
    _card_selected = false;
    return true;
}

void player::update(bn::random&)
{
}

void player::start_turn()
{
}

void player::end_turn()
{
}
