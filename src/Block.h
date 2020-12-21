//
// Created by Evan on 20/12/09.
//

#ifndef BLOCKSANDSTICKS_BLOCK_H
#define BLOCKSANDSTICKS_BLOCK_H

#include <glad/glad.h>
#include <glfw3.h>

#include "../include/Shader.h"
#include "../include/camera.h"
#define STB_IMAGE_IMPLEMENTATION

#include "../include/GLM/glm/glm.hpp"
#include "../include/GLM/glm/gtc/type_ptr.hpp"
#include "../include/GLM/glm/gtc/matrix_transform.hpp"
#include <iostream>
#include <string>
#include <map>

//extern const float vertices[];
//extern const glm::vec3 cubePositions[];
// extern const std::map<int, std::string, std::string> BLOCK_IDS;

class Block {
private:
    int x,y,z,w;
    int BlockID;
    glm::vec3 coord;
    std::string load_texture(int);
    void draw_block(std::string);
    static std::string get_texture_path(int);
    Shader *s;
public:
    Block(int, int, int, int, int, Shader &);
    ~Block();
    std::string get_block_name();
    int get_block_id();

    // loads texture to the block
    int set_block(int);
    int place_block(int);
    int break_block(int);

};


#endif //BLOCKSANDSTICKS_BLOCK_H
