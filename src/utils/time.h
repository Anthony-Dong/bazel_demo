#pragma once

#include <chrono>
#include <string>
#include <ctime>
#include "absl/time/time.h"
#include "absl/time/clock.h"

namespace Example {
namespace Utils {

std::string LocalTime() {
    return absl::FormatTime(absl::Now());
}

std::string UnixTime(int64_t unix) {
    auto t = absl::FromUnixSeconds(unix);
    return absl::FormatTime(t);
}

} // namespace Utils
} // namespace Example