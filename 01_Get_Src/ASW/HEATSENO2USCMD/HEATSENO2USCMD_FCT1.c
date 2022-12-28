/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2USCMD                                          */
/* !Description     : HEATSENO2USCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2USCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AMONT             */
/*                                                                            */
/* !File            : HEATSENO2USCMD_FCT1.c                                   */
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
/*   1 / HEATSENO2USCMD_vidInitOutput                                         */
/*   2 / HEATSENO2USCMD_vidLsUsHeatRaw                                        */
/*   3 / HEATSENO2USCMD_vidSlopHeat                                           */
/*   4 / HEATSENO2USCMD_vidLsUsHeatMan                                        */
/*   5 / HEATSENO2USCMD_vidLsUsHeatCor                                        */
/*   6 / HEATSENO2USCMD_vidLsUsHeatDiag                                       */
/*   7 / HEATSENO2USCMD_vidLsUsHeatReq                                        */
/*   8 / HEATSENO2USCMD_vidLsUsHeatCmd                                        */
/*   9 / HEATSENO2USCMD_vidCalcPwmPeriod                                      */
/*   10 / HEATSENO2USCMD_vidCalculTimeOn                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 04308 / 07                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2USCMD/HEATSEN$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "HEATSENO2USCMD.H"
#include "HEATSENO2USCMD_l.h"
#include "HEATSENO2USCMD_IM.h"
#include "VEMS.h"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidInitOutput                               */
/* !Description :  fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrReq;                                */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrMan;                                */
/*  output boolean Chauffage_sonde_o2_amont;                                  */
/*  output boolean Chauf_o2_amont_demande_on;                                 */
/*  output boolean HeatSenO2_bMonRunUsHeatCmd;                                */
/*  output uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;                            */
/*  output uint8 Lshd_lbup_diag_cmd_counter;                                  */
/*  output uint16 Lshd_upstr_period_counter;                                  */
/*  output uint8 HEATSENO2USCMD_u8DiagCmdCntPrev;                             */
/*  output uint16 HEATSENO2USCMD_u16RcoPeriodPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidInitOutput(void)
{
   VEMS_vidSET(LsSys_rLsUsMainOxCHeatPwrReq, 0);
   VEMS_vidSET(LsSys_rLsUsMainOxCHeatPwrMan, 0);
   VEMS_vidSET(Chauffage_sonde_o2_amont, 0);
   VEMS_vidSET(Chauf_o2_amont_demande_on, 0);
   VEMS_vidSET(HeatSenO2_bMonRunUsHeatCmd, 1);
   HEATSENO2USCMD_u8MainOxCHeatPrev = LSUSMAINOXCHEAT_PHASE_A;
   Lshd_lbup_diag_cmd_counter = 0;
   Lshd_upstr_period_counter = 0;

   /* internal variables are set to 1 in order to activate the timer blocks */
   HEATSENO2USCMD_u8DiagCmdCntPrev = 1;
   HEATSENO2USCMD_u16RcoPeriodPrev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatRaw                              */
