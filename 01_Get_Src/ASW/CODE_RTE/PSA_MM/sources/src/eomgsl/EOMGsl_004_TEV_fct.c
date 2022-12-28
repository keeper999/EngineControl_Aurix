
#ifndef _EOMGSL_004_TEV_FCT_C_
#define _EOMGSL_004_TEV_FCT_C_
#include "library_lut.h"
#include "EOMGsl_004_TEV_fct.h"
#include "EOMGsl_004_calibrations.h"
#define EOMGSL_START_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean EOM_bSpcInjMod_out;AR_IF_GLOBAL_BOOLEAN Boolean 
EOM_bTWCHeatPha_out;AR_IF_GLOBAL_BOOLEAN Boolean EOM_bTranMod_out;
#define EOMGSL_STOP_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_16BIT
#include "EOMGsl_MemMap.h"
static UInt16 z961b67de2a43a5a99a8456aac402b63f;
#define EOMGSL_STOP_SEC_VAR_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
static UInt8 z17034412092199c468ea60c145c164da;static UInt8 
ze9912f32f77d7306ff560ecfef9ff912;
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
static Boolean z77966695a29b59d010645d8762807885;static Boolean 
z7a6accb88ab1f04185fcdfed3c4e2b49;
#define EOMGSL_STOP_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
static Boolean zee3aa0948a56cb9d63d87c6b99380eb8;static Boolean 
zd9e8bb88d076dc1285725e1e72ed82af;
#define EOMGSL_STOP_SEC_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
static UInt8 z6533568a2d9d3b1d124dd321fcaca833;static UInt8 
zc0492d0b3e8097e175d1dd42d0605132;
#define EOMGSL_STOP_SEC_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_VAR_UNSPECIFIED
#include "EOMGsl_MemMap.h"
static struct zd1a376d219976d28f7c639cc9ea12fcf 
za28ff32708016f587d9483fa75bcadb0;
#define EOMGSL_STOP_SEC_VAR_UNSPECIFIED
#include "EOMGsl_MemMap.h"
static Void z21c47e0fca7ad77a88eafaee2f89b81d(Void);
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_004_TEV_fct(Void){UInt16 z0ff3a0b00c988d206a143e9d8e745108;UInt16 
z1dbacece1d98fa29c2367125b6237bdd;UInt16 z4d07e7e2c823c49a982e2b8d9b7c5162;
UInt16 z40290a0a4db2e3511df592b08b0d6efc;UInt16 
zc832c0812af90be49f5f4ac6a7b9691e;UInt16 z829c13a9249677a414c95435ef0ddfa5;
UInt16 z89a1b5948f77ff6c689b1585b9c3e39c;UInt16 
z1c5100621445c284d7a4857a85aeaa70;UInt16 z3689abe2775033d673baa56871aa9df3;
UInt16 za1408d7544c5d3dd1db19ef556f118ca;UInt8 z2ce398cb19db02e581d2b7b0474fad62
;UInt8 z66413b1215fdb5e0b4f803ce54d7dec4;UInt8 zf46bc200bb209412b82f61764119c93f
;UInt8 zfff98d8e525399e3f48f660825e7d9c8;UInt8 z242513f2255f1062d98a9bc0060030ff
;UInt8 zafe75e6ff8a3bdb6c60a3b8846f47d41;UInt8 z86ebb8751daae3ddad7a272285cde188
;UInt8 z8a7e9fb51d2016520e7b997a11d9a3de;SInt32 
zd468f45f7296e73fe1291d4b933ffed7;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
SInt16 z083933e535293d75bb743b103b9f75c1;EOM_bRmpTranEndDly=
zee3aa0948a56cb9d63d87c6b99380eb8;if(za28ff32708016f587d9483fa75bcadb0.
zabf0e01207f605b49148135708c35977){za28ff32708016f587d9483fa75bcadb0.
zabf0e01207f605b49148135708c35977=0;za28ff32708016f587d9483fa75bcadb0.
z4a052598993b4333361aaeb65ec9fd0a=1;z21c47e0fca7ad77a88eafaee2f89b81d();}else{if
(za28ff32708016f587d9483fa75bcadb0.z4a052598993b4333361aaeb65ec9fd0a){if(
RE004_EOM_bDiTran_in){if(za28ff32708016f587d9483fa75bcadb0.
zf32e303d35e04f9af4d6471a0a457517){za28ff32708016f587d9483fa75bcadb0.
zf32e303d35e04f9af4d6471a0a457517=0;}else{za28ff32708016f587d9483fa75bcadb0.
z7af7395280d171b6942072aee71dfd88=0;}za28ff32708016f587d9483fa75bcadb0.
z4a052598993b4333361aaeb65ec9fd0a=0;za28ff32708016f587d9483fa75bcadb0.
zaf12c6b48bebb2dc6ab0af07b27a41a9=1;za28ff32708016f587d9483fa75bcadb0.
zb4954c6223aeba6ffd725fe80a500782=1;z17034412092199c468ea60c145c164da=
RE004_EOM_stCmbModReq_in;ze9912f32f77d7306ff560ecfef9ff912=
RE004_EOM_stCmbModReq_in;z77966695a29b59d010645d8762807885=1;
z7a6accb88ab1f04185fcdfed3c4e2b49=1;z961b67de2a43a5a99a8456aac402b63f=0;}else{if
(za28ff32708016f587d9483fa75bcadb0.zf32e303d35e04f9af4d6471a0a457517){if(
zee3aa0948a56cb9d63d87c6b99380eb8&&(z961b67de2a43a5a99a8456aac402b63f<=
EOM_tiTranMax_C)){za28ff32708016f587d9483fa75bcadb0.
zf32e303d35e04f9af4d6471a0a457517=0;z21c47e0fca7ad77a88eafaee2f89b81d();}else{if
(z961b67de2a43a5a99a8456aac402b63f>EOM_tiTranMax_C){
za28ff32708016f587d9483fa75bcadb0.zf32e303d35e04f9af4d6471a0a457517=0;
z21c47e0fca7ad77a88eafaee2f89b81d();}else{z961b67de2a43a5a99a8456aac402b63f=(
UInt16)(z961b67de2a43a5a99a8456aac402b63f+5);}}}else{if(
za28ff32708016f587d9483fa75bcadb0.z7af7395280d171b6942072aee71dfd88){if(
RE004_EOM_stCmbModReq_in!=z17034412092199c468ea60c145c164da){
za28ff32708016f587d9483fa75bcadb0.z7af7395280d171b6942072aee71dfd88=0;
za28ff32708016f587d9483fa75bcadb0.zf32e303d35e04f9af4d6471a0a457517=1;
ze9912f32f77d7306ff560ecfef9ff912=RE004_EOM_stCmbModReq_in;
z77966695a29b59d010645d8762807885=0;z7a6accb88ab1f04185fcdfed3c4e2b49=1;}}}}}
else{if(za28ff32708016f587d9483fa75bcadb0.zc5be4c5f2cc074fbafbef66b701b7a99){
za28ff32708016f587d9483fa75bcadb0.zc5be4c5f2cc074fbafbef66b701b7a99=0;
za28ff32708016f587d9483fa75bcadb0.z4a052598993b4333361aaeb65ec9fd0a=1;
z21c47e0fca7ad77a88eafaee2f89b81d();}else{if(za28ff32708016f587d9483fa75bcadb0.
zaf12c6b48bebb2dc6ab0af07b27a41a9){if(!(RE004_EOM_bDiTran_in)){
za28ff32708016f587d9483fa75bcadb0.zb4954c6223aeba6ffd725fe80a500782=0;
za28ff32708016f587d9483fa75bcadb0.zaf12c6b48bebb2dc6ab0af07b27a41a9=0;
za28ff32708016f587d9483fa75bcadb0.z4a052598993b4333361aaeb65ec9fd0a=1;
z21c47e0fca7ad77a88eafaee2f89b81d();}else{if(za28ff32708016f587d9483fa75bcadb0.
zb4954c6223aeba6ffd725fe80a500782){if(RE004_EOM_stCmbModReq_in!=
z17034412092199c468ea60c145c164da){za28ff32708016f587d9483fa75bcadb0.
zb4954c6223aeba6ffd725fe80a500782=1;z17034412092199c468ea60c145c164da=
RE004_EOM_stCmbModReq_in;ze9912f32f77d7306ff560ecfef9ff912=
RE004_EOM_stCmbModReq_in;z77966695a29b59d010645d8762807885=1;
z7a6accb88ab1f04185fcdfed3c4e2b49=1;z961b67de2a43a5a99a8456aac402b63f=0;}else{
z7a6accb88ab1f04185fcdfed3c4e2b49=0;}}}}else{if(!(
za28ff32708016f587d9483fa75bcadb0.z200e638cb93af591a6bdc9f35cd13398)){
za28ff32708016f587d9483fa75bcadb0.z200e638cb93af591a6bdc9f35cd13398=1;switch(
RE004_EOM_bFdoutModReq_in){case 1:{za28ff32708016f587d9483fa75bcadb0.
zc5be4c5f2cc074fbafbef66b701b7a99=1;z17034412092199c468ea60c145c164da=2;
ze9912f32f77d7306ff560ecfef9ff912=2;z77966695a29b59d010645d8762807885=1;break;}
case 0:{za28ff32708016f587d9483fa75bcadb0.zabf0e01207f605b49148135708c35977=1;
z17034412092199c468ea60c145c164da=0;ze9912f32f77d7306ff560ecfef9ff912=0;
z77966695a29b59d010645d8762807885=1;break;}default:{break;}}}}}}}TabIdxS50T513((
const UInt16*)EOM_stCmdModCur_stTranTypX_A,21,(UInt16)(((UInt16)
z17034412092199c468ea60c145c164da)+1),&(zc0492d0b3e8097e175d1dd42d0605132),&(
z1dbacece1d98fa29c2367125b6237bdd));TabIdxS50T513((const UInt16*)
EOM_stCmdModTar_stTranTypY_A,21,(UInt16)(((UInt16)
ze9912f32f77d7306ff560ecfef9ff912)+1),&(z6533568a2d9d3b1d124dd321fcaca833),&(
z0ff3a0b00c988d206a143e9d8e745108));EOM_stTranTyp=Tab2DIntp2I1T33280((const 
UInt8*)&(EOM_stTranTyp_M[0][0]),21,zc0492d0b3e8097e175d1dd42d0605132,
z1dbacece1d98fa29c2367125b6237bdd,z6533568a2d9d3b1d124dd321fcaca833,
z0ff3a0b00c988d206a143e9d8e745108);EOM_tiRmpInjSys=EOM_tiRmpInjSys_T[
EOM_stTranTyp];EOM_tiTran=z961b67de2a43a5a99a8456aac402b63f;
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiInjTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7){
EOM_tiInjRmp=0;}else{EOM_tiInjRmp=(UInt16)zd468f45f7296e73fe1291d4b933ffed7;}if(
1>EOM_tiRmpInjSys){z4d07e7e2c823c49a982e2b8d9b7c5162=1;}else{
z4d07e7e2c823c49a982e2b8d9b7c5162=EOM_tiRmpInjSys;}
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((UInt32)
EOM_tiInjRmp)<<7))/z4d07e7e2c823c49a982e2b8d9b7c5162)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){z2ce398cb19db02e581d2b7b0474fad62=128;}
else{z2ce398cb19db02e581d2b7b0474fad62=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpPFu=EOM_tiRmpPFu_T[EOM_stTranTyp];zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)(((UInt32)EOM_tiTran)-((UInt32)EOM_tiInjPFuTranDly_T[EOM_stTranTyp]));if(
0>zd468f45f7296e73fe1291d4b933ffed7){EOM_tiPFuRmp=0;}else{EOM_tiPFuRmp=(UInt16)
zd468f45f7296e73fe1291d4b933ffed7;}if(1>EOM_tiRmpPFu){
z40290a0a4db2e3511df592b08b0d6efc=1;}else{z40290a0a4db2e3511df592b08b0d6efc=
EOM_tiRmpPFu;}zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((
UInt32)EOM_tiPFuRmp)<<7))/z40290a0a4db2e3511df592b08b0d6efc)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){z66413b1215fdb5e0b4f803ce54d7dec4=128;}
else{z66413b1215fdb5e0b4f803ce54d7dec4=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpVlvSys=EOM_tiRmpVlvSys_T[EOM_stTranTyp];
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiVlvTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7){
EOM_tiVlvRmp=0;}else{EOM_tiVlvRmp=(UInt16)zd468f45f7296e73fe1291d4b933ffed7;}if(
1>EOM_tiRmpVlvSys){zc832c0812af90be49f5f4ac6a7b9691e=1;}else{
zc832c0812af90be49f5f4ac6a7b9691e=EOM_tiRmpVlvSys;}
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((UInt32)
EOM_tiVlvRmp)<<7))/zc832c0812af90be49f5f4ac6a7b9691e)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){zf46bc200bb209412b82f61764119c93f=128;}
else{zf46bc200bb209412b82f61764119c93f=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpTqRes=EOM_tiRmpTqRes_T[EOM_stTranTyp];
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiTqResTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7){
EOM_tiTqResRmp=0;}else{EOM_tiTqResRmp=(UInt16)zd468f45f7296e73fe1291d4b933ffed7;
}if(1>EOM_tiRmpTqRes){z829c13a9249677a414c95435ef0ddfa5=1;}else{
z829c13a9249677a414c95435ef0ddfa5=EOM_tiRmpTqRes;}
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((UInt32)
EOM_tiTqResRmp)<<7))/z829c13a9249677a414c95435ef0ddfa5)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){zfff98d8e525399e3f48f660825e7d9c8=128;}
else{zfff98d8e525399e3f48f660825e7d9c8=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpTarIdl=EOM_tiRmpTarIdl_T[EOM_stTranTyp];
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiTarIdlTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7){
EOM_tiTarIdlRmp=0;}else{EOM_tiTarIdlRmp=(UInt16)
zd468f45f7296e73fe1291d4b933ffed7;}if(1>EOM_tiRmpTarIdl){
z89a1b5948f77ff6c689b1585b9c3e39c=1;}else{z89a1b5948f77ff6c689b1585b9c3e39c=
EOM_tiRmpTarIdl;}zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)
(((UInt32)EOM_tiTarIdlRmp)<<7))/z89a1b5948f77ff6c689b1585b9c3e39c)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){z242513f2255f1062d98a9bc0060030ff=128;}
else{z242513f2255f1062d98a9bc0060030ff=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpIgSys=EOM_tiRmpIgSys_T[EOM_stTranTyp];
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiIgSysTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7){
EOM_tiIgSysRmp=0;}else{EOM_tiIgSysRmp=(UInt16)zd468f45f7296e73fe1291d4b933ffed7;
}if(1>EOM_tiRmpIgSys){z1c5100621445c284d7a4857a85aeaa70=1;}else{
z1c5100621445c284d7a4857a85aeaa70=EOM_tiRmpIgSys;}
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((UInt32)
EOM_tiIgSysRmp)<<7))/z1c5100621445c284d7a4857a85aeaa70)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){zafe75e6ff8a3bdb6c60a3b8846f47d41=128;}
else{zafe75e6ff8a3bdb6c60a3b8846f47d41=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpTEx=EOM_tiRmpTEx_T[EOM_stTranTyp];zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)(((UInt32)EOM_tiTran)-((UInt32)EOM_tiTExTranDly_T[EOM_stTranTyp]));if(0>
zd468f45f7296e73fe1291d4b933ffed7){EOM_tiTExRmp=0;}else{EOM_tiTExRmp=(UInt16)
zd468f45f7296e73fe1291d4b933ffed7;}if(1>EOM_tiRmpTEx){
z3689abe2775033d673baa56871aa9df3=1;}else{z3689abe2775033d673baa56871aa9df3=
EOM_tiRmpTEx;}zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((UInt32)(((
UInt32)EOM_tiTExRmp)<<7))/z3689abe2775033d673baa56871aa9df3)<<1))>>1);if(
zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}if(
128<z21fed86397a19bfad54bda2cfdaa9d19){z86ebb8751daae3ddad7a272285cde188=128;}
else{z86ebb8751daae3ddad7a272285cde188=(UInt8)z21fed86397a19bfad54bda2cfdaa9d19;
}EOM_tiRmpRateMixt=EOM_tiRmpRateMixt_T[EOM_stTranTyp];
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)EOM_tiTran)-((UInt32)
EOM_tiTRateMixtTranDly_T[EOM_stTranTyp]));if(0>zd468f45f7296e73fe1291d4b933ffed7
){EOM_tiRateMixtRmp=0;}else{EOM_tiRateMixtRmp=(UInt16)
zd468f45f7296e73fe1291d4b933ffed7;}if(1>EOM_tiRmpRateMixt){
za1408d7544c5d3dd1db19ef556f118ca=1;}else{za1408d7544c5d3dd1db19ef556f118ca=
EOM_tiRmpRateMixt;}zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((SInt32)((((
UInt32)(((UInt32)EOM_tiRateMixtRmp)<<7))/za1408d7544c5d3dd1db19ef556f118ca)<<1))
>>1);if(zd468f45f7296e73fe1291d4b933ffed7>0){z21fed86397a19bfad54bda2cfdaa9d19=(
UInt32)zd468f45f7296e73fe1291d4b933ffed7;}else{z21fed86397a19bfad54bda2cfdaa9d19
=0;}if(128<z21fed86397a19bfad54bda2cfdaa9d19){z8a7e9fb51d2016520e7b997a11d9a3de=
128;}else{z8a7e9fb51d2016520e7b997a11d9a3de=(UInt8)
z21fed86397a19bfad54bda2cfdaa9d19;}z083933e535293d75bb743b103b9f75c1=(SInt16)(((
UInt16)z2ce398cb19db02e581d2b7b0474fad62)<<4);z083933e535293d75bb743b103b9f75c1
+=((SInt16)(((UInt16)z66413b1215fdb5e0b4f803ce54d7dec4)<<4));
z083933e535293d75bb743b103b9f75c1+=((SInt16)(((UInt16)
zf46bc200bb209412b82f61764119c93f)<<4));z083933e535293d75bb743b103b9f75c1+=((
SInt16)(((UInt16)zfff98d8e525399e3f48f660825e7d9c8)<<4));
z083933e535293d75bb743b103b9f75c1+=((SInt16)(((UInt16)
z242513f2255f1062d98a9bc0060030ff)<<4));z083933e535293d75bb743b103b9f75c1+=((
SInt16)(((UInt16)zafe75e6ff8a3bdb6c60a3b8846f47d41)<<4));
z083933e535293d75bb743b103b9f75c1+=((SInt16)(((UInt16)
z86ebb8751daae3ddad7a272285cde188)<<4));EOM_bRmpTranEnd=((SInt16)(
z083933e535293d75bb743b103b9f75c1+((SInt16)(((UInt16)
z8a7e9fb51d2016520e7b997a11d9a3de)<<4))))==16384;
RE004_EOM_prm_facTranModNotSync_16_out=0;RE004_EOM_prm_facTranModNotSync_15_out=
0;RE004_EOM_prm_facTranModNotSync_14_out=z86ebb8751daae3ddad7a272285cde188;
RE004_EOM_prm_facTranModNotSync_13_out=zafe75e6ff8a3bdb6c60a3b8846f47d41;
RE004_EOM_prm_facTranModNotSync_12_out=zafe75e6ff8a3bdb6c60a3b8846f47d41;
RE004_EOM_prm_facTranModNotSync_11_out=zafe75e6ff8a3bdb6c60a3b8846f47d41;
RE004_EOM_prm_facTranModNotSync_10_out=zafe75e6ff8a3bdb6c60a3b8846f47d41;
RE004_EOM_prm_facTranModNotSync_09_out=zafe75e6ff8a3bdb6c60a3b8846f47d41;
RE004_EOM_prm_facTranModNotSync_08_out=z242513f2255f1062d98a9bc0060030ff;
RE004_EOM_prm_facTranModNotSync_07_out=zfff98d8e525399e3f48f660825e7d9c8;
RE004_EOM_prm_facTranModNotSync_06_out=z8a7e9fb51d2016520e7b997a11d9a3de;
RE004_EOM_prm_facTranModNotSync_05_out=zf46bc200bb209412b82f61764119c93f;
RE004_EOM_prm_facTranModNotSync_04_out=z2ce398cb19db02e581d2b7b0474fad62;
RE004_EOM_prm_facTranModNotSync_03_out=z2ce398cb19db02e581d2b7b0474fad62;
RE004_EOM_prm_facTranModNotSync_02_out=z2ce398cb19db02e581d2b7b0474fad62;
RE004_EOM_prm_facTranModNotSync_01_out=z66413b1215fdb5e0b4f803ce54d7dec4;
EOM_bSpcInjMod_out=z17034412092199c468ea60c145c164da==13;EOM_bEnaCmbModChgNotDly
=z77966695a29b59d010645d8762807885;RE004_EOM_bEnaCmbModChg_out=
zd9e8bb88d076dc1285725e1e72ed82af;EOM_bTranMod_out=
z7a6accb88ab1f04185fcdfed3c4e2b49;EOM_bTWCHeatPha_out=(
z17034412092199c468ea60c145c164da<=11)&&(z17034412092199c468ea60c145c164da>=5);
RE004_EOM_stCmbModCur_out=z17034412092199c468ea60c145c164da;
RE004_EOM_stCmbModTar_out=ze9912f32f77d7306ff560ecfef9ff912;
zee3aa0948a56cb9d63d87c6b99380eb8=EOM_bRmpTranEnd;
zd9e8bb88d076dc1285725e1e72ed82af=EOM_bEnaCmbModChgNotDly;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_004_TEV_ini(Void){EOMGsl_004_FctVarInit();}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
Void EOMGsl_004_FctVarInit(Void){z77966695a29b59d010645d8762807885=0;
z7a6accb88ab1f04185fcdfed3c4e2b49=0;z17034412092199c468ea60c145c164da=0;
ze9912f32f77d7306ff560ecfef9ff912=0;z961b67de2a43a5a99a8456aac402b63f=0;
z6533568a2d9d3b1d124dd321fcaca833=0;zc0492d0b3e8097e175d1dd42d0605132=0;
za28ff32708016f587d9483fa75bcadb0.z200e638cb93af591a6bdc9f35cd13398=0;
za28ff32708016f587d9483fa75bcadb0.zabf0e01207f605b49148135708c35977=0;
za28ff32708016f587d9483fa75bcadb0.z4a052598993b4333361aaeb65ec9fd0a=0;
za28ff32708016f587d9483fa75bcadb0.zf32e303d35e04f9af4d6471a0a457517=0;
za28ff32708016f587d9483fa75bcadb0.z7af7395280d171b6942072aee71dfd88=0;
za28ff32708016f587d9483fa75bcadb0.zc5be4c5f2cc074fbafbef66b701b7a99=0;
za28ff32708016f587d9483fa75bcadb0.zaf12c6b48bebb2dc6ab0af07b27a41a9=0;
za28ff32708016f587d9483fa75bcadb0.zb4954c6223aeba6ffd725fe80a500782=0;
zee3aa0948a56cb9d63d87c6b99380eb8=0;zd9e8bb88d076dc1285725e1e72ed82af=1;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
static Void z21c47e0fca7ad77a88eafaee2f89b81d(Void){
za28ff32708016f587d9483fa75bcadb0.z7af7395280d171b6942072aee71dfd88=1;
z17034412092199c468ea60c145c164da=ze9912f32f77d7306ff560ecfef9ff912;
z77966695a29b59d010645d8762807885=1;z7a6accb88ab1f04185fcdfed3c4e2b49=0;
z961b67de2a43a5a99a8456aac402b63f=0;}
#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"
#endif

