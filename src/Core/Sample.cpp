#include "Core/Sample.hpp"

#include <algorithm>
#include <limits>

namespace sc 
{
    Sample::Sample()
    :
    value(0)
    {
    }

    Sample::Sample(int16_t value)
    : 
    value(value)
    {

    }

    Sample::Sample(double amplitude) 
    {
        amplitude = std::clamp(amplitude, -1.0, 1.0);
        value = static_cast<int16_t>(amplitude * std::numeric_limits<int16_t>::max());
    }

    Sample::operator int16_t() const 
    {
        return value;
    }


    Sample& Sample::operator-=(const Sample& other)
    {
        value -= other.value;
        return *this;
    }

    Sample& Sample::operator-=(int16_t other)
    {
        value -= other;
        return *this;
    }

    Sample& Sample::operator+=(const Sample& other)
    {
        value += other.value;
        return *this;
    }

    Sample& Sample::operator+=(int16_t other)
    {
        value += other;
        return *this;
    }

}
