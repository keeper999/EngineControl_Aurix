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
**   $FILENAME   : SpiSlave.h $                                               **
**                                                                            **
**   $CC VERSION : \main\10 $                                                 **
**                                                                            **
**   $DATE       : 2014-09-19 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of SPI Slave driver.                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY : [cover parentID= DS_NAS_PR746,] [/cover]
*******************************************************************************/

#ifndef SPISLAVE_H
#define SPISLAVE_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h  */
#include "Std_Types.h"

#include "Mcal.h"
#include "Mcal_DmaLib.h"

/* Inclusion from Diagnostic Error Manager File */
/* The module shall include the Dem.h file.*/
#include "Spi.h"     

#if(SPI_SLAVE_ENABLE == STD_ON)             

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define SPI_INSTANCE_ID       ((uint8)0U)

#define SPI_VENDOR_ID         (17U)
#define SPI_MODULE_ID         (83U)

/* API Service ID's */
/* API Service ID for Spi_SlaveSetupEB() */
#define SPI_SLAVE_SID_SETUPEB      ((uint8)0x11)

/* API Service ID for Spi_SlaveReadPrepare() */
#define SPI_SLAVE_SID_READPREPARE    ((uint8)0x12)


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
#if (SPI_SLAVE_ENABLE == STD_ON)

typedef struct Spi_SlaveChnlAccessType
{
  Spi_DmaConfigType DmaChannelIdx;
  /* Current Channel Index on the Async Bus */
  uint8  CurrentChannelIndex;
  
 
}Spi_SlaveChnlAccessType;

#endif



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/* UTP fix #AI00249141 */
#define SPI_START_SEC_ASIL1_VAR_FAST_32BIT
#include "MemMap.h"

/* Variable to Hold Job Result. */
extern uint32 Spi_SlaveJobResult[SPI_JOB_ASIL_ARRAY_INDEX];

#define SPI_STOP_SEC_ASIL1_VAR_FAST_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"

extern void Spi_lSlaveCancel(Spi_SequenceType Sequence);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /*SPI_SLAVE_ENABLE == STD_ON */

#endif /* SPISLAVE_H */