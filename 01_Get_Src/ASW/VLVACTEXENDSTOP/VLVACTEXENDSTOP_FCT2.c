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
/* !File            : VLVACTEXENDSTOP_FCT2.C                                  */
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
/*   1 / VLVACTEXENDSTOP_vidExhaustOff                                        */
/*   2 / VLVACTEXENDSTOP_vidExOffsets                                         */
/*   3 / VLVACTEXENDSTOP_vidLearningDiag                                      */
/*   4 / VLVACTEXENDSTOP_vidOffLrnErrDet                                      */
/*   5 / VLVACTEXENDSTOP_vidOffCons                                           */
/*   6 / VLVACTEXENDSTOP_vidOffAvrgComp                                       */
/*   7 / VLVACTEXENDSTOP_vidMemoirisaCond                                     */
/*   8 / VLVACTEXENDSTOP_vidMemoirisation                                     */
/*   9 / VLVACTEXENDSTOP_vidFrstOffLrnCon                                     */
/*   10 / VLVACTEXENDSTOP_ExtOffIndUpdate                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5885665 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXENDSTOP/VLVACTE$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
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
/* !Function    :  VLVACTEXENDSTOP_vidExhaustOff                              */
/* !Description :  Ce bloc calcule la valeur de décalage de l’AAC de          */
/*                 l'échappement en soustrayant à la dernière valeur acquise  */
/*                 de l’angle vilebrequin une valeur de référence apprise ou  */
/*                 calibrée pour chacune des dents de la cible AAC.           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_004.01                                     */
/*                 VEMS_R_08_06268_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXENDSTOP_vidExOffsets();                          */
/*  extf argret void VLVACTEXENDSTOP_ExtOffIndUpdate();                       */
/*  extf argret void VLVACTEXENDSTOP_ExtOffIndUpdate1();                      */
/*  input boolean VlvAct_bExLrnEna;                                           */
/*  input boolean Vta_exhaust_allow_learning;                                 */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input uint8 CoVSCtl_stAccP;                                               */
/*  input boolean VlvAct_bExLrnFrstOfsAuth;                                   */
/*  input boolean VlvAct_bExOfsLrnDone;                                       */
/*  input uint16 VlvAct_agExMesLrnLim_C;                                      */
/*  input boolean VLVACTEXENDSTOP_bExhaustOffPrev;                            */
/*  output boolean VLVACTEXENDSTOP_bExhaustOffPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidExhaustOff(void)
{
   boolean bLocalVlvAct_bExLrnEna;
   boolean bLocalVta_exhaust_allow_learning ;
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalVcpe_cam_offsets_are_lrn;
   boolean bLocalLrnEna;
   boolean bLocalAuthEna;
   boolean bLocalLrnAuthEna;
   boolean bLocalExOfsLrnDone;
   boolean bLocalVlvAct_bExLrnFrstOfsAuth;
   uint8   u8LocalCoVSCtl_stAccP;
   uint16  u16LocalVxx_rel_ex_vvt_mes;


   VEMS_vidGET(VlvAct_bExLrnEna, bLocalVlvAct_bExLrnEna);
   VEMS_vidGET(Vta_exhaust_allow_learning, bLocalVta_exhaust_allow_learning);
   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpe_cam_offsets_are_lrn);
   VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
   VEMS_vidGET(CoVSCtl_stAccP, u8LocalCoVSCtl_stAccP);
   VEMS_vidGET(VlvAct_bExLrnFrstOfsAuth, bLocalVlvAct_bExLrnFrstOfsAuth);

   if (  (bLocalVlvAct_bExOfsFrstLrn != 0)
      && (bLocalVlvAct_bExLrnEna != 0))
   {
      bLocalLrnEna = 1;
   }
   else
   {
      bLocalLrnEna = 0;
   }
   if (  (bLocalVlvAct_bExLrnFrstOfsAuth != 0)
      && (bLocalVlvAct_bExLrnEna != 0))
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

   if (VlvAct_bExOfsLrnDone != 0)
   {
      if (u8LocalCoVSCtl_stAccP == 0)
      {
         bLocalExOfsLrnDone = 1;
      }
      else
      {
         bLocalExOfsLrnDone = 0;
      }
   }
   else
   {
      bLocalExOfsLrnDone = 1;
   }

   if (  (bLocalLrnAuthEna != 0)
      && (bLocalVta_exhaust_allow_learning != 0)
      && (bLocalVcpe_cam_offsets_are_lrn == 0)
      && (bLocalExOfsLrnDone == 1)
      && (u16LocalVxx_rel_ex_vvt_mes <= VlvAct_agExMesLrnLim_C))
   {
      VLVACTEXENDSTOP_vidExOffsets();
      if (VLVACTEXENDSTOP_bExhaustOffPrev == 0)
      {
         VLVACTEXENDSTOP_ExtOffIndUpdate();
         VLVACTEXENDSTOP_bExhaustOffPrev = 1;
      }
   }
   else
   {
      if (VLVACTEXENDSTOP_bExhaustOffPrev != 0)
      {
         VLVACTEXENDSTOP_ExtOffIndUpdate1();
         VLVACTEXENDSTOP_bExhaustOffPrev = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidExOffsets                               */
