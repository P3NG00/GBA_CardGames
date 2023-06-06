#ifndef CG_SCENE_MAIN_MENU_HPP
#define CG_SCENE_MAIN_MENU_HPP

#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"

#include "common_variable_8x16_sprite_font.h"

#include "cg_scene.hpp"

// TODO abstract scene class
class scene_main_menu : public scene
{
    bn::sprite_text_generator _text_generator = bn::sprite_text_generator(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 20> _text_sprites = bn::vector<bn::sprite_ptr, 20>();
protected:
    bool done() override;
public:
    scene_main_menu();
};

#endif
