#include "part01.hpp"

#include <iostream>

#include "utils.hpp"

using namespace day04;
using namespace std;
long day04::solve_part1(const std::vector<string> &lines) {
    CharMatrix charMatrix = fromLines(lines, '\0');
    size_t rows = charMatrix.getRows();
    size_t cols = charMatrix.getCols();
    long counter = 0;
    const char roll = '@';
    for (long i =0; i<rows; i++) {
        for (long j=0; j<cols; j++) {
            int roll_counter = 0;
            char c = charMatrix.at(i,j);
            if (c == roll) {
                // -1 -1
                if (i-1 >= 0 && j-1 >=0 && charMatrix.at(i-1, j-1) == roll) {
                    roll_counter++;
                }
                // -1 0
                if (i-1 >=0 && j >=0 && charMatrix.at(i-1, j) == roll) {
                    roll_counter++;
                }
                // -1 1
                if (i-1 >=0 && j+1 < cols && charMatrix.at(i-1, j+1) == roll) {
                    roll_counter++;
                }
                // 0 -1
                if (i >= 0 && j-1 >= 0 && charMatrix.at(i, j-1) == roll) {
                    roll_counter++;
                }
                // 0 1
                if (i >= 0 && j+1 < cols && charMatrix.at(i, j+1) == roll) {
                    roll_counter++;
                }
                // 1 -1
                if (i+1 < rows && j-1 >= 0 && charMatrix.at(i+1, j-1) == roll) {
                    roll_counter++;
                }
                // 1 0
                if (i+1 < rows && j >= 0 && charMatrix.at(i+1, j) == roll) {
                    roll_counter++;
                }
                // 1 1
                if (i+1 < rows && j+1 < cols && charMatrix.at(i+1, j+1) == roll) {
                    roll_counter++;
                }
                if (roll_counter < 4) {
                    counter++;
                }
            }
        }
    }
    return counter;
}