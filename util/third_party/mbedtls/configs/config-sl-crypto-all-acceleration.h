/*
 *  Configuration for enabling CRYPTO hardware acceleration in all mbedtls
 *  modules when running on SiliconLabs devices.
 *
 *  Copyright (C) 2016, Silicon Labs, http://www.silabs.com
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
 
/**
 * @defgroup sl_crypto_config Silicon Labs CRYPTO Hardware Acceleration Configuration
 * @addtogroup sl_crypto_config
 *
 * @brief 
 *  mbed TLS configuration for Silicon Labs CRYPTO hardware acceleration 
 *
 * @details
 *  mbed TLS configuration is composed of settings in this Silicon Labs specific CRYPTO hardware acceleration file located in mbedtls\configs and the mbed TLS configuration file in mbedtls/include/mbedtls/config.h. 
 *  This configuration can be used as a starting point to evaluate hardware acceleration available on Silicon Labs devices. 
 *
 * @{
 */

#ifndef MBEDTLS_CONFIG_SL_CRYPTO_ALL_ACCELERATION_H
#define MBEDTLS_CONFIG_SL_CRYPTO_ALL_ACCELERATION_H

#include "em_device.h"

#if !defined(NO_CRYPTO_ACCELERATION)
/**
 * @name SECTION: Silicon Labs Acceleration settings
 *
 * This section sets Silicon Labs Acceleration settings.
 * @{
   
 */
/**
 * \def MBEDTLS_SLCL_PLUGINS
 *
 * Enable slcl_xxx.c plugins including support for CRYPTO preemption,
 * asynchronous API support, DMA and BUFC I/O modes, and support for
 * classic EFM32 devices with AES module, EFM32GG, etc.
 *
 * Module:  sl_crypto/src/slcl_xxx.c
 *
 * Comment/uncomment to disable/enable.
 */
//#define MBEDTLS_SLCL_PLUGINS

/* Enable MBEDTLS_SLCL_PLUGINS in order to generate documentation: */
#if defined(DOXY_DOC_ONLY)
#define MBEDTLS_SLCL_PLUGINS
#endif

/**
 * \def MBEDTLS_AES_ALT
 *
 * Enable hardware acceleration for the AES block cipher
 *
 * Module:  sl_crypto/src/sl_aes.c
 *          or
 *          sl_crypto/src/slcl_aes.c if MBEDTLS_SLCL_PLUGINS is defined.
 *
 * See MBEDTLS_AES_C for more information.
 */
#define MBEDTLS_AES_ALT

/**
 * \def MBEDTLS_CCM_ALT
 *
 * Enable hardware acceleration for the Counter with CBC-MAC (CCM) mode for
 * 128-bit block cipher.
 *
 * Module:  sl_crypto/src/slcl_ccm.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS
 *
 * See MBEDTLS_CCM_C for more information.
 */
#if defined(MBEDTLS_SLCL_PLUGINS)
#define MBEDTLS_CCM_ALT
#endif

/**
 * \def MBEDTLS_CMAC_C
 *
 * Enable Cipher-based Message Authentication Code (CMAC) based on AES-128.
 * Note: MBEDTLS_CMAC_ALT is required to enable the API since a pure C
 * implementation of CMAC is not supported.
 *
 * Module:  sl_crypto/src/slcl_cmac.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS, MBEDTLS_CMAC_ALT and (CRYPTO_COUNT > 0)
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_CMAC_C
#endif

/**
 * \def MBEDTLS_CMAC_ALT
 *
 * Enable hardware acceleration for the Cipher-based Message Authentication Code
 * (CMAC) based on AES-128.
 *
 * Module:  sl_crypto/src/slcl_cmac.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS, MBEDTLS_CMAC_C and (CRYPTO_COUNT > 0)
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && defined(MBEDTLS_CMAC_C) && \
  defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_CMAC_ALT
#endif

/**
 * \def MBEDTLS_ECP_DEVICE_ALT
 * \def MBEDTLS_ECP_DEVICE_ALT
 * \def MBEDTLS_ECP_DOUBLE_JAC_ALT
 * \def MBEDTLS_ECP_DEVICE_ADD_MIXED_ALT
 * \def MBEDTLS_ECP_NORMALIZE_JAC_ALT
 * \def MBEDTLS_ECP_NORMALIZE_JAC_MANY_ALT
 * \def MBEDTLS_MPI_MODULAR_DIVISION_ALT
 *
 * Enable hardware acceleration for the elliptic curve over GF(p) library.
 *
 * Module:  sl_crypto/src/sl_ecp.c
 *          or
 *          sl_crypto/src/slcl_ecp.c if MBEDTLS_SLCL_PLUGINS is defined.
 * Caller:  library/ecp.c
 *          library/ecdh.c
 *          library/ecdsa.c
 *          library/ecjpake.c
 *
 * Requires: MBEDTLS_BIGNUM_C, MBEDTLS_ECP_C and at least one
 * MBEDTLS_ECP_DP_XXX_ENABLED and (CRYPTO_COUNT > 0)
 */
