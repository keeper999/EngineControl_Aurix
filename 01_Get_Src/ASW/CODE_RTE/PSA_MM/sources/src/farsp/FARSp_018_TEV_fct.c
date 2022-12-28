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
* %name: FARSp_018_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:58 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_018_TEV_fct.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_018_TEV_FCT_C_
#define _FARSP_018_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_018_TEV_fct.h"
#include "FARSp_018_calibrations.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE018_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE018_ExM_mO2StgCur_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_ExM_mO2StgEngStop_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_UsThrM_pAirExtEstim_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtTWCPurgeSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_32BIT UInt32 FARSp_RE018_Ext_tiAst_in;
#define FARSP_STOP_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE018_CoPTSt_tCoMesRStrtSTT_in;AR_IF_GLOBAL_8BIT 
UInt8 FARSp_RE018_Ext_uLsDsMes_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE018_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE018_CoPTSt_bRStrtSTT_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE018_LsSys_bLsDsMainOxCHeatOk_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z6e1a8ef9d55239a1aac05e0329b37ca0;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 zbbf69a006e56aa22d3bd0742c5fe8508;static UInt16 
z090cc65c0fd863e8137de08c90c6cab4;static UInt16 
ze108b360a8b234a83b33994618068f72;static UInt16 
z029438c3f16ca99ff63b9db8a86de0c6;static UInt16 
zc7af74f8e876d09b0a112280d5304226;static UInt16 
z4eee818488580b90ee2c3bb629708d45;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
static UInt32 z8cddcec91562863ed98e3e744f70af9a;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 zba14f4c2e0fa0d6eae341c856b7d789c;static UInt8 
zb0b859d2071e1e62a5c801b5c8143ecb;static UInt8 z39f7dacc92761e627c037d5f6fd5d073
;static UInt8 zd1fb2862a5b7033a0c46f4116e07253d;static UInt8 
z963a6979101102bd5a5975d5f16523aa;static UInt8 z5d47a0c3a5d74e6a47c4ca837750feeb
;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_017_MSE_ini(Void){FARSp_018_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_018_TEV_fct(Void){TabIdxS50T512((const UInt8*)
FARSp_tCoMesRStrtSTTAst_A,8,FARSp_RE018_CoPTSt_tCoMesRStrtSTT_in,&(
zba14f4c2e0fa0d6eae341c856b7d789c),&(zbbf69a006e56aa22d3bd0742c5fe8508));
z8cddcec91562863ed98e3e744f70af9a=Tab1DIntp2I1T66((const UInt32*)
FARSp_tiAstThd_T,zba14f4c2e0fa0d6eae341c856b7d789c,
zbbf69a006e56aa22d3bd0742c5fe8508);FARSp_bAcvRichTWCPurgeSTT=((!(
FARSp_RE018_LsSys_bLsDsMainOxCHeatOk_in))||(
FARSp_RE018_LsSys_bLsDsMainOxCHeatOk_in&&(FARSp_RE018_Ext_uLsDsMes_in<=((UInt8)(
((UInt16)(FARSp_uLsDsThd_C<<1))/39)))))&&(FARSp_RE018_Ext_tiAst_in<=
z8cddcec91562863ed98e3e744f70af9a)&&(FARSp_RE018_ExM_mO2StgCur_in>=
FARSp_mAirO2MinThd_C)&&(FARSp_RE018_UsThrM_pAirExtEstim_in>=
FARSp_pAirExtMinThd_C)&&FARSp_RE018_CoPTSt_bRStrtSTT_in;if(
FARSp_bAcvRichTWCPurgeSTT){UInt16 zffd6164c64378afa970bfec6bbd221f1;UInt8 
z0a78b698c5011b1deb89a30e12a5c72c;UInt8 zc519b3259434f7d986a197a56481bb1f;
FARSp_facTWCPurgeSpFlex=FARSp_RE018_FARSp_prm_facGasFlexSp_in[15];
FARSp_facTWCPurgeSpGas=FARSp_RE018_FARSp_prm_facGasFlexSp_in[14];TabIdxS50T516((
const SInt16*)FARSp_tCoMesRStrtSTTCor_A,8,(SInt16)(((UInt16)
FARSp_RE018_CoPTSt_tCoMesRStrtSTT_in)-40),&(z39f7dacc92761e627c037d5f6fd5d073),&
(ze108b360a8b234a83b33994618068f72));TabIdxS50T514((const UInt32*)
FARSp_tiAstCor_A,8,FARSp_RE018_Ext_tiAst_in,&(zd1fb2862a5b7033a0c46f4116e07253d)
,&(z029438c3f16ca99ff63b9db8a86de0c6));TabIdxS50T513((const UInt16*)
FARSp_mO2StgEngStopCor_A,8,FARSp_RE018_ExM_mO2StgEngStop_in,&(
z963a6979101102bd5a5975d5f16523aa),&(zc7af74f8e876d09b0a112280d5304226));
FARSp_facMixtSTTWupSpCor_MP=(UInt16)((((UInt32)(((UInt16)Tab1DIntp2I1T64((const 
UInt8*)FARSp_facRStrtSTTMixtCor_T,z39f7dacc92761e627c037d5f6fd5d073,
ze108b360a8b234a83b33994618068f72))*((UInt16)Tab1DIntp2I1T64((const UInt8*)
FARSp_facAstMixtCor_T,zd1fb2862a5b7033a0c46f4116e07253d,
z029438c3f16ca99ff63b9db8a86de0c6))))*((UInt32)Tab1DIntp2I1T64((const UInt8*)
FARSp_facO2StgMixtCor_T,z963a6979101102bd5a5975d5f16523aa,
zc7af74f8e876d09b0a112280d5304226)))>>7);if(FARSp_facTWCPurgeSpGas){
z0a78b698c5011b1deb89a30e12a5c72c=FARSp_facTWCPurgeSpGas;}else{
z0a78b698c5011b1deb89a30e12a5c72c=0;}FARSp_rMixtTWCPurgeSpGas=
FARSp_RE018_FARSp_prm_rMixtGasFlexSp_in[14];if(FARSp_facTWCPurgeSpFlex){
zc519b3259434f7d986a197a56481bb1f=FARSp_facTWCPurgeSpFlex;}else{
zc519b3259434f7d986a197a56481bb1f=0;}FARSp_rMixtTWCPurgeSpFlex=
FARSp_RE018_FARSp_prm_rMixtGasFlexSp_in[15];if(FARSp_facMixtSTTWupSpCor_MP){
zffd6164c64378afa970bfec6bbd221f1=FARSp_facMixtSTTWupSpCor_MP;}else{
zffd6164c64378afa970bfec6bbd221f1=0;}TabIdxS50T513((const UInt16*)
FARSp_nEngTWCPurgeX_A,12,FARSp_RE018_Ext_nEng_in,&(
z5d47a0c3a5d74e6a47c4ca837750feeb),&(z4eee818488580b90ee2c3bb629708d45));
TabIdxS50T514((const UInt32*)FARSp_rAirLdCorTWCPurgeY_A,12,(UInt32)
FARSp_RE018_EngM_rAirLdCor_in,&(zb0b859d2071e1e62a5c801b5c8143ecb),&(
z090cc65c0fd863e8137de08c90c6cab4));FARSp_rMixtTWCPurgeSpRaw_MP=
Tab2DIntp2I1T33281((const UInt16*)&(FARSp_rMixtTWCPurgeRaw_M[0][0]),12,
z5d47a0c3a5d74e6a47c4ca837750feeb,z4eee818488580b90ee2c3bb629708d45,
zb0b859d2071e1e62a5c801b5c8143ecb,z090cc65c0fd863e8137de08c90c6cab4);
FARSp_rMixtTWCPurgeSpGsl=(UInt16)(((UInt32)(((SInt32)((((SInt32)
zffd6164c64378afa970bfec6bbd221f1)*((SInt32)(((UInt32)
FARSp_rMixtTWCPurgeSpRaw_MP)-4096)))>>12))+16384))>>2);
FARSp_rMixtTWCPurgeFlex_MP=(UInt16)(((UInt16)(SInt32)((((SInt32)
zc519b3259434f7d986a197a56481bb1f)*((SInt32)(((UInt32)FARSp_rMixtTWCPurgeSpFlex)
-((UInt32)FARSp_rMixtTWCPurgeSpGsl))))>>7))+FARSp_rMixtTWCPurgeSpGsl);
FARSp_rMixtTWCPurgeSpRaw=(UInt16)(((UInt16)(SInt32)((((SInt32)
z0a78b698c5011b1deb89a30e12a5c72c)*((SInt32)(((UInt32)FARSp_rMixtTWCPurgeSpGas)-
((UInt32)FARSp_rMixtTWCPurgeFlex_MP))))>>7))+FARSp_rMixtTWCPurgeFlex_MP);
z6e1a8ef9d55239a1aac05e0329b37ca0=FARSp_rMixtTWCPurgeSpRaw;}if(
FARSp_bAcvRichTWCPurgeSTT){FARSp_rMixtTWCPurgeSp=
z6e1a8ef9d55239a1aac05e0329b37ca0;}else{FARSp_rMixtTWCPurgeSp=4096;}
FARSp_rMixtTWCPurgeSp_out=FARSp_rMixtTWCPurgeSp;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_018_FctVarInit(Void){z6e1a8ef9d55239a1aac05e0329b37ca0=0;
zbbf69a006e56aa22d3bd0742c5fe8508=0;zba14f4c2e0fa0d6eae341c856b7d789c=0;
z090cc65c0fd863e8137de08c90c6cab4=0;zb0b859d2071e1e62a5c801b5c8143ecb=0;
ze108b360a8b234a83b33994618068f72=0;z39f7dacc92761e627c037d5f6fd5d073=0;
z029438c3f16ca99ff63b9db8a86de0c6=0;zd1fb2862a5b7033a0c46f4116e07253d=0;
zc7af74f8e876d09b0a112280d5304226=0;z963a6979101102bd5a5975d5f16523aa=0;
z4eee818488580b90ee2c3bb629708d45=0;z5d47a0c3a5d74e6a47c4ca837750feeb=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

