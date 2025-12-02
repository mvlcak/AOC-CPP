#include "io.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace aoc {
    std::string read_file(const std::string& path) {
        std::ifstream in(path);
        if (!in) throw std::runtime_error("Failed to open: " + path);
        std::ostringstream ss;
        ss << in.rdbuf();
        return ss.str();
    }
    std::vector<std::string> read_lines(const std::string& path) {
        std::ifstream in(path);
        if (!in) throw std::runtime_error("Failed to open: " + path);
        std::vector<std::string> lines;
        std::string s;
        while (std::getline(in, s)) lines.push_back(s);
        return lines;
    }

    std::vector<idRange> split_day02(const std::string &path) {
        std::ifstream in(path);
        if (!in) throw std::runtime_error("Failed to open: " + path);
        std::vector<idRange> ranges;
        std::string s;
        while (std::getline(in, s, ','))
        {
            auto dash = s.find('-');
            if (dash == std::string::npos) continue; // or throw

            std::string first = s.substr(0, dash);
            std::string second = s.substr(dash + 1);
            ranges.emplace_back(idRange{std::stol(first), std::stol(second)});
        }
        return ranges;
    }
}
