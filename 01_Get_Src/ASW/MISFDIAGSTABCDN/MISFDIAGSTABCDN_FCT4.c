/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDIAGSTABCDN                                         */
/* !Description     : MISFDIAGSTABCDN component.                              */
/*                                                                            */
/* !Module          : MISFDIAGSTABCDN                                         */
/* !Description     : Conditions de stabilité pour diagnostic misfire         */
/*                                                                            */
/* !File            : MISFDIAGSTABCDN_FCT4.C                                  */
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
/*   1 / MISFDIAGSTABCDN_vidIgnAdvStable                                      */
/*   2 / MISFDIAGSTABCDN_vidStabSet                                           */
/*   3 / MISFDIAGSTABCDN_vidStabChkDly                                        */
/*   4 / MISFDIAGSTABCDN_vidMisfStbCdLost                                     */
/*   5 / MISFDIAGSTABCDN_vidMisIgAdvStNul                                     */
/*   6 / MISFDIAGSTABCDN_vidChkLdStabFilt                                     */
/*   7 / MISFDIAGSTABCDN_vidChkLdStab                                         */
/*   8 / MISFDIAGSTABCDN_vidChkLdAlNrmStb                                     */
/*   9 / MISFDIAGSTABCDN_vidChkLdAlIdlStb                                     */
/*   10 / MISFDIAGSTABCDN_vidChkLdNotStb                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5577717 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066973                                         */
/* !OtherRefs   : VEMS V02 ECU#068484                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDIAGSTABCDN/MISFDIAGSTABC$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   15 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   15 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEMS.h"
#include "MISFDIAGSTABCDN.h"
#include "MISFDIAGSTABCDN_L.h"
#include "MISFDIAGSTABCDN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidIgnAdvStable                            */
/* !Description :  La stabilité ne peut être retrouvée que lorsque le saut    */
/*                 d’avance devient inférieur à Misf_agIgAdvStabLim_C et      */
/*                 qu’après qu’une durée calibrable ne soit écoulée.          */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidStabSet();                            */
/*  extf argret void MISFDIAGSTABCDN_vidStabChkDly();                         */
/*  input uint16 Misf_ctIgAdvStab;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidIgnAdvStable(void)
{
   if (Misf_ctIgAdvStab == 0)
   {
      MISFDIAGSTABCDN_vidStabSet();
   }
   else
   {
      MISFDIAGSTABCDN_vidStabChkDly();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidStabSet                                 */
/* !Description :  Lorsque le compteur Misf_ctIgAdvStab s’annule, la stabilité*/
/*                 du système est confirmée                                   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_stability_conditions;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidStabSet(void)
{
   VEMS_vidSET(Mf_stability_conditions, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidStabChkDly                              */
/* !Description :  Lorsque le saut d’avance est au dessous du seuil, le       */
/*                 compteur Misf_ctIgAdvStab est décrémenté à chaque fin      */
/*                 d’acquisition de la fenêtre Misfire                        */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Misf_ctIgAdvStab;                                            */
/*  output uint16 Misf_ctIgAdvStab;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidStabChkDly(void)
{
   if (Misf_ctIgAdvStab > 0)
   {
      Misf_ctIgAdvStab = (uint16)(Misf_ctIgAdvStab - 1);
   }
   else
   {
      Misf_ctIgAdvStab = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidMisfStbCdLost                           */
/* !Description :  Lorsque les conditions de stabilité en couple indiqué,     */
/*                 rapport de boîte et couple prélevé sont perdues, la        */
/*                 vérification de la condition de stabilité par rapport aux  */
/*                 sauts d’avances n’est plus calculée                        */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDIAGSTABCDN_vidMisIgAdvStNul();                      */
/*  input boolean Misf_bEngStabCdn;                                           */
/*  input boolean MISFDIAGSTABCDN_bMisfEngCdnPrev;                            */
/*  output boolean MISFDIAGSTABCDN_bMisfEngCdnPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidMisfStbCdLost(void)
{
   if (  (Misf_bEngStabCdn == 0)
      && (MISFDIAGSTABCDN_bMisfEngCdnPrev != 0))
   {
      MISFDIAGSTABCDN_vidMisIgAdvStNul();
   }
   MISFDIAGSTABCDN_bMisfEngCdnPrev = Misf_bEngStabCdn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidMisIgAdvStNul                           */
