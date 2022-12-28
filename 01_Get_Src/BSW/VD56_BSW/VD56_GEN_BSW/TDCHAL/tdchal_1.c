/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TDCHAL                                                  */
/* !Description     : TDCHAL Component                                        */
/*                                                                            */
/* !File            : TDCHAL_1.c                                              */
/* !Description     : Functions of the TDCHAL Component                       */
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
 * %PID: P2017_BSW:A275.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "std_types.h"
#include "std_limits.h"
#include "CRKHAL.h"
#include "MATHSRV.h"
#include "TDCHAL_Cfg.h"
#include "TDCHAL_I.h"
#include "TSKSRV.h"
#include "tdchal.h"
#include "tdchal_l.h"


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
/* !FuncName    : TDCHAL_vidInterrupt                                         */
/* !Description : Interrupt handler of crank TDC alarm                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidInterrupt(void)
{
   TDCHAL_vidON_SETPOINT();
   TDCHAL_vidGET_TDC_COUNTER(TDCHAL_vu8Counter);
   TDCHAL_vidNEXT_SETPOINT();
   TDCHAL_vidPROGRAM_SETPOINT();
}

/******************************************************************************/
/* !FuncName    : TDCHAL_vidOnTDC                                             */
/* !Description : Configured handler of TDC events.                           */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
void TDCHAL_vidOnTDC(void)
{
   uint32         u32LocalPeriod;
   uint32         u32LocalTdcDate;
   Std_ReturnType udtLocalRet;


   udtLocalRet = CRKHAL_udtReadToothEdgeDate(&u32LocalTdcDate);
   if(udtLocalRet != E_NOT_OK)
   {
      if (TDCHAL_vbFirstTdc == FALSE)
      {
         u32LocalPeriod   = ( (u32LocalTdcDate - TDCHAL_u32LastTdcDate) 
                            & TDCHAL_u32TOOTH_EDGE_DATE_MASK);
         TDCHAL_vu32Period = (uint32)( ( u32LocalPeriod
                                      * TDCHAL_u16COEF_TIMER_RESOL)
                                    / TDCHAL_u16COEF_DESIRED_RESOL);
      }
      else
      {
         TDCHAL_vidApproximatePeriod();
         TDCHAL_vbFirstTdc = FALSE;
      }
      TDCHAL_u32LastTdcDate = u32LocalTdcDate;
   }
   TDCHAL_vidACTIVATE_TDC_TASK();
}

#if (TDCHAL_coBDC_ENABLED == TRUE)

/******************************************************************************/
/* !FuncName    : TDCHAL_vidOnBDC                                             */
/* !Description : Configured handler of BDC events.                           */
/*                                                                            */
/* !LastAuthor  : G. Mostafa                                                  */
/******************************************************************************/
void TDCHAL_vidOnBDC(void)
{
   uint32         u32LocalBdcDate;
   uint32         u32LocalPeriod;
   Std_ReturnType udtLocalRet;

#if ((TDCHAL_coBDC_CALC_PER_ON_ENABLED == TRUE))
   udtLocalRet = CRKHAL_udtReadToothEdgeDate(&u32LocalBdcDate);
   if(udtLocalRet != E_NOT_OK)
   {
      if (TDCHAL_vbFirstBdc == FALSE)
      {
         u32LocalPeriod   = ( (u32LocalBdcDate - TDCHAL_u32LastBdcDate)
                            & TDCHAL_u32TOOTH_EDGE_DATE_MASK);
         TDCHAL_vu32Period = (uint32)( ( u32LocalPeriod
                                      * TDCHAL_u16COEF_TIMER_RESOL)
                                    / TDCHAL_u16COEF_DESIRED_RESOL);
      }
      else
      {
         TDCHAL_vidApproximatePeriod();
         TDCHAL_vbFirstBdc = FALSE;
      }
      TDCHAL_u32LastBdcDate = u32LocalBdcDate;
   }
#endif /*  TDCHAL_bCALC_PER_ON_BDC_ALLOWED */
   TDCHAL_vidACTIVATE_BDC_TASK();
}
#endif /* TDCHAL_coBDC_ENABLED */

/******************************************************************************/
/* !FuncName    : TDCHAL_vidApproximatePeriod                                 */
/* !Description : Approximates TDC period based on last tooth duration.       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidApproximatePeriod(void)
{
   uint16         u16LocalNumberOfTeeth;
   uint16         u16LocalTargetToothAngle;
   uint32         u32LocalPrevToothDuration;
   uint32         u32LocalToothDuration;
   uint32         u32LocalToothInfoBuf[TDCHAL_u8TOOTH_INFO_BUF_SIZE];
   uint32         u32LocalVar;
   Std_ReturnType udtLocalStatus1;
   Std_ReturnType udtLocalStatus2;

   udtLocalStatus1 = CRKHAL_udtGetToothInfo(TDCHAL_u8TOOTH_INFO_BUF_SIZE,
                                            u32LocalToothInfoBuf);
   u32LocalToothDuration     = u32LocalToothInfoBuf[1];
   u32LocalPrevToothDuration = u32LocalToothInfoBuf[2];

   udtLocalStatus2 = CRKHAL_udtGetTargetToothAngle(&u16LocalTargetToothAngle);
   if ((udtLocalStatus1 == E_OK) && (udtLocalStatus2 == E_OK))
   {
      if (u16LocalTargetToothAngle != UINT16_MIN)
      {
         u16LocalNumberOfTeeth = (uint16)( TDCHAL_u16TDC_OFFSET
                                         / u16LocalTargetToothAngle);
         u32LocalToothDuration = MATHSRV_udtMIN(u32LocalToothDuration,
                                                u32LocalPrevToothDuration);
         u32LocalVar = u32LocalToothDuration * ((uint32)u16LocalNumberOfTeeth);
         TDCHAL_vu32Period = (uint32)( ( u32LocalVar
                                      * TDCHAL_u16COEF_TOOTH_DURATION_RESOL)
                                    / TDCHAL_u16COEF_DESIRED_RESOL);
      }
      else
      {
         TDCHAL_vu32Period = UINT32_MAX;
      }
   }
   else
   {
      TDCHAL_vu32Period = UINT32_MAX;
   }
}

/******************************************************************************/
/* !FuncName    : TDCHAL_vidDriverInitialisation                              */
/* !Description : Internal initialization of TDCHAL component                 */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TDCHAL_vidDriverInitialisation(void)
{
   CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_TDC);
   CRKHAL_vidDeactivateAlarmMode(CRKHAL_u8ALARM_TDC);
   TDCHAL_vu32Period = UINT32_MAX;
   TDCHAL_vbEnabled = FALSE;
   TDCHAL_vbFirstTdc = TRUE;
#if (  (TDCHAL_coBDC_ENABLED == TRUE) \
    && (TDCHAL_coBDC_CALC_PER_ON_ENABLED == TRUE))
   TDCHAL_vbFirstBdc = TRUE;
#endif /* TDCHAL_coBDC_ENABLED and TDCHAL_coBDC_CALC_PER_ON_ENABLED */
}

#define TDCHAL_STOP_SEC_CODE
#include "TDCHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
