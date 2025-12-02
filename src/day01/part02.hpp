#pragma once
#include <vector>
#include <string>
namespace day01 {
    long solve_part2(const std::vector<std::string>& lines);
    int shift_position(const char& side, int& position, const int& shift, long& counter);
}