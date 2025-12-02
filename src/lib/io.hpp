#pragma once
#include <string>
#include <vector>

namespace aoc {
    std::string read_file(const std::string& path);
    std::vector<std::string> read_lines(const std::string& path);
    struct {
        long startId;
        long endId;
    }typedef idRange;
    std::vector<idRange> split_day02(const std::string& path);
}