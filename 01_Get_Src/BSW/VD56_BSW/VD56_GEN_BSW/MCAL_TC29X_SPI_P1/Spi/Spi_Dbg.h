/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Spi_Dbg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2013-10-23 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of SPI Handler driver.                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY : 
*******************************************************************************/


#ifndef SPI_DBG_H
#define SPI_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Spi.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_START_SEC_VAR_UNSPECIFIED
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if ( SPI_DEBUG_SUPPORT == STD_ON )
extern volatile Spi_StatusType Spi_BusStatus;
#endif
#endif

#ifdef VALEO_PATCH_SPI_MEMMAP_SEC
#define SPI_STOP_SEC_VAR_UNSPECIFIED
#include "SPI_MemMap.h"
#endif /* VALEO_PATCH_SPI_MEMMAP_SEC   */

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* SPI_DBG_H */

