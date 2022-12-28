/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSTOPCLCN                                             */
/* !Description     : THRSTOPCLCN component.                                  */
/*                                                                            */
/* !Module          : THRSTOPCLCN                                             */
/* !Description     : Calcul des butees du papillon.                          */
/*                                                                            */
/* !File            : THRSTOPCLCN_FCT1.C                                      */
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
/*   1 / THRSTOPCLCN_vidInitOutput                                            */
/*   2 / THRSTOPCLCN_vidInitEndStopHiLow                                      */
/*   3 / THRSTOPCLCN_vidPositionFiltering                                     */
/*   4 / THRSTOPCLCN_vidOpenThrusts                                           */
/*   5 / THRSTOPCLCN_vidClosedThrusts                                         */
/*   6 / THRSTOPCLCN_vidFilter                                                */
/*   7 / THRSTOPCLCN_vidRefLearning                                           */
/*   8 / THRSTOPCLCN_vidNoFilter                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 04799 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#061157                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSTOPCLCN/THRSTOPCLCN_fct1$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   20 Apr 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "THRSTOPCLCN.h"
#include "THRSTOPCLCN_L.h"
#include "THRSTOPCLCN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation des variables produites le       */
/*                 composant software THRSTOPCLCN.                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input ???? UINT32_MIN;                                                    */
/*  input uint16 Tps_1_raw_filt_position;                                     */
/*  input uint16 Tps_2_raw_filt_position;                                     */
/*  output uint16 Tpac_1_filt_filt_position;                                  */
/*  output uint16 Tpac_2_filt_filt_position;                                  */
/*  output boolean Tpac_throttle_locked;                                      */
/*  output boolean Thr_FLrn_bAcv_PwrOn;                                       */
/*  output uint32 THRSTOPCLCN_u32ThrotFiltPosMem1;                            */
/*  output uint32 THRSTOPCLCN_u32ThrotFiltPosMem2;                            */
/*  output uint16 THRSTOPCLCN_u16Tps1RawPosPrev1;                             */
/*  output uint16 THRSTOPCLCN_u16Tps1RawPosPrev2;                             */
/*  output uint16 THRSTOPCLCN_u16Tps2RawPosPrev1;                             */
/*  output uint16 THRSTOPCLCN_u16Tps2RawPosPrev2;                             */
/*  output uint16 Tpac_1_closed_throttle_pos_prec;                            */
/*  output uint16 Tpac_2_closed_throttle_pos_prec;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidInitOutput(void)
{
   uint16 u16LocalTps_1_raw_filt_position;
   uint16 u16LocalTps_2_raw_filt_position;

   /* Outputs initializations */
   VEMS_vidSET(Tpac_1_filt_filt_position, 0);
   VEMS_vidSET(Tpac_2_filt_filt_position, 0);
   VEMS_vidSET(Tpac_throttle_locked, 0);
   VEMS_vidSET(Thr_FLrn_bAcv_PwrOn, 0);
   /* filters initialization */
   THRSTOPCLCN_u32ThrotFiltPosMem1 = UINT32_MIN;
   THRSTOPCLCN_u32ThrotFiltPosMem2 = UINT32_MIN;
   VEMS_vidGET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);
   VEMS_vidGET(Tps_2_raw_filt_position, u16LocalTps_2_raw_filt_position);
   THRSTOPCLCN_u16Tps1RawPosPrev1 = u16LocalTps_1_raw_filt_position;
   THRSTOPCLCN_u16Tps1RawPosPrev2 = u16LocalTps_1_raw_filt_position;
   THRSTOPCLCN_u16Tps2RawPosPrev1 = u16LocalTps_2_raw_filt_position;
   THRSTOPCLCN_u16Tps2RawPosPrev2 = u16LocalTps_2_raw_filt_position;
   /* Previous values initialization */
   Tpac_1_closed_throttle_pos_prec = 0;
   Tpac_2_closed_throttle_pos_prec = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidInitEndStopHiLow                            */
