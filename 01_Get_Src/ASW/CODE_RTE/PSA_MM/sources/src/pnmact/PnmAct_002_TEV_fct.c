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
* %name: PnmAct_002_TEV_fct.c %
*
* %version: 1.0.build1 %
*
* %date_modified: Mon Jan  7 10:52:35 2013 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC4 %
* %full_filespec: PnmAct_002_TEV_fct.c-1.0.build1:csrc:2 %
*
*******************************************************************************/


#ifndef _PNMACT_002_TEV_FCT_C_
#define _PNMACT_002_TEV_FCT_C_
#include "PnmAct_calibrations.h"
#include "PnmAct_002_TEV_fct.h"
#include "Library_lut.h"
#include "dsfxp.h"
#define PNMACT_START_SEC_GLOBAL_16BIT
#include "PnmAct_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_ExM_pDsTrbEstimSI_in;AR_IF_GLOBAL_16BIT 
UInt16 PnmAct_RE002_ExM_pExMnfEstim_in;AR_IF_GLOBAL_16BIT SInt16 
PnmAct_RE002_TrbAct_pDifMaxPnmActReq_in;AR_IF_GLOBAL_16BIT SInt16 
PnmAct_RE002_TrbAct_pDifTrbActReq_in;AR_IF_GLOBAL_16BIT UInt16 
PnmAct_RE002_TrbAct_rRCOReqRaw_in;AR_IF_GLOBAL_16BIT UInt16 
PnmAct_RE002_UsThrM_pAirExt_in;AR_IF_GLOBAL_16BIT UInt16 
PnmAct_RE002_UsThrM_pUsCmpr_in;AR_IF_GLOBAL_16BIT UInt16 
PnmAct_rOpTrbActEstim_out;AR_IF_GLOBAL_16BIT SInt16 PnmAct_rRCOCorReq_out;
#define PNMACT_STOP_SEC_GLOBAL_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_16BIT
#include "PnmAct_MemMap.h"
static UInt16 z5722749cca161a8d5d52b2bbe1a5014f;static UInt16 
zc0780a5ae31a12b85e6f9a62103d4e21;
#define PNMACT_STOP_SEC_VAR_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_16BIT
#include "PnmAct_MemMap.h"
static UInt16 zae970cb005df1f4c064d7a0ed075653e;static UInt16 
zd273acc013d72280f06f0fbce9d4d51a;static UInt16 
z583ad347122014dc28fcd8e647638ba1;
#define PNMACT_STOP_SEC_VAR_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_32BIT
#include "PnmAct_MemMap.h"
static SInt32 z7fe3f8cbad554e0c2564f59320a65ed6;static UInt32 
zf07a3abcde002c64fd411a6aa0ba269d;static SInt32 
zca9edea8cad43f7de1304d01733e56ac;static SInt32 
zff36860d4211fa6e347c7a6285f7fa26;static SInt32 
z253e1cc02658f3f827af88d6f76de4a1;
#define PNMACT_STOP_SEC_VAR_32BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_8BIT
#include "PnmAct_MemMap.h"
#define PNMACT_STOP_SEC_VAR_8BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_BOOLEAN
#include "PnmAct_MemMap.h"
static Boolean zbaba1034d499bbc79c90f14517567dc5;static Boolean 
zc3cbb14ac63a7f5f30ecbbe7530a3df0;
#define PNMACT_STOP_SEC_VAR_BOOLEAN
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_VAR_8BIT
#include "PnmAct_MemMap.h"
static UInt8 zfb2080a2250c2fe8781ecad41e5ce11b;static UInt8 
z7dd1249e5d89db8cd0fa0c9149d3a12e;static UInt8 ze709d376dc33b858232d454f8227159d
;static UInt8 za8e60e08755db5f938763ffe5782b344;static UInt8 
z09f49b6ebf597dc5bab6c8d31a331006;static UInt8 zd56a3f61146d964906a3e7a62318ac24
;static UInt8 zfd410d75db385ceeff8f470edb77be11;static UInt8 
z71da5499ed6785c7c2ee8ba2cf3830b1;
#define PNMACT_STOP_SEC_VAR_8BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CODE
#include "PnmAct_MemMap.h"
Void PnmAct_001_MSE_ini(Void){PnmAct_FctVarInit();}
#define PNMACT_STOP_SEC_CODE
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CODE
#include "PnmAct_MemMap.h"
Void PnmAct_002_TEV_fct(Void){SInt32 zc69cd6cba97f7f30484dfb10715d7ff0;SInt32 
z1c6c5c780d75520bf30c807034e37f68;SInt32 z70929c92ba72d314d465d5dc86942c9a;
UInt32 z88466fa517fff7f79b7f50c9b9d72af8;UInt32 
z462197851b61d1414430ae1d57121608;UInt32 zc5c50f3e678a93554619201dc3ba7294;
SInt32 z6c00ea1a233ce8a307b41ac7a3225392;SInt32 
z26fa84b3cca4659aaf238e2a8dfd3d96;SInt32 z74dde8fc4e65e00eaa101166e0a49fc0;
SInt32 z3cdff48e49a45470d8fa905d9d809ff9;SInt32 
z31a4aa1d177c756f2701194c4da17625;SInt32 zd356999b9f9267db4f04a5d4bb011bfc;
SInt32 z8129325be6b494a2c297524760b634d8;SInt32 
z25985910c7d67e01ad9897de114d3d61;UInt32 z9a40fc480cffbc911d305666f7159bb0;
SInt32 zf511b51c107ffe50f171a8409975cec2;UInt16 SPnmAct11_PnmAct_volPnmAct_T;
SInt16 zfc8af2ce95012f479fb4fda0545939dd;SInt16 
zee0518777a26bf3a018ed7efe2ba9cfb;UInt16 z94f8a0c76aa035c34e41d29151673550;
UInt16 z230a413318f8af89fd7974bd479e48a3;UInt16 SPnmAct9_PnmAct_rRCODB_T;UInt8 
zaccdeec5401e3a1449ca05810c928efd;SInt32 zd468f45f7296e73fe1291d4b933ffed7;
SInt32 z06f32ff761b03af45c9f63ba6e33e8d9;SInt32 
z91d6bd6fb6e014158f04ff5ae654b748;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
UInt32 z598fc83d17c7afbb99b61c2115312c40;zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)(((UInt32)(SInt32)(((UInt32)PnmAct_RE002_ExM_pExMnfEstim_in)-((UInt32)
PnmAct_RE002_ExM_pDsTrbEstimSI_in)))-1);if(PnmAct_bSelPresAirExt_C){
z230a413318f8af89fd7974bd479e48a3=PnmAct_RE002_UsThrM_pUsCmpr_in;}else{
z230a413318f8af89fd7974bd479e48a3=PnmAct_RE002_UsThrM_pAirExt_in;}
z8129325be6b494a2c297524760b634d8=(SInt32)(((UInt32)(SInt32)(((UInt32)
z230a413318f8af89fd7974bd479e48a3)-((UInt32)(SInt32)(
z7fe3f8cbad554e0c2564f59320a65ed6>>10))))-1);z06f32ff761b03af45c9f63ba6e33e8d9=(
SInt32)(((UInt32)PnmAct_RE002_TrbAct_rRCOReqRaw_in)+((UInt32)
zca9edea8cad43f7de1304d01733e56ac));z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)
PnmAct_rRCOMin_C;if(z06f32ff761b03af45c9f63ba6e33e8d9>
z91d6bd6fb6e014158f04ff5ae654b748){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
z06f32ff761b03af45c9f63ba6e33e8d9;}else{z21fed86397a19bfad54bda2cfdaa9d19=(
UInt32)z91d6bd6fb6e014158f04ff5ae654b748;}if(((UInt32)PnmAct_rRCOMax_C)<
z21fed86397a19bfad54bda2cfdaa9d19){z94f8a0c76aa035c34e41d29151673550=
PnmAct_rRCOMax_C;}else{z94f8a0c76aa035c34e41d29151673550=(UInt16)
z21fed86397a19bfad54bda2cfdaa9d19;}TabIdxS50T516((const SInt16*)
PnmAct_pDifTrbActEstim2_A,9,(SInt16)(z7fe3f8cbad554e0c2564f59320a65ed6>>10),&(
zfd410d75db385ceeff8f470edb77be11),&(zd273acc013d72280f06f0fbce9d4d51a));
TabIdxS50T513((const UInt16*)PnmAct_pAirExt_A,8,
z230a413318f8af89fd7974bd479e48a3,&(zd56a3f61146d964906a3e7a62318ac24),&(
zae970cb005df1f4c064d7a0ed075653e));zd356999b9f9267db4f04a5d4bb011bfc=(SInt32)((
(UInt32)(SInt32)(((UInt32)z94f8a0c76aa035c34e41d29151673550)-((UInt32)
Tab2DIntp2I1T33281((const UInt16*)&(PnmAct_rRCO_M[0][0]),8,
zfd410d75db385ceeff8f470edb77be11,zd273acc013d72280f06f0fbce9d4d51a,
zd56a3f61146d964906a3e7a62318ac24,zae970cb005df1f4c064d7a0ed075653e))))-1);if(
zd356999b9f9267db4f04a5d4bb011bfc>((SInt32)0)){SInt32 
z8d47e11c3d89c3fa92dbff6c244475f7;SInt32 zb4dc614932615400de5af12a2552c1b5;
SInt32 z5e10af846bcb5473f8dba5e8a40da4dd;SInt32 
z7e0f0b500294f2fd23ab4a418742eea5;SInt32 z36cb84a92bb266c626e16695195f4aa8;
SInt32 z1263ec604286387a1c511304f348f27f;z06f32ff761b03af45c9f63ba6e33e8d9=(
SInt32)(((UInt32)z8129325be6b494a2c297524760b634d8)-1);
z8d47e11c3d89c3fa92dbff6c244475f7=z8129325be6b494a2c297524760b634d8;if(
z8129325be6b494a2c297524760b634d8<0){z8d47e11c3d89c3fa92dbff6c244475f7=-
z8d47e11c3d89c3fa92dbff6c244475f7;}if(1>z8d47e11c3d89c3fa92dbff6c244475f7){
z36cb84a92bb266c626e16695195f4aa8=1;}else{z36cb84a92bb266c626e16695195f4aa8=
z8d47e11c3d89c3fa92dbff6c244475f7;}z1263ec604286387a1c511304f348f27f=(((SInt32)(
((SInt32)PnmAct_pVacRef_C)<<15))+16384)/z36cb84a92bb266c626e16695195f4aa8;if(
z8129325be6b494a2c297524760b634d8>=0){zb4dc614932615400de5af12a2552c1b5=
z1263ec604286387a1c511304f348f27f;}else{zb4dc614932615400de5af12a2552c1b5=-
z1263ec604286387a1c511304f348f27f;}if(zb4dc614932615400de5af12a2552c1b5>1){
z5e10af846bcb5473f8dba5e8a40da4dd=zb4dc614932615400de5af12a2552c1b5;}else{
z5e10af846bcb5473f8dba5e8a40da4dd=1;}if(32768<z5e10af846bcb5473f8dba5e8a40da4dd)
{z7e0f0b500294f2fd23ab4a418742eea5=32768;}else{z7e0f0b500294f2fd23ab4a418742eea5
=z5e10af846bcb5473f8dba5e8a40da4dd;}PnmAct_mfAirOutRaw_MP=((UInt32)
Tab2DS34I2T4172(&(SPnmAct8_PnmAct_mfAirOut_M_map),C__I16FITI32_SAT(
z06f32ff761b03af45c9f63ba6e33e8d9,32767),(UInt16)(((UInt16)(
z7e0f0b500294f2fd23ab4a418742eea5<<1))+65535),&(
za8e60e08755db5f938763ffe5782b344),&(z09f49b6ebf597dc5bab6c8d31a331006)))*((
UInt32)zd356999b9f9267db4f04a5d4bb011bfc);PnmAct_mfAirOut_MP=
PnmAct_mfAirOutRaw_MP;}else{PnmAct_mfAirOut_MP=0;}
z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(((UInt32)PnmAct_mfAirOutMax_C)<<16);
if(z21fed86397a19bfad54bda2cfdaa9d19<PnmAct_mfAirOut_MP){
z9a40fc480cffbc911d305666f7159bb0=z21fed86397a19bfad54bda2cfdaa9d19;}else{
z9a40fc480cffbc911d305666f7159bb0=PnmAct_mfAirOut_MP;}if(
z230a413318f8af89fd7974bd479e48a3!=0){C__I64SHLI32C6_LT32(
z8129325be6b494a2c297524760b634d8,15,17,z06f32ff761b03af45c9f63ba6e33e8d9,
z21fed86397a19bfad54bda2cfdaa9d19);C__I32DIVI64U32(
z06f32ff761b03af45c9f63ba6e33e8d9,z21fed86397a19bfad54bda2cfdaa9d19,(UInt32)
z230a413318f8af89fd7974bd479e48a3,z25985910c7d67e01ad9897de114d3d61);}else{if(
z8129325be6b494a2c297524760b634d8<0){z25985910c7d67e01ad9897de114d3d61=(-
2147483647L-1L);}else{z25985910c7d67e01ad9897de114d3d61=2147483647;}}
C__I64SHLI32C6_LT32(z25985910c7d67e01ad9897de114d3d61,1,31,
z06f32ff761b03af45c9f63ba6e33e8d9,z21fed86397a19bfad54bda2cfdaa9d19);
C__I64SUBI64U32(z06f32ff761b03af45c9f63ba6e33e8d9,
z21fed86397a19bfad54bda2cfdaa9d19,(UInt32)1,z06f32ff761b03af45c9f63ba6e33e8d9,
z21fed86397a19bfad54bda2cfdaa9d19);TabIdxS50T513((const UInt16*)
PnmAct_rPresExtTrbAct_A,10,C__U16FITI64_SAT(z06f32ff761b03af45c9f63ba6e33e8d9,
z21fed86397a19bfad54bda2cfdaa9d19,65535),&(z71da5499ed6785c7c2ee8ba2cf3830b1),&(
z583ad347122014dc28fcd8e647638ba1));SPnmAct9_PnmAct_rRCODB_T=Tab1DIntp2I1T65((
const UInt16*)PnmAct_rRCODB_T,zfd410d75db385ceeff8f470edb77be11,
zd273acc013d72280f06f0fbce9d4d51a);PnmAct_bDB_MP=((SInt32)(((UInt32)
SPnmAct9_PnmAct_rRCODB_T)-65535))>zd356999b9f9267db4f04a5d4bb011bfc;if(
PnmAct_bDB_MP){SInt32 z1d0d41bbfeff6cc7ad2ae22b341e3f69;
z1d0d41bbfeff6cc7ad2ae22b341e3f69=((SInt32)(((UInt32)
zd356999b9f9267db4f04a5d4bb011bfc)-((UInt32)SPnmAct9_PnmAct_rRCODB_T)))+65535;
F__I64MULU32I32((UInt32)Tab2DIntp2I1T33281((const UInt16*)&(PnmAct_mfAirIn_M[0][
0]),10,zd56a3f61146d964906a3e7a62318ac24,zae970cb005df1f4c064d7a0ed075653e,
z71da5499ed6785c7c2ee8ba2cf3830b1,z583ad347122014dc28fcd8e647638ba1),
z1d0d41bbfeff6cc7ad2ae22b341e3f69,&(z06f32ff761b03af45c9f63ba6e33e8d9),&(
z21fed86397a19bfad54bda2cfdaa9d19));PnmAct_mfAirInRaw_MP=C__I32SHRI64C6_LT32(
z06f32ff761b03af45c9f63ba6e33e8d9,z21fed86397a19bfad54bda2cfdaa9d19,1,31);
PnmAct_mfAirIn_MP=PnmAct_mfAirInRaw_MP;}else{PnmAct_mfAirIn_MP=0;}if(
PnmAct_mfAirIn_MP>PnmAct_mfAirInMin_C){zf511b51c107ffe50f171a8409975cec2=
PnmAct_mfAirIn_MP;}else{zf511b51c107ffe50f171a8409975cec2=PnmAct_mfAirInMin_C;}
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(z9a40fc480cffbc911d305666f7159bb0>>3)
;z06f32ff761b03af45c9f63ba6e33e8d9+=((SInt32)(zf511b51c107ffe50f171a8409975cec2
<<1));PnmAct_mfAirTot_MP=(SInt32)(((UInt32)z06f32ff761b03af45c9f63ba6e33e8d9)-((
UInt32)(SInt32)(((UInt32)Tab2DIntp2I1T33281((const UInt16*)&(PnmAct_mfAirInDB_M[
0][0]),10,zd56a3f61146d964906a3e7a62318ac24,zae970cb005df1f4c064d7a0ed075653e,
z71da5499ed6785c7c2ee8ba2cf3830b1,z583ad347122014dc28fcd8e647638ba1))<<9)));
SPnmAct11_PnmAct_volPnmAct_T=Tab1DS2I2T521(&(SPnmAct11_PnmAct_volPnmAct_T_map),
z5722749cca161a8d5d52b2bbe1a5014f,&(zfb2080a2250c2fe8781ecad41e5ce11b));if(
SPnmAct11_PnmAct_volPnmAct_T!=0){PnmAct_pDeltaPnmAct_MP=PnmAct_mfAirTot_MP/
SPnmAct11_PnmAct_volPnmAct_T;}else{if(PnmAct_mfAirTot_MP<0){
PnmAct_pDeltaPnmAct_MP=(-2147483647L-1L);}else{PnmAct_pDeltaPnmAct_MP=2147483647
;}}zc69cd6cba97f7f30484dfb10715d7ff0=(SInt32)(((UInt32)PnmAct_pDeltaPnmAct_MP)+(
(UInt32)z7fe3f8cbad554e0c2564f59320a65ed6));z06f32ff761b03af45c9f63ba6e33e8d9=(
SInt32)(((SInt32)PnmAct_pDifTrbEstimMin_C)<<10);if(
zc69cd6cba97f7f30484dfb10715d7ff0>z06f32ff761b03af45c9f63ba6e33e8d9){
z1c6c5c780d75520bf30c807034e37f68=zc69cd6cba97f7f30484dfb10715d7ff0;}else{
z1c6c5c780d75520bf30c807034e37f68=z06f32ff761b03af45c9f63ba6e33e8d9;}
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((SInt32)
PnmAct_RE002_TrbAct_pDifMaxPnmActReq_in)<<10);if(
z06f32ff761b03af45c9f63ba6e33e8d9<z1c6c5c780d75520bf30c807034e37f68){
z70929c92ba72d314d465d5dc86942c9a=z06f32ff761b03af45c9f63ba6e33e8d9;}else{
z70929c92ba72d314d465d5dc86942c9a=z1c6c5c780d75520bf30c807034e37f68;}
PnmAct_rOpTrbAct_MP=Tab2DS34I2T4196(&(SPnmAct12_TrbAct_rOpTrbActEstim_M_map),
C__I16FITI32_SAT(zd468f45f7296e73fe1291d4b933ffed7,32767),(SInt16)(
z70929c92ba72d314d465d5dc86942c9a>>10),&(z7dd1249e5d89db8cd0fa0c9149d3a12e),&(
ze709d376dc33b858232d454f8227159d));if(PnmAct_facFilGainTrbAct_C){
zaccdeec5401e3a1449ca05810c928efd=PnmAct_facFilGainTrbAct_C;}else{
zaccdeec5401e3a1449ca05810c928efd=0;}if(zc3cbb14ac63a7f5f30ecbbe7530a3df0){
zc5c50f3e678a93554619201dc3ba7294=zf07a3abcde002c64fd411a6aa0ba269d;}else{
zc5c50f3e678a93554619201dc3ba7294=2147483648U;}F__U64MULU32U32((UInt32)(UInt16)(
((UInt16)(-zaccdeec5401e3a1449ca05810c928efd))+256),
zc5c50f3e678a93554619201dc3ba7294,&(z21fed86397a19bfad54bda2cfdaa9d19),&(
z598fc83d17c7afbb99b61c2115312c40));z88466fa517fff7f79b7f50c9b9d72af8=((UInt32)(
(((UInt32)(((UInt32)PnmAct_rOpTrbAct_MP)*((UInt32)
zaccdeec5401e3a1449ca05810c928efd)))+((UInt32)zaccdeec5401e3a1449ca05810c928efd)
)<<7))+C__U32SHRU64C6_LT32(z21fed86397a19bfad54bda2cfdaa9d19,
z598fc83d17c7afbb99b61c2115312c40,8,24);if(zbaba1034d499bbc79c90f14517567dc5){
z462197851b61d1414430ae1d57121608=z88466fa517fff7f79b7f50c9b9d72af8;}else{
z462197851b61d1414430ae1d57121608=2147483648U;}z21fed86397a19bfad54bda2cfdaa9d19
=(UInt32)(z462197851b61d1414430ae1d57121608>>15);if(65535<
z21fed86397a19bfad54bda2cfdaa9d19){PnmAct_rOpTrbActEstim_out=65535;}else{
PnmAct_rOpTrbActEstim_out=(UInt16)z21fed86397a19bfad54bda2cfdaa9d19;}if(
PnmAct_bTrbActCf_C){zee0518777a26bf3a018ed7efe2ba9cfb=(SInt16)(((UInt16)(-
PnmAct_RE002_TrbAct_pDifTrbActReq_in))-1);}else{
zee0518777a26bf3a018ed7efe2ba9cfb=PnmAct_RE002_TrbAct_pDifTrbActReq_in;}
PnmAct_pDifErr_MP=(SInt32)(((UInt32)(SInt32)(((UInt32)
zee0518777a26bf3a018ed7efe2ba9cfb)-((UInt32)(SInt32)(
z70929c92ba72d314d465d5dc86942c9a>>10))))-1);F__I64MULU32I32(PnmAct_FacpGain_C,
PnmAct_pDifErr_MP,&(zd468f45f7296e73fe1291d4b933ffed7),&(
z21fed86397a19bfad54bda2cfdaa9d19));PnmAct_rRCOpCor_MP=((SInt32)
C__I32SHRI64C6_LT32(zd468f45f7296e73fe1291d4b933ffed7,
z21fed86397a19bfad54bda2cfdaa9d19,11,21))+((SInt32)(PnmAct_FacpGain_C>>12));
PnmAct_rRCOReqPrev_MP=zc0780a5ae31a12b85e6f9a62103d4e21;PnmAct_bInhICtl_MP=(
zc0780a5ae31a12b85e6f9a62103d4e21<PnmAct_rRCOLoThd_C)||(
zc0780a5ae31a12b85e6f9a62103d4e21>PnmAct_rRCOHiThd_C);if(PnmAct_bInhICtl_MP){
z31a4aa1d177c756f2701194c4da17625=(SInt32)0;}else{F__I64MULI32U32(
PnmAct_pDifErr_MP,(UInt32)PnmAct_FaciGain_C,&(zd468f45f7296e73fe1291d4b933ffed7)
,&(z21fed86397a19bfad54bda2cfdaa9d19));z31a4aa1d177c756f2701194c4da17625=((
SInt32)C__I32SHRI64C6_LT32(zd468f45f7296e73fe1291d4b933ffed7,
z21fed86397a19bfad54bda2cfdaa9d19,2,30))+((SInt32)(PnmAct_FaciGain_C>>3));}
z3cdff48e49a45470d8fa905d9d809ff9=(SInt32)(((UInt32)
z31a4aa1d177c756f2701194c4da17625)+((UInt32)z253e1cc02658f3f827af88d6f76de4a1));
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)PnmAct_rRCOCorMin_C)<<7);if(
z3cdff48e49a45470d8fa905d9d809ff9>zd468f45f7296e73fe1291d4b933ffed7){
z6c00ea1a233ce8a307b41ac7a3225392=z3cdff48e49a45470d8fa905d9d809ff9;}else{
z6c00ea1a233ce8a307b41ac7a3225392=zd468f45f7296e73fe1291d4b933ffed7;}
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)PnmAct_rRCOCorMax_C)<<7);if(
zd468f45f7296e73fe1291d4b933ffed7<z6c00ea1a233ce8a307b41ac7a3225392){
PnmAct_rRCOiCor_MP=zd468f45f7296e73fe1291d4b933ffed7;}else{PnmAct_rRCOiCor_MP=
z6c00ea1a233ce8a307b41ac7a3225392;}z74dde8fc4e65e00eaa101166e0a49fc0=(SInt32)(((
UInt32)(SInt32)(((UInt32)PnmAct_pDifErr_MP)-((UInt32)
zff36860d4211fa6e347c7a6285f7fa26)))-1);F__I64MULU32I32((UInt32)
PnmAct_FacdGain_C,z74dde8fc4e65e00eaa101166e0a49fc0,&(
zd468f45f7296e73fe1291d4b933ffed7),&(z21fed86397a19bfad54bda2cfdaa9d19));
PnmAct_rRCOdCor_MP=(SInt32)C__I32SHRI64C6_LT32(zd468f45f7296e73fe1291d4b933ffed7
,z21fed86397a19bfad54bda2cfdaa9d19,16,16);zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)(PnmAct_rRCOpCor_MP>>5);zd468f45f7296e73fe1291d4b933ffed7+=((SInt32)(
PnmAct_rRCOiCor_MP>>7));z26fa84b3cca4659aaf238e2a8dfd3d96=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)+((UInt32)PnmAct_rRCOdCor_MP));
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)PnmAct_rRCOCorMin_C;if(
z26fa84b3cca4659aaf238e2a8dfd3d96>zd468f45f7296e73fe1291d4b933ffed7){
z06f32ff761b03af45c9f63ba6e33e8d9=z26fa84b3cca4659aaf238e2a8dfd3d96;}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}if(((SInt32
)PnmAct_rRCOCorMax_C)<z06f32ff761b03af45c9f63ba6e33e8d9){
zfc8af2ce95012f479fb4fda0545939dd=PnmAct_rRCOCorMax_C;}else{
zfc8af2ce95012f479fb4fda0545939dd=(SInt16)z06f32ff761b03af45c9f63ba6e33e8d9;}
PnmAct_rRCOCorReq_out=zfc8af2ce95012f479fb4fda0545939dd;
z7fe3f8cbad554e0c2564f59320a65ed6=z70929c92ba72d314d465d5dc86942c9a;
zca9edea8cad43f7de1304d01733e56ac=(SInt32)(((SInt32)
zfc8af2ce95012f479fb4fda0545939dd)<<1);z5722749cca161a8d5d52b2bbe1a5014f=(UInt16
)(((UInt16)(z462197851b61d1414430ae1d57121608>>15))+65535);
zc3cbb14ac63a7f5f30ecbbe7530a3df0=1;zf07a3abcde002c64fd411a6aa0ba269d=
z88466fa517fff7f79b7f50c9b9d72af8;zbaba1034d499bbc79c90f14517567dc5=1;
zc0780a5ae31a12b85e6f9a62103d4e21=z94f8a0c76aa035c34e41d29151673550;
z253e1cc02658f3f827af88d6f76de4a1=PnmAct_rRCOiCor_MP;
zff36860d4211fa6e347c7a6285f7fa26=PnmAct_pDifErr_MP;}
#define PNMACT_STOP_SEC_CODE
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CODE
#include "PnmAct_MemMap.h"
Void PnmAct_FctVarInit(Void){zfb2080a2250c2fe8781ecad41e5ce11b=0;
z7dd1249e5d89db8cd0fa0c9149d3a12e=0;ze709d376dc33b858232d454f8227159d=0;
za8e60e08755db5f938763ffe5782b344=0;z09f49b6ebf597dc5bab6c8d31a331006=0;
zae970cb005df1f4c064d7a0ed075653e=0;zd56a3f61146d964906a3e7a62318ac24=0;
zd273acc013d72280f06f0fbce9d4d51a=0;zfd410d75db385ceeff8f470edb77be11=0;
z583ad347122014dc28fcd8e647638ba1=0;z71da5499ed6785c7c2ee8ba2cf3830b1=0;
z5722749cca161a8d5d52b2bbe1a5014f=65535;z7fe3f8cbad554e0c2564f59320a65ed6=-512;
zbaba1034d499bbc79c90f14517567dc5=0;zc3cbb14ac63a7f5f30ecbbe7530a3df0=0;
zf07a3abcde002c64fd411a6aa0ba269d=0;zca9edea8cad43f7de1304d01733e56ac=0;
zff36860d4211fa6e347c7a6285f7fa26=-1;z253e1cc02658f3f827af88d6f76de4a1=0;
zc0780a5ae31a12b85e6f9a62103d4e21=0;}
#define PNMACT_STOP_SEC_CODE
#include "PnmAct_MemMap.h"
#endif

