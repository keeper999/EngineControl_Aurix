/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGWG                                               */
/* !Description     : FCTDIAGWG component                                     */
/*                                                                            */
/* !Module          : FCTDIAGWG                                               */
/* !Description     : FUNCTIONAL DIAGNOSIS OF WASTEGATE                       */
/*                                                                            */
/* !File            : FCTDIAGWG_FCT1.C                                        */
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
/*   1 / FCTDIAGWG_vidInitOutput                                              */
/*   2 / FCTDIAGWG_vidInit                                                    */
/*   3 / FCTDIAGWG_vidCls_pTrbAct                                             */
/*   4 / FCTDIAGWG_vidStuckCls_pTrbAct                                        */
/*   5 / FCTDIAGWG_vidAcvActStuckCls                                          */
/*   6 / FCTDIAGWG_vidOp_pTrbAct                                              */
/*   7 / FCTDIAGWG_vidPTrb_ActStuckOp                                         */
/*   8 / FCTDIAGWG_vidAcvActStuckOp                                           */
/*   9 / FCTDIAGWG_vidClcpUsThrNat                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5070705 / 03                                        */
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
#include "FCTDIAGWG.h"
#include "FCTDIAGWG_L.h"
#include "FCTDIAGWG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidInitOutput                                    */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Wg_tiTrbActStuckCls_C;                                       */
/*  output uint16 Wg_tiStuckCls;                                              */
/*  output boolean FCTDIAGWG_bTimerInit;                                      */
/*  output boolean FCTDIAGWG_bTimeout1;                                       */
/*  output uint16 Wg_pUsThrNat;                                               */
/*  output uint8 Wg_tiStuckOp;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidInitOutput(void)
{
   Wg_tiStuckCls = (uint16)MATHSRV_udtMIN(Wg_tiTrbActStuckCls_C, 1000);
   FCTDIAGWG_bTimerInit = 0;
   FCTDIAGWG_bTimeout1 = 0;
   VEMS_vidSET(Wg_pUsThrNat, 0);
   Wg_tiStuckOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidInit                                          */
/* !Description :  This function is in charge of the initialization of the    */
/*                 variables on the ECU reset (Wg_EveRst_FctDiagWg)           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Wg_bDgoStuckCls_pTrbAct;                                   */
/*  output boolean Wg_bMonRunStuckCls_pTrbAct;                                */
/*  output boolean Wg_bMonRunStuckOp_pTrbAct;                                 */
/*  output boolean Wg_bDgoStuckOp_pTrbAct;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidInit(void)
{
   Wg_bDgoStuckCls_pTrbAct = 0;
   Wg_bMonRunStuckCls_pTrbAct = 0;
   Wg_bMonRunStuckOp_pTrbAct = 0;
   Wg_bDgoStuckOp_pTrbAct = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidCls_pTrbAct                                   */
/* !Description :  The stuck closed Waste gate suspicion test is continuous on*/
/*                 piece.                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FCTDIAGWG_vidAcvActStuckCls();                           */
/*  extf argret void FCTDIAGWG_vidStuckCls_pTrbAct();                         */
/*  input uint16 Wg_pUsThrNat;                                                */
/*  input sint16 Wg_pUsThrNatStuckClsOfs_C;                                   */
/*  input boolean Wg_bMonRunStuckCls_pTrbAct;                                 */
/*  output uint16 Wg_pUsThrNatStuckCls;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidCls_pTrbAct(void)
{
   uint16 u16LocalWg_pUsThrNat;
   sint32 s32LocalWg_pUsThrNatStuckCls;


   VEMS_vidGET(Wg_pUsThrNat, u16LocalWg_pUsThrNat);
   s32LocalWg_pUsThrNatStuckCls =
         (sint32)(Wg_pUsThrNatStuckClsOfs_C + u16LocalWg_pUsThrNat);
   Wg_pUsThrNatStuckCls =
         (uint16)MATHSRV_udtCLAMP(s32LocalWg_pUsThrNatStuckCls, 0, 65535);
   FCTDIAGWG_vidAcvActStuckCls();
   if (Wg_bMonRunStuckCls_pTrbAct != 0)
   {
      FCTDIAGWG_vidStuckCls_pTrbAct();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidStuckCls_pTrbAct                              */
/* !Description :  this function is in charge of the diagnosis result for the */
/*                 stuck closed Waste Gate suspicion.                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 Wg_pUsThrNatStuckCls;                                        */
/*  output boolean Wg_bDgoStuckCls_pTrbAct;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidStuckCls_pTrbAct(void)
{
   uint16 u16LocalTrbAct_pUsThrFil;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);
   if (u16LocalTrbAct_pUsThrFil > Wg_pUsThrNatStuckCls)
   {
      Wg_bDgoStuckCls_pTrbAct = 1;
   }
   else
   {
      Wg_bDgoStuckCls_pTrbAct = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidAcvActStuckCls                                */
