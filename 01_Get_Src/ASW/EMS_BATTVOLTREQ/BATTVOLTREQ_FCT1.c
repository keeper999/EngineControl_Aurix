/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BATTVOLTREQ                                             */
/* !Description     : BATTVOLTREQ component.                                  */
/*                                                                            */
/* !Module          : BATTVOLTREQ                                             */
/* !Description     : BATTERY VOLTAGE BOOST REQUEST                           */
/*                                                                            */
/* !File            : BATTVOLTREQ_FCT1.C                                      */
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
/*   1 / BATTVOLTREQ_vidInitOutput                                            */
/*   2 / BATTVOLTREQ_vidInit                                                  */
/*   3 / BATTVOLTREQ_vidBattVltRqstLowVlt                                     */
/*   4 / BATTVOLTREQ_vidWasteMaxClsdCond                                      */
/*   5 / BATTVOLTREQ_vidBattVoltRqstCond                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 04680 / 01                                        */
/* !OtherRefs   : 01460_11_00651_2 / 01                                       */
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
#include "BATTVOLTREQ.h"
#include "BATTVOLTREQ_L.h"
#include "BATTVOLTREQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTREQ_vidInitOutput                                  */
/* !Description :  This block describes the initialization of the battery     */
/*                 voltage boost request.                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean BoostAct_bAcvTrbActMax_MP;                                 */
/*  output boolean BoostAct_bAcvTrbActMax;                                    */
/*  output uint16 BATTVOLTREQ_u16TOffDlyAuthCnt;                              */
/*  output boolean BATTVOLTREQ_bOutNegHysRqstCond;                            */
/*  output boolean BATTVOLTREQ_bAcvTrbActMax_MPPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTREQ_vidInitOutput(void)
{
   BoostAct_bAcvTrbActMax_MP = 0;
   BoostAct_bAcvTrbActMax = 0;
   BATTVOLTREQ_u16TOffDlyAuthCnt = 0;
   BATTVOLTREQ_bOutNegHysRqstCond = 0;
   BATTVOLTREQ_bAcvTrbActMax_MPPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTREQ_vidInit                                        */
/* !Description :  This block describes the initialization of the battery     */
/*                 voltage boost request.                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean BoostReq_bBattVoltReqIni_C;                                 */
/*  output boolean BoostReq_bBattVoltReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTREQ_vidInit(void)
{
   boolean bLocalBoostReq_bBattVoltReq;


   bLocalBoostReq_bBattVoltReq = BoostReq_bBattVoltReqIni_C;
   VEMS_vidSET(BoostReq_bBattVoltReq, bLocalBoostReq_bBattVoltReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTREQ_vidBattVltRqstLowVlt                           */
/* !Description :  This block describes the battery voltage boost request due */
/*                 to low battery voltage: BoostReq_bBattVoltReq              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BATTVOLTREQ_vidWasteMaxClsdCond();                       */
/*  extf argret void BATTVOLTREQ_vidBattVoltRqstCond();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTREQ_vidBattVltRqstLowVlt(void)
{
   BATTVOLTREQ_vidWasteMaxClsdCond();
   BATTVOLTREQ_vidBattVoltRqstCond();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTREQ_vidWasteMaxClsdCond                            */
