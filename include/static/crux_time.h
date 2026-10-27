#ifndef CRUX_STATIC_TIME_H
#define CRUX_STATIC_TIME_H

#include "kernel_types.h"
#include "time_api.h"

#ifdef __cplusplus
extern "C" {
#endif

// The static rendering of the time contract: plain externs, defined by the
// time driver and linked into the binary. A static consumer pays zero
// indirection and cannot accidentally dispatch - the same shape as the
// platform's static rendering.
extern uint64_t Time_GetTicksNS(void);
extern uint64_t Time_GetTicks(void);

#ifdef __cplusplus
}
#endif

#endif
