#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // TODO main menu scene

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
