#include "part02.hpp"

#include <iostream>

#include "utils.hpp"

using namespace std;
using namespace aoc;

long day04::solve_part2(const std::vector<string> &lines) {

    CharMatrix charMatrix = fromLines(lines, '\0');
    size_t rows = charMatrix.getRows();
    size_t cols = charMatrix.getCols();
    long counter = 0;
    long previous_counter = -1;
    const char roll = '@';
    const char used_roll = 'x';
    while (previous_counter != counter) {
        previous_counter = counter;
        for (long i = 0; i<rows; i++) {
            for (long j = 0; j<cols; j++) {
                int roll_counter = 0;
                char c = charMatrix.at(i,j);
                vector<coordinates> coord_vector;
                if (c == roll) {
                    // -1 -1
                    if (i-1 >= 0 && j-1 >=0 && (charMatrix.at(i-1, j-1) == roll || charMatrix.at(i-1, j-1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // -1 0
                    if (i-1 >=0 && j >=0 && (charMatrix.at(i-1, j) == roll || charMatrix.at(i-1, j) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // -1 1
                    if (i-1 >=0 && j+1 < cols && (charMatrix.at(i-1, j+1) == roll || charMatrix.at(i-1, j+1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // 0 -1
                    if (i >= 0 && j-1 >= 0 && (charMatrix.at(i, j-1) == roll || charMatrix.at(i, j-1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // 0 1
                    if (i >= 0 && j+1 < cols && (charMatrix.at(i, j+1) == roll || charMatrix.at(i, j+1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // 1 -1
                    if (i+1 < rows && j-1 >= 0 && (charMatrix.at(i+1, j-1) == roll || charMatrix.at(i+1, j-1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // 1 0
                    if (i+1 < rows && j >= 0 && (charMatrix.at(i+1, j) == roll || charMatrix.at(i+1, j) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    // 1 1
                    if (i+1 < rows && j+1 < cols && (charMatrix.at(i+1, j+1) == roll || charMatrix.at(i+1, j+1) == used_roll)) {
                        roll_counter++;
                        coord_vector.push_back(coordinates(i, j));
                    }
                    if (roll_counter < 4) {
                        counter++;
                        coord_vector.push_back(coordinates(i, j));
                        for (coordinates coord : coord_vector) {
                            charMatrix.set(coord.row, coord.col, used_roll);
                        }
                    }
                }
            }
        }
        //charMatrix.print(std::cout);
        charMatrix.remove_used();
    }

    return counter;
}
