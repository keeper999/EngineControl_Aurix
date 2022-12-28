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
/* !File            : PWRSEN_ACQ_FCT4.C                                       */
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
/*   1 / PWRSEN_ACQ_vidAcqDiagVRawMeas4                                       */
/*   2 / PWRSEN_ACQ_vidAcquisition4                                           */
/*   3 / PWRSEN_ACQ_vidDetectFailPwSp4Sdf                                     */
/*   4 / PWRSEN_ACQ_vidDegradModePwSp4Sdf                                     */
/*   5 / PWRSEN_ACQ_vidDiagVRawMes4                                           */
/*   6 / PWRSEN_ACQ_vidInitVEndValMeas4                                       */
/*   7 / PWRSEN_ACQ_vidVEndValMeas4                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_FCT4.C_v    $*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
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
/* !Function    :  PWRSEN_ACQ_vidAcqDiagVRawMeas4                             */
/* !Description :  Lorsque le défaut sur l'ALIM 4 est détecté, on fige la     */
/*                 valeur envoyée au reste du CMM à la  dernière valeur       */
/*                 valide.  Aussi, lorsqu'il est confirmé on applique une     */
/*                 valeur par défaut est calibrable à la sortie du  module    */
/*                 d'acquisition.                                             */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcquisition4();                            */
/*  extf argret void PWRSEN_ACQ_vidDetectFailPwSp4Sdf();                      */
/*  extf argret void PWRSEN_ACQ_vidDegradModePwSp4Sdf();                      */
/*  output boolean Pwr_bMonRunORng_vMes4_Sfty;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcqDiagVRawMeas4(void)
{
   PWRSEN_ACQ_vidAcquisition4();
   PWRSEN_ACQ_vidDetectFailPwSp4Sdf();
   PWRSEN_ACQ_vidDegradModePwSp4Sdf();
   Pwr_bMonRunORng_vMes4_Sfty = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAcquisition4                                 */
/* !Description :  La valeur lue sur le convertisseur est mise à l'échelle en */
/*                 fonction de la sortie du TLE 4471 (tension de référence    */
/*                 divisée par 2).                                            */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_capteur_4;                              */
/*  output uint16 Tension_alimentation_4_mesuree;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAcquisition4(void)
{
   uint16 u16LocalTension_alim_4_mesuree;
   uint16 u16LocalTension_alim_capteur_4;


   VEMS_vidGET(Tension_alimentation_capteur_4, u16LocalTension_alim_capteur_4);

   u16LocalTension_alim_4_mesuree =
      (uint16)((uint32)(u16LocalTension_alim_capteur_4 + 2) / 4);
   u16LocalTension_alim_4_mesuree =
      (uint16)MATHSRV_udtMIN(u16LocalTension_alim_4_mesuree, 1278);

   VEMS_vidSET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDetectFailPwSp4Sdf                           */
/* !Description :  La tension mesurée est comparée aux seuils tolérables pour */
/*                 la SdF (possibilité de reconstruire les informations       */
/*                 papillon et pédale).                                       */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_10_02612_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint16 Tension_alim_capteur_maxi_sdf;                               */
/*  input uint16 Tension_alim_capteur_mini_sdf;                               */
/*  output boolean Pwr_bDgoORng_vMes4_Sfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDetectFailPwSp4Sdf(void)
{
   uint16 u16LocalTension_alim_4_mesuree;


   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   if (  (u16LocalTension_alim_4_mesuree >= Tension_alim_capteur_maxi_sdf)
      || (u16LocalTension_alim_4_mesuree <= Tension_alim_capteur_mini_sdf) )
   {
      Pwr_bDgoORng_vMes4_Sfty = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes4_Sfty = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDegradModePwSp4Sdf                           */
