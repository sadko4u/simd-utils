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

        void init(cpu_features_t *options)
        {
            if (!(options->features & CPU_OPTION_SSE))
                return;

            printf("Initializing SSE-optimized DSP functions\n");

            dsp::example_function       = sse::example_function;
        }
    }
}
