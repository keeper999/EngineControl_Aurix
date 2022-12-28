/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLCTRL                                                 */
/* !Description     : IDLCTRL Component                                       */
/*                                                                            */
/* !Module          : IDLCTRL                                                 */
/* !Description     : Régulateur de régime ralenti                            */
/*                                                                            */
/* !File            : IDLCTRL_FCT1.c                                          */
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
/*   1 / IDLCTRL_vidInitOutput                                                */
/*   2 / IDLCTRL_vidIdleSpeedControl                                          */
/*   3 / IDLCTRL_vidCalc_regulateur_av                                        */
/*   4 / IDLCTRL_vidConditionner_erreur                                       */
/*   5 / IDLCTRL_vidParametrer_PID                                            */
/*   6 / IDLCTRL_vidParametrer_mode_1                                         */
/*   7 / IDLCTRL_vidParametrer_mode_2                                         */
/*   8 / IDLCTRL_vidParametrer_mode_3                                         */
/*   9 / IDLCTRL_vidParametrer_mode_4                                         */
/*   10 / IDLCTRL_vidCalculer_couple_init                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5659858 / 01                                        */
/* !Reference   : PTS_DOC_5700651 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_1336 / 2.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLCTRL/IDLCTRL_F$*/
/* $Revision::   1.16                                                        $*/
/* $Author::   mbenfrad                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLCTRL.h"
#include "IDLCTRL_L.h"
#include "IDLCTRL_IM.h"
#include "IDLCTRL_MACRO.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidInitOutput                                      */
/* !Description :  Cette fonction initialise les variables du module          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IdlSys_noGear;                                                */
/*  input boolean IdlSys_bAcvBrk;                                             */
/*  input sint16 IdlSys_nErrIdlCtl;                                           */
/*  input uint16 IdlSys_nErrIdlCorLim_A[8];                                   */
/*  input uint16 IdlSys_tqIdlCorMaxNorm_M[4][8];                              */
/*  input uint16 IdlSys_tqIdlCorMaxBrk_M[4][8];                               */
/*  output sint16 IdlSys_tqIdcAirIdl;                                         */
/*  output sint16 IdlSys_tqIdcIdl;                                            */
/*  output sint16 IdlSys_tqIdcIdlNotSat;                                      */
/*  output sint16 IdlSys_tqIdcIdlRaw;                                         */
/*  output sint16 IdlSys_nErrIdlCtl;                                          */
/*  output sint16 IdlSys_nErrIdlCtlPID;                                       */
/*  output uint16 IDLCTRL_u16TabSample[12];                                   */
/*  output boolean IDLCTRL_bRstCalc;                                          */
/*  output uint16 IDLCTRL_u16RatLimOutput;                                    */
/*  output sint16 IDLCTRL_s16EngErrIdlCtlPrev;                                */
/*  output sint16 IdlSys_nErrIdlCtl1;                                         */
/*  output sint32 IdlSys_tqIdlCor;                                            */
/*  output sint32 IDLCTRL_s32TqIdlCor;                                        */
/*  output sint16 IdlSys_tqIdlCorDerFil_MP;                                   */
/*  output sint16 IdlSys_tqIdcAirIdlRaw;                                      */
/*  output sint32 IDLCTRL_s32TqIdcAirIdlRawFiltMem;                           */
/*  output uint16 IdlSys_facDerIdlCtl;                                        */
/*  output uint16 IdlSys_facFilIdlCtl;                                        */
/*  output uint16 IdlSys_facIntIdlCtl;                                        */
/*  output uint16 IdlSys_facPropIdlCtl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidInitOutput(void)
{
   boolean  bLocalIIdlSys_bAcvBrk;
   uint8    u8LocalIdlSys_noGear;
   uint8    u8Localindex;
   uint16   u16LocalParaColumn;
   uint16   u16LocalParaLine;
   uint16   u16LocalIdlSys_nErrIdlCtl;
   uint16   u16LocalRatLimOutput;


   /*module Outputs initialization*/
   VEMS_vidSET(IdlSys_tqIdcAirIdl, 0);
   VEMS_vidSET(IdlSys_tqIdcIdl, 0);
   VEMS_vidSET(IdlSys_tqIdcIdlNotSat , 0);

   /*CSMT_CGMT08_1336_V2_0*/
   IdlSys_tqIdcIdlRaw = 0;

   /*F01_01_Conditionner_erreur*/
   IdlSys_nErrIdlCtl = 0;
   IdlSys_nErrIdlCtlPID = 0;
   for ( u8Localindex = 0;
         u8Localindex < IDLCTRL_u8MAX_SAMPLE_NB;
         u8Localindex++)
   {
      IDLCTRL_u16TabSample[u8Localindex] = 0;
   }
   IDLCTRL_bRstCalc = 0;
   /*F01_04_Borner_correction*/
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(IdlSys_bAcvBrk, bLocalIIdlSys_bAcvBrk);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   u16LocalIdlSys_nErrIdlCtl = (uint16)((IdlSys_nErrIdlCtl / 4) + 8000);
   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlCorLim_A,
                                                     u16LocalIdlSys_nErrIdlCtl,
                                                     8);

   if (bLocalIIdlSys_bAcvBrk == 0)
   {
      u16LocalRatLimOutput =
         MATHSRV_u16Interp2d(&IdlSys_tqIdlCorMaxNorm_M[0][0],
                             u16LocalParaLine,
                             u16LocalParaColumn,
                             8);
   }
   else
   {
      u16LocalRatLimOutput =
         MATHSRV_u16Interp2d(&IdlSys_tqIdlCorMaxBrk_M[0][0],
                             u16LocalParaLine,
                             u16LocalParaColumn,
                             8);
   }

   IDLCTRL_u16RatLimOutput =
      (uint16)MATHSRV_udtMIN(u16LocalRatLimOutput, 16000);

   /*F01_05_Calculer_correction_PID*/
   IDLCTRL_s16EngErrIdlCtlPrev = 0;
   IdlSys_nErrIdlCtl1 = 0;
   IdlSys_tqIdlCor = 0;
   IDLCTRL_s32TqIdlCor = 0;

   /*F01_05_01_Calculer_termes_regulateur*/
   IdlSys_tqIdlCorDerFil_MP = 0;

   /*F02_Calculer_regulateur_air*/
   IdlSys_tqIdcAirIdlRaw = 0;
   IDLCTRL_s32TqIdcAirIdlRawFiltMem = 0;
   IdlSys_facDerIdlCtl = 0;
   IdlSys_facFilIdlCtl = 0;
   IdlSys_facIntIdlCtl = 0;
   IdlSys_facPropIdlCtl = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidIdleSpeedControl                                */
