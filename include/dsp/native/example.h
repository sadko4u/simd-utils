/*
 * example.h
 *
 *  Created on: 25 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_NATIVE_EXAMPLE_H_
#define DSP_NATIVE_EXAMPLE_H_

#ifndef DSP_NATIVE_IMPL
    #error "This header should not be included directly"
#endif /* DSP_NATIVE_IMPL */

void example_function()
{
    printf("Native implementation of example function called\n");
}

#endif /* DSP_NATIVE_EXAMPLE_H_ */
