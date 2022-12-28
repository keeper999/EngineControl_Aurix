/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : CAN                                                     */
/* !Description     : CAN Component                                           */
/*                                                                            */
/* !File            : Can.h                                                   */
/* !Description     : Upper Layer of CAN_17_MCANP component                   */
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
 * %PID: P2017_BSW:0A192495.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef _CAN_H_
#define _CAN_H_

#include "Can_17_MCanP.h"

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Can_ConfigType                  Can_17_MCanP_ConfigType

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define Can_Init                        Can_17_MCanP_Init
#define Can_CheckBaudrate               Can_17_MCanP_CheckBaudrate
#define Can_ChangeBaudrate              Can_17_MCanP_ChangeBaudrate
#define Can_SetControllerMode           Can_17_MCanP_SetControllerMode
#define Can_DisableControllerInterrupts Can_17_MCanP_DisableControllerInterrupts
#define Can_EnableControllerInterrupts  Can_17_MCanP_EnableControllerInterrupts
#define Can_Write                       Can_17_MCanP_Write
#define Can_MainFunction_Write          Can_17_MCanP_MainFunction_Write
#define Can_MainFunction_Read           Can_17_MCanP_MainFunction_Read
#define Can_MainFunction_BusOff         Can_17_MCanP_MainFunction_BusOff
#define Can_MainFunction_Wakeup         Can_17_MCanP_MainFunction_Wakeup
#define Can_MainFunction_Mode           Can_17_MCanP_MainFunction_Mode
#define Can_CheckWakeup                 Can_17_MCanP_CheckWakeup
#define Can_IsrBusOffHandler            Can_17_MCanP_IsrBusOffHandler
#define Can_IsrReceiveHandler           Can_17_MCanP_IsrReceiveHandler
#define Can_IsrTransmitHandler          Can_17_MCanP_IsrTransmitHandler
#define Can_GetVersionInfo              Can_17_MCanP_GetVersionInfo

#endif  /* _CAN_H_ */

/*------------------------------ end of file ---------------------------------*/
