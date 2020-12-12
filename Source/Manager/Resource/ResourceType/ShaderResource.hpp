#pragma once
#include "../Resource.hpp"

namespace PhysicsProject
{
    class ShaderResource final : public Resource
    {
    public:
        explicit ShaderResource(const std::wstring& path);
        ~ShaderResource();

        void Initialize() override;
        void Shutdown() override;

    private:
    };
}
