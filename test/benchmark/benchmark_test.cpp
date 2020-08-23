#include <benchmark/benchmark.h>
#include <state_machine_factory.h>

class StateMachineGeneratorBenchmark : public ::benchmark::Fixture
{
public:
    StateMachineGeneratorBenchmark()
    {
        Repetitions(20);
        ReportAggregatesOnly(false);
        Unit(benchmark::kMicrosecond);
    }

    void RunBenchmark(benchmark::State& state)
    {
        for(auto _ : state)
        {
            using namespace state_machine;
            std::string csv_file_name{"data/weather_intent_data.csv"};
            auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
            benchmark::ClobberMemory();
            state.counters["count"] = 1;
            state.counters["Rate"] = ::benchmark::Counter(1,benchmark::Counter::kIsRate);
        }
    }
};

BENCHMARK_F(StateMachineGeneratorBenchmark, CsvFile)(benchmark::State& state)
{
    RunBenchmark(state);
}

BENCHMARK_MAIN();
