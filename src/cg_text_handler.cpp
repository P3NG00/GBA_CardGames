#include "cg_text_handler.hpp"

template<int Size>
void text_handler::generate(int x, int y, const bn::string_view& text, bn::vector<bn::sprite_ptr, Size>& text_sprites, bn::sprite_text_generator::alignment_type alignment)
{
    bn::fixed_point position = bn::fixed_point(x, y);
    generate(position, text, text_sprites, alignment);
}

template<int Size>
void text_handler::generate(bn::fixed_point& position, const bn::string_view& text, bn::vector<bn::sprite_ptr, Size>& text_sprites, bn::sprite_text_generator::alignment_type alignment)
{
    _text_generator.set_alignment(alignment);
    _text_generator.generate(position, text, text_sprites);
}

template void text_handler::generate<2>(bn::fixed_point&, const bn::string_view&, bn::vector<bn::sprite_ptr, 2>&, bn::sprite_text_generator::alignment_type);
template void text_handler::generate<13>(int, int, const bn::string_view&, bn::vector<bn::sprite_ptr, 13>&, bn::sprite_text_generator::alignment_type);
