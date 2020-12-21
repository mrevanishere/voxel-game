//
// Created by Evan on 20/12/12.
//

#ifndef BLOCKSANDSTICKS_CHUNKMANAGER_H
#define BLOCKSANDSTICKS_CHUNKMANAGER_H

#include "../../include/GLM/glm/glm.hpp"
#include "../../include/GLM/glm/gtc/type_ptr.hpp"
#include "../../include/GLM/glm/gtc/matrix_transform.hpp"

#include "Chunk.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <set>

class ChunkManager {
private:
    int render_distance = 3;
    std::vector<Chunk> chunks;
    // std::vector<std::unique_ptr<Chunk>> chunkptrs;
    std::vector<int> blocks;
    std::map<int, std::vector<int>> chunkBuffer;
    // Flat[x + (y*HEIGHT) + (z*WIDTH*HEIGHT)] =  Original[x,y,z]
public:
    explicit ChunkManager(glm::vec3 camera_chunk_pos);
    ~ChunkManager();
    void update(Shader &shader, glm::vec3 camera_chunk_pos, glm::vec3 previous_chunk_position);
    void load(Chunk &);
    void read();
    void write();

    // void add_block(glm::vec3 pos, int BlockID);
    // int rem_block(glm::vec3 pos, int strength);
};


#endif //BLOCKSANDSTICKS_CHUNKMANAGER_H
