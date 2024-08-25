#pragma once

#include <memory>

namespace sc
{

const unsigned int DEFAULT_BUFFER_SIZE = 1024;

struct AudioEngine_Config
{
public:
    unsigned int bufferSize = DEFAULT_BUFFER_SIZE;

    bool debugOutSamples = false;
};

}
