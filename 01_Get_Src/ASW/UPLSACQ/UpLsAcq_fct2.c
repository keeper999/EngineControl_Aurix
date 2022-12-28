/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : UPLSACQ                                                 */
/* !Description     : UPLSACQ component.                                      */
/*                                                                            */
/* !Module          : UPLSACQ                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AMONT                 */
/*                                                                            */
/* !File            : UPLSACQ_fct2.C                                          */
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
/*   1 / UPLSACQ_vidSO2UsDefaultCountDec                                      */
/*   2 / UPLSACQ_vidSenO2UsFiltSyncEngine                                     */
/*   3 / UPLSACQ_vidSenO2UsFiltStallEng                                       */
/*   4 / UPLSACQ_vidSenO2UsDiagGroundMngt                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6562315 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/UPLSACQ/UPLSACQ_FCT2.c_v          $*/
/* $Revision::   1.8      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "UPLSACQ.H"
#include "UPLSACQ_L.H"
#include "UPLSACQ_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSO2UsDefaultCountDec                            */
/* !Description :  Calcul du temps minimal après démarrage moteur à partir    */
/*                 duquel la sonde est considérée comme chaude                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsen_active_dead_zone_count;                                */
/*  output uint16 Ldsen_active_dead_zone_count;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSO2UsDefaultCountDec(void)
{
   if (Ldsen_active_dead_zone_count != 0)
   {
      Ldsen_active_dead_zone_count = (uint16)(Ldsen_active_dead_zone_count - 1);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsFiltSyncEngine                           */
/* !Description :  fonctionnement de la sonde en moteur synchronisé           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void UPLSACQ_vidFilteringSyncEngine();                        */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Seuil_regime_moteur_filt_so2_am;                              */
/*  input boolean UPLSACQ_bFiltSondeEnablePrev;                               */
/*  input uint16 Tension_sonde_amont_brute;                                   */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev1;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev2;                             */
/*  output uint16 UPLSACQ_u16SenO2UsVoltagePrev3;                             */
/*  output boolean UPLSACQ_bFiltSondeEnablePrev;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsFiltSyncEngine(void)
{
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalSeuilRegMotFilt;
   uint16  u16LocalTension_sonde_amont_brut;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalSeuilRegMotFilt = (uint16)(Seuil_regime_moteur_filt_so2_am * 32);

   if (u16LocalRegime_moteur >= u16LocalSeuilRegMotFilt)
   {
      if (UPLSACQ_bFiltSondeEnablePrev == 0)
      {
         VEMS_vidGET(Tension_sonde_amont_brute,
                     u16LocalTension_sonde_amont_brut);
         UPLSACQ_u16SenO2UsVoltagePrev1 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont_brut, 1023);
         UPLSACQ_u16SenO2UsVoltagePrev2 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont_brut, 1023);
         UPLSACQ_u16SenO2UsVoltagePrev3 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont_brut, 1023);
      }
      UPLSACQ_vidFilteringSyncEngine();
      UPLSACQ_bFiltSondeEnablePrev = 1;
   }
   else
   {
      UPLSACQ_bFiltSondeEnablePrev = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsFiltStallEng                             */
