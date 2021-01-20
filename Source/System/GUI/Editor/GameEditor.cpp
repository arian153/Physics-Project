#include "GameEditor.hpp"
#include "../../../External/imgui/imgui.h"
#include "../../Core/OS-API/Application.hpp"
#include "../../../Manager/Level/LevelManager.hpp"
#include "../../../Manager/Resource/ResourceType/JsonResource.hpp"
#include "Command/EditorCommand.hpp"

namespace PhysicsProject
{
    GameEditor::GameEditor()
    {
    }

    GameEditor::~GameEditor()
    {
    }

    void GameEditor::Initialize(Application* application)
    {
        m_application                = application;
        m_space_editor.m_game_editor = this;
        m_space_editor.Initialize(application);
        m_window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        m_window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        m_window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        m_command_registry.Initialize();
        m_space_editor.m_command_registry = &m_command_registry;
    }

    void GameEditor::Update(Real dt)
    {
        if (m_b_open)
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->GetWorkPos());
            ImGui::SetNextWindowSize(viewport->GetWorkSize());
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            ImGui::Begin("Engine 5th Editor", &m_b_open, m_window_flags);
            ImGui::PopStyleVar(3);
            // DockSpace
            ImGuiIO& io = ImGui::GetIO();
            if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
            {
                ImGuiID dock_space_id = ImGui::GetID("E5-Editor");
                ImGui::DockSpace(dock_space_id, ImVec2(0.0f, 0.0f), m_dock_space_flags);
            }
            if (ImGui::BeginMenuBar())
            {
                UpdateFileTab();
                UpdateEditTab();
                UpdateObjectTab();
                ImGui::EndMenuBar();
            }
            ImGui::End();
            {
                m_space_editor.UpdateSceneWindow(dt);
                m_space_editor.UpdateHierarchyWindow();
                m_space_editor.UpdateInspectorWindow();
                m_level_editor.Update(dt);
                UpdateCommandWindow();
            }
        }
    }

    void GameEditor::Shutdown()
    {
        m_command_registry.Shutdown();
    }

    bool GameEditor::IsOpen() const
    {
        return m_b_open;
    }

    void GameEditor::SetOpen(bool is_open)
    {
        m_b_open = is_open;
    }

    void GameEditor::UpdateFileTab()
    {
        if (ImGui::BeginMenu("File"))
        {
            size_t open_count = m_space_editor.OpenCount();
            if (ImGui::BeginMenu("New"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Open"))
            {
                if (ImGui::BeginMenu("Space", open_count < m_space_editor.Size()))
                {
                    m_space_editor.OpenSequence();
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Close", nullptr, false, open_count > 0))
            {
                m_space_editor.CloseSequence();
            }
            if (ImGui::MenuItem("Close All", nullptr, false, open_count > 0))
            {
                m_space_editor.CloseAllSequence();
            }
            if (ImGui::MenuItem("Close Editor"))
            {
                m_b_open = false;
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Save", nullptr, false, open_count > 0))
            {
            }
            if (ImGui::MenuItem("Save All", nullptr, false, open_count > 0))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Exit"))
            {
                m_application->GetLevelManager()->SetQuit();
            }
            ImGui::EndMenu();
        }
    }

    void GameEditor::UpdateEditTab()
    {
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "Ctrl+Z"))
            {
                m_command_registry.UndoCommand();
            }
            if (ImGui::MenuItem("Redo", "Ctrl+Y"))
            {
                m_command_registry.RedoCommand();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "Ctrl+X"))
            {
            }
            if (ImGui::MenuItem("Copy", "Ctrl+C"))
            {
            }
            if (ImGui::MenuItem("Paste", "Ctrl+V"))
            {
            }
            if (ImGui::MenuItem("Duplicate", "Ctrl+D"))
            {
            }
            if (ImGui::MenuItem("Delete", "Ctrl+R"))
            {
            }
            ImGui::EndMenu();
        }
    }

    void GameEditor::UpdateObjectTab()
    {
        if (ImGui::BeginMenu("Object"))
        {
            if (ImGui::MenuItem("Create Empty"))
            {
            }
            if (ImGui::MenuItem("Create 3D Object"))
            {
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Create Camera"))
            {
            }
            if (ImGui::MenuItem("Create Light"))
            {
            }
            ImGui::EndMenu();
        }
    }

    static bool Items_CommandGetter(void* data, int idx, const char** out_text)
    {
        auto& commands = *static_cast<std::vector<EditorCommand*>*>(data);
        if (idx < 0 || idx >= static_cast<int>(commands.size()))
        {
            return false;
        }
        *out_text = commands[idx]->TypeCStr();
        return true;
    }

    void GameEditor::UpdateCommandWindow()
    {
        ImGui::Begin("Commands");
        ImVec2 min = ImGui::GetWindowContentRegionMin();
        ImVec2 max = ImGui::GetWindowContentRegionMax();
        ImGui::PushItemWidth(max.x - min.x);
        auto commands = m_command_registry.m_command_registry;
        if (ImGui::ListBox(
                           "##ObjectList", &m_command_index, Items_CommandGetter,
                           static_cast<void*>(&commands), static_cast<int>(commands.size()), (int)m_command_registry.m_registry_size))
        {
        }
        ImGui::End();
    }
}
