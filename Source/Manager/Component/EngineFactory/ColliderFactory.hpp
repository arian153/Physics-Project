#pragma once
#include "../ComponentFactory.hpp"

namespace PhysicsProject
{
    class Component;
    class Object;

    class ColliderFactory final : public ComponentFactory
    {
    public:
        ColliderFactory();
        ~ColliderFactory();

        Component* Create(Object* owner, Space* space) override;
        Component* Clone(Component* origin, Object* dest, Space* space) override;
    };
}
