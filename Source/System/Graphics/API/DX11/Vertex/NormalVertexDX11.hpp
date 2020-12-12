#pragma once
#include <directxmath.h>

namespace PhysicsProject
{
    class NormalVertexDX11
    {
    public:
        NormalVertexDX11();
        ~NormalVertexDX11();

    public:
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT2 uv;
        DirectX::XMFLOAT3 normal;
        DirectX::XMFLOAT3 tangent;
        DirectX::XMFLOAT3 binormal;
    };
}