/* !Description :  C'est cette valeur brute qui est utilisée par la sûreté de */
/*                 fonctionnement. Si elle est hors des seuils tolérables, on */
/*                 fige la valeur à sa valeur précédente. Lorsque la panne est*/
/*                 mémorisée, le mode dégradé est assuré par la sûreté de     */
/*                 fonctionnement.                                            */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Pwr_bDgoORng_vMes4_Sfty;                                    */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  output uint16 Tension_alimentation_4_brute;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDegradModePwSp4Sdf(void)
{
   uint16 u16LocalTensionAlim_4_mesure;


   if (Pwr_bDgoORng_vMes4_Sfty == 0)
   {
      VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTensionAlim_4_mesure);
      u16LocalTensionAlim_4_mesure =
         (uint16)MATHSRV_udtMIN(u16LocalTensionAlim_4_mesure, 1278);
      VEMS_vidSET(Tension_alimentation_4_brute, u16LocalTensionAlim_4_mesure);
   }
   else
   {
      VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTensionAlim_4_mesure);
      u16LocalTensionAlim_4_mesure =
         (uint16)MATHSRV_udtMIN(u16LocalTensionAlim_4_mesure, 1278);
      VEMS_vidSET(Tension_alimentation_4_brute, u16LocalTensionAlim_4_mesure);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidDiagVRawMes4                                 */
/* !Description :  La détection du défaut décrite ici est utilisée pour les   */
/*                 capteurs qui ne tolèrent pas d'écart important de la       */
/*                 tension d'alim capteur (mesure pression, ...).             */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_10_02612_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alim_capteur_maxi;                                   */
/*  input uint16 Tension_alim_capteur_mini;                                   */
/*  output boolean Pwr_bDgoORng_vMes4;                                        */
/*  output boolean Pwr_bMonRunORng_vMes4;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidDiagVRawMes4(void)
{
   uint16 u16LocalTension_alim_4_brute;


   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);

   if (  (u16LocalTension_alim_4_brute >= Tension_alim_capteur_maxi)
      || (u16LocalTension_alim_4_brute <= Tension_alim_capteur_mini) )
   {
      Pwr_bDgoORng_vMes4 = 1;
   }
   else
   {
      Pwr_bDgoORng_vMes4 = 0;
   }

   Pwr_bMonRunORng_vMes4 = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidInitVEndValMeas4                             */
/* !Description :  Lorsque l’on a une panne présente, la valeur fournie en    */
/*                 sortie est la valeur par défaut.                           */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input boolean Pwr_bDgoORng_vMes4;                                         */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  output uint16 Tension_alimentation_4;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidInitVEndValMeas4(void)
{
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alimentation_4;


   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);

   if (Pwr_bDgoORng_vMes4 != 0)
   {
      u16LocalTension_alimentation_4 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
   }
   else
   {
      u16LocalTension_alimentation_4 =
         (uint16)MATHSRV_udtMIN(u16LocalTension_alim_4_brute,1278);
   }
   VEMS_vidSET(Tension_alimentation_4, u16LocalTension_alimentation_4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidVEndValMeas4                                 */
/* !Description :  Lorsque le défaut sur l'ALIM 4 est détecté, on fige la     */
/*                 valeur envoyée au reste du CMM à la  dernière valeur       */
/*                 valide.  Aussi, lorsqu'il est confirmé on applique une     */
/*                 valeur par défaut est calibrable à la sortie du  module    */
/*                 d'acquisition.                                             */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_10_02612_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean ;         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_alim_par_defaut;                                     */
/*  input boolean Pwr_bDgoORng_vMes4;                                         */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4;                                      */
/*  output uint16 Tension_alimentation_4;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidVEndValMeas4(void)
{
   boolean bLocalAcvPwrSenMes4SftyMod;
   uint16  u16LocalTension_alim_4_brut;
   uint16  u16LocalTension_alimentation_4;


   bLocalAcvPwrSenMes4SftyMod = GDGAR_bGetFRM(FRM_FRM_ACVPWRSENMES4SFTYMOD);
   if (bLocalAcvPwrSenMes4SftyMod != 0)
   {
      u16LocalTension_alimentation_4 =
         (uint16)MATHSRV_udtMIN(Tension_alim_par_defaut, 1278);
      VEMS_vidSET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   }
   else
   {
      if (Pwr_bDgoORng_vMes4 == 0)
      {
         VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brut);
         u16LocalTension_alimentation_4 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_alim_4_brut,1278);
         VEMS_vidSET(Tension_alimentation_4, u16LocalTension_alimentation_4);
      }
      else
      {
         VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
         u16LocalTension_alimentation_4 =
            (uint16)MATHSRV_udtMIN(u16LocalTension_alimentation_4,1278);
         VEMS_vidSET(Tension_alimentation_4, u16LocalTension_alimentation_4);
      }
   }
}

/*-------------------------------- end of file -------------------------------*/