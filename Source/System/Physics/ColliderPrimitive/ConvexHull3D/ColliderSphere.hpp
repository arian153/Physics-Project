#pragma once
#include "../ColliderPrimitive.hpp"

namespace PhysicsProject
{
    class ColliderSphere final : public ColliderPrimitive
    {
    public:
        ColliderSphere();
        ~ColliderSphere() override;
        ColliderSphere(const ColliderSphere& rhs)            = delete;
        ColliderSphere& operator=(const ColliderSphere& rhs) = delete;

        void Initialize() override;
        void Shutdown() override;

        //minkowski support - gjk, epa
        Vector3 Support(const Vector3& direction) override;

        //ray - collider intersection
        bool    TestRayIntersection(const Ray& local_ray, Real& minimum_t, Real& maximum_t) const override;
        Vector3 GetNormal(const Vector3& local_point_on_collider) override;

        //physics
        void SetMassData(Real density) override;
        Real GetVolume() override;

        //collider 
        void SetScaleData(const Vector3& scale) override;
        void SetUnit() override;
        void UpdateBoundingVolume() override;
        void Draw(PrimitiveRenderer* renderer, eRenderingMode mode, const Color& color) const override;

        Real Radius() const;
        void SetSphere(Real radius);

    protected:
        void Clone(ColliderPrimitive* origin) override;
        void Load(const Json::Value& data) override;
        void Save(const Json::Value& data) override;
        void EditPrimitive(CommandRegistry* registry) override;

    private:
        Real m_radius             = 1.0f;
        Real m_scaled_radius = 1.0f;
    };
}
