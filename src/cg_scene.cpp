#include "cg_scene.hpp"

scene::scene()
{
}

bool scene::done()
{
    return false;
}

void scene::update(bn::random&, text_handler&)
{
}

void scene::execute(bn::random& random_obj, text_handler& texthandler)
{
    while (!done())
    {
        update(random_obj, texthandler);
        bn::core::update();
    }
}
