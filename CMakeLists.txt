cmake_minimum_required(VERSION 3.17)
project(blocksandsticks)
set(CMAKE_CXX_STANDARD 14)
# set(SOURCE_FILES main.cpp)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
#MATH(EXPR heap_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--heap,${heap_size}")


add_executable(${PROJECT_NAME} src/main.cpp
        include/Shader.h
        include/stb_image.h
        include/camera.h
        src/Block.h
        src/World/Chunk.cpp
        src/World/Chunk.h
        src/World/World.cpp
        src/World/World.h
        src/World/BlockDef.h
        src/World/ChunkManager.cpp
        src/World/ChunkManager.h
        src/World/DefaultChunkVertices.h src/World/ChunkVertices.h)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/include")
include(FindPkgConfig)

find_package(GLAD REQUIRED)
include_directories(${GLAD_INCLUDE_DIR})

find_package(glfw3 REQUIRED)
include_directories(${GLFW3_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} GLAD ${GLFW3_LIBRARY})
