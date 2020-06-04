import unittest
import copy

import lsst.utils.tests
from lsst.afw.detection import Psf
from lsst.afw.image import Image
from lsst.afw.image.color import Color
from lsst.geom import Point2D


class ZeroPsf(Psf):
    def __init__(self):
        Psf.__init__(self)

    def doComputeImage(self, point2d=None, color=None):
        return Image((21, 21), dtype=np.float)


class PythonPsfInheritTestSuite(lsst.utils.tests.TestCase):
    def setUp(self):
        self.psf = ZeroPsf()

    def testEval(self):
        self.psf.computeImage()


class MemoryTester(lsst.utils.tests.MemoryTestCase):
    pass


def setup_module(module):
    lsst.utils.tests.init()


if __name__ == "__main__":
    lsst.utils.tests.init()
    unittest.main()
