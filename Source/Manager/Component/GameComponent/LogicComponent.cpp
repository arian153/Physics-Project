#include "LogicComponent.hpp"

namespace PhysicsProject
{
    LogicComponent::~LogicComponent()
    {
    }

    LogicComponent::LogicComponent(Object* owner)
        : Component(owner)
    {
    }
}
