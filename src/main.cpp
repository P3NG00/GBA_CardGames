#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // execute main menu scene
    scene_main_menu().execute();

    // execute game scene
    scene_game().execute();
}
