/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DSO2SEN                                                 */
/* !Description     : DSO2SEN Component                                       */
/*                                                                            */
/* !Module          : DSO2SEN                                                 */
/* !Description     : ACQUISITION DE LA SONDE A OXYGENE AVAL                  */
/*                                                                            */
/* !File            : DSO2SEN_FCT2.C                                          */
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
/*   1 / DSO2SEN_vidInitDeadZoneCount                                         */
/*   2 / DSO2SEN_vidDiagOCSO2                                                 */
/*   3 / DSO2SEN_vidMngVoltSO2Extrema                                         */
/*   4 / DSO2SEN_vidRunClefOff                                                */
/*   5 / DSO2SEN_vidDiagSCGSO2                                                */
/*   6 / DSO2SEN_vidManageTempoDestock                                        */
/*   7 / DSO2SEN_vidInitTempoDestock                                          */
/*   8 / DSO2SEN_vidTempoBeforeFailure                                        */
/*   9 / DSO2SEN_vidInitCptrAuthorizeFail                                     */
/*   10 / DSO2SEN_vidAnalogMeasurement                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_6563982 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/DSO2SEN/DSO2SEN_FCT2.C_v          $*/
/* $Revision::   1.14                                                        $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "DSO2SEN.h"
#include "DSO2SEN_L.h"
#include "DSO2SEN_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidInitDeadZoneCount                               */
/* !Description :  Initialisation du compteur de la zone morte                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Ldsd_sensor_dead_zone_count;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidInitDeadZoneCount(void)
{
   Ldsd_sensor_dead_zone_count = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidDiagOCSO2                                       */
/* !Description :  Ce diagnostic permet de détecter la présence anormalement  */
/*                 longue de la tension sonde dans une bande morte centrée    */
/*                 autour du point de polarisation, ce qui induit l’absence de*/
/*                 sonde aval ou une mauvaise connexion.                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DSO2SEN_vidDefaultOCSO2();                               */
/*  input boolean Engine_stabilised;                                          */
/*  input st07 Engine_running_state;                                          */
/*  input boolean LsSys_bLsDsMainOxCHeatOkdiag;                               */
/*  input boolean Lshd_down_lbda_sens_heat_active;                            */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Ldsd_seuil_temp_eau_diag_masse;                               */
/*  output boolean Ext_bMonRunOc_uDsLs;                                       */
/*  output boolean Ext_bMonWaitOc_DsO2Sen;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidDiagOCSO2(void)
{
   boolean bLocalInhDsO2SenOcDiag;
   boolean bLocalEngine_stabilised;
   boolean bLocalLsSys_bLDMainOxCHeatOkdiag;
   boolean bLocalLshd_dn_lbda_sens_heat_act;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalTemperature_eau;


   bLocalInhDsO2SenOcDiag = GDGAR_bGetFRM(FRM_FRM_INHDSO2SENOCDIAG);

   VEMS_vidGET(Engine_stabilised, bLocalEngine_stabilised);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOkdiag,
               bLocalLsSys_bLDMainOxCHeatOkdiag);
   VEMS_vidGET(Lshd_down_lbda_sens_heat_active,
               bLocalLshd_dn_lbda_sens_heat_act);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);

   if (  (bLocalEngine_stabilised != 0)
      && (u8LocalEngine_running_state != ERUN_FULL_LOAD)
      && (bLocalLsSys_bLDMainOxCHeatOkdiag != 0)
      && (bLocalLshd_dn_lbda_sens_heat_act != 0)
      && (u8LocalTemperature_eau > Ldsd_seuil_temp_eau_diag_masse)
      && (bLocalInhDsO2SenOcDiag == 0))
   {
      Ext_bMonRunOc_uDsLs = 1;
      DSO2SEN_vidDefaultOCSO2();
   }
   else
   {
      Ext_bMonRunOc_uDsLs = 0;
   }
   Ext_bMonWaitOc_DsO2Sen = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidMngVoltSO2Extrema                               */
