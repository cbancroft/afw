// -*- lsst-c++ -*-

/* 
 * LSST Data Management System
 * Copyright 2008, 2009, 2010 LSST Corporation.
 * 
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
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
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <http://www.lsstcorp.org/LegalNotices/>.
 */

#include "lsst/afw/geom/XYTransform.h"
#include "boost/make_shared.hpp"

namespace lsst {
namespace afw {
namespace geom {

IdentityXYTransform::IdentityXYTransform()
    : XYTransform()
{ }

PTR(XYTransform) IdentityXYTransform::clone() const
{
    return boost::make_shared<IdentityXYTransform> ();
}

Point2D IdentityXYTransform::forwardTransform(Point2D const &point) const
{
    return point;
}

Point2D IdentityXYTransform::reverseTransform(Point2D const &point) const
{
    return point;
}

AffineTransform IdentityXYTransform::linearizeForwardTransform(Point2D const &point) const
{
    // note: AffineTransform constructor called with no arguments gives the identity transform
    return AffineTransform(); 
}

AffineTransform IdentityXYTransform::linearizeReverseTransform(Point2D const &point) const
{
    // note: AffineTransform constructor called with no arguments gives the identity transform
    return AffineTransform(); 
}

}}}