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
/* !File            : PWRSEN_ACQ_FCT6.C                                       */
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
/*   1 / PWRSEN_ACQ_vidCluPosnCf                                              */
/*   2 / PWRSEN_ACQ_vidNeutCf                                                 */
/*   3 / PWRSEN_ACQ_vidnEngCf                                                 */
/*   4 / PWRSEN_ACQ_vidAccP2Cf                                                */
/*   5 / PWRSEN_ACQ_vidAlimSwitchSdlFast                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_FCT6.C_v    $*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
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
/* !Function    :  PWRSEN_ACQ_vidCluPosnCf                                    */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de position de l'embrayage                                 */
/* !Number      :  FCT6.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_1;                                      */
/*  input uint16 Tension_alimentation_1_brute;                                */
/*  input uint16 Tension_alimentation_1_mesuree;                              */
/*  input uint16 Tension_alimentation_2;                                      */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alimentation_3;                                      */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alimentation_4;                                      */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint8 Ext_idxCluPosnCf_C;                                           */
/*  output uint16 Ext_uCluPosnSenPwr;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidCluPosnCf(void)
{
   uint16 u16LocalidxCluPosnCf_C;
   uint16 u16LocalTension_alimentation_1;
   uint16 u16LocalTension_alim_1_brute;
   uint16 u16LocalTension_alim_1_mesuree;
   uint16 u16LocalTension_alimentation_2;
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alimentation_3;
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alimentation_4;
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alim_4_mesuree;
   uint32 u32LocalidxCluPosnCf_C;


   VEMS_vidGET(Tension_alimentation_1, u16LocalTension_alimentation_1);
   VEMS_vidGET(Tension_alimentation_1_brute, u16LocalTension_alim_1_brute);
   VEMS_vidGET(Tension_alimentation_1_mesuree, u16LocalTension_alim_1_mesuree);
   VEMS_vidGET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
   VEMS_vidGET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
   VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);
   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   switch (Ext_idxCluPosnCf_C)
   {
      case 0:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxCluPosnCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxCluPosnCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxCluPosnCf_C, 65535);

   VEMS_vidSET(Ext_uCluPosnSenPwr, u16LocalidxCluPosnCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidNeutCf                                       */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de point mort BVM                                          */
/* !Number      :  FCT6.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_1;                                      */
/*  input uint16 Tension_alimentation_1_brute;                                */
/*  input uint16 Tension_alimentation_1_mesuree;                              */
/*  input uint16 Tension_alimentation_2;                                      */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alimentation_3;                                      */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alimentation_4;                                      */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint8 Ext_idxNeutCf_C;                                              */
/*  output uint16 Ext_uNeutSenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidNeutCf(void)
{
   uint16 u16LocalidxNeutCf_C;
   uint16 u16LocalTension_alimentation_1;
   uint16 u16LocalTension_alim_1_brute;
   uint16 u16LocalTension_alim_1_mesuree;
   uint16 u16LocalTension_alimentation_2;
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alimentation_3;
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alimentation_4;
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alim_4_mesuree;
   uint32 u32LocalidxNeutCf_C;


   VEMS_vidGET(Tension_alimentation_1, u16LocalTension_alimentation_1);
   VEMS_vidGET(Tension_alimentation_1_brute, u16LocalTension_alim_1_brute);
   VEMS_vidGET(Tension_alimentation_1_mesuree, u16LocalTension_alim_1_mesuree);
   VEMS_vidGET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
   VEMS_vidGET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
   VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);
   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   switch (Ext_idxNeutCf_C)
   {
      case 0:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxNeutCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxNeutCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxNeutCf_C, 65535);

   VEMS_vidSET(Ext_uNeutSenPwr, u16LocalidxNeutCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidnEngCf                                       */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de régime moteur Uni ou bidirectionnelle                   */
/* !Number      :  FCT6.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_1;                                      */
/*  input uint16 Tension_alimentation_1_brute;                                */
/*  input uint16 Tension_alimentation_1_mesuree;                              */
/*  input uint16 Tension_alimentation_2;                                      */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alimentation_3;                                      */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alimentation_4;                                      */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint8 Ext_idxnEngCf_C;                                              */
/*  output uint16 Ext_unEngSenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidnEngCf(void)
{
   uint16 u16LocalidxnEngCf_C;
   uint16 u16LocalTension_alimentation_1;
   uint16 u16LocalTension_alim_1_brute;
   uint16 u16LocalTension_alim_1_mesuree;
   uint16 u16LocalTension_alimentation_2;
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alimentation_3;
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alimentation_4;
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alim_4_mesuree;
   uint32 u32LocalidxnEngCf_C;


   VEMS_vidGET(Tension_alimentation_1, u16LocalTension_alimentation_1);
   VEMS_vidGET(Tension_alimentation_1_brute, u16LocalTension_alim_1_brute);
   VEMS_vidGET(Tension_alimentation_1_mesuree, u16LocalTension_alim_1_mesuree);
   VEMS_vidGET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
   VEMS_vidGET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
   VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);
   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   switch (Ext_idxnEngCf_C)
   {
      case 0:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxnEngCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxnEngCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxnEngCf_C, 65535);

   VEMS_vidSET(Ext_unEngSenPwr, u16LocalidxnEngCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAccP2Cf                                      */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de la pédale d'accélération 2                              */
