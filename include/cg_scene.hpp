#ifndef CG_SCENE_HPP
#define CG_SCENE_HPP

#include "bn_core.h"
#include "bn_random.h"

class scene
{
protected:
    scene();
    virtual bool done();
    virtual void update(bn::random& random_obj);
public:
    virtual ~scene() = default;
    void execute(bn::random& random_obj);
};

#endif
