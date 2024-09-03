#include "Examples/Oscillators/SawtoothOsc_Example.hpp"

namespace sc
{

SawtoothOsc_Example::SawtoothOsc_Example(
    double frequency,
    double amplitude,
    unsigned int sampleRate
)
:
Oscillator_Example(frequency, amplitude, sampleRate)
{

}

StereoSample SawtoothOsc_Example::GetNextSample()
{
    static Sample sample = Sample(m_amplitude);

    sample -= Sample( (2 * m_amplitude) / (m_sampleRate / m_frequency) );

    if(sample <= Sample(-m_amplitude)) 
    {
        sample = Sample(m_amplitude);
    }

    return StereoSample(sample);
}


}
