/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !Module          : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !File            : PWMHAL_Def.h                                                                                    */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A382.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/


#ifndef PWMHAL_DEF_H
#define PWMHAL_DEF_H


#include "Std_Types.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

#define PWMHAL_u8HOD_LINK       0   /* PWMHAL channel linked to HOD PWM driver */
#define PWMHAL_u8PWM_LINK       1   /* PWMHAL channel linked to AUTOSAR PWM driver */
#define PWMHAL_u8SPECIFIC_LINK  2   /* PWMHAL channel linked to a Specific PWM driver */

#endif /* PWMHAL_DEF_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/