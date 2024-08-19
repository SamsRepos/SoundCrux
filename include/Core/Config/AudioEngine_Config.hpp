#pragma once

#include <memory>

namespace sc
{

const unsigned int DEFAULT_BUFFER_SIZE = 1024;

class AudioGenerator;

struct AudioEngine_Config
{
public:
    AudioEngine_Config(std::shared_ptr<AudioGenerator> generator);

    const std::shared_ptr<AudioGenerator> generator;

    unsigned int bufferSize = DEFAULT_BUFFER_SIZE;

    bool debugOutSamples = false;
};

}
