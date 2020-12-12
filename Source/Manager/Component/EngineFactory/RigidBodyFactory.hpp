#pragma once
#include "../ComponentFactory.hpp"

namespace PhysicsProject
{
    class Component;
    class Object;

    class RigidBodyFactory final : public ComponentFactory
    {
    public:
        RigidBodyFactory();
        ~RigidBodyFactory();

        Component* Create(Object* owner, Space* space) override;
        Component* Clone(Component* origin, Object* dest, Space* space) override;
    };
}
