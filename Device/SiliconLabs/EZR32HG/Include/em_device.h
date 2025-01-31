/**************************************************************************//**
 * @file em_device.h
 * @brief CMSIS Cortex-M Peripheral Access Layer for Silicon Laboratories
 *        microcontroller devices
 *
 * This is a convenience header file for defining the part number on the
 * build command line, instead of specifying the part specific header file.
 *
 * @verbatim
 * Example: Add "-DEFM32G890F128" to your build options, to define part
 *          Add "#include "em_device.h" to your source files
 *
 *
 * @endverbatim
 * @version 4.4.0
 ******************************************************************************
 * @section License
 * <b>Copyright 2016 Silicon Laboratories, Inc. http://www.silabs.com</b>
 ******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.@n
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.@n
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Laboratories, Inc.
 * has no obligation to support this Software. Silicon Laboratories, Inc. is
 * providing the Software "AS IS", with no express or implied warranties of any
 * kind, including, but not limited to, any implied warranties of
 * merchantability or fitness for any particular purpose or warranties against
 * infringement of any proprietary rights of a third party.
 *
 * Silicon Laboratories, Inc. will not be liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this Software.
 *
 *****************************************************************************/

#ifndef EM_DEVICE_H
#define EM_DEVICE_H

#if defined(EZR32HG220F32R55)
#include "ezr32hg220f32r55.h"

#elif defined(EZR32HG220F32R60)
#include "ezr32hg220f32r60.h"

#elif defined(EZR32HG220F32R61)
#include "ezr32hg220f32r61.h"

#elif defined(EZR32HG220F32R63)
#include "ezr32hg220f32r63.h"

#elif defined(EZR32HG220F32R67)
#include "ezr32hg220f32r67.h"

#elif defined(EZR32HG220F32R68)
#include "ezr32hg220f32r68.h"

#elif defined(EZR32HG220F32R69)
#include "ezr32hg220f32r69.h"

#elif defined(EZR32HG220F64R55)
#include "ezr32hg220f64r55.h"

#elif defined(EZR32HG220F64R60)
#include "ezr32hg220f64r60.h"

#elif defined(EZR32HG220F64R61)
#include "ezr32hg220f64r61.h"

#elif defined(EZR32HG220F64R63)
#include "ezr32hg220f64r63.h"

#elif defined(EZR32HG220F64R67)
#include "ezr32hg220f64r67.h"

#elif defined(EZR32HG220F64R68)
#include "ezr32hg220f64r68.h"

#elif defined(EZR32HG220F64R69)
#include "ezr32hg220f64r69.h"

#elif defined(EZR32HG320F32R55)
#include "ezr32hg320f32r55.h"

#elif defined(EZR32HG320F32R60)
#include "ezr32hg320f32r60.h"

#elif defined(EZR32HG320F32R61)
#include "ezr32hg320f32r61.h"

#elif defined(EZR32HG320F32R63)
#include "ezr32hg320f32r63.h"

#elif defined(EZR32HG320F32R67)
#include "ezr32hg320f32r67.h"

#elif defined(EZR32HG320F32R68)
#include "ezr32hg320f32r68.h"

#elif defined(EZR32HG320F32R69)
#include "ezr32hg320f32r69.h"

#elif defined(EZR32HG320F64R55)
#include "ezr32hg320f64r55.h"

#elif defined(EZR32HG320F64R60)
#include "ezr32hg320f64r60.h"

#elif defined(EZR32HG320F64R61)
#include "ezr32hg320f64r61.h"

#elif defined(EZR32HG320F64R63)
#include "ezr32hg320f64r63.h"

#elif defined(EZR32HG320F64R67)
#include "ezr32hg320f64r67.h"

#elif defined(EZR32HG320F64R68)
#include "ezr32hg320f64r68.h"

#elif defined(EZR32HG320F64R69)
#include "ezr32hg320f64r69.h"

#else
#error "em_device.h: PART NUMBER undefined"
#endif
#endif /* EM_DEVICE_H */