/* !Description :  Les valeurs maximales et minimales lues sur les deux       */
/*                 capteurs sont initialisées à une valeur intermédiaire avant*/
/*                 que l’apprentissage ne débute                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_middle_throttle_pos;                                    */
/*  output uint16 Tpac_1_max_measured_position;                               */
/*  output uint16 Tpac_2_max_measured_position;                               */
/*  output uint16 Tpac_1_min_measured_position;                               */
/*  output uint16 Tpac_2_min_measured_position;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidInitEndStopHiLow(void)
{
   Tpac_1_max_measured_position =
      (uint16)MATHSRV_udtMIN(Tpac_middle_throttle_pos, 1023);
   Tpac_2_max_measured_position =
      (uint16)MATHSRV_udtMIN(Tpac_middle_throttle_pos, 1023);
   Tpac_1_min_measured_position =
      (uint16)MATHSRV_udtMIN(Tpac_middle_throttle_pos, 1023);
   Tpac_2_min_measured_position =
      (uint16)MATHSRV_udtMIN(Tpac_middle_throttle_pos, 1023);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidPositionFiltering                           */
/* !Description :  Les positions fournies par les deux capteurs sont filtrées */
/*                 par un filtre médian. Les maxima et minima sont enregistrés*/
/*                 en permanence pour la recherche et l'apprentissage des     */
/*                 butées. Elles sont réinitialisées à chaque début           */
/*                 d’apprentissage de butée.                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16MedianFilter(????);                                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tps_1_raw_filt_position;                                     */
/*  input uint16 THRSTOPCLCN_u16Tps1RawPosPrev1;                              */
/*  input uint16 THRSTOPCLCN_u16Tps1RawPosPrev2;                              */
/*  input uint16 Tpac_1_max_measured_position;                                */
/*  input uint16 Tpac_1_min_measured_position;                                */
/*  input uint16 Tps_2_raw_filt_position;                                     */
/*  input uint16 THRSTOPCLCN_u16Tps2RawPosPrev1;                              */
/*  input uint16 THRSTOPCLCN_u16Tps2RawPosPrev2;                              */
/*  input uint16 Tpac_2_max_measured_position;                                */
/*  input uint16 Tpac_2_min_measured_position;                                */
/*  output uint16 Tpac_1_filt_filt_position;                                  */
/*  output uint16 Tpac_1_max_measured_position;                               */
/*  output uint16 Tpac_1_min_measured_position;                               */
/*  output uint16 Tpac_2_filt_filt_position;                                  */
/*  output uint16 Tpac_2_max_measured_position;                               */
/*  output uint16 Tpac_2_min_measured_position;                               */
/*  output uint16 THRSTOPCLCN_u16Tps1RawPosPrev2;                             */
/*  output uint16 THRSTOPCLCN_u16Tps1RawPosPrev1;                             */
/*  output uint16 THRSTOPCLCN_u16Tps2RawPosPrev2;                             */
/*  output uint16 THRSTOPCLCN_u16Tps2RawPosPrev1;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidPositionFiltering(void)
{
   uint16 u16LocalTps_1_raw_filt_position;
   uint16 u16Localfilter;
   uint16 u16LocalTps_2_raw_filt_position;
   uint16 u16LocalTpac_1_filt_filtposition;
   uint16 u16LocalTpac_2_filt_filtposition;
   uint16 u16LocalTpac_1_max_position;
   uint16 u16LocalTpac_2_max_position;

   /* Filtering of position provieded by detector 1 */
   VEMS_vidGET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);
   u16Localfilter = MATHSRV_u16MedianFilter(u16LocalTps_1_raw_filt_position,
                                            THRSTOPCLCN_u16Tps1RawPosPrev1,
                                            THRSTOPCLCN_u16Tps1RawPosPrev2);
   u16LocalTpac_1_filt_filtposition =
      (uint16)MATHSRV_udtMIN(u16Localfilter, 1023);
   VEMS_vidSET(Tpac_1_filt_filt_position, u16LocalTpac_1_filt_filtposition);
   u16LocalTpac_1_max_position =
      (uint16)MATHSRV_udtMAX(u16LocalTpac_1_filt_filtposition,
                             Tpac_1_max_measured_position);
   Tpac_1_max_measured_position =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_max_position, 1023);

   Tpac_1_min_measured_position =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_filt_filtposition,
                             Tpac_1_min_measured_position);
   /* Filtering of position provieded by detector 2 */
   VEMS_vidGET(Tps_2_raw_filt_position, u16LocalTps_2_raw_filt_position);
   u16Localfilter = MATHSRV_u16MedianFilter(u16LocalTps_2_raw_filt_position,
                                            THRSTOPCLCN_u16Tps2RawPosPrev1,
                                            THRSTOPCLCN_u16Tps2RawPosPrev2);
   u16LocalTpac_2_filt_filtposition =
      (uint16)MATHSRV_udtMIN(u16Localfilter, 1023);
   VEMS_vidSET(Tpac_2_filt_filt_position, u16LocalTpac_2_filt_filtposition);
   u16LocalTpac_2_max_position =
      (uint16)MATHSRV_udtMAX(u16LocalTpac_2_filt_filtposition,
                             Tpac_2_max_measured_position);
   Tpac_2_max_measured_position =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_max_position, 1023);
   Tpac_2_min_measured_position =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_filt_filtposition,
                             Tpac_2_min_measured_position);
   THRSTOPCLCN_u16Tps1RawPosPrev2 =
      (uint16)MATHSRV_udtMIN(THRSTOPCLCN_u16Tps1RawPosPrev1, 1024);
   VEMS_vidGET(Tps_1_raw_filt_position, u16LocalTps_1_raw_filt_position);
   THRSTOPCLCN_u16Tps1RawPosPrev1 =
      (uint16)MATHSRV_udtMIN(u16LocalTps_1_raw_filt_position, 1024);

   THRSTOPCLCN_u16Tps2RawPosPrev2 =
      (uint16)MATHSRV_udtMIN(THRSTOPCLCN_u16Tps2RawPosPrev1, 1024);
   VEMS_vidGET(Tps_2_raw_filt_position, u16LocalTps_2_raw_filt_position);
   THRSTOPCLCN_u16Tps2RawPosPrev1 =
      (uint16)MATHSRV_udtMIN(u16LocalTps_2_raw_filt_position, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidOpenThrusts                                 */
/* !Description :  Si ces valeurs maximales sont hors-gamme, une panne «      */
/*                 Tpac_thrusts » est mémorisée immédiatement, dans le cas    */
/*                 d’un papillon à limp home négatif (Tpac_throttle_lh_pos =  */
/*                 0). La mesure est dite hors gamme et la butée  haute       */
/*                 conserve sa précédente valeur.                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpac_open_thrust_search_inh;                                */
/*  input uint16 Tpac_1_max_measured_position;                                */
/*  input uint16 Tpac_1_open_pos_max;                                         */
/*  input uint16 Tpac_1_open_pos_min;                                         */
/*  input uint16 Tpac_2_max_measured_position;                                */
/*  input uint16 Tpac_2_open_pos_max;                                         */
/*  input uint16 Tpac_2_open_pos_min;                                         */
/*  input uint16 Tpac_1_open_throttle_pos_cal;                                */
/*  input uint16 Tpac_2_open_throttle_pos_cal;                                */
/*  input boolean Tpac_throttle_lh_pos;                                       */
/*  input boolean Thr_bDgoEndStopReq1;                                        */
/*  input boolean Thr_bDgoEndStopReq2;                                        */
/*  output boolean Thr_bDgoEndStopReq1;                                       */
/*  output uint16 Tpac_1_open_throttle_pos;                                   */
/*  output boolean Thr_bDgoEndStopReq2;                                       */
/*  output uint16 Tpac_2_open_throttle_pos;                                   */
/*  output boolean Tpac_1_open_pos_dft;                                       */
/*  output boolean Tpac_2_open_pos_dft;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidOpenThrusts(void)
{
   boolean bLocalInhSecuMngThrPosnSen1;
   boolean bLocalInhSecuMngThrPosnSen2;
   uint16  u16LocalTpac_1_open_throttle_pos;
   uint16  u16LocalTpac_2_open_throttle_pos;

   if (Tpac_open_thrust_search_inh == 0)
   {  /* 1_Open_thrusts_1 */
      bLocalInhSecuMngThrPosnSen1 =
                           GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN1);
      if(bLocalInhSecuMngThrPosnSen1 == 0)
      {  /* Treatment of position provieded by detector 1 */
         if (  (Tpac_1_max_measured_position >= Tpac_1_open_pos_max)
            || (Tpac_1_max_measured_position <= Tpac_1_open_pos_min) )
         {
            Thr_bDgoEndStopReq1 = 1;
         }
         else
         {
            Thr_bDgoEndStopReq1 = 0;
            u16LocalTpac_1_open_throttle_pos =
               (uint16)MATHSRV_udtMIN(Tpac_1_max_measured_position, 1023);
            VEMS_vidSET(Tpac_1_open_throttle_pos,
                        u16LocalTpac_1_open_throttle_pos);
         }
      }
      /* 2_Open_thrusts_2 */
      bLocalInhSecuMngThrPosnSen2 =
                           GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN2);
      if(bLocalInhSecuMngThrPosnSen2 == 0)
      {
         if (  (Tpac_2_max_measured_position >= Tpac_2_open_pos_max)
            || (Tpac_2_max_measured_position <= Tpac_2_open_pos_min))
         {
            Thr_bDgoEndStopReq2 = 1;
         }
         else
         {
            Thr_bDgoEndStopReq2 = 0;
            u16LocalTpac_2_open_throttle_pos =
               (uint16)MATHSRV_udtMIN(Tpac_2_max_measured_position, 1023);
            VEMS_vidSET(Tpac_2_open_throttle_pos,
                        u16LocalTpac_2_open_throttle_pos);
         }
      }
   }
   else
   {
      u16LocalTpac_1_open_throttle_pos =
         (uint16)MATHSRV_udtMIN(Tpac_1_open_throttle_pos_cal, 1023);
      VEMS_vidSET(Tpac_1_open_throttle_pos, u16LocalTpac_1_open_throttle_pos);
      u16LocalTpac_2_open_throttle_pos =
         (uint16)MATHSRV_udtMIN(Tpac_2_open_throttle_pos_cal, 1023);
      VEMS_vidSET(Tpac_2_open_throttle_pos, u16LocalTpac_2_open_throttle_pos);
   }

   if (Tpac_throttle_lh_pos == 0)
   {
      Tpac_1_open_pos_dft = Thr_bDgoEndStopReq1;
      Tpac_2_open_pos_dft = Thr_bDgoEndStopReq2;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidClosedThrusts                               */
/* !Description :  Ce processus est « triggé » par l'automate de gestion de   */
/*                 l'asservissement du papillon motorisé lorsque la butée     */
/*                 basse est trouvée. La butée basse devient alors le minimum */
/*                 de position lu au cours de la recherche de butée.          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRSTOPCLCN_vidNoFilter();                               */
/*  extf argret void THRSTOPCLCN_vidFilter();                                 */
/*  extf argret void THRSTOPCLCN_vidRefLearning();                            */
/*  input uint16 Tpac_1_closed_throttle_pos;                                  */
/*  input uint16 Tpac_2_closed_throttle_pos;                                  */
/*  input uint16 Tpac_1_min_measured_position;                                */
/*  input uint16 Tpac_1_closed_pos_max;                                       */
/*  input uint16 Tpac_1_closed_pos_min;                                       */
/*  input uint16 Tpac_1_closed_throttle_pos_prec;                             */
/*  input uint16 Tpac_2_min_measured_position;                                */
/*  input uint16 Tpac_2_closed_pos_max;                                       */
/*  input uint16 Tpac_2_closed_pos_min;                                       */
/*  input uint16 Tpac_2_closed_throttle_pos_prec;                             */
/*  input boolean Tpac_closed_filter_manu_inh;                                */
/*  input boolean Thr_bNewThrCpt;                                             */
/*  input uint8 Temperature_air;                                              */
/*  input uint8 Tpac_closed_thrusts_air_temp_max;                             */
/*  input uint8 Tpac_closed_thrusts_air_temp_min;                             */
/*  output uint16 Tpac_1_closed_throttle_pos_prec;                            */
/*  output uint16 Tpac_2_closed_throttle_pos_prec;                            */
/*  output boolean Tpac_1_closed_pos_dft;                                     */
/*  output uint16 Tpac_1_closed_throttle_pos;                                 */
/*  output boolean Tpac_2_closed_pos_dft;                                     */
/*  output uint16 Tpac_2_closed_throttle_pos;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidClosedThrusts(void)
{
   boolean bLocalInhSecuMngThrPosnSen1;
   boolean bLocalInhSecuMngThrPosnSen2;
   uint8   u8LocalTemperature_air;
   uint16  u16LocalTpac_1_closed_throt_pos;
   uint16  u16LocalTpac_2_closed_throt_pos;


   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);

   Tpac_1_closed_throttle_pos_prec =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_closed_throt_pos, 1023);
   Tpac_2_closed_throttle_pos_prec =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_closed_throt_pos, 1023);

   bLocalInhSecuMngThrPosnSen1 =
                           GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN1);
   if (bLocalInhSecuMngThrPosnSen1 == 0)
   {  /* 1_Close_thrusts_1 */
      if (  (Tpac_1_min_measured_position >= Tpac_1_closed_pos_max)
         || (Tpac_1_min_measured_position <= Tpac_1_closed_pos_min))
      {
         Tpac_1_closed_pos_dft = 1;
         u16LocalTpac_1_closed_throt_pos = Tpac_1_closed_throttle_pos_prec;
      }
      else
      {
         u16LocalTpac_1_closed_throt_pos =
            (uint16)MATHSRV_udtMIN(Tpac_1_min_measured_position, 1023);
         Tpac_1_closed_pos_dft = 0;
      }
      VEMS_vidSET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   }

   bLocalInhSecuMngThrPosnSen2 =
                           GDGAR_bGetFRM(FRM_FRM_INHSECUMNGTHRPOSNSEN2);
   if (bLocalInhSecuMngThrPosnSen2 == 0)
   {  /* 2_Close_thrusts_2 */
      if (  (Tpac_2_min_measured_position >= Tpac_2_closed_pos_max)
         || (Tpac_2_min_measured_position <= Tpac_2_closed_pos_min) )
      {
         Tpac_2_closed_pos_dft = 1;
         u16LocalTpac_2_closed_throt_pos = Tpac_2_closed_throttle_pos_prec;
      }
      else
      {
         Tpac_2_closed_pos_dft = 0;
         u16LocalTpac_2_closed_throt_pos =
            (uint16)MATHSRV_udtMIN(Tpac_2_min_measured_position, 1023);
      }
      VEMS_vidSET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);
   }

   /* /3_Trait_closed_thrusts */

   if (Tpac_closed_filter_manu_inh != 0)
   {
      THRSTOPCLCN_vidNoFilter();
   }
   else
   {
      if (Thr_bNewThrCpt == 0)
      {
         VEMS_vidGET(Temperature_air, u8LocalTemperature_air);
         if (  (u8LocalTemperature_air <= Tpac_closed_thrusts_air_temp_max)
            && (u8LocalTemperature_air >= Tpac_closed_thrusts_air_temp_min) )
         {  /* 1_filtre */
            THRSTOPCLCN_vidFilter();
         }
      }
   }

   if (Thr_bNewThrCpt != 0)
   {  /* 2_ref_apprent */
      THRSTOPCLCN_vidRefLearning();
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidFilter                                      */
/* !Description :  L’évolution importante de la butée basse apprise du        */
/*                 papillon motorisé d’un roulage à un autre peut conduire à  */
/*                 des problèmes pour assurer la régulation ralenti. Pour     */
/*                 remédier à cela, on filtre la position apprise par un      */
/*                 filtre de premier ordre.                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16FirstOrderFilterGu8(????);                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_1_clo_throttle_filt_pos;                                */
/*  input uint16 Tpac_1_closed_throttle_pos;                                  */
/*  input uint8 Tpac_closed_filter_gain_pos;                                  */
/*  input uint8 Tpac_closed_filter_gain_neg;                                  */
/*  input uint32 THRSTOPCLCN_u32ThrotFiltPosMem1;                             */
/*  input uint16 Tpac_1_closed_throttle_ref;                                  */
/*  input uint16 Tpac_1_closed_pos_max_rr;                                    */
/*  input uint16 Tpac_2_clo_throttle_filt_pos;                                */
/*  input uint16 Tpac_2_closed_throttle_pos;                                  */
/*  input uint32 THRSTOPCLCN_u32ThrotFiltPosMem2;                             */
/*  input uint16 Tpac_2_closed_throttle_ref;                                  */
/*  input uint16 Tpac_2_closed_pos_max_rr;                                    */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*  output boolean Thr_bDgoClsIdlCtl;                                         */
/*  output boolean Thr_bMonRunClsIdlCtl;                                      */
/*  output boolean Thr_bMonWaitClsIdlCtl;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidFilter(void)
{
   boolean bLocalFailure;
   uint8   u8LocalGain;
   uint16  u16LocalFilterOut;
   uint16  u16LocalTpac_1_clo_throt_filtpos;
   uint16  u16LocalTpac_1_closed_throt_pos;
   uint16  u16LocalTpac_1_closed_throt_ref;
   uint16  u16LocalTpac_2_clo_throt_filtpos;
   uint16  u16LocalTpac_2_closed_throt_pos;
   uint16  u16LocalTpac_2_closed_throt_ref;


   bLocalFailure = 0;
   /* Filtring of position provieded by detector 1 */
   VEMS_vidGET(Tpac_1_clo_throttle_filt_pos, u16LocalTpac_1_clo_throt_filtpos);
   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   if (u16LocalTpac_1_closed_throt_pos >= u16LocalTpac_1_clo_throt_filtpos)
   {
      u8LocalGain = Tpac_closed_filter_gain_pos;
   }
   else
   {
      u8LocalGain = Tpac_closed_filter_gain_neg;
   }

   u16LocalFilterOut =
      MATHSRV_u16FirstOrderFilterGu8(u8LocalGain,
                                     &THRSTOPCLCN_u32ThrotFiltPosMem1,
                                     u16LocalTpac_1_closed_throt_pos);
   u16LocalTpac_1_clo_throt_filtpos = (uint16)MATHSRV_udtMIN(u16LocalFilterOut,
                                                             1024);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, u16LocalTpac_1_clo_throt_filtpos);

   VEMS_vidGET(Tpac_1_closed_throttle_ref, u16LocalTpac_1_closed_throt_ref);
   if (  (u16LocalTpac_1_clo_throt_filtpos >= ( u16LocalTpac_1_closed_throt_ref
                                              + Tpac_1_closed_pos_max_rr) )
      || (u16LocalTpac_1_clo_throt_filtpos <= ( u16LocalTpac_1_closed_throt_ref
                                              - Tpac_1_closed_pos_max_rr) ) )
   {
      bLocalFailure = 1;
   }

   /* Filtring of position provieded by detector 2 */
   VEMS_vidGET(Tpac_2_clo_throttle_filt_pos, u16LocalTpac_2_clo_throt_filtpos);
   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);
   if (u16LocalTpac_2_closed_throt_pos >= u16LocalTpac_2_clo_throt_filtpos)
   {
      u8LocalGain = Tpac_closed_filter_gain_pos;
   }
   else
   {
      u8LocalGain = Tpac_closed_filter_gain_neg;
   }

   u16LocalFilterOut =
      MATHSRV_u16FirstOrderFilterGu8(u8LocalGain,
                                     &THRSTOPCLCN_u32ThrotFiltPosMem2,
                                     u16LocalTpac_2_closed_throt_pos);
   u16LocalTpac_2_clo_throt_filtpos = (uint16)MATHSRV_udtMIN(u16LocalFilterOut,
                                                             1024);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, u16LocalTpac_2_clo_throt_filtpos);

   VEMS_vidGET(Tpac_2_closed_throttle_ref, u16LocalTpac_2_closed_throt_ref);
   if (  (u16LocalTpac_2_clo_throt_filtpos >= ( u16LocalTpac_2_closed_throt_ref
                                              + Tpac_2_closed_pos_max_rr) )
      || (u16LocalTpac_2_clo_throt_filtpos <= ( u16LocalTpac_2_closed_throt_ref
                                              - Tpac_2_closed_pos_max_rr) ) )
   {
      bLocalFailure = 1;
   }

   /* Diagnosis of End Stop on Idle */
   if (bLocalFailure != 0)
   {
      Thr_bDgoClsIdlCtl = 1;
   }
   else
   {
      Thr_bDgoClsIdlCtl = 0;
   }
   Thr_bMonRunClsIdlCtl = 1;
   Thr_bMonWaitClsIdlCtl = DIAG_DISPO;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidRefLearning                                 */
