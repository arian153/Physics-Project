#pragma once
#include "../../Math/Primitive/ConvexHull.hpp"
#include "../NarrowPhase/SupportPoint.hpp"

namespace PhysicsProject
{
    class IntersectionUtility
    {
    public:
        IntersectionUtility();
        ~IntersectionUtility();

        bool HasIntersection(Primitive* a, Primitive* b) const;

    private:
        SupportPoint GenerateCSOSupport(Primitive*  a, Primitive*  b, const Vector3& direction) const;
    };
}
