//
// Created by Evan on 20/12/10.
//

#include "Chunk.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../include/stb_image.h"

// move to BlockDef
const char *DIRT_IMAGE_PATH = "../resources/textures/dirt.jpg";
const char *STONE_IMAGE_PATH = "../resources/textures/stone.jpg";
const char *GRASS_IMAGE_PATH = "../resources/textures/grass.jpg";

Chunk::Chunk(glm::vec3 chunk_pos) {
    this->chunk_pos = chunk_pos;
    this->loaded = false;
    // std::cout << "Chunk constructor" << std::endl;
}

void Chunk::update_buffer(std::vector<int> blocks) {
    // just send a vector of indices to be skipped?
    // for i in vert:
        // if vert[i] == 0:
            // vertices[i*36, i*37) = null
    int entire = 0;
    if (entire) {
        // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    } else {
        // glBufferSubData(GL_ARRAY_BUFFER, )
    }
}

void Chunk::gen_buffer() {
    // if vertices
        //
    // else default

    // maybe move first 4 to constructor
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // std::cout << "Size of vertices: " << sizeof(vertices) << std::endl;
    // data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)(3 * sizeof(int)));
    glEnableVertexAttribArray(1);
    // std::cout << "VAO gen" << std::endl;
}

void Chunk::draw(Shader &shade) {
    glm::mat4 model = glm::mat4(1);
    model = glm::translate(model, chunk_pos*glm::vec3(16, 16, 16));
    shade.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void Chunk::default_chunk_gen_buffer() {
//    glGenVertexArrays(1, &VAO); // generate vertex array using &VAO
//    glGenBuffers(1, &VBO); // generates a buffer using the &VBO id
//    glBindVertexArray(VAO); //  binds vao to vertex array
//    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind vbo to the array buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(defvertices), defvertices, GL_STATIC_DRAW);
//    std::cout << glGetError() << std::endl;
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
}

void Chunk::default_chunk_draw(Shader &s) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 30.0f, -16.0f));
    s.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 884340);
}

void Chunk::default_block_gen_buffer() {
    glGenVertexArrays(1, &VAO); // generate vertex array using &VAO
    glGenBuffers(1, &VBO); // generates a buffer using the &VBO id
    glBindVertexArray(VAO); //  binds vao to vertex array
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind vbo to the array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(controlvertices), controlvertices, GL_STATIC_DRAW);
    std::cout << glGetError() << std::endl;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Chunk::default_block_draw(Shader &s) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 50.0f, 1.0f));
    s.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Chunk::array_chunk_gen_buffer() {
    glGenVertexArrays(1, &VAO); // generate vertex array using &VAO
    glGenBuffers(1, &VBO); // generates a buffer using the &VBO id
    glBindVertexArray(VAO); //  binds vao to vertex array
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind vbo to the array buffer
    glBufferData(GL_ARRAY_BUFFER, defchunk.size() * sizeof(int), defchunk.data(), GL_STATIC_DRAW);
    std::cout << "array vector buffer: " << glGetError() << std::endl;
    glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)(3 * sizeof(int)));
    glEnableVertexAttribArray(1);
    std::cout << "acg done" << std::endl;
}

void Chunk::array_chunk_draw(Shader &s) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, chunk_pos * glm::vec3(16, 16, 16));
    s.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, defchunk.size());
    // 884340
}

void Chunk::null_chunk_gen_buffer() {
    glGenVertexArrays(1, &VAO); // generate vertex array using &VAO
    glGenBuffers(1, &VBO); // generates a buffer using the &VBO id
    glBindVertexArray(VAO); //  binds vao to vertex array
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind vbo to the array buffer
    glBufferData(GL_ARRAY_BUFFER, nullChunk.size() * sizeof(int), nullChunk.data(), GL_STATIC_DRAW);
    std::cout << "null vector buffer: " << glGetError() << std::endl;
    glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)(3 * sizeof(int)));
    glEnableVertexAttribArray(1);
}

void Chunk::null_chunk_draw(Shader &s) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(2, 16, -2));
    s.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, nullChunk.size());
    // 884340
}

void Chunk::load_texture(int BlockID, int face) {
    // load and create a texture
    // -------------------------
    unsigned int texture1;
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load(DIRT_IMAGE_PATH, &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // end load texture

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
}

Chunk::~Chunk() {
    // ------------------------------------------------------------------------
    // std::cout << " chunkdes ";
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}