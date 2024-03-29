#include "InstanceDataDX11.hpp"
#include "../../../Vertex/InstanceDataCommon.hpp"
#include "../ConverterDX11.hpp"

namespace PhysicsProject
{
    InstanceDataDX11::InstanceDataDX11()
        : world(), color()
    {
    }

    InstanceDataDX11::~InstanceDataDX11()
    {
    }

    InstanceDataCommon::InstanceDataCommon()
    {
    }

    InstanceDataCommon::~InstanceDataCommon()
    {
    }

    InstanceDataCommon::InstanceDataCommon(const Matrix44& w, const Color& c)
    {
        world = ConverterDX11::ToXMFloat4X4(w);
        color = ConverterDX11::ToXMFloat4(c);
    }
}
