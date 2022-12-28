/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKSHDDET                                               */
/* !Description     : KNKSHDDET Component.                                    */
/*                                                                            */
/* !Module          : KNKSHDDET                                               */
/* !Description     : Détection palliative de cliquetis.                      */
/*                                                                            */
/* !File            : KNKSHDDET_FCT1.C                                        */
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
/*   1 / KNKSHDDET_vidInitOutput                                              */
/*   2 / KNKSHDDET_vidInitialization                                          */
/*   3 / KNKSHDDET_vidDetManager                                              */
/*   4 / KNKSHDDET_vidDetection                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5145312 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKSHDDET/KNKSHDD$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   02 May 2013 $*/
/* $Author::   etsasson                               $$Date::   02 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKSHDDET.h"
#include "KNKSHDDET_L.h"
#include "KNKSHDDET_im.h"
#include "GDGAR.h"
#include "SWFAIL.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKSHDDET_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Knk_deg_manu_inh_Acv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDDET_vidInitOutput(void)
{
   VEMS_vidSET(Knk_deg_manu_inh_Acv, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKSHDDET_vidInitialization                                */
/* !Description :  Au Reset du calculateur (EveRst), ainsi qu’a l’activation  */
/*                 des combustions (EveRTSn), on réinitialise les variables   */
/*                 suivantes : Knk_deg_det_cur_uavb1 et Knk_deg_det_uavb1     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output boolean Knk_deg_det_cur_uavb1[4];                                  */
/*  output boolean Knk_deg_det_uavb1[4];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDDET_vidInitialization(void)
{
   boolean bLocalKnk_deg_det_cur_uavb1[KNKSHDDET_u32ARRAY_LENGTH];
   boolean bLocalKnk_deg_det_uavb1[KNKSHDDET_u32ARRAY_LENGTH];
   uint8   u8LocalIndex;

   for (u8LocalIndex = 0;
        u8LocalIndex < KNKSHDDET_u32ARRAY_LENGTH;
        u8LocalIndex++)
   {
      bLocalKnk_deg_det_cur_uavb1[u8LocalIndex] = 0;
      bLocalKnk_deg_det_uavb1[u8LocalIndex] = 0;
   }
   VEMS_vidSET1DArray(Knk_deg_det_cur_uavb1,
                      KNKSHDDET_u32ARRAY_LENGTH,
                      bLocalKnk_deg_det_cur_uavb1);
   VEMS_vidSET1DArray(Knk_deg_det_uavb1,
                      KNKSHDDET_u32ARRAY_LENGTH,
                      bLocalKnk_deg_det_uavb1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKSHDDET_vidDetManager                                    */
/* !Description :  La détection palliative n’est calculée que si la           */
/*                 calibration Knk_deg_manu_inh_uacb0 = 0                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void KNKSHDDET_vidDetection();                                */
/*  input boolean Knk_deg_manu_inh_uacb0;                                     */
/*  output boolean Knk_deg_manu_inh_Acv;                                      */
/*  output boolean Knk_deg_manu_inh_uacb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDDET_vidDetManager(void)
{
   VEMS_vidSET(Knk_deg_manu_inh_Acv, Knk_deg_manu_inh_uacb0);
   if(Knk_deg_manu_inh_uacb0 == 0)
   {
      KNKSHDDET_vidDetection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKSHDDET_vidDetection                                     */
