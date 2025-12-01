#pragma once
#include <string>
#include <vector>

namespace aoc {
    std::string read_file(const std::string& path);
    std::vector<std::string> read_lines(const std::string& path);
}