#include "benchmark.h"

#include "encryption/Key.h"

#include <iostream>

static void benchmark_three_d_one(benchmark::State& state) {
	const auto number_threads = state.range(0);

	const auto& keys = Holder::get_keys();

	for (auto _ : state) {
		const auto val = Key::get_smallest_hash_parallel(keys, number_threads);
		benchmark::DoNotOptimize(val);
	}

	const auto serial_answer = Key::get_smallest_hash(keys);
	const auto parallel_answer = Key::get_smallest_hash_parallel(keys, number_threads);

	if (serial_answer != parallel_answer) {
		std::cerr << "Serial and parallel answers don't match!\n";
	}
}

static void benchmark_three_f_one(benchmark::State& state) {
	const auto number_threads = state.range(0);
    const auto& keys = Holder::get_keys();

	for (auto _ : state) {
        const auto val = Key::find_key_parallel(keys, 0xF1,number_threads);
        benchmark::DoNotOptimize(val);


        const auto serial_answer = Key::find_key(keys, 0xF1);
        const auto parallel_answer = Key::find_key_parallel(keys, 0xF1, number_threads);

        if (serial_answer != parallel_answer) {
            std::cerr << "Serial and parallel answers don't match!\n";
        }
	}
}

BENCHMARK(benchmark_three_d_one)->Unit(benchmark::kMillisecond)->Arg(1);
BENCHMARK(benchmark_three_d_one)->Unit(benchmark::kMillisecond)->Arg(2);
BENCHMARK(benchmark_three_d_one)->Unit(benchmark::kMillisecond)->Arg(4);

BENCHMARK(benchmark_three_f_one)->Unit(benchmark::kMillisecond)->Arg(1);
BENCHMARK(benchmark_three_f_one)->Unit(benchmark::kMillisecond)->Arg(2);
BENCHMARK(benchmark_three_f_one)->Unit(benchmark::kMillisecond)->Arg(4);
