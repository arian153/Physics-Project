#pragma once
#include "../API/GraphicsAPI.hpp"
#include IncludeTextFormatBufferAPI

namespace PhysicsProject
{
    class RendererCommon;
    class Color;
    class Vector2;

    class TextFormatBufferCommon : public TextFormatBufferAPI
    {
    public:
        TextFormatBufferCommon();
        ~TextFormatBufferCommon();

        void Initialize(RendererCommon* renderer);
        void Shutdown();

    private:
    };
}
