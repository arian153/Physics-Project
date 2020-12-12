#pragma once
#include "../../Core/Utility/CoreDef.hpp"
#include "../API/GraphicsAPI.hpp"
#include IncludeShaderManagerAPI
#include "../../Math/Utility/MathDef.hpp"

namespace PhysicsProject
{
    class Camera;
    class TextureCommon;
    class TextureShaderCommon;
    class MatrixData;
    class ResourceManager;
    class RendererCommon;
    class ColorShaderCommon;
    class Color;

    class ShaderManagerCommon : public ShaderManagerAPI
    {
    public:
        ShaderManagerCommon();
        ~ShaderManagerCommon();
        void Initialize(RendererCommon* renderer, ResourceManager* resource_manager);
        void Shutdown();

        void RenderColorShader(U32 indices_count, const MatrixData& mvp_data) const;
        void RenderTextureShader(U32 indices_count, const MatrixData& mvp_data, TextureCommon* texture, const Color& color) const;

        ColorShaderCommon*   GetColorShader() const;
        TextureShaderCommon* GetTextureShader() const;

    private:
        //shader others
        ColorShaderCommon*   m_color_shader   = nullptr;
        TextureShaderCommon* m_texture_shader = nullptr;

        //resource manager
        ResourceManager* m_resource_manager = nullptr;
    };
}
