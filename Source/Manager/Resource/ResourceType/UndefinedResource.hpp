#pragma once

#include "../Resource.hpp"

namespace PhysicsProject
{
    class UndefinedResource final : public Resource
    {
    public:
        explicit UndefinedResource(const std::wstring& path);
        ~UndefinedResource();

        void Initialize() override;
        void Shutdown() override;

    private:
    };
}
