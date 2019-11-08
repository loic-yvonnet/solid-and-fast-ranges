cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(GCC_COMPILE_FLAGS "-Wall -Wextra -Werror -Wsuggest-override -Wno-register -Wno-missing-braces -Wno-unknown-pragmas -fdiagnostics-show-option")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")
set(range-v3_DIR "/vcpkg/packages/range-v3_x64-linux/share/range-v3")
find_package(range-v3 CONFIG REQUIRED)
project(hello_world)
add_executable(hello_world
                    src/main.cpp
)
target_link_libraries(hello_world PRIVATE meta concepts range-v3)
