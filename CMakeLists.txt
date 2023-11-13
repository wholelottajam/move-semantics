cmake_minimum_required(VERSION 3.26)
project(move_semantics)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wpedantic -fno-elide-constructors)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.1.1
)

FetchContent_MakeAvailable(fmt)

add_executable(move_semantics
        main.cpp
        util/object_lifetime_tracker.h
        src/copy_elision.cpp
)

target_link_libraries(move_semantics PRIVATE fmt::fmt)