/*
 * example.h
 *
 *  Created on: 25 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_X86_AVX_EXAMPLE_H_
#define DSP_X86_AVX_EXAMPLE_H_

#ifndef DSP_X86_AVX_IMPL
    #error "This header should not be included directly"
#endif /* DSP_X86_AVX_IMPL */

void example_function()
{
    printf("AVX-optimized implementation of example function called\n");
}

#endif /* DSP_X86_AVX_EXAMPLE_H_ */
