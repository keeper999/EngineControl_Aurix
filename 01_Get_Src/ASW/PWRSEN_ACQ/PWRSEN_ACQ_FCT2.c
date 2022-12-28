/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRSEN_ACQ                                              */
/* !Description     : PWRSEN_ACQ Component                                    */
/*                                                                            */
/* !Module          : PWRSEN_ACQ                                              */
/* !Description     : ACQUISITION TENSION ALIMENTATION CAPTEURS               */
/*                                                                            */
/* !File            : PWRSEN_ACQ_FCT2.C                                       */
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
/*   1 / PWRSEN_ACQ_vidAcqDiagVRawMeas2                                       */
/*   2 / PWRSEN_ACQ_vidAcquisition2                                           */
/*   3 / PWRSEN_ACQ_vidDetectFailPwSp2Sdf                                     */
/*   4 / PWRSEN_ACQ_vidDegradModePwSp2Sdf                                     */
/*   5 / PWRSEN_ACQ_vidDiagVRawMes2                                           */
/*   6 / PWRSEN_ACQ_vidInitVEndValMeas2                                       */
/*   7 / PWRSEN_ACQ_vidVEndValMeas2                                           */
/*   8 / PWRSEN_ACQ_vidAlimSchSdlMidAcq                                       */
/*   9 / PWRSEN_ACQ_vidAlimSchSdlFastAcq                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_FCT2.C_v    $*/
/* $Revision::   1.5      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PWRSEN_ACQ.h"
#include "PWRSEN_ACQ_L.h"
#include "PWRSEN_ACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAcqDiagVRawMeas2                             */
/* !Description :  Si la valeur lue n'est pas dans l'intervalle admissible on */
/*                 déclare une panne présente.                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcquisition2();                            */
/*  extf argret void PWRSEN_ACQ_vidDetectFailPwSp2Sdf();                      */
/*  extf argret void PWRSEN_ACQ_vidDegradModePwSp2Sdf();                      */
/*  output boolean Pwr_bMonRunORng_vMes2_Sfty;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcqDiagVRawMeas2(void)
{
   PWRSEN_ACQ_vidAcquisition2();
   PWRSEN_ACQ_vidDetectFailPwSp2Sdf();
   PWRSEN_ACQ_vidDegradModePwSp2Sdf();

   Pwr_bMonRunORng_vMes2_Sfty = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAcquisition2                                 */
/* !Description :  La valeur lue sur le convertisseur est mise à l'échelle en */
/*                 fonction de la sortie du TLE 4471 (tension de référence    */
/*                 divisée par 2).                                            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_capteur_2;                              */
/*  output uint16 Tension_alimentation_2_mesuree;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcquisition2(void)
{
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alim_capteur_2;


   VEMS_vidGET(Tension_alimentation_capteur_2, u16LocalTension_alim_capteur_2);

   u16LocalTension_alim_2_mesuree =
      (uint16)((uint32)(u16LocalTension_alim_capteur_2 + 2) / 4);
   u16LocalTension_alim_2_mesuree =
      (uint16)MATHSRV_udtMIN(u16LocalTension_alim_2_mesuree, 1278);

   VEMS_vidSET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDetectFailPwSp2Sdf                           */
/* !Description :  Cette fonction détecte les éventuels défauts sur           */
/*                 l'alimentation 2 pour la sûreté de fonctionnement.         */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alim_capteur_maxi_sdf;                               */
/*  input uint16 Tension_alim_capteur_mini_sdf;                               */
/*  output boolean Pwr_bDgoORng_vMes2_Sfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDetectFailPwSp2Sdf(void)
{
   uint16 u16LocalTension_alim_2_mesuree;


   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);

   if (  (u16LocalTension_alim_2_mesuree >= Tension_alim_capteur_maxi_sdf)
      || (u16LocalTension_alim_2_mesuree <= Tension_alim_capteur_mini_sdf))
   {
      Pwr_bDgoORng_vMes2_Sfty = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes2_Sfty = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDegradModePwSp2Sdf                           */
