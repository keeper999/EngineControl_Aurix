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
/* !File            : PWRSEN_ACQ_FCT3.C                                       */
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
/*   1 / PWRSEN_ACQ_vidAcqDiagVRawMeas3                                       */
/*   2 / PWRSEN_ACQ_vidAcquisition3                                           */
/*   3 / PWRSEN_ACQ_vidDetectFailPwSp3Sdf                                     */
/*   4 / PWRSEN_ACQ_vidDegradModePwSp3Sdf                                     */
/*   5 / PWRSEN_ACQ_vidDiagVRawMes3                                           */
/*   6 / PWRSEN_ACQ_vidInitVEndValMeas3                                       */
/*   7 / PWRSEN_ACQ_vidVEndValMeas3                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_FCT3.C_v    $*/
/* $Revision::   1.2      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
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
/* !Function    :  PWRSEN_ACQ_vidAcqDiagVRawMeas3                             */
/* !Description :  Lorsque le défaut sur l'ALIM 3 est détecté, on fige la     */
/*                 valeur envoyée au reste du CMM à la  dernière valeur       */
/*                 valide.  Aussi, lorsqu'il est confirmé on applique une     */
/*                 valeur par défaut est calibrable à la sortie du  module    */
/*                 d'acquisition.                                             */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcquisition3();                            */
/*  extf argret void PWRSEN_ACQ_vidDetectFailPwSp3Sdf();                      */
/*  extf argret void PWRSEN_ACQ_vidDegradModePwSp3Sdf();                      */
/*  output boolean Pwr_bMonRunORng_vMes3_Sfty;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcqDiagVRawMeas3(void)
{
   PWRSEN_ACQ_vidAcquisition3();
   PWRSEN_ACQ_vidDetectFailPwSp3Sdf();
   PWRSEN_ACQ_vidDegradModePwSp3Sdf();
   Pwr_bMonRunORng_vMes3_Sfty = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAcquisition3                                 */
/* !Description :  La valeur lue sur le convertisseur est mise à l'échelle en */
/*                 fonction de la sortie du TLE 4471 (tension de référence    */
/*                 divisée par 2).                                            */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_capteur_3;                              */
/*  output uint16 Tension_alimentation_3_mesuree;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcquisition3(void)
{
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alim_capteur_3;


   VEMS_vidGET(Tension_alimentation_capteur_3, u16LocalTension_alim_capteur_3);

   u16LocalTension_alim_3_mesuree =
      (uint16)((uint32)(u16LocalTension_alim_capteur_3 + 2) / 4);
   u16LocalTension_alim_3_mesuree =
      (uint16)MATHSRV_udtMIN(u16LocalTension_alim_3_mesuree, 1278);

   VEMS_vidSET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDetectFailPwSp3Sdf                           */
/* !Description :  La tension mesurée est comparée aux seuils tolérables pour */
/*                 la SdF (possibilité de reconstruire les informations       */
/*                 papillon et pédale).                                       */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alim_capteur_maxi_sdf;                               */
/*  input uint16 Tension_alim_capteur_mini_sdf;                               */
/*  output boolean Pwr_bDgoORng_vMes3_Sfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDetectFailPwSp3Sdf(void)
{
   uint16 u16LocalTension_alim_3_mesuree;


   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);


   if (  (u16LocalTension_alim_3_mesuree >= Tension_alim_capteur_maxi_sdf)
      || (u16LocalTension_alim_3_mesuree <= Tension_alim_capteur_mini_sdf) )
   {
      Pwr_bDgoORng_vMes3_Sfty = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes3_Sfty = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDegradModePwSp3Sdf                           */
/* !Description :  C'est cette valeur brute qui est utilisée par la sûreté de */
/*                 fonctionnement. Si elle est hors des seuils tolérables, on */
/*                 fige la valeur à sa valeur précédente. Lorsque la panne est*/
/*                 mémorisée, le mode dégradé est assuré par la sûreté de     */
/*                 fonctionnement.                                            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input boolean Pwr_bDgoORng_vMes3_Sfty;                                    */
/*  output uint16 Tension_alimentation_3_brute;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDegradModePwSp3Sdf(void)
{
   uint16 u16LocalTension_alim_3_mesuree;


   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);

   u16LocalTension_alim_3_mesuree =
      (uint16)MATHSRV_udtMIN(u16LocalTension_alim_3_mesuree, 1278);
   if (Pwr_bDgoORng_vMes3_Sfty == 0)
   {
      VEMS_vidSET(Tension_alimentation_3_brute, u16LocalTension_alim_3_mesuree);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDiagVRawMes3                                 */
/* !Description :  La détection du défaut décrite ici est utilisée pour les   */
/*                 capteurs qui ne tolèrent pas d'écart important de la       */
/*                 tension d'alim capteur (mesure pression, ...).             */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alim_capteur_maxi;                                   */
/*  input uint16 Tension_alim_capteur_mini;                                   */
/*  output boolean Pwr_bDgoORng_vMes3;                                        */
/*  output boolean Pwr_bMonRunORng_vMes3;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDiagVRawMes3(void)
{
   uint16 u16LocalTension_alim_3_brute;


   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);

   if (  (u16LocalTension_alim_3_brute >= Tension_alim_capteur_maxi)
      || (u16LocalTension_alim_3_brute <= Tension_alim_capteur_mini))
   {
      Pwr_bDgoORng_vMes3 = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes3 = 0;
   }

   Pwr_bMonRunORng_vMes3 = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidInitVEndValMeas3                             */
/* !Description :  Lorsqu’une panne est présente, la valeur fournie en sortie */
/*                 est la valeur par défaut                                   */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Pwr_bDgoORng_vMes3;                                         */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  output uint16 Tension_alimentation_3;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidInitVEndValMeas3(void)
{
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alimentation_3;

   if (Pwr_bDgoORng_vMes3 != 0)
   {
      u16LocalTension_alimentation_3 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
   }
   else
   {
      VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
      u16LocalTension_alimentation_3 =
         (uint16)MATHSRV_udtMIN(u16LocalTension_alim_3_brute, 1278);
   }
   VEMS_vidSET(Tension_alimentation_3, u16LocalTension_alimentation_3);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidVEndValMeas3                                 */
/* !Description :  Ce module spécifie la gestion des modes dégradés.          */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05190_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean ;         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  input boolean Pwr_bDgoORng_vMes3;                                         */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  output uint16 Tension_alimentation_3;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidVEndValMeas3(void)
{
   boolean bLocalAcvPwrSenMes3SftyMod;
   uint16  u16LocalTension_alimentation_3;
   uint16  u16LocalTension_alim_3_brute;


   bLocalAcvPwrSenMes3SftyMod = GDGAR_bGetFRM(FRM_FRM_ACVPWRSENMES3SFTYMOD);
   if (bLocalAcvPwrSenMes3SftyMod != 0)
   {
      u16LocalTension_alimentation_3 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
      VEMS_vidSET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   }
   else
   {
      if (Pwr_bDgoORng_vMes3 == 0)
      {
         VEMS_vidGET(Tension_alimentation_3_brute,
                     u16LocalTension_alim_3_brute);
         u16LocalTension_alimentation_3 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_alim_3_brute, 1278);
         VEMS_vidSET(Tension_alimentation_3, u16LocalTension_alimentation_3);
      }
   }
}

/*-------------------------------- end of file -------------------------------*/