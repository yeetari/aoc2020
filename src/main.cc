#include <Day.hh>

#include <benchmark/benchmark.h>
#include <fmt/core.h>

static void run(benchmark::State &state) {
    for (auto _ : state) {
        solve_part_one();
        solve_part_two();
    }
}

BENCHMARK(run)->Unit(benchmark::kMillisecond);

int main(int argc, char **argv) {
    if (argc != 1 && argc != 2) {
        fmt::print("Usage: {} [--bench]\n", argv[0]);
        return 1;
    }
    const bool bench = argc == 2;
    if (bench && strcmp(argv[1], "--bench") != 0) {
        fmt::print("Unknown option {}\n", argv[1]);
        return 1;
    }
    create_input();
    if (!bench) {
        fmt::print("Part one: {}\n", solve_part_one());
        fmt::print("Part two: {}\n", solve_part_two());
        return 0;
    }
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}
