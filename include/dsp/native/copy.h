/*
 * context.h
 *
 *  Created on: 06 авг. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_NATIVE_COPY_H_
#define DSP_NATIVE_COPY_H_

#ifndef DSP_NATIVE_IMPL
    #error "This header should not be included directly"
#endif /* DSP_NATIVE_IMPL */

void copyf(float *dst, const float *src, size_t n)
{
    ::memcpy(dst, src, n * sizeof(float));
}

void copyd(double *dst, const double *src, size_t n)
{
    ::memcpy(dst, src, n * sizeof(double));
}

void movef(float *dst, const float *src, size_t n)
{
    ::memmove(dst, src, n * sizeof(float));
}

void moved(double *dst, const double *src, size_t n)
{
    ::memmove(dst, src, n * sizeof(double));
}

#endif /* DSP_NATIVE_COPY_H_ */
