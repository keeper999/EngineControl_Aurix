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
/* !File            : MISFSUCDETIDLE_FCT2.C                                   */
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
/*   1 / MISFSUCDETIDLE_vidMisfire2DetMf                                      */
/*   2 / MISFSUCDETIDLE_vidFilter2MfSuc                                       */
/*   3 / MISFSUCDETIDLE_vidAlgo2trustSuc                                      */
/*   4 / MISFSUCDETIDLE_vidDecisionMfSuc                                      */
/*   5 / MISFSUCDETIDLE_vidNotDetectMfSuc                                     */
/*   6 / MISFSUCDETIDLE_vidMisfSucDetNot                                      */
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
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidMisfire2DetMf                            */
/* !Description :  Ce bloc calcule :  -  La sortie de l’algorithme  -         */
/*                 L’indice de confiance correspondant                        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidFilter2MfSuc();                        */
/*  extf argret void MISFSUCDETIDLE_vidAlgo2trustSuc();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidMisfire2DetMf(void)
{
   MISFSUCDETIDLE_vidFilter2MfSuc();
   MISFSUCDETIDLE_vidAlgo2trustSuc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidFilter2MfSuc                             */
/* !Description :  Ce bloc calcule :  -  La sortie de l’algorithme            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Mf_idle_crite_uavn0;                                         */
/*  input sint16 Mf_idle_crite_next_uavn0;                                    */
/*  input sint16 Mf_idle_crite_prev_prev_uavn0;                               */
/*  output sint16 MisfDet_critAlgoIdleOut2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidFilter2MfSuc(void)
{
   sint16 s16LocalMf_idle_crite_uavn0;
   sint16 s16LocalMf_idle_crite_next_uavn0;
   sint16 s16LocalMf_idle_crite_prev_prev;
   sint32 s32LocalMisfDetCritAlgoIdleOut2;


   VEMS_vidGET(Mf_idle_crite_uavn0, s16LocalMf_idle_crite_uavn0);
   VEMS_vidGET(Mf_idle_crite_next_uavn0, s16LocalMf_idle_crite_next_uavn0);
   VEMS_vidGET(Mf_idle_crite_prev_prev_uavn0, s16LocalMf_idle_crite_prev_prev);

   s32LocalMisfDetCritAlgoIdleOut2 =
      (sint32)( (2 * s16LocalMf_idle_crite_uavn0)
              - s16LocalMf_idle_crite_next_uavn0
              - s16LocalMf_idle_crite_prev_prev);
   MisfDet_critAlgoIdleOut2 =
      (sint16)MATHSRV_udtCLAMP(s32LocalMisfDetCritAlgoIdleOut2,
                               -32768,
                               32767);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidAlgo2trustSuc                            */
/* !Description :   Ce bloc calcule : -  L’indice de confiance correspondant  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_idle_algo_thresh_2_uavn0;                                 */
/*  input sint16 MisfDet_critAlgoIdleOut2;                                    */
/*  output sint16 Mf_idle2_algo_trust_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidAlgo2trustSuc(void)
{
   sint32 s32LocalMf_idle2_trustuavn0;


   if (Mf_idle_algo_thresh_2_uavn0 == 0)
   {
      s32LocalMf_idle2_trustuavn0 = 0;
   }
   else
   {
      s32LocalMf_idle2_trustuavn0 = (sint32)( ( MisfDet_critAlgoIdleOut2
                                              * 8192)
                                            / Mf_idle_algo_thresh_2_uavn0);
   }
   Mf_idle2_algo_trust_uavn0 =
      (sint16)MATHSRV_udtCLAMP(s32LocalMf_idle2_trustuavn0, -32768, 32767);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidDecisionMfSuc                            */
/* !Description :  e bloc vérifie 2 choses :   -  si le 1er misfire a         */
/*                 effectivement eu lieu  -  si le 2ème misfire a             */
/*                 effectivement eu lieu                                      */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Mf_misfire_idle_det_thresh_uacn0;                             */
/*  input sint16 Mf_idle1_algo_trust_uavn0;                                   */
/*  input sint16 Mf_idle2_algo_trust_uavn0;                                   */
/*  output boolean MisfDet_bMisfSucDetRaw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidDecisionMfSuc(void)
{
   uint16 u16LocalMf_misfire_det_thresh;


   u16LocalMf_misfire_det_thresh = (uint16)( Mf_misfire_idle_det_thresh_uacn0
                                           * 64);
   if (  (Mf_idle1_algo_trust_uavn0 > u16LocalMf_misfire_det_thresh)
      && (u16LocalMf_misfire_det_thresh < Mf_idle2_algo_trust_uavn0))
   {
      MisfDet_bMisfSucDetRaw = 1;
   }
   else
   {
      MisfDet_bMisfSucDetRaw = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidNotDetectMfSuc                           */
/* !Description :  Calcul de boolean de detection                             */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean MisfDet_bMisfSucDetRaw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidNotDetectMfSuc(void)
{
   MisfDet_bMisfSucDetRaw = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFSUCDETIDLE_vidMisfSucDetNot                            */
/* !Description :  Si les conditions d’activation de la détection ne sont pas */
/*                 atteintes (Mf_algo_cond_ok_uavb0 = 0) alors le booléen de  */
/*                 détection est mis à 0.                                     */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean MisfDet_bMisfSucDetRaw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFSUCDETIDLE_vidMisfSucDetNot(void)
{
   MisfDet_bMisfSucDetRaw = 0;
}
/*---------------------------- end of file -----------------------------------*/