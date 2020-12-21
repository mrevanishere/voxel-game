//
// Created by Evan on 20/12/12.
//

#ifndef BLOCKSANDSTICKS_WORLD_H
#define BLOCKSANDSTICKS_WORLD_H

#include "../../include/GLM/glm/glm.hpp"
#include "../../include/GLM/glm/gtc/type_ptr.hpp"
#include "../../include/GLM/glm/gtc/matrix_transform.hpp"

#include "BlockDef.h"

class World {
private:
    int initialLoad;
    int worldID;
public:
    World(int);
    void generate();
    void generate_new_chunk(glm::vec3);
    void update();
    bool changed();
};


#endif //BLOCKSANDSTICKS_WORLD_H
