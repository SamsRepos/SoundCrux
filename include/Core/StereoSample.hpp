#pragma once

#include "Core/Sample.hpp"

namespace sc 
{

struct StereoSample
{
public:
    Sample left;
    Sample right;

    StereoSample();
    StereoSample(Sample value);

    StereoSample& operator=(Sample value);
};

}
