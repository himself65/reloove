#ifndef RELOOVE_TIMEDATA_H
#define RELOOVE_TIMEDATA_H
#include <uv.h>

struct TimeData {
    typedef unsigned long long ULL;

    ULL timeout;

    bool operator<(const TimeData &that) const {
        return timeout < that.timeout;
    }
};

#endif //RELOOVE_TIMEDATA_H
