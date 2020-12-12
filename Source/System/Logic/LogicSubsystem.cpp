#include "LogicSubsystem.hpp"
#include "../../Manager/Component/GameComponent/LogicComponent.hpp"

namespace PhysicsProject
{
    LogicSubsystem::LogicSubsystem()
    {
    }

    LogicSubsystem::~LogicSubsystem()
    {
    }

    void LogicSubsystem::Initialize()
    {
    }

    void LogicSubsystem::Update(Real dt)
    {
        for (auto& logic : m_logic_components)
        {
            logic->Update(dt);
        }
    }

    void LogicSubsystem::Render() const
    {
        for (auto& logic : m_logic_components)
        {
            logic->Render();
        }
    }

    void LogicSubsystem::Shutdown()
    {
        m_logic_components.clear();
    }

    void LogicSubsystem::AddLogic(LogicComponent* logic)
    {
        m_logic_components.push_back(logic);
    }

    void LogicSubsystem::RemoveLogic(LogicComponent* logic)
    {
        if (m_logic_components.empty() == false)
        {
            auto found = std::find(m_logic_components.begin(), m_logic_components.end(), logic);
            if (found != m_logic_components.end())
            {
                m_logic_components.erase(found);
            }
        }
    }

    void LogicSubsystem::InitializeLogic(LogicComponent* logic) const
    {
        logic->m_input              = m_input;
        logic->m_text_renderer      = m_text_renderer;
        logic->m_primitive_renderer = m_primitive_renderer;
    }

    void LogicSubsystem::SetPrimitiveRenderer(PrimitiveRenderer* primitive_renderer)
    {
        m_primitive_renderer = primitive_renderer;
    }
}
