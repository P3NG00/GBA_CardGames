#include "cg_scene_main_menu.hpp"

scene_main_menu::scene_main_menu(text_handler& texthandler)
{
    // start text
    texthandler.generate(0, -6, "Press Start", _start_text_sprites);
    texthandler.generate(0,  6, "to begin", _start_text_sprites);
    // cpu speed text
    texthandler.generate(0, 40, "CPU Speed", _start_text_sprites);
    texthandler.generate(-90, 60, "Snail", _start_text_sprites);
    texthandler.generate(-30, 60, "Mild", _start_text_sprites);
    texthandler.generate( 30, 60, "Fast", _start_text_sprites);
    texthandler.generate( 90, 60, "Instant", _start_text_sprites);
    _update_textbox_position();
}

void scene_main_menu::_update_textbox_position()
{
    _text_background_box.set_x((_cpu_speed * 60) - 90);
}

bool scene_main_menu::done()
{
    return bn::keypad::start_pressed();
}

void scene_main_menu::update(bn::random& random_obj, text_handler&)
{
    // update random object every frame to allow time seeding
    random_obj.update();
    // update position of cpu speed selector
    bool update_textbox_position = false;
    if (bn::keypad::left_pressed() && _cpu_speed > 0)
    {
        _cpu_speed--;
        update_textbox_position = true;
    }
    if (bn::keypad::right_pressed() && _cpu_speed < 3)
    {
        _cpu_speed++;
        update_textbox_position = true;
    }
    if (update_textbox_position)
        _update_textbox_position();
}

bn::fixed scene_main_menu::get_cpu_speed()
{
    switch (_cpu_speed)
    {
        case 0: return 3;   // Snail
        case 1: return 1;   // Mild
        case 2: return 0.5; // Fast
        case 3: return 0;   // Instant
        default: return 1;
    }
}
