/*
 * mxcsr.h
 *
 *  Created on: 17 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_X86_SSE_MXCSR_H_
#define DSP_X86_SSE_MXCSR_H_

#ifndef X86_SSE_IMPL
    #error "This heades should not be included directly"
#endif /* X86_SSE_IMPL */

#define MXCSR_IE                    (1 << 0)
#define MXCSR_DE                    (1 << 1)
#define MXCSR_ZE                    (1 << 2)
#define MXCSR_OE                    (1 << 3)
#define MXCSR_UE                    (1 << 4)
#define MXCSR_PE                    (1 << 5)
#define MXCSR_DAZ                   (1 << 6) /* Denormals are zeros flag */
#define MXCSR_IM                    (1 << 7)
#define MXCSR_DM                    (1 << 8)
#define MXCSR_ZM                    (1 << 9)
#define MXCSR_OM                    (1 << 10)
#define MXCSR_UM                    (1 << 11)
#define MXCSR_PM                    (1 << 12)
#define MXCSR_RC_MASK               (3 << 13)
#define MXCSR_RC_NEAREST            (0 << 13)
#define MXCSR_RC_N_INF              (1 << 13)
#define MXCSR_RC_P_INF              (2 << 13)
#define MXCSR_RC_ZERO               (3 << 13)
#define MXCSR_FZ                    (1 << 15) /* Flush to zero flag */

static uint32_t mxcsr_mask;

inline void init_mxcsr_mask()
{
    uint8_t fxsave[512] __dsp_aligned16;
    uint8_t *ptr        = fxsave;

    __asm__ __volatile__
    (
        // Clear FXSAVE structure
        __ASM_EMIT("xor     %%eax, %%eax")
        __ASM_EMIT("mov     $0x80, %%ecx")
        __ASM_EMIT("rep     stosl")

        // Issue fxsave
        __ASM_EMIT("fxsave  (%[fxsave])")

        // Get mask
        __ASM_EMIT("mov     0x1c(%[fxsave]), %%eax")
        __ASM_EMIT("test    %%eax, %%eax") // Old processors issue zero MXCSR mask
        __ASM_EMIT("jnz     1f")
        __ASM_EMIT("mov     $0xffbf, %%eax")
        __ASM_EMIT("1:")

        // Store MXCSR mask
        __ASM_EMIT("mov     %%eax, %[mask]")

        : "+D" (ptr), [fxsave] "+S" (ptr), [mask] "+m" (mxcsr_mask)
        :
        : "cc", "memory",
          "%eax", "%ecx"
    );
}

inline uint32_t read_mxcsr()
{
    uint32_t result = 0;

    __asm__ __volatile__
    (
        __ASM_EMIT("stmxcsr %[result]")

        : [result] "+m" (result)
        :
        : "memory"
    );

    return result;
}


inline void write_mxcsr(uint32_t value)
{
    __asm__ __volatile__
    (
        // Clear FXSAVE structure
        __ASM_EMIT("and         %[mask], %[value]")
        __ASM_EMIT("ldmxcsr     %[value]")

        : [value] "+m" (value)
        : [mask] "r" (mxcsr_mask)
        : "cc", "memory"
    );
}



#endif /* DSP_X86_SSE_MXCSR_H_ */
