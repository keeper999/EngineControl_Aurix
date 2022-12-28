/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRNOUT                                           */
/* !Description     : MISFDFTLRNOUT component.                                */
/*                                                                            */
/* !Module          : MISFDFTLRNOUT                                           */
/* !Description     : GENERATION DE L'ETAT D'APPRENTISSAGE DES DEFAUTS        */
/*                    MISFIRE.                                                */
/*                                                                            */
/* !File            : MISFDFTLRNOUT_FCT1.C                                    */
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
/*   1 / MISFDFTLRNOUT_vidInitOutput                                          */
/*   2 / MISFDFTLRNOUT_vidMfwAdaptCntMin                                      */
/*   3 / MISFDFTLRNOUT_vidMfwAdaptCZonLev                                     */
/*   4 / MISFDFTLRNOUT_vidMfwAdaptZRatio                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 00762 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRNOUT/MISFDFTLRNOUT_F$*/
/* $Revision::   1.0      $$Author::   fsanchez2      $$Date::   22 Oct 2009 $*/
/* $Author::   fsanchez2                              $$Date::   22 Oct 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFDFTLRNOUT.h"
#include "MISFDFTLRNOUT_L.h"
#include "MISFDFTLRNOUT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRNOUT_vidInitOutput                                */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Mfw_adapt_zones_ratio;                                       */
/*  output uint8 Mfw_adapt_current_zone_level;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRNOUT_vidInitOutput(void)
{
   VEMS_vidSET(Mfw_adapt_zones_ratio, 0);
   VEMS_vidSET(Mfw_adapt_current_zone_level, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRNOUT_vidMfwAdaptCntMin                            */
/* !Description :  Ce module comporte la comparaison des deux vecteurs        */
/*                 d’entrée par rapport à Mfw_adapt_zone_ratio_thresh. Chaque */
/*                 composante des vecteurs d’entrée est comparée au seuil. De */
/*                 cette comparaison est extrait un vecteur constitué des plus*/
/*                 petites composantes.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mfw_adapt_zone_ratio_thresh;                                  */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  output uint8 Mf_adap_lw_corr_count_min[9];                                */
/*  output uint8 Mf_adap_shrt_corr_count_min[9];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRNOUT_vidMfwAdaptCntMin(void)
{
   uint8 u8LocalCounter;
   uint8 u8LocalMfAdapCorrCountUavn1;


   for (u8LocalCounter = 0; u8LocalCounter < 9; u8LocalCounter++)
   {
      VEMS_vidGET1DArrayElement(Mf_adap_lw_corr_count_uavn1, u8LocalCounter,
                                u8LocalMfAdapCorrCountUavn1);
      Mf_adap_lw_corr_count_min[u8LocalCounter] =
            (uint8)MATHSRV_udtMIN(u8LocalMfAdapCorrCountUavn1,
                                  Mfw_adapt_zone_ratio_thresh);

      VEMS_vidGET1DArrayElement(Mf_adap_shrt_corr_count_uavn1,u8LocalCounter,
                                u8LocalMfAdapCorrCountUavn1);
      Mf_adap_shrt_corr_count_min[u8LocalCounter] =
            (uint8)MATHSRV_udtMIN(u8LocalMfAdapCorrCountUavn1,
                                  Mfw_adapt_zone_ratio_thresh);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRNOUT_vidMfwAdaptCZonLev                           */
