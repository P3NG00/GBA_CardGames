#include "cg_player.hpp"

player::player(bn::fixed_point position, int playfield_offset_y) :
    _pile_hand_sprite_handler(card_pile_sprite_handler<CardPileHandMax>(position, &_pile_hand)),
    _playfield_offset_y(playfield_offset_y)
{
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

void player::update(bn::random& random_obj)
{
}

void player::start_turn()
{
}

void player::end_turn()
{
    bn::fixed_point position = get_hand_sprite_handler().get_position() + bn::fixed_point(0, _playfield_offset_y);
    _sprite_card_played = load_sprite(get_hand().get_card_type(_card_index), position);
    get_hand().remove_card_type(_card_index);
    get_hand_sprite_handler().update_sprites();
    _card_selected = false;
}
