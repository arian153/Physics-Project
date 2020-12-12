#pragma once
#include "../Component.hpp"
#include "../../../System/Physics/Physics.hpp"

namespace PhysicsProject
{
    class ColliderComponent final : public Component
    {
    public:
        ~ColliderComponent();
        ColliderComponent()                                        = delete;
        ColliderComponent(const ColliderComponent& rhs)            = delete;
        ColliderComponent& operator=(const ColliderComponent& rhs) = delete;

        void Initialize() override;
        void Update(Real dt) override;
        void Shutdown() override;

        ColliderPrimitive* AddCollider(eColliderType type) const;
        ColliderPrimitive* GetCollider(size_t index) const;
        void               EraseCollider(ColliderPrimitive* collider) const;

        void SetMass(Real density) const;
        void SetScale(const Vector3& scale) const;

        MassData GetMass() const;
        Vector3  GetScale() const;

        void SetTransform(Transform* transform);
        void SetRigidBody(RigidBody* rigid_body);
        
    protected:
        bool Load(const Json::Value& data) override;
        void Save(Json::Value& data) const override;
        void Edit(CommandRegistry* command_registry) override;
        void Subscribe() override;
        void Unsubscribe() override;

    private:
        friend class ColliderFactory;
        friend class RigidBodyComponent;
        friend class ColliderSet;

    private:
        explicit ColliderComponent(Object* owner);
        void     Clone(ColliderComponent* origin);

    private:
        ColliderSet* m_collider_set = nullptr;
        RigidBody*   m_rigid_body   = nullptr;
        Transform*   m_transform    = nullptr;

        bool m_b_init = false;
    };
}
