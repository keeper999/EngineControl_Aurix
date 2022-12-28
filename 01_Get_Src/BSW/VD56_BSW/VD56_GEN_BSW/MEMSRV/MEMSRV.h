/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : MEMSRV                                                  */
/* !Description     : Memory management services                              */
/*                                                                            */
/* !File            : MEMSRV.h                                                */
/* !Description     : MEMSRV header file                                      */
/*                                                                            */
/* !Reference       : PON EEM NT 05 1920 01                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:MEMSRV H-99055480X4420X508.A-SRC;1.1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MEMSRV_H
#define MEMSRV_H

#include "Std_Types.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define MEMSRV_START_SEC_CODE
#include "MEMSRV_MemMap.h"

void MEMSRV_vidCopyU8 (uint8  *pu8Dest,  const uint8  *pu8Src,  uint16 u16ElementNumber);
void MEMSRV_vidCopyU16(uint16 *pu16Dest, const uint16 *pu16Src, uint16 u16ElementNumber);
void MEMSRV_vidCopyU32(uint32 *pu32Dest, const uint32 *pu32Src, uint16 u16ElementNumber);

void MEMSRV_vidSetU8  (uint8  *pu8Dest,  uint8  u8Value,  uint16 u16ElementNumber);
void MEMSRV_vidSetU16 (uint16 *pu16Dest, uint16 u16Value, uint16 u16ElementNumber);
void MEMSRV_vidSetU32 (uint32 *pu32Dest, uint32 u32Value, uint16 u16ElementNumber);

#define MEMSRV_STOP_SEC_CODE
#include "MEMSRV_MemMap.h"

#endif /* MEMSRV_H */

/*------------------------------ end of file -------------------------------*/
