#pragma once

namespace sc 
{

const unsigned int DEFAULT_SAMPLE_RATE = 48000;
const unsigned int DEFAULT_BUFFER_SIZE = 1024;

struct StereoSample;

class AudioGenerator 
{
    friend class AudioEngine;

public:
    AudioGenerator(
        unsigned int sampleRate = DEFAULT_SAMPLE_RATE,
        unsigned int bufferSize = DEFAULT_BUFFER_SIZE
    );

protected:
    virtual StereoSample GetNextSample() = 0;

    const unsigned int m_sampleRate;
    const unsigned int m_bufferSize;

private:

};

}
