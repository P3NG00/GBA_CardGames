#include "main.hpp"

int main()
{
    // initialize butano
    bn::core::init();

    // background visible in all scenes
    bn::regular_bg_ptr background = bn::regular_bg_items::background.create_bg(0, 0);
    // random number generator
    bn::random random_obj = bn::random();
    // text handler
    text_handler texthandler = text_handler();

    // setup main menu scene
    bn::optional<scene_main_menu> scene_main_menu_obj = scene_main_menu(texthandler);
    // execute main menu scene
    scene_main_menu_obj.value().execute(random_obj, texthandler);

    // TODO create 'tutorial scene' that explains the cards and buttons

    // setup game scene
    scene_game scene_game_obj = scene_game(random_obj, texthandler, scene_main_menu_obj.value().get_cpu_speed());
    // dispose of main menu scene
    scene_main_menu_obj.reset();
    // execute game scene
    scene_game_obj.execute(random_obj, texthandler);

    // TODO create 'game over scene' that shows the winner and the score

    // TODO return to main menu
}
