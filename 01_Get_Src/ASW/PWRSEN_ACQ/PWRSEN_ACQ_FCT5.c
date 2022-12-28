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
/* !File            : PWRSEN_ACQ_FCT5.c                                       */
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
/*   1 / PWRSEN_ACQ_vidAlimAps                                                */
/*   2 / PWRSEN_ACQ_vidAlimAc                                                 */
/*   3 / PWRSEN_ACQ_vidAlimAirPts                                             */
/*   4 / PWRSEN_ACQ_vidAlimPmast                                              */
/*   5 / PWRSEN_ACQ_vidBoostPresCf                                            */
/*   6 / PWRSEN_ACQ_vidPfuCf                                                  */
/*   7 / PWRSEN_ACQ_vidTrbActCf                                               */
/*   8 / PWRSEN_ACQ_vidptOilCf                                                */
/*   9 / PWRSEN_ACQ_vidInCmCf                                                 */
/*   10 / PWRSEN_ACQ_vidExCmCf                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_FCT5.c_v    $*/
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
/* !Function    :  PWRSEN_ACQ_vidAlimAps                                      */
/* !Description :  Ces switchs servent à redistribuer les valeurs             */
/*                 d’acquisitions de la tension d’alimentation pour chaque    */
/*                 capteur qui nécessitent un calcul de la tension            */
/*                 d’alimentation à une récurrence moyenne.                   */
/* !Number      :  FCT5.1                                                     */
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
/*  input uint8 Conf_alimentation_aps;                                        */
/*  output uint16 Tension_alimentation_aps;                                   */
/*  output uint16 Ext_uAccP1SenPwr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimAps(void)
{
   uint16 u16LocalTension_alim_aps;
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
   uint32 u32LocalTension_alim_aps;


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


   switch (Conf_alimentation_aps)
   {
      case 0:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alimentation_1
                                            * 4);
         break;

      case 1:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_1_brute
                                            * 4);
         break;

      case 2:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_1_mesuree
                                            * 4);
         break;

      case 3:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alimentation_2
                                            * 4);
         break;

      case 4:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_2_brute
                                            * 4);
         break;

      case 5:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_2_mesuree
                                            * 4);
         break;

      case 6:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alimentation_3
                                            * 4);
         break;

      case 7:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_3_brute
                                            * 4);
         break;

      case 8:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_3_mesuree
                                            * 4);
         break;

      case 9:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alimentation_4
                                            * 4);
         break;

      case 10:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_4_brute
                                            * 4);
         break;

      case 11:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_4_mesuree
                                            * 4);
         break;

      default:
         u32LocalTension_alim_aps = (uint32)( u16LocalTension_alim_4_mesuree
                                            * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalTension_alim_aps =
   (uint16)MATHSRV_udtMIN(u32LocalTension_alim_aps, 65535);

   VEMS_vidSET(Tension_alimentation_aps, u16LocalTension_alim_aps);
   VEMS_vidSET(Ext_uAccP1SenPwr, u16LocalTension_alim_aps);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimAc                                       */
/* !Description :  Ces switchs servent à redistribuer les valeurs             */
/*                 d’acquisitions de la tension d’alimentation pour chaque    */
/*                 capteur qui nécessitent un calcul de la tension            */
/*                 d’alimentation à une récurrence moyenne.                   */
/* !Number      :  FCT5.2                                                     */
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
/*  input uint8 Conf_alimentation_ac;                                         */
/*  output uint16 Tension_alimentation_ac;                                    */
/*  output uint16 Ext_upAcSenPwr;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimAc(void)
{
   uint16 u16LocalTension_alim_ac;
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
   uint32 u32LocalTension_alim_ac;


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


   switch (Conf_alimentation_ac)
   {
      case 0:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alimentation_1
                                           * 4);
         break;

      case 1:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_1_brute
                                           * 4);
         break;

      case 2:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_1_mesuree
                                           * 4);
         break;

      case 3:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alimentation_2
                                           * 4);
         break;

      case 4:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_2_brute
                                           * 4);
         break;

      case 5:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_2_mesuree
                                           * 4);
         break;

      case 6:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alimentation_3
                                           * 4);
         break;

      case 7:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_3_brute
                                           * 4);
         break;

      case 8:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_3_mesuree
                                           * 4);
         break;

      case 9:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alimentation_4
                                           * 4);
         break;

      case 10:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_4_brute
                                           * 4);
         break;

      case 11:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_4_mesuree
                                           * 4);
         break;

      default:
         u32LocalTension_alim_ac = (uint32)( u16LocalTension_alim_4_mesuree
                                           * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalTension_alim_ac =
      (uint16)MATHSRV_udtMIN(u32LocalTension_alim_ac, 65535);

   VEMS_vidSET(Tension_alimentation_ac, u16LocalTension_alim_ac);
   VEMS_vidSET(Ext_upAcSenPwr, u16LocalTension_alim_ac);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimAirPts                                   */
