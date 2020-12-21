//
// Created by Evan on 20/12/10.
//

#ifndef BLOCKSANDSTICKS_BLOCKRENDER_H
#define BLOCKSANDSTICKS_BLOCKRENDER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../include/GLM/glm/glm.hpp"
#include "../../include/GLM/glm/gtc/type_ptr.hpp"
#include "../../include/GLM/glm/gtc/matrix_transform.hpp"

#include "../../Shader.h"

#include <iostream>

class BlockRender {
private:
    int block_type;
    unsigned int VBO, VAO;
    glm::mat4 model;
public:
    BlockRender(int block_type);
    ~BlockRender();
    void gen_buffer();
    void load_texture(int BlockID, int face);
    void draw(Shader &, glm::vec3, int BlockID, int face);
};


#endif //BLOCKSANDSTICKS_BLOCKRENDER_H
