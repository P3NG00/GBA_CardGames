#ifndef CG_SCENE_HPP
#define CG_SCENE_HPP

#include "bn_core.h"
#include "bn_random.h"

class scene
{
protected:
    scene();
    virtual ~scene() = default;
    virtual bool done() { return false; }
    virtual void update(bn::random& random_obj) {}
public:
    void execute(bn::random& random_obj);
};

#endif
