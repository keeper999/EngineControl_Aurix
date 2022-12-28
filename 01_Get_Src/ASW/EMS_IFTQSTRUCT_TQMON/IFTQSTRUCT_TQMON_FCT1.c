/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFTQSTRUCT_TQMON                                        */
/* !Description     : IFTQSTRUCT_TQMON Component                              */
/*                                                                            */
/* !Module          : IFTQSTRUCT_TQMON                                        */
/* !Description     : Safety TMS : Interface TMS                              */
/*                                                                            */
/* !File            : IFTQSTRUCT_TQMON_FCT1.C                                 */
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
/*   1 / IFTQSTRUCT_TQMON_vidInitOutput                                       */
/*   2 / IFTQSTRUCT_TQMON_vidInitOutputBis                                    */
/*   3 / IFTQSTRUCT_TQMON_vidGerCprInject                                     */
/*   4 / IFTQSTRUCT_TQMON_vidGenerInf10ms                                     */
/*   5 / IFTQSTRUCT_TQMON_vidFluxInternes                                     */
/*   6 / IFTQSTRUCT_TQMON_vidGenerInf40ms                                     */
/*   7 / IFTQSTRUCT_TQMON_vidGeInf40msBis                                     */
/*   8 / IFTQSTRUCT_TQMON_vidGeInf40m2Bis                                     */
/*   9 / IFTQSTRUCT_TQMON_vidGeInf40m3Bis                                     */
/*   10 / IFTQSTRUCT_TQMON_vidGeInf40m4Bis                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5050415 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2536 / 2.11 br1                                 */
/* !OtherRefs   : VEMS V02 ECU#058176                                         */
/* !OtherRefs   : VEMS V02 ECU#059384                                         */
/* !OtherRefs   : VEMS V02 ECU#060678                                         */
/* !OtherRefs   : VEMS V02 ECU#065782                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFTQSTRUCT_TQMON/IFTQS$*/
/* $Revision::   1.29     $$Author::   mbenfrad       $$Date::   15 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IFTQSTRUCT_TQMON.h"
#include "IFTQSTRUCT_TQMON_L.h"
#include "IFTQSTRUCT_TQMON_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidInitOutput                             */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input uint16 IFTQSTRUCT_TQMON_u16FilterOut;                               */
/*  output boolean SftyMgt_bAcvIdlCll;                                        */
/*  output boolean SftyMgt_bATParkNeutExt;                                    */
/*  output boolean SftyMgt_bIniIdlCtlIdlSys;                                  */
/*  output uint16 SftyMgt_nTarIdlSftyTqSys;                                   */
/*  output uint16 SftyMgt_nTarIdlATTqSys;                                     */
/*  output uint16 SftyMgt_nTarIdlStrtTqSys;                                   */
/*  output boolean SftyMgt_bDeacAOS;                                          */
/*  output boolean SftyMgt_bDeceAcvCll;                                       */
/*  output boolean SftyMgt_bEnaTqOfsSfty;                                     */
/*  output boolean SftyMgt_bEngSpdLimHiIntvFRM;                               */
/*  output boolean SftyMgt_bEngSpdLimLoIntvFRM;                               */
/*  output boolean SftyMgt_bInhCnvLossMdl_FRM;                                */
/*  output boolean SftyMgt_bAcvDrvTraInvldFRM;                                */
/*  output boolean SftyMgt_bInhNRegTakeOffFRM;                                */
/*  output boolean SftyMgt_bAcvNRegTakeOffTqDem;                              */
/*  output boolean SftyMgt_bInhStgPmpLoss_FRM;                                */
/*  output boolean SftyMgt_bTakeOffCoPt;                                      */
/*  output boolean SftyMgt_bTqGrdLimBuf;                                      */
/*  output uint16 SftyMgt_nCkFil;                                             */
/*  output uint16 SftyMgt_nCkFilBuf;                                          */
/*  output uint16 SftyMgt_nOfsIdlTakeOff;                                     */
/*  output uint16 SftyMgt_nTarIdl;                                            */
/*  output uint16 SftyMgt_nTarIdlUnChkBuf;                                    */
/*  output uint8 SftyMgt_noAcvCyl;                                            */
/*  output boolean SftyMgt_bDgoSftyORngAMCoPTSt;                              */
/*  output uint16 SftyMgt_nTarIdlDynIdlSys;                                   */
/*  output boolean SftyMgt_bEngStrtReq;                                       */
/*  output boolean SftyMgt_bFuCutOffReqTqSys;                                 */
/*  output boolean SftyMgt_bDgoSftyORngATCoPTSt;                              */
/*  output boolean SftyMgt_bDrvTraAMTExt;                                     */
/*  output uint8 SftyMgt_noEgdGearCordCoPt;                                   */
/*  output boolean SftyMgt_bInhAntiDBFRM;                                     */
/*  output boolean SftyMgt_bInhRvTqDemTakeOffFRM;                             */
/*  output boolean SftyMgt_bInhTqCllFRM;                                      */
/*  output boolean SftyMgt_bModSptTqDem;                                      */
/*  output uint16 SftyMgt_rDrivTakeOffTqDem;                                  */
/*  output boolean SftyMgt_bOpTra;                                            */
/*  output uint16 SftyMgt_spdVehBuf;                                          */
/*  output uint8 SftyMgt_stClu;                                               */
/*  output boolean SftyMgt_bSTTCf;                                            */
/*  output sint16 SftyMgt_tqAirReqGBxCoPt;                                    */
/*  output boolean SftyMgt_bStaAuthStaCtl;                                    */
/*  output sint8 SftyMgt_noEgdGearSfty;                                       */
/*  output uint8 SftyMgt_noGearCord;                                          */
/*  output boolean SftyMgt_bTqSysAcvTqSys;                                    */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDriFilPrev;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev1;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev2;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev3;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev4;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev;                             */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev1;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev2;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev3;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev4;                            */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev;                           */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev1;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev2;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev3;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev4;                          */
/*  output uint16 IFTQSTRUCT_TQMON_u16FilterOut;                              */
/*  output uint32 IFTQSTRUCT_TQMON_u32nEngFiltMem;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr;                            */
/*  output sint16 SftyMgt_tqEfcNRegTakeOffNorm;                               */
/*  output sint16 SftyMgt_tqEfcNRegTakeOffEco;                                */
/*  output boolean SftyMgt_bEnaPresOffsSfty;                                  */
/*  output uint16 SftyMgt_pAirExtMesCorUsThrM;                                */
/*  output uint16 SftyMgt_pAirExtMesSI;                                       */
/*  output sint16 SftyMgt_tqIdcEngCurMaxEngLim;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidInitOutput(void)
{
   uint16 u16LocalSftyMgt_nEng;


   VEMS_vidSET(SftyMgt_bAcvIdlCll, 0);
   VEMS_vidSET(SftyMgt_bATParkNeutExt, 0);
   VEMS_vidSET(SftyMgt_bIniIdlCtlIdlSys, 0);
   VEMS_vidSET(SftyMgt_nTarIdlSftyTqSys, 0);
   VEMS_vidSET(SftyMgt_nTarIdlATTqSys, 0);
   VEMS_vidSET(SftyMgt_nTarIdlStrtTqSys, 0);
   VEMS_vidSET(SftyMgt_bDeacAOS, 0);
   VEMS_vidSET(SftyMgt_bDeceAcvCll, 0);
   VEMS_vidSET(SftyMgt_bEnaTqOfsSfty, 0);
   VEMS_vidSET(SftyMgt_bEngSpdLimHiIntvFRM, 0);
   VEMS_vidSET(SftyMgt_bEngSpdLimLoIntvFRM, 0);
   VEMS_vidSET(SftyMgt_bInhCnvLossMdl_FRM, 0);
   VEMS_vidSET(SftyMgt_bAcvDrvTraInvldFRM, 0);
   VEMS_vidSET(SftyMgt_bInhNRegTakeOffFRM, 0);
   VEMS_vidSET(SftyMgt_bAcvNRegTakeOffTqDem, 0);
   VEMS_vidSET(SftyMgt_bInhStgPmpLoss_FRM, 0);
   VEMS_vidSET(SftyMgt_bTakeOffCoPt, 0);
   VEMS_vidSET(SftyMgt_bTqGrdLimBuf, 0);
   VEMS_vidSET(SftyMgt_nCkFil, 0);
   VEMS_vidSET(SftyMgt_nCkFilBuf, 0);
   VEMS_vidSET(SftyMgt_nOfsIdlTakeOff, 0);
   VEMS_vidSET(SftyMgt_nTarIdl, 3000);
   VEMS_vidSET(SftyMgt_nTarIdlUnChkBuf, 3000);
   VEMS_vidSET(SftyMgt_noAcvCyl, 3);
   VEMS_vidSET(SftyMgt_bDgoSftyORngAMCoPTSt, 0);
   VEMS_vidSET(SftyMgt_nTarIdlDynIdlSys, 0);
   VEMS_vidSET(SftyMgt_bEngStrtReq, 0);
   VEMS_vidSET(SftyMgt_bFuCutOffReqTqSys, 0);
   VEMS_vidSET(SftyMgt_bDgoSftyORngATCoPTSt, 0);
   VEMS_vidSET(SftyMgt_bDrvTraAMTExt, 0);
   VEMS_vidSET(SftyMgt_noEgdGearCordCoPt, 0);
   VEMS_vidSET(SftyMgt_bInhAntiDBFRM, 0);
   VEMS_vidSET(SftyMgt_bInhRvTqDemTakeOffFRM, 0);
   VEMS_vidSET(SftyMgt_bInhTqCllFRM, 0);
   VEMS_vidSET(SftyMgt_bModSptTqDem, 0);
   VEMS_vidSET(SftyMgt_rDrivTakeOffTqDem, 0);
   VEMS_vidSET(SftyMgt_bOpTra, 0);
   VEMS_vidSET(SftyMgt_spdVehBuf, 0);
   VEMS_vidSET(SftyMgt_stClu, 1);
   VEMS_vidSET(SftyMgt_bSTTCf, 0);
   VEMS_vidSET(SftyMgt_tqAirReqGBxCoPt, 0);
   VEMS_vidSET(SftyMgt_bStaAuthStaCtl, 0);
   VEMS_vidSET(SftyMgt_noEgdGearSfty, 0);
   VEMS_vidSET(SftyMgt_noGearCord, 0);
   VEMS_vidSET(SftyMgt_bTqSysAcvTqSys, 0);
   IFTQSTRUCT_TQMON_u8CorDriFilPrev = 0;
   IFTQSTRUCT_TQMON_u8CorDrFilPrev1 = 0;
   IFTQSTRUCT_TQMON_u8CorDrFilPrev2 = 0;
   IFTQSTRUCT_TQMON_u8CorDrFilPrev3 = 0;
   IFTQSTRUCT_TQMON_u8CorDrFilPrev4 = 0;
   IFTQSTRUCT_TQMON_bDeceAcvPrev = 0;
   IFTQSTRUCT_TQMON_bDeceAcvPrev1 = 0;
   IFTQSTRUCT_TQMON_bDeceAcvPrev2 = 0;
   IFTQSTRUCT_TQMON_bDeceAcvPrev3 = 0;
   IFTQSTRUCT_TQMON_bDeceAcvPrev4 = 0;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev = 0;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev1 = 0;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev2 = 0;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev3 = 0;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev4 = 0;
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   IFTQSTRUCT_TQMON_u16FilterOut =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_nEng, 8000);
   IFTQSTRUCT_TQMON_u32nEngFiltMem =
      (uint32)(IFTQSTRUCT_TQMON_u16FilterOut * 256);
   IFTQSTRUCT_TQMON_u8TiDlyEgdGrCtr = 0;
   IFTQSTRUCT_TQMON_u8TiDlyTqSysCtr = 0;
   VEMS_vidSET(SftyMgt_tqEfcNRegTakeOffNorm, 0);
   VEMS_vidSET(SftyMgt_tqEfcNRegTakeOffEco, 0);
   VEMS_vidSET(SftyMgt_bEnaPresOffsSfty, 0);
   VEMS_vidSET(SftyMgt_pAirExtMesCorUsThrM, 0);
   VEMS_vidSET(SftyMgt_pAirExtMesSI, 0);
   VEMS_vidSET(SftyMgt_tqIdcEngCurMaxEngLim, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidInitOutputBis                          */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint16 SftyMgt_pDsThrCor;                                          */