/* !Description :  Lorsque les conditions de stabilité en couple indiqué,     */
/*                 rapport de boîte et couple prélevé sont perdues, la        */
/*                 vérification de la condition de stabilité par rapport aux  */
/*                 sauts d’avances n’est plus calculée                        */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Mf_stability_conditions;                                   */
/*  output uint16 Misf_ctIgAdvStab;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidMisIgAdvStNul(void)
{
   VEMS_vidSET(Mf_stability_conditions, 0);
   Misf_ctIgAdvStab = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLdStabFilt                           */
/* !Description :  La stratégie de détection de stabilité en couple se compose*/
/*                 : 01_Mf_check_load_stability : active quand un rapport est */
/*                 engagé, 02_Mf_check_load_stability_noGear : active quand   */
/*                 aucun rapport est engagé.                                  */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDIAGSTABCDN_vidChkLdAlNrmStb();                      */
/*  extf argret void MISFDIAGSTABCDN_vidChkLdAlIdlStb();                      */
/*  extf argret void MISFDIAGSTABCDN_vidChkLdNotStb();                        */
/*  input boolean Mf_bAcvCondNormRaw;                                         */
/*  input boolean Mf_bAcvCondIdleRaw;                                         */
/*  input boolean MISFDIAGSTABCDN_bAcvCdNrmRawPrev;                           */
/*  input boolean MISFDIAGSTABCDN_bAcvCdIdlRawPrev;                           */
/*  output boolean Misf_bRstFilTq;                                            */
/*  output boolean Misf_bRstFilTqIdle;                                        */
/*  output boolean MISFDIAGSTABCDN_bAcvCdNrmRawPrev;                          */
/*  output boolean MISFDIAGSTABCDN_bAcvCdIdlRawPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLdStabFilt(void)
{
   boolean bLocalMf_bAcvCondNormRaw;
   boolean bLocalMf_bAcvCondIdleRaw;


   VEMS_vidGET(Mf_bAcvCondNormRaw, bLocalMf_bAcvCondNormRaw);
   VEMS_vidGET(Mf_bAcvCondIdleRaw, bLocalMf_bAcvCondIdleRaw);

   if (  (bLocalMf_bAcvCondNormRaw != 0)
      && (MISFDIAGSTABCDN_bAcvCdNrmRawPrev == 0))
   {
      Misf_bRstFilTq = 1;
   }
   else
   {
      Misf_bRstFilTq = 0;
   }

   if (  (bLocalMf_bAcvCondIdleRaw != 0)
      && (MISFDIAGSTABCDN_bAcvCdIdlRawPrev == 0))
   {
      Misf_bRstFilTqIdle = 1;
   }
   else
   {
      Misf_bRstFilTqIdle = 0;
   }

   if (bLocalMf_bAcvCondNormRaw != 0)
   {
      MISFDIAGSTABCDN_vidChkLdAlNrmStb();
   }
   else
   {
      if (bLocalMf_bAcvCondIdleRaw != 0)
      {
         MISFDIAGSTABCDN_vidChkLdAlIdlStb();
      }
      else
      {
         MISFDIAGSTABCDN_vidChkLdNotStb();
      }
   }
   MISFDIAGSTABCDN_bAcvCdNrmRawPrev = bLocalMf_bAcvCondNormRaw;
   MISFDIAGSTABCDN_bAcvCdIdlRawPrev = bLocalMf_bAcvCondIdleRaw;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLdStab                               */
