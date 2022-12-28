/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACPRESACQ                                               */
/* !Description     : ACPRESACQ component                                     */
/*                                                                            */
/* !Module          : ACPRESACQ                                               */
/* !Description     : ACQUISITION DE LA PRESSION DU FLUIDE REFRIGERANT        */
/*                                                                            */
/* !File            : ACPRESACQ_FCT1.C                                        */
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
/*   1 / ACPRESACQ_vidInitOutput                                              */
/*   2 / ACPRESACQ_vidInit                                                    */
/*   3 / ACPRESACQ_vidPressure_refri                                          */
/*   4 / ACPRESACQ_vidDiagnosisConversion                                     */
/*   5 / ACPRESACQ_vidElectricDiagnosis                                       */
/*   6 / ACPRESACQ_vidFiltering                                               */
/*   7 / ACPRESACQ_VidPressRefriDiagFunc                                      */
/*   8 / ACPRESACQ_vidFunctionalDetection                                     */
/*   9 / ACPRESACQ_vidMgtDefaultTracking                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6545428 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACPRESACQ/ACPRESACQ_FCT1.C_v      $*/
/* $Revision::   1.4      $$Author::   wbouach        $$Date::   14 May 2014 $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACPRESACQ.h"
#include "ACPRESACQ_L.h"
#include "ACPRESACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidInitOutput                                    */
/* !Description :  Fonction qui initialise les sorties.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean ACPRESACQ_bFilteringInit;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidInitOutput(void)
{
   ACPRESACQ_bFilteringInit = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidInit                                          */
/* !Description :  L'acquisition de la pression de fluide réfrigérant doit    */
/*                 être effectué dès le réveil principal  du calculateur .    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Cl_pressure_diag_trk_delay;                                   */
/*  output uint8 Cl_pressure_diag_trk_count;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidInit(void)
{
   Cl_pressure_diag_trk_count =
     (uint8)MATHSRV_udtMIN(Cl_pressure_diag_trk_delay,160);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidPressure_refri                                */
/* !Description :  En cas de défaut sur la batterie, la détection de défaut   */
/*                 est inhibée ; dans le cas d'un  défaut sur les             */
/*                 alimentations capteurs, la détection de défaut est inhibée */
/*                 sur le groupe de capteurs alimenté par l'alimentation en   */
/*                 défaut                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ACPRESACQ_vidDiagnosisConversion();                      */
/*  extf argret void ACPRESACQ_vidFiltering();                                */
/*  input uint16 Acquis_tension_press_refri;                                  */
/*  input boolean Cf_bAcvLnrClimSenAcq;                                       */
/*  input boolean Manu_inh_clim;                                              */
/*  output uint16 Cl_pressure_result_ad_conv;                                 */
/*  output boolean Ext_bMonRunHi_pACMes;                                      */
/*  output boolean Ext_bMonRunLo_pACMes;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidPressure_refri(void)
{
   boolean bLocalINHACPRESACQELDIAG;
   boolean bLocalCf_bAcvLnrClimSenAcq;
   uint16  u16LocalAcqu_tension_press_refri;
   uint16  u16LocalCl_press_result_ad_conv;


   VEMS_vidGET(Acquis_tension_press_refri, u16LocalAcqu_tension_press_refri);
   u16LocalCl_press_result_ad_conv =
      (uint16)MATHSRV_udtMIN(u16LocalAcqu_tension_press_refri, 4095);
   VEMS_vidSET(Cl_pressure_result_ad_conv, u16LocalCl_press_result_ad_conv);

   VEMS_vidGET(Cf_bAcvLnrClimSenAcq, bLocalCf_bAcvLnrClimSenAcq);

   bLocalINHACPRESACQELDIAG = GDGAR_bGetFRM(FRM_FRM_INHACPRESACQELDIAG);

   if (  (Manu_inh_clim == 0)
      && (bLocalCf_bAcvLnrClimSenAcq != 0))
   {
      if (bLocalINHACPRESACQELDIAG == 0)
      {
         Ext_bMonRunHi_pACMes = 1;
         Ext_bMonRunLo_pACMes = 1;
      }
      else
      {
         Ext_bMonRunHi_pACMes = 0;
         Ext_bMonRunLo_pACMes = 0;
      }
      ACPRESACQ_vidDiagnosisConversion();
      ACPRESACQ_vidFiltering();
   }
   else
   {
      Ext_bMonRunHi_pACMes = 0;
      Ext_bMonRunLo_pACMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidDiagnosisConversion                           */