/* !Description :  Ces switchs servent à redistribuer les valeurs             */
/*                 d’acquisitions de la tension d’alimentation pour chaque    */
/*                 capteur qui nécessitent un calcul de la tension            */
/*                 d’alimentation à une récurrence moyenne.                   */
/* !Number      :  FCT5.3                                                     */
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
/*  input uint8 Conf_alimentation_air_pts;                                    */
/*  output uint16 Tension_alimentation_air_pts;                               */
/*  output uint16 Ext_uptAirSenPwr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimAirPts(void)
{
   uint16 u16LocalTension_alim_air_pts;
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
   uint32 u32LocalTension_alim_air_pts;


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

   switch (Conf_alimentation_air_pts)
   {
      case 0:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alimentation_1
                                                * 4);
         break;

      case 1:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_1_brute
                                                * 4);
         break;

      case 2:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_1_mesuree
                                                * 4);
         break;

      case 3:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alimentation_2
                                                * 4);
         break;

      case 4:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_2_brute
                                                * 4);
         break;

      case 5:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_2_mesuree
                                                * 4);
         break;

      case 6:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alimentation_3
                                                * 4);
         break;

      case 7:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_3_brute
                                                * 4);
         break;

      case 8:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_3_mesuree
                                                * 4);
         break;

      case 9:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alimentation_4
                                                * 4);
         break;

      case 10:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_4_brute
                                                * 4);
         break;

      case 11:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_4_mesuree
                                                * 4);
         break;

      default:
         u32LocalTension_alim_air_pts = (uint32)( u16LocalTension_alim_4_mesuree
                                                * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalTension_alim_air_pts =
      (uint16)MATHSRV_udtMIN(u32LocalTension_alim_air_pts, 65535);

   VEMS_vidSET(Tension_alimentation_air_pts, u16LocalTension_alim_air_pts);
   VEMS_vidSET(Ext_uptAirSenPwr, u16LocalTension_alim_air_pts);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidAlimPmast                                    */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de dépression MASTERVAC.                                   */
/* !Number      :  FCT5.4                                                     */
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
/*  input uint8 Conf_alimentation_pmast;                                      */
/*  output uint16 Tension_alimentation_pmast;                                 */
/*  output uint16 Ext_upMastSenPwr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidAlimPmast(void)
{
   uint16 u16LocalTensionAlimentationPmast;
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
   uint32 u32LocalTensionAlimentationPmast;


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

   switch (Conf_alimentation_pmast)
   {
      case 0:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalTensionAlimentationPmast =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalTensionAlimentationPmast =
      (uint16)MATHSRV_udtMIN(u32LocalTensionAlimentationPmast, 65535);

   VEMS_vidSET(Tension_alimentation_pmast, u16LocalTensionAlimentationPmast);
   VEMS_vidSET(Ext_upMastSenPwr, u16LocalTensionAlimentationPmast);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidBoostPresCf                                  */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de la pression de suralimentation                          */
/* !Number      :  FCT5.5                                                     */
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
/*  input uint8 Ext_idxBoostPresCf_C;                                         */
/*  output uint16 Ext_upBoostSenPwr;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidBoostPresCf(void)
{
   uint16 u16LocalidxBoostPresCf_C;
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
   uint32 u32LocalidxBoostPresCf_C;


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

   switch (Ext_idxBoostPresCf_C)
   {
      case 0:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxBoostPresCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxBoostPresCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxBoostPresCf_C, 65535);

   VEMS_vidSET(Ext_upBoostSenPwr, u16LocalidxBoostPresCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidPfuCf                                        */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 pression rail                                              */
