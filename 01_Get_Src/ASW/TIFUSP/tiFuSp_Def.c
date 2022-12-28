/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tiFuSp                                                  */
/* !Description     : CALCUL DU TEMPS D INJECTION                             */
/*                                                                            */
/* !Module          : tiFuSp                                                  */
/*                                                                            */
/* !File            : tiFuSp_Def.c                                            */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
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
/*   Code generated on: Sun Nov 17 20:13:35 2013                              */
/*   Model name       : tiFuSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.766                                                 */
/*   Root subsystem   : /tiFuSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/TIFUSP/tiFuSp_Def.c_v     $*/
/* $Revision::   1.22                                                        $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "tiFuSp.h"
#include "tiFuSp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "SEC_CALIB_32BIT" */
#define TIFUSP_START_SEC_CALIB_32BIT
#include "tiFuSp_MemMap.h"

CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_A[16] = { 0U, 156U, 313U, 469U,
  625U, 781U, 938U, 1094U, 1250U, 1406U, 1563U, 1719U, 1875U, 2031U, 2188U,
  2344U } ;

CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_C = 313U;
CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInjTotETB_M[256] = { 625U, 631U, 638U,
  647U, 653U, 659U, 666U, 675U, 681U, 688U, 694U, 681U, 666U, 653U, 638U, 625U,
  938U, 947U, 959U, 969U, 978U, 991U, 1000U, 1009U, 1022U, 1031U, 1041U, 1022U,
  1000U, 978U, 959U, 938U, 1250U, 1263U, 1278U, 1291U, 1306U, 1319U, 1334U,
  1347U, 1363U, 1375U, 1388U, 1363U, 1334U, 1306U, 1278U, 1250U, 1563U, 1581U,
  1597U, 1616U, 1631U, 1650U, 1666U, 1684U, 1700U, 1719U, 1738U, 1700U, 1666U,
  1631U, 1597U, 1563U, 1875U, 1897U, 1916U, 1938U, 1959U, 1978U, 2000U, 2022U,
  2041U, 2063U, 2084U, 2041U, 2000U, 1959U, 1916U, 1875U, 2188U, 2213U, 2238U,
  2259U, 2284U, 2309U, 2334U, 2356U, 2381U, 2406U, 2431U, 2381U, 2334U, 2284U,
  2238U, 2188U, 2500U, 2528U, 2556U, 2584U, 2613U, 2638U, 2666U, 2694U, 2722U,
  2750U, 2778U, 2722U, 2666U, 2613U, 2556U, 2500U, 2813U, 2844U, 2875U, 2906U,
  2938U, 2969U, 3000U, 3031U, 3063U, 3094U, 3125U, 3063U, 3000U, 2938U, 2875U,
  2813U, 3125U, 3159U, 3194U, 3228U, 3263U, 3300U, 3334U, 3369U, 3403U, 3438U,
  3472U, 3403U, 3334U, 3263U, 3194U, 3125U, 3438U, 3475U, 3513U, 3553U, 3591U,
  3628U, 3666U, 3706U, 3744U, 3781U, 3819U, 3744U, 3666U, 3591U, 3513U, 3438U,
  3750U, 3791U, 3834U, 3875U, 3916U, 3959U, 4000U, 4041U, 4084U, 4125U, 4166U,
  4084U, 4000U, 3916U, 3834U, 3750U, 4063U, 4106U, 4153U, 4197U, 4244U, 4288U,
  4334U, 4378U, 4425U, 4469U, 4513U, 4425U, 4334U, 4244U, 4153U, 4063U, 4375U,
  4425U, 4472U, 4522U, 4569U, 4619U, 4666U, 4716U, 4763U, 4813U, 4863U, 4763U,
  4666U, 4569U, 4472U, 4375U, 4688U, 4741U, 4791U, 4844U, 4897U, 4947U, 5000U,
  5053U, 5103U, 5156U, 5209U, 5103U, 5000U, 4897U, 4791U, 4688U, 5000U, 5056U,
  5113U, 5166U, 5222U, 5278U, 5334U, 5387U, 5444U, 5500U, 5556U, 5444U, 5334U,
  5222U, 5113U, 5000U, 5313U, 5372U, 5431U, 5491U, 5550U, 5606U, 5666U, 5725U,
  5784U, 5844U, 5903U, 5784U, 5666U, 5550U, 5431U, 5313U } ;