/* !Description :  C'est cette valeur brute qui est utilisée par la sûreté de */
/*                 fonctionnement. Si elle est hors des seuils tolérables, on */
/*                 fige la valeur à sa valeur précédente. Lorsque la panne est*/
/*                 mémorisée, le mode dégradé est assuré par la sûreté de     */
/*                 fonctionnement.                                            */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input boolean Pwr_bDgoORng_vMes2_Sfty;                                    */
/*  output uint16 Tension_alimentation_2_brute;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDegradModePwSp2Sdf(void)
{
   uint16 u16LocalTension_alim_2_mesuree;


   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);

   if (Pwr_bDgoORng_vMes2_Sfty == 0)
   {
      u16LocalTension_alim_2_mesuree =
         (uint16)MATHSRV_udtMIN(u16LocalTension_alim_2_mesuree, 1278);
      VEMS_vidSET(Tension_alimentation_2_brute, u16LocalTension_alim_2_mesuree);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDiagVRawMes2                                 */
/* !Description :  La détection du défaut décrite ici est utilisée pour les   */
/*                 capteurs qui ne tolèrent pas d'écart important de la       */
/*                 tension d'alim capteur (mesure pression, ...).             */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alim_capteur_maxi;                                   */
/*  input uint16 Tension_alim_capteur_mini;                                   */
/*  output boolean Pwr_bDgoORng_vMes2;                                        */
/*  output boolean Pwr_bMonRunORng_vMes2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDiagVRawMes2(void)
{
   uint16 u16LocalTension_alim_2_brute;


   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);

   if (  (u16LocalTension_alim_2_brute >= Tension_alim_capteur_maxi)
      || (u16LocalTension_alim_2_brute <= Tension_alim_capteur_mini))
   {
      Pwr_bDgoORng_vMes2 = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes2 = 0;
   }

   Pwr_bMonRunORng_vMes2 = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidInitVEndValMeas2                             */
