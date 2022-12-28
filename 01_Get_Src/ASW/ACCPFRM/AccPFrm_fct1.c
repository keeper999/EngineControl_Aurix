/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPFRM                                                 */
/* !Description     : ACCPFRM component.                                      */
/*                                                                            */
/* !Module          : ACCPFRM                                                 */
/* !Description     : Formatage de la volonté conducteur sur la pédale        */
/*                    accélérateur.                                           */
/*                                                                            */
/* !File            : ACCPFRM_FCT1.C                                          */
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
/*   1 / ACCPFRM_vidInitOutput                                                */
/*   2 / ACCPFRM_vidMuxFormatting                                             */
/*   3 / ACCPFRM_vidMuxFormatPosPed                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 03781 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPFRM/ACCPFRM_FCT1.C_v     $*/
/* $Revision::   1.7                                                         $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPFRM.h"
#include "ACCPFRM_L.h"
#include "ACCPFRM_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPFRM_vidInitOutput                                      */
/* !Description :  Fonction d'initialisation des variables de sortie          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AccP_rDrvReq;                                                */
/*  output boolean AccP_bHdPtMon;                                             */
/*  output boolean ACCPFRM_bHystPosPedOut;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPFRM_vidInitOutput(void)
{
   VEMS_vidSET(AccP_rDrvReq, 0);
   VEMS_vidSET(AccP_bHdPtMon, 0);
   ACCPFRM_bHystPosPedOut = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPFRM_vidMuxFormatting                                   */
