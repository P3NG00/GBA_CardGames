#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_card.h"

int main()
{
    // initialize butano
    bn::core::init();

    // setup game
    bn::sprite_ptr card = bn::sprite_items::card.create_sprite(0, 0);

    // game loop
    while(true)
    {
        // TODO handle game logic
        if (bn::keypad::left_held())
            card.set_x(card.x() - 1);
        if (bn::keypad::right_held())
            card.set_x(card.x() + 1);
        if (bn::keypad::up_held())
            card.set_y(card.y() - 1);
        if (bn::keypad::down_held())
            card.set_y(card.y() + 1);

        // update butano
        bn::core::update();
    }
}
