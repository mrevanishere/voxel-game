//
// Created by Evan on 20/12/10.
//

#ifndef BLOCKSANDSTICKS_CHUNK_H
#define BLOCKSANDSTICKS_CHUNK_H

#include <glad/glad.h>
#include <glfw3.h>

#include "../../include/GLM/glm/glm.hpp"
#include "../../include/GLM/glm/gtc/type_ptr.hpp"
#include "../../include/GLM/glm/gtc/matrix_transform.hpp"

#include "../../include/Shader.h"
#include "DefaultChunkVertices.h"

#include "ChunkVertices.h"

#include <iostream>
#include <vector>
#include <array>

class Chunk {
private:
    unsigned int VBO, VAO, EBO;
    std::array<int, defchunk.size()> vertices = defchunk;
public:
    bool loaded;
    glm::vec3 chunk_pos;

    Chunk(glm::vec3 chunk_pos);
    ~Chunk();
    void gen_buffer();
    void update_buffer(std::vector<int> blocks);
    void load_texture(int BlockID, int face);
    void draw(Shader &);

    void default_block_draw(Shader &);
    void default_block_gen_buffer();
    void default_chunk_draw(Shader &);
    void default_chunk_gen_buffer();
    void array_chunk_gen_buffer();
    void array_chunk_draw(Shader &);
    void null_chunk_gen_buffer();
    void null_chunk_draw(Shader &);
};


#endif //BLOCKSANDSTICKS_CHUNK_H
