#pragma once
#include "../../../Manager/Component/ComponentFactory.hpp"

namespace Game
{
    class ControllerFactory final : public PhysicsProject::ComponentFactory
    {
    public:
        ControllerFactory();
        ~ControllerFactory();

        PhysicsProject::Component* Create(PhysicsProject::Object* owner, PhysicsProject::Space* space) override;
        PhysicsProject::Component* Clone(PhysicsProject::Component* origin, PhysicsProject::Object* dest, PhysicsProject::Space* space) override;
    };
}
