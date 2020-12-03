#include <Day.hh>
#include <Stream.hh>

#include <vector>

struct Input {
    unsigned min;
    unsigned max;
    char letter;
    std::string password;
};

static std::vector<Input> s_inputs;

void create_input() {
    s_inputs.clear();
    Stream stream("input/day2.txt");
    while (auto *line = stream.next()) {
        auto &input = s_inputs.emplace_back();
        int dash_idx = line->find_first_of('-');
        int space_idx = line->find_first_of(' ');
        input.min = std::stoi(line->substr(0, dash_idx));
        input.max = std::stoi(line->substr(dash_idx + 1, space_idx));
        input.letter = line->at(space_idx + 1);
        input.password = line->substr(space_idx + 4);
    }
}

std::string solve_part_one() {
    int num_valid = 0;
    for (const auto &input : s_inputs) {
        int letter_count = std::count(input.password.begin(), input.password.end(), input.letter);
        num_valid += static_cast<int>(letter_count >= input.min && letter_count <= input.max);
    }
    return std::to_string(num_valid);
}

std::string solve_part_two() {
    int num_valid = 0;
    for (const auto &input : s_inputs) {
        const auto &password = input.password;
        const char letter = input.letter;
        num_valid += static_cast<int>(password.at(input.min - 1) == letter ^ password.at(input.max - 1) == letter);
    }
    return std::to_string(num_valid);
}