/* !Description :  Ce module calcule la puissance de chauffage de la sonde O2,*/
/*                 qui doit être adaptée en fonction des phases de vie du     */
/*                 véhicule.                                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2USCMD_vidSlopHeat();                            */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;                             */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input uint8 LsSys_tCoLsUsMainOxCHeatPhaC1_T[6];                           */
/*  input uint8 LsSys_rLsUsMainOxCHeatPhaseC1_M[6];                           */
/*  input uint8 LsSys_tCoLsUsMainOxCHeatPhaC2_T[6];                           */
/*  input uint8 LsSys_rLsUsMainOxCHeatPhaseC2_M[6];                           */
/*  input uint16 ExM_mfEgTot;                                                 */
/*  input uint16 LsSys_mfEgTotUsHeatPwrMod_T[8];                              */
/*  input uint16 LsSys_mfEgTotUsHeatPhaseD_T[8];                              */
/*  input uint16 LsSys_mfEgTotUsHeatPhaseC1_T[8];                             */
/*  input uint16 LsSys_mfEgTotUsHeatPhaseC2_T[8];                             */
/*  input uint16 ExM_tExLsUsMainOxCEstim;                                     */
/*  input uint16 LsSys_tExEstimUsHeatPwrMod_T[8];                             */
/*  input uint16 LsSys_tExEstimUsHeatPhaseD_T[8];                             */
/*  input uint16 LsSys_tExEstimUsHeatPhaseC1_T[8];                            */
/*  input uint16 LsSys_tExEstimUsHeatPhaseC2_T[8];                            */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrMod_M[8][8];                         */
/*  input uint8 LsSys_facLsUsMainOxCHeatPhaseD_M[8][8];                       */
/*  input uint8 LsSys_facLsUsOxCHeatPhaseC1_M[8][8];                          */
/*  input uint8 LsSys_facLsUsOxCHeatPhaseC2_M[8][8];                          */
/*  input uint8 LsSys_rLsUsMainOxCHeatPhaseB_C;                               */
/*  input uint8 LsSys_rLsUsMainOxCHeatPhaseD_C;                               */
/*  input uint8 LsSys_rLsUsMainOxCHeatPhaseF_C;                               */
/*  input sint16 LsSys_UsNegSlopHeat;                                         */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrRaw;                                 */
/*  input uint8 LsSys_UsPosSlopHeat;                                          */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrRaw;                                */
/*  output uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatRaw(void)
{
   /* 01_LsUsHeatRaw */
   uint8  u8LocalLsSys_UsNegSlopHeat;
   uint8  u8LocalOutMap1;
   uint8  u8LocalOutMap2;
   uint8  u8LocalOutMap3;
   uint8  u8LocalOutMap4;
   uint8  u8LocalLsSys_stLsUsMainOxCHeat;
   uint8  u8LocalSiteInterpolation;
   uint8  u8LocalInterpC1;
   uint8  u8LocalInterpC2;
   uint16 u16LocalParaX1;
   uint16 u16LocalParaX2;
   uint16 u16LocalParaX3;
   uint16 u16LocalParaX4;
   uint16 u16LocalParaY1;
   uint16 u16LocalParaY2;
   uint16 u16LocalParaY3;
   uint16 u16LocalParaY4;
   uint16 u16LocalExM_mfEgTot;
   uint16 u16LocalExM_tExLsUsMainOxCEstim;
   uint16 u16LocalParaC1;
   uint16 u16LocalParaC2;
   uint16 u16LocalRateLimterInput;
   uint16 u16LocalRateLimterOutput;
   sint16 s16LocalLsSys_UsNegSlopHeat;
   sint16 s16LocalLsSys_tCoLsHeat;
   sint32 s32LocalInput;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   if (u8LocalLsSys_stLsUsMainOxCHeat != HEATSENO2USCMD_u8MainOxCHeatPrev)
   {
      HEATSENO2USCMD_vidSlopHeat();
   }

   VEMS_vidGET(LsSys_tCoLsHeat, s16LocalLsSys_tCoLsHeat);
   s32LocalInput = (sint32)(s16LocalLsSys_tCoLsHeat + 40);
   u8LocalSiteInterpolation = (uint8)MATHSRV_udtCLAMP(s32LocalInput, 0, 254);

   u16LocalParaC1 = MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsUsMainOxCHeatPhaC1_T,
                                                u8LocalSiteInterpolation,
                                                6);
   u8LocalInterpC1 = MATHSRV_u8Interp1d(LsSys_rLsUsMainOxCHeatPhaseC1_M,
                                        u16LocalParaC1);

   u16LocalParaC2 = MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsUsMainOxCHeatPhaC2_T,
                                                u8LocalSiteInterpolation,
                                                6);
   u8LocalInterpC2 = MATHSRV_u8Interp1d(LsSys_rLsUsMainOxCHeatPhaseC2_M,
                                        u16LocalParaC2);

   VEMS_vidGET(ExM_mfEgTot, u16LocalExM_mfEgTot);
   u16LocalExM_mfEgTot = (uint16)(((u16LocalExM_mfEgTot * 3125) + 2048) / 4096);
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotUsHeatPwrMod_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotUsHeatPhaseD_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX3 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotUsHeatPhaseC1_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX4 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotUsHeatPhaseC2_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);
   VEMS_vidGET(ExM_tExLsUsMainOxCEstim, u16LocalExM_tExLsUsMainOxCEstim);
   u16LocalExM_tExLsUsMainOxCEstim = (uint16)( u16LocalExM_tExLsUsMainOxCEstim
                                             / 32);
   u16LocalParaY1 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimUsHeatPwrMod_T,
                                                u16LocalExM_tExLsUsMainOxCEstim,
                                                8);

   u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimUsHeatPhaseD_T,
                                                u16LocalExM_tExLsUsMainOxCEstim,
                                                8);

   u16LocalParaY3 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimUsHeatPhaseC1_T,
                                                u16LocalExM_tExLsUsMainOxCEstim,
                                                8);

   u16LocalParaY4 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimUsHeatPhaseC2_T,
                                                u16LocalExM_tExLsUsMainOxCEstim,
                                                8);

   u8LocalOutMap1 = MATHSRV_u8Interp2d(&LsSys_rLsUsMainOxCHeatPwrMod_M[0][0],
                                       u16LocalParaX1,
                                       u16LocalParaY1,
                                       8);

   u8LocalOutMap2 = MATHSRV_u8Interp2d(&LsSys_facLsUsMainOxCHeatPhaseD_M[0][0],
                                       u16LocalParaX2,
                                       u16LocalParaY2,
                                       8);

   u8LocalOutMap3 = MATHSRV_u8Interp2d(&LsSys_facLsUsOxCHeatPhaseC1_M[0][0],
                                       u16LocalParaX3,
                                       u16LocalParaY3,
                                       8);
   u8LocalOutMap4 = MATHSRV_u8Interp2d(&LsSys_facLsUsOxCHeatPhaseC2_M[0][0],
                                       u16LocalParaX4,
                                       u16LocalParaY4,
                                       8);
   switch (u8LocalLsSys_stLsUsMainOxCHeat)
   {
      case LSUSMAINOXCHEAT_PHASE_A :
         u16LocalRateLimterInput = 0;
         break;

      case LSUSMAINOXCHEAT_PHASE_B :
         u16LocalRateLimterInput = LsSys_rLsUsMainOxCHeatPhaseB_C;
         break;

      case LSUSMAINOXCHEAT_PHASE_C1 :
         u16LocalRateLimterInput = (uint16)( ( u8LocalInterpC1
                                             * u8LocalOutMap3
                                             * 5)
                                           / 1000);
         break;

      case LSUSMAINOXCHEAT_PHASE_C2 :
         u16LocalRateLimterInput = (uint16)( ( u8LocalInterpC2
                                             * u8LocalOutMap4
                                             * 5)
                                           / 1000);
         break;

      case LSUSMAINOXCHEAT_PHASE_D :
         u16LocalRateLimterInput = (uint16)( ( LsSys_rLsUsMainOxCHeatPhaseD_C
                                             * u8LocalOutMap2
                                             * 5)
                                           / 1000);
         break;

      case LSUSMAINOXCHEAT_PHASE_E :
         u16LocalRateLimterInput = u8LocalOutMap1;
         break;

      case LSUSMAINOXCHEAT_PHASE_F :
         u16LocalRateLimterInput = LsSys_rLsUsMainOxCHeatPhaseF_C;
         break;

      case LSUSMAINOXCHEAT_PHASE_G :
         u16LocalRateLimterInput = 0;
         break;

      default:
         u16LocalRateLimterInput = 0;
         break;
   }
   s16LocalLsSys_UsNegSlopHeat = (sint16)((-1) * LsSys_UsNegSlopHeat);
   u8LocalLsSys_UsNegSlopHeat =
      (uint8)MATHSRV_udtCLAMP(s16LocalLsSys_UsNegSlopHeat, 0, 200);
   u16LocalRateLimterOutput =
      MATHSRV_u16SlewFilter((uint16)LsSys_rLsUsMainOxCHeatPwrRaw,
                            u16LocalRateLimterInput,
                            (uint16)LsSys_UsPosSlopHeat,
                            (uint16)u8LocalLsSys_UsNegSlopHeat);
   LsSys_rLsUsMainOxCHeatPwrRaw =
      (uint8)MATHSRV_udtMIN(u16LocalRateLimterOutput, 200);
   HEATSENO2USCMD_u8MainOxCHeatPrev = u8LocalLsSys_stLsUsMainOxCHeat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidSlopHeat                                 */
