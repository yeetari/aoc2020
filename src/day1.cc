#include <Day.hh>
#include <Stream.hh>

#include <fmt/core.h>

static std::vector<int> s_inputs;

void create_input() {
    s_inputs.clear();
    Stream input("input/day1.txt");
    while (auto *line = input.next()) {
        s_inputs.push_back(std::stoi(*line));
    }
}

std::string solve_part_one() {
    // O(n^2)
    for (int x : s_inputs) {
        for (int y : s_inputs) {
            if (x + y == 2020) {
                return std::to_string(x * y);
            }
        }
    }
    return "Invalid input!";
}

std::string solve_part_two() {
    // O(n^3)
    for (int x : s_inputs) {
        for (int y : s_inputs) {
            for (int z : s_inputs) {
                if (x + y + z == 2020) {
                    return std::to_string(x * y * z);
                }
            }
        }
    }
    return "Invalid input!";
}
