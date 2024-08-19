#pragma once

namespace sc 
{

const unsigned int DEFAULT_SAMPLE_RATE = 48000;

struct StereoSample;

class AudioGenerator 
{
    friend class AudioEngine;

public:
    AudioGenerator(
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE
    );

protected:
    virtual StereoSample GetNextSample() = 0;

    const unsigned int m_sampleRate;

private:

};

}
