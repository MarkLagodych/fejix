#ifndef FEJIX_CORE_H
#define FEJIX_CORE_H

#include <stdbool.h>
#include <stdint.h>


#ifndef FEJIX_EXPORT

#if defined(FJ_BUILD_WINDOWS_DLL)
#define FJ_EXPORT_LINKAGE __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define FJ_EXPORT_LINKAGE __attribute__((visibility("default")))
#else
#define FJ_EXPORT_LINKAGE
#endif

#if defined(__cplusplus)
#define FJ_EXPORT extern "C" FJ_EXPORT_LINKAGE
#else
#define FJ_EXPORT extern FJ_EXPORT_LINKAGE
#endif

#endif


typedef uint32_t fj_params_type;

struct fj_params_base
{
    fj_params_type type;
    struct fj_params *next;
};

#endif
