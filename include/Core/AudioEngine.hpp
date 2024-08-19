#pragma once

#include <memory>
#include <thread>
#include <string>
#include <vector>

#include <AL/al.h>
#include <AL/alc.h>

#include "Core/Config/AudioEngine_Config.hpp"


namespace sc 
{
    
const int NUM_CHANNELS = 2;
const int NUM_BUFFERS  = 2;

//struct AudioEngine_Config;

class AudioGenerator;
class StereoSample;

class AudioEngine
{
public:
    AudioEngine(const AudioEngine&) = delete;
    AudioEngine& operator=(const AudioEngine&) = delete;

    static void InitAndStart(AudioEngine_Config config);
    static void StopAndCloseStream();

protected:
    friend struct std::default_delete<AudioEngine>;
    ~AudioEngine();

private:
    inline static std::unique_ptr<AudioEngine> m_instance = nullptr;
    AudioEngine(AudioEngine_Config config);

    void AudioProcessingLoop();
    void FillBuffer(ALuint buffer);

    static void CheckOpenALError(const std::string& operation);

    const AudioEngine_Config m_config;

    bool m_running;

    ALCdevice* m_device;
    ALCcontext* m_context;
    ALuint m_source = 0;
    ALuint m_buffers[NUM_BUFFERS];

    std::thread m_audioThread;

    std::shared_ptr<AudioGenerator> m_generator;

    std::vector<StereoSample> m_debugSamples;
};

}
