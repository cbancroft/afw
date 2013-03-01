// -*- lsst-c++ -*-

#include <map>

#include "lsst/afw/table/io/Persistable.h"
#include "lsst/afw/table/io/OutputArchive.h"
#include "lsst/afw/table/io/InputArchive.h"
#include "lsst/afw/fits.h"

namespace lsst { namespace afw { namespace table { namespace io {

// ----- Persistable ----------------------------------------------------------------------------------------

void Persistable::writeFits(fits::Fits & fitsfile) const {
    OutputArchive archive;
    archive.put(this);
    archive.writeFits(fitsfile);
}

void Persistable::writeFits(std::string const & fileName, std::string const & mode) const {
    fits::Fits fitsfile(fileName, mode, fits::Fits::AUTO_CLOSE | fits::Fits::AUTO_CHECK);
    writeFits(fitsfile);
}

void Persistable::writeFits(fits::MemFileManager & manager, std::string const & mode) const {
    fits::Fits fitsfile(manager, mode, fits::Fits::AUTO_CLOSE | fits::Fits::AUTO_CHECK);
    writeFits(fitsfile);
}

std::string Persistable::getPersistenceName() const { return std::string(); }

std::string Persistable::getPythonModule() const { return std::string(); }

void Persistable::write(OutputArchiveHandle &) const {
    assert(!isPersistable());
    throw LSST_EXCEPT(
        pex::exceptions::LogicErrorException,
        "afw::table-based persistence is not supported for this object."
    );
}

PTR(Persistable) Persistable::_readFits(std::string const & fileName, int hdu) {
    fits::Fits fitsfile(fileName, "r", fits::Fits::AUTO_CLOSE | fits::Fits::AUTO_CHECK);
    fitsfile.setHdu(hdu);
    return _readFits(fitsfile);
}

PTR(Persistable) Persistable::_readFits(fits::MemFileManager & manager, int hdu) {
    fits::Fits fitsfile(manager, "r", fits::Fits::AUTO_CLOSE | fits::Fits::AUTO_CHECK);
    fitsfile.setHdu(hdu);
    return _readFits(fitsfile);
}

PTR(Persistable) Persistable::_readFits(fits::Fits & fitsfile) {
    InputArchive archive = InputArchive::readFits(fitsfile);
    return archive.get(1); // the first object saved always has id=1
}

// ----- PersistableFactory ---------------------------------------------------------------------------------

namespace {

typedef std::map<std::string,PersistableFactory const *> RegistryMap;

RegistryMap & getRegistry() {
    static RegistryMap instance;
    return instance;
}

} // anonymous

PersistableFactory::PersistableFactory(std::string const & name) {
    getRegistry()[name] = this;
}

PersistableFactory const & PersistableFactory::lookup(std::string const & name) {
    RegistryMap::const_iterator i = getRegistry().find(name);
    if (i == getRegistry().end()) {
        throw LSST_EXCEPT(
            pex::exceptions::NotFoundException,
            (boost::format("PeristableFactory with name '%s' not found.") % name).str()
        );
    }
    return *i->second;
}

}}}} // namespace lsst::afw::table::io