#if defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_ECP_DEVICE_ALT
#define MBEDTLS_ECP_DOUBLE_JAC_ALT
#define MBEDTLS_ECP_DEVICE_ADD_MIXED_ALT
#define MBEDTLS_ECP_NORMALIZE_JAC_ALT
#define MBEDTLS_ECP_NORMALIZE_JAC_MANY_ALT
#define MBEDTLS_MPI_MODULAR_DIVISION_ALT
#endif

/**
 * \def MBEDTLS_ECP_ALT
 * \def MBEDTLS_ECP_GROUP_LOAD_ALT
 * \def MBEDTLS_CRYPTO_DEVICE_PREEMPTION
 *
 * Enable CRYPTO preemption for the elliptic curve over GF(p) library.
 *
 * Module:  sl_crypto/src/slcl_ecp.c
 *          
 * Caller:  library/ecp.c
 *          library/ecdh.c
 *          library/ecdsa.c
 *          library/ecjpake.c
 *
 * Requires: MBEDTLS_BIGNUM_C,
 *           MBEDTLS_ECP_C,
 *           MBEDTLS_ECP_DEVICE_ALT,
 *           MBEDTLS_SLCL_PLUGINS
 *           at least one MBEDTLS_ECP_DP_XXX_ENABLED
 *           and (CRYPTO_COUNT > 0)
 *
 * Comment/uncomment macros to disable/enable
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_ECP_ALT
#define MBEDTLS_ECP_GROUP_LOAD_ALT
//#define MBEDTLS_CRYPTO_DEVICE_PREEMPTION
#endif

/**
 * \def MBEDTLS_CRYPTO_CRITICAL_REGION_ALT
 *
 * Enable user defined alternative implementation of CRYPTO critical regions
 * (of CRYPTO preemption support).
 *
 * Module:  sl_crypto/src/cryptodrv.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS
 *           MBEDTLS_CRYPTO_DEVICE_PREEMPTION
 *           and (CRYPTO_COUNT > 0)
 *
 * Comment/uncomment macros to disable/enable
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && defined(MBEDTLS_CRYPTO_DEVICE_PREEMPTION) && \
  defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
//#define MBEDTLS_CRYPTO_CRITICAL_REGION_ALT
#endif

/**
 * \def MBEDTLS_INCLUDE_ASYNCH_API
 *
 * Enable asynchronous (non-blocking) API support.
 *
 * Module:  sl_crypto/src/slcl_aes.c
 *          sl_crypto/src/slcl_ccm.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS
 *           MBEDTLS_AES_ALT or MBEDTLS_CCM_ALT
 *           and (CRYPTO_COUNT > 0)
 *
 * Comment/uncomment macros to disable/enable
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && \
  (defined(MBEDTLS_AES_ALT) || defined(MBEDTLS_CCM_ALT)) && \
  defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
//#define MBEDTLS_INCLUDE_ASYNCH_API
#endif

/**
 * \def MBEDTLS_INCLUDE_IO_MODE_DMA
 *
 * Enable support for moving data to/from CRYPTO with DMA.
 *
 * Module:  sl_crypto/src/slcl_aes.c
 *          sl_crypto/src/slcl_ccm.c
 *
 * Requires: MBEDTLS_SLCL_PLUGINS
 *           MBEDTLS_AES_ALT or MBEDTLS_CCM_ALT
 *           and (CRYPTO_COUNT > 0)
 *
 * Comment/uncomment macros to disable/enable
 */
#if defined(MBEDTLS_SLCL_PLUGINS) && \
  (defined(MBEDTLS_AES_ALT) || defined(MBEDTLS_CCM_ALT)) && \
  defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
//#define MBEDTLS_INCLUDE_IO_MODE_DMA
#endif

