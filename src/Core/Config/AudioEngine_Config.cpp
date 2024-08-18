#include "Core/Config/AudioEngine_Config.hpp"

#include "Core/AudioGenerator.hpp"

namespace sc
{

AudioEngine_Config::AudioEngine_Config(std::shared_ptr<AudioGenerator> generator)
:
generator(generator)
{   
}

}
