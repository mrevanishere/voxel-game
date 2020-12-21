set(FIND_GLFW3_PATHS
        ${CMAKE_SOURCE_DIR}/include/GLFW3
        ${CMAKE_SOURCE_DIR}/include/GLFW3/lib-mingw
#        ${CMAKE_SOURCE_DIR}/include/GLFW3/lib-mingw-w64
        ${CMAKE_SOURCE_DIR}/include/GLFW3/include
        ${CMAKE_SOURCE_DIR}/include/GLFW3/include/GLFW
)


find_path(GLFW3_INCLUDE_DIR glfw3.h
        PATH_SUFFIXES include
        PATHS ${FIND_GLFW3_PATHS})


find_library(GLFW3_LIBRARY
        NAMES glfw3
        PATH_SUFFIXES lib
        PATHS ${FIND_GLFW3_PATHS})

#add_library("glfw3" "${CMAKE_SOURCE_DIR}/include/glfw3/lib-mingw-w64/libglfw3.a")
#target_include_directories("glfw3" PRIVATE "${CMAKE_SOURCE_DIR}/include/glfw3/include")
#target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/glfw3/include")