/* !Description :  The stuck closed Waste gate suspicion test                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16FRMindex);             */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input uint16 Wg_tiTrbActStuckCls_C;                                       */
/*  input uint16 Wg_tiStuckCls;                                               */
/*  output uint16 Wg_tiStuckCls;                                              */
/*  output boolean Wg_bMonRunStuckCls_pTrbAct;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidAcvActStuckCls(void)
{
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   boolean bLocalInhFctDiagWg;
   sint32  s32LocalDiff;


   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   bLocalInhFctDiagWg = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGWG);
   if (bLocalTrbAct_bBoostPresClCtlAcv != 0)
   {
      Wg_tiStuckCls = (uint16)MATHSRV_udtMIN(Wg_tiTrbActStuckCls_C, 1000) ;
   }
   else
   {
      s32LocalDiff = (sint32)(Wg_tiStuckCls - 1);
      Wg_tiStuckCls = (uint16)MATHSRV_udtCLAMP(s32LocalDiff, 0, 1000);
   }
   if (  (bLocalInhFctDiagWg == 0)
      && (Wg_tiStuckCls == 0))
   {
      Wg_bMonRunStuckCls_pTrbAct = 1;
   }
   else
   {
      Wg_bMonRunStuckCls_pTrbAct = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidOp_pTrbAct                                    */
/* !Description :  The stuck open Waste gate suspicion test                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FCTDIAGWG_vidAcvActStuckOp();                            */
/*  extf argret void FCTDIAGWG_vidPTrb_ActStuckOp();                          */
/*  input uint16 Wg_pUsThrNat;                                                */
/*  input uint16 Wg_pTrbActStuckOp_C;                                         */
/*  input boolean Wg_bMonRunStuckOp_pTrbAct;                                  */
/*  output uint16 Wg_pTrbActStuckOp;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidOp_pTrbAct(void)
{
   uint32 u32LocalWg_pTrbActStuckOp;
   uint16 u16LocalWg_pUsThrNat;


   VEMS_vidGET(Wg_pUsThrNat, u16LocalWg_pUsThrNat);
   u32LocalWg_pTrbActStuckOp =
         (uint32)(Wg_pTrbActStuckOp_C + u16LocalWg_pUsThrNat);
   Wg_pTrbActStuckOp =
         (uint16)MATHSRV_udtMIN(u32LocalWg_pTrbActStuckOp, 65535);
   FCTDIAGWG_vidAcvActStuckOp();
   if (Wg_bMonRunStuckOp_pTrbAct != 0)
   {
      FCTDIAGWG_vidPTrb_ActStuckOp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidPTrb_ActStuckOp                               */
/* !Description :  This function is in charge of the Diagnosis result fot the */
/*                 stuck open Waste Gate suspicion.                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 Wg_pTrbActStuckOp;                                           */
/*  output boolean Wg_bDgoStuckOp_pTrbAct;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidPTrb_ActStuckOp(void)
{
   uint16  u16LocalTrbAct_pUsThrFil;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);

   if (u16LocalTrbAct_pUsThrFil < Wg_pTrbActStuckOp )
   {
      Wg_bDgoStuckOp_pTrbAct = 1;
   }
   else
   {
      Wg_bDgoStuckOp_pTrbAct = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidAcvActStuckOp                                 */
