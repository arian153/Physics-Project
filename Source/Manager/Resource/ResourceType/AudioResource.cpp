#include "AudioResource.hpp"

namespace PhysicsProject
{
    AudioResource::AudioResource(const std::wstring& path)
        : Resource(path)
    {
        m_type = eResourceType::Audio;
    }

    AudioResource::~AudioResource()
    {
    }

    void AudioResource::Initialize()
    {
    }

    void AudioResource::Shutdown()
    {
    }
}
