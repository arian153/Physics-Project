#pragma once
#include <d3d11.h>
#include <directxmath.h>

namespace PhysicsProject
{
    class ColorShaderDX11
    {
    protected:
        struct MatrixBufferType
        {
            DirectX::XMMATRIX mvp;
        };

    public:
        ColorShaderDX11();
        ~ColorShaderDX11();

        void SetHWnd(HWND hwnd);
        void SetDevice(ID3D11Device* device);
        void SetDeviceContext(ID3D11DeviceContext* device_context);

    protected:
        ID3D11VertexShader*  m_vertex_shader  = nullptr;
        ID3D11PixelShader*   m_pixel_shader   = nullptr;
        ID3D11InputLayout*   m_layout         = nullptr;
        ID3D11Buffer*        m_matrix_buffer  = nullptr;
        ID3D11DeviceContext* m_device_context = nullptr;
        ID3D11Device*        m_device         = nullptr;
        HWND                 m_hwnd           = nullptr;
    };
}
