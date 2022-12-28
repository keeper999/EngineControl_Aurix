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
* %name: FARSp_026_TEV_fct.c %
*
* %version: 5.0.build1 %
*
* %date_modified: Tue Aug  7 11:14:57 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_026_TEV_fct.c-5.0.build1:csrc:2 %
*
*******************************************************************************/


#ifndef _FARSP_026_TEV_FCT_C_
#define _FARSP_026_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_RE026_calibrations.h"
#include "FARSp_026_TEV_fct.h"
#define FARSP_START_SEC_CONST_UNSPECIFIED
#include "FARSp_MemMap.h"
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4196 
z6c1f462dcf3beb6044ea2c2a4df7b839={12,12,(const SInt16*)&(
FARSp_tCoMesWupNormEthX_A[0]),(const SInt16*)&(FARSp_tCoStrtMesWupNormEthY_A[0])
,(const UInt16*)&(FARSp_rMixtWupNormEthSp_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4172 
z42a7432f38f1a21a154246ee212ee774={12,12,(const SInt16*)&(
FARSp_tCoMesAstNormEthX_A[0]),(const UInt16*)&(FARSp_ctNbCmbAstNormEthY_A[0]),(
const UInt16*)&(FARSp_rMixtAstNormEthSp_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4164 
z55e9433fc1b69e63b07c5a0c55112ace={12,12,(const SInt16*)&(
FARSp_tCoMesWupSTTEthX_A[0]),(const UInt8*)&(FARSp_tCoMesRStrtWupSTTEthY_A[0]),(
const UInt16*)&(FARSp_rMixtWupSTTEthSp_M[0][0])};AR_SEC_CONST_UNSPECIFIED_STATIC
 MAP_Tab2DS34I2T4168 za0385ff978a1a90b7c3761de32a7d663={12,12,(const UInt8*)&(
FARSp_tCoMesRStrtAstSTTEthX_A[0]),(const UInt16*)&(FARSp_ctNbCmbAstSTTEthY_A[0])
,(const UInt16*)&(FARSp_rMixtAstSTTEthSp_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab1DS2I2T0 
z60c78c2b65c2c4055782ba218c212eff={8,(const UInt8*)&(FARSp_rAstWupEth_A[0]),(
const UInt8*)&(FARSp_facAstWupEth_T[0])};AR_SEC_CONST_UNSPECIFIED_STATIC 
MAP_Tab1DS2I2T0 z5105c2efb31331f1a8e0c57fb90861f3={8,(const UInt8*)&(
FARSp_rTWCHeatEth_A[0]),(const UInt8*)&(FARSp_facTWCHeatEth_T[0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4169 
zc95d3d4712ed4da5cd8f7b2898fa4e88={8,8,(const UInt16*)&(
FARSp_nEngTWCHeatEthCal1_A[0]),(const UInt16*)&(FARSp_rAirLdTWCHeatEthCal1_A[0])
,(const UInt16*)&(FARSp_rMixtTWCHeatEthCal1_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4169 
z928e4620b1f1336747679793ffc4dca4={8,8,(const UInt16*)&(
FARSp_nEngTWCHeatEthCal2_A[0]),(const UInt16*)&(FARSp_rAirLdTWCHeatEthCal2_A[0])
,(const UInt16*)&(FARSp_rMixtTWCHeatEthCal2_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4169 
z71d9c8f043650663bef9fa30b16d31c9={8,8,(const UInt16*)&(
FARSp_nEngTWCHeatEthCal3_A[0]),(const UInt16*)&(FARSp_rAirLdTWCHeatEthCal3_A[0])
,(const UInt16*)&(FARSp_rMixtTWCHeatEthCal3_M[0][0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab2DS34I2T4169 
z6d8037dfd7b3b10f85f3867216e6ed2e={8,8,(const UInt16*)&(FARSp_nEngSatMaxEthX_A[0
]),(const UInt16*)&(FARSp_rAirLdSatMaxEthY_A[0]),(const UInt16*)&(
FARSp_rMixtLimSatMaxEth_M[0][0])};AR_SEC_CONST_UNSPECIFIED_STATIC 
MAP_Tab2DS34I2T4169 z48bc00674095402cb6a1f8a530aa9159={8,8,(const UInt16*)&(
FARSp_nEngSatMinEthX_A[0]),(const UInt16*)&(FARSp_rAirLdSatMinEthY_A[0]),(const 
UInt16*)&(FARSp_rMixtLimSatMinEth_M[0][0])};AR_SEC_CONST_UNSPECIFIED_STATIC 
MAP_Tab1DS2I2T0 z08cb0f2de12b385114d35207c6131565={8,(const UInt8*)&(
FARSp_rMixtLimMaxEth_A[0]),(const UInt8*)&(FARSp_facMixtLimMaxEth_T[0])};
AR_SEC_CONST_UNSPECIFIED_STATIC MAP_Tab1DS2I2T0 
z1f37bc61d0f136b96a03565a79686459={8,(const UInt8*)&(FARSp_rMixtLimMinEth_A[0]),
(const UInt8*)&(FARSp_facMixtLimMinEth_T[0])};
#define FARSP_STOP_SEC_CONST_UNSPECIFIED
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE026_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE026_Ext_nEng_in;AR_IF_GLOBAL_16BIT SInt16 
FARSp_RE026_Ext_tCoMes_in;AR_IF_GLOBAL_16BIT SInt16 
FARSp_RE026_Ext_tCoStrtMes_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE026_InjSys_ctNbCmbAst_in;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_AfuA_rEthWiExct_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_CoPTSt_tCoMesRStrtSTT_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_facBasModCur_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_facBasModTar_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_facTranMod_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_idxBas1ModCur_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_idxBas1ModTar_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_idxBas2ModCur_in[16];AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE026_EOM_prm_idxBas2ModTar_in[16];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE026_AfuA_bInvldEthRat_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE026_CoPTSt_bRStrtSTT_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z114e301bef21317a567c3184588dc1ee;static UInt16 
Sa46_FARSp_rMi__WCHeatEthCal1_M;static UInt16 Sa47_FARSp_rMi__WCHeatEthCal2_M;
static UInt16 Sa48_FARSp_rMi__WCHeatEthCal3_M;static UInt16 
z2473198941c2bd1647d793ad55e01867;static UInt16 
z306b6c24f708b198f9f6a87ddfbc9fd0;static UInt16 
zb9e1a22d4655bc68a38158a941f19bb3;static UInt16 
z681ea48ee4d4f9f5be312d0ba570dd2e;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z3cdec2e958085e150bc6b0927017143b;static UInt8 
z4ac458e07bccf56db70061e1e93e1abb;static UInt8 zf0352b6d25422adeb838d1bc5829422b
;static UInt8 z1fa876f49ce3b2e8c76869c9ff61ddf9;static UInt8 
zafcb038ef71d5b65437fe56e1adc905b;static UInt8 ze9bbeda3dcecf18c2294b1c36edd34ed
;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
static Boolean z674416dbef09c7131ed3d84cb62deb85;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 zd914ad56144d062c61e23ad4e558a10c;static UInt8 
zf70dad3187a9f045692a121190d8a9a3;static UInt8 zc9d0d2fcc7e598084151ff439651ca32
;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
static Boolean zda19e9db3f2fe88111fd2a5e752bcedd;static Boolean 
z464f0ce8b8d13ce2efdbbcfdd4d414b2;static Boolean 
z506824ff6d97f13c54f2b9e6d05e500b;static Boolean 
z994c0f66b2e550170735a6232109128d;static Boolean 
z017f2eecf6fcef866a7462e0b2008043;static Boolean 
z818fc7ed927f99be8c103275a24b3189;static Boolean 
z878cf678ea5d565c5b04390b4227a868;static Boolean 
z11050c4ef962cbf1bb35ade162b0de0b;static Boolean 
z8a79f72b11252dd28f377f6ad48877bf;static Boolean 
z9e77dfddf70385dd0beb96027b9365ba;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 ze6c5e45462955d87efdb6a043a388ef4;static UInt8 
zd9df91e12a3b3f02cb6b08de02211cf8;static UInt8 z358d72448aa9b1a47db501781f905138
;static UInt8 zf87942ff71f7ef5ce49c4bf28e9283b0;static UInt8 
zd2725726164865cc1b48444dff7fcacc;static UInt8 z7d625c868c539706d99552fa6f12b24b
;static UInt8 z7a0c1253ba41ee3ffe9713b2e4c77079;static UInt8 
z1c479a56ab7beb4d274db4af53198da2;static UInt8 z73d09182bb24fccebdb968e07c9e7ef5
;static UInt8 z4836916fb4a9c463aec93fe76e19d5a2;static UInt8 
zec1e655c3a13b1e5afa0ed9ef3dfef0f;static UInt8 zd43731a63f2e07078cb2b18709e70316
;static UInt8 z571e17f38c13dcebfa50858e054ba370;static UInt8 
z0fc0a7ac6b1bf5e83cd087cfa8f52b79;static UInt8 z1cf5f27bf656f5fd72433bf98688156b
;static UInt8 z9857bb4813161ce21b23bf566f59a52a;static UInt8 
z271b299a503a3cc9eb8083e2ea99ac48;static UInt8 zed88658f84be6fec58be9811691bb386
;static UInt8 z6dc1cddd1091e92ce075206e8f56c3af;static UInt8 
z90b6bf74c33200f659917f18f76e2729;static UInt8 z038154fcff868c328791595d4b303bf1
;static UInt8 zc36a535095a7552852777102610ccac3;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_025_MSE_ini(Void){FARSp_RE026_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_026_TEV_fct(Void){UInt32 z4d7cd0c91293b8c36bc16bb968c52090;UInt8 
zf4097140f034199ed41001e59b9617cf=0;UInt8 zf245c2a69e4b70e1732b301642ec16b9;
UInt8 z66767d1382c8602cf99f84a5968fa08b;UInt8 zb8f167c1f13bb624f2132f4ea4dc868e;
UInt8 ze707d3fa68f6005b04b3e72c756ed467;SInt32 zd468f45f7296e73fe1291d4b933ffed7
;if(FARSp_bInvldEthRatAcv_C){UInt16 z9c9f71eb98ac1e3edf54c5f4ca7a2520;SInt16 
z6ea14ae93dd588b6182ff2f70ee88942;UInt16 zeff5d5ac106e500e7d08161e2e3c60e9;
UInt16 zb6437ab9a28d4dfa8315e3637f7b7d31;UInt16 
ze94a9cded824cbe9710f75d8e98f583f;UInt16 z19c9faa4d8bf55d84fcd321ed7a45f56;
UInt16 zff998d256b05950a95bd0bbed7fb5f7f;UInt16 
z4dd0d808e2355aa263a3e7f8075eeebe;UInt16 z8af74214365ca96e64c6a68cce323f12;
UInt16 z5883edabb055faf114e55d99640189bd;Boolean 
z1579fc361432413c8b51901c0b3ce54d;Boolean zc846e6e1bf769790487b6be902dc813c;
Boolean z8225183cc921c2dff6140c632aa6c8f6;Boolean 
za92b89ee669e477776af5326584d3852;SInt16 z083933e535293d75bb743b103b9f75c1;
zf4097140f034199ed41001e59b9617cf=1;if(z11050c4ef962cbf1bb35ade162b0de0b){
za92b89ee669e477776af5326584d3852=z878cf678ea5d565c5b04390b4227a868;}else{
za92b89ee669e477776af5326584d3852=FARSp_RE026_AfuA_bInvldEthRat_in;}
z674416dbef09c7131ed3d84cb62deb85=za92b89ee669e477776af5326584d3852!=
FARSp_RE026_AfuA_bInvldEthRat_in;if(z674416dbef09c7131ed3d84cb62deb85){
z8225183cc921c2dff6140c632aa6c8f6=za92b89ee669e477776af5326584d3852;}else{if(
z9e77dfddf70385dd0beb96027b9365ba){z8225183cc921c2dff6140c632aa6c8f6=
z8a79f72b11252dd28f377f6ad48877bf;}else{z8225183cc921c2dff6140c632aa6c8f6=
FARSp_RE026_AfuA_bInvldEthRat_in;}}switch(FARSp_RE026_AfuA_bInvldEthRat_in){case
 0:{zafcb038ef71d5b65437fe56e1adc905b=FARSp_RE026_AfuA_rEthWiExct_in;break;}case
 1:{zafcb038ef71d5b65437fe56e1adc905b=FARSp_rEthDft_C;break;}}if(
FARSp_tEthDftTran_C>1){z9c9f71eb98ac1e3edf54c5f4ca7a2520=FARSp_tEthDftTran_C;}
else{z9c9f71eb98ac1e3edf54c5f4ca7a2520=1;}if(z464f0ce8b8d13ce2efdbbcfdd4d414b2){
zb6437ab9a28d4dfa8315e3637f7b7d31=z306b6c24f708b198f9f6a87ddfbc9fd0;}else{
zb6437ab9a28d4dfa8315e3637f7b7d31=z9c9f71eb98ac1e3edf54c5f4ca7a2520;}
z1579fc361432413c8b51901c0b3ce54d=z674416dbef09c7131ed3d84cb62deb85||(
z506824ff6d97f13c54f2b9e6d05e500b&&(z9c9f71eb98ac1e3edf54c5f4ca7a2520!=
zb6437ab9a28d4dfa8315e3637f7b7d31));if(z1579fc361432413c8b51901c0b3ce54d){if(
z674416dbef09c7131ed3d84cb62deb85){z114e301bef21317a567c3184588dc1ee=0;}else{
z114e301bef21317a567c3184588dc1ee=(UInt16)(((UInt16)(((UInt16)(-
zb9e1a22d4655bc68a38158a941f19bb3))+zb6437ab9a28d4dfa8315e3637f7b7d31))+1);}}
ze94a9cded824cbe9710f75d8e98f583f=(UInt16)(z9c9f71eb98ac1e3edf54c5f4ca7a2520-
z114e301bef21317a567c3184588dc1ee);if(ze94a9cded824cbe9710f75d8e98f583f){
z19c9faa4d8bf55d84fcd321ed7a45f56=ze94a9cded824cbe9710f75d8e98f583f;}else{
z19c9faa4d8bf55d84fcd321ed7a45f56=0;}if(1000<z19c9faa4d8bf55d84fcd321ed7a45f56){
zff998d256b05950a95bd0bbed7fb5f7f=1000;}else{zff998d256b05950a95bd0bbed7fb5f7f=
z19c9faa4d8bf55d84fcd321ed7a45f56;}if(zff998d256b05950a95bd0bbed7fb5f7f){
z4dd0d808e2355aa263a3e7f8075eeebe=zff998d256b05950a95bd0bbed7fb5f7f;}else{
z4dd0d808e2355aa263a3e7f8075eeebe=0;}if(z1579fc361432413c8b51901c0b3ce54d&&(!(
z818fc7ed927f99be8c103275a24b3189))){zeff5d5ac106e500e7d08161e2e3c60e9=(UInt16)(
z4dd0d808e2355aa263a3e7f8075eeebe+1);}else{if(z017f2eecf6fcef866a7462e0b2008043)
{zeff5d5ac106e500e7d08161e2e3c60e9=z681ea48ee4d4f9f5be312d0ba570dd2e;}else{
zeff5d5ac106e500e7d08161e2e3c60e9=0;}}z6ea14ae93dd588b6182ff2f70ee88942=(SInt16)
(zeff5d5ac106e500e7d08161e2e3c60e9-1);z083933e535293d75bb743b103b9f75c1=
z6ea14ae93dd588b6182ff2f70ee88942;if(z083933e535293d75bb743b103b9f75c1>0){
z8af74214365ca96e64c6a68cce323f12=(UInt16)z083933e535293d75bb743b103b9f75c1;}
else{z8af74214365ca96e64c6a68cce323f12=0;}if(z4dd0d808e2355aa263a3e7f8075eeebe<
z8af74214365ca96e64c6a68cce323f12){z5883edabb055faf114e55d99640189bd=
z4dd0d808e2355aa263a3e7f8075eeebe;}else{z5883edabb055faf114e55d99640189bd=
z8af74214365ca96e64c6a68cce323f12;}zc846e6e1bf769790487b6be902dc813c=
z6ea14ae93dd588b6182ff2f70ee88942>0;if(zc846e6e1bf769790487b6be902dc813c){UInt16
 z74758c4335611124781e7e8354fd1255;if(!(zda19e9db3f2fe88111fd2a5e752bcedd)){
zc9d0d2fcc7e598084151ff439651ca32=0;z994c0f66b2e550170735a6232109128d=0;
zda19e9db3f2fe88111fd2a5e752bcedd=1;}if(z994c0f66b2e550170735a6232109128d){
zd914ad56144d062c61e23ad4e558a10c=zc9d0d2fcc7e598084151ff439651ca32;}else{switch
(z8225183cc921c2dff6140c632aa6c8f6){case 0:{ze9bbeda3dcecf18c2294b1c36edd34ed=
FARSp_RE026_AfuA_rEthWiExct_in;break;}case 1:{ze9bbeda3dcecf18c2294b1c36edd34ed=
FARSp_rEthDft_C;break;}default:{}}zd914ad56144d062c61e23ad4e558a10c=
ze9bbeda3dcecf18c2294b1c36edd34ed;}if(z5883edabb055faf114e55d99640189bd>1){
z74758c4335611124781e7e8354fd1255=z5883edabb055faf114e55d99640189bd;}else{
z74758c4335611124781e7e8354fd1255=1;}z994c0f66b2e550170735a6232109128d=1;
zc9d0d2fcc7e598084151ff439651ca32=(UInt8)(zd914ad56144d062c61e23ad4e558a10c+((
UInt8)(SInt16)(((SInt16)(((UInt16)zafcb038ef71d5b65437fe56e1adc905b)-((UInt16)
zd914ad56144d062c61e23ad4e558a10c)))/((SInt32)z74758c4335611124781e7e8354fd1255)
)));}else{zda19e9db3f2fe88111fd2a5e752bcedd=0;}if(
zc846e6e1bf769790487b6be902dc813c){FARSp_rEthWiExct=
zd914ad56144d062c61e23ad4e558a10c;}else{FARSp_rEthWiExct=
zafcb038ef71d5b65437fe56e1adc905b;}z464f0ce8b8d13ce2efdbbcfdd4d414b2=1;
z306b6c24f708b198f9f6a87ddfbc9fd0=z9c9f71eb98ac1e3edf54c5f4ca7a2520;
z506824ff6d97f13c54f2b9e6d05e500b=zc846e6e1bf769790487b6be902dc813c;
zb9e1a22d4655bc68a38158a941f19bb3=z5883edabb055faf114e55d99640189bd;
z818fc7ed927f99be8c103275a24b3189=z1579fc361432413c8b51901c0b3ce54d;
z017f2eecf6fcef866a7462e0b2008043=1;z681ea48ee4d4f9f5be312d0ba570dd2e=
z5883edabb055faf114e55d99640189bd;z11050c4ef962cbf1bb35ade162b0de0b=1;
z878cf678ea5d565c5b04390b4227a868=FARSp_RE026_AfuA_bInvldEthRat_in;
z9e77dfddf70385dd0beb96027b9365ba=1;z8a79f72b11252dd28f377f6ad48877bf=
z8225183cc921c2dff6140c632aa6c8f6;}else{zf4097140f034199ed41001e59b9617cf=2;
FARSp_rEthWiExct=FARSp_RE026_AfuA_rEthWiExct_in;}if(
zf70dad3187a9f045692a121190d8a9a3!=zf4097140f034199ed41001e59b9617cf){if(
zf70dad3187a9f045692a121190d8a9a3==1){zda19e9db3f2fe88111fd2a5e752bcedd=0;}}
FARSp_bAcvRatMixtAstWupEthSp=(FARSp_RE026_Ext_tCoMes_in<=
FARSp_tCoMesThdAfsWupSTTEnaEth_C)||(z2473198941c2bd1647d793ad55e01867>=
FARSp_rMixtThdAfsWupSTTEnaEth_C);if(FARSp_bAcvRatMixtAstWupEthSp){
FARSp_facAstWupEthSpRaw=Tab1DS2I2T0(&(z60c78c2b65c2c4055782ba218c212eff),
FARSp_rEthWiExct,&(z73d09182bb24fccebdb968e07c9e7ef5));if(
FARSp_RE026_CoPTSt_bRStrtSTT_in){UInt16 Sa34_FARSp_rMixtAstSTTEthSp_M;UInt16 
Sa34_FARSp_rMixtWupSTTEthSp_M;Sa34_FARSp_rMixtWupSTTEthSp_M=Tab2DS34I2T4164(&(
z55e9433fc1b69e63b07c5a0c55112ace),FARSp_RE026_Ext_tCoMes_in,
FARSp_RE026_CoPTSt_tCoMesRStrtSTT_in,&(z7d625c868c539706d99552fa6f12b24b),&(
z7a0c1253ba41ee3ffe9713b2e4c77079));Sa34_FARSp_rMixtAstSTTEthSp_M=
Tab2DS34I2T4168(&(za0385ff978a1a90b7c3761de32a7d663),
FARSp_RE026_CoPTSt_tCoMesRStrtSTT_in,FARSp_RE026_InjSys_ctNbCmbAst_in,&(
zd9df91e12a3b3f02cb6b08de02211cf8),&(z358d72448aa9b1a47db501781f905138));if(
Sa34_FARSp_rMixtWupSTTEthSp_M>Sa34_FARSp_rMixtAstSTTEthSp_M){
FARSp_rMixtSTTEthSp_MP=Sa34_FARSp_rMixtWupSTTEthSp_M;}else{
FARSp_rMixtSTTEthSp_MP=Sa34_FARSp_rMixtAstSTTEthSp_M;}FARSp_rMixtAstWupEthSpRaw=
FARSp_rMixtSTTEthSp_MP;}else{UInt16 Sa34_FARSp_rMixtAstNormEthSp_M;UInt16 
Sa34_FARSp_rMixtWupNormEthSp_M;Sa34_FARSp_rMixtWupNormEthSp_M=Tab2DS34I2T4196(&(
z6c1f462dcf3beb6044ea2c2a4df7b839),FARSp_RE026_Ext_tCoMes_in,
FARSp_RE026_Ext_tCoStrtMes_in,&(zf87942ff71f7ef5ce49c4bf28e9283b0),&(
zd2725726164865cc1b48444dff7fcacc));Sa34_FARSp_rMixtAstNormEthSp_M=
Tab2DS34I2T4172(&(z42a7432f38f1a21a154246ee212ee774),
FARSp_RE026_Ext_tCoStrtMes_in,FARSp_RE026_InjSys_ctNbCmbAst_in,&(
z1c479a56ab7beb4d274db4af53198da2),&(ze6c5e45462955d87efdb6a043a388ef4));if(
Sa34_FARSp_rMixtWupNormEthSp_M>Sa34_FARSp_rMixtAstNormEthSp_M){
FARSp_rMixtNormEthSp_MP=Sa34_FARSp_rMixtWupNormEthSp_M;}else{
FARSp_rMixtNormEthSp_MP=Sa34_FARSp_rMixtAstNormEthSp_M;}
FARSp_rMixtAstWupEthSpRaw=FARSp_rMixtNormEthSp_MP;}}else{
FARSp_rMixtAstWupEthSpRaw=4096;FARSp_facAstWupEthSpRaw=0;}for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){FARSp_prm_facGasFlexSp_out[
zd468f45f7296e73fe1291d4b933ffed7]=0;}FARSp_prm_facGasFlexSp_out[7]=
FARSp_facAstWupEthSpRaw;FARSp_prm_facGasFlexSp_out[8]=0;
FARSp_prm_facGasFlexSp_out[9]=Tab1DS2I2T0(&(z5105c2efb31331f1a8e0c57fb90861f3),
FARSp_rEthWiExct,&(z4836916fb4a9c463aec93fe76e19d5a2));for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){FARSp_prm_facGasFlexSp_out[
zd468f45f7296e73fe1291d4b933ffed7+10]=0;}FARSp_prm_facGasFlexSp_out[17]=
Tab1DS2I2T0(&(z08cb0f2de12b385114d35207c6131565),FARSp_rEthWiExct,&(
zc36a535095a7552852777102610ccac3));FARSp_prm_facGasFlexSp_out[18]=0;
FARSp_prm_facGasFlexSp_out[19]=Tab1DS2I2T0(&(z1f37bc61d0f136b96a03565a79686459),
FARSp_rEthWiExct,&(z038154fcff868c328791595d4b303bf1));
FARSp_prm_facGasFlexSp_out[20]=0;FARSp_prm_facGasFlexSp_out[21]=0;
FARSp_prm_facGasFlexSp_out[22]=0;FARSp_prm_facGasFlexSp_out[23]=0;if(
FARSp_RE026_EOM_prm_idxBas1ModCur_in[5]>1){zf245c2a69e4b70e1732b301642ec16b9=
FARSp_RE026_EOM_prm_idxBas1ModCur_in[5];}else{zf245c2a69e4b70e1732b301642ec16b9=
1;}if(4<zf245c2a69e4b70e1732b301642ec16b9){z3cdec2e958085e150bc6b0927017143b=4;}
else{z3cdec2e958085e150bc6b0927017143b=zf245c2a69e4b70e1732b301642ec16b9;}if(
FARSp_RE026_EOM_prm_idxBas1ModTar_in[5]>1){zb8f167c1f13bb624f2132f4ea4dc868e=
FARSp_RE026_EOM_prm_idxBas1ModTar_in[5];}else{zb8f167c1f13bb624f2132f4ea4dc868e=
1;}if(4<zb8f167c1f13bb624f2132f4ea4dc868e){zf0352b6d25422adeb838d1bc5829422b=4;}
else{zf0352b6d25422adeb838d1bc5829422b=zb8f167c1f13bb624f2132f4ea4dc868e;}if(
FARSp_RE026_EOM_prm_idxBas2ModCur_in[5]>1){z66767d1382c8602cf99f84a5968fa08b=
FARSp_RE026_EOM_prm_idxBas2ModCur_in[5];}else{z66767d1382c8602cf99f84a5968fa08b=
1;}if(4<z66767d1382c8602cf99f84a5968fa08b){z4ac458e07bccf56db70061e1e93e1abb=4;}
else{z4ac458e07bccf56db70061e1e93e1abb=z66767d1382c8602cf99f84a5968fa08b;}if(
FARSp_RE026_EOM_prm_idxBas2ModTar_in[5]>1){ze707d3fa68f6005b04b3e72c756ed467=
FARSp_RE026_EOM_prm_idxBas2ModTar_in[5];}else{ze707d3fa68f6005b04b3e72c756ed467=
1;}if(4<ze707d3fa68f6005b04b3e72c756ed467){z1fa876f49ce3b2e8c76869c9ff61ddf9=4;}
else{z1fa876f49ce3b2e8c76869c9ff61ddf9=ze707d3fa68f6005b04b3e72c756ed467;}
FARSp_bAcvTWCHeatCal3=(z3cdec2e958085e150bc6b0927017143b==3)||(
z4ac458e07bccf56db70061e1e93e1abb==3)||(zf0352b6d25422adeb838d1bc5829422b==3)||(
z1fa876f49ce3b2e8c76869c9ff61ddf9==3);FARSp_bAcvTWCHeatCal2=(
z3cdec2e958085e150bc6b0927017143b==2)||(z4ac458e07bccf56db70061e1e93e1abb==2)||(
zf0352b6d25422adeb838d1bc5829422b==2)||(z1fa876f49ce3b2e8c76869c9ff61ddf9==2);
FARSp_bAcvTWCHeatCal1=(z3cdec2e958085e150bc6b0927017143b==1)||(
z4ac458e07bccf56db70061e1e93e1abb==1)||(zf0352b6d25422adeb838d1bc5829422b==1)||(
z1fa876f49ce3b2e8c76869c9ff61ddf9==1);if(FARSp_bAcvTWCHeatCal1){
Sa46_FARSp_rMi__WCHeatEthCal1_M=Tab2DS34I2T4169(&(
zc95d3d4712ed4da5cd8f7b2898fa4e88),FARSp_RE026_Ext_nEng_in,
FARSp_RE026_EngM_rAirLdCor_in,&(zd43731a63f2e07078cb2b18709e70316),&(
zec1e655c3a13b1e5afa0ed9ef3dfef0f));}if(FARSp_bAcvTWCHeatCal2){
Sa47_FARSp_rMi__WCHeatEthCal2_M=Tab2DS34I2T4169(&(
z928e4620b1f1336747679793ffc4dca4),FARSp_RE026_Ext_nEng_in,
FARSp_RE026_EngM_rAirLdCor_in,&(z0fc0a7ac6b1bf5e83cd087cfa8f52b79),&(
z571e17f38c13dcebfa50858e054ba370));}if(FARSp_bAcvTWCHeatCal3){
Sa48_FARSp_rMi__WCHeatEthCal3_M=Tab2DS34I2T4169(&(
z71d9c8f043650663bef9fa30b16d31c9),FARSp_RE026_Ext_nEng_in,
FARSp_RE026_EngM_rAirLdCor_in,&(z9857bb4813161ce21b23bf566f59a52a),&(
z1cf5f27bf656f5fd72433bf98688156b));}switch(z1fa876f49ce3b2e8c76869c9ff61ddf9){
case 1:{FARSp_rMixtTWCHeatBas2EthTar=Sa46_FARSp_rMi__WCHeatEthCal1_M;break;}case
 2:{FARSp_rMixtTWCHeatBas2EthTar=Sa47_FARSp_rMi__WCHeatEthCal2_M;break;}case 3:{
FARSp_rMixtTWCHeatBas2EthTar=Sa48_FARSp_rMi__WCHeatEthCal3_M;break;}case 4:{
FARSp_rMixtTWCHeatBas2EthTar=4096;break;}}switch(
zf0352b6d25422adeb838d1bc5829422b){case 1:{FARSp_rMixtTWCHeatBas1EthTar=
Sa46_FARSp_rMi__WCHeatEthCal1_M;break;}case 2:{FARSp_rMixtTWCHeatBas1EthTar=
Sa47_FARSp_rMi__WCHeatEthCal2_M;break;}case 3:{FARSp_rMixtTWCHeatBas1EthTar=
Sa48_FARSp_rMi__WCHeatEthCal3_M;break;}case 4:{FARSp_rMixtTWCHeatBas1EthTar=4096
;break;}}switch(z4ac458e07bccf56db70061e1e93e1abb){case 1:{
FARSp_rMixtTWCHeatBas2EthCur=Sa46_FARSp_rMi__WCHeatEthCal1_M;break;}case 2:{
FARSp_rMixtTWCHeatBas2EthCur=Sa47_FARSp_rMi__WCHeatEthCal2_M;break;}case 3:{
FARSp_rMixtTWCHeatBas2EthCur=Sa48_FARSp_rMi__WCHeatEthCal3_M;break;}case 4:{
FARSp_rMixtTWCHeatBas2EthCur=4096;break;}}switch(
z3cdec2e958085e150bc6b0927017143b){case 1:{FARSp_rMixtTWCHeatBas1EthCur=
Sa46_FARSp_rMi__WCHeatEthCal1_M;break;}case 2:{FARSp_rMixtTWCHeatBas1EthCur=
Sa47_FARSp_rMi__WCHeatEthCal2_M;break;}case 3:{FARSp_rMixtTWCHeatBas1EthCur=
Sa48_FARSp_rMi__WCHeatEthCal3_M;break;}case 4:{FARSp_rMixtTWCHeatBas1EthCur=4096
;break;}}z4d7cd0c91293b8c36bc16bb968c52090=(UInt32)((((SInt32)
FARSp_RE026_EOM_prm_facBasModCur_in[5])*((SInt32)(((UInt32)
FARSp_rMixtTWCHeatBas1EthCur)-((UInt32)FARSp_rMixtTWCHeatBas2EthCur))))+((UInt32
)(((UInt32)FARSp_rMixtTWCHeatBas2EthCur)<<7)));for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){FARSp_prm_rMixtGasFlexSp_out[
zd468f45f7296e73fe1291d4b933ffed7]=4096;}FARSp_prm_rMixtGasFlexSp_out[7]=
FARSp_rMixtAstWupEthSpRaw;FARSp_prm_rMixtGasFlexSp_out[8]=4096;
FARSp_prm_rMixtGasFlexSp_out[9]=(UInt16)(((UInt16)(SInt16)((((SInt32)
FARSp_RE026_EOM_prm_facTranMod_in[5])*((SInt32)(((UInt32)((((SInt32)
FARSp_RE026_EOM_prm_facBasModTar_in[5])*((SInt32)(((UInt32)
FARSp_rMixtTWCHeatBas1EthTar)-((UInt32)FARSp_rMixtTWCHeatBas2EthTar))))+((UInt32
)(((UInt32)FARSp_rMixtTWCHeatBas2EthTar)<<7))))-
z4d7cd0c91293b8c36bc16bb968c52090)))>>14))+((UInt16)(
z4d7cd0c91293b8c36bc16bb968c52090>>7)));for(zd468f45f7296e73fe1291d4b933ffed7=0;
zd468f45f7296e73fe1291d4b933ffed7<=6;(zd468f45f7296e73fe1291d4b933ffed7)++){
FARSp_prm_rMixtGasFlexSp_out[zd468f45f7296e73fe1291d4b933ffed7+10]=4096;}
FARSp_prm_rMixtGasFlexSp_out[17]=Tab2DS34I2T4169(&(
z6d8037dfd7b3b10f85f3867216e6ed2e),FARSp_RE026_Ext_nEng_in,
FARSp_RE026_EngM_rAirLdCor_in,&(z90b6bf74c33200f659917f18f76e2729),&(
z271b299a503a3cc9eb8083e2ea99ac48));FARSp_prm_rMixtGasFlexSp_out[18]=4096;
FARSp_prm_rMixtGasFlexSp_out[19]=Tab2DS34I2T4169(&(
z48bc00674095402cb6a1f8a530aa9159),FARSp_RE026_Ext_nEng_in,
FARSp_RE026_EngM_rAirLdCor_in,&(zed88658f84be6fec58be9811691bb386),&(
z6dc1cddd1091e92ce075206e8f56c3af));FARSp_prm_rMixtGasFlexSp_out[20]=4096;
FARSp_prm_rMixtGasFlexSp_out[21]=4096;FARSp_prm_rMixtGasFlexSp_out[22]=4096;
FARSp_prm_rMixtGasFlexSp_out[23]=4096;zf70dad3187a9f045692a121190d8a9a3=
zf4097140f034199ed41001e59b9617cf;z2473198941c2bd1647d793ad55e01867=
FARSp_rMixtAstWupEthSpRaw;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_RE026_FctVarInit(Void){ze6c5e45462955d87efdb6a043a388ef4=0;
zd9df91e12a3b3f02cb6b08de02211cf8=0;z358d72448aa9b1a47db501781f905138=0;
zf87942ff71f7ef5ce49c4bf28e9283b0=0;zd2725726164865cc1b48444dff7fcacc=0;
z7d625c868c539706d99552fa6f12b24b=0;z7a0c1253ba41ee3ffe9713b2e4c77079=0;
z1c479a56ab7beb4d274db4af53198da2=0;z73d09182bb24fccebdb968e07c9e7ef5=0;
z4836916fb4a9c463aec93fe76e19d5a2=0;zec1e655c3a13b1e5afa0ed9ef3dfef0f=0;
zd43731a63f2e07078cb2b18709e70316=0;z571e17f38c13dcebfa50858e054ba370=0;
z0fc0a7ac6b1bf5e83cd087cfa8f52b79=0;z1cf5f27bf656f5fd72433bf98688156b=0;
z9857bb4813161ce21b23bf566f59a52a=0;z271b299a503a3cc9eb8083e2ea99ac48=0;
zed88658f84be6fec58be9811691bb386=0;z6dc1cddd1091e92ce075206e8f56c3af=0;
z90b6bf74c33200f659917f18f76e2729=0;z038154fcff868c328791595d4b303bf1=0;
zc36a535095a7552852777102610ccac3=0;FARSp_facAstWupEthSpRaw=0;FARSp_rEthWiExct=0
;FARSp_rMixtAstWupEthSpRaw=0;zda19e9db3f2fe88111fd2a5e752bcedd=0;
z114e301bef21317a567c3184588dc1ee=0;zd914ad56144d062c61e23ad4e558a10c=0;
zf70dad3187a9f045692a121190d8a9a3=0;Sa46_FARSp_rMi__WCHeatEthCal1_M=0;
Sa47_FARSp_rMi__WCHeatEthCal2_M=0;Sa48_FARSp_rMi__WCHeatEthCal3_M=0;
z2473198941c2bd1647d793ad55e01867=4096;z306b6c24f708b198f9f6a87ddfbc9fd0=0;
z464f0ce8b8d13ce2efdbbcfdd4d414b2=0;z506824ff6d97f13c54f2b9e6d05e500b=0;
zb9e1a22d4655bc68a38158a941f19bb3=0;zc9d0d2fcc7e598084151ff439651ca32=0;
z994c0f66b2e550170735a6232109128d=0;z681ea48ee4d4f9f5be312d0ba570dd2e=0;
z017f2eecf6fcef866a7462e0b2008043=0;z818fc7ed927f99be8c103275a24b3189=0;
z878cf678ea5d565c5b04390b4227a868=1;z11050c4ef962cbf1bb35ade162b0de0b=0;
z8a79f72b11252dd28f377f6ad48877bf=1;z9e77dfddf70385dd0beb96027b9365ba=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

