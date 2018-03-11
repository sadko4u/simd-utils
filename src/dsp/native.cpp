/*
 * native.cpp
 *
 *  Created on: 25 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>
#include <stdio.h>

#define DSP_NATIVE_IMPL

namespace dsp
{
    namespace native
    {
        #include <dsp/native/example.h>
    }
}

#undef DSP_NATIVE_IMPL

namespace dsp
{
    namespace native
    {
        void init()
        {
            printf("Initializing native DSP functions\n");
            dsp::example_function       = native::example_function;
        }
    }
}


