#include <Day.hh>
#include <Stream.hh>

#include <fmt/core.h>

#include <vector>

static std::vector<bool> s_inputs;
static int s_row_length;
static int s_num_columns;

static char at(int x, int y) {
    return s_inputs.at(x + y * s_row_length);
}

static int count_trees(int right, int down) {
    int x = 0;
    int y = 0;
    int num_trees = 0;
    while (y < s_num_columns) {
        num_trees += at(x % s_row_length, y);
        x += right;
        y += down;
    }
    return num_trees;
}

void create_input() {
    s_inputs.clear();
    s_row_length = 0;
    s_num_columns = 0;
    Stream stream("input/day3.txt");
    while (auto *line = stream.next()) {
        s_row_length = line->length();
        s_num_columns++;
        for (auto ch : *line) {
            s_inputs.push_back(ch == '#');
        }
    }
}

std::string solve_part_one() {
    return std::to_string(count_trees(3, 1));
}

std::string solve_part_two() {
    int result = 1;
    result *= count_trees(1, 1);
    result *= count_trees(3, 1);
    result *= count_trees(5, 1);
    result *= count_trees(7, 1);
    result *= count_trees(1, 2);
    return std::to_string(result);
}