/* !Description :  Ce bloc met à jour les valeurs maximales de variation des  */
/*                 puissances de chauffe lors des changements de phase de     */
/*                 chauffage sonde amont                                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st71 LsSys_stLsUsMainOxCHeat;                                       */
/*  input sint16 LsSys_UsNegSlopHeatWku_C;                                    */
/*  input uint8 LsSys_UsPosSlopHeatWku_C;                                     */
/*  input uint8 LsSys_UsPosSlopHeatDewProt_C;                                 */
/*  input sint16 LsSys_UsNegSlopHeatDewProt_C;                                */
/*  input uint8 LsSys_UsPosSlopHeatHi_C;                                      */
/*  input uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;                             */
/*  input uint8 LsSys_UsPosSlopHeatNoHi_C;                                    */
/*  input uint8 LsSys_UsPosSlopHeatHot_C;                                     */
/*  input sint16 LsSys_UsNegSlopHeatHi_C;                                     */
/*  output uint8 LsSys_UsPosSlopHeat;                                         */
/*  output sint16 LsSys_UsNegSlopHeat;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidSlopHeat(void)
{
   /* 01_SlopHeat */
   uint8  u8LocalLsSysUsPosSlopHeat;
   uint8  u8LocalLsSys_stLsUsMainOxCHeat;
   sint16 s16LocalLsSysUsNegSlopHeat;


   VEMS_vidGET(LsSys_stLsUsMainOxCHeat, u8LocalLsSys_stLsUsMainOxCHeat);
   switch (u8LocalLsSys_stLsUsMainOxCHeat)
   {
      case LSUSMAINOXCHEAT_PHASE_A :
         u8LocalLsSysUsPosSlopHeat = 200;
         s16LocalLsSysUsNegSlopHeat = LsSys_UsNegSlopHeatWku_C;
         break;

      case LSUSMAINOXCHEAT_PHASE_B :
         u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatWku_C;
         s16LocalLsSysUsNegSlopHeat = -200;
         break;

      case LSUSMAINOXCHEAT_PHASE_C1 :
         u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatDewProt_C;
         s16LocalLsSysUsNegSlopHeat = -200;
         break;

      case LSUSMAINOXCHEAT_PHASE_C2 :
         u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatDewProt_C;
         s16LocalLsSysUsNegSlopHeat = LsSys_UsNegSlopHeatDewProt_C;
         break;

      case LSUSMAINOXCHEAT_PHASE_D :
         u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatHi_C;
         s16LocalLsSysUsNegSlopHeat = -200;
         break;

      case LSUSMAINOXCHEAT_PHASE_E :
         if (  (HEATSENO2USCMD_u8MainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_C1)
            || (HEATSENO2USCMD_u8MainOxCHeatPrev == LSUSMAINOXCHEAT_PHASE_C2) )
         {
            u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatNoHi_C;
         }
         else
         {
            u8LocalLsSysUsPosSlopHeat = LsSys_UsPosSlopHeatHot_C;
         }
         s16LocalLsSysUsNegSlopHeat = LsSys_UsNegSlopHeatHi_C;
         break;

      case LSUSMAINOXCHEAT_PHASE_F :
      case LSUSMAINOXCHEAT_PHASE_G :
         u8LocalLsSysUsPosSlopHeat = 200;
         s16LocalLsSysUsNegSlopHeat = -200;
         break;

      default:
         u8LocalLsSysUsPosSlopHeat = 0;
         s16LocalLsSysUsNegSlopHeat = 0;
         break;
   }
   LsSys_UsPosSlopHeat = (uint8)MATHSRV_udtMIN(u8LocalLsSysUsPosSlopHeat, 200);
   LsSys_UsNegSlopHeat = (sint16)MATHSRV_udtCLAMP(s16LocalLsSysUsNegSlopHeat,
                                                  -200,
                                                  0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatMan                              */
/* !Description :  Ce bloc prévoit l’utilisation d’un mode banc pour le signal*/
/*                 de commande du chauffage sonde amont.                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bUsHeatPwrManEna_C;                                   */
/*  input uint8 LsSys_rUsHeatPwrMan_C;                                        */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrRaw;                                 */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrMan;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatMan(void)
{
   uint8 u8LocalHeatPwrMan;


   if (LsSys_bUsHeatPwrManEna_C != 0)
   {
      u8LocalHeatPwrMan = LsSys_rUsHeatPwrMan_C;
   }
   else
   {
      u8LocalHeatPwrMan = LsSys_rLsUsMainOxCHeatPwrRaw;
   }
   u8LocalHeatPwrMan = (uint8)MATHSRV_udtMIN(u8LocalHeatPwrMan, 200);
   VEMS_vidSET(LsSys_rLsUsMainOxCHeatPwrMan, u8LocalHeatPwrMan);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatCor                              */
/* !Description :  Ce module permet de prendre en compte la tension batterie  */
/*                 dans le calcul de la puissance de chauffage de la sonde, en*/
/*                 corrigeant la valeur du signal RCO brut (une hausse du     */
/*                 signal traduisant une baisse de la tension batterie) :     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrMan;                                 */
/*  input uint8 LsSys_uBattUsHeatRef;                                         */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrCor;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatCor(void)
{
   boolean bLocalInhuBattCorLsHeat;
   uint8   u8LocalHeatPwrMan;
   sint16  s16LocalExt_uBattMes;
   uint32  u32LocalRcoCorrDen;
   uint32  u32LocalRcoCorrNum;
   uint32  u32LocalRcoCorr;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrMan, u8LocalHeatPwrMan);
   bLocalInhuBattCorLsHeat = GDGAR_bGetFRM(FRM_FRM_INHUBATTCORLSHEAT);
   if (  (s16LocalExt_uBattMes > 0)
      && (bLocalInhuBattCorLsHeat == 0) )
   {
      u32LocalRcoCorrNum =  (uint32)( LsSys_uBattUsHeatRef
                                    * LsSys_uBattUsHeatRef
                                    * u8LocalHeatPwrMan
                                    * 100);
      u32LocalRcoCorrDen = (uint32)( s16LocalExt_uBattMes
                                   * s16LocalExt_uBattMes);
      u32LocalRcoCorr = u32LocalRcoCorrNum / u32LocalRcoCorrDen;
   }
   else
   {
      u32LocalRcoCorr = u8LocalHeatPwrMan;
   }
   LsSys_rLsUsMainOxCHeatPwrCor = (uint8)MATHSRV_udtMIN(u32LocalRcoCorr, 200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatDiag                             */
/* !Description :  Afin de pouvoir diagnostiquer un éventuel court-circuit au */
/*                 niveau du driver de puissance du chauffage sonde, la       */
/*                 commande de chauffage est volontairement annulée de façon  */
/*                 périodique                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lshd_lbup_diag_cmd_per_uacn0;                                 */
/*  input uint8 HEATSENO2USCMD_u8DiagCmdCntPrev;                              */
/*  input uint8 Lshd_lbup_diag_cmd_counter;                                   */
/*  input boolean HeatSenO2_bMonRunUsHeatCmd;                                 */
/*  input boolean Lshd_lbup_heat_diag_ena_uacb0;                              */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrCor;                                 */
/*  output uint8 HEATSENO2USCMD_u8DiagCmdCntPrev;                             */
/*  output uint8 Lshd_lbup_diag_cmd_counter;                                  */
/*  output boolean HeatSenO2_bMonRunUsHeatCmd;                                */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrDiag;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatDiag(void)
{
   boolean bLocalHeatSenO2_bMonRunUsHeatCmd;
   uint8   u8LocalDuration;


   if (Lshd_lbup_diag_cmd_per_uacn0 > 0)
   {
      u8LocalDuration = (uint8)(Lshd_lbup_diag_cmd_per_uacn0 - 1);
   }
   else
   {
      u8LocalDuration = 0;
   }
   if (   (HEATSENO2USCMD_u8DiagCmdCntPrev != 0)
       && (Lshd_lbup_diag_cmd_counter == 0) )
   {
      HEATSENO2USCMD_u8DiagCmdCntPrev = 0;
      Lshd_lbup_diag_cmd_counter = u8LocalDuration;
      if (Lshd_lbup_diag_cmd_counter == 0)
      {
         bLocalHeatSenO2_bMonRunUsHeatCmd = 1;
      }
      else
      {
         bLocalHeatSenO2_bMonRunUsHeatCmd = 0;
      }
   }
   else
   {
      HEATSENO2USCMD_u8DiagCmdCntPrev = Lshd_lbup_diag_cmd_counter;
      if (Lshd_lbup_diag_cmd_counter > 0)
      {
         Lshd_lbup_diag_cmd_counter = (uint8)(Lshd_lbup_diag_cmd_counter - 1);
         if (Lshd_lbup_diag_cmd_counter == 0)
         {
            bLocalHeatSenO2_bMonRunUsHeatCmd = 1;
         }
         else
         {
            bLocalHeatSenO2_bMonRunUsHeatCmd = 0;
         }
      }
       /* This code is added in order to  avoid qac warning */
      else
      {
         VEMS_vidGET(HeatSenO2_bMonRunUsHeatCmd,
                     bLocalHeatSenO2_bMonRunUsHeatCmd);
      }
   }
   VEMS_vidSET(HeatSenO2_bMonRunUsHeatCmd, bLocalHeatSenO2_bMonRunUsHeatCmd);

   if (  (bLocalHeatSenO2_bMonRunUsHeatCmd != 0)
      && (Lshd_lbup_heat_diag_ena_uacb0 != 0) )
   {

      LsSys_rLsUsMainOxCHeatPwrDiag = 0;
   }
   else
   {
      LsSys_rLsUsMainOxCHeatPwrDiag =
         (uint8)MATHSRV_udtMIN(LsSys_rLsUsMainOxCHeatPwrCor, 200);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatReq                              */
/* !Description :  La puissance de chauffage précédemment calculée est        */
/*                 remplacée par la valeur nulle lorsque le mode dégradé de   */
/*                 fonctionnement est activé ou en cas de surtension batterie.*/
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_006.01                                     */
/*                 VEMS_R_09_04308_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bAcvLsUsMainOxCHeatLih;                               */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_uBattAcvHeatLih_C;                                      */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrDiag;                                */
/*  output uint8 LsSys_rLsUsMainOxCHeatPwrReq;                                */
/*  output boolean Chauffage_sonde_o2_amont;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatReq(void)
{
   boolean bLocalLsSys_bAcvLsUsMainOxCHeatL;
   boolean bLocalChauffage_sonde_o2_amont;
   uint8   u8LocalLsSys_rLsUsMainOxCHeatPwr;
   sint16  s16LocalExt_uBattMes;
   uint16  u16LocalLsSys_uBattAcvHeatLih_C;


   VEMS_vidGET(LsSys_bAcvLsUsMainOxCHeatLih, bLocalLsSys_bAcvLsUsMainOxCHeatL);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   bLocalChauffage_sonde_o2_amont = 0;
   u16LocalLsSys_uBattAcvHeatLih_C = (uint16)(LsSys_uBattAcvHeatLih_C * 10);
   if (  (bLocalLsSys_bAcvLsUsMainOxCHeatL != 0)
      || (s16LocalExt_uBattMes > (sint16)u16LocalLsSys_uBattAcvHeatLih_C) )
   {
      VEMS_vidSET(LsSys_rLsUsMainOxCHeatPwrReq, 0);
   }
   else
   {
      u8LocalLsSys_rLsUsMainOxCHeatPwr =
         (uint8)MATHSRV_udtMIN(LsSys_rLsUsMainOxCHeatPwrDiag, 200);
      VEMS_vidSET(LsSys_rLsUsMainOxCHeatPwrReq,
                  u8LocalLsSys_rLsUsMainOxCHeatPwr);
      if (u8LocalLsSys_rLsUsMainOxCHeatPwr != 0)
      {
         bLocalChauffage_sonde_o2_amont = 1;
      }
   }
   VEMS_vidSET(Chauffage_sonde_o2_amont, bLocalChauffage_sonde_o2_amont);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidLsUsHeatCmd                              */
/* !Description :  L’objectif de ce module est la génération du signal de     */
/*                 commande du transistor régissant le chauffage de la sonde à*/
/*                 oxygène amont.                                             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_04308_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2USCMD_vidCalcPwmPeriod();                       */
/*  extf argret void HEATSENO2USCMD_vidCalculTimeOn();                        */
/*  extf argret void HEATSENO2USCMD_vidDriverCmd();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidLsUsHeatCmd(void)
{
   HEATSENO2USCMD_vidCalcPwmPeriod();
   HEATSENO2USCMD_vidCalculTimeOn();
   HEATSENO2USCMD_vidDriverCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidCalcPwmPeriod                            */
/* !Description :  fonction de calcul et/ou  détermination de la période du   */
/*                 signal de commande de chauffage                            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrReq;                                 */
/*  input boolean Lshd_upstr_t_on_strategy;                                   */
/*  input uint16 Lshd_upstr_t_on_delay;                                       */
/*  input uint16 Lshd_upstr_rco_per_uacn0;                                    */
/*  output uint16 Lshd_upstr_rco_periode;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidCalcPwmPeriod(void)
{
   uint8  u8LocalLsSys_rLsUsMainOxCHeatPwr;
   uint32 u32LocalDelay;


   VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrReq, u8LocalLsSys_rLsUsMainOxCHeatPwr);

   if (  (Lshd_upstr_t_on_strategy != 0)
      && (u8LocalLsSys_rLsUsMainOxCHeatPwr > 0) )
   {
      u32LocalDelay = ( (Lshd_upstr_t_on_delay * 200)
                      / u8LocalLsSys_rLsUsMainOxCHeatPwr);
      Lshd_upstr_rco_periode = (uint16)MATHSRV_udtMIN(u32LocalDelay, 510);
   }
   else
   {
      Lshd_upstr_rco_periode =
         (uint16)MATHSRV_udtMIN(Lshd_upstr_rco_per_uacn0, 510);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2USCMD_vidCalculTimeOn                             */
/* !Description :  fonction de calcul et/ou  détermination du temps           */
/*                 d’activation du signal de commande de chauffage pendant    */
/*                 cette période                                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lshd_upstr_t_on_strategy;                                   */
/*  input uint16 Lshd_upstr_t_on_delay;                                       */
/*  input uint8 LsSys_rLsUsMainOxCHeatPwrReq;                                 */
/*  input uint16 Lshd_upstr_rco_per_uacn0;                                    */
/*  output uint16 Lshd_upstr_t_on_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2USCMD_vidCalculTimeOn(void)
{
   uint8  u8LocalLsSys_rLsUsMainOxCHeatPwr;
   uint32 u32LocalFixPeriod;


   if (Lshd_upstr_t_on_strategy != 0)
   {
      Lshd_upstr_t_on_uavn0 =
         (uint16)MATHSRV_udtMIN(Lshd_upstr_t_on_delay, 510);
   }
   else
   {
      VEMS_vidGET(LsSys_rLsUsMainOxCHeatPwrReq,
                  u8LocalLsSys_rLsUsMainOxCHeatPwr);
      u32LocalFixPeriod = ( ( u8LocalLsSys_rLsUsMainOxCHeatPwr
                            * Lshd_upstr_rco_per_uacn0)
                          / 200);
      Lshd_upstr_t_on_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalFixPeriod, 510);
   }
}

/*------------------------------- end of file --------------------------------*/