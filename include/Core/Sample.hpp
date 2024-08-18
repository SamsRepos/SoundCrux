#pragma once

#include <cstdint>

namespace sc 
{

struct Sample 
{
public:
    int16_t value;

    Sample();
    Sample(int16_t sample);
    Sample(double sample);

    operator int16_t() const;

    Sample& operator-=(const Sample& other);
    Sample& operator-=(int16_t other);

    Sample& operator+=(const Sample& other);
    Sample& operator+=(int16_t other);
};

}
