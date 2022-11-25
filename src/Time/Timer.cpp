#include "Time/Timer.hpp"
#include <fmt/core.h>

using namespace std::chrono;

void Timer::Start()
{
    start = high_resolution_clock::now();
}
void Timer::Stop()
{
    end = high_resolution_clock::now();
}
double Timer::GetDuration() const
{
    return duration<double, std::milli>(end - start).count();
}
std::basic_string<char> Timer::GetStringDuration(const char *message) const
{
    return fmt::format("{} {}ms", message, GetDuration());
}