/*  output uint16 SftyMgt_pwrAC5Loss;                                         */
/*  output uint8 SftyMgt_stDrvTraCoPTSt;                                      */
/*  output uint16 SftyMgt_tqACLossUnChkBuf;                                   */
/*  output sint16 SftyMgt_tqAltLossUnChkBuf;                                  */
/*  output sint16 SftyMgt_tqCkEfcMaxVSCtl;                                    */
/*  output sint16 SftyMgt_tqCkEfcMinVSCtl;                                    */
/*  output sint16 SftyMgt_tqCkEngLossAdpUnChkBuf;                             */
/*  output uint16 SftyMgt_tqCkEngLossUnChkBuf;                                */
/*  output uint16 SftyMgt_tqCkPmpHiPUnChkBuf;                                 */
/*  output uint16 SftyMgt_tqCnvLossUnChkBuf;                                  */
/*  output uint16 SftyMgt_rAccPSptModTqDem;                                   */
/*  output sint16 SftyMgt_tqEfcReqCoChaUnChkBuf;                              */
/*  output uint16 SftyMgt_tqFanStrtLossUnChkBuf;                              */
/*  output sint16 SftyMgt_tqIdcIdl;                                           */
/*  output sint16 SftyMgt_tqIdcRedEngLim;                                     */
/*  output sint16 SftyMgt_tqIdcSysEngLim;                                     */
/*  output sint16 SftyMgt_tqLimEM;                                            */
/*  output sint16 SftyMgt_tqMaxRes;                                           */
/*  output uint16 SftyMgt_tqStgPmpLossUnChkBuf;                               */
/*  output sint16 SftyMgt_tqSumLossCmp;                                       */
/*  output sint16 SftyMgt_tqSumLossCmpUnChkBuf;                               */
/*  output uint16 SftyMgt_tqAuxLossTqCmp;                                     */
/*  output boolean SftyMgt_bDgoSIPORngCoPt;                                   */
/*  output boolean SftyMgt_bInhCoPtSIPFRM;                                    */
/*  output boolean SftyMgt_bInhCoStrtRStrt;                                   */
/*  output uint8 SftyMgt_stTqPTMinCtlVSCtl;                                   */
/*  output boolean SftyMgt_bSIPCoPt;                                          */
/*  output boolean SftyMgt_bStaReq;                                           */
/*  output sint16 SftyMgt_tqCkDrivFilEngLim;                                  */
/*  output sint16 SftyMgt_tqIdcNReg;                                          */
/*  output sint16 SftyMgt_tqGBx;                                              */
/*  output boolean SftyMgt_bAcvCllUnChk;                                      */
/*  output sint16 SftyMgt_tqCkAntiOscCor;                                     */
/*  output sint16 SftyMgt_tqCkEfcFil;                                         */
/*  output sint16 SftyMgt_tqCkEfcFilTqSys;                                    */
/*  output sint16 SftyMgt_tqCkEfcTqDem;                                       */
/*  output sint16 SftyMgt_tqCkEfcWoutAntiDBTqDem;                             */
/*  output sint16 SftyMgt_tqDrvRawCoPt;                                       */
/*  output sint16 SftyMgt_tqEfcDifLrnOutDZone;                                */
/*  output sint16 SftyMgt_tqEfcReqCoChaChk;                                   */
/*  output sint16 SftyMgt_tqIdcAirReqTqSys;                                   */
/*  output sint16 SftyMgt_tqIdcReqCordNRegReq;                                */
/*  output sint16 SftyMgt_tqReqGBxCoPt;                                       */
/*  output boolean SftyMgt_bAcvCllTqCll;                                      */
/*  output boolean SftyMgt_bAcvAutoInj;                                       */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev;                              */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev1;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev2;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev3;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev4;                             */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev;                            */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev1;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev2;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev3;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev4;                           */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev;                              */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev1;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev2;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev3;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev4;                             */
/*  output uint16 SftyMgt_spd1000RatCf_MP;                                    */
/*  output sint16 SftyMgt_prm_tqLimEM[5];                                     */
/*  output sint8 SftyMgt_prm_noTarGearTra[5];                                 */
/*  output uint8 SftyMgt_prm_noGearCordDrivFil[5];                            */
/*  output uint16 SftyMgt_prm_nCkFil[5];                                      */
/*  output boolean SftyMgt_prm_bDeceAcvTqSys[5];                              */
/*  output boolean SftyMgt_prm_bNRegReq[5];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidInitOutputBis(void)
{
   uint8  u8LocalIndex;


   VEMS_vidSET(SftyMgt_pDsThrCor, 12500);
   VEMS_vidSET(SftyMgt_pwrAC5Loss, 0);
   VEMS_vidSET(SftyMgt_stDrvTraCoPTSt, 0);
   VEMS_vidSET(SftyMgt_tqACLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqAltLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcMaxVSCtl, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcMinVSCtl, -32000);
   VEMS_vidSET(SftyMgt_tqCkEngLossAdpUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqCkEngLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqCkPmpHiPUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqCnvLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_rAccPSptModTqDem, 0);
   VEMS_vidSET(SftyMgt_tqEfcReqCoChaUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqFanStrtLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqIdcIdl, 0);
   VEMS_vidSET(SftyMgt_tqIdcRedEngLim, 0);
   VEMS_vidSET(SftyMgt_tqIdcSysEngLim, 0);
   VEMS_vidSET(SftyMgt_tqLimEM, 0);
   VEMS_vidSET(SftyMgt_tqMaxRes, 0);
   VEMS_vidSET(SftyMgt_tqStgPmpLossUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqSumLossCmp, 0);
   VEMS_vidSET(SftyMgt_tqSumLossCmpUnChkBuf, 0);
   VEMS_vidSET(SftyMgt_tqAuxLossTqCmp, 0);
   VEMS_vidSET(SftyMgt_bDgoSIPORngCoPt, 0);
   VEMS_vidSET(SftyMgt_bInhCoPtSIPFRM, 0);
   VEMS_vidSET(SftyMgt_bInhCoStrtRStrt, 0);
   VEMS_vidSET(SftyMgt_stTqPTMinCtlVSCtl, 0);
   VEMS_vidSET(SftyMgt_bSIPCoPt, 0);
   VEMS_vidSET(SftyMgt_bStaReq, 1);
   VEMS_vidSET(SftyMgt_tqCkDrivFilEngLim, 0);
   VEMS_vidSET(SftyMgt_tqIdcNReg, 0);
   VEMS_vidSET(SftyMgt_tqGBx, 0);
   VEMS_vidSET(SftyMgt_bAcvCllUnChk, 0);
   VEMS_vidSET(SftyMgt_tqCkAntiOscCor, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcFil, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcFilTqSys, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcTqDem, 0);
   VEMS_vidSET(SftyMgt_tqCkEfcWoutAntiDBTqDem, 0);
   VEMS_vidSET(SftyMgt_tqDrvRawCoPt, 0);
   VEMS_vidSET(SftyMgt_tqEfcDifLrnOutDZone, 0);
   VEMS_vidSET(SftyMgt_tqEfcReqCoChaChk, 0);
   VEMS_vidSET(SftyMgt_tqIdcAirReqTqSys, 0);
   VEMS_vidSET(SftyMgt_tqIdcReqCordNRegReq, 0);
   VEMS_vidSET(SftyMgt_tqReqGBxCoPt, 0);
   VEMS_vidSET(SftyMgt_bAcvCllTqCll, 0);
   VEMS_vidSET(SftyMgt_bAcvAutoInj, 0);
   IFTQSTRUCT_TQMON_s8TarGearPrev = 0;
   IFTQSTRUCT_TQMON_s8TarGearPrev1 = 0;
   IFTQSTRUCT_TQMON_s8TarGearPrev2 = 0;
   IFTQSTRUCT_TQMON_s8TarGearPrev3 = 0;
   IFTQSTRUCT_TQMON_s8TarGearPrev4 = 0;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev = 0;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev1 = 0;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev2 = 0;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev3 = 0;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev4 = 0;
   IFTQSTRUCT_TQMON_u16CkFilPrev = 0;
   IFTQSTRUCT_TQMON_u16CkFilPrev1 = 0;
   IFTQSTRUCT_TQMON_u16CkFilPrev2 = 0;
   IFTQSTRUCT_TQMON_u16CkFilPrev3 = 0;
   IFTQSTRUCT_TQMON_u16CkFilPrev4 = 0;
   SftyMgt_spd1000RatCf_MP = 0;

   for( u8LocalIndex = 0; u8LocalIndex < 5; u8LocalIndex ++ )
   {
      VEMS_vidSET1DArrayElement(SftyMgt_prm_tqLimEM, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_noTarGearTra, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_noGearCordDrivFil, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_nCkFil, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_bDeceAcvTqSys, u8LocalIndex, 0);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_bNRegReq, u8LocalIndex, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGerCprInject                           */
