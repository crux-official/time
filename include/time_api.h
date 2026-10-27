#ifndef CRUX_TIME_API_H
#define CRUX_TIME_API_H

#include "kernel_types.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The time concern's contract: the one struct of function pointers the time
// driver fills and serves. The concern is dispatched through the
// engine's registry channel: the driver's served TimeAPI, selected by the
// concern's stable dispatch id. The driver that fills it is selected per platform by the
// composition's driver table; the 1:1 concern bijection says this interface
// is driven by exactly one driver in every cell that composes it.
//
// GetTicksNS is the monotonic clock in nanoseconds; GetTicks is the same
// clock in milliseconds. Every API struct in this project leads with its version.
typedef struct TimeAPI {
  PackageVersion version;
  uint64_t (*GetTicksNS)(void);
  uint64_t (*GetTicks)(void);
} TimeAPI;

#ifdef __cplusplus
}
#endif

#endif
