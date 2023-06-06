#include "cg_scene.hpp"

scene::scene()
{
}

bool scene::done()
{
    return false;
}

void scene::update(bn::random& random_obj)
{
    random_obj.update();
}

void scene::execute(bn::random& random_obj)
{
    while (!done())
    {
        update(random_obj);
        bn::core::update();
    }
}
