#pragma once
#include "SupportPoint.hpp"
#include "Simplex.hpp"
#include "../Resolution/ContactPoint.hpp"
#include <unordered_map>
#include "../Resolution/ContactManifold.hpp"
#include "../BroadPhase/ColliderPair.hpp"

namespace PhysicsProject
{
    class ColorFlag;
    class ManifoldTable;
    class ColliderPrimitive;
    class Polytope;

    class NarrowPhase
    {
    public:
        NarrowPhase();
        ~NarrowPhase();

        void Initialize();
        void Shutdown();

        void SetPrimitiveRenderer(PrimitiveRenderer* primitive_renderer);

        void GenerateContact(std::list<ColliderPair>& potential_list, ManifoldTable* data_table);
        void Render(const ColorFlag& draw_gjk_flag, const ColorFlag& draw_epa_flag);

        SupportPoint GenerateCSOSupport(ColliderPrimitive* a, ColliderPrimitive* b, const Vector3& direction);
        bool         GJKCollisionDetection(ColliderPrimitive* a, ColliderPrimitive* b, Simplex& simplex);
        bool         EPAContactGeneration(ColliderPrimitive* a, ColliderPrimitive* b, Polytope& polytope, ContactPoint& result);

    private:
        size_t FindLeastSignificantComponent(const Vector3& vector3);
        void   BlowUpSimplexToTetrahedron(ColliderPrimitive* collider_a, ColliderPrimitive* collider_b, Simplex& simplex);

    private:
        PrimitiveRenderer*    m_primitive_renderer = nullptr;
        std::vector<Simplex>  m_simplexes;
        std::vector<Polytope> m_polytopes;

        size_t m_gjk_exit_iteration = 100;
        size_t m_epa_exit_iteration = 100;

        Vector3 m_search_dirs[6];
        Vector3 m_axes[3];
    };

    
}
