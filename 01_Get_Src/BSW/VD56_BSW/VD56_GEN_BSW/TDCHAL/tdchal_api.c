/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : TDCHAL Component                                        */
/*                                                                            */
/* !File            : TDCHAL_API.c                                            */
/* !Description     : APIs of the TDCHAL Component                            */
/*                                                                            */
/* !Reference       : PTS DOC 5038320                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A273.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "std_types.h"
#include "std_limits.h"
#include "CRKHAL.h"
#include "TDCHAL_Cfg.h"
#include "tdchal.h"
#include "tdchal_l.h"
#include "TDCHAL_I.h"


#define TDCHAL_START_SEC_CODE
#include "TDCHAL_MemMap.h"

#ifndef TDCHAL_coBDC_ENABLED
   #error "TDCHAL_coBDC should be defined"
#endif

#ifndef TDCHAL_coBDC_CALC_PER_ON_ENABLED
   #error "TDCHAL_coBDC_CALC_PER_ON_ENABLED should be defined"
#endif

#ifndef TRUE
   #error "TRUE should be defined"
#endif

/******************************************************************************/
/* !FuncName    : TDCHAL_vidInit                                              */
/* !Description : Initialize TDCHAL component                                 */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidInit(void)
{
   TDCHAL_vidDriverInitialisation();
}

/******************************************************************************/
/* !FuncName    : TDCHAL_vidEnable                                            */
/* !Description : Enable TDCHAL component                                     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidEnable(void)
{
   if (TDCHAL_vbEnabled == FALSE)
   {
      CRKHAL_vidActivateAlarmMode(CRKHAL_u8ALARM_TDC, MODE_NO_ACTION);
      TDCHAL_vidFIND_LAST_SETPOINT();
      TDCHAL_vidGET_TDC_COUNTER(TDCHAL_vu8Counter);
      TDCHAL_vidNEXT_SETPOINT();
      TDCHAL_vidPROGRAM_SETPOINT();
      TDCHAL_vidApproximatePeriod();
      TDCHAL_vbFirstTdc = TRUE;
#if (  (TDCHAL_coBDC_ENABLED == TRUE) \
    && (TDCHAL_coBDC_CALC_PER_ON_ENABLED == TRUE))
      TDCHAL_vbFirstBdc = TRUE;
#endif  /* TDCHAL_coBDC_ENABLED and TDCHAL_coBDC_CALC_PER_ON_ENABLED */
      TDCHAL_vbEnabled = TRUE;
      CRKHAL_vidEnableAlarmNotif(CRKHAL_u8ALARM_TDC);
   }
}

/******************************************************************************/
/* !FuncName    : TDCHAL_vidDisable                                           */
/* !Description : Disable TDCHAL component                                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidDisable(void)
{
   TDCHAL_vidDriverInitialisation();
}

/******************************************************************************/
/* !FuncName    : TDCHAL_udtGetCounter                                        */
/* !Description : Get the current TDC Counter                                 */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType TDCHAL_udtGetCounter
(
   uint8* pu8Counter
)
{
   Std_ReturnType udtLocalStatus;

   *pu8Counter = TDCHAL_vu8Counter;
   if (TDCHAL_vbEnabled == TRUE)
   {
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/* !FuncName    : TDCHAL_udtGetPeriod                                         */
/* !Description : Get latest calculated TDC period                            */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
Std_ReturnType TDCHAL_udtGetPeriod
(
   uint32* pu32Period
)
{
   Std_ReturnType  udtLocalStatus;
   CRKHAL_tenuMode enuLocalCrkMode;
   uint32          u32LocalPeriod;

   u32LocalPeriod = TDCHAL_vu32Period;
   if ((u32LocalPeriod != UINT32_MAX) && (TDCHAL_vbEnabled == TRUE))
   {
      *pu32Period = u32LocalPeriod;
      udtLocalStatus = CRKHAL_udtReadMode(&enuLocalCrkMode);
      if (enuLocalCrkMode == CRKHAL_udtNORMAL_MODE)
      {
         udtLocalStatus = E_OK;
      }
      else
      {
         udtLocalStatus = E_NOT_OK;
      }
   }
   else
   {
      *pu32Period = UINT32_MAX;
      udtLocalStatus = E_NOT_OK;
   }
   return(udtLocalStatus);
}

#define TDCHAL_STOP_SEC_CODE
#include "TDCHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
