/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSCMD                                          */
/* !Description     : HEATSENO2DSCMD Component                                */
/*                                                                            */
/* !Module          : HEATSENO2DSCMD                                          */
/* !Description     : COMMANDE DU CHAUFFAGE SONDE O2 ON/OFF AVAL              */
/*                                                                            */
/* !File            : HEATSENO2DSCMD_FCT1.C                                   */
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
/*   1 / HEATSENO2DSCMD_vidInitOutput                                         */
/*   2 / HEATSENO2DSCMD_vidLsUsHeatRaw                                        */
/*   3 / HEATSENO2DSCMD_vidSlopHeat                                           */
/*   4 / HEATSENO2DSCMD_vidLsUsHeatMan                                        */
/*   5 / HEATSENO2DSCMD_vidLsUsHeatCor                                        */
/*   6 / HEATSENO2DSCMD_vidLsUsHeatDiag                                       */
/*   7 / HEATSENO2DSCMD_vidLsUsHeatReq                                        */
/*   8 / HEATSENO2DSCMD_vidLsUsHeatCmd                                        */
/*   9 / HEATSENO2DSCMD_vidCalcPwmPeriod                                      */
/*   10 / HEATSENO2DSCMD_vidCalculTimeOn                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 04727 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/HEATSENO2/HEATSENO2DSCMD/HEATSENO2$*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   24 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   24 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "HEATSENO2DSCMD.H"
#include "HEATSENO2DSCMD_l.h"
#include "HEATSENO2DSCMD_IM.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidInitOutput                               */
/* !Description :  fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrReq;                                */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrMan;                                */
/*  output boolean Chauffage_sonde_o2_aval;                                   */
/*  output boolean Chauf_o2_aval_demande_on;                                  */
/*  output boolean HeatSenO2_bMonRunDsHeatCmd;                                */
/*  output boolean Lshd_down_lbda_sens_heat_active;                           */
/*  output uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;                            */
/*  output uint8 Lshd_lbdw_diag_cmd_counter;                                  */
/*  output uint16 Lshd_dwstr_period_counter;                                  */
/*  output boolean Lshd_dwstr_period_updating;                                */
/*  output uint8 HEATSENO2DSCMD_u8DiagCmdCntPrev;                             */
/*  output uint16 HEATSENO2DSCMD_u16RcoPeriodPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidInitOutput(void)
{
   VEMS_vidSET(LsSys_rLsDsMainOxCHeatPwrReq, 0);
   VEMS_vidSET(LsSys_rLsDsMainOxCHeatPwrMan, 0);
   VEMS_vidSET(Chauffage_sonde_o2_aval, 0);
   VEMS_vidSET(Chauf_o2_aval_demande_on, 0);
   VEMS_vidSET(HeatSenO2_bMonRunDsHeatCmd, 1);
   VEMS_vidSET(Lshd_down_lbda_sens_heat_active, 0);
   HEATSENO2DSCMD_u8MainOxCHeatPrev = LSDSMAINOXCHEAT_PHASE_A;
   Lshd_lbdw_diag_cmd_counter = 0;
   Lshd_dwstr_period_counter = 0;
   Lshd_dwstr_period_updating  = 1;
   /* internal variables are set to 1 in order to activate the timer blocks */
   HEATSENO2DSCMD_u8DiagCmdCntPrev = 1;
   HEATSENO2DSCMD_u16RcoPeriodPrev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatRaw                              */