/* !Description :  Lors  d'un  apprentissage  en  fonctionnement  si  le      */
/*                 contrôle  moteur  demande  un  décalage  on  sort  de      */
/*                 l'apprentissage  pour  revenir  en  mode  asservi.         */
/*                 L'apprentissage  en  fonctionnement  se  fera  lors  du    */
/*                 prochain passage au ralenti.                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_005.01                                     */
/*                 VEMS_R_08_06268_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTEXENDSTOP_vidOffCons();                            */
/*  extf argret void VLVACTEXENDSTOP_vidLearningDiag();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXENDSTOP_vidMemoirisaCond();                      */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_agCmExMes;                                               */
/*  input uint8 Vta_exhaust_tooth_counter;                                    */
/*  input uint8 Vcpe_learn_zero_counter;                                      */
/*  input uint16 Vta_exhaust_cam_off_mes[4];                                  */
/*  input uint8 Kfvcpe_k_offset_filter;                                       */
/*  input uint32 VLVACTEXENDSTOP_u32FiltreCamMem0;                            */
/*  input uint32 VLVACTEXENDSTOP_u32FiltreCamMem1;                            */
/*  input uint32 VLVACTEXENDSTOP_u32FiltreCamMem2;                            */
/*  input uint32 VLVACTEXENDSTOP_u32FiltreCamMem3;                            */
/*  input uint8 VlvAct_nEngExLrnThdLoDiag_C;                                  */
/*  input boolean Vta_exhaust_inh_old_off_eep;                                */
/*  input uint8 VlvAct_noExLrnCntMin_C;                                       */
/*  input uint16 Kcvcpe_learn_zero_offsets;                                   */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  output uint8 Vcpe_learn_zero_counter;                                     */
/*  output uint16 Vta_exhaust_cam_off_mes[4];                                 */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output boolean VlvAct_bExOfsClcnInh;                                      */
/*  output boolean VlvAct_bMonRunEndStopOldVlvActEx;                          */
/*  output boolean VlvAct_bMonRunLrnEndStopVlvActEx;                          */
/*  output boolean VlvAct_bMonRunLrnFaiLimVlvActEx;                           */
/*  output boolean VlvAct_bMonRunOldLrnVlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidExOffsets(void)
{
   boolean             bLocalInhVlvActExEndStopLrnOfs;
   boolean             bLocalVcpeCamOffsetsAreLearned;
   boolean             bLocalResult;
   uint8               u8LocalVta_exhaust_tooth_counter;
   uint16              u16LocalExt_nEng;
   uint16              u16LocalVtaExhaustCamOffMes_0;
   uint16              u16LocalVtaExhaustCamOffMes_1;
   uint16              u16LocalVtaExhaustCamOffMes_2;
   uint16              u16LocalVtaExhaustCamOffMes_3;
   uint16              u16LocalFilterInput0;
   uint16              u16LocalFilterInput1;
   uint16              u16LocalFilterInput2;
   uint16              u16LocalFilterInput3;
   uint16              u16LocalTemp;
   uint16              u16LocalTemp2;
   uint16              u16LocalExt_agCmExMes;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_agCmExMes, u16LocalExt_agCmExMes);
   VEMS_vidGET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);

   bLocalInhVlvActExEndStopLrnOfs =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXENDSTOPLRNOFS);
   u16LocalTemp = (uint16)(Vcpe_learn_zero_counter + 1);
   Vcpe_learn_zero_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 200);

   switch (u8LocalVta_exhaust_tooth_counter)
   {
      case 0:
         u16LocalFilterInput0 = u16LocalExt_agCmExMes;
         u16LocalFilterInput1 = Vta_exhaust_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_exhaust_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_exhaust_cam_off_mes[3];
         break;

      case 1:
         u16LocalFilterInput0 = Vta_exhaust_cam_off_mes[0];
         u16LocalFilterInput1 = u16LocalExt_agCmExMes;
         u16LocalFilterInput2 = Vta_exhaust_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_exhaust_cam_off_mes[3];
         break;

      case 2:
         u16LocalFilterInput0 = Vta_exhaust_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_exhaust_cam_off_mes[1];
         u16LocalFilterInput2 = u16LocalExt_agCmExMes;
         u16LocalFilterInput3 = Vta_exhaust_cam_off_mes[3];
         break;

      case 3:
         u16LocalFilterInput0 = Vta_exhaust_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_exhaust_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_exhaust_cam_off_mes[2];
         u16LocalFilterInput3 = u16LocalExt_agCmExMes;
         break;

      default:
         u16LocalFilterInput0 = Vta_exhaust_cam_off_mes[0];
         u16LocalFilterInput1 = Vta_exhaust_cam_off_mes[1];
         u16LocalFilterInput2 = Vta_exhaust_cam_off_mes[2];
         u16LocalFilterInput3 = Vta_exhaust_cam_off_mes[3];
         break;
   }
   u16LocalVtaExhaustCamOffMes_0 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpe_k_offset_filter,
                                     &VLVACTEXENDSTOP_u32FiltreCamMem0,
                                     u16LocalFilterInput0);
   u16LocalVtaExhaustCamOffMes_1 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpe_k_offset_filter,
                                     &VLVACTEXENDSTOP_u32FiltreCamMem1,
                                     u16LocalFilterInput1);
   u16LocalVtaExhaustCamOffMes_2 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpe_k_offset_filter,
                                     &VLVACTEXENDSTOP_u32FiltreCamMem2,
                                     u16LocalFilterInput2);
   u16LocalVtaExhaustCamOffMes_3 =
      MATHSRV_u16FirstOrderFilterGu8(Kfvcpe_k_offset_filter,
                                     &VLVACTEXENDSTOP_u32FiltreCamMem3,
                                     u16LocalFilterInput3);

   Vta_exhaust_cam_off_mes[0] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustCamOffMes_0, 7679);
   Vta_exhaust_cam_off_mes[1] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustCamOffMes_1, 7679);
   Vta_exhaust_cam_off_mes[2] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustCamOffMes_2, 7679);
   Vta_exhaust_cam_off_mes[3] =
      (uint16)MATHSRV_udtMIN(u16LocalVtaExhaustCamOffMes_3, 7679);

   u16LocalTemp2 = (uint16)(VlvAct_nEngExLrnThdLoDiag_C * 32);
   if (  (Vta_exhaust_inh_old_off_eep != 0)
      && (Vcpe_learn_zero_counter >= VlvAct_noExLrnCntMin_C))
   {
      bLocalResult = 1;
      VLVACTEXENDSTOP_vidOffCons();
   }
   else
   {
      bLocalResult = 0;
   }
   if ((uint16)(Vcpe_learn_zero_counter) > Kcvcpe_learn_zero_offsets)
   {
      VLVACTEXENDSTOP_vidLearningDiag();
      VEMS_vidSET(Vcpe_cam_offsets_are_learned, 1);
      VEMS_vidSET(VlvAct_bExOfsClcnInh, 1);
      VlvAct_bMonRunEndStopOldVlvActEx = 0;
      if (u16LocalExt_nEng > u16LocalTemp2)
      {
         VlvAct_bMonRunLrnEndStopVlvActEx = 1;
         VlvAct_bMonRunLrnFaiLimVlvActEx = 1;
         VlvAct_bMonRunOldLrnVlvActEx = 1;
      }
      else
      {
         VlvAct_bMonRunLrnEndStopVlvActEx = 0;
         VlvAct_bMonRunLrnFaiLimVlvActEx = 0;
         VlvAct_bMonRunOldLrnVlvActEx = 0;
      }
   }
   else
   {
      VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpeCamOffsetsAreLearned);
      if (bLocalVcpeCamOffsetsAreLearned !=0 )
      {
         VLVACTEXENDSTOP_vidLearningDiag();
         VlvAct_bMonRunEndStopOldVlvActEx = 0;
         if (u16LocalExt_nEng > u16LocalTemp2)
         {
            VlvAct_bMonRunLrnEndStopVlvActEx = 1;
            VlvAct_bMonRunLrnFaiLimVlvActEx = 1;
            VlvAct_bMonRunOldLrnVlvActEx = 1;
         }
         else
         {
            VlvAct_bMonRunLrnEndStopVlvActEx = 0;
            VlvAct_bMonRunLrnFaiLimVlvActEx = 0;
            VlvAct_bMonRunOldLrnVlvActEx = 0;
         }
      }
      else
      {
         VlvAct_bMonRunLrnEndStopVlvActEx = 0;
         VlvAct_bMonRunLrnFaiLimVlvActEx = 0;
         VlvAct_bMonRunOldLrnVlvActEx = 0;
         if ( (u16LocalExt_nEng > u16LocalTemp2)
            &&(bLocalResult != 0))
         {
            VlvAct_bMonRunEndStopOldVlvActEx = 1;
         }
         else
         {
            VlvAct_bMonRunEndStopOldVlvActEx = 0;
         }

      }

      if (bLocalInhVlvActExEndStopLrnOfs != 0)
      {
         VEMS_vidSET(Vcpe_cam_offsets_are_learned, 1);
      }
   }
   VLVACTEXENDSTOP_vidMemoirisaCond();
   VEMS_vidSET(VlvAct_bExOfsClcnInh, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidLearningDiag                            */
