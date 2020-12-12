#pragma once
#include "../../Core/Utility/CoreDef.hpp"

namespace PhysicsProject
{
    class ColliderEdge
    {
    public:
        ColliderEdge();
        ColliderEdge(size_t a, size_t b);
        ~ColliderEdge();

    public:
        size_t a = Core::U64_MAX;
        size_t b = Core::U64_MAX;
    };
}
