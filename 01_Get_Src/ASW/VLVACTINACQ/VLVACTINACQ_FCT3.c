/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINACQ                                             */
/* !Description     : VLVACTINACQ component.                                  */
/*                                                                            */
/* !Module          : VLVACTINACQ                                             */
/* !Description     : ACQUISITION DU DECALAGE ET CALCUL DE LA VITESSE DE      */
/*                    DECALAGE DE LA VVT D'ADMISSION                          */
/*                                                                            */
/* !File            : VLVACTINACQ_FCT3.C                                      */
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
/*   1 / VLVACTINACQ_vidCurrentVelo                                           */
/*   2 / VLVACTINACQ_vidSecondOrderFilter                                     */
/*   3 / VLVACTINACQ_vidIntakeResyn                                           */
/*   4 / VLVACTINACQ_vidIntakePmhCounter                                      */
/*   5 / VLVACTINACQ_vidIntCamshaftEdge                                       */
/*   6 / VLVACTINACQ_vidORngSpdVlvbMonRun                                     */
/*   7 / VLVACTINACQ_vidORngShiftbMonRun                                      */
/*   8 / VLVACTINACQ_vidMissToothbMonRun                                      */
/*   9 / VLVACTINACQ_vidTDCDiagbMonRun                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6588653 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINACQ/VLVACT$*/
/* $Revision::   1.20     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINACQ.h"
#include "VLVACTINACQ_L.h"
#include "VLVACTINACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidCurrentVelo                                 */
/* !Description :  Ce bloc calcule la valeur de la vitesse de décalage de     */
/*                 l’AAC d’admission                                          */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidSecondOrderFilter();                      */
/*  input boolean Vta_intake_velocity_set;                                    */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input uint16 VLVACTINACQ_u16RelInVvtMesPrev;                              */
/*  input boolean Vta_intake_vel_calc_mod;                                    */
/*  input uint16 Periode_moteur;                                              */
/*  input uint16 Vta_intake_tooth_time;                                       */
/*  input sint16 Vta_intake_filt_velocity;                                    */
/*  input uint16 Vta_intake_dyn_lim;                                          */
/*  output sint16 Vta_intake_camshaft_velocity;                               */
/*  output boolean Vta_intake_velocity_set;                                   */
/*  output boolean VlvAct_bDgoORngSpdVlvActIn;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidCurrentVelo(void)
{
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalVta_intake_tooth_time;
   uint16 u16LocalVxx_rel_in_vvt_mes;
   uint16 u16Local;
   uint16 u16Local2;
   sint16 s16LocalVta_intake_filt_velocity;
   sint32 s32LocalDifference;


   if (Vta_intake_velocity_set != 0)
   {
      VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);

      s32LocalDifference = (sint32)( u16LocalVxx_rel_in_vvt_mes
                                   - VLVACTINACQ_u16RelInVvtMesPrev);
      u16Local = (uint16)MATHSRV_udtABS(s32LocalDifference);
      if (Vta_intake_vel_calc_mod != 0)
      {
         VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);

         if (u16LocalPeriode_moteur == 0)
         {
            if (s32LocalDifference >= 0)
            {
               Vta_intake_camshaft_velocity = 5333;
            }
            else
            {
               Vta_intake_camshaft_velocity = -5333;
            }
         }
         else
         {
            u16Local2 = (uint16)((2667 * u16LocalPeriode_moteur) / 156250);
            if (u16Local <= u16Local2)
            {
               Vta_intake_camshaft_velocity =
                  (sint16)( ( 312500 * s32LocalDifference)
                          / u16LocalPeriode_moteur);
            }
            else
            {
               if (s32LocalDifference > 0)
               {
                  Vta_intake_camshaft_velocity = 5333;
               }
               else
               {
                  Vta_intake_camshaft_velocity = -5333;
               }
            }
         }
      }
      else
      {
         VEMS_vidGET(Vta_intake_tooth_time, u16LocalVta_intake_tooth_time);

         if (u16LocalVta_intake_tooth_time == 0)
         {
            if (s32LocalDifference >= 0)
            {
               Vta_intake_camshaft_velocity = 5333;
            }
            else
            {
               Vta_intake_camshaft_velocity = -5333;
            }
         }
         else
         {
            u16Local2 = (uint16)( ( 2667 * u16LocalVta_intake_tooth_time)
                                / 64000);
            if (u16Local <= u16Local2)
            {
               Vta_intake_camshaft_velocity =
                  (sint16)( (128000 * s32LocalDifference)
                          / u16LocalVta_intake_tooth_time);
            }
            else
            {
               if (s32LocalDifference > 0)
               {
                  Vta_intake_camshaft_velocity = 5333;
               }
               else
               {
                  Vta_intake_camshaft_velocity = -5333;
               }
            }
         }
      }
   }

   Vta_intake_velocity_set = 1;

   VLVACTINACQ_vidSecondOrderFilter();
   VEMS_vidGET(Vta_intake_filt_velocity, s16LocalVta_intake_filt_velocity);
   u16Local = (uint16)MATHSRV_udtABS(s16LocalVta_intake_filt_velocity);
   if (u16Local > Vta_intake_dyn_lim)
   {
      VlvAct_bDgoORngSpdVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoORngSpdVlvActIn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidSecondOrderFilter                           */
