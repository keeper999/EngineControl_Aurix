/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : LIN                                                     */
/* !Description     : LIN Component                                           */
/*                                                                            */
/* !File            : LIN.h                                                   */
/* !Description     : Upper Layer of LIN_17_ASCLIN component                  */
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
 * %PID: P2017_BSW:0A192483.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef _LIN_H_
#define _LIN_H_

#include "Lin_17_AscLin.h"

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Lin_ChannelType                 Lin_17_AscLin_ChannelType 
#define Lin_ConfigType                  Lin_17_AscLin_ConfigType 
#define Lin_ChannelInfoType             Lin_17_AscLin_ChannelInfoType

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define Lin_GetVersionInfo              Lin_17_AscLin_GetVersionInfo
#define Lin_Init                        Lin_17_AscLin_Init
#define Lin_WakeupValidation            Lin_17_AscLin_WakeupValidation
#define Lin_CheckWakeup                 Lin_17_AscLin_CheckWakeup
#define Lin_SendFrame                   Lin_17_AscLin_SendFrame
#define Lin_GoToSleep                   Lin_17_AscLin_GoToSleep
#define Lin_GoToSleepInternal           Lin_17_AscLin_GoToSleepInternal
#define Lin_Wakeup                      Lin_17_AscLin_Wakeup
#define Lin_GetStatus                   Lin_17_AscLin_GetStatus
#define Lin_IsrReceive                  Lin_17_AscLin_IsrReceive
#define Lin_IsrTransmit                 Lin_17_AscLin_IsrTransmit
#define Lin_IsrError                    Lin_17_AscLin_IsrError

#endif  /* _LIN_H_ */

/*------------------------------ end of file ---------------------------------*/
