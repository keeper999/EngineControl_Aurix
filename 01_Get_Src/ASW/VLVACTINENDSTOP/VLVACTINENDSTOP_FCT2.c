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
/* !File            : VLVACTINENDSTOP_FCT2.C                                  */
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
/*   1 / VLVACTINENDSTOP_vidIntakeOff                                         */
/*   2 / VLVACTINENDSTOP_vidInOffsets                                         */
/*   3 / VLVACTINENDSTOP_vidLearningDiag                                      */
/*   4 / VLVACTINENDSTOP_vidOffLrnErrDet                                      */
/*   5 / VLVACTINENDSTOP_vidOffCons                                           */
/*   6 / VLVACTINENDSTOP_vidOffAvrgComp                                       */
/*   7 / VLVACTINENDSTOP_vidMemoirisaCond                                     */
/*   8 / VLVACTINENDSTOP_vidMemoirisation                                     */
/*   9 / VLVACTINENDSTOP_vidFrstOffLrnCon                                     */
/*   10 / VLVACTINENDSTOP_IntOffIndUpdate                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5883893 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINENDSTOP/VLVACTI$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
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
/* !Function    :  VLVACTINENDSTOP_vidIntakeOff                               */
/* !Description :  Ce bloc calcule la valeur de décalage de l’AAC d’admission */
/*                 en soustrayant à la dernière valeur acquise de l’angle     */
/*                 vilebrequin une valeur de référence apprise ou calibrée    */
/*                 pour chacune des dents de la cible AAC.                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_004.01                                     */
/*                 VEMS_R_08_06255_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINENDSTOP_vidInOffsets();                          */
/*  extf argret void VLVACTINENDSTOP_IntOffIndUpdate();                       */
/*  extf argret void VLVACTINENDSTOP_IntOffIndUpdate1();                      */
/*  input boolean VlvAct_bInLrnEna;                                           */
/*  input boolean Vta_intake_allow_learning;                                  */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input uint8 CoVSCtl_stAccP;                                               */
/*  input boolean VlvAct_bInLrnFrstOfsAuth;                                   */
/*  input boolean VlvAct_bInOfsLrnDone;                                       */
/*  input uint16 VlvAct_agInMesLrnLim_C;                                      */
/*  input boolean VLVACTINENDSTOP_bIntakeOffPrev;                             */
/*  output boolean VLVACTINENDSTOP_bIntakeOffPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidIntakeOff(void)
{
   boolean bLocalVlvAct_bInLrnEna;
   boolean bLocalVta_intake_allow_learning;
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalVcpi_cam_offsets_are_lrn;
   boolean bLocalLrnEna;
   boolean bLocalAuthEna;
   boolean bLocalLrnAuthEna;
   boolean bLocalInOfsLrnDone;
   boolean bLocalVlvAct_bInLrnFrstOfsAuth;
   uint8   u8LocalCoVSCtl_stAccP;
   uint16  u16LocalVxx_rel_in_vvt_mes;


   VEMS_vidGET(VlvAct_bInLrnEna, bLocalVlvAct_bInLrnEna);
   VEMS_vidGET(Vta_intake_allow_learning, bLocalVta_intake_allow_learning);
   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);
   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpi_cam_offsets_are_lrn);
   VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   VEMS_vidGET(CoVSCtl_stAccP, u8LocalCoVSCtl_stAccP);
   VEMS_vidGET(VlvAct_bInLrnFrstOfsAuth, bLocalVlvAct_bInLrnFrstOfsAuth);


   if (  (bLocalVlvAct_bInOfsFrstLrn != 0)
      && (bLocalVlvAct_bInLrnEna != 0))
   {
      bLocalLrnEna = 1;
   }
   else
   {
      bLocalLrnEna = 0;
   }
   if (  (bLocalVlvAct_bInLrnFrstOfsAuth != 0)
      && (bLocalVlvAct_bInLrnEna != 0))
   {
      bLocalAuthEna = 1;
   }
   else
   {
      bLocalAuthEna = 0;
   }
   if (  (bLocalLrnEna != 0)
      || (bLocalAuthEna != 0))
   {
      bLocalLrnAuthEna = 1;
   }
   else
   {
      bLocalLrnAuthEna = 0;
   }

   if (VlvAct_bInOfsLrnDone !=0)
   {
      if (u8LocalCoVSCtl_stAccP == 0)
      {
         bLocalInOfsLrnDone = 1;
      }
      else
      {
         bLocalInOfsLrnDone = 0;
      }
   }
   else
   {
      bLocalInOfsLrnDone = 1;
   }

   if (  (bLocalLrnAuthEna != 0)
      && (bLocalVta_intake_allow_learning != 0)
      && (bLocalVcpi_cam_offsets_are_lrn == 0)
      && (bLocalInOfsLrnDone == 1)
      && (u16LocalVxx_rel_in_vvt_mes <= VlvAct_agInMesLrnLim_C))
   {
      VLVACTINENDSTOP_vidInOffsets();
      if (VLVACTINENDSTOP_bIntakeOffPrev == 0)
      {
         VLVACTINENDSTOP_IntOffIndUpdate();
         VLVACTINENDSTOP_bIntakeOffPrev = 1;
      }
   }
   else
   {
      if (VLVACTINENDSTOP_bIntakeOffPrev != 0)
      {
         VLVACTINENDSTOP_IntOffIndUpdate1();
         VLVACTINENDSTOP_bIntakeOffPrev = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidInOffsets                               */