/* !Description :  La fonction « Régulation du Régime de Ralenti » se         */
/*                 décompose en 3 sous fonctions appelées à la récurrence     */
/*                 synchro : calcul de la correction , filtrage différentiel  */
/*                 de la correction  et synthèse des consignes de couple      */
/*                 avance et air .                                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IDLCTRL_vidCalc_regulateur_av();                         */
/*  extf argret void IDLCTRL_vidCalc_regulateur_air();                        */
/*  extf argret void IDLCTRL_vidCoord_couples_ralenti();                      */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input boolean TqSys_bTypFu;                                               */
/*  input sint16 IdlSys_nErrIdlCtlPID;                                        */
/*  output sint16 IDLCTRL_s16EngErrIdlCtlPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidIdleSpeedControl(void)
{
   boolean bLocalIdlSys_bEnaIdl;
   boolean bLocalTqSys_bTypFu;


   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
   VEMS_vidGET(TqSys_bTypFu, bLocalTqSys_bTypFu);

   if ( bLocalIdlSys_bEnaIdl != 0)
   {
      /*F01_Calculer_regulateur_avance*/
      IDLCTRL_vidCalc_regulateur_av();

      if (bLocalTqSys_bTypFu != 0)
      {
         /*F02_Calculer_regulateur_air*/
         IDLCTRL_vidCalc_regulateur_air();
      }
   }

   /*F03_Coordonner_couples_ralenti*/
   IDLCTRL_vidCoord_couples_ralenti();

   /*Updating previous values (F01_05_Calculer_correction_PID)*/
   IDLCTRL_s16EngErrIdlCtlPrev =
      (sint16)MATHSRV_udtCLAMP(IdlSys_nErrIdlCtlPID, -32000, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCalc_regulateur_av                              */
/* !Description :  Fonction de calcul de la correction demandée par le        */
/*                 régulateur avance.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCTRL_vidConditionner_erreur();                        */
/*  extf argret void IDLCTRL_vidParametrer_PID();                             */
/*  extf argret void IDLCTRL_vidCalculer_couple_init();                       */
/*  extf argret void IDLCTRL_vidBorner_correction();                          */
/*  extf argret void IDLCTRL_vidCalc_correction_PID();                        */
/*  extf argret void IDLCTRL_vidAppliquer_SBPA();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCalc_regulateur_av(void)
{
   /*F01_01_Conditionner_erreur*/
   IDLCTRL_vidConditionner_erreur();

   /*F01_02_Parametrer_PID*/
   IDLCTRL_vidParametrer_PID();

   /*F01_03_Calculer_couple_initialisation*/
   IDLCTRL_vidCalculer_couple_init();

   /*F01_04_Borner_correction*/
   IDLCTRL_vidBorner_correction();

   /*F01_05_Calculer_correction_PID*/
   IDLCTRL_vidCalc_correction_PID();

   /*F01_06_Appliquer_SBPA*/
   IDLCTRL_vidAppliquer_SBPA();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidConditionner_erreur                             */
/* !Description :  Cette fonction  calcule  l’erreur  de  position  à         */
/*                 destination  du  régulateur :  différence entre  la        */
/*                 consigne dynamique de régime et le régime moteur mesuré.   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 IdlSys_nTarIdlDyn;                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint16 IdlSys_nErrIdl_A[8];                                         */
/*  input uint16 IDLCTRL_u16nErrIdlAir;                                       */
/*  input uint16 IdlSys_nErrIdlPID_M[4][8];                                   */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input uint16 IDLCTRL_u16TabSample[12];                                    */
/*  input uint8 IDLCTRL_u8Ind;                                                */
/*  input uint8 IdlSys_noAvgNErr_C;                                           */
/*  input boolean IDLCTRL_bRstCalc;                                           */
/*  input boolean IdlSys_bSelNErrFac_C;                                       */
/*  output uint16 IDLCTRL_u16nErrIdlAir;                                      */
/*  output sint16 IdlSys_nErrIdlCtlPID;                                       */
/*  output sint16 IdlSys_nErrIdlCtl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidConditionner_erreur(void)
{
   boolean bLocalIdlSys_bIniIdlCtl;
   uint8   u8LocalIdlSys_noGear;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalIdlSys_nTarIdlDyn;
   uint16  u16LocalParaLine;
   uint16  u16LocalParaColumn;
   uint16  u16LocalInterp;
   sint32  s32LocalIdlSys_nErrIdlCtlPID;
   sint32  s32LocalMoyenne;
   uint32  u32LocalMoyenne;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(IdlSys_nTarIdlDyn, u16LocalIdlSys_nTarIdlDyn);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   s32LocalIdlSys_nErrIdlCtlPID =
      (sint32)((u16LocalIdlSys_nTarIdlDyn - u16LocalExt_nEngClc0) + 32000);
   IDLCTRL_u16nErrIdlAir =
      (uint16)MATHSRV_udtCLAMP(s32LocalIdlSys_nErrIdlCtlPID,0 ,64000);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);
   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdl_A,
                                                     IDLCTRL_u16nErrIdlAir,
                                                     8);
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_nErrIdlPID_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);

   s32LocalIdlSys_nErrIdlCtlPID = (sint32)(u16LocalInterp - 32000);
   IdlSys_nErrIdlCtlPID =
      (sint16)MATHSRV_udtMIN(s32LocalIdlSys_nErrIdlCtlPID, 32000);
   /*calcul Moyenne glissante*/
   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);
   LIBPSA_u16SlidAverFilt(u16LocalInterp,
                          u16LocalInterp,
                          bLocalIdlSys_bIniIdlCtl,
                          IDLCTRL_u16TabSample,
                          IDLCTRL_U16TABSAMPLE_COLS,
                          &IDLCTRL_u8Ind,
                          IdlSys_noAvgNErr_C,
                          &IDLCTRL_bRstCalc,
                          &u32LocalMoyenne);

   s32LocalMoyenne = (sint32)(u32LocalMoyenne - 32000);
   if (IdlSys_bSelNErrFac_C != 0)
   {
      IdlSys_nErrIdlCtl =
         (sint16)MATHSRV_udtMIN(s32LocalMoyenne, 32000);
   }
   else
   {
      IdlSys_nErrIdlCtl =
         (sint16)MATHSRV_udtMIN(s32LocalIdlSys_nErrIdlCtlPID, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidParametrer_PID                                  */
/* !Description :  Les coefficients proportionnel (KP), intégral (KI), dérivée*/
/*                 (KD) et dérivée filtrée (KF) du régulateur air sont        */
/*                 interpolés dans des cartographies indexées selon le rapport*/
/*                 de boite engagé et la valeur de la correction avance en    */
/*                 entrée du régulateur.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IDLCTRL_vidParametrer_mode_1();                          */
/*  extf argret void IDLCTRL_vidParametrer_mode_2();                          */
/*  extf argret void IDLCTRL_vidParametrer_mode_3();                          */
/*  extf argret void IDLCTRL_vidParametrer_mode_4();                          */
/*  input uint8 IdlSys_idxIdlCtlMod;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidParametrer_PID(void)
{
   uint8 u8LocalIdlSys_idxIdlCtlMod;


   VEMS_vidGET(IdlSys_idxIdlCtlMod, u8LocalIdlSys_idxIdlCtlMod);

   switch(u8LocalIdlSys_idxIdlCtlMod)
   {
      case 1:
         /*F01_02_01_Parametrer_mode_1*/
         IDLCTRL_vidParametrer_mode_1();
         break;

      case 2:
         /*F01_02_02_Parametrer_mode_2*/
         IDLCTRL_vidParametrer_mode_2();
         break;

      case 3:
         /*F01_02_03_Parametrer_mode_3*/
         IDLCTRL_vidParametrer_mode_3();
         break;

      case 4:
         /*F01_02_04_Parametrer_mode_4*/
         IDLCTRL_vidParametrer_mode_4();
         break;

      default:
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidParametrer_mode_1                               */
/* !Description :  Calcul des gains du régulateur avance pour le mode 1.      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_nErrIdlCtl;                                           */
/*  input uint16 IdlSys_nErrIdlPID_A[8];                                      */
/*  input uint16 IdlSys_facPropIdlCtl1_M[4][8];                               */
/*  input uint16 IdlSys_facIntIdlCtl1_M[4][8];                                */
/*  input uint16 IdlSys_facDerIdlCtl1_M[4][8];                                */
/*  input uint16 IdlSys_facFilIdlCtl1_M[4][8];                                */
/*  output uint16 IdlSys_facPropIdlCtl;                                       */
/*  output uint16 IdlSys_facIntIdlCtl;                                        */
/*  output uint16 IdlSys_facDerIdlCtl;                                        */
/*  output uint16 IdlSys_facFilIdlCtl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidParametrer_mode_1(void)
{
   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalParaColumn;
   uint16 u16LocalParaLine;
   uint16 u16LocalIdlSys_nErrIdlCtl;
   uint16 u16LocalInterp;
   sint16 s16LocalIdlSys_nErrIdlCtl;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   s16LocalIdlSys_nErrIdlCtl = (sint16)((IdlSys_nErrIdlCtl / 4) + 8000);
   u16LocalIdlSys_nErrIdlCtl =
      (uint16)MATHSRV_udtMAX(s16LocalIdlSys_nErrIdlCtl, 0);

   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlPID_A,
                                                     u16LocalIdlSys_nErrIdlCtl,
                                                     8);

   /*Production of IdlSys_facPropIdlCtl (Mode 1)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facPropIdlCtl1_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facPropIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facIntIdlCtl (Mode 1)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facIntIdlCtl1_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facIntIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facDerIdlCtl (Mode 1)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facDerIdlCtl1_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facDerIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facFilIdlCtl (Mode 1)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facFilIdlCtl1_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 7680);
   IdlSys_facFilIdlCtl = (uint16)(u16LocalInterp * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidParametrer_mode_2                               */
/* !Description :  Calcul des gains du régulateur avance pour le mode 2.      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_nErrIdlCtl;                                           */
/*  input uint16 IdlSys_nErrIdlPID_A[8];                                      */
/*  input uint16 IdlSys_facPropIdlCtl2_M[4][8];                               */
/*  input uint16 IdlSys_facIntIdlCtl2_M[4][8];                                */
/*  input uint16 IdlSys_facDerIdlCtl2_M[4][8];                                */
/*  input uint16 IdlSys_facFilIdlCtl2_M[4][8];                                */
/*  output uint16 IdlSys_facPropIdlCtl;                                       */
/*  output uint16 IdlSys_facIntIdlCtl;                                        */
/*  output uint16 IdlSys_facDerIdlCtl;                                        */
/*  output uint16 IdlSys_facFilIdlCtl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidParametrer_mode_2(void)
{
   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalParaColumn;
   uint16 u16LocalParaLine;
   uint16 u16LocalIdlSys_nErrIdlCtl;
   uint16 u16LocalInterp;
   sint16 s16LocalIdlSys_nErrIdlCtl;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   s16LocalIdlSys_nErrIdlCtl = (sint16)((IdlSys_nErrIdlCtl / 4) + 8000);
   u16LocalIdlSys_nErrIdlCtl =
      (uint16)MATHSRV_udtMAX(s16LocalIdlSys_nErrIdlCtl, 0);

   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlPID_A,
                                                     u16LocalIdlSys_nErrIdlCtl,
                                                     8);

   /*Production of IdlSys_facPropIdlCtl (Mode 2)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facPropIdlCtl2_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facPropIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facIntIdlCtl (Mode 2)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facIntIdlCtl2_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facIntIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facDerIdlCtl (Mode 2)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facDerIdlCtl2_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facDerIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facFilIdlCtl (Mode 2)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facFilIdlCtl2_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 7680);
   IdlSys_facFilIdlCtl = (uint16)(u16LocalInterp * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidParametrer_mode_3                               */
/* !Description :  Calcul des gains du régulateur avance pour le mode 3.      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_nErrIdlCtl;                                           */
/*  input uint16 IdlSys_nErrIdlPID_A[8];                                      */
/*  input uint16 IdlSys_facPropIdlCtl3_M[4][8];                               */
/*  input uint16 IdlSys_facIntIdlCtl3_M[4][8];                                */
/*  input uint16 IdlSys_facDerIdlCtl3_M[4][8];                                */
/*  input uint16 IdlSys_facFilIdlCtl3_M[4][8];                                */
/*  output uint16 IdlSys_facPropIdlCtl;                                       */
/*  output uint16 IdlSys_facIntIdlCtl;                                        */
/*  output uint16 IdlSys_facDerIdlCtl;                                        */
/*  output uint16 IdlSys_facFilIdlCtl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidParametrer_mode_3(void)
{

   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalParaColumn;
   uint16 u16LocalParaLine;
   uint16 u16LocalIdlSys_nErrIdlCtl;
   uint16 u16LocalInterp;
   sint16 s16LocalIdlSys_nErrIdlCtl;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   s16LocalIdlSys_nErrIdlCtl = (sint16)((IdlSys_nErrIdlCtl / 4) + 8000);
   u16LocalIdlSys_nErrIdlCtl =
      (uint16)MATHSRV_udtMAX(s16LocalIdlSys_nErrIdlCtl, 0);

   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlPID_A,
                                                     u16LocalIdlSys_nErrIdlCtl,
                                                     8);

   /*Production of IdlSys_facPropIdlCtl (Mode 3)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facPropIdlCtl3_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facPropIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facIntIdlCtl (Mode 3)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facIntIdlCtl3_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facIntIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facDerIdlCtl (Mode 3)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facDerIdlCtl3_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facDerIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facFilIdlCtl (Mode 3)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facFilIdlCtl3_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 7680);
   IdlSys_facFilIdlCtl = (uint16)(u16LocalInterp * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidParametrer_mode_4                               */
/* !Description :  Calcul des gains du régulateur avance pour le mode 4.      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_nErrIdlCtl;                                           */
/*  input uint16 IdlSys_nErrIdlPID_A[8];                                      */
/*  input uint16 IdlSys_facPropIdlCtl4_M[4][8];                               */
/*  input uint16 IdlSys_facIntIdlCtl4_M[4][8];                                */
/*  input uint16 IdlSys_facDerIdlCtl4_M[4][8];                                */
/*  input uint16 IdlSys_facFilIdlCtl4_M[4][8];                                */
/*  output uint16 IdlSys_facPropIdlCtl;                                       */
/*  output uint16 IdlSys_facIntIdlCtl;                                        */
/*  output uint16 IdlSys_facDerIdlCtl;                                        */
/*  output uint16 IdlSys_facFilIdlCtl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidParametrer_mode_4(void)
{

   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalParaColumn;
   uint16 u16LocalParaLine;
   uint16 u16LocalIdlSys_nErrIdlCtl;
   uint16 u16LocalInterp;
   sint16 s16LocalIdlSys_nErrIdlCtl;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   s16LocalIdlSys_nErrIdlCtl = (sint16)((IdlSys_nErrIdlCtl / 4) + 8000);
   u16LocalIdlSys_nErrIdlCtl =
      (uint16)MATHSRV_udtMAX(s16LocalIdlSys_nErrIdlCtl, 0);

   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlPID_A,
                                                     u16LocalIdlSys_nErrIdlCtl,
                                                     8);

   /*Production of IdlSys_facPropIdlCtl (Mode 4)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facPropIdlCtl4_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facPropIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facIntIdlCtl (Mode 4)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facIntIdlCtl4_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facIntIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facDerIdlCtl (Mode 4)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facDerIdlCtl4_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8192);
   IdlSys_facDerIdlCtl = (uint16)(u16LocalInterp * 4);

   /*Production of IdlSys_facFilIdlCtl (Mode 4)*/
   u16LocalInterp = MATHSRV_u16Interp2d(&IdlSys_facFilIdlCtl4_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 7680);
   IdlSys_facFilIdlCtl = (uint16)(u16LocalInterp * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCalculer_couple_init                            */
/* !Description :  Fonction qui calcule le couple d’initialisation de la      */
/*                 correction du régulateur de ralenti.                       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tqIdcIdlIni;                                          */
/*  input sint16 IdlSys_tqIdcIdlStab;                                         */
/*  output sint16 IdlSys_tqIdlCorIni;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCalculer_couple_init(void)
{
   sint16 s16LocalIdlSys_tqIdcIdlIni;
   sint16 s16LocalIdlSys_tqIdcIdlStab;
   sint32 s32LocalIdIdlSys_tqIdlCorIni;


   VEMS_vidGET(IdlSys_tqIdcIdlIni, s16LocalIdlSys_tqIdcIdlIni);
   VEMS_vidGET(IdlSys_tqIdcIdlStab, s16LocalIdlSys_tqIdcIdlStab);
   s32LocalIdIdlSys_tqIdlCorIni =
      (sint32)(s16LocalIdlSys_tqIdcIdlIni - s16LocalIdlSys_tqIdcIdlStab);
   IdlSys_tqIdlCorIni = (sint16)MATHSRV_udtCLAMP(s32LocalIdIdlSys_tqIdlCorIni,
                                                 -32000,
                                                 32000);
}

/*------------------------------ end of file ---------------------------------*/