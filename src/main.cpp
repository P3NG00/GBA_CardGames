#include "bn_core.h"

#include "cg_card.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // setup game
    card card_obj1(card_type::Milage25,  -64, 0);
    card card_obj2(card_type::Milage50,  -48, 0);
    card card_obj3(card_type::Milage75,  -32, 0);
    card card_obj4(card_type::Milage100, -16, 0);
    card card_obj5(card_type::Milage200,   0, 0);

    // game loop
    while(true)
    {
        // TODO handle game logic

        // update butano
        bn::core::update();
    }
}
