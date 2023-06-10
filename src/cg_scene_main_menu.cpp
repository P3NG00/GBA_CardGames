#include "cg_scene_main_menu.hpp"

scene_main_menu::scene_main_menu()
{
    _text_generator.set_center_alignment();
    // start text
    _text_generator.generate(0, -6, "Press Start", _text_sprites);
    _text_generator.generate(0,  6, "to begin",    _text_sprites);
    // cpu speed text
    _text_generator.generate(0, 40, "CPU Speed", _text_sprites);
    _text_generator.generate(-90, 60, "Snail",   _text_sprites);
    _text_generator.generate(-30, 60, "Mild",    _text_sprites);
    _text_generator.generate( 30, 60, "Fast",    _text_sprites);
    _text_generator.generate( 90, 60, "Instant", _text_sprites);
}

bool scene_main_menu::done()
{
    return bn::keypad::start_pressed();
}

void scene_main_menu::update(bn::random& random_obj)
{
    // update random object every frame to allow time seeding
    random_obj.update();
    // update position of cpu speed selector
    if (bn::keypad::left_pressed() && _cpu_speed > 0)
        _cpu_speed--;
    if (bn::keypad::right_pressed() && _cpu_speed < 3)
        _cpu_speed++;
    _text_background_box.set_x((_cpu_speed * 60) - 90);
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
