/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAT                                                    */
/* !Description     : AFAT Software component                                 */
/*                                                                            */
/* !Module          : AFAT                                                    */
/*                                                                            */
/* !File            : AFAT_Def.c                                              */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AFAT_SWC.mdl                                          */
/*   Root subsystem   : /AFAT                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.11                                                        $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAT.h"
#include "AFAT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_32BIT" */
#define AFAT_START_SEC_CALIB_32BIT
#include "AFAT_MemMap.h"

CONST(SInt32, AFAT_CALIB) AFA_facSlopInjGainIni_C = 0;
CONST(UInt32, AFAT_CALIB) AFA_facSlopInjGainSat_C = 184320000U;
CONST(SInt32, AFAT_CALIB) AFA_facSlopInjGain_B = 0;
CONST(UInt32, AFAT_CALIB) AFA_tiDlyLstObs_B = 0U;
CONST(UInt32, AFAT_CALIB) AFA_tiDlySpcInjMod_C = 400U;

#define AFAT_STOP_SEC_CALIB_32BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CARTO_32BIT" */
#define AFAT_START_SEC_CARTO_32BIT
#include "AFAT_MemMap.h"

CONST(SInt32, AFAT_CARTO) AFA_facMassFlowArGrdThr_T[22] = { 0, -14, -40, -66,
  -90, -114, -140, -170, -202, -236, -277, -332, -401, -487, -589, -720, -859,
  -1016, -1263, -1627, -4025, -4025 } ;

#define AFAT_STOP_SEC_CARTO_32BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define AFAT_START_SEC_CALIB_16BIT
#include "AFAT_MemMap.h"

CONST(UInt16, AFAT_CALIB) AFA_agCkClsExVlvBolDelta_C = 11U;
CONST(UInt16, AFAT_CALIB) AFA_agCkOpInVlvBolDelta_C = 11U;
CONST(SInt16, AFAT_CALIB) AFA_arEffThrOfsIni_C = 0;
CONST(UInt16, AFAT_CALIB) AFA_arEffThrOfsSat_C = 255U;
CONST(SInt16, AFAT_CALIB) AFA_arEffThrOfs_B = -32768;
CONST(SInt16, AFAT_CALIB) AFA_facIvsInjGainIni_C = 0;
CONST(UInt16, AFAT_CALIB) AFA_facIvsInjGainSat_C = 64000U;
CONST(SInt16, AFAT_CALIB) AFA_facIvsInjGain_B = -32768;
CONST(UInt16, AFAT_CALIB) AFA_facOutInnovThd_C = 30U;
CONST(UInt16, AFAT_CALIB) AFA_lamErrFirstObsDB_C = 1966U;
CONST(UInt16, AFAT_CALIB) AFA_lamFbDB_C = 0U;
CONST(UInt16, AFAT_CALIB) AFA_nEngLstObs_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfcAst_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfcCovErrRstThd_C = 3U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfcMinThd_C = 1U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfcSpcInjModThd_C = 1U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfcThd_C = 2U;
CONST(UInt16, AFAT_CALIB) AFA_noAdpEfc_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_pDsThrEstimErrDB_C = 0U;
CONST(UInt16, AFAT_CALIB) AFA_pDsThrEstimErrFirstObsDB_C = 94U;
CONST(UInt16, AFAT_CALIB) AFA_pDsThrPredFil_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_pUsThrCorFil_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_prm_covErrEstim_B[8] = { 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U } ;

CONST(UInt16, AFAT_CALIB) AFA_prm_covErrIni_C[8] = { 3328U, 3328U, 3328U,
  3328U, 2816U, 2816U, 2816U, 0U } ;

CONST(UInt16, AFAT_CALIB) AFA_rAirLdCorFil_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_rAirPresFil_B = 0U;
CONST(UInt16, AFAT_CALIB) AFA_rErrDB_C = 34406U;
CONST(UInt16, AFAT_CALIB) AFA_rOpClsEGRVlvDeltaMinThd_C = 655U;
CONST(UInt16, AFAT_CALIB) AFA_rTotLdCorLstObs_B = 0U;
CONST(SInt16, AFAT_CALIB) AFA_tiOffInjIni_C = 0;

#define AFAT_STOP_SEC_CALIB_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define AFAT_START_SEC_CARTO_16BIT
#include "AFAT_MemMap.h"

