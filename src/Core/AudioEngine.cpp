#include "Core/AudioEngine.hpp"

#include <atomic>
#include <chrono>
#include <fstream>

#include "Core/StereoSample.hpp"
#include "Core/AudioGenerator.hpp"

namespace sc 
{

namespace
{
    std::ofstream debugOutSamplesFile;

    void DebugOutSample(StereoSample sample)
    { 
        if(!debugOutSamplesFile.is_open())
        {
            debugOutSamplesFile.open("debugOutSamples.csv");
        }

        debugOutSamplesFile << sample.left << ", " << sample.right << std::endl;
    }
}

void AudioEngine::InitAndStart(AudioEngine_Config config, std::shared_ptr<AudioGenerator> generator)
{
    if(m_instance)
    {
        throw std::runtime_error("AudioEngine instance already exists");
    }

    m_instance.reset(new AudioEngine(config, generator));
}

void AudioEngine::StopAndCloseStream()
{
    if(debugOutSamplesFile.is_open())
    {
        debugOutSamplesFile.close();
    }

    m_instance.reset();
}

AudioEngine::AudioEngine(AudioEngine_Config config, std::shared_ptr<AudioGenerator> generator)
:
m_config(config),
m_generator(generator),
m_running(false),
m_device(nullptr),
m_context(nullptr)
{
    if(m_running)
    {
        throw std::runtime_error("AudioEngine is already running");
    }
    
    m_device = alcOpenDevice(nullptr);
    
    if(!m_device) 
    {
        throw std::runtime_error("No audio devices found");
    }

    m_context = alcCreateContext(m_device, nullptr);
    if(!m_context || !alcMakeContextCurrent(m_context)) 
    {
        throw std::runtime_error("No audio devices found");
    }

    alGenSources(1, &m_source);
    CheckOpenALError("Source Generation");

    alGenBuffers(NUM_BUFFERS, m_buffers);
    CheckOpenALError("Buffer Generation");

    // Buffer initial data
    for(int i = 0; i < NUM_BUFFERS; i++) 
    {
        FillBuffer(m_buffers[i]);
    }

    alSourceQueueBuffers(m_source, NUM_BUFFERS, m_buffers);
    alSourcePlay(m_source);
    
    m_running = true;
    m_audioThread = std::thread(&AudioEngine::AudioProcessingLoop, this);
}

AudioEngine::~AudioEngine()
{
    m_running = false;

    if(m_audioThread.joinable())
    {
        m_audioThread.join();
    }

    if(m_source)
    {
        alSourceStop(m_source);
        alDeleteSources(1, &m_source);
        alDeleteBuffers(NUM_BUFFERS, m_buffers);
    }

    if(m_context) 
    {
        alcMakeContextCurrent(nullptr);
        alcDestroyContext(m_context);
    }

    if(m_device) 
    {
        alcCloseDevice(m_device);
    }
}

void AudioEngine::AudioProcessingLoop()
{
    while(m_running) 
    {
        ALint processed = 0;
        alGetSourcei(m_source, AL_BUFFERS_PROCESSED, &processed);

        while(processed--) 
        {
            ALuint buffer;
            alSourceUnqueueBuffers(m_source, 1, &buffer);
            FillBuffer(buffer);
            alSourceQueueBuffers(m_source, 1, &buffer);
        }

        ALint state;
        alGetSourcei(m_source, AL_SOURCE_STATE, &state);
        if(state != AL_PLAYING) 
        {
            alSourcePlay(m_source);
        }
    }
}

void AudioEngine::FillBuffer(ALuint buffer)
{
    std::vector<int16_t> audioBuffer(m_config.bufferSize * NUM_CHANNELS);

    for(unsigned int i = 0; i < m_config.bufferSize; i++) 
    {
        StereoSample stereoSample = m_generator->GetNextSample();
        
        if(m_config.debugOutSamples)
        {
            DebugOutSample(stereoSample);
        }
        
        audioBuffer[i * 2]     = stereoSample.left.value;
        audioBuffer[i * 2 + 1] = stereoSample.right.value;
    }

    alBufferData(buffer, AL_FORMAT_STEREO16, audioBuffer.data(), audioBuffer.size() * sizeof(int16_t), m_generator->m_sampleRate);
    CheckOpenALError("Buffer Data");
}

void AudioEngine::CheckOpenALError(const std::string& operation) {
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
        throw std::runtime_error("OpenAL error during " + operation + ": " + std::to_string(error));
    }
}

}
