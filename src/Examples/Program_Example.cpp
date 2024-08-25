#include "Examples/Program_Example.hpp"

#include <memory>
#include <iostream>

#include <SoundCrux.hpp>
#include "Examples/Oscillators/SineOsc_Example.hpp"

namespace sc
{

void Program_Example()
{
    std::shared_ptr<SineOsc_Example> generator = std::make_shared<SineOsc_Example>();

    AudioEngine_Config config;

    AudioEngine::InitAndStart(config, generator);

    std::cout << "Playing sine wave now" << std::endl;
    std::cout << "Press Enter to stop the program..." << std::endl;
  

    std::cin.get();
}

}
