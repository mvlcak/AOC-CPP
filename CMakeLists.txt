cmake_minimum_required(VERSION 3.20)
project(AOC_C__ CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Common library
add_library(aoc_lib
        src/lib/io.cpp
)
target_include_directories(aoc_lib PUBLIC src/lib)

# Helper to add a day target
function(aoc_day DAY)
    set(TGT day${DAY})
    add_executable(${TGT}
            src/day${DAY}/main.cpp
            src/day${DAY}/part01.cpp
            src/day${DAY}/part02.cpp
    )
    target_link_libraries(${TGT} PRIVATE aoc_lib)
    set_target_properties(${TGT} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    )
endfunction()

# Days
aoc_day(01)
