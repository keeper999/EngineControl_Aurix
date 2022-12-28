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
/* !File            : VLVACTINACQ_FCT2.C                                      */
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
/*   1 / VLVACTINACQ_vidIntakeRisingCapt                                      */
/*   2 / VLVACTINACQ_vidTraitementXDent                                       */
/*   3 / VLVACTINACQ_vidIntakeCaptCalc                                        */
/*   4 / VLVACTINACQ_vidIntakeCalcul                                          */
/*   5 / VLVACTINACQ_vidIntakeDiagnosis                                       */
/*   6 / VLVACTINACQ_vidCamEngineSpeed                                        */
/*   7 / VLVACTINACQ_vidInCamEngineSpd                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6588653 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTIN/VLVACTINACQ/VLVACT$*/
/* $Revision::   1.24     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "VLVACTINACQ.h"
#include "VLVACTINACQ_L.h"
#include "VLVACTINACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeRisingCapt                            */
/* !Description :  Fonction  de prise en compte du nombre de dents de la cible*/
/*                 AAC                                                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void VLVACTINACQ_vidTraitementXDent();                        */
/*  input uint16 Acquisition_angle_vilb_aac_adm;                              */
/*  input uint16 Ext_agCmInMesTbl[4];                                         */
/*  input uint32 Acquisition_temps_dents_aac_adm;                             */
/*  input boolean VlvAct_bInSelTypIniCntCmTooth_C;                            */
/*  input uint8 Vta_intake_tooth_counter;                                     */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  input uint16 VlvAct_agInMaxFrntGap_C;                                     */
/*  input boolean VlvAct_bMonRunMissToothVlvActIn;                            */
/*  output uint8 Vta_intake_pmh_counter;                                      */
/*  output uint16 Ext_agCmInMes;                                              */
/*  output uint16 Ext_agCmInMesTbl[4];                                        */
/*  output uint16 Vta_intake_tooth_time;                                      */
/*  output uint16 Ext_tiPatCmIn;                                              */
/*  output uint8 Vta_intake_tooth_counter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeRisingCapt(void)
{
   uint8  u8LocalEng_noCmbCyl;
   uint8  u8LocalVta_intake_tooth_counter;
   uint16 u16LocalToothNb;
   uint16 u16LocalAgCmInMes;
   uint16 u16LocalCounter;
   uint16 u16LocalVtaIntToothTime;
   uint16 u16LocalTemp;
   uint16 u16LocalVcpiCamOffsetsMAX;
   uint16 u16LocalExtAgCmInMesTblMAX;
   uint16 u16LocalVcpi_cam_offsets[VLVACTINACQ_u8CAM_LENGTH];
   uint16 u16LocalAcqanglevilbaacadm;
   uint16 u16LocalMod;
   uint32 u32LocalAcqTempsDentsaacadm;
   uint32 u32LocalDiv;
   uint32 u32LocalResult;
   sint16 s16LocalVta_intake_tooth_counter;
   sint16 s16LocalDiff;
   sint32 s32LocalDiff;


   Vta_intake_pmh_counter = 0;
   /* CamHAL */
   VEMS_vidGET(Acquisition_angle_vilb_aac_adm, u16LocalAcqanglevilbaacadm);
   u16LocalAgCmInMes = (uint16)(u16LocalAcqanglevilbaacadm / 6);
   u16LocalAgCmInMes = (uint16)MATHSRV_udtMIN(u16LocalAgCmInMes, 7679);
   VEMS_vidSET(Ext_agCmInMes, u16LocalAgCmInMes);
   Ext_agCmInMesTbl[3] = (uint16)MATHSRV_udtMIN(Ext_agCmInMesTbl[2], 7679);
   Ext_agCmInMesTbl[2] = (uint16)MATHSRV_udtMIN(Ext_agCmInMesTbl[1], 7679);
   Ext_agCmInMesTbl[1] = (uint16)MATHSRV_udtMIN(Ext_agCmInMesTbl[0], 7679);
   Ext_agCmInMesTbl[0] = u16LocalAgCmInMes;

   /* CamHAL1 */
   VEMS_vidGET(Acquisition_temps_dents_aac_adm, u32LocalAcqTempsDentsaacadm);
   if (u32LocalAcqTempsDentsaacadm > 268435455)
   {
      u32LocalDiv = u32LocalAcqTempsDentsaacadm / 625;
      u16LocalMod =(uint16)(u32LocalAcqTempsDentsaacadm % 625);
      u32LocalResult = u32LocalDiv + ((u16LocalMod * 16) / 625);
   }
   else
   {
      u32LocalResult = (u32LocalAcqTempsDentsaacadm * 16) / 625;
   }
   u16LocalVtaIntToothTime = (uint16)MATHSRV_udtMIN(u32LocalResult,
                                                    65535);
   VEMS_vidSET(Vta_intake_tooth_time, u16LocalVtaIntToothTime);
   VEMS_vidSET(Ext_tiPatCmIn, u16LocalVtaIntToothTime);

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

   if (  (Ext_agCmInMesTbl[0] != 0)
      && (Ext_agCmInMesTbl[1] != 0)
      && (Ext_agCmInMesTbl[2] != 0)
      && (Ext_agCmInMesTbl[3] != 0))
   {
      VEMS_vidGET1DArray(Vcpi_cam_offsets,
                         VLVACTINACQ_u8CAM_LENGTH,
                         u16LocalVcpi_cam_offsets);
      u16LocalVcpiCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpi_cam_offsets[0],
                                u16LocalVcpi_cam_offsets[1]);
      u16LocalVcpiCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpiCamOffsetsMAX,
                                u16LocalVcpi_cam_offsets[2]);
      u16LocalVcpiCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpiCamOffsetsMAX,
                                u16LocalVcpi_cam_offsets[3]);

      u16LocalExtAgCmInMesTblMAX =
         (uint16)MATHSRV_udtMAX(Ext_agCmInMesTbl[0], Ext_agCmInMesTbl[1]);
      u16LocalExtAgCmInMesTblMAX =
         (uint16)MATHSRV_udtMAX(u16LocalExtAgCmInMesTblMAX,
                                Ext_agCmInMesTbl[2]);
      u16LocalExtAgCmInMesTblMAX =
         (uint16)MATHSRV_udtMAX(u16LocalExtAgCmInMesTblMAX,
                                Ext_agCmInMesTbl[3]);

      s32LocalDiff =
         (sint32)(u16LocalVcpiCamOffsetsMAX - u16LocalExtAgCmInMesTblMAX);
      u16LocalTemp = (uint16)MATHSRV_udtABS(s32LocalDiff);
   }
   else
   {
      u16LocalTemp = 0;
   }

   if (u16LocalTemp >= VlvAct_agInMaxFrntGap_C)
   {
      s16LocalDiff = (sint16)( s16LocalVta_intake_tooth_counter
                             + Vta_intake_tooth_nb);
      u16LocalToothNb = (uint16)(Vta_intake_tooth_nb + 1);
      s16LocalDiff = (sint16)(s16LocalDiff % u16LocalToothNb);
      u8LocalVta_intake_tooth_counter = (uint8)MATHSRV_udtMIN(s16LocalDiff, 3);
   }
   else
   {
      u8LocalVta_intake_tooth_counter =
         (uint8)MATHSRV_udtCLAMP(s16LocalVta_intake_tooth_counter, 0, 3);
   }
   VEMS_vidSET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);

   if(VlvAct_bMonRunMissToothVlvActIn != 0)
   {
      VLVACTINACQ_vidTraitementXDent();
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidTraitementXDent                             */
/* !Description :  Detection d'un  fonctionnement  sur une dent  ratée   en   */
/*                 contrôlant  le  temps entre deux dents consécutives.       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Periode_moteur;                                              */
/*  input uint16 Vta_intake_noMultPeriod;                                     */
/*  input uint16 Vta_intake_tooth_time;                                       */
/*  input uint8 Vta_intake_tooth_counter;                                     */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  output boolean VlvAct_bDgoMissToothVlvActIn;                              */
/*  output uint8 Vta_intake_tooth_counter;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidTraitementXDent(void)
{
   uint8  u8LocalCounter;
   uint8  u8LocalVta_intake_tooth_counter;
   uint16 u16LocalTouthNb;
   uint16 u16LocalVta_intake_tooth_time;
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalTemp;
   uint16 u16LocalMin;
   uint32 u32LocalTemp1;
   uint32 u32LocalTemp2;


   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
   u32LocalTemp1 = u16LocalPeriode_moteur * Vta_intake_noMultPeriod;
   if (u32LocalTemp1 > (UINT32_MAX / (uint32)24))
   {
      u32LocalTemp2 = (u32LocalTemp1 / 625) * 24;
   }
   else
   {
      u32LocalTemp2 = (u32LocalTemp1 * 24) / 625;
   }
   u16LocalMin = (uint16)MATHSRV_udtMIN(u32LocalTemp2, 65535);
   VEMS_vidGET(Vta_intake_tooth_time, u16LocalVta_intake_tooth_time);
   VEMS_vidGET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);

   if (u16LocalVta_intake_tooth_time > u16LocalMin)
   {
      VlvAct_bDgoMissToothVlvActIn = 1;

      u16LocalTemp = (uint16)(u8LocalVta_intake_tooth_counter + 1);
      u16LocalTouthNb = (uint16)(Vta_intake_tooth_nb + 1);

      u16LocalTemp =
         (uint16)(MATHSRV_udtMIN(u16LocalTemp, 255) % u16LocalTouthNb);

      u8LocalVta_intake_tooth_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 3);
   }
   else
   {
      VlvAct_bDgoMissToothVlvActIn = 0;
      u16LocalTouthNb = (uint16)(Vta_intake_tooth_nb + 1);
      u8LocalCounter =
         (uint8)(u8LocalVta_intake_tooth_counter % u16LocalTouthNb);
      u8LocalVta_intake_tooth_counter =
         (uint8)MATHSRV_udtMIN(u8LocalCounter, 3);
   }
   VEMS_vidSET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeCaptCalc                              */
/* !Description :  Fonction de calcul du décalage à partir des mesures sur les*/
/*                 fronts dents AAC                                           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINACQ_vidIntakeCalcul();                           */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeCaptCalc(void)
{
   boolean bLocalVlvAct_bInOfsFrstLrn;


   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);
   if (bLocalVlvAct_bInOfsFrstLrn != 0)
   {
      VLVACTINACQ_vidIntakeCalcul();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeCalcul                                */
/* !Description :  Fonction de calcul de la valeur de la vitesse de décalage  */
/*                 de l’AAC d’admission                                       */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 Vta_intake_tooth_counter;                                     */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  input uint16 Ext_agCmInMes;                                               */
/*  input boolean Vta_intake_advance_configuration;                           */
/*  input uint16 Vta_intake_lower_def_limit;                                  */
/*  input uint16 Vta_intake_higher_def_limit;                                 */
/*  output sint16 Vta_intake_camshaft_shift;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeCalcul(void)
{
   uint8  u8LocalVta_intake_tooth_counter;
   uint16 u16LocalVcpi_cam_offsets[VLVACTINACQ_u8CAM_LENGTH];
   uint16 u16LocalExt_agCmInMes;
   sint32 s32LocalCalc;
   sint32 s32LocalAdd;


   VEMS_vidGET(Vta_intake_tooth_counter, u8LocalVta_intake_tooth_counter);

   if (u8LocalVta_intake_tooth_counter > 3)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   else
   {
      VEMS_vidGET1DArray(Vcpi_cam_offsets,VLVACTINACQ_u8CAM_LENGTH,
                     u16LocalVcpi_cam_offsets);

      VEMS_vidGET(Ext_agCmInMes, u16LocalExt_agCmInMes);
      if (Vta_intake_advance_configuration != 0)
      {
         s32LocalCalc =
            (sint32)( u16LocalVcpi_cam_offsets[u8LocalVta_intake_tooth_counter]
                    - u16LocalExt_agCmInMes);
      }
      else
      {
         s32LocalCalc =
            (sint32)( u16LocalExt_agCmInMes
                    - u16LocalVcpi_cam_offsets[u8LocalVta_intake_tooth_counter]
                    );
      }
      s32LocalAdd = s32LocalCalc + EVC_CYCLE_LENGHT_IN;
      if (  ((s32LocalCalc + Vta_intake_lower_def_limit) <= 0)
         && (s32LocalAdd < Vta_intake_higher_def_limit))
      {
         Vta_intake_camshaft_shift =
            (sint16)MATHSRV_udtMAX(s32LocalAdd, -7680);
      }
      else
      {
         if (  (s32LocalCalc >= Vta_intake_higher_def_limit)
            && ( (  (s32LocalCalc - EVC_CYCLE_LENGHT_IN)
                 + Vta_intake_lower_def_limit)
               > 0))
         {
            Vta_intake_camshaft_shift = (sint16)
               MATHSRV_udtMIN((s32LocalCalc - EVC_CYCLE_LENGHT_IN), 7679);
         }
         else
         {
            Vta_intake_camshaft_shift =
               (sint16)MATHSRV_udtCLAMP(s32LocalCalc, -7680, 7679);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidIntakeDiagnosis                             */
/* !Description :  Cette fonction réalise le diagnostic pmh                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_nEngInORngShiftThdLo_C;                               */
/*  input uint16 VlvAct_nEngInORngShiftThdLoHys_C;                            */
/*  input boolean VLVACTINACQ_bnEngInORngShiftThd;                            */
/*  input sint16 Vta_intake_camshaft_shift;                                   */
/*  input uint16 Vta_intake_lower_def_limit;                                  */
/*  input uint16 Vta_intake_higher_def_limit;                                 */
/*  input boolean VlvAct_bDgoTDCDiagVlvActIn;                                 */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  output boolean VLVACTINACQ_bnEngInORngShiftThd;                           */
/*  output boolean Vta_intake_velocity_set;                                   */
/*  output boolean VlvAct_bDgoORngShiftVlvActIn;                              */
/*  output uint16 VLVACTINACQ_u16RelInVvtMesPrev;                             */
/*  output uint16 Vxx_rel_in_vvt_mes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidIntakeDiagnosis(void)
{
   boolean bLocalresult;
   uint16  u16LocalVxx_rel_in_vvt_mes;
   uint16  u16LocalExt_nEng;
   sint32  s32Localdiff;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   s32Localdiff =
      (sint32)( VlvAct_nEngInORngShiftThdLo_C
              - VlvAct_nEngInORngShiftThdLoHys_C);
   if (VLVACTINACQ_bnEngInORngShiftThd == 0)
   {
      if (u16LocalExt_nEng >= VlvAct_nEngInORngShiftThdLo_C)
      {
         VLVACTINACQ_bnEngInORngShiftThd = 1;
      }
      else
      {
         VLVACTINACQ_bnEngInORngShiftThd = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32Localdiff)
      {
         VLVACTINACQ_bnEngInORngShiftThd = 0;
      }
      else
      {
         VLVACTINACQ_bnEngInORngShiftThd = 1;
      }
   }
   s32Localdiff =
      (sint32)( Vta_intake_camshaft_shift
              + Vta_intake_lower_def_limit);
   if (  (Vta_intake_camshaft_shift >= Vta_intake_higher_def_limit)
      || (s32Localdiff <= 0))
   {
      Vta_intake_velocity_set = 0;
      bLocalresult = 1;
   }
   else
   {
      bLocalresult = 0;
   }
   if (  (VLVACTINACQ_bnEngInORngShiftThd != 0)
      && (bLocalresult == 1))
   {
      VlvAct_bDgoORngShiftVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoORngShiftVlvActIn = 0;
   }
   if (  (bLocalresult == 0)
      && (VlvAct_bDgoTDCDiagVlvActIn == 0))
   {
      VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
      VLVACTINACQ_u16RelInVvtMesPrev = u16LocalVxx_rel_in_vvt_mes;
      u16LocalVxx_rel_in_vvt_mes =
         (uint16)MATHSRV_udtCLAMP(Vta_intake_camshaft_shift, 0, 1066);
      VEMS_vidSET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidCamEngineSpeed                              */
/* !Description :  Cette fonction reconstitue le régime moteur à partir de    */
/*                 l’intervalle de temps entre deux évènements dents AAC      */
/*                 admission et l’écart angulaire théorique entre deux        */
/*                 évènements dents AAC admission.                            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINACQ_vidInCamEngineSpd();                         */
/*  input boolean VlvAct_bDgoMissToothVlvActIn;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidCamEngineSpeed(void)
{
   if (VlvAct_bDgoMissToothVlvActIn == 0)
   {
      VLVACTINACQ_vidInCamEngineSpd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINACQ_vidInCamEngineSpd                              */
/* !Description :  Fonction pour la reconstitution du  régime moteur à partir */
/*                 de l’intervalle  de temps et de l’écart angulaire théorique*/
/*                 entre deux évènements dents AAC admission.                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 VLVACTINACQ_u8VehActvStatePrev;                               */
/*  input uint16 Vta_intake_tooth_time;                                       */
/*  input uint16 VlvAct_agCmInToothGap_C;                                     */
/*  input uint8 Vta_intake_tooth_nb;                                          */
/*  input uint16 VlvAct_nEngInCm;                                             */
/*  input uint16 VLVACTINACQ_u16EngInCmPrev1;                                 */
/*  input uint16 VLVACTINACQ_u16EngInCmPrev2;                                 */
/*  input uint16 VLVACTINACQ_u16EngInCmPrev3;                                 */
/*  input uint16 VlvAct_nEngInCmAdd;                                          */
/*  output uint16 VlvAct_nEngInCm;                                            */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev1;                                */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev2;                                */
/*  output uint16 VLVACTINACQ_u16EngInCmPrev3;                                */
/*  output uint8 VLVACTINACQ_u8VehActvStatePrev;                              */
/*  output uint16 VlvAct_nEngInCmAdd;                                         */
/*  output uint16 VlvAct_nEngInCmFil;                                         */
/*  output uint16 Ext_nEngCmInMes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINACQ_vidInCamEngineSpd(void)
{
   uint8   u8LocalVehicleActiveState;
   uint16  u16LocalToothNb;
   uint16  u16LocalVta_intake_tooth_time;
   uint16  u16Localtemp;
   uint16  u16LocalCalc;
   uint32  u32LocalnEngInCm;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicleActiveState);
   if (  (u8LocalVehicleActiveState != VS_STALL)
      && (VLVACTINACQ_u8VehActvStatePrev == VS_STALL))
   {
      VlvAct_nEngInCm = 0;
      VLVACTINACQ_u16EngInCmPrev1 = 0;
      VLVACTINACQ_u16EngInCmPrev2 = 0;
      VLVACTINACQ_u16EngInCmPrev3 = 0;
   }
   else
   {
      VEMS_vidGET(Vta_intake_tooth_time, u16LocalVta_intake_tooth_time);
      if (u16LocalVta_intake_tooth_time != 0)
      {
         u32LocalnEngInCm = (uint32)( (VlvAct_agCmInToothGap_C * 2000)
                                    / u16LocalVta_intake_tooth_time);
         VlvAct_nEngInCm = (uint16)MATHSRV_udtMIN(u32LocalnEngInCm, 7500);
      }
      else
      {
         VlvAct_nEngInCm = 7500;
      }
   }
   VLVACTINACQ_u8VehActvStatePrev = u8LocalVehicleActiveState;

   if (Vta_intake_tooth_nb < 4)
   {
      if (Vta_intake_tooth_nb == 0)
      {
         VlvAct_nEngInCmAdd = VlvAct_nEngInCm;
      }
      else
      {
         if (Vta_intake_tooth_nb == 1)
         {
            u32LocalnEngInCm = (uint32)( VlvAct_nEngInCm
                                       + VLVACTINACQ_u16EngInCmPrev1);
         }
         else
         {
            if (Vta_intake_tooth_nb == 2)
            {
               u32LocalnEngInCm = (uint32)( VlvAct_nEngInCm
                                          + VLVACTINACQ_u16EngInCmPrev1
                                          + VLVACTINACQ_u16EngInCmPrev2);
            }
            else
            {
               u32LocalnEngInCm = (uint32)( VlvAct_nEngInCm
                                          + VLVACTINACQ_u16EngInCmPrev1
                                          + VLVACTINACQ_u16EngInCmPrev2
                                          + VLVACTINACQ_u16EngInCmPrev3);
            }
         }
         VlvAct_nEngInCmAdd = (uint16)MATHSRV_udtMIN(u32LocalnEngInCm, 30000);
      }

      u16LocalToothNb = (uint16)(Vta_intake_tooth_nb + 1);
      u16Localtemp = (uint16)(VlvAct_nEngInCmAdd / u16LocalToothNb);
      u16LocalCalc = (uint16)MATHSRV_udtMIN(u16Localtemp, 8000);
      u16Localtemp = (uint16)MATHSRV_udtMIN(u16Localtemp, 7500);
      VEMS_vidSET(VlvAct_nEngInCmFil, u16Localtemp);
      VEMS_vidSET(Ext_nEngCmInMes, u16LocalCalc);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   VLVACTINACQ_u16EngInCmPrev3 = VLVACTINACQ_u16EngInCmPrev2;
   VLVACTINACQ_u16EngInCmPrev2 = VLVACTINACQ_u16EngInCmPrev1;
   VLVACTINACQ_u16EngInCmPrev1 = VlvAct_nEngInCm;
}
/*------------------------------- end of file --------------------------------*/