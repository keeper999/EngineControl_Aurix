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
/* !File            : VLVACTEXACQ_FCT2.C                                      */
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
/*   1 / VLVACTEXACQ_vidExhaustRisingCapt                                     */
/*   2 / VLVACTEXACQ_vidTraitementXDent                                       */
/*   3 / VLVACTEXACQ_vidExhaustCaptCalc                                       */
/*   4 / VLVACTEXACQ_vidExhaustCalcul                                         */
/*   5 / VLVACTEXACQ_vidExhaustDiagnosis                                      */
/*   6 / VLVACTEXACQ_vidExCamEngineSpd                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6588648 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/VLVACT/VLVACTEX/VLVACTEXACQ/VLVACT$*/
/* $Revision::   1.27     $$Author::   wbouach        $$Date::   02 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "VLVACTEXACQ.h"
#include "VLVACTEXACQ_L.h"
#include "VLVACTEXACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustRisingCapt                           */
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
/*  extf argret void VLVACTEXACQ_vidTraitementXDent();                        */
/*  input uint16 Acquisition_angle_vilb_aac_ech;                              */
/*  input uint16 Ext_agCmExMesTbl[4];                                         */
/*  input uint32 Acquisition_temps_dents_aac_ech;                             */
/*  input boolean VlvAct_bExSelTypIniCntCmTooth_C;                            */
/*  input uint8 Vta_exhaust_tooth_counter;                                    */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  input uint16 VlvAct_agExMaxFrntGap_C;                                     */
/*  input boolean VlvAct_bMonRunMissToothVlvActEx;                            */
/*  output uint8 Vta_exhaust_pmh_counter;                                     */
/*  output uint16 Ext_agCmExMes;                                              */
/*  output uint16 Ext_agCmExMesTbl[4];                                        */
/*  output uint16 Vta_exhaust_tooth_time;                                     */
/*  output uint16 Ext_tiPatCmEx;                                              */
/*  output uint8 Vta_exhaust_tooth_counter;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustRisingCapt(void)
{
   uint8  u8LocalEng_noCmbCyl;
   uint8  u8LocalVta_exhaust_tooth_counter;
   uint16 u16LocalToothNb;
   uint16 u16LocalAgCmExMes;
   uint16 u16LocalCounter;
   uint16 u16LocalVtaExtToothTime;
   uint16 u16LocalTemp;
   uint16 u16LocalVcpeCamOffsetsMAX;
   uint16 u16LocalExtAgCmExMesTblMAX;
   uint16 u16LocalVcpe_cam_offsets[VLVACTEXACQ_u8CAM_LENGTH];
   uint16 u16LocalAcqnglevilbaacech;
   uint16 u16LocalMod;
   uint32 u32LocalAcqTempsDentsaacech;
   uint32 u32LocalDiv;
   uint32 u32LocalResult;
   sint16 s16LocalVta_exhaust_tooth_countr;
   sint16 s16LocalDiff;
   sint32 s32LocalDiff;


   Vta_exhaust_pmh_counter = 0;
   /* CAMEXHAL */

   VEMS_vidGET(Acquisition_angle_vilb_aac_ech, u16LocalAcqnglevilbaacech);
   u16LocalAgCmExMes = (uint16)(u16LocalAcqnglevilbaacech / 6);
   u16LocalAgCmExMes = (uint16)MATHSRV_udtMIN(u16LocalAgCmExMes, 7679);
   VEMS_vidSET(Ext_agCmExMes, u16LocalAgCmExMes);
   Ext_agCmExMesTbl[3] = (uint16)MATHSRV_udtMIN(Ext_agCmExMesTbl[2], 7679);
   Ext_agCmExMesTbl[2] = (uint16)MATHSRV_udtMIN(Ext_agCmExMesTbl[1], 7679);
   Ext_agCmExMesTbl[1] = (uint16)MATHSRV_udtMIN(Ext_agCmExMesTbl[0], 7679);
   Ext_agCmExMesTbl[0] = u16LocalAgCmExMes;
   /* CAMEXHAL1 */
   VEMS_vidGET(Acquisition_temps_dents_aac_ech, u32LocalAcqTempsDentsaacech);
   if (u32LocalAcqTempsDentsaacech > 268435455)
   {
      u32LocalDiv = u32LocalAcqTempsDentsaacech / 625;
      u16LocalMod =(uint16)(u32LocalAcqTempsDentsaacech % 625);
      u32LocalResult = u32LocalDiv + ((u16LocalMod * 16) / 625);
   }
   else
   {
      u32LocalResult = (u32LocalAcqTempsDentsaacech * 16) / 625;
   }
   u16LocalVtaExtToothTime = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   VEMS_vidSET(Vta_exhaust_tooth_time, u16LocalVtaExtToothTime);
   VEMS_vidSET(Ext_tiPatCmEx, u16LocalVtaExtToothTime);

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

   if (  (Ext_agCmExMesTbl[0] != 0)
      && (Ext_agCmExMesTbl[1] != 0)
      && (Ext_agCmExMesTbl[2] != 0)
      && (Ext_agCmExMesTbl[3] != 0))
   {
      VEMS_vidGET1DArray(Vcpe_cam_offsets,
                         VLVACTEXACQ_u8CAM_LENGTH,
                         u16LocalVcpe_cam_offsets);
      u16LocalVcpeCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpe_cam_offsets[0],
                                u16LocalVcpe_cam_offsets[1]);
      u16LocalVcpeCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpeCamOffsetsMAX,
                                u16LocalVcpe_cam_offsets[2]);
      u16LocalVcpeCamOffsetsMAX =
         (uint16)MATHSRV_udtMAX(u16LocalVcpeCamOffsetsMAX,
                                u16LocalVcpe_cam_offsets[3]);

      u16LocalExtAgCmExMesTblMAX =
         (uint16)MATHSRV_udtMAX(Ext_agCmExMesTbl[0], Ext_agCmExMesTbl[1]);
      u16LocalExtAgCmExMesTblMAX =
         (uint16)MATHSRV_udtMAX(u16LocalExtAgCmExMesTblMAX,
                                Ext_agCmExMesTbl[2]);
      u16LocalExtAgCmExMesTblMAX =
         (uint16)MATHSRV_udtMAX(u16LocalExtAgCmExMesTblMAX,
                                Ext_agCmExMesTbl[3]);

      s32LocalDiff =
         (sint32)(u16LocalVcpeCamOffsetsMAX - u16LocalExtAgCmExMesTblMAX);
      u16LocalTemp = (uint16)MATHSRV_udtABS(s32LocalDiff);
   }
   else
   {
      u16LocalTemp = 0;
   }

   if (u16LocalTemp >= VlvAct_agExMaxFrntGap_C)
   {
      s16LocalDiff = (sint16)( s16LocalVta_exhaust_tooth_countr
                             + Vta_exhaust_tooth_nb);
      u16LocalToothNb = (uint16)(Vta_exhaust_tooth_nb + 1);
      s16LocalDiff = (sint16)(s16LocalDiff % u16LocalToothNb);
      u8LocalVta_exhaust_tooth_counter = (uint8)MATHSRV_udtMIN(s16LocalDiff, 3);
   }
   else
   {
      u8LocalVta_exhaust_tooth_counter =
         (uint8)MATHSRV_udtCLAMP(s16LocalVta_exhaust_tooth_countr, 0, 3);
   }
   VEMS_vidSET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);

   if (VlvAct_bMonRunMissToothVlvActEx != 0)
   {
      VLVACTEXACQ_vidTraitementXDent();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidTraitementXDent                             */
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
/*  input uint16 Vta_exhaust_noMultPeriod;                                    */
/*  input uint16 Vta_exhaust_tooth_time;                                      */
/*  input uint8 Vta_exhaust_tooth_counter;                                    */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  output boolean VlvAct_bDgoMissToothVlvActEx;                              */
/*  output uint8 Vta_exhaust_tooth_counter;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidTraitementXDent(void)
{
   uint8  u8LocalCounter;
   uint8  u8LocalVta_exhaust_tooth_counter;
   uint16 u16LocalTouthNb;
   uint16 u16LocalVta_exhaust_tooth_time;
   uint16 u16LocalPeriode_moteur;
   uint16 u16LocalTemp;
   uint16 u16LocalMin;
   uint32 u32LocalTemp1;
   uint32 u32LocalTemp2;


   VEMS_vidGET(Periode_moteur, u16LocalPeriode_moteur);
   u32LocalTemp1 = u16LocalPeriode_moteur * Vta_exhaust_noMultPeriod;
   if (u32LocalTemp1 > (UINT32_MAX / (uint32)24))
   {
      u32LocalTemp2 = (u32LocalTemp1 / 625) * 24;
   }
   else
   {
      u32LocalTemp2 = (u32LocalTemp1 * 24) / 625;
   }
   u16LocalMin = (uint16)MATHSRV_udtMIN(u32LocalTemp2, 65535);
   VEMS_vidGET(Vta_exhaust_tooth_time, u16LocalVta_exhaust_tooth_time);
   VEMS_vidGET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);

   if (u16LocalVta_exhaust_tooth_time > u16LocalMin)
   {
      VlvAct_bDgoMissToothVlvActEx = 1;

      u16LocalTemp = (uint16)(u8LocalVta_exhaust_tooth_counter + 1);
      u16LocalTouthNb = (uint16)(Vta_exhaust_tooth_nb + 1);

      u16LocalTemp =
         (uint16)(MATHSRV_udtMIN(u16LocalTemp, 255) % u16LocalTouthNb);

      u8LocalVta_exhaust_tooth_counter = (uint8)MATHSRV_udtMIN(u16LocalTemp, 3);
   }
   else
   {
      VlvAct_bDgoMissToothVlvActEx = 0;
      u16LocalTouthNb = (uint16)(Vta_exhaust_tooth_nb + 1);
      u8LocalCounter =
         (uint8)(u8LocalVta_exhaust_tooth_counter % u16LocalTouthNb);
      u8LocalVta_exhaust_tooth_counter =
         (uint8)MATHSRV_udtMIN(u8LocalCounter, 3);
   }
   VEMS_vidSET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustCaptCalc                             */
/* !Description :  Fonction de calcul du décalage à partir des mesures sur les*/
/*                 fronts dents AAC                                           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXACQ_vidExhaustCalcul();                          */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustCaptCalc(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn;


   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   if (bLocalVlvAct_bExOfsFrstLrn != 0)
   {
      VLVACTEXACQ_vidExhaustCalcul();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustCalcul                               */
/* !Description :  Fonction de calcul de la valeur de la vitesse de décalage  */
/*                 de l’AAC d’échappement                                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 Vta_exhaust_tooth_counter;                                    */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  input uint16 Ext_agCmExMes;                                               */
/*  input boolean Vta_exhaust_advance_config;                                 */
/*  input uint16 Vta_exhaust_lower_def_limit;                                 */
/*  input uint16 Vta_exhaust_higher_def_limit;                                */
/*  output sint16 Vta_exhaust_camshaft_shift;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustCalcul(void)
{
   uint8  u8LocalVta_exhaust_tooth_counter;
   uint16 u16LocalVcpi_cam_offsets[VLVACTEXACQ_u8CAM_LENGTH];
   uint16 u16LocalExt_agCmInMes;
   sint32 s32LocalCalc;
   sint32 s32LocalAdd;


   VEMS_vidGET(Vta_exhaust_tooth_counter, u8LocalVta_exhaust_tooth_counter);

   if (u8LocalVta_exhaust_tooth_counter > 3)
   {
      SWFAIL_vidSoftwareErrorHook();
   }
   else
   {
      VEMS_vidGET1DArray(Vcpe_cam_offsets,VLVACTEXACQ_u8CAM_LENGTH,
                     u16LocalVcpi_cam_offsets);

      VEMS_vidGET(Ext_agCmExMes, u16LocalExt_agCmInMes);
      if (Vta_exhaust_advance_config != 0)
      {
         s32LocalCalc =
            (sint32)( u16LocalVcpi_cam_offsets[u8LocalVta_exhaust_tooth_counter]
                    - u16LocalExt_agCmInMes);
      }
      else
      {
         s32LocalCalc =
            (sint32)( u16LocalExt_agCmInMes
                    - u16LocalVcpi_cam_offsets[u8LocalVta_exhaust_tooth_counter]
                    );
      }
      s32LocalAdd = s32LocalCalc + EVC_CYCLE_LENGHT_EX;
      if (  ((s32LocalCalc + Vta_exhaust_lower_def_limit) <= 0)
         && (s32LocalAdd < Vta_exhaust_higher_def_limit))
      {
         Vta_exhaust_camshaft_shift =
            (sint16)MATHSRV_udtMAX(s32LocalAdd, -7680);
      }
      else
      {
         if (  (s32LocalCalc >= Vta_exhaust_higher_def_limit)
            && ( ( (s32LocalCalc - EVC_CYCLE_LENGHT_EX)
                 + Vta_exhaust_lower_def_limit)
               > 0))
         {
            Vta_exhaust_camshaft_shift = (sint16)
               MATHSRV_udtMIN((s32LocalCalc - EVC_CYCLE_LENGHT_EX), 7679);
         }
         else
         {
            Vta_exhaust_camshaft_shift =
               (sint16)MATHSRV_udtCLAMP(s32LocalCalc, -7680, 7679);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExhaustDiagnosis                            */
/* !Description :  Cette fonction réalise le diagnostic pmh                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_nEngExORngShiftThdLo_C;                               */
/*  input uint16 VlvAct_nEngExORngShiftThdLoHys_C;                            */
/*  input boolean VLVACTEXACQ_bnEngExORngShiftThd;                            */
/*  input sint16 Vta_exhaust_camshaft_shift;                                  */
/*  input uint16 Vta_exhaust_lower_def_limit;                                 */
/*  input uint16 Vta_exhaust_higher_def_limit;                                */
/*  input boolean VlvAct_bDgoTDCDiagVlvActEx;                                 */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  output boolean VLVACTEXACQ_bnEngExORngShiftThd;                           */
/*  output boolean Vta_exhaust_velocity_set;                                  */
/*  output boolean VlvAct_bDgoORngShiftVlvActEx;                              */
/*  output uint16 VLVACTEXACQ_u16RelInVvtMesPrev;                             */
/*  output uint16 Vxx_rel_ex_vvt_mes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExhaustDiagnosis(void)
{
   boolean bLocalresult;
   uint16  u16LocalVxx_rel_ex_vvt_mes;
   uint16  u16LocalExt_nEng;
   sint32  s32Localdiff;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   s32Localdiff =
      (sint32)( VlvAct_nEngExORngShiftThdLo_C
              - VlvAct_nEngExORngShiftThdLoHys_C);
   if (VLVACTEXACQ_bnEngExORngShiftThd == 0)
   {
      if (u16LocalExt_nEng >= VlvAct_nEngExORngShiftThdLo_C)
      {
         VLVACTEXACQ_bnEngExORngShiftThd = 1;
      }
      else
      {
         VLVACTEXACQ_bnEngExORngShiftThd = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32Localdiff)
      {
         VLVACTEXACQ_bnEngExORngShiftThd = 0;
      }
      else
      {
         VLVACTEXACQ_bnEngExORngShiftThd = 1;
      }
   }
   s32Localdiff =
      (sint32)(Vta_exhaust_camshaft_shift + Vta_exhaust_lower_def_limit);
   if (  (Vta_exhaust_camshaft_shift >= Vta_exhaust_higher_def_limit)
      || (s32Localdiff <= 0))
   {
      Vta_exhaust_velocity_set = 0;
      bLocalresult = 1;
   }
   else
   {
      bLocalresult = 0;
   }
   if (  (VLVACTEXACQ_bnEngExORngShiftThd != 0)
      && (bLocalresult == 1))
   {
      VlvAct_bDgoORngShiftVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoORngShiftVlvActEx = 0;
   }
   if (  (bLocalresult == 0)
      && (VlvAct_bDgoTDCDiagVlvActEx == 0))
   {
      VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
      VLVACTEXACQ_u16RelInVvtMesPrev = u16LocalVxx_rel_ex_vvt_mes;
      u16LocalVxx_rel_ex_vvt_mes =
         (uint16)MATHSRV_udtCLAMP(Vta_exhaust_camshaft_shift, 0, 1066);
      VEMS_vidSET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXACQ_vidExCamEngineSpd                              */
/* !Description :  Fonction pour la reconstitution du  régime moteur à partir */
/*                 de l’intervalle  de temps et de l’écart angulaire théorique*/
/*                 entre deux évènements dents AAC échappement.               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean VlvAct_bDgoMissToothVlvActEx;                               */
/*  input uint8 VLVACTEXACQ_u8VehActivStatePrev;                              */
/*  input uint16 Vta_exhaust_tooth_time;                                      */
/*  input uint16 VlvAct_agCmExToothGap_C;                                     */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  input uint16 VlvAct_nEngExCm;                                             */
/*  input uint16 VLVACTEXACQ_u16EngInCmPrev1;                                 */
/*  input uint16 VLVACTEXACQ_u16EngInCmPrev2;                                 */
/*  input uint16 VLVACTEXACQ_u16EngInCmPrev3;                                 */
/*  input uint16 VlvAct_nEngExCmAdd;                                          */
/*  output uint16 VlvAct_nEngExCm;                                            */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev1;                                */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev2;                                */
/*  output uint16 VLVACTEXACQ_u16EngInCmPrev3;                                */
/*  output uint16 VlvAct_nEngExCmAdd;                                         */
/*  output uint16 VlvAct_nEngExCmFil;                                         */
/*  output uint16 Ext_nEngCmExMes;                                            */
/*  output uint8 VLVACTEXACQ_u8VehActivStatePrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXACQ_vidExCamEngineSpd(void)
{
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalToothNb;
   uint16  u16LocalVta_exhaust_tooth_time;
   uint16  u16Localtemp;
   uint16  u16LocalCalc;
   uint32  u32LocalnEngExCm;


   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);

   if (VlvAct_bDgoMissToothVlvActEx == 0)
   {
      if (  (u8LocalVehicle_active_state != VS_STALL)
         && (VLVACTEXACQ_u8VehActivStatePrev == VS_STALL))
      {
         VlvAct_nEngExCm = 0;
         VLVACTEXACQ_u16EngInCmPrev1 = 0;
         VLVACTEXACQ_u16EngInCmPrev2 = 0;
         VLVACTEXACQ_u16EngInCmPrev3 = 0;
      }
      else
      {
         VEMS_vidGET(Vta_exhaust_tooth_time, u16LocalVta_exhaust_tooth_time);
         if (u16LocalVta_exhaust_tooth_time != 0)
         {
            u32LocalnEngExCm = (uint32)( (VlvAct_agCmExToothGap_C * 2000)
                                       / u16LocalVta_exhaust_tooth_time);
            VlvAct_nEngExCm = (uint16)MATHSRV_udtMIN(u32LocalnEngExCm, 7500);
         }
         else
         {
            VlvAct_nEngExCm = 7500;
         }
      }
      if (Vta_exhaust_tooth_nb < 4)
      {
         if (Vta_exhaust_tooth_nb == 0)
         {
            VlvAct_nEngExCmAdd = VlvAct_nEngExCm;
         }
         else
         {
            if (Vta_exhaust_tooth_nb == 1)
            {
               u32LocalnEngExCm = (uint32)( VlvAct_nEngExCm
                                          + VLVACTEXACQ_u16EngInCmPrev1);
            }
            else
            {
               if (Vta_exhaust_tooth_nb == 2)
               {
                  u32LocalnEngExCm = (uint32)( VlvAct_nEngExCm
                                             + VLVACTEXACQ_u16EngInCmPrev1
                                             + VLVACTEXACQ_u16EngInCmPrev2);
               }
               else
               {
                  u32LocalnEngExCm = (uint32)( VlvAct_nEngExCm
                                             + VLVACTEXACQ_u16EngInCmPrev1
                                             + VLVACTEXACQ_u16EngInCmPrev2
                                             + VLVACTEXACQ_u16EngInCmPrev3);
               }
            }
            VlvAct_nEngExCmAdd = (uint16)MATHSRV_udtMIN(u32LocalnEngExCm,
                                                        30000);
         }

         u16LocalToothNb = (uint16)(Vta_exhaust_tooth_nb + 1);
         u16Localtemp = (uint16)(VlvAct_nEngExCmAdd / u16LocalToothNb);
         u16LocalCalc = (uint16)MATHSRV_udtMIN(u16Localtemp, 8000);
         u16Localtemp = (uint16)MATHSRV_udtMIN(u16Localtemp, 7500);
         VEMS_vidSET(VlvAct_nEngExCmFil, u16Localtemp);
         VEMS_vidSET(Ext_nEngCmExMes, u16LocalCalc);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }

      VLVACTEXACQ_u16EngInCmPrev3 = VLVACTEXACQ_u16EngInCmPrev2;
      VLVACTEXACQ_u16EngInCmPrev2 = VLVACTEXACQ_u16EngInCmPrev1;
      VLVACTEXACQ_u16EngInCmPrev1 = VlvAct_nEngExCm;
      VLVACTEXACQ_u8VehActivStatePrev = u8LocalVehicle_active_state;
   }
}
/*------------------------------- end of file --------------------------------*/