#include "AxisRadian.hpp"

namespace PhysicsProject
{
    AxisRadian::AxisRadian(const Vector3& axis, Real radian)
        : axis(axis), radian(radian)
    {
    }

    AxisRadian::AxisRadian(const AxisRadian& rhs)
        : axis(rhs.axis), radian(rhs.radian)
    {
    }

    AxisRadian::~AxisRadian()
    {
    }

    AxisRadian& AxisRadian::operator=(const AxisRadian& rhs)
    {
        if (this != &rhs)
        {
            axis = rhs.axis;
            radian = rhs.radian;
        }
        return *this;
    }
}