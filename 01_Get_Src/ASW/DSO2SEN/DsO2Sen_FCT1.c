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
/* !File            : DSO2SEN_FCT1.C                                          */
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
/*   1 / DSO2SEN_vidInitOutput                                                */
/*   2 / DSO2SEN_vidMngDownStreamSO2                                          */
/*   3 / DSO2SEN_vidVoltSO2WithoutDefect                                      */
/*   4 / DSO2SEN_vidDiagCCSO2                                                 */
/*   5 / DSO2SEN_vidCalDownStreamSO2                                          */
/*   6 / DSO2SEN_vidSO2LeanToRich                                             */
/*   7 / DSO2SEN_vidSO2RichToLean                                             */
/*   8 / DSO2SEN_vidFreezeDownStreamSO2                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6563982 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/DSO2SEN/DSO2SEN_FCT1.C_v          $*/
/* $Revision::   1.13                                                        $*/
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
/* !Function    :  DSO2SEN_vidInitOutput                                      */
/* !Description :  Initialisation des sorties au Reset ECU                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 So2_av_signal_no_fail;                                      */
/*  output uint16 So2_av_signal_failure;                                      */
/*  output uint8 Compteur_transition_sonde_aval;                              */
/*  output boolean Sonde_riche_aval;                                          */
/*  output uint16 Tension_sonde_aval;                                         */
/*  output uint16 Tension_sonde_aval_brute;                                   */
/*  output uint16 Tension_sonde_av_min_dc;                                    */
/*  output uint16 Tension_sonde_av_max_dc;                                    */
/*  output uint32 DSO2SEN_FiltredPositionMem;                                 */
/*  output uint16 Tension_sonde_aval_int;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidInitOutput(void)
{
   VEMS_vidSET(So2_av_signal_no_fail, 0);
   VEMS_vidSET(So2_av_signal_failure, 0);
   VEMS_vidSET(Compteur_transition_sonde_aval, 0);
   VEMS_vidSET(Sonde_riche_aval, 0);
   VEMS_vidSET(Tension_sonde_aval, 0);
   VEMS_vidSET(Tension_sonde_aval_brute, 0);
   Tension_sonde_av_min_dc = 1023;
   Tension_sonde_av_max_dc = 0;
   DSO2SEN_FiltredPositionMem = 0;
   Tension_sonde_aval_int = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidMngDownStreamSO2                                */
/* !Description :  Fonction permettant l’acquisition de la tension de la sonde*/
/*                 aval et la simulation du comportement d’une sonde viellie. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void DSO2SEN_vidVoltSO2WithoutDefect();                       */
/*  extf argret void DSO2SEN_vidBenchModeDownStream();                        */
/*  input boolean Clef_de_contact;                                            */
/*  input uint16 Plus_sonde_o2_av_result_ad_conv;                             */
/*  input uint16 Seuil_maxi_tension_sonde;                                    */
/*  input boolean Mode_banc_sonde_aval;                                       */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Tension_sonde_aval_int;                                      */
/*  output uint16 Tension_sonde_aval_brute;                                   */
/*  output uint16 Tension_sonde_aval;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidMngDownStreamSO2(void)
{
   boolean bLocalClef_de_contact;
   uint16  u16LocalTension_sonde_aval_brute;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalTension_sonde;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (bLocalClef_de_contact != 0)
   {
      u16LocalTension_sonde_aval_brute =
         (uint16)MATHSRV_udtMIN(Plus_sonde_o2_av_result_ad_conv, 1023);
      VEMS_vidSET(Tension_sonde_aval_brute, u16LocalTension_sonde_aval_brute);

      if (u16LocalTension_sonde_aval_brute < Seuil_maxi_tension_sonde)
      {
         DSO2SEN_vidVoltSO2WithoutDefect();
      }

      if (Mode_banc_sonde_aval != 0)
      {
         DSO2SEN_vidBenchModeDownStream();
         VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
         u16LocalTension_sonde =
            (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1023);
      }
      else
      {
         u16LocalTension_sonde =
            (uint16)MATHSRV_udtMIN(Tension_sonde_aval_int, 1023);
      }

      VEMS_vidSET(Tension_sonde_aval, u16LocalTension_sonde);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidVoltSO2WithoutDefect                            */
/* !Description :  Fonction calculant la tension différentielle de la sonde   */
/*                 aval avant le mode banc.                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval_brute;                                    */
/*  output uint16 Tension_sonde_aval_int;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidVoltSO2WithoutDefect(void)
{
   uint16 u16LocalTension_sonde_aval_brute;


   VEMS_vidGET(Tension_sonde_aval_brute, u16LocalTension_sonde_aval_brute);
   Tension_sonde_aval_int =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval_brute, 1023);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidDiagCCSO2                                       */
