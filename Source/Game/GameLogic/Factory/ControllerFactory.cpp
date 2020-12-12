#include "ControllerFactory.h"
#include "../../../Manager/Component/Component.hpp"
#include "../Component/ControllerComponent.h"

namespace Game
{
    ControllerFactory::ControllerFactory()
    {
        type = typeid(ControllerComponent).name();
    }

    ControllerFactory::~ControllerFactory()
    {
    }

    PhysicsProject::Component* ControllerFactory::Create(PhysicsProject::Object* owner, PhysicsProject::Space* space)

    {
        auto create    = new ControllerComponent(owner);
        create->m_type = type;
        create->SetSpace(space);
        return create;
    }

    PhysicsProject::Component* ControllerFactory::Clone(PhysicsProject::Component* origin, PhysicsProject::Object* dest, PhysicsProject::Space* space)
    {
        auto source = static_cast<ControllerComponent*>(origin);
        auto cloned = static_cast<ControllerComponent*>(this->Create(dest, space));
        cloned->Clone(source);
        return cloned;
    }
}
