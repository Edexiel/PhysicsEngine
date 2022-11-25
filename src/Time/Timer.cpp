#include "Time/Timer.hpp"
#include <fmt/core.h>


void Timer::Start()
{

    start = std::chrono::high_resolution_clock::now();

}

void Timer::Stop()
{
    end = std::chrono::high_resolution_clock::now();
}

double Timer::GetDuration() const
{
    return std::chrono::duration<double, std::milli>(end - start).count();
}

std::basic_string<char> Timer::GetStringDuration(const char *message) const
{
    return fmt::format("{} {}ms", message, GetDuration());
}
