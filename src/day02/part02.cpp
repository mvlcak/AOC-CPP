#include "part02.hpp"

#include <iostream>
using namespace std;
using namespace aoc;

long day02::solve_part2(const std::vector<idRange> &ranges) {
    long count = 0;
    for (const auto& range : ranges) {
        for (long i = range.startId; i <= range.endId; i++) {
            int digits = (i == 0) ? 1 : (int)log10(i) + 1;
            string num = to_string(i);

            string repeated;
            for (long d = 1; d <= digits / 2; d++) {
                cout << "Digit "<< d <<" \n";
                if (digits % d != 0) {
                    continue;
                }

                bool match = true;
                for (long j = 0; j < digits-d; j++) {
                    cout << "Comparing "<< j << " " << num[j+d] << " and " << j+d << " " << num[j + d] << "\n";

                    if (num[j] != num[j+d]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    cout << "Valid ID: "<< num<<"\n";
                    count += i;
                    break;
                }
            }
        }
    }
    return count;
}