/* !Description :  Lors du premier apprentissage en usine ou lors des demandes*/
/*                 d’apprentissage en APV, on mémorise la première butée basse*/
/*                 apprise en E2PROM. Tpac_x_closed_throttle_ref n’est ensuite*/
/*                 pas remise à jour lors des apprentissages sous power-down. */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_1_closed_throttle_pos;                                  */
/*  input uint16 Tpac_2_closed_throttle_pos;                                  */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_1_closed_throttle_ref;                                 */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_2_closed_throttle_ref;                                 */
/*  output boolean Thr_bNewThrCpt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidRefLearning(void)
{
   uint16 u16LocalTpac_1_clo_throt_filtpos;
   uint16 u16LocalTpac_1_closed_throt_pos;
   uint16 u16LocalTpac_1_closed_throt_ref;
   uint16 u16LocalTpac_2_clo_throt_filtpos;
   uint16 u16LocalTpac_2_closed_throt_pos;
   uint16 u16LocalTpac_2_closed_throt_ref;


   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   u16LocalTpac_1_clo_throt_filtpos =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_closed_throt_pos, 1024);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, u16LocalTpac_1_clo_throt_filtpos);

   u16LocalTpac_1_closed_throt_ref =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_closed_throt_pos, 1023);
   VEMS_vidSET(Tpac_1_closed_throttle_ref, u16LocalTpac_1_closed_throt_ref);

   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);
   u16LocalTpac_2_clo_throt_filtpos =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_closed_throt_pos, 1024);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, u16LocalTpac_2_clo_throt_filtpos);
   u16LocalTpac_2_closed_throt_ref =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_closed_throt_pos, 1023);
   VEMS_vidSET(Tpac_2_closed_throttle_ref, u16LocalTpac_2_closed_throt_ref);
   Thr_bNewThrCpt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSTOPCLCN_vidNoFilter                                    */