/* !Description :  The stuck open Waste gate suspicion test is continuous on  */
/*                 piece                                                      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_002.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16FRMindex);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 TrbAct_pUsThrCorReq;                                         */
/*  input uint16 Wg_pUsThrNat;                                                */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Wg_pUsThrNatStuckOpOfs_C;                                    */
/*  input uint16 Wg_pAirExtMes_A[8];                                          */
/*  input uint16 Wg_nEng_pAirExtMes_T[8];                                     */
/*  input uint16 Wg_nEngMax_pAirExtMes_T[8];                                  */
/*  input uint16 Wg_nDifpUsThr_A[8];                                          */
/*  input uint8 Wg_tiDifpUsThr_T[8];                                          */
/*  input boolean FCTDIAGWG_bTimerInit;                                       */
/*  input uint8 Wg_rClsThdThr_C;                                              */
/*  input uint16 Wg_pAirExtMes_C;                                             */
/*  input uint8 Wg_tiStuckOp;                                                 */
/*  input boolean FCTDIAGWG_bTimeout1;                                        */
/*  output boolean FCTDIAGWG_bTimerInit;                                      */
/*  output uint8 Wg_tiStuckOp;                                                */
/*  output boolean FCTDIAGWG_bTimeout1;                                       */
/*  output boolean Wg_bMonRunStuckOp_pTrbAct;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidAcvActStuckOp(void)
{
   boolean bLocalInhFctDiagWg;
   boolean bLocalTimerInitPrev;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   uint8   u8LocalCorrectedThrottlePosition;
   uint8   u8LocalWg_tiDifpUsThr_T;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalTrbAct_pUsThrCorReq;
   uint16  u16LocalWg_pUsThrNat;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalCalcPara;
   uint16  u16LocalCalcPara2;
   uint16  u16LocalWg_nEng_pAirExtMes_T;
   uint16  u16LocalWgnEngMax_pAirExtMes_T;
   sint32  s32LocalSUM;


   bLocalInhFctDiagWg = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGWG);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrectedThrottlePosition);
   VEMS_vidGET(TrbAct_pUsThrCorReq, u16LocalTrbAct_pUsThrCorReq);
   VEMS_vidGET(Wg_pUsThrNat, u16LocalWg_pUsThrNat);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   s32LocalSUM = (sint32)(Wg_pUsThrNatStuckOpOfs_C + u16LocalWg_pUsThrNat);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Wg_pAirExtMes_A,
                                                   u16LocalExt_pAirExtMes,
                                                   8);
   u16LocalWg_nEng_pAirExtMes_T = MATHSRV_u16Interp1d(Wg_nEng_pAirExtMes_T,
                                                      u16LocalCalcPara);
   u16LocalWgnEngMax_pAirExtMes_T = MATHSRV_u16Interp1d(Wg_nEngMax_pAirExtMes_T,
                                                        u16LocalCalcPara);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(Wg_nDifpUsThr_A,
                                                    u16LocalExt_nEng,
                                                    8);
   u8LocalWg_tiDifpUsThr_T = MATHSRV_u8Interp1d(Wg_tiDifpUsThr_T,
                                                u16LocalCalcPara2);

   bLocalTimerInitPrev = FCTDIAGWG_bTimerInit;
   if (  (bLocalInhFctDiagWg == 0)
      && (u8LocalCorrectedThrottlePosition > Wg_rClsThdThr_C)
      && (u16LocalTrbAct_pUsThrCorReq > s32LocalSUM)
      && (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      && (u16LocalExt_nEng > u16LocalWg_nEng_pAirExtMes_T)
      && (u16LocalExt_nEng < u16LocalWgnEngMax_pAirExtMes_T)
      && (u16LocalExt_pAirExtMes > Wg_pAirExtMes_C))
   {
      FCTDIAGWG_bTimerInit = 1;
   }
   else
   {
      FCTDIAGWG_bTimerInit = 0;
   }
   /* Timer */
   if (  (FCTDIAGWG_bTimerInit != 0)
      && (bLocalTimerInitPrev == 0) )
   {
      Wg_tiStuckOp = (uint8)MATHSRV_udtMIN(u8LocalWg_tiDifpUsThr_T, 200);
      if (Wg_tiStuckOp == 0)
      {
         FCTDIAGWG_bTimeout1 = 1;
      }
      else
      {
         FCTDIAGWG_bTimeout1 = 0;
      }
   }
   else
   {
      if (Wg_tiStuckOp > 0)
      {
         Wg_tiStuckOp = (uint8)( Wg_tiStuckOp - 1);
         if (Wg_tiStuckOp == 0)
         {
            FCTDIAGWG_bTimeout1 = 1;
         }
         else
         {
            FCTDIAGWG_bTimeout1 = 0;
         }
      }
   }
   /* Fin timer */
   if (  (FCTDIAGWG_bTimerInit != 0)
      && (FCTDIAGWG_bTimeout1 != 0))
   {
      Wg_bMonRunStuckOp_pTrbAct = 1;
   }
   else
   {
      Wg_bMonRunStuckOp_pTrbAct = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGWG_vidClcpUsThrNat                                  */
/* !Description :  Calculation of the natural boost pressure                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_E_11_02722_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Wg_pAirExtMesInter_C;                                        */
/*  input uint16 Wg_nEngX_A[8];                                               */
/*  input uint16 Wg_pAirExtMesInterY_A[8];                                    */
/*  input uint16 Wg_pAirExtMesInter;                                          */
/*  input uint16 Wg_pUsThrNat_nEngX_pAirExtMesY_M[8][8];                      */
/*  output uint16 Wg_pAirExtMesInter;                                         */
/*  output uint16 Wg_pUsThrNat;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGWG_vidClcpUsThrNat(void)
{
   boolean bLocalCf_bPresPAirExtSens;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalWg_pUsThrNat;
   uint32  u32LocalWg_pAirExtMesInter;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   if (bLocalCf_bPresPAirExtSens != 0)
   {
      u32LocalWg_pAirExtMesInter = (uint32)(  ( ( u16LocalExt_pAirExtMes * 25)
                                              + 1)
                                           / 2);
      Wg_pAirExtMesInter =
            (uint16)MATHSRV_udtMIN(u32LocalWg_pAirExtMesInter, 65535);
   }
   else
   {
      Wg_pAirExtMesInter = Wg_pAirExtMesInter_C;
   }
   u16LocalCalcParaX =
      MATHSRV_u16CalcParaIncAryU16(Wg_nEngX_A,
                                  u16LocalExt_nEng,
                                  8);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(Wg_pAirExtMesInterY_A,
                                  Wg_pAirExtMesInter,
                                  8);
   u16LocalWg_pUsThrNat =
      MATHSRV_u16Interp2d(&Wg_pUsThrNat_nEngX_pAirExtMesY_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          8);
   VEMS_vidSET(Wg_pUsThrNat, u16LocalWg_pUsThrNat);
}
/*-------------------------------end of file----------------------------------*/