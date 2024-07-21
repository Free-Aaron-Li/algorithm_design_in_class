project(sort_algorithms)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set_directory_properties(${PROJECT_SOURCE_DIR}/asset)


set(SOURCES
        include/Sort.hpp
        src/main.cpp
        src/Sort.cpp
        ../stack_and_queue/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

#------------------------------------
# head files
#------------------------------------

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

#------------------------------------
# packages
#------------------------------------
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)