#include "Core/StereoSample.hpp"

namespace sc
{

StereoSample::StereoSample()
{

}

StereoSample::StereoSample(Sample value)
{
    left = right = value;
}

StereoSample& StereoSample::operator=(Sample value) {
    left = right = value;
    return *this;
}

}
