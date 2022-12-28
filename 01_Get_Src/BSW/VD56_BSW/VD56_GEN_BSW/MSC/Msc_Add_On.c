/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MSC                                                     */
/* !Description     : Micro Second Channel Module                             */
/*                                                                            */
/* !File            : Msc_Add_On.c                                            */
/* !Description     : This file defines the add-on API of the MSC component.  */
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
 * %PID: P2017_BSW:0A192554.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Limits.h"
#include "Std_Types.h"

#include "IfxMsc_reg.h"
#include "Msc.h"
#include "Msc_Add_On.h"
#include "Msc_Cfg.h"
#include "SchM_MSC.h"

/******************************************************************************/
/* Global Constant Definitions                                                */
/******************************************************************************/
#define MSC_START_SEC_CONST_32BIT
#include "MSC_MemMap.h"

/* To store the Msc driver configuration pointer */
static const Msc_ConfigType * const Msc_kConfigPtr = &Msc_ConfigRoot[0u];

#define MSC_STOP_SEC_CONST_32BIT
#include "MSC_MemMap.h"


#define MSC_START_SEC_CODE
#include "MSC_MemMap.h"

/******************************************************************************/
/* !FuncName    : Msc_vidStartRxTimeoutAlarm                                  */
/* !Description : Programs a Timeout IT if no frame is received after Timeout */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidStartRxTimeoutAlarm(uint8 ModNum)
{
   /* Check if selected MSC module is configured */
   if (Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
   {
      /* Clear the current timeout flag*/
      MSC_REGMAP[ModNum].USCE.B.USTC = MSC_ONE_U;

      /* Reload the Timeout Prescalar and Timeout Value,
         to start the timeout detection*/
      MSC_REGMAP[ModNum].USCE.U = ( (Msc_kConfigPtr->ModCfgPtr[ModNum]->UpstreamTimeoutConfig)
                                  | MSC_TIMEOUT_ENABLE
                                  | MSC_SRN4_USED);
   }
}

/******************************************************************************/
/* !FuncName    : Msc_vidStopRxTimeoutAlarm                                   */
/* !Description : Disables a Timeout IT if no frame is received after Timeout */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidStopRxTimeoutAlarm(uint8 ModNum)
{
   /* Check if selected MSC module is configured */
   if (Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
   {
      /* Clear the current timeout flag*/
      MSC_REGMAP[ModNum].USCE.B.USTC = MSC_ONE_U;

      /* Reload the Timeout Prescalar and Timeout Value,
         to start the timeout detection*/
      MSC_REGMAP[ModNum].USCE.U = ( (Msc_kConfigPtr->ModCfgPtr[ModNum]->UpstreamTimeoutConfig)
                                  | MSC_TIMEOUT_DISABLE
                                  | MSC_SRN4_USED);
   }
}

/******************************************************************************/
/* !FuncName    : Msc_vidEnaRxInterrupt                                       */
/* !Description : Enable Rx Interrupts                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidEnaRxInterrupt(uint8 ModNum)
{
   MSC_REGMAP[ModNum].ICR.B.RDIE = 1u;
}

/******************************************************************************/
/* !FuncName    : Msc_vidDisaRxInterrupt                                      */
/* !Description : Disable Rx Interrupts                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidDisaRxInterrupt(uint8 ModNum)
{
   MSC_REGMAP[ModNum].ICR.B.RDIE = 0u;
}

/******************************************************************************/
/* !FuncName    : Msc_vidEnaTxInterrupt                                       */
/* !Description : Enable Tx Interrupts                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidEnaTxInterrupt(uint8 ModNum)
{
   MSC_REGMAP[ModNum].ICR.B.ECIE = 1u;
}

/******************************************************************************/
/* !FuncName    : Msc_vidDisaTxInterrupt                                      */
/* !Description : Disable Tx Interrupts                                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidDisaTxInterrupt(uint8 ModNum)
{
   MSC_REGMAP[ModNum].ICR.B.ECIE = 0u;
}

/******************************************************************************/
/* !FuncName    : Msc_vidGetRxDataRegAddress                                  */
/* !Description : Gets Addressof Rx Data Register UD0                         */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidGetRxDataRegAddress(uint8 ModNum, uint32 * pu32RxDataRegAddress)
{
   *pu32RxDataRegAddress = (uint32)&(MSC_REGMAP[ModNum].UD[0u].U);
}

/******************************************************************************/
/* !FuncName    : Msc_vidCfgDataRegBitSrc                                     */
/* !Description : Configure the source of channel linked to input Bit Number  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void Msc_vidCfgDataRegBitSrc(uint8 ModNum, uint8 u8BitNumber, uint8 u8ChannelSrc)
{
   uint32 u32DataSrcReg;

   SchM_Enter_MSC_CfgDataRegBitSrc();
   u32DataSrcReg =  MSC_REGMAP[ModNum].DSDSL.U & (~(3u << (2u * u8BitNumber)));
   u32DataSrcReg |= (u8ChannelSrc << (2u * u8BitNumber));
   MSC_REGMAP[ModNum].DSDSL.U = u32DataSrcReg;
   SchM_Exit_MSC_CfgDataRegBitSrc();
}

#define MSC_STOP_SEC_CODE
#include "MSC_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