/* !Description :  This block describes the boolean of the wastegate maximaly */
/*                 closed condition: BoostAct_bAcvTrbActMax                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 UsThrM_pAirExt;                                              */
/*  input uint16 BoostReq_pAirExt_A[5];                                       */
/*  input uint16 BoostReq_rDuCyThd_T[5];                                      */
/*  input uint32 BoostAct_rDuCyReqWoutSat;                                    */
/*  input uint16 BoostReq_rDuCyMaxThd_C;                                      */
/*  input boolean BoostAct_bAcvTrbActMax_MP;                                  */
/*  input boolean BATTVOLTREQ_bAcvTrbActMax_MPPrev;                           */
/*  input uint16 BoostReq_tiDlyAcvMax_C;                                      */
/*  input uint16 BATTVOLTREQ_u16TOffDlyAuthCnt;                               */
/*  output boolean BoostAct_bAcvTrbActMax_MP;                                 */
/*  output boolean BoostAct_bAcvTrbActMax;                                    */
/*  output uint16 BATTVOLTREQ_u16TOffDlyAuthCnt;                              */
/*  output boolean BATTVOLTREQ_bAcvTrbActMax_MPPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTREQ_vidWasteMaxClsdCond(void)
{
   uint16 u16LocalUsThrM_pAirExt;
   uint16 u16LocalCalcParaExt;
   uint16 u16LocalLow;
   uint32 u32LocalBoostAct_rDuCyReqWoutSat;


   VEMS_vidGET(UsThrM_pAirExt, u16LocalUsThrM_pAirExt);
   u16LocalCalcParaExt = MATHSRV_u16CalcParaIncAryU16(BoostReq_pAirExt_A,
                                                      u16LocalUsThrM_pAirExt,
                                                      5);
   u16LocalLow = MATHSRV_u16Interp1d(BoostReq_rDuCyThd_T,
                                     u16LocalCalcParaExt);

   VEMS_vidGET(BoostAct_rDuCyReqWoutSat, u32LocalBoostAct_rDuCyReqWoutSat);

   if (u16LocalLow != BoostReq_rDuCyMaxThd_C)
   {
      if (u32LocalBoostAct_rDuCyReqWoutSat <= u16LocalLow)
      {
         BoostAct_bAcvTrbActMax_MP = 0;
      }
      else
      {
         if (u32LocalBoostAct_rDuCyReqWoutSat >= BoostReq_rDuCyMaxThd_C)
         {
            BoostAct_bAcvTrbActMax_MP = 1;
         }
      }
   }
   else
   {
      if(u32LocalBoostAct_rDuCyReqWoutSat < u16LocalLow)
      {
         BoostAct_bAcvTrbActMax_MP = 0;
      }
      else
      {
         BoostAct_bAcvTrbActMax_MP = 1;
      }
   }

   if (BoostAct_bAcvTrbActMax_MP != 0)
   {
      BoostAct_bAcvTrbActMax = 1;
   }
   else
   {
      if (BATTVOLTREQ_bAcvTrbActMax_MPPrev != 0)
      {
         BATTVOLTREQ_u16TOffDlyAuthCnt =
            (uint16)(((BoostReq_tiDlyAcvMax_C * 25) + 1024) / 2048);
      }
      else
      {
         if (BATTVOLTREQ_u16TOffDlyAuthCnt > 0)
         {
            BATTVOLTREQ_u16TOffDlyAuthCnt =
               (uint16)(BATTVOLTREQ_u16TOffDlyAuthCnt - 1);
         }
      }
      if (BATTVOLTREQ_u16TOffDlyAuthCnt != 0)
      {
         BoostAct_bAcvTrbActMax = 1;
      }
      else
      {
         BoostAct_bAcvTrbActMax = 0;
      }
   }
   BATTVOLTREQ_bAcvTrbActMax_MPPrev = BoostAct_bAcvTrbActMax_MP;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BATTVOLTREQ_vidBattVoltRqstCond                            */
/* !Description :  This block describes conditions of battery voltage boost   */
/*                 request due to low battery voltage.                        */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_04668_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input boolean AirSys_bAcvFrzMod;                                          */
/*  input uint16 UsThrM_pAirExt;                                              */
/*  input boolean BoostAct_bAcvTrbActMax;                                     */
/*  input boolean BoostReq_bAcvFrzMod_C;                                      */
/*  input boolean BoostReq_bAcvStraBattVoltReq_C;                             */
/*  input uint16 BoostReq_pAirExtHiThd_C;                                     */
/*  input uint16 BoostReq_pAirExtLoThd_C;                                     */
/*  input boolean BoostReq_bAcvBattVoltReq_C;                                 */
/*  input boolean BATTVOLTREQ_bOutNegHysRqstCond;                             */
/*  output boolean BATTVOLTREQ_bOutNegHysRqstCond;                            */
/*  output boolean BoostReq_bBattVoltReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BATTVOLTREQ_vidBattVoltRqstCond(void)
{
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   boolean bLocalAirSys_bAcvFrzMod;
   boolean bLocaloutput1;
   uint16  u16LocalUsThrM_pAirExt;


   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   VEMS_vidGET(AirSys_bAcvFrzMod, bLocalAirSys_bAcvFrzMod);
   VEMS_vidGET(UsThrM_pAirExt, u16LocalUsThrM_pAirExt);

   if (  (BoostAct_bAcvTrbActMax != 0)
      && (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      && (  (BoostReq_bAcvFrzMod_C == 0)
         || (bLocalAirSys_bAcvFrzMod == 0))
      && (BoostReq_bAcvStraBattVoltReq_C != 0))
   {
      bLocaloutput1 = 1;
   }
   else
   {
      bLocaloutput1 = 0;
   }

   if (u16LocalUsThrM_pAirExt >= BoostReq_pAirExtHiThd_C)
   {
      BATTVOLTREQ_bOutNegHysRqstCond = 0;
   }
   else
   {
      if (u16LocalUsThrM_pAirExt <= BoostReq_pAirExtLoThd_C)
      {
         BATTVOLTREQ_bOutNegHysRqstCond = 1;
      }
   }

   if (  (bLocaloutput1 != 0)
      || (BoostReq_bAcvBattVoltReq_C != 0)
      || (BATTVOLTREQ_bOutNegHysRqstCond != 0))
   {
      VEMS_vidSET(BoostReq_bBattVoltReq, 1);
   }
   else
   {
      VEMS_vidSET(BoostReq_bBattVoltReq, 0);
   }
}
/*-------------------------------- end of file -------------------------------*/