/* !Description :  Les offsets mesurés sont appris en EEPROM si on n'a pas eu */
/*                 de panne, si le moteur est chaud et si on pas eu de        */
/*                 fonctionnement 3 dents pendant cet apprentissage. Cette    */
/*                 fonction permet d'actualiser la variable offset.           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidPrvLrnErDetec();                      */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret void VLVACTEXENDSTOP_vidOffLrnErrDet(argin uint16             */
/* u16Margin,argin uint16 *u16ExhaustAngle,uint16 *u16OffMes,argout boolean   */
/* *bErrDet);                                                                 */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vta_exhaust_off_margin;                                      */
/*  input uint16 Vta_exhaust_reference_angle[4];                              */
/*  input uint16 Vta_exhaust_cam_off_mes_av[4];                               */
/*  input boolean VlvAct_bDgoLrnEndStopVlvActEx;                              */
/*  input uint8 VlvAct_CtOfsExConf;                                           */
/*  input uint8 VlvAct_noOfsExValConfThd_C;                                   */
/*  input boolean VlvAct_bDgoOldLrnVlvActEx;                                  */
/*  input uint16 Vta_exhaust_learn_delay;                                     */
/*  input uint16 VlvAct_CtExLrnEndStopFai;                                    */
/*  input uint16 VlvAct_CtExLrnEndStopRelzd;                                  */
/*  input uint16 VlvAct_noFaiLrnExThd_C;                                      */
/*  output uint16 Vcpe_cam_offsets[4];                                        */
/*  output uint16 Vta_exhaust_learn_tempo;                                    */
/*  output uint16 VlvAct_CtExLrnEndStopFai;                                   */
/*  output uint16 VlvAct_CtExLrnEndStopRelzd;                                 */
/*  output boolean VlvAct_bDgoLrnFaiLimVlvActEx;                              */
/*  output boolean VlvAct_bExOfsFrstLrn;                                      */
/*  output st17 Ext_stAgCmExAdapt;                                            */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*  output boolean VlvAct_bExOfsLrnDone;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidLearningDiag(void)
{
   boolean              bLocalInhVlvActExEndStopUpdOfs;
   uint8                u8LocalInd;
   uint16               u16LocalVcpe_cam_offsets[VLVACTEXENDSTOP_u8OFFLENGTH];
   uint32               u32LocalVlvAct;
   uint32               u32LocalVlvActFai;
   GDFRM_tenuGDUState   LocalstDgoTDCDiagVlvActEx;
   GDFRM_tenuGDUState   LocalstDgoMissToothVlvActEx;


   VLVACTEXENDSTOP_vidPrvLrnErDetec();
   LocalstDgoTDCDiagVlvActEx = GDGAR_tenuGetStDgo(GD_DFT_TDCDIAGVLVACTEX);
   LocalstDgoMissToothVlvActEx = GDGAR_tenuGetStDgo(GD_DFT_MISSTOOTHVLVACTEX);

   VLVACTEXENDSTOP_vidOffLrnErrDet(Vta_exhaust_off_margin,
                                   Vta_exhaust_reference_angle,
                                   Vta_exhaust_cam_off_mes_av,
                                   &VlvAct_bDgoLrnEndStopVlvActEx);
   bLocalInhVlvActExEndStopUpdOfs =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXENDSTOPUPDOFS);

   if (  (VlvAct_CtOfsExConf >= VlvAct_noOfsExValConfThd_C)
      && (VlvAct_bDgoLrnEndStopVlvActEx == 0)
      && (VlvAct_bDgoOldLrnVlvActEx == 0)
      && (LocalstDgoMissToothVlvActEx != GDU_ETAT_PCTL_PRESENT)
      && (LocalstDgoTDCDiagVlvActEx != GDU_ETAT_PCTL_PRESENT)
      && (bLocalInhVlvActExEndStopUpdOfs == 0))
   {
      for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
      {
         u16LocalVcpe_cam_offsets[u8LocalInd] =
            (uint16)MATHSRV_udtMIN(Vta_exhaust_cam_off_mes_av[u8LocalInd],
                                   7679);
      }
      VEMS_vidSET1DArray(Vcpe_cam_offsets,4,u16LocalVcpe_cam_offsets);
   }

   Vta_exhaust_learn_tempo = (uint16)MATHSRV_udtMIN(Vta_exhaust_learn_delay,
                                                    16383);
   if (  (VlvAct_bDgoLrnEndStopVlvActEx != 0)
      || (VlvAct_bDgoOldLrnVlvActEx != 0)
      || (VlvAct_CtOfsExConf < VlvAct_noOfsExValConfThd_C))
   {
      u32LocalVlvActFai = (uint32)(VlvAct_CtExLrnEndStopFai + 1);
      VlvAct_CtExLrnEndStopFai = (uint16)MATHSRV_udtMIN(u32LocalVlvActFai,
                                                        65535);
   }
   else
   {
      u32LocalVlvAct = (uint32)(VlvAct_CtExLrnEndStopRelzd + 1);
      VlvAct_CtExLrnEndStopRelzd = (uint16)MATHSRV_udtMIN(u32LocalVlvAct,
                                                          65535);
   }
   if (VlvAct_CtExLrnEndStopFai > VlvAct_noFaiLrnExThd_C)
   {
      VlvAct_bDgoLrnFaiLimVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoLrnFaiLimVlvActEx = 0;
   }

   VEMS_vidSET(VlvAct_bExOfsFrstLrn, 1);
   VEMS_vidSET(Ext_stAgCmExAdapt, VLVACT_ST_EXLRN_DONE);
   VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_DONE);
   VlvAct_bExOfsLrnDone = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidOffLrnErrDet                            */
