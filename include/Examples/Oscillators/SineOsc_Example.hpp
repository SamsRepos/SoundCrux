#pragma once

#include "Examples/Oscillators/Base/Oscillator_Example.hpp"

namespace sc 
{

class SineOsc_Example : public Oscillator_Example
{
public:
    SineOsc_Example(
        double frequency        = DEFAULT_FREQUENCY,
        double amplitude        = DEFAULT_AMPLITUDE,
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE
    );

    virtual ~SineOsc_Example() = default;
    
protected:
    virtual StereoSample GetNextSample();

private:

};

}