/* !Description :  Ce module calcule la puissance de chauffage de la sonde O2,*/
/*                 qui doit être adaptée en fonction des phases de vie du     */
/*                 véhicule                                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_006.01                                     */
/*                 VEMS_R_09_04727_001.01                                     */
/*                 VEMS_R_09_04727_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSCMD_vidSlopHeat();                            */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;                             */
/*  input sint16 LsSys_tCoLsHeat;                                             */
/*  input uint8 LsSys_tCoLsDsMainOxCHeatPhaC1_T[6];                           */
/*  input uint8 LsSys_rLsDsMainOxCHeatPhaseC1_M[6];                           */
/*  input uint8 LsSys_tCoLsDsMainOxCHeatPhaC2_T[6];                           */
/*  input uint8 LsSys_rLsDsMainOxCHeatPhaseC2_M[6];                           */
/*  input uint16 ExM_mfEgTot;                                                 */
/*  input uint16 LsSys_mfEgTotDsHeatPwrMod_T[8];                              */
/*  input uint16 LsSys_mfEgTotDsHeatPhaseD_T[8];                              */
/*  input uint16 LsSys_mfEgTotDsHeatPhaseC1_T[8];                             */
/*  input uint16 LsSys_mfEgTotDsHeatPhaseC2_T[8];                             */
/*  input uint16 ExM_tExLsDsMainOxCEstim;                                     */
/*  input uint16 LsSys_tExEstimDsHeatPwrMod_T[8];                             */
/*  input uint16 LsSys_tExEstimDsHeatPhaseD_T[8];                             */
/*  input uint16 LsSys_tExEstimDsHeatPhaseC1_T[8];                            */
/*  input uint16 LsSys_tExEstimDsHeatPhaseC2_T[8];                            */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrMod_M[8][8];                         */
/*  input uint8 LsSys_facLsDsMainOxCHeatPhaseD_M[8][8];                       */
/*  input uint8 LsSys_facLsDsOxCHeatPhaseC1_M[8][8];                          */
/*  input uint8 LsSys_facLsDsOxCHeatPhaseC2_M[8][8];                          */
/*  input uint8 LsSys_rLsDsMainOxCHeatPhaseB_C;                               */
/*  input uint8 LsSys_rLsDsMainOxCHeatPhaseD_C;                               */
/*  input uint8 LsSys_rLsDsMainOxCHeatPhaseF_C;                               */
/*  input sint16 LsSys_DsNegSlopHeat;                                         */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrRaw;                                 */
/*  input uint8 LsSys_DsPosSlopHeat;                                          */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrRaw;                                */
/*  output uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatRaw(void)
{
   uint8  u8LocalLsSys_DsNegSlopHeat;
   uint8  u8LocalOutMap1;
   uint8  u8LocalOutMap2;
   uint8  u8LocalOutMap3;
   uint8  u8LocalOutMap4;
   uint8  u8LocalLsSys_stLsDsMainOxCHeat;
   uint8  u8LocalInp;
   uint8  u8LocalInterp1;
   uint8  u8LocalInterp2;
   uint16 u16LocalParaX1;
   uint16 u16LocalParaX2;
   uint16 u16LocalParaX3;
   uint16 u16LocalParaX4;
   uint16 u16LocalParaY1;
   uint16 u16LocalParaY2;
   uint16 u16LocalParaY3;
   uint16 u16LocalParaY4;
   uint16 u16LocalExM_mfEgTot;
   uint16 u16LocalExM_tExLsDsMainOxCEstim;
   uint16 u16LocalPara;
   uint16 u16LocalRateLimterInput;
   uint16 u16LocalRateLimterOutput;
   sint16 s16LocalLsSys_DsNegSlopHeat;
   sint16 s16LocalLsSys_tCoLsHeat;
   sint32 s32LocalInput;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);
   if (u8LocalLsSys_stLsDsMainOxCHeat != HEATSENO2DSCMD_u8MainOxCHeatPrev)
   {
      HEATSENO2DSCMD_vidSlopHeat();
   }

   VEMS_vidGET(LsSys_tCoLsHeat, s16LocalLsSys_tCoLsHeat);
   s32LocalInput = (sint32)(s16LocalLsSys_tCoLsHeat + 40);
   u8LocalInp = (uint8)MATHSRV_udtCLAMP(s32LocalInput, 0, 254);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsDsMainOxCHeatPhaC1_T,
                                              u8LocalInp,
                                              6);
   u8LocalInterp1 = MATHSRV_u8Interp1d(LsSys_rLsDsMainOxCHeatPhaseC1_M,
                                       u16LocalPara);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(LsSys_tCoLsDsMainOxCHeatPhaC2_T,
                                              u8LocalInp,
                                              6);
   u8LocalInterp2 = MATHSRV_u8Interp1d(LsSys_rLsDsMainOxCHeatPhaseC2_M,
                                       u16LocalPara);

   VEMS_vidGET(ExM_mfEgTot,u16LocalExM_mfEgTot);
   u16LocalExM_mfEgTot = (uint16)(((u16LocalExM_mfEgTot * 3125) + 2048) / 4096);

   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotDsHeatPwrMod_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotDsHeatPhaseD_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX3 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotDsHeatPhaseC1_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   u16LocalParaX4 = MATHSRV_u16CalcParaIncAryU16(LsSys_mfEgTotDsHeatPhaseC2_T,
                                                 u16LocalExM_mfEgTot,
                                                 8);

   VEMS_vidGET(ExM_tExLsDsMainOxCEstim,u16LocalExM_tExLsDsMainOxCEstim);
   u16LocalExM_tExLsDsMainOxCEstim = (uint16)( u16LocalExM_tExLsDsMainOxCEstim
                                             / 32);

   u16LocalParaY1 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimDsHeatPwrMod_T,
                                                u16LocalExM_tExLsDsMainOxCEstim,
                                                8);

   u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimDsHeatPhaseD_T,
                                                u16LocalExM_tExLsDsMainOxCEstim,
                                                8);

   u16LocalParaY3 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimDsHeatPhaseC1_T,
                                                u16LocalExM_tExLsDsMainOxCEstim,
                                                8);

   u16LocalParaY4 = MATHSRV_u16CalcParaIncAryU16(LsSys_tExEstimDsHeatPhaseC2_T,
                                                u16LocalExM_tExLsDsMainOxCEstim,
                                                8);

   u8LocalOutMap1 = MATHSRV_u8Interp2d(&LsSys_rLsDsMainOxCHeatPwrMod_M[0][0],
                                       u16LocalParaX1,
                                       u16LocalParaY1,
                                       8);

   u8LocalOutMap2 = MATHSRV_u8Interp2d(&LsSys_facLsDsMainOxCHeatPhaseD_M[0][0],
                                       u16LocalParaX2,
                                       u16LocalParaY2,
                                       8);

   u8LocalOutMap3 = MATHSRV_u8Interp2d(&LsSys_facLsDsOxCHeatPhaseC1_M[0][0],
                                       u16LocalParaX3,
                                       u16LocalParaY3,
                                       8);
   u8LocalOutMap4 = MATHSRV_u8Interp2d(&LsSys_facLsDsOxCHeatPhaseC2_M[0][0],
                                       u16LocalParaX4,
                                       u16LocalParaY4,
                                       8);

   switch (u8LocalLsSys_stLsDsMainOxCHeat)
   {
      case LSDSMAINOXCHEAT_PHASE_A :
         u16LocalRateLimterInput = 0;
         break;

      case LSDSMAINOXCHEAT_PHASE_B :
         u16LocalRateLimterInput = LsSys_rLsDsMainOxCHeatPhaseB_C;
         break;

      case LSDSMAINOXCHEAT_PHASE_C1 :
         u16LocalRateLimterInput = (uint16)( ( u8LocalInterp1
                                             * u8LocalOutMap3
                                             * 5)
                                            / 1000);
         break;

      case LSDSMAINOXCHEAT_PHASE_C2 :
         u16LocalRateLimterInput = (uint16)( ( u8LocalInterp2
                                             * u8LocalOutMap4
                                             * 5)
                                           / 1000);
         break;

      case LSDSMAINOXCHEAT_PHASE_D :
         u16LocalRateLimterInput = (uint16)( ( LsSys_rLsDsMainOxCHeatPhaseD_C
                                             * u8LocalOutMap2
                                             * 5)
                                           / 1000);
         break;

      case LSDSMAINOXCHEAT_PHASE_E :
         u16LocalRateLimterInput = u8LocalOutMap1;
         break;

      case LSDSMAINOXCHEAT_PHASE_F :
         u16LocalRateLimterInput = LsSys_rLsDsMainOxCHeatPhaseF_C;
         break;

      case LSDSMAINOXCHEAT_PHASE_G :
         u16LocalRateLimterInput = 0;
         break;

      default:
         u16LocalRateLimterInput = 0;
         break;
   }

   s16LocalLsSys_DsNegSlopHeat = (sint16)((-1) * LsSys_DsNegSlopHeat);
   u8LocalLsSys_DsNegSlopHeat =
      (uint8)MATHSRV_udtCLAMP(s16LocalLsSys_DsNegSlopHeat, 0, 200);
   u16LocalRateLimterOutput =
      MATHSRV_u16SlewFilter((uint16)LsSys_rLsDsMainOxCHeatPwrRaw,
                           u16LocalRateLimterInput,
                           (uint16)LsSys_DsPosSlopHeat,
                           (uint16)u8LocalLsSys_DsNegSlopHeat);

   LsSys_rLsDsMainOxCHeatPwrRaw =
      (uint8)MATHSRV_udtMIN(u16LocalRateLimterOutput, 200);
   HEATSENO2DSCMD_u8MainOxCHeatPrev = u8LocalLsSys_stLsDsMainOxCHeat;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidSlopHeat                                 */
