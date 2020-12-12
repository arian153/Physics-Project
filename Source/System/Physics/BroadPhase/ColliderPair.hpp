#pragma once

namespace PhysicsProject
{
    class ColliderPrimitive;

    class ColliderPair
    {
    public:
        ColliderPair(ColliderPrimitive* a, ColliderPrimitive* b)
            : first(a), second(b)
        {
        }

        ~ColliderPair()
        {
        }

    public:
        ColliderPrimitive* first = nullptr;
        ColliderPrimitive* second = nullptr;
    };
}