/* !Description :  Le critère de stablité est basé sur la variation crête à   */
/*                 crête du couple indiqué depuis la dernière                 */
/*                 initialisation.Un seuil a été ajouté pour pouvoir          */
/*                 différencier le cas où l’on est au point mort et le cas ou */
/*                 l’on a un rapport engagé.                                  */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDIAGSTABCDN_vidLoadNotStable();                      */
/*  extf argret void MISFDIAGSTABCDN_vidLoadStable();                         */
/*  input boolean Mf_bAcvCondNormRaw;                                         */
/*  input boolean Mf_bAcvCondIdleRaw;                                         */
/*  input uint8 Gear_engaged;                                                 */
/*  input sint16 Indicated_torque_mf_max;                                     */
/*  input sint16 Indicated_torque_mf_min;                                     */
/*  input sint16 Mf_neut_indic_tor_stab_limit;                                */
/*  input sint16 Mf_indicated_tor_stability_limit;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLdStab(void)
{
   boolean bLocalMf_bAcvCondNormRaw;
   boolean bLocalMf_bAcvCondIdleRaw;
   uint8   u8LocalGear_engaged;
   sint16  s16LocalLimit;
   sint32  s32LocalCalc1;

   VEMS_vidGET(Mf_bAcvCondNormRaw, bLocalMf_bAcvCondNormRaw);
   VEMS_vidGET(Mf_bAcvCondIdleRaw, bLocalMf_bAcvCondIdleRaw);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   s32LocalCalc1 = (sint32)(Indicated_torque_mf_max - Indicated_torque_mf_min);

   if (  (  (u8LocalGear_engaged == 0)
         && (bLocalMf_bAcvCondNormRaw != 0))
      || (bLocalMf_bAcvCondIdleRaw != 0))
   {
      s16LocalLimit = Mf_neut_indic_tor_stab_limit;
   }
   else
   {
      s16LocalLimit = Mf_indicated_tor_stability_limit;
   }
   if (s32LocalCalc1 > s16LocalLimit)
   {
      MISFDIAGSTABCDN_vidLoadNotStable();
   }
   else
   {
      MISFDIAGSTABCDN_vidLoadStable();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLdAlNrmStb                           */
