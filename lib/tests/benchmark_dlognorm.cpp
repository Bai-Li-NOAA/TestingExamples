#include "benchmark/benchmark.h"
#include "dlognorm.hpp"

void BM_dlgnorm(benchmark::State &state)
{
  for (auto _ : state)
    dlognorm(5.0, 10.0, 2.5);
}
BENCHMARK(BM_dlgnorm);