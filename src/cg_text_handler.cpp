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

template void text_handler::generate<PlayerMilageSpritesMax>(bn::fixed_point&, const bn::string_view&, bn::vector<bn::sprite_ptr, PlayerMilageSpritesMax>&, bn::sprite_text_generator::alignment_type);
template void text_handler::generate<MainMenuSpritesMax>(int, int, const bn::string_view&, bn::vector<bn::sprite_ptr, MainMenuSpritesMax>&, bn::sprite_text_generator::alignment_type);
