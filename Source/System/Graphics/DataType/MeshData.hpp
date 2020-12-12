#pragma once
#include "../../Core/Utility/CoreDef.hpp"
#include <vector>
#include "../Vertex/NormalVertexCommon.hpp"

namespace PhysicsProject
{
    class MeshData
    {
    public:
        MeshData()
        {
        }

        ~MeshData()
        {
        }

    public:
        std::vector<NormalVertexCommon> vertices;
        std::vector<U32>           indices;
        bool                       b_resource = false;
    };
}
