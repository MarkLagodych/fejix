#ifndef FEJIX_UTILS_H
#define FEJIX_UTILS_H

#include <fejix/fejix.h>

// Out Of Memory callback. Should do only necessary cleanup and then exit
// the process.
typedef void (*fj_oom_callback)(void *callback_data);

// The default implementation just calls `exit(EXIT_FAILURE)`.
FJ_EXPORT void fj_set_oom_callback(fj_oom_callback callback,
    void *callback_data);

// Called for small (most) allocations. Big allocations handle OOMs gracefully.
FJ_EXPORT void fj_oom(void);


#endif
