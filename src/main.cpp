#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // execute main menu scene
    scene_main_menu main_menu_scene_obj = scene_main_menu();

    while (!main_menu_scene_obj.done())
    {
        // update butano
        bn::core::update();
    }

    // create game scene
    scene_game game_scene_obj = scene_game();

    while (true)
    {
        // update game scene
        game_scene_obj.update();

        // update butano
        bn::core::update();
    }
}