/* !Number      :  FCT5.6                                                     */
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
/*  input uint8 Ext_idxPfuCf_C;                                               */
/*  output uint16 Ext_uPfuSenPwr;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidPfuCf(void)
{
   uint16 u16LocalidxPfuCf_C;
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
   uint32 u32LocalidxPfuCf_C;


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

   switch (Ext_idxPfuCf_C)
   {
      case 0:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxPfuCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxPfuCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxPfuCf_C, 65535);

   VEMS_vidSET(Ext_uPfuSenPwr, u16LocalidxPfuCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidTrbActCf                                     */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de position de la soupape Wastegate                        */
/* !Number      :  FCT5.7                                                     */
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
/*  input uint8 Ext_idxTrbActCf_C;                                            */
/*  output uint16 Ext_uTrbActSenPwr;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidTrbActCf(void)
{
   uint16 u16LocalidxTrbActCf_C;
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
   uint32 u32LocalidxTrbActCf_C;


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

   switch (Ext_idxTrbActCf_C)
   {
      case 0:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxTrbActCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxTrbActCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxTrbActCf_C, 65535);

   VEMS_vidSET(Ext_uTrbActSenPwr, u16LocalidxTrbActCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidptOilCf                                      */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de pression et de température d'huile                      */
/* !Number      :  FCT5.8                                                     */
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
/*  input uint8 Ext_idxptOilCf_C;                                             */
/*  output uint16 Ext_uptOilSenPwr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidptOilCf(void)
{
   uint16 u16LocalidxptOilCf_C;
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
   uint32 u32LocalidxptOilCf_C;


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

   switch (Ext_idxptOilCf_C)
   {
      case 0:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxptOilCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxptOilCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxptOilCf_C, 65535);

   VEMS_vidSET(Ext_uptOilSenPwr, u16LocalidxptOilCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidInCmCf                                       */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de position arbre à cames (AAC) d'admission                */
/* !Number      :  FCT5.9                                                     */
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
/*  input uint8 Ext_idxInCmCf_C;                                              */
/*  output uint16 Ext_uInCmSenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidInCmCf(void)
{
   uint16 u16LocalidxInCmCf_C;
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
   uint32 u32LocalidxInCmCf_C;


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

   switch (Ext_idxInCmCf_C)
   {
      case 0:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxInCmCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxInCmCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxInCmCf_C, 65535);

   VEMS_vidSET(Ext_uInCmSenPwr, u16LocalidxInCmCf_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PWRSEN_ACQ_vidExCmCf                                       */
/* !Description :  Fonction qui calcule la tension d'alimentation du capteur  */
/*                 de position arbre à cames (AAC) d'échappement              */
/* !Number      :  FCT5.10                                                    */
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
/*  input uint8 Ext_idxExCmCf_C;                                              */
/*  output uint16 Ext_uExCmSenPwr;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PWRSEN_ACQ_vidExCmCf(void)
{
   uint16 u16LocalidxExCmCf_C;
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
   uint32 u32LocalidxExCmCf_C;


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

   switch (Ext_idxExCmCf_C)
   {
      case 0:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alimentation_1 * 4);
         break;

      case 1:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_1_brute * 4);
         break;

      case 2:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_1_mesuree * 4);
         break;

      case 3:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alimentation_2 * 4);
         break;

      case 4:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_2_brute * 4);
         break;

      case 5:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_2_mesuree * 4);
         break;

      case 6:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alimentation_3 * 4);
         break;

      case 7:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_3_brute * 4);
         break;

      case 8:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_3_mesuree * 4);
         break;

      case 9:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alimentation_4 * 4);
         break;

      case 10:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_4_brute * 4);
         break;

      case 11:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         break;

      default:
         u32LocalidxExCmCf_C =
            (uint32)(u16LocalTension_alim_4_mesuree * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u16LocalidxExCmCf_C =
      (uint16)MATHSRV_udtMIN(u32LocalidxExCmCf_C, 65535);

   VEMS_vidSET(Ext_uExCmSenPwr, u16LocalidxExCmCf_C);
}

/*-------------------------------- end of file -------------------------------*/