/* !Description :  Gestion de la tension sonde extreme                        */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input boolean DC_bSyncGlbDC;                                              */
/*  input uint16 Inhibe_extrema_sonde_count;                                  */
/*  input boolean Ext_bMonRunScp_uDsLs;                                       */
/*  input uint16 Tension_sonde_av_max_dc;                                     */
/*  input boolean Ext_bMonRunScg_uDsLs;                                       */
/*  input uint16 Tension_sonde_av_min_dc;                                     */
/*  input uint16 Tension_sonde_av_max_cycle;                                  */
/*  input uint16 Tension_sonde_av_min_cycle;                                  */
/*  output uint16 Tension_sonde_av_max_dc;                                    */
/*  output uint16 Tension_sonde_av_min_dc;                                    */
/*  output uint16 Tension_sonde_av_max_cycle;                                 */
/*  output uint16 Tension_sonde_av_min_cycle;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidMngVoltSO2Extrema(void)
{
   boolean bLocalDC_bSyncGlbDC;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalTension_sonde_avalclp;
   uint16  u16LocalInhibe_extrema_sonde_cnt;
   uint16  u16LocalTension_sonde_av_max_dc;
   uint16  u16LocalTension_sonde_av_min_dc;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(DC_bSyncGlbDC, bLocalDC_bSyncGlbDC);
   VEMS_vidGET(Inhibe_extrema_sonde_count, u16LocalInhibe_extrema_sonde_cnt);

   if (u16LocalInhibe_extrema_sonde_cnt == 0)
   {
      u16LocalTension_sonde_avalclp =
         (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1023);

      if (  (Ext_bMonRunScp_uDsLs != 0)
         && (u16LocalTension_sonde_aval > Tension_sonde_av_max_dc))
      {
         Tension_sonde_av_max_dc = u16LocalTension_sonde_avalclp;
      }
      else
      {
         Tension_sonde_av_max_dc =
            (uint16)MATHSRV_udtMIN(Tension_sonde_av_max_dc, 1023);
      }

      if (  (Ext_bMonRunScg_uDsLs != 0)
         && (u16LocalTension_sonde_aval < Tension_sonde_av_min_dc))
      {
         Tension_sonde_av_min_dc = u16LocalTension_sonde_avalclp;
      }
      else
      {
         Tension_sonde_av_min_dc =
            (uint16)MATHSRV_udtMIN(Tension_sonde_av_min_dc, 1023);
      }

      if (bLocalDC_bSyncGlbDC != 0)
      {
         u16LocalTension_sonde_av_max_dc = Tension_sonde_av_max_dc;
         u16LocalTension_sonde_av_min_dc = Tension_sonde_av_min_dc;
      }
      else
      {
         VEMS_vidGET(Tension_sonde_av_max_cycle,
                     u16LocalTension_sonde_av_max_dc);
         u16LocalTension_sonde_av_max_dc =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_av_max_dc, 1023);

         VEMS_vidGET(Tension_sonde_av_min_cycle,
                     u16LocalTension_sonde_av_min_dc);
         u16LocalTension_sonde_av_min_dc =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_av_min_dc, 1023);

      }
   }
   else
   {
      Tension_sonde_av_min_dc = (uint16)MATHSRV_udtMIN(Tension_sonde_av_min_dc,
                                                       1023);
      Tension_sonde_av_max_dc = (uint16)MATHSRV_udtMIN(Tension_sonde_av_max_dc,
                                                       1023);

      VEMS_vidGET(Tension_sonde_av_max_cycle,
                  u16LocalTension_sonde_av_max_dc);
      u16LocalTension_sonde_av_max_dc =
         (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_av_max_dc, 1023);

      VEMS_vidGET(Tension_sonde_av_min_cycle,
                  u16LocalTension_sonde_av_min_dc);
      u16LocalTension_sonde_av_min_dc =
         (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_av_min_dc, 1023);
   }

   VEMS_vidSET(Tension_sonde_av_max_cycle, u16LocalTension_sonde_av_max_dc);
   VEMS_vidSET(Tension_sonde_av_min_cycle, u16LocalTension_sonde_av_min_dc);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidRunClefOff                                      */