/* !Description :  Lors  d'un  apprentissage  en  fonctionnement  si  le      */
/*                 contrôle  moteur  demande  un  décalage  on  sort  de      */
/*                 l'apprentissage  pour  revenir  en  mode  asservi.         */
/*                 L'apprentissage  en  fonctionnement  se  fera  lors  du    */
/*                 prochain passage au ralenti.                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_005.01                                     */
/*                 VEMS_R_08_06255_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTINENDSTOP_vidOffCons();                            */
/*  extf argret void VLVACTINENDSTOP_vidLearningDiag();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTINENDSTOP_vidMemoirisaCond();                      */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_agCmInMes;                                               */
/*  input uint8 Vta_intake_tooth_counter;                                     */
/*  input uint8 Vcpi_learn_zero_counter;                                      */
/*  input uint16 Vta_intake_cam_off_mes[4];                                   */
/*  input uint8 Kfvcpi_k_offset_filter;                                       */
/*  input uint32 VLVACTINENDSTOP_u32FiltreCamMem0;                            */
/*  input uint32 VLVACTINENDSTOP_u32FiltreCamMem1;                            */
/*  input uint32 VLVACTINENDSTOP_u32FiltreCamMem2;                            */
/*  input uint32 VLVACTINENDSTOP_u32FiltreCamMem3;                            */
/*  input uint8 VlvAct_nEngInLrnThdLoDiag_C;                                  */
/*  input boolean Vta_intake_inh_old_off_eep;                                 */
/*  input uint8 VlvAct_noInLrnCntMin_C;                                       */
/*  input uint16 Kcvcpi_learn_zero_offsets;                                   */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  output uint8 Vcpi_learn_zero_counter;                                     */
/*  output uint16 Vta_intake_cam_off_mes[4];                                  */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output boolean VlvAct_bInOfsClcnInh;                                      */
/*  output boolean VlvAct_bMonRunEndStopOldVlvActIn;                          */
/*  output boolean VlvAct_bMonRunLrnEndStopVlvActIn;                          */
/*  output boolean VlvAct_bMonRunLrnFaiLimVlvActIn;                           */
/*  output boolean VlvAct_bMonRunOldLrnVlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidInOffsets(void)
{
   boolean             bLocalInhVlvActInEndStopLrnOfs;
   boolean             bLocalVcpiCamOffsetsAreLearned;
   boolean             bLocalResult;
   uint8               u8LocalVta_intake_tooth_counter;
   uint16              u16LocalExt_nEng;
   uint16              u16LocalVtaIntakeCamOffMes_0;
   uint16              u16LocalVtaIntakeCamOffMes_1;
   uint16              u16LocalVtaIntakeCamOffMes_2;
   uint16              u16LocalVtaIntakeCamOffMes_3;
   uint16              u16LocalFilterInput0;
   uint16              u16LocalFilterInput1;
   uint16              u16LocalFilterInput2;
   uint16              u16LocalFilterInput3;
   uint16              u16LocalTemp;
   uint16              u16LocalTemp2;
   uint16              u16LocalExt_agCmInMes;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_agCmInMes, u16LocalExt_agCmInMes);
   VEMS_vidGET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);

   bLocalInhVlvActInEndStopLrnOfs =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINENDSTOPLRNOFS);
   u16LocalTemp = (uint16)(Vcpi_learn_zero_counter + 1);
   Vcpi_learn_zero_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 200);

   switch(u8LocalVta_intake_tooth_counter)
   {
      case 0:
         u16LocalFilterInput0 = u16LocalExt_agCmInMes;
         u16LocalFilterInput1 = Vta_intake_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_intake_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_intake_cam_off_mes[3];
         break;

      case 1:
         u16LocalFilterInput0 = Vta_intake_cam_off_mes[0];
         u16LocalFilterInput1 = u16LocalExt_agCmInMes;
         u16LocalFilterInput2 = Vta_intake_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_intake_cam_off_mes[3];
         break;

      case 2:
         u16LocalFilterInput0 = Vta_intake_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_intake_cam_off_mes[1];
         u16LocalFilterInput2 = u16LocalExt_agCmInMes;
         u16LocalFilterInput3 = Vta_intake_cam_off_mes[3];
         break;

      case 3:
         u16LocalFilterInput0 = Vta_intake_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_intake_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_intake_cam_off_mes[2];
         u16LocalFilterInput3 = u16LocalExt_agCmInMes;
         break;

      default:
         u16LocalFilterInput0 = Vta_intake_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_intake_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_intake_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_intake_cam_off_mes[3];
         break;
   }
   u16LocalVtaIntakeCamOffMes_0 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpi_k_offset_filter,
                                     &VLVACTINENDSTOP_u32FiltreCamMem0,
                                     u16LocalFilterInput0);
   u16LocalVtaIntakeCamOffMes_1 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpi_k_offset_filter,
                                     &VLVACTINENDSTOP_u32FiltreCamMem1,
                                     u16LocalFilterInput1);
   u16LocalVtaIntakeCamOffMes_2 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpi_k_offset_filter,
                                     &VLVACTINENDSTOP_u32FiltreCamMem2,
                                     u16LocalFilterInput2);
   u16LocalVtaIntakeCamOffMes_3 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpi_k_offset_filter,
                                     &VLVACTINENDSTOP_u32FiltreCamMem3,
                                     u16LocalFilterInput3);

   Vta_intake_cam_off_mes[0] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakeCamOffMes_0, 7679);
   Vta_intake_cam_off_mes[1] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakeCamOffMes_1, 7679);
   Vta_intake_cam_off_mes[2] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakeCamOffMes_2, 7679);
   Vta_intake_cam_off_mes[3] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaIntakeCamOffMes_3, 7679);

   u16LocalTemp2 = (uint16)(VlvAct_nEngInLrnThdLoDiag_C * 32);
   if (  (Vta_intake_inh_old_off_eep != 0)
      && (Vcpi_learn_zero_counter >= VlvAct_noInLrnCntMin_C))
   {
      bLocalResult = 1;
      VLVACTINENDSTOP_vidOffCons();
   }
   else
   {
      bLocalResult = 0;
   }

   if ((uint16)(Vcpi_learn_zero_counter) > Kcvcpi_learn_zero_offsets)
   {
      VLVACTINENDSTOP_vidLearningDiag();
      VEMS_vidSET(Vcpi_cam_offsets_are_learned, 1);
      VEMS_vidSET(VlvAct_bInOfsClcnInh, 1);
      VlvAct_bMonRunEndStopOldVlvActIn = 0;
      if (u16LocalExt_nEng > u16LocalTemp2)
      {
         VlvAct_bMonRunLrnEndStopVlvActIn = 1;
         VlvAct_bMonRunLrnFaiLimVlvActIn = 1;
         VlvAct_bMonRunOldLrnVlvActIn = 1;
      }
      else
      {
         VlvAct_bMonRunLrnEndStopVlvActIn = 0;
         VlvAct_bMonRunLrnFaiLimVlvActIn = 0;
         VlvAct_bMonRunOldLrnVlvActIn = 0;
      }
   }
   else
   {
      VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpiCamOffsetsAreLearned);
      if (bLocalVcpiCamOffsetsAreLearned !=0 )
      {
         VLVACTINENDSTOP_vidLearningDiag();
         VlvAct_bMonRunEndStopOldVlvActIn = 0;
         if (u16LocalExt_nEng > u16LocalTemp2)
         {
            VlvAct_bMonRunLrnEndStopVlvActIn = 1;
            VlvAct_bMonRunLrnFaiLimVlvActIn = 1;
            VlvAct_bMonRunOldLrnVlvActIn = 1;
         }
         else
         {
            VlvAct_bMonRunLrnEndStopVlvActIn = 0;
            VlvAct_bMonRunLrnFaiLimVlvActIn = 0;
            VlvAct_bMonRunOldLrnVlvActIn = 0;
         }
      }
      else
      {
         VlvAct_bMonRunLrnEndStopVlvActIn = 0;
         VlvAct_bMonRunLrnFaiLimVlvActIn = 0;
         VlvAct_bMonRunOldLrnVlvActIn = 0;
         if ( (u16LocalExt_nEng > u16LocalTemp2)
            &&(bLocalResult !=0))
         {
            VlvAct_bMonRunEndStopOldVlvActIn = 1;
         }
         else
         {
            VlvAct_bMonRunEndStopOldVlvActIn = 0;
         }
      }
      if (bLocalInhVlvActInEndStopLrnOfs != 0)
      {
         VEMS_vidSET(Vcpi_cam_offsets_are_learned, 1);
      }
      else
      {

      }
   }
   VLVACTINENDSTOP_vidMemoirisaCond();
   VEMS_vidSET(VlvAct_bInOfsClcnInh, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidLearningDiag                            */
