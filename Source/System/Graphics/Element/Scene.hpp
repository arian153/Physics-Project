#pragma once
#include "../../Math/Utility/MathDef.hpp"
#include "Camera.hpp"
#include "../DataType/ProjectionType.hpp"
#include <vector>
#include "../DataType/Frustum.hpp"

namespace PhysicsProject
{
    class TextRenderer;
    class ResourceManager;
    class TextTextureBufferCommon;
    class RenderTextureBufferCommon;
    class ColliderSet;
    class PrimitiveRenderer;
    class MatrixManager;
    class ShaderManagerCommon;
    class RendererCommon;
    class RendererDX11;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        void Initialize();
        void Update(Real dt);
        void Render() const;
        void Shutdown();

        void SetRenderer(RendererCommon* renderer);
        void SetShaderManager(ShaderManagerCommon* shader_manager);
        void SetMatrixManager(MatrixManager* matrix_manager);
        void SetMainCamera(Camera* camera);
        void SetResourceManager(ResourceManager* resource_manager);
        void SetTextRenderer(TextRenderer* text_renderer);

        void SetProjectionType(eProjectionType projection_type);
        void UpdateView();
        void UpdateProjection();
        void OnResize() const;

        PrimitiveRenderer* GetPrimitiveRenderer() const;

        //add
        Camera* AddCamera(Camera* camera);

        //remove
        void RemoveCamera(Camera* camera);

        Basis GetMainCameraBasis() const;
        Real  GetAspectRatio() const;

    private:
        RendererCommon*      m_renderer           = nullptr;
        ShaderManagerCommon* m_shader_manager     = nullptr;
        MatrixManager*       m_matrix_manager     = nullptr;
        ResourceManager*     m_resource_manager   = nullptr;
        Camera*              m_main_camera        = nullptr;
        PrimitiveRenderer*   m_primitive_renderer = nullptr;
        TextRenderer*        m_text_renderer      = nullptr;

        std::vector<Camera*> m_cameras;

        eProjectionType m_projection_type = eProjectionType::Perspective;
        Matrix44        m_view_matrix;
        Matrix44        m_projection_matrix;
        Matrix44        m_orthogonal_matrix;
        Frustum         m_frustum;
    };
}
