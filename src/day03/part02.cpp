#include "part02.hpp"

#include <iostream>

#include "utils.hpp"
using namespace std;
using namespace aoc;

long day03::solve_part2(const std::vector<string> &lines) {
    long count = 0;
    for (const auto &line : lines) {
        int joltage [12] = {0};
        std::fill(std::begin(joltage), std::end(joltage), 0);
        for (std::size_t i = 0; i < line.size(); i++) {
            int num = char_to_int(line[i]);
            for (int k = 0, j=11; k < 12; k++, j--) {
                if (num>joltage[k] && i < line.size() - j) {
                    joltage[k] = num;
                    for (int l = k+1; l < 12; l++) {
                        joltage[l] = 0;
                    }
                    break;
                }
            }
        }
        //cout << max1 << " " << max2 << "\n";

        for (int i = 0, j =11; i<12; i++, j--) {
            count += joltage[i]*pow(10, j);
        }
    }
    return count;
}
