/*
 * defs.h
 *
 *  Created on: 16 февр. 2018 г.
 *      Author: sadko
 */

#ifndef DSP_DEFS_H_
#define DSP_DEFS_H_

#ifndef DSP_H_IMPL
    #error "This header should not be included directly"
#endif /* DSP_H_IMPL */

#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>

#define __ASM_EMIT(code)                    code "\n\t"

#ifdef __i386__
    #define ARCH_I386
    #define __ASM_EMIT32(code)                  code "\n\t"
    #define __IF_32(...)                        __VA_ARGS__
#endif /* __i386__ */

#ifdef __x86_64__
    #define ARCH_X86_64
    #define __ASM_EMIT64(code)                  code "\n\t"
    #define __IF_64(...)                        __VA_ARGS__
#endif

#if defined(ARCH_I386) || defined(ARCH_X86_64)
    #define ARCH_X86
    #define ARCH_LE
#endif /* defined(__i386__) || defined(__x86_64__) */

#ifndef __ASM_EMIT32
    #define __ASM_EMIT32(code)
#endif /* __ASM_EMIT64 */

#ifndef __ASM_EMIT64
    #define __ASM_EMIT64(code)
#endif /* __ASM_EMIT64 */

#ifndef __IF_32
    #define __IF_32(...)
#endif /* __IF_32 */

#ifndef __IF_64
    #define __IF_64(...)
#endif /* __IF_64 */

#ifdef ARCH_LE
    #define __IF_LEBE(le, be)   (le)
    #define __IF_LE(le)         (le)
    #define __IF_BE(be)
    #ifdef ARCH_BE
        #undef ARCH_BE
    #endif /* ARCH_BE */
#else
    #define __IF_LEBE(le, be)   (be)
    #define __IF_LE(le)
    #define __IF_BE(be)         (be)

    #ifndef ARCH_BE
        #define ARCH_BE
    #endif /* ARCH_BE */
#endif /* ARCH_LE */

#if defined(__unix__) || defined(unix) || defined(__unix)
    #define PLATFORM_UNIX
#endif /* __unix__ */

#if defined(__linux__) || defined(__linux) || defined(linux)
    #define PLATFORM_LINUX
#endif /* __linux__ */

#if defined(__bsd__) || defined(__bsd) || defined(__FreeBSD__)
    #define PLATFORM_BSD
#endif /* __bsd__ */

#if defined(__macosx__) || defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_MACOSX
#endif /* __macosx__ */

#if defined(PLATFORM_UNIX) || defined(PLATFORM_LINUX) || defined(PLATFORM_MACOSX) || defined(PLATFORM_BSD)
    #define PLATFORM_UNIX_COMPATIBLE
#endif /* unix-compatible platforms */

#if defined(__WINDOWS__) || defined(__WIN32__) || defined(__WIN64__) || defined(_WIN64) || defined(_WIN32) || defined(__WINNT) || defined(__WINNT__)
    #define PLATFORM_WINDOWS
#endif /* __macosx__ */

#define __dsp_aligned16                     __attribute__ ((aligned (16)))
#define __dsp_aligned32                     __attribute__ ((aligned (32)))
#define __dsp_aligned64                     __attribute__ ((aligned (64)))
#define __dsp_aligned(bytes)                __attribute__ ((aligned (bytes)))

namespace dsp
{
    __IF_32( typedef        uint32_t            umword_t );
    __IF_32( typedef        int32_t             smword_t );
    __IF_64( typedef        uint64_t            umword_t );
    __IF_64( typedef        int64_t             smword_t );
}

#endif /* DSP_DEFS_H_ */
