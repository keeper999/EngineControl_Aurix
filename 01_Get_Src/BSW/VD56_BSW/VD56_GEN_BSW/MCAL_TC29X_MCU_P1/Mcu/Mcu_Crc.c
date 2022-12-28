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
**  $FILENAME   : Mcu_Crc.c $                                                **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2013-10-10 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains basic initialization of CRC(FCE) module. **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Mcu.h"
/* Inclusion of controller sfr file */
#include "IfxFce_reg.h"
#include "Mcu_Local.h"

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

#if (MCU_CRC_HW_USED == STD_ON)  

/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Syntax : void Mcu_lCrcInit (void)                                          **
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
** Description :  This service shall initialize FCE clock and configure the   **
**                configured FCE Kernels.                                     **
**                                                                            **
*******************************************************************************/
void Mcu_lCrcInit(void)
{
  /* Enable the FCE clock */
  Mcal_ResetENDINIT();
  MODULE_FCE0.CLC.B.DISR = 0U; 
  
  /* Configure CFG Register for respective configured kernels */
  Crc_lCfgInit();
  
  #if (MCU_CRC16_HW_MODE == STD_ON)
  FCE0_IN2_CFG.U = 0U;
  #endif
  
  #if (MCU_CRC32_HW_MODE == STD_ON)
  FCE0_IN0_CFG.U = 0U;
  FCE0_IN0_CFG.B.XSEL = 1U;
  FCE0_IN0_CFG.B.REFIN = 1U;
  FCE0_IN0_CFG.B.REFOUT = 1U;
  #endif
  
  Mcal_SetENDINIT();  
}/*End of Mcu_lCrcInit()*/

#define MCU_STOP_SEC_CODE
#include "MemMap.h"

#define MCU_START_SEC_SAFETY_CODE
#include "MemMap.h"

#if (MCU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lCrcInitCheck (void)                           **
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
Std_ReturnType Mcu_lCrcInitCheck(void)
{
  Std_ReturnType ErrorFlag = E_OK;
  uint32         TempFlag;  
  #if (MCU_CRC32_HW_MODE == STD_ON) || (MCU_CRC16_HW_MODE == STD_ON) 
  uint32         RegVal;
  #endif

  ErrorFlag = Crc_lCfgInitCheck();
  
  #if (MCU_CRC16_HW_MODE == STD_ON)
  RegVal = MODULE_FCE0.IN2.CFG.U;
  #endif

  TempFlag = (uint32)MODULE_FCE0.CLC.B.DISS;
  if ( (TempFlag != 0U)
       #if (MCU_CRC16_HW_MODE == STD_ON)
       || (RegVal != 0U)
       #endif
     )       
  {
    ErrorFlag = E_NOT_OK;
  }

  #if (MCU_CRC32_HW_MODE == STD_ON)
  RegVal = MODULE_FCE0.IN0.CFG.U;  
  /* Verify XSEL, REFIN, REFOUT bits */
  if ((ErrorFlag == E_OK) && (RegVal != ((uint32)7U << 8U)))
  {
    ErrorFlag = E_NOT_OK;  
  }
  #endif
  
  return ErrorFlag;
}/*End of Mcu_lCrcInitCheck()*/

#endif /*End Of MCU_SAFETY_ENABLE*/

#define MCU_STOP_SEC_SAFETY_CODE
#include "MemMap.h"

#endif /*#if (MCU_CRC_HW_USED == STD_ON) */
