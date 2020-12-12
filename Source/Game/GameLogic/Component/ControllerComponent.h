#pragma once
#include "../../../System/Core/Core.hpp"
#include "../../../System/Math/Math.hpp"
#include "../../../Manager/Component/GameComponent/LogicComponent.hpp"

namespace Game
{
    class ControllerComponent final : public PhysicsProject::LogicComponent
    {
    public:
        ~ControllerComponent();
        ControllerComponent()                                          = delete;
        ControllerComponent(const ControllerComponent& rhs)            = delete;
        ControllerComponent& operator=(const ControllerComponent& rhs) = delete;

        void Initialize() override;
        void Update(PhysicsProject::Real dt) override;
        void Shutdown() override;
        void Render() override;

    protected:
        bool Load(const Json::Value& data) override;
        void Save(Json::Value& data) const override;
        void Edit(PhysicsProject::CommandRegistry* command_registry) override;
        void Subscribe() override;
        void Unsubscribe() override;

    private:
        friend class ControllerFactory;

    private:
        explicit ControllerComponent(PhysicsProject::Object* owner);
        void     Clone(ControllerComponent* origin);

    private:
        PhysicsProject::Real    m_theta  = -PhysicsProject::Math::HALF_PI;
        PhysicsProject::Real    m_phi    = PhysicsProject::Math::HALF_PI;
        PhysicsProject::Real    m_radius = 60.0f;
        PhysicsProject::Vector3 target_pos;
        PhysicsProject::Vector3 eye_pos;
    };
}
