/*
 * copy.h
 *
 *  Created on: 06 авг. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_COPY_H_
#define DSP_COPY_H_

#ifndef DSP_H_IMPL
    #error "This header should not be included directly"
#endif /* DSP_H_IMPL */

//-----------------------------------------------------------------------
// DSP data copy routines
extern void (* copyf)(float *dst, const float *src, size_t n);
extern void (* copyd)(double *dst, const double *src, size_t n);

extern void (* movef)(float *dst, const float *src, size_t n);
extern void (* moved)(double *dst, const double *src, size_t n);

#endif /* DSP_COPY_H_ */
