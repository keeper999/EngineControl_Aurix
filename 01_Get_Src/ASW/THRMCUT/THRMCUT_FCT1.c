/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRMCUT                                                 */
/* !Description     : THRMCUT Component                                       */
/*                                                                            */
/* !Module          : THRMCUT                                                 */
/* !Description     : DETECTION DE MICRO-COUPURES CMM/BPM ET MODE PALLIATIF   */
/*                                                                            */
/* !File            : THRMCUT_FCT1.C                                          */
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
/*   1 / THRMCUT_vidInit                                                      */
/*   2 / THRMCUT_vidDetection                                                 */
/*   3 / THRMCUT_vidManager                                                   */
/*   4 / THRMCUT_vidTpsRatioMeasPosEnab                                       */
/*   5 / THRMCUT_vidPiste1Mng                                                 */
/*   6 / THRMCUT_vidSwitchManagementPiste1                                    */
/*   7 / THRMCUT_vidPiste2Mng                                                 */
/*   8 / THRMCUT_vidSwitchManagementPiste2                                    */
/*   9 / THRMCUT_vidMicroCutBmpFuncInhib                                      */
/*                                                                            */
/* !Reference: V02 NT 08 04513 / 05                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRMCUT/THRMCUT_FCT1.C_v      $*/
/* $Revision::   1.6      $$Author::   acabresp       $$Date::   31 Mar 2010 $*/
/* $Author::   acabresp                               $$Date::   31 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "THRMCUT.h"
#include "THRMCUT_L.h"
#include "THRMCUT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidInit                                             */
/* !Description : Initialisation des variables.                               */
/* !Number      : FCT1.1                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint16 Tps_1_ratio_meas_position;                                  */
/*   input uint16 Tps_2_ratio_meas_position;                                  */
/*   output uint16 Tps_1_raw_filt_position;                                   */
/*   output uint16 Tps_2_raw_filt_position;                                   */
/*   output boolean Tps_mcut_detect_flag;                                     */
/*   output boolean Throttle_pos_ref_freeze_enab;                             */
/*   output boolean Tps_1_overlap_demand;                                     */
/*   output boolean Tps_2_overlap_demand;                                     */
/*   output boolean Thr_bDeacThrStopLrn;                                      */
/*   output uint16 Tps_1_ratio_meas_pos_prec_3;                               */
/*   output uint16 Tps_1_ratio_meas_pos_prec_2;                               */
/*   output uint16 Tps_1_ratio_meas_pos_prec_1;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_3;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_2;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_1;                               */
/*   output uint32 THRMCUT_u32RatioMeasPosFiltMem;                            */
/*   output sint32 THRMCUT_s32FilterPrev;                                     */
/*   output boolean Tps_ratio_meas_position_enab_prev;                        */
/*   output boolean Tps_1_overlap_demand_Prev;                                */
/*   output boolean Tps_2_overlap_demand_Prev;                                */
/*   output boolean THRMCUT_bMcutDetectflag;                                  */
/*   output boolean THRMCUT_bMcutDetectflagTimeOut;                           */
/*   output uint16 THRMCUT_u16McutDetectflagTimer;                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidInit(void)
{
   uint16 u16LocalTps1_ratio_meas_position;
   uint16 u16LocalTps2_ratio_meas_position;
   uint16 u16LocalTps_1_raw_filt_position;
   uint16 u16LocalTps_2_raw_filt_position;


   VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);
   u16LocalTps_1_raw_filt_position =
      (uint16)MATHSRV_udtMIN(u16LocalTps1_ratio_meas_position, 1024);
   VEMS_vidSET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);
   u16LocalTps_2_raw_filt_position =
      (uint16)MATHSRV_udtMIN(u16LocalTps2_ratio_meas_position, 1024);
   VEMS_vidSET(Tps_2_raw_filt_position, u16LocalTps_2_raw_filt_position);
   VEMS_vidSET(Tps_mcut_detect_flag, 0);
   VEMS_vidSET(Throttle_pos_ref_freeze_enab, 0);
   VEMS_vidSET(Tps_1_overlap_demand, 0);
   VEMS_vidSET(Tps_2_overlap_demand, 0);
   VEMS_vidSET(Thr_bDeacThrStopLrn, 0);

   /* Filters initialization */
   Tps_1_ratio_meas_pos_prec_3 = 0;
   Tps_1_ratio_meas_pos_prec_2 = 0;
   Tps_1_ratio_meas_pos_prec_1 = 0;
   Tps_2_ratio_meas_pos_prec_3 = 0;
   Tps_2_ratio_meas_pos_prec_2 = 0;
   Tps_2_ratio_meas_pos_prec_1 = 0;

   THRMCUT_u32RatioMeasPosFiltMem = UINT32_MIN;
   THRMCUT_s32FilterPrev = 0;
   Tps_ratio_meas_position_enab_prev = 0;
   Tps_1_overlap_demand_Prev = 0;
   Tps_2_overlap_demand_Prev = 0;

   THRMCUT_bMcutDetectflag = 0;
   THRMCUT_bMcutDetectflagTimeOut = 0;
   THRMCUT_u16McutDetectflagTimer = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidDetection                                        */