/* !Description :  Fonction de détection de stabilité en couple quand un      */
/*                 rapport est engagé active quand les conditions d’activation*/
/*                 de l’algo Normal sont réunies.                             */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input boolean MISFDIAGSTABCDN_bfirstiteration;                            */
/*  input sint16 MISFDIAGSTABCDN_s16OutFilterStab;                            */
/*  input boolean Misf_bRstFilTq;                                             */
/*  input uint16 Misf_FilTqGain_C;                                            */
/*  input sint32 MISFDIAGSTABCDN_s32FiltStabMem;                              */
/*  input uint32 Misf_tqDifFilTq;                                             */
/*  input uint16 Misf_tqAccrFilTqThd_C;                                       */
/*  input uint16 Misf_tqDeceFilTqThd_C;                                       */
/*  input boolean Misf_bDetAccr;                                              */
/*  input uint8 Misf_tDlyStabAccrTq_C;                                        */
/*  input uint8 Misf_tDlyStabDeceTq_C;                                        */
/*  input uint8 Misf_ctStabTq;                                                */
/*  output sint16 MISFDIAGSTABCDN_s16OutFilterStab;                           */
/*  output sint32 MISFDIAGSTABCDN_s32FiltStabMem;                             */
/*  output boolean MISFDIAGSTABCDN_bfirstiteration;                           */
/*  output uint32 Misf_tqDifFilTq;                                            */
/*  output boolean Misf_bDetAccr;                                             */
/*  output uint8 Misf_ctStabTq;                                               */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLdAlNrmStb(void)
{
   sint16    s16LocalEngLim_tqIdcEngCur;
   sint16    s16LocalFilterPrev;
   sint16    s16LocalOutFilterStab;
   sint32    s32LocalDiff;
   uint32    u32LocalMisf_tqAccrFilTqThd_C;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   if (MISFDIAGSTABCDN_bfirstiteration == 0)
   {
      MISFDIAGSTABCDN_s16OutFilterStab =
         (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur, -32000, 32000);
      MISFDIAGSTABCDN_s32FiltStabMem =
         (sint32)(MISFDIAGSTABCDN_s16OutFilterStab * 256);
      MISFDIAGSTABCDN_bfirstiteration = 1;
      s16LocalFilterPrev = MISFDIAGSTABCDN_s16OutFilterStab;
   }
   else
   {
      s16LocalFilterPrev =
         (sint16)MATHSRV_udtCLAMP(MISFDIAGSTABCDN_s16OutFilterStab,
                                 -32000,
                                 32000);
      if (Misf_bRstFilTq != 0)
      {
         MISFDIAGSTABCDN_s16OutFilterStab =
            (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur,
                                    -32000,
                                    32000);
         MISFDIAGSTABCDN_s32FiltStabMem =
            (sint32)(MISFDIAGSTABCDN_s16OutFilterStab * 256);
      }
      else
      {
         if (Misf_FilTqGain_C >= 256)
         {
            MISFDIAGSTABCDN_s16OutFilterStab =
               (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur,
                                       -32000,
                                       32000);
            MISFDIAGSTABCDN_s32FiltStabMem =
               (sint32)(MISFDIAGSTABCDN_s16OutFilterStab * 256);
         }
         else
         {
            s16LocalOutFilterStab =
               MATHSRV_s16FirstOrderFilterGu8((uint8)Misf_FilTqGain_C,
                                              &MISFDIAGSTABCDN_s32FiltStabMem,
                                              s16LocalEngLim_tqIdcEngCur);
            MISFDIAGSTABCDN_s16OutFilterStab =
               (sint16)MATHSRV_udtCLAMP(s16LocalOutFilterStab, -32000, 32000);
         }
      }
   }
   if (Misf_bRstFilTq != 0)
   {
      Misf_tqDifFilTq = 64000;
   }
   else
   {
      s32LocalDiff =
         (sint32)( ( MISFDIAGSTABCDN_s16OutFilterStab
                    - s16LocalFilterPrev)
                 + 64000);
      Misf_tqDifFilTq = (uint32)MATHSRV_udtMAX(s32LocalDiff, 0);
   }

   if (Misf_tqDifFilTq >= 64000)
   {
      Misf_bDetAccr = 1;
   }
   else
   {
      Misf_bDetAccr = 0;
   }
   u32LocalMisf_tqAccrFilTqThd_C = (uint32)(Misf_tqAccrFilTqThd_C + 64000);
   if (  (Misf_tqDifFilTq > u32LocalMisf_tqAccrFilTqThd_C)
      || (Misf_tqDifFilTq < Misf_tqDeceFilTqThd_C)
      || (Misf_bRstFilTq != 0))
   {
      if (Misf_bDetAccr != 0)
      {
         Misf_ctStabTq = Misf_tDlyStabAccrTq_C;
      }
      else
      {
         Misf_ctStabTq = Misf_tDlyStabDeceTq_C;
      }
   }
   else
   {
      if (Misf_ctStabTq > 0)
      {
         Misf_ctStabTq = (uint8)(Misf_ctStabTq - 1);
      }
   }
   if (Misf_ctStabTq > 0)
   {
      Indicated_torque_mf_not_stable = 1;
   }
   else
   {
      Indicated_torque_mf_not_stable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLdAlIdlStb                           */
/* !Description :  Fonction de détection de stabilité en couple quand aucun   */
/*                 rapport n’est engagé qui s'active quand les conditions     */
/*                 d’activation de l’algo Idle sont réunies                   */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input boolean MISFDIAGSTABCDN_bfirstiteration1;                           */
/*  input sint16 MISFDIAGSTABCDN_s16OutFilterNoGr;                            */
/*  input boolean Misf_bRstFilTqIdle;                                         */
/*  input uint16 Misf_NeutFilTqGain_C;                                        */
/*  input sint32 MISFDIAGSTABCDN_s32FiltNoGrMem;                              */
/*  input uint16 Misf_tqNeutDifFilTq;                                         */
/*  input uint16 Misf_tqNeutFilTqThd_C;                                       */
/*  input uint8 Misf_tDlyNoGearStabTq_C;                                      */
/*  input uint8 Misf_ctNeutStabTq;                                            */
/*  output sint16 MISFDIAGSTABCDN_s16OutFilterNoGr;                           */
/*  output sint32 MISFDIAGSTABCDN_s32FiltNoGrMem;                             */
/*  output boolean MISFDIAGSTABCDN_bfirstiteration1;                          */
/*  output uint16 Misf_tqNeutDifFilTq;                                        */
/*  output uint8 Misf_ctNeutStabTq;                                           */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLdAlIdlStb(void)
{
   sint16    s16LocalOutFilterNoGr;
   sint16    s16LocalEngLim_tqIdcEngCur;
   sint16    s16LocalFilterPrev;
   sint32    s32LocalDiff;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   if (MISFDIAGSTABCDN_bfirstiteration1 == 0)
   {
      MISFDIAGSTABCDN_s16OutFilterNoGr =
         (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur, -32000, 32000);
      MISFDIAGSTABCDN_s32FiltNoGrMem =
         (sint32)(MISFDIAGSTABCDN_s16OutFilterNoGr * 256);
      MISFDIAGSTABCDN_bfirstiteration1 = 1;
      s16LocalFilterPrev = MISFDIAGSTABCDN_s16OutFilterNoGr;

   }
   else
   {

      s16LocalFilterPrev =
         (sint16)MATHSRV_udtCLAMP(MISFDIAGSTABCDN_s16OutFilterNoGr,
                                 -32000,
                                 32000);
      if (Misf_bRstFilTqIdle != 0)
      {
         MISFDIAGSTABCDN_s16OutFilterNoGr =
            (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur, -32000, 32000);
         MISFDIAGSTABCDN_s32FiltNoGrMem =
            (sint32)(MISFDIAGSTABCDN_s16OutFilterNoGr * 256);
      }
      else
      {
         if (Misf_NeutFilTqGain_C >= 256)
         {
            MISFDIAGSTABCDN_s16OutFilterNoGr =
               (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcEngCur,
                                       -32000,
                                       32000);
            MISFDIAGSTABCDN_s32FiltNoGrMem =
               (sint32)(MISFDIAGSTABCDN_s16OutFilterNoGr * 256);
         }
         else
         {
            s16LocalOutFilterNoGr =
               MATHSRV_s16FirstOrderFilterGu8((uint8)Misf_NeutFilTqGain_C,
                                             &MISFDIAGSTABCDN_s32FiltNoGrMem,
                                             s16LocalEngLim_tqIdcEngCur);
            MISFDIAGSTABCDN_s16OutFilterNoGr =
               (sint16)MATHSRV_udtCLAMP(s16LocalOutFilterNoGr, -32000, 32000);
         }
      }
   }

   if (Misf_bRstFilTqIdle != 0)
   {
      Misf_tqNeutDifFilTq = 0;
   }
   else
   {
      s32LocalDiff = (sint32)( MISFDIAGSTABCDN_s16OutFilterNoGr
                             - s16LocalFilterPrev);
      Misf_tqNeutDifFilTq = (uint16)MATHSRV_udtABS(s32LocalDiff);
   }

   if (  (Misf_tqNeutDifFilTq > Misf_tqNeutFilTqThd_C)
      || (Misf_bRstFilTqIdle != 0))
   {
      Misf_ctNeutStabTq = Misf_tDlyNoGearStabTq_C;
   }
   else
   {
      if (Misf_ctNeutStabTq > 0)
      {
         Misf_ctNeutStabTq = (uint8)(Misf_ctNeutStabTq - 1);
      }
   }
   if (Misf_ctNeutStabTq > 25)
   {
      Indicated_torque_mf_not_stable = 1;
   }
   else
   {
      Indicated_torque_mf_not_stable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDIAGSTABCDN_vidChkLdNotStb                             */
/* !Description :  Focntion de diagnostique qui s'active quand les conditions */
/*                 de détection Misf sont pas réunies                         */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Indicated_torque_mf_not_stable;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDIAGSTABCDN_vidChkLdNotStb(void)
{
   Indicated_torque_mf_not_stable = 1;
}

/*------------------------------- end of file --------------------------------*/