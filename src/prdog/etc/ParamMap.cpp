#include <prdog/etc/ParamMap.hpp>
#include "prdog_internal_commons.hpp"

using namespace prdog;

real ParamMap::getReal(const string& key) const {
    try {
        return strToReal(at(key));
    } catch (out_of_range& e) {
        return 0.0;
    }
}

int ParamMap::getInt(const string& key) const {
    try {
        return stoi(at(key));
    } catch (out_of_range& e) {
        return 0;
    }
}

const string& ParamMap::getString(const string& key) const {
    static string empty("");
    try {
        return at(key);
    } catch (out_of_range& e) {
        return empty;
    }
}