/* !Description : Détection de Micro-coupures sur la piste 1.                 */
/* !Number      : FCT1.2                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;         */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input boolean THRMCUT_bMcutDetectflag;                                   */
/*   input boolean Tps_1_mcut_det_manu_inh;                                   */
/*   input uint16 Tps_1_ratio_meas_position;                                  */
/*   input uint16 Tps_2_ratio_meas_position;                                  */
/*   input uint8 Tps_1_drop_mcut_filter_gain;                                 */
/*   input uint32 THRMCUT_u32RatioMeasPosFiltMem;                             */
/*   input uint16 THRMCUT_u16FiltredPosition;                                 */
/*   input uint16 Tps_drop_mcut_diff_tolerance;                               */
/*   input sint32 THRMCUT_s32FilterPrev;                                      */
/*   input uint16 Tps_drop_mcut_grad_tolerance;                               */
/*   input uint16 Thr_tiMcutMaxDetTi_C;                                       */
/*   input uint16 THRMCUT_u16McutDetectflagTimer;                             */
/*   input boolean THRMCUT_bMcutDetectflagTimeOut;                            */
/*   output uint16 THRMCUT_u16FiltredPosition;                                */
/*   output boolean THRMCUT_bMcutDetectflag;                                  */
/*   output uint16 THRMCUT_u16McutDetectflagTimer;                            */
/*   output boolean THRMCUT_bMcutDetectflagTimeOut;                           */
/*   output boolean Tps_mcut_detect_flag;                                     */
/*   output sint32 THRMCUT_s32FilterPrev;                                     */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidDetection(void)
{
   boolean bLocalInhThrCutDet;
   boolean bLocalMcutDetectflagPrev;
   uint16  u16LocalFiltredPos;
   uint16  u16LocalFilterAbs;
   uint16  u16LocalTps1_ratio_meas_position;
   uint16  u16LocalTps2_ratio_meas_position;
   uint32  u32LocalDeltaFilter;
   sint32  s32LocalFilter;
   sint32  s32LocalDeltaFilter;


   bLocalMcutDetectflagPrev = THRMCUT_bMcutDetectflag;
   if (Tps_1_mcut_det_manu_inh == 0)
   {
      bLocalInhThrCutDet = GDGAR_bGetFRM(FRM_FRM_INHTHRCUTDET);
      VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
      VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);

      s32LocalFilter = (sint32)( u16LocalTps1_ratio_meas_position
                               - u16LocalTps2_ratio_meas_position);

      u16LocalFilterAbs = (uint16)(MATHSRV_udtABS(s32LocalFilter));
      u16LocalFiltredPos =
         MATHSRV_u16FirstOrderFilterGu8(Tps_1_drop_mcut_filter_gain,
                                        &THRMCUT_u32RatioMeasPosFiltMem,
                                        u16LocalFilterAbs);
      THRMCUT_u16FiltredPosition = (uint16)MATHSRV_udtMIN(u16LocalFiltredPos,
                                                          1024);
      if(bLocalInhThrCutDet == 0)
      {
         if(THRMCUT_u16FiltredPosition < Tps_drop_mcut_diff_tolerance)
         {
            THRMCUT_bMcutDetectflag = 0;
         }
         else
         {
            s32LocalDeltaFilter = s32LocalFilter - THRMCUT_s32FilterPrev;

            u32LocalDeltaFilter = (uint32)(MATHSRV_udtABS(s32LocalDeltaFilter));

            if(u32LocalDeltaFilter >= Tps_drop_mcut_grad_tolerance)
            {
               THRMCUT_bMcutDetectflag = 1;
            }
         }
      }
      else
      {
         THRMCUT_bMcutDetectflag = 0;
      }

      if (  (THRMCUT_bMcutDetectflag != 0)
         && (bLocalMcutDetectflagPrev == 0))
      {
         THRMCUT_u16McutDetectflagTimer = Thr_tiMcutMaxDetTi_C;
         if (THRMCUT_u16McutDetectflagTimer == 0)
         {
            THRMCUT_bMcutDetectflagTimeOut = 1;
         }
         else
         {
            THRMCUT_bMcutDetectflagTimeOut = 0;
         }
      }
      else
      {
         if (THRMCUT_u16McutDetectflagTimer > 0)
         {
            THRMCUT_u16McutDetectflagTimer =
               (uint16)(THRMCUT_u16McutDetectflagTimer - 1);

            if (THRMCUT_u16McutDetectflagTimer == 0)
            {
               THRMCUT_bMcutDetectflagTimeOut = 1;
            }
            else
            {
               THRMCUT_bMcutDetectflagTimeOut = 0;
            }
         }
      }
      if (  (THRMCUT_bMcutDetectflag != 0)
         && (THRMCUT_bMcutDetectflagTimeOut == 0))
      {
         VEMS_vidSET(Tps_mcut_detect_flag, 1);
      }
      else
      {
         VEMS_vidSET(Tps_mcut_detect_flag, 0);
      }
      THRMCUT_s32FilterPrev = s32LocalFilter;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidManager                                          */
/* !Description : Production de l’indicateur de l'inhibition du figeage de la */
/*                consigne papillon en cas de détection d'une micro-coupure.  */
/* !Number      : FCT1.3                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret void THRMCUT_vidTpsRatioMeasPosEnab();                       */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   extf argret void THRMCUT_vidPiste1Mng();                                 */
/*   extf argret void THRMCUT_vidPiste2Mng();                                 */
/*   input boolean Tps_1_mcut_det_manu_inh;                                   */
/*   input boolean Throttle_pos_ref_freeze_manu_inh;                          */
/*   input boolean Tps_ratio_meas_position_enab;                              */
/*   output boolean Throttle_pos_ref_freeze_enab;                             */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidManager(void)
{
   if (Tps_1_mcut_det_manu_inh == 0)
   {
      THRMCUT_vidTpsRatioMeasPosEnab();

      if (  (Throttle_pos_ref_freeze_manu_inh == 0)
         && (Tps_ratio_meas_position_enab == 0))
      {
         VEMS_vidSET(Throttle_pos_ref_freeze_enab, 1);
      }
      else
      {
         VEMS_vidSET(Throttle_pos_ref_freeze_enab, 0);
      }

      THRMCUT_vidPiste1Mng();
      THRMCUT_vidPiste2Mng();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidTpsRatioMeasPosEnab                              */
/* !Description : Determination conditions for normal use of tracks 1 and 2 of*/
/*                the position BFM                                            */
/* !Number      : FCT1.4                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16          */
/*   u16IdxDft);                                                              */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   input uint8 Conf_alimentation_thr;                                       */
/*   input boolean Tps_mcut_detect_flag;                                      */
/*   output boolean Tps_ratio_meas_position_enab;                             */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidTpsRatioMeasPosEnab(void)
{
   /* Creation of the variables */
   GDFRM_tenuGDUState LocalstDgoScgPosnSnsr1;
   GDFRM_tenuGDUState LocalstDgoScpPosnSnsr1;
   GDFRM_tenuGDUState LocalstDgoScgPosnSnsr2;
   GDFRM_tenuGDUState LocalstDgoScpPosnSnsr2;
   GDFRM_tenuGDUState LocalstDgoCohPosnSnsr;
   GDFRM_tenuGDUState LocalstDgoORng_vMesX_sfty;
   boolean            bLocalTps_mcut_detect_flag;


   /* Affectation of the variables */
   LocalstDgoScgPosnSnsr1 = GDGAR_tenuGetStDgo(GD_DFT_SCGPOSNSNSR1);
   LocalstDgoScpPosnSnsr1 = GDGAR_tenuGetStDgo(GD_DFT_SCPPOSNSNSR1);
   LocalstDgoScgPosnSnsr2 = GDGAR_tenuGetStDgo(GD_DFT_SCGPOSNSNSR2);
   LocalstDgoScpPosnSnsr2 = GDGAR_tenuGetStDgo(GD_DFT_SCPPOSNSNSR2);
   LocalstDgoCohPosnSnsr = GDGAR_tenuGetStDgo(GD_DFT_COHPOSNSNSR);


   if (Conf_alimentation_thr > 5)
   {
      LocalstDgoORng_vMesX_sfty = GDGAR_tenuGetStDgo(GD_DFT_ORNG_VMES3_SFTY);
   }
   else
   {
      if(Conf_alimentation_thr > 2)
      {
         LocalstDgoORng_vMesX_sfty = GDGAR_tenuGetStDgo(GD_DFT_ORNG_VMES2_SFTY);
      }
      else
      {
         LocalstDgoORng_vMesX_sfty = GDGAR_tenuGetStDgo(GD_DFT_ORNG_VMES1_SFTY);
      }
   }

   VEMS_vidGET(Tps_mcut_detect_flag, bLocalTps_mcut_detect_flag);

   if (  (bLocalTps_mcut_detect_flag != 0)
      || (LocalstDgoScgPosnSnsr1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScpPosnSnsr1 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScgPosnSnsr2 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoScpPosnSnsr2 == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoCohPosnSnsr == GDU_ETAT_PCTL_PRESENT)
      || (LocalstDgoORng_vMesX_sfty == GDU_ETAT_PCTL_PRESENT))
   {
      Tps_ratio_meas_position_enab = 0;
   }
   else
   {
      Tps_ratio_meas_position_enab = 1;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidPiste1Mng                                        */
/* !Description : Management of the Piste 1                                   */
/* !Number      : FCT1.5                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   extf argret void THRMCUT_vidSwitchManagementPiste1();                    */
/*   input uint16 Tps_1_ratio_meas_position;                                  */
/*   input boolean Tps_ratio_meas_position_enab;                              */
/*   input uint16 Tps_1_ratio_meas_pos_prec_2;                                */
/*   input uint16 Tps_1_ratio_meas_pos_prec_1;                                */
/*   input uint16 Tps_1_ratio_meas_pos_prec_0;                                */
/*   input boolean Tps_ratio_meas_position_enab_prev;                         */
/*   input uint8 Tps_num_rec_prev_mcut;                                       */
/*   input uint16 Tps_1_ratio_meas_pos_prec_3;                                */
/*   input uint16 Tpac_throttle_position_reference;                           */
/*   input uint8 Tps_overlap_gain_meas;                                       */
/*   input uint8 Tps_overlap_gain_ref;                                        */
/*   output uint16 Tps_1_ratio_meas_pos_prec_3;                               */
/*   output uint16 Tps_1_ratio_meas_pos_prec_2;                               */
/*   output uint16 Tps_1_ratio_meas_pos_prec_1;                               */
/*   output uint16 Tps_1_ratio_meas_pos_prec_0;                               */
/*   output boolean Tps_1_overlap_demand;                                     */
/*   output uint16 Tps_1_ratio_meas_pos_overlap;                              */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidPiste1Mng(void)
{
   uint16 u16LocalMeasPos;
   uint16 u16LocalTps1_ratio_meas_position;
   uint16 u16LocalTpacThrottlePosReference;
   uint32 u32LocalVar;


   VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
   /* Management of the function THRMCUT_vidNominalModePiste1 */
   if (Tps_ratio_meas_position_enab != 0)
   {
      Tps_1_ratio_meas_pos_prec_3 =
         (uint16)MATHSRV_udtMIN(Tps_1_ratio_meas_pos_prec_2, 1024);
      Tps_1_ratio_meas_pos_prec_2 =
         (uint16)MATHSRV_udtMIN(Tps_1_ratio_meas_pos_prec_1, 1024);
      Tps_1_ratio_meas_pos_prec_1 =
         (uint16)MATHSRV_udtMIN(Tps_1_ratio_meas_pos_prec_0, 1024);
      Tps_1_ratio_meas_pos_prec_0 =
         (uint16)MATHSRV_udtMIN(u16LocalTps1_ratio_meas_position, 1024);

      VEMS_vidSET(Tps_1_overlap_demand, 0);
   }
   else
   {
      VEMS_vidSET(Tps_1_overlap_demand, 1);
   }

   /* Management of the function THRMCUT_vidOverlapping_value_piste1 */
   if (  (Tps_ratio_meas_position_enab == 0)
      && (Tps_ratio_meas_position_enab_prev != 0))
   {
      switch (Tps_num_rec_prev_mcut)
      {
         case 0:
            u16LocalMeasPos = u16LocalTps1_ratio_meas_position;
            break;

         case 1:
            u16LocalMeasPos = Tps_1_ratio_meas_pos_prec_1;
            break;

         case 2:
            u16LocalMeasPos = Tps_1_ratio_meas_pos_prec_2;
            break;

         default:
            u16LocalMeasPos = Tps_1_ratio_meas_pos_prec_3;
            break;
      }

      VEMS_vidGET(Tpac_throttle_position_reference,
                  u16LocalTpacThrottlePosReference);
      u32LocalVar = ( (uint32)( u16LocalMeasPos
                              * (uint16)(Tps_overlap_gain_meas + 1))
                    + (uint32)( u16LocalTpacThrottlePosReference
                              * (uint16)(Tps_overlap_gain_ref + 1)));

      u32LocalVar = ( u32LocalVar
                    / ( Tps_overlap_gain_meas
                      + Tps_overlap_gain_ref
                      + 2));
      Tps_1_ratio_meas_pos_overlap = (uint16)MATHSRV_udtMIN(u32LocalVar, 1024);
   }

   /* Management of the function THRMCUT_vidSwitchManagementPiste1 */
   THRMCUT_vidSwitchManagementPiste1();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidSwitchManagementPiste1                           */
/* !Description : Estimation of the micro cut for the piste 1                 */
/* !Number      : FCT1.6                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint16 Tps_1_ratio_meas_position;                                  */
/*   input boolean Tps_1_overlap_demand;                                      */
/*   input uint16 Tps_1_raw_filt_position;                                    */
/*   input boolean Tps_1_overlap_demand_Prev;                                 */
/*   input uint16 Tps_1_ratio_meas_pos_overlap;                               */
/*   input uint8 Tps_overlap_switch_step_number;                              */
/*   input uint16 Tps_1_diff_ratio_meas_overlap;                              */
/*   input uint16 Tps_1_switch_step;                                          */
/*   input uint16 Tps_overlap_switch_max_rate;                                */
/*   output uint16 Tps_1_diff_ratio_meas_overlap;                             */
/*   output uint16 Tps_1_switch_step;                                         */
/*   output uint16 Tps_1_raw_filt_position;                                   */
/*   output boolean Tps_1_overlap_demand_Prev;                                */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidSwitchManagementPiste1(void)
{
   boolean bLocalTps_1_overlap_demand;
   uint16  u16LocalSlewRate;
   uint16  u16LocalTps1_ratio_meas_position;
   uint16  u16LocalTps_1_raw_filt_position;
   uint16  u16LocalTps1RatioMeasPos;
   sint32  s32LocalDiff;


   VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
   VEMS_vidGET(Tps_1_overlap_demand, bLocalTps_1_overlap_demand);
   VEMS_vidGET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);

   if (bLocalTps_1_overlap_demand != Tps_1_overlap_demand_Prev)
   {
      /* Management of the function THRMCUT_vidDiffEstimationPiste1 */

      s32LocalDiff = ( u16LocalTps1_ratio_meas_position
                     - Tps_1_ratio_meas_pos_overlap);

      u16LocalTps1RatioMeasPos = (uint16)MATHSRV_udtABS(s32LocalDiff);

      Tps_1_diff_ratio_meas_overlap =
         (uint16)MATHSRV_udtMIN(u16LocalTps1RatioMeasPos, 1024);

      u16LocalTps1RatioMeasPos =
         (uint16)( Tps_1_diff_ratio_meas_overlap
                 / (uint16)( Tps_overlap_switch_step_number
                           + 1));
      Tps_1_switch_step = u16LocalTps1RatioMeasPos;
   }
   else
   {
      /* Management of the function THRMCUT_vidSwitchingTransientsPiste1 */
      s32LocalDiff = Tps_1_diff_ratio_meas_overlap - Tps_1_switch_step;
      Tps_1_diff_ratio_meas_overlap = (uint16)MATHSRV_udtCLAMP(s32LocalDiff,
                                                               0,
                                                               1024);
   }

   if (bLocalTps_1_overlap_demand != 0)
   {
      u16LocalSlewRate = Tps_1_ratio_meas_pos_overlap;
   }
   else
   {
      u16LocalSlewRate = u16LocalTps1_ratio_meas_position;
   }

   if (Tps_1_diff_ratio_meas_overlap == 0)
   {
      u16LocalSlewRate = MATHSRV_u16SlewFilter(u16LocalTps_1_raw_filt_position,
                                               u16LocalSlewRate,
                                               1024,
                                               1024);
   }
   else
   {
      u16LocalSlewRate = MATHSRV_u16SlewFilter(u16LocalTps_1_raw_filt_position,
                                               u16LocalSlewRate,
                                               Tps_overlap_switch_max_rate,
                                               Tps_overlap_switch_max_rate);
   }

   u16LocalSlewRate = (uint16)MATHSRV_udtMIN(u16LocalSlewRate, 1024);
   VEMS_vidSET(Tps_1_raw_filt_position, u16LocalSlewRate);
   Tps_1_overlap_demand_Prev = bLocalTps_1_overlap_demand;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidPiste2Mng                                        */
/* !Description : Management of the Piste 2                                   */
/* !Number      : FCT1.7                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   extf argret void THRMCUT_vidSwitchManagementPiste2();                    */
/*   input uint16 Tps_2_ratio_meas_position;                                  */
/*   input boolean Tps_ratio_meas_position_enab;                              */
/*   input uint16 Tps_2_ratio_meas_pos_prec_2;                                */
/*   input uint16 Tps_2_ratio_meas_pos_prec_1;                                */
/*   input uint16 Tps_2_ratio_meas_pos_prec_0;                                */
/*   input boolean Tps_ratio_meas_position_enab_prev;                         */
/*   input uint8 Tps_num_rec_prev_mcut;                                       */
/*   input uint16 Tps_2_ratio_meas_pos_prec_3;                                */
/*   input uint16 Tpac_throttle_position_reference;                           */
/*   input uint8 Tps_overlap_gain_meas;                                       */
/*   input uint8 Tps_overlap_gain_ref;                                        */
/*   output uint16 Tps_2_ratio_meas_pos_prec_3;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_2;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_1;                               */
/*   output uint16 Tps_2_ratio_meas_pos_prec_0;                               */
/*   output boolean Tps_2_overlap_demand;                                     */
/*   output uint16 Tps_2_ratio_meas_pos_overlap;                              */
/*   output boolean Tps_ratio_meas_position_enab_prev;                        */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidPiste2Mng(void)
{
   uint16 u16LocalMeasPos;
   uint16 u16LocalTps2_ratio_meas_position;
   uint16 u16LocalTpacThrottlePosReference;
   uint32 u32LocalVar;


   /* Management of the function THRMCUT_vidNominalModePiste1 */
   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);
   if (Tps_ratio_meas_position_enab != 0)
   {
      Tps_2_ratio_meas_pos_prec_3 =
         (uint16)MATHSRV_udtMIN(Tps_2_ratio_meas_pos_prec_2, 1024);
      Tps_2_ratio_meas_pos_prec_2 =
         (uint16)MATHSRV_udtMIN(Tps_2_ratio_meas_pos_prec_1, 1024);
      Tps_2_ratio_meas_pos_prec_1 =
         (uint16)MATHSRV_udtMIN(Tps_2_ratio_meas_pos_prec_0, 1024);
      Tps_2_ratio_meas_pos_prec_0 =
         (uint16)MATHSRV_udtMIN(u16LocalTps2_ratio_meas_position, 1024);

      VEMS_vidSET(Tps_2_overlap_demand, 0);
   }
   else
   {
      VEMS_vidSET(Tps_2_overlap_demand, 1);
   }

   /* Management of the function THRMCUT_vidOverlapping_value_piste1 */
   if (  (Tps_ratio_meas_position_enab == 0)
      && (Tps_ratio_meas_position_enab_prev != 0))
   {
      switch (Tps_num_rec_prev_mcut)
      {
         case 0:
            u16LocalMeasPos = u16LocalTps2_ratio_meas_position;
            break;

         case 1:
            u16LocalMeasPos = Tps_2_ratio_meas_pos_prec_1;
            break;

         case 2:
            u16LocalMeasPos = Tps_2_ratio_meas_pos_prec_2;
            break;

         default:
            u16LocalMeasPos = Tps_2_ratio_meas_pos_prec_3;
            break;
      }

      VEMS_vidGET(Tpac_throttle_position_reference,
                  u16LocalTpacThrottlePosReference);
      u32LocalVar = ( (uint32)( u16LocalMeasPos
                              * (uint16)(Tps_overlap_gain_meas + 1))
                    + (uint32)( u16LocalTpacThrottlePosReference
                              * (uint16)(Tps_overlap_gain_ref + 1)));

      u32LocalVar = ( u32LocalVar
                    / ( Tps_overlap_gain_meas
                      + Tps_overlap_gain_ref
                      + 2));
      Tps_2_ratio_meas_pos_overlap = (uint16)MATHSRV_udtMIN(u32LocalVar, 1024);
   }

   /* Management of the function THRMCUT_vidSwitchManagementPiste1 */
   THRMCUT_vidSwitchManagementPiste2();

   Tps_ratio_meas_position_enab_prev = Tps_ratio_meas_position_enab;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidSwitchManagementPiste2                           */
/* !Description : Estimation of the micro cut for the piste 2                 */
/* !Number      : FCT1.8                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint16 Tps_2_ratio_meas_position;                                  */
/*   input boolean Tps_2_overlap_demand;                                      */
/*   input uint16 Tps_2_raw_filt_position;                                    */
/*   input boolean Tps_2_overlap_demand_Prev;                                 */
/*   input uint16 Tps_2_ratio_meas_pos_overlap;                               */
/*   input uint8 Tps_overlap_switch_step_number;                              */
/*   input uint16 Tps_2_diff_ratio_meas_overlap;                              */
/*   input uint16 Tps_2_switch_step;                                          */
/*   input uint16 Tps_overlap_switch_max_rate;                                */
/*   output uint16 Tps_2_diff_ratio_meas_overlap;                             */
/*   output uint16 Tps_2_switch_step;                                         */
/*   output uint16 Tps_2_raw_filt_position;                                   */
/*   output boolean Tps_2_overlap_demand_Prev;                                */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidSwitchManagementPiste2(void)
{
   boolean bLocalTps_2_overlap_demand;
   uint16  u16LocalSlewRate;
   uint16  u16LocalTps2_ratio_meas_position;
   uint16  u16LocalTps_2_raw_filt_position;
   uint16  u16LocalTps2RatioMeasPos;
   sint32  s32LocalDiff;


   VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);
   VEMS_vidGET(Tps_2_overlap_demand, bLocalTps_2_overlap_demand);
   VEMS_vidGET(Tps_2_raw_filt_position, u16LocalTps_2_raw_filt_position);

   if (bLocalTps_2_overlap_demand != Tps_2_overlap_demand_Prev)
   {
      s32LocalDiff = ( u16LocalTps2_ratio_meas_position
                     - Tps_2_ratio_meas_pos_overlap);

      u16LocalTps2RatioMeasPos = (uint16)MATHSRV_udtABS(s32LocalDiff);

      Tps_2_diff_ratio_meas_overlap =
         (uint16)MATHSRV_udtMIN(u16LocalTps2RatioMeasPos, 1024);

      u16LocalTps2RatioMeasPos =
         (uint16)( Tps_2_diff_ratio_meas_overlap
                 / (uint16)( Tps_overlap_switch_step_number
                           + 1));
      Tps_2_switch_step = u16LocalTps2RatioMeasPos;
   }
   else
   {
      s32LocalDiff = ( Tps_2_diff_ratio_meas_overlap
                     - Tps_2_switch_step);
      Tps_2_diff_ratio_meas_overlap = (uint16)MATHSRV_udtCLAMP(s32LocalDiff,
                                                               0,
                                                               1024);
   }

   if (bLocalTps_2_overlap_demand != 0)
   {
      u16LocalSlewRate = Tps_2_ratio_meas_pos_overlap;
   }
   else
   {
      u16LocalSlewRate = u16LocalTps2_ratio_meas_position;
   }

   if (Tps_2_diff_ratio_meas_overlap == 0)
   {
      u16LocalSlewRate = MATHSRV_u16SlewFilter(u16LocalTps_2_raw_filt_position,
                                               u16LocalSlewRate,
                                               1024,
                                               1024);
   }
   else
   {
      u16LocalSlewRate = MATHSRV_u16SlewFilter(u16LocalTps_2_raw_filt_position,
                                               u16LocalSlewRate,
                                               Tps_overlap_switch_max_rate,
                                               Tps_overlap_switch_max_rate);
   }

   u16LocalSlewRate = (uint16)MATHSRV_udtMIN(u16LocalSlewRate, 1024);
   VEMS_vidSET(Tps_2_raw_filt_position, u16LocalSlewRate);
   Tps_2_overlap_demand_Prev = bLocalTps_2_overlap_demand;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : THRMCUT_vidMicroCutBmpFuncInhib                             */
/* !Description : Inhibition of the micro cut functionnality                  */
/* !Number      : FCT1.9                                                      */
/* !Author      : B.KBOUBI                                                    */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input boolean Tps_1_mcut_det_manu_inh;                                   */
/*   input uint16 Tps_1_ratio_meas_position;                                  */
/*   input uint16 Tps_2_ratio_meas_position;                                  */
/*   output uint16 Tps_1_raw_filt_position;                                   */
/*   output uint16 Tps_2_raw_filt_position;                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRMCUT_vidMicroCutBmpFuncInhib(void)
{
   uint16 u16LocalTps1_ratio_meas_position;
   uint16 u16LocalTps2_ratio_meas_position;
   uint16 u16LocalTpsRawFiltPosition;


   if (Tps_1_mcut_det_manu_inh != 0)
   {
      VEMS_vidGET(Tps_1_ratio_meas_position, u16LocalTps1_ratio_meas_position);
      VEMS_vidGET(Tps_2_ratio_meas_position, u16LocalTps2_ratio_meas_position);

      u16LocalTpsRawFiltPosition =
         (uint16)MATHSRV_udtMIN(u16LocalTps1_ratio_meas_position, 1024);
      VEMS_vidSET(Tps_1_raw_filt_position, u16LocalTpsRawFiltPosition);

      u16LocalTpsRawFiltPosition =
         (uint16)MATHSRV_udtMIN(u16LocalTps2_ratio_meas_position, 1024);
      VEMS_vidSET(Tps_2_raw_filt_position, u16LocalTpsRawFiltPosition);
   }
}
/*------------------------------ End of file ---------------------------------*/