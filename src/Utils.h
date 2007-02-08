// -*- lsst-c++ -*-
//! \file
//! \brief Generic LSST software support
//!
#if !defined(LSST_UTILS_H)
#define LSST_UTILS_H 1

namespace lsst {
    namespace utils {

//! Start a namespace without confusing emacs
//! \sa LSST_END_NAMESPACE
#define LSST_START_NAMESPACE(NAME) namespace NAME {
//! End a namespace without confusing emacs
//! \sa LSST_START_NAMESPACE
#define LSST_END_NAMESPACE(NAME) }

//! \namespace lsst::utils
//\brief LSST utilities
LSST_START_NAMESPACE(lsst)
LSST_START_NAMESPACE(utils)

LSST_END_NAMESPACE(utils)
LSST_END_NAMESPACE(lsst)

    }
}

#endif
