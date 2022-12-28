/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_FlsLoader.h                                      */
/* !Description     : APIs of DEVHAL_FLSLOADER Component                      */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef DEVHAL_FLSLOADER_H
#define DEVHAL_FLSLOADER_H

#include "Std_Types.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DEVHAL_START_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"

void DEVHAL_vidInitFlsLoader(void);
void DEVHAL_vidEraseCalib(uint32 u32StartAddress, uint32 u32NbSectors);
void DEVHAL_vidCopyCalib(uint32 u32SrcStartAddress, uint32 u32DestStartAddress, uint32 u32NbOfBytes);

#define DEVHAL_STOP_SEC_CODE_COPY_CALIB
#include "DEVHAL_MemMap.h"

#endif /* DEVHAL_FLSLOADER_H */

/*-------------------------------- end of file -------------------------------*/
