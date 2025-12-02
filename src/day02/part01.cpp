#include "part01.hpp"

#include <iostream>

#include "io.hpp"

using namespace day02;
using namespace std;
long day02::solve_part1(const std::vector<aoc::idRange> &ranges) {
    long count = 0;
    for (const auto& range : ranges) {
        for (long i = range.startId; i <= range.endId; i++) {
            int digits = (i == 0) ? 1 : (int)log10(i) + 1;
            if (digits % 2 == 0) {
                string num = to_string(i);
                bool match = true;
                for (long j = 0; j < digits / 2; j++) {
                    if (num[j] != num[j + digits / 2]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    count += i;
                }
            }
        }
    }
    return count;
}