/* !Description :  Fonction de production de la sortie                        */
/*                 Mfw_adapt_current_zone_level.                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_adap_bkpt_ind_uavn0;                                       */
/*  input uint8 Mfw_adapt_zone_ratio_thresh;                                  */
/*  input uint8 Mf_adap_shrt_corr_count_min[9];                               */
/*  input uint8 Mf_adap_lw_corr_count_min[9];                                 */
/*  input uint16 Mfw_adapt_current_zone_level_res;                            */
/*  output uint16 Mfw_adapt_current_zone_level_res;                           */
/*  output uint8 Mfw_adapt_current_zone_level;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRNOUT_vidMfwAdaptCZonLev(void)
{
   uint8  u8LocalMf_adap_bkpt_ind_uavn0;
   uint8  u8LocalMfwAdaptCurrentZoneLevel;
   uint32 u32LocalScaling;


   VEMS_vidGET(Mf_adap_bkpt_ind_uavn0, u8LocalMf_adap_bkpt_ind_uavn0);

   if (u8LocalMf_adap_bkpt_ind_uavn0 > 0)
   {
      if (u8LocalMf_adap_bkpt_ind_uavn0 > 9)
      {
         u8LocalMf_adap_bkpt_ind_uavn0 = 9;
      }

      if (Mfw_adapt_zone_ratio_thresh > 0)
      {
         u32LocalScaling = (uint32)
            ( ( ( Mf_adap_shrt_corr_count_min[u8LocalMf_adap_bkpt_ind_uavn0 - 1]
                + Mf_adap_lw_corr_count_min[u8LocalMf_adap_bkpt_ind_uavn0 - 1])
              * 32768)
            / Mfw_adapt_zone_ratio_thresh);

         Mfw_adapt_current_zone_level_res =
                  (uint16)MATHSRV_udtMIN(u32LocalScaling , 65535);
      }
      else
      {
         Mfw_adapt_current_zone_level_res = 65535;
      }

      u8LocalMfwAdaptCurrentZoneLevel
            = (uint8)(Mfw_adapt_current_zone_level_res / 256);
   }
   else
   {
      Mfw_adapt_current_zone_level_res = 0;
      u8LocalMfwAdaptCurrentZoneLevel = 0;
   }

   VEMS_vidSET(Mfw_adapt_current_zone_level,
               u8LocalMfwAdaptCurrentZoneLevel);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRNOUT_vidMfwAdaptZRatio                            */
/* !Description :  Fonction de production de la sortie Mfw_adapt_zones_ratio. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_adap_bkpt_ind_uavn0;                                       */
/*  input uint8 Mfw_adapt_zone_ratio_thresh;                                  */
/*  input uint8 Mf_adap_shrt_corr_count_min[9];                               */
/*  input uint8 Mf_adap_lw_corr_count_min[9];                                 */
/*  input uint16 Mfw_adapt_zones_ratio_res;                                   */
/*  output uint16 Mfw_adapt_zones_ratio_res;                                  */
/*  output uint8 Mfw_adapt_zones_ratio;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRNOUT_vidMfwAdaptZRatio(void)
{
   uint8  u8LocalMfwAdaptZonesRatio;
   uint8  u8LocalMf_adap_bkpt_ind_uavn0;
   uint8  u8LocalCounter;
   uint16 u16LocalSum;
   uint32 u32LocalScaling;


   VEMS_vidGET(Mf_adap_bkpt_ind_uavn0, u8LocalMf_adap_bkpt_ind_uavn0);
   if (u8LocalMf_adap_bkpt_ind_uavn0 > 0)
   {
      if (Mfw_adapt_zone_ratio_thresh > 0)
      {
         u16LocalSum = 0;
         for (u8LocalCounter = 0; u8LocalCounter < 9; u8LocalCounter++)
         {
            u16LocalSum = (uint16)( u16LocalSum
                                  + Mf_adap_shrt_corr_count_min[u8LocalCounter]
                                  + Mf_adap_lw_corr_count_min[u8LocalCounter]);
         }

         u32LocalScaling = (uint32)( (u16LocalSum * 32768)
                                   / (9 * Mfw_adapt_zone_ratio_thresh));

         Mfw_adapt_zones_ratio_res =
               (uint16)MATHSRV_udtMIN(u32LocalScaling, 65535);
      }
      else
      {
         Mfw_adapt_zones_ratio_res = 65535;
      }
      u8LocalMfwAdaptZonesRatio
            = (uint8)(Mfw_adapt_zones_ratio_res / 256);
   }
   else
   {
      Mfw_adapt_zones_ratio_res = 0;
      u8LocalMfwAdaptZonesRatio = 0;
   }

   VEMS_vidSET(Mfw_adapt_zones_ratio, u8LocalMfwAdaptZonesRatio);
}
/*---------------------------- end of file -----------------------------------*/