#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // background visible in all scenes
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);
    // random number generator
    bn::random random_obj = bn::random();

    // setup main menu scene
    bn::optional<scene_main_menu> scene_main_menu_obj = scene_main_menu();
    // execute main menu scene
    scene_main_menu_obj.value().execute(random_obj);

    // setup game scene
    scene_game scene_game_obj = scene_game(random_obj, scene_main_menu_obj.value().get_cpu_speed());
    // dispose of main menu scene
    scene_main_menu_obj.reset();
    // execute game scene
    scene_game_obj.execute(random_obj);
}
