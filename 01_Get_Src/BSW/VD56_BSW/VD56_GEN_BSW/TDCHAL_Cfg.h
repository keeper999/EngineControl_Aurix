/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : Configuration of the TDCHAL component                   */
/*                                                                            */
/* !File            : TDCHAL_Cfg.h                                            */
/* !Description     : Configuration of the TDCHAL component                   */
/*                                                                            */
/* !Reference       : V03 NT 09 06361                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192516.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TDCHAL_CFG_H
#define TDCHAL_CFG_H

#include "Std_Types.h"
#include "SWFAIL.h"
#include "TDCHAL_L.h"
#include "TSKSRV.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define TDCHAL_START_SEC_CONST_UNSPECIFIED
#include "TDCHAL_MemMap.h"

/* !MComment: Array of pointer to functions of all defined OnSetPoint.        */
extern void
   (* const TDCHAL_kapfvidOnSetPoint[TDCHAL_u8NB_ACTIONS_ON_SETPOINT])(void);

/* !MComment: Set points functions.                                           */
#define TDCHAL_STOP_SEC_CONST_UNSPECIFIED
#include "TDCHAL_MemMap.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : TDCHAL_vidACTIVATE_TDC_TASK                                 */
/* !Description : Defines the TDC task activation.                            */
/*                                                                            */
/* !LastAuthor  : Mina Sabry                                                  */
/******************************************************************************/
#define TDCHAL_vidACTIVATE_TDC_TASK() \
do \
{ \
   switch (TDCHAL_ku8NumberOfCylinders) \
   { \
      case TDCHAL_u8THREE_CYLINDERS: \
         TSKSRV_vidActivateTask(TDCHAL_TDC_1_EVENT); \
         TSKSRV_vidActivateTask(TDCHAL_TDC_2_EVENT); \
         break; \
   \
      case TDCHAL_u8FOUR_CYLINDERS: \
         TSKSRV_vidActivateTask(TDCHAL_TDC_1_EVENT); \
         TSKSRV_vidActivateTask(TDCHAL_TDC_2_EVENT); \
         TSKSRV_vidActivateTask(TDCHAL_BDC_1_EVENT); \
         TSKSRV_vidActivateTask(TDCHAL_BDC_2_EVENT); \
         break; \
   \
      default: \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
   } \
} \
while (0)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidACTIVATE_BDC_TASK                                 */
/* !Description : Defines the BDC task activation.                            */
/*                                                                            */
/* !LastAuthor  : Mina Sabry                                                  */
/******************************************************************************/
#define TDCHAL_vidACTIVATE_BDC_TASK() \
do \
{ \
   if (TDCHAL_ku8NumberOfCylinders == TDCHAL_u8THREE_CYLINDERS) \
   { \
      TSKSRV_vidActivateTask(TDCHAL_BDC_1_EVENT); \
      TSKSRV_vidActivateTask(TDCHAL_BDC_2_EVENT); \
    } \
} \
while (0)

#endif  /* TDCHAL_CFG_H */

/*------------------------------ end of file ---------------------------------*/
