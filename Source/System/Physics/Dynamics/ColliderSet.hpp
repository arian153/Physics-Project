#pragma once
#include "../../Math/Utility/MathDef.hpp"
#include "../BroadPhase/BoundingAABB.hpp"
#include "MassData.hpp"

namespace PhysicsProject
{
    class RigidBody;
    enum class eColliderType;
    class ColliderPrimitive;
    class World;

    class ColliderSet
    {
    public:
        explicit ColliderSet(World* world);
        ~ColliderSet();

        void Initialize();
        void Shutdown();

        //primitives
        ColliderPrimitive* AddCollider(eColliderType type);
        ColliderPrimitive* GetCollider(size_t index) const;
        void               EraseCollider(ColliderPrimitive* collider) const;

        RigidBody* GetRigidBody() const;

        //setters
        void SetMass(Real density);
        void SetScale(const Vector3& scale);
        void SetRigidBody(RigidBody* rigid_body);

        //getters
        MassData GetMassData() const;
        Vector3  GetScale() const;

        //modify data
        void UpdateMassData();
        void SyncToTransform(Transform* transform) const;
        void SyncFromTransform(Transform* transform);
        void UpdateBoundingVolume();
        void UpdateUnitScale();

        void Clone(ColliderSet* origin, RigidBody* body, World* world);

    private:

    private:
        friend class World;
        friend class RigidBody;
        friend class ColliderComponent;
        friend class ManifoldTable;
        friend class ContactManifold;

    private:
        RigidBody*         m_rigid_body = nullptr;
        World*             m_world      = nullptr;
        MassData           m_mass_data;
        Vector3            m_scale = Vector3(1.0f, 1.0f, 1.0f);
        BoundingAABB       m_bounding_volume;
        ColliderComponent* m_component = nullptr;

        //primitives
        std::vector<ColliderPrimitive*>* m_colliders = nullptr;
    };
}
