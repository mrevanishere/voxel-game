//
// Created by Evan on 20/12/09.
//

#include "Block.h"
// #include "include/stb_image.h"


Block::Block(int x, int y, int z, int w, int BlockID, Shader &mainShader) {
    std::cout << "Block constructor" << std::endl;
    this->coord = glm::vec3(x, y, z);
    this->w = w;
    this->s = &mainShader;
    this->set_block(this->BlockID);

}

// laod texture of BID and bind to shader?
int Block::set_block(int ID) {
    std::cout << "set_block()" << std::endl;


    this->BlockID = ID;
    draw_block(load_texture(ID));


    std::cout << "complete" << std::endl;
    return 0;
}

void Block::draw_block(std::string texture) {
    std::cout << "draw_block()";


    glm::mat4 model = glm::mat4(1.0f); // initialize with identity matrix
    model = glm::translate(model, this->coord); // translate to world position
    this->s->setMat4("model", model); // shader
    glDrawArrays(GL_TRIANGLES, 0, 36); // draw Block


    std::cout << "complete" << std::endl;
}

std::string Block::load_texture(int ID) {
    std::cout << "load_texture() complete" << std::endl;
    return "texture1";
}

std::string Block::get_texture_path(int ID) {
    if (true) {
        return "resources/textures/grass.jpg";
    }
    else {
        return "NONE";
    }
    return "";
}

Block::~Block() {
    std::cout << "destructor ";
    delete[] this->s;
    std::cout << " complete " << std::endl;
}

