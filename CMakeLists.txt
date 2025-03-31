cmake_minimum_required(VERSION 3.10)
project(HelloOpenGLSDL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set path to local libraries
set(LIBS_DIR "C:/Users/daniele/Desktop/project/libs")

# Add GLAD
add_library(glad STATIC ${LIBS_DIR}/glad/src/glad.c)
target_include_directories(glad PUBLIC ${LIBS_DIR}/glad/include)

# Add GLFW

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
    IMPORTED_LOCATION "${LIBS_DIR}/glfw/glfw3.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBS_DIR}/glfw/include"
)	

# Add executable
add_executable(hello main.cpp DisplayManager.h DisplayManager.cpp EngineManager.h EngineManager.cpp ILogic.h ILogic.cpp TestGame.h TestGame.cpp RenderMgr.h RenderMgr.cpp)

set(GLM_INCLUDE_DIR "C:/Users/daniele/Desktop/project/libs/glm")
# Add the GLM include directory to your project
include_directories(${GLM_INCLUDE_DIR})

# # Set the path to your local Eigen headers
# set(EIGEN3_INCLUDE_DIR "C:/Users/daniele/Desktop/project/libs/eigen-3.3.8")

# include_directories(${EIGEN3_INCLUDE_DIR})

# Include directories
target_include_directories(hello PRIVATE 
    ${LIBS_DIR}/glad/include
    ${LIBS_DIR}/glfw/include
)

# Link libraries
target_link_libraries(hello PRIVATE glad glfw OpenGL32)