/* !Description :  Ce bloc met à jour les valeurs maximales de variation des  */
/*                 puissances de chauffe lors des changements de phase de     */
/*                 chauffage sonde aval ;                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_008.01                                     */
/*                 VEMS_R_09_04727_002.01                                     */
/*                 VEMS_R_09_04727_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st70 LsSys_stLsDsMainOxCHeat;                                       */
/*  input sint16 LsSys_DsNegSlopHeatWku_C;                                    */
/*  input uint8 LsSys_DsPosSlopHeatWku_C;                                     */
/*  input uint8 LsSys_DsPosSlopHeatDewProt_C;                                 */
/*  input sint16 LsSys_DsNegSlopHeatDewProt_C;                                */
/*  input uint8 LsSys_DsPosSlopHeatHi_C;                                      */
/*  input uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;                             */
/*  input uint8 LsSys_DsPosSlopHeatNoHi_C;                                    */
/*  input uint8 LsSys_DsPosSlopHeatHot_C;                                     */
/*  input sint16 LsSys_DsNegSlopHeatHi_C;                                     */
/*  output uint8 LsSys_DsPosSlopHeat;                                         */
/*  output sint16 LsSys_DsNegSlopHeat;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidSlopHeat(void)
{
   uint8  u8LocalLsSysDsPosSlopHeat;
   uint8  u8LocalLsSys_stLsDsMainOxCHeat;
   sint16 s16LocalLsSysDsNegSlopHeat;


   VEMS_vidGET(LsSys_stLsDsMainOxCHeat, u8LocalLsSys_stLsDsMainOxCHeat);
   switch (u8LocalLsSys_stLsDsMainOxCHeat)
   {
      case LSDSMAINOXCHEAT_PHASE_A :
         u8LocalLsSysDsPosSlopHeat = 200;
         s16LocalLsSysDsNegSlopHeat = LsSys_DsNegSlopHeatWku_C;
         break;

      case LSDSMAINOXCHEAT_PHASE_B :
         u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatWku_C;
         s16LocalLsSysDsNegSlopHeat = -200;
         break;

      case LSDSMAINOXCHEAT_PHASE_C1 :
         u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatDewProt_C;
         s16LocalLsSysDsNegSlopHeat = -200;
         break;

      case LSDSMAINOXCHEAT_PHASE_C2 :
         u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatDewProt_C;
         s16LocalLsSysDsNegSlopHeat = LsSys_DsNegSlopHeatDewProt_C;
         break;

      case LSDSMAINOXCHEAT_PHASE_D :
         u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatHi_C;
         s16LocalLsSysDsNegSlopHeat = -200;
         break;

      case LSDSMAINOXCHEAT_PHASE_E :
         if (  (HEATSENO2DSCMD_u8MainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_C1)
            || (HEATSENO2DSCMD_u8MainOxCHeatPrev == LSDSMAINOXCHEAT_PHASE_C2))
         {
            u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatNoHi_C;
         }
         else
         {
            u8LocalLsSysDsPosSlopHeat = LsSys_DsPosSlopHeatHot_C;
         }
         s16LocalLsSysDsNegSlopHeat = LsSys_DsNegSlopHeatHi_C;
         break;

      case LSDSMAINOXCHEAT_PHASE_F :
      case LSDSMAINOXCHEAT_PHASE_G :
         u8LocalLsSysDsPosSlopHeat = 200;
         s16LocalLsSysDsNegSlopHeat = -200;
         break;

      default:
         u8LocalLsSysDsPosSlopHeat = 0;
         s16LocalLsSysDsNegSlopHeat = 0;
         break;
   }
   LsSys_DsPosSlopHeat = (uint8)MATHSRV_udtMIN(u8LocalLsSysDsPosSlopHeat, 200);
   LsSys_DsNegSlopHeat = (sint16)MATHSRV_udtCLAMP(s16LocalLsSysDsNegSlopHeat,
                                                  -200,
                                                  0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatMan                              */
