#pragma once

#include <memory>

namespace sc
{

class AudioGenerator;

struct AudioEngine_Config
{
public:
    AudioEngine_Config(std::shared_ptr<AudioGenerator> generator);

    const std::shared_ptr<AudioGenerator> generator;

    bool debugOutSamples = false;
};

}
