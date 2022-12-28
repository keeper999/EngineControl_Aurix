/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGDMPVLV                                           */
/* !Description     : FCTDIAGDMPVLV Component                                 */
/*                                                                            */
/* !Module          : FCTDIAGDMPVLV                                           */
/* !Description     : Dump Valve Functional Diagnosis                         */
/*                                                                            */
/* !File            : FCTDIAGDMPVLV_FCT1.C                                    */
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
/*   1 / FCTDIAGDMPVLV_vidInitOutput                                          */
/*   2 / FCTDIAGDMPVLV_vidInit                                                */
/*   3 / FCTDIAGDMPVLV_vidDmpVlv_Op                                           */
/*   4 / FCTDIAGDMPVLV_vidCondStuckOp                                         */
/*   5 / FCTDIAGDMPVLV_vidDiagStuckOp                                         */
/*   6 / FCTDIAGDMPVLV_vidDmpVlvCls                                           */
/*   7 / FCTDIAGDMPVLV_vidCondStuckCls                                        */
/*   8 / FCTDIAGDMPVLV_vidDetOscStuckCls                                      */
/*   9 / FCTDIAGDMPVLV_vidCntDiagStuckCls                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5068534 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065849                                         */
/* !OtherRefs   : VEMS V02 ECU#066089                                         */
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
#include "FCTDIAGDMPVLV.h"
#include "FCTDIAGDMPVLV_L.h"
#include "FCTDIAGDMPVLV_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidInitOutput                                */
/* !Description :  Output initialization function.                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 FCTDIAGDMPVLV_u16FilterOutput;                               */
/*  output uint16 DmpVlv_tiStuckOp;                                           */
/*  output uint16 DmpVlv_tiStuckCls;                                          */
/*  output uint32 DmpVlv_tiAcvCntOscStuckCls;                                 */
/*  output boolean FCTDIAGDMPVLV_bTimeOut1;                                   */
/*  output boolean FCTDIAGDMPVLV_bTimeOut2;                                   */
/*  output boolean DmpVlv_bEndCntOscStuckCls;                                 */
/*  output boolean FCTDIAGDMPVLV_bPresOscStuck_prev;                          */
/*  output boolean FCTDIAGDMPVLV_bTimer1Init_prev;                            */
/*  output boolean FCTDIAGDMPVLV_bTimer2Init_prev;                            */
/*  output boolean FCTDIAGDMPVLV_bTimer3Init_prev;                            */
/*  output boolean FCTDIAGDMPVLV_bOscStuckCls_prev;                           */
/*  output boolean DmpVlv_bPresOscStuckCls;                                   */
/*  output boolean DmpVlv_bOscStuckCls;                                       */
/*  output uint8 DmpVlv_ctPresOscStuckCls;                                    */
/*  output uint8 DmpVlv_ctDiagStuckCls;                                       */
/*  output uint16 FCTDIAGDMPVLV_u16FilterOutput;                              */
/*  output uint32 FCTDIAGDMPVLV_u32FilterKMem;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidInitOutput(void)
{
   /*counter*/
   DmpVlv_tiStuckOp = 0;
   DmpVlv_tiStuckCls = 0;
   DmpVlv_tiAcvCntOscStuckCls = 0;
   /*Timer's outputs*/
   FCTDIAGDMPVLV_bTimeOut1 = 0;
   FCTDIAGDMPVLV_bTimeOut2 = 0;
   DmpVlv_bEndCntOscStuckCls = 0;
   /*variables prev*/
   FCTDIAGDMPVLV_bPresOscStuck_prev = 0;
   FCTDIAGDMPVLV_bTimer1Init_prev = 0;
   FCTDIAGDMPVLV_bTimer2Init_prev = 0;
   FCTDIAGDMPVLV_bTimer3Init_prev = 0;
   FCTDIAGDMPVLV_bOscStuckCls_prev = 1;
   DmpVlv_bPresOscStuckCls = 0;
   DmpVlv_bOscStuckCls = 0;
   DmpVlv_ctPresOscStuckCls = 0;
   DmpVlv_ctDiagStuckCls = 0;
   /*Filter's output*/
   FCTDIAGDMPVLV_u16FilterOutput = 0;
   FCTDIAGDMPVLV_u32FilterKMem =
      (uint32)(FCTDIAGDMPVLV_u16FilterOutput * 65536);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidInit                                      */
