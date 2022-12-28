/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHAUT                                             */
/* !Description     : THRBENCHAUT Component                                   */
/*                                                                            */
/* !Module          : THRBENCHAUT                                             */
/* !Description     : MODE BANC AUTOMATIQUE PAPILLON MOTORISE                 */
/*                                                                            */
/* !File            : THRBENCHAUT_FCT1.C                                      */
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
/*   1 / THRBENCHAUT_vidInitOutput                                            */
/*   2 / THRBENCHAUT_vidMotThrAutBenchMod                                     */
/*   3 / THRBENCHAUT_vidDynMode_1                                             */
/*   4 / THRBENCHAUT_vidControlPart                                           */
/*   5 / THRBENCHAUT_vidUserCalibrations                                      */
/*   6 / THRBENCHAUT_vidCurrentIndex                                          */
/*   7 / THRBENCHAUT_vidNextIndex                                             */
/*   8 / THRBENCHAUT_vidComputeAbsRefIncr                                     */
/*   9 / THRBENCHAUT_vidComputeAbsolutRef                                     */
/*   10 / THRBENCHAUT_vidComputeIncrement                                     */
/*                                                                            */
/* !Reference   : V02 NT 08 04529 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055915                                         */
/* !OtherRefs   : VEMS V02 ECU#056022                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRBENCHAUT/THRBENCHAUT_FCT1$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRBENCHAUT.h"
#include "THRBENCHAUT_L.h"
#include "THRBENCHAUT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation des paramètres produits          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st33 Etat_papmot_mode_banc;                                        */
/*  output uint8 Tpac_test_bed_table_counter;                                 */
/*  output boolean Tpac_compute_ref_enab;                                     */
/*  output uint16 Dtc_throttle_pos_for_test_bed;                              */
/*  output boolean THRBENCHAUT_bTpacOpenLpCtrlPrev;                           */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed1;                           */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed2;                           */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed3;                           */
/*  output uint16 Tpac_dyn_test_bed_duration;                                 */
/*  output uint8 Tpac_dyn_test_bed_next_offset;                               */
/*  output sint16 Tpac_dyn_test_bed_next_rel_ref;                             */
/*  output sint32 Tpac_dyn_test_bed_increment;                                */
/*  output uint8 Tpac_sin_signal_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidInitOutput(void)
{
   /* State machine initialization */
   Etat_papmot_mode_banc = PAPMOT_IDLE;
   Tpac_test_bed_table_counter = 0;
   Tpac_compute_ref_enab = 0;
   /* Module Output initialization */
   VEMS_vidSET(Dtc_throttle_pos_for_test_bed, 0);
   /* Internal variable initialization */
   THRBENCHAUT_bTpacOpenLpCtrlPrev = 0;
   THRBENCHAUT_u16DtcThrPosTestBed1 = 0;
   THRBENCHAUT_u16DtcThrPosTestBed2 = 0;
   THRBENCHAUT_u16DtcThrPosTestBed3 = 0;
   Tpac_dyn_test_bed_duration = 0;
   Tpac_dyn_test_bed_next_offset = 0;
   Tpac_dyn_test_bed_next_rel_ref = 0;
   Tpac_dyn_test_bed_increment = 0;
   Tpac_sin_signal_count = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidMotThrAutBenchMod                           */
/* !Description :  Le mode banc automatique présente deux modes de            */
/*                 fonctionnement :Un mode génération de consignes en         */
/*                 créneaux/rampes paramétrables et Un mode génération de     */
/*                 consignes en sinus paramétrables                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidDynMode_2();                              */
/*  extf argret void THRBENCHAUT_vidDynMode_3();                              */
/*  extf argret void THRBENCHAUT_vidDynMode_1();                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Dtc_throttle_test_bed_mode;                                 */
/*  input boolean Tpac_dyn_test_bed_mode;                                     */
/*  input uint16 THRBENCHAUT_u16DtcThrPosTestBed2;                            */
/*  input boolean Tpac_dyn_test_bed_sinus_mode;                               */
/*  input uint16 THRBENCHAUT_u16DtcThrPosTestBed3;                            */
/*  input uint16 THRBENCHAUT_u16DtcThrPosTestBed1;                            */
/*  output uint16 Dtc_throttle_pos_for_test_bed;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidMotThrAutBenchMod(void)
{
   uint16 u16LocalDtc_thr_pos_bed;


   if (Dtc_throttle_test_bed_mode != 0)
   {
      THRBENCHAUT_vidDynMode_2();
      THRBENCHAUT_vidDynMode_3();
      THRBENCHAUT_vidDynMode_1();
      /* ThrBenchAut */
      if (Tpac_dyn_test_bed_mode != 0)
      {
         u16LocalDtc_thr_pos_bed = THRBENCHAUT_u16DtcThrPosTestBed2;
      }
      else
      {
         if (Tpac_dyn_test_bed_sinus_mode != 0)
         {
            u16LocalDtc_thr_pos_bed = THRBENCHAUT_u16DtcThrPosTestBed3;
         }
         else
         {
            u16LocalDtc_thr_pos_bed = THRBENCHAUT_u16DtcThrPosTestBed1;
         }
      }

      u16LocalDtc_thr_pos_bed =
         (uint16)MATHSRV_udtMIN(u16LocalDtc_thr_pos_bed, 1024);
      VEMS_vidSET(Dtc_throttle_pos_for_test_bed, u16LocalDtc_thr_pos_bed);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidDynMode_1                                   */
