#ifndef CG_SCENE_MAIN_MENU_HPP
#define CG_SCENE_MAIN_MENU_HPP

#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"

#include "bn_sprite_items_text_background_box.h"

#include "cg_scene.hpp"
#include "cg_text_handler.hpp"

class scene_main_menu : public scene
{
    void _update_textbox_position();
    bn::vector<bn::sprite_ptr, 13> _start_text_sprites = bn::vector<bn::sprite_ptr, 13>();
    bn::sprite_ptr _text_background_box = bn::sprite_items::text_background_box.create_sprite(0, 60);
    int _cpu_speed = 1; // TODO save and load last value in file
protected:
    bool done() override;
    void update(bn::random& random_obj, text_handler& texthandler) override;
public:
    scene_main_menu(text_handler& texthandler);
    bn::fixed get_cpu_speed();
};

#endif