/* !Description :  The diagnosis outputs are initialized at the ECU reset     */
/*                 event.                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean DmpVlv_bDgoStuckCls_DmpVlv;                                */
/*  output boolean DmpVlv_bMonRunStuckCls_DmpVlv;                             */
/*  output boolean DmpVlv_bMonRunStuckOp_DmpVlv;                              */
/*  output boolean DmpVlv_bDgoStuckOp_DmpVlv;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidInit(void)
{
   DmpVlv_bDgoStuckCls_DmpVlv = 0;
   DmpVlv_bMonRunStuckCls_DmpVlv = 0;
   DmpVlv_bMonRunStuckOp_DmpVlv = 0;
   DmpVlv_bDgoStuckOp_DmpVlv = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidDmpVlv_Op                                 */
/* !Description :  This function allows the calculation of the stuck open Dump*/
/*                 Valve diagnosis activation flag and the calculation of the */
/*                 stuck open Dump Valve diagnosis result.                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03495_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGDMPVLV_vidCondStuckOp();                          */
/*  extf argret void FCTDIAGDMPVLV_vidDiagStuckOp();                          */
/*  input boolean DmpVlv_bMonRunStuckOp_DmpVlv;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidDmpVlv_Op(void)
{
   FCTDIAGDMPVLV_vidCondStuckOp();

   if (DmpVlv_bMonRunStuckOp_DmpVlv != 0)
   {
      FCTDIAGDMPVLV_vidDiagStuckOp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidCondStuckOp                               */
