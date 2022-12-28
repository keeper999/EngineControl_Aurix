/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXACQ                                             */
/* !Description     : VLVACTEXACQ Component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXACQ                                             */
/* !Description     : Acquisition du Décalage et Calcul de la Vitesse de      */
/*                    Décalage de la VVT d’échappement                        */
/*                                                                            */
/* !File            : VLVACTEXACQ_FCT3.C                                      */
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
/*   1 / VLVACTEXACQ_vidCurrentVelo                                           */
/*   2 / VLVACTEXACQ_vidSecondOrderFilter                                     */
/*   3 / VLVACTEXACQ_vidExhaustResyn                                          */
/*   4 / VLVACTEXACQ_vidExhaustPmhCounter                                     */
/*   5 / VLVACTEXACQ_vidIntCamshaftEdge                                       */
/*   6 / VLVACTEXACQ_vidORngSpdVlvbMonRun                                     */
/*   7 / VLVACTEXACQ_vidORngShiftbMonRun                                      */
/*   8 / VLVACTEXACQ_vidMissToothbMonRun                                      */
/*   9 / VLVACTEXACQ_vidTDCDiagbMonRun                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6588648 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXACQ/VLVACT$*/
/* $Revision::   1.19     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXACQ.h"
#include "VLVACTEXACQ_L.h"
#include "VLVACTEXACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidCurrentVelo                                 */
/* !Description :  Ce bloc calcule la valeur de la vitesse de décalage de     */
/*                 l’AAC d’échappement                                        */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidSecondOrderFilter();                      */
/*  input boolean Vta_exhaust_velocity_set;                                   */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input uint16 VLVACTEXACQ_u16RelInVvtMesPrev;                              */
/*  input boolean Vta_exhaust_vel_calc_mod;                                   */
/*  input uint16 Periode_moteur;                                              */
/*  input uint16 Vta_exhaust_tooth_time;                                      */
/*  input sint16 Vta_exhaust_filt_velocity;                                   */
/*  input uint16 Vta_exhaust_dyn_lim;                                         */
/*  output sint16 Vta_exhaust_camshaft_velocity;                              */
/*  output boolean Vta_exhaust_velocity_set;                                  */
/*  output boolean VlvAct_bDgoORngSpdVlvActEx;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidCurrentVelo(void)
{
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalVta_exhaust_tooth_time;
   uint16 u16LocalVxx_rel_ex_vvt_mes;
   uint16 u16Local;
   sint32 s32LocalDifference;
   sint16 s16LocalVta_exhaust_flt_velocity;
   uint16 u16Local2;


   if (Vta_exhaust_velocity_set != 0)
   {
      VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
      s32LocalDifference = (sint32)( u16LocalVxx_rel_ex_vvt_mes
                                   - VLVACTEXACQ_u16RelInVvtMesPrev);
      u16Local = (uint16)MATHSRV_udtABS(s32LocalDifference);
      if (Vta_exhaust_vel_calc_mod != 0)
      {
         VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
         if (u16LocalPeriode_moteur == 0)
         {
            if (s32LocalDifference >= 0)
            {
               Vta_exhaust_camshaft_velocity = 5333;
            }
            else
            {
               Vta_exhaust_camshaft_velocity = -5333;
            }
         }
         else
         {
            u16Local2 = (uint16)((2667 * u16LocalPeriode_moteur) / 156250);
            if (u16Local <= u16Local2)
            {
               Vta_exhaust_camshaft_velocity =
                  (sint16)( ( 312500 * s32LocalDifference)
                          / u16LocalPeriode_moteur);
            }
            else
            {
               if (s32LocalDifference > 0)
               {
                  Vta_exhaust_camshaft_velocity = 5333;
               }
               else
               {
                  Vta_exhaust_camshaft_velocity = -5333;
               }
            }
         }
      }
      else
      {
         VEMS_vidGET(Vta_exhaust_tooth_time, u16LocalVta_exhaust_tooth_time);

         if (u16LocalVta_exhaust_tooth_time == 0)
         {
            if (s32LocalDifference >= 0)
            {
               Vta_exhaust_camshaft_velocity = 5333;
            }
            else
            {
               Vta_exhaust_camshaft_velocity = -5333;
            }
         }
         else
         {
            u16Local2 = (uint16)( (2667 * u16LocalVta_exhaust_tooth_time)
                                 / 64000);
            if (u16Local <= u16Local2)
            {
               Vta_exhaust_camshaft_velocity =
                  (sint16)( (128000 * s32LocalDifference)
                          / u16LocalVta_exhaust_tooth_time);
            }
            else
            {
               if (s32LocalDifference > 0)
               {
                  Vta_exhaust_camshaft_velocity = 5333;
               }
               else
               {
                  Vta_exhaust_camshaft_velocity = -5333;
               }
            }
         }
      }
   }
   Vta_exhaust_velocity_set = 1;

   VLVACTEXACQ_vidSecondOrderFilter();
   VEMS_vidGET(Vta_exhaust_filt_velocity, s16LocalVta_exhaust_flt_velocity);
   u16Local = (uint16)MATHSRV_udtABS(s16LocalVta_exhaust_flt_velocity);
   if (u16Local > Vta_exhaust_dyn_lim)
   {
      VlvAct_bDgoORngSpdVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoORngSpdVlvActEx = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidSecondOrderFilter                           */
