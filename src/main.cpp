#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // setup background
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);

    // execute main menu scene
    scene_main_menu().execute();

    // execute game scene
    scene_game().execute();
}
