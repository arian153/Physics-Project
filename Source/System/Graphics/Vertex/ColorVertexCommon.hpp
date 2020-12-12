#pragma once
#include "../API/GraphicsAPI.hpp"
#include IncludeColorVertexAPI


namespace PhysicsProject
{
    class Vector3;
    class Color;

    class ColorVertexCommon : public ColorVertexAPI
    {
    public:
        ColorVertexCommon();
        ColorVertexCommon(const Vector3& position, const Color& color);

        Vector3 GetPosition() const;
        Color   GetColor() const;

    public:
    };
}
