#ifndef FEJIX_PARAMS_H
#define FEJIX_PARAMS_H


#define FJ_GET_EXTRA_PARAMS(BASIC_PARAM, ...) \
    { \
        struct fj_params *_params = (void *) (BASIC_PARAM); \
        for (_params = _params->next; _params; _params = _params->next) \
        { \
            switch (_params->type) \
            { \
                __VA_ARGS__ \
            } \
        } \
    }

#define FJ_PARAM(TYPE, DEST_VAR) \
    case TYPE: \
        DEST_VAR = (void *) _params; \
        break;


#endif
