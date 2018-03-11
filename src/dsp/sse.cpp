/*
 * sse.cpp
 *
 *  Created on: 17 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>
#include <dsp/x86/features.h>

#include <stdio.h>

#define X86_SSE_IMPL
namespace dsp
{
    namespace sse
    {
        #include <dsp/x86/sse/mxcsr.h>
        #include <dsp/x86/sse/example.h>
    }
} /* namespace dsp::sse */

#undef X86_SSE_IMPL

namespace dsp
{
    namespace sse
    {
        using namespace x86;

        static dsp::start_t     dsp_start       = NULL;
        static dsp::finish_t    dsp_finish      = NULL;

        static void start(context_t *ctx)
        {
            dsp_start(ctx);
            uint32_t    mxcsr       = read_mxcsr();
            ctx->data[ctx->top++]   = mxcsr;
            write_mxcsr(mxcsr | MXCSR_FZ | MXCSR_DAZ);
        }

        static void finish(context_t *ctx)
        {
            write_mxcsr(ctx->data[--ctx->top]);
            dsp_finish(ctx);
        }

        void init(cpu_features_t *options)
        {
            if (!(options->features & CPU_OPTION_SSE))
                return;

            printf("Initializing SSE-optimized DSP functions\n");
            dsp_start                   = dsp::start;
            dsp_finish                  = dsp::finish;
            dsp::start                  = sse::start;
            dsp::finish                 = sse::finish;

            dsp::example_function       = sse::example_function;
        }
    }
}
