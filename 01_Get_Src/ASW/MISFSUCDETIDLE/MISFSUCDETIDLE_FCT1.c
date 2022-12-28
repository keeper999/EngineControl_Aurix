/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFSUCDETIDLE                                          */
/* !Description     : MISFSUCDETIDLE component                                */
/*                                                                            */
/* !Module          : MISFSUCDETIDLE                                          */
/* !Description     : Algorithmes De Détection De 2 Misfires Successifs en    */
/*                    IDLE                                                    */
/*                                                                            */
/* !File            : MISFSUCDETIDLE_FCT1.C                                   */
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
/*   1 / MISFSUCDETIDLE_vidInitOutput                                         */
/*   2 / MISFSUCDETIDLE_vidIni                                                */
/*   3 / MISFSUCDETIDLE_vidMainMisfSucDet                                     */
/*   4 / MISFSUCDETIDLE_vidMisfSucDet                                         */
/*   5 / MISFSUCDETIDLE_vidAutoDetMfSuc                                       */
/*   6 / MISFSUCDETIDLE_vidDetectionMfSuc                                     */
/*   7 / MISFSUCDETIDLE_vidAlgoMfSuc                                          */
/*   8 / MISFSUCDETIDLE_vidMisfire1DetMf                                      */
/*   9 / MISFSUCDETIDLE_vidFilter1MfSuc                                       */
/*   10 / MISFSUCDETIDLE_vidAlgo1trustSuc                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5198644 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065828                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFSUCDETIDLE.h"
#include "MISFSUCDETIDLE_L.h"
#include "MISFSUCDETIDLE_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidInitOutput                               */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;                            */
/*  output uint8 MISFSUCDETIDLE_u8MfIdlesingPrev2;                            */
/*  output boolean MISFSUCDETIDLE_bMisfSucRawPrev1;                           */
/*  output boolean MISFSUCDETIDLE_bMisfSucRawPrev2;                           */
/*  output boolean MISFSUCDETIDLE_bCondSucEnaPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidInitOutput(void)
{
   MISFSUCDETIDLE_u8MfIdlesingPrev1 = 0;
   MISFSUCDETIDLE_u8MfIdlesingPrev2 = 0;
   MISFSUCDETIDLE_bMisfSucRawPrev1 = 0;
   MISFSUCDETIDLE_bMisfSucRawPrev2 = 0;
   MISFSUCDETIDLE_bCondSucEnaPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidIni                                      */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_2_misfire_idle_detected_uavb0;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidIni(void)
{
   VEMS_vidSET(Mf_2_misfire_idle_detected_uavb0, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidMainMisfSucDet                           */
/* !Description :  En fonction de la calibration MisfDet_noDelaySyncSuc_C il  */
/*                 est possible de détecter 2 misfire successif avec un délai */
/*                 souhaité par rapport à MisfDet_bMisfSucDetRaw.             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDETIDLE_vidMisfSucDet();                          */
/*  extf argret void MISFSUCDETIDLE_vidMisfSucDetNot();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Mf_algo_idle_cond_ok;                                       */
/*  input uint8 MisfDet_noDelaySyncSuc_C;                                     */
/*  input boolean MisfDet_bMisfSucDetRaw;                                     */
/*  input boolean MISFSUCDETIDLE_bMisfSucRawPrev1;                            */
/*  input boolean MISFSUCDETIDLE_bMisfSucRawPrev2;                            */
/*  input uint8 Mf_Idle_det_single_output_uavb0;                              */
/*  input uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;                             */
/*  output boolean Mf_2_misfire_idle_detected_uavb0;                          */
/*  output boolean MisfDet_bMisfSucDetRaw;                                    */
/*  output boolean MISFSUCDETIDLE_bMisfSucRawPrev1;                           */
/*  output boolean MISFSUCDETIDLE_bMisfSucRawPrev2;                           */
/*  output uint8 MISFSUCDETIDLE_u8MfIdlesingPrev2;                            */
/*  output uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidMainMisfSucDet(void)
{
   boolean bLocalMf_algo_idle_cond_ok;
   uint8   u8LocalMfIdledetsingleoutuavb0;


   VEMS_vidGET(Mf_algo_idle_cond_ok, bLocalMf_algo_idle_cond_ok);
   if (bLocalMf_algo_idle_cond_ok != 0)
   {
      MISFSUCDETIDLE_vidMisfSucDet();
   }
   else
   {
      MISFSUCDETIDLE_vidMisfSucDetNot();
   }

   switch (MisfDet_noDelaySyncSuc_C)
   {
      case 0:
         VEMS_vidSET(Mf_2_misfire_idle_detected_uavb0, MisfDet_bMisfSucDetRaw);
         break;

      case 1:
         VEMS_vidSET(Mf_2_misfire_idle_detected_uavb0,
                     MISFSUCDETIDLE_bMisfSucRawPrev1);
         break;

      case 2:
         VEMS_vidSET(Mf_2_misfire_idle_detected_uavb0,
                     MISFSUCDETIDLE_bMisfSucRawPrev2);
         break;

      default:
         VEMS_vidSET(Mf_2_misfire_idle_detected_uavb0, MisfDet_bMisfSucDetRaw);
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
   MISFSUCDETIDLE_bMisfSucRawPrev2 = MISFSUCDETIDLE_bMisfSucRawPrev1;
   MISFSUCDETIDLE_bMisfSucRawPrev1 = MisfDet_bMisfSucDetRaw;
   VEMS_vidGET(Mf_Idle_det_single_output_uavb0, u8LocalMfIdledetsingleoutuavb0);
   MISFSUCDETIDLE_u8MfIdlesingPrev2 = MISFSUCDETIDLE_u8MfIdlesingPrev1;
   MISFSUCDETIDLE_u8MfIdlesingPrev1 = u8LocalMfIdledetsingleoutuavb0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidMisfSucDet                               */
/* !Description :  Ce bloc est constitué de 3 modules dont les fonctions sont */
/*                 respectivement:  -  L’activation de la stratégie de        */
/*                 détection dédiée à 2 misfires successifs (en IDLE) car     */
/*                 celle-ci n’est pas tout le temps active, elle le sera      */
/*                 uniquement s’il y a doute.                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidAutoDetMfSuc();                        */
/*  extf argret void MISFSUCDETIDLE_vidDetectionMfSuc();                      */
/*  extf argret void MISFSUCDETIDLE_vidNotDetectMfSuc();                      */
/*  input boolean MisfDet_bMisfSucDetEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidMisfSucDet(void)
{

   MISFSUCDETIDLE_vidAutoDetMfSuc();
   if (MisfDet_bMisfSucDetEna != 0)
   {
      MISFSUCDETIDLE_vidDetectionMfSuc();
   }
   else
   {
      MISFSUCDETIDLE_vidNotDetectMfSuc();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidAutoDetMfSuc                             */
/* !Description :  Ce bloc permet d’activer la stratégie de détection de 2    */
/*                 misfires successifs (en IDLE) dès lors que la sortie unique*/
/*                 (en IDLE) est supérieure à un seuil calibrable.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_Idle_det_single_output_uavb0;                              */
/*  input uint8 MisfDet_noDelaySyncDetSingle_C;                               */
/*  input uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;                             */
/*  input uint8 MISFSUCDETIDLE_u8MfIdlesingPrev2;                             */
/*  input uint8 Mf_Idl_det_single_out_prev_uavb0;                             */
/*  input uint8 Mf_2_misfire_idle_det_uacn0;                                  */
/*  input boolean MISFSUCDETIDLE_bCondSucEnaPrev;                             */
/*  output uint8 Mf_Idl_det_single_out_prev_uavb0;                            */
/*  output boolean MisfDet_bMisfSucDetEna;                                    */
/*  output boolean MISFSUCDETIDLE_bCondSucEnaPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidAutoDetMfSuc(void)
{
   uint8 u8LocalMfIdledetsingleoutuavb0;


   VEMS_vidGET(Mf_Idle_det_single_output_uavb0, u8LocalMfIdledetsingleoutuavb0);
   switch(MisfDet_noDelaySyncDetSingle_C)
   {
      case 0:
         Mf_Idl_det_single_out_prev_uavb0 =  u8LocalMfIdledetsingleoutuavb0;
         break;

      case 1:
         Mf_Idl_det_single_out_prev_uavb0 =  MISFSUCDETIDLE_u8MfIdlesingPrev1;
         break;

      case 2:
         Mf_Idl_det_single_out_prev_uavb0 =  MISFSUCDETIDLE_u8MfIdlesingPrev2;
         break;

      default:
         Mf_Idl_det_single_out_prev_uavb0 =  u8LocalMfIdledetsingleoutuavb0;
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
   if (Mf_Idl_det_single_out_prev_uavb0 > Mf_2_misfire_idle_det_uacn0)
   {
      if (MISFSUCDETIDLE_bCondSucEnaPrev != 0)
      {
         MisfDet_bMisfSucDetEna = 1;
      }
      else
      {
         MisfDet_bMisfSucDetEna = 0;
      }
      MISFSUCDETIDLE_bCondSucEnaPrev = 1;
   }
   else
   {
      MisfDet_bMisfSucDetEna = 0;
      MISFSUCDETIDLE_bCondSucEnaPrev = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidDetectionMfSuc                           */
/* !Description :  Ce bloc est composé 2 deux sous-systèmes :  -  Le calcul   */
/*                 des nouveaux algorithmes permettant la détection des 2     */
/*                 misfires (en IDLE)  -  La décision permettant de dire si 2 */
/*                 misfires successifs se sont produits ou non (en IDLE).     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidAlgoMfSuc();                           */
/*  extf argret void MISFSUCDETIDLE_vidDecisionMfSuc();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidDetectionMfSuc(void)
{
   MISFSUCDETIDLE_vidAlgoMfSuc();
   MISFSUCDETIDLE_vidDecisionMfSuc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidAlgoMfSuc                                */
/* !Description :  Ce bloc se décompose en 2 sous-blocs :  -  Calcul de       */
/*                 l’indice de confiance appliqué au « 1er misfire » scruté  -*/
/*                  Calcul de l’indice de confiance appliqué au « 2ème misfire*/
/*                 » scruté                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFSUCDETIDLE_vidMisfire1DetMf();                       */
/*  extf argret void MISFSUCDETIDLE_vidMisfire2DetMf();                       */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint16 MisfDet_tqEngCurIdle_X[7];                                   */
/*  input uint16 MisfDet_nEngCurIdle_Y[7];                                    */
/*  input uint16 Mf_idle_algo_thresh_2_map_uacn2[7][7];                       */
/*  output uint16 Mf_idle_algo_thresh_2_uavn0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidAlgoMfSuc(void)
{
   uint16 u16LocalExt_nEng;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalEngLimTqIdcEng;
   sint16 s16LocalEngLim_tqIdcEngCur;
   sint32 s32LocalEngLim_tqIdcEngCur;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);

   s32LocalEngLim_tqIdcEngCur = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalEngLimTqIdcEng = (uint16)MATHSRV_udtMAX(s32LocalEngLim_tqIdcEngCur,
                                                   0);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(MisfDet_tqEngCurIdle_X,
                                                    u16LocalEngLimTqIdcEng,
                                                    7);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(MisfDet_nEngCurIdle_Y,
                                                    u16LocalExt_nEng,
                                                    7);
   Mf_idle_algo_thresh_2_uavn0 =
      MATHSRV_u16Interp2d(&Mf_idle_algo_thresh_2_map_uacn2[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          7);
   MISFSUCDETIDLE_vidMisfire1DetMf();
   MISFSUCDETIDLE_vidMisfire2DetMf();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidMisfire1DetMf                            */
/* !Description :  Ce bloc calcule :  -  La sortie de l’algorithme  -         */
/*                 L’indice de confiance correspondant                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidFilter1MfSuc();                        */
/*  extf argret void MISFSUCDETIDLE_vidAlgo1trustSuc();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidMisfire1DetMf(void)
{
   MISFSUCDETIDLE_vidFilter1MfSuc();
   MISFSUCDETIDLE_vidAlgo1trustSuc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidFilter1MfSuc                             */
/* !Description :  Ce bloc calcule :  -  La sortie de l’algorithme            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Mf_idle_crite_prev_uavn0;                                    */
/*  input sint16 Mf_idle_crite_next_uavn0;                                    */
/*  input sint16 Mf_idle_crite_prev_prev_uavn0;                               */
/*  output sint16 MisfDet_critAlgoIdleOut1;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidFilter1MfSuc(void)
{
   sint16 s16LocalMf_idle_crite_prev_uavn0;
   sint16 s16LocalMf_idle_crite_next_uavn0;
   sint16 s16LocalMf_idle_crite_prev_prev;
   sint32 s32LocalMisfDetCritAlgoIdleOut1;


   VEMS_vidGET(Mf_idle_crite_prev_uavn0, s16LocalMf_idle_crite_prev_uavn0);
   VEMS_vidGET(Mf_idle_crite_next_uavn0, s16LocalMf_idle_crite_next_uavn0);
   VEMS_vidGET(Mf_idle_crite_prev_prev_uavn0, s16LocalMf_idle_crite_prev_prev);
   s32LocalMisfDetCritAlgoIdleOut1 =
      (sint32)( (2 * s16LocalMf_idle_crite_prev_uavn0)
              - s16LocalMf_idle_crite_next_uavn0
              - s16LocalMf_idle_crite_prev_prev);
   MisfDet_critAlgoIdleOut1 =
      (sint16)MATHSRV_udtCLAMP(s32LocalMisfDetCritAlgoIdleOut1,
                               -32768,
                               32767);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidAlgo1trustSuc                            */
/* !Description :  Ce bloc calcule : -  L’indice de confiance correspondant   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_idle_algo_thresh_2_uavn0;                                 */
/*  input sint16 MisfDet_critAlgoIdleOut1;                                    */
/*  output sint16 Mf_idle1_algo_trust_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidAlgo1trustSuc(void)
{
   sint32 s32LocalMf_idle1_trustuavn0;


   if (Mf_idle_algo_thresh_2_uavn0 == 0)
   {
      s32LocalMf_idle1_trustuavn0 = 0;
   }
   else
   {
      s32LocalMf_idle1_trustuavn0 = (sint32)( ( MisfDet_critAlgoIdleOut1
                                              * 8192)
                                            / Mf_idle_algo_thresh_2_uavn0);
   }
   Mf_idle1_algo_trust_uavn0 =
      (sint16)MATHSRV_udtCLAMP(s32LocalMf_idle1_trustuavn0, -32768, 32767);
}
/*---------------------------- end of file -----------------------------------*/