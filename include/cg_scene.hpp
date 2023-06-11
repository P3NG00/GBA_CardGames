#ifndef CG_SCENE_HPP
#define CG_SCENE_HPP

#include "bn_core.h"
#include "bn_random.h"

#include "cg_text_handler.hpp"

class scene
{
protected:
    scene();
    virtual bool done();
    virtual void update(bn::random& random_obj, text_handler& texthandler);
public:
    virtual ~scene() = default;
    void execute(bn::random& random_obj, text_handler& texthandler);
};

#endif
