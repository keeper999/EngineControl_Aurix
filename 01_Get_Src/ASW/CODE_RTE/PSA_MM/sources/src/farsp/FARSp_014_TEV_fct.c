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
* %name: FARSp_014_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:55 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_014_TEV_fct.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_014_TEV_FCT_C_
#define _FARSP_014_TEV_FCT_C_
#include "FARSp_014_TEV_fct.h"
#include "FARSp_014_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtLihSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE014_FRM_bAcvAflLih_in;AR_IF_GLOBAL_BOOLEAN 
Boolean FARSp_RE014_FRM_bAcvAfrLih_in;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_RE014_FRM_bAcvAfsLih_in;AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bLihAcv_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_32BIT UInt32 z2bb38f618a74db7af7bf398dfd42e7d9;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_SEC_VAR_BOOLEAN Boolean z733bc82238dd7383195e3b41da48414b;AR_SEC_VAR_BOOLEAN 
Boolean z4740cbdd9167b464101af13ff48630b9;AR_SEC_VAR_BOOLEAN Boolean 
zc24a057188fdd1ee3aaf9d3e38972098;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_013_MSE_ini(Void){FARSp_014_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_014_TEV_fct(Void){UInt32 z84a5cd307017f301e669dbcd4fffbce7;SInt32 
z67f3cdc0a9a05c60c4186848677207fa;UInt32 z326f60a0317d0807d64df267e3c21f6e;
UInt32 ze2abac23984e7292d1482bf65d6f4ca8;UInt32 
z7e81c7dcb41d037e3985e358464ae702;UInt32 zb82f21993a48afd7734f6a103e3a8cbc;
UInt16 ze3e13a75473290416af32aef934622d5;UInt16 
z51fefa54176032b9e9380983fd3af8d0;UInt16 ze3029e73591cb2cae23bb3e8b38d0404;
UInt16 zcc821c1ece92627b77b3f06d1aafa179;SInt16 
zde5afcd101029ee956460250f7e86e1a;UInt16 zfc9e4eaa20bbe8c47e85a852ff6a38ec;
UInt16 z9040fe900bfaf6f9748b882f7d52f3bf;UInt16 
z2ad462edf4d61de37f8ed0b0c8b5c442;UInt16 z47083df2ef41227e08c19ee48489f5aa;
UInt16 z25b30e616705c4f87a83db93657985eb;Boolean 
zc7fff0d900fd0eb6f7c51aeb1e769494;Boolean z00e19762917220e65b491428bdbd42a5;
Boolean z96c95265573d3ac4f702d3f451cead8f;Boolean 
zbe2436341672db129c375a82f65e2da8;Boolean zcad27792c167cf6dd45d57a7057ae531;
Boolean z7e73b935f30f44039240f41da55de145;Boolean 
ze12e3fa9c24dc8d32ecd238e0d0c2f4a;Boolean z69569b9294d55d6fc567117db39db664;
Boolean z2b3d99f8ca4fa0eb4b2ce7788ded666a;UInt32 
z6aef5c1bd1b6e842408a5c8546f4670a;UInt32 z9952894c8792c930180e1bb753749439;
UInt32 z714f886ee91a45d2f0b285351ea60810;UInt32 
z9e8893cbbbf79c6c88d6ce42c26ffe2b;if(FARSp_noMixtLihSpPrio_C==2){
z96c95265573d3ac4f702d3f451cead8f=1;}else{z96c95265573d3ac4f702d3f451cead8f=0;}
if(z96c95265573d3ac4f702d3f451cead8f&&FARSp_RE014_FRM_bAcvAfsLih_in){
z00e19762917220e65b491428bdbd42a5=1;}else{z00e19762917220e65b491428bdbd42a5=0;}
if(FARSp_noMixtLihSpPrio_C==1){zbe2436341672db129c375a82f65e2da8=1;}else{
zbe2436341672db129c375a82f65e2da8=0;}if(zbe2436341672db129c375a82f65e2da8&&
FARSp_RE014_FRM_bAcvAfsLih_in){zc7fff0d900fd0eb6f7c51aeb1e769494=1;}else{
zc7fff0d900fd0eb6f7c51aeb1e769494=0;}if(FARSp_RE014_FRM_bAcvAfrLih_in!=0){
z51fefa54176032b9e9380983fd3af8d0=FARSp_rMixtAfrLihSp_C;}else{
z51fefa54176032b9e9380983fd3af8d0=4096;}if(zc7fff0d900fd0eb6f7c51aeb1e769494!=0)
{ze3029e73591cb2cae23bb3e8b38d0404=4096;}else{ze3029e73591cb2cae23bb3e8b38d0404=
z51fefa54176032b9e9380983fd3af8d0;}if(FARSp_RE014_FRM_bAcvAflLih_in!=0){
ze3e13a75473290416af32aef934622d5=FARSp_rMixtAflLihSp_C;}else{
ze3e13a75473290416af32aef934622d5=ze3029e73591cb2cae23bb3e8b38d0404;}if(
z00e19762917220e65b491428bdbd42a5!=0){zcc821c1ece92627b77b3f06d1aafa179=4096;}
else{zcc821c1ece92627b77b3f06d1aafa179=ze3e13a75473290416af32aef934622d5;}if(
FARSp_facFilLih_C<=0){z2b3d99f8ca4fa0eb4b2ce7788ded666a=1;}else{
z2b3d99f8ca4fa0eb4b2ce7788ded666a=0;}if(16384<=FARSp_facFilLih_C){
z69569b9294d55d6fc567117db39db664=1;}else{z69569b9294d55d6fc567117db39db664=0;}
if(FARSp_RE014_FRM_bAcvAfrLih_in||FARSp_RE014_FRM_bAcvAflLih_in||
FARSp_RE014_FRM_bAcvAfsLih_in){FARSp_bLihAuth=1;}else{FARSp_bLihAuth=0;}if(!(
z4740cbdd9167b464101af13ff48630b9)){ze12e3fa9c24dc8d32ecd238e0d0c2f4a=1;}else{
ze12e3fa9c24dc8d32ecd238e0d0c2f4a=0;}if(FARSp_bLihAuth&&
ze12e3fa9c24dc8d32ecd238e0d0c2f4a){z7e73b935f30f44039240f41da55de145=1;}else{
z7e73b935f30f44039240f41da55de145=0;}if(FARSp_facFilLih_C>0){
z2ad462edf4d61de37f8ed0b0c8b5c442=FARSp_facFilLih_C;}else{
z2ad462edf4d61de37f8ed0b0c8b5c442=0;}if(16384<z2ad462edf4d61de37f8ed0b0c8b5c442)
{z47083df2ef41227e08c19ee48489f5aa=16384;}else{z47083df2ef41227e08c19ee48489f5aa
=z2ad462edf4d61de37f8ed0b0c8b5c442;}ze2abac23984e7292d1482bf65d6f4ca8=(UInt32)((
((UInt32)zcc821c1ece92627b77b3f06d1aafa179)*((UInt32)
z47083df2ef41227e08c19ee48489f5aa))>>12);z9040fe900bfaf6f9748b882f7d52f3bf=(
UInt16)(((UInt16)(-z47083df2ef41227e08c19ee48489f5aa))+16384);if(
z733bc82238dd7383195e3b41da48414b!=0){z84a5cd307017f301e669dbcd4fffbce7=
z2bb38f618a74db7af7bf398dfd42e7d9;}else{z84a5cd307017f301e669dbcd4fffbce7=16384;
}F__U64MULU32U32((UInt32)z9040fe900bfaf6f9748b882f7d52f3bf,
z84a5cd307017f301e669dbcd4fffbce7,&(z9952894c8792c930180e1bb753749439),&(
z714f886ee91a45d2f0b285351ea60810));z326f60a0317d0807d64df267e3c21f6e=
C__U32SHRU64C6_LT32(z9952894c8792c930180e1bb753749439,
z714f886ee91a45d2f0b285351ea60810,14,18);z7e81c7dcb41d037e3985e358464ae702=
ze2abac23984e7292d1482bf65d6f4ca8+z326f60a0317d0807d64df267e3c21f6e;if(
z7e73b935f30f44039240f41da55de145!=0){zb82f21993a48afd7734f6a103e3a8cbc=16384;}
else{zb82f21993a48afd7734f6a103e3a8cbc=z7e81c7dcb41d037e3985e358464ae702;}
z9e8893cbbbf79c6c88d6ce42c26ffe2b=(UInt32)(zb82f21993a48afd7734f6a103e3a8cbc>>2)
;zfc9e4eaa20bbe8c47e85a852ff6a38ec=C__U16SATU32_SATu(
z9e8893cbbbf79c6c88d6ce42c26ffe2b,61440);if(zc24a057188fdd1ee3aaf9d3e38972098!=0
){z25b30e616705c4f87a83db93657985eb=zfc9e4eaa20bbe8c47e85a852ff6a38ec;}else{
z25b30e616705c4f87a83db93657985eb=4096;}FARSp_rMixtLihSp=
z25b30e616705c4f87a83db93657985eb;z67f3cdc0a9a05c60c4186848677207fa=(SInt32)(((
UInt32)z25b30e616705c4f87a83db93657985eb)-4096);
z6aef5c1bd1b6e842408a5c8546f4670a=(UInt32)z67f3cdc0a9a05c60c4186848677207fa;if(
z67f3cdc0a9a05c60c4186848677207fa<0){z6aef5c1bd1b6e842408a5c8546f4670a=-((SInt32
)z6aef5c1bd1b6e842408a5c8546f4670a);}zde5afcd101029ee956460250f7e86e1a=(SInt16)(
z6aef5c1bd1b6e842408a5c8546f4670a>>1);if(((SInt32)(UInt16)(
zde5afcd101029ee956460250f7e86e1a<<1))>((SInt32)FARSp_rMixtDeltaThdLih_C)){
zcad27792c167cf6dd45d57a7057ae531=1;}else{zcad27792c167cf6dd45d57a7057ae531=0;}
if(zcad27792c167cf6dd45d57a7057ae531||FARSp_bLihAuth){FARSp_bLihAcv=1;}else{
FARSp_bLihAcv=0;}z4740cbdd9167b464101af13ff48630b9=FARSp_bLihAuth;
z2bb38f618a74db7af7bf398dfd42e7d9=zb82f21993a48afd7734f6a103e3a8cbc;
z733bc82238dd7383195e3b41da48414b=1;zc24a057188fdd1ee3aaf9d3e38972098=1;
FARSp_bLihAcv_out=FARSp_bLihAcv;FARSp_rMixtLihSp_out=FARSp_rMixtLihSp;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_014_FctVarInit(Void){z2bb38f618a74db7af7bf398dfd42e7d9=0;
z733bc82238dd7383195e3b41da48414b=0;z4740cbdd9167b464101af13ff48630b9=0;
zc24a057188fdd1ee3aaf9d3e38972098=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