/* !Description :  Commande du clé off                                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean Sonde_riche_aval;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidRunClefOff(void)
{
   boolean bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (bLocalClef_de_contact == 0)
   {
      VEMS_vidSET(Sonde_riche_aval, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidDiagSCGSO2                                      */
/* !Description :  Ce bloc permet de détecter un court-circuit à la masse sur */
/*                 la sonde aval. Le principe de cette détection repose sur le*/
/*                 fait que lors d'un CC masse, le signal sonde vaut environ  */
/*                 0V.                                                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_010.01                                     */
/*                 VEMS_R_08_05194_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DSO2SEN_vidManageTempoDestock();                         */
/*  extf argret void DSO2SEN_vidTempoBeforeFailure();                         */
/*  extf argret void DSO2SEN_vidInitCptrAuthorizeFail();                      */
/*  extf argret void DSO2SEN_vidInitTempoDestock();                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ldsd_tension_so2_filter_gain;                                 */
/*  input uint32 DSO2SEN_FiltredPositionMem;                                  */
/*  input uint16 Mf_emiss_sum_uavn0;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Auto_injection;                                             */
/*  input boolean Engine_stabilised;                                          */
/*  input uint16 Ldsd_mass_diag_mf_emiss_thresh;                              */
/*  input uint16 Ldsd_destockage_so2_av_count;                                */
/*  input uint8 Ldsd_seuil_temp_eau_diag_masse;                               */
/*  input uint16 Tension_sonde_aval_filtre;                                   */
/*  input uint16 Ldsd_seuil_tension_so2_masse;                                */
/*  input uint16 Ldsd_confirm_def_so2_av_count;                               */
/*  output uint16 Tension_sonde_aval_filtre;                                  */
/*  output boolean Ext_bDgoScg_uDsLs;                                         */
/*  output boolean Ext_bMonRunScg_uDsLs;                                      */
/*  output boolean Ext_bMonWaitScg_uDsLs;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidDiagSCGSO2(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalEngine_stabilised;
   boolean bLocalFailure;
   boolean bLocalInhDsO2SenScgDiag;
   boolean bLocalInhDsO2SenDiagEl;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalVehicle_active_state;
   uint16  u16LocalMf_emiss_sum_uavn0;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalTension_sonde_aval_filt;


   bLocalInhDsO2SenScgDiag = GDGAR_bGetFRM(FRM_FRM_INHDSO2SENSCGDIAG);
   bLocalInhDsO2SenDiagEl = GDGAR_bGetFRM(FRM_FRM_INHDSO2SENDIAGEL);

   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   u16LocalTension_sonde_aval_filt =
      MATHSRV_u16FirstOrderFilterGu8(Ldsd_tension_so2_filter_gain,
                                     &DSO2SEN_FiltredPositionMem,
                                     u16LocalTension_sonde_aval);
   Tension_sonde_aval_filtre =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval_filt, 1023);

   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Engine_stabilised, bLocalEngine_stabilised);

   if(  (bLocalAuto_injection != 0)
     && (u8LocalVehicle_active_state == VS_RUNNING))
   {
      DSO2SEN_vidManageTempoDestock();
      if(  (bLocalEngine_stabilised != 0)
        && (bLocalInhDsO2SenScgDiag == 0)
        && (u16LocalMf_emiss_sum_uavn0 <= Ldsd_mass_diag_mf_emiss_thresh)
        && (Ldsd_destockage_so2_av_count == 0)
        && (u8LocalTemperature_eau > Ldsd_seuil_temp_eau_diag_masse)
        && (Tension_sonde_aval_filtre <= Ldsd_seuil_tension_so2_masse))
      {
         DSO2SEN_vidTempoBeforeFailure();
         bLocalFailure = 1;
      }
      else
      {
         DSO2SEN_vidInitCptrAuthorizeFail();
         bLocalFailure = 0;
      }
   }
   else
   {
      DSO2SEN_vidInitCptrAuthorizeFail();
      DSO2SEN_vidInitTempoDestock();
      bLocalFailure = 0;
   }

   if (bLocalInhDsO2SenDiagEl == 0)
   {
      if(  (Ldsd_confirm_def_so2_av_count == 0)
        && (bLocalFailure != 0))
      {
         Ext_bDgoScg_uDsLs = 1;
         Ext_bMonRunScg_uDsLs = 1;
      }
      else
      {
         Ext_bDgoScg_uDsLs = 0;

         if(Tension_sonde_aval_filtre > Ldsd_seuil_tension_so2_masse)
         {
            Ext_bMonRunScg_uDsLs = 1;
         }
         else
         {
            Ext_bMonRunScg_uDsLs = 0;
         }
      }
   }
   else
   {
      Ext_bDgoScg_uDsLs = 0;
      Ext_bMonRunScg_uDsLs = 0;
   }
   Ext_bMonWaitScg_uDsLs = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidManageTempoDestock                              */
