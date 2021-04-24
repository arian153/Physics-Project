#pragma once
#include "..//..//Math/Math.hpp"

namespace PhysicsProject
{
    class ColliderSet;
    class ColliderPrimitive;

    class BoundingAABB
    {
    public:
        explicit BoundingAABB(ColliderPrimitive* collider = nullptr);
        ~BoundingAABB();

        void         Set(const Vector3& min, const Vector3& max);
        void         ExpandMargin(Real margin);
        bool         Intersect(BoundingAABB* aabb) const;
        bool         Intersect(const BoundingAABB& aabb) const;
        bool         Contains(const Vector3& point) const;
        bool         TestRayIntersection(const Ray& ray, Real& t, Real max_distance = -1.0f) const;
        bool         Contains(BoundingAABB* aabb) const;
        Real         Volume() const;
        Vector3      Center() const;
        Vector3      Size() const;
        Vector3      HalfSize() const;
        Vector3      Min() const;
        Vector3      Max() const;
        BoundingAABB Union(const BoundingAABB& aabb) const;
        //getter
        ColliderPrimitive* GetCollider() const;
        void*              GetUserData() const;
    private:
        friend class DynamicBVHNode;
        friend class DynamicBVH;
        friend class GridData;
        friend class GridPartition;
    private:
        Vector3            m_min;
        Vector3            m_max;
        ColliderSet*       m_collider_set = nullptr;
        ColliderPrimitive* m_collider     = nullptr;
        void*              m_userdata     = nullptr;
    };
}
