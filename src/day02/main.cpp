#include <iostream>
#include "io.hpp"
#include "part01.hpp"
#include "part02.hpp"
#include <filesystem>

int main(int argc, char** argv) {
    const std::string inputPath = (argc > 1) ? argv[1] : "src/day02/input.txt";
    auto ranges = aoc::split_day02(inputPath);
    std::cout << "Part1: " << day02::solve_part1(ranges) << "\n";
    std::cout << "Part2: " << day02::solve_part2(ranges) << "\n";
    return 0;
}