/* !Number      :  FCT6.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_1;                                      */
/*  input uint16 Tension_alimentation_1_brute;                                */
/*  input uint16 Tension_alimentation_1_mesuree;                              */
/*  input uint16 Tension_alimentation_2;                                      */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alimentation_3;                                      */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alimentation_4;                                      */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint8 Ext_idxAccP2Cf_C;                                             */
/*  output uint16 Ext_uAccP2SenPwr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAccP2Cf(void)
{
   uint16 u16LocalidxAccP2Cf_C;
   uint16 u16LocalTension_alimentation_1;
   uint16 u16LocalTension_alim_1_brute;
   uint16 u16LocalTension_alim_1_mesuree;
   uint16 u16LocalTension_alimentation_2;
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alimentation_3;
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alimentation_4;
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alim_4_mesuree;
   uint32 u32LocalidxAccP2Cf_C;


   VEMS_vidGET(Tension_alimentation_1, u16LocalTension_alimentation_1);
   VEMS_vidGET(Tension_alimentation_1_brute, u16LocalTension_alim_1_brute);
   VEMS_vidGET(Tension_alimentation_1_mesuree, u16LocalTension_alim_1_mesuree);
   VEMS_vidGET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
   VEMS_vidGET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
   VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);
   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   switch (Ext_idxAccP2Cf_C)
   {
      case 0:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxAccP2Cf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxAccP2Cf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxAccP2Cf_C, 65535);

   VEMS_vidSET(Ext_uAccP2SenPwr, u16LocalidxAccP2Cf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimSwitchSdlFast                            */
/* !Description :  Ce switch sert à redistribuer les valeurs d’acquisitions de*/
/*                 la tension d’alimentation sur le capteur de position       */
/*                 papillon qui nécessite un calcul de la tension             */
/*                 d’alimentation à une récurrence rapide.                    */
/* !Number      :  FCT6.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_1;                                      */
/*  input uint16 Tension_alimentation_1_brute;                                */
/*  input uint16 Tension_alimentation_1_mesuree;                              */
/*  input uint16 Tension_alimentation_2;                                      */
/*  input uint16 Tension_alimentation_2_brute;                                */
/*  input uint16 Tension_alimentation_2_mesuree;                              */
/*  input uint16 Tension_alimentation_3;                                      */
/*  input uint16 Tension_alimentation_3_brute;                                */
/*  input uint16 Tension_alimentation_3_mesuree;                              */
/*  input uint16 Tension_alimentation_4;                                      */
/*  input uint16 Tension_alimentation_4_brute;                                */
/*  input uint16 Tension_alimentation_4_mesuree;                              */
/*  input uint8 Conf_alimentation_thr;                                        */
/*  output uint16 Tension_alimentation_thr;                                   */
/*  output uint16 Ext_uThrSenPwr;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimSwitchSdlFast(void)
{
   uint16 u16LocalTension_alimentation_thr;
   uint16 u16LocalTension_alimentation_1;
   uint16 u16LocalTension_alim_1_brute;
   uint16 u16LocalTension_alim_1_mesuree;
   uint16 u16LocalTension_alimentation_2;
   uint16 u16LocalTension_alim_2_brute;
   uint16 u16LocalTension_alim_2_mesuree;
   uint16 u16LocalTension_alimentation_3;
   uint16 u16LocalTension_alim_3_brute;
   uint16 u16LocalTension_alim_3_mesuree;
   uint16 u16LocalTension_alimentation_4;
   uint16 u16LocalTension_alim_4_brute;
   uint16 u16LocalTension_alim_4_mesuree;
   uint32 u32LocalTension_alimentation_thr;


   VEMS_vidGET(Tension_alimentation_1, u16LocalTension_alimentation_1);
   VEMS_vidGET(Tension_alimentation_1_brute, u16LocalTension_alim_1_brute);
   VEMS_vidGET(Tension_alimentation_1_mesuree, u16LocalTension_alim_1_mesuree);
   VEMS_vidGET(Tension_alimentation_2, u16LocalTension_alimentation_2);
   VEMS_vidGET(Tension_alimentation_2_brute, u16LocalTension_alim_2_brute);
   VEMS_vidGET(Tension_alimentation_2_mesuree, u16LocalTension_alim_2_mesuree);
   VEMS_vidGET(Tension_alimentation_3, u16LocalTension_alimentation_3);
   VEMS_vidGET(Tension_alimentation_3_brute, u16LocalTension_alim_3_brute);
   VEMS_vidGET(Tension_alimentation_3_mesuree, u16LocalTension_alim_3_mesuree);
   VEMS_vidGET(Tension_alimentation_4, u16LocalTension_alimentation_4);
   VEMS_vidGET(Tension_alimentation_4_brute, u16LocalTension_alim_4_brute);
   VEMS_vidGET(Tension_alimentation_4_mesuree, u16LocalTension_alim_4_mesuree);

   switch (Conf_alimentation_thr)
   {
      case 0:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalTension_alimentation_thr =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalTension_alimentation_thr =
      (uint16)MATHSRV_udtMIN(u32LocalTension_alimentation_thr, 65535);

   VEMS_vidSET(Tension_alimentation_thr, u16LocalTension_alimentation_thr);
   VEMS_vidSET(Ext_uThrSenPwr, u16LocalTension_alimentation_thr);
}

/*-------------------------------- end of file -------------------------------*/