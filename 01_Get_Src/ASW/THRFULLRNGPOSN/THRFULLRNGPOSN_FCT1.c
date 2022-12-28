/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRFULLRNGPOSN                                          */
/* !Description     : THRFULLRNGPOSN component.                               */
/*                                                                            */
/* !Module          : THRFULLRNGPOSN                                          */
/* !Description     : THROTTLE FULL RANGE POSITION                            */
/*                                                                            */
/* !File            : THRFULLRNGPOSN_FCT1.C                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / THRFULLRNGPOSN_vidInitOutput                                         */
/*   2 / THRFULLRNGPOSN_vidComput                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 08266 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRFULLRNGPOSN/THRFULLRNGPOS$*/
/* $Revision::   1.0      $$Author::   vgarnier       $$Date::   13 Oct 2010 $*/
/* $Author::   vgarnier                               $$Date::   13 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRFULLRNGPOSN.h"
#include "THRFULLRNGPOSN_L.h"
#include "THRFULLRNGPOSN_IM.h"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRFULLRNGPOSN_vidInitOutput                               */
/* !Description :  Output initialization                                      */
/* !Number      :  FCT.1.1                                                    */
/* !Author      :  N.ABIDI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ssm_filt_throttle_position;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRFULLRNGPOSN_vidInitOutput(void)
{
   VEMS_vidSET(Ssm_filt_throttle_position, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRFULLRNGPOSN_vidComput                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  N.ABIDI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input uint8 Dtc_throttle_position_max_limit;                              */
/*  input uint8 Dtc_throttle_position_min_limit;                              */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  output uint16 Ssm_filt_throttle_position;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRFULLRNGPOSN_vidComput(void)
{
   uint8  u8LocalDtcThrottlePosMaxLimit;
   uint8  u8LocalDtcThrottlePosMinLimit;
   uint16 u16LocalSsm_closed_throttle_pos;
   uint16 u16LocalOutputClamp;
   uint16 u16LocalSsmFiltThrottlePosition;
   uint16 u16LocalSsmRawFiltThrotPosition;
   uint16 u16LocalMaxClamp;
   uint16 u16LocalMinClamp;
   uint32 u32LocalSumMaxClamp;
   sint16 s16LocalDenum;
   sint32 s32LocalSumMinClamp;
   sint32 s32LocalSsmFiltThrottlePosition;

   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);
   VEMS_vidGET(Dtc_throttle_position_max_limit, u8LocalDtcThrottlePosMaxLimit);
   VEMS_vidGET(Dtc_throttle_position_min_limit, u8LocalDtcThrottlePosMinLimit);
   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsmRawFiltThrotPosition);

   /* Scaling : u16LocalSsm_closed_throttle_pos : 100/1024 */
   /* u8LocalDtcThrottlePosMaxLimit: 100/256               */
   u32LocalSumMaxClamp = (uint32)( u16LocalSsm_closed_throttle_pos
                                 + (u8LocalDtcThrottlePosMaxLimit * 4));
   /* Scaling : u16LocalSsm_closed_throttle_pos : 100/1024 */
   /* u8LocalDtcThrottlePosMinLimit: 100/256               */
   s32LocalSumMinClamp = (sint32)( u16LocalSsm_closed_throttle_pos
                                 + (u8LocalDtcThrottlePosMinLimit * 4));

   u16LocalMinClamp = (uint16)MATHSRV_udtMIN(s32LocalSumMinClamp, 65535);
   u16LocalMaxClamp = (uint16)MATHSRV_udtMIN(u32LocalSumMaxClamp, 65535);
   u16LocalOutputClamp =
      (uint16)MATHSRV_udtCLAMP(u16LocalSsmRawFiltThrotPosition,
                               u16LocalMinClamp,
                               u16LocalMaxClamp);
   s16LocalDenum =
      (sint16)(u8LocalDtcThrottlePosMaxLimit - u8LocalDtcThrottlePosMinLimit);
   /* Scaling : u16LocalOutputClamp : 100/1024 */
   /* s32LocalSumMinClamp : 100/1024           */
   /* s16LocalDenum: 100/256                     */
   if (s16LocalDenum != 0)
   {
      s32LocalSsmFiltThrottlePosition =
         ((u16LocalOutputClamp - s32LocalSumMinClamp) * 256) / s16LocalDenum;
   }
   else
   {
      s32LocalSsmFiltThrottlePosition = 1024;
   }
   u16LocalSsmFiltThrottlePosition =
      (uint16)MATHSRV_udtMAX(s32LocalSsmFiltThrottlePosition, 0);
   VEMS_vidSET(Ssm_filt_throttle_position, u16LocalSsmFiltThrottlePosition);

}
/*-------------------------------- end of file -------------------------------*/