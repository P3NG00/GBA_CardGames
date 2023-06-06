#include "cg_scene.hpp"

scene::scene()
{
}

void scene::execute(bn::random& random_obj)
{
    while (!done())
    {
        update(random_obj);
        bn::core::update();
    }
}
