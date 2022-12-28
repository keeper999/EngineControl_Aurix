/*********************************************************************************************************************/
/*                                                                                                                    */
/* !Layer          : HAL                                                                                              */
/*                                                                                                                    */
/* !Component      : PWMHAL                                                                                           */
/*                                                                                                                    */
/* !Module         : PWMHAL_CFG                                                                                       */
/* !Description    : Configurations of the PWMHAL component.                                                          */
/*                                                                                                                    */
/* !File           : PWMHAL_Co.h                                                                                      */
/*                                                                                                                    */
/* !Scope          : Public                                                                                           */
/*                                                                                                                    */
/* !Target         : All                                                                                              */
/*                                                                                                                    */
/* !Vendor         : Valeo                                                                                            */
/*                                                                                                                    */
/* Coding language : C                                                                                                */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/** 11/10/14, 10:16:19: generated by Genecode v2.6.0.0                                                                       */
/**********************************************************************************************************************/

#ifndef PWMHAL_CO_H
#define PWMHAL_CO_H


/***************************************************************************************************************************************/
/* DEFINES                                                                                                                             */
/***************************************************************************************************************************************/

#define PWMHAL_coYES 0xAA
#define PWMHAL_coNO  0x55

#define PWMHAL_coHOD_CHANNEL_EXIST        PWMHAL_coNO
#define PWMHAL_coPWM_CHANNEL_EXIST        PWMHAL_coYES
#define PWMHAL_coSPECIFIC_CHANNEL_EXIST   PWMHAL_coYES
#define PWMHAL_coSINGLE_LOWER_LAYER   PWMHAL_coNO


#endif /* PWMHAL_CO_H  */

/*---------------------------------------------------- end of file ---------------------------------------------------*/