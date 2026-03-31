#pragma once
#include <chrono>
#include <cstdint>
#include <ostream>
#include <string>

class Timer
{
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    float getElapsedSeconds() const;
    uint64_t getElapsedMilliseconds() const;
    uint64_t getDeltaMilliseconds();

    bool hasElapsed(float seconds) const;
    std::string toString() const;

    bool isStarted() const;
    bool isPaused() const;

    friend std::ostream& operator<<(std::ostream& os, const Timer& timer);

private:
    using Clock = std::chrono::steady_clock;
    using TimePoint = Clock::time_point;

    TimePoint mStartTime;
    TimePoint mLastTickTime;
    Clock::duration mPausedDuration;

    bool mPaused;
    bool mStarted;
};