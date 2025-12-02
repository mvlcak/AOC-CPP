#include "part01.hpp"

#include <iostream>

#include "io.hpp"

using namespace day01;

long day01::solve_part1(const std::vector<std::string> &lines) {
    int current_position=50;
    long counter = 0;
    for (const auto &line : lines) {
        char direction = line[0];
        int shift = std::stoi(line.substr(1, line.size() - 1));
        shift_position(direction, current_position, shift);
        if (current_position == 0) {
            counter++;
        }
    }
    return counter;
}

int day01::shift_position(const char& side, int& position, const int& shift) {

    if (side == 'L') {
        position -= shift % 100;


        if (position < 0) {
            position += 100;
        }
    } else if (side == 'R') {
        position += shift % 100;
        if (position > 99) {
            position -=  100;
        }
    }
    return position;

}
