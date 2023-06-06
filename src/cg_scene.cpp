#include "cg_scene.hpp"

scene::scene()
{
}

void scene::execute()
{
    while (!done())
    {
        update();
        bn::core::update();
    }
}
