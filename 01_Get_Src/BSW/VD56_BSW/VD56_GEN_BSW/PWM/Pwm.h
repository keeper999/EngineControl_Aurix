/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : PWM                                                     */
/* !Description     : PWM Component                                           */
/*                                                                            */
/* !File            : Pwm.h                                                   */
/* !Description     : Upper Layer of PWM_17_GTM components                    */
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
 * %PID: P2017_BSW:0A111606.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef _PWM_H_
#define _PWM_H_

#include "Pwm_17_Gtm.h"
#include "Pwm_17_Gtm_add_on.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define Pwm_DeInit                Pwm_17_Gtm_DeInit
#define Pwm_DisableNotification   Pwm_17_Gtm_DisableNotification
#define Pwm_EnableNotification    Pwm_17_Gtm_EnableNotification
#define Pwm_GetOutputState        Pwm_17_Gtm_GetOutputState
#define Pwm_Init                  Pwm_17_Gtm_Init
#define Pwm_SetDutyCycle          Pwm_17_Gtm_SetDutyCycle
#define Pwm_SetOutputToIdle       Pwm_17_Gtm_SetOutputToIdle
#define Pwm_SetPeriodAndDuty      Pwm_17_Gtm_SetPeriodAndDuty
#define Pwm_GetVersionInfo        Pwm_17_Gtm_GetVersionInfo

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Pwm_ChannelClassType      Pwm_17_Gtm_ChannelClassType
#define Pwm_ChannelType           Pwm_17_Gtm_ChannelType
#define Pwm_ConfigType            Pwm_17_Gtm_ConfigType
#define Pwm_EdgeNotificationType  Pwm_17_Gtm_EdgeNotificationType
#define Pwm_OutputStateType       Pwm_17_Gtm_OutputStateType
#define Pwm_PeriodType            Pwm_17_Gtm_PeriodType

#endif  /* _PWM_H_ */

/*------------------------------ end of file ---------------------------------*/
