/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MSC                                                     */
/* !Description     : Micro Second Channel Module                             */
/*                                                                            */
/* !File            : Msc_Add_On.h                                            */
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
 * %PID: P2017_BSW:0A192485.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MSC_ADD_ON_H
#define MSC_ADD_ON_H

#include "Std_Types.h"

/******************************************************************************/
/* Private Macro Definitions                                                  */
/******************************************************************************/
#define MSC_ONE_U                             (1U)
/* Start Address of MSC Register - MSC0_CLC*/
#define MSC_REGMAP                            ((Ifx_MSC *)(void *) &(MSC0_CLC))

#define MSC_TIMEOUT_ENABLE                    0x0100U
#define MSC_TIMEOUT_DISABLE                   0x0000U
#define MSC_SRN4_USED                         0x2000U

#define MSC_udtDATA_REG_SRC                   0u
#define MSC_udtALTINL_SRC                     2u
#define MSC_udtALTINL_INVERTED_SRC            3u

/******************************************************************************/
/* External Functions                                                         */
/******************************************************************************/
#define MSC_START_SEC_CODE
#include "MSC_MemMap.h"

void Msc_vidStartRxTimeoutAlarm(uint8 ModNum);
void Msc_vidStopRxTimeoutAlarm(uint8 ModNum);
void Msc_vidDisaRxInterrupt(uint8 ModNum);
void Msc_vidDisaTxInterrupt(uint8 ModNum);
void Msc_vidEnaRxInterrupt(uint8 ModNum);
void Msc_vidEnaTxInterrupt(uint8 ModNum);
void Msc_vidGetRxDataRegAddress(uint8 ModNum, uint32 * pu32RxDataRegAddress);
void Msc_vidCfgDataRegBitSrc(uint8 ModNum, uint8 u8BitNumber, uint8 u8ChannelSrc);

#define MSC_STOP_SEC_CODE
#include "MSC_MemMap.h"

#endif /* MSC_ADD_ON_H */
/*------------------------------ end of file ---------------------------------*/
