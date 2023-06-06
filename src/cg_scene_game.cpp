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
        _cardpile.add_card(card_type::HazardStop);
    if (bn::keypad::left_pressed())
        _cardpile.add_card(card_type::HazardOutOfGas);
    if (bn::keypad::down_pressed())
        _cardpile.add_card(card_type::HazardSpeedLimit);
    if (bn::keypad::right_pressed())
        _cardpile.add_card(card_type::RemedyGo);
    if (bn::keypad::a_pressed())
        _cardpile.add_card(card_type::RemedyGasoline);
    // reset key
    if (bn::keypad::start_pressed())
        _cardpile.clear();
}