/* !Description :  Fonctionnement en moteur cale                              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :   Lazhar DHIB                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void UPLSACQ_vidFilteringStallEngine();                       */
/*  input uint16 Regime_moteur;                                               */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint8 Seuil_regime_moteur_filt_so2_am;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsFiltStallEng(void)
{
   boolean bLocalMoteur_synchronise;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   if (  (u16LocalRegime_moteur < (Seuil_regime_moteur_filt_so2_am * 32))
      || (bLocalMoteur_synchronise == 0))
   {
      UPLSACQ_vidFilteringStallEngine();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  UPLSACQ_vidSenO2UsDiagGroundMngt                           */
/* !Description :  Detection d'un court-circuit à la masse sur la sonde amont */
/* !Number      :  FCT2.4                                                     */
/* !Author      :   Lazhar DHIB                                               */
/* !Trace_To    :  VEMS_R_08_04819_004.01                                     */
/*                 VEMS_R_08_04819_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint16 Mf_emiss_sum_uavn0;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean Auto_injection;                                             */
/*  input boolean Engine_stabilised;                                          */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Ldsen_tension_so2_filter_gain;                                */
/*  input uint32 UPLSACQ_u32FiltredVoltageMem;                                */
/*  input uint16 Ldsen_gas_course_so2_am_count;                               */
/*  input uint16 Ldsen_gas_course_so2_am_delay;                               */
/*  input uint16 UPLSACQ_u16SenO2UsFiltred;                                   */
/*  input uint16 Ldsen_seuil_tension_so2_masse;                               */
/*  input uint16 Ldsen_masse_diag_mf_emiss_thresh;                            */
/*  input uint8 Ldsen_seuil_temp_eau_diag_masse;                              */
/*  input uint16 Ldsen_confirm_def_so2_am_count;                              */
/*  input uint16 Ldsen_confirm_def_so2_am_delay;                              */
/*  output boolean Ext_bMonWaitScg_uUpLs;                                     */
/*  output uint16 UPLSACQ_u16SenO2UsFiltred;                                  */
/*  output uint16 Ldsen_gas_course_so2_am_count;                              */
/*  output uint16 Ldsen_confirm_def_so2_am_count;                             */
/*  output boolean Ext_bDgoScg_uUpLs;                                         */
/*  output boolean Ext_bMonRunScg_uUpLs;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void UPLSACQ_vidSenO2UsDiagGroundMngt(void)
{
   boolean bLocalData;
   boolean bLocalInhSenO2UsScgDiag;
   boolean bLocalInhUpLsAcqDiagEl;
   boolean bLocalExtDgoScgUUpLs;
   boolean bLocalExtMonRunScgUUpLs;
   boolean bLocalAuto_injection;
   boolean bLocalEngine_stabilised;
   uint8   u8LocalFilterGain;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalTension_sonde_amont;
   uint16  u16LocalMf_emiss_sum_uavn0;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Engine_stabilised, bLocalEngine_stabilised);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   Ext_bMonWaitScg_uUpLs = 0;
   bLocalInhSenO2UsScgDiag = GDGAR_bGetFRM(FRM_FRM_INHSENO2USSCGDIAG);
   bLocalInhUpLsAcqDiagEl = GDGAR_bGetFRM(FRM_FRM_INHUPLSACQDIAGEL);
   bLocalData = 0;
   bLocalExtDgoScgUUpLs = 0;
   bLocalExtMonRunScgUUpLs = 0;
   u8LocalFilterGain =
            (uint8)MATHSRV_udtMIN((Ldsen_tension_so2_filter_gain + 1), 255);
   UPLSACQ_u16SenO2UsFiltred =
      MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                     &UPLSACQ_u32FiltredVoltageMem,
                                     u16LocalTension_sonde_amont);

   if (  (bLocalAuto_injection != 0)
      && (u8LocalVehicle_active_state == VS_RUNNING))
   {
      if (Ldsen_gas_course_so2_am_count > 52428)
      {
         Ldsen_gas_course_so2_am_count = 52428;
      }
      else
      {
         if (Ldsen_gas_course_so2_am_count > 1)
         {
            Ldsen_gas_course_so2_am_count =
               (uint16)(Ldsen_gas_course_so2_am_count - 1);
         }
         else
         {
            Ldsen_gas_course_so2_am_count = 0;
            bLocalData = 1;
         }
      }
   }
   else
   {
      Ldsen_gas_course_so2_am_count =
         (uint16)MATHSRV_udtMIN(Ldsen_gas_course_so2_am_delay, 52428);
   }

   if (UPLSACQ_u16SenO2UsFiltred < Ldsen_seuil_tension_so2_masse)
   {
      if (  (bLocalData != 0)
         && (bLocalEngine_stabilised != 0)
         && (u16LocalMf_emiss_sum_uavn0 <= Ldsen_masse_diag_mf_emiss_thresh)
         && (bLocalInhSenO2UsScgDiag == 0)
         && (u8LocalTemperature_eau > Ldsen_seuil_temp_eau_diag_masse))
      {
         if (Ldsen_confirm_def_so2_am_count > 52428)
         {
            Ldsen_confirm_def_so2_am_count = 52428;
         }
         else
         {
            if (Ldsen_confirm_def_so2_am_count > 1)
            {
               Ldsen_confirm_def_so2_am_count =
                  (uint16)(Ldsen_confirm_def_so2_am_count - 1);
            }
            else
            {
               Ldsen_confirm_def_so2_am_count = 0;
               if (bLocalInhUpLsAcqDiagEl == 0)
               {
                  bLocalExtDgoScgUUpLs = 1;
                  bLocalExtMonRunScgUUpLs = 1;
               }
            }
         }
      }
      else
      {
         Ldsen_confirm_def_so2_am_count =
            (uint16)MATHSRV_udtMIN(Ldsen_confirm_def_so2_am_delay, 52428);
      }
   }
   else
   {
      Ldsen_confirm_def_so2_am_count =
         (uint16)MATHSRV_udtMIN(Ldsen_confirm_def_so2_am_delay, 52428);
      if (bLocalInhUpLsAcqDiagEl == 0)
      {
         bLocalExtMonRunScgUUpLs = 1;
      }
   }
   Ext_bDgoScg_uUpLs = bLocalExtDgoScgUUpLs;
   Ext_bMonRunScg_uUpLs = bLocalExtMonRunScgUUpLs;
}
/*------------------------------- end of file --------------------------------*/