/* !Description :  Le mode créneaux/rampes paramétrables (mode 1) est gérée   */
/*                 par un Stateflow et Le Stateflow commande une partie       */
/*                 opérative qui a pour but de calculer la consigne.          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidControlPart();                            */
/*  extf argret void THRBENCHAUT_vidComputeReference();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidDynMode_1(void)
{
   /* Dyn_mode_1 */
   THRBENCHAUT_vidControlPart();
   THRBENCHAUT_vidComputeReference();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidControlPart                                 */
/* !Description :  Partie contrôle faite avec un automate                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidUserCalibrations();                       */
/*  extf argret void THRBENCHAUT_vidComputeAbsRefIncr();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st33 Etat_papmot_mode_banc;                                         */
/*  input boolean Tpac_dyn_test_bed_mode;                                     */
/*  input boolean Tpac_dyn_test_bed_sinus_mode;                               */
/*  input uint8 Tpac_test_bed_table_counter;                                  */
/*  input uint16 Tpac_dyn_test_bed_duration;                                  */
/*  input uint16 Tpac_dyn_test_bed_tempo;                                     */
/*  input uint8 Tpac_dyn_test_bed_pattern_number;                             */
/*  output st33 Etat_papmot_mode_banc;                                        */
/*  output uint8 Tpac_test_bed_table_counter;                                 */
/*  output uint16 Tpac_dyn_test_bed_tempo;                                    */
/*  output boolean Tpac_compute_ref_enab;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidControlPart(void)
{
   /* Control_part */
   uint16 u16LocalTpac_test_bed_table;
   uint16 u16LocalTpac_dyn_test_bed;


   switch(Etat_papmot_mode_banc)
   {
      case PAPMOT_IDLE:
         if (  (Tpac_dyn_test_bed_mode == 0)
            && (Tpac_dyn_test_bed_sinus_mode == 0))
         {
            Etat_papmot_mode_banc = PAPMOT_INCR_IDX;
            u16LocalTpac_test_bed_table =
               (uint16)(Tpac_test_bed_table_counter + 1);
            Tpac_test_bed_table_counter =
               (uint8)MATHSRV_udtMIN(u16LocalTpac_test_bed_table, 16);
            Tpac_dyn_test_bed_tempo =
               (uint16)MATHSRV_udtMIN(Tpac_dyn_test_bed_duration, 409);
            Tpac_compute_ref_enab = 1;
            /* User_calibrations */
            THRBENCHAUT_vidUserCalibrations();
            /* Compute_abs_ref_incr */
            THRBENCHAUT_vidComputeAbsRefIncr();
         }
         break;
      case PAPMOT_INCR_IDX:
         if (  (Tpac_dyn_test_bed_mode != 0)
            || (Tpac_dyn_test_bed_sinus_mode != 0))
         {
            Tpac_test_bed_table_counter = 0;
            Tpac_compute_ref_enab = 0;
            Etat_papmot_mode_banc = PAPMOT_IDLE;
         }
         else
         {
            if (Tpac_dyn_test_bed_tempo == 0)
            {
               if ((Tpac_test_bed_table_counter >=
                    Tpac_dyn_test_bed_pattern_number)
                  || (Tpac_test_bed_table_counter >= 32))
               {
                  Tpac_test_bed_table_counter = 0;
               }
                  Etat_papmot_mode_banc = PAPMOT_INCR_IDX;
                  u16LocalTpac_test_bed_table =
                     (uint16)(Tpac_test_bed_table_counter + 1);
                  Tpac_test_bed_table_counter =
                     (uint8)MATHSRV_udtMIN(u16LocalTpac_test_bed_table,16);
                  Tpac_dyn_test_bed_tempo =
                     (uint16)MATHSRV_udtMIN(Tpac_dyn_test_bed_duration, 409);
                  Tpac_compute_ref_enab = 1;
                  /* Operative_part/1_User_calibrations */
                  THRBENCHAUT_vidUserCalibrations();
                  /* Operative_part/2_Compute_abs_ref_incr */
                  THRBENCHAUT_vidComputeAbsRefIncr();
            }
            else
            {
               u16LocalTpac_dyn_test_bed =
                  (uint16)(Tpac_dyn_test_bed_tempo - 1);
               Tpac_dyn_test_bed_tempo =
                  (uint16)MATHSRV_udtMIN(u16LocalTpac_dyn_test_bed, 409);
            }
         }
         break;
      default:
         Tpac_test_bed_table_counter = 0;
         Tpac_compute_ref_enab = 0;
         Etat_papmot_mode_banc = PAPMOT_IDLE;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidUserCalibrations                            */
/* !Description :  Ce sous-système définit les cartographies à partir         */
/*                 desquelles l’utilisateur définit le cycle d’actionnement   */
/*                 désiré.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidCurrentIndex();                           */
/*  extf argret void THRBENCHAUT_vidNextIndex();                              */
/*  input boolean Tpac_dyn_test_bed_type_ref;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidUserCalibrations(void)
{
   /* User_calibrations */
   THRBENCHAUT_vidCurrentIndex();
   if (Tpac_dyn_test_bed_type_ref != 0)
   {
      THRBENCHAUT_vidNextIndex();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidCurrentIndex                                */
/* !Description :  Définir l'index actuel de la calibration utilisée          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tpac_test_bed_table_counter;                                  */
/*  input sint16 Tpac_dyn_test_bed_rel_ref_map[16];                           */
/*  input uint16 Tpac_dyn_test_bed_duration_map[16];                          */
/*  input boolean Tpac_dyn_test_bed_type_ref_map[16];                         */
/*  input uint8 Tpac_dyn_test_bed_offset_map[16];                             */
/*  output sint16 Tpac_dyn_test_bed_rel_ref;                                  */
/*  output uint16 Tpac_dyn_test_bed_duration;                                 */
/*  output boolean Tpac_dyn_test_bed_type_ref;                                */
/*  output uint8 Tpac_dyn_test_bed_offset;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidCurrentIndex(void)
{
   boolean bLocalTstDynBedTypRef;
   uint8   u8LocalTstDynBedOffset;
   uint8   u8LocalTpacTestBedTableCounter;
   uint16  u8LocalTstDynBedDuration;
   sint16  s16LocalTstDynBedRelRef;


   /* 1_Current_index */
   u8LocalTpacTestBedTableCounter =
      (uint8)MATHSRV_udtMIN(Tpac_test_bed_table_counter, 15);
   s16LocalTstDynBedRelRef =
      Tpac_dyn_test_bed_rel_ref_map[u8LocalTpacTestBedTableCounter];
   u8LocalTstDynBedDuration =
      Tpac_dyn_test_bed_duration_map[u8LocalTpacTestBedTableCounter];
   bLocalTstDynBedTypRef =
      Tpac_dyn_test_bed_type_ref_map[u8LocalTpacTestBedTableCounter];
   u8LocalTstDynBedOffset =
      Tpac_dyn_test_bed_offset_map[u8LocalTpacTestBedTableCounter];

   Tpac_dyn_test_bed_rel_ref = (sint16)MATHSRV_udtCLAMP(s16LocalTstDynBedRelRef,
                                                        -1024,
                                                        1024);
   Tpac_dyn_test_bed_duration =
      (uint16)MATHSRV_udtMIN(u8LocalTstDynBedDuration, 409);

   Tpac_dyn_test_bed_type_ref = bLocalTstDynBedTypRef;
   Tpac_dyn_test_bed_offset = (uint8)MATHSRV_udtMIN(u8LocalTstDynBedOffset, 2);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidNextIndex                                   */
/* !Description :  Determiner l'index suivant                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Tpac_test_bed_table_counter;                                  */
/*  input uint8 Tpac_test_bed_next_table_counter;                             */
/*  input sint16 Tpac_dyn_test_bed_rel_ref_map[16];                           */
/*  input uint8 Tpac_dyn_test_bed_offset_map[16];                             */
/*  output uint8 Tpac_test_bed_next_table_counter;                            */
/*  output sint16 Tpac_dyn_test_bed_next_rel_ref;                             */
/*  output uint8 Tpac_dyn_test_bed_next_offset;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidNextIndex(void)
{
   uint8  u8LocalTstDynBedOffset;
   uint8  u8LocalCounter;
   uint16 u16LocalCounter;
   sint16 s16LocalTstDynBedRelRef;


   /* Next_index */
   u16LocalCounter = (uint16)(Tpac_test_bed_table_counter + 1);
   Tpac_test_bed_next_table_counter =
      (uint8)MATHSRV_udtMIN(u16LocalCounter, 16);
   u8LocalCounter = (uint8)MATHSRV_udtMIN(Tpac_test_bed_next_table_counter, 15);

   s16LocalTstDynBedRelRef =
      Tpac_dyn_test_bed_rel_ref_map[u8LocalCounter];

   u8LocalTstDynBedOffset =
      Tpac_dyn_test_bed_offset_map[u8LocalCounter];

   Tpac_dyn_test_bed_next_rel_ref =
      (sint16)MATHSRV_udtCLAMP(s16LocalTstDynBedRelRef, -1024, 1024);

   Tpac_dyn_test_bed_next_offset =
      (uint8)MATHSRV_udtMIN(u8LocalTstDynBedOffset, 2);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidComputeAbsRefIncr                           */
/* !Description :  Ce sous-système calcule les valeurs de consigne par rapport*/
/*                 à la butée basse de l’index de plage courant et suivant.   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidComputeAbsolutRef();                      */
/*  extf argret void THRBENCHAUT_vidComputeIncrement();                       */
/*  input boolean Tpac_dyn_test_bed_type_ref;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidComputeAbsRefIncr(void)
{
   /* Compute_abs_ref_incr */
   THRBENCHAUT_vidComputeAbsolutRef();
   if (Tpac_dyn_test_bed_type_ref != 0)
   {
      THRBENCHAUT_vidComputeIncrement();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidComputeAbsolutRef                           */
/* !Description :  Ce sous-système calcule la valeur de la consigne ramenée   */
/*                 par rapport à la butée basse. Un offset est ajoutée à la   */
/*                 valeur de consigne relative.                               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input uint16 Ssm_open_throttle_pos;                                       */
/*  input uint8 Tpac_dyn_test_bed_next_offset;                                */
/*  input sint16 Tpac_dyn_test_bed_next_rel_ref;                              */
/*  input uint16 Ssm_limp_home_throttle_pos;                                  */
/*  input uint8 Tpac_dyn_test_bed_offset;                                     */
/*  input sint16 Tpac_dyn_test_bed_rel_ref;                                   */
/*  input uint16 Tpac_dyn_test_bed_abs_ref;                                   */
/*  output uint16 Tpac_dyn_test_bed_next_abs_ref;                             */
/*  output uint16 Tpac_dyn_test_bed_abs_ref;                                  */
/*  output uint16 THRBENCHAUT_u16DtcThrPosTestBed1;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidComputeAbsolutRef(void)
{
   uint16 u16LocalSsm_clos_thr_pos;
   uint16 u16LocalSsm_limp_thr_pos;
   uint16 u16LocalSsm_open_thr_pos;
   sint32 s32LocalCLAMP;
   sint32 s32LocalCompThrPos;
   sint32 s32LocalTpac_next_rel_ref;


   /* Compute_absolute_reference */
   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_clos_thr_pos);
   VEMS_vidGET(Ssm_open_throttle_pos, u16LocalSsm_open_thr_pos);
   s32LocalCompThrPos = (sint32)u16LocalSsm_open_thr_pos
                      - (sint32)u16LocalSsm_clos_thr_pos;

   if (Tpac_dyn_test_bed_next_offset == 0)
   {
      Tpac_dyn_test_bed_next_abs_ref =
         (uint16)MATHSRV_udtMAX(Tpac_dyn_test_bed_next_rel_ref, 0);
   }
   else
   {
      if (Tpac_dyn_test_bed_next_offset == 1)
      {
         VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_thr_pos);
         s32LocalTpac_next_rel_ref = Tpac_dyn_test_bed_next_rel_ref
                                   + u16LocalSsm_limp_thr_pos;
         Tpac_dyn_test_bed_next_abs_ref =
            (uint16)MATHSRV_udtCLAMP(s32LocalTpac_next_rel_ref, 0, 1024);
      }
      else
      {
         s32LocalTpac_next_rel_ref = (sint32)Tpac_dyn_test_bed_next_rel_ref
                                   + s32LocalCompThrPos;
         Tpac_dyn_test_bed_next_abs_ref =
               (uint16)MATHSRV_udtCLAMP(s32LocalTpac_next_rel_ref,
                                        0,
                                        1024);
      }
   }

   if (Tpac_dyn_test_bed_offset == 0)
   {
      Tpac_dyn_test_bed_abs_ref =
         (uint16)MATHSRV_udtCLAMP(Tpac_dyn_test_bed_rel_ref, 0, 1024);
   }
   else
   {
      if (Tpac_dyn_test_bed_offset == 1)
      {
         VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_thr_pos);
         s32LocalCLAMP = Tpac_dyn_test_bed_rel_ref + u16LocalSsm_limp_thr_pos;
         Tpac_dyn_test_bed_abs_ref =
            (uint16)MATHSRV_udtCLAMP(s32LocalCLAMP, 0, 1024);
      }
      else
      {
         s32LocalCLAMP = (sint32)Tpac_dyn_test_bed_rel_ref + s32LocalCompThrPos;
         Tpac_dyn_test_bed_abs_ref =
               (uint16)MATHSRV_udtCLAMP(s32LocalCLAMP, 0, 1024);
      }
   }
   s32LocalCompThrPos = MATHSRV_udtMAX(s32LocalCompThrPos, 0);
   THRBENCHAUT_u16DtcThrPosTestBed1 =
      (uint16)MATHSRV_udtMIN(Tpac_dyn_test_bed_abs_ref, s32LocalCompThrPos);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHAUT_vidComputeIncrement                            */