/* !Description :  Le signal de ratiométrie de tension (-) est converti via un*/
/*                 gain (Pa/-) et un offset (Pa) en  signal de pression (Pa)  */
/*                 La dynamique de la pression de fluide réfrigérant est      */
/*                 [0..4194240] Pa et de résolution 64  Pa.                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACPRESACQ_vidElectricDiagnosis();                        */
/*  input uint16 Tension_alimentation_ac;                                     */
/*  input uint16 Cl_pressure_result_ad_conv;                                  */
/*  input uint16 Cl_voltage_pressure_slope;                                   */
/*  input sint16 Cl_voltage_pressure_offset;                                  */
/*  output uint16 Cl_pressure_result_ratio;                                   */
/*  output uint16 Cl_raw_pressure;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidDiagnosisConversion(void)
{
   uint16 u16LocalCl_raw_pressure;
   uint16 u16LocalTension_alimentation_ac;
   uint16 u16LocalCl_press_result_ad_conv;
   uint32 u32LocalCl_pressure_result_ratio;
   uint32 u32LocalCl_raw_pressure;
   sint32 s32LocalCl_raw_pressure;


   VEMS_vidGET(Tension_alimentation_ac, u16LocalTension_alimentation_ac);

   if (u16LocalTension_alimentation_ac != 0)
   {
      VEMS_vidGET(Cl_pressure_result_ad_conv, u16LocalCl_press_result_ad_conv);
      u32LocalCl_pressure_result_ratio =
         (uint32)(u16LocalCl_press_result_ad_conv * 65536);
      u32LocalCl_pressure_result_ratio =
         ( u32LocalCl_pressure_result_ratio
         / (uint32)u16LocalTension_alimentation_ac);
      Cl_pressure_result_ratio =
         (uint16)MATHSRV_udtMIN(u32LocalCl_pressure_result_ratio, 65535);

      u32LocalCl_raw_pressure =
         (uint32)(u16LocalCl_press_result_ad_conv * Cl_voltage_pressure_slope);
      s32LocalCl_raw_pressure = ( (sint32)u32LocalCl_raw_pressure
                                / (sint32)u16LocalTension_alimentation_ac);
   }
   else
   {
      Cl_pressure_result_ratio = 65535;

      u32LocalCl_raw_pressure = (uint32)(Cl_voltage_pressure_slope * 65535);
      s32LocalCl_raw_pressure = (sint32)(u32LocalCl_raw_pressure / 65536);
   }

   s32LocalCl_raw_pressure =
      (s32LocalCl_raw_pressure + (sint32)Cl_voltage_pressure_offset);
   u16LocalCl_raw_pressure =
      (uint16)MATHSRV_udtCLAMP(s32LocalCl_raw_pressure, 0, 65535);

   VEMS_vidSET(Cl_raw_pressure, u16LocalCl_raw_pressure);

   ACPRESACQ_vidElectricDiagnosis();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidElectricDiagnosis                             */
/* !Description :  Ce sous-système compare la tension issue du capteur aux    */
/*                 valeurs minimales et  maximales de fonctionnement du       */
/*                 capteur dans la zone correcte.                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Cl_pressure_result_ratio;                                    */
/*  input uint16 Ac_cooling_max_ratio_value;                                  */
/*  input uint16 Ac_cooling_min_ratio_value;                                  */
/*  output boolean Ext_bDgoHi_pACMes;                                         */
/*  output boolean Ext_bDgoLo_pACMes;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidElectricDiagnosis(void)
{
   if (Cl_pressure_result_ratio > Ac_cooling_max_ratio_value)
   {
      Ext_bDgoHi_pACMes = 1;
   }
   else
   {
      Ext_bDgoHi_pACMes = 0;
   }
   if (Cl_pressure_result_ratio < Ac_cooling_min_ratio_value)
   {
      Ext_bDgoLo_pACMes = 1;
   }
   else
   {
      Ext_bDgoLo_pACMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidFiltering                                     */
