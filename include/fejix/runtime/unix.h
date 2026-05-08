#ifndef FEJIX_RUNTIME_UNIX_H
#define FEJIX_RUNTIME_UNIX_H


#include <fejix/fejix.h>


typedef fj_err (*fj_unix_runtime_event_callback)(void *callback_data,
    uint32_t file_descriptor, uint16_t event_flags);

struct fj_unix_runtime
{
    void *self;

    // `event_flags` can be `POLLIN`, `POLLOUT`, or `POLLIN|POLLOUT`.
    fj_err (*add)(void *self, uint32_t file_descriptor, uint16_t event_flags,
        fj_unix_runtime_event_callback callback, void *callback_data);

    fj_err (*remove)(void *self, uint32_t file_descriptor);
};


#endif
