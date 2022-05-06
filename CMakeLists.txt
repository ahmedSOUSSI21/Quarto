cmake_minimum_required( VERSION 2.8 )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (Quarto)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Quarto main.cpp ${SRC_FILES})
target_include_directories(Quarto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

