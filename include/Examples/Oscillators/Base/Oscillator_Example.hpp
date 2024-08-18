#pragma once

#include "Core/AudioGenerator.hpp"

#include "Core/StereoSample.hpp"


namespace sc 
{

const double DEFAULT_FREQUENCY = 440.0;
const double DEFAULT_AMPLITUDE = 0.5;

//struct StereoSample;

class Oscillator_Example : public AudioGenerator 
{
public:
    Oscillator_Example(
        double frequency        = DEFAULT_FREQUENCY,
        double amplitude        = DEFAULT_AMPLITUDE,
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE,
        unsigned int bufferSize = DEFAULT_BUFFER_SIZE
    );

    void SetFrequency(double frequency);
    void SetAmplitude(double amplitude);

protected:
    //virtual StereoSample GetNextSample();
    
    double m_frequency;
    double m_amplitude;

private:
};

}
