#include "Timer/Timer.hpp"

#include <iomanip>
#include <sstream>

Timer::Timer() : mStartTime{}, mLastTickTime{}, mPausedDuration(Clock::duration::zero()), mPaused(false), mStarted(false)
{
}

void Timer::start()
{
    mStarted = true;
    mPaused = false;
    mStartTime = Clock::now();
    mLastTickTime = mStartTime;
    mPausedDuration = Clock::duration::zero();
}

void Timer::stop()
{
    mStarted = false;
    mPaused = false;
    mStartTime = TimePoint{};
    mLastTickTime = TimePoint{};
    mPausedDuration = Clock::duration::zero();
}

void Timer::pause()
{
    if (mStarted && !mPaused)
    {
        mPaused = true;
        mPausedDuration = Clock::now() - mStartTime;
    }
}

void Timer::unpause()
{
    if (mStarted && mPaused)
    {
        mPaused = false;
        mStartTime = Clock::now() - mPausedDuration;
        mLastTickTime = mStartTime;
        mPausedDuration = Clock::duration::zero();
    }
}

float Timer::getElapsedSeconds() const
{
    if (!mStarted)
    {
        return 0.0f;
    }

    if (mPaused)
    {
        return std::chrono::duration<float>(mPausedDuration).count();
    }

    return std::chrono::duration<float>(Clock::now() - mStartTime).count();
}

uint64_t Timer::getElapsedMilliseconds() const
{
    if (!mStarted)
    {
        return 0;
    }

    if (mPaused)
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(mPausedDuration).count();
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - mStartTime).count();
}

uint64_t Timer::getDeltaMilliseconds()
{
    if (!mStarted || mPaused)
    {
        return 0;
    }

    const TimePoint now = Clock::now();
    const uint64_t delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - mLastTickTime).count();
    mLastTickTime = now;
    return delta;
}

bool Timer::hasElapsed(float seconds) const
{
    return getElapsedSeconds() >= seconds;
}

std::string Timer::toString() const
{
    const float total = getElapsedSeconds();
    const int m = static_cast<int>(total) / 60;
    const float s = total - static_cast<float>(m * 60);

    std::ostringstream oss;

    if (m > 0)
    {
        oss << m << "m ";
    }

    oss << std::fixed << std::setprecision(2) << s << "s";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Timer& timer)
{
    os << timer.toString();
    return os;
}

bool Timer::isStarted() const
{
    return mStarted;
}

bool Timer::isPaused() const
{
    return mPaused && mStarted;
}