/* !Description :  This function calculates  the stuck open Dump Valve        */
/*                 diagnosis activation flag.                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrCorReq;                                         */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 Wg_pUsThrNat;                                                */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input uint16 Wg_pAirExtMesInter_C;                                        */
/*  input uint16 FctDiagDmpVlv_nEng_A[8];                                     */
/*  input uint16 DmpVlv_pAirInter_A[8];                                       */
/*  input uint16 DmpVlv_pAirExtMesInter;                                      */
/*  input uint16 DmpVlv_pThdBoostPres_M[8][8];                                */
/*  input uint16 DmpVlv_pAirExtMes_A[8];                                      */
/*  input uint16 DmpVlv_nEngMinThd_T[8];                                      */
/*  input uint16 DmpVlv_nEngMaxThd_T[8];                                      */
/*  input uint16 DmpVlv_tiTrbActStuckOp_T[8];                                 */
/*  input sint16 DmpVlv_pUsThrCorReqOfst_C;                                   */
/*  input uint16 DmpVlv_pThdBoostPres;                                        */
/*  input uint16 DmpVlv_pUsThrCorServoErrThd_C;                               */
/*  input uint16 Wg_pAirExtMes_C;                                             */
/*  input uint8 Wg_rClsThdThr_C;                                              */
/*  input boolean FCTDIAGDMPVLV_bTimer1Init_prev;                             */
/*  input uint16 DmpVlv_tiStuckOp;                                            */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean FCTDIAGDMPVLV_bTimeOut1;                                    */
/*  input uint16 Wg_pTrbActStuckOp_C;                                         */
/*  output uint16 DmpVlv_pAirExtMesInter;                                     */
/*  output uint16 DmpVlv_pThdBoostPres;                                       */
/*  output uint16 DmpVlv_tiStuckOp;                                           */
/*  output boolean FCTDIAGDMPVLV_bTimeOut1;                                   */
/*  output boolean FCTDIAGDMPVLV_bTimer1Init_prev;                            */
/*  output boolean DmpVlv_bMonRunStuckOp_DmpVlv;                              */
/*  output uint16 DmpVlv_pThdBoostPresWgStuckOp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidCondStuckOp(void)
{
   boolean bLocalInhFctDiagDmpVlv;
   boolean bLocalTimer1Init;
   boolean bLocalPresPAirExtSens;
   boolean bLocalTrbAct_bBoostPresClCtlAcv;
   uint8   u8LocalExt_tiTDC;
   uint8   u8LocalCorr_throttle_position;
   uint16  u16LocalTrbAct_pUsThrCorReq;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalParanEngMinMaxThd;
   uint16  u16LocalParatiTrbActStuckOp;
   uint16  u16LocaltiTrbActStuckOp;
   uint16  u16LocalnEngMinThd;
   uint16  u16LocalnEngMaxThd;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalWg_pUsThrNat;
   uint16  u16LocalParapThdBoostPresX;
   uint16  u16LocalParapThdBoostPresY;
   uint16  u16LocalTrbAct_pUsThrFil;
   uint32  u32LocalpAirExtMesInter;
   uint32  u32LocalBoostPresWgStuckOp;
   sint32  s32LocaltiStuckOp;
   sint32  s32LocalTrbAct_pUsThr;
   sint32  s32LocalDmpVlv_pUsThr;


   bLocalInhFctDiagDmpVlv = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGDMPVLV);
   VEMS_vidGET(TrbAct_pUsThrCorReq, u16LocalTrbAct_pUsThrCorReq);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorr_throttle_position);
   VEMS_vidGET(Wg_pUsThrNat, u16LocalWg_pUsThrNat);
   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalPresPAirExtSens);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalTrbAct_bBoostPresClCtlAcv);


   /*Production DmpVlv_pAirExtMesInter*/
   if (bLocalPresPAirExtSens != 0)
   {
      u32LocalpAirExtMesInter = (uint32)(u16LocalExt_pAirExtMes * 25) / 2;
      DmpVlv_pAirExtMesInter =
         (uint16)MATHSRV_udtMIN(u32LocalpAirExtMesInter, 65535);
   }
   else
   {
      DmpVlv_pAirExtMesInter = Wg_pAirExtMesInter_C;
   }
   /*Production DmpVlv_pThdBoostPres*/
   u16LocalParapThdBoostPresX =
      MATHSRV_u16CalcParaIncAryU16(FctDiagDmpVlv_nEng_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocalParapThdBoostPresY =
      MATHSRV_u16CalcParaIncAryU16(DmpVlv_pAirInter_A,
                                   DmpVlv_pAirExtMesInter,
                                   8);
   DmpVlv_pThdBoostPres = MATHSRV_u16Interp2d(&DmpVlv_pThdBoostPres_M[0][0],
                                              u16LocalParapThdBoostPresX,
                                              u16LocalParapThdBoostPresY,
                                              8);

   u16LocalParanEngMinMaxThd =
      MATHSRV_u16CalcParaIncAryU16(DmpVlv_pAirExtMes_A,
                                   u16LocalExt_pAirExtMes,
                                   8);
   u16LocalnEngMinThd = MATHSRV_u16Interp1d(DmpVlv_nEngMinThd_T,
                                            u16LocalParanEngMinMaxThd);
   u16LocalnEngMaxThd = MATHSRV_u16Interp1d(DmpVlv_nEngMaxThd_T,
                                            u16LocalParanEngMinMaxThd);
   u16LocalParatiTrbActStuckOp =
      MATHSRV_u16CalcParaIncAryU16(FctDiagDmpVlv_nEng_A,
                                   u16LocalExt_nEng,
                                   8);
   u16LocaltiTrbActStuckOp = MATHSRV_u16Interp1d(DmpVlv_tiTrbActStuckOp_T,
                                                 u16LocalParatiTrbActStuckOp);

   s32LocalTrbAct_pUsThr = ( u16LocalTrbAct_pUsThrCorReq
                           - u16LocalTrbAct_pUsThrFil);
   s32LocalDmpVlv_pUsThr = (DmpVlv_pUsThrCorReqOfst_C + DmpVlv_pThdBoostPres);

   if (  (bLocalInhFctDiagDmpVlv == 0)
      && (s32LocalTrbAct_pUsThr > DmpVlv_pUsThrCorServoErrThd_C)
      && (u16LocalTrbAct_pUsThrCorReq > s32LocalDmpVlv_pUsThr)
      && (u16LocalnEngMinThd < u16LocalExt_nEng)
      && (u16LocalnEngMaxThd > u16LocalExt_nEng)
      && (u16LocalExt_pAirExtMes > Wg_pAirExtMes_C)
      && (bLocalTrbAct_bBoostPresClCtlAcv != 0)
      && (u8LocalCorr_throttle_position > Wg_rClsThdThr_C))
   {
      bLocalTimer1Init = 1;
   }
   else
   {
      bLocalTimer1Init = 0;
   }

   /*Debut Timer1*/
   if (  (FCTDIAGDMPVLV_bTimer1Init_prev == 0)
      && ( bLocalTimer1Init != 0))
   {
      DmpVlv_tiStuckOp = u16LocaltiTrbActStuckOp;
      if (DmpVlv_tiStuckOp == 0)
      {
         FCTDIAGDMPVLV_bTimeOut1 = 1;
      }
      else
      {
         FCTDIAGDMPVLV_bTimeOut1 = 0;
      }
   }
   else
   {
      if (DmpVlv_tiStuckOp > 0)
      {
         VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

         s32LocaltiStuckOp =
            (sint32)(DmpVlv_tiStuckOp - u8LocalExt_tiTDC);
         DmpVlv_tiStuckOp =
            (uint16)MATHSRV_udtCLAMP(s32LocaltiStuckOp, 0, 8000);
         if (DmpVlv_tiStuckOp == 0)
         {
            FCTDIAGDMPVLV_bTimeOut1 = 1;
         }
         else
         {
            FCTDIAGDMPVLV_bTimeOut1 = 0;
         }
      }
   }
   FCTDIAGDMPVLV_bTimer1Init_prev = bLocalTimer1Init;
   /*Fin Timer1*/

   if (  (bLocalTimer1Init != 0)
      && (FCTDIAGDMPVLV_bTimeOut1 != 0))
   {
      DmpVlv_bMonRunStuckOp_DmpVlv = 1;
   }
   else
   {
      DmpVlv_bMonRunStuckOp_DmpVlv = 0;
   }

   /*Production DmpVlv_pThdBoostPresWgStuckOp*/
   u32LocalBoostPresWgStuckOp =
      (uint32)(Wg_pTrbActStuckOp_C + u16LocalWg_pUsThrNat);
   DmpVlv_pThdBoostPresWgStuckOp =
      (uint16)MATHSRV_udtMIN(u32LocalBoostPresWgStuckOp, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidDiagStuckOp                               */
/* !Description :  This function calculates the stuck open Dump Valve         */
/*                 diagnosis result.                                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03495_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 DmpVlv_pThdBoostPresWgStuckOp;                               */
/*  input uint16 DmpVlv_pThdBoostPres;                                        */
/*  output boolean DmpVlv_bDgoStuckOp_DmpVlv;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidDiagStuckOp(void)
{
   uint16  u16LocalTrbAct_pUsThrFil;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);


   if (  (DmpVlv_pThdBoostPresWgStuckOp < u16LocalTrbAct_pUsThrFil)
      && (DmpVlv_pThdBoostPres > u16LocalTrbAct_pUsThrFil))
   {
      DmpVlv_bDgoStuckOp_DmpVlv = 1;
   }
   else
   {
      DmpVlv_bDgoStuckOp_DmpVlv = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidDmpVlvCls                                 */
/* !Description :  This function allows the calculation of theStuck closed    */
/*                 Dump Valve diagnosis  activation flag and the calculation  */
/*                 of the stuck closed Dump Valve diagnosis result.           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03495_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGDMPVLV_vidCondStuckCls();                         */
/*  extf argret void FCTDIAGDMPVLV_vidDetOscStuckCls();                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FCTDIAGDMPVLV_vidCntDiagStuckCls();                      */
/*  input boolean DmpVlv_bPresOscStuckCls;                                    */
/*  input boolean DmpVlv_bMonRunStuckCls_DmpVlv;                              */
/*  input uint16 FCTDIAGDMPVLV_u16FilterOutput;                               */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 DmpVlv_tCo_A[4];                                              */
/*  input uint8 DmpVlv_ctThdDiagStuckCls_T[4];                                */
/*  input boolean FCTDIAGDMPVLV_bPresOscStuck_prev;                           */
/*  input uint8 DmpVlv_ctDiagStuckCls;                                        */
/*  input uint8 DmpVlv_ctThdDiagStuckCls;                                     */
/*  output boolean FCTDIAGDMPVLV_bPresOscStuck_prev;                          */
/*  output boolean FCTDIAGDMPVLV_bTimer3Init_prev;                            */
/*  output boolean FCTDIAGDMPVLV_bOscStuckCls_prev;                           */
/*  output uint8 DmpVlv_ctPresOscStuckCls;                                    */
/*  output boolean DmpVlv_bOscStuckCls;                                       */
/*  output boolean DmpVlv_bEndCntOscStuckCls;                                 */
/*  output uint32 DmpVlv_tiAcvCntOscStuckCls;                                 */
/*  output uint16 FCTDIAGDMPVLV_u16FilterOutput;                              */
/*  output uint32 FCTDIAGDMPVLV_u32FilterKMem;                                */
/*  output boolean DmpVlv_bPresOscStuckCls;                                   */
/*  output uint8 DmpVlv_ctThdDiagStuckCls;                                    */
/*  output boolean DmpVlv_bDgoStuckCls_DmpVlv;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidDmpVlvCls(void)
{
   uint8  u8LocalThdindex;
   uint8  u8LocalExt_tCoMes;
   uint16 u16LocalParactThdDiagStuckCls;
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalExt_tCoMes;


   FCTDIAGDMPVLV_bPresOscStuck_prev = DmpVlv_bPresOscStuckCls;
   FCTDIAGDMPVLV_vidCondStuckCls();
   if (DmpVlv_bMonRunStuckCls_DmpVlv != 0)
   {
      FCTDIAGDMPVLV_vidDetOscStuckCls();
   }
   else
   {
      FCTDIAGDMPVLV_bTimer3Init_prev = 0;
      FCTDIAGDMPVLV_bOscStuckCls_prev = 1;
      DmpVlv_ctPresOscStuckCls = 0;
      DmpVlv_bOscStuckCls = 0;
      DmpVlv_bEndCntOscStuckCls = 0;
      DmpVlv_tiAcvCntOscStuckCls = 0;
      FCTDIAGDMPVLV_u16FilterOutput = 0;
      FCTDIAGDMPVLV_u32FilterKMem =
         (uint32)(FCTDIAGDMPVLV_u16FilterOutput * 65536);
      DmpVlv_bPresOscStuckCls = 0;
   }

   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 255);
   u16LocalParactThdDiagStuckCls =
      MATHSRV_u16CalcParaIncAryU8(DmpVlv_tCo_A,
                                  u8LocalExt_tCoMes,
                                  4);
   u8LocalThdindex = (uint8)(u16LocalParactThdDiagStuckCls >> 8);
   DmpVlv_ctThdDiagStuckCls = DmpVlv_ctThdDiagStuckCls_T[u8LocalThdindex];

   if (  (FCTDIAGDMPVLV_bPresOscStuck_prev == 0)
      && (DmpVlv_bPresOscStuckCls != 0))
   {
      FCTDIAGDMPVLV_vidCntDiagStuckCls();
   }

   if (DmpVlv_ctDiagStuckCls >= DmpVlv_ctThdDiagStuckCls)
   {
      DmpVlv_bDgoStuckCls_DmpVlv = 1;
   }
   else
   {
      DmpVlv_bDgoStuckCls_DmpVlv = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidCondStuckCls                              */
/* !Description :  This function calculates  the stuck closed Dump Valve      */
/*                 diagnosis activation flag.                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03495_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 DmpVlv_rDmpVlvCmdAppld;                                      */
/*  input uint16 DmpVlv_uBattMinStuckCls_C;                                   */
/*  input uint16 DmpVlv_rThdCmdStuckCls_C;                                    */
/*  input boolean FCTDIAGDMPVLV_bTimer2Init_prev;                             */
/*  input uint16 DmpVlv_tiTrbActStuckCls_C;                                   */
/*  input uint16 DmpVlv_tiStuckCls;                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean FCTDIAGDMPVLV_bTimeOut2;                                    */
/*  output uint16 DmpVlv_tiStuckCls;                                          */
/*  output boolean FCTDIAGDMPVLV_bTimeOut2;                                   */
/*  output boolean FCTDIAGDMPVLV_bTimer2Init_prev;                            */
/*  output boolean DmpVlv_bMonRunStuckCls_DmpVlv;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidCondStuckCls(void)
{
   boolean bLocalInhFctDiagDmpVlv;
   boolean bLocalTimer2Init;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalrDmpVlvCmdAppld;
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocaltiStuckCls;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(DmpVlv_rDmpVlvCmdAppld, u16LocalrDmpVlvCmdAppld);
   bLocalInhFctDiagDmpVlv = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGDMPVLV);

   if (  (bLocalInhFctDiagDmpVlv == 0)
      && ((sint32)s16LocalExt_uBattMes > (sint32)DmpVlv_uBattMinStuckCls_C)
      && (u16LocalrDmpVlvCmdAppld > DmpVlv_rThdCmdStuckCls_C))
   {
      bLocalTimer2Init = 1;
   }
   else
   {
      bLocalTimer2Init = 0;
   }
   /*Debut Timer2*/
   if (  (FCTDIAGDMPVLV_bTimer2Init_prev == 0)
      && ( bLocalTimer2Init != 0))
   {
      DmpVlv_tiStuckCls = DmpVlv_tiTrbActStuckCls_C;
      if (DmpVlv_tiStuckCls == 0)
      {
         FCTDIAGDMPVLV_bTimeOut2 = 1;
      }
      else
      {
         FCTDIAGDMPVLV_bTimeOut2 = 0;
      }
   }
   else
   {
      if (DmpVlv_tiStuckCls > 0)
      {
         VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);

         s32LocaltiStuckCls =
            (sint32)(DmpVlv_tiStuckCls - u8LocalExt_tiTDC);
         DmpVlv_tiStuckCls =
            (uint16)MATHSRV_udtCLAMP(s32LocaltiStuckCls, 0, 8000);
         if (DmpVlv_tiStuckCls == 0)
         {
            FCTDIAGDMPVLV_bTimeOut2 = 1;
         }
         else
         {
            FCTDIAGDMPVLV_bTimeOut2 = 0;
         }
      }
   }
   FCTDIAGDMPVLV_bTimer2Init_prev = bLocalTimer2Init;
   /*Fin Timer2*/

   if (  (bLocalTimer2Init != 0)
      && (FCTDIAGDMPVLV_bTimeOut2 != 0))
   {
      DmpVlv_bMonRunStuckCls_DmpVlv = 1;
   }
   else
   {
      DmpVlv_bMonRunStuckCls_DmpVlv = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidDetOscStuckCls                            */
/* !Description :  This function detects and counts the super charging        */
/*                 pressure oscillations while the stuck closed Dump Valve.   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 DmpVlv_GainFiltPresStuckCls_C;                               */
/*  input uint32 FCTDIAGDMPVLV_u32FilterKMem;                                 */
/*  input uint16 FCTDIAGDMPVLV_u16FilterOutput;                               */
/*  input sint16 DmpVlv_pDiagFiltStuckCls;                                    */
/*  input uint8 DmpVlv_CoefPresStuckCls_C;                                    */
/*  input sint16 DmpVlv_pThdOscStuckCls_C;                                    */
/*  input sint16 DmpVlv_pOfsOscStuckCls_C;                                    */
/*  input uint16 DmpVlv_pThdAcvDiagStuckCls_C;                                */
/*  input boolean FCTDIAGDMPVLV_bTimer3Init_prev;                             */
/*  input uint32 DmpVlv_tiAcvCntOscStuckCls_C;                                */
/*  input uint32 DmpVlv_tiAcvCntOscStuckCls;                                  */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint8 DmpVlv_ctPresOscStuckCls;                                     */
/*  input boolean FCTDIAGDMPVLV_bOscStuckCls_prev;                            */
/*  input boolean DmpVlv_bOscStuckCls;                                        */
/*  input uint8 DmpVlv_nbMaxOscStuckCls_C;                                    */
/*  output uint16 FCTDIAGDMPVLV_u16FilterOutput;                              */
/*  output sint16 DmpVlv_pDiagFiltStuckCls;                                   */
/*  output boolean DmpVlv_bOscStuckCls;                                       */
/*  output uint32 DmpVlv_tiAcvCntOscStuckCls;                                 */
/*  output boolean DmpVlv_bEndCntOscStuckCls;                                 */
/*  output boolean FCTDIAGDMPVLV_bTimer3Init_prev;                            */
/*  output uint8 DmpVlv_ctPresOscStuckCls;                                    */
/*  output boolean DmpVlv_bPresOscStuckCls;                                   */
/*  output boolean FCTDIAGDMPVLV_bOscStuckCls_prev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidDetOscStuckCls(void)
{
   boolean bLocalTimer3Init;
   uint8   u8LocalExt_tiTDC;
   uint8   u8LocalSwitch1;
   uint8   u8LocalSwitch2;
   uint16  u16LocalTrbAct_pUsThrFil;
   uint16  u16LocalctPresOscStuckCls;
   uint32  u32LocaltiAcvCntOscStuckCls;
   sint32  s32LocalHystInput;
   sint32  s32LocalHystTreshold2;
   sint32  s32LocalDiagFiltStuckCls;
   sint32  s32LocalHystTreshold1;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);

   /*First-Order Filter*/
   FCTDIAGDMPVLV_u16FilterOutput =
      MATHSRV_u16FirstOrderFilterGu16(DmpVlv_GainFiltPresStuckCls_C,
                                      &FCTDIAGDMPVLV_u32FilterKMem,
                                      u16LocalTrbAct_pUsThrFil);

   s32LocalDiagFiltStuckCls =
      (sint32)(u16LocalTrbAct_pUsThrFil - FCTDIAGDMPVLV_u16FilterOutput);
   DmpVlv_pDiagFiltStuckCls =
      (sint16)MATHSRV_udtCLAMP(s32LocalDiagFiltStuckCls, -32767, 32767);

   s32LocalHystInput =
      (sint32)(DmpVlv_pDiagFiltStuckCls * DmpVlv_CoefPresStuckCls_C);
   s32LocalHystTreshold2 =
      (sint32)((DmpVlv_pThdOscStuckCls_C + DmpVlv_pOfsOscStuckCls_C) * 10);
   s32LocalHystTreshold1 = (sint32)(DmpVlv_pThdOscStuckCls_C * 10);

   /*Begin Hysteresis*/
   if (s32LocalHystInput > s32LocalHystTreshold2)
   {
      DmpVlv_bOscStuckCls = 1;
   }
   else
   {
      if (s32LocalHystInput <= s32LocalHystTreshold1)
      {
         DmpVlv_bOscStuckCls = 0;
      }
   }
   /*End Hysteresis*/

   if (u16LocalTrbAct_pUsThrFil > DmpVlv_pThdAcvDiagStuckCls_C)
   {
      bLocalTimer3Init = 1;
   }
   else
   {
      bLocalTimer3Init = 0;
   }
   /*Debut Timer3*/
   if (  (FCTDIAGDMPVLV_bTimer3Init_prev == 0)
      && (bLocalTimer3Init != 0))
   {
      DmpVlv_tiAcvCntOscStuckCls = MATHSRV_udtMIN(DmpVlv_tiAcvCntOscStuckCls_C,
                                                  80000);
      if (DmpVlv_tiAcvCntOscStuckCls == 0)
      {
         DmpVlv_bEndCntOscStuckCls = 1;
      }
      else
      {
         DmpVlv_bEndCntOscStuckCls = 0;
      }
   }
   else
   {
      if (DmpVlv_tiAcvCntOscStuckCls > 0)
      {
         VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
         if(u8LocalExt_tiTDC > DmpVlv_tiAcvCntOscStuckCls)
         {
            DmpVlv_tiAcvCntOscStuckCls = 0;
         }
         else
         {
            u32LocaltiAcvCntOscStuckCls =
               (DmpVlv_tiAcvCntOscStuckCls - u8LocalExt_tiTDC);
            DmpVlv_tiAcvCntOscStuckCls =
               MATHSRV_udtMIN(u32LocaltiAcvCntOscStuckCls, 80000);
         }
         if (DmpVlv_tiAcvCntOscStuckCls == 0)
         {
            DmpVlv_bEndCntOscStuckCls = 1;
         }
         else
         {
            DmpVlv_bEndCntOscStuckCls = 0;
         }
      }
   }
   FCTDIAGDMPVLV_bTimer3Init_prev = bLocalTimer3Init;
   /*Fin Timer3*/

   if (DmpVlv_tiAcvCntOscStuckCls > 0)
   {
      u8LocalSwitch1 = DmpVlv_ctPresOscStuckCls;
   }
   else
   {
      u8LocalSwitch1 = 0;
   }

   if (  (FCTDIAGDMPVLV_bOscStuckCls_prev == 0)
      && (DmpVlv_bOscStuckCls != 0))
   {
      u8LocalSwitch2 = 1;
   }
   else
   {
      u8LocalSwitch2 = 0;
   }
   u16LocalctPresOscStuckCls = (uint16)(u8LocalSwitch1 + u8LocalSwitch2);
   DmpVlv_ctPresOscStuckCls =
      (uint8)MATHSRV_udtMIN(u16LocalctPresOscStuckCls, 255);

   if (DmpVlv_ctPresOscStuckCls > DmpVlv_nbMaxOscStuckCls_C)
   {
      DmpVlv_bPresOscStuckCls = 1;
   }
   else
   {
      DmpVlv_bPresOscStuckCls = 0;
   }

   FCTDIAGDMPVLV_bOscStuckCls_prev = DmpVlv_bOscStuckCls;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGDMPVLV_vidCntDiagStuckCls                           */
/* !Description :  This function allows the counter to increase by one at     */
/*                 every oscillation detection flag’s rising edge.            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DmpVlv_ctDiagStuckCls;                                        */
/*  input uint8 DmpVlv_ctThdDiagStuckCls;                                     */
/*  output uint8 DmpVlv_ctDiagStuckCls;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGDMPVLV_vidCntDiagStuckCls(void)
{
   uint16 u16Localsum;


   u16Localsum = (uint16)(DmpVlv_ctDiagStuckCls + 1);
   DmpVlv_ctDiagStuckCls =
      (uint8)MATHSRV_udtMIN(DmpVlv_ctThdDiagStuckCls, u16Localsum);
}
/*------------------------------ end of file ---------------------------------*/