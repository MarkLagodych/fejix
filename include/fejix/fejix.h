#ifndef FEJIX_H
#define FEJIX_H


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// For C++, use `extern "C" { ... }` around Fejix headers.

#if defined(__GNUC__) && __GNUC__ >= 4

// This has no effect when building a static library.
#define FJ_EXPORT __attribute__((visibility("default")))

#elif defined(FJ_BUILD_WINDOWS_DLL)

// `dllimport` is not used because it is not compatible with static libraries
// and so would make using the header harder because of additional
// STATIC/DYNAMIC compile switches.

#define FJ_EXPORT __declspec(dllexport)

#else

#define FJ_EXPORT

#endif


typedef uint8_t fj_err;
enum
{
    FJ_ERR_OK,
    FJ_ERR_OUT_OF_MEMORY,
    FJ_ERR_UNSUPPORTED,
    FJ_ERR_INVALID_ARGUMENT,
    FJ_ERR_INTERNAL_ERROR,
    FJ_ERR_IO_ERROR,
    FJ_ERR_BACKEND_ERROR,
};

typedef uint16_t fj_window_kind;
enum
{
    FJ_WINDOW_NORMAL,
    FJ_WINDOW_POPUP,
    FJ_WINDOW_LAYER,
    FJ_WINDOW_TASK_ICON,
    FJ_WINDOW_STATUS_ICON,
    FJ_WINDOW_NOTIFICATION,
    FJ_WINDOW_MESSAGE_BOX,
};

typedef uint16_t fj_event_kind;

enum
{
    FJ_DISPLAY_EVENT_ERROR,
};

typedef uint16_t fj_property_kind;

enum
{
    FJ_DISPLAY_PROTOCOL,
    FJ_DISPLAY_SUPPORTS_POPUP_WINDOWS,
    FJ_DISPLAY_SUPPORTS_LAYER_WINDOWS,
};


struct fj_display;
struct fj_window;


typedef void (*fj_event_callback)(void *callback_data, fj_event_kind kind,
    void const *data);


// Returns NULL if no protocol is built in.
FJ_EXPORT char const *fj_display_default_protocol(void);

FJ_EXPORT bool fj_display_supports_protocol(char const *protocol);


FJ_EXPORT fj_err fj_display_connect(struct fj_display **out_display,
    char const *protocol, void *opt_runtime, fj_event_callback event_callback,
    void *callback_data);

FJ_EXPORT fj_err fj_display_disconnect(struct fj_display *display);

FJ_EXPORT fj_err fj_display_get(struct fj_display *display,
    fj_property_kind property, void *out_value);

FJ_EXPORT fj_err fj_window_create(struct fj_window **out_window,
    struct fj_display *display, fj_window_kind kind,
    fj_event_callback event_callback, void *callback_data);

FJ_EXPORT fj_err fj_window_destroy(struct fj_window *window);

FJ_EXPORT fj_err fj_window_get(struct fj_window *window,
    fj_property_kind property, void *out_value);

FJ_EXPORT fj_err fj_window_set(struct fj_window *window,
    fj_property_kind property, void const *value);
// TODO windows&renderers & input


#endif
