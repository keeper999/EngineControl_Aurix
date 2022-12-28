/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXENDSTOP                                         */
/* !Description     : VLVACTEXENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTEXENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'échappement .                                         */
/*                                                                            */
/* !File            : VLVACTEXENDSTOP_FCT1.C                                  */
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
/*   1 / VLVACTEXENDSTOP_vidInitOutput                                        */
/*   2 / VLVACTEXENDSTOP_vidInitFailure                                       */
/*   3 / VLVACTEXENDSTOP_vidOffsetsReset                                      */
/*   4 / VLVACTEXENDSTOP_vidLearningReset                                     */
/*   5 / VLVACTEXENDSTOP_vidLstLrnTmpCntr                                     */
/*   6 / VLVACTEXENDSTOP_vidReset                                             */
/*   7 / VLVACTEXENDSTOP_vidExtAllowLrng                                      */
/*   8 / VLVACTEXENDSTOP_vidExtAllowLearn                                     */
/*   9 / VLVACTEXENDSTOP_vidExOffReset                                        */
/*   10 / VLVACTEXENDSTOP_vidInitDiagSrv                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5885665 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXENDSTOP/VLVACTE$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXENDSTOP.h"
#include "VLVACTEXENDSTOP_L.h"
#include "VLVACTEXENDSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidInitOutput                              */
/* !Description :  Initialisation des sorties au reset.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input boolean VlvAct_bExOfsFrstLrn_eep;                                   */
/*  input boolean VlvAct_bExOfsFrstLrnWouDft_eep;                             */
/*  input uint8 Ext_stAgCmExFrstAdapt_eep;                                    */
/*  input uint16 Vcpe_cam_offsets_eep[4];                                     */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output boolean Vta_exhaust_allow_learning;                                */
/*  output boolean VLVACTEXENDSTOP_bOffLearnPrev;                             */
/*  output boolean VLVACTEXENDSTOP_bMotSyncPrev;                              */
/*  output boolean VLVACTEXENDSTOP_bIni2ndTimerPrev;                          */
/*  output boolean VLVACTEXENDSTOP_bExtAllowLng;                              */
/*  output boolean VLVACTEXENDSTOP_bTimeOut1;                                 */
/*  output boolean VLVACTEXENDSTOP_bTimeOut2;                                 */
/*  output uint16 VLVACTEXENDSTOP_u16Timer1;                                  */
/*  output uint16 VLVACTEXENDSTOP_u16Timer2;                                  */
/*  output boolean VLVACTEXENDSTOP_bExhaustOffPrev;                           */
/*  output uint32 VLVACTEXENDSTOP_u32FiltreCamMem0;                           */
/*  output uint32 VLVACTEXENDSTOP_u32FiltreCamMem1;                           */
/*  output uint32 VLVACTEXENDSTOP_u32FiltreCamMem2;                           */
/*  output uint32 VLVACTEXENDSTOP_u32FiltreCamMem3;                           */
/*  output uint16 Vcpe_cam_offsets[4];                                        */
/*  output boolean VlvAct_bExOfsFrstLrn;                                      */
/*  output boolean VlvAct_bExOfsFrstLrnWouDft;                                */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*  output boolean VlvAct_bExFrstClnAuth;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidInitOutput(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn_eep;
   boolean bLocalVlvAct_bExOfsFrstLrWD_eep;
   uint8   u8LocalExt_stAgCmExFrstAdapt_eep;
   uint8   u8LocalInd;
   uint16  u16Local;


   VEMS_vidSET(Vcpe_cam_offsets_are_learned, 0);
   VEMS_vidSET(Vta_exhaust_allow_learning, 0);
   VLVACTEXENDSTOP_bOffLearnPrev = 0;
   VLVACTEXENDSTOP_bMotSyncPrev = 0;
   VLVACTEXENDSTOP_bIni2ndTimerPrev = 0;
   VLVACTEXENDSTOP_bExtAllowLng = 0;
   VLVACTEXENDSTOP_bTimeOut1 = 0;
   VLVACTEXENDSTOP_bTimeOut2 = 0;
   VLVACTEXENDSTOP_u16Timer1 = 0;
   VLVACTEXENDSTOP_u16Timer2 = 0;
   VLVACTEXENDSTOP_bExhaustOffPrev = 0;
   VLVACTEXENDSTOP_u32FiltreCamMem0 = 0;
   VLVACTEXENDSTOP_u32FiltreCamMem1 = 0;
   VLVACTEXENDSTOP_u32FiltreCamMem2 = 0;
   VLVACTEXENDSTOP_u32FiltreCamMem3 = 0;
   VEMS_vidGET(VlvAct_bExOfsFrstLrn_eep, bLocalVlvAct_bExOfsFrstLrn_eep);
   VEMS_vidGET(VlvAct_bExOfsFrstLrnWouDft_eep, bLocalVlvAct_bExOfsFrstLrWD_eep);
   VEMS_vidGET(Ext_stAgCmExFrstAdapt_eep, u8LocalExt_stAgCmExFrstAdapt_eep);
   for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
   {
      VEMS_vidGET1DArrayElement(Vcpe_cam_offsets_eep,u8LocalInd,u16Local);
      u16Local = (uint16)MATHSRV_udtMIN(u16Local,7679);
      VEMS_vidSET1DArrayElement(Vcpe_cam_offsets,u8LocalInd,u16Local);
   }
   VEMS_vidSET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn_eep);
   VEMS_vidSET(VlvAct_bExOfsFrstLrnWouDft, bLocalVlvAct_bExOfsFrstLrWD_eep);
   VEMS_vidSET(Ext_stAgCmExFrstAdapt, u8LocalExt_stAgCmExFrstAdapt_eep);
   VEMS_vidSET(VlvAct_bExFrstClnAuth, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidInitFailure                             */
/* !Description :  Les pannes VVT présentes sont initialisées sur clé off-on  */
/*                 afin de ne pas rester figées entre le clé on et le         */
/*                 démarrage du moteur.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Vta_exhaust_cam_offsets_manu_inh;                           */
/*  output boolean VlvAct_bDgoEndStopOldVlvActEx;                             */
/*  output boolean VlvAct_bDgoLrnEndStopVlvActEx;                             */
/*  output boolean VlvAct_bExOfsClcnInh;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidInitFailure(void)
{
   VlvAct_bDgoEndStopOldVlvActEx = 0;
   VlvAct_bDgoLrnEndStopVlvActEx = 0;
   if (Vta_exhaust_cam_offsets_manu_inh != 0)
   {
      VEMS_vidSET(VlvAct_bExOfsClcnInh, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bExOfsClcnInh, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidOffsetsReset                            */
/* !Description :  Possibilités pour lancer un apprentissage des offsets en   */
/*                 cours d'utilisation                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTEXENDSTOP_vidLearningReset();                      */
/*  input uint8 CoVSCtl_stAccP;                                               */
/*  input boolean VlvAct_bExMngLrnStEna;                                      */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input boolean VlvAct_bExLrnEndStopLimEna_C;                               */
/*  input uint16 VlvAct_CtExLrnEndStopRelzd;                                  */
/*  input uint16 VlvAct_CtExLrnEndStopRelzdThd_C;                             */
/*  input uint16 VlvAct_ExMngStCmd;                                           */
/*  input uint16 VlvAct_ExCmdMinLrnValThd_C;                                  */
/*  input boolean VlvAct_bExRunLrnAuth;                                       */
/*  input boolean Vta_exhaust_force_off_learning;                             */
/*  input uint16 Vta_exhaust_learn_tempo;                                     */
/*  input boolean Vta_exhaust_allow_delay;                                    */
/*  input boolean Vta_exhaust_run_learning_dsb;                               */
/*  input uint16 VlvAct_agExMesLrnLim_C;                                      */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input boolean VLVACTEXENDSTOP_bOffLearnPrev;                              */
/*  output boolean VlvAct_bExRunLrnAuth;                                      */
/*  output boolean Vta_exhaust_allow_delay;                                   */
/*  output boolean VLVACTEXENDSTOP_bOffLearnPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidOffsetsReset(void)
{
   boolean             bLocalRisingEdge;
   boolean             bLocalInhVlvActExEndStopLrnRst;
   boolean             bLocalVlvAct_bExMngLrnStEna;
   boolean             bLocalVcpeCamOffsetsAreLearned;
   boolean             bLocalcomp;
   uint8               u8LocalCoVSCtl_stAccP;
   uint16              u16LocalVlvAct_ExMngStCmd;
   uint16              u16LocalVxx_rel_ex_vvt_mes;
   GDFRM_tenuGDUState  LocalstDgoORngShiftVlvActEx;


   LocalstDgoORngShiftVlvActEx = GDGAR_tenuGetStDgo(GD_DFT_ORNGSHIFTVLVACTEX);
   VEMS_vidGET(CoVSCtl_stAccP, u8LocalCoVSCtl_stAccP);
   VEMS_vidGET(VlvAct_bExMngLrnStEna, bLocalVlvAct_bExMngLrnStEna);
   VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);


   if (  (VlvAct_bExLrnEndStopLimEna_C != 0)
         && (VlvAct_CtExLrnEndStopRelzd > VlvAct_CtExLrnEndStopRelzdThd_C))
   {
      bLocalcomp = 0;
   }
   else
   {
      bLocalcomp = 1;
   }
   if (  (u8LocalCoVSCtl_stAccP == 0)
      && (bLocalcomp != 0)
      && (bLocalVlvAct_bExMngLrnStEna !=0))
   {
      VlvAct_bExRunLrnAuth = 1;
   }
   else
   {
      VlvAct_bExRunLrnAuth = 0;
   }
   VEMS_vidGET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   if (u16LocalVlvAct_ExMngStCmd <= VlvAct_ExCmdMinLrnValThd_C)
   {
      Vta_exhaust_allow_delay = 1;
   }
   else
   {
      Vta_exhaust_allow_delay = 0;
   }
   if (  (VlvAct_bExRunLrnAuth != 0)
      && (  (Vta_exhaust_force_off_learning != 0)
         || (  (Vta_exhaust_learn_tempo == 0)
            && (Vta_exhaust_allow_delay != 0)
            && (Vta_exhaust_run_learning_dsb == 0)
            && (u16LocalVxx_rel_ex_vvt_mes <= VlvAct_agExMesLrnLim_C))))
   {
      bLocalRisingEdge = 1;
   }
   else
   {
      bLocalRisingEdge = 0;
   }

   bLocalInhVlvActExEndStopLrnRst =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXENDSTOPLRNRST);
   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpeCamOffsetsAreLearned);
   if (  (  (LocalstDgoORngShiftVlvActEx == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoORngShiftVlvActEx == GDU_ETAT_FUGITIF)
         || (LocalstDgoORngShiftVlvActEx == GDU_ETAT_ABSENT))
      && (bLocalInhVlvActExEndStopLrnRst == 0)
      && (bLocalVcpeCamOffsetsAreLearned != 0)
      && (u16LocalVlvAct_ExMngStCmd <= VlvAct_ExCmdMinLrnValThd_C))
   {
      if (  (bLocalRisingEdge != 0)
         && (VLVACTEXENDSTOP_bOffLearnPrev == 0))
      {
         VLVACTEXENDSTOP_vidLearningReset();
      }
   }

   VLVACTEXENDSTOP_bOffLearnPrev = bLocalRisingEdge;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidLearningReset                           */
/* !Description :  apprentissage des offsets en cours d'utilisation           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output uint8 Vcpe_learn_zero_counter;                                     */
/*  output uint8 VlvAct_CtOfsExConf;                                          */
/*  output uint32 VlvAct_AgOfsExValAdd[4];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidLearningReset(void)
{
   VEMS_vidSET(Vcpe_cam_offsets_are_learned, 0);
   Vcpe_learn_zero_counter = 0;
   VlvAct_CtOfsExConf = 0;
   VlvAct_AgOfsExValAdd[0] = 0;
   VlvAct_AgOfsExValAdd[1] = 0;
   VlvAct_AgOfsExValAdd[2] = 0;
   VlvAct_AgOfsExValAdd[3] = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidLstLrnTmpCntr                           */
/* !Description :  On décrémente la temporisation depuis le dernier           */
/*                 apprentissage.                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Vta_exhaust_learn_tempo;                                     */
/*  output uint16 Vta_exhaust_learn_tempo;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidLstLrnTmpCntr(void)
{
   sint32 s32LocalTemp;


   s32LocalTemp = (sint32)(Vta_exhaust_learn_tempo - 1);
   Vta_exhaust_learn_tempo = (uint16)MATHSRV_udtCLAMP(s32LocalTemp, 0, 16383);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidReset                                   */
/* !Description :  Vcpe_cam_offsets: angles de référence ou offsets appris    */
/*                 précédemment --> offsets de position.                      */
/*                 Vcpe_cam_offsets_are_learned: flag fin d’apprentissage     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_003.01                                     */
/*                 VEMS_R_08_06268_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint16 Vta_exhaust_learn_tempo;                                     */
/*  input uint16 Vta_exhaust_learn_delay;                                     */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean Vta_exhaust_cam_offsets_manu_inh;                           */
/*  input uint16 Vta_exhaust_reference_angle[4];                              */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  output uint16 Vta_exhaust_learn_tempo;                                    */
/*  output uint16 Vta_exhaust_cam_off_mes[4];                                 */
/*  output uint16 Vta_exhaust_cam_old_off_eep[4];                             */
/*  output uint16 Vcpe_cam_offsets[4];                                        */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*  output uint8 VlvAct_CtOfsExConf;                                          */
/*  output uint8 Vcpe_learn_zero_counter;                                     */
/*  output boolean VlvAct_bExOfsLrnDone;                                      */
/*  output uint32 VlvAct_AgOfsExValAdd[4];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidReset(void)
{
   boolean bLocalVcpeCamOffsetsAreLearned;
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalInd;
   uint16  u16LocalVcpe_cam_offsets[VLVACTEXENDSTOP_u8OFFLENGTH];
   uint16  u16LocalVta_exhaust_learn_tempo;


   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u16LocalVta_exhaust_learn_tempo = Vta_exhaust_learn_tempo;
   }
   else
   {
      u16LocalVta_exhaust_learn_tempo = Vta_exhaust_learn_delay;
   }
   Vta_exhaust_learn_tempo =
      (uint16)MATHSRV_udtMIN(u16LocalVta_exhaust_learn_tempo, 16383);

   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);

   if (Vta_exhaust_cam_offsets_manu_inh != 0)
   {
      bLocalVcpeCamOffsetsAreLearned = 1;
      for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
      {
         u16LocalVcpe_cam_offsets[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                   7679);
         Vta_exhaust_cam_off_mes[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                   7679);
         Vta_exhaust_cam_old_off_eep[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                   7679);
      }
      VEMS_vidSET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
   }
   else
   {
      if (bLocalVlvAct_bExOfsFrstLrn != 0)
      {
         bLocalVcpeCamOffsetsAreLearned = 1;
         VEMS_vidGET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
         for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
         {
            u16LocalVcpe_cam_offsets[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(u16LocalVcpe_cam_offsets[u8LocalInd],
                                      7679);
            Vta_exhaust_cam_off_mes[u8LocalInd] =
               u16LocalVcpe_cam_offsets[u8LocalInd];
            Vta_exhaust_cam_old_off_eep[u8LocalInd] =
               u16LocalVcpe_cam_offsets[u8LocalInd];
         }
         VEMS_vidSET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
      }
      else
      {
         bLocalVcpeCamOffsetsAreLearned = 0;
         for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
         {
            u16LocalVcpe_cam_offsets[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                      7679);
            Vta_exhaust_cam_off_mes[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                      7679);
            Vta_exhaust_cam_old_off_eep[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                      7679);
         }
         VEMS_vidSET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
      }
   }

   VEMS_vidSET(Vcpe_cam_offsets_are_learned, bLocalVcpeCamOffsetsAreLearned);

   if (bLocalVlvAct_bExOfsFrstLrn != 0)
   {
      VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_DONE);
   }
   else
   {
      VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_NOTDONE);
   }

   VlvAct_CtOfsExConf = 0;
   Vcpe_learn_zero_counter = 0;
   VlvAct_bExOfsLrnDone = 0;
   VlvAct_AgOfsExValAdd[0] = 0;
   VlvAct_AgOfsExValAdd[1] = 0;
   VlvAct_AgOfsExValAdd[2] = 0;
   VlvAct_AgOfsExValAdd[3] = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidExtAllowLrng                            */
/* !Description :  Condition pour commencer l'apprentissage des offsets après */
/*                 démarrage.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXENDSTOP_vidExtAllowLearn();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bExOfsClcnInh;                                       */
/*  input boolean VlvAct_bExOfsFrstLrnByp_C;                                  */
/*  input boolean VlvAct_bExOfsFrstLrnMan_C;                                  */
/*  input boolean VlvAct_bExOfsFrstLrnWouDftByp_C;                            */
/*  input boolean VlvAct_bExOfsFrstLrnWouDftMan_C;                            */
/*  output boolean VlvAct_bExOfsFrstLrn;                                      */
/*  output boolean VlvAct_bExOfsFrstLrnMan_C;                                 */
/*  output boolean VlvAct_bExOfsFrstLrnWouDft;                                */
/*  output boolean VlvAct_bExOfsFrstLrnWouDftMan_C;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidExtAllowLrng(void)
{
   boolean bLocalVlvAct_bExOfsClcnInh;


   VEMS_vidGET(VlvAct_bExOfsClcnInh, bLocalVlvAct_bExOfsClcnInh);
   if (bLocalVlvAct_bExOfsClcnInh == 0)
   {
      VLVACTEXENDSTOP_vidExtAllowLearn();
   }
   if (VlvAct_bExOfsFrstLrnByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bExOfsFrstLrn, VlvAct_bExOfsFrstLrnMan_C);
   }
   if (VlvAct_bExOfsFrstLrnWouDftByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bExOfsFrstLrnWouDft, VlvAct_bExOfsFrstLrnWouDftMan_C);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidExtAllowLearn                           */
/* !Description :  Ce bloc détermine quand peut commencer l'apprentissage des */
/*                 offsets après démarrage. Il y a trois conditions           */
/*                 calibrables: un seuil de régime, un délai après            */
/*                 synchronisation et un délai après que la consigne soit     */
/*                 nulle.                                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXENDSTOP_vidExOffReset();                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint16 VlvAct_ExMngStCmd;                                           */
/*  input boolean VLVACTEXENDSTOP_bMotSyncPrev;                               */
/*  input uint16 Kfvcpe_t_offset_learn_delay;                                 */
/*  input uint16 VLVACTEXENDSTOP_u16Timer1;                                   */
/*  input boolean VLVACTEXENDSTOP_bTimeOut1;                                  */
/*  input uint16 VlvAct_ExCmdMinLrnValThd_C;                                  */
/*  input boolean VLVACTEXENDSTOP_bIni2ndTimerPrev;                           */
/*  input uint16 Kfvcpe_t_zero_set_time;                                      */
/*  input uint16 VLVACTEXENDSTOP_u16Timer2;                                   */
/*  input uint8 Vta_exhaust_min_reg;                                          */
/*  input boolean Vta_exhaust_allow_learning;                                 */
/*  input boolean VlvAct_bExMngLrnStEna;                                      */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean VlvAct_bExLrnFrstOfsAuth;                                   */
/*  input boolean VLVACTEXENDSTOP_bExtAllowLng;                               */
/*  input boolean VLVACTEXENDSTOP_bTimeOut2;                                  */
/*  output uint16 VLVACTEXENDSTOP_u16Timer1;                                  */
/*  output boolean VLVACTEXENDSTOP_bTimeOut1;                                 */
/*  output boolean VLVACTEXENDSTOP_bMotSyncPrev;                              */
/*  output uint16 VLVACTEXENDSTOP_u16Timer2;                                  */
/*  output boolean VLVACTEXENDSTOP_bTimeOut2;                                 */
/*  output boolean VLVACTEXENDSTOP_bIni2ndTimerPrev;                          */
/*  output boolean VlvAct_bExFrstClnAuth;                                     */
/*  output boolean VLVACTEXENDSTOP_bExtAllowLng;                              */
/*  output boolean Vta_exhaust_allow_learning;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidExtAllowLearn(void)
{
   boolean bLocalInitSecondTimer;
   boolean bLocalMoteur_synchronise;
   boolean bLocalVtaExhaustAllowLearning;
   boolean bLocalVlvAct_bExMngLrnStEna;
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalVlvAct_bExLrnFrstOfsAuth;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalVlvAct_ExMngStCmd;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   if (  (bLocalMoteur_synchronise != 0)
      && (VLVACTEXENDSTOP_bMotSyncPrev == 0))
   {
      VLVACTEXENDSTOP_u16Timer1 =
         (uint16)MATHSRV_udtMIN(Kfvcpe_t_offset_learn_delay, 20000);

      if (VLVACTEXENDSTOP_u16Timer1 == 0)
      {
         VLVACTEXENDSTOP_bTimeOut1 = 1;
      }
      else
      {
         VLVACTEXENDSTOP_bTimeOut1 = 0;
      }
   }
   else
   {
      if (VLVACTEXENDSTOP_u16Timer1 > 0)
      {
         VLVACTEXENDSTOP_u16Timer1 = (uint16)(VLVACTEXENDSTOP_u16Timer1 - 1);
         if (VLVACTEXENDSTOP_u16Timer1 == 0)
         {
            VLVACTEXENDSTOP_bTimeOut1 = 1;
         }
         else
         {
            VLVACTEXENDSTOP_bTimeOut1 = 0;
         }
      }
   }
   VLVACTEXENDSTOP_bMotSyncPrev = bLocalMoteur_synchronise;

   if (  (VLVACTEXENDSTOP_bTimeOut1 != 0)
      && (u16LocalVlvAct_ExMngStCmd <= VlvAct_ExCmdMinLrnValThd_C))
   {
      bLocalInitSecondTimer = 1;
   }
   else
   {
      bLocalInitSecondTimer = 0;
   }
   if (  (bLocalInitSecondTimer != 0)
      && (VLVACTEXENDSTOP_bIni2ndTimerPrev == 0))
   {
      VLVACTEXENDSTOP_u16Timer2 = (uint16)MATHSRV_udtMIN(Kfvcpe_t_zero_set_time,
                                                         20000);

      if (VLVACTEXENDSTOP_u16Timer2 == 0)
      {
         VLVACTEXENDSTOP_bTimeOut2 = 1;
      }
      else
      {
         VLVACTEXENDSTOP_bTimeOut2 = 0;
      }
   }
   else
   {
      if (VLVACTEXENDSTOP_u16Timer2 > 0)
      {
         VLVACTEXENDSTOP_u16Timer2 = (uint16)(VLVACTEXENDSTOP_u16Timer2 - 1);
         if (VLVACTEXENDSTOP_u16Timer2 == 0)
         {
            VLVACTEXENDSTOP_bTimeOut2 = 1;
         }
         else
         {
            VLVACTEXENDSTOP_bTimeOut2 = 0;
         }
      }
   }
   VLVACTEXENDSTOP_bIni2ndTimerPrev = bLocalInitSecondTimer;
   VEMS_vidSET(VlvAct_bExFrstClnAuth, VLVACTEXENDSTOP_bTimeOut1);

   if (u16LocalExt_nEng > (uint16)(Vta_exhaust_min_reg * 32))
   {
      VLVACTEXENDSTOP_bExtAllowLng = 1;
   }

   VEMS_vidGET(Vta_exhaust_allow_learning, bLocalVtaExhaustAllowLearning);
   VEMS_vidGET(VlvAct_bExMngLrnStEna, bLocalVlvAct_bExMngLrnStEna);
   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidGET(VlvAct_bExLrnFrstOfsAuth, bLocalVlvAct_bExLrnFrstOfsAuth);
   if (  (VLVACTEXENDSTOP_bExtAllowLng != 0)
      && (bLocalInitSecondTimer !=0)
      && (VLVACTEXENDSTOP_bTimeOut2 != 0)
      && (  (  (bLocalVlvAct_bExOfsFrstLrn != 0)
            && (bLocalVlvAct_bExMngLrnStEna != 0))
         || (bLocalVlvAct_bExLrnFrstOfsAuth != 0)))
   {
      VEMS_vidSET(Vta_exhaust_allow_learning, 1);
      if (bLocalVtaExhaustAllowLearning == 0)
      {
         VLVACTEXENDSTOP_vidExOffReset();
      }
   }
   else
   {
      VEMS_vidSET(Vta_exhaust_allow_learning, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidExOffReset                              */
/* !Description :  exhaust offset reset.                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidExOffReset(void)
{
   boolean  bLocalCoPTSt_bRStrtSTT;


   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidSET(Vcpe_cam_offsets_are_learned, bLocalCoPTSt_bRStrtSTT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidInitDiagSrv                             */
/* !Description :  Ce bloc procède à l’initialisation des variables suivantes */
/*                 suite à une demande APV : - Valeur apprentissage butée     */
/*                 basse déphaseur AAC échappement - Etat apprentissage       */
/*                 déphaseur AAC échappement - Etat apprentissage roulage en  */
/*                 cours échappement                                          */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06255_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vta_exhaust_reference_angle[4];                              */
/*  output uint16 Vcpe_cam_offsets[4];                                        */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output st17 Ext_stAgCmExAdapt;                                            */
/*  output boolean VlvAct_bExOfsFrstLrn;                                      */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidInitDiagSrv(void)
{
   uint8  u8LocalInd;
   uint16 u16LocalVcpe_cam_offsets[VLVACTEXENDSTOP_u8OFFLENGTH];


   for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
   {
      u16LocalVcpe_cam_offsets[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(Vta_exhaust_reference_angle[u8LocalInd],
                                7679);
   }
   VEMS_vidSET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
   VEMS_vidSET(Vcpe_cam_offsets_are_learned, 0);
   VEMS_vidSET(Ext_stAgCmExAdapt, VLVACT_ST_EXLRN_NOTDONE);
   VEMS_vidSET(VlvAct_bExOfsFrstLrn, 0);
   VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_NOTDONE);
}
/*--------------------------------- end of file ------------------------------*/