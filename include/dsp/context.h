/*
 * context.h
 *
 *  Created on: 06 авг. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_CONTEXT_H_
#define DSP_CONTEXT_H_

#ifndef DSP_H_IMPL
    #error "This header should not be included directly"
#endif /* DSP_H_IMPL */

//-----------------------------------------------------------------------
// DSP context parameters
#pragma pack(push, 1)
typedef struct context_t
{
    uint32_t        top;
    uint32_t        data[15];
} context_t;
#pragma pack(pop)

// Start and finish types
typedef void (* start_t)(context_t *ctx);
typedef void (* finish_t)(context_t *ctx);

/** Initialize DSP
    *
    */
void init();

/** Start DSP processing, save machine context
    *
    * @param ctx structure to save context
    */
extern void (* start)(context_t *ctx);

/** Finish DSP processing, restore machine context
    *
    * @param ctx structure to restore context
    */
extern void (* finish)(context_t *ctx);

#endif /* DSP_CONTEXT_H_ */
