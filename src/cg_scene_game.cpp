#include "cg_scene_game.hpp"

scene_game::scene_game() :
    _background(bn::regular_bg_items::background.create_bg(0, 0)),
    _cardpile(0, 0)
{
}

void scene_game::update()
{
    // TODO handle game logic
    if (bn::keypad::up_pressed())
        _cardpile.add_card(card_type::Milage25);
    if (bn::keypad::left_pressed())
        _cardpile.add_card(card_type::Milage50);
    if (bn::keypad::down_pressed())
        _cardpile.add_card(card_type::Milage75);
    if (bn::keypad::right_pressed())
        _cardpile.add_card(card_type::Milage100);
    if (bn::keypad::a_pressed())
        _cardpile.add_card(card_type::Milage200);
    if (bn::keypad::start_pressed())
        _cardpile.clear();
}