/* !Description :  fonction gerer coupure injection                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_01265_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bTotCutOff;                                         */
/*  input uint8 SftyMgt_prm_bInjAcvCyl;                                       */
/*  output uint8 SftyMgt_noAcvCyl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGerCprInject(void)
{
   boolean bLocalTotCutOff;
   uint8   u8LocalOutput;
   uint8   u8LocalSftyMgt_prm_bInjAcvCyl;


   VEMS_vidGET(SftyMgt_bTotCutOff, bLocalTotCutOff);
   if (bLocalTotCutOff == 0)
   {
      VEMS_vidGET(SftyMgt_prm_bInjAcvCyl, u8LocalSftyMgt_prm_bInjAcvCyl);
      u8LocalOutput = (uint8)( (u8LocalSftyMgt_prm_bInjAcvCyl & 0x01)
                             + ((u8LocalSftyMgt_prm_bInjAcvCyl & 0x02) >> 1)
                             + ((u8LocalSftyMgt_prm_bInjAcvCyl & 0x04) >> 2)
                             + ((u8LocalSftyMgt_prm_bInjAcvCyl & 0x08) >> 3));
   }
   else
   {
      u8LocalOutput = 0;
   }
   VEMS_vidSET(SftyMgt_noAcvCyl, u8LocalOutput);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGenerInf10ms                           */