/* !Description :  Le calcul de la détection doit être effectué APRES le      */
/*                 calcul de Somme_cliq_cyl et la  détection de cliquetis et  */
/*                 AVANT le rafraîchissement de Autorise_detection_cl.        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 Knk_noCyl;                                                    */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input boolean KnkTreat_bInhKnkDet;                                        */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 Knk_deg_det_load_bkpt_uacn1[12];                             */
/*  input uint16 Knk_deg_det_n_bkpt_uacn1[9];                                 */
/*  input uint16 Knk_deg_det_thr_cyl1_uacn2[12][9];                           */
/*  input uint16 Knk_deg_det_thr_cyl2_uacn2[12][9];                           */
/*  input uint16 Knk_deg_det_thr_cyl3_uacn2[12][9];                           */
/*  input uint16 Knk_deg_det_thr_cyl4_uacn2[12][9];                           */
/*  input uint16 Somme_clq_cyl[4];                                            */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input boolean Detection_rbl[4];                                           */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Knk_deg_det_seuil_temp_eau_uacn0;                             */
/*  input boolean Knk_deg_det_cur_manu_inh_uacb0;                             */
/*  output boolean Knk_deg_det_uavb1[4];                                      */
/*  output boolean Knk_deg_det_cur_uavb1[4];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDDET_vidDetection(void)
{
   boolean bLocalInhShdDet;
   boolean bLocalDetection_cliquetis;
   boolean bLocalDetection_rbl;
   boolean bLocalKnk_sens_diag_act_uavb0;
   boolean bLocalKnkTreat_bInhKnkDet;
   boolean bLocalDetection_fortcliquetis;
   uint8   u8LocalKnk_noCyl;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalKnkDegDetThr;
   uint16  u16LocalSiteInterpY;
   uint16  u16LocalSiteInterpX;
   uint16  u16LocalExt_rTotLd;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalSomme_clq_cyl;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   VEMS_vidGET(KnkTreat_bInhKnkDet, bLocalKnkTreat_bInhKnkDet);
   bLocalInhShdDet = GDGAR_bGetFRM(FRM_FRM_INHSHDDET);

   if (  (bLocalKnk_sens_diag_act_uavb0 != 0)
      || (bLocalInhShdDet != 0 )
      || (bLocalKnkTreat_bInhKnkDet != 0))
   {
      if (u8LocalKnk_noCyl < KNKSHDDET_u32ARRAY_LENGTH)
      {
         VEMS_vidSET1DArrayElement(Knk_deg_det_uavb1, u8LocalKnk_noCyl, 0);
         VEMS_vidSET1DArrayElement(Knk_deg_det_cur_uavb1, u8LocalKnk_noCyl, 0);
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
      VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
      u16LocalSiteInterpX =
         MATHSRV_u16CalcParaIncAryU16(Knk_deg_det_load_bkpt_uacn1,
                                      u16LocalExt_rTotLd,
                                      12);
      u16LocalSiteInterpY =
         MATHSRV_u16CalcParaIncAryU16(Knk_deg_det_n_bkpt_uacn1,
                                      u16LocalRegime_moteur,
                                      9);
      switch (u8LocalKnk_noCyl)
      {
         case 0:
            u16LocalKnkDegDetThr =
               MATHSRV_u16Interp2d(&Knk_deg_det_thr_cyl1_uacn2[0][0],
                                    u16LocalSiteInterpX,
                                    u16LocalSiteInterpY,
                                    9);
            break;

         case 1:
            u16LocalKnkDegDetThr =
                MATHSRV_u16Interp2d(&Knk_deg_det_thr_cyl2_uacn2[0][0],
                                    u16LocalSiteInterpX,
                                    u16LocalSiteInterpY,
                                    9);
            break;

         case 2:
            u16LocalKnkDegDetThr =
                MATHSRV_u16Interp2d(&Knk_deg_det_thr_cyl3_uacn2[0][0],
                                    u16LocalSiteInterpX,
                                    u16LocalSiteInterpY,
                                    9);
            break;

         case 3:
            u16LocalKnkDegDetThr =
                MATHSRV_u16Interp2d(&Knk_deg_det_thr_cyl4_uacn2[0][0],
                                    u16LocalSiteInterpX,
                                    u16LocalSiteInterpY,
                                    9);
            break;

         default:
            u16LocalKnkDegDetThr = 0;
            SWFAIL_vidSoftwareErrorHook();
            break;
      }

      if (u8LocalKnk_noCyl < KNKSHDDET_u32ARRAY_LENGTH)
      {
         VEMS_vidGET1DArrayElement(Somme_clq_cyl,
                                   u8LocalKnk_noCyl,
                                   u16LocalSomme_clq_cyl);
         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_fortcliquetis);
         VEMS_vidGET1DArrayElement(Detection_rbl,
                                   u8LocalKnk_noCyl,
                                   bLocalDetection_rbl);
         VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
         if (  (u16LocalSomme_clq_cyl > u16LocalKnkDegDetThr)
            && (bLocalDetection_cliquetis == 0)
            && (u8LocalTemperature_eau >= Knk_deg_det_seuil_temp_eau_uacn0)
            && (bLocalDetection_fortcliquetis == 0)
            && (bLocalDetection_rbl == 0))
         {
            VEMS_vidSET1DArrayElement(Knk_deg_det_uavb1, u8LocalKnk_noCyl, 1);
            if (Knk_deg_det_cur_manu_inh_uacb0 == 0)
            {
               VEMS_vidSET1DArrayElement(Knk_deg_det_cur_uavb1,
                                         u8LocalKnk_noCyl,
                                         1);
            }
            else
            {
               VEMS_vidSET1DArrayElement(Knk_deg_det_cur_uavb1,
                                         u8LocalKnk_noCyl,
                                         0);
            }
         }
         else
         {
            VEMS_vidSET1DArrayElement(Knk_deg_det_uavb1, u8LocalKnk_noCyl, 0);
            VEMS_vidSET1DArrayElement(Knk_deg_det_cur_uavb1,
                                      u8LocalKnk_noCyl,
                                      0);
         }
      }
   }
}

/*------------------------------- end of file --------------------------------*/