#pragma once
#include "../ColliderPrimitive.hpp"

namespace PhysicsProject
{
    class ColliderTriangle final : public ColliderPrimitive
    {
    public:
        ColliderTriangle();
        ~ColliderTriangle() override;
        ColliderTriangle(const ColliderTriangle& rhs) = delete;
        ColliderTriangle& operator=(const ColliderTriangle& rhs) = delete;

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

        Vector2 Vertex(size_t i) const;
        void SetTriangle(const Vector2& v0, const Vector2& v1, const Vector2& v2);
    protected:
        void Clone(ColliderPrimitive* origin) override;
        void Load(const Json::Value& data) override;
        void Save(const Json::Value& data) override;

    private:
        Vector2 m_vertices[3];
        Vector2 m_scaled_vertices[3];
    };
}