CONST(SInt16, AFAT_CARTO) AFA_agCkGrdClsExVlvX_A[12] = { -293, -240, -187, -133,
  -80, -27, 27, 80, 133, 187, 240, 293 } ;

CONST(UInt16, AFAT_CARTO) AFA_agCkGrdClsInVlvX_A[12] = { 955U, 1008U, 1061U,
  1115U, 1168U, 1221U, 1275U, 1328U, 1381U, 1435U, 1488U, 1541U } ;

CONST(SInt16, AFAT_CARTO) AFA_agCkGrdOpInVlvY_A[12] = { -293, -240, -187, -133,
  -80, -27, 27, 80, 133, 187, 240, 293 } ;

CONST(SInt16, AFAT_CARTO) AFA_agCkGrdPosnVlvOvlpX_A[12] = { -293, -240, -187,
  -133, -80, -27, 27, 80, 133, 187, 240, 293 } ;

CONST(SInt16, AFAT_CARTO) AFA_agCkGrdVlvOvlpX_A[24] = { -613, -560, -507, -453,
  -400, -347, -293, -240, -187, -133, -80, -27, 27, 80, 133, 187, 240, 293, 347,
  400, 453, 507, 560, 613 } ;

CONST(UInt16, AFAT_CARTO) AFA_agCk_facTDCGrd_A[19] = { 1U, 29U, 83U, 136U,
  189U, 268U, 347U, 400U, 480U, 667U, 933U, 1120U, 1227U, 1333U, 1440U, 1547U,
  1653U, 1760U, 1867U } ;

