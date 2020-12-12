#pragma once
#include "MathDef.hpp"

namespace PhysicsProject
{
    class AxisRadian;
    class Quaternion;
    class Matrix44;
    class Matrix33;
    class EulerAngle;
    class Vector3;
    class Vector4;

    namespace Math
    {
        namespace Matrix44
        {
            //rotation
            PhysicsProject::Matrix44 Rotation(const Quaternion& quaternion);
            PhysicsProject::Matrix44 Rotation(const PhysicsProject::Matrix33& rotation_matrix);
            PhysicsProject::Matrix44 Rotation(const EulerAngle& euler_angle);
            PhysicsProject::Matrix44 Rotation(const AxisRadian& axis_radian);

            //principle rotation
            PhysicsProject::Matrix44 RotationX(Real radian);
            PhysicsProject::Matrix44 RotationY(Real radian);
            PhysicsProject::Matrix44 RotationZ(Real radian);

            //scale
            PhysicsProject::Matrix44 Scale(const PhysicsProject::Vector4& scale);
            PhysicsProject::Matrix44 Scale(const PhysicsProject::Vector3& scale, Real w = 1.0f);

            //translation
            PhysicsProject::Matrix44 Translation(const PhysicsProject::Vector3& translation);

            //Matrix Generation
            PhysicsProject::Matrix44 AffineTransformation
            (
                const PhysicsProject::Vector3& scale,
                const PhysicsProject::Vector3& origin,
                const Quaternion&       rotation,
                const PhysicsProject::Vector3& translation
            );

            PhysicsProject::Matrix44 PerspectiveMatrix
            (
                Real screen_aspect,
                Real field_of_view,
                Real far_plane,
                Real near_plane
            );

            PhysicsProject::Matrix44 OrthoGraphicMatrix
            (
                size_t client_width,
                size_t client_height,
                Real   far_plane,
                Real   near_plane
            );

            PhysicsProject::Matrix44 OrthoGraphicCenterMatrix
            (
                Real right,
                Real left,
                Real top,
                Real bottom,
                Real far_plane,
                Real near_plane
            );

            PhysicsProject::Matrix44 LookAt
            (
                const PhysicsProject::Vector3& eye_position,
                const PhysicsProject::Vector3& focus_position,
                const PhysicsProject::Vector3& up_direction
            );

            PhysicsProject::Matrix44 LookTo
            (
                const PhysicsProject::Vector3& eye_position,
                const PhysicsProject::Vector3& eye_direction,
                const PhysicsProject::Vector3& up_direction
            );
        }

        namespace Matrix33
        {
            //rotation
            PhysicsProject::Matrix33 Rotation(const Quaternion& quaternion);
            PhysicsProject::Matrix33 Rotation(const PhysicsProject::Matrix44& rotation_matrix);
            PhysicsProject::Matrix33 Rotation(const EulerAngle& euler_angle);
            PhysicsProject::Matrix33 Rotation(const AxisRadian& axis_radian);

            //principle rotation
            PhysicsProject::Matrix33 RotationX(Real radian);
            PhysicsProject::Matrix33 RotationY(Real radian);
            PhysicsProject::Matrix33 RotationZ(Real radian);

            //scale
            PhysicsProject::Matrix33 Scale(const PhysicsProject::Vector3& scale);
        }
    }
}