/* !Description :  On réalise un filtrage passe-bas de la tension capteur. A  */
/*                 cet effet, on utilise la méthode  des rectangles supérieurs*/
/*                 qui donne le signal filtré en fonction du signal non filtré*/
/*                 à  l'instant courant et du signal filtré à l'instant       */
/*                 précédent.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_06201_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cl_raw_pressure;                                             */
/*  input boolean ACPRESACQ_bFilteringInit;                                   */
/*  input uint16 Cl_default_pressure;                                         */
/*  input boolean Ext_bDgoHi_pACMes;                                          */
/*  input boolean Ext_bDgoLo_pACMes;                                          */
/*  input uint16 Cl_current_pressure;                                         */
/*  input uint16 Cl_coeff_filtre_pression_refri;                              */
/*  output boolean ACPRESACQ_bFilteringInit;                                  */
/*  output uint16 Cl_current_pressure;                                        */
/*  output uint16 Cl_raw_pressure_prec;                                       */
/*  output uint16 Cl_pressure;                                                */
/*  output uint16 AC_pACMes;                                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidFiltering(void)
{
   boolean bLocalACVDFTMOD_PACMES;
   uint16  u16Local;
   uint16  u16Local2;
   uint16  u16Local3;
   uint16  u16LocalCl_raw_pressure;
   sint16  s16Local;


   bLocalACVDFTMOD_PACMES  = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PACMES);

   if (ACPRESACQ_bFilteringInit == 0)
   {
      ACPRESACQ_bFilteringInit = 1;
      Cl_current_pressure = Cl_default_pressure;
      Cl_raw_pressure_prec = Cl_default_pressure;
   }
   else
   {
      if (  (Ext_bDgoHi_pACMes == 0)
         && (Ext_bDgoLo_pACMes == 0))
      {
         VEMS_vidGET(Cl_raw_pressure, u16LocalCl_raw_pressure);
         if ( u16LocalCl_raw_pressure > Cl_current_pressure )
         {
            u16Local = (uint16)(u16LocalCl_raw_pressure - Cl_current_pressure);
            u16Local = (uint16)
              ( ( (uint32)(u16Local * Cl_coeff_filtre_pression_refri)) / 65536);
            Cl_current_pressure = (uint16)(u16Local + Cl_current_pressure);
         }
         else
         {
            u16Local = (uint16)(Cl_current_pressure - u16LocalCl_raw_pressure);
            s16Local = (sint16)(-(sint16)( ( (uint32)(u16Local
                                   * Cl_coeff_filtre_pression_refri)) / 65536));
            Cl_current_pressure =(uint16)(s16Local + Cl_current_pressure);
         }
      }
   }
   if (bLocalACVDFTMOD_PACMES != 0)
   {
      u16Local2 = Cl_default_pressure;
   }
   else
   {
      u16Local2 = Cl_current_pressure;
   }

   VEMS_vidSET(Cl_pressure, u16Local2);

   u16Local3 = (uint16)( ( (uint32)(u16Local2 * 1024)) / 100000);
   u16Local3 = (uint16)MATHSRV_udtMIN(u16Local3, 640);

   VEMS_vidSET(AC_pACMes, u16Local3);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_VidPressRefriDiagFunc                            */
