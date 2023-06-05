#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_keypad.h"

#include "cg_card.hpp"
#include "cg_card_pile.hpp"
#include "cg_card_type.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // TODO setup game
    card_pile<16> cardpile(0, 0);

    // game loop
    while(true)
    {
        // TODO handle game logic
        if (bn::keypad::up_pressed())
            cardpile.add_card(card_type::Milage25);
        if (bn::keypad::left_pressed())
            cardpile.add_card(card_type::Milage50);
        if (bn::keypad::down_pressed())
            cardpile.add_card(card_type::Milage75);
        if (bn::keypad::right_pressed())
            cardpile.add_card(card_type::Milage100);
        if (bn::keypad::a_pressed())
            cardpile.add_card(card_type::Milage200);
        if (bn::keypad::start_pressed())
            cardpile.clear();

        // update butano
        bn::core::update();
    }
}
