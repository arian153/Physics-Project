#include "EditorCommand.hpp"

namespace PhysicsProject
{
    EditorCommand::EditorCommand()
    {
    }

    EditorCommand::~EditorCommand()
    {
    }

    void EditorCommand::SetRegistry(CommandRegistry* registry)
    {
        m_registry = registry;
    }

    std::string EditorCommand::Type() const
    {
        return m_type;
    }

    const char* EditorCommand::TypeCStr() const
    {
        return m_type.c_str();
    }
}
