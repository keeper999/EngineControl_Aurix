/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TWCMGT                                                  */
/* !Description     : TWCMGT component.                                       */
/*                                                                            */
/* !Module          : TWCMGT                                                  */
/* !Description     : Three Way Catalyst Heating Manager.                     */
/*                                                                            */
/* !File            : TWCMGT_FCT3.C                                           */
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
/*   1 / TWCMGT_VidCount_Light_Off_Time                                       */
/*   2 / TWCMGT_VidTWCEstHeatDeactLgOfTim                                     */
/*   3 / TWCMGT_VidManageLightOff                                             */
/*   4 / TWCMGT_VidMngWaste_Gate_Position                                     */
/*   5 / TWCMGT_VidManage_Output                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 02024 / 01                                        */
/* !OtherRefs   : 01460_10_02228 / 1                                          */
/* !OtherRefs   : VEMS V02 ECU#054415                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TWCMGT.h"
#include "TWCMGT_L.h"
#include "TWCMGT_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidCount_Light_Off_Time                             */
/* !Description :  This block calculates the duration since the beginning of  */
/*                 the TWC heating. If the heating is deactivated, the counter*/
/*                 still goes on.                                             */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TWCMgt_tiLiOff;                                              */
/*  input uint16 TWCMgt_tiSdlFast_C;                                          */
/*  output uint16 TWCMgt_tiLiOff;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidCount_Light_Off_Time(void)
{
   uint32  u32LocalCounter;


   u32LocalCounter = (uint32)(TWCMgt_tiLiOff + TWCMgt_tiSdlFast_C) ;
   TWCMgt_tiLiOff = (uint16)MATHSRV_udtMIN(u32LocalCounter,50000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidTWCEstHeatDeactLgOfTim                           */
/* !Description :  This block estimates the duration before light-off 1 which */
/*                 has to be applied if the three way catalyst heating has    */
/*                 been deactivated.                                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input uint16 TWCMgt_tiLiOff;                                              */
/*  input uint16 TWCMgt_tiLiOffNormCdn;                                       */
/*  input uint16 TWCMGT_u16tiLiOffOutMem;                                     */
/*  input uint16 TWCMgt_tiHeatCaseDeac_A[12];                                 */
/*  input uint16 TWCMGT_u16InputTtiHeatCaseDeac;                              */
/*  input uint16 TWCMgt_tiHeatCaseDeacLiOff_T[12];                            */
/*  output uint16 TWCMGT_u16tiLiOffOutMem;                                    */
/*  output uint16 TWCMGT_u16InputTtiHeatCaseDeac;                             */
/*  output uint16 TWCMgt_tiLiOffHeatDeac;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidTWCEstHeatDeactLgOfTim(void)
{
   uint16  u16LocalCalcPara;
   uint16  u16LocalInterp1D;
   uint32  u32LocalSum;
   sint32  s32LocalSum;


   if (TWCMgt_bTWCHeatReq != 0)
   {
      TWCMGT_u16tiLiOffOutMem = TWCMgt_tiLiOff;
   }
   s32LocalSum = (sint32)(TWCMgt_tiLiOffNormCdn - TWCMGT_u16tiLiOffOutMem);
   TWCMGT_u16InputTtiHeatCaseDeac =(uint16)MATHSRV_udtMAX(s32LocalSum, 0);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU16(TWCMgt_tiHeatCaseDeac_A,
                                   TWCMGT_u16InputTtiHeatCaseDeac,
                                   12);
   u16LocalInterp1D =
      MATHSRV_u16Interp1d(TWCMgt_tiHeatCaseDeacLiOff_T, u16LocalCalcPara);
   u32LocalSum = (uint32)(TWCMGT_u16tiLiOffOutMem + u16LocalInterp1D);
   TWCMgt_tiLiOffHeatDeac = (uint16)MATHSRV_udtMIN(u32LocalSum, 50000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidManageLightOff                                   */
