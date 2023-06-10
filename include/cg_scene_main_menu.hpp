#ifndef CG_SCENE_MAIN_MENU_HPP
#define CG_SCENE_MAIN_MENU_HPP

#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"

#include "bn_sprite_items_text_background_box.h"
#include "common_variable_8x16_sprite_font.h"

#include "cg_scene.hpp"

class scene_main_menu : public scene
{
    bn::sprite_text_generator _text_generator = bn::sprite_text_generator(common::variable_8x16_sprite_font);
    bn::sprite_ptr _text_background_box = bn::sprite_items::text_background_box.create_sprite(0, 60);
    bn::vector<bn::sprite_ptr, 20> _text_sprites = bn::vector<bn::sprite_ptr, 20>();
    int _cpu_speed = 1;
protected:
    bool done() override;
    void update(bn::random& random_obj) override;
public:
    scene_main_menu();
    bn::fixed get_cpu_speed();
};

#endif
