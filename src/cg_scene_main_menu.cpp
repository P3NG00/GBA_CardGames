#include "cg_scene_main_menu.hpp"

scene_main_menu::scene_main_menu()
{
    _text_generator.set_center_alignment();
    _text_generator.generate(0, 0, "Press Start", _text_sprites);
}

bool scene_main_menu::done()
{
    return bn::keypad::start_pressed();
}