/* !Description :  Calcul de l'incrément                                      */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Tpac_dyn_test_bed_duration;                                  */
/*  input uint16 Tpac_dyn_test_bed_next_abs_ref;                              */
/*  input uint16 Tpac_dyn_test_bed_abs_ref;                                   */
/*  input uint16 TEST_BED_SAMP_PERIOD;                                        */
/*  output sint32 Tpac_dyn_test_bed_increment;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHAUT_vidComputeIncrement(void)
{
   uint16 u16Localdiff;
   uint32 u32LocalComp;
   uint32 u32LocalMod;
   sint32 s32LocalCompThrPos;


   /* Compute_increment */
   if (Tpac_dyn_test_bed_duration > 0)
   {
      if (Tpac_dyn_test_bed_next_abs_ref >= Tpac_dyn_test_bed_abs_ref)
      {
         u16Localdiff = (uint16)( Tpac_dyn_test_bed_next_abs_ref
                                - Tpac_dyn_test_bed_abs_ref);
      }
      else
      {
         u16Localdiff = (uint16)( Tpac_dyn_test_bed_abs_ref
                                - Tpac_dyn_test_bed_next_abs_ref);
      }
      u32LocalComp = (uint32)( (u16Localdiff * TEST_BED_SAMP_PERIOD)
                             / Tpac_dyn_test_bed_duration);
      if (u32LocalComp < 64)
      {
         u32LocalMod = (uint32)( ( ( (u16Localdiff * TEST_BED_SAMP_PERIOD)
                                   % Tpac_dyn_test_bed_duration)
                                 * 2097152)
                               / Tpac_dyn_test_bed_duration);
         s32LocalCompThrPos = (sint32)( (u32LocalComp * 2097152)
                                      + u32LocalMod);
      }
      else
      {
         s32LocalCompThrPos = 134217728;
      }
      if (Tpac_dyn_test_bed_next_abs_ref < Tpac_dyn_test_bed_abs_ref)
      {
         s32LocalCompThrPos = (-1)* s32LocalCompThrPos;
      }
      Tpac_dyn_test_bed_increment = s32LocalCompThrPos;
   }
   else
   {
      if (Tpac_dyn_test_bed_next_abs_ref < Tpac_dyn_test_bed_abs_ref)
      {
         Tpac_dyn_test_bed_increment = -134217728;
      }
      else
      {
         Tpac_dyn_test_bed_increment = 134217728;
      }
   }
}
/*------------------------------- end of file --------------------------------*/