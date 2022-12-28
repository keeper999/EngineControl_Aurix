/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Mcal_DmaLib.c $                                            **
**                                                                           **
**  $CC VERSION : \main\12 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-28 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains Mcal Dma library routines               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxDma_reg.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxSrc_reg.h"
/* Own header file */
#include "Mcal.h"
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"
#include "Mcal_DmaLib.h"

/*******************************************************************************
**                      File Inclusion Check                                  **
*******************************************************************************/
#ifndef MCAL_SW_MAJOR_VERSION
#error "MCAL_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_MINOR_VERSION
  #error "MCAL_SW_MINOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_PATCH_VERSION
#error "MCAL_SW_PATCH_VERSION is not defined. "
#endif

#if ( MCAL_SW_MAJOR_VERSION != 1 )
  #error "MCAL_SW_MAJOR_VERSION does not match. "
#endif

#if ( MCAL_SW_MINOR_VERSION != 0 )
  #error "MCAL_SW_MINOR_VERSION does not match. "
#endif


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*Memory Map of the Code*/
#define MCAL_DMALIB_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_7]        [/cover]
** Syntax           : void Mcal_DmaEnableIntr                                 **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Dma Hw channel Interrupt             **
*******************************************************************************/
void  Mcal_DmaEnableIntr(Dma_ChannelType Channel)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;

  MoveEngCh0BaseAddr = SRC_DMACH0ADDR;

  IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)MoveEngCh0BaseAddr +
                                                           Channel);
  IntrSrc.SRE = 1U;
  IntrSrc.CLRR = 1U;
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)MoveEngCh0BaseAddr + Channel) =
                                                                   IntrSrc;
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_8]        [/cover]
** Syntax           :  void Mcal_DmaDisableIntr                               **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Dma Hw channel Interrupt             **
*******************************************************************************/
void Mcal_DmaDisableIntr(Dma_ChannelType Channel)
{
  Ifx_SRC_SRCR_Bits IntrSrc;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;

    MoveEngCh0BaseAddr = SRC_DMACH0ADDR;


    IntrSrc = *((volatile Ifx_SRC_SRCR_Bits *)(void *)MoveEngCh0BaseAddr +
                                                                    Channel);
  if (IntrSrc.SRE == 1U)
  {
    IntrSrc.CLRR = 1U;
    IntrSrc.IOVCLR = 1U;
    IntrSrc.SWSCLR = 1U;
    IntrSrc.SRE = 0U; /*  Disable intr */
  *((volatile Ifx_SRC_SRCR_Bits *)(void *)MoveEngCh0BaseAddr + Channel) =
                                                                    IntrSrc;
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR96_2]        [/cover] 
** Syntax           :  void Mcal_DmaCfgNoOfMovesPerTransfer                   **
** (                                                                          **
**   Dma_ChannelType Channel, uint8 NoOfMoves                                 **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                NoOfMoves - No of Dma Moves (logical no)                    **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to configure the No of Dma moves per transfer  **
*******************************************************************************/
void Mcal_DmaCfgNoOfMovesPerTransfer(Dma_ChannelType Channel, uint8 NoOfMoves)
{
  uint8 BlkmVal;

  switch(NoOfMoves)
  {
    case 1:
    {
      BlkmVal = 0U;
      break;
    }

    case 2:
    {
      BlkmVal = 1U;
      break;
    }

    case 4:
    {
      BlkmVal = 2U;
      break;
    }

    case 8:
    {
      BlkmVal = 3U;
      break;
    }

    case 16:
    {
      BlkmVal = 4U;
      break;
    }
    case 3:
    {
      BlkmVal = 5U;
      break;
    }
    case 5:
    {
      BlkmVal = 6U;
      break;
    }
    case 9:
    {
      BlkmVal = 7U;
      break;
    }
    default:
    {
      BlkmVal = 0U;
      break;
    }
  }

  MODULE_DMA.CH[Channel].CHCFGR.U  |=
                       (uint32_t)((uint32)BlkmVal << DMA_CHCFGR_BLKM_BIT_POS);

}


/*Memory Map of the Code*/
#define MCAL_DMALIB_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"