CONST(UInt32, TIFUSP_CALIB) InjrSys_tiInj_A[16] = { 0U, 16U, 31U, 47U, 63U,
  78U, 94U, 109U, 125U, 141U, 156U, 172U, 188U, 203U, 219U, 234U } ;

CONST(UInt32, TIFUSP_CALIB) InjrSys_ti_facCorInjGain_A[9] = { 0U, 156U, 313U,
  469U, 625U, 781U, 938U, 1094U, 1250U } ;

#define TIFUSP_STOP_SEC_CALIB_32BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_16BIT" */
#define TIFUSP_START_SEC_CALIB_16BIT
#include "tiFuSp_MemMap.h"

CONST(UInt16, TIFUSP_CALIB) InjrSys_agEndInjSpcModMax_M[256] = { 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U, 2453U,
  2453U, 2453U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U, 2347U,
  2347U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U, 2240U,
  2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U, 2133U,
  2133U, 2133U, 2133U, 2133U, 2133U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U,
  2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 2027U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U, 1920U,
  1920U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_mFuInjEstimETB_M[256] = { 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 34U, 40U, 47U, 54U, 60U, 67U,
  74U, 81U, 87U, 94U, 101U, 107U, 114U, 121U, 128U, 134U, 67U, 81U, 94U, 107U,
  121U, 134U, 148U, 161U, 174U, 188U, 201U, 215U, 228U, 242U, 255U, 268U, 101U,
  121U, 141U, 161U, 181U, 201U, 221U, 242U, 262U, 282U, 302U, 322U, 342U, 362U,
  383U, 403U, 134U, 161U, 188U, 215U, 242U, 268U, 295U, 322U, 349U, 376U, 403U,
  429U, 456U, 483U, 510U, 537U, 168U, 201U, 235U, 268U, 302U, 336U, 369U, 403U,
  436U, 470U, 503U, 537U, 570U, 604U, 638U, 671U, 201U, 242U, 282U, 322U, 362U,
  403U, 443U, 483U, 523U, 564U, 604U, 644U, 685U, 725U, 765U, 805U, 235U, 282U,
  329U, 376U, 423U, 470U, 517U, 564U, 611U, 658U, 705U, 752U, 799U, 846U, 893U,
  940U, 268U, 322U, 376U, 429U, 483U, 537U, 591U, 644U, 698U, 752U, 805U, 859U,
  913U, 966U, 1020U, 1074U, 302U, 362U, 423U, 483U, 544U, 604U, 664U, 725U, 785U,
  846U, 906U, 966U, 1027U, 1087U, 1148U, 1208U, 336U, 403U, 470U, 537U, 604U,
  671U, 738U, 805U, 872U, 940U, 1007U, 1074U, 1141U, 1208U, 1275U, 1342U, 369U,
  443U, 517U, 591U, 664U, 738U, 812U, 886U, 960U, 1033U, 1107U, 1181U, 1255U,
  1329U, 1403U, 1476U, 403U, 483U, 564U, 644U, 725U, 805U, 886U, 966U, 1047U,
  1127U, 1208U, 1288U, 1369U, 1450U, 1530U, 1611U, 436U, 523U, 611U, 698U, 785U,
  872U, 960U, 1047U, 1134U, 1221U, 1309U, 1396U, 1483U, 1570U, 1658U, 1745U,
  470U, 564U, 658U, 752U, 846U, 940U, 1033U, 1127U, 1221U, 1315U, 1409U, 1503U,
  1597U, 1691U, 1785U, 1879U, 503U, 604U, 705U, 805U, 906U, 1007U, 1107U, 1208U,
  1309U, 1409U, 1510U, 1611U, 1711U, 1812U, 1913U, 2013U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_nEng_facCorInjGain_A[9] = { 500U, 750U,
  1000U, 1500U, 2500U, 3500U, 4500U, 5500U, 6500U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_pFuRailMes_A[16] = { 1280U, 2560U, 3840U,
  5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U,
  17920U, 19200U, 20480U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_pFuRailSplMes_A[16] = { 1280U, 2560U,
  3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U,
  16640U, 17920U, 19200U, 20480U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjH2ETB_C = 16384U;
CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjS1ETB_C = 0U;
CONST(UInt16, TIFUSP_CALIB) InjrSys_rTiInjS2ETB_C = 0U;
CONST(UInt16, TIFUSP_CALIB) InjrSys_tiBtwnInj_A[16] = { 0U, 16U, 31U, 47U, 63U,
  78U, 94U, 109U, 125U, 141U, 156U, 172U, 188U, 203U, 219U, 234U } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_tiInjMin_C = 31U;
CONST(UInt16, TIFUSP_CALIB) InjrSys_tiInjMin_M[128] = { 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U, 94U } ;

CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsCor_A[16] = { -15625, -14594, -13531,
  -12500, -11469, -10406, -9375, -8344, -7281, -6250, -5219, -4156, -3125, -2094,
  -1031, 0 } ;

CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsH2Cor_M[256] = { 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38,
  -37, -37, -36, -35, -34, -33, -35, -34, -34, -33, -32, -32, -31, -30, -30, -29,
  -28, -27, -27, -26, -25, -25, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -8, -8, -7, -7, -7, -7, -7, -7, -7, -6, -6, -6,
  -6, -6, -6, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_tiOfsS1CorH2_M[256] = { 24956U, 24956U,
  24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U,
  24956U, 24956U, 24956U, 24956U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U,
  25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U,
  26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U,
  26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26518U, 26518U, 26518U, 26518U,
  26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U,
  26518U, 26518U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U,
  27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27565U, 27565U,
  27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U,
  27565U, 27565U, 27565U, 27565U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U,
  28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U,
  28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U,
  28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 29127U, 29127U, 29127U, 29127U,
  29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U,
  29127U, 29127U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U,
  29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 30159U, 30159U,
  30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U,
  30159U, 30159U, 30159U, 30159U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U,
  30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U,
  31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U,
  31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31721U, 31721U, 31721U, 31721U,
  31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U,
  31721U, 31721U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U,
  32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsS1Cor_M[256] = { 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -23, -23, -22, -22, -22, -21, -21, -20, -20, -19,
  -19, -18, -18, -17, -17, -16, -18, -17, -17, -17, -16, -16, -15, -15, -15, -14,
  -14, -14, -13, -13, -13, -12, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10,
  -9, -9, -9, -9, -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9,
  -9, -9, -9, -8, -8, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3,
  -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ;

CONST(UInt16, TIFUSP_CALIB) InjrSys_tiOfsS2CorS1_M[256] = { 24956U, 24956U,
  24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U, 24956U,
  24956U, 24956U, 24956U, 24956U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U,
  25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U, 25471U,
  26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26002U,
  26002U, 26002U, 26002U, 26002U, 26002U, 26002U, 26518U, 26518U, 26518U, 26518U,
  26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U, 26518U,
  26518U, 26518U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U,
  27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27034U, 27565U, 27565U,
  27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U, 27565U,
  27565U, 27565U, 27565U, 27565U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U,
  28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U, 28081U,
  28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 28596U,
  28596U, 28596U, 28596U, 28596U, 28596U, 28596U, 29127U, 29127U, 29127U, 29127U,
  29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U, 29127U,
  29127U, 29127U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U,
  29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 29643U, 30159U, 30159U,
  30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U, 30159U,
  30159U, 30159U, 30159U, 30159U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U,
  30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U, 30690U,
  31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31205U,
  31205U, 31205U, 31205U, 31205U, 31205U, 31205U, 31721U, 31721U, 31721U, 31721U,
  31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U, 31721U,
  31721U, 31721U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U,
  32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32252U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U,
  32768U, 32768U, 32768U, 32768U } ;

CONST(SInt16, TIFUSP_CALIB) InjrSys_tiOfsS2Cor_M[256] = { 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10,
  -9, -9, -9, -9, -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9,
  -9, -9, -9, -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9,
  -9, -9, -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9,
  -9, -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9,
  -8, -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8,
  -8, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8, -8,
  -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8, -8, -12,
  -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8, -8, -12, -11,
  -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -8, -8, -9, -9, -8, -8,
  -8, -8, -8, -8, -7, -7, -7, -7, -7, -7, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5,
  -5, -5, -5, -5, -4, -4, -4, -4, -6, -6, -6, -6, -5, -5, -5, -5, -5, -5, -5, -5,
  -4, -4, -4, -4, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ;

#define TIFUSP_STOP_SEC_CALIB_16BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_8BIT" */
#define TIFUSP_START_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

CONST(UInt8, TIFUSP_CALIB) InjrSys_IdxInjrMdlInj_A[8] = { 1U, 2U, 3U, 4U, 5U,
  6U, 7U, 8U } ;

CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl1_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl2_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl3_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl4_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl5_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facCorInjETBCyl6_C = 128U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_facFuSysCor_M[81] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U }
;

CONST(UInt8, TIFUSP_CALIB) InjrSys_noETBSelMassFuEstim_C = 2U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_noETBSelMassFuReq_C = 1U;
CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsH2CorPFu_T[16] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U }
;

CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsS1CorPFu_T[16] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U }
;

CONST(UInt8, TIFUSP_CALIB) InjrSys_tiOfsS2CorPFu_T[16] = { 128U, 128U, 128U,
  128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U }
;

CONST(UInt8, TIFUSP_CALIB) TIFUSP_u8Inhib = 0U;

#define TIFUSP_STOP_SEC_CALIB_8BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_CALIB_BOOLEAN" */
#define TIFUSP_START_SEC_CALIB_BOOLEAN
#include "tiFuSp_MemMap.h"

CONST(Boolean, TIFUSP_CALIB) InjrSys_bAcvMFuInjCmprCyl_C = 0;
CONST(Boolean, TIFUSP_CALIB) InjrSys_bAcvTiInjETB_C = 0;

#define TIFUSP_STOP_SEC_CALIB_BOOLEAN
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_32BIT" */
#define TIFUSP_START_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

VAR(Float32, TIFUSP_VAR) InjrSys_agBegInjH1;
VAR(Float32, TIFUSP_VAR) InjrSys_agWdInjSpcModMax;
VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjH1[2];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjH2[2];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS1[2];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS1Prev[2];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_agEndInjS2Prev[2];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_facGain[6];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_facGainCor[6];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_mFuInjReq[6];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiEfcInj_MP[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiH2ReqCylPrev[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInj[4];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1ReqCyl[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1TmpCyl[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH1TmpCylPrev[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjH2ReqCyl[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjMFu[4];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjReq[6];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiInjReqSat[6];
VAR(Float32, TIFUSP_VAR) InjrSys_prm_tiInjReqSatMin[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjS1ReqCyl[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiInjS2ReqCyl[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiS1ReqCylPrev[6];
VAR(UInt32, TIFUSP_VAR) InjrSys_prm_tiS2ReqCylPrev[6];
VAR(Float32, TIFUSP_VAR) InjrSys_tiInjSpcModMax;

#define TIFUSP_STOP_SEC_VAR_32BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_16BIT" */
#define TIFUSP_START_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

VAR(UInt16, TIFUSP_VAR) InjrSys_mFuInjEstim;
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjH1[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjH2[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS1[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS1Prev[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS2[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_agBegInjS2Prev[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjH2Req[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjS1Req[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_mFuInjS2Req[2];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiInjOfs[6];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiInjOfsCor[6];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsCor[6];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsH2Cor[2];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS1Cor[2];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS2Cor[2];
VAR(SInt16, TIFUSP_VAR) InjrSys_prm_tiOfsS2CorPrev[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevH2[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevS1[2];
VAR(UInt16, TIFUSP_VAR) InjrSys_prm_tiWoutInjPrevS2[2];

#define TIFUSP_STOP_SEC_VAR_16BIT
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_BOOLEAN" */
#define TIFUSP_START_SEC_VAR_BOOLEAN
#include "tiFuSp_MemMap.h"

VAR(Boolean, TIFUSP_VAR) InjrSys_bAcvRstrtSTT;
VAR(Boolean, TIFUSP_VAR) InjrSys_prm_bDettiInjMin[6];

#define TIFUSP_STOP_SEC_VAR_BOOLEAN
#include "tiFuSp_MemMap.h"

/* !Comment: Define data in section "SEC_VAR_8BIT" */
#define TIFUSP_START_SEC_VAR_8BIT
#include "tiFuSp_MemMap.h"

VAR(UInt8, TIFUSP_VAR) InjrSys_facCorInjETBCmpr;
VAR(UInt8, TIFUSP_VAR) InjrSys_facCorInjETBIn;

#define TIFUSP_STOP_SEC_VAR_8BIT
#include "tiFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