/* !Description :  Le filtrage de la butée basse ne sera pas activé lors du   */
/*                 premier apprentissage en usine ou lors des demandes        */
/*                 d’apprentissage en APV.                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tpac_1_closed_throttle_pos;                                  */
/*  input uint16 Tpac_2_closed_throttle_pos;                                  */
/*  output uint16 Tpac_1_clo_throttle_filt_pos;                               */
/*  output uint16 Tpac_2_clo_throttle_filt_pos;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSTOPCLCN_vidNoFilter(void)
{
   uint16 u16LocalTpac_1_clo_throt_filtpos;
   uint16 u16LocalTpac_1_closed_throt_pos;
   uint16 u16LocalTpac_2_clo_throt_filtpos;
   uint16 u16LocalTpac_2_closed_throt_pos;


   VEMS_vidGET(Tpac_1_closed_throttle_pos, u16LocalTpac_1_closed_throt_pos);
   u16LocalTpac_1_clo_throt_filtpos =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_1_closed_throt_pos, 1024);
   VEMS_vidSET(Tpac_1_clo_throttle_filt_pos, u16LocalTpac_1_clo_throt_filtpos);

   VEMS_vidGET(Tpac_2_closed_throttle_pos, u16LocalTpac_2_closed_throt_pos);
   u16LocalTpac_2_clo_throt_filtpos =
      (uint16)MATHSRV_udtMIN(u16LocalTpac_2_closed_throt_pos, 1024);
   VEMS_vidSET(Tpac_2_clo_throttle_filt_pos, u16LocalTpac_2_clo_throt_filtpos);
}
/*------------------------------- End of file --------------------------------*/