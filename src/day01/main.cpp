#include <iostream>
#include "io.hpp"
#include "part01.hpp"
#include "part02.hpp"
#include <filesystem>

int main(int argc, char** argv) {
    const std::string inputPath = (argc > 1) ? argv[1] : "src/day01/input.txt";
    auto lines = aoc::read_lines(inputPath);
    std::cout << "Part1: " << day01::solve_part1(lines) << "\n";
    std::cout << "Part2: " << day02::solve_part2(lines) << "\n";
    return 0;
}