/* !Description :  Les offsets mesurés sont appris en EEPROM si on n'a pas eu */
/*                 de panne, si le moteur est chaud et si on pas eu de        */
/*                 fonctionnement 3 dents pendant cet apprentissage. Cette    */
/*                 fonction permet d'actualiser la variable offset.           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidPrevOfLrnErDt();                      */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret void VLVACTINENDSTOP_vidOffLrnErrDet(argin uint16             */
/* u16Margin,argin uint16 *u16IntakeAngle,argin uint16 *u16OffMes ,argout     */
/* boolean *bErrDet);                                                         */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vta_intake_off_margin;                                       */
/*  input uint16 Vta_intake_reference_angle[4];                               */
/*  input uint16 Vta_intake_cam_off_mes_av[4];                                */
/*  input boolean VlvAct_bDgoLrnEndStopVlvActIn;                              */
/*  input uint8 VlvAct_CtOfsInConf;                                           */
/*  input uint8 VlvAct_noOfsInValConfThd_C;                                   */
/*  input boolean VlvAct_bDgoOldLrnVlvActIn;                                  */
/*  input uint16 Vta_intake_learn_delay;                                      */
/*  input uint16 VlvAct_CtInLrnEndStopFai;                                    */
/*  input uint16 VlvAct_CtInLrnEndStopRelzd;                                  */
/*  input uint16 VlvAct_noFaiLrnInThd_C;                                      */
/*  output uint16 Vcpi_cam_offsets[4];                                        */
/*  output uint16 Vta_intake_learn_tempo;                                     */
/*  output uint16 VlvAct_CtInLrnEndStopFai;                                   */
/*  output uint16 VlvAct_CtInLrnEndStopRelzd;                                 */
/*  output boolean VlvAct_bDgoLrnFaiLimVlvActIn;                              */
/*  output boolean VlvAct_bInOfsFrstLrn;                                      */
/*  output st62 Ext_stAgCmInAdapt;                                            */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*  output boolean VlvAct_bInOfsLrnDone;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidLearningDiag(void)
{
   boolean             bLocalInhVlvActInEndStopUpdOfs;
   uint8               u8LocalInd;
   uint16              u16LocalVcpi_cam_offsets[VLVACTINENDSTOP_u8OFFLENGTH];
   uint32              u32LocalVlvAct;
   uint32              u32LocalVlvActFai;
   GDFRM_tenuGDUState  LocalstDgoTDCDiagVlvActIn;
   GDFRM_tenuGDUState  LocalstDgoMissToothVlvActIn;


   VLVACTINENDSTOP_vidPrevOfLrnErDt();
   LocalstDgoTDCDiagVlvActIn = GDGAR_tenuGetStDgo(GD_DFT_TDCDIAGVLVACTIN);
   LocalstDgoMissToothVlvActIn = GDGAR_tenuGetStDgo(GD_DFT_MISSTOOTHVLVACTIN);

   VLVACTINENDSTOP_vidOffLrnErrDet(Vta_intake_off_margin,
                                   Vta_intake_reference_angle,
                                   Vta_intake_cam_off_mes_av,
                                   &VlvAct_bDgoLrnEndStopVlvActIn);
   bLocalInhVlvActInEndStopUpdOfs =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINENDSTOPUPDOFS);
   if (  (VlvAct_CtOfsInConf >= VlvAct_noOfsInValConfThd_C)
      && (VlvAct_bDgoLrnEndStopVlvActIn == 0)
      && (VlvAct_bDgoOldLrnVlvActIn == 0)
      && (LocalstDgoMissToothVlvActIn != GDU_ETAT_PCTL_PRESENT)
      && (LocalstDgoTDCDiagVlvActIn != GDU_ETAT_PCTL_PRESENT)
      && (bLocalInhVlvActInEndStopUpdOfs == 0))
   {
      for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
      {
         u16LocalVcpi_cam_offsets[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_intake_cam_off_mes_av[u8LocalInd],
                                   7679);
      }
      VEMS_vidSET1DArray(Vcpi_cam_offsets,4,u16LocalVcpi_cam_offsets);
   }

   Vta_intake_learn_tempo = (uint16)MATHSRV_udtMIN(Vta_intake_learn_delay,
                                                   16383);
   if (  (VlvAct_bDgoLrnEndStopVlvActIn != 0)
      || (VlvAct_bDgoOldLrnVlvActIn != 0)
      || (VlvAct_CtOfsInConf < VlvAct_noOfsInValConfThd_C))
   {
      u32LocalVlvActFai = (uint32)(VlvAct_CtInLrnEndStopFai + 1);
      VlvAct_CtInLrnEndStopFai = (uint16)MATHSRV_udtMIN(u32LocalVlvActFai,
                                                        65535);
   }
   else
   {
      u32LocalVlvAct = (uint32)(VlvAct_CtInLrnEndStopRelzd + 1);
      VlvAct_CtInLrnEndStopRelzd = (uint16)MATHSRV_udtMIN(u32LocalVlvAct,
                                                          65535);
   }
   if (VlvAct_CtInLrnEndStopFai > VlvAct_noFaiLrnInThd_C)
   {
      VlvAct_bDgoLrnFaiLimVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoLrnFaiLimVlvActIn = 0;
   }

   VEMS_vidSET(VlvAct_bInOfsFrstLrn, 1);
   VEMS_vidSET(Ext_stAgCmInAdapt, VLVACT_ST_INLRN_DONE);
   VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_DONE);
   VlvAct_bInOfsLrnDone = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidOffLrnErrDet                            */
