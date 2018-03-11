/*
 * dsp.h
 *
 *  Created on: 16 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_H_
#define DSP_H_

#define DSP_H_IMPL

#include <dsp/defs.h>

namespace dsp
{
    #include <dsp/dsp/example.h>

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

}

#undef DSP_H_IMPL

#endif /* DSP_H_ */