/* !Description :  This block manages the light-off depending on the current  */
/*                 situation. Several parameters are taking into account:Cold */
/*                 or warm temperature, Catalyst heating activation status and*/
/*                 Time since start of catalyst heating or catalyst           */
/*                 temperature threshold.                                     */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 ExM_tOxCEstim;                                               */
/*  input sint16 TWCMgt_tTWCLiOff_C;                                          */
/*  input boolean TWCMGT_bInTWCLiOffTurnOnPrev;                               */
/*  input uint16 TWCMgt_tiDlyTWCLiOff_C;                                      */
/*  input uint16 TWCMGT_u16TWCLiOffCount;                                     */
/*  input uint16 TWCMgt_tiSdlFast_C;                                          */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input uint16 TWCMgt_tiLiOff;                                              */
/*  input uint16 TWCMgt_tiLiOffNormCdn;                                       */
/*  input uint16 TWCMgt_tiLiOffHeatDeac;                                      */
/*  input uint8 TWCMgt_stModLiOffClc_C;                                       */
/*  input boolean TWCMGT_bOutTWCLiOffTurnOnDelay;                             */
/*  output uint16 TWCMGT_u16TWCLiOffCount;                                    */
/*  output boolean TWCMGT_bOutTWCLiOffTurnOnDelay;                            */
/*  output boolean TWCMGT_bInTWCLiOffTurnOnPrev;                              */
/*  output boolean TWCMgt_bLiOffDone;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidManageLightOff(void)
{
   boolean  bLocalTWCHeatReq;
   boolean  bLocalTWCLiOffTurnOndelay;
   boolean  bLocalTWCMgt_bLiOffDone;
   sint16   s16LocalExM_tOxCEstim;


   VEMS_vidGET(ExM_tOxCEstim, s16LocalExM_tOxCEstim);
   if (s16LocalExM_tOxCEstim > TWCMgt_tTWCLiOff_C)
   {
      bLocalTWCLiOffTurnOndelay = 1;
   }
   else
   {
      bLocalTWCLiOffTurnOndelay = 0;
   }
   if (bLocalTWCLiOffTurnOndelay != 0)
   {
      if (TWCMGT_bInTWCLiOffTurnOnPrev == 0)
      {
         TWCMGT_u16TWCLiOffCount = TWCMgt_tiDlyTWCLiOff_C;
      }
      else
      {
         if (TWCMGT_u16TWCLiOffCount >= TWCMgt_tiSdlFast_C)
         {
            TWCMGT_u16TWCLiOffCount =
               (uint16)(TWCMGT_u16TWCLiOffCount - TWCMgt_tiSdlFast_C);
         }
         else
         {
            TWCMGT_u16TWCLiOffCount = 0;
         }
      }
      if (TWCMGT_u16TWCLiOffCount == 0)
      {
         TWCMGT_bOutTWCLiOffTurnOnDelay = 1;
      }
      else
      {
         TWCMGT_bOutTWCLiOffTurnOnDelay = 0;
      }
   }
   else
   {
      TWCMGT_bOutTWCLiOffTurnOnDelay = 0;
   }
   TWCMGT_bInTWCLiOffTurnOnPrev = bLocalTWCLiOffTurnOndelay;

   if (TWCMgt_bTWCHeatReq != 0)
   {
      if (TWCMgt_tiLiOff > TWCMgt_tiLiOffNormCdn)
      {
         bLocalTWCHeatReq = 1;
      }
      else
      {
         bLocalTWCHeatReq = 0;
      }
   }
   else
   {
      if (TWCMgt_tiLiOff > TWCMgt_tiLiOffHeatDeac)
      {
         bLocalTWCHeatReq = 1;
      }
      else
      {
         bLocalTWCHeatReq = 0;
      }
   }

   switch (TWCMgt_stModLiOffClc_C)
   {
      case 0:
         bLocalTWCMgt_bLiOffDone = TWCMGT_bOutTWCLiOffTurnOnDelay;
         break;

      case 1:
         if (  (TWCMGT_bOutTWCLiOffTurnOnDelay != 0)
            || (bLocalTWCHeatReq != 0))
         {
            bLocalTWCMgt_bLiOffDone = 1;
         }
         else
         {
            bLocalTWCMgt_bLiOffDone = 0;
         }
         break;

      case 2:
         bLocalTWCMgt_bLiOffDone = bLocalTWCHeatReq;
         break;

      default:
         bLocalTWCMgt_bLiOffDone = bLocalTWCHeatReq;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(TWCMgt_bLiOffDone, bLocalTWCMgt_bLiOffDone);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidMngWaste_Gate_Position                           */
