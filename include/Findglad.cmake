set(FIND_GLAD_PATHS
        ${CMAKE_SOURCE_DIR}/include/GLAD
        ${CMAKE_SOURCE_DIR}/include/GLAD/src
        ${CMAKE_SOURCE_DIR}/include/GLAD/include
        ${CMAKE_SOURCE_DIR}/include/GLAD/include/glad
        ${CMAKE_SOURCE_DIR}/include/GLAD/include/KHR
)

find_path(GLAD_INCLUDE_DIR glad.h
        PATH_SUFFIXES include
        PATHS ${FIND_GLAD_PATHS})

add_library("GLAD" "${CMAKE_SOURCE_DIR}/include/GLAD/src/glad.c" ../src/Block.cpp ../src/Block.h)
target_include_directories("GLAD" PRIVATE "${CMAKE_SOURCE_DIR}/include/GLAD/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/GLAD/include")