/* !Description :  Fonction qui gère le formatage de la volonté conducteur à  */
/*                 envoyer sur le CAN                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPFRM_vidMuxFormatPosPed();                            */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPFRM_vidMuxFormatting(void)
{
   if (  (Tr_test_bed_mode_dyn == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      ACCPFRM_vidMuxFormatPosPed();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPFRM_vidMuxFormatPosPed                                 */
/* !Description :  La fonction qui définie la stratégie de détection de pied  */
/*                 levé basée sur la valeur des signaux renvoyés par les 2    */
/*                 pistes du capteur pédale.                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input boolean Ext_bAccPHdPt;                                              */
/*  input uint16 AccP_rAccPPHdPt_C;                                           */
/*  input uint8 Dv_detect_pl_low_thresh_mux;                                  */
/*  input uint8 Dv_detect_pl_high_thresh_mux;                                 */
/*  input boolean ACCPFRM_bHystPosPedOut;                                     */
/*  input st02 Ssm_pedal_pos_sensing_status;                                  */
/*  input boolean Ssm_mux_dv_pos_pedal_ff_manu_inh;                           */
/*  input boolean Cc_accel_pedal_wot_request;                                 */
/*  input boolean Lvv_pt_dur_ad_conv;                                         */
/*  input boolean VSCtl_bKdAuthVSLim;                                         */
/*  input boolean Accp_bAcvModPedalWotRequest;                                */
/*  input uint16 CoVSCtl_rAccPTra;                                            */
/*  input boolean Accp_bInhModPosnPedRel;                                     */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input boolean Cc_accel_pedal_regulation_master;                           */
/*  input boolean Cc_couple_lvv_effectif;                                     */
/*  input boolean Aps_mux_pl_securise_manu_inh;                               */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint16 Aps_detect_pl_mux_coh_tolerance;                             */
/*  output uint8 AccP_rDrvReq;                                                */
/*  output boolean AccP_bHdPtMon;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPFRM_vidMuxFormatPosPed(void)
{
   boolean bLocalAccP_bHdPtMon;
   boolean bLocalAcvIrvLihPed;
   boolean bLocalAcvPHdPtMdl;
   boolean bLocalAcvPed;
   boolean bLocalAcvRvVstLihPed;
   boolean bLocalCc_accel_ped_regul_master;
   boolean bLocalCc_accel_pedal_wot_request;
   boolean bLocalCc_couple_lvv_effectif;
   boolean bLocalExt_bAccPHdPt;
   boolean bLocalInhPHdPt;
   boolean bLocalVSCtl_bKdAuthVSLim;
   boolean bLocalLvv_pt_dur_ad_conv;
   uint8   u8LocalAccP_rDrvReq;
   uint8   u8LocalDv_pos_ped_relative;
   uint8   u8LocalSsm_pedal_pos_sens_status;
   uint16  u16LocalAbsSub;
   uint16  u16LocalAccP_rAccP;
   uint16  u16LocalAps_1_filtered_position;
   uint16  u16LocalAps_2_formated_position;
   uint16  u16LocalCoVSCtl_rAccPTra;
   uint16  u16LocalMin;
   uint16  u16LocalThresh1;
   uint16  u16LocalThresh2;
   sint32  s32LocalDiff;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   VEMS_vidGET(Ext_bAccPHdPt, bLocalExt_bAccPHdPt);

   bLocalAcvPHdPtMdl = GDGAR_bGetFRM(FRM_FRM_ACVPHDPTMDL);
   if (  (  (bLocalAcvPHdPtMdl != 0)
         && (u16LocalAccP_rAccP > AccP_rAccPPHdPt_C))
      || (  (bLocalAcvPHdPtMdl == 0)
         && (bLocalExt_bAccPHdPt != 0)))
   {
      bLocalAccP_bHdPtMon = 1;
   }
   else
   {
      bLocalAccP_bHdPtMon = 0;
   }

   /* Bloc Hystérisis */
   u16LocalThresh1 = (uint16)(Dv_detect_pl_low_thresh_mux * 50);
   u16LocalThresh2 = (uint16)(Dv_detect_pl_high_thresh_mux * 50);
   MATHSRV_vidSchmittTriggerU16(u16LocalAccP_rAccP,
                                u16LocalThresh1,
                                u16LocalThresh2,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &ACCPFRM_bHystPosPedOut);

   bLocalAcvIrvLihPed = GDGAR_bGetFRM(FRM_FRM_ACVIRVLIHPED);
   bLocalAcvRvVstLihPed = GDGAR_bGetFRM(FRM_FRM_ACVRVVSTLIHPED);
   VEMS_vidGET(Ssm_pedal_pos_sensing_status, u8LocalSsm_pedal_pos_sens_status);

   if (  (Ssm_mux_dv_pos_pedal_ff_manu_inh == 0)
      && (u8LocalSsm_pedal_pos_sens_status == SSM_PEDAL_POS_FAILURE)
      && (  (bLocalAcvIrvLihPed != 0)
         || (bLocalAcvRvVstLihPed != 0)))
   {
      u8LocalAccP_rDrvReq = 0xFF;
   }
   else
   {
      bLocalInhPHdPt = GDGAR_bGetFRM(FRM_FRM_INHPHDPT);
      VEMS_vidGET(Cc_accel_pedal_wot_request, bLocalCc_accel_pedal_wot_request);
      VEMS_vidGET(Lvv_pt_dur_ad_conv, bLocalLvv_pt_dur_ad_conv);
      VEMS_vidGET(VSCtl_bKdAuthVSLim, bLocalVSCtl_bKdAuthVSLim);
      if (  (  (bLocalCc_accel_pedal_wot_request != 0)
            && (bLocalLvv_pt_dur_ad_conv != 0)
            && (Accp_bAcvModPedalWotRequest != 0))
         || (  (bLocalVSCtl_bKdAuthVSLim != 0)
            && (bLocalInhPHdPt == 0)
            && (bLocalAccP_bHdPtMon != 0)))
      {
         u8LocalAccP_rDrvReq = 200;
      }
      else
      {
         VEMS_vidGET(CoVSCtl_rAccPTra, u16LocalCoVSCtl_rAccPTra);
         if (Accp_bInhModPosnPedRel != 0)
         {
            u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalCoVSCtl_rAccPTra,
                                                 12736);
            u8LocalAccP_rDrvReq = (uint8)((u16LocalMin + 32) / 64);
         }
         else
         {
            VEMS_vidGET(Dv_position_pedale_relative,
                        u8LocalDv_pos_ped_relative);
            VEMS_vidGET(Cc_accel_pedal_regulation_master,
                        bLocalCc_accel_ped_regul_master);
            VEMS_vidGET(Cc_couple_lvv_effectif, bLocalCc_couple_lvv_effectif);
            bLocalAcvPed = GDGAR_bGetFRM(FRM_FRM_ACVPED);
            if (  (bLocalAcvPed == 0)
               && (bLocalCc_accel_ped_regul_master == 0)
               && (bLocalCc_couple_lvv_effectif == 0)
               && (Aps_mux_pl_securise_manu_inh == 0))
            {
               /* Calcul soustraction */
               VEMS_vidGET(Aps_1_filtered_position,
                           u16LocalAps_1_filtered_position);
               VEMS_vidGET(Aps_2_formated_position,
                           u16LocalAps_2_formated_position);
               s32LocalDiff = u16LocalAps_1_filtered_position
                            - u16LocalAps_2_formated_position;
               u16LocalAbsSub = (uint16)MATHSRV_udtABS(s32LocalDiff);
               if (  (ACCPFRM_bHystPosPedOut != 0)
                  && (u16LocalAbsSub > Aps_detect_pl_mux_coh_tolerance))
               {
                  u16LocalMin = 0;
               }
               else
               {
                  u16LocalMin = (uint16)(u8LocalDv_pos_ped_relative * 50);
               }
            }
            else
            {
               u16LocalMin = (uint16)(u8LocalDv_pos_ped_relative * 50);
            }

            u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalCoVSCtl_rAccPTra,
                                                 u16LocalMin);
            u16LocalMin = (uint16)MATHSRV_udtMIN(u16LocalMin, 12736);
            u8LocalAccP_rDrvReq = (uint8)((u16LocalMin + 32) / 64);
         }
      }
   }
   VEMS_vidSET(AccP_rDrvReq, u8LocalAccP_rDrvReq);
   VEMS_vidSET(AccP_bHdPtMon, bLocalAccP_bHdPtMon);
}
/*------------------------------ End of file ---------------------------------*/