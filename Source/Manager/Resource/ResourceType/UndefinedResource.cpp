#include "UndefinedResource.hpp"

namespace PhysicsProject
{
    UndefinedResource::UndefinedResource(const std::wstring& path)
        : Resource(path)
    {
    }

    UndefinedResource::~UndefinedResource()
    {
    }

    void UndefinedResource::Initialize()
    {
    }

    void UndefinedResource::Shutdown()
    {
    }
}