/* !Description :  Controler l'écart entre les valeurs précédemment acquises  */
/*                 et les actuelles pour détecter un problème.                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidOffLrnErrDet
(
   uint16 u16Margin,
   uint16* u16IntakeAngle,
   uint16* u16OffMes,
   boolean* bErrDet
)
{
   sint32  s32LocalSum1;
   sint32  s32LocalSum2;
   uint8   u8LocalIndex;

   *bErrDet = 0;
   u8LocalIndex = 0;

   u16IntakeAngle[0] = u16IntakeAngle[0]; /*To avoid QAC warning*/
   u16OffMes[0] = u16OffMes [0]; /*To avoid QAC warning*/

   while ((*bErrDet == 0) && (u8LocalIndex != 4))
   {
      if (  ((u16Margin + u16IntakeAngle[u8LocalIndex]) > 7680)
         && ((u16OffMes[u8LocalIndex] - u16Margin ) < 0) )
      {
         s32LocalSum1 =
                  (sint32)(u16OffMes[u8LocalIndex] + 7680);
      }
      else
      {
         s32LocalSum1 = (sint32)(u16OffMes[u8LocalIndex]);
      }

      if (  (( u16IntakeAngle[u8LocalIndex] - u16Margin) < 0)
         && ((u16OffMes[u8LocalIndex] + u16Margin ) > 7680))
      {
         s32LocalSum2 = (sint32)(u16IntakeAngle[u8LocalIndex] + 7680);
      }
      else
      {
         s32LocalSum2 = (sint32)(u16IntakeAngle[u8LocalIndex]);
      }

      if (  ((s32LocalSum2 + u16Margin) < s32LocalSum1)
         || ((s32LocalSum2 - u16Margin) > s32LocalSum1))
      {
         *bErrDet = 1;
      }
      u8LocalIndex = (uint8)(u8LocalIndex + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidOffCons                                 */
/* !Description :  On  réalise  dans  ce  bloc  un  test  pour  vérifier  que */
/*                 l'écart  entre  les  valeurs  précédemment  acquises  et   */
/*                 les actuelles reste dans les tolérances fixées.            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidOffLrnErrDet(argin uint16             */
/*  u16Margin,argin uint16 *u16IntakeAngle,argin uint16 *u16OffMes ,argout    */
/*  boolean *bErrDet);                                                        */
/*  extf argret void VLVACTINENDSTOP_vidOffAvrgComp();                        */
/*  input uint16 Vta_intake_old_off_margin;                                   */
/*  input uint16 Vta_intake_cam_old_off_eep[4];                               */
/*  input uint16 Vta_intake_cam_off_mes[4];                                   */
/*  input boolean VlvAct_bDgoEndStopOldVlvActIn;                              */
/*  input uint8 VlvAct_CtOfsInConf;                                           */
/*  input uint8 VlvAct_noOfsInValConfThd_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidOffCons(void)
{
   VLVACTINENDSTOP_vidOffLrnErrDet(Vta_intake_old_off_margin,
                                   Vta_intake_cam_old_off_eep,
                                   Vta_intake_cam_off_mes,
                                   &VlvAct_bDgoEndStopOldVlvActIn);
   if (  (VlvAct_bDgoEndStopOldVlvActIn == 0)
      && (VlvAct_CtOfsInConf <= VlvAct_noOfsInValConfThd_C))
   {
      VLVACTINENDSTOP_vidOffAvrgComp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidOffAvrgComp                             */
/* !Description :  Offsets average computation.                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_CtOfsInConf;                                           */
/*  input uint16 Vta_intake_cam_off_mes[4];                                   */
/*  input uint32 VlvAct_AgOfsInValAdd[4];                                     */
/*  output uint8 VlvAct_CtOfsInConf;                                          */
/*  output uint32 VlvAct_AgOfsInValAdd[4];                                    */
/*  output uint16 Vta_intake_cam_off_mes_av[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidOffAvrgComp(void)
{
   uint8  u8LocalInd;
   uint16 u16Localtemp;
   uint32 u32LocalTemp;


   u16Localtemp = (uint16)(VlvAct_CtOfsInConf + 1);
   VlvAct_CtOfsInConf = (uint8)MATHSRV_udtMIN(u16Localtemp, 200);
   for(u8LocalInd=0;u8LocalInd<4;u8LocalInd++)
   {
      u32LocalTemp = (uint32)(1536000 - Vta_intake_cam_off_mes[u8LocalInd]);
      if (VlvAct_AgOfsInValAdd[u8LocalInd] > u32LocalTemp)
      {
         VlvAct_AgOfsInValAdd[u8LocalInd] = 1536000;
      }
      else
      {
         VlvAct_AgOfsInValAdd[u8LocalInd] = VlvAct_AgOfsInValAdd[u8LocalInd] +
                                            Vta_intake_cam_off_mes[u8LocalInd];

      }
      u32LocalTemp = (VlvAct_AgOfsInValAdd[u8LocalInd] / VlvAct_CtOfsInConf);
      Vta_intake_cam_off_mes_av[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(u32LocalTemp,7679);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidMemoirisaCond                           */
/* !Description :  condition de mémoirisation                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_005.01                                     */
/*                 VEMS_R_08_06255_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTINENDSTOP_vidMemoirisation();                      */
/*  input boolean VlvAct_bDgoEndStopOldVlvActIn;                              */
/*  input uint8 Vcpi_learn_zero_counter;                                      */
/*  input uint8 VlvAct_noInLrnCntMin_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidMemoirisaCond(void)
{
   boolean             bLocalInhVlvActInEndStopWrMem;
   GDFRM_tenuGDUState  LocalstDgoTDCDiagVlvActIn;
   GDFRM_tenuGDUState  LocalstDgoMissToothVlvActIn;


   LocalstDgoTDCDiagVlvActIn = GDGAR_tenuGetStDgo(GD_DFT_TDCDIAGVLVACTIN);
   LocalstDgoMissToothVlvActIn =
      GDGAR_tenuGetStDgo(GD_DFT_MISSTOOTHVLVACTIN);

   bLocalInhVlvActInEndStopWrMem =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINENDSTOPWRMEM);

   if (  (VlvAct_bDgoEndStopOldVlvActIn == 0)
      && (  (LocalstDgoMissToothVlvActIn == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoMissToothVlvActIn == GDU_ETAT_FUGITIF)
         || (LocalstDgoMissToothVlvActIn == GDU_ETAT_ABSENT))
      && (  (LocalstDgoTDCDiagVlvActIn == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoTDCDiagVlvActIn == GDU_ETAT_FUGITIF)
         || (LocalstDgoTDCDiagVlvActIn == GDU_ETAT_ABSENT))
      && (bLocalInhVlvActInEndStopWrMem == 0)
      && (Vcpi_learn_zero_counter >= VlvAct_noInLrnCntMin_C))
   {
      VLVACTINENDSTOP_vidMemoirisation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidMemoirisation                           */
/* !Description :  Mémoirisation des valeurs de la butée  de repos de la VVT  */
/*                 admission pour chaque dent came du précédent apprentissage.*/
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Vta_intake_cam_off_mes[4];                                   */
/*  output boolean Vta_intake_inh_old_off_eep;                                */
/*  output uint16 Vta_intake_cam_old_off_eep[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidMemoirisation(void)
{
   uint8 u8LocalInd;


   Vta_intake_inh_old_off_eep = 1;
   for(u8LocalInd=0;u8LocalInd<4;u8LocalInd++)
   {
      Vta_intake_cam_old_off_eep[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(Vta_intake_cam_off_mes[u8LocalInd], 7679);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidFrstOffLrnCon                           */
/* !Description :  Le premier apprentissage est réalisé si et seulement si    */
/*                 plusieurs conditions (température  et pression d’huile,    */
/*                 température d’eau, régime et pas de mode dégradé pour la   */
/*                 VVT  admission)  sont réalisées.                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_006.02                                     */
/*                 VEMS_R_08_06255_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 VlvAct_tCoInLrnThdLoFrst_C;                                  */
/*  input sint16 VlvAct_tCoInLrnThdLoFrstHys_C;                               */
/*  input sint16 VlvAct_tOilInLrnThdLoFrst_C;                                 */
/*  input sint16 VlvAct_tOilInLrnThdLoFrstHys_C;                              */
/*  input uint8 VlvAct_nEngInLrnThdLoFrst_C;                                  */
/*  input uint8 VlvAct_nEngInLrnThdLoFrstHys_C;                               */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut03;                             */
/*  input uint8 VlvAct_nEngInLrnThdHiFrst_C;                                  */
/*  input uint8 VlvAct_nEngInLrnThdHiFrstHys_C;                               */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut04;                             */
/*  input sint16 VlvAct_tCoInLrnThdHiFrstHys_C;                               */
/*  input sint16 VlvAct_tCoInLrnThdHiFrst_C;                                  */
/*  input sint16 VlvAct_tOilInLrnThdHiFrst_C;                                 */
/*  input sint16 VlvAct_tOilInLrnThdHiFrstHys_C;                              */
/*  input boolean VlvAct_bInLrnFrstOfsAuthByp_C;                              */
/*  input boolean VlvAct_bInLrnFrstOfsAuthMan_C;                              */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut01;                             */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut02;                             */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut05;                             */
/*  input boolean VLVACTINENDSTOP_bFrstHystOut06;                             */
/*  output boolean VLVACTINENDSTOP_bFrstHystOut01;                            */
/*  output boolean VLVACTINENDSTOP_bFrstHystOut02;                            */
/*  output boolean VLVACTINENDSTOP_bFrstHystOut05;                            */
/*  output boolean VLVACTINENDSTOP_bFrstHystOut06;                            */
/*  output boolean VlvAct_bInLrnFrstOfsAuth;                                  */
/*  output boolean VlvAct_bInLrnFrstOfsAuthMan_C;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidFrstOffLrnCon(void)
{
   boolean  bLocalVlvAct_bInOfsFrstLrn;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalLow;
   uint16   u16LocalHigh;
   sint16   s16LocalLow;
   sint16   s16LocalExt_tCoMes;
   sint16   s16LocalEng_tOilEstim;
   sint32   s32LocalLow;
   sint32   s32LocalSomme;
   sint32   s32LocalSommeHi;
   sint32   s32LocalSommeLow;
   sint32   s32Local;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);

   s32LocalLow = (sint32)( VlvAct_tCoInLrnThdLoFrst_C
                         - VlvAct_tCoInLrnThdLoFrstHys_C);
   if (s16LocalExt_tCoMes > VlvAct_tCoInLrnThdLoFrst_C)
   {
      VLVACTINENDSTOP_bFrstHystOut01 = 1;
   }
   else
   {
      if (s16LocalExt_tCoMes <= s32LocalLow)
      {
         VLVACTINENDSTOP_bFrstHystOut01 = 0;
      }
   }
   s32LocalLow = (sint32)( VlvAct_tOilInLrnThdLoFrst_C
                         - VlvAct_tOilInLrnThdLoFrstHys_C) * 4;
   s32Local = (sint32)(VlvAct_tOilInLrnThdLoFrst_C * 4);
   if (s16LocalEng_tOilEstim > s32Local)
   {
      VLVACTINENDSTOP_bFrstHystOut02 = 1;
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocalLow)
      {
         VLVACTINENDSTOP_bFrstHystOut02 = 0;
      }
   }

   s16LocalLow = (sint16)( VlvAct_nEngInLrnThdLoFrst_C
                         - VlvAct_nEngInLrnThdLoFrstHys_C);
   u16LocalLow = (uint16)MATHSRV_udtMAX(s16LocalLow, 0);
   u16LocalLow = (uint16)(u16LocalLow * 32);
   u16LocalHigh = (uint16)(VlvAct_nEngInLrnThdLoFrst_C * 32);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalLow,
                                u16LocalHigh,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTINENDSTOP_bFrstHystOut03);

   u16LocalLow = (uint16)(VlvAct_nEngInLrnThdHiFrst_C * 32);
   u16LocalHigh = (uint16)( ( VlvAct_nEngInLrnThdHiFrst_C
                            + VlvAct_nEngInLrnThdHiFrstHys_C)
                          * 32);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalLow,
                                u16LocalHigh,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINENDSTOP_bFrstHystOut04);

   s32LocalSomme = (sint32)( VlvAct_tCoInLrnThdHiFrstHys_C
                           + VlvAct_tCoInLrnThdHiFrst_C);
   if (s16LocalExt_tCoMes > s32LocalSomme)
   {
      VLVACTINENDSTOP_bFrstHystOut05 = 0;
   }
   else
   {
      if (s16LocalExt_tCoMes <= VlvAct_tCoInLrnThdHiFrst_C)
      {
         VLVACTINENDSTOP_bFrstHystOut05 = 1;
      }
   }
   s32LocalSommeHi = (sint32)( ( VlvAct_tOilInLrnThdHiFrst_C
                               + VlvAct_tOilInLrnThdHiFrstHys_C)
                             * 4);
   s32LocalSommeLow = (sint32)(VlvAct_tOilInLrnThdHiFrst_C * 4);
   if (s16LocalEng_tOilEstim > s32LocalSommeHi)
   {
      VLVACTINENDSTOP_bFrstHystOut06 = 0;
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocalSommeLow)
      {
         VLVACTINENDSTOP_bFrstHystOut06 = 1;
      }
   }

   if (VlvAct_bInLrnFrstOfsAuthByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bInLrnFrstOfsAuth, VlvAct_bInLrnFrstOfsAuthMan_C);
   }
   else
   {
      VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);

      if (  (VLVACTINENDSTOP_bFrstHystOut01 != 0)
         && (VLVACTINENDSTOP_bFrstHystOut02 != 0)
         && (bLocalVlvAct_bInOfsFrstLrn == 0)
         && (VLVACTINENDSTOP_bFrstHystOut03 != 0)
         && (VLVACTINENDSTOP_bFrstHystOut04 != 0)
         && (VLVACTINENDSTOP_bFrstHystOut05 != 0)
         && (VLVACTINENDSTOP_bFrstHystOut06 != 0))
      {
         VEMS_vidSET(VlvAct_bInLrnFrstOfsAuth, 1);
      }
      else
      {
         VEMS_vidSET(VlvAct_bInLrnFrstOfsAuth, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_IntOffIndUpdate                            */
/* !Description :  Mise à jour de l'etat de l'apprentissage des butées de     */
/*                 l'AAC admission                                            */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  output st62 Ext_stAgCmInAdapt;                                            */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_IntOffIndUpdate(void)
{
   boolean bLocalVlvAct_bInOfsFrstLrn;


   VEMS_vidSET(Ext_stAgCmInAdapt, VLVACT_ST_INLRN_RUN);

   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);

   if (bLocalVlvAct_bInOfsFrstLrn != 0)
   {
      VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_DONE);
   }
   else
   {
      VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_RUN);
   }
}
/*--------------------------------- end of file ------------------------------*/