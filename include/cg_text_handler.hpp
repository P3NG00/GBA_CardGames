#ifndef CG_TEXT_HANDLER_HPP
#define CG_TEXT_HANDLER_HPP

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string_view.h"
#include "bn_vector.h"

#include "common_variable_8x16_sprite_font.h"

class text_handler
{
    bn::sprite_text_generator _text_generator = bn::sprite_text_generator(common::variable_8x16_sprite_font);
public:
    template<int Size>
    void generate(
        int x,
        int y,
        const bn::string_view& text,
        bn::vector<bn::sprite_ptr, Size>& text_sprites,
        bn::sprite_text_generator::alignment_type alignment = bn::sprite_text_generator::alignment_type::CENTER
    );
    template<int Size>
    void generate(
        bn::fixed_point& position,
        const bn::string_view& text,
        bn::vector<bn::sprite_ptr, Size>& text_sprites,
        bn::sprite_text_generator::alignment_type alignment = bn::sprite_text_generator::alignment_type::CENTER
    );
    void clear();
};

#endif
