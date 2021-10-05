# Good practice to always define a minimum VERSION
cmake_minimum_required(VERSION 3.9)

# This property specifies the C++ standard whose features are requested to build this target
set (CMAKE_CXX_STANDARD 11)

# Set the project name (used for the PROJECT_NAME variable later on)
project(closedLoop)

# Specify that the CMake.js source code should be included when looking for header files
include_directories(${CMAKE_JS_INC})

# Specify what files should be compiled 
file(GLOB SOURCE_FILES src/cpp/hello.cc)

# Tell CMake that we are building a library, that it is shared (not static), and list the source code that should be compiled into it.
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

# This is a CMake.js thing, rename it as a .node file instead of a .so file so that it loads correctly.
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Include Node-API wrappers that make integration easier in C++
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

# Specify that the library should use the node-addon-api include directories in addition to the cmake js includes 
#  that were specified earlier
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

# Specify that the library should be linked to the CMake.js lib and napi libs needed for the addon module
target_link_libraries( ${PROJECT_NAME} PUBLIC
  ${NAPIPROJECT}
  ${CMAKE_JS_LIB}
)

# define NAPI_VERSION to ensure compatibility when running
add_definitions(-DNAPI_VERSION=3)