/* !Description :  Gestion tension sonde aval en daig CC                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_002.01                                     */
/*                 VEMS_R_08_05194_003.01                                     */
/*                 VEMS_R_08_05194_004.01                                     */
/*                 VEMS_R_08_05194_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DSO2SEN_vidCalDownStreamSO2();                           */
/*  extf argret void DSO2SEN_vidSO2LeanToRich();                              */
/*  extf argret void DSO2SEN_vidSO2RichToLean();                              */
/*  extf argret void DSO2SEN_vidFreezeDownStreamSO2();                        */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Seuil_sonde_aval_riche;                                      */
/*  input uint16 Seuil_sonde_aval_pauvre;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidDiagCCSO2(void)
{
   boolean bLocalInhDsO2SenFuRatClcn;
   boolean bLocalClef_de_contact;
   boolean bLocalSonde_riche_aval;
   uint16  u16LocalTension_sonde_aval;


   bLocalInhDsO2SenFuRatClcn = GDGAR_bGetFRM(FRM_FRM_INHDSO2SENFURATCLCN);

   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Sonde_riche_aval, bLocalSonde_riche_aval);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);

   if (bLocalClef_de_contact != 0)
   {
      DSO2SEN_vidCalDownStreamSO2();

      if (bLocalInhDsO2SenFuRatClcn == 0)
      {
         if (  (bLocalSonde_riche_aval == 0)
            && (u16LocalTension_sonde_aval >= Seuil_sonde_aval_riche))
         {
            DSO2SEN_vidSO2LeanToRich();
         }
         else
         {
            if (  (bLocalSonde_riche_aval != 0)
               && (u16LocalTension_sonde_aval < Seuil_sonde_aval_riche)
               && (u16LocalTension_sonde_aval < Seuil_sonde_aval_pauvre))
            {
               DSO2SEN_vidSO2RichToLean();
            }
         }
      }
      else
      {
         DSO2SEN_vidFreezeDownStreamSO2();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidCalDownStreamSO2                                */
/* !Description :  Calcul de la tension sonde aval                            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_05194_006.01                                     */
/*                 VEMS_R_08_05194_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Plus_sonde_o2_av_result_ad_conv;                             */
/*  input uint16 Seuil_maxi_tension_sonde;                                    */
/*  output uint16 So2_av_signal_no_fail;                                      */
/*  output boolean Ext_bMonWaitScp_uDsLs;                                     */
/*  output boolean Ext_bMonRunScp_uDsLs;                                      */
/*  output boolean Ext_bDgoScp_uDsLs;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidCalDownStreamSO2(void)
{
   uint16  u16LocalSo2AvSignalNoFail;
   boolean bLocalInhDsO2SenDiagEl;


   bLocalInhDsO2SenDiagEl = GDGAR_bGetFRM(FRM_FRM_INHDSO2SENDIAGEL);
   u16LocalSo2AvSignalNoFail =
      (uint16)MATHSRV_udtMIN(Plus_sonde_o2_av_result_ad_conv, 1023);
   VEMS_vidSET(So2_av_signal_no_fail, u16LocalSo2AvSignalNoFail);

   Ext_bMonWaitScp_uDsLs = 0;

   if (bLocalInhDsO2SenDiagEl == 0)
   {
      Ext_bMonRunScp_uDsLs = 1;
   }
   else
   {
      Ext_bMonRunScp_uDsLs = 0;
   }

   if (Plus_sonde_o2_av_result_ad_conv >= Seuil_maxi_tension_sonde)
   {
      if (bLocalInhDsO2SenDiagEl == 0)
      {
         Ext_bDgoScp_uDsLs = 1;
      }
      else
      {
         Ext_bDgoScp_uDsLs = 0;
      }
   }
   else
   {
      Ext_bDgoScp_uDsLs = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidSO2LeanToRich                                   */
/* !Description :  Sonde  pauvre au riche                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Compteur_transition_sonde_aval;                               */
/*  output boolean Sonde_riche_aval;                                          */
/*  output uint8 Compteur_transition_sonde_aval;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidSO2LeanToRich(void)
{
   uint8  u8LocalCompteurTransSondeAval;
   uint16 u16LocalCompteurTransSondeAval;


   /* sonde_lean_to_rich */
   VEMS_vidSET(Sonde_riche_aval, 1);
   VEMS_vidGET(Compteur_transition_sonde_aval, u8LocalCompteurTransSondeAval);
   u16LocalCompteurTransSondeAval = (uint16)(u8LocalCompteurTransSondeAval + 1);
   u8LocalCompteurTransSondeAval =
      (uint8)MATHSRV_udtMIN(u16LocalCompteurTransSondeAval, 255);
   VEMS_vidSET(Compteur_transition_sonde_aval, u8LocalCompteurTransSondeAval);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidSO2RichToLean                                   */
/* !Description :  Sonde riche ou pauvre                                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Compteur_transition_sonde_aval;                               */
/*  output boolean Sonde_riche_aval;                                          */
/*  output uint8 Compteur_transition_sonde_aval;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidSO2RichToLean(void)
{
   uint8  u8LocalCompteurTransSondeAval;
   uint16 u16LocalCompteurTransSondeAval;


   /* sonde_rich_to_lean */
   VEMS_vidSET(Sonde_riche_aval, 0);
   VEMS_vidGET(Compteur_transition_sonde_aval, u8LocalCompteurTransSondeAval);
   u16LocalCompteurTransSondeAval = (uint16)(u8LocalCompteurTransSondeAval + 1);
   u8LocalCompteurTransSondeAval =
      (uint8)MATHSRV_udtMIN(u16LocalCompteurTransSondeAval, 255);
   VEMS_vidSET(Compteur_transition_sonde_aval, u8LocalCompteurTransSondeAval);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DSO2SEN_vidFreezeDownStreamSO2                             */
/* !Description :  Blocage de la sonde aval                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sonde_riche_aval;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DSO2SEN_vidFreezeDownStreamSO2(void)
{
   /* freeze_sonde_aval */
   VEMS_vidSET(Sonde_riche_aval, 0);
}
/*-------------------------------- end of file -------------------------------*/
