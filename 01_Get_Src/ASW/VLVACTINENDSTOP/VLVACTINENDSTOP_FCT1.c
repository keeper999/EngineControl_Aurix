/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINENDSTOP                                         */
/* !Description     : VLVACTINENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTINENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'admission .                                           */
/*                                                                            */
/* !File            : VLVACTINENDSTOP_FCT1.C                                  */
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
/*   1 / VLVACTINENDSTOP_vidInitOutput                                        */
/*   2 / VLVACTINENDSTOP_vidInitFailure                                       */
/*   3 / VLVACTINENDSTOP_vidOffsetsReset                                      */
/*   4 / VLVACTINENDSTOP_vidLearningReset                                     */
/*   5 / VLVACTINENDSTOP_vidLstLrnTmpCntr                                     */
/*   6 / VLVACTINENDSTOP_vidReset                                             */
/*   7 / VLVACTINENDSTOP_vidIntAllowLrng                                      */
/*   8 / VLVACTINENDSTOP_vidIntAllowLearn                                     */
/*   9 / VLVACTINENDSTOP_vidInOffReset                                        */
/*   10 / VLVACTINENDSTOP_vidInitDiagSrv                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5883893 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINENDSTOP/VLVACTI$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINENDSTOP.h"
#include "VLVACTINENDSTOP_L.h"
#include "VLVACTINENDSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidInitOutput                              */
/* !Description :  Initialisation des sorties au reset.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input boolean VlvAct_bInOfsFrstLrn_eep;                                   */
/*  input boolean VlvAct_bInOfsFrstLrnWouDft_eep;                             */
/*  input uint8 Ext_stAgCmInFrstAdapt_eep;                                    */
/*  input uint16 Vcpi_cam_offsets_eep[4];                                     */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output boolean Vta_intake_allow_learning;                                 */
/*  output boolean VLVACTINENDSTOP_bOffLearnPrev;                             */
/*  output boolean VLVACTINENDSTOP_bMotSyncPrev;                              */
/*  output boolean VLVACTINENDSTOP_bIni2ndTimerPrev;                          */
/*  output boolean VLVACTINENDSTOP_bIntAllowLng;                              */
/*  output boolean VLVACTINENDSTOP_bTimeOut1;                                 */
/*  output boolean VLVACTINENDSTOP_bTimeOut2;                                 */
/*  output uint16 VLVACTINENDSTOP_u16Timer1;                                  */
/*  output uint16 VLVACTINENDSTOP_u16Timer2;                                  */
/*  output boolean VLVACTINENDSTOP_bIntakeOffPrev;                            */
/*  output uint32 VLVACTINENDSTOP_u32FiltreCamMem0;                           */
/*  output uint32 VLVACTINENDSTOP_u32FiltreCamMem1;                           */
/*  output uint32 VLVACTINENDSTOP_u32FiltreCamMem2;                           */
/*  output uint32 VLVACTINENDSTOP_u32FiltreCamMem3;                           */
/*  output uint16 Vcpi_cam_offsets[4];                                        */
/*  output boolean VlvAct_bInOfsFrstLrn;                                      */
/*  output boolean VlvAct_bInOfsFrstLrnWouDft;                                */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*  output boolean VlvAct_bInFrstClnAuth;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidInitOutput(void)
{
   boolean bLocalVlvAct_bInOfsFrstLrn_eep;
   boolean bLocalVlvAct_bInOfsFrstLrWD_eep;
   uint8   u8LocalExt_stAgCmInFrstAdapt_eep;
   uint8   u8LocalInd;
   uint16  u16Local;


   VEMS_vidSET(Vcpi_cam_offsets_are_learned, 0);
   VEMS_vidSET(Vta_intake_allow_learning, 0);
   VLVACTINENDSTOP_bOffLearnPrev = 0;
   VLVACTINENDSTOP_bMotSyncPrev = 0;
   VLVACTINENDSTOP_bIni2ndTimerPrev = 0;
   VLVACTINENDSTOP_bIntAllowLng = 0;
   VLVACTINENDSTOP_bTimeOut1 = 0;
   VLVACTINENDSTOP_bTimeOut2 = 0;
   VLVACTINENDSTOP_u16Timer1 = 0;
   VLVACTINENDSTOP_u16Timer2 = 0;
   VLVACTINENDSTOP_bIntakeOffPrev = 0;
   VLVACTINENDSTOP_u32FiltreCamMem0 = 0;
   VLVACTINENDSTOP_u32FiltreCamMem1 = 0;
   VLVACTINENDSTOP_u32FiltreCamMem2 = 0;
   VLVACTINENDSTOP_u32FiltreCamMem3 = 0;
   VEMS_vidGET(VlvAct_bInOfsFrstLrn_eep, bLocalVlvAct_bInOfsFrstLrn_eep);
   VEMS_vidGET(VlvAct_bInOfsFrstLrnWouDft_eep, bLocalVlvAct_bInOfsFrstLrWD_eep);
   VEMS_vidGET(Ext_stAgCmInFrstAdapt_eep, u8LocalExt_stAgCmInFrstAdapt_eep);
   for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
   {
      VEMS_vidGET1DArrayElement(Vcpi_cam_offsets_eep,u8LocalInd,u16Local);
      u16Local = (uint16)MATHSRV_udtMIN(u16Local,7679);
      VEMS_vidSET1DArrayElement(Vcpi_cam_offsets,u8LocalInd,u16Local);
   }
   VEMS_vidSET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn_eep);
   VEMS_vidSET(VlvAct_bInOfsFrstLrnWouDft, bLocalVlvAct_bInOfsFrstLrWD_eep);
   VEMS_vidSET(Ext_stAgCmInFrstAdapt, u8LocalExt_stAgCmInFrstAdapt_eep);
   VEMS_vidSET(VlvAct_bInFrstClnAuth, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidInitFailure                             */
/* !Description :  Les pannes VVT présentes sont initialisées sur clé off-on  */
/*                 afin de ne pas rester figées entre le clé on et le         */
/*                 démarrage du moteur.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Vta_intake_cam_offsets_manu_inh;                            */
/*  output boolean VlvAct_bDgoEndStopOldVlvActIn;                             */
/*  output boolean VlvAct_bDgoLrnEndStopVlvActIn;                             */
/*  output boolean VlvAct_bInOfsClcnInh;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidInitFailure(void)
{
   VlvAct_bDgoEndStopOldVlvActIn = 0;
   VlvAct_bDgoLrnEndStopVlvActIn = 0;
   if (Vta_intake_cam_offsets_manu_inh != 0)
   {
      VEMS_vidSET(VlvAct_bInOfsClcnInh, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bInOfsClcnInh, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidOffsetsReset                            */
/* !Description :  Possibilités pour lancer un apprentissage des offsets en   */
/*                 cours d'utilisation                                        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTINENDSTOP_vidLearningReset();                      */
/*  input uint8 CoVSCtl_stAccP;                                               */
/*  input boolean VlvAct_bInMngLrnStEna;                                      */
/*  input boolean VlvAct_bInLrnEndStopLimEna_C;                               */
/*  input uint16 VlvAct_CtInLrnEndStopRelzd;                                  */
/*  input uint16 VlvAct_CtInLrnEndStopRelzdThd_C;                             */
/*  input uint16 VlvAct_InMngStCmd;                                           */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input uint16 VlvAct_InCmdMinLrnValThd_C;                                  */
/*  input boolean VlvAct_bInRunLrnAuth;                                       */
/*  input boolean Vta_intake_force_off_learning;                              */
/*  input uint16 Vta_intake_learn_tempo;                                      */
/*  input boolean Vta_intake_allow_delay;                                     */
/*  input boolean Vta_intake_run_learning_dsb;                                */
/*  input uint16 VlvAct_agInMesLrnLim_C;                                      */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input boolean VLVACTINENDSTOP_bOffLearnPrev;                              */
/*  output boolean VlvAct_bInRunLrnAuth;                                      */
/*  output boolean Vta_intake_allow_delay;                                    */
/*  output boolean VLVACTINENDSTOP_bOffLearnPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidOffsetsReset(void)
{
   boolean            bLocalRisingEdge;
   boolean            bLocalInhVlvActInEndStopLrnRst;
   boolean            bLocalVlvAct_bInMngLrnStEna ;
   boolean            bLocalVcpiCamOffsetsAreLearned;
   boolean            bLocalcomp;
   uint8              u8LocalCoVSCtl_stAccP;
   uint16             u16LocalVlvAct_InMngStCmd;
   uint16             u16LocalVxx_rel_in_vvt_mes;
   GDFRM_tenuGDUState LocalstDgoORngShiftVlvActIn;


   LocalstDgoORngShiftVlvActIn = GDGAR_tenuGetStDgo(GD_DFT_ORNGSHIFTVLVACTIN);
   VEMS_vidGET(CoVSCtl_stAccP, u8LocalCoVSCtl_stAccP);
   VEMS_vidGET(VlvAct_bInMngLrnStEna, bLocalVlvAct_bInMngLrnStEna);
   if (  (VlvAct_bInLrnEndStopLimEna_C != 0)
      && (VlvAct_CtInLrnEndStopRelzd > VlvAct_CtInLrnEndStopRelzdThd_C))
   {
      bLocalcomp = 0;
   }
   else
   {
      bLocalcomp = 1;
   }
   if (  (u8LocalCoVSCtl_stAccP == 0)
      && (bLocalcomp != 0)
      && (bLocalVlvAct_bInMngLrnStEna !=0))
   {
      VlvAct_bInRunLrnAuth = 1;
   }
   else
   {
      VlvAct_bInRunLrnAuth = 0;
   }
   VEMS_vidGET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);
   VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   if (u16LocalVlvAct_InMngStCmd <= VlvAct_InCmdMinLrnValThd_C)
   {
      Vta_intake_allow_delay = 1;
   }
   else
   {
      Vta_intake_allow_delay = 0;
   }
   if (  (VlvAct_bInRunLrnAuth != 0)
      && (  (Vta_intake_force_off_learning != 0)
         || (  (Vta_intake_learn_tempo == 0)
            && (Vta_intake_allow_delay != 0)
            && (Vta_intake_run_learning_dsb == 0)
            && (u16LocalVxx_rel_in_vvt_mes <= VlvAct_agInMesLrnLim_C))))
   {
      bLocalRisingEdge = 1;
   }
   else
   {
      bLocalRisingEdge = 0;
   }

   bLocalInhVlvActInEndStopLrnRst =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINENDSTOPLRNRST);
   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpiCamOffsetsAreLearned);
   if (  (  (LocalstDgoORngShiftVlvActIn == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoORngShiftVlvActIn == GDU_ETAT_FUGITIF)
         || (LocalstDgoORngShiftVlvActIn == GDU_ETAT_ABSENT))
      && (bLocalInhVlvActInEndStopLrnRst == 0)
      && (bLocalVcpiCamOffsetsAreLearned != 0)
      && (u16LocalVlvAct_InMngStCmd <= VlvAct_InCmdMinLrnValThd_C))
   {
      if (  (bLocalRisingEdge != 0)
         && (VLVACTINENDSTOP_bOffLearnPrev == 0))
      {
         VLVACTINENDSTOP_vidLearningReset();
      }
   }

   VLVACTINENDSTOP_bOffLearnPrev = bLocalRisingEdge;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidLearningReset                           */
/* !Description :  apprentissage des offsets en cours d'utilisation           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output uint8 Vcpi_learn_zero_counter;                                     */
/*  output uint8 VlvAct_CtOfsInConf;                                          */
/*  output uint32 VlvAct_AgOfsInValAdd[4];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidLearningReset(void)
{
   VEMS_vidSET(Vcpi_cam_offsets_are_learned, 0);
   Vcpi_learn_zero_counter = 0;
   VlvAct_CtOfsInConf = 0;
   VlvAct_AgOfsInValAdd[0] = 0;
   VlvAct_AgOfsInValAdd[1] = 0;
   VlvAct_AgOfsInValAdd[2] = 0;
   VlvAct_AgOfsInValAdd[3] = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidLstLrnTmpCntr                           */
/* !Description :  On décrémente la temporisation depuis le dernier           */
/*                 apprentissage.                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Vta_intake_learn_tempo;                                      */
/*  output uint16 Vta_intake_learn_tempo;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidLstLrnTmpCntr(void)
{
   sint32 s32LocalTemp;


   s32LocalTemp = (sint32)(Vta_intake_learn_tempo - 1);
   Vta_intake_learn_tempo = (uint16)MATHSRV_udtCLAMP(s32LocalTemp, 0, 16383);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidReset                                   */
/* !Description :  Vcpi_cam_offsets: angles de référence ou offsets appris    */
/*                 précédemment --> offsets de position.                      */
/*                 Vcpi_cam_offsets_are_learned: flag fin d’apprentissage     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_011.01                                     */
/*                 VEMS_R_08_06255_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint16 Vta_intake_learn_tempo;                                      */
/*  input uint16 Vta_intake_learn_delay;                                      */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean Vta_intake_cam_offsets_manu_inh;                            */
/*  input uint16 Vta_intake_reference_angle[4];                               */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  output uint16 Vta_intake_learn_tempo;                                     */
/*  output uint16 Vta_intake_cam_off_mes[4];                                  */
/*  output uint16 Vta_intake_cam_old_off_eep[4];                              */
/*  output uint16 Vcpi_cam_offsets[4];                                        */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*  output uint8 VlvAct_CtOfsInConf;                                          */
/*  output uint8 Vcpi_learn_zero_counter;                                     */
/*  output boolean VlvAct_bInOfsLrnDone;                                      */
/*  output uint32 VlvAct_AgOfsInValAdd[4];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidReset(void)
{
   boolean bLocalVcpi_cam_offsets_are_lrn;
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalInd;
   uint16  u16LocalVta_intake_learn_tempo;
   uint16  u16LocalVcpi_cam_offsets[VLVACTINENDSTOP_u8OFFLENGTH];


   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u16LocalVta_intake_learn_tempo = Vta_intake_learn_tempo;
   }
   else
   {
      u16LocalVta_intake_learn_tempo = Vta_intake_learn_delay;
   }
   Vta_intake_learn_tempo =
      (uint16)MATHSRV_udtMIN(u16LocalVta_intake_learn_tempo,
                             16383);
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);

   if (Vta_intake_cam_offsets_manu_inh != 0)
   {
      bLocalVcpi_cam_offsets_are_lrn = 1;
      for (u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
      {
         u16LocalVcpi_cam_offsets[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                   7679);

         Vta_intake_cam_off_mes[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                   7679);

         Vta_intake_cam_old_off_eep[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                   7679);
      }
      VEMS_vidSET1DArray(Vcpi_cam_offsets, 4, u16LocalVcpi_cam_offsets);
   }
   else
   {
      if (bLocalVlvAct_bInOfsFrstLrn != 0)
      {
         bLocalVcpi_cam_offsets_are_lrn = 1;
         VEMS_vidGET1DArray(Vcpi_cam_offsets, 4, u16LocalVcpi_cam_offsets);

         for (u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
         {
            u16LocalVcpi_cam_offsets[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(u16LocalVcpi_cam_offsets[u8LocalInd],
                                      7679);
            VEMS_vidSET1DArrayElement(Vcpi_cam_offsets,
                                      u8LocalInd,
                                      u16LocalVcpi_cam_offsets[u8LocalInd]);
            Vta_intake_cam_off_mes[u8LocalInd] =
               u16LocalVcpi_cam_offsets[u8LocalInd];

            Vta_intake_cam_old_off_eep[u8LocalInd] =
               u16LocalVcpi_cam_offsets[u8LocalInd];
         }
      }
      else
      {
         bLocalVcpi_cam_offsets_are_lrn = 0;
         for (u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
         {
            u16LocalVcpi_cam_offsets[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                      7679);

            Vta_intake_cam_off_mes[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                      7679);

            Vta_intake_cam_old_off_eep[u8LocalInd] =
               (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd],
                                      7679);
         }
         VEMS_vidSET1DArray(Vcpi_cam_offsets, 4, u16LocalVcpi_cam_offsets);
      }
   }
   VEMS_vidSET(Vcpi_cam_offsets_are_learned, bLocalVcpi_cam_offsets_are_lrn);

   if (bLocalVlvAct_bInOfsFrstLrn != 0)
   {
      VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_DONE);
   }
   else
   {
      VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_NOTDONE);
   }

   VlvAct_CtOfsInConf = 0;
   Vcpi_learn_zero_counter = 0;
   VlvAct_bInOfsLrnDone = 0;
   VlvAct_AgOfsInValAdd[0] = 0;
   VlvAct_AgOfsInValAdd[1] = 0;
   VlvAct_AgOfsInValAdd[2] = 0;
   VlvAct_AgOfsInValAdd[3] = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidIntAllowLrng                            */
/* !Description :  Condition pour commencer l'apprentissage des offsets après */
/*                 démarrage.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINENDSTOP_vidIntAllowLearn();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bInOfsClcnInh;                                       */
/*  input boolean VlvAct_bInOfsFrstLrnByp_C;                                  */
/*  input boolean VlvAct_bInOfsFrstLrnMan_C;                                  */
/*  input boolean VlvAct_bInOfsFrstLrnWoutDftByp_C;                           */
/*  input boolean VlvAct_bInOfsFrstLrnWouDftMan_C;                            */
/*  output boolean VlvAct_bInOfsFrstLrn;                                      */
/*  output boolean VlvAct_bInOfsFrstLrnMan_C;                                 */
/*  output boolean VlvAct_bInOfsFrstLrnWouDft;                                */
/*  output boolean VlvAct_bInOfsFrstLrnWouDftMan_C;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidIntAllowLrng(void)
{
   boolean  bLocalVlvAct_bInOfsClcnInh;


   VEMS_vidGET(VlvAct_bInOfsClcnInh, bLocalVlvAct_bInOfsClcnInh);

   if (bLocalVlvAct_bInOfsClcnInh == 0)
   {
      VLVACTINENDSTOP_vidIntAllowLearn();
   }
   if (VlvAct_bInOfsFrstLrnByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bInOfsFrstLrn, VlvAct_bInOfsFrstLrnMan_C);
   }
   if (VlvAct_bInOfsFrstLrnWoutDftByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bInOfsFrstLrnWouDft, VlvAct_bInOfsFrstLrnWouDftMan_C);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidIntAllowLearn                           */
/* !Description :  Ce bloc détermine quand peut commencer l'apprentissage des */
/*                 offsets après démarrage. Il y a trois conditions           */
/*                 calibrables: un seuil de régime, un délai après            */
/*                 synchronisation et un délai après que la consigne soit     */
/*                 nulle.                                                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINENDSTOP_vidInOffReset();                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint16 VlvAct_InMngStCmd;                                           */
/*  input boolean VLVACTINENDSTOP_bMotSyncPrev;                               */
/*  input uint16 Kfvcpi_t_offset_learn_delay;                                 */
/*  input uint16 VLVACTINENDSTOP_u16Timer1;                                   */
/*  input boolean VLVACTINENDSTOP_bTimeOut1;                                  */
/*  input uint16 VlvAct_InCmdMinLrnValThd_C;                                  */
/*  input boolean VLVACTINENDSTOP_bIni2ndTimerPrev;                           */
/*  input uint16 Kfvcpi_t_zero_set_time;                                      */
/*  input uint16 VLVACTINENDSTOP_u16Timer2;                                   */
/*  input uint8 Vta_intake_min_reg;                                           */
/*  input boolean Vta_intake_allow_learning;                                  */
/*  input boolean VlvAct_bInMngLrnStEna;                                      */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean VlvAct_bInLrnFrstOfsAuth;                                   */
/*  input boolean VLVACTINENDSTOP_bIntAllowLng;                               */
/*  input boolean VLVACTINENDSTOP_bTimeOut2;                                  */
/*  output uint16 VLVACTINENDSTOP_u16Timer1;                                  */
/*  output boolean VLVACTINENDSTOP_bTimeOut1;                                 */
/*  output boolean VLVACTINENDSTOP_bMotSyncPrev;                              */
/*  output uint16 VLVACTINENDSTOP_u16Timer2;                                  */
/*  output boolean VLVACTINENDSTOP_bTimeOut2;                                 */
/*  output boolean VLVACTINENDSTOP_bIni2ndTimerPrev;                          */
/*  output boolean VlvAct_bInFrstClnAuth;                                     */
/*  output boolean VLVACTINENDSTOP_bIntAllowLng;                              */
/*  output boolean Vta_intake_allow_learning;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidIntAllowLearn(void)
{
   boolean bLocalInitSecondTimer;
   boolean bLocalMoteur_synchronise;
   boolean bLocalVtaIntakeAllowLearning;
   boolean bLocalVlvAct_bInMngLrnStEna;
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalVlvAct_bInLrnFrstOfsAuth;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalVlvAct_InMngStCmd;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);

   if (  (bLocalMoteur_synchronise != 0)
      && (VLVACTINENDSTOP_bMotSyncPrev == 0))
   {
      VLVACTINENDSTOP_u16Timer1 =
         (uint16)MATHSRV_udtMIN(Kfvcpi_t_offset_learn_delay,
                                20000);

      if (VLVACTINENDSTOP_u16Timer1 == 0)
      {
         VLVACTINENDSTOP_bTimeOut1 = 1;
      }
      else
      {
         VLVACTINENDSTOP_bTimeOut1 = 0;
      }
   }
   else
   {
      if (VLVACTINENDSTOP_u16Timer1 > 0)
      {
         VLVACTINENDSTOP_u16Timer1 = (uint16)(VLVACTINENDSTOP_u16Timer1 - 1);
         if (VLVACTINENDSTOP_u16Timer1 == 0)
         {
            VLVACTINENDSTOP_bTimeOut1 = 1;
         }
         else
         {
            VLVACTINENDSTOP_bTimeOut1 = 0;
         }
      }
   }

   VLVACTINENDSTOP_bMotSyncPrev = bLocalMoteur_synchronise;

   if (  (VLVACTINENDSTOP_bTimeOut1 != 0 )
      && (u16LocalVlvAct_InMngStCmd <= VlvAct_InCmdMinLrnValThd_C))
   {
      bLocalInitSecondTimer = 1;
   }
   else
   {
      bLocalInitSecondTimer = 0;
   }
   if (  (bLocalInitSecondTimer != 0)
      && (VLVACTINENDSTOP_bIni2ndTimerPrev == 0))
   {
      VLVACTINENDSTOP_u16Timer2 = (uint16)MATHSRV_udtMIN(Kfvcpi_t_zero_set_time,
                                                         20000);
      if (VLVACTINENDSTOP_u16Timer2 == 0)
      {
         VLVACTINENDSTOP_bTimeOut2 = 1;
      }
      else
      {
         VLVACTINENDSTOP_bTimeOut2 = 0;
      }
   }
   else
   {
      if (VLVACTINENDSTOP_u16Timer2 > 0)
      {
         VLVACTINENDSTOP_u16Timer2 = (uint16)(VLVACTINENDSTOP_u16Timer2 - 1);
         if (VLVACTINENDSTOP_u16Timer2 == 0)
         {
            VLVACTINENDSTOP_bTimeOut2 = 1;
         }
         else
         {
            VLVACTINENDSTOP_bTimeOut2 = 0;
         }
      }
   }

   VLVACTINENDSTOP_bIni2ndTimerPrev = bLocalInitSecondTimer;
   VEMS_vidSET(VlvAct_bInFrstClnAuth, VLVACTINENDSTOP_bTimeOut1);

   if (u16LocalExt_nEng > (uint16)(Vta_intake_min_reg * 32))
   {
      VLVACTINENDSTOP_bIntAllowLng = 1;
   }
   VEMS_vidGET(Vta_intake_allow_learning, bLocalVtaIntakeAllowLearning);
   VEMS_vidGET(VlvAct_bInMngLrnStEna, bLocalVlvAct_bInMngLrnStEna);
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);

   VEMS_vidGET(VlvAct_bInLrnFrstOfsAuth, bLocalVlvAct_bInLrnFrstOfsAuth);

   if (  (VLVACTINENDSTOP_bIntAllowLng != 0)
      && (bLocalInitSecondTimer !=0)
      && (VLVACTINENDSTOP_bTimeOut2 != 0)
      && (  (  (bLocalVlvAct_bInOfsFrstLrn != 0)
            && (bLocalVlvAct_bInMngLrnStEna != 0))
         || (bLocalVlvAct_bInLrnFrstOfsAuth != 0)))
   {
      VEMS_vidSET(Vta_intake_allow_learning, 1);
      if (bLocalVtaIntakeAllowLearning == 0)
      {
         VLVACTINENDSTOP_vidInOffReset();
      }
   }
   else
   {
      VEMS_vidSET(Vta_intake_allow_learning, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidInOffReset                              */
/* !Description :  Intake offset reset.                                       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidInOffReset(void)
{
   boolean  bLocalCoPTSt_bRStrtSTT;


   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidSET(Vcpi_cam_offsets_are_learned, bLocalCoPTSt_bRStrtSTT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidInitDiagSrv                             */
/* !Description :  Ce bloc procède à l’initialisation des variables suivantes */
/*                 suite à une demande APV : - Valeur apprentissage butée     */
/*                 basse déphaseur AAC admission - Etat apprentissage         */
/*                 déphaseur AAC admission - Etat apprentissage roulage en    */
/*                 cours admission                                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_08_06255_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vta_intake_reference_angle[4];                               */
/*  output uint16 Vcpi_cam_offsets[4];                                        */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output st62 Ext_stAgCmInAdapt;                                            */
/*  output boolean VlvAct_bInOfsFrstLrn;                                      */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidInitDiagSrv(void)
{
   uint8  u8LocalInd;
   uint16 u16LocalVcpi_cam_offsets[VLVACTINENDSTOP_u8OFFLENGTH];


   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      u16LocalVcpi_cam_offsets[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(Vta_intake_reference_angle[u8LocalInd], 7679);
   }
   VEMS_vidSET1DArray(Vcpi_cam_offsets, 4, u16LocalVcpi_cam_offsets);
   VEMS_vidSET(Vcpi_cam_offsets_are_learned, 0);
   VEMS_vidSET(Ext_stAgCmInAdapt, VLVACT_ST_INLRN_NOTDONE);
   VEMS_vidSET(VlvAct_bInOfsFrstLrn, 0);
   VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_NOTDONE);
}

/*--------------------------------- end of file ------------------------------*/