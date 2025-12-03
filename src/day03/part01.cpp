#include "part01.hpp"

#include <iostream>

#include "io.hpp"
#include "utils.hpp"

using namespace day03;
using namespace std;
long day03::solve_part1(const std::vector<string> &lines) {
    long count = 0;
    for (const auto &line : lines) {
        int max1 = 0;
        int max2 = 0;
        for (std::size_t i = 0; i < line.size(); i++) {
            int num = char_to_int(line[i]);
            if (num > max1 && i != line.size() - 1) {
                max1 = num;
                max2 = 0;
            } else if (num > max2) {
                max2 = num;
            }
        }
    }
    return count;
}

namespace day03 {
    int char_to_int(const char& c) {
        return static_cast<int>(c - '0');
    }
}