/*
 * example.h
 *
 *  Created on: 25 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_X86_SSE_EXAMPLE_H_
#define DSP_X86_SSE_EXAMPLE_H_

#ifndef X86_SSE_IMPL
    #error "This heades should not be included directly"
#endif /* X86_SSE_IMPL */

void example_function()
{
    printf("SSE-optimized implementation of example function called\n");
}

#endif /* DSP_X86_SSE_EXAMPLE_H_ */