/* !Description :  The goal of this block is to determine the state of the    */
/*                 variable TWCMgt_stTrbActPosnReq”. This variable is used to */
/*                 command the turbocharger waste gate.                       */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TWCMgt_bTCoAr;                                              */
/*  input uint16 TWCMgt_tiPha1_tiTrbPosn_A[12];                               */
/*  input uint16 TWCMgt_tiHiTWCHiAr;                                          */
/*  input uint16 TWCMgt_tiTrbOpPosn_T[12];                                    */
/*  input uint16 TWCMgt_tiTrbClsPosn_T[12];                                   */
/*  input uint16 TWCMgt_tiTrbOpPosnThdLoAr_C;                                 */
/*  input uint16 TWCMgt_tiTrbClsPosnThdLoAr_C;                                */
/*  input uint16 TWCMgt_tiTWC;                                                */
/*  input boolean TWCMgt_bInhCtlTrbPosn_C;                                    */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  output uint8 TWCMgt_stTrbActPosnReqBas;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidMngWaste_Gate_Position(void)
{
   boolean  blocaltiTrbOpPosn;
   uint16   u16LocalCalcPara;
   uint16   u16LocaltiTrbOpPosn;
   uint16   u16LocaltiTrbClsPosn;


   if (TWCMgt_bTCoAr != 0)
   {
      u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(TWCMgt_tiPha1_tiTrbPosn_A,
                                                      TWCMgt_tiHiTWCHiAr,
                                                      12);
      u16LocaltiTrbOpPosn =
         MATHSRV_u16Interp1d(TWCMgt_tiTrbOpPosn_T, u16LocalCalcPara);
      u16LocaltiTrbClsPosn =
         MATHSRV_u16Interp1d(TWCMgt_tiTrbClsPosn_T, u16LocalCalcPara);
   }
   else
   {
      u16LocaltiTrbOpPosn = TWCMgt_tiTrbOpPosnThdLoAr_C;
      u16LocaltiTrbClsPosn = TWCMgt_tiTrbClsPosnThdLoAr_C;
   }
   if (u16LocaltiTrbOpPosn <= TWCMgt_tiTWC)
   {
      blocaltiTrbOpPosn = 1;
   }
   else
   {
      blocaltiTrbOpPosn = 0;
   }
   if (  (TWCMgt_bInhCtlTrbPosn_C != 0)
      || (TWCMgt_bTWCHeatReq == 0)
      || (blocaltiTrbOpPosn != 0))
   {
      TWCMgt_stTrbActPosnReqBas = 0;
   }
   else
   {
      if (TWCMgt_tiTWC >= u16LocaltiTrbClsPosn)
      {
         TWCMgt_stTrbActPosnReqBas = 2;
      }
      else
      {
         TWCMgt_stTrbActPosnReqBas = 1;
      }
   }

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TWCMGT_VidManage_Output                                    */
/* !Description :  The goal of this function is to set the variable           */
/*                 TWCMgt_stTrbActPosnReq” and TWCMgt_stHeatPhaReq to 0 when  */
/*                 the catalyst heating is finished (TWCMgt_bTWCHeatReq = 0). */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02024_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TWCMgt_bTWCHeatReq;                                         */
/*  input uint8 TWCMgt_stTrbActPosnReqBas;                                    */
/*  input uint8 TWCMgt_stHeatPhaReqBas;                                       */
/*  output uint8 TWCMgt_stTrbActPosnReq;                                      */
/*  output uint8 TWCMgt_stHeatPhaReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TWCMGT_VidManage_Output(void)
{
   uint8   u8LocalTWCMgt_stTrbActPosnReq;
   uint8   u8LocalTWCMgt_stHeatPhaReq;


   if (TWCMgt_bTWCHeatReq != 0)
   {
      u8LocalTWCMgt_stTrbActPosnReq =
         (uint8)MATHSRV_udtMIN(TWCMgt_stTrbActPosnReqBas, 2);
      u8LocalTWCMgt_stHeatPhaReq =
         (uint8)MATHSRV_udtMIN(TWCMgt_stHeatPhaReqBas, 4);
   }
   else
   {
      u8LocalTWCMgt_stTrbActPosnReq = 0;
      u8LocalTWCMgt_stHeatPhaReq = 0;
   }
   VEMS_vidSET(TWCMgt_stTrbActPosnReq, u8LocalTWCMgt_stTrbActPosnReq);
   VEMS_vidSET(TWCMgt_stHeatPhaReq, u8LocalTWCMgt_stHeatPhaReq);
}
/*------------------------------- end of file --------------------------------*/