/* !Description :  Outre le test électrique, un test fonctionnel sur le       */
/*                 gradient est effectué. Si le gradient dépasse la           */
/*                 calibration  Ac_cooling_max_tracker_value, la panne        */
/*                 Ext_bDgoGrd_pACMes est générée.                            */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ACPRESACQ_vidFunctionalDetection();                      */
/*  input boolean Cf_bAcvLnrClimSenAcq;                                       */
/*  input boolean Manu_inh_clim;                                              */
/*  input boolean Ext_bMonRunGrdSng_pACMes;                                   */
/*  output boolean Ext_bMonRunGrd_pACMes;                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_VidPressRefriDiagFunc(void)
{
   boolean bLocalINHACPRESACQELDIAG;
   boolean bLocalCf_bAcvLnrClimSenAcq;


   VEMS_vidGET(Cf_bAcvLnrClimSenAcq, bLocalCf_bAcvLnrClimSenAcq);

   bLocalINHACPRESACQELDIAG  = GDGAR_bGetFRM(FRM_FRM_INHACPRESACQELDIAG);
   if (  (Manu_inh_clim == 0)
      && (bLocalCf_bAcvLnrClimSenAcq != 0)
      && (bLocalINHACPRESACQELDIAG == 0)
      )
   {
      ACPRESACQ_vidFunctionalDetection();
      if (Ext_bMonRunGrdSng_pACMes != 0)
      {
         Ext_bMonRunGrd_pACMes = 1;
      }
   }
   else
   {
      Ext_bMonRunGrd_pACMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidFunctionalDetection                           */
/* !Description :  Ce système génère la panne fonctionnelle.                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ACPRESACQ_vidMgtDefaultTracking();                       */
/*  input uint16 Cl_raw_pressure;                                             */
/*  input uint8 Cl_pressure_diag_trk_count;                                   */
/*  input uint16 Cl_raw_pressure_prec;                                        */
/*  input boolean Ext_bDgoHi_pACMes;                                          */
/*  input boolean Ext_bDgoLo_pACMes;                                          */
/*  output uint8 Cl_pressure_diag_trk_count;                                  */
/*  output uint16 Ac_cooling_pressure_trk_delta;                              */
/*  output boolean Ext_bMonRunGrdSng_pACMes;                                  */
/*  output uint16 Cl_raw_pressure_prec;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidFunctionalDetection(void)
{
   boolean bLocalACVDFTMOD_PACMES;
   uint16  u16LocalCl_raw_pressure;


   VEMS_vidGET(Cl_raw_pressure, u16LocalCl_raw_pressure);

   bLocalACVDFTMOD_PACMES  = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PACMES);
   Cl_pressure_diag_trk_count =
     (uint8)MATHSRV_udtMAX((Cl_pressure_diag_trk_count - 1),0);
   Ac_cooling_pressure_trk_delta =
     (uint16)MATHSRV_udtABS((u16LocalCl_raw_pressure - Cl_raw_pressure_prec));
   if (  (Cl_pressure_diag_trk_count == 0)
      && ( (  (Ext_bDgoHi_pACMes == 0)
           && (Ext_bDgoLo_pACMes == 0)
           && (bLocalACVDFTMOD_PACMES == 0)
           ))
      )
   {
      Ext_bMonRunGrdSng_pACMes = 1;
      ACPRESACQ_vidMgtDefaultTracking();
   }
   else
   {
      Ext_bMonRunGrdSng_pACMes = 0;
   }
   Cl_raw_pressure_prec = u16LocalCl_raw_pressure;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACPRESACQ_vidMgtDefaultTracking                            */
/* !Description :  Le coefficient AC_SampleTiMid_SC permet de prendre en      */
/*                 compte la période d'activation de la fonction tout en      */
/*                 conservant Ac_cooling_max_tracker_value en kPa/s (et non   */
/*                 pas en kPa/ AC_SampleTiMid_SC s).                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ac_cooling_max_tracker_value;                                */
/*  input uint16 Ac_cooling_pressure_trk_delta;                               */
/*  output boolean Ext_bDgoGrd_pACMes;                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACPRESACQ_vidMgtDefaultTracking(void)
{
   uint32 u32LocalThresh;

   u32LocalThresh =
      (Ac_cooling_max_tracker_value * (uint32)AC_SampleTiMid_SC)/64;
   if ( Ac_cooling_pressure_trk_delta > u32LocalThresh )
   {
      Ext_bDgoGrd_pACMes = 1;
   }
   else
   {
      Ext_bDgoGrd_pACMes = 0;
   }
}
/*------------------------------- end of file --------------------------------*/