/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CTRLCFG                                                 */
/* !Description     : CTRLCFG Component                                       */
/*                                                                            */
/* !Module          : CTRLCFG                                                 */
/* !Description     : CONFIGURATION FLOW MANAGEMENT                           */
/*                                                                            */
/* !File            : CTRLCFG_FCT1.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / CTRLCFG_vidCtrlCfg                                                   */
/*   2 / CTRLCFG_vidCtrlCfg2                                                  */
/*   3 / CTRLCFG_vidFrameCfg                                                  */
/*   4 / CTRLCFG_vidFrameCfg2                                                 */
/*   5 / CTRLCFG_vidFrameCfg3                                                 */
/*   6 / CTRLCFG_vidBrkUCFrame                                                */
/*   7 / CTRLCFG_vidBrkUCFrame2                                               */
/*   8 / CTRLCFG_vidGearBoxFrame                                              */
/*   9 / CTRLCFG_vidBSIFrame                                                  */
/*   10 / CTRLCFG_vidBSIFrame2                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5068500 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CTRLCFG/CTRLCFG_FCT1.C_v        $*/
/* $Revision::   1.20     $$Author::   pbakabad       $$Date::   Jul 01 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 01 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CTRLCFG.h"
#include "CTRLCFG_L.h"
#include "CTRLCFG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidCtrlCfg                                         */
/* !Description :  All the activation flows are fixed to 1.                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_002.07                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input uint8 Tra_stGearCtlFirst;                                           */
/*  input boolean Ext_bBlowBy1Cf;                                             */
/*  input uint8 Ext_stStrtRstrtDevCf;                                         */
/*  input uint8 Ext_stOilPresCf;                                              */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input boolean Ctrl_bTAirExtMes_C;                                         */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean Far_bSelFarSpMdlCf_C;                                       */
/*  input boolean HPPmpAct_bAcv_PFuAcq_C;                                     */
/*  input boolean Spg_bAcv_pUsThr_C;                                          */
/*  input boolean Wg_bTrbAct_rCtl_C;                                          */
/*  input boolean OilSysHw_bOilPmpCmd_C;                                      */
/*  input uint8 Ext_stBrkAsiTypCf_C;                                          */
/*  input boolean Ctrl_bAcv_EngMes_C;                                         */
/*  input boolean Ctrl_bAvc_BlowBy1_C;                                        */
/*  input boolean CoT_bAcv_TrbCoWaPmp_C;                                      */
/*  input boolean Oil_bAcv_uEngOilLvl_C;                                      */
/*  output boolean Ctrl_bStrtLockAcq;                                         */
/*  output boolean Ctrl_bTAirExtMes;                                          */
/*  output boolean Ctrl_bTAirExtMes_C;                                        */
/*  output boolean Ctrl_bVVTVlvIn;                                            */
/*  output boolean VlvAct_bAcvVlvActInStr_C;                                  */
/*  output boolean Ctrl_bCmInAcq;                                             */
/*  output boolean Ctrl_bVVTVlvEx;                                            */
/*  output boolean VlvAct_bAcvVlvActExStr_C;                                  */
/*  output boolean Ctrl_bCmExAcq;                                             */
/*  output boolean Ctrl_bSelFarSpMdlCf;                                       */
/*  output boolean Far_bSelFarSpMdlCf_C;                                      */
/*  output boolean Ctrl_bAcv_PFuAcq;                                          */
/*  output boolean HPPmpAct_bAcv_PFuAcq_C;                                    */
/*  output boolean Ctrl_bAcv_pUsThr;                                          */
/*  output boolean Spg_bAcv_pUsThr_C;                                         */
/*  output boolean Ctrl_bTrbAct_rCtl;                                         */
/*  output boolean Ctrl_bOilPmpCmd;                                           */
/*  output boolean Ctrl_bOilPropPresAcq;                                      */
/*  output boolean AirPres_bAcvBrkAsiAcq;                                     */
/*  output boolean Ctrl_bAcv_pRelBrkAsi;                                      */
/*  output uint8 Ext_stBrkAsiTypCf;                                           */
/*  output uint8 Ext_stBrkAsiTypCf_C;                                         */
/*  output boolean Ctrl_bAcv_EngMes;                                          */
/*  output boolean Ctrl_bAcv_EngMes_C;                                        */
/*  output boolean Ctrl_BlowBy1Hw;                                            */
/*  output boolean Ctrl_bAvc_BlowBy1;                                         */
/*  output uint8 Tra_stGearCtl;                                               */
/*  output boolean Gear_bAcvNeutPosnAcq;                                      */
/*  output boolean EngSt_bAcvDftStaCmdAcq;                                    */
/*  output boolean Pwr_bAcvDMTRAcq;                                           */
/*  output boolean Ctrl_VSSNwMgt_bVSSNwAcvAuth;                               */
/*  output boolean EngSt_bAcvAuthStrtSTTAcq;                                  */
/*  output boolean Ctrl_bAcv_TrbCoWaPmp;                                      */
/*  output boolean CoT_bAcv_TrbCoWaPmp_C;                                     */
/*  output boolean Ctrl_bAcv_uEngOilLvl;                                      */
/*  output boolean Oil_bAcv_uEngOilLvl_C;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidCtrlCfg(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bSTTCf;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalExt_bBlowBy1Cf;
   boolean bLocalImmoUnlockWkuSt;
   uint8   u8LocalExt_stStrtRstrtDevCf;
   uint8   u8LocalTra_stGearCtlFirst;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stOilPresCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(Tra_stGearCtlFirst, u8LocalTra_stGearCtlFirst);
   VEMS_vidGET(Ext_bBlowBy1Cf, bLocalExt_bBlowBy1Cf);
   VEMS_vidGET(Ext_stStrtRstrtDevCf, u8LocalExt_stStrtRstrtDevCf);
   VEMS_vidGET(Ext_stOilPresCf, u8LocalExt_stOilPresCf);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalImmoUnlockWkuSt);

   if (  (bLocalExt_bArchiCf != 0)
      && (  (u8LocalExt_stGBxCf == 1)
         || (u8LocalExt_stGBxCf == 2) ) )
   {
      VEMS_vidSET(Ctrl_bStrtLockAcq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bStrtLockAcq, 0);
   }

   VEMS_vidSET(Ctrl_bTAirExtMes, Ctrl_bTAirExtMes_C);
   VEMS_vidSET(Ctrl_bVVTVlvIn, VlvAct_bAcvVlvActInStr_C);
   VEMS_vidSET(Ctrl_bCmInAcq, VlvAct_bAcvVlvActInStr_C);
   VEMS_vidSET(Ctrl_bVVTVlvEx, VlvAct_bAcvVlvActExStr_C);
   VEMS_vidSET(Ctrl_bCmExAcq, VlvAct_bAcvVlvActExStr_C);
   VEMS_vidSET(Ctrl_bSelFarSpMdlCf, Far_bSelFarSpMdlCf_C);
   VEMS_vidSET(Ctrl_bAcv_PFuAcq, HPPmpAct_bAcv_PFuAcq_C);
   VEMS_vidSET(Ctrl_bAcv_pUsThr, Spg_bAcv_pUsThr_C);

   if (  (  (bLocalECU_bWkuMain != 0)
         || (bLocalImmoUnlockWkuSt != 0))
      && (Wg_bTrbAct_rCtl_C != 0))
   {
      VEMS_vidSET(Ctrl_bTrbAct_rCtl, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bTrbAct_rCtl, 0);
   }

   if (  (OilSysHw_bOilPmpCmd_C != 0)
      && (bLocalUCE_bPwrlAcv == 0))
   {
      VEMS_vidSET(Ctrl_bOilPmpCmd, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bOilPmpCmd, 0);
   }

   if (u8LocalExt_stOilPresCf == 2)
   {
      VEMS_vidSET(Ctrl_bOilPropPresAcq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bOilPropPresAcq, 0);
   }

   if (Ext_stBrkAsiTypCf_C == ABSOLU)
   {
      VEMS_vidSET(AirPres_bAcvBrkAsiAcq, 1);
   }
   else
   {
      VEMS_vidSET(AirPres_bAcvBrkAsiAcq, 0);
   }

   if (Ext_stBrkAsiTypCf_C == RELATIF)
   {
      VEMS_vidSET(Ctrl_bAcv_pRelBrkAsi, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcv_pRelBrkAsi, 0);
   }

   VEMS_vidSET(Ext_stBrkAsiTypCf, Ext_stBrkAsiTypCf_C);
   VEMS_vidSET(Ctrl_bAcv_EngMes, Ctrl_bAcv_EngMes_C);
   VEMS_vidSET(Ctrl_BlowBy1Hw, bLocalExt_bBlowBy1Cf);

   if (  (Ctrl_bAvc_BlowBy1_C != 0)
      && ( bLocalExt_bBlowBy1Cf != 0))
   {
      VEMS_vidSET(Ctrl_bAvc_BlowBy1, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAvc_BlowBy1, 0);
   }

   /* Calcul Tra_stGearCtl */
   if (u8LocalExt_stGBxCf != 1)
   {
      VEMS_vidSET(Tra_stGearCtl, 0);
   }
   else
   {
      if (u8LocalTra_stGearCtlFirst == 1)
      {
         VEMS_vidSET(Tra_stGearCtl, 3);
      }
      else
      {
         if (u8LocalTra_stGearCtlFirst == 2)
         {
            VEMS_vidSET(Tra_stGearCtl, 4);
         }
         else
         {
            if (u8LocalTra_stGearCtlFirst == 3)
            {
               VEMS_vidSET(Tra_stGearCtl, 6);
            }
            else
            {
               VEMS_vidSET(Tra_stGearCtl, 2);
            }
         }
      }
   }

   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bSTTCf != 0))
   {
      VEMS_vidSET(Gear_bAcvNeutPosnAcq, 1);
   }
   else
   {
      VEMS_vidSET(Gear_bAcvNeutPosnAcq, 0);
   }

   if (  (u8LocalExt_stStrtRstrtDevCf == STTD_PRESENT)
      && (bLocalECU_bWkuMain != 0))
   {
      VEMS_vidSET(EngSt_bAcvDftStaCmdAcq, 1);
   }
   else
   {
      VEMS_vidSET(EngSt_bAcvDftStaCmdAcq, 0);
   }

   if (  (u8LocalExt_stStrtRstrtDevCf == STTD_PRESENT)
      && (  (bLocalECU_bWkuMain != 0)
         || (bLocalUCE_bPwrlAcv != 0)))
   {
      VEMS_vidSET(Pwr_bAcvDMTRAcq, 1);
   }
   else
   {
      VEMS_vidSET(Pwr_bAcvDMTRAcq, 0);
   }

   if (u8LocalExt_stStrtRstrtDevCf == STTD_PRESENT)
   {
      VEMS_vidSET(Ctrl_VSSNwMgt_bVSSNwAcvAuth, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_VSSNwMgt_bVSSNwAcvAuth, 0);
   }

   VEMS_vidSET(EngSt_bAcvAuthStrtSTTAcq, bLocalExt_bSTTCf);
   VEMS_vidSET(Ctrl_bAcv_TrbCoWaPmp, CoT_bAcv_TrbCoWaPmp_C);
   VEMS_vidSET(Ctrl_bAcv_uEngOilLvl, Oil_bAcv_uEngOilLvl_C);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidCtrlCfg2                                        */
