#pragma once

#include <algorithm>
#include <ios>
#include <vector>
#include <stdexcept>
#include <ostream>

namespace day04 {
    struct coordinates {
        size_t row;
        size_t col;
    };
    struct CharMatrix {
        size_t rows, cols;
        std::vector<char> data;

        CharMatrix(size_t r, size_t c, char fill = '\0')
            : rows(r), cols(c), data(r * c, fill) {}

        size_t idx(size_t i, size_t j) const { return i * cols + j; }

        char& at(size_t i, size_t j) {
            if (i >= rows || j >= cols) throw std::out_of_range("index");
            return data[idx(i, j)];
        }

        const char& at(size_t i, size_t j) const {
            if (i >= rows || j >= cols) throw std::out_of_range("index");
            return data[idx(i, j)];
        }

        void set(size_t i, size_t j, char fill) {
            data[idx(i, j)] = fill;
        }

        void remove_used() {
            std::replace(data.begin(), data.end(), 'x', '.');
        }

        void print(std::ostream& os) const {
            for (size_t i = 0; i < rows; ++i) {
                const char* rowPtr = data.data() + i * cols;
                os.write(rowPtr, static_cast<std::streamsize>(cols));
                os.put('\n');
            }
        }

        size_t getRows() const { return rows; }
        size_t getCols() const { return cols; }
    };
    CharMatrix fromLines(const std::vector<std::string>& lines, char pad = '\0');
}