CONST(SInt16, AFAT_CARTO) AFA_facCorAtmGrdSlopEfc_M[18][12] = { { 0, 0, 2954, 0, 0,
  0, 2519, 0, 0, 1582, 0, 0 },{ 0, 2235, 0, 0, 0, 0, 0, 0, 2405, 0, 0, 0 },{ 1927, 0,
  0, 861, 0, 0, 0, 2414, 0, 0, 0, 0 },{ 0, 0, 2412, 0, 0, 0, 1865, 0, 0, 1501, 0, 0 },
{ 0, 3266, 0, 0, 0, 0, 0, 0, 1595, 0, 0, 0 },{ 1226, 0, 0, 1271, 0, 0, 0, 3414, 0,
  0, 0, 0 },{ 0, 0, 512, 0, 0, 0, 606, 0, 0, 1267, 0, 0 },{ 0, 4070, 0, 0, 0, 0, 0, 0,
  258, 0, 0, 0 },{ 508, 0, 0, 851, 0, 0, 0, 3845, 0, 0, 0, 0 },{ 0, 0, 143, 0, 0, 0,
  543, 0, 0, 712, 0, 0 },{ 0, 2941, 0, 0, 0, 0, 0, 0, 239, 0, 0, 0 },{ 311, 0, 0, 220,
  0, 0, 0, 4123, 0, 0, 0, 0 },{ 0, 0, 155, 0, 0, 0, 409, 0, 0, 379, 0, 0 },{ 0, 4459,
  0, 0, 0, 0, 0, 0, 71, 0, 0, 0 },{ 407, 0, 0, 503, 0, 0, 0, 4145, 0, 0, 0, 0 },{ 0, 0,
  195, 0, 0, 0, 568, 0, 0, 409, 0, 0 },{ 0, 3881, 0, 0, 0, 0, 0, 0, 170, 0, 0, 0 },
{ 652, 0, 0, 455, 0, 0, 0, 3278, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_facCorBoostGrdSlopEfc_M[18][12] = { { 0, 0, 489, 0, 0,
  0, -1533, 0, 0, -115, 0, 0 },{ 0, 1296, 0, 0, 0, 0, 0, 0, 464, 0, 0, 0 },{ -1145, 0,
  0, 48, 0, 0, 0, 1079, 0, 0, 0, 0 },{ 0, 0, 433, 0, 0, 0, -1196, 0, 0, 12, 0, 0 },{ 0,
  362, 0, 0, 0, 0, 0, 0, 644, 0, 0, 0 },{ -792, 0, 0, 374, 0, 0, 0, 166, 0, 0, 0, 0 },
{ 0, 0, 440, 0, 0, 0, 147, 0, 0, 324, 0, 0 },{ 0, -218, 0, 0, 0, 0, 0, 0, 595, 0, 0,
  0 },{ -455, 0, 0, 280, 0, 0, 0, -20, 0, 0, 0, 0 },{ 0, 0, 569, 0, 0, 0, -276, 0, 0,
  193, 0, 0 },{ 0, 1182, 0, 0, 0, 0, 0, 0, 705, 0, 0, 0 },{ -383, 0, 0, 357, 0, 0, 0,
  -261, 0, 0, 0, 0 },{ 0, 0, 541, 0, 0, 0, -358, 0, 0, 555, 0, 0 },{ 0, 881, 0, 0, 0,
  0, 0, 0, 379, 0, 0, 0 },{ -708, 0, 0, 172, 0, 0, 0, -661, 0, 0, 0, 0 },{ 0, 0, 142,
  0, 0, 0, -784, 0, 0, -19, 0, 0 },{ 0, -394, 0, 0, 0, 0, 0, 0, -415, 0, 0, 0 },
{ -1179, 0, 0, -256, 0, 0, 0, -291, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_facCorMassGrdBurnRg_M[18][12] = { { 0, -589, 0, 0, 0,
  -259, 0, 0, -5313, 0, 0, 0 },{ -6433, 0, 0, 0, 0, 0, 0, 3276, 0, 0, 0, 2549 },{ 0, 0,
  -3277, 0, 0, 0, -4557, 0, 0, 0, 0, 0 },{ 0, 8276, 0, 0, 0, 3352, 0, 0, -157, 0, 0,
  0 },{ -2827, 0, 0, 0, 0, 0, 0, 12028, 0, 0, 0, 2680 },{ 0, 0, 299, 0, 0, 0, -623, 0,
  0, 0, 0, 0 },{ 0, 13228, 0, 0, 0, 1488, 0, 0, 1566, 0, 0, 0 },{ -888, 0, 0, 0, 0, 0,
  0, 7202, 0, 0, 0, 960 },{ 0, 0, 2680, 0, 0, 0, -1272, 0, 0, 0, 0, 0 },{ 0, 2084, 0,
  0, 0, 174, 0, 0, 1030, 0, 0, 0 },{ -1720, 0, 0, 0, 0, 0, 0, -1376, 0, 0, 0, -367 },
{ 0, 0, -738, 0, 0, 0, -1184, 0, 0, 0, 0, 0 },{ 0, -4286, 0, 0, 0, -772, 0, 0,
  -1716, 0, 0, 0 },{ -2584, 0, 0, 0, 0, 0, 0, -4843, 0, 0, 0, -685 },{ 0, 0, -2385, 0,
  0, 0, -2533, 0, 0, 0, 0, 0 },{ 0, -5354, 0, 0, 0, -1064, 0, 0, -2250, 0, 0, 0 },
{ -3776, 0, 0, 0, 0, 0, 0, -6547, 0, 0, 0, -93 },{ 0, 0, -2287, 0, 0, 0, -2819, 0,
  0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_facMassFlowGrdCor_M[18][12] = { { 0, 10131, 0, 0, 0,
  10131, 0, 0, 10131, 0, 0, 0 },{ 10131, 0, 0, 0, 0, 0, 0, 262, 0, 0, 0, 262 },{ 0, 0,
  262, 0, 0, 0, 262, 0, 0, 0, 0, 0 },{ 0, -918, 0, 0, 0, -918, 0, 0, -918, 0, 0, 0 },
{ -918, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0,
  0, 0, -1311, 0, 0, 0, -1311 },{ 0, 0, -1311, 0, 0, 0, -1311, 0, 0, 0, 0, 0 },{ 0,
  -2097, 0, 0, 0, -2097, 0, 0, -2097, 0, 0, 0 },{ -2097, 0, 0, 0, 0, 0, 0, -1835, 0,
  0, 0, -1835 },{ 0, 0, -1835, 0, 0, 0, -1835, 0, 0, 0, 0, 0 },{ 0, -1914, 0, 0, 0,
  -1914, 0, 0, -1914, 0, 0, 0 },{ -1914, 0, 0, 0, 0, 0, 0, -2019, 0, 0, 0, -2019 },{ 0,
  0, -2019, 0, 0, 0, -2019, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_facTGrdBurnCyl_T[15] = { 1200, 1200, 1200, 1200,
  1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200 } ;

CONST(UInt16, AFAT_CARTO) AFA_mfArGrdVlv_rPres_T[22] = { 65535U, 65535U,
  65535U, 65513U, 65421U, 65323U, 65194U, 65012U, 64790U, 64481U, 64072U, 63558U,
  62657U, 61309U, 59158U, 56283U, 49984U, 45609U, 40480U, 40480U, 40480U, 40480U
} ;

CONST(SInt16, AFAT_CARTO) AFA_mfGrdBurnRspgRedBas_M[18][24] = { { 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13,
  0, 0, 0, 26, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 0, 33, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 33, 0, 0, 0, 59, 0, 0, 33, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 72, 0, 0, 0, 69 },{ 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 161, 0, 0, 0,
  82, 0, 0, 49, 0, 0, 0 },{ 13, 0, 0, 0, 0, 0, 0, 242, 0, 0, 0, 105, 0, 0, 79, 0, 0,
  0, 13, 0, 0, 0, 0, 0 },{ 0, 200, 0, 0, 0, 134, 0, 0, 249, 0, 0, 0, 144, 0, 0, 0,
  0, 0, 0, 328, 0, 0, 0, 239 },{ 0, 0, 272, 0, 0, 0, 138, 0, 0, 0, 0, 0, 0, 364, 0,
  0, 0, 236, 0, 0, 229, 0, 0, 0 },{ 203, 0, 0, 0, 0, 0, 0, 436, 0, 0, 0, 292, 0, 0,
  334, 0, 0, 0, 269, 0, 0, 0, 0, 0 },{ 0, 452, 0, 0, 0, 308, 0, 0, 338, 0, 0, 0,
  236, 0, 0, 0, 0, 0, 0, 590, 0, 0, 0, 344 },{ 0, 0, 318, 0, 0, 0, 295, 0, 0, 0, 0,
  0, 0, 557, 0, 0, 0, 410, 0, 0, 387, 0, 0, 0 },{ 344, 0, 0, 0, 0, 0, 0, 560, 0, 0,
  0, 416, 0, 0, 410, 0, 0, 0, 315, 0, 0, 0, 0, 0 },{ 0, 649, 0, 0, 0, 593, 0, 0,
  475, 0, 0, 0, 282, 0, 0, 0, 0, 0, 0, 737, 0, 0, 0, 413 },{ 0, 0, 380, 0, 0, 0,
  393, 0, 0, 0, 0, 0, 0, 678, 0, 0, 0, 406, 0, 0, 547, 0, 0, 0 },{ 383, 0, 0, 0, 0,
  0, 0, 898, 0, 0, 0, 1026, 0, 0, 537, 0, 0, 0, 478, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_mfGrdBurnRspgRedCor_M[18][24] = { { 0, 0, 0, 0, 0, 0,
  0, 0, -275, 0, 0, 0, -452, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, -206, 0, 0,
  0, -413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -62, 0, 0, 0 },{ -472, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, -29, 0, 0, 0, -321, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 59, 0, 0, 0, -187, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 534 },{ 0, 0, 29, 0, 0, 0,
  -102, 0, 0, 0, 0, 0, 0, 43, 0, 0, 0, -455, 0, 0, 59, 0, 0, 0 },{ -111, 0, 0, 0, 0,
  0, 0, 26, 0, 0, 0, -56, 0, 0, 121, 0, 0, 0, -105, 0, 0, 0, 0, 0 },{ 0, 121, 0, 0,
  0, 36, 0, 0, 121, 0, 0, 0, -49, 0, 0, 0, 0, 0, 0, 98, 0, 0, 0, 52 },{ 0, 0, 49, 0,
  0, 0, 36, 0, 0, 0, 0, 0, 0, 118, 0, 0, 0, 79, 0, 0, 69, 0, 0, 0 },{ -16, 0, 0, 0,
  0, 0, 0, 216, 0, 0, 0, 121, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 246, 0, 0,
  0, 164, 0, 0, 125, 0, 0, 0, 39, 0, 0, 0, 0, 0, 0, 324, 0, 0, 0, 619 },{ 0, 0, 393,
  0, 0, 0, 174, 0, 0, 0, 0, 0, 0, 485, 0, 0, 0, 580, 0, 0, 560, 0, 0, 0 },{ 210, 0,
  0, 0, 0, 0, 0, 652, 0, 0, 0, 770, 0, 0, 393, 0, 0, 0, 613, 0, 0, 0, 0, 0 },{ 0,
  724, 0, 0, 0, 665, 0, 0, 652, 0, 0, 0, 626, 0, 0, 0, 0, 0, 0, 931, 0, 0, 0,
  845 },{ 0, 0, 485, 0, 0, 0, 839, 0, 0, 0, 0, 0, 0, 872, 0, 0, 0, 1140, 0, 0, 511,
  0, 0, 0 },{ 999, 0, 0, 0, 0, 0, 0, 963, 0, 0, 0, 1111, 0, 0, 616, 0, 0, 0, 845, 0,
  0, 0, 0, 0 },{ 0, 750, 0, 0, 0, 1570, 0, 0, 672, 0, 0, 0, 885, 0, 0, 0, 0, 0, 0,
  891, 0, 0, 0, 980 },{ 0, 0, 688, 0, 0, 0, 875, 0, 0, 0, 0, 0, 0, 1072, 0, 0, 0,
  960, 0, 0, 668, 0, 0, 0 },{ 845, 0, 0, 0, 0, 0, 0, 1222, 0, 0, 0, 2359, 0, 0, 691,
  0, 0, 0, 396, 0, 0, 0, 0, 0 } } ;

CONST(UInt16, AFAT_CARTO) AFA_nEngRef1_A[3] = { 0U, 1275U, 2750U } ;

CONST(SInt16, AFAT_CARTO) AFA_pGrdBegCorBoostSlopEfc_M[18][12] = { { 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0 } } ;

CONST(UInt16, AFAT_CARTO) AFA_rLdRef1_A[3] = { 0U, 6554U, 11469U } ;

CONST(SInt16, AFAT_CARTO) AFA_rVolCylGrd_agCkClsEx_M[13][12] = { { 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_rVolCylGrd_agCkOpIn_M[12][13] = { { 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } ;

CONST(SInt16, AFAT_CARTO) AFA_rVolGrdCyl_T[19] = { 131, 1796, 5040, 8218, 11298,
  15554, 19431, 21758, 24717, 28819, 28735, 25274, 22361, 19110, 15657, 12190,
  8651, 5177, 1737 } ;

CONST(UInt16, AFAT_CARTO) AFA_tGrdBurnCyl_A[15] = { 2405U, 4005U, 5605U, 7205U,
  8805U, 10405U, 12005U, 13605U, 16005U, 19205U, 22405U, 25605U, 28805U, 32005U,
  36805U } ;

#define AFAT_STOP_SEC_CARTO_16BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define AFAT_START_SEC_CARTO_8BIT
#include "AFAT_MemMap.h"

CONST(UInt8, AFAT_CARTO) AFA_bExVlvAdp_M[16][16] = { { 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } } ;

CONST(UInt8, AFAT_CARTO) AFA_bInVlvAdp_M[16][16] = { { 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U },{ 1U, 1U, 1U, 1U, 1U, 1U, 1U,
  1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U, 1U } } ;

CONST(UInt8, AFAT_CARTO) AFA_noDivEngLd_T[3] = { 1U, 2U, 3U } ;

CONST(UInt8, AFAT_CARTO) AFA_noDivEngSpd_T[3] = { 1U, 2U, 3U } ;

#define AFAT_STOP_SEC_CARTO_8BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AFAT_START_SEC_CALIB_8BIT
#include "AFAT_MemMap.h"

CONST(SInt8, AFAT_CALIB) AFA_agCkClsExVlvOfsIni_C = 0;
CONST(SInt8, AFAT_CALIB) AFA_agCkClsExVlvOfs_B = -128;
CONST(SInt8, AFAT_CALIB) AFA_agCkOpInVlvOfsIni_C = 0;
CONST(SInt8, AFAT_CALIB) AFA_agCkOpInVlvOfs_B = -128;
CONST(UInt8, AFAT_CALIB) AFA_agCkVlvExSat_C = 32U;
CONST(UInt8, AFAT_CALIB) AFA_agCkVlvInSat_C = 32U;
CONST(SInt8, AFAT_CALIB) AFA_arEffEGRVlvOfsIni_C = 0;
CONST(SInt8, AFAT_CALIB) AFA_arEffEGRVlvOfs_B = -50;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValAdpInc_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValClsEGRInc_C = 41U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValClsExInc_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValLamFb_C = 12U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValMdlNotCohInc_C = 41U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValOpInInc_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValPresAirInc_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValPresDsThr_C = 8U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValRstInc_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_covNoiseValThrPosnInc_C = 1U;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs1Ini_C = 0;
CONST(UInt8, AFAT_CALIB) AFA_facArEffThrOfs1Sat_C = 126U;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs1_B = -128;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs2Ini_C = 0;
CONST(UInt8, AFAT_CALIB) AFA_facArEffThrOfs2Sat_C = 126U;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs2_B = -128;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs3Ini_C = 0;
CONST(UInt8, AFAT_CALIB) AFA_facArEffThrOfs3Sat_C = 126U;
CONST(SInt8, AFAT_CALIB) AFA_facArEffThrOfs3_B = -128;
CONST(UInt8, AFAT_CALIB) AFA_facFilPresInjDelta_C = 3U;
CONST(UInt8, AFAT_CALIB) AFA_noAdpClcRst_B = 0U;
CONST(UInt8, AFAT_CALIB) AFA_noAdpEfcDoneDBThd_C = 2U;
CONST(UInt8, AFAT_CALIB) AFA_noAdpEfcEngStopThd_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_noObsDoneIdlThd_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_noObsDone_B = 0U;
CONST(UInt8, AFAT_CALIB) AFA_noObsIdlFirstObsThd_C = 1U;
CONST(UInt8, AFAT_CALIB) AFA_noObsInnovNotCohThd_C = 4U;
CONST(UInt8, AFAT_CALIB) AFA_noObsSpcInjModThd_C = 10U;
CONST(UInt8, AFAT_CALIB) AFA_noRstAdpVal_B = 0U;
CONST(UInt8, AFAT_CALIB) AFA_pAirExtDeltaMinThd_C = 64U;
CONST(UInt8, AFAT_CALIB) AFA_rCorArEffEGRVlvReqSat_C = 255U;
CONST(SInt8, AFAT_CALIB) AFA_rCor_arEffEGRVlvIni_C = 0;
CONST(SInt8, AFAT_CALIB) AFA_rCor_arEffEGRVlv_B = -128;
CONST(UInt8, AFAT_CALIB) AFA_rOpClsThrRawDeltaThd_C = 254U;
CONST(UInt8, AFAT_CALIB) AFA_tiOffInjSat_C = 255U;
CONST(SInt8, AFAT_CALIB) AFA_tiOffInj_B = -128;

#define AFAT_STOP_SEC_CALIB_8BIT
#include "AFAT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AFAT_START_SEC_CALIB_BOOLEAN
#include "AFAT_MemMap.h"

CONST(Boolean, AFAT_CALIB) AFAT_ACTIVE_BYP_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bAcvEngSpdCorScv_C = 1;
CONST(Boolean, AFAT_CALIB) AFA_bAcvEngSpdCorSlop_C = 1;
CONST(Boolean, AFAT_CALIB) AFA_bAcvSpcInjModIni_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bAcvSpcInjMod_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bAuthClsCanPurg_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bClsEGRRef_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bEngStopAuthIni_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bEngStopAuth_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bFitClsExVlvBol_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bFitOpInVlvBol_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bFitPresAirExt_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bFitZeroPosnThr_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bIdcCohLstObs_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpArEffEGROfs_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpArEffTot_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpFacArEffThrOfs1_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpFacArEffThrOfs2_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpFacArEffThrOfs3_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpInjOfs_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpIvsInjGain_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpVlvExOfs_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdpVlvInOfs_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhAdp_pDsThr_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhCalcMod_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhFacEthStoich_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhFacRhoFu_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bInhMaskSen_C = 1;
CONST(Boolean, AFAT_CALIB) AFA_bInnovTestCohDone_B = 0;
CONST(Boolean, AFAT_CALIB) AFA_bSelInjGain_C = 0;
CONST(Boolean, AFAT_CALIB) AFA_bSelPresObs_C = 1;
CONST(Boolean, AFAT_CALIB) AFA_bSelRstCovErrMod_C = 1;

#define AFAT_STOP_SEC_CALIB_BOOLEAN
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