/* !Description :  Ce bloc permet de détecter un court-circuit à la masse sur */
/*                 la sonde aval. Le principe de cette détection repose sur le*/
/*                 fait que lors d'un CC masse, le signal sonde vaut environ  */
/*                 0V.                                                        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_destockage_so2_av_count;                                */
/*  output uint16 Ldsd_destockage_so2_av_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidManageTempoDestock(void)
{
   sint32 s32LocalLdsdDestockageSo2AvCount;


   s32LocalLdsdDestockageSo2AvCount = (sint32)( Ldsd_destockage_so2_av_count
                                              - 1);
   Ldsd_destockage_so2_av_count =
      (uint16)MATHSRV_udtCLAMP(s32LocalLdsdDestockageSo2AvCount, 0, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidInitTempoDestock                                */
/* !Description :  Initialisation de tempo de destockage                      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_destockage_so2_av_delay;                                */
/*  output uint16 Ldsd_destockage_so2_av_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidInitTempoDestock(void)
{
   Ldsd_destockage_so2_av_count =
      (uint16)MATHSRV_udtMIN(Ldsd_destockage_so2_av_delay, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidTempoBeforeFailure                              */
/* !Description :  Tempo avant autorisation panne                             */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_confirm_def_so2_av_count;                               */
/*  output uint16 Ldsd_confirm_def_so2_av_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidTempoBeforeFailure(void)
{
   sint32 s32LocalLdsdConfirmDefSo2AvCount;


   s32LocalLdsdConfirmDefSo2AvCount = (sint32)( Ldsd_confirm_def_so2_av_count
                                              - 1);
   Ldsd_confirm_def_so2_av_count =
      (uint16)MATHSRV_udtCLAMP(s32LocalLdsdConfirmDefSo2AvCount, 0, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidInitCptrAuthorizeFail                           */
/* !Description :  Initialisation du compteur qui  autorise la panne          */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_confirm_def_so2_av_delay;                               */
/*  output uint16 Ldsd_confirm_def_so2_av_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidInitCptrAuthorizeFail(void)
{
   Ldsd_confirm_def_so2_av_count =
      (uint16)MATHSRV_udtMIN(Ldsd_confirm_def_so2_av_delay, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidAnalogMeasurement                               */
/* !Description :  Mesure analoguique de la sonde aval.                       */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acq_tension_sonde_o2_av;                                     */
/*  output uint16 Plus_sonde_o2_av_result_ad_conv;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidAnalogMeasurement(void)
{
   uint16 u16LocalSonde_o2_av_rslt_ad_conv;
   uint16 u16LocalAcq_tension_sonde_o2_av;


   VEMS_vidGET(Acq_tension_sonde_o2_av, u16LocalAcq_tension_sonde_o2_av);
   u16LocalSonde_o2_av_rslt_ad_conv =
      (uint16)((uint32)(u16LocalAcq_tension_sonde_o2_av + 2) / 4);
   Plus_sonde_o2_av_result_ad_conv =
      (uint16)MATHSRV_udtMIN(u16LocalSonde_o2_av_rslt_ad_conv, 1023);
}
/*-------------------------------- end of file -------------------------------*/