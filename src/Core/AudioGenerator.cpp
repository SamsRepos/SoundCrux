#include "Core/AudioGenerator.hpp"

namespace sc
{
    AudioGenerator::AudioGenerator(
        unsigned int sampleRate,
        unsigned int bufferSize
    )
    :
    m_sampleRate(sampleRate),
    m_bufferSize(bufferSize)
    {

    }
}
