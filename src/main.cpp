#include "bn_core.h"

#include "cg_card.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // setup game
    card card_obj(card_type::Milage25);

    // game loop
    while(true)
    {
        // TODO handle game logic

        // update butano
        bn::core::update();
    }
}
