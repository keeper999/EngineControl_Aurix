/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FLOWMNG                                                 */
/* !Description     : FLOWMNG Component                                       */
/*                                                                            */
/* !Module          : FLOWMNG                                                 */
/* !Description     : Management of the configurable information flow         */
/*                                                                            */
/* !File            : FLOWMNG_FCT1.C                                          */
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
/*   1 / FLOWMNG_vidInitOutput                                                */
/*   2 / FLOWMNG_vidClu                                                       */
/*   3 / FLOWMNG_vidPMastervac                                                */
/*   4 / FLOWMNG_vidAlt_Cpt_Dem_Redem                                         */
/*   5 / FLOWMNG_vidPosGearSel                                                */
/*   6 / FLOWMNG_vidPosGearTempo                                              */
/*   7 / FLOWMNG_vidOil                                                       */
/*   8 / FLOWMNG_vidPosGearLev                                                */
/*   9 / FLOWMNG_vidBrkPush                                                   */
/*   10 / FLOWMNG_vidDAGMP_Traction                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT1.C_v        $*/
/* $Revision::   1.18     $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   10 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_pRelBrkAsiInit_C;                                         */
/*  input uint16 Ext_pBrkAsiInit_C;                                           */
/*  output boolean Ext_bCluPedPrss;                                           */
/*  output uint8 Ext_rCluP;                                                   */
/*  output uint16 Ext_rCluPHiFreq;                                            */
/*  output sint16 Ext_tOil;                                                   */
/*  output uint32 Ext_ctSec;                                                  */
/*  output uint16 Ext_ctDay;                                                  */
/*  output uint8 Ext_ctYr;                                                    */
/*  output boolean FLOWMNG_bTimer_prev;                                       */
/*  output boolean FLOWMNG_bTimer1_prev;                                      */
/*  output boolean FLOWMNG_bTimer2_prev;                                      */
/*  output uint8 FLOWMNG_u8Ext_ctInt_prev;                                    */
/*  output uint8 FLOWMNG_u8Timer;                                             */
/*  output uint8 FLOWMNG_u8Timer1;                                            */
/*  output uint8 FLOWMNG_u8Timer2;                                            */
/*  output boolean FLOWMNG_bTimeOut;                                          */
/*  output boolean FLOWMNG_bTime1Out;                                         */
/*  output boolean FLOWMNG_bTime2Out;                                         */
/*  output uint8 FLOWMNG_u8Ext_ctInt;                                         */
/*  output uint16 FLOWMNG_u16Ext_ctDay;                                       */
/*  output uint8 FLOWMNG_u8Ext_ctYr;                                          */
/*  output uint8 Ext_pRelBrkAsi;                                              */
/*  output uint16 Ext_pBrkAsi;                                                */
/*  output uint8 Tra_posnATLevExtSecu_prev;                                   */
/*  output sint16 Ext_tAirExtMesFineResl_prev;                                */
/*  output uint16 Fgigb_ti_VsctlDiagIniGb;                                    */
/*  output uint32 FLOWMNG_u32TiCtctSecStopEng_Prev;                           */
/*  output uint32 FLOWMNG_u32Ext_ctSec_Prev;                                  */
/*  output uint16 FLOWMNG_u16Ext_ctDay_Prev;                                  */
/*  output uint8 FLOWMNG_u8Ext_ctYr_Prev;                                     */
/*  output uint32 FLOWMNG_u32Ext_ctSecEngStop_Prev;                           */
/*  output uint32 FLOWMNG_u32Ext_ctSec_Prev_2;                                */
/*  output uint16 FLOWMNG_u16Ext_ctDay_Prev_2;                                */
/*  output uint8 FLOWMNG_u8Ext_ctYr_Prev_2;                                   */
/*  output uint32 TiCt_ctSecStopEng;                                          */
/*  output uint32 Ext_ctSecEngStop;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidInitOutput(void)
{
   uint8  u8Local_Ext_pRelBrkAsi;
   uint16 u16Local_Ext_pBrkAsi;


   VEMS_vidSET(Ext_bCluPedPrss, 0);
   VEMS_vidSET(Ext_rCluP, 0);
   VEMS_vidSET(Ext_rCluPHiFreq, 0);
   VEMS_vidSET(Ext_tOil, 0);
   VEMS_vidSET(Ext_ctSec, 0);
   VEMS_vidSET(Ext_ctDay, 0);
   VEMS_vidSET(Ext_ctYr, 0);
   FLOWMNG_bTimer_prev = 0;
   FLOWMNG_bTimer1_prev = 0;
   FLOWMNG_bTimer2_prev = 0;
   FLOWMNG_u8Ext_ctInt_prev = 0;
   FLOWMNG_u8Timer = 0;
   FLOWMNG_u8Timer1 = 0;
   FLOWMNG_u8Timer2 = 0;
   FLOWMNG_bTimeOut = 0;
   FLOWMNG_bTime1Out = 0;
   FLOWMNG_bTime2Out = 0;
   FLOWMNG_u8Ext_ctInt = 0;
   FLOWMNG_u16Ext_ctDay = 0;
   FLOWMNG_u8Ext_ctYr = 0;
   u8Local_Ext_pRelBrkAsi = (uint8)MATHSRV_udtCLAMP(Ext_pRelBrkAsiInit_C,
                                                    2,
                                                    125);
   VEMS_vidSET(Ext_pRelBrkAsi, u8Local_Ext_pRelBrkAsi);
   u16Local_Ext_pBrkAsi = (uint16)MATHSRV_udtCLAMP(Ext_pBrkAsiInit_C, 20, 1000);
   VEMS_vidSET(Ext_pBrkAsi, u16Local_Ext_pBrkAsi);
   Tra_posnATLevExtSecu_prev = 0;
   Ext_tAirExtMesFineResl_prev = 0;
   Fgigb_ti_VsctlDiagIniGb = 0;
   /**init Prev*/
   FLOWMNG_u32TiCtctSecStopEng_Prev = 0;
   FLOWMNG_u32Ext_ctSec_Prev = 0;
   FLOWMNG_u16Ext_ctDay_Prev = 0;
   FLOWMNG_u8Ext_ctYr_Prev = 0;
   FLOWMNG_u32Ext_ctSecEngStop_Prev = 0;
   FLOWMNG_u32Ext_ctSec_Prev_2 = 0;
   FLOWMNG_u16Ext_ctDay_Prev_2 = 0;
   FLOWMNG_u8Ext_ctYr_Prev_2 = 0;
   /**/
   VEMS_vidSET(TiCt_ctSecStopEng, 0);
   VEMS_vidSET(Ext_ctSecEngStop, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidClu                                             */
/* !Description :  Ce bloc traite les différents cas pour les signaux         */
/*                 d'embrayage                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_002.02                                     */
/*                 VEMS_R_11_00339_003.02                                     */
/*                 VEMS_R_11_00339_004.01                                     */
/*                 VEMS_R_11_00339_005.02                                     */
/*                 VEMS_R_11_00339_006.02                                     */
/*                 VEMS_R_11_00339_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_ESPPropSnsr_CMMSwt;                                    */
/*  input boolean Ctrl_rCluPedPrssMes;                                        */
/*  input boolean Ctrl_CMMPropSnsrOnly_PTT;                                   */
/*  input boolean Ctrl_ESPPropSnsr_CMMPropSnsr;                               */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean Ctrl_bCluPedPrssSen;                                        */
/*  input boolean Ext_bCluPedPrssMes;                                         */
/*  input uint16 Ext_rCluPedPrssMes;                                          */
/*  input uint16 Ext_rCluPCAN;                                                */
/*  input uint16 Ext_rCluPHiFreq;                                             */
/*  output boolean FlowMng_bCluSwtEna;                                        */
/*  output boolean FlowMng_bCluPropSnsrEna;                                   */
/*  output uint16 Ext_rCluPHiFreq;                                            */
/*  output uint8 Ext_rCluP;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidClu(void)
{
   boolean bLocalCtrl_bCluPedPrssSen;
   boolean bLocalCtrl_ESPPropSnsr_CMMSwt;
   boolean bLocalCtrl_rCluPedPrssMes;
   boolean bLocalCtrl_CMMPropSnsrOnly_PTT;
   boolean bLocalCtrl_ESPPropSnsr_CMMPrSnsr;
   boolean bLocalExt_bCluPedPrssMes;
   boolean bLocalFRM_bINHCLUCLCNRCLUDFT;
   boolean bLocalPrev;
   uint8   u8LocalExt_rCluP;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalExt_rCluPedPrssMes;
   uint16  u16LocalExt_rCluPCAN;
   uint16  u16LocalExt_rCluPHiFreq;
   uint32  u32LocalExt_rCluFreq;
   uint32  u32LocalExt_rCluP;


   VEMS_vidGET(Ctrl_ESPPropSnsr_CMMSwt, bLocalCtrl_ESPPropSnsr_CMMSwt);
   VEMS_vidGET(Ctrl_rCluPedPrssMes, bLocalCtrl_rCluPedPrssMes);
   VEMS_vidGET(Ctrl_CMMPropSnsrOnly_PTT, bLocalCtrl_CMMPropSnsrOnly_PTT);
   VEMS_vidGET(Ctrl_ESPPropSnsr_CMMPropSnsr, bLocalCtrl_ESPPropSnsr_CMMPrSnsr);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ctrl_bCluPedPrssSen, bLocalCtrl_bCluPedPrssSen);
   VEMS_vidGET(Ext_bCluPedPrssMes, bLocalExt_bCluPedPrssMes);
   VEMS_vidGET(Ext_rCluPedPrssMes, u16LocalExt_rCluPedPrssMes);
   VEMS_vidGET(Ext_rCluPCAN, u16LocalExt_rCluPCAN);

   bLocalFRM_bINHCLUCLCNRCLUDFT = GDGAR_bGetFRM(FRM_FRM_INHCLUCLCNRCLUDFT);
   /*production of Ext_rCluPHiFreq*/
   bLocalPrev = 0;
   if (  (bLocalCtrl_bCluPedPrssSen != 0)
      || (bLocalCtrl_ESPPropSnsr_CMMSwt != 0))
   {
      VEMS_vidSET(FlowMng_bCluSwtEna, 1);
   }
   else
   {
      VEMS_vidSET(FlowMng_bCluSwtEna, 0);
   }

   if (  (bLocalCtrl_rCluPedPrssMes != 0)
      || (bLocalCtrl_CMMPropSnsrOnly_PTT != 0)
      || (bLocalCtrl_ESPPropSnsr_CMMPrSnsr != 0))
   {
      VEMS_vidSET(FlowMng_bCluPropSnsrEna, 1);
   }
   else
   {
      VEMS_vidSET(FlowMng_bCluPropSnsrEna, 0);
   }
   if (u8LocalExt_stGBxCf != 0)
   {
      u16LocalExt_rCluPHiFreq = 0;
   }
   else
   {
      if (bLocalCtrl_bCluPedPrssSen !=0)
      {
         if (bLocalExt_bCluPedPrssMes != 0)
         {
            u16LocalExt_rCluPHiFreq = 1024;
         }
         else
         {
            u16LocalExt_rCluPHiFreq = 0;
         }
      }
      else
      {
         if (  (bLocalCtrl_rCluPedPrssMes != 0)
            || (bLocalCtrl_CMMPropSnsrOnly_PTT != 0))
         {
            u16LocalExt_rCluPHiFreq = u16LocalExt_rCluPedPrssMes;
         }
         else
         {
            if (bLocalCtrl_ESPPropSnsr_CMMSwt != 0)
            {
               u16LocalExt_rCluPHiFreq = u16LocalExt_rCluPCAN;
            }
            else
            {
               if (bLocalCtrl_ESPPropSnsr_CMMPrSnsr != 0)
               {
                  if (bLocalFRM_bINHCLUCLCNRCLUDFT != 0)
                  {
                     u16LocalExt_rCluPHiFreq = u16LocalExt_rCluPCAN;
                  }
                  else
                  {
                     u16LocalExt_rCluPHiFreq = u16LocalExt_rCluPedPrssMes;
                  }
               }
               else
               {
                  VEMS_vidGET(Ext_rCluPHiFreq, u16LocalExt_rCluPHiFreq);
                  bLocalPrev = 1;
               }
            }
         }
      }
   }
   if (bLocalPrev != 0)
   {
      u32LocalExt_rCluFreq = u16LocalExt_rCluPHiFreq;
      u32LocalExt_rCluP = (u16LocalExt_rCluPHiFreq + 4) / 8;
   }
   else
   {
      u32LocalExt_rCluFreq =
         (uint32)(((u16LocalExt_rCluPHiFreq * 25) + 8) / 16);
      u32LocalExt_rCluP = ((u16LocalExt_rCluPHiFreq * 25) + 64) / 128;
   }

   u16LocalExt_rCluPHiFreq = (uint16)MATHSRV_udtMIN(u32LocalExt_rCluFreq, 1600);
   VEMS_vidSET(Ext_rCluPHiFreq, u16LocalExt_rCluPHiFreq);

   u8LocalExt_rCluP = (uint8)MATHSRV_udtMIN(u32LocalExt_rCluP, 200);
   VEMS_vidSET(Ext_rCluP, u8LocalExt_rCluP);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidPMastervac                                      */
/* !Description :  Ce bloc permet le calcul des variables Ext_pRelBrkAsi et   */
/*                 Ext_pBrkAsi                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input uint8 Ext_stBrkAsiTypCf;                                            */
/*  input uint8 Ext_pRelBrkAsiMes;                                            */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_pBrkAsiMes;                                              */
/*  input uint8 Ext_pRelBrkAsi;                                               */
/*  input uint16 Ext_pBrkAsi;                                                 */
/*  input uint8 Ext_pRelBrkAsiInit_C;                                         */
/*  input uint16 Ext_pBrkAsiInit_C;                                           */
/*  output uint8 Ext_pRelBrkAsi;                                              */
/*  output uint16 Ext_pBrkAsi;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidPMastervac(void)
{
   boolean bLocalECU_bWkuMain;
   boolean bLocalECU_bImmoUnlockWkuSt;
   boolean bLocalUCE_bPwrlAcv;
   uint8   u8LocalExt_stBrkAsiTypCf;
   uint8   u8LocalExt_pRelBrkAsiMes;
   uint8   u8LocalExt_pRelBrkAsi;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalExt_pBrkAsiMes;
   uint16  u16LocalExt_pBrkAsi;
   sint32  s32Local;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(Ext_stBrkAsiTypCf, u8LocalExt_stBrkAsiTypCf);
   VEMS_vidGET(Ext_pRelBrkAsiMes, u8LocalExt_pRelBrkAsiMes);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_pBrkAsiMes, u16LocalExt_pBrkAsiMes);

   if (  (bLocalECU_bWkuMain == 0)
      && (bLocalECU_bImmoUnlockWkuSt == 0)
      && (bLocalUCE_bPwrlAcv == 0))
   {
      VEMS_vidGET(Ext_pRelBrkAsi, u8LocalExt_pRelBrkAsi);
      VEMS_vidGET(Ext_pBrkAsi, u16LocalExt_pBrkAsi);
   }
   else
   {
      if (u8LocalExt_stBrkAsiTypCf == ABSENT)
      {
         u8LocalExt_pRelBrkAsi = Ext_pRelBrkAsiInit_C;
         u16LocalExt_pBrkAsi = Ext_pBrkAsiInit_C;
      }
      else
      {
         if (u8LocalExt_stBrkAsiTypCf == RELATIF)
         {
            s32Local =
              (sint32)(u16LocalExt_pAirExtMes - (u8LocalExt_pRelBrkAsiMes * 8));
            u16LocalExt_pBrkAsi = (uint16)MATHSRV_udtMAX(s32Local, 0);
            u8LocalExt_pRelBrkAsi = u8LocalExt_pRelBrkAsiMes;
         }
         else
         {

            s32Local = (sint32)( ( ( u16LocalExt_pAirExtMes -
                                     u16LocalExt_pBrkAsiMes)
                                 + 4)
                               / 8);
            u8LocalExt_pRelBrkAsi = (uint8)MATHSRV_udtCLAMP(s32Local, 0, 255);
            u16LocalExt_pBrkAsi = u16LocalExt_pBrkAsiMes;
         }
      }
   }
   u8LocalExt_pRelBrkAsi = (uint8)MATHSRV_udtCLAMP(u8LocalExt_pRelBrkAsi,
                                                   2,
                                                   125);
   u16LocalExt_pBrkAsi = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pBrkAsi,
                                                  20,
                                                  1000);
   VEMS_vidSET(Ext_pRelBrkAsi, u8LocalExt_pRelBrkAsi);
   VEMS_vidSET(Ext_pBrkAsi, u16LocalExt_pBrkAsi);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Cpt_Dem_Redem                               */
/* !Description :  Ce bloc permet le calcul de la variable AraMth_ctStaAcv    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_035.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint32 DmgBelt_noEngStrt;                                           */
/*  input uint32 StaStrtMgt_ctStaAcv;                                         */
/*  output uint32 AraMth_ctStaAcv;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Cpt_Dem_Redem(void)
{
   boolean bLocalExt_bSTTCf;
   uint8   u8LocalExt_stElProdCf;
   uint32  u32LocalDmgBelt_noEngStrt;
   uint32  u32LocalStaStrtMgt_ctStaAcv;
   uint32  u32Local;


   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stElProdCf, u8LocalExt_stElProdCf);
   VEMS_vidGET(DmgBelt_noEngStrt, u32LocalDmgBelt_noEngStrt);
   VEMS_vidGET(StaStrtMgt_ctStaAcv, u32LocalStaStrtMgt_ctStaAcv);

   if (bLocalExt_bSTTCf != 0)
   {
      if (u8LocalExt_stElProdCf == EIPRODCF_ALTRV)
      {
         u32Local = MATHSRV_udtMIN(u32LocalDmgBelt_noEngStrt, 3000000);
         VEMS_vidSET(AraMth_ctStaAcv, u32Local);
      }
      else
      {
         if (u8LocalExt_stElProdCf == EIPRODCF_ALTDRV)
         {
            u32Local = MATHSRV_udtMIN(u32LocalStaStrtMgt_ctStaAcv,
                                      3000000);
            VEMS_vidSET(AraMth_ctStaAcv, u32Local);
         }
         else
         {
            VEMS_vidSET(AraMth_ctStaAcv, 0);
         }
      }
   }
   else
   {
      VEMS_vidSET(AraMth_ctStaAcv, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidPosGearSel                                      */
/* !Description :  Fonction qui gère le flux relativement à la position du    */
/*                 levier du vitessse et la position du PN                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stPosATLevExtdCAN;                                        */
/*  input uint8 Ext_stPosATLevPNCAN;                                          */
/*  output uint8 Tra_posnATLevExtSecu;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidPosGearSel(void)
{
   boolean bLocal_DftInvPosATLevPN;
   uint8   u8LocalExt_stPosATLevExtdCAN;
   uint8   u8LocalExt_stPosATLevPNCAN;


   bLocal_DftInvPosATLevPN = GDGAR_bGetFRM(FRM_FRM_DFTINVPOSATLEVPN);
   VEMS_vidGET(Ext_stPosATLevExtdCAN, u8LocalExt_stPosATLevExtdCAN);
   VEMS_vidGET(Ext_stPosATLevPNCAN, u8LocalExt_stPosATLevPNCAN);

   if (bLocal_DftInvPosATLevPN != 0)
   {
      VEMS_vidSET(Tra_posnATLevExtSecu, 3);
   }
   else
   {
      if (  (u8LocalExt_stPosATLevExtdCAN == 0)
         && (u8LocalExt_stPosATLevPNCAN == 1))
      {
         VEMS_vidSET(Tra_posnATLevExtSecu, 0);
      }
      else
      {
         if (  (u8LocalExt_stPosATLevExtdCAN == 2)
            && (u8LocalExt_stPosATLevPNCAN == 1))
         {
            VEMS_vidSET(Tra_posnATLevExtSecu, 2);
         }
         else
         {
            if (  (u8LocalExt_stPosATLevExtdCAN == 1)
               && (u8LocalExt_stPosATLevPNCAN == 2))
            {
               VEMS_vidSET(Tra_posnATLevExtSecu, 1);
            }
            else
            {
               if (  (u8LocalExt_stPosATLevExtdCAN == 3)
                  && (u8LocalExt_stPosATLevPNCAN == 2))
               {
                  VEMS_vidSET(Tra_posnATLevExtSecu, 3);
               }
               else
               {
                  VEMS_vidSET(Tra_posnATLevExtSecu, 2);
               }
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidPosGearTempo                                    */
/* !Description :  Fonction de gestion du flux relativement à la position du  */
/*                 levier de vitesse et celle du PN avec temporisation.       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stPosATLevExtdCAN;                                        */
/*  input uint8 Ext_stPosATLevPNCAN;                                          */
/*  input boolean FLOWMNG_bTimer_prev;                                        */
/*  input uint8 Ext_tPosATLevInCoh_C;                                         */
/*  input uint8 FLOWMNG_u8Timer;                                              */
/*  input boolean FLOWMNG_bTimer1_prev;                                       */
/*  input uint8 Ext_tPosATLevExtdInCoh_C;                                     */
/*  input uint8 FLOWMNG_u8Timer1;                                             */
/*  input boolean FLOWMNG_bTimer2_prev;                                       */
/*  input uint8 Ext_tPosATLevExtdInter_C;                                     */
/*  input uint8 FLOWMNG_u8Timer2;                                             */
/*  input boolean FLOWMNG_bTimeOut;                                           */
/*  input boolean FLOWMNG_bTime1Out;                                          */
/*  input boolean FLOWMNG_bTime2Out;                                          */
/*  input uint8 Tra_posnATLevExtSecu_prev;                                    */
/*  output uint8 FLOWMNG_u8Timer;                                             */
/*  output boolean FLOWMNG_bTimeOut;                                          */
/*  output boolean FLOWMNG_bTimer_prev;                                       */
/*  output uint8 FLOWMNG_u8Timer1;                                            */
/*  output boolean FLOWMNG_bTime1Out;                                         */
/*  output boolean FLOWMNG_bTimer1_prev;                                      */
/*  output uint8 FLOWMNG_u8Timer2;                                            */
/*  output boolean FLOWMNG_bTime2Out;                                         */
/*  output boolean FLOWMNG_bTimer2_prev;                                      */
/*  output uint8 Tra_posnATLevExtSecu;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidPosGearTempo(void)
{
   boolean bLocalInit;
   boolean bLocalInit1;
   boolean bLocalInit2;
   boolean bLocal_DftInvPosATLevPN;
   uint8   u8LocalExt_stPosATLevExtdCAN;
   uint8   u8LocalExt_stPosATLevPNCAN;
   uint8   u8LocalTra_posnATLevExtSecu;


   bLocal_DftInvPosATLevPN = GDGAR_bGetFRM(FRM_FRM_DFTINVPOSATLEVPN);
   VEMS_vidGET(Ext_stPosATLevExtdCAN, u8LocalExt_stPosATLevExtdCAN);
   VEMS_vidGET(Ext_stPosATLevPNCAN, u8LocalExt_stPosATLevPNCAN);

   /*timer*/
   if (  (  (  (u8LocalExt_stPosATLevExtdCAN == 1)
            || (u8LocalExt_stPosATLevExtdCAN == 3))
         && (u8LocalExt_stPosATLevPNCAN == 1)
         && (bLocal_DftInvPosATLevPN == 0))
      || (  (  (u8LocalExt_stPosATLevExtdCAN == 0)
            || (u8LocalExt_stPosATLevExtdCAN == 2))
         && (u8LocalExt_stPosATLevPNCAN == 2)
         && (bLocal_DftInvPosATLevPN == 0)))

   {
      bLocalInit = 1;
   }
   else
   {
      bLocalInit = 0;
   }

   if (  (FLOWMNG_bTimer_prev == 0)
      && (bLocalInit != 0))
   {
      FLOWMNG_u8Timer = Ext_tPosATLevInCoh_C;
      if (FLOWMNG_u8Timer == 0)
      {
         FLOWMNG_bTimeOut = 1;
      }
      else
      {
         FLOWMNG_bTimeOut = 0;
      }
   }
   else
   {
      if (FLOWMNG_u8Timer > 0)
      {
         FLOWMNG_u8Timer = (uint8)(FLOWMNG_u8Timer - 1);
         if (FLOWMNG_u8Timer == 0)
         {
            FLOWMNG_bTimeOut = 1;
         }
         else
         {
            FLOWMNG_bTimeOut = 0;
         }
      }
   }
   FLOWMNG_bTimer_prev = bLocalInit;

      /*timer1*/
   if (  (  (  (  (  (u8LocalExt_stPosATLevExtdCAN >= 4)
                  && (u8LocalExt_stPosATLevExtdCAN <=7))
               || (u8LocalExt_stPosATLevExtdCAN >= 11))
            && (u8LocalExt_stPosATLevPNCAN == 1)
            && (bLocal_DftInvPosATLevPN == 0)))
      || (  (  (  (u8LocalExt_stPosATLevExtdCAN >= 4)
              && (u8LocalExt_stPosATLevExtdCAN <=7))
            || (u8LocalExt_stPosATLevExtdCAN >= 11))
         && ( u8LocalExt_stPosATLevPNCAN == 2)
         && (bLocal_DftInvPosATLevPN == 0)))

   {
      bLocalInit1 = 1;
   }
   else
   {
      bLocalInit1 = 0;
   }

   if (  (FLOWMNG_bTimer1_prev == 0)
      && (bLocalInit1 != 0))
   {
      FLOWMNG_u8Timer1 = Ext_tPosATLevExtdInCoh_C;
      if (FLOWMNG_u8Timer1 == 0)
      {
         FLOWMNG_bTime1Out = 1;
      }
      else
      {
         FLOWMNG_bTime1Out = 0;
      }
   }
   else
   {
      if (FLOWMNG_u8Timer1 > 0)
      {
         FLOWMNG_u8Timer1 = (uint8)(FLOWMNG_u8Timer1 - 1);
         if (FLOWMNG_u8Timer1 == 0)
         {
            FLOWMNG_bTime1Out = 1;
         }
         else
         {
            FLOWMNG_bTime1Out = 0;
         }
      }
   }
   FLOWMNG_bTimer1_prev = bLocalInit1;

   /*timer2*/
   if (  (  (  (u8LocalExt_stPosATLevExtdCAN == 8)
            || (u8LocalExt_stPosATLevExtdCAN == 10))
         && (u8LocalExt_stPosATLevPNCAN == 1)
         && (bLocal_DftInvPosATLevPN == 0))
      || ( (  (u8LocalExt_stPosATLevExtdCAN == 8)
           || (u8LocalExt_stPosATLevExtdCAN == 10))
         && (u8LocalExt_stPosATLevPNCAN == 2)
         && (bLocal_DftInvPosATLevPN == 0)))

   {
      bLocalInit2 = 1;
   }
   else
   {
      bLocalInit2 = 0;
   }

   if (  (FLOWMNG_bTimer2_prev == 0)
      && (bLocalInit2 != 0))
   {
      FLOWMNG_u8Timer2 = Ext_tPosATLevExtdInter_C;
      if (FLOWMNG_u8Timer2 == 0)
      {
         FLOWMNG_bTime2Out = 1;
      }
      else
      {
         FLOWMNG_bTime2Out = 0;
      }
   }
   else
   {
      if (FLOWMNG_u8Timer2 > 0)
      {
         FLOWMNG_u8Timer2 = (uint8)(FLOWMNG_u8Timer2 - 1);
         if (FLOWMNG_u8Timer2 == 0)
         {
            FLOWMNG_bTime2Out = 1;
         }
         else
         {
            FLOWMNG_bTime2Out = 0;
         }
      }
   }

   FLOWMNG_bTimer2_prev = bLocalInit2;

   if (  (FLOWMNG_bTimeOut != 0)
      || (FLOWMNG_bTime1Out != 0)
      || (FLOWMNG_bTime2Out != 0))
   {
      u8LocalTra_posnATLevExtSecu = 3;
   }
   else
   {
      u8LocalTra_posnATLevExtSecu = Tra_posnATLevExtSecu_prev;
   }
   u8LocalTra_posnATLevExtSecu =
      (uint8)MATHSRV_udtMIN(u8LocalTra_posnATLevExtSecu, 3);
   VEMS_vidSET(Tra_posnATLevExtSecu, u8LocalTra_posnATLevExtSecu);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidOil                                             */
/* !Description :  Function OIL                                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_031.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input boolean Ext_bOilPresProp;                                           */
/*  input boolean Ext_bRawOilPresProp;                                        */
/*  input boolean Oil_Pres_alertProp;                                         */
/*  input boolean Ext_bOilPresDetec;                                          */
/*  input boolean Ext_bRawOilPresDetec;                                       */
/*  input boolean Oil_pres_alertDetec;                                        */
/*  output boolean Ext_bOilPres;                                              */
/*  output boolean Ext_bPresOilEng;                                           */
/*  output boolean Ext_bRawOilPres;                                           */
/*  output boolean Oil_pres_alert;                                            */
/*  output boolean Ext_bPresOilWarn;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidOil(void)
{
   boolean bLocalExt_bOilPresProp;
   boolean bLocalExt_bRawOilPresProp;
   boolean bLocalOil_Pres_alertProp;
   boolean bLocalCtrl_bOilPropPresAcq;
   boolean bLocalOil_pres_alertDetec;
   boolean bLocalExt_bRawOilPresDetec;
   boolean bLocalExt_bOilPresDetec;
   boolean bLocalFRM_bInhDiag_bPresOilWarn;
   boolean bLocalExt_bPresOilWarn;


   bLocalFRM_bInhDiag_bPresOilWarn =
                            GDGAR_bGetFRM(FRM_FRM_INHDIAG_BPRESOILWARN);
   VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
   if (bLocalCtrl_bOilPropPresAcq != 0)
   {
      VEMS_vidGET(Ext_bOilPresProp, bLocalExt_bOilPresProp);
      VEMS_vidGET(Ext_bRawOilPresProp, bLocalExt_bRawOilPresProp);
      VEMS_vidGET(Oil_Pres_alertProp, bLocalOil_Pres_alertProp);
      VEMS_vidSET(Ext_bOilPres, bLocalExt_bOilPresProp);
      VEMS_vidSET(Ext_bPresOilEng, bLocalExt_bOilPresProp);
      VEMS_vidSET(Ext_bRawOilPres, bLocalExt_bRawOilPresProp);
      VEMS_vidSET(Oil_pres_alert, bLocalOil_Pres_alertProp);
      bLocalExt_bPresOilWarn = bLocalOil_Pres_alertProp;
   }
   else
   {
      VEMS_vidGET(Ext_bOilPresDetec, bLocalExt_bOilPresDetec);
      VEMS_vidGET(Ext_bRawOilPresDetec, bLocalExt_bRawOilPresDetec);
      VEMS_vidGET(Oil_pres_alertDetec, bLocalOil_pres_alertDetec);
      VEMS_vidSET(Ext_bOilPres, bLocalExt_bOilPresDetec);
      VEMS_vidSET(Ext_bRawOilPres, bLocalExt_bRawOilPresDetec);
      VEMS_vidSET(Oil_pres_alert, bLocalOil_pres_alertDetec);
      VEMS_vidSET(Ext_bPresOilEng, bLocalExt_bOilPresDetec);
      bLocalExt_bPresOilWarn = bLocalOil_pres_alertDetec;
   }
   if (bLocalFRM_bInhDiag_bPresOilWarn != 0)
   {
      VEMS_vidSET(Ext_bPresOilWarn, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bPresOilWarn, bLocalExt_bPresOilWarn);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidPosGearLev                                      */
/* !Description :  Fonction qui gère le niveau delevier de vitesse.           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidFirstCases();                                 */
/*  extf argret void FLOWMNG_vidPosGearSel();                                 */
/*  extf argret void FLOWMNG_vidPosGearTempo();                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bPosAT_FrstCases;                                       */
/*  input uint8 Tra_posnATLevExtSecu;                                         */
/*  output uint8 Tra_posnATLevExtSecu_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidPosGearLev(void)
{
   uint8  u8LocalTra_posnATLevExtSecu;


   FLOWMNG_vidFirstCases();
   if (Ext_bPosAT_FrstCases != 0)
   {
      FLOWMNG_vidPosGearSel();
   }
   else
   {
      FLOWMNG_vidPosGearTempo();
   }
   VEMS_vidGET(Tra_posnATLevExtSecu, u8LocalTra_posnATLevExtSecu);
   Tra_posnATLevExtSecu_prev =
   (uint8)MATHSRV_udtMIN(u8LocalTra_posnATLevExtSecu, 3);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidBrkPush                                         */
/* !Description :  Fonction qui gère les informations relatives à l'appuie sur*/
/*                 le frein.                                                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bMainBrkPedPrssMes;                                     */
/*  input boolean Ext_bMainBrkPedPrssHsMes;                                   */
/*  input boolean Ext_bSecBrkPedPrssMes;                                      */
/*  output boolean Ext_bBrkPedPrss;                                           */
/*  output boolean Ext_bBrkPedPrssHs;                                         */
/*  output boolean Ext_bEfcBrkPedPrss;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidBrkPush(void)
{
   boolean bLocalExt_bMainBrkPedPrssMes;
   boolean bLocalExt_bMainBrkPedPrssHsMes;
   boolean bLocalExt_bSecBrkPedPrssMes;
   boolean bLocalFRM_bBrkPedPrss;


   VEMS_vidGET(Ext_bMainBrkPedPrssMes, bLocalExt_bMainBrkPedPrssMes);
   VEMS_vidGET(Ext_bMainBrkPedPrssHsMes, bLocalExt_bMainBrkPedPrssHsMes);
   VEMS_vidGET(Ext_bSecBrkPedPrssMes, bLocalExt_bSecBrkPedPrssMes);
   bLocalFRM_bBrkPedPrss = GDGAR_bGetFRM(FRM_FRM_BRKPEDPRSS);

   if (  (bLocalExt_bMainBrkPedPrssMes != 0)
      || (bLocalExt_bMainBrkPedPrssHsMes != 0)
      || (bLocalExt_bSecBrkPedPrssMes != 0)
      || (bLocalFRM_bBrkPedPrss != 0))
   {
      VEMS_vidSET(Ext_bBrkPedPrss, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bBrkPedPrss, 0);
   }

   if (  (bLocalFRM_bBrkPedPrss != 0)
      || (bLocalExt_bMainBrkPedPrssHsMes != 0))
   {
      VEMS_vidSET(Ext_bBrkPedPrssHs, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bBrkPedPrssHs, 0);
   }

   if (  (bLocalExt_bMainBrkPedPrssMes != 0)
      && (bLocalExt_bSecBrkPedPrssMes != 0))
   {
      VEMS_vidSET(Ext_bEfcBrkPedPrss, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bEfcBrkPedPrss, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDAGMP_Traction                                  */
/* !Description :  Fonction qui détermine l'état du traction en fonction du   */
/*                 type de DAGMP et de la boite à vitesse.                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_019.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stStrtCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 CoPTSt_stDrvTra;                                              */
/*  output uint8 Ext_stPwt;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDAGMP_Traction(void)
{
   uint8 u8LocalExt_stStrtCf;
   uint8 u8LocalExt_stGBxCf;
   uint8 u8LocalExt_stPwt;
   uint8 u8LocalCoPTSt_stDrvTra;


   VEMS_vidGET(Ext_stStrtCf, u8LocalExt_stStrtCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (  (u8LocalExt_stStrtCf == DAGMP_Key_Meca)
      && (u8LocalExt_stGBxCf == BVM))
   {
      u8LocalExt_stPwt = Driv_Train_closed;
   }
   else
   {
      VEMS_vidGET(CoPTSt_stDrvTra, u8LocalCoPTSt_stDrvTra);
      if (u8LocalCoPTSt_stDrvTra == 0)
      {
         u8LocalExt_stPwt = 1;
      }
      else
      {
         if (u8LocalCoPTSt_stDrvTra == 1)
         {
            u8LocalExt_stPwt = 0;
         }
         else
         {
            u8LocalExt_stPwt = 2;
         }
      }
   }
   VEMS_vidSET(Ext_stPwt, u8LocalExt_stPwt);
}
/*------------------------------- end of file --------------------------------*/