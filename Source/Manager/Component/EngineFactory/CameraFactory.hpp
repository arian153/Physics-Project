#pragma once
#include "../ComponentFactory.hpp"

namespace PhysicsProject
{
    class Component;
    class Object;

    class CameraFactory final : public ComponentFactory
    {
    public:
        CameraFactory();
        ~CameraFactory();

        Component* Create(Object* owner, Space* space) override;
        Component* Clone(Component* origin, Object* dest, Space* space) override;
    };
}