/* !Description :  Lorsque on a un défaut présent au Reset, la valeur fournie */
/*                 en sortie est la valeur par défaut. Cette valeur ne  doit  */
/*                 pas être utilisée par les modules liés à la sûreté de      */
/*                 fonctionnement.                                            */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Pwr_bDgoORng_vMes2;                                         */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  output uint16 Tension_alimentation_2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidInitVEndValMeas2(void)
{
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alimentation_2;


   if (Pwr_bDgoORng_vMes2 != 0)
   {
      u16LocalTension_alimentation_2 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
      VEMS_vidSET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   }
   else
   {
      VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
      u16LocalTension_alimentation_2 =
         (uint16)MATHSRV_udtMIN(u16LocalTension_alim_2_brute, 1278);
      VEMS_vidSET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidVEndValMeas2                                 */
/* !Description :  Lorsque le défaut sur l'ALIM 2 est détecté, on fige la     */
/*                 valeur envoyée au reste du CMM à la  dernière valeur       */
/*                 valide.  Aussi, lorsqu'il est confirmé on applique une     */
/*                 valeur par défaut est calibrable à la sortie du  module    */
/*                 d'acquisition.                                             */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean ;         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  input boolean Pwr_bDgoORng_vMes2;                                         */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  output uint16 Tension_alimentation_2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidVEndValMeas2(void)
{
   boolean bLocalAcvPwrSenMes2SftyMod;
   uint16  u16LocalTension_alim_2_brute;
   uint16  u16LocalTension_alimentation_2;


   bLocalAcvPwrSenMes2SftyMod = GDGAR_bGetFRM(FRM_FRM_ACVPWRSENMES2SFTYMOD);
   if (bLocalAcvPwrSenMes2SftyMod != 0)
   {
      u16LocalTension_alimentation_2 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
      VEMS_vidSET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   }
   else
   {
      if (Pwr_bDgoORng_vMes2 == 0)
      {
         VEMS_vidGET(Tension_alimentation_2_brute,
                     u16LocalTension_alim_2_brute);
         u16LocalTension_alimentation_2 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_alim_2_brute, 1278);
         VEMS_vidSET(Tension_alimentation_2, u16LocalTension_alimentation_2);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimSchSdlMidAcq                             */
/* !Description :  Attribution l’acquisition de tension d’alimentation au     */
/*                 moniteur moyen pour son utilisation par le capteur de      */
/*                 position papillon                                          */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas2();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes2();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas2();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait );                    */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas3();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes3();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas3();                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas4();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes4();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas4();                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas1();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes1();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas1();                            */
/*  extf argret void PWRSEN_ACQ_vidAlimAps();                                 */
/*  extf argret void PWRSEN_ACQ_vidAlimAc();                                  */
/*  extf argret void PWRSEN_ACQ_vidAlimAirPts();                              */
/*  extf argret void PWRSEN_ACQ_vidAlimPmast();                               */
/*  extf argret void PWRSEN_ACQ_vidBoostPresCf();                             */
/*  extf argret void PWRSEN_ACQ_vidPfuCf();                                   */
/*  extf argret void PWRSEN_ACQ_vidTrbActCf();                                */
/*  extf argret void PWRSEN_ACQ_vidptOilCf();                                 */
/*  extf argret void PWRSEN_ACQ_vidInCmCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidExCmCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidCluPosnCf();                               */
/*  extf argret void PWRSEN_ACQ_vidNeutCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidnEngCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidAccP2Cf();                                 */
/*  input uint8 Conf_alimentation_thr;                                        */
/*  input boolean Pwr_bDgoORng_vMes2;                                         */
/*  input boolean Pwr_bMonRunORng_vMes2;                                      */
/*  input boolean Pwr_bDgoORng_vMes2_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes2_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes3;                                         */
/*  input boolean Pwr_bMonRunORng_vMes3;                                      */
/*  input boolean Pwr_bDgoORng_vMes3_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes3_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes4;                                         */
/*  input boolean Pwr_bMonRunORng_vMes4;                                      */
/*  input boolean Pwr_bDgoORng_vMes4_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes4_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes1;                                         */
/*  input boolean Pwr_bMonRunORng_vMes1;                                      */
/*  input boolean Pwr_bDgoORng_vMes1_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes1_Sfty;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimSchSdlMidAcq(void)
{
   if (Conf_alimentation_thr <= 2)
   {
      /* Call Pwr_Alim2_Acq */
      PWRSEN_ACQ_vidAcqDiagVRawMeas2();
      PWRSEN_ACQ_vidDiagVRawMes2();
      PWRSEN_ACQ_vidVEndValMeas2();
      GDGAR_vidGdu(GD_DFT_ORNG_VMES2,
                   Pwr_bDgoORng_vMes2,
                   Pwr_bMonRunORng_vMes2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_VMES2_SFTY,
                   Pwr_bDgoORng_vMes2_Sfty,
                   Pwr_bMonRunORng_vMes2_Sfty,
                   DIAG_DISPO);
      /* Call Pwr_Alim3_Acq */
      PWRSEN_ACQ_vidAcqDiagVRawMeas3();
      PWRSEN_ACQ_vidDiagVRawMes3();
      PWRSEN_ACQ_vidVEndValMeas3();
      GDGAR_vidGdu(GD_DFT_ORNG_VMES3,
                   Pwr_bDgoORng_vMes3,
                   Pwr_bMonRunORng_vMes3,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_VMES3_SFTY,
                   Pwr_bDgoORng_vMes3_Sfty,
                   Pwr_bMonRunORng_vMes3_Sfty,
                   DIAG_DISPO);
      /* Call Pwr_Alim4_Acq */
      PWRSEN_ACQ_vidAcqDiagVRawMeas4();
      PWRSEN_ACQ_vidDiagVRawMes4();
      PWRSEN_ACQ_vidVEndValMeas4();
      GDGAR_vidGdu(GD_DFT_ORNG_VMES4,
                   Pwr_bDgoORng_vMes4,
                   Pwr_bMonRunORng_vMes4,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_VMES4_SFTY,
                   Pwr_bDgoORng_vMes4_Sfty,
                   Pwr_bMonRunORng_vMes4_Sfty,
                   DIAG_DISPO);
   }
   else
   {
      if (Conf_alimentation_thr <= 5)
      {
         /* Call Pwr_Alim1_Acq */
         PWRSEN_ACQ_vidAcqDiagVRawMeas1();
         PWRSEN_ACQ_vidDiagVRawMes1();
         PWRSEN_ACQ_vidVEndValMeas1();
         GDGAR_vidGdu(GD_DFT_ORNG_VMES1,
                      Pwr_bDgoORng_vMes1,
                      Pwr_bMonRunORng_vMes1,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNG_VMES1_SFTY,
                      Pwr_bDgoORng_vMes1_Sfty,
                      Pwr_bMonRunORng_vMes1_Sfty,
                      DIAG_DISPO);
         /* Call Pwr_Alim3_Acq */
         PWRSEN_ACQ_vidAcqDiagVRawMeas3();
         PWRSEN_ACQ_vidDiagVRawMes3();
         PWRSEN_ACQ_vidVEndValMeas3();
         GDGAR_vidGdu(GD_DFT_ORNG_VMES3,
                      Pwr_bDgoORng_vMes3,
                      Pwr_bMonRunORng_vMes3,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNG_VMES3_SFTY,
                      Pwr_bDgoORng_vMes3_Sfty,
                      Pwr_bMonRunORng_vMes3_Sfty,
                      DIAG_DISPO);
         /* Call Pwr_Alim4_Acq */
         PWRSEN_ACQ_vidAcqDiagVRawMeas4();
         PWRSEN_ACQ_vidDiagVRawMes4();
         PWRSEN_ACQ_vidVEndValMeas4();
         GDGAR_vidGdu(GD_DFT_ORNG_VMES4,
                      Pwr_bDgoORng_vMes4,
                      Pwr_bMonRunORng_vMes4,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNG_VMES4_SFTY,
                      Pwr_bDgoORng_vMes4_Sfty,
                      Pwr_bMonRunORng_vMes4_Sfty,
                      DIAG_DISPO);

      }
      else
      {
         if (Conf_alimentation_thr <= 8)
         {
            /* Call Pwr_Alim1_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas1();
            PWRSEN_ACQ_vidDiagVRawMes1();
            PWRSEN_ACQ_vidVEndValMeas1();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES1,
                         Pwr_bDgoORng_vMes1,
                         Pwr_bMonRunORng_vMes1,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES1_SFTY,
                         Pwr_bDgoORng_vMes1_Sfty,
                         Pwr_bMonRunORng_vMes1_Sfty,
                         DIAG_DISPO);
            /* Call Pwr_Alim2_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas2();
            PWRSEN_ACQ_vidDiagVRawMes2();
            PWRSEN_ACQ_vidVEndValMeas2();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES2,
                         Pwr_bDgoORng_vMes2,
                         Pwr_bMonRunORng_vMes2,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES2_SFTY,
                         Pwr_bDgoORng_vMes2_Sfty,
                         Pwr_bMonRunORng_vMes2_Sfty,
                         DIAG_DISPO);
            /* Call Pwr_Alim4_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas4();
            PWRSEN_ACQ_vidDiagVRawMes4();
            PWRSEN_ACQ_vidVEndValMeas4();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES4,
                         Pwr_bDgoORng_vMes4,
                         Pwr_bMonRunORng_vMes4,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES4_SFTY,
                         Pwr_bDgoORng_vMes4_Sfty,
                         Pwr_bMonRunORng_vMes4_Sfty,
                         DIAG_DISPO);

         }
         else
         {
            /* Call Pwr_Alim1_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas1();
            PWRSEN_ACQ_vidDiagVRawMes1();
            PWRSEN_ACQ_vidVEndValMeas1();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES1,
                         Pwr_bDgoORng_vMes1,
                         Pwr_bMonRunORng_vMes1,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES1_SFTY,
                         Pwr_bDgoORng_vMes1_Sfty,
                         Pwr_bMonRunORng_vMes1_Sfty,
                         DIAG_DISPO);
            /* Call Pwr_Alim2_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas2();
            PWRSEN_ACQ_vidDiagVRawMes2();
            PWRSEN_ACQ_vidVEndValMeas2();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES2,
                         Pwr_bDgoORng_vMes2,
                         Pwr_bMonRunORng_vMes2,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES2_SFTY,
                         Pwr_bDgoORng_vMes2_Sfty,
                         Pwr_bMonRunORng_vMes2_Sfty,
                         DIAG_DISPO);
            /* Call Pwr_Alim3_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas3();
            PWRSEN_ACQ_vidDiagVRawMes3();
            PWRSEN_ACQ_vidVEndValMeas3();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES3,
                         Pwr_bDgoORng_vMes3,
                         Pwr_bMonRunORng_vMes3,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES3_SFTY,
                         Pwr_bDgoORng_vMes3_Sfty,
                         Pwr_bMonRunORng_vMes3_Sfty,
                         DIAG_DISPO);

         }
      }
   }
   /* Call Pwr_SdlMid_Acq_alim */
   PWRSEN_ACQ_vidAlimAps();
   PWRSEN_ACQ_vidAlimAc();
   PWRSEN_ACQ_vidAlimAirPts();
   PWRSEN_ACQ_vidAlimPmast();
   PWRSEN_ACQ_vidBoostPresCf();
   PWRSEN_ACQ_vidPfuCf();
   PWRSEN_ACQ_vidTrbActCf();
   PWRSEN_ACQ_vidptOilCf();
   PWRSEN_ACQ_vidInCmCf();
   PWRSEN_ACQ_vidExCmCf();
   PWRSEN_ACQ_vidCluPosnCf();
   PWRSEN_ACQ_vidNeutCf();
   PWRSEN_ACQ_vidnEngCf();
   PWRSEN_ACQ_vidAccP2Cf();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimSchSdlFastAcq                            */
/* !Description :  Attribution l’acquisition de tension d’alimentation au     */
/*                 moniteur rapide pour son utilisation par le capteur de     */
/*                 position papillon                                          */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas1();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes1();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas1();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait );                    */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas2();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes2();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas2();                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas3();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes3();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas3();                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas4();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes4();                            */
/*  extf argret void PWRSEN_ACQ_vidVEndValMeas4();                            */
/*  extf argret void PWRSEN_ACQ_vidAlimSwitchSdlFast();                       */
/*  input uint8 Conf_alimentation_thr;                                        */
/*  input boolean Pwr_bDgoORng_vMes1;                                         */
/*  input boolean Pwr_bMonRunORng_vMes1;                                      */
/*  input boolean Pwr_bDgoORng_vMes1_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes1_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes2;                                         */
/*  input boolean Pwr_bMonRunORng_vMes2;                                      */
/*  input boolean Pwr_bDgoORng_vMes2_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes2_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes3;                                         */
/*  input boolean Pwr_bMonRunORng_vMes3;                                      */
/*  input boolean Pwr_bDgoORng_vMes3_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes3_Sfty;                                 */
/*  input boolean Pwr_bDgoORng_vMes4;                                         */
/*  input boolean Pwr_bMonRunORng_vMes4;                                      */
/*  input boolean Pwr_bDgoORng_vMes4_Sfty;                                    */
/*  input boolean Pwr_bMonRunORng_vMes4_Sfty;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimSchSdlFastAcq(void)
{
   if (Conf_alimentation_thr <= 2)
   {
      /* Call Pwr_Alim1_Acq */
      PWRSEN_ACQ_vidAcqDiagVRawMeas1();
      PWRSEN_ACQ_vidDiagVRawMes1();
      PWRSEN_ACQ_vidVEndValMeas1();
      GDGAR_vidGdu(GD_DFT_ORNG_VMES1,
                   Pwr_bDgoORng_vMes1,
                   Pwr_bMonRunORng_vMes1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_VMES1_SFTY,
                   Pwr_bDgoORng_vMes1_Sfty,
                   Pwr_bMonRunORng_vMes1_Sfty,
                   DIAG_DISPO);
   }
   else
   {
      if (Conf_alimentation_thr <= 5)
      {
         /* Call Pwr_Alim2_Acq */
         PWRSEN_ACQ_vidAcqDiagVRawMeas2();
         PWRSEN_ACQ_vidDiagVRawMes2();
         PWRSEN_ACQ_vidVEndValMeas2();
         GDGAR_vidGdu(GD_DFT_ORNG_VMES2,
                      Pwr_bDgoORng_vMes2,
                      Pwr_bMonRunORng_vMes2,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ORNG_VMES2_SFTY,
                      Pwr_bDgoORng_vMes2_Sfty,
                      Pwr_bMonRunORng_vMes2_Sfty,
                      DIAG_DISPO);
      }
      else
      {
         if (Conf_alimentation_thr <= 8)
         {
            /* Call Pwr_Alim3_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas3();
            PWRSEN_ACQ_vidDiagVRawMes3();
            PWRSEN_ACQ_vidVEndValMeas3();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES3,
                         Pwr_bDgoORng_vMes3,
                         Pwr_bMonRunORng_vMes3,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES3_SFTY,
                         Pwr_bDgoORng_vMes3_Sfty,
                         Pwr_bMonRunORng_vMes3_Sfty,
                         DIAG_DISPO);
         }
         else
         {
            /* Call Pwr_Alim4_Acq */
            PWRSEN_ACQ_vidAcqDiagVRawMeas4();
            PWRSEN_ACQ_vidDiagVRawMes4();
            PWRSEN_ACQ_vidVEndValMeas4();
            GDGAR_vidGdu(GD_DFT_ORNG_VMES4,
                         Pwr_bDgoORng_vMes4,
                         Pwr_bMonRunORng_vMes4,
                         DIAG_DISPO);
            GDGAR_vidGdu(GD_DFT_ORNG_VMES4_SFTY,
                         Pwr_bDgoORng_vMes4_Sfty,
                         Pwr_bMonRunORng_vMes4_Sfty,
                         DIAG_DISPO);
         }
      }
   }
   /* Call Pwr_SdlFast_Acq_alim */
   PWRSEN_ACQ_vidAlimSwitchSdlFast();
}

/*-------------------------------- end of file -------------------------------*/