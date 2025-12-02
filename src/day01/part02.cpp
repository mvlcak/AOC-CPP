#include "part02.hpp"

#include <iostream>

long day01::solve_part2(const std::vector<std::string> &lines) {
    int current_position=50;
    long counter = 0;
    for (const auto &line : lines) {
        char direction = line[0];
        int shift = std::stoi(line.substr(1, line.size() - 1));
        shift_position(direction, current_position, shift, counter);
        if (current_position == 0) {
            counter++;
        }
    }
    return counter;
}

int day01::shift_position(const char& side, int& position, const int& shift, long& counter) {
    int previous_position = position;
    if (side == 'L') {
        position -= shift % 100;
        counter += shift / 100;

        if (position < 0) {
            position += 100;
            if (position != 0 && previous_position != 0) {
                counter++;
            }
        }
    } else if (side == 'R') {
        position += shift % 100;
        counter += shift / 100;
        if (position > 99) {
            position -=  100;
            if (position != 0 && previous_position != 0) {
                counter++;
            }
        }
    }
    return position;

}