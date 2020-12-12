#pragma once
#include "../ComponentFactory.hpp"

namespace PhysicsProject
{
    class Component;
    class Object;

    class TransformFactory final : public ComponentFactory
    {
    public:
        TransformFactory();
        ~TransformFactory();

        Component* Create(Object* owner, Space* space) override;
        Component* Clone(Component* origin, Object* dest, Space* space) override;
    };
}
