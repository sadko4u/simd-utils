/*
 * features.h
 *
 *  Created on: 24 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_X86_FEATURES_H_
#define DSP_X86_FEATURES_H_

#include <dsp/defs.h>

namespace dsp
{
    namespace x86
    {
        enum cpu_features_enum
        {
            // Different legacy feature set
            CPU_OPTION_FPU              = 1 << 0,
            CPU_OPTION_CMOV             = 1 << 1,
            CPU_OPTION_MMX              = 1 << 2,

            // SSE feature set
            CPU_OPTION_FXSAVE           = 1 << 3,
            CPU_OPTION_SSE              = 1 << 4,
            CPU_OPTION_SSE2             = 1 << 5,
            CPU_OPTION_SSE3             = 1 << 6,
            CPU_OPTION_SSSE3            = 1 << 7,
            CPU_OPTION_SSE4_1           = 1 << 8,
            CPU_OPTION_SSE4_2           = 1 << 9,
            CPU_OPTION_SSE4A            = 1 << 10,

            // AVX and FMA feature set
            CPU_OPTION_OSXSAVE          = 1 << 11,
            CPU_OPTION_FMA3             = 1 << 12,
            CPU_OPTION_FMA4             = 1 << 13,
            CPU_OPTION_AVX              = 1 << 14,
            CPU_OPTION_AVX2             = 1 << 15,

            // AVX-512 feature set
            CPU_OPTION_AVX512F          = 1 << 16,
            CPU_OPTION_AVX512DQ         = 1 << 17,
            CPU_OPTION_AVX512IFMA       = 1 << 18,
            CPU_OPTION_AVX512PF         = 1 << 19,
            CPU_OPTION_AVX512ER         = 1 << 20,
            CPU_OPTION_AVX512CD         = 1 << 21,
            CPU_OPTION_AVX512BW         = 1 << 22,
            CPU_OPTION_AVX512VL         = 1 << 23,
            CPU_OPTION_AVX512VBMI       = 1 << 24
        };

        enum cpu_vendor_enum
        {
            CPU_VENDOR_UNKNOWN,
            CPU_VENDOR_INTEL,
            CPU_VENDOR_AMD
        };

        typedef struct cpu_features_t
        {
            uint32_t            vendor;
            uint32_t            family;
            uint32_t            model;
            uint32_t            features;
        } cpu_features_t;
    }
}

#endif /* DSP_X86_FEATURES_H_ */
