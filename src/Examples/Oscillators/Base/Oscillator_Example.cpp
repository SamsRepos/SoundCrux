#include "Examples/Oscillators/Base/Oscillator_Example.hpp"

namespace sc 
{

Oscillator_Example::Oscillator_Example(
    double frequency,
    double amplitude,
    unsigned int sampleRate
)
:
AudioGenerator(sampleRate),
m_frequency(frequency),
m_amplitude(amplitude)
{
}


void Oscillator_Example::SetFrequency(double frequency)
{
    m_frequency = frequency;
}

void Oscillator_Example::SetAmplitude(double amplitude)
{
    m_amplitude = amplitude;
}


}
