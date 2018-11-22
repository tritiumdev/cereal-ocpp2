#pragma once

#include <cstdint>

namespace lgpl3 { namespace ocpp20 { namespace time {

// static constants
static constexpr uint64_t nanos_in_second()  { return 1000 * 1000 * 1000; }
static constexpr uint64_t nanos_in_minute()  { return 60 * nanos_in_second(); }
static constexpr uint64_t minutes_in_hour()  { return 60; }
static constexpr uint64_t minutes_in_day()   { return 60*24; }
static constexpr int nano_second_precision() { return 9; }
static constexpr const char* utc_indicator() { return "Z"; } // Could technically be "+00:00"


} } }


