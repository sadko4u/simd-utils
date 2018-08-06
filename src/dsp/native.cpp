/*
 * native.cpp
 *
 *  Created on: 25 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>
#include <stdio.h>
#include <string.h>

#define DSP_NATIVE_IMPL

namespace dsp
{
    namespace native
    {
        #include <dsp/native/example.h>
        #include <dsp/native/copy.h>
    }
}

#undef DSP_NATIVE_IMPL

namespace dsp
{
    namespace native
    {
        void start(context_t *ctx)
        {
            ctx->top        = 0;
        }

        void finish(context_t *ctx)
        {
        }

        void init()
        {
            printf("Initializing native DSP functions\n");
            dsp::start                  = native::start;
            dsp::finish                 = native::finish;
            dsp::example_function       = native::example_function;
            
            // DSP data copy routines
            dsp::copyf                  = native::copyf;
            dsp::copyd                  = native::copyd;
            dsp::movef                  = native::movef;
            dsp::moved                  = native::moved;
        }
    }
}