/* !Description :  Fonction de calcul d'un filtre du second d'ordre           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vta_exhaust_camshaft_velocity_1;                             */
/*  input sint16 Vta_exhaust_filt_velocity;                                   */
/*  input uint16 Vta_exhaust_tooth_time;                                      */
/*  input uint16 Vta_exhaust_to_1;                                            */
/*  input sint16 Vta_exhaust_camshaft_velocity;                               */
/*  input sint32 VLVACTEXACQ_s32FrstOrderFiltMem1;                            */
/*  input uint16 Vta_exhaust_to_2;                                            */
/*  input sint16 VLVACTEXACQ_s16VtaExhaustFilt1;                              */
/*  input sint32 VLVACTEXACQ_s32FrstOrderFiltMem2;                            */
/*  input sint16 VLVACTEXACQ_s16VtaExhaustFilt2;                              */
/*  output sint16 Vta_exhaust_camshaft_velocity_2;                            */
/*  output sint16 Vta_exhaust_camshaft_velocity_1;                            */
/*  output sint32 VLVACTEXACQ_s32FrstOrderFiltMem1;                           */
/*  output sint16 VLVACTEXACQ_s16VtaExhaustFilt1;                             */
/*  output sint32 VLVACTEXACQ_s32FrstOrderFiltMem2;                           */
/*  output sint16 VLVACTEXACQ_s16VtaExhaustFilt2;                             */
/*  output sint16 Vta_exhaust_filt_velocity;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidSecondOrderFilter(void)
{
   sint16 s16LocalExhaustFiltVelocity;
   sint16 s16LocalVtaExhaustFilt1;
   sint16 s16LocalVtaExhaustFilt2;
   uint16 u16LocalFirstOrderGain1;
   uint16 u16LocalFirstOrderGain2;
   uint16 u16LocalVta_exhaust_tooth_time;
   uint32 u32LocalCalNum;
   uint32 u32LocalCalDen;

   /*UPDATE PREVIOUS VALUES*/

   Vta_exhaust_camshaft_velocity_2 =
      (sint16)MATHSRV_udtCLAMP(Vta_exhaust_camshaft_velocity_1, -5333, 5333);

   VEMS_vidGET(Vta_exhaust_filt_velocity, s16LocalExhaustFiltVelocity);
   Vta_exhaust_camshaft_velocity_1 =
      (sint16)MATHSRV_udtCLAMP(s16LocalExhaustFiltVelocity, -5333, 5333);

   VEMS_vidGET(Vta_exhaust_tooth_time, u16LocalVta_exhaust_tooth_time);

   /*GAINS CALC*/
   u32LocalCalNum = (uint32)(u16LocalVta_exhaust_tooth_time * 65536);

   if ( Vta_exhaust_to_1 == 0)
   {
      s16LocalVtaExhaustFilt1 = Vta_exhaust_camshaft_velocity;

      VLVACTEXACQ_s32FrstOrderFiltMem1 =
         (sint32)(s16LocalVtaExhaustFilt1 * 65536);
   }
   else
   {
      /*GAIN1 CALC*/
      if (u16LocalVta_exhaust_tooth_time == 0)
      {
         u16LocalFirstOrderGain1 = 0;
      }
      else
      {
         u32LocalCalDen = (uint32)( ( Vta_exhaust_to_1
                                    * 4)
                                  + u16LocalVta_exhaust_tooth_time);
         u16LocalFirstOrderGain1 =(uint16)(u32LocalCalNum / u32LocalCalDen);

      }
      /*FILTER1 CALC*/
      s16LocalVtaExhaustFilt1 =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFirstOrderGain1,
                                         &VLVACTEXACQ_s32FrstOrderFiltMem1,
                                         Vta_exhaust_camshaft_velocity);
   }
   VLVACTEXACQ_s16VtaExhaustFilt1 =
     (sint16)MATHSRV_udtCLAMP(s16LocalVtaExhaustFilt1, -5333, 5333);

   if ( Vta_exhaust_to_2 == 0)
   {
      s16LocalVtaExhaustFilt2 = VLVACTEXACQ_s16VtaExhaustFilt1;
      VLVACTEXACQ_s32FrstOrderFiltMem2 =
         (sint32)(s16LocalVtaExhaustFilt2 * 65536);
   }
   else
   {
      /*GAIN2 CALC*/
      if (u16LocalVta_exhaust_tooth_time == 0)
      {
         u16LocalFirstOrderGain2 = 0;

      }
      else
      {
         u32LocalCalDen = (uint32)( ( Vta_exhaust_to_2
                                    * 4)
                                  + u16LocalVta_exhaust_tooth_time);
         u16LocalFirstOrderGain2 =(uint16)(u32LocalCalNum / u32LocalCalDen);
      }

      /*FILTER2 CALC*/
      s16LocalVtaExhaustFilt2 =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFirstOrderGain2,
                                         &VLVACTEXACQ_s32FrstOrderFiltMem2,
                                         VLVACTEXACQ_s16VtaExhaustFilt1);
   }
   /*SET Output*/
   VLVACTEXACQ_s16VtaExhaustFilt2 =
      (sint16)MATHSRV_udtCLAMP(s16LocalVtaExhaustFilt2, -5333, 5333);
   VEMS_vidSET(Vta_exhaust_filt_velocity, VLVACTEXACQ_s16VtaExhaustFilt2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustResyn                                */
/* !Description :  Fonction de resynchronisation du compteur dent AAC sur une */
/*                 panne présente pmh ou/et décalage                          */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bExSelTypIniCntCmTooth_C;                            */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input boolean Vta_exhaust_camshaft_level;                                 */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  output boolean Vta_exhaust_velocity_set;                                  */
/*  output uint8 Vta_exhaust_tooth_counter;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustResyn(void)
{
   uint8   u8LocalEng_noCmbCyl;
   uint8   u8LocalVta_exhaust_tooth_counter;
   sint16  s16LocalCalc;


   Vta_exhaust_velocity_set = 0;

   if (VlvAct_bExSelTypIniCntCmTooth_C != 0)
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalCalc = (sint16)(u8LocalEng_noCmbCyl - 1);
   }
   else
   {
      if (Vta_exhaust_camshaft_level != 0)
      {
         s16LocalCalc = 0;
      }
      else
      {
         s16LocalCalc = (sint16)(Vta_exhaust_tooth_nb - 1);
      }
   }
   u8LocalVta_exhaust_tooth_counter = (uint8)MATHSRV_udtCLAMP(s16LocalCalc,
                                                              0,
                                                              3);
   VEMS_vidSET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustPmhCounter                           */
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
/*  input uint16 VlvAct_nEngExTDCDiagThdLo_C;                                 */
/*  input uint16 VlvAct_nEngExTDCDiagThdLoHys_C;                              */
/*  input boolean VLVACTEXACQ_bnEngExTDCDiagThd;                              */
/*  input uint8 Vta_exhaust_pmh_counter;                                      */
/*  input uint8 Vta_exhaust_pmh_threshold;                                    */
/*  output boolean VLVACTEXACQ_bnEngExTDCDiagThd;                             */
/*  output uint8 Vta_exhaust_pmh_counter;                                     */
/*  output boolean VlvAct_bDgoTDCDiagVlvActEx;                                */
/*  output boolean Vta_exhaust_velocity_set;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustPmhCounter(void)
{
   uint16 u16LocalTemp;
   uint16 u16LocalExt_nEng;
   sint32 s32Localdiff;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   s32Localdiff =
      (sint32)(VlvAct_nEngExTDCDiagThdLo_C - VlvAct_nEngExTDCDiagThdLoHys_C);
   if (VLVACTEXACQ_bnEngExTDCDiagThd == 0)
   {
      if (u16LocalExt_nEng >= VlvAct_nEngExTDCDiagThdLo_C)
      {
         VLVACTEXACQ_bnEngExTDCDiagThd = 1;
      }
      else
      {
         VLVACTEXACQ_bnEngExTDCDiagThd = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32Localdiff)
      {
         VLVACTEXACQ_bnEngExTDCDiagThd = 0;
      }
      else
      {
         VLVACTEXACQ_bnEngExTDCDiagThd = 1;
      }
   }
   u16LocalTemp = (uint16)(Vta_exhaust_pmh_counter + 1);
   Vta_exhaust_pmh_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 255);

   if (Vta_exhaust_pmh_counter > Vta_exhaust_pmh_threshold)
   {
      if (VLVACTEXACQ_bnEngExTDCDiagThd != 0)
      {
         VlvAct_bDgoTDCDiagVlvActEx = 1;
      }
      else
      {
         VlvAct_bDgoTDCDiagVlvActEx = 0;
      }
      Vta_exhaust_velocity_set = 0;
   }
   else
   {
      VlvAct_bDgoTDCDiagVlvActEx = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidIntCamshaftEdge                             */
/* !Description :  Sur l’événement ExCam, le compteur de fronts utiles est    */
/*                 incrémenté.                                                */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctEdgeCmEx;                                               */
/*  output uint8 Ext_ctEdgeCmEx;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidIntCamshaftEdge(void)
{
   uint8  u8LocalExt_ctEdgeCmEx;
   uint16 u16LocalCalc;


   VEMS_vidGET(Ext_ctEdgeCmEx, u8LocalExt_ctEdgeCmEx);
   u16LocalCalc = (uint16)(u8LocalExt_ctEdgeCmEx + 1);
   u8LocalExt_ctEdgeCmEx = (uint8)(u16LocalCalc % 256);
   VEMS_vidSET(Ext_ctEdgeCmEx, u8LocalExt_ctEdgeCmEx);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidORngSpdVlvbMonRun                           */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunORngSpdVlvActEx.                             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input boolean VlvAct_bDgoORngShiftVlvActEx;                               */
/*  input boolean VlvAct_bDgoTDCDiagVlvActEx;                                 */
/*  output boolean VlvAct_bMonRunORngSpdVlvActEx;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidORngSpdVlvbMonRun(void)
{
   boolean bLocalMoteur_synchronise;
   boolean bLocalVcpe_cam_offsets_are_learn;


   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpe_cam_offsets_are_learn);

   if (  (VlvAct_bDgoORngShiftVlvActEx == 0)
      && (VlvAct_bDgoTDCDiagVlvActEx == 0)
      && (bLocalVcpe_cam_offsets_are_learn != 0)
      && (bLocalMoteur_synchronise != 0))
   {
      VlvAct_bMonRunORngSpdVlvActEx = 1;
   }
   else
   {
      VlvAct_bMonRunORngSpdVlvActEx = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidORngShiftbMonRun                            */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunORngShiftVlvActEx.                           */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Vlvact_nEngAcvExORngShiftThd_C;                              */
/*  output boolean VlvAct_bMonRunORngShiftVlvActEx;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidORngShiftbMonRun(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalInhVlvActExAcqShiftDiag;
   uint16  u16LocalExt_nEng;


   bLocalInhVlvActExAcqShiftDiag =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXACQSHIFTDIAG);

   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (bLocalInhVlvActExAcqShiftDiag == 0)
      && (bLocalVlvAct_bExOfsFrstLrn != 0)
      && (u16LocalExt_nEng > Vlvact_nEngAcvExORngShiftThd_C))
   {
      VlvAct_bMonRunORngShiftVlvActEx = 1;
   }
   else
   {
      VlvAct_bMonRunORngShiftVlvActEx = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidMissToothbMonRun                            */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunMissToothVlvActEx.                           */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExSelTypIniCntCmTooth_C;                            */
/*  input uint8 Vta_exhaust_tooth_counter;                                    */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Vta_exhaust_velocity_set;                                   */
/*  input boolean Vta_exhaust_X_tooth_check;                                  */
/*  input uint8 Vta_exhaust_def_tooth;                                        */
/*  input uint16 Vlvact_nEngAcvExMissToothThd_C;                              */
/*  output boolean VlvAct_bMonRunMissToothVlvActEx;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidMissToothbMonRun(void)
{
   uint8  u8LocalVta_exhaust_tooth_counter;
   uint8  u8LocalEng_noCmbCyl;
   uint16 u16LocalCounter;
   uint16 u16LocalToothNb;
   uint16 u16LocalExt_nEng;
   sint16 s16LocalVta_exhaust_tooth_countr;


   if (VlvAct_bExSelTypIniCntCmTooth_C == 0 )
   {
      VEMS_vidGET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);

      u16LocalCounter = (uint16)(u8LocalVta_exhaust_tooth_counter + 1);
      u16LocalToothNb = (uint16)(Vta_exhaust_tooth_nb + 1);
      u16LocalCounter = (uint16)MATHSRV_udtMIN(u16LocalCounter, 255);
      s16LocalVta_exhaust_tooth_countr = (sint16)( u16LocalCounter
                                                  % u16LocalToothNb);
   }
   else
   {
      VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
      s16LocalVta_exhaust_tooth_countr = (sint16)(u8LocalEng_noCmbCyl - 1);
   }

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (Vta_exhaust_velocity_set != 0)
      && (  (Vta_exhaust_X_tooth_check != 0)
         || (Vta_exhaust_def_tooth == s16LocalVta_exhaust_tooth_countr))
      && (u16LocalExt_nEng > Vlvact_nEngAcvExMissToothThd_C))
   {
      VlvAct_bMonRunMissToothVlvActEx = 1;
   }
   else
   {
      VlvAct_bMonRunMissToothVlvActEx = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidTDCDiagbMonRun                              */
/* !Description :  Fonction de calcul de la variable                          */
/*                 VlvAct_bMonRunTDCDiagVlvActEx.                             */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input boolean Vta_exhaust_allow_learning;                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Vlvact_nEngAcvExTDCThd_C;                                    */
/*  output boolean VlvAct_bMonRunTDCDiagVlvActEx;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidTDCDiagbMonRun(void)
{
   boolean bLocalVcpe_cam_offsets_are_learn;
   boolean bLocalInhVlvActExAcqTDCDiag;
   boolean bLocalVta_exhaust_allow_learning;
   uint16  u16LocalExt_nEng;


   bLocalInhVlvActExAcqTDCDiag = GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXACQTDCDIAG);

   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpe_cam_offsets_are_learn);
   VEMS_vidGET(Vta_exhaust_allow_learning, bLocalVta_exhaust_allow_learning);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   if (  (bLocalInhVlvActExAcqTDCDiag == 0)
      && (  (bLocalVcpe_cam_offsets_are_learn != 0)
         || (bLocalVta_exhaust_allow_learning != 0))
      && (u16LocalExt_nEng > Vlvact_nEngAcvExTDCThd_C))
   {
      VlvAct_bMonRunTDCDiagVlvActEx = 1;
   }
   else
   {
      VlvAct_bMonRunTDCDiagVlvActEx = 0;
   }
}

/*------------------------------- end of file --------------------------------*/