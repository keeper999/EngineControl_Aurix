/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: FARSp_010_TEV_fct.c %
*
* %version: 4.0.build2 %
*
* %date_modified: Wed Jun 27 09:04:49 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_010_TEV_fct.c-4.0.build2:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_010_TEV_FCT_C_
#define _FARSP_010_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_010_TEV_fct.h"
#include "FARSp_010_calibrations.h"
#include "dsfxp.h"
#include "FARSp_calibrations.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT SInt16 FARSp_RE010_CoHeat_tCoEstimStrt_in;AR_IF_GLOBAL_16BIT 
SInt16 FARSp_RE010_CoHeat_tCoEstim_in;AR_IF_GLOBAL_16BIT SInt16 
FARSp_RE010_Ext_tCoMes_in;AR_IF_GLOBAL_16BIT SInt16 
FARSp_RE010_Ext_tCoStrtMes_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE010_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE010_InjSys_ctNbCmbAst_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtAstWupSTTSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_32BIT UInt32 FARSp_RE010_EOM_tiEngStopRst_in;AR_IF_GLOBAL_32BIT 
UInt32 FARSp_RE010_Ext_tiAst_in;
#define FARSP_STOP_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE010_CoPTSt_tCoMesRStrtSTT_in;AR_IF_GLOBAL_8BIT 
UInt8 FARSp_RE010_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_CoHeat_bAcvHeatMgt_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_CoPTSt_bRStrtSTT_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_FRM_bLihAstWupSTT_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 zdbbc965a9a7e12fc07d49a74ee4298e0;static UInt16 
zfd037a61fe9a3ddb9f4f6c6513f79ba0;static UInt16 
z57d9ef2a0bada7bf236a4f8a2468f2ae;static UInt16 
za97c483343c9ee652a17af58606a8fd8;static UInt16 
z4b8b180123732901e00868bdfbc53512;static UInt16 
z48acfd246095d75f57d59cc862d6d994;static UInt16 
zb9f7bd13cb30d8fdcae201feed22d2c5;static UInt16 
zdae12794616d1dc8d9dc1c1beda6cf61;static UInt16 
z8b2112f4c6b9189d0cc70d5f22c80a02;static UInt16 
zd222186d748856922e88cf0666407dc1;static UInt16 
z8cef369909fdc2324f7244e3af7de6de;static UInt16 
zb58e2378760620aa530d37be392421ae;static UInt16 
z2fff5495b0b2a2e5225f3ff53b14c42d;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_32BIT SInt32 z541bf422cd215514349e84622c95cf07;AR_SEC_VAR_32BIT 
UInt32 z05a6e990ff8581148b05482b4caff0ba;AR_SEC_VAR_32BIT SInt32 
ze76d36b52ecabab8ff095bb58ca13c3f;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z886428d1f479e05e05c5a7ec9a7f382c;static UInt8 
z6bc086f8b8a09f733a3f78ceb4b4900c;static UInt8 z1f9ec3bc64e2efd6f5a9f7ae9753e360
;static UInt8 ze265b491542e200d80319e3f0bb7c30b;static UInt8 
z677ca4eea23f9ad4f442abcd12177ed2;static UInt8 z7054ffd059acd7da8ac3664fa2036833
;static UInt8 z942b59c6b1c6eca2470a2f8455bb1ebb;static UInt8 
z02d044d69cf441c7b09eaf64ad8a906a;static UInt8 ze3055759321138148537d57c9b729e66
;static UInt8 zde219646ff2f7b31f0199e3c3d1a2d2b;static UInt8 
z271c86c0a5ee5dde6b2072fa6ff3909b;static UInt8 z7390d359cbcceb90788088f1771f1d07
;static UInt8 z8a93d561819a6c9479a3aa067f3f9d75;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_SEC_VAR_BOOLEAN Boolean za3b95fe021b1b7557e12f7cefbbce983;AR_SEC_VAR_BOOLEAN 
Boolean za7a69071b7b38612462536449b8d6665;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_009_MSE_ini(Void){FARSp_010_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_010_TEV_fct(Void){SInt32 zab3973934e3d745c1765436585ccb5fd;SInt32 
z64aedc9ee321452bf9f69fc75f00e468;SInt32 zd4878cf137abc655e2056a8cca334a04;
SInt32 zb736ad9516ed087738d3ebde60697982;SInt32 
zf2e9439ec34ea972c328238948f6d17c;SInt32 zfdb2cc5d38db127fb6b2bea6f213d0e1;
SInt32 z8e4d8b9139e8a65a62bb0777c309ca89;SInt32 
zb092c88a48544a542a46d6b377c31723;UInt32 z27b88c8aef9bdfc82053a6ae93e1c3c4;
SInt32 z166bf68c74bcdbcc5b653c06fa6197ff;SInt32 
z82ed213bf17555e68aedbb72c5347ed9;SInt32 z9a42c8f9ee95e37174722976ab86f2a4;
SInt32 z1f908626031e646e4e91446411fc6d6a;SInt32 
zd50976da57244fb25394cb8e834e639f;UInt32 z64857587729cd78d12042211be75c572;
UInt32 z6cdc98b608e29222ce2aae77cb0c41c4;SInt32 
z939536e8ea0a11abb9442180d8a5655c;SInt32 zc75114a7176b6aa05730d13c4119b341;
SInt32 z62c330519754d90de3b0ce1417f83fc0;SInt32 
zc0862b5b80515cc3878a216cccbaccdb;SInt32 z384b0e36041370ec96faf65b6899f911;
SInt32 za6744abbb13408cd4a9b057a1eb85e72;SInt32 
z64350aa70c6694b1e07b014c9c976551;SInt32 z676925920573cd8bcc743d5cd362fb7e;
SInt32 zbf368011ef854ed91c2828bd971c8a53;SInt32 
z31a1b53c1346c88fb40e637e360a47b3;UInt32 z00534134b71b22ec5de50e408abde5d1;
UInt32 z530dbd9320ebf9cc1b6992a7bdd12eec;UInt32 
z24bcf2aaa456f95c5cc8477e0db51b8f;UInt16 zb8a66c97722a855d0f475b7f3ca21eb3;
UInt16 zddfc88a671144ae46e71779ab30108dc;UInt16 
z4508bfae300cc4c460c1e3f042083a76;UInt16 z33efe2afc52a0bb3284f0b9952c30a7e;
UInt16 zbdf479a1f92dfbdb0048ef90eb448509;UInt16 
z67cbc9072638b1b1d03d0d4a5d86c702;UInt16 z52f5f45c40bea8dc6d815155ddc7b283;
UInt16 zb9a05ad14805fdd0a83f580eda8b706d;UInt8 z7729b1cb3b0681c1df8cc4728a972735
;UInt8 z3b660f48afb80bb74ab05a093920979e;Boolean 
ze124684e8020275bff17ba272f6b8848;Boolean z15274c67cdb8b2677788180f50adbb08;
UInt8 z9af59b5badd307f519b5c5eb529c4ee9;UInt8 z93fa2665160a8c87ce72c327877e9f18;
Boolean z57888219031e7c7f71a0159083b511c7;Boolean 
zbfba42ae5a848b1cd4006f4ec47db7ce;UInt8 z44de24bfe4c1cf33435049addd0e4757;UInt8 
z193ce0aee6a4b6f07077de9fa966194e;Boolean zb11f91cc54ed5c61dbf22792f795ba85;
Boolean z9ff58ad054faf9beda3a4c3f5be38841;Boolean 
z2628d875497f18420b41f5333cf14800;Boolean z92a210ef888051fe9e1b2c4967dd8cc9;
Boolean ze8d2ba4a4e613deb26ddd848f5d0315c;Boolean 
z7cf8d02c0d5753920e8e95925383b30d;UInt8 zbb1740655a4682673ce332a5fe07337e;UInt8 
z0e72ec99b0c48fceac7643aba0528624;UInt8 z73f643845a0ba43135a0ae2c95942734;
Boolean z48c91f7a41cc392af53823b9b35597a4;Boolean 
z1dd05397ca2251fca42067abac293cc9;Boolean ze8d69de49912dc90fabb4f30afc33471;
Boolean z78ccb4de14e83a66a7699c3d4b1aab2b;UInt8 
z1c7982e71e5ba0bfb18e2601be12bf99;SInt32 z411b1fdbfe2607cafd1a5b8d6f62cbed;
UInt32 z6ed381dde86082b97ed90c539a2bbdb9;if(FARSp_RE010_EOM_tiEngStopRst_in<=0){
z7cf8d02c0d5753920e8e95925383b30d=1;}else{z7cf8d02c0d5753920e8e95925383b30d=0;}
if(FARSp_RE010_EOM_tiEngStopRst_in>0){z00534134b71b22ec5de50e408abde5d1=
FARSp_RE010_EOM_tiEngStopRst_in;}else{z00534134b71b22ec5de50e408abde5d1=0;}if(
65535<z00534134b71b22ec5de50e408abde5d1){z530dbd9320ebf9cc1b6992a7bdd12eec=65535
;}else{z530dbd9320ebf9cc1b6992a7bdd12eec=z00534134b71b22ec5de50e408abde5d1;}
TabIdxS50T513((const UInt16*)FARSp_tiEngModSTT_A,16,(UInt16)
z530dbd9320ebf9cc1b6992a7bdd12eec,&(z8a93d561819a6c9479a3aa067f3f9d75),&(
z2fff5495b0b2a2e5225f3ff53b14c42d));zbb1740655a4682673ce332a5fe07337e=
Tab1DIntp2I1T64((const UInt8*)FARSp_facRatMixtSTTCor_T,
z8a93d561819a6c9479a3aa067f3f9d75,z2fff5495b0b2a2e5225f3ff53b14c42d);if(
zbb1740655a4682673ce332a5fe07337e<=0){z1dd05397ca2251fca42067abac293cc9=1;}else{
z1dd05397ca2251fca42067abac293cc9=0;}if(65535<=FARSp_RE010_EOM_tiEngStopRst_in){
ze8d2ba4a4e613deb26ddd848f5d0315c=1;}else{ze8d2ba4a4e613deb26ddd848f5d0315c=0;}
if(128<=zbb1740655a4682673ce332a5fe07337e){z48c91f7a41cc392af53823b9b35597a4=1;}
else{z48c91f7a41cc392af53823b9b35597a4=0;}if(FARSp_RE010_FRM_bLihAstWupSTT_in>0)
{if(FARSp_RE010_Ext_tiAst_in>0){z64857587729cd78d12042211be75c572=
FARSp_RE010_Ext_tiAst_in;}else{z64857587729cd78d12042211be75c572=0;}if(65535<
z64857587729cd78d12042211be75c572){z6cdc98b608e29222ce2aae77cb0c41c4=65535;}else
{z6cdc98b608e29222ce2aae77cb0c41c4=z64857587729cd78d12042211be75c572;}if(
z6cdc98b608e29222ce2aae77cb0c41c4>=((UInt32)FARSp_tiAstDeacAstWupLih_C)){
FARSp_bAstWupRatLimAcv_MP=1;}else{FARSp_bAstWupRatLimAcv_MP=0;}if(
FARSp_bAstWupRatLimAcv_MP!=0){z52f5f45c40bea8dc6d815155ddc7b283=4096;}else{
z52f5f45c40bea8dc6d815155ddc7b283=FARSp_rMixtAstWupSpLihIni_C;}if(
FARSp_RE010_Ext_tiAst_in<=0){z92a210ef888051fe9e1b2c4967dd8cc9=1;}else{
z92a210ef888051fe9e1b2c4967dd8cc9=0;}if(65535<=FARSp_RE010_Ext_tiAst_in){
z2628d875497f18420b41f5333cf14800=1;}else{z2628d875497f18420b41f5333cf14800=0;}
z939536e8ea0a11abb9442180d8a5655c=0;if(za7a69071b7b38612462536449b8d6665!=0){
z64350aa70c6694b1e07b014c9c976551=ze76d36b52ecabab8ff095bb58ca13c3f;}else{
z64350aa70c6694b1e07b014c9c976551=(SInt32)(((UInt32)
z52f5f45c40bea8dc6d815155ddc7b283)<<12);}z62c330519754d90de3b0ce1417f83fc0=(
SInt32)(((UInt32)(SInt32)(((UInt32)z52f5f45c40bea8dc6d815155ddc7b283)<<12))-((
UInt32)z64350aa70c6694b1e07b014c9c976551));zc75114a7176b6aa05730d13c4119b341=(
SInt32)(((UInt32)(((SInt32)(((UInt32)FARSp_tiSdlFARSp_C)*((UInt32)
FARSp_rMixtSpGrdNegWupLih_C)))*82))-((UInt32)(SInt32)((((UInt32)
FARSp_tiSdlFARSp_C)*25165824)/5)));if(z62c330519754d90de3b0ce1417f83fc0>
zc75114a7176b6aa05730d13c4119b341){z384b0e36041370ec96faf65b6899f911=
z62c330519754d90de3b0ce1417f83fc0;}else{z384b0e36041370ec96faf65b6899f911=
zc75114a7176b6aa05730d13c4119b341;}if(z939536e8ea0a11abb9442180d8a5655c<
z384b0e36041370ec96faf65b6899f911){za6744abbb13408cd4a9b057a1eb85e72=
z939536e8ea0a11abb9442180d8a5655c;}else{za6744abbb13408cd4a9b057a1eb85e72=
z384b0e36041370ec96faf65b6899f911;}zc0862b5b80515cc3878a216cccbaccdb=(SInt32)(((
UInt32)za6744abbb13408cd4a9b057a1eb85e72)+((UInt32)
z64350aa70c6694b1e07b014c9c976551));if(FARSp_bAstWupRatLimAcv_MP!=0){
FARSp_rMixtAstWupSpLih=zc0862b5b80515cc3878a216cccbaccdb;}else{
FARSp_rMixtAstWupSpLih=(SInt32)(((UInt32)z52f5f45c40bea8dc6d815155ddc7b283)<<12)
;}ze76d36b52ecabab8ff095bb58ca13c3f=FARSp_rMixtAstWupSpLih;
za7a69071b7b38612462536449b8d6665=1;}if(zbb1740655a4682673ce332a5fe07337e>0){
z0e72ec99b0c48fceac7643aba0528624=zbb1740655a4682673ce332a5fe07337e;}else{
z0e72ec99b0c48fceac7643aba0528624=0;}if(128<z0e72ec99b0c48fceac7643aba0528624){
z73f643845a0ba43135a0ae2c95942734=128;}else{z73f643845a0ba43135a0ae2c95942734=
z0e72ec99b0c48fceac7643aba0528624;}if(FARSp_RE010_Ext_tCoMes_in<=
FARSp_tCoMesThdAfsWupSTTEna_C){ze8d69de49912dc90fabb4f30afc33471=1;}else{
ze8d69de49912dc90fabb4f30afc33471=0;}FARSp_rMixtAstWupSTTSpPrev=
z05a6e990ff8581148b05482b4caff0ba;if(((UInt16)(z05a6e990ff8581148b05482b4caff0ba
>>12))>=FARSp_rMixtThdAfsWupSTTEna_C){z78ccb4de14e83a66a7699c3d4b1aab2b=1;}else{
z78ccb4de14e83a66a7699c3d4b1aab2b=0;}if(ze8d69de49912dc90fabb4f30afc33471||
z78ccb4de14e83a66a7699c3d4b1aab2b||FARSp_RE010_CoHeat_bAcvHeatMgt_in){
FARSp_bAcvRatMixtAstWupSTTSp=1;}else{FARSp_bAcvRatMixtAstWupSTTSp=0;}if(
FARSp_bAcvRatMixtAstWupSTTSp>0){SInt32 z6aef5c1bd1b6e842408a5c8546f4670a;SInt32 
z8a32e8d845d1f17c84c918e08dcfca18;SInt32 zf2db5999c2eb295c38ea65e87793add2;
UInt32 z7a5324c7539cb46c4a9459c152a42e3f;SInt32 
zcb4212a0d00d75016670ed5391d4bb1d;UInt32 z1cb1a1497410b13813fdd4a83b2f0925;
UInt32 z1f8568e2a312eeded13d6e88817fdf9c;UInt32 
zcf8c1dcf09c7e455cb239c5fc102b1bb;UInt32 z47ab5c3e9fe9e65bb42cb7a45b6e5b2a;
UInt32 zd3b057973ce65de3986e0516c640f7ca;SInt32 
z5edc5c6579989cb0858aeba89f7e6ad6;UInt32 z7b29269501f129ef42ed14aa3302c970;
SInt32 z1c3821acc5f8190f68679dc8d4841e4a;UInt32 
z81c68cf2db807602ed9512da3dd26be0;SInt16 z9e8893cbbbf79c6c88d6ce42c26ffe2b;if(
FARSp_RE010_CoHeat_bAcvHeatMgt_in!=0){z1c7982e71e5ba0bfb18e2601be12bf99=1;}else{
z1c7982e71e5ba0bfb18e2601be12bf99=0;}FARSp_facAstWupSpFlex=
FARSp_RE010_FARSp_prm_facGasFlexSp_in[7];if(FARSp_facAstWupSpFlex<=0){
z9ff58ad054faf9beda3a4c3f5be38841=1;}else{z9ff58ad054faf9beda3a4c3f5be38841=0;}
FARSp_facAstWupSpGas=FARSp_RE010_FARSp_prm_facGasFlexSp_in[6];if(
FARSp_facAstWupSpGas<=0){zbfba42ae5a848b1cd4006f4ec47db7ce=1;}else{
zbfba42ae5a848b1cd4006f4ec47db7ce=0;}zb736ad9516ed087738d3ebde60697982=((SInt32)
FARSp_tiSdlFARSp_C)*((SInt32)FARSp_facTranIncWupCoHeat_C);if(
za3b95fe021b1b7557e12f7cefbbce983!=0){z166bf68c74bcdbcc5b653c06fa6197ff=
z541bf422cd215514349e84622c95cf07;}else{z166bf68c74bcdbcc5b653c06fa6197ff=(
SInt32)(((UInt32)z1c7982e71e5ba0bfb18e2601be12bf99)<<24);}
zf2e9439ec34ea972c328238948f6d17c=(SInt32)(((UInt32)(SInt32)(((UInt32)
z1c7982e71e5ba0bfb18e2601be12bf99)<<24))-((UInt32)
z166bf68c74bcdbcc5b653c06fa6197ff));zd4878cf137abc655e2056a8cca334a04=(SInt32)((
(UInt32)(((SInt32)FARSp_tiSdlFARSp_C)*((SInt32)FARSp_facTranDecWupCoHeat_C)))-((
UInt32)(((SInt32)FARSp_tiSdlFARSp_C)*51200)));C__I64SHLI32C6_LT32(
zd4878cf137abc655e2056a8cca334a04,13,19,zf2db5999c2eb295c38ea65e87793add2,
z7a5324c7539cb46c4a9459c152a42e3f);C__I64DIVI64U32(
zf2db5999c2eb295c38ea65e87793add2,z7a5324c7539cb46c4a9459c152a42e3f,(UInt32)25,
zcb4212a0d00d75016670ed5391d4bb1d,z1cb1a1497410b13813fdd4a83b2f0925);
z6aef5c1bd1b6e842408a5c8546f4670a=(SInt32)z1cb1a1497410b13813fdd4a83b2f0925;if(
zf2e9439ec34ea972c328238948f6d17c>z6aef5c1bd1b6e842408a5c8546f4670a){
z8e4d8b9139e8a65a62bb0777c309ca89=zf2e9439ec34ea972c328238948f6d17c;}else{
z8e4d8b9139e8a65a62bb0777c309ca89=z6aef5c1bd1b6e842408a5c8546f4670a;}
C__U64SHLI32C6_LT32(zb736ad9516ed087738d3ebde60697982,13,19,
z1f8568e2a312eeded13d6e88817fdf9c,zcf8c1dcf09c7e455cb239c5fc102b1bb);
C__U64DIVU64U32(z1f8568e2a312eeded13d6e88817fdf9c,
zcf8c1dcf09c7e455cb239c5fc102b1bb,(UInt32)25,z47ab5c3e9fe9e65bb42cb7a45b6e5b2a,
zd3b057973ce65de3986e0516c640f7ca);z8a32e8d845d1f17c84c918e08dcfca18=(SInt32)
zd3b057973ce65de3986e0516c640f7ca;if(z8a32e8d845d1f17c84c918e08dcfca18<
z8e4d8b9139e8a65a62bb0777c309ca89){zb092c88a48544a542a46d6b377c31723=
z8a32e8d845d1f17c84c918e08dcfca18;}else{zb092c88a48544a542a46d6b377c31723=
z8e4d8b9139e8a65a62bb0777c309ca89;}zfdb2cc5d38db127fb6b2bea6f213d0e1=(SInt32)(((
UInt32)zb092c88a48544a542a46d6b377c31723)+((UInt32)
z166bf68c74bcdbcc5b653c06fa6197ff));if(1){FARSp_facTranAstWupCoHeat_MP=
zfdb2cc5d38db127fb6b2bea6f213d0e1;}else{FARSp_facTranAstWupCoHeat_MP=(SInt32)(((
UInt32)z1c7982e71e5ba0bfb18e2601be12bf99)<<24);}if(FARSp_facTranAstWupCoHeat_MP
<=0){z15274c67cdb8b2677788180f50adbb08=1;}else{z15274c67cdb8b2677788180f50adbb08
=0;}if(128<=FARSp_facAstWupSpFlex){zb11f91cc54ed5c61dbf22792f795ba85=1;}else{
zb11f91cc54ed5c61dbf22792f795ba85=0;}if(128<=FARSp_facAstWupSpGas){
z57888219031e7c7f71a0159083b511c7=1;}else{z57888219031e7c7f71a0159083b511c7=0;}
if(16777216<=FARSp_facTranAstWupCoHeat_MP){ze124684e8020275bff17ba272f6b8848=1;}
else{ze124684e8020275bff17ba272f6b8848=0;}if(FARSp_facAstWupSpGas>0){
z9af59b5badd307f519b5c5eb529c4ee9=FARSp_facAstWupSpGas;}else{
z9af59b5badd307f519b5c5eb529c4ee9=0;}if(128<z9af59b5badd307f519b5c5eb529c4ee9){
z93fa2665160a8c87ce72c327877e9f18=128;}else{z93fa2665160a8c87ce72c327877e9f18=
z9af59b5badd307f519b5c5eb529c4ee9;}FARSp_rMixtAstWupSpGas=
FARSp_RE010_FARSp_prm_rMixtGasFlexSp_in[6];if(FARSp_facAstWupSpFlex>0){
z44de24bfe4c1cf33435049addd0e4757=FARSp_facAstWupSpFlex;}else{
z44de24bfe4c1cf33435049addd0e4757=0;}if(128<z44de24bfe4c1cf33435049addd0e4757){
z193ce0aee6a4b6f07077de9fa966194e=128;}else{z193ce0aee6a4b6f07077de9fa966194e=
z44de24bfe4c1cf33435049addd0e4757;}FARSp_rMixtAstWupSpFlex=
FARSp_RE010_FARSp_prm_rMixtGasFlexSp_in[7];z9e8893cbbbf79c6c88d6ce42c26ffe2b=(
SInt16)(FARSp_facTranAstWupCoHeat_MP>>17);if(z9e8893cbbbf79c6c88d6ce42c26ffe2b>0
){z7729b1cb3b0681c1df8cc4728a972735=(UInt8)z9e8893cbbbf79c6c88d6ce42c26ffe2b;}
else{z7729b1cb3b0681c1df8cc4728a972735=0;}if(128<
z7729b1cb3b0681c1df8cc4728a972735){z3b660f48afb80bb74ab05a093920979e=128;}else{
z3b660f48afb80bb74ab05a093920979e=z7729b1cb3b0681c1df8cc4728a972735;}
TabIdxS50T516((const SInt16*)FARSp_tCoMesWupCoHeatX_A,12,
FARSp_RE010_CoHeat_tCoEstim_in,&(z02d044d69cf441c7b09eaf64ad8a906a),&(
zdae12794616d1dc8d9dc1c1beda6cf61));TabIdxS50T516((const SInt16*)
FARSp_tCoStrtMesWupCoHeatY_A,12,FARSp_RE010_CoHeat_tCoEstimStrt_in,&(
z942b59c6b1c6eca2470a2f8455bb1ebb),&(zb9f7bd13cb30d8fdcae201feed22d2c5));
z33efe2afc52a0bb3284f0b9952c30a7e=Tab2DIntp2I1T33281((const UInt16*)&(
FARSp_rMixtWupCoHeatSp_M[0][0]),12,z02d044d69cf441c7b09eaf64ad8a906a,
zdae12794616d1dc8d9dc1c1beda6cf61,z942b59c6b1c6eca2470a2f8455bb1ebb,
zb9f7bd13cb30d8fdcae201feed22d2c5);TabIdxS50T516((const SInt16*)
FARSp_tCoMesAstCoHeatX_A,12,FARSp_RE010_CoHeat_tCoEstimStrt_in,&(
z6bc086f8b8a09f733a3f78ceb4b4900c),&(zfd037a61fe9a3ddb9f4f6c6513f79ba0));
TabIdxS50T513((const UInt16*)FARSp_ctNbCmbAstCoHeatY_A,12,
FARSp_RE010_InjSys_ctNbCmbAst_in,&(z886428d1f479e05e05c5a7ec9a7f382c),&(
zdbbc965a9a7e12fc07d49a74ee4298e0));zb8a66c97722a855d0f475b7f3ca21eb3=
Tab2DIntp2I1T33281((const UInt16*)&(FARSp_rMixtAstCoHeatSp_M[0][0]),12,
z6bc086f8b8a09f733a3f78ceb4b4900c,zfd037a61fe9a3ddb9f4f6c6513f79ba0,
z886428d1f479e05e05c5a7ec9a7f382c,zdbbc965a9a7e12fc07d49a74ee4298e0);if(
z33efe2afc52a0bb3284f0b9952c30a7e>zb8a66c97722a855d0f475b7f3ca21eb3){
FARSp_rMixtAstWupCoHeatSp_MP=z33efe2afc52a0bb3284f0b9952c30a7e;}else{
FARSp_rMixtAstWupCoHeatSp_MP=zb8a66c97722a855d0f475b7f3ca21eb3;}TabIdxS50T516((
const SInt16*)FARSp_tCoMesWupSTTX_A,12,FARSp_RE010_Ext_tCoMes_in,&(
z7390d359cbcceb90788088f1771f1d07),&(zb58e2378760620aa530d37be392421ae));
TabIdxS50T516((const SInt16*)FARSp_tCoMesRStrtWupSTTY_A,12,(SInt16)(((UInt16)
FARSp_RE010_CoPTSt_tCoMesRStrtSTT_in)-40),&(z271c86c0a5ee5dde6b2072fa6ff3909b),&
(z8cef369909fdc2324f7244e3af7de6de));z67cbc9072638b1b1d03d0d4a5d86c702=
Tab2DIntp2I1T33281((const UInt16*)&(FARSp_rMixtWupSTTSp_M[0][0]),12,
z7390d359cbcceb90788088f1771f1d07,zb58e2378760620aa530d37be392421ae,
z271c86c0a5ee5dde6b2072fa6ff3909b,z8cef369909fdc2324f7244e3af7de6de);
TabIdxS50T516((const SInt16*)FARSp_tCoMesRStrtAstSTTX_A,12,(SInt16)(((UInt16)
FARSp_RE010_CoPTSt_tCoMesRStrtSTT_in)-40),&(z7054ffd059acd7da8ac3664fa2036833),&
(z48acfd246095d75f57d59cc862d6d994));TabIdxS50T513((const UInt16*)
FARSp_ctNbCmbAstSTTY_A,12,FARSp_RE010_InjSys_ctNbCmbAst_in,&(
z677ca4eea23f9ad4f442abcd12177ed2),&(z4b8b180123732901e00868bdfbc53512));
z4508bfae300cc4c460c1e3f042083a76=Tab2DIntp2I1T33281((const UInt16*)&(
FARSp_rMixtAstSTTSp_M[0][0]),12,z7054ffd059acd7da8ac3664fa2036833,
z48acfd246095d75f57d59cc862d6d994,z677ca4eea23f9ad4f442abcd12177ed2,
z4b8b180123732901e00868bdfbc53512);if(z67cbc9072638b1b1d03d0d4a5d86c702>
z4508bfae300cc4c460c1e3f042083a76){FARSp_rMixtAstWupSTTSp_MP=
z67cbc9072638b1b1d03d0d4a5d86c702;}else{FARSp_rMixtAstWupSTTSp_MP=
z4508bfae300cc4c460c1e3f042083a76;}TabIdxS50T516((const SInt16*)
FARSp_tCoMesWupNormX_A,12,FARSp_RE010_Ext_tCoMes_in,&(
zde219646ff2f7b31f0199e3c3d1a2d2b),&(zd222186d748856922e88cf0666407dc1));
TabIdxS50T516((const SInt16*)FARSp_tCoStrtMesWupNormY_A,12,
FARSp_RE010_Ext_tCoStrtMes_in,&(ze3055759321138148537d57c9b729e66),&(
z8b2112f4c6b9189d0cc70d5f22c80a02));zbdf479a1f92dfbdb0048ef90eb448509=
Tab2DIntp2I1T33281((const UInt16*)&(FARSp_rMixtWupNormSp_M[0][0]),12,
zde219646ff2f7b31f0199e3c3d1a2d2b,zd222186d748856922e88cf0666407dc1,
ze3055759321138148537d57c9b729e66,z8b2112f4c6b9189d0cc70d5f22c80a02);
TabIdxS50T516((const SInt16*)FARSp_tCoMesAstNormX_A,12,
FARSp_RE010_Ext_tCoStrtMes_in,&(ze265b491542e200d80319e3f0bb7c30b),&(
za97c483343c9ee652a17af58606a8fd8));TabIdxS50T513((const UInt16*)
FARSp_ctNbCmbAstNormY_A,12,FARSp_RE010_InjSys_ctNbCmbAst_in,&(
z1f9ec3bc64e2efd6f5a9f7ae9753e360),&(z57d9ef2a0bada7bf236a4f8a2468f2ae));
zddfc88a671144ae46e71779ab30108dc=Tab2DIntp2I1T33281((const UInt16*)&(
FARSp_rMixtAstNormSp_M[0][0]),12,ze265b491542e200d80319e3f0bb7c30b,
za97c483343c9ee652a17af58606a8fd8,z1f9ec3bc64e2efd6f5a9f7ae9753e360,
z57d9ef2a0bada7bf236a4f8a2468f2ae);if(zbdf479a1f92dfbdb0048ef90eb448509>
zddfc88a671144ae46e71779ab30108dc){FARSp_rMixtAstWupNormSp_MP=
zbdf479a1f92dfbdb0048ef90eb448509;}else{FARSp_rMixtAstWupNormSp_MP=
zddfc88a671144ae46e71779ab30108dc;}if(FARSp_RE010_CoPTSt_bRStrtSTT_in!=0){
zb9a05ad14805fdd0a83f580eda8b706d=FARSp_rMixtAstWupSTTSp_MP;}else{
zb9a05ad14805fdd0a83f580eda8b706d=FARSp_rMixtAstWupNormSp_MP;}
z64aedc9ee321452bf9f69fc75f00e468=(SInt32)(((UInt32)FARSp_rMixtAstWupCoHeatSp_MP
)-((UInt32)zb9a05ad14805fdd0a83f580eda8b706d));zab3973934e3d745c1765436585ccb5fd
=(SInt32)((((SInt32)z3b660f48afb80bb74ab05a093920979e)*
z64aedc9ee321452bf9f69fc75f00e468)<<5);FARSp_rMixtAstWupSpGsl=(UInt32)(
zab3973934e3d745c1765436585ccb5fd+((UInt32)(((UInt32)
zb9a05ad14805fdd0a83f580eda8b706d)<<12)));zd50976da57244fb25394cb8e834e639f=(
SInt32)(((UInt32)(SInt32)(((UInt32)FARSp_rMixtAstWupSpFlex)<<12))-
FARSp_rMixtAstWupSpGsl);F__I64MULU32I32((UInt32)
z193ce0aee6a4b6f07077de9fa966194e,zd50976da57244fb25394cb8e834e639f,&(
z5edc5c6579989cb0858aeba89f7e6ad6),&(z7b29269501f129ef42ed14aa3302c970));
z1f908626031e646e4e91446411fc6d6a=C__I32SHRI64C6_LT32(
z5edc5c6579989cb0858aeba89f7e6ad6,z7b29269501f129ef42ed14aa3302c970,7,25);
FARSp_rMixtAstWupFlex_MP=(UInt32)(z1f908626031e646e4e91446411fc6d6a+
FARSp_rMixtAstWupSpGsl);z9a42c8f9ee95e37174722976ab86f2a4=(SInt32)(((UInt32)(
SInt32)(((UInt32)FARSp_rMixtAstWupSpGas)<<12))-FARSp_rMixtAstWupFlex_MP);
F__I64MULU32I32((UInt32)z93fa2665160a8c87ce72c327877e9f18,
z9a42c8f9ee95e37174722976ab86f2a4,&(z1c3821acc5f8190f68679dc8d4841e4a),&(
z81c68cf2db807602ed9512da3dd26be0));z82ed213bf17555e68aedbb72c5347ed9=
C__I32SHRI64C6_LT32(z1c3821acc5f8190f68679dc8d4841e4a,
z81c68cf2db807602ed9512da3dd26be0,7,25);FARSp_rMixtAstWupSpRaw=(SInt32)(
z82ed213bf17555e68aedbb72c5347ed9+FARSp_rMixtAstWupFlex_MP);
z541bf422cd215514349e84622c95cf07=FARSp_facTranAstWupCoHeat_MP;
za3b95fe021b1b7557e12f7cefbbce983=1;}zbf368011ef854ed91c2828bd971c8a53=(SInt32)(
((UInt32)FARSp_rMixtAstWupSpRaw)-16777216);F__I64MULU32I32((UInt32)
z73f643845a0ba43135a0ae2c95942734,zbf368011ef854ed91c2828bd971c8a53,&(
z411b1fdbfe2607cafd1a5b8d6f62cbed),&(z6ed381dde86082b97ed90c539a2bbdb9));
z676925920573cd8bcc743d5cd362fb7e=C__I32SHRI64C6_LT32(
z411b1fdbfe2607cafd1a5b8d6f62cbed,z6ed381dde86082b97ed90c539a2bbdb9,7,25);
z31a1b53c1346c88fb40e637e360a47b3=(SInt32)(((UInt32)
z676925920573cd8bcc743d5cd362fb7e)+16777216);if(FARSp_bAcvRatMixtAstWupSTTSp!=0)
{z24bcf2aaa456f95c5cc8477e0db51b8f=(UInt32)z31a1b53c1346c88fb40e637e360a47b3;}
else{z24bcf2aaa456f95c5cc8477e0db51b8f=16777216;}if(
FARSp_RE010_FRM_bLihAstWupSTT_in!=0){FARSp_rMixtAstWupSTTSp=(UInt32)
FARSp_rMixtAstWupSpLih;}else{FARSp_rMixtAstWupSTTSp=
z24bcf2aaa456f95c5cc8477e0db51b8f;}z27b88c8aef9bdfc82053a6ae93e1c3c4=
FARSp_rMixtAstWupSTTSp;FARSp_rMixtAstWupSTTSp_out=(UInt16)(
z27b88c8aef9bdfc82053a6ae93e1c3c4>>12);z05a6e990ff8581148b05482b4caff0ba=
FARSp_rMixtAstWupSTTSp;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_010_FctVarInit(Void){FARSp_RE010_Ext_tCoMes_in=0;
FARSp_rMixtAstWupSpLih=0;FARSp_rMixtAstWupSpRaw=0;
zdbbc965a9a7e12fc07d49a74ee4298e0=0;z886428d1f479e05e05c5a7ec9a7f382c=0;
zfd037a61fe9a3ddb9f4f6c6513f79ba0=0;z6bc086f8b8a09f733a3f78ceb4b4900c=0;
z57d9ef2a0bada7bf236a4f8a2468f2ae=0;z1f9ec3bc64e2efd6f5a9f7ae9753e360=0;
za97c483343c9ee652a17af58606a8fd8=0;ze265b491542e200d80319e3f0bb7c30b=0;
z4b8b180123732901e00868bdfbc53512=0;z677ca4eea23f9ad4f442abcd12177ed2=0;
z48acfd246095d75f57d59cc862d6d994=0;z7054ffd059acd7da8ac3664fa2036833=0;
zb9f7bd13cb30d8fdcae201feed22d2c5=0;z942b59c6b1c6eca2470a2f8455bb1ebb=0;
zdae12794616d1dc8d9dc1c1beda6cf61=0;z02d044d69cf441c7b09eaf64ad8a906a=0;
z8b2112f4c6b9189d0cc70d5f22c80a02=0;ze3055759321138148537d57c9b729e66=0;
zd222186d748856922e88cf0666407dc1=0;zde219646ff2f7b31f0199e3c3d1a2d2b=0;
z8cef369909fdc2324f7244e3af7de6de=0;z271c86c0a5ee5dde6b2072fa6ff3909b=0;
zb58e2378760620aa530d37be392421ae=0;z7390d359cbcceb90788088f1771f1d07=0;
z2fff5495b0b2a2e5225f3ff53b14c42d=0;z8a93d561819a6c9479a3aa067f3f9d75=0;
z541bf422cd215514349e84622c95cf07=0;za3b95fe021b1b7557e12f7cefbbce983=0;
z05a6e990ff8581148b05482b4caff0ba=0;ze76d36b52ecabab8ff095bb58ca13c3f=0;
za7a69071b7b38612462536449b8d6665=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