/* !Description :  Controler l'écart entre les valeurs précédemment acquises  */
/*                 et les actuelles pour détecter un problème.                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidOffLrnErrDet
(
   uint16 u16Margin,
   uint16* u16ExhaustAngle,
   uint16* u16OffMes,
   boolean* bErrDet
)
{
   sint32  s32LocalSum1;
   sint32  s32LocalSum2;
   uint8   u8LocalIndex;

   *bErrDet = 0;
   u8LocalIndex = 0;

   u16ExhaustAngle[0] = u16ExhaustAngle[0]; /*To avoid QAC warning*/
   u16OffMes[0] = u16OffMes [0]; /*To avoid QAC warning*/

   while ((*bErrDet == 0) && (u8LocalIndex != 4))
   {
      if (  ((u16Margin + u16ExhaustAngle[u8LocalIndex]) > 7680)
         && ((u16OffMes[u8LocalIndex] - u16Margin ) < 0) )
      {
         s32LocalSum1 =
                  (sint32)(u16OffMes[u8LocalIndex] + 7680);
      }
      else
      {
         s32LocalSum1 = (sint32)(u16OffMes[u8LocalIndex]);
      }

      if (  (( u16ExhaustAngle[u8LocalIndex] - u16Margin) < 0)
         && ((u16OffMes[u8LocalIndex] + u16Margin ) > 7680))
      {
         s32LocalSum2 = (sint32)(u16ExhaustAngle[u8LocalIndex] + 7680);
      }
      else
      {
         s32LocalSum2 = (sint32)(u16ExhaustAngle[u8LocalIndex]);
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
/* !Function    :  VLVACTEXENDSTOP_vidOffCons                                 */
/* !Description :  On  réalise  dans  ce  bloc  un  test  pour  vérifier  que */
/*                 l'écart  entre  les  valeurs  précédemment  acquises  et   */
/*                 les actuelles reste dans les tolérances fixées.            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidOffLrnErrDet(argin uint16             */
/*  u16Margin,argin uint16 *u16ExhaustAngle,uint16 *u16OffMes,argout boolean  */
/*  *bErrDet);                                                                */
/*  extf argret void VLVACTEXENDSTOP_vidOffAvrgComp();                        */
/*  input uint16 Vta_exhaust_old_off_margin;                                  */
/*  input uint16 Vta_exhaust_cam_old_off_eep[4];                              */
/*  input uint16 Vta_exhaust_cam_off_mes[4];                                  */
/*  input boolean VlvAct_bDgoEndStopOldVlvActEx;                              */
/*  input uint8 VlvAct_CtOfsExConf;                                           */
/*  input uint8 VlvAct_noOfsExValConfThd_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidOffCons(void)
{
   VLVACTEXENDSTOP_vidOffLrnErrDet(Vta_exhaust_old_off_margin,
                                   Vta_exhaust_cam_old_off_eep,
                                   Vta_exhaust_cam_off_mes,
                                   &VlvAct_bDgoEndStopOldVlvActEx);
   if (  (VlvAct_bDgoEndStopOldVlvActEx == 0)
      && (VlvAct_CtOfsExConf <= VlvAct_noOfsExValConfThd_C))
   {
      VLVACTEXENDSTOP_vidOffAvrgComp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidOffAvrgComp                             */
/* !Description :  Offsets average computation.                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_CtOfsExConf;                                           */
/*  input uint16 Vta_exhaust_cam_off_mes[4];                                  */
/*  input uint32 VlvAct_AgOfsExValAdd[4];                                     */
/*  output uint8 VlvAct_CtOfsExConf;                                          */
/*  output uint32 VlvAct_AgOfsExValAdd[4];                                    */
/*  output uint16 Vta_exhaust_cam_off_mes_av[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidOffAvrgComp(void)
{
   uint8  u8LocalInd;
   uint16 u16Localtemp;
   uint32 u32LocalTemp;


   u16Localtemp = (uint16)(VlvAct_CtOfsExConf + 1);
   VlvAct_CtOfsExConf = (uint8)MATHSRV_udtMIN(u16Localtemp, 200);
   for(u8LocalInd=0;u8LocalInd<4;u8LocalInd++)
   {
      u32LocalTemp = (uint32)(1536000 - Vta_exhaust_cam_off_mes[u8LocalInd]);
      if (VlvAct_AgOfsExValAdd[u8LocalInd] > u32LocalTemp)
      {
         VlvAct_AgOfsExValAdd[u8LocalInd] = 1536000;
      }
      else
      {
         VlvAct_AgOfsExValAdd[u8LocalInd] = VlvAct_AgOfsExValAdd[u8LocalInd] +
                                            Vta_exhaust_cam_off_mes[u8LocalInd];

      }
      u32LocalTemp = (VlvAct_AgOfsExValAdd[u8LocalInd] / VlvAct_CtOfsExConf);
      Vta_exhaust_cam_off_mes_av[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(u32LocalTemp,7679);
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidMemoirisaCond                           */
/* !Description :  condition de mémoirisation                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTEXENDSTOP_vidMemoirisation();                      */
/*  input boolean VlvAct_bDgoEndStopOldVlvActEx;                              */
/*  input uint8 Vcpe_learn_zero_counter;                                      */
/*  input uint8 VlvAct_noExLrnCntMin_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidMemoirisaCond(void)
{
   boolean             bLocalInhVlvActExEndStopWrMem;
   GDFRM_tenuGDUState  LocalstDgoTDCDiagVlvActEx;
   GDFRM_tenuGDUState  LocalstDgoMissToothVlvActEx;


   LocalstDgoMissToothVlvActEx = GDGAR_tenuGetStDgo(GD_DFT_MISSTOOTHVLVACTEX);
   LocalstDgoTDCDiagVlvActEx = GDGAR_tenuGetStDgo(GD_DFT_TDCDIAGVLVACTEX);
   bLocalInhVlvActExEndStopWrMem =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXENDSTOPWRMEM);
   if (  (VlvAct_bDgoEndStopOldVlvActEx == 0)
      && (  (LocalstDgoMissToothVlvActEx == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoMissToothVlvActEx == GDU_ETAT_FUGITIF)
         || (LocalstDgoMissToothVlvActEx == GDU_ETAT_ABSENT))
      && (  (LocalstDgoTDCDiagVlvActEx == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoTDCDiagVlvActEx == GDU_ETAT_FUGITIF)
         || (LocalstDgoTDCDiagVlvActEx == GDU_ETAT_ABSENT))
      && (bLocalInhVlvActExEndStopWrMem == 0)
      && (Vcpe_learn_zero_counter >= VlvAct_noExLrnCntMin_C))
   {
      VLVACTEXENDSTOP_vidMemoirisation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidMemoirisation                           */
/* !Description :  Mémoirisation des valeurs de la butée  de repos de la VVT  */
/*                 admission pour chaque dent came du précédent apprentissage.*/
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Vta_exhaust_cam_off_mes[4];                                  */
/*  output boolean Vta_exhaust_inh_old_off_eep;                               */
/*  output uint16 Vta_exhaust_cam_old_off_eep[4];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidMemoirisation(void)
{
   uint8 u8LocalInd;


   Vta_exhaust_inh_old_off_eep = 1;
   for(u8LocalInd=0;u8LocalInd<4;u8LocalInd++)
   {
      Vta_exhaust_cam_old_off_eep[u8LocalInd] =
         (uint16)MATHSRV_udtMIN(Vta_exhaust_cam_off_mes[u8LocalInd], 7679);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidFrstOffLrnCon                           */
/* !Description :  Le premier apprentissage est réalisé si et seulement si    */
/*                 plusieurs conditions (température  et pression d’huile,    */
/*                 température d’eau, régime et pas de mode dégradé pour la   */
/*                 VVT  admission)  sont réalisées.                           */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_006.02                                     */
/*                 VEMS_R_08_06268_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 VlvAct_tCoExLrnThdLoFrst_C;                                  */
/*  input sint16 VlvAct_tCoExLrnThdLoFrstHys_C;                               */
/*  input sint16 VlvAct_tOilExLrnThdLoFrst_C;                                 */
/*  input sint16 VlvAct_tOilExLrnThdLoFrstHys_C;                              */
/*  input uint8 VlvAct_nEngExLrnThdLoFrst_C;                                  */
/*  input uint8 VlvAct_nEngExLrnThdLoFrstHys_C;                               */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut03;                             */
/*  input uint8 VlvAct_nEngExLrnThdHiFrst_C;                                  */
/*  input uint8 VlvAct_nEngExLrnThdHiFrstHys_C;                               */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut04;                             */
/*  input sint16 VlvAct_tCoExLrnThdHiFrst_C;                                  */
/*  input sint16 VlvAct_tCoExLrnThdHiFrstHys_C;                               */
/*  input sint16 VlvAct_tOilExLrnThdHiFrst_C;                                 */
/*  input sint16 VlvAct_tOilExLrnThdHiFrstHys_C;                              */
/*  input boolean VlvAct_bExLrnFrstOfsAuthByp_C;                              */
/*  input boolean VlvAct_bExLrnFrstOfsAuthMan_C;                              */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut01;                             */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut02;                             */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut05;                             */
/*  input boolean VLVACTEXENDSTOP_bFrstHystOut06;                             */
/*  output boolean VLVACTEXENDSTOP_bFrstHystOut01;                            */
/*  output boolean VLVACTEXENDSTOP_bFrstHystOut02;                            */
/*  output boolean VLVACTEXENDSTOP_bFrstHystOut05;                            */
/*  output boolean VLVACTEXENDSTOP_bFrstHystOut06;                            */
/*  output boolean VlvAct_bExLrnFrstOfsAuth;                                  */
/*  output boolean VlvAct_bExLrnFrstOfsAuthMan_C;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidFrstOffLrnCon(void)
{
   boolean  bLocalVlvAct_bExOfsFrstLrn;
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

   s32LocalLow = (sint32)( VlvAct_tCoExLrnThdLoFrst_C
                         - VlvAct_tCoExLrnThdLoFrstHys_C);
   if (s16LocalExt_tCoMes > VlvAct_tCoExLrnThdLoFrst_C)
   {
      VLVACTEXENDSTOP_bFrstHystOut01 = 1;
   }
   else
   {
      if (s16LocalExt_tCoMes <= s32LocalLow)
      {
         VLVACTEXENDSTOP_bFrstHystOut01 = 0;
      }
   }

   s32LocalLow = (sint32)( VlvAct_tOilExLrnThdLoFrst_C
                         - VlvAct_tOilExLrnThdLoFrstHys_C) * 4;

   s32Local = (sint32)(VlvAct_tOilExLrnThdLoFrst_C * 4);
   if (s16LocalEng_tOilEstim > s32Local)
   {
      VLVACTEXENDSTOP_bFrstHystOut02 = 1;
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocalLow)
      {
         VLVACTEXENDSTOP_bFrstHystOut02 = 0;
      }
   }

   s16LocalLow = (sint16)( VlvAct_nEngExLrnThdLoFrst_C
                         - VlvAct_nEngExLrnThdLoFrstHys_C);
   u16LocalLow = (uint16)MATHSRV_udtMAX(s16LocalLow,0);
   u16LocalLow = (uint16)(u16LocalLow * 32);
   u16LocalHigh = (uint16)(VlvAct_nEngExLrnThdLoFrst_C * 32);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalLow,
                                u16LocalHigh,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VLVACTEXENDSTOP_bFrstHystOut03);

   u16LocalLow = (uint16)(VlvAct_nEngExLrnThdHiFrst_C * 32);
   u16LocalHigh = (uint16)( ( VlvAct_nEngExLrnThdHiFrst_C
                            + VlvAct_nEngExLrnThdHiFrstHys_C)
                          * 32);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalLow,
                                u16LocalHigh,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXENDSTOP_bFrstHystOut04);
   s32LocalSomme = (sint32)( VlvAct_tCoExLrnThdHiFrst_C
                           + VlvAct_tCoExLrnThdHiFrstHys_C);
   if (s16LocalExt_tCoMes > s32LocalSomme)
   {
      VLVACTEXENDSTOP_bFrstHystOut05 = 0;
   }
   else
   {
      if (s16LocalExt_tCoMes <= VlvAct_tCoExLrnThdHiFrst_C)
      {
         VLVACTEXENDSTOP_bFrstHystOut05 = 1;
      }
   }

   s32LocalSommeHi = (sint32)( VlvAct_tOilExLrnThdHiFrst_C
                             + VlvAct_tOilExLrnThdHiFrstHys_C) * 4;
   s32LocalSommeLow = (sint32)(VlvAct_tOilExLrnThdHiFrst_C * 4);
   if (s16LocalEng_tOilEstim > s32LocalSommeHi)
   {
      VLVACTEXENDSTOP_bFrstHystOut06 = 0;
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocalSommeLow)
      {
         VLVACTEXENDSTOP_bFrstHystOut06 = 1;
      }
   }

   if (VlvAct_bExLrnFrstOfsAuthByp_C != 0)
   {
      VEMS_vidSET(VlvAct_bExLrnFrstOfsAuth, VlvAct_bExLrnFrstOfsAuthMan_C);
   }
   else
   {
      VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
      if (  (VLVACTEXENDSTOP_bFrstHystOut01 != 0)
         && (VLVACTEXENDSTOP_bFrstHystOut02 != 0)
         && (bLocalVlvAct_bExOfsFrstLrn == 0)
         && (VLVACTEXENDSTOP_bFrstHystOut03 != 0)
         && (VLVACTEXENDSTOP_bFrstHystOut04 != 0)
         && (VLVACTEXENDSTOP_bFrstHystOut05 != 0)
         && (VLVACTEXENDSTOP_bFrstHystOut06 != 0))
      {
         VEMS_vidSET(VlvAct_bExLrnFrstOfsAuth, 1);
      }
      else
      {
         VEMS_vidSET(VlvAct_bExLrnFrstOfsAuth, 0);
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_ExtOffIndUpdate                            */
/* !Description :  Mise à jour de l'etat de l'apprentissage des butées de     */
/*                 l'AAC échappement.                                         */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  output st17 Ext_stAgCmExAdapt;                                            */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_ExtOffIndUpdate(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn;


   VEMS_vidSET(Ext_stAgCmExAdapt, VLVACT_ST_EXLRN_RUN);

   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);

   if (bLocalVlvAct_bExOfsFrstLrn != 0)
   {
      VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_DONE);
   }
   else
   {
      VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_RUN);
   }
}
/*--------------------------------- end of file ------------------------------*/