/* !Description :  Fonction de calcul d'un filtre du second d'ordre           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vta_intake_camshaft_velocity_1;                              */
/*  input sint16 Vta_intake_filt_velocity;                                    */
/*  input uint16 Vta_intake_tooth_time;                                       */
/*  input uint16 Vta_intake_to_1;                                             */
/*  input sint16 Vta_intake_camshaft_velocity;                                */
/*  input sint32 VLVACTINACQ_s32FrstOrderFiltMem1;                            */
/*  input uint16 Vta_intake_to_2;                                             */
/*  input sint16 VLVACTINACQ_s16VtaIntakeFilt1;                               */
/*  input sint32 VLVACTINACQ_s32FrstOrderFiltMem2;                            */
/*  input sint16 VLVACTINACQ_s16VtaIntakeFilt2;                               */
/*  output sint16 Vta_intake_camshaft_velocity_2;                             */
/*  output sint16 Vta_intake_camshaft_velocity_1;                             */
/*  output sint32 VLVACTINACQ_s32FrstOrderFiltMem1;                           */
/*  output sint16 VLVACTINACQ_s16VtaIntakeFilt1;                              */
/*  output sint32 VLVACTINACQ_s32FrstOrderFiltMem2;                           */
/*  output sint16 VLVACTINACQ_s16VtaIntakeFilt2;                              */
/*  output sint16 Vta_intake_filt_velocity;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidSecondOrderFilter(void)
{
   sint16 s16LocalIntakeFiltVelocity;
   sint16 s16LocalVtaIntakeFilt1;
   sint16 s16LocalVtaIntakeFilt2;
   uint16 u16LocalFirstOrderGain1;
   uint16 u16LocalFirstOrderGain2;
   uint16 u16LocalVta_intake_tooth_time;
   uint32 u32LocalCalNum;
   uint32 u32LocalCalDen;

   /*UPDATE PREVIOUS VALUES*/
   Vta_intake_camshaft_velocity_2 =
      (sint16)MATHSRV_udtCLAMP(Vta_intake_camshaft_velocity_1, -5333, 5333);

   VEMS_vidGET(Vta_intake_filt_velocity, s16LocalIntakeFiltVelocity);
   Vta_intake_camshaft_velocity_1 =
      (sint16)MATHSRV_udtCLAMP(s16LocalIntakeFiltVelocity, -5333, 5333);

   VEMS_vidGET(Vta_intake_tooth_time, u16LocalVta_intake_tooth_time);

   /*GAINS CALC*/
   u32LocalCalNum = (uint32)(u16LocalVta_intake_tooth_time * 65536);

   if ( Vta_intake_to_1 == 0)
   {
      s16LocalVtaIntakeFilt1 = Vta_intake_camshaft_velocity;

      VLVACTINACQ_s32FrstOrderFiltMem1 =
         (sint32)(s16LocalVtaIntakeFilt1 * 65536);
   }
   else
   {
      /*GAIN1 CALC*/
      if (u16LocalVta_intake_tooth_time == 0)
      {
         u16LocalFirstOrderGain1 = 0;
      }
      else
      {
         u32LocalCalDen = (uint32)( ( Vta_intake_to_1
                                    * 4)
                                  + u16LocalVta_intake_tooth_time);
         u16LocalFirstOrderGain1 =(uint16)(u32LocalCalNum / u32LocalCalDen);

      }
      /*FILTER1 CALC*/
      s16LocalVtaIntakeFilt1 =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFirstOrderGain1,
                                         &VLVACTINACQ_s32FrstOrderFiltMem1,
                                         Vta_intake_camshaft_velocity);
   }
   VLVACTINACQ_s16VtaIntakeFilt1 =
     (sint16)MATHSRV_udtCLAMP(s16LocalVtaIntakeFilt1, -5333, 5333);

   if ( Vta_intake_to_2 == 0)
   {
      s16LocalVtaIntakeFilt2 = VLVACTINACQ_s16VtaIntakeFilt1;
      VLVACTINACQ_s32FrstOrderFiltMem2 =
         (sint32)(s16LocalVtaIntakeFilt2 * 65536);
   }
   else
   {
      /*GAIN2 CALC*/
      if (u16LocalVta_intake_tooth_time == 0)
      {
         u16LocalFirstOrderGain2 = 0;

      }
      else
      {
         u32LocalCalDen = (uint32)( ( Vta_intake_to_2
                                    * 4)
                                  + u16LocalVta_intake_tooth_time);
         u16LocalFirstOrderGain2 =(uint16)(u32LocalCalNum / u32LocalCalDen);
      }

      /*FILTER2 CALC*/
      s16LocalVtaIntakeFilt2 =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFirstOrderGain2,
                                         &VLVACTINACQ_s32FrstOrderFiltMem2,
                                         VLVACTINACQ_s16VtaIntakeFilt1);
   }
   /*SET Output*/
   VLVACTINACQ_s16VtaIntakeFilt2 =
      (sint16)MATHSRV_udtCLAMP(s16LocalVtaIntakeFilt2, -5333, 5333);
   VEMS_vidSET(Vta_intake_filt_velocity, VLVACTINACQ_s16VtaIntakeFilt2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeResyn                                 */
/* !Description :  Fonction de resynchronisation du compteur dent AAC sur une */
/*                 panne présente pmh ou/et décalage                          */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bInSelTypIniCntCmTooth_C;                            */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input boolean Vta_intake_camshaft_level;                                  */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  output boolean Vta_intake_velocity_set;                                   */
/*  output uint8 Vta_intake_tooth_counter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeResyn(void)
{
   uint8   u8LocalEng_noCmbCyl;
   uint8   u8LocalVta_intake_tooth_counter;
   sint16  s16LocalCalc;


   Vta_intake_velocity_set = 0;

   if (VlvAct_bInSelTypIniCntCmTooth_C != 0)
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalCalc = (sint16)(u8LocalEng_noCmbCyl - 1);
   }
   else
   {
      if (Vta_intake_camshaft_level != 0)
      {
         s16LocalCalc = 0;
      }
      else
      {
         s16LocalCalc = (sint16)(Vta_intake_tooth_nb - 1);
      }
   }
   u8LocalVta_intake_tooth_counter = (uint8)MATHSRV_udtCLAMP(s16LocalCalc,
                                                             0,
                                                             3);
   VEMS_vidSET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakePmhCounter                            */
/* !Description :  Cette fonction réalise  le  diagnostic  sur  le  nombre  de*/
/*                  pmh  vu   successivement (c'est à dire sans événement dent*/
/*                 AAC intercalé)                                             */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_nEngInTDCDiagThdLo_C;                                 */
/*  input uint16 VlvAct_nEngInTDCDiagThdLoHys_C;                              */
/*  input boolean VLVACTINACQ_bnEngInTDCDiagThd;                              */
/*  input uint8 Vta_intake_pmh_counter;                                       */
/*  input uint8 Vta_intake_pmh_threshold;                                     */
/*  output boolean VLVACTINACQ_bnEngInTDCDiagThd;                             */
/*  output uint8 Vta_intake_pmh_counter;                                      */
/*  output boolean VlvAct_bDgoTDCDiagVlvActIn;                                */
/*  output boolean Vta_intake_velocity_set;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakePmhCounter(void)
{
   uint16 u16LocalTemp;
   uint16 u16LocalExt_nEng;
   sint32 s32Localdiff;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   s32Localdiff =
      (sint32)(VlvAct_nEngInTDCDiagThdLo_C - VlvAct_nEngInTDCDiagThdLoHys_C);
   if (VLVACTINACQ_bnEngInTDCDiagThd == 0)
   {
      if (u16LocalExt_nEng >= VlvAct_nEngInTDCDiagThdLo_C)
      {
         VLVACTINACQ_bnEngInTDCDiagThd = 1;
      }
      else
      {
         VLVACTINACQ_bnEngInTDCDiagThd = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32Localdiff)
      {
         VLVACTINACQ_bnEngInTDCDiagThd = 0;
      }
      else
      {
         VLVACTINACQ_bnEngInTDCDiagThd = 1;
      }
   }
   u16LocalTemp = (uint16)(Vta_intake_pmh_counter + 1);
   Vta_intake_pmh_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 255);

   if(Vta_intake_pmh_counter > Vta_intake_pmh_threshold)
   {
      if(VLVACTINACQ_bnEngInTDCDiagThd != 0)
      {
         VlvAct_bDgoTDCDiagVlvActIn = 1;
      }
      else
      {
         VlvAct_bDgoTDCDiagVlvActIn = 0;
      }
      Vta_intake_velocity_set = 0;
   }
   else
   {
      VlvAct_bDgoTDCDiagVlvActIn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntCamshaftEdge                             */
/* !Description :  Sur l’événement InCam, le compteur de fronts utiles est    */
/*                 incrémenté.                                                */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctEdgeCmIn;                                               */
/*  output uint8 Ext_ctEdgeCmIn;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntCamshaftEdge(void)
{
   uint8  u8LocalExt_ctEdgeCmIn;
   uint16 u16LocalCalc;


   VEMS_vidGET(Ext_ctEdgeCmIn, u8LocalExt_ctEdgeCmIn);
   u16LocalCalc = (uint16)(u8LocalExt_ctEdgeCmIn + 1);
   u8LocalExt_ctEdgeCmIn = (uint8)(u16LocalCalc % 256);
   VEMS_vidSET(Ext_ctEdgeCmIn, u8LocalExt_ctEdgeCmIn);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidORngSpdVlvbMonRun                           */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunORngSpdVlvActIn.                             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input boolean VlvAct_bDgoORngShiftVlvActIn;                               */
/*  input boolean VlvAct_bDgoTDCDiagVlvActIn;                                 */
/*  output boolean VlvAct_bMonRunORngSpdVlvActIn;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidORngSpdVlvbMonRun(void)
{
   boolean bLocalMoteur_synchronise;
   boolean bLocalVcpi_cam_offsets_are_learn;


   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpi_cam_offsets_are_learn);

   if (  (VlvAct_bDgoORngShiftVlvActIn == 0)
      && (VlvAct_bDgoTDCDiagVlvActIn == 0)
      && (bLocalVcpi_cam_offsets_are_learn != 0)
      && (bLocalMoteur_synchronise != 0))
   {
      VlvAct_bMonRunORngSpdVlvActIn = 1;
   }
   else
   {
      VlvAct_bMonRunORngSpdVlvActIn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidORngShiftbMonRun                            */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunORngShiftVlvActIn.                           */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_nEngAcvInOrngShiftThd_C;                              */
/*  output boolean VlvAct_bMonRunORngShiftVlvActIn;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidORngShiftbMonRun(void)
{
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalInhVlvActInAcqShiftDiag;
   uint16  u16LocalExt_nEng;


   bLocalInhVlvActInAcqShiftDiag =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINACQSHIFTDIAG);

   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (bLocalInhVlvActInAcqShiftDiag == 0)
      && (bLocalVlvAct_bInOfsFrstLrn != 0)
      && (u16LocalExt_nEng > VlvAct_nEngAcvInOrngShiftThd_C))
   {
      VlvAct_bMonRunORngShiftVlvActIn = 1;
   }
   else
   {
      VlvAct_bMonRunORngShiftVlvActIn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidMissToothbMonRun                            */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunMissToothVlvActIn.                           */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInSelTypIniCntCmTooth_C;                            */
/*  input uint8 Vta_intake_tooth_counter;                                     */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Vta_intake_velocity_set;                                    */
/*  input boolean Vta_intake_X_tooth_check;                                   */
/*  input uint8 Vta_intake_def_tooth;                                         */
/*  input uint16 VlvAct_nEngAcvInMissToothThd_C;                              */
/*  output boolean VlvAct_bMonRunMissToothVlvActIn;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidMissToothbMonRun(void)
{
   uint8  u8LocalVta_intake_tooth_counter;
   uint8  u8LocalEng_noCmbCyl;
   uint16 u16LocalCounter;
   uint16 u16LocalToothNb;
   uint16 u16LocalExt_nEng;
   sint16 s16LocalVta_intake_tooth_counter;


   if (VlvAct_bInSelTypIniCntCmTooth_C == 0 )
   {
      VEMS_vidGET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);

      u16LocalCounter = (uint16)(u8LocalVta_intake_tooth_counter + 1);
      u16LocalToothNb = (uint16)(Vta_intake_tooth_nb + 1);
      u16LocalCounter = (uint16)MATHSRV_udtMIN(u16LocalCounter, 255);
      s16LocalVta_intake_tooth_counter = (sint16)( u16LocalCounter
                                                 % u16LocalToothNb);
   }
   else
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalVta_intake_tooth_counter = (sint16)(u8LocalEng_noCmbCyl - 1);
   }

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (Vta_intake_velocity_set != 0)
      && (  (Vta_intake_X_tooth_check != 0)
         || (Vta_intake_def_tooth == s16LocalVta_intake_tooth_counter))
      && (u16LocalExt_nEng > VlvAct_nEngAcvInMissToothThd_C))
   {
      VlvAct_bMonRunMissToothVlvActIn = 1;
   }
   else
   {
      VlvAct_bMonRunMissToothVlvActIn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidTDCDiagbMonRun                              */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunTDCDiagVlvActIn.                             */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Vcpi_cam_offsets_are_learned;                               */
/*  input boolean Vta_intake_allow_learning;                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_nEngAcvInTDCThd_C;                                    */
/*  output boolean VlvAct_bMonRunTDCDiagVlvActIn;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidTDCDiagbMonRun(void)
{
   boolean bLocalVcpi_cam_offsets_are_learn;
   boolean bLocalInhVlvActInAcqTDCDiag;
   boolean bLocalVta_intake_allow_learning;
   uint16  u16LocalExt_nEng;


   bLocalInhVlvActInAcqTDCDiag = GDGAR_bGetFRM(FRM_FRM_INHVLVACTINACQTDCDIAG);

   VEMS_vidGET(Vcpi_cam_offsets_are_learned, bLocalVcpi_cam_offsets_are_learn);
   VEMS_vidGET(Vta_intake_allow_learning, bLocalVta_intake_allow_learning);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (bLocalInhVlvActInAcqTDCDiag == 0)
      && (  (bLocalVcpi_cam_offsets_are_learn != 0)
         || (bLocalVta_intake_allow_learning != 0))
      && (u16LocalExt_nEng > VlvAct_nEngAcvInTDCThd_C))
   {
      VlvAct_bMonRunTDCDiagVlvActIn = 1;
   }
   else
   {
      VlvAct_bMonRunTDCDiagVlvActIn = 0;
   }

}
/*------------------------------- end of file --------------------------------*/