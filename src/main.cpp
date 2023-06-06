#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // setup background
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);

    // setup random
    bn::random random_obj = bn::random();

    // execute main menu scene
    scene_main_menu().execute(random_obj);

    // execute game scene
    scene_game(random_obj).execute(random_obj);
}
