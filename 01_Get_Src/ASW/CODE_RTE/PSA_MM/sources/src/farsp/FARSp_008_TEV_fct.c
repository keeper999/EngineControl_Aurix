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
* %name: FARSp_008_TEV_fct.c %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:54:54 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_008_TEV_fct.c-4.0.build1:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_008_TEV_FCT_C_
#define _FARSP_008_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_008_TEV_fct.h"
#include "FARSp_008_calibrations.h"
#include "dsfxp.h"
#include "FARSp_calibrations.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE008_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE008_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE008_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE008_UsThrM_pAirExtEstim_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtFullLdSpRaw_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE008_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE008_AfuA_bFlexAdpAcv_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE008_TqSys_bAuthRich_in;AR_IF_GLOBAL_BOOLEAN
 Boolean FARSp_bAcvRichFullLd_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 ze52d3fa58e3351032d0638f2ebb55c8e;static UInt16 
z49c21d4b59ad58a9997969dc1c40a4a3;static UInt16 
z2e49a776930bf6e13489439661ea7a5a;static UInt16 
za88935f13349b9fb0cdc4b845651cd0c;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_32BIT UInt32 z8a3810b5efddc9355a3eac94fa1abb46;AR_SEC_VAR_32BIT 
UInt32 zffb5762868cb4dd832b48274acca5c00;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
AR_SEC_VAR_8BIT UInt8 z2582b2f9d6e66827b65657f4b935ca9a;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z1d396f7ce39a4e1259ff47a502ddb2b2;static UInt8 
zb06a9d971a107da5ee73c5be9f35b181;static UInt8 z42256e2cdaf28f80756b70b8b60cbcf7
;static UInt8 z31aed7b8b9165773fc2e69ed8930338b;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
static Boolean z7a15368fa6feedf9b1e3f7897898c9a9;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_SEC_VAR_BOOLEAN Boolean zd599232c540e89c7ac0045e7a53799a0;AR_SEC_VAR_BOOLEAN 
Boolean z61a23c7a7bc417b5f1583bf5cd01ff2f;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_007_MSE_ini(Void){FARSp_008_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_008_TEV_fct(Void){SInt32 zcbef50c5fb159f946db6ed287e41f768;SInt32 
z1311269ce58023070a45ef1bec58461f;UInt32 zacf62dfc43833890072cea8fb8fe0978;
SInt32 z88062b9417702b2411115599b367bd1c;UInt32 
z2e28701ef49deba177ec893560508ceb;SInt32 z3b42dfcf49c3005442cd8ad4e76e61fb;
SInt32 z7dc6172cc469a63dbed5c45407b5cd8f;UInt32 
zcd29f873a768661ee3957831dc5dfe11;UInt32 z2598987833881371c51dc4aac9af212d;
UInt32 ze743d4f6268d679a3a4234e02e41bd85;UInt32 
z0486e74cd01ac463a4388c45f7ba4af5;UInt32 z81cd42ac2bc3c961d270df400edd9026;
UInt32 z29fb240070f90dd109ed762f6058159c;SInt16 
z1594682a4c22b679f6631676c2b46982;UInt16 zd126a7e0255faf5db64b555a83edad68;
UInt16 z4cdb7721aacde5e82c640d1b519f9789;UInt16 
z4e10aea4d19121794e1e1d1945abf345;UInt16 z1cab202f24fd2fbc79d355b9748f6cc4;
UInt16 zce7dd997d4b2885a6124c54c902c9af8;UInt8 zbe974039a671bf01d089020ebcd92716
;UInt8 zc1cc0bfadaed524e5cbfe0d2f9eb461d;Boolean 
ze1a98f750561fc24a084f1529fd886dc;Boolean ze6dda10cdb4b42cfbb8e21423ddd039c;
UInt8 zcde11e037b4d32da85f9f25ec7d0479b;UInt8 z70e194cc5e01a85a6bd8520bfd002c33;
Boolean z003b2e6a0c1e611c3edbe7613c5854a9;Boolean 
z25b4eda641d2f7aced706c6a0bad6d66;Boolean ze08553c4d0cdb8697081892f453f1ad7;
Boolean zcc9ea4f6edb590898ccae56a0103ff5f;Boolean 
z5f049ae895d48528d0250ba123db7970;Boolean z1e25dacbc3b80981fe8e815f92572a87;
Boolean z141221ca42d49e2674f3d2254f2968bc;Boolean 
z66191cbda9c676252a42064a521cde8b;Boolean z481165ac78aa60f4f892730d3d872d2b;
Boolean z634d1c74fd24af5debae1068b50a4445;Boolean 
z6e81b1fa3bafc46877847eae0c3b62e1;Boolean z3149f4817a5b02b43919d0076fbdcf8d;
UInt8 zbd4e01a09e98f3c4d167f84807bd0aa9;Boolean 
zcf90cc6ccbeef76d0fbad02426d0f914;UInt8 z90b149c8026f8853a1e8a1d668ec1c90;UInt8 
zfe8cb3dd5e3aa900d71b4494552c9152;UInt8 zc6cf9e1be60566e191b1094fb849edc0;
Boolean ze77dc1383c344981fece2ca3922c1f84;Boolean 
zdb0d8a1f11967b8c3af6d7a47b1bdddb;SInt32 z9952894c8792c930180e1bb753749439;
UInt32 z714f886ee91a45d2f0b285351ea60810;UInt32 
z5b5dda10a4deac02a9d1952cc6909f26;UInt32 z1b6c2592abf49f3d6e5a2cd4e158bc59;
SInt32 z71034583e7ad0155ef8aa49c512a61b3;UInt32 
z86c4d0ac8c46ee4e1c9d7163c0584249;FARSp_facFullLdSpGas=
FARSp_RE008_FARSp_prm_facGasFlexSp_in[4];if(FARSp_facFullLdSpGas>0){
zbe974039a671bf01d089020ebcd92716=FARSp_facFullLdSpGas;}else{
zbe974039a671bf01d089020ebcd92716=0;}if(128<zbe974039a671bf01d089020ebcd92716){
zc1cc0bfadaed524e5cbfe0d2f9eb461d=128;}else{zc1cc0bfadaed524e5cbfe0d2f9eb461d=
zbe974039a671bf01d089020ebcd92716;}FARSp_rMixtFullLdSpGas=
FARSp_RE008_FARSp_prm_rMixtGasFlexSp_in[4];FARSp_facFullLdSpFlex=
FARSp_RE008_FARSp_prm_facGasFlexSp_in[5];if(FARSp_facFullLdSpFlex>0){
zcde11e037b4d32da85f9f25ec7d0479b=FARSp_facFullLdSpFlex;}else{
zcde11e037b4d32da85f9f25ec7d0479b=0;}if(128<zcde11e037b4d32da85f9f25ec7d0479b){
z70e194cc5e01a85a6bd8520bfd002c33=128;}else{z70e194cc5e01a85a6bd8520bfd002c33=
zcde11e037b4d32da85f9f25ec7d0479b;}FARSp_rMixtFullLdSpFlex=
FARSp_RE008_FARSp_prm_rMixtGasFlexSp_in[5];TabIdxS50T513((const UInt16*)
FARSp_nEngFullLdX_A,12,FARSp_RE008_Ext_nEng_in,&(
z31aed7b8b9165773fc2e69ed8930338b),&(za88935f13349b9fb0cdc4b845651cd0c));
TabIdxS50T513((const UInt16*)FARSp_pAirExtEstimFullLdY_A,6,
FARSp_RE008_UsThrM_pAirExtEstim_in,&(z42256e2cdaf28f80756b70b8b60cbcf7),&(
z2e49a776930bf6e13489439661ea7a5a));FARSp_rMixtFullLdSpGsl=Tab2DIntp2I1T33281((
const UInt16*)&(FARSp_rMixtFullLdGsl_M[0][0]),6,
z31aed7b8b9165773fc2e69ed8930338b,za88935f13349b9fb0cdc4b845651cd0c,
z42256e2cdaf28f80756b70b8b60cbcf7,z2e49a776930bf6e13489439661ea7a5a);
z3b42dfcf49c3005442cd8ad4e76e61fb=(SInt32)(((SInt32)(((UInt32)
FARSp_rMixtFullLdSpFlex)-((UInt32)FARSp_rMixtFullLdSpGsl)))<<12);F__I64MULU32I32
((UInt32)z70e194cc5e01a85a6bd8520bfd002c33,z3b42dfcf49c3005442cd8ad4e76e61fb,&(
z71034583e7ad0155ef8aa49c512a61b3),&(z86c4d0ac8c46ee4e1c9d7163c0584249));
z88062b9417702b2411115599b367bd1c=C__I32SHRI64C6_LT32(
z71034583e7ad0155ef8aa49c512a61b3,z86c4d0ac8c46ee4e1c9d7163c0584249,7,25);
FARSp_rMixtFullLdFlex_MP=(UInt32)(z88062b9417702b2411115599b367bd1c+((UInt32)(((
UInt32)FARSp_rMixtFullLdSpGsl)<<12)));z2e28701ef49deba177ec893560508ceb=
FARSp_rMixtFullLdFlex_MP;z1311269ce58023070a45ef1bec58461f=(SInt32)(((UInt32)(
SInt32)(((UInt32)FARSp_rMixtFullLdSpGas)<<12))-z2e28701ef49deba177ec893560508ceb
);F__I64MULU32I32((UInt32)zc1cc0bfadaed524e5cbfe0d2f9eb461d,
z1311269ce58023070a45ef1bec58461f,&(z9952894c8792c930180e1bb753749439),&(
z714f886ee91a45d2f0b285351ea60810));zcbef50c5fb159f946db6ed287e41f768=
C__I32SHRI64C6_LT32(z9952894c8792c930180e1bb753749439,
z714f886ee91a45d2f0b285351ea60810,7,25);zacf62dfc43833890072cea8fb8fe0978=(
UInt32)(zcbef50c5fb159f946db6ed287e41f768+z2e28701ef49deba177ec893560508ceb);
z90b149c8026f8853a1e8a1d668ec1c90=(UInt8)(z2582b2f9d6e66827b65657f4b935ca9a+1);
if(FARSp_RE008_AfuA_bFlexAdpAcv_in&&FARSp_bFlexAdpAuth_C){
z5f049ae895d48528d0250ba123db7970=1;}else{z5f049ae895d48528d0250ba123db7970=0;}
if(!(z5f049ae895d48528d0250ba123db7970)){zcc9ea4f6edb590898ccae56a0103ff5f=1;}
else{zcc9ea4f6edb590898ccae56a0103ff5f=0;}if(zcc9ea4f6edb590898ccae56a0103ff5f&&
FARSp_RE008_TqSys_bAuthRich_in){ze08553c4d0cdb8697081892f453f1ad7=1;}else{
ze08553c4d0cdb8697081892f453f1ad7=0;}if(ze08553c4d0cdb8697081892f453f1ad7!=0){
zfe8cb3dd5e3aa900d71b4494552c9152=z90b149c8026f8853a1e8a1d668ec1c90;}else{
zfe8cb3dd5e3aa900d71b4494552c9152=0;}if(FARSp_RE008_TqSys_bAuthRich_in&&(!(
z7a15368fa6feedf9b1e3f7897898c9a9))){TabIdxS50T513((const UInt16*)
FARSp_nEngFullLdDlyX_A,6,FARSp_RE008_Ext_nEng_in,&(
zb06a9d971a107da5ee73c5be9f35b181),&(z49c21d4b59ad58a9997969dc1c40a4a3));
TabIdxS50T513((const UInt16*)FARSp_rAirCorLdFullLdDlyY_A,6,
FARSp_RE008_EngM_rAirLdCor_in,&(z1d396f7ce39a4e1259ff47a502ddb2b2),&(
ze52d3fa58e3351032d0638f2ebb55c8e));FARSp_tiFullLdDly=Tab2DIntp2I1T33280((const 
UInt8*)&(FARSp_tiFullLdDly_M[0][0]),6,zb06a9d971a107da5ee73c5be9f35b181,
z49c21d4b59ad58a9997969dc1c40a4a3,z1d396f7ce39a4e1259ff47a502ddb2b2,
ze52d3fa58e3351032d0638f2ebb55c8e);}if(FARSp_tiSdlFARSp_C!=0){
zc6cf9e1be60566e191b1094fb849edc0=(UInt8)((((UInt16)FARSp_tiFullLdDly)*10)/
FARSp_tiSdlFARSp_C);}else{zc6cf9e1be60566e191b1094fb849edc0=255;}if(
zfe8cb3dd5e3aa900d71b4494552c9152>zc6cf9e1be60566e191b1094fb849edc0){
zcf90cc6ccbeef76d0fbad02426d0f914=1;}else{zcf90cc6ccbeef76d0fbad02426d0f914=0;}
if(ze08553c4d0cdb8697081892f453f1ad7&&zcf90cc6ccbeef76d0fbad02426d0f914){
FARSp_bAcvRichFullLdDly=1;}else{FARSp_bAcvRichFullLdDly=0;}if(
FARSp_bAcvRichFullLdDly!=0){zd126a7e0255faf5db64b555a83edad68=(UInt16)(
zacf62dfc43833890072cea8fb8fe0978>>12);}else{zd126a7e0255faf5db64b555a83edad68=
4096;}if(zfe8cb3dd5e3aa900d71b4494552c9152<zc6cf9e1be60566e191b1094fb849edc0){
zbd4e01a09e98f3c4d167f84807bd0aa9=zfe8cb3dd5e3aa900d71b4494552c9152;}else{
zbd4e01a09e98f3c4d167f84807bd0aa9=zc6cf9e1be60566e191b1094fb849edc0;}
z7dc6172cc469a63dbed5c45407b5cd8f=(SInt32)(((UInt32)
zd126a7e0255faf5db64b555a83edad68)-((UInt32)(SInt32)(
z8a3810b5efddc9355a3eac94fa1abb46>>12)));if(z7dc6172cc469a63dbed5c45407b5cd8f<0)
{z6e81b1fa3bafc46877847eae0c3b62e1=1;}else{z6e81b1fa3bafc46877847eae0c3b62e1=0;}
if(z6e81b1fa3bafc46877847eae0c3b62e1!=0){z4cdb7721aacde5e82c640d1b519f9789=
FARSp_facFilFullLdNeg_C;}else{z4cdb7721aacde5e82c640d1b519f9789=
FARSp_facFilFullLdPos_C;}if(z4cdb7721aacde5e82c640d1b519f9789<=0){
zdb0d8a1f11967b8c3af6d7a47b1bdddb=1;}else{zdb0d8a1f11967b8c3af6d7a47b1bdddb=0;}
if(FARSp_facFullLdSpFlex<=0){z25b4eda641d2f7aced706c6a0bad6d66=1;}else{
z25b4eda641d2f7aced706c6a0bad6d66=0;}if(FARSp_facFullLdSpGas<=0){
ze6dda10cdb4b42cfbb8e21423ddd039c=1;}else{ze6dda10cdb4b42cfbb8e21423ddd039c=0;}
if(16384<=z4cdb7721aacde5e82c640d1b519f9789){ze77dc1383c344981fece2ca3922c1f84=1
;}else{ze77dc1383c344981fece2ca3922c1f84=0;}if(128<=FARSp_facFullLdSpFlex){
z003b2e6a0c1e611c3edbe7613c5854a9=1;}else{z003b2e6a0c1e611c3edbe7613c5854a9=0;}
if(128<=FARSp_facFullLdSpGas){ze1a98f750561fc24a084f1529fd886dc=1;}else{
ze1a98f750561fc24a084f1529fd886dc=0;}z1594682a4c22b679f6631676c2b46982=(SInt16)(
((SInt32)(((UInt32)zd126a7e0255faf5db64b555a83edad68)-((UInt32)
FARSp_rMixtOfsAcvFilPos_C)))>>2);if(((SInt32)z1594682a4c22b679f6631676c2b46982)
<=((SInt32)(z8a3810b5efddc9355a3eac94fa1abb46>>14))){
z3149f4817a5b02b43919d0076fbdcf8d=1;}else{z3149f4817a5b02b43919d0076fbdcf8d=0;}
if(z3149f4817a5b02b43919d0076fbdcf8d&&FARSp_bAcvRichFullLdDly){
z141221ca42d49e2674f3d2254f2968bc=1;}else{z141221ca42d49e2674f3d2254f2968bc=0;}
if(!(FARSp_bAcvRichFullLdDly)){z1e25dacbc3b80981fe8e815f92572a87=1;}else{
z1e25dacbc3b80981fe8e815f92572a87=0;}if(((UInt32)(((UInt32)FARSp_rMixtAfsTran_C)
<<12))>=z8a3810b5efddc9355a3eac94fa1abb46){z634d1c74fd24af5debae1068b50a4445=1;}
else{z634d1c74fd24af5debae1068b50a4445=0;}if(z1e25dacbc3b80981fe8e815f92572a87&&
z634d1c74fd24af5debae1068b50a4445){z66191cbda9c676252a42064a521cde8b=1;}else{
z66191cbda9c676252a42064a521cde8b=0;}if(z141221ca42d49e2674f3d2254f2968bc||
z66191cbda9c676252a42064a521cde8b){FARSp_bInhFilTranFullLd_MP=1;}else{
FARSp_bInhFilTranFullLd_MP=0;}if(!(FARSp_bInhFilTranFullLd_MP)){
z481165ac78aa60f4f892730d3d872d2b=1;}else{z481165ac78aa60f4f892730d3d872d2b=0;}
if(z481165ac78aa60f4f892730d3d872d2b||FARSp_bAcvRichFullLdDly){
FARSp_bAcvRichFullLd=1;}else{FARSp_bAcvRichFullLd=0;}FARSp_bAcvRichFullLd_out=
FARSp_bAcvRichFullLd;FARSp_rMixtFullLdSpRaw_out=(UInt16)(
zacf62dfc43833890072cea8fb8fe0978>>12);if(z4cdb7721aacde5e82c640d1b519f9789>0){
z1cab202f24fd2fbc79d355b9748f6cc4=z4cdb7721aacde5e82c640d1b519f9789;}else{
z1cab202f24fd2fbc79d355b9748f6cc4=0;}if(16384<z1cab202f24fd2fbc79d355b9748f6cc4)
{zce7dd997d4b2885a6124c54c902c9af8=16384;}else{zce7dd997d4b2885a6124c54c902c9af8
=z1cab202f24fd2fbc79d355b9748f6cc4;}z2598987833881371c51dc4aac9af212d=(UInt32)((
((UInt32)zd126a7e0255faf5db64b555a83edad68)*((UInt32)
zce7dd997d4b2885a6124c54c902c9af8))>>2);z4e10aea4d19121794e1e1d1945abf345=(
UInt16)(((UInt16)(-zce7dd997d4b2885a6124c54c902c9af8))+16384);if(
z61a23c7a7bc417b5f1583bf5cd01ff2f!=0){z29fb240070f90dd109ed762f6058159c=
zffb5762868cb4dd832b48274acca5c00;}else{z29fb240070f90dd109ed762f6058159c=(
UInt32)(((UInt32)zd126a7e0255faf5db64b555a83edad68)<<12);}F__U64MULU32U32((
UInt32)z4e10aea4d19121794e1e1d1945abf345,z29fb240070f90dd109ed762f6058159c,&(
z5b5dda10a4deac02a9d1952cc6909f26),&(z1b6c2592abf49f3d6e5a2cd4e158bc59));
zcd29f873a768661ee3957831dc5dfe11=C__U32SHRU64C6_LT32(
z5b5dda10a4deac02a9d1952cc6909f26,z1b6c2592abf49f3d6e5a2cd4e158bc59,14,18);
ze743d4f6268d679a3a4234e02e41bd85=z2598987833881371c51dc4aac9af212d+
zcd29f873a768661ee3957831dc5dfe11;if(FARSp_bInhFilTranFullLd_MP!=0){
z0486e74cd01ac463a4388c45f7ba4af5=(UInt32)(((UInt32)
zd126a7e0255faf5db64b555a83edad68)<<12);}else{z0486e74cd01ac463a4388c45f7ba4af5=
ze743d4f6268d679a3a4234e02e41bd85;}if(zd599232c540e89c7ac0045e7a53799a0!=0){
z81cd42ac2bc3c961d270df400edd9026=z0486e74cd01ac463a4388c45f7ba4af5;}else{
z81cd42ac2bc3c961d270df400edd9026=(UInt32)(((UInt32)
zd126a7e0255faf5db64b555a83edad68)<<12);}FARSp_rMixtFullLdSp_out=(UInt16)(
z81cd42ac2bc3c961d270df400edd9026>>12);z2582b2f9d6e66827b65657f4b935ca9a=
zbd4e01a09e98f3c4d167f84807bd0aa9;z7a15368fa6feedf9b1e3f7897898c9a9=
FARSp_RE008_TqSys_bAuthRich_in;z8a3810b5efddc9355a3eac94fa1abb46=
z81cd42ac2bc3c961d270df400edd9026;zffb5762868cb4dd832b48274acca5c00=
z0486e74cd01ac463a4388c45f7ba4af5;z61a23c7a7bc417b5f1583bf5cd01ff2f=1;
zd599232c540e89c7ac0045e7a53799a0=1;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_008_FctVarInit(Void){FARSp_tiFullLdDly=0;
ze52d3fa58e3351032d0638f2ebb55c8e=0;z1d396f7ce39a4e1259ff47a502ddb2b2=0;
z49c21d4b59ad58a9997969dc1c40a4a3=0;zb06a9d971a107da5ee73c5be9f35b181=0;
z2e49a776930bf6e13489439661ea7a5a=0;z42256e2cdaf28f80756b70b8b60cbcf7=0;
za88935f13349b9fb0cdc4b845651cd0c=0;z31aed7b8b9165773fc2e69ed8930338b=0;
z8a3810b5efddc9355a3eac94fa1abb46=0;z2582b2f9d6e66827b65657f4b935ca9a=0;
zd599232c540e89c7ac0045e7a53799a0=0;zffb5762868cb4dd832b48274acca5c00=0;
z61a23c7a7bc417b5f1583bf5cd01ff2f=0;z7a15368fa6feedf9b1e3f7897898c9a9=1;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

