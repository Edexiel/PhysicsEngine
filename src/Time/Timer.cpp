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
float Timer::GetDuration() const
{
    return (float) duration_cast<milliseconds>(end - start).count();
}
std::basic_string<char> Timer::GetStringDuration(const char *message) const
{
    return fmt::format("{} {}ms", message, GetDuration());
}
