#include "Scene.hpp"
#include "../Renderer/RendererCommon.hpp"
#include "../Shader/ShaderManagerCommon.hpp"
#include "../Utility/MatrixManager.hpp"
#include "../Utility/PrimitiveRenderer.hpp"
#include "../../../Manager/Resource/ResourceManager.hpp"
#include "../Utility/TextRenderer.hpp"

namespace PhysicsProject
{
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::Initialize()
    {
        m_matrix_manager->AddScene(this);
        //primitive renderer
        m_primitive_renderer = new PrimitiveRenderer(m_renderer);
        m_primitive_renderer->Initialize(m_shader_manager->GetColorShader());
        UpdateView();
        UpdateProjection();
    }

    void Scene::Update(Real dt)
    {
        if (m_main_camera == nullptr || m_cameras.empty())
            return;
        MatrixData mvp_data;
        mvp_data.projection = m_projection_matrix;
        m_main_camera->Update();
        mvp_data.view = m_main_camera->GetViewMatrix();
        m_frustum.ConstructFrustum(m_matrix_manager->GetFarPlane(), mvp_data.projection, mvp_data.view);
        m_primitive_renderer->UpdateFrustum(m_frustum);
    }

    void Scene::Render() const
    {
        if (m_main_camera == nullptr || m_cameras.empty())
            return;
        m_primitive_renderer->Render();
        m_primitive_renderer->Clear();
    }

    void Scene::Shutdown()
    {
        m_matrix_manager->RemoveScene(this);
        if (m_primitive_renderer != nullptr)
        {
            m_primitive_renderer->Shutdown();
            delete m_primitive_renderer;
            m_primitive_renderer = nullptr;
        }
         for (auto& camera : m_cameras)
        {
            camera->Shutdown();
            delete camera;
            camera = nullptr;
        }
        m_cameras.clear();
    }

    void Scene::SetRenderer(RendererCommon* renderer)
    {
        m_renderer = renderer;
    }

    void Scene::SetShaderManager(ShaderManagerCommon* shader_manager)
    {
        m_shader_manager = shader_manager;
    }

    void Scene::SetMatrixManager(MatrixManager* matrix_manager)
    {
        m_matrix_manager = matrix_manager;
    }

    void Scene::SetMainCamera(Camera* camera)
    {
        if (camera != nullptr)
        {
            m_main_camera = camera;
        }
    }

    void Scene::SetResourceManager(ResourceManager* resource_manager)
    {
        m_resource_manager = resource_manager;
    }

    void Scene::SetTextRenderer(TextRenderer* text_renderer)
    {
        m_text_renderer = text_renderer;
    }

    void Scene::SetProjectionType(eProjectionType projection_type)
    {
        m_projection_type = projection_type;
        UpdateProjection();
    }

    void Scene::UpdateView()
    {
        if (m_main_camera != nullptr)
        {
            m_view_matrix = m_main_camera->GetViewMatrix();
        }
        if (m_primitive_renderer != nullptr)
        {
            m_primitive_renderer->UpdateViewMatrix(m_view_matrix);
        }
    }

    void Scene::UpdateProjection()
    {
        switch (m_projection_type)
        {
        case eProjectionType::Perspective:
            m_projection_matrix = m_matrix_manager->GetPerspectiveMatrix();
            m_orthogonal_matrix = m_matrix_manager->GetOrthoGraphicMatrix();
            break;
        case eProjectionType::OrthoGraphic:
            m_projection_matrix = m_matrix_manager->GetOrthoGraphicMatrix();
            break;
        default:
            break;
        }
        if (m_primitive_renderer != nullptr)
        {
            m_primitive_renderer->UpdateProjectionMatrix(m_projection_matrix);
        }
    }

    void Scene::OnResize() const
    {
         }

    PrimitiveRenderer* Scene::GetPrimitiveRenderer() const
    {
        return m_primitive_renderer;
    }

    Camera* Scene::AddCamera(Camera* camera)
    {
        if (m_cameras.empty())
        {
            m_main_camera = camera;
        }
        m_cameras.push_back(camera);
        return camera;
    }

    void Scene::RemoveCamera(Camera* camera)
    {
        auto found = std::find(m_cameras.begin(), m_cameras.end(), camera);
        m_cameras.erase(found);
    }

    Basis Scene::GetMainCameraBasis() const
    {
        return m_main_camera->GetBasis();
    }

    Real Scene::GetAspectRatio() const
    {
        return m_matrix_manager->GetAspectRatio();
    }
}
