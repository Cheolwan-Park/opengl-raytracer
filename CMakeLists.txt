cmake_minimum_required (VERSION 3.8)
project ("opengl-raytracer")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)
message(STATUS "module path: ${CMAKE_MODULE_PATH}")

set(CMAKE_CXX_STANDARD 20)
add_compile_options( -Os )
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -Os" )
if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17" )
    set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG" )
else()
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )
    set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g" )
endif()


add_executable (opengl-raytracer 
"src/main.cpp" "src/Application.cpp" "src/Application.hpp" "src/Camera.hpp" "src/Input.cpp" "src/Input.hpp" 
"src/Shader.cpp" "src/Shader.hpp" "src/Texture.cpp" "src/Texture.hpp" "src/util.hpp")

# sdl
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(opengl-raytracer ${SDL2_LIBRARY})

# opengl
find_package ( OpenGL REQUIRED )
if (OPENGL_FOUND )
    target_link_libraries ( opengl-raytracer ${OPENGL_LIBRARY} )
    target_link_libraries ( opengl-raytracer ${OPENGiL_gl_LIBRARY} )
    target_link_libraries ( opengl-raytracer ${OPENGL_glu_LIBRARY} )
endif()

# glm
find_package( GLM REQUIRED )
if( GLM_FOUND )
    include_directories( ${GLM_INCLUDE_DIRS} )
endif()

# glew
find_package( GLEW REQUIRED )
if( GLEW_FOUND )
    include_directories( ${GLEW_INCLUDE_DIR} )
    target_link_libraries( opengl-raytracer ${GLEW_LIBRARY} )
endif()

# imgui
FILE(GLOB IMGUI_SRC imgui/*.cpp)
add_library(
        imgui
        ${IMGUI_SRC}
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_sdl.cpp
)
target_link_libraries(opengl-raytracer imgui)
include_directories( imgui/ )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DIMGUI_IMPL_OPENGL_LOADER_GLEW" )

# SOIL2
add_library(
        soil2
        SOIL2/src/SOIL2/image_DXT.c
        SOIL2/src/SOIL2/image_helper.c
        SOIL2/src/SOIL2/SOIL2.c
        SOIL2/src/SOIL2/wfETC.c
        SOIL2/src/common/common.cpp
)
target_link_libraries(opengl-raytracer soil2)
include_directories(SOIL2/src/)
