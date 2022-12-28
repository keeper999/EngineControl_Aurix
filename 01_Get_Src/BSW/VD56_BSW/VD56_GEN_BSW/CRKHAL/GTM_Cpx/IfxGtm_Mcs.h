/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : GTM_MCS                                                 */
/* !Description     : GTM_MCS Component                                       */
/*                                                                            */
/* !File            : IfxGtm_Mcs.h                                            */
/* !Description     : Definition of data of MCS Component                     */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/******************************************************************************/
/* VERSION   : v.0.1          DATE : Oct 18 2013                         */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A18523.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXGTM_MCS_H_
#define IFXGTM_MCS_H_

#include "Std_Types.h"
#include "IfxGtm_bf.h"
#include "IfxGtm_Def.h"
#include "IfxGtm_Mcs.h"
#include "IfxGtm_Reg.h"

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
/** \addtogroup CRAKHAL
 * \{ */
/******************************************************************************/
/* !FuncName    : GTM_CLEAR_NOTIFY_MCS                                        */
/* !Description : This macro Clears the MCS IRQ Notification  				  */
/*                                                                            */
/******************************************************************************/
/* B.MCS_IRQ */
#define GTM_CLEAR_NOTIFY_MCS      GTM_MCS0_CH0_IRQ_NOTIFY.U = (0x1U)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_INTERRUPT_MCS                                    */
/* !Description : This macro Enables the MCS Interrupt      				  */
/*                                                                            */
/******************************************************************************/
#define GTM_ENABLE_INTERRUPT_MCS  GTM_MCS0_CH0_IRQ_EN.U = (0x7U)

/******************************************************************************/
/* !FuncName    : GTM_ENABLE_MCS                                              */
/* !Description : This macro Enables the MCS                				  */
/*                                                                            */
/******************************************************************************/
/* GTM_MCS0_CH0_CTRL.B.EN = (1U); */
#define GTM_ENABLE_MCS           \
do \
{ \
 IFX_GTM_SET_BIT(GTM_MCS0_CH0_CTRL.U,  IFX_GTM_MCS_CH_CTRL_EN_OFF); \
}\
while(0)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_INTERRUPT_MCS                                   */
/* !Description : This macro Disables the MCS Interrupt        				  */
/*                                                                            */
/******************************************************************************/
#define GTM_DISABLE_INTERRUPT_MCS GTM_MCS0_CH0_IRQ_EN.U = (0x0U)

/******************************************************************************/
/* !FuncName    : GTM_DISABLE_MCS                                             */
/* !Description : This macro Disables the MCS               				  */
/*                                                                            */
/******************************************************************************/
/* GTM_MCS0_CH0_CTRL.B.EN = (0U); */
#define GTM_DISABLE_MCS          \
do \
{ \
	IFX_GTM_CLEAR_BIT(GTM_MCS0_CH0_CTRL.U, IFX_GTM_MCS_CH_CTRL_EN_OFF); \
}\
while(0)	

/******************************************************************************/
/*                           Typedefs                                         */
/******************************************************************************/


/******************************************************************************/
/*                           Enums                                            */
/******************************************************************************/


/******************************************************************************/
/*                           Struct                                           */
/******************************************************************************/


/******************************************************************************/
/*                           Variables                                        */
/******************************************************************************/

#define CRKHAL_START_SEC_CODE
#include "CRKHAL_MemMap.h"

/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/

void IfxGtm_vidUpdateToothTskDurationThd(uint32 CRKHAL_u32ToothTskDurationThd);

void IfxGtm_loadCodeToMcs0(void);

void IfxGtm_vidMcs0Init(void);

void IfxGtm_vidMcsResetVars(void);

#define CRKHAL_STOP_SEC_CODE
#include "CRKHAL_MemMap.h"

#endif /* IFXGTM_MCS_H_ */

/*------------------------------ end of file ---------------------------------*/
