/*
 * avx.cpp
 *
 *  Created on: 24 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>
#include <dsp/x86/features.h>
#include <stdio.h>

#define DSP_X86_AVX_IMPL

namespace dsp
{
    namespace x86
    {
        #include <dsp/x86/avx/xcr.h>
    }
}

namespace dsp
{
    namespace avx
    {
        #include <dsp/x86/avx/example.h>
    }
}

#undef DSP_X86_AVX_IMPL

namespace dsp
{
    namespace avx
    {
        using namespace x86;

        void init(cpu_features_t *options)
        {
            if (!(options->features & CPU_OPTION_AVX))
                return;

            printf("Initializing AVX-optimized DSP functions\n");

            dsp::example_function       = avx::example_function;
        }
    }
}