/* !Description :  Ce bloc prévoit l’utilisation d’un mode banc pour le signal*/
/*                 de commande du chauffage sonde aval.                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_020.01                                     */
/*                 VEMS_R_09_04727_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bDsHeatPwrManEna_C;                                   */
/*  input uint8 LsSys_rDsHeatPwrMan_C;                                        */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrRaw;                                 */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrMan;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatMan(void)
{
   uint8 u8LocalLsSysrPwrMan;


   if (LsSys_bDsHeatPwrManEna_C != 0)
   {
      u8LocalLsSysrPwrMan = LsSys_rDsHeatPwrMan_C;
   }
   else
   {
      u8LocalLsSysrPwrMan = LsSys_rLsDsMainOxCHeatPwrRaw;
   }
   u8LocalLsSysrPwrMan =(uint8)MATHSRV_udtMIN(u8LocalLsSysrPwrMan,200);
   VEMS_vidSET(LsSys_rLsDsMainOxCHeatPwrMan, u8LocalLsSysrPwrMan);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatCor                              */
/* !Description :  Ce module permet de prendre en compte la tension batterie  */
/*                 dans le calcul de la puissance de chauffage de la sonde, en*/
/*                 corrigeant la valeur du signal RCO brut(une hausse du      */
/*                 signal traduisant une baisse de la tension batterie)       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_019.01                                     */
/*                 VEMS_R_09_04727_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrMan;                                 */
/*  input uint8 LsSys_uBattDsHeatRef;                                         */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrCor;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatCor(void)
{
   boolean bLocalInhuBattCorLsHeat;
   uint8   u8LocalHeatPwrMan;
   sint16  s16LocalExt_uBattMes;
   uint32  u32LocalRcoCorrDen;
   uint32  u32LocalRcoCorrNum;
   uint32  u32LocalRcoCorr;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrMan, u8LocalHeatPwrMan);
   bLocalInhuBattCorLsHeat = GDGAR_bGetFRM(FRM_FRM_INHUBATTCORLSHEAT);
   if (  (s16LocalExt_uBattMes > 0)
      && (bLocalInhuBattCorLsHeat == 0) )
   {
      u32LocalRcoCorrNum =  (uint32)( LsSys_uBattDsHeatRef
                                    * LsSys_uBattDsHeatRef
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
   LsSys_rLsDsMainOxCHeatPwrCor = (uint8)MATHSRV_udtMIN(u32LocalRcoCorr, 200);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatDiag                             */
/* !Description :  Afin de pouvoir diagnostiquer un éventuel court-circuit au */
/*                 niveau du driver de puissance du chauffage sonde, la       */
/*                 commande de chauffage est volontairement annulée de façon  */
/*                 périodique                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_021.01                                     */
/*                 VEMS_R_09_04727_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lshd_lbdw_diag_cmd_per_uacn0;                                 */
/*  input uint8 HEATSENO2DSCMD_u8DiagCmdCntPrev;                              */
/*  input uint8 Lshd_lbdw_diag_cmd_counter;                                   */
/*  input boolean HeatSenO2_bMonRunDsHeatCmd;                                 */
/*  input boolean Lshd_lbdw_heat_diag_ena_uacb0;                              */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrCor;                                 */
/*  output uint8 HEATSENO2DSCMD_u8DiagCmdCntPrev;                             */
/*  output uint8 Lshd_lbdw_diag_cmd_counter;                                  */
/*  output boolean HeatSenO2_bMonRunDsHeatCmd;                                */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrDiag;                               */
/*  output boolean Lshd_down_lbda_sens_heat_active;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatDiag(void)
{
   boolean bLocalHeatSenO2_bMonRunDsHeatCmd;
   uint8   u8LocalDuration;


   if (Lshd_lbdw_diag_cmd_per_uacn0 > 0)
   {
      u8LocalDuration = (uint8)( Lshd_lbdw_diag_cmd_per_uacn0 - 1);
   }
   else
   {
      u8LocalDuration = 0;
   }

   if (  (HEATSENO2DSCMD_u8DiagCmdCntPrev != 0)
      && (Lshd_lbdw_diag_cmd_counter == 0))
   {
      HEATSENO2DSCMD_u8DiagCmdCntPrev = 0;
      Lshd_lbdw_diag_cmd_counter = u8LocalDuration;
      if (Lshd_lbdw_diag_cmd_counter == 0)
      {
         bLocalHeatSenO2_bMonRunDsHeatCmd = 1;
      }
      else
      {
         bLocalHeatSenO2_bMonRunDsHeatCmd = 0;
      }
   }
   else
   {
      HEATSENO2DSCMD_u8DiagCmdCntPrev = Lshd_lbdw_diag_cmd_counter;
      if (Lshd_lbdw_diag_cmd_counter > 0)
      {
         Lshd_lbdw_diag_cmd_counter = (uint8)(Lshd_lbdw_diag_cmd_counter - 1);
         if (Lshd_lbdw_diag_cmd_counter == 0)
         {
            bLocalHeatSenO2_bMonRunDsHeatCmd = 1;
         }
         else
         {
            bLocalHeatSenO2_bMonRunDsHeatCmd = 0;
         }
      }
       /* This code is added in order to  avoid qac warning */
      else
      {
         VEMS_vidGET(HeatSenO2_bMonRunDsHeatCmd,
                     bLocalHeatSenO2_bMonRunDsHeatCmd);
      }
   }
   VEMS_vidSET(HeatSenO2_bMonRunDsHeatCmd, bLocalHeatSenO2_bMonRunDsHeatCmd);

   if (  (bLocalHeatSenO2_bMonRunDsHeatCmd != 0)
      && (Lshd_lbdw_heat_diag_ena_uacb0 != 0) )
   {

      LsSys_rLsDsMainOxCHeatPwrDiag = 0;
      VEMS_vidSET(Lshd_down_lbda_sens_heat_active,0);
   }
   else
   {
      LsSys_rLsDsMainOxCHeatPwrDiag =
         (uint8)MATHSRV_udtMIN(LsSys_rLsDsMainOxCHeatPwrCor, 200);
      VEMS_vidSET(Lshd_down_lbda_sens_heat_active,1);
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatReq                              */
/* !Description :  La puissance de chauffage précédemment calculée est        */
/*                 remplacée par la valeur nulle lorsque le mode dégradé de   */
/*                 fonctionnement est activé ou en cas de surtension batterie.*/
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_018.01                                     */
/*                 VEMS_R_09_01916_028.01                                     */
/*                 VEMS_R_09_04727_006.01                                     */
/*                 VEMS_R_09_04727_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean LsSys_bAcvLsDsMainOxCHeatLih;                               */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 LsSys_uBattAcvHeatLih_C;                                      */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrDiag;                                */
/*  output uint8 LsSys_rLsDsMainOxCHeatPwrReq;                                */
/*  output boolean Chauffage_sonde_o2_aval;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatReq(void)
{
   boolean bLocalLsSys_bAcvLsDsMainOxCHeatL;
   boolean bLocalChauffage_sonde_o2_aval;
   uint8   u8LocalLsSys_rLsDsMainOxCHeatPwr;
   sint16  s16LocalExt_uBattMes;
   uint16  u16LocalLsSys_uBattAcvHeatLih_C;


   VEMS_vidGET(LsSys_bAcvLsDsMainOxCHeatLih,bLocalLsSys_bAcvLsDsMainOxCHeatL);
   VEMS_vidGET(Ext_uBattMes,s16LocalExt_uBattMes);

   bLocalChauffage_sonde_o2_aval = 0;
   u16LocalLsSys_uBattAcvHeatLih_C = (uint16)(LsSys_uBattAcvHeatLih_C * 10);
   if (  (bLocalLsSys_bAcvLsDsMainOxCHeatL != 0)
      || (s16LocalExt_uBattMes > (sint16)u16LocalLsSys_uBattAcvHeatLih_C) )
   {
      VEMS_vidSET(LsSys_rLsDsMainOxCHeatPwrReq, 0);
   }
   else
   {
      u8LocalLsSys_rLsDsMainOxCHeatPwr =
         (uint8)MATHSRV_udtMIN(LsSys_rLsDsMainOxCHeatPwrDiag, 200);
      VEMS_vidSET(LsSys_rLsDsMainOxCHeatPwrReq,
                  u8LocalLsSys_rLsDsMainOxCHeatPwr);
      if (u8LocalLsSys_rLsDsMainOxCHeatPwr != 0)
      {
         bLocalChauffage_sonde_o2_aval = 1;
      }
   }
   VEMS_vidSET(Chauffage_sonde_o2_aval, bLocalChauffage_sonde_o2_aval);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidLsUsHeatCmd                              */
/* !Description :  L’objectif de ce module est la génération du signal de     */
/*                 commande du transistor régissant le chauffage de la sonde à*/
/*                 oxygène aval.                                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_01916_022.01                                     */
/*                 VEMS_R_09_04727_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSCMD_vidCalcPwmPeriod();                       */
/*  extf argret void HEATSENO2DSCMD_vidCalculTimeOn();                        */
/*  extf argret void HEATSENO2DSCMD_vidDriverCmd();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidLsUsHeatCmd(void)
{
   HEATSENO2DSCMD_vidCalcPwmPeriod();
   HEATSENO2DSCMD_vidCalculTimeOn();
   HEATSENO2DSCMD_vidDriverCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidCalcPwmPeriod                            */
/* !Description :  fonction de  calcul et/ou  détermination de la période du  */
/*                 signal de commande de chauffage                            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrReq;                                 */
/*  input boolean Lshd_dwstr_t_on_strategy;                                   */
/*  input uint16 Lshd_dwstr_t_on_delay;                                       */
/*  input uint16 Lshd_dwstr_rco_per_uacn0;                                    */
/*  output uint16 Lshd_dwstr_rco_periode;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidCalcPwmPeriod(void)
{
   uint8  u8LocalLsSys_rLsDsMainOxCHeatPwr;
   uint32 u32LocalDelay;


   VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrReq,u8LocalLsSys_rLsDsMainOxCHeatPwr);

   if (  (Lshd_dwstr_t_on_strategy != 0)
      && (u8LocalLsSys_rLsDsMainOxCHeatPwr > 0) )
   {
      u32LocalDelay = ( (Lshd_dwstr_t_on_delay * 200)
                      / u8LocalLsSys_rLsDsMainOxCHeatPwr);
      Lshd_dwstr_rco_periode = (uint16)MATHSRV_udtMIN(u32LocalDelay, 510);
   }
   else
   {
      Lshd_dwstr_rco_periode =
         (uint16)MATHSRV_udtMIN(Lshd_dwstr_rco_per_uacn0, 510);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSCMD_vidCalculTimeOn                             */
/* !Description :  fonction de calcul et/ou détermination du temps            */
/*                 d’activation du signal de commande de chauffage pendant    */
/*                 cette période                                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lshd_dwstr_t_on_strategy;                                   */
/*  input uint16 Lshd_dwstr_t_on_delay;                                       */
/*  input uint8 LsSys_rLsDsMainOxCHeatPwrReq;                                 */
/*  input uint16 Lshd_dwstr_rco_per_uacn0;                                    */
/*  output uint16 Lshd_dwstr_t_on_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSCMD_vidCalculTimeOn(void)
{
   uint8  u8LocalLsSys_rLsDsMainOxCHeatPwr;
   uint32 u32LocalFixPeriod;


   if (Lshd_dwstr_t_on_strategy != 0)
   {
      Lshd_dwstr_t_on_uavn0 =
         (uint16)MATHSRV_udtMIN(Lshd_dwstr_t_on_delay, 510);
   }
   else
   {
      VEMS_vidGET(LsSys_rLsDsMainOxCHeatPwrReq,
                  u8LocalLsSys_rLsDsMainOxCHeatPwr);
      u32LocalFixPeriod =( ( u8LocalLsSys_rLsDsMainOxCHeatPwr
                           * Lshd_dwstr_rco_per_uacn0)
                         / 200);
      Lshd_dwstr_t_on_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalFixPeriod, 510);
   }
}

/*------------------------------- end of file --------------------------------*/