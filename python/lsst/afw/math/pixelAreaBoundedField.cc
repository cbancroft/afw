/*
 * This file is part of afw.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <pybind11/pybind11.h>

#include "lsst/afw/math/PixelAreaBoundedField.h"

namespace py = pybind11;
using namespace py::literals;

namespace lsst {
namespace afw {
namespace math {
namespace {

using PyClass = py::class_<PixelAreaBoundedField, std::shared_ptr<PixelAreaBoundedField>, BoundedField>;

PYBIND11_MODULE(pixelAreaBoundedField, mod) {
    py::module::import("lsst.afw.geom.skyWcs");
    PyClass cls(mod, "PixelAreaBoundedField");
    cls.def(
        py::init<lsst::geom::Box2I const &, std::shared_ptr<afw::geom::SkyWcs const>,
                 lsst::geom::AngleUnit const &, double>(),
        "bbox"_a, "skyWcs"_a, "unit"_a=lsst::geom::radians, "scaling"_a=1.0
    );
    // All other operations are wrapped by the BoundedField base class.
}

}  // namespace
}  // namespace math
}  // namespace afw
}  // namespace lsst
