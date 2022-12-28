/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTMANCLU                                              */
/* !Description     : PROTMANCLU Component                                    */
/*                                                                            */
/* !Module          : PROTMANCLU                                              */
/* !Description     : Clutch protection for manual gearbox                    */
/*                                                                            */
/* !File            : PROTMANCLU_FCT1.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / PROTMANCLU_vidInitOutput                                             */
/*   2 / PROTMANCLU_vidClutch_Protection                                      */
/*   3 / PROTMANCLU_vidDeterStatesClutch                                      */
/*   4 / PROTMANCLU_vidEstimTorqTransClut                                     */
/*   5 / PROTMANCLU_vidDetermStateClutch                                      */
/*   6 / PROTMANCLU_vidReconfTorqTransClu                                     */
/*   7 / PROTMANCLU_vidDeterTripltGearbox                                     */
/*   8 / PROTMANCLU_vidEstimClutchTemper                                      */
/*   9 / PROTMANCLU_vidEstimHeatArdClutch                                     */
/*   10 / PROTMANCLU_vidEstimDissipatEnerg                                    */
/*                                                                            */
/* !Reference   : V02 NT 11 04687 / 01                                        */
/* !OtherRefs   : 01460_10_03770/1.1                                          */
/* !OtherRefs   : VEMS V02 ECU#056597                                         */
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
#include "PROTMANCLU.h"
#include "PROTMANCLU_l.h"
#include "PROTMANCLU_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidInitOutput                                   */
/* !Description :  Initialization of internals and outputs.                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void PROTMANCLU_vidCalculPrevTempInit();                      */
/*  input uint16 PtLim_tWhlCluEstimPrev;                                      */
/*  input uint16 PtLim_tCluEstimPrev;                                         */
/*  input uint16 PtLim_tItAirCluEstimPrev;                                    */
/*  input uint16 PtLim_tCaseCluEstimPrev;                                     */
/*  input uint16 PtLim_tGearCluEstimPrev;                                     */
/*  output boolean CoPt_bAcvProtCluP;                                         */
/*  output boolean CoPt_bDgoCluDmgAfts;                                       */
/*  output boolean CoPt_bMonRunCluDmgAfts;                                    */
/*  output boolean CoPt_bWarnProtClu;                                         */
/*  output uint8 CoPt_rSpdFanReqProtManClu;                                   */
/*  output sint16 CoPt_tManCluEstim;                                          */
/*  output boolean CoPt_bAcvProtCluBfCord;                                    */
/*  output boolean CoPt_bDgoCluDmgAftsBfCord;                                 */
/*  output boolean CoPt_bMonRunCluDmgAftsBfCord;                              */
/*  output boolean CoPt_bWarnProtCluBfCord;                                   */
/*  output uint8 CoPt_rSpdFanReqProtCluBfCord;                                */
/*  output sint16 CoPt_tManCluEstimBfCord;                                    */
/*  output boolean PtLim_bDeacManCluProtReg;                                  */
/*  output uint16 PtLim_facTCaseExtAir;                                       */
/*  output uint16 PtLim_facTCaseItAir;                                        */
/*  output uint16 PtLim_facTCluItAir;                                         */
/*  output uint16 PtLim_facTCoMesAirExt;                                      */
/*  output uint16 PtLim_facTEngItAir;                                         */
/*  output uint16 PtLim_facTExtAirGear;                                       */
/*  output uint16 PtLim_facTGearItAir;                                        */
/*  output uint16 PtLim_facTWhlCluItAir;                                      */
/*  output uint16 PtLim_facTqGearHiA_MP;                                      */
/*  output uint16 PtLim_facTqGearHiB_MP;                                      */
/*  output uint8 PtLim_facTqGearHiC_MP;                                       */
/*  output uint16 PtLim_facTqGearLoA_MP;                                      */
/*  output uint16 PtLim_facTqGearLoB_MP;                                      */
/*  output uint8 PtLim_facTqGearLoC_MP;                                       */
/*  output uint16 PtLim_facTqGearMidA_MP;                                     */
/*  output uint16 PtLim_facTqGearMidB_MP;                                     */
/*  output uint8 PtLim_facTqGearMidC_MP;                                      */
/*  output sint16 PtLim_nCkGrdFil_MP;                                         */
/*  output uint16 PtLim_nDeltaPrimEngSpdHi;                                   */
/*  output uint16 PtLim_nDeltaPrimEngSpdLo;                                   */
/*  output uint16 PtLim_nDeltaPrimEngSpdMid;                                  */
/*  output uint16 PtLim_nPrimShaftTheHi;                                      */
/*  output uint16 PtLim_nPrimShaftTheLo;                                      */
/*  output uint16 PtLim_nPrimShaftTheMid;                                     */
/*  output uint8 PtLim_noCrtSelGear;                                          */
/*  output uint8 PtLim_noGearHi;                                              */
/*  output uint8 PtLim_noGearLo;                                              */
/*  output uint8 PtLim_noGearMid;                                             */
/*  output uint8 PtLim_noGearSel;                                             */
/*  output uint8 PtLim_noProtManClu;                                          */
/*  output sint16 PtLim_pwrDeltaCluSel;                                       */
/*  output sint16 PtLim_pwrDeltaGearSel;                                      */
/*  output sint16 PtLim_pwrDeltaWhlCluSel;                                    */
/*  output uint16 PtLim_pwrHeatCluLo;                                         */
/*  output uint16 PtLim_pwrHeatGearLo;                                        */
/*  output uint16 PtLim_pwrHeatWhlCluLo;                                      */
/*  output uint8 PtLim_stManClu;                                              */
/*  output uint16 PtLim_tAirExtMes;                                           */
/*  output uint16 PtLim_tCaseCluEstimGrd_MP;                                  */
/*  output uint16 PtLim_tCluEstimGrd_MP;                                      */
/*  output uint16 PtLim_tCoMes;                                               */
/*  output uint16 PtLim_tGearCluEstimGrd_MP;                                  */
/*  output sint16 PtLim_tGrdDynCluT;                                          */
/*  output uint16 PtLim_tItAirCluEstimGrd_MP;                                 */
/*  output sint8 PtLim_tOfsCluFanProtHiT;                                     */
/*  output sint8 PtLim_tOfsCluFanProtLoT;                                     */
/*  output sint8 PtLim_tOfsCluNRegT;                                          */
/*  output sint8 PtLim_tOfsCluStopWarnT;                                      */
/*  output uint16 PtLim_tOilEstim;                                            */
/*  output uint16 PtLim_tWhlCluEstimGrd_MP;                                   */
/*  output sint16 PtLim_tqManClu;                                             */
/*  output uint16 PtLim_tqManCluCf;                                           */
/*  output sint16 PtLim_wDeltaCluLoHi;                                        */
/*  output sint16 PtLim_wDeltaCluLoMid;                                       */
/*  output sint16 PtLim_wDeltaGearLoHi;                                       */
/*  output sint16 PtLim_wDeltaGearLoMid;                                      */
/*  output sint16 PtLim_wDeltaWhlCluLoHi;                                     */
/*  output sint16 PtLim_wDeltaWhlCluLoMid;                                    */
/*  output uint8 PtLim_prm_facRatePtToWhl_MP[3];                              */
/*  output sint16 PtLim_prm_pwrDeltaLoHi_MP[3];                               */
/*  output sint16 PtLim_prm_pwrDeltaLoMid_MP[3];                              */
/*  output uint16 PtLim_tWhlCluEstim;                                         */
/*  output uint16 PtLim_tCluEstim;                                            */
/*  output uint16 PtLim_tItAirCluEstim;                                       */
/*  output uint16 PtLim_tCaseCluEstim;                                        */
/*  output uint16 PtLim_tGearCluEstim;                                        */
/*  output sint32 PROTMANCLU_s32Filtre1Mem;                                   */
/*  output sint32 PROTMANCLU_s32Filtre2Mem;                                   */
/*  output boolean PROTMANCLU_bOutHysNeg5;                                    */
/*  output boolean PROTMANCLU_bOutHysPos5;                                    */
/*  output uint8 PROTMANCLU_u8OutMem1;                                        */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev2;                            */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev;                             */
/*  output boolean PROTMANCLU_bRstIntegrator;                                 */
/*  output boolean PROTMANCLU_bRstIntegratorPrev;                             */
/*  output uint8 PROTMANCLU_u8PtLim_noGearMid;                                */
/*  output boolean PROTMANCLU_bOutHysPos;                                     */
/*  output boolean PROTMANCLU_bTurnOffDelayInPrev;                            */
/*  output uint16 PROTMANCLU_u16TurnOffDelayCount;                            */
/*  output boolean PROTMANCLU_bOutHysPos1;                                    */
/*  output boolean PROTMANCLU_bOutHysPos2;                                    */
/*  output boolean PROTMANCLU_bOutHysPos3;                                    */
/*  output boolean PROTMANCLU_bOutHysPos4;                                    */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev1;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev2;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev3;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev4;                            */
/*  output boolean PROTMANCLU_bBasculeRS;                                     */
/*  output uint16 PROTMANCLU_u16SpdVehFanReq;                                 */
/*  output uint8 PROTMANCLU_u8Ext_stGBxCfPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidInitOutput(void)
{
   uint8 u8LocalIndex1;


   /*Outputs's initialization*/
   VEMS_vidSET(CoPt_bAcvProtCluP, 0);
   VEMS_vidSET(CoPt_bDgoCluDmgAfts, 0);
   VEMS_vidSET(CoPt_bMonRunCluDmgAfts, 1);
   VEMS_vidSET(CoPt_bWarnProtClu, 0);
   VEMS_vidSET(CoPt_rSpdFanReqProtManClu, 0);
   VEMS_vidSET(CoPt_tManCluEstim , 320);

   /*Internals's initialization*/
   CoPt_bAcvProtCluBfCord       = 0;
   CoPt_bDgoCluDmgAftsBfCord    = 0;
   CoPt_bMonRunCluDmgAftsBfCord = 1;
   CoPt_bWarnProtCluBfCord      = 0;
   CoPt_rSpdFanReqProtCluBfCord = 0;
   CoPt_tManCluEstimBfCord      = 320;
   PtLim_bDeacManCluProtReg     = 0;
   PtLim_facTCaseExtAir         = 222;
   PtLim_facTCaseItAir          = 1629;
   PtLim_facTCluItAir           = 1141;
   PtLim_facTCoMesAirExt        = 4368;
   PtLim_facTEngItAir           = 825;
   PtLim_facTExtAirGear         = 1778;
   PtLim_facTGearItAir          = 1141;
   PtLim_facTWhlCluItAir        = 825;
   PtLim_facTqGearHiA_MP        = 6143;
   PtLim_facTqGearHiB_MP        = 20;
   PtLim_facTqGearHiC_MP        = 127;
   PtLim_facTqGearLoA_MP        = 6143;
   PtLim_facTqGearLoB_MP        = 20;
   PtLim_facTqGearLoC_MP        = 127;
   PtLim_facTqGearMidA_MP       = 6143;
   PtLim_facTqGearMidB_MP       = 20;
   PtLim_facTqGearMidC_MP       = 127;
   PtLim_nCkGrdFil_MP           = 0;
   PtLim_nDeltaPrimEngSpdHi     = 0;
   PtLim_nDeltaPrimEngSpdLo     = 0;
   PtLim_nDeltaPrimEngSpdMid    = 0;
   PtLim_nPrimShaftTheHi        = 0;
   PtLim_nPrimShaftTheLo        = 0;
   PtLim_nPrimShaftTheMid       = 0;
   PtLim_noCrtSelGear           = 1;
   PtLim_noGearHi               = 3;
   PtLim_noGearLo               = 1;
   PtLim_noGearMid              = 2;
   PtLim_noGearSel              = 0;
   PtLim_noProtManClu           = 0;
   PtLim_pwrDeltaCluSel         = 0;
   PtLim_pwrDeltaGearSel        = 0;
   PtLim_pwrDeltaWhlCluSel      = 0;
   PtLim_pwrHeatCluLo           = 0;
   PtLim_pwrHeatGearLo          = 0;
   PtLim_pwrHeatWhlCluLo        = 0;
   PtLim_stManClu               = 0;
   PtLim_tAirExtMes             = 273;
   PtLim_tCaseCluEstimGrd_MP    = 0;
   PtLim_tCluEstimGrd_MP        = 0;
   PtLim_tCoMes                 = 273;
   PtLim_tGearCluEstimGrd_MP    = 0;
   PtLim_tGrdDynCluT            = 0;
   PtLim_tItAirCluEstimGrd_MP   = 0;
   PtLim_tOfsCluFanProtHiT      = 0;
   PtLim_tOfsCluFanProtLoT      = 0;
   PtLim_tOfsCluNRegT           = 0;
   PtLim_tOfsCluStopWarnT       = 0;
   PtLim_tOilEstim              = 1092;
   PtLim_tWhlCluEstimGrd_MP     = 0;
   PtLim_tqManClu               = 0;
   PtLim_tqManCluCf             = 0;
   PtLim_wDeltaCluLoHi          = 0;
   PtLim_wDeltaCluLoMid         = 0;
   PtLim_wDeltaGearLoHi         = 0;
   PtLim_wDeltaGearLoMid        = 0;
   PtLim_wDeltaWhlCluLoHi       = 0;
   PtLim_wDeltaWhlCluLoMid      = 0;

   for (u8LocalIndex1 = 0;
        u8LocalIndex1 < 3;
        u8LocalIndex1++)
   {
      PtLim_prm_facRatePtToWhl_MP[u8LocalIndex1] = 0;
      PtLim_prm_pwrDeltaLoHi_MP[u8LocalIndex1]   = 0;
      PtLim_prm_pwrDeltaLoMid_MP[u8LocalIndex1]  = 0;
   }

   /*F03_03_07_Calculation_of_the_previous_temperatures */
   PROTMANCLU_vidCalculPrevTempInit();

   PtLim_tWhlCluEstim = (uint16)MATHSRV_udtCLAMP(PtLim_tWhlCluEstimPrev,
                                                 3568,
                                                 20368);
   PtLim_tCluEstim = (uint16)MATHSRV_udtCLAMP(PtLim_tCluEstimPrev,
                                              3568,
                                              20368);
   PtLim_tItAirCluEstim = (uint16)MATHSRV_udtCLAMP(PtLim_tItAirCluEstimPrev,
                                                   3568,
                                                   20368);
   PtLim_tCaseCluEstim =  (uint16)MATHSRV_udtCLAMP(PtLim_tCaseCluEstimPrev,
                                                   3568,
                                                   20368);
   PtLim_tGearCluEstim =  (uint16)MATHSRV_udtCLAMP(PtLim_tGearCluEstimPrev,
                                                   3568,
                                                   20368);

   /*Global variable's initialization*/
   PROTMANCLU_s32Filtre1Mem         = 0;
   PROTMANCLU_s32Filtre2Mem         = 0;
   PROTMANCLU_bOutHysNeg5           = 1;
   PROTMANCLU_bOutHysPos5           = 1;
   PROTMANCLU_u8OutMem1             = 0;
   PROTMANCLU_u8PtLim_stManCluPrev2 = 0;
   PROTMANCLU_u8PtLim_stManCluPrev  = 0;
   PROTMANCLU_bRstIntegrator        = 0;
   PROTMANCLU_bRstIntegratorPrev    = 0;
   PROTMANCLU_u8PtLim_noGearMid     = 0;
   PROTMANCLU_bOutHysPos            = 0;
   PROTMANCLU_bTurnOffDelayInPrev   = 0;
   PROTMANCLU_u16TurnOffDelayCount  = 0;
   PROTMANCLU_bOutHysPos1           = 0;
   PROTMANCLU_bOutHysPos2           = 0;
   PROTMANCLU_bOutHysPos3           = 0;
   PROTMANCLU_bOutHysPos4           = 0;
   PROTMANCLU_s16CoPt_tManCluPrev1  = 0;
   PROTMANCLU_s16CoPt_tManCluPrev2  = 0;
   PROTMANCLU_s16CoPt_tManCluPrev3  = 0;
   PROTMANCLU_s16CoPt_tManCluPrev4  = 0;
   PROTMANCLU_bBasculeRS            = 0;
   PROTMANCLU_u16SpdVehFanReq       = 0;
   PROTMANCLU_u8Ext_stGBxCfPrev     = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidClutch_Protection                            */
/* !Description :  This function contains  4 subsystems.                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PROTMANCLU_vidCalculPrevTempInit();                      */
/*  extf argret void PROTMANCLU_vidDeterStatesClutch();                       */
/*  extf argret void PROTMANCLU_vidDeterTripltGearbox();                      */
/*  extf argret void PROTMANCLU_vidEstimClutchTemper();                       */
/*  extf argret void PROTMANCLU_vidActivationProtect();                       */
/*  extf argret void PROTMANCLU_vidOutput_managment();                        */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 PROTMANCLU_u8Ext_stGBxCfPrev;                                 */
/*  input uint16 PtLim_tWhlCluEstimPrev;                                      */
/*  input uint16 PtLim_tCluEstimPrev;                                         */
/*  input uint16 PtLim_tItAirCluEstimPrev;                                    */
/*  input uint16 PtLim_tCaseCluEstimPrev;                                     */
/*  input uint16 PtLim_tGearCluEstimPrev;                                     */
/*  output uint8 PtLim_stManClu;                                              */
/*  output uint16 PtLim_tqManCluCf;                                           */
/*  output uint8 PtLim_noGearLo;                                              */
/*  output uint8 PtLim_noGearMid;                                             */
/*  output uint8 PtLim_noGearHi;                                              */
/*  output uint8 PtLim_noGearSel;                                             */
/*  output sint16 CoPt_tManCluEstimBfCord;                                    */
/*  output uint8 CoPt_rSpdFanReqProtCluBfCord;                                */
/*  output boolean CoPt_bWarnProtCluBfCord;                                   */
/*  output boolean CoPt_bAcvProtCluBfCord;                                    */
/*  output boolean CoPt_bDgoCluDmgAftsBfCord;                                 */
/*  output boolean CoPt_bMonRunCluDmgAftsBfCord;                              */
/*  output uint16 PtLim_tCoMes;                                               */
/*  output uint16 PtLim_tAirExtMes;                                           */
/*  output sint16 PtLim_nCkGrdFil_MP;                                         */
/*  output sint16 PtLim_tqManClu;                                             */
/*  output boolean PROTMANCLU_bOutHysNeg5;                                    */
/*  output boolean PROTMANCLU_bOutHysPos5;                                    */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev2;                            */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev;                             */
/*  output boolean PROTMANCLU_bRstIntegratorPrev;                             */
/*  output uint8 PROTMANCLU_u8OutMem1;                                        */
/*  output sint16 PtLim_wDeltaGearLoMid;                                      */
/*  output sint16 PtLim_wDeltaCluLoMid;                                       */
/*  output sint16 PtLim_wDeltaWhlCluLoMid;                                    */
/*  output sint16 PtLim_wDeltaWhlCluLoHi;                                     */
/*  output sint16 PtLim_wDeltaCluLoHi;                                        */
/*  output sint16 PtLim_wDeltaGearLoHi;                                       */
/*  output uint16 PtLim_tWhlCluEstim;                                         */
/*  output uint16 PtLim_tCluEstim;                                            */
/*  output uint16 PtLim_tItAirCluEstim;                                       */
/*  output uint16 PtLim_tCaseCluEstim;                                        */
/*  output uint16 PtLim_tGearCluEstim;                                        */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev1;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev2;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev3;                            */
/*  output sint16 PROTMANCLU_s16CoPt_tManCluPrev4;                            */
/*  output boolean PROTMANCLU_bTurnOffDelayInPrev;                            */
/*  output boolean PROTMANCLU_bOutHysPos1;                                    */
/*  output boolean PROTMANCLU_bOutHysPos2;                                    */
/*  output boolean PROTMANCLU_bOutHysPos3;                                    */
/*  output boolean PROTMANCLU_bOutHysPos4;                                    */
/*  output boolean PROTMANCLU_bOutHysPos;                                     */
/*  output boolean PROTMANCLU_bBasculeRS;                                     */
/*  output sint32 PROTMANCLU_s32Filtre1Mem;                                   */
/*  output sint32 PROTMANCLU_s32Filtre2Mem;                                   */
/*  output uint16 PROTMANCLU_u16TurnOffDelayCount;                            */
/*  output uint8 PROTMANCLU_u8Ext_stGBxCfPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidClutch_Protection(void)
{
   /*F0_Clutch_Protection */
   uint8 u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 0)
   {
      if (PROTMANCLU_u8Ext_stGBxCfPrev != 0)
      {
         /*Main blocks output initialisation*/
         PtLim_stManClu                   = 0;
         PtLim_tqManCluCf                 = 0;
         PtLim_noGearLo                   = 1;
         PtLim_noGearMid                  = 2;
         PtLim_noGearHi                   = 3;
         PtLim_noGearSel                  = 0;
         CoPt_tManCluEstimBfCord          = 320;
         CoPt_rSpdFanReqProtCluBfCord     = 0;
         CoPt_bWarnProtCluBfCord          = 0;
         CoPt_bAcvProtCluBfCord           = 0;
         CoPt_bDgoCluDmgAftsBfCord        = 0;
         CoPt_bMonRunCluDmgAftsBfCord     = 1;
         PtLim_tCoMes                     = 273;
         PtLim_tAirExtMes                 = 273;

         /*Dynamic block initialisation*/
         PtLim_nCkGrdFil_MP               = 0;
         PtLim_tqManClu                   = 0;
         PROTMANCLU_bOutHysNeg5           = 1;
         PROTMANCLU_bOutHysPos5           = 1;
         PROTMANCLU_u8PtLim_stManCluPrev2 = 0;
         PROTMANCLU_u8PtLim_stManCluPrev  = 0;
         PROTMANCLU_bRstIntegratorPrev    = 0;
         PROTMANCLU_u8OutMem1             = 0;
         PtLim_wDeltaGearLoMid            = 0;
         PtLim_wDeltaCluLoMid             = 0;
         PtLim_wDeltaWhlCluLoMid          = 0;
         PtLim_wDeltaWhlCluLoHi           = 0;
         PtLim_wDeltaCluLoHi              = 0;
         PtLim_wDeltaGearLoHi             = 0;
         /*F03_03_07_Calculation_of_the_previous_temperatures*/
         PROTMANCLU_vidCalculPrevTempInit();
         PtLim_tWhlCluEstim =
            (uint16)MATHSRV_udtCLAMP(PtLim_tWhlCluEstimPrev, 3568, 20368);
         PtLim_tCluEstim =
            (uint16)MATHSRV_udtCLAMP(PtLim_tCluEstimPrev, 3568, 20368);
         PtLim_tItAirCluEstim =
            (uint16)MATHSRV_udtCLAMP(PtLim_tItAirCluEstimPrev, 3568, 20368);
         PtLim_tCaseCluEstim =
            (uint16)MATHSRV_udtCLAMP(PtLim_tCaseCluEstimPrev, 3568, 20368);
         PtLim_tGearCluEstim =
            (uint16)MATHSRV_udtCLAMP(PtLim_tGearCluEstimPrev, 3568, 20368);
         PROTMANCLU_s16CoPt_tManCluPrev1  = 0;
         PROTMANCLU_s16CoPt_tManCluPrev2  = 0;
         PROTMANCLU_s16CoPt_tManCluPrev3  = 0;
         PROTMANCLU_s16CoPt_tManCluPrev4  = 0;
         PROTMANCLU_bTurnOffDelayInPrev   = 0;
         PROTMANCLU_bOutHysPos1           = 0;
         PROTMANCLU_bOutHysPos2           = 0;
         PROTMANCLU_bOutHysPos3           = 0;
         PROTMANCLU_bOutHysPos4           = 0;
         PROTMANCLU_bOutHysPos            = 0;
         PROTMANCLU_bBasculeRS            = 0;
         PROTMANCLU_s32Filtre1Mem         = 0;
         PROTMANCLU_s32Filtre2Mem         = 0;
         PROTMANCLU_u8OutMem1             = 0;
         PROTMANCLU_u16TurnOffDelayCount  = 0;
      }
      PROTMANCLU_vidDeterStatesClutch();
      PROTMANCLU_vidDeterTripltGearbox();
      PROTMANCLU_vidEstimClutchTemper();
      PROTMANCLU_vidActivationProtect();
   }
   PROTMANCLU_vidOutput_managment();
   PROTMANCLU_u8Ext_stGBxCfPrev = (uint8)MATHSRV_udtMIN(u8LocalExt_stGBxCf, 2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidDeterStatesClutch                            */
/* !Description :  This Function determines the different states of clutch and*/
/*                 it calculates the torque transmitted by the clutch.        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidEstimTorqTransClut();                      */
/*  extf argret void PROTMANCLU_vidDetermStateClutch();                       */
/*  extf argret void PROTMANCLU_vidReconfTorqTransClu();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidDeterStatesClutch(void)
{
   /*F01_Determination_of_states_of_clutch */
   PROTMANCLU_vidEstimTorqTransClut();
   PROTMANCLU_vidDetermStateClutch();
   PROTMANCLU_vidReconfTorqTransClu();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimTorqTransClut                           */
/* !Description :  This Function calculates the torque transmitted by the     */
/*                 clutch.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TreatTenms_nCkGrdFil;                                        */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*  input uint16 PtLim_tiFilEngSpd_C;                                         */
/*  input sint16 PtLim_nCkGrdFil_MP;                                          */
/*  input sint32 PROTMANCLU_s32Filtre1Mem;                                    */
/*  input uint8 PtLim_jCluEng_C;                                              */
/*  input uint16 PtLim_tiFilTqClu_C;                                          */
/*  input sint16 PtLim_tqManClu;                                              */
/*  input sint32 PROTMANCLU_s32Filtre2Mem;                                    */
/*  output sint16 PtLim_nCkGrdFil_MP;                                         */
/*  output sint32 PROTMANCLU_s32Filtre1Mem;                                   */
/*  output sint16 PtLim_tqManClu;                                             */
/*  output sint32 PROTMANCLU_s32Filtre2Mem;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimTorqTransClut(void)
{
   /*F01_01_Estimation_of_the_torque_transmitted_by_clutch */
   uint16 u16localGain;
   sint16 s16LocalTreatTenms_nCkGrdFil;
   sint16 s16LocalPtLim_nCkGrdFil_MP;
   sint16 s16LocalPtLim_tqManClu;
   sint16 s16LocalFilterIn;
   sint16 s16LocalTqSys_tqCkEngReal;
   uint32 u32LocalTF;
   sint32 s32LocalFilterIn;


   VEMS_vidGET(TreatTenms_nCkGrdFil, s16LocalTreatTenms_nCkGrdFil);
   VEMS_vidGET(TqSys_tqCkEngReal, s16LocalTqSys_tqCkEngReal);
      /* Filter1 */

   if (PtLim_tiFilEngSpd_C == 0)
   {
      PtLim_nCkGrdFil_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalTreatTenms_nCkGrdFil, -32000, 32000);
      PROTMANCLU_s32Filtre1Mem = (sint32)(PtLim_nCkGrdFil_MP * 65536);
   }
   else
   {
      u32LocalTF = (uint32)(PtLim_tiFilEngSpd_C * 125);
      u16localGain = (uint16)( (uint32)( PtLim_tiSdlManCluTEstim_SC
                                       * 1048576)
                             / ( ( PtLim_tiSdlManCluTEstim_SC
                                 * 16)
                               + u32LocalTF));
      s16LocalPtLim_nCkGrdFil_MP =
         MATHSRV_s16FirstOrderFilterGu16(u16localGain,
                                         &PROTMANCLU_s32Filtre1Mem,
                                         s16LocalTreatTenms_nCkGrdFil);
      PtLim_nCkGrdFil_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalPtLim_nCkGrdFil_MP, -32000, 32000);
   }
   /* Filter2 */

   s32LocalFilterIn =
      ( (sint32)( 32
                * s16LocalTqSys_tqCkEngReal)
      - (sint32)( PtLim_nCkGrdFil_MP
                * PtLim_jCluEng_C));
   if (s32LocalFilterIn < 0)
   {
      s32LocalFilterIn = (s32LocalFilterIn - 16) / 32;
   }
   else
   {
      s32LocalFilterIn = (s32LocalFilterIn + 16) / 32;
   }

   s16LocalFilterIn = (sint16)MATHSRV_udtCLAMP(s32LocalFilterIn, -32768, 32767);

   if (PtLim_tiFilTqClu_C == 0)
   {
      PtLim_tqManClu =
         (sint16)MATHSRV_udtCLAMP(s16LocalFilterIn, -32000, 32000);
      PROTMANCLU_s32Filtre2Mem = (sint32)(PtLim_tqManClu * 65536);
   }
   else
   {
      u32LocalTF = (uint32)(PtLim_tiFilTqClu_C * 125);
      u16localGain = (uint16)( (uint32)( PtLim_tiSdlManCluTEstim_SC
                                       * 1048576)
                             / ( ( PtLim_tiSdlManCluTEstim_SC
                                 * 16)
                               + u32LocalTF));
      s16LocalPtLim_tqManClu =
         MATHSRV_s16FirstOrderFilterGu16(u16localGain,
                                         &PROTMANCLU_s32Filtre2Mem,
                                         s16LocalFilterIn);
      PtLim_tqManClu =
         (sint16)MATHSRV_udtCLAMP(s16LocalPtLim_tqManClu, -32000, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidDetermStateClutch                            */
/* !Description :  This Function determines the different states of the       */
/*                 clutch.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 PROTMANCLU_u8PtLim_stManCluPrev;                              */
/*  input uint8 PtLim_stManClu;                                               */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input sint8 PtLim_tqCluTqThdPosHi_C;                                      */
/*  input sint16 PtLim_tqManClu;                                              */
/*  input sint8 PtLim_tqCluTqThdPosLo_C;                                      */
/*  input sint8 PtLim_tqCluTqThdNegLo_C;                                      */
/*  input sint8 PtLim_tqCluTqThdNegHi_C;                                      */
/*  input boolean PROTMANCLU_bOutHysPos5;                                     */
/*  input boolean PROTMANCLU_bOutHysNeg5;                                     */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev2;                            */
/*  output uint8 PROTMANCLU_u8PtLim_stManCluPrev;                             */
/*  output boolean PROTMANCLU_bOutHysNeg5;                                    */
/*  output boolean PROTMANCLU_bOutHysPos5;                                    */
/*  output uint8 PtLim_stManClu;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidDetermStateClutch(void)
{
   /*F01_02_Determination_of_states_of_clutch*/
   sint8  s8LocalCoPt_noEgdGearCordIt;
   sint16 s16LocalComp;


   /*F03_01_01_03_Calculation_of_delta_energy_between_LowEnergy_MiddleEnergy */
   PROTMANCLU_u8PtLim_stManCluPrev2 =
      (uint8)MATHSRV_udtMIN(PROTMANCLU_u8PtLim_stManCluPrev, 3);
   PROTMANCLU_u8PtLim_stManCluPrev = (uint8)MATHSRV_udtMIN(PtLim_stManClu, 3);

   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalCoPt_noEgdGearCordIt);

   /*HysterNeg*/
   s16LocalComp =(sint16)(PtLim_tqCluTqThdPosHi_C * 16);
   if (PtLim_tqManClu >= s16LocalComp)
   {
      PROTMANCLU_bOutHysNeg5 = 0;
   }
   else
   {
      s16LocalComp = (sint16)(PtLim_tqCluTqThdPosLo_C * 16);
      if (PtLim_tqManClu <= s16LocalComp)
      {
         PROTMANCLU_bOutHysNeg5 = 1;
      }
   }

   /*HysterPos*/
   s16LocalComp = (sint16)(PtLim_tqCluTqThdNegLo_C * 16);
   if (PtLim_tqManClu <= s16LocalComp)
   {
      PROTMANCLU_bOutHysPos5 = 0;
   }
   else
   {
      s16LocalComp = (sint16)(PtLim_tqCluTqThdNegHi_C * 16);
      if (PtLim_tqManClu >= s16LocalComp)
      {
         PROTMANCLU_bOutHysPos5 = 1;
      }
   }

   if (s8LocalCoPt_noEgdGearCordIt != 0)
   {
      PtLim_stManClu = 2;
   }
   else
   {
      if (  (PROTMANCLU_bOutHysPos5 == 0)
         || (PROTMANCLU_bOutHysNeg5 == 0))
      {
         PtLim_stManClu = 3;
      }
      else
      {
         PtLim_stManClu = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidReconfTorqTransClu                           */
/* !Description :  This Function  reconfigures the torque transmitted by the  */
/*                 clutch.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 PtLim_stManClu;                                               */
/*  input sint16 PtLim_tqManClu;                                              */
/*  output uint16 PtLim_tqManCluCf;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidReconfTorqTransClu(void)
{
   /* F01_03_Reconfiguration_of_the_torque_transmitted_by_clutch */
   uint8  u8LocalCoPTSt_stEng;
   uint16 u16LocalPtLim_tqManCluCf;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   if (  (u8LocalCoPTSt_stEng != 5)
      || (PtLim_stManClu != 3))
   {
      PtLim_tqManCluCf =0;
   }
   else
   {
      u16LocalPtLim_tqManCluCf = (uint16)MATHSRV_udtABS(PtLim_tqManClu);
      PtLim_tqManCluCf =
         (uint16)MATHSRV_udtMIN(u16LocalPtLim_tqManCluCf, 32000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidDeterTripltGearbox                           */
/* !Description :  This Function defines three gearbox ratios which are       */
/*                 susceptible to be engaged.                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 PtLim_stManClu;                                               */
/*  input boolean CoPt_bRvsCord;                                              */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 PtLim_spdVehRng_A[3];                                         */
/*  input uint8 PtLim_noGearSel_T[3];                                         */
/*  input uint8 PROTMANCLU_u8OutMem1;                                         */
/*  input uint8 PtLim_noGearSelLo_A[3];                                       */
/*  input uint8 PtLim_noGearLo_T[3];                                          */
/*  input uint8 PtLim_noGearSelMid_A[3];                                      */
/*  input uint8 PtLim_noGearMid_T[3];                                         */
/*  input uint8 PtLim_noGearSelHi_A[3];                                       */
/*  input uint8 PtLim_noGearHi_T[3];                                          */
/*  output uint8 PROTMANCLU_u8OutMem1;                                        */
/*  output uint8 PtLim_noGearSel;                                             */
/*  output uint8 PtLim_noGearLo;                                              */
/*  output uint8 PtLim_noGearMid;                                             */
/*  output uint8 PtLim_noGearHi;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidDeterTripltGearbox(void)
{
   /*F02_Determination_of_a_triplet_of_gearbox_ratio */
   boolean bLocalCoPt_bRvsCord;
   uint8   u8localInterp1d;
   uint8   u8LocalVeh_spdVeh;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalCalcParaX;


   if (PtLim_stManClu != 3)
   {
      VEMS_vidGET(CoPt_bRvsCord, bLocalCoPt_bRvsCord);
      if (bLocalCoPt_bRvsCord != 0)
      {
         PROTMANCLU_u8OutMem1 = 0;
      }
      else
      {
         VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
         u16LocalVeh_spdVeh = (uint16)((u16LocalVeh_spdVeh + 64) / 128);
         u8LocalVeh_spdVeh = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 255);
         u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_spdVehRng_A,
                                                         u8LocalVeh_spdVeh,
                                                         3);
         PROTMANCLU_u8OutMem1 =
            MATHSRV_u8Interp1d(PtLim_noGearSel_T, u16LocalCalcParaX);
      }
   }

   PtLim_noGearSel = (uint8)MATHSRV_udtMIN(PROTMANCLU_u8OutMem1, 2);
   /* Interp1*/
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearSelLo_A,
                                                   PROTMANCLU_u8OutMem1,
                                                   3);
   u8localInterp1d =
      MATHSRV_u8Interp1d(PtLim_noGearLo_T, u16LocalCalcParaX);
   PtLim_noGearLo = (uint8)MATHSRV_udtMIN(u8localInterp1d, 6);
   /* Interp2*/

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearSelMid_A,
                                                   PROTMANCLU_u8OutMem1,
                                                   3);
   u8localInterp1d = MATHSRV_u8Interp1d(PtLim_noGearMid_T, u16LocalCalcParaX);
   PtLim_noGearMid = (uint8)MATHSRV_udtMIN(u8localInterp1d, 6);
   /* Interp3*/

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(PtLim_noGearSelHi_A,
                                                   PROTMANCLU_u8OutMem1,
                                                   3);
   u8localInterp1d = MATHSRV_u8Interp1d(PtLim_noGearHi_T, u16LocalCalcParaX);
   PtLim_noGearHi = (uint8)MATHSRV_udtMIN(u8localInterp1d, 6);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimClutchTemper                            */
/* !Description :  This Function calculates the temperature of clutch friction*/
/*                 pad .                                                      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidEstimHeatArdClutch();                      */
/*  extf argret void PROTMANCLU_vidSelectEnergyInject();                      */
/*  extf argret void PROTMANCLU_vidEstimClutchTemp();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimClutchTemper(void)
{
   /*F03_Estimation_of_the_clutch_facing_temperature */
   PROTMANCLU_vidEstimHeatArdClutch();
   PROTMANCLU_vidSelectEnergyInject();
   PROTMANCLU_vidEstimClutchTemp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimHeatArdClutch                           */
/* !Description :  This Function calculates the heat around the clutch.       */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidEstimDissipatEnerg();                      */
/*  extf argret void PROTMANCLU_vidCalcCoefConvHeatex();                      */
/*  extf argret void PROTMANCLU_vidConvTemperToKelvin();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimHeatArdClutch(void)
{
   /*F03_01_Estimation_of_heat_around_the_clutch */
   PROTMANCLU_vidEstimDissipatEnerg();
   PROTMANCLU_vidCalcCoefConvHeatex();
   PROTMANCLU_vidConvTemperToKelvin();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTMANCLU_vidEstimDissipatEnerg                           */
/* !Description :  This function  calculates the heat around the clutch.it    */
/*                 calculates the dissipated energies and the coefficients of */
/*                 convective heat transfers and converts the temperatures to */
/*                 Kelvin unit.                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04687_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTMANCLU_vidCalDelEngPrimshaft();                      */
/*  extf argret void PROTMANCLU_vidCalcDisPowerLowRat();                      */
/*  extf argret void PROTMANCLU_vidCalcDelLowMidEnrgy();                      */
/*  extf argret void PROTMANCLU_vidCalcDelLowHighEngy();                      */
/*  input uint8 PtLim_stManClu;                                               */
/*  input uint8 PROTMANCLU_u8PtLim_stManCluPrev2;                             */
/*  input uint8 PROTMANCLU_u8PtLim_stManCluPrev;                              */
/*  input boolean PROTMANCLU_bRstIntegrator;                                  */
/*  input boolean PROTMANCLU_bRstIntegratorPrev;                              */
/*  input sint16 PtLim_wDeltaWhlCluLoMid;                                     */
/*  input sint16 PtLim_prm_pwrDeltaLoMid_MP[3];                               */
/*  input sint16 PtLim_wDeltaCluLoMid;                                        */
/*  input sint16 PtLim_wDeltaGearLoMid;                                       */
/*  input sint16 PtLim_wDeltaWhlCluLoHi;                                      */
/*  input sint16 PtLim_prm_pwrDeltaLoHi_MP[3];                                */
/*  input sint16 PtLim_wDeltaCluLoHi;                                         */
/*  input sint16 PtLim_wDeltaGearLoHi;                                        */
/*  output boolean PROTMANCLU_bRstIntegrator;                                 */
/*  output sint16 PtLim_wDeltaWhlCluLoMid;                                    */
/*  output sint16 PtLim_wDeltaCluLoMid;                                       */
/*  output sint16 PtLim_wDeltaGearLoMid;                                      */
/*  output sint16 PtLim_wDeltaWhlCluLoHi;                                     */
/*  output sint16 PtLim_wDeltaCluLoHi;                                        */
/*  output sint16 PtLim_wDeltaGearLoHi;                                       */
/*  output boolean PROTMANCLU_bRstIntegratorPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTMANCLU_vidEstimDissipatEnerg(void)
{
   /*  F03_01_01_Estimation_of_the_dissipated_energies */
   sint32 s32LocalPwrDeltaLoHi0;
   sint32 s32LocalPwrDeltaLoHi1;
   sint32 s32LocalPwrDeltaLoHi2;
   sint32 s32LocalPwrDeltaLoMid0;
   sint32 s32LocalPwrDeltaLoMid1;
   sint32 s32LocalPwrDeltaLoMid2;


   PROTMANCLU_vidCalDelEngPrimshaft();
   PROTMANCLU_vidCalcDisPowerLowRat();
   if (  (PtLim_stManClu == 1)
      || (  (PROTMANCLU_u8PtLim_stManCluPrev2 != 2)
         && (PROTMANCLU_u8PtLim_stManCluPrev == 2)))
   {
      PROTMANCLU_bRstIntegrator = 1;
   }
   else
   {
      PROTMANCLU_bRstIntegrator = 0;
   }
   PROTMANCLU_vidCalcDelLowMidEnrgy();

   /*F03_01_01_03_Calculation_of_delta_energy_between_LowEnergy_MiddleEnergy  */
   if (  (PROTMANCLU_bRstIntegrator != 0)
      && (PROTMANCLU_bRstIntegratorPrev == 0))
   {
      PtLim_wDeltaWhlCluLoMid = 0;
      PtLim_wDeltaCluLoMid    = 0;
      PtLim_wDeltaGearLoMid   = 0;
   }
   else
   {
      s32LocalPwrDeltaLoMid0 = ( (sint32)( PtLim_wDeltaWhlCluLoMid
                                         * 1000)
                               + (sint32)( PtLim_prm_pwrDeltaLoMid_MP[0]
                                         * PtLim_tiSdlManCluTEstim_SC));
      if (s32LocalPwrDeltaLoMid0 < (sint32)0)
      {
         s32LocalPwrDeltaLoMid0 = (s32LocalPwrDeltaLoMid0 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoMid0 = (s32LocalPwrDeltaLoMid0 + 500) / (sint32)1000;
      }

      s32LocalPwrDeltaLoMid1 = ( (sint32)( PtLim_wDeltaCluLoMid
                                         * 1000)
                               + (sint32)( PtLim_prm_pwrDeltaLoMid_MP[1]
                                         * PtLim_tiSdlManCluTEstim_SC));

      if (s32LocalPwrDeltaLoMid1 < (sint32)0)
      {
         s32LocalPwrDeltaLoMid1 = (s32LocalPwrDeltaLoMid1 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoMid1 = (s32LocalPwrDeltaLoMid1 + 500) / (sint32)1000;
      }

      s32LocalPwrDeltaLoMid2 = ( (sint32)( PtLim_wDeltaGearLoMid * 1000)
                               + (sint32)( PtLim_prm_pwrDeltaLoMid_MP[2]
                                         * PtLim_tiSdlManCluTEstim_SC));

      if (s32LocalPwrDeltaLoMid2 < (sint32)0)
      {
         s32LocalPwrDeltaLoMid2 = (s32LocalPwrDeltaLoMid2 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoMid2 = (s32LocalPwrDeltaLoMid2 + 500) / (sint32)1000;
      }

      PtLim_wDeltaWhlCluLoMid =
         (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid0, -32768, 32767);
      PtLim_wDeltaCluLoMid =
         (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid1, -32768, 32767);
      PtLim_wDeltaGearLoMid =
        (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoMid2, -32768, 32767);
   }
   PROTMANCLU_vidCalcDelLowHighEngy();

   /*F03_01_01_04_Calculation_of_delta_energy_between_LowEnergy_HighEnergy    */

   if (  (PROTMANCLU_bRstIntegrator != 0)
      && (PROTMANCLU_bRstIntegratorPrev == 0))
   {
      PtLim_wDeltaWhlCluLoHi = 0;
      PtLim_wDeltaCluLoHi    = 0;
      PtLim_wDeltaGearLoHi   = 0;
   }
   else
   {
      s32LocalPwrDeltaLoHi0 = ( (sint32)( PtLim_wDeltaWhlCluLoHi
                                        * 1000)
                              + (sint32)( PtLim_prm_pwrDeltaLoHi_MP[0]
                                        * PtLim_tiSdlManCluTEstim_SC));
      if (s32LocalPwrDeltaLoHi0 < 0)
      {
         s32LocalPwrDeltaLoHi0 = (s32LocalPwrDeltaLoHi0 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoHi0 = (s32LocalPwrDeltaLoHi0 + 500) / (sint32)1000;
      }

      s32LocalPwrDeltaLoHi1 = ( (sint32)(PtLim_wDeltaCluLoHi
                                        * 1000)
                              + (sint32)( PtLim_prm_pwrDeltaLoHi_MP[1]
                                        * PtLim_tiSdlManCluTEstim_SC));
      if (s32LocalPwrDeltaLoHi1 < (sint32)0)
      {
         s32LocalPwrDeltaLoHi1 = (s32LocalPwrDeltaLoHi1 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoHi1 = (s32LocalPwrDeltaLoHi1 + 500) / (sint32)1000;
      }

      s32LocalPwrDeltaLoHi2 = ( (sint32)( PtLim_wDeltaGearLoHi
                                         * 1000)
                              + (sint32)( PtLim_prm_pwrDeltaLoHi_MP[2]
                                        * PtLim_tiSdlManCluTEstim_SC));
      if (s32LocalPwrDeltaLoHi2 < (sint32)0)
      {
         s32LocalPwrDeltaLoHi2 = (s32LocalPwrDeltaLoHi2 - 500) / (sint32)1000;
      }
      else
      {
         s32LocalPwrDeltaLoHi2 = (s32LocalPwrDeltaLoHi2 + 500) / (sint32)1000;
      }
      PtLim_wDeltaWhlCluLoHi =
         (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi0, -32768, 32767);
      PtLim_wDeltaCluLoHi =
         (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi1, -32768, 32767);
      PtLim_wDeltaGearLoHi =
        (sint16)MATHSRV_udtCLAMP(s32LocalPwrDeltaLoHi2, -32768, 32767);
   }
   /*condition of reset of the integrator*/
   PROTMANCLU_bRstIntegratorPrev = PROTMANCLU_bRstIntegrator;
}

/*---------------------------------End Of File--------------------------------*/