/**
 * \def MBEDTLS_SHA1_ALT
 *
 * Enable hardware acceleration for the SHA1 cryptographic hash algorithm.
 *
 * Module:  sl_crypto/src/sl_sha1.c
 *          or
 *          sl_crypto/src/slcl_sha1.c if MBEDTLS_SLCL_PLUGINS is defined.
 * Caller:  library/mbedtls_md.c
 *          library/ssl_cli.c
 *          library/ssl_srv.c
 *          library/ssl_tls.c
 *          library/x509write_crt.c
 *
 * Requires: MBEDTLS_SHA1_C and (CRYPTO_COUNT > 0)
 * See MBEDTLS_SHA1_C for more information.
 */
#if defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_SHA1_ALT
#endif

/**
 * \def MBEDTLS_SHA256_ALT
 *
 * Enable hardware acceleration for the SHA-224 and SHA-256 cryptographic
 * hash algorithms.
 *
 * Module:  sl_crypto/src/sl_sha256.c
 *          or
 *          sl_crypto/src/slcl_sha256.c if MBEDTLS_SLCL_PLUGINS is defined.
 * Caller:  library/entropy.c
 *          library/mbedtls_md.c
 *          library/ssl_cli.c
 *          library/ssl_srv.c
 *          library/ssl_tls.c
 *
 * Requires: MBEDTLS_SHA256_C and (CRYPTO_COUNT > 0)
 * See MBEDTLS_SHA256_C for more information.
 */
#if defined(CRYPTO_COUNT) && (CRYPTO_COUNT > 0)
#define MBEDTLS_SHA256_ALT
#endif

#endif /* #if !defined(NO_CRYPTO_ACCELERATION) */

/**
 * \def MBEDTLS_TIMING_ALT
 *
 * Enable timing support for SiliconLabs devices including
 * mbedtls_timing_init(), mbedtls_timing_free() and
 * mbedtls_timing_hardclock() using the DWT cycle counter to return
 * timestamps.
 *
 * Requires MBEDTLS_TIMING_C and DWT (defined by ARM CMSIS interface
 * for some Cortex-M cores).
 */
#if defined (DWT)
#define MBEDTLS_TIMING_ALT
#endif

/* Default ECC configuration for Silicon Labs devices: */

/* ECC curves supported by CRYPTO hardware module: */
#define MBEDTLS_ECP_DP_SECP192R1_ENABLED
#define MBEDTLS_ECP_DP_SECP224R1_ENABLED
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED

/* Save RAM by adjusting to our exact needs */
#define MBEDTLS_ECP_MAX_BITS   256
#ifndef MBEDTLS_MPI_MAX_SIZE
#define MBEDTLS_MPI_MAX_SIZE    32 // 384 bits is 48 bytes
#endif

/* 
   Set MBEDTLS_ECP_WINDOW_SIZE to configure
   ECC point multiplication window size, see ecp.h:
   2 = Save RAM at the expense of speed
   3 = Improve speed at the expense of RAM
   4 = Optimize speed at the expense of RAM
*/
#define MBEDTLS_ECP_WINDOW_SIZE        3
#define MBEDTLS_ECP_FIXED_POINT_OPTIM  0

/* Significant speed benefit at the expense of some ROM */
#define MBEDTLS_ECP_NIST_OPTIM

/* Include the default mbedtls config file */
#include "mbedtls/config.h"

#undef MBEDTLS_FS_IO
#define MBEDTLS_NO_PLATFORM_ENTROPY
/* Hardware entropy source is not yet supported. Uncomment this macro to 
   provide your own implementation of an entropy collector. */
//#define MBEDTLS_ENTROPY_HARDWARE_ALT

/* Exclude and/or change default config here. E.g.: */
//#undef MBEDTLS_ECP_DP_SECP384R1_ENABLED
//#undef MBEDTLS_ECP_DP_SECP521R1_ENABLED
//#undef MBEDTLS_ECP_DP_BP384R1_ENABLED
//#undef MBEDTLS_ECP_DP_BP512R1_ENABLED
//#undef MBEDTLS_SHA512_C

#include "mbedtls/check_config.h"

/** @} (end section sl_crypto_config) */
/** @} (end addtogroup sl_crypto_config) */

#endif /* MBEDTLS_CONFIG_SL_CRYPTO_ALL_ACCELERATION_H */
