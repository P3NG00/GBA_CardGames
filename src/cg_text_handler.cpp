#include "cg_text_handler.hpp"

text_handler::text_handler()
{
    _text_generator.set_center_alignment();
}

template<int Size>
void text_handler::generate(int x, int y, const bn::string_view& text, bn::vector<bn::sprite_ptr, Size>& text_sprites)
{
    bn::fixed_point position = bn::fixed_point(x, y);
    generate(position, text, text_sprites);
}

template<int Size>
void text_handler::generate(bn::fixed_point& position, const bn::string_view& text, bn::vector<bn::sprite_ptr, Size>& text_sprites)
{
    _text_generator.generate(position, text, text_sprites);
}

template void text_handler::generate<PlayerMilageSpritesMax>(bn::fixed_point&, const bn::string_view&, bn::vector<bn::sprite_ptr, PlayerMilageSpritesMax>&);
template void text_handler::generate<MainMenuSpritesMax>(int, int, const bn::string_view&, bn::vector<bn::sprite_ptr, MainMenuSpritesMax>&);
