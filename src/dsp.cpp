/*
 * dsp.cpp
 *
 *  Created on: 17 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>

namespace dsp
{
    namespace native
    {
        void init();
    }

#ifdef ARCH_X86
    namespace x86
    {
        void init();
    }
#endif /* ARCH_X86 */
}

namespace dsp
{
    // Function prototypes
    void (* example_function)()             = NULL;
    void (* start)(context_t *ctx)          = NULL;
    void (* finish)(context_t *ctx)         = NULL;
    
    // Data copying
    void (* copyf)(float *dst, const float *src, size_t n) = NULL;
    void (* copyd)(double *dst, const double *src, size_t n) = NULL;

    void (* movef)(float *dst, const float *src, size_t n) = NULL;
    void (* moved)(double *dst, const double *src, size_t n) = NULL;

    // Initialization
    void init()
    {
        native::init();
        #ifdef ARCH_X86
            x86::init();
        #endif /* ARCH_X86 */
    }
}
