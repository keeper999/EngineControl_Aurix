/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : PWM                                                     */
/* !Description     : Pulse Width Modulation Module.                          */
/*                                                                            */
/* !File            : Pwm_17_Gtm_add_on.h                                     */
/* !Description     : This file defines the add-on API of the PWM component.  */
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
 * %PID: P2017_BSW:0A111502.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef PWM_17_GTM_ADD_ON_H
#define PWM_17_GTM_ADD_ON_H

#include "Pwm_17_Gtm.h"
#include "Std_Types.h"

#define PWM_17_GTM_START_SEC_CODE
#include "PWM_17_GTM_MemMap.h"

extern uint16 Pwm_17_Gtm_vidGetDutyCycle(Pwm_17_Gtm_ChannelType ChannelNumber);

#define PWM_17_GTM_STOP_SEC_CODE
#include "PWM_17_GTM_MemMap.h"

#endif /* PWM_17_GTM_ADD_ON_H */
/*------------------------------ end of file ---------------------------------*/