/* !Description :  All the activation flows are fixed to 1.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_002.07                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bStrtDrvIfCf;                                           */
/*  input boolean Ext_bBPGACf;                                                */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Srv_bInhSftyLvl2;                                           */
/*  input uint8 Ext_stCabHeatCf;                                              */
/*  input uint8 Ext_stStrtRstrtDevCf;                                         */
/*  input boolean Srv_bAcvUnloadRail;                                         */
/*  input boolean Ext_bAcv_BrkSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_CluSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_ThrSftyLvl2_C;                                     */
/*  input boolean Ext_bAcv_VehSpdSftyLvl2_C;                                  */
/*  input boolean Ext_bAcv_NeutPosnAcqSftyLvl2_C;                             */
/*  input boolean Ext_bAcv_BrkAsiSftyLvl2_C;                                  */
/*  input boolean Ext_bAcv_AccPSftyLvl2_C;                                    */
/*  input boolean Ext_bAcv_RelBrkAsiSftyLvl2_C;                               */
/*  input boolean Ext_bAcv_FHCANF34DLvl2_C;                                   */
/*  input boolean Ext_bAcv_FHCANF329Lvl2_C;                                   */
/*  input boolean Ext_bAcv_FHCANF38DLvl2_C;                                   */
/*  input boolean Ext_bAcv_FHCANF349Lvl2_C;                                   */
/*  input boolean Ext_bAcv_FHCANF3C9Lvl2_C;                                   */
/*  input boolean Ctrl_bTreatAdHeatRly_C;                                     */
/*  input boolean Fu_bAcv_FuTnkPmp_C;                                         */
/*  input boolean Fu_bAcv_HpPmp_C;                                            */
/*  output boolean Ctrl_bEngRun;                                              */
/*  output boolean Ext_bEngRun_Archi2010EcoPush;                              */
/*  output boolean Ext_bAcv_BrkSftyLvl2;                                      */
/*  output boolean Ext_bAcv_CluSftyLvl2;                                      */
/*  output boolean Ext_bAcv_ThrSftyLvl2;                                      */
/*  output boolean Ext_bAcv_VehSpdSftyLvl2;                                   */
/*  output boolean Ext_bAcv_NeutPosnAcqSftyLvl2;                              */
/*  output boolean Ext_bAcv_BrkAsiSftyLvl2;                                   */
/*  output boolean Ext_bAcv_AccPSftyLvl2;                                     */
/*  output boolean Ext_bAcv_RelBrkAsiSftyLvl2;                                */
/*  output boolean Ext_bAcv_FHCANF34DLvl2;                                    */
/*  output boolean Ext_bAcv_FHCANF329Lvl2;                                    */
/*  output boolean Ext_bAcv_FHCANF38DLvl2;                                    */
/*  output boolean Ext_bAcv_FHCANF349Lvl2;                                    */
/*  output boolean Ext_bAcv_FHCANF3C9Lvl2;                                    */
/*  output boolean Cf_bPushLine;                                              */
/*  output boolean Cf_bKeyLine;                                               */
/*  output boolean Ctrl_bTreatAdHeatRly;                                      */
/*  output boolean Ctrl_bAcv_FuTnkPmp;                                        */
/*  output boolean Ctrl_bAcv_HpPmp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidCtrlCfg2(void)
{
   boolean bLocalSrv_bInhSftyLvl2;
   boolean bLocalExt_stCabHeatCf;
   boolean bLocalExt_stStrtRstrtDevCf;
   boolean bLocalExt_bStrtDrvIfCf;
   boolean bLocalSrv_bAcvUnloadRail;
   boolean bLocalExt_bBPGACf;
   boolean bLocalExt_bArchiCf;


   VEMS_vidGET(Ext_bStrtDrvIfCf, bLocalExt_bStrtDrvIfCf);
   VEMS_vidGET(Ext_bBPGACf, bLocalExt_bBPGACf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Srv_bInhSftyLvl2, bLocalSrv_bInhSftyLvl2);
   VEMS_vidGET(Ext_stCabHeatCf, bLocalExt_stCabHeatCf);
   VEMS_vidGET(Ext_stStrtRstrtDevCf, bLocalExt_stStrtRstrtDevCf);
   VEMS_vidGET(Srv_bAcvUnloadRail, bLocalSrv_bAcvUnloadRail);


   if (  (bLocalExt_bArchiCf == 0)
      || (bLocalExt_bBPGACf != 0))
   {
      VEMS_vidSET(Ctrl_bEngRun, 1);
      VEMS_vidSET(Ext_bEngRun_Archi2010EcoPush, 0);
   }
   else
   {
      VEMS_vidSET(Ctrl_bEngRun, bLocalExt_bStrtDrvIfCf);
      VEMS_vidSET(Ext_bEngRun_Archi2010EcoPush, bLocalExt_bStrtDrvIfCf);
   }

   if (  (Ext_bAcv_BrkSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_BrkSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_BrkSftyLvl2, 0);
   }

   if (  (Ext_bAcv_CluSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_CluSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_CluSftyLvl2, 0);
   }

   if (  (Ext_bAcv_ThrSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_ThrSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_ThrSftyLvl2, 0);
   }

   if (  (Ext_bAcv_VehSpdSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_VehSpdSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_VehSpdSftyLvl2, 0);
   }

   if (  (Ext_bAcv_NeutPosnAcqSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_NeutPosnAcqSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_NeutPosnAcqSftyLvl2, 0);
   }

   if (  (Ext_bAcv_BrkAsiSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_BrkAsiSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_BrkAsiSftyLvl2, 0);
   }

   if (  (Ext_bAcv_AccPSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_AccPSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_AccPSftyLvl2, 0);
   }

   if (  (Ext_bAcv_RelBrkAsiSftyLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_RelBrkAsiSftyLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_RelBrkAsiSftyLvl2, 0);
   }

   if (  (Ext_bAcv_FHCANF34DLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_FHCANF34DLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_FHCANF34DLvl2, 0);
   }

   if (  (Ext_bAcv_FHCANF329Lvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_FHCANF329Lvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_FHCANF329Lvl2, 0);
   }

   if (  (Ext_bAcv_FHCANF38DLvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_FHCANF38DLvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_FHCANF38DLvl2, 0);
   }

   if (  (Ext_bAcv_FHCANF349Lvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_FHCANF349Lvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_FHCANF349Lvl2, 0);
   }

   if (  (Ext_bAcv_FHCANF3C9Lvl2_C != 0)
      && (bLocalSrv_bInhSftyLvl2 == 0))
   {
      VEMS_vidSET(Ext_bAcv_FHCANF3C9Lvl2, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bAcv_FHCANF3C9Lvl2, 0);
   }

   if (bLocalExt_stStrtRstrtDevCf == STTD_PRESENT)
   {
      if (bLocalExt_bStrtDrvIfCf !=0)
      {
         VEMS_vidSET(Cf_bPushLine, 1);
         VEMS_vidSET(Cf_bKeyLine, 0);
      }
      else
      {
         VEMS_vidSET(Cf_bPushLine, 0);
         VEMS_vidSET(Cf_bKeyLine, 1);
      }
   }
   else
   {
      VEMS_vidSET(Cf_bPushLine, 0);
      VEMS_vidSET(Cf_bKeyLine, 0);
   }

   /* Calcul Ctrl_bTreatAdHeatRly */
   if (  (  (bLocalExt_stCabHeatCf == 1)
         || (bLocalExt_stCabHeatCf == 2)
         || (bLocalExt_stCabHeatCf == 5)
         || (bLocalExt_stCabHeatCf == 6))
      && (bLocalExt_bArchiCf == 0)
      && (Ctrl_bTreatAdHeatRly_C != 0))
   {
      VEMS_vidSET(Ctrl_bTreatAdHeatRly, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bTreatAdHeatRly, 0);
   }

   if (  (Fu_bAcv_FuTnkPmp_C != 0)
      && (bLocalSrv_bAcvUnloadRail == 0))
   {
      VEMS_vidSET(Ctrl_bAcv_FuTnkPmp, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcv_FuTnkPmp, 0);
   }
   if (  (bLocalSrv_bAcvUnloadRail == 0)
      && (Fu_bAcv_HpPmp_C != 0) )
   {
      VEMS_vidSET(Ctrl_bAcv_HpPmp, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bAcv_HpPmp, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidFrameCfg                                        */
/* !Description :  According the variant coding of the vehicle, the CAN frames*/
/*                 will be activated (their control flow will be equal to 1). */
/*                 We authorize the transmission or the reception of each     */
/*                 frame.                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTRLCFG_vidBrkUCFrame();                                 */
/*  extf argret void CTRLCFG_vidBrkUCFrame2();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidFrameCfg(void)
{
   CTRLCFG_vidBrkUCFrame();
   CTRLCFG_vidBrkUCFrame2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidFrameCfg2                                       */
/* !Description :  According the variant coding of the vehicle, the CAN frames*/
/*                 will be activated (their control flow will be equal to 1). */
/*                 We authorize the transmission or the reception of each     */
/*                 frame.                                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTRLCFG_vidGearBoxFrame();                               */
/*  extf argret void CTRLCFG_vidBSIFrame();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidFrameCfg2(void)
{
   CTRLCFG_vidGearBoxFrame();
   CTRLCFG_vidBSIFrame();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidFrameCfg3                                       */
/* !Description :  According the variant coding of the vehicle, the CAN frames*/
/*                 will be activated (their control flow will be equal to 1). */
/*                 We authorize the transmission or the reception of each     */
/*                 frame.                                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTRLCFG_vidBSIFrame2();                                  */
/*  extf argret void CTRLCFG_vidBSIFrame3();                                  */
/*  extf argret void CTRLCFG_vidBSIFrame4();                                  */
/*  extf argret void CTRLCFG_vidBSIFrame5();                                  */
/*  extf argret void CTRLCFG_vidECUFrames();                                  */
/*  extf argret void CTRLCFG_vidECUFrames2();                                 */
/*  extf argret void CTRLCFG_vidECUFrames3();                                 */
/*  extf argret void CTRLCFG_vidPSFrames();                                   */
/*  extf argret void CTRLCFG_vidCluFrames();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidFrameCfg3(void)
{
   CTRLCFG_vidBSIFrame2();
   CTRLCFG_vidBSIFrame3();
   CTRLCFG_vidBSIFrame4();
   CTRLCFG_vidBSIFrame5();
   CTRLCFG_vidECUFrames();
   CTRLCFG_vidECUFrames2();
   CTRLCFG_vidECUFrames3();
   CTRLCFG_vidPSFrames();
   CTRLCFG_vidCluFrames();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBrkUCFrame                                      */
/* !Description :  Each frame sent or received by the Brake control unit are  */
/*                 activated by a control flow, according the vehicle         */
/*                 configuration.                                             */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_003.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bSpdCf;                                                 */
/*  input boolean Ext_bFilCf_spdVehAvrFrntWhl;                                */
/*  input boolean Ext_bASRESPCf;                                              */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input boolean Ext_bEasyMoveCf;                                            */
/*  input boolean Ext_bBrkMainInfoCf;                                         */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  output boolean Ctrl_FRE_30D;                                              */
/*  output boolean Ctrl_CDS_34D;                                              */
/*  output boolean Ctrl_rSlopStab;                                            */
/*  output boolean Ctrl_stHillAsi;                                            */
/*  output boolean Ctrl_ABR_38D;                                              */
/*  output boolean Ctrl_FRE_3CD;                                              */
/*  output boolean Ctrl_bHillAsiRdyEngStop;                                   */
/*  output boolean Ctrl_EASY_MOVE_3AD;                                        */
/*  output boolean Ctrl_ABR_44D;                                              */
/*  output boolean Ctrl_ABR_50D;                                              */
/*  output boolean Ctrl_bMainBrkPedPrssMes;                                   */
/*  output boolean Ctrl_pBrkMCT;                                              */
/*  output boolean Ctrl_rCluPCAN;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBrkUCFrame(void)
{
   boolean bLocalExt_bABSCf;
   boolean bLocalExt_bSpdCf;
   boolean bLocalExt_bSpdFrntWhl;
   boolean bLocalExt_bASRESPCf;
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bEasyMoveCf;
   boolean bLocalExt_bBrkMainInfoCf;
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_bABSCf, bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bSpdCf, bLocalExt_bSpdCf);
   VEMS_vidGET(Ext_bFilCf_spdVehAvrFrntWhl, bLocalExt_bSpdFrntWhl);
   VEMS_vidGET(Ext_bASRESPCf, bLocalExt_bASRESPCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_bEasyMoveCf, bLocalExt_bEasyMoveCf);
   VEMS_vidGET(Ext_bBrkMainInfoCf, bLocalExt_bBrkMainInfoCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);

   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bSpdCf == 0)
      && (bLocalExt_bSpdFrntWhl != 0) )
   {
      VEMS_vidSET(Ctrl_FRE_30D, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_FRE_30D, 0);
   }

   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bASRESPCf != 0) )
   {
      VEMS_vidSET(Ctrl_CDS_34D, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_CDS_34D, 0);
   }

   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bASRESPCf != 0)
      && (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_rSlopStab, 1);
      VEMS_vidSET(Ctrl_stHillAsi, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_rSlopStab, 0);
      VEMS_vidSET(Ctrl_stHillAsi, 0);
   }

   if (  (bLocalExt_bABSCf != 0)
      || (bLocalExt_bASRESPCf != 0) )
   {
      VEMS_vidSET(Ctrl_ABR_38D, 1);
      VEMS_vidSET(Ctrl_FRE_3CD, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_ABR_38D, 0);
      VEMS_vidSET(Ctrl_FRE_3CD, 0);
   }

   if (  (bLocalExt_bSTTCf != 0)
      && (bLocalExt_bASRESPCf != 0) )
   {
      VEMS_vidSET(Ctrl_bHillAsiRdyEngStop, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bHillAsiRdyEngStop, 0);
   }

   if (  (bLocalExt_bASRESPCf != 0)
      && (bLocalExt_bEasyMoveCf != 0) )
   {
      VEMS_vidSET(Ctrl_EASY_MOVE_3AD, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_EASY_MOVE_3AD, 0);
   }

   if (bLocalExt_bABSCf != 0)
   {
      VEMS_vidSET(Ctrl_ABR_44D, 1);
      VEMS_vidSET(Ctrl_ABR_50D, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_ABR_44D, 0);
      VEMS_vidSET(Ctrl_ABR_50D, 0);
   }

   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bSpdFrntWhl != 0)
      && (bLocalExt_bBrkMainInfoCf != 0) )
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrssMes, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrssMes, 0);
   }

   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bSpdFrntWhl != 0)
      && (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_pBrkMCT, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_pBrkMCT, 0);
   }

   if (  (bLocalExt_bEasyMoveCf != 0)
      && (bLocalExt_bSTTCf == 0)
      && (u8LocalExt_stGBxCf ==0)
      && (bLocalExt_bArchiCf == 0))
   {
      VEMS_vidSET(Ctrl_rCluPCAN, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_rCluPCAN, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBrkUCFrame2                                     */
/* !Description :  Each frame sent or received by the Brake control unit are  */
/*                 activated by a control flow, according the vehicle         */
/*                 configuration.                                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_003.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input boolean Ext_bEasyMoveCf;                                            */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bBrkMainInfoCf;                                         */
/*  input boolean Ext_bBrkDiagRelbCf;                                         */
/*  input uint8 Ext_stStrtRstrtDevCf;                                         */
/*  input boolean Ctrl_stBrkIp_C;                                             */
/*  output boolean Ctrl_stEngRStrtInh;                                        */
/*  output boolean Ctrl_bEngRStrtReqSTT;                                      */
/*  output boolean Ctrl_bDrvAvl;                                              */
/*  output boolean Ctrl_stBrkIp;                                              */
/*  output boolean Ctrl_stBrkIp_C;                                            */
/*  output boolean Ctrl_ctClcProc50D;                                         */
/*  output boolean Ctrl_noCks50D;                                             */
/*  output boolean Ctrl_bMainBrkPedPrssHSCha;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBrkUCFrame2(void)
{
   boolean bLocalExt_bABSCf;
   boolean bLocalExt_bSTTCf;
   boolean bLocalExt_bEasyMoveCf;
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bBrkDiagRelbCf;
   boolean bLocalExt_bBrkMainInfoCf;
   uint8   u8LocalExt_stStrtRstrtDevCf;


   VEMS_vidGET(Ext_bABSCf, bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_bEasyMoveCf, bLocalExt_bEasyMoveCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_bBrkMainInfoCf, bLocalExt_bBrkMainInfoCf);
   VEMS_vidGET(Ext_bBrkDiagRelbCf, bLocalExt_bBrkDiagRelbCf);
   VEMS_vidGET(Ext_stStrtRstrtDevCf, u8LocalExt_stStrtRstrtDevCf);

   if (  (u8LocalExt_stStrtRstrtDevCf == STTD_PRESENT)
      && (bLocalExt_bEasyMoveCf != 0))
   {
      VEMS_vidSET(Ctrl_stEngRStrtInh, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_stEngRStrtInh, 0);
   }
   if (bLocalExt_bSTTCf != 0)
   {
      VEMS_vidSET(Ctrl_bEngRStrtReqSTT, 1);
      VEMS_vidSET(Ctrl_bDrvAvl, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bEngRStrtReqSTT, 0);
      VEMS_vidSET(Ctrl_bDrvAvl, 0);
   }

   VEMS_vidSET(Ctrl_stBrkIp, Ctrl_stBrkIp_C);
   if (  (bLocalExt_bArchiCf != 0)
      && (bLocalExt_bABSCf != 0))
   {
      VEMS_vidSET(Ctrl_ctClcProc50D, 1);
      VEMS_vidSET(Ctrl_noCks50D, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_ctClcProc50D, 0);
      VEMS_vidSET(Ctrl_noCks50D, 0);
   }

   if (  (bLocalExt_bBrkDiagRelbCf != 0)
      || (bLocalExt_bBrkMainInfoCf != 0))
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrssHSCha, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrssHSCha, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidGearBoxFrame                                    */
/* !Description :  According to the variant coding of the vehicle, the Gear   */
/*                 Box frames are activated or not.                           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_004.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  output boolean Ctrl_STT_BV_329;                                           */
/*  output boolean Ctrl_tqCnsATRStrt;                                         */
/*  output boolean Ctrl_stPosATLevPNCAN;                                      */
/*  output boolean Ctrl_V2_BVMP_349;                                          */
/*  output boolean Ctrl_idxPtSptBVMP;                                         */
/*  output boolean Ctrl_bEngCutReq;                                           */
/*  output boolean Ctrl_posnAMTLev;                                           */
/*  output boolean Ctrl_V2_BVA_349;                                           */
/*  output boolean Ctrl_tqLoss;                                               */
/*  output boolean Ctrl_rCnvTq;                                               */
/*  output boolean Ctrl_idxPtSptBVA;                                          */
/*  output boolean Ctrl_bLiMILReqGUS;                                         */
/*  output boolean Ctrl_tqCnvExtd;                                            */
/*  output boolean Ctrl_nTrb;                                                 */
/*  output boolean Ctrl_V2_BV_3C9;                                            */
/*  output boolean Ctrl_V2_BV_489;                                            */
/*  output boolean Ctrl_Acq_bNeut;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidGearBoxFrame(void)
{
   boolean bLocalExt_bSTTCf;
   uint8   u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (  (  (u8LocalExt_stGBxCf == 1)
         || (u8LocalExt_stGBxCf == 2) )
      && (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_STT_BV_329, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_STT_BV_329, 0);
   }

   if (  (u8LocalExt_stGBxCf == 1)
      && (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_tqCnsATRStrt, 1);
      VEMS_vidSET(Ctrl_stPosATLevPNCAN, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_tqCnsATRStrt, 0);
      VEMS_vidSET(Ctrl_stPosATLevPNCAN, 0);
   }

   if (u8LocalExt_stGBxCf == 2)
   {
      VEMS_vidSET(Ctrl_V2_BVMP_349, 1);
      VEMS_vidSET(Ctrl_idxPtSptBVMP, 1);
      VEMS_vidSET(Ctrl_bEngCutReq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_V2_BVMP_349, 0);
      VEMS_vidSET(Ctrl_idxPtSptBVMP, 0);
      VEMS_vidSET(Ctrl_bEngCutReq, 0);
   }

   if (  (u8LocalExt_stGBxCf == 2)
      && (bLocalExt_bSTTCf != 0) )
   {
      VEMS_vidSET(Ctrl_posnAMTLev, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_posnAMTLev, 0);
   }

   if (u8LocalExt_stGBxCf == 1)
   {
      VEMS_vidSET(Ctrl_V2_BVA_349, 1);
      VEMS_vidSET(Ctrl_tqLoss, 1);
      VEMS_vidSET(Ctrl_rCnvTq, 1);
      VEMS_vidSET(Ctrl_idxPtSptBVA, 1);
      VEMS_vidSET(Ctrl_bLiMILReqGUS, 1);
      VEMS_vidSET(Ctrl_tqCnvExtd, 1);
      VEMS_vidSET(Ctrl_nTrb, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_V2_BVA_349, 0);
      VEMS_vidSET(Ctrl_tqLoss, 0);
      VEMS_vidSET(Ctrl_rCnvTq, 0);
      VEMS_vidSET(Ctrl_idxPtSptBVA, 0);
      VEMS_vidSET(Ctrl_bLiMILReqGUS, 0);
      VEMS_vidSET(Ctrl_tqCnvExtd, 0);
      VEMS_vidSET(Ctrl_nTrb, 0);
   }

   if (  (u8LocalExt_stGBxCf == 1)
      || (u8LocalExt_stGBxCf == 2) )
   {
      VEMS_vidSET(Ctrl_V2_BV_3C9, 1);
      VEMS_vidSET(Ctrl_V2_BV_489, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_V2_BV_3C9, 0);
      VEMS_vidSET(Ctrl_V2_BV_489, 0);
   }

   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bSTTCf != 0))
   {
      VEMS_vidSET(Ctrl_Acq_bNeut, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_Acq_bNeut, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBSIFrame                                        */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the BSI are activated or not.          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_005.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bBrkMainInfoCf;                                         */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint8 Ext_stCabHeatCf;                                              */
/*  input boolean Ctrl_BSI_412_C;                                             */
/*  input boolean Ctrl_CMM_488_C;                                             */
/*  input boolean Ctrl_BSI_4F2_C;                                             */
/*  input boolean Ctrl_CLIM_50E_C;                                            */
/*  input boolean Ctrl_BSI_592_C;                                             */
/*  input boolean Ctrl_BSI_432_C;                                             */
/*  input boolean Ctrl_BSI_612_C;                                             */
/*  input boolean Ctrl_IS_VIN_VDS_BSI_492_C;                                  */
/*  input boolean Ctrl_IS_VIN_VIS_BSI_4B2_C;                                  */
/*  input boolean Ctrl_IS_VIN_WMI_BSI_4D2_C;                                  */
/*  output boolean Ctrl_BSI_412;                                              */
/*  output boolean Ctrl_BSI_412_C;                                            */
/*  output boolean Ctrl_CMM_488;                                              */
/*  output boolean Ctrl_CMM_488_C;                                            */
/*  output boolean Ctrl_BSI_4F2;                                              */
/*  output boolean Ctrl_BSI_4F2_C;                                            */
/*  output boolean Ctrl_CLIM_50E;                                             */
/*  output boolean Ctrl_CLIM_50E_C;                                           */
/*  output boolean Ctrl_BSI_592;                                              */
/*  output boolean Ctrl_BSI_592_C;                                            */
/*  output boolean Ctrl_BSI_432;                                              */
/*  output boolean Ctrl_BSI_432_C;                                            */
/*  output boolean Ctrl_BSI_612;                                              */
/*  output boolean Ctrl_BSI_612_C;                                            */
/*  output boolean Ctrl_VDS_BSI_492;                                          */
/*  output boolean Ctrl_IS_VIN_VDS_BSI_492_C;                                 */
/*  output boolean Ctrl_VIS_BSI_4B2;                                          */
/*  output boolean Ctrl_IS_VIN_VIS_BSI_4B2_C;                                 */
/*  output boolean Ctrl_WMI_BSI_4D2;                                          */
/*  output boolean Ctrl_IS_VIN_WMI_BSI_4D2_C;                                 */
/*  output boolean Ctrl_bMainBrkPedPrss;                                      */
/*  output boolean Ctrl_bMainBrkPedPrssHSVeh;                                 */
/*  output boolean Ctrl_bHeatReq;                                             */
/*  output boolean Ctrl_stAdHeat;                                             */
/*  output boolean Ctrl_bTypStrt;                                             */
/*  output boolean Ctrl_V2_BSI_552;                                           */
/*  output boolean Ctrl_NEW_JDD_55F;                                          */
/*  output boolean Ctrl_BSI_792;                                              */
/*  output boolean Ctrl_bAcvSta;                                              */
/*  output boolean Ctrl_noJDD;                                                */
/*  output boolean Ctrl_bWkuMainSev;                                          */
/*  output boolean Ctrl_stNetwEl;                                             */
/*  output boolean Ctrl_CONTEXTE_1_5B2;                                       */
/*  output boolean Ctrl_bAcv_stVehCf;                                         */
/*  output boolean Ctrl_JDD_CAN_BSI_772;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBSIFrame(void)
{
   boolean bLocalExt_bBrkMainInfoCf;
   boolean bLocalExt_bArchiCf;
   uint8   u8LocalExt_stCabHeatCf;


   VEMS_vidGET(Ext_bBrkMainInfoCf, bLocalExt_bBrkMainInfoCf);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(Ext_stCabHeatCf, u8LocalExt_stCabHeatCf);

   VEMS_vidSET(Ctrl_BSI_412, Ctrl_BSI_412_C);
   VEMS_vidSET(Ctrl_CMM_488, Ctrl_CMM_488_C);
   VEMS_vidSET(Ctrl_BSI_4F2, Ctrl_BSI_4F2_C);
   VEMS_vidSET(Ctrl_CLIM_50E, Ctrl_CLIM_50E_C);
   VEMS_vidSET(Ctrl_BSI_592, Ctrl_BSI_592_C);
   VEMS_vidSET(Ctrl_BSI_432, Ctrl_BSI_432_C);
   VEMS_vidSET(Ctrl_BSI_612, Ctrl_BSI_612_C);
   VEMS_vidSET(Ctrl_VDS_BSI_492, Ctrl_IS_VIN_VDS_BSI_492_C);
   VEMS_vidSET(Ctrl_VIS_BSI_4B2, Ctrl_IS_VIN_VIS_BSI_4B2_C);
   VEMS_vidSET(Ctrl_WMI_BSI_4D2, Ctrl_IS_VIN_WMI_BSI_4D2_C);

   if (bLocalExt_bBrkMainInfoCf == 0)
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrss, 1);
      VEMS_vidSET(Ctrl_bMainBrkPedPrssHSVeh, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bMainBrkPedPrss, 0);
      VEMS_vidSET(Ctrl_bMainBrkPedPrssHSVeh, 0);
   }

   if (  (u8LocalExt_stCabHeatCf == 2)
      || (u8LocalExt_stCabHeatCf == 3)
      || (u8LocalExt_stCabHeatCf == 4)
      || (u8LocalExt_stCabHeatCf == 6) )
   {
      VEMS_vidSET(Ctrl_bHeatReq, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bHeatReq, 0);
   }

   if (  (u8LocalExt_stCabHeatCf != 0)
      && (bLocalExt_bArchiCf == 0) )
   {
      VEMS_vidSET(Ctrl_stAdHeat, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_stAdHeat, 0);
   }

   if (bLocalExt_bArchiCf != 0)
   {
      VEMS_vidSET(Ctrl_bTypStrt, 1);
      VEMS_vidSET(Ctrl_V2_BSI_552, 1);
      VEMS_vidSET(Ctrl_NEW_JDD_55F, 1);
      VEMS_vidSET(Ctrl_BSI_792, 1);
      VEMS_vidSET(Ctrl_bAcvSta, 1);
      VEMS_vidSET(Ctrl_noJDD, 1);
      VEMS_vidSET(Ctrl_bWkuMainSev, 1);
      VEMS_vidSET(Ctrl_stNetwEl, 1);
      VEMS_vidSET(Ctrl_CONTEXTE_1_5B2, 1);
      VEMS_vidSET(Ctrl_bAcv_stVehCf, 1);
      VEMS_vidSET(Ctrl_JDD_CAN_BSI_772, 0);
   }
   else
   {
      VEMS_vidSET(Ctrl_bTypStrt, 0);
      VEMS_vidSET(Ctrl_V2_BSI_552, 0);
      VEMS_vidSET(Ctrl_NEW_JDD_55F, 0);
      VEMS_vidSET(Ctrl_BSI_792, 0);
      VEMS_vidSET(Ctrl_bAcvSta, 0);
      VEMS_vidSET(Ctrl_noJDD, 0);
      VEMS_vidSET(Ctrl_bWkuMainSev, 0);
      VEMS_vidSET(Ctrl_stNetwEl, 0);
      VEMS_vidSET(Ctrl_CONTEXTE_1_5B2, 0);
      VEMS_vidSET(Ctrl_bAcv_stVehCf, 0);
      VEMS_vidSET(Ctrl_JDD_CAN_BSI_772, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CTRLCFG_vidBSIFrame2                                       */
/* !Description :  According to the variant coding of the vehicle, the frames */
/*                 sent or received by the BSI are activated or not.          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_R_10_03182_005.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDVSRegCf;                                               */
/*  input boolean Ext_bVSLimCf;                                               */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input uint8 Ext_stElEMgtCf;                                               */
/*  output boolean Ctrl_bVSCtlDft;                                            */
/*  output boolean Ctrl_noCks50E;                                             */
/*  output boolean Ctrl_spdVehVSCtlReq;                                       */
/*  output boolean Ctrl_bVSRegDVSRegReq;                                      */
/*  output boolean Ctrl_stVSCtlReq;                                           */
/*  output boolean Ctrl_bVSLimReq;                                            */
/*  output boolean Ctrl_stVSCtl;                                              */
/*  output boolean Ctrl_ctBSIFrame;                                           */
/*  output boolean Ctrl_rBattSoC;                                             */
/*  output boolean Ctrl_stBattSoC;                                            */
/*  output boolean Ctrl_noIncCurBattMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CTRLCFG_vidBSIFrame2(void)
{
   boolean bLocalExt_bVSLimCf;
   boolean bLocalExt_bSTTCf;
   uint8   u8LocalExt_stElEMgtCf;
   uint8   u8LocalExt_stDVSRegCf;


   VEMS_vidGET(Ext_stDVSRegCf, u8LocalExt_stDVSRegCf);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);
   VEMS_vidGET(Ext_bSTTCf, bLocalExt_bSTTCf);
   VEMS_vidGET(Ext_stElEMgtCf, u8LocalExt_stElEMgtCf);

   if (  (u8LocalExt_stDVSRegCf == 1)
      || (bLocalExt_bVSLimCf != 0) )
   {
      VEMS_vidSET(Ctrl_bVSCtlDft, 1);
      VEMS_vidSET(Ctrl_noCks50E, 1);
      VEMS_vidSET(Ctrl_spdVehVSCtlReq, 1);
      VEMS_vidSET(Ctrl_bVSRegDVSRegReq, 1);
      VEMS_vidSET(Ctrl_stVSCtlReq, 1);
      VEMS_vidSET(Ctrl_bVSLimReq, 1);
      VEMS_vidSET(Ctrl_stVSCtl, 1);
      VEMS_vidSET(Ctrl_ctBSIFrame, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_bVSCtlDft, 0);
      VEMS_vidSET(Ctrl_noCks50E, 0);
      VEMS_vidSET(Ctrl_spdVehVSCtlReq, 0);
      VEMS_vidSET(Ctrl_bVSRegDVSRegReq, 0);
      VEMS_vidSET(Ctrl_stVSCtlReq, 0);
      VEMS_vidSET(Ctrl_bVSLimReq, 0);
      VEMS_vidSET(Ctrl_stVSCtl, 0);
      VEMS_vidSET(Ctrl_ctBSIFrame, 0);
   }

   if (  (bLocalExt_bSTTCf != 0)
      || (u8LocalExt_stElEMgtCf == 5) )
   {
      VEMS_vidSET(Ctrl_rBattSoC, 1);
      VEMS_vidSET(Ctrl_stBattSoC, 1);
      VEMS_vidSET(Ctrl_noIncCurBattMes, 1);
   }
   else
   {
      VEMS_vidSET(Ctrl_rBattSoC, 0);
      VEMS_vidSET(Ctrl_stBattSoC, 0);
      VEMS_vidSET(Ctrl_noIncCurBattMes, 0);
   }
}
/*------------------------------- end of file --------------------------------*/