/* !Description :  Fonction Generer info 10 ms                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_01265_003.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_noGearCordDrivFil;                                       */
/*  input uint8 SftyMgt_noGearCordDrivFil_A[9];                               */
/*  input uint8 SftyMgt_noGearCordDrivFil_T[9];                               */
/*  input boolean SftyMgt_bSelDlySdl_C;                                       */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDriFilPrev;                             */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev4;                             */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev3;                             */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev2;                             */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev1;                             */
/*  input uint8 IFTQSTRUCT_TQMON_u8CorDrFilOut;                               */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input uint8 SftyMgt_facGainFil_nCkFil_C;                                  */
/*  input uint16 IFTQSTRUCT_TQMON_u16FilterOut;                               */
/*  input uint32 IFTQSTRUCT_TQMON_u32nEngFiltMem;                             */
/*  input boolean SftyMgt_bAcvGain_nCkFil_C;                                  */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilPrev;                               */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilPrev4;                              */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilPrev3;                              */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilPrev2;                              */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilPrev1;                              */
/*  input uint16 IFTQSTRUCT_TQMON_u16CkFilOut;                                */
/*  input sint16 TqLimEM_tqLimEM;                                             */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev;                             */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev4;                            */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev3;                            */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev2;                            */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev1;                            */
/*  input sint16 IFTQSTRUCT_TQMON_s16TqLimEMOut;                              */
/*  input boolean TqSys_bDeceAcv;                                             */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvPrev;                              */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvPrev4;                             */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvPrev3;                             */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvPrev2;                             */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvPrev1;                             */
/*  input boolean IFTQSTRUCT_TQMON_bDeceAcvOut;                               */
/*  input boolean CoPt_bAcvNRegReq;                                           */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev;                            */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev4;                           */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev3;                           */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev2;                           */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev1;                           */
/*  input boolean IFTQSTRUCT_TQMON_bAcvNRegReOut;                             */
/*  input sint8 Tra_noTarGear;                                                */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearPrev;                               */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearPrev4;                              */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearPrev3;                              */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearPrev2;                              */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearPrev1;                              */
/*  input sint8 IFTQSTRUCT_TQMON_s8TarGearOut;                                */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilOut;                              */
/*  output uint8 SftyMgt_prm_noGearDrivFilRaw[5];                             */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev4;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev3;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev2;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDrFilPrev1;                            */
/*  output uint8 IFTQSTRUCT_TQMON_u8CorDriFilPrev;                            */
/*  output uint16 IFTQSTRUCT_TQMON_u16FilterOut;                              */
/*  output uint32 IFTQSTRUCT_TQMON_u32nEngFiltMem;                            */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilOut;                               */
/*  output uint16 SftyMgt_prm_nCkFilRaw[5];                                   */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev4;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev3;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev2;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev1;                             */
/*  output uint16 IFTQSTRUCT_TQMON_u16CkFilPrev;                              */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMOut;                             */
/*  output sint16 SftyMgt_prm_tqLimEMRaw[5];                                  */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev4;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev3;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev2;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev1;                           */
/*  output sint16 IFTQSTRUCT_TQMON_s16TqLimEMPrev;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvOut;                              */
/*  output boolean SftyMgt_prm_bDeceAcvRaw[5];                                */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev4;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev3;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev2;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev1;                            */
/*  output boolean IFTQSTRUCT_TQMON_bDeceAcvPrev;                             */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegReOut;                            */
/*  output boolean SftyMgt_prm_bNRegReqRaw[5];                                */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev4;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev3;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev2;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev1;                          */
/*  output boolean IFTQSTRUCT_TQMON_bAcvNRegRePrev;                           */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearOut;                               */
/*  output sint8 SftyMgt_prm_noTarGearTraRaw[5];                              */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev4;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev3;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev2;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev1;                             */
/*  output sint8 IFTQSTRUCT_TQMON_s8TarGearPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGenerInf10ms(void)
{
   boolean bLocalCoPt_bAcvNRegReq;
   boolean bLocalTqSys_bDeceAcv;
   uint8   u8Localinterp1;
   uint8   u8LocalCoPt_noGearCordDrivFil;
   uint8   u8LocalGain;
   uint16  u16LocalTmpVar;
   uint16  u16LocalSftyMgt_nEng;
   uint16  u16LocalPara;
   sint8   s8LocalTra_noTarGear;
   sint16  s16LocalTqLimEM_tqLimEM;


   /* Calcul de SftyMgt_prm_noGearDrivFilRaw*/
   VEMS_vidGET(CoPt_noGearCordDrivFil, u8LocalCoPt_noGearCordDrivFil);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(SftyMgt_noGearCordDrivFil_A,
                                              u8LocalCoPt_noGearCordDrivFil,
                                              9);
   u8Localinterp1 = MATHSRV_u8Interp1d(SftyMgt_noGearCordDrivFil_T,
                                       u16LocalPara);

   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_u8CorDrFilOut =
         (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDriFilPrev, 8);
   }
   else
   {
      IFTQSTRUCT_TQMON_u8CorDrFilOut = (uint8)MATHSRV_udtMIN(u8Localinterp1, 8);
   }

   SftyMgt_prm_noGearDrivFilRaw[0] =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev4, 8);
   SftyMgt_prm_noGearDrivFilRaw[1] =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev3, 8);
   SftyMgt_prm_noGearDrivFilRaw[2] =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev2, 8);
   SftyMgt_prm_noGearDrivFilRaw[3] =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev1, 8);
   SftyMgt_prm_noGearDrivFilRaw[4] = IFTQSTRUCT_TQMON_u8CorDrFilOut;

   IFTQSTRUCT_TQMON_u8CorDrFilPrev4 =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev3, 8);
   IFTQSTRUCT_TQMON_u8CorDrFilPrev3 =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev2, 8);
   IFTQSTRUCT_TQMON_u8CorDrFilPrev2 =
      (uint8)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u8CorDrFilPrev1, 8);
   IFTQSTRUCT_TQMON_u8CorDrFilPrev1 = IFTQSTRUCT_TQMON_u8CorDrFilOut;
   IFTQSTRUCT_TQMON_u8CorDriFilPrev = (uint8)MATHSRV_udtMIN(u8Localinterp1, 8);

   /*DLowPassFilter_TypeK*/
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   if (SftyMgt_facGainFil_nCkFil_C >= 254)
   {
      IFTQSTRUCT_TQMON_u16FilterOut =
         (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_nEng, 8000);
      IFTQSTRUCT_TQMON_u32nEngFiltMem =
         (uint32)(IFTQSTRUCT_TQMON_u16FilterOut * 256);
   }
   else
   {
      u8LocalGain = (uint8)(SftyMgt_facGainFil_nCkFil_C + 1);
      u16LocalTmpVar =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalGain,
                                        &IFTQSTRUCT_TQMON_u32nEngFiltMem,
                                        u16LocalSftyMgt_nEng);
      IFTQSTRUCT_TQMON_u16FilterOut =
         (uint16)MATHSRV_udtMIN(u16LocalTmpVar, 8000);
   }

   /* Calcul de SftyMgt_prm_nCkFilRaw*/
   if (SftyMgt_bAcvGain_nCkFil_C != 0)
   {
      u16LocalTmpVar = (uint16)(IFTQSTRUCT_TQMON_u16FilterOut * 4);
   }
   else
   {
      VEMS_vidGET(Eng_nCkFil, u16LocalTmpVar);
   }

   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_u16CkFilOut =
         (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev, 32000);
   }
   else
   {
      IFTQSTRUCT_TQMON_u16CkFilOut =
         (uint16)MATHSRV_udtMIN(u16LocalTmpVar, 32000);
   }

   SftyMgt_prm_nCkFilRaw[0] =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev4, 32000);
   SftyMgt_prm_nCkFilRaw[1] =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev3, 32000);
   SftyMgt_prm_nCkFilRaw[2] =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev2, 32000);
   SftyMgt_prm_nCkFilRaw[3] =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev1, 32000);
   SftyMgt_prm_nCkFilRaw[4] = IFTQSTRUCT_TQMON_u16CkFilOut;

   IFTQSTRUCT_TQMON_u16CkFilPrev4 =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev3, 32000);
   IFTQSTRUCT_TQMON_u16CkFilPrev3 =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev2, 32000);
   IFTQSTRUCT_TQMON_u16CkFilPrev2 =
      (uint16)MATHSRV_udtMIN(IFTQSTRUCT_TQMON_u16CkFilPrev1, 32000);
   IFTQSTRUCT_TQMON_u16CkFilPrev1 = IFTQSTRUCT_TQMON_u16CkFilOut;
   IFTQSTRUCT_TQMON_u16CkFilPrev =
      (uint16)MATHSRV_udtMIN(u16LocalTmpVar, 32000);

   /* Calcul de SftyMgt_prm_tqLimEMRaw*/
   VEMS_vidGET(TqLimEM_tqLimEM, s16LocalTqLimEM_tqLimEM);

   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_s16TqLimEMOut =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev, -32000, 32000);
   }
   else
   {
      IFTQSTRUCT_TQMON_s16TqLimEMOut =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqLimEM_tqLimEM, -32000, 32000);
   }
   SftyMgt_prm_tqLimEMRaw[0] =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev4, -32000, 32000);
   SftyMgt_prm_tqLimEMRaw[1] =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev3, -32000, 32000);
   SftyMgt_prm_tqLimEMRaw[2] =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev2, -32000, 32000);
   SftyMgt_prm_tqLimEMRaw[3] =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev1, -32000, 32000);
   SftyMgt_prm_tqLimEMRaw[4] = IFTQSTRUCT_TQMON_s16TqLimEMOut;

   IFTQSTRUCT_TQMON_s16TqLimEMPrev4 =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev3, -32000, 32000);
   IFTQSTRUCT_TQMON_s16TqLimEMPrev3 =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev2, -32000, 32000);
   IFTQSTRUCT_TQMON_s16TqLimEMPrev2 =
      (sint16)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s16TqLimEMPrev1, -32000, 32000);
   IFTQSTRUCT_TQMON_s16TqLimEMPrev1 = IFTQSTRUCT_TQMON_s16TqLimEMOut;
   IFTQSTRUCT_TQMON_s16TqLimEMPrev =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqLimEM_tqLimEM, -32000, 32000);

   /* Calcul de SftyMgt_prm_bDeceAcvRaw*/
   VEMS_vidGET(TqSys_bDeceAcv, bLocalTqSys_bDeceAcv);
   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_bDeceAcvOut = IFTQSTRUCT_TQMON_bDeceAcvPrev;
   }
   else
   {
      IFTQSTRUCT_TQMON_bDeceAcvOut = bLocalTqSys_bDeceAcv;
   }
   SftyMgt_prm_bDeceAcvRaw[0] = IFTQSTRUCT_TQMON_bDeceAcvPrev4;
   SftyMgt_prm_bDeceAcvRaw[1] = IFTQSTRUCT_TQMON_bDeceAcvPrev3;
   SftyMgt_prm_bDeceAcvRaw[2] = IFTQSTRUCT_TQMON_bDeceAcvPrev2;
   SftyMgt_prm_bDeceAcvRaw[3] = IFTQSTRUCT_TQMON_bDeceAcvPrev1;
   SftyMgt_prm_bDeceAcvRaw[4] = IFTQSTRUCT_TQMON_bDeceAcvOut;
   IFTQSTRUCT_TQMON_bDeceAcvPrev4 = IFTQSTRUCT_TQMON_bDeceAcvPrev3;
   IFTQSTRUCT_TQMON_bDeceAcvPrev3 = IFTQSTRUCT_TQMON_bDeceAcvPrev2;
   IFTQSTRUCT_TQMON_bDeceAcvPrev2 = IFTQSTRUCT_TQMON_bDeceAcvPrev1;
   IFTQSTRUCT_TQMON_bDeceAcvPrev1 = IFTQSTRUCT_TQMON_bDeceAcvOut;
   IFTQSTRUCT_TQMON_bDeceAcvPrev = bLocalTqSys_bDeceAcv;

   /*Calcul de SftyMgt_prm_bNRegReqRaw*/
   VEMS_vidGET(CoPt_bAcvNRegReq, bLocalCoPt_bAcvNRegReq);
   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_bAcvNRegReOut = IFTQSTRUCT_TQMON_bAcvNRegRePrev;
   }
   else
   {
      IFTQSTRUCT_TQMON_bAcvNRegReOut = bLocalCoPt_bAcvNRegReq;
   }
   SftyMgt_prm_bNRegReqRaw[0] = IFTQSTRUCT_TQMON_bAcvNRegRePrev4;
   SftyMgt_prm_bNRegReqRaw[1] = IFTQSTRUCT_TQMON_bAcvNRegRePrev3;
   SftyMgt_prm_bNRegReqRaw[2] = IFTQSTRUCT_TQMON_bAcvNRegRePrev2;
   SftyMgt_prm_bNRegReqRaw[3] = IFTQSTRUCT_TQMON_bAcvNRegRePrev1;
   SftyMgt_prm_bNRegReqRaw[4] = IFTQSTRUCT_TQMON_bAcvNRegReOut;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev4 = IFTQSTRUCT_TQMON_bAcvNRegRePrev3;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev3 = IFTQSTRUCT_TQMON_bAcvNRegRePrev2;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev2 = IFTQSTRUCT_TQMON_bAcvNRegRePrev1;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev1 = IFTQSTRUCT_TQMON_bAcvNRegReOut;
   IFTQSTRUCT_TQMON_bAcvNRegRePrev = bLocalCoPt_bAcvNRegReq;

   /*Calcul de SftyMgt_prm_noTarGearTraRaw*/
   VEMS_vidGET(Tra_noTarGear, s8LocalTra_noTarGear);
   if (SftyMgt_bSelDlySdl_C != 0)
   {
      IFTQSTRUCT_TQMON_s8TarGearOut =
         (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev, -1, 9);
   }
   else
   {
      IFTQSTRUCT_TQMON_s8TarGearOut =
         (sint8)MATHSRV_udtCLAMP(s8LocalTra_noTarGear, -1, 9);
   }
   SftyMgt_prm_noTarGearTraRaw[0] =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev4, -1, 9);
   SftyMgt_prm_noTarGearTraRaw[1] =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev3, -1, 9);
   SftyMgt_prm_noTarGearTraRaw[2] =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev2, -1, 9);
   SftyMgt_prm_noTarGearTraRaw[3] =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev1, -1, 9);
   SftyMgt_prm_noTarGearTraRaw[4] = IFTQSTRUCT_TQMON_s8TarGearOut;

   IFTQSTRUCT_TQMON_s8TarGearPrev4 =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev3, -1, 9);
   IFTQSTRUCT_TQMON_s8TarGearPrev3 =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev2, -1, 9);
   IFTQSTRUCT_TQMON_s8TarGearPrev2 =
      (sint8)MATHSRV_udtCLAMP(IFTQSTRUCT_TQMON_s8TarGearPrev1, -1, 9);
   IFTQSTRUCT_TQMON_s8TarGearPrev1 = IFTQSTRUCT_TQMON_s8TarGearOut;
   IFTQSTRUCT_TQMON_s8TarGearPrev =
      (sint8)MATHSRV_udtCLAMP(s8LocalTra_noTarGear, -1, 9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidFluxInternes                           */
/* !Description :  cette fonction permet de déterminer les flux internes.     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_10_01265_004.07                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidGenerInf40ms();                      */
/*  extf argret void IFTQSTRUCT_TQMON_vidGeInf40msBis();                      */
/*  extf argret void IFTQSTRUCT_TQMON_vidGeInf40m2Bis();                      */
/*  extf argret void IFTQSTRUCT_TQMON_vidGeInf40m3Bis();                      */
/*  extf argret void IFTQSTRUCT_TQMON_vidGeInf40m4Bis();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidFluxInternes(void)
{
   IFTQSTRUCT_TQMON_vidGenerInf40ms();
   IFTQSTRUCT_TQMON_vidGeInf40msBis();
   IFTQSTRUCT_TQMON_vidGeInf40m2Bis();
   IFTQSTRUCT_TQMON_vidGeInf40m3Bis();
   IFTQSTRUCT_TQMON_vidGeInf40m4Bis();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGenerInf40ms                           */
/* !Description :  fonction generer info 40 ms.                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 TqDem_rAccPSptMod;                                           */
/*  input boolean TqDem_bTqGrdLim;                                            */
/*  input uint16 InM_pDsThrCor;                                               */
/*  input uint16 TqCmp_pwrAC5Loss;                                            */
/*  input uint16 TqCmp_tqACLoss;                                              */
/*  input sint16 TqCmp_tqAltLoss;                                             */
/*  input sint16 VSCtl_tqCkEfcMaxReq;                                         */
/*  input sint16 VSCtl_tqCkEfcMinReq;                                         */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean CoPt_bDiagSIPORng;                                          */
/*  input sint16 TqSys_tqCkEfcFil;                                            */
/*  output uint16 SftyMgt_rAccPSptModTqDem;                                   */
/*  output boolean SftyMgt_bTqGrdLimBuf;                                      */
/*  output boolean SftyMgt_bInhCnvLossMdl_FRM;                                */
/*  output boolean SftyMgt_bInhNRegTakeOffFRM;                                */
/*  output boolean SftyMgt_bInhStgPmpLoss_FRM;                                */
/*  output uint16 SftyMgt_pDsThrCor;                                          */
/*  output uint16 SftyMgt_pwrAC5Loss;                                         */
/*  output uint16 SftyMgt_tqACLossUnChkBuf;                                   */
/*  output sint16 SftyMgt_tqAltLossUnChkBuf;                                  */
/*  output sint16 SftyMgt_tqCkEfcMaxVSCtl;                                    */
/*  output sint16 SftyMgt_tqCkEfcMinVSCtl;                                    */
/*  output boolean SftyMgt_bAcvIdlCll;                                        */
/*  output boolean SftyMgt_bInhCoPtSIPFRM;                                    */
/*  output boolean SftyMgt_bDgoSIPORngCoPt;                                   */
/*  output sint16 SftyMgt_tqCkEfcFil;                                         */
/*  output sint16 SftyMgt_tqCkEfcFilTqSys;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGenerInf40ms(void)
{
   boolean bLocalTemp1;
   boolean bLocalTemp2;
   boolean bLocalFRM_INHCNVLOSSMDL;
   boolean bLocalFRM_INHREGNDECO;
   boolean bLocalFRM_INHSTGPUMPLOSSMDL;
   boolean bLocalFRM_INHCOPTSIP;
   uint16  u16LocalTemp;
   sint16  s16LocalTemp;


   VEMS_vidGET(TqDem_rAccPSptMod, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 12800);
   VEMS_vidSET(SftyMgt_rAccPSptModTqDem, u16LocalTemp);
   VEMS_vidGET(TqDem_bTqGrdLim, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bTqGrdLimBuf, bLocalTemp1);
   bLocalFRM_INHCNVLOSSMDL = GDGAR_bGetFRM(FRM_FRM_INHCNVLOSSMDL);
   VEMS_vidSET(SftyMgt_bInhCnvLossMdl_FRM, bLocalFRM_INHCNVLOSSMDL);
   bLocalFRM_INHREGNDECO = GDGAR_bGetFRM(FRM_FRM_INHREGNDECO);
   VEMS_vidSET(SftyMgt_bInhNRegTakeOffFRM, bLocalFRM_INHREGNDECO);
   bLocalFRM_INHSTGPUMPLOSSMDL = GDGAR_bGetFRM(FRM_FRM_INHSTGPUMPLOSSMDL);
   VEMS_vidSET(SftyMgt_bInhStgPmpLoss_FRM, bLocalFRM_INHSTGPUMPLOSSMDL);
   VEMS_vidGET(InM_pDsThrCor, u16LocalTemp);
   VEMS_vidSET(SftyMgt_pDsThrCor, u16LocalTemp);
   VEMS_vidGET(TqCmp_pwrAC5Loss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 5000);
   VEMS_vidSET(SftyMgt_pwrAC5Loss, u16LocalTemp);
   VEMS_vidGET(TqCmp_tqACLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqACLossUnChkBuf, u16LocalTemp);
   VEMS_vidGET(TqCmp_tqAltLoss, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqAltLossUnChkBuf, s16LocalTemp);
   VEMS_vidGET(VSCtl_tqCkEfcMaxReq, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfcMaxVSCtl, s16LocalTemp);
   VEMS_vidGET(VSCtl_tqCkEfcMinReq, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfcMinVSCtl, s16LocalTemp);
   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTemp2);
   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalTemp1);
   if (  (bLocalTemp2 != 0)
      && (bLocalTemp1 !=0 ))
   {
      VEMS_vidSET(SftyMgt_bAcvIdlCll, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bAcvIdlCll, 0);
   }
   bLocalFRM_INHCOPTSIP = GDGAR_bGetFRM(FRM_FRM_INHCOPTSIP);
   VEMS_vidSET(SftyMgt_bInhCoPtSIPFRM, bLocalFRM_INHCOPTSIP);
   VEMS_vidGET(CoPt_bDiagSIPORng , bLocalTemp1);
   VEMS_vidSET(SftyMgt_bDgoSIPORngCoPt, bLocalTemp1);
   VEMS_vidGET(TqSys_tqCkEfcFil , s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfcFil, s16LocalTemp);
   VEMS_vidSET(SftyMgt_tqCkEfcFilTqSys, s16LocalTemp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGeInf40msBis                           */
/* !Description :  fonction generer info 40 ms.                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqSys_tqCkEngLossAdp;                                        */
/*  input uint16 TqSys_tqCkEngLoss;                                           */
/*  input uint16 TqSys_tqCkPumpHiPLoss;                                       */
/*  input uint16 TqCmp_tqCnvLoss;                                             */
/*  input sint16 CoCha_tqEfcReq;                                              */
/*  input uint16 TqRes_tqFanStrtLoss;                                         */
/*  input sint16 IdlSys_tqIdcIdl;                                             */
/*  input sint16 EngLim_tqIdcRed;                                             */
/*  input sint16 EngLim_tqIdcSyst;                                            */
/*  input sint16 TqLimEM_tqLimEM;                                             */
/*  input uint16 TqCmp_tqStgPmpLoss;                                          */
/*  input uint16 TqSys_nOfsTotTakeOff;                                        */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input boolean TPM_bInhInjCutOff;                                          */
/*  input boolean InjSys_bAcvAirLdMinSat;                                     */
/*  output sint16 SftyMgt_tqCkEngLossAdpUnChkBuf;                             */
/*  output uint16 SftyMgt_tqCkEngLossUnChkBuf;                                */
/*  output uint16 SftyMgt_tqCkPmpHiPUnChkBuf;                                 */
/*  output uint16 SftyMgt_tqCnvLossUnChkBuf;                                  */
/*  output sint16 SftyMgt_tqEfcReqCoChaUnChkBuf;                              */
/*  output sint16 SftyMgt_tqEfcReqCoChaChk;                                   */
/*  output uint16 SftyMgt_tqFanStrtLossUnChkBuf;                              */
/*  output sint16 SftyMgt_tqIdcIdl;                                           */
/*  output sint16 SftyMgt_tqIdcRedEngLim;                                     */
/*  output sint16 SftyMgt_tqIdcSysEngLim;                                     */
/*  output sint16 SftyMgt_tqLimEM;                                            */
/*  output uint16 SftyMgt_tqStgPmpLossUnChkBuf;                               */
/*  output uint16 SftyMgt_nOfsIdlTakeOff;                                     */
/*  output boolean SftyMgt_bAcvAutoInj;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGeInf40msBis(void)
{

   boolean bLocalEOM_bTWCHeatPha;
   boolean bLocalTPM_bInhInjCutOff;
   boolean bLocalInjSys_bAcvAirLdMinSat;
   sint16  s16LocalTemp;
   uint16  u16LocalTemp;


   VEMS_vidGET(TqSys_tqCkEngLossAdp, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEngLossAdpUnChkBuf, s16LocalTemp);
   VEMS_vidGET(TqSys_tqCkEngLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqCkEngLossUnChkBuf, u16LocalTemp);
   VEMS_vidGET(TqSys_tqCkPumpHiPLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqCkPmpHiPUnChkBuf, u16LocalTemp);
   VEMS_vidGET(TqCmp_tqCnvLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqCnvLossUnChkBuf, u16LocalTemp);
   VEMS_vidGET(CoCha_tqEfcReq, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqEfcReqCoChaUnChkBuf, s16LocalTemp);
   VEMS_vidSET(SftyMgt_tqEfcReqCoChaChk, s16LocalTemp);
   VEMS_vidGET(TqRes_tqFanStrtLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 1600);
   VEMS_vidSET(SftyMgt_tqFanStrtLossUnChkBuf, u16LocalTemp);
   VEMS_vidGET(IdlSys_tqIdcIdl, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcIdl, s16LocalTemp);
   VEMS_vidGET(EngLim_tqIdcRed, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcRedEngLim, s16LocalTemp);
   VEMS_vidGET(EngLim_tqIdcSyst, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcSysEngLim, s16LocalTemp);
   VEMS_vidGET(TqLimEM_tqLimEM, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqLimEM, s16LocalTemp);
   VEMS_vidGET(TqCmp_tqStgPmpLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqStgPmpLossUnChkBuf, u16LocalTemp);
   VEMS_vidGET(TqSys_nOfsTotTakeOff, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nOfsIdlTakeOff, u16LocalTemp);

   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidGET(TPM_bInhInjCutOff, bLocalTPM_bInhInjCutOff);
   VEMS_vidGET(InjSys_bAcvAirLdMinSat, bLocalInjSys_bAcvAirLdMinSat);
   if (  (bLocalEOM_bTWCHeatPha != 0)
      || (bLocalTPM_bInhInjCutOff != 0)
      || (bLocalInjSys_bAcvAirLdMinSat != 0))
   {
      VEMS_vidSET(SftyMgt_bAcvAutoInj, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bAcvAutoInj, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGeInf40m2Bis                           */
/* !Description :  fonction generer info 40 ms.                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input boolean TqSys_bAOSAcv;                                              */
/*  input sint16 TqRes_tqMaxResnoSat;                                         */
/*  input boolean CoStrtRStrt_bInh;                                           */
/*  input boolean StaStrtMgt_bStaReq;                                         */
/*  input boolean CoPt_bSIP;                                                  */
/*  input sint16 CoPt_tqAirReqGBx;                                            */
/*  input sint16 CoPt_tqReqGBx;                                               */
/*  input sint16 CoPt_tqIdcReqCord_nRegReq;                                   */
/*  input sint16 CoPt_tqEfcCordLim_tqGBx;                                     */
/*  input boolean TqSys_bDeceAcv;                                             */
/*  input boolean TqCll_bAcvCll;                                              */
/*  input boolean CoPt_bTakeOff;                                              */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint8 CoPt_noGearCord_Sfty;                                         */
/*  output boolean SftyMgt_bDeacAOS;                                          */
/*  output sint16 SftyMgt_tqMaxRes;                                           */
/*  output boolean SftyMgt_bInhCoStrtRStrt;                                   */
/*  output boolean SftyMgt_bStaReq;                                           */
/*  output boolean SftyMgt_bSIPCoPt;                                          */
/*  output sint16 SftyMgt_tqAirReqGBxCoPt;                                    */
/*  output sint16 SftyMgt_tqReqGBxCoPt;                                       */
/*  output sint16 SftyMgt_tqIdcNReg;                                          */
/*  output sint16 SftyMgt_tqIdcReqCordNRegReq;                                */
/*  output sint16 SftyMgt_tqGBx;                                              */
/*  output boolean SftyMgt_bDeceAcvCll;                                       */
/*  output boolean SftyMgt_bAcvCllUnChk;                                      */
/*  output boolean SftyMgt_bAcvCllTqCll;                                      */
/*  output boolean SftyMgt_bEngSpdLimHiIntvFRM;                               */
/*  output boolean SftyMgt_bEngSpdLimLoIntvFRM;                               */
/*  output boolean SftyMgt_bInhRvTqDemTakeOffFRM;                             */
/*  output boolean SftyMgt_bTakeOffCoPt;                                      */
/*  output uint16 SftyMgt_nCkFil;                                             */
/*  output uint16 SftyMgt_nCkFilBuf;                                          */
/*  output uint8 SftyMgt_noGearCord;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGeInf40m2Bis(void)
{
   boolean bLocalTemp1;
   boolean bLocalFRM_ENGSPDLIMHIINTV;
   boolean bLocalFRM_ENGSPDLIMLOINTV;
   boolean bLocalFRM_INHRVTQDEMTAKEOFF;
   boolean bLocalTqCll_bAcvCll;
   boolean bLocalTqSys_bDeceAcv;
   uint8   u8LocalTemp;
   uint16  u16LocalTemp;
   sint16  s16LocalTemp;


   VEMS_vidGET(TqSys_bAOSAcv, bLocalTemp1);
   if (bLocalTemp1 == 0)
   {
      VEMS_vidSET(SftyMgt_bDeacAOS, 1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDeacAOS, 0);
   }
   VEMS_vidGET(TqRes_tqMaxResnoSat, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqMaxRes, s16LocalTemp);
   VEMS_vidGET(CoStrtRStrt_bInh, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bInhCoStrtRStrt, bLocalTemp1);
   VEMS_vidGET(StaStrtMgt_bStaReq, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bStaReq, bLocalTemp1);
   VEMS_vidGET(CoPt_bSIP, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bSIPCoPt, bLocalTemp1);
   VEMS_vidGET(CoPt_tqAirReqGBx,s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqAirReqGBxCoPt,s16LocalTemp);
   VEMS_vidGET(CoPt_tqReqGBx,s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqReqGBxCoPt,s16LocalTemp);
   VEMS_vidGET(CoPt_tqIdcReqCord_nRegReq, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcNReg, s16LocalTemp);
   VEMS_vidSET(SftyMgt_tqIdcReqCordNRegReq, s16LocalTemp);
   VEMS_vidGET(CoPt_tqEfcCordLim_tqGBx, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqGBx, s16LocalTemp);
   VEMS_vidGET(TqSys_bDeceAcv, bLocalTqSys_bDeceAcv);
   VEMS_vidSET(SftyMgt_bDeceAcvCll, bLocalTqSys_bDeceAcv);
   VEMS_vidGET(TqCll_bAcvCll, bLocalTqCll_bAcvCll);
   VEMS_vidSET(SftyMgt_bAcvCllUnChk, bLocalTqCll_bAcvCll);
   VEMS_vidSET(SftyMgt_bAcvCllTqCll, bLocalTqCll_bAcvCll);
   bLocalFRM_ENGSPDLIMHIINTV = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMHIINTV);
   VEMS_vidSET(SftyMgt_bEngSpdLimHiIntvFRM, bLocalFRM_ENGSPDLIMHIINTV);
   bLocalFRM_ENGSPDLIMLOINTV = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMLOINTV);
   VEMS_vidSET(SftyMgt_bEngSpdLimLoIntvFRM, bLocalFRM_ENGSPDLIMLOINTV);
   bLocalFRM_INHRVTQDEMTAKEOFF = GDGAR_bGetFRM(FRM_FRM_INHRVTQDEMTAKEOFF);
   VEMS_vidSET(SftyMgt_bInhRvTqDemTakeOffFRM, bLocalFRM_INHRVTQDEMTAKEOFF);
   VEMS_vidGET(CoPt_bTakeOff, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bTakeOffCoPt, bLocalTemp1);
   VEMS_vidGET(Eng_nCkFil, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nCkFil, u16LocalTemp);
   VEMS_vidSET(SftyMgt_nCkFilBuf, u16LocalTemp);
   VEMS_vidGET(CoPt_noGearCord_Sfty, u8LocalTemp);
   u8LocalTemp = (uint8)MATHSRV_udtMIN(u8LocalTemp, 7);
   VEMS_vidSET(SftyMgt_noGearCord, u8LocalTemp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGeInf40m3Bis                           */
/* !Description :  fonction generer info 40 ms.                               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input uint16 TqCmp_tqAuxLoss;                                             */
/*  input sint16 TqSys_tqCkAOSCor;                                            */
/*  input uint8 CoPTSt_stDrvTra;                                              */
/*  input boolean CoPTSt_bDgoSftyORngAM;                                      */
/*  input boolean CoPTSt_bDgoSftyORngAT;                                      */
/*  input boolean StaCtl_bStaAuth;                                            */
/*  input boolean Ext_bDrvTraAMT;                                             */
/*  input boolean Ext_bATParkNeut;                                            */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input uint16 TqSys_nTarIdlSfty;                                           */
/*  input uint16 TqSys_nTarIdlAT;                                             */
/*  input uint16 TqSys_nTarIdlStrt;                                           */
/*  input boolean Ext_bSTTCf;                                                 */
/*  input sint16 CoPt_tqDrvRaw;                                               */
/*  input boolean TqSys_bFuCutOffReq;                                         */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 VSCtl_stTqPTMinCtl;                                           */
/*  input sint16 TqDem_tqCkEfcWoutAntiDB;                                     */
/*  input uint16 SftyMgt_prm_nCkFilRaw[5];                                    */
/*  input boolean SftyMgt_prm_bNRegReqRaw[5];                                 */
/*  input uint8 SftyMgt_prm_noGearDrivFilRaw[5];                              */
/*  input sint8 SftyMgt_prm_noTarGearTraRaw[5];                               */
/*  input sint16 SftyMgt_prm_tqLimEMRaw[5];                                   */
/*  input boolean SftyMgt_prm_bDeceAcvRaw[5];                                 */
/*  output sint16 SftyMgt_tqSumLossCmp;                                       */
/*  output sint16 SftyMgt_tqSumLossCmpUnChkBuf;                               */
/*  output uint16 SftyMgt_tqAuxLossTqCmp;                                     */
/*  output sint16 SftyMgt_tqCkAntiOscCor;                                     */
/*  output uint8 SftyMgt_stDrvTraCoPTSt;                                      */
/*  output boolean SftyMgt_bAcvDrvTraInvldFRM;                                */
/*  output boolean SftyMgt_bDgoSftyORngAMCoPTSt;                              */
/*  output boolean SftyMgt_bDgoSftyORngATCoPTSt;                              */
/*  output boolean SftyMgt_bStaAuthStaCtl;                                    */
/*  output boolean SftyMgt_bDrvTraAMTExt;                                     */
/*  output boolean SftyMgt_bATParkNeutExt;                                    */
/*  output boolean SftyMgt_bIniIdlCtlIdlSys;                                  */
/*  output uint16 SftyMgt_nTarIdlSftyTqSys;                                   */
/*  output uint16 SftyMgt_nTarIdlATTqSys;                                     */
/*  output uint16 SftyMgt_nTarIdlStrtTqSys;                                   */
/*  output boolean SftyMgt_bSTTCf;                                            */
/*  output sint16 SftyMgt_tqDrvRawCoPt;                                       */
/*  output boolean SftyMgt_bFuCutOffReqTqSys;                                 */
/*  output uint8 SftyMgt_noEgdGearCordCoPt;                                   */
/*  output uint8 SftyMgt_stTqPTMinCtlVSCtl;                                   */
/*  output sint16 SftyMgt_tqCkEfcWoutAntiDBTqDem;                             */
/*  output uint16 SftyMgt_prm_nCkFil[5];                                      */
/*  output boolean SftyMgt_prm_bNRegReq[5];                                   */
/*  output uint8 SftyMgt_prm_noGearCordDrivFil[5];                            */
/*  output sint8 SftyMgt_prm_noTarGearTra[5];                                 */
/*  output sint16 SftyMgt_prm_tqLimEM[5];                                     */
/*  output boolean SftyMgt_prm_bDeceAcvTqSys[5];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGeInf40m3Bis(void)
{
   boolean bLocalTemp1;
   boolean bLocalTemp;
   boolean bLocalFRM_ACVDRVTRAINVLD;
   uint8   u8LocalIndex;
   uint8   u8LocalTemp;
   sint8   s8LocalTemp;
   uint16  u16LocalTemp;
   uint16  u16LocalSftyMgt_nTarIdlStrtTqSys;
   sint16  s16LocalTqSys_tqCkAOscCor;
   sint16  s16LocalTemp3;
   sint16  s16LocalTemp;
   uint32  u32LocalTemp;


   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqSumLossCmp, s16LocalTemp);
   VEMS_vidSET(SftyMgt_tqSumLossCmpUnChkBuf, s16LocalTemp);
   VEMS_vidGET(TqCmp_tqAuxLoss, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 8000);
   VEMS_vidSET(SftyMgt_tqAuxLossTqCmp, u16LocalTemp);
   VEMS_vidGET(TqSys_tqCkAOSCor, s16LocalTqSys_tqCkAOscCor);
   s16LocalTqSys_tqCkAOscCor =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqCkAOscCor, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkAntiOscCor, s16LocalTqSys_tqCkAOscCor);
   VEMS_vidGET(CoPTSt_stDrvTra, u8LocalTemp);
   u8LocalTemp = (uint8)MATHSRV_udtMIN(u8LocalTemp, 2);
   VEMS_vidSET(SftyMgt_stDrvTraCoPTSt, u8LocalTemp);
   bLocalFRM_ACVDRVTRAINVLD = GDGAR_bGetFRM(FRM_FRM_ACVDRVTRAINVLD);
   VEMS_vidSET(SftyMgt_bAcvDrvTraInvldFRM, bLocalFRM_ACVDRVTRAINVLD);
   VEMS_vidGET(CoPTSt_bDgoSftyORngAM, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bDgoSftyORngAMCoPTSt, bLocalTemp1);
   VEMS_vidGET(CoPTSt_bDgoSftyORngAT, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bDgoSftyORngATCoPTSt, bLocalTemp1);
   VEMS_vidGET(StaCtl_bStaAuth, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bStaAuthStaCtl, bLocalTemp1);
   VEMS_vidGET(Ext_bDrvTraAMT, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bDrvTraAMTExt, bLocalTemp1);
   VEMS_vidGET(Ext_bATParkNeut, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bATParkNeutExt, bLocalTemp1);
   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bIniIdlCtlIdlSys, bLocalTemp1);
   VEMS_vidGET(TqSys_nTarIdlSfty, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nTarIdlSftyTqSys, u16LocalTemp);
   VEMS_vidGET(TqSys_nTarIdlAT, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nTarIdlATTqSys, u16LocalTemp);
   VEMS_vidGET(TqSys_nTarIdlStrt, u16LocalTemp);
   u32LocalTemp = 4 * u16LocalTemp;
   u16LocalSftyMgt_nTarIdlStrtTqSys = (uint16)MATHSRV_udtMIN(u32LocalTemp,
                                                             32000);
   VEMS_vidSET(SftyMgt_nTarIdlStrtTqSys, u16LocalSftyMgt_nTarIdlStrtTqSys);
   VEMS_vidGET(Ext_bSTTCf, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bSTTCf, bLocalTemp1);
   VEMS_vidGET(CoPt_tqDrvRaw, s16LocalTemp3);
   s16LocalTemp3 = (sint16)MATHSRV_udtCLAMP(s16LocalTemp3, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqDrvRawCoPt, s16LocalTemp3);
   VEMS_vidGET(TqSys_bFuCutOffReq, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bFuCutOffReqTqSys, bLocalTemp1);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalTemp);
   u8LocalTemp = (uint8)MATHSRV_udtMIN(u8LocalTemp, 7);
   VEMS_vidSET(SftyMgt_noEgdGearCordCoPt, u8LocalTemp);
   VEMS_vidGET(VSCtl_stTqPTMinCtl, u8LocalTemp);
   u8LocalTemp = (uint8)MATHSRV_udtMIN(u8LocalTemp, 2);
   VEMS_vidSET(SftyMgt_stTqPTMinCtlVSCtl, u8LocalTemp);
   VEMS_vidGET(TqDem_tqCkEfcWoutAntiDB, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfcWoutAntiDBTqDem, s16LocalTemp);

   for( u8LocalIndex = 0; u8LocalIndex < 5; u8LocalIndex ++ )
   {
      u16LocalTemp = SftyMgt_prm_nCkFilRaw[u8LocalIndex];
      u16LocalTemp =
         (uint16)MATHSRV_udtMIN(u16LocalTemp,32000);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_nCkFil,
                                u8LocalIndex,
                                u16LocalTemp);

      bLocalTemp = SftyMgt_prm_bNRegReqRaw[u8LocalIndex];
      VEMS_vidSET1DArrayElement(SftyMgt_prm_bNRegReq,
                                u8LocalIndex,
                                bLocalTemp);

      u8LocalTemp = SftyMgt_prm_noGearDrivFilRaw[u8LocalIndex];
      u8LocalTemp =
         (uint8)MATHSRV_udtMIN(u8LocalTemp, 8);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_noGearCordDrivFil,
                                u8LocalIndex,
                                u8LocalTemp);
      s8LocalTemp = SftyMgt_prm_noTarGearTraRaw[u8LocalIndex];
      s8LocalTemp =
         (sint8)MATHSRV_udtCLAMP(s8LocalTemp,-1, 9);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_noTarGearTra,
                                u8LocalIndex,
                                s8LocalTemp);
      s16LocalTemp = SftyMgt_prm_tqLimEMRaw[u8LocalIndex];
      s16LocalTemp =
         (sint16)MATHSRV_udtCLAMP(s16LocalTemp,-32000, 32000);
      VEMS_vidSET1DArrayElement(SftyMgt_prm_tqLimEM,
                                u8LocalIndex,
                                s16LocalTemp);
      bLocalTemp = SftyMgt_prm_bDeceAcvRaw[u8LocalIndex];
      VEMS_vidSET1DArrayElement(SftyMgt_prm_bDeceAcvTqSys,
                                u8LocalIndex,
                                bLocalTemp);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidGeInf40m4Bis                           */
/* !Description :  fonction generer info 40 ms.                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint16 EngLim_tqCkDrivFil;                                          */
/*  input sint16 TqDem_tqCkEfc;                                               */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input sint16 DZone_tqEfcDifLrnOut;                                        */
/*  input boolean TqDem_bModSpt;                                              */
/*  input boolean TqDem_bAcvNRegTakeOff;                                      */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input boolean CoReqVeh_bEngStrtReq;                                       */
/*  input uint16 IdlSys_nTarIdlDyn;                                           */
/*  input uint16 TqSys_nTarIdlFil;                                            */
/*  input uint16 TqDem_rDrivTakeOff;                                          */
/*  input sint16 TqDem_tqEfcNRegTakeOffNorm[2];                               */
/*  input sint16 TqDem_tqEfcNRegTakeOffEco[2];                                */
/*  input uint16 Ext_pAirExtMesSI;                                            */
/*  input uint16 UsThrM_pAirExtMesCor;                                        */
/*  input sint16 EngLim_tqIdcEngCurMax;                                       */
/*  output sint16 SftyMgt_tqCkDrivFilEngLim;                                  */
/*  output sint16 SftyMgt_tqCkEfcTqDem;                                       */
/*  output boolean SftyMgt_bInhTqCllFRM;                                      */
/*  output sint16 SftyMgt_tqIdcAirReqTqSys;                                   */
/*  output sint16 SftyMgt_tqEfcDifLrnOutDZone;                                */
/*  output boolean SftyMgt_bModSptTqDem;                                      */
/*  output boolean SftyMgt_bInhAntiDBFRM;                                     */
/*  output boolean SftyMgt_bAcvNRegTakeOffTqDem;                              */
/*  output uint16 SftyMgt_spdVehBuf;                                          */
/*  output boolean SftyMgt_bEngStrtReq;                                       */
/*  output uint16 SftyMgt_nTarIdl;                                            */
/*  output uint16 SftyMgt_nTarIdlDynIdlSys;                                   */
/*  output uint16 SftyMgt_nTarIdlUnChkBuf;                                    */
/*  output uint16 SftyMgt_rDrivTakeOffTqDem;                                  */
/*  output sint16 SftyMgt_tqEfcNRegTakeOffNorm;                               */
/*  output sint16 SftyMgt_tqEfcNRegTakeOffEco;                                */
/*  output uint16 SftyMgt_pAirExtMesSI;                                       */
/*  output uint16 SftyMgt_pAirExtMesCorUsThrM;                                */
/*  output sint16 SftyMgt_tqIdcEngCurMaxEngLim;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidGeInf40m4Bis(void)
{
   boolean bLocalFRM_INHANTIDB;
   boolean bLocalFRM_INHTQCLL;
   boolean bLocalTemp1;
   uint16  u16LocalTemp;
   sint16  s16LocalTemp;


   VEMS_vidGET(EngLim_tqCkDrivFil, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkDrivFilEngLim, s16LocalTemp);
   VEMS_vidGET(TqDem_tqCkEfc, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqCkEfcTqDem, s16LocalTemp);
   bLocalFRM_INHTQCLL = GDGAR_bGetFRM(FRM_FRM_INHTQCLL);
   VEMS_vidSET(SftyMgt_bInhTqCllFRM, bLocalFRM_INHTQCLL);
   VEMS_vidGET(TqSys_tqIdcAirReq, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcAirReqTqSys, s16LocalTemp);
   VEMS_vidGET(DZone_tqEfcDifLrnOut, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqEfcDifLrnOutDZone, s16LocalTemp);
   VEMS_vidGET(TqDem_bModSpt, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bModSptTqDem, bLocalTemp1);
   bLocalFRM_INHANTIDB = GDGAR_bGetFRM(FRM_FRM_INHANTIDB);
   VEMS_vidSET(SftyMgt_bInhAntiDBFRM, bLocalFRM_INHANTIDB);
   VEMS_vidGET(TqDem_bAcvNRegTakeOff, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bAcvNRegTakeOffTqDem, bLocalTemp1);
   VEMS_vidGET(SftyMgt_spdVeh, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 64000);
   VEMS_vidSET(SftyMgt_spdVehBuf, u16LocalTemp);
   VEMS_vidGET(CoReqVeh_bEngStrtReq, bLocalTemp1);
   VEMS_vidSET(SftyMgt_bEngStrtReq, bLocalTemp1);
   VEMS_vidGET(IdlSys_nTarIdlDyn, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nTarIdl, u16LocalTemp);
   VEMS_vidSET(SftyMgt_nTarIdlDynIdlSys, u16LocalTemp);
   VEMS_vidGET(TqSys_nTarIdlFil, u16LocalTemp);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 32000);
   VEMS_vidSET(SftyMgt_nTarIdlUnChkBuf, u16LocalTemp);
   VEMS_vidGET(TqDem_rDrivTakeOff,u16LocalTemp);
   u16LocalTemp = (uint16) (((u16LocalTemp * 125) + 64)/ 128);
   u16LocalTemp = (uint16)MATHSRV_udtMIN(u16LocalTemp, 1000);
   VEMS_vidSET(SftyMgt_rDrivTakeOffTqDem, u16LocalTemp);
   VEMS_vidGET1DArrayElement(TqDem_tqEfcNRegTakeOffNorm, 0, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqEfcNRegTakeOffNorm, s16LocalTemp);
   VEMS_vidGET1DArrayElement(TqDem_tqEfcNRegTakeOffEco, 0, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqEfcNRegTakeOffEco, s16LocalTemp);
   VEMS_vidGET(Ext_pAirExtMesSI, u16LocalTemp);
   VEMS_vidSET(SftyMgt_pAirExtMesSI, u16LocalTemp);
   VEMS_vidGET(UsThrM_pAirExtMesCor, u16LocalTemp);
   VEMS_vidSET(SftyMgt_pAirExtMesCorUsThrM, u16LocalTemp);
   VEMS_vidGET(EngLim_tqIdcEngCurMax, s16LocalTemp);
   s16LocalTemp = (sint16)MATHSRV_udtCLAMP(s16LocalTemp, -32000, 32000);
   VEMS_vidSET(SftyMgt_tqIdcEngCurMaxEngLim, s16LocalTemp);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/