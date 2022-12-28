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
**  $FILENAME   : Mcu_Dma.c $                                                **
**                                                                            **
**  $CC VERSION : \main\4 $                                                  **
**                                                                            **
**  $DATE       : 2013-10-21 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains basic initialization of DMA module.      **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of controller sfr file */
#include "Mcu.h"
#include "Mcu_Local.h"
#include "Mcal_DmaLib.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Mcu_lDmaInit (void)                                          **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description :  This service shall initialize DMA clock for other drivers   **
**                to use DMA if DMA Complex driver is not used.               **
**                                                                            **
*******************************************************************************/
void Mcu_lDmaInit(void)
{
  /* Enable the DMA clock */
  Mcal_ResetENDINIT();
  MODULE_DMA.CLC.B.DISR  = 0U;
  Mcal_SetENDINIT();

  /* Move Engine Interrupt trigger activated */
  MODULE_DMA.ERRINTR.U = DMA_ERRINTR_ENABLE;
}/*End of Mcu_lDmaInit()*/

#define MCU_STOP_SEC_CODE
#include "MemMap.h"

#define MCU_START_SEC_SAFETY_CODE
#include "MemMap.h"

#if (MCU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lDmaInitCheck (void)                           **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :  This service shall verify the DMA specific                  **
**                initialization done by MCU.                                 **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lDmaInitCheck(void)
{
  Std_ReturnType ErrorFlag;

  ErrorFlag = E_OK;
  
  if (MODULE_DMA.CLC.B.DISS != 0U)
  {
    ErrorFlag = E_NOT_OK;
  }
  
  return ErrorFlag;
}/*End of Mcu_lDmaInitCheck()*/

#endif /*End Of MCU_SAFETY_ENABLE*/

#define MCU_STOP_SEC_SAFETY_CODE
#include "MemMap.h"