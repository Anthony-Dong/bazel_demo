#pragma once

#include <string>
#include <strstream>

namespace example::config{
#ifdef __clang__
    inline std::string clang_version() {
        std::ostrstream ss;
        ss << "Clang version: "
                  << __clang_major__ << "."
                  << __clang_minor__ << "."
                  << __clang_patchlevel__;
        return ss.str();
    }
#else
    std::string clang_version() {
        return "-";
    }
#endif
}
