#pragma once
#include "../ComponentFactory.hpp"

namespace PhysicsProject
{
    class Component;
    class Object;

    class PointConstraintFactory final : public ComponentFactory
    {
    public:
        PointConstraintFactory();
        ~PointConstraintFactory();

        Component* Create(Object* owner, Space* space) override;
        Component* Clone(Component* origin, Object* dest, Space* space) override;
    };
}
