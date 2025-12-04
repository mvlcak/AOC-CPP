
#include "utils.hpp"
#include <string>
#include <vector>

using namespace day04;
namespace day04 {
    CharMatrix fromLines(const std::vector<std::string>& lines, char pad) {
        size_t rows = lines.size();
        size_t cols = rows ? lines[0].size() : 0;
        CharMatrix m(rows, cols, pad);
        for (size_t i = 0; i < rows; ++i) {
            if (lines[i].size() != cols) throw std::runtime_error("inconsistent width");
            for (size_t j = 0; j < cols; ++j) {
                m.at(i, j) = lines[i][j];
            }
        }
        return m;
    }

}
