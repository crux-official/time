#ifndef CRUX_DYNAMIC_TIME_H
#define CRUX_DYNAMIC_TIME_H

#include "kernel_types.h"
#include "time_api.h"
#include "engine.h"
#include "kernel_types.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// The dynamic rendering of the time contract: every call dispatches through
// the engine's registry channel - the time driver's served TimeAPI, selected
// by the concern's stable dispatch id (DRIVER_TIME, platform_types.h).
// crux_engine_api is the module-global pointer defined by the install TU the
// DYNAMIC dialect compiles in and installed by the target's Construct (the
// same pattern as the engine's own dynamic rendering).
static inline uint64_t Time_GetTicksNS(void) {
  return ((TimeAPI *)crux_engine_api->GetExtensionAPI(DRIVER_TIME))->GetTicksNS();
}
static inline uint64_t Time_GetTicks(void) {
  return ((TimeAPI *)crux_engine_api->GetExtensionAPI(DRIVER_TIME))->GetTicks();
}

#ifdef __cplusplus
}
#endif

#endif
