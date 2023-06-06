#ifndef CG_SCENE_HPP
#define CG_SCENE_HPP

#include "bn_core.h"

class scene
{
protected:
    scene();
    virtual ~scene() = default;
    virtual void update() {}
    virtual bool done() { return false; }
public:
    void execute();
};

#endif
