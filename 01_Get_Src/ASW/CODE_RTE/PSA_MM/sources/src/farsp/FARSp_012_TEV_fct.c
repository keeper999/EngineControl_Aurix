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
* %name: FARSp_012_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:53 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_012_TEV_fct.c-3.0:csrc:3 %
*
*******************************************************************************/


#ifndef _FARSP_012_TEV_FCT_C_
#define _FARSP_012_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_012_TEV_fct.h"
#include "FARSp_012_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE012_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE012_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE012_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtTWCHeatSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facBasModCur_in[16];
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facBasModTar_in[16];
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facTranMod_in[16];AR_IF_GLOBAL_8BIT 
UInt8 FARSp_RE012_EOM_prm_idxBas1ModCur_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE012_EOM_prm_idxBas1ModTar_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE012_EOM_prm_idxBas2ModCur_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE012_EOM_prm_idxBas2ModTar_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE012_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE012_EOM_bTWCHeatPha_in;AR_IF_GLOBAL_BOOLEAN
 Boolean FARSp_RE012_TWCMgt_bLiOffDone_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bAcvRatMixtTWCHeat_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_16BIT UInt16 z53720b9e7c59297bd94585182414125b;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 zc8e45bf47b30762e1c3f531afbb93b04;static UInt16 
z12f2ad3f4ca1900544747952218b81f7;static UInt16 
z45df858a4eec5f56c821636a744e1e05;static UInt16 
z580feba146489235c897c52d9ab568e0;static UInt16 
z222493c5caa2c2fe9874c889d3f7e88f;static UInt16 
z7ac73ce71ed38b031fc6967db977cef3;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z4e6c5029de565e4b70a97a4351d06e38;static UInt8 
z8c5412ddb357e30e247074cb96865664;static UInt8 z908d2d6bcec9e6edc17cbfaa91892995
;static UInt8 zb14ea42a45fb60e1837a035bdd69f50f;static UInt8 
z371c692504afaeb5cb3d90ded1c1384e;static UInt8 zed62b8fdf92ac3da23fe4312360f801e
;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_011_MSE_ini(Void){FARSp_012_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_012_TEV_fct(Void){SInt32 z0c5b298f248925a85188f6fda39977f5;SInt32 
z02260e058831cf0b5f62754ff2fb2654;SInt32 z25c61b268ff9697be9b73c1bd5a493a2;
SInt32 z866b29dd55741ae22b8b976739e3ed84;SInt32 
z57b992dcd837ee1f2d7e5678bc0224b2;SInt32 z5ad7fe7dab504ba7c8e1d94f83a27e63;
SInt32 z7af72bce84e10edecc66977a3914d96d;SInt32 
zd650afc343aeb1ec9555de02c66034be;SInt32 zb61107fccc123f9f5a95e1f88a40999e;
SInt32 ze5f7fbc0e90daae2099d5d33dfa86543;UInt16 
z7e363f030fd7ff5a7052e720c6d685e8;UInt16 z4cc020f2cb81414ce0b513af3b19e8f6;
UInt16 z06070af8df90ae71143028fe62150a58;UInt16 
zf8482acfed016cba76d0ce7a04dd5022;UInt16 z1e0b58398dc3e0db707a75c0dc2eb1a2;
UInt16 z715a9e3a26823ca65ca87c93b2c82db1;UInt16 
z15320f799caf1b2050993f4e488c7b8f;UInt16 z89ff735f5b18ce0bc5ce911e8efb4232;
UInt16 z1a4ffd127562d20dd82ffc6b57148f96;UInt16 
zbe285b2d4f286e27b264ac3c4c8bd85c;UInt16 z6bfd608c91d52694a125459a5af1671e;
UInt16 z11e67c978ce575caf9c7c65d5ba214e8;UInt16 
z280e753f1bce0588d0f6717ef6a5b9ac;Boolean z94098ee30444c9815aeb642784a80500[4];
Boolean zc6b9d4ec8b2f47f260cff3a7e0ff1c46[4];Boolean 
z1c63d6087602bd3b4ecc5020ce1aa009[4];Boolean z57c91f3425850ee59dd4a3d64d770330;
Boolean zfae7e5c7354dd14705ea22fe0fd023b2;Boolean 
zb1c381dc9d1bef2ef57d2b4ea3f787de;Boolean zd8558855a43f2e498c165709e69b86c4;
Boolean z74efe080b9cf8c192ff191ef95146758;Boolean 
z741deabd1b2c01c90297005e2c3d134a;Boolean z9bc6e9b63279479e396ac96133389440;
Boolean z3dc49e464e34eea0fc913d303a082216;Boolean 
z0178150a73ac92b63777632f122d0db3;Boolean z716960ba6d8620fb48c680b62b818b8b;
Boolean ze7d9c0ad273070ff44ac82db94cbca6d;Boolean 
z980add21afeca8f0dede26a380456a82;UInt16 z6aef5c1bd1b6e842408a5c8546f4670a;
UInt16 z8a32e8d845d1f17c84c918e08dcfca18;UInt16 
z9e8893cbbbf79c6c88d6ce42c26ffe2b;UInt16 z6e734a09d7304fa17b93518ecee7e65d;
UInt16 z5213e430c4516eeb20925e0e3195cd78;FARSp_facTWCHeatSpFlex=
FARSp_RE012_FARSp_prm_facGasFlexSp_in[9];if(FARSp_facTWCHeatSpFlex<=0){
z716960ba6d8620fb48c680b62b818b8b=1;}else{z716960ba6d8620fb48c680b62b818b8b=0;}
FARSp_facTWCHeatSpGas=FARSp_RE012_FARSp_prm_facGasFlexSp_in[8];if(
FARSp_facTWCHeatSpGas<=0){z3dc49e464e34eea0fc913d303a082216=1;}else{
z3dc49e464e34eea0fc913d303a082216=0;}FARSp_facBasModTar=
FARSp_RE012_EOM_prm_facBasModTar_in[5];if(FARSp_facBasModTar<=0){
z741deabd1b2c01c90297005e2c3d134a=1;}else{z741deabd1b2c01c90297005e2c3d134a=0;}
FARSp_facTranMod=FARSp_RE012_EOM_prm_facTranMod_in[5];if(FARSp_facTranMod<=0){
zd8558855a43f2e498c165709e69b86c4=1;}else{zd8558855a43f2e498c165709e69b86c4=0;}
FARSp_facBasModCur=FARSp_RE012_EOM_prm_facBasModCur_in[5];if(FARSp_facBasModCur
<=0){zfae7e5c7354dd14705ea22fe0fd023b2=1;}else{zfae7e5c7354dd14705ea22fe0fd023b2
=0;}if(128<=FARSp_facTWCHeatSpFlex){z0178150a73ac92b63777632f122d0db3=1;}else{
z0178150a73ac92b63777632f122d0db3=0;}if(128<=FARSp_facTWCHeatSpGas){
z9bc6e9b63279479e396ac96133389440=1;}else{z9bc6e9b63279479e396ac96133389440=0;}
if(128<=FARSp_facBasModTar){z74efe080b9cf8c192ff191ef95146758=1;}else{
z74efe080b9cf8c192ff191ef95146758=0;}if(128<=FARSp_facTranMod){
zb1c381dc9d1bef2ef57d2b4ea3f787de=1;}else{zb1c381dc9d1bef2ef57d2b4ea3f787de=0;}
if(128<=FARSp_facBasModCur){z57c91f3425850ee59dd4a3d64d770330=1;}else{
z57c91f3425850ee59dd4a3d64d770330=0;}if(!(FARSp_RE012_TWCMgt_bLiOffDone_in)){
ze7d9c0ad273070ff44ac82db94cbca6d=1;}else{ze7d9c0ad273070ff44ac82db94cbca6d=0;}
if(ze7d9c0ad273070ff44ac82db94cbca6d&&FARSp_RE012_EOM_bTWCHeatPha_in){
z980add21afeca8f0dede26a380456a82=1;}else{z980add21afeca8f0dede26a380456a82=0;}
FARSp_bAcvRatMixtTWCHeat=z980add21afeca8f0dede26a380456a82;
z6aef5c1bd1b6e842408a5c8546f4670a=(UInt16)(((UInt16)FARSp_facTWCHeatSpGas)<<5);
if(z6aef5c1bd1b6e842408a5c8546f4670a>0){zbe285b2d4f286e27b264ac3c4c8bd85c=
z6aef5c1bd1b6e842408a5c8546f4670a;}else{zbe285b2d4f286e27b264ac3c4c8bd85c=0;}if(
4096<zbe285b2d4f286e27b264ac3c4c8bd85c){z6bfd608c91d52694a125459a5af1671e=4096;}
else{z6bfd608c91d52694a125459a5af1671e=zbe285b2d4f286e27b264ac3c4c8bd85c;}
FARSp_rMixtTWCHeatSpGas=FARSp_RE012_FARSp_prm_rMixtGasFlexSp_in[8];
z8a32e8d845d1f17c84c918e08dcfca18=(UInt16)(((UInt16)FARSp_facTWCHeatSpFlex)<<5);
if(z8a32e8d845d1f17c84c918e08dcfca18>0){z11e67c978ce575caf9c7c65d5ba214e8=
z8a32e8d845d1f17c84c918e08dcfca18;}else{z11e67c978ce575caf9c7c65d5ba214e8=0;}if(
4096<z11e67c978ce575caf9c7c65d5ba214e8){z280e753f1bce0588d0f6717ef6a5b9ac=4096;}
else{z280e753f1bce0588d0f6717ef6a5b9ac=z11e67c978ce575caf9c7c65d5ba214e8;}
FARSp_rMixtTWCHeatSpFlex=FARSp_RE012_FARSp_prm_rMixtGasFlexSp_in[9];
z9e8893cbbbf79c6c88d6ce42c26ffe2b=(UInt16)(((UInt16)FARSp_facTranMod)<<5);if(
z9e8893cbbbf79c6c88d6ce42c26ffe2b>0){z1e0b58398dc3e0db707a75c0dc2eb1a2=
z9e8893cbbbf79c6c88d6ce42c26ffe2b;}else{z1e0b58398dc3e0db707a75c0dc2eb1a2=0;}if(
4096<z1e0b58398dc3e0db707a75c0dc2eb1a2){z715a9e3a26823ca65ca87c93b2c82db1=4096;}
else{z715a9e3a26823ca65ca87c93b2c82db1=z1e0b58398dc3e0db707a75c0dc2eb1a2;}
z6e734a09d7304fa17b93518ecee7e65d=(UInt16)(((UInt16)FARSp_facBasModTar)<<5);if(
z6e734a09d7304fa17b93518ecee7e65d>0){z15320f799caf1b2050993f4e488c7b8f=
z6e734a09d7304fa17b93518ecee7e65d;}else{z15320f799caf1b2050993f4e488c7b8f=0;}if(
4096<z15320f799caf1b2050993f4e488c7b8f){z89ff735f5b18ce0bc5ce911e8efb4232=4096;}
else{z89ff735f5b18ce0bc5ce911e8efb4232=z15320f799caf1b2050993f4e488c7b8f;}
FARSp_idxBas1ModCur=C__U8SATU8_SATu(FARSp_RE012_EOM_prm_idxBas1ModCur_in[5],4);
z94098ee30444c9815aeb642784a80500[0]=0;z94098ee30444c9815aeb642784a80500[1]=0;
z94098ee30444c9815aeb642784a80500[2]=0;z94098ee30444c9815aeb642784a80500[3]=0;
z94098ee30444c9815aeb642784a80500[FARSp_idxBas1ModCur-1]=1;FARSp_idxBas2ModCur=
C__U8SATU8_SATu(FARSp_RE012_EOM_prm_idxBas2ModCur_in[5],4);
zc6b9d4ec8b2f47f260cff3a7e0ff1c46[0]=z94098ee30444c9815aeb642784a80500[0];
zc6b9d4ec8b2f47f260cff3a7e0ff1c46[1]=z94098ee30444c9815aeb642784a80500[1];
zc6b9d4ec8b2f47f260cff3a7e0ff1c46[2]=z94098ee30444c9815aeb642784a80500[2];
zc6b9d4ec8b2f47f260cff3a7e0ff1c46[3]=z94098ee30444c9815aeb642784a80500[3];
zc6b9d4ec8b2f47f260cff3a7e0ff1c46[FARSp_idxBas2ModCur-1]=1;FARSp_idxBas1ModTar=
C__U8SATU8_SATu(FARSp_RE012_EOM_prm_idxBas1ModTar_in[5],4);
z1c63d6087602bd3b4ecc5020ce1aa009[0]=zc6b9d4ec8b2f47f260cff3a7e0ff1c46[0];
z1c63d6087602bd3b4ecc5020ce1aa009[1]=zc6b9d4ec8b2f47f260cff3a7e0ff1c46[1];
z1c63d6087602bd3b4ecc5020ce1aa009[2]=zc6b9d4ec8b2f47f260cff3a7e0ff1c46[2];
z1c63d6087602bd3b4ecc5020ce1aa009[3]=zc6b9d4ec8b2f47f260cff3a7e0ff1c46[3];
z1c63d6087602bd3b4ecc5020ce1aa009[FARSp_idxBas1ModTar-1]=1;FARSp_idxBas2ModTar=
C__U8SATU8_SATu(FARSp_RE012_EOM_prm_idxBas2ModTar_in[5],4);
FARSp_prm_bAcvTWCHeatCal[0]=z1c63d6087602bd3b4ecc5020ce1aa009[0];
FARSp_prm_bAcvTWCHeatCal[1]=z1c63d6087602bd3b4ecc5020ce1aa009[1];
FARSp_prm_bAcvTWCHeatCal[2]=z1c63d6087602bd3b4ecc5020ce1aa009[2];
FARSp_prm_bAcvTWCHeatCal[3]=z1c63d6087602bd3b4ecc5020ce1aa009[3];
FARSp_prm_bAcvTWCHeatCal[FARSp_idxBas2ModTar-1]=1;FARSp_bAcvCal1=
FARSp_prm_bAcvTWCHeatCal[0];if(FARSp_bAcvCal1>0){TabIdxS50T513((const UInt16*)
FARSp_nEngTWCHeatCal1X_A,8,FARSp_RE012_Ext_nEng_in,&(
z8c5412ddb357e30e247074cb96865664),&(z12f2ad3f4ca1900544747952218b81f7));
TabIdxS50T513((const UInt16*)FARSp_rAirLdTWCHeatCal1Y_A,8,
FARSp_RE012_EngM_rAirLdCor_in,&(z4e6c5029de565e4b70a97a4351d06e38),&(
zc8e45bf47b30762e1c3f531afbb93b04));FARSp_rMixtTWCHeatCal1=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtTWCHeatCal1_M[0][0]),8,
z8c5412ddb357e30e247074cb96865664,z12f2ad3f4ca1900544747952218b81f7,
z4e6c5029de565e4b70a97a4351d06e38,zc8e45bf47b30762e1c3f531afbb93b04);}
FARSp_bAcvCal2=FARSp_prm_bAcvTWCHeatCal[1];if(FARSp_bAcvCal2>0){TabIdxS50T513((
const UInt16*)FARSp_nEngTWCHeatCal2X_A,8,FARSp_RE012_Ext_nEng_in,&(
zb14ea42a45fb60e1837a035bdd69f50f),&(z580feba146489235c897c52d9ab568e0));
TabIdxS50T513((const UInt16*)FARSp_rAirLdTWCHeatCal2Y_A,8,
FARSp_RE012_EngM_rAirLdCor_in,&(z908d2d6bcec9e6edc17cbfaa91892995),&(
z45df858a4eec5f56c821636a744e1e05));FARSp_rMixtTWCHeatCal2=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtTWCHeatCal2_M[0][0]),8,
zb14ea42a45fb60e1837a035bdd69f50f,z580feba146489235c897c52d9ab568e0,
z908d2d6bcec9e6edc17cbfaa91892995,z45df858a4eec5f56c821636a744e1e05);}
FARSp_bAcvCal3=FARSp_prm_bAcvTWCHeatCal[2];if(FARSp_bAcvCal3>0){TabIdxS50T513((
const UInt16*)FARSp_nEngTWCHeatCal3X_A,8,FARSp_RE012_Ext_nEng_in,&(
zed62b8fdf92ac3da23fe4312360f801e),&(z7ac73ce71ed38b031fc6967db977cef3));
TabIdxS50T513((const UInt16*)FARSp_rAirLdTWCHeatCal3Y_A,8,
FARSp_RE012_EngM_rAirLdCor_in,&(z371c692504afaeb5cb3d90ded1c1384e),&(
z222493c5caa2c2fe9874c889d3f7e88f));FARSp_rMixtTWCHeatCal3=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtTWCHeatCal3_M[0][0]),8,
zed62b8fdf92ac3da23fe4312360f801e,z7ac73ce71ed38b031fc6967db977cef3,
z371c692504afaeb5cb3d90ded1c1384e,z222493c5caa2c2fe9874c889d3f7e88f);}
FARSp_bAcvCal4=FARSp_prm_bAcvTWCHeatCal[3];if(FARSp_bAcvCal4>0){
z53720b9e7c59297bd94585182414125b=4096;}FARSp_prm_rMixtTWCHeatCal[0]=
FARSp_rMixtTWCHeatCal1;FARSp_prm_rMixtTWCHeatCal[1]=FARSp_rMixtTWCHeatCal2;
FARSp_prm_rMixtTWCHeatCal[2]=FARSp_rMixtTWCHeatCal3;FARSp_prm_rMixtTWCHeatCal[3]
=z53720b9e7c59297bd94585182414125b;switch(FARSp_idxBas1ModTar){case 1:{
FARSp_rMixtTWCHeatBas1ModTar=FARSp_prm_rMixtTWCHeatCal[0];break;}case 2:{
FARSp_rMixtTWCHeatBas1ModTar=FARSp_prm_rMixtTWCHeatCal[1];break;}case 3:{
FARSp_rMixtTWCHeatBas1ModTar=FARSp_prm_rMixtTWCHeatCal[2];break;}case 4:{
FARSp_rMixtTWCHeatBas1ModTar=FARSp_prm_rMixtTWCHeatCal[3];break;}default:{}}
switch(FARSp_idxBas2ModTar){case 1:{FARSp_rMixtTWCHeatBas2ModTar=
FARSp_prm_rMixtTWCHeatCal[0];break;}case 2:{FARSp_rMixtTWCHeatBas2ModTar=
FARSp_prm_rMixtTWCHeatCal[1];break;}case 3:{FARSp_rMixtTWCHeatBas2ModTar=
FARSp_prm_rMixtTWCHeatCal[2];break;}case 4:{FARSp_rMixtTWCHeatBas2ModTar=
FARSp_prm_rMixtTWCHeatCal[3];break;}default:{}}z5ad7fe7dab504ba7c8e1d94f83a27e63
=(SInt32)(((UInt32)FARSp_rMixtTWCHeatBas1ModTar)-((UInt32)
FARSp_rMixtTWCHeatBas2ModTar));z57b992dcd837ee1f2d7e5678bc0224b2=(SInt32)((((
SInt32)z89ff735f5b18ce0bc5ce911e8efb4232)*z5ad7fe7dab504ba7c8e1d94f83a27e63)>>12
);z4cc020f2cb81414ce0b513af3b19e8f6=(UInt16)(((UInt16)
z57b992dcd837ee1f2d7e5678bc0224b2)+FARSp_rMixtTWCHeatBas2ModTar);
z5213e430c4516eeb20925e0e3195cd78=(UInt16)(((UInt16)FARSp_facBasModCur)<<5);if(
z5213e430c4516eeb20925e0e3195cd78>0){z06070af8df90ae71143028fe62150a58=
z5213e430c4516eeb20925e0e3195cd78;}else{z06070af8df90ae71143028fe62150a58=0;}if(
4096<z06070af8df90ae71143028fe62150a58){zf8482acfed016cba76d0ce7a04dd5022=4096;}
else{zf8482acfed016cba76d0ce7a04dd5022=z06070af8df90ae71143028fe62150a58;}switch
(FARSp_idxBas1ModCur){case 1:{FARSp_rMixtTWCHeatBas1ModCur=
FARSp_prm_rMixtTWCHeatCal[0];break;}case 2:{FARSp_rMixtTWCHeatBas1ModCur=
FARSp_prm_rMixtTWCHeatCal[1];break;}case 3:{FARSp_rMixtTWCHeatBas1ModCur=
FARSp_prm_rMixtTWCHeatCal[2];break;}case 4:{FARSp_rMixtTWCHeatBas1ModCur=
FARSp_prm_rMixtTWCHeatCal[3];break;}default:{}}switch(FARSp_idxBas2ModCur){case 
1:{FARSp_rMixtTWCHeatBas2ModCur=FARSp_prm_rMixtTWCHeatCal[0];break;}case 2:{
FARSp_rMixtTWCHeatBas2ModCur=FARSp_prm_rMixtTWCHeatCal[1];break;}case 3:{
FARSp_rMixtTWCHeatBas2ModCur=FARSp_prm_rMixtTWCHeatCal[2];break;}case 4:{
FARSp_rMixtTWCHeatBas2ModCur=FARSp_prm_rMixtTWCHeatCal[3];break;}default:{}}
z02260e058831cf0b5f62754ff2fb2654=(SInt32)(((UInt32)FARSp_rMixtTWCHeatBas1ModCur
)-((UInt32)FARSp_rMixtTWCHeatBas2ModCur));z0c5b298f248925a85188f6fda39977f5=(
SInt32)((((SInt32)zf8482acfed016cba76d0ce7a04dd5022)*
z02260e058831cf0b5f62754ff2fb2654)>>12);z7e363f030fd7ff5a7052e720c6d685e8=(
UInt16)(((UInt16)z0c5b298f248925a85188f6fda39977f5)+FARSp_rMixtTWCHeatBas2ModCur
);z866b29dd55741ae22b8b976739e3ed84=(SInt32)(((UInt32)
z4cc020f2cb81414ce0b513af3b19e8f6)-((UInt32)z7e363f030fd7ff5a7052e720c6d685e8));
z25c61b268ff9697be9b73c1bd5a493a2=(SInt32)((((SInt32)
z715a9e3a26823ca65ca87c93b2c82db1)*z866b29dd55741ae22b8b976739e3ed84)>>12);
FARSp_rMixtTWCHeatSpGsl=(UInt16)(((UInt16)z25c61b268ff9697be9b73c1bd5a493a2)+
z7e363f030fd7ff5a7052e720c6d685e8);ze5f7fbc0e90daae2099d5d33dfa86543=(SInt32)(((
UInt32)FARSp_rMixtTWCHeatSpFlex)-((UInt32)FARSp_rMixtTWCHeatSpGsl));
zb61107fccc123f9f5a95e1f88a40999e=(SInt32)((((SInt32)
z280e753f1bce0588d0f6717ef6a5b9ac)*ze5f7fbc0e90daae2099d5d33dfa86543)>>12);
FARSp_rMixtTWCHeatFlex_MP=(UInt16)(((UInt16)zb61107fccc123f9f5a95e1f88a40999e)+
FARSp_rMixtTWCHeatSpGsl);zd650afc343aeb1ec9555de02c66034be=(SInt32)(((UInt32)
FARSp_rMixtTWCHeatSpGas)-((UInt32)FARSp_rMixtTWCHeatFlex_MP));
z7af72bce84e10edecc66977a3914d96d=(SInt32)((((SInt32)
z6bfd608c91d52694a125459a5af1671e)*zd650afc343aeb1ec9555de02c66034be)>>12);
FARSp_rMixtTWCHeatSpRaw=(UInt16)(((UInt16)z7af72bce84e10edecc66977a3914d96d)+
FARSp_rMixtTWCHeatFlex_MP);if(z980add21afeca8f0dede26a380456a82!=0){
FARSp_rMixtTWCHeatSp=FARSp_rMixtTWCHeatSpRaw;}else{FARSp_rMixtTWCHeatSp=4096;}
FARSp_bAcvRatMixtTWCHeat_out=FARSp_bAcvRatMixtTWCHeat;
z1a4ffd127562d20dd82ffc6b57148f96=FARSp_rMixtTWCHeatSp;FARSp_rMixtTWCHeatSp_out=
z1a4ffd127562d20dd82ffc6b57148f96;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_012_FctVarInit(Void){FARSp_rMixtTWCHeatCal1=0;FARSp_rMixtTWCHeatCal2=
0;FARSp_rMixtTWCHeatCal3=0;FARSp_rMixtTWCHeatSp_out=4096;
zc8e45bf47b30762e1c3f531afbb93b04=0;z4e6c5029de565e4b70a97a4351d06e38=0;
z12f2ad3f4ca1900544747952218b81f7=0;z8c5412ddb357e30e247074cb96865664=0;
z45df858a4eec5f56c821636a744e1e05=0;z908d2d6bcec9e6edc17cbfaa91892995=0;
z580feba146489235c897c52d9ab568e0=0;zb14ea42a45fb60e1837a035bdd69f50f=0;
z222493c5caa2c2fe9874c889d3f7e88f=0;z371c692504afaeb5cb3d90ded1c1384e=0;
z7ac73ce71ed38b031fc6967db977cef3=0;zed62b8fdf92ac3da23fe4312360f801e=0;
z53720b9e7c59297bd94585182414125b=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

