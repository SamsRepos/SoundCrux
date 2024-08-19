#include "Examples/Oscillators/SineOsc_Example.hpp"

#include <cmath>

namespace sc
{

const double PI = 3.14159265358979323846;

SineOsc_Example::SineOsc_Example(
    double frequency,
    double amplitude,
    unsigned int sampleRate
)
:
Oscillator_Example(frequency, amplitude, sampleRate)
{

}

StereoSample SineOsc_Example::GetNextSample()
{
    static double phase = 0.0;
    const double increment = 2.0 * PI * m_frequency / m_sampleRate;

    Sample sample = Sample(m_amplitude * sin(phase));

    phase += increment;
    if (phase >= 2.0 * PI) phase -= 2.0 * PI;

    return StereoSample(sample);
}


}
