#ifndef PHYSICSENGINE_TIMER_HPP
#define PHYSICSENGINE_TIMER_HPP

#include <chrono>
#include <string>

class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start, end;

public:
    void Start();
    void Stop();

    double GetDuration() const;
    std::basic_string<char> GetStringDuration(const char *) const;

};


#endif //PHYSICSENGINE_TIMER_HPP
