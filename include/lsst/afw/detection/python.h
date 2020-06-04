#ifndef LSST_AFW_DETECTION_PYTHON_H
#define LSST_AFW_DETECTION_PYTHON_H

#include "pybind11/pybind11.h"
#include "lsst/afw/detection/Psf.h"
#include "lsst/afw/typehandling/python.h"

namespace lsst {
namespace afw {
namespace detection {

// Trampoline for Psf
template <typename Base = Psf>
class PyPsf : public lsst::afw::typehandling::StorableHelper<Base> {
public:
    using lsst::afw::typehandling::StorableHelper<Base>::StorableHelper;  // Inherit ctors
    using Image = typename Base::Image;

    std::shared_ptr<Psf> clone() const override {
        PYBIND11_OVERLOAD_PURE(std::shared_ptr<Psf>, Base, clone,);
    }

    std::shared_ptr<Psf> resized(int width, int height) const override {
        PYBIND11_OVERLOAD_PURE(std::shared_ptr<Psf>, Base, resized, width, height);
    }

    lsst::geom::Point2D getAveragePosition() const override {
        PYBIND11_OVERLOAD(lsst::geom::Point2D, Base, getAveragePosition,);
    }

    std::shared_ptr<typename Base::Image> doComputeImage(
        lsst::geom::Point2D const& position,
        image::Color const& color
    ) const override {
        PYBIND11_OVERLOAD(std::shared_ptr<typename Base::Image>, Base, doComputeImage, position, color);
    }

    std::shared_ptr<Image> doComputeKernelImage(
        lsst::geom::Point2D const& position,
        image::Color const& color
    ) const override {
        PYBIND11_OVERLOAD_PURE(std::shared_ptr<Image>, Base, doComputeKernelImage, position, color);
    }

    double doComputeApertureFlux(
        double radius, lsst::geom::Point2D const& position,
        image::Color const& color
    ) const override {
        PYBIND11_OVERLOAD_PURE(double, Base, doComputeApertureFlux, position, color);
    }

    geom::ellipses::Quadrupole doComputeShape(
        lsst::geom::Point2D const& position,
        image::Color const& color
    ) const override {
        PYBIND11_OVERLOAD_PURE(geom::ellipses::Quadrupole, Base, doComputeShape, position, color);
    }

    lsst::geom::Box2I doComputeBBox(
        lsst::geom::Point2D const& position,
        image::Color const& color
    ) const override {
        PYBIND11_OVERLOAD_PURE(lsst::geom::Box2I, Base, doComputeBBox, position, color);
    }
};

}
}
}
#endif
