

#include <glad/glad.h>
#include <glfw3.h>

#include "../include/Shader.h"
#include "../include/camera.h"

#include "../include/GLM/glm/glm.hpp"
#include "../include/GLM/glm/gtc/type_ptr.hpp"
#include "../include/GLM/glm/gtc/matrix_transform.hpp"

#include <iostream>
#include "World/Chunk.h"
#include "World/ChunkManager.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void mouse_callback(GLFWwindow *window, double xpos, double ypos);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

void processInput(GLFWwindow *window);
// settings
namespace constants {
    const unsigned int SCR_WIDTH = 1920;
    const unsigned int SCR_HEIGHT = 1080;
    const char *VERTEX_SHADER_PATH = "../resources/shaders/shader.vert";
    const char *FRAGMENT_SHADER_PATH = "../resources/shaders/shader.frag";
}


// camera
Camera camera(glm::vec3(0.0f, 50.0f, 3.0f));
float lastX = constants::SCR_WIDTH / 2.0f;
float lastY = constants::SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // window creation
    GLFWwindow *window = glfwCreateWindow(constants::SCR_WIDTH, constants::SCR_HEIGHT, "Mining Away", NULL, NULL);
    if (window == NULL) // check for window
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // ???
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // ???
    glfwSetCursorPosCallback(window, mouse_callback); // mouse callback
    glfwSetScrollCallback(window, scroll_callback); // scroll callback
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // capture mouse
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glEnable(GL_DEPTH_TEST); // configure global opengl state
    // glClearColor(0.541f, 0.624f, 1.0f, 1.0f);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    // SHADING AND RENDER
    Shader ourShader(constants::VERTEX_SHADER_PATH, constants::FRAGMENT_SHADER_PATH);
    Chunk dbr(glm::vec3(0, 5, -1));
    // dbr.gen_buffer();
    dbr.load_texture(1, 0); // fix textures last
//
//    Chunk br(glm::vec3(-1, 2, -2));
//    br.gen_buffer();
//    br.load_texture(1, 0);

    ChunkManager cm(camera.chunk_position);
    cm.read();

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    std::cout << "prerender done" << std::endl;
    // render loop
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ourShader.use();
        camera.update(ourShader, constants::SCR_WIDTH, constants::SCR_HEIGHT);

        // experimental space
        // br.draw(ourShader);
        cm.update(ourShader, camera.chunk_position, camera.previous_chunk_position);

        camera.previous_chunk_position = camera.chunk_position;


        // CONTROL
        // dbr.default_block_draw(ourShader);
        // dbr.array_chunk_draw(ourShader);

        // glfw: swap buffers and poll IO events
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.ProcessKeyboard(SPACE, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.ProcessKeyboard(SHIFT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}