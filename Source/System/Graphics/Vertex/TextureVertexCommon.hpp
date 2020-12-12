#pragma once
#include "../API/GraphicsAPI.hpp"
#include IncludeTextureVertexAPI
#include "../../Math/Utility/MathDef.hpp"

namespace PhysicsProject
{
    class Vector2;
    class Vector3;

    class TextureVertexCommon : public TextureVertexAPI
    {
    public:
        TextureVertexCommon();
        TextureVertexCommon(Real px, Real py, Real pz, Real u, Real v);
        TextureVertexCommon(const Vector3& p, const Vector2& _uv);

        Vector3 GetPosition() const;
        Vector2 GetUV() const;

        void SetPosition(const Vector3& p);
        void SetUV(const Vector2& _uv);

    public:
    };
}
