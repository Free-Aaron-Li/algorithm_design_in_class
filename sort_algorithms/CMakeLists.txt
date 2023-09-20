cmake_minimum_required(VERSION 3.24)
project(sort_algorithms)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set_directory_properties(${PROJECT_SOURCE_DIR}/assert)


set(SOURCES
        src/main.cpp
)

#------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)