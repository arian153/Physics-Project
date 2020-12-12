﻿#pragma once
#include "../Algebra/Vector3.hpp"
#include "../Algebra/Quaternion.hpp"
#include "../Algebra/Matrix44.hpp"

namespace PhysicsProject
{
    class Transform
    {
    public:
        Transform();
        ~Transform();

        Transform& operator=(const Transform& rhs);

        Matrix44 LocalToWorldMatrix() const;

        Vector3 LocalToWorldPoint(const Vector3& local_point) const;
        Vector3 WorldToLocalPoint(const Vector3& world_point) const;
        Vector3 LocalToWorldVector(const Vector3& local_vector) const;
        Vector3 WorldToLocalVector(const Vector3& world_vector) const;
        Vector3 LocalToWorldRotatingOrigin(const Vector3& local_vector) const;
        Vector3 WorldToLocalRotatingOrigin(const Vector3& world_vector) const;

    public:
        Vector3    rotating_origin;
        Vector3    position;
        Vector3    scale = Vector3(1.0f, 1.0f, 1.0f);
        Quaternion orientation;
    };
}
