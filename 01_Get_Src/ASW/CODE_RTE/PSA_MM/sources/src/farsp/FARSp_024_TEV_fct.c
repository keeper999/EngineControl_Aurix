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
* %name: FARSp_024_TEV_fct.c %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:55:03 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_024_TEV_fct.c-4.0.build1:csrc:5 %
*
*******************************************************************************/


#ifndef _FARSP_024_TEV_FCT_C_
#define _FARSP_024_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_024_TEV_fct.h"
#include "FARSp_024_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT SInt16 FARSp_RE024_Ext_tCoMes_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtSpAntiStall_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE024_CoPt_noEgdGearCord_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE024_IdlSys_bAcvAntiStall_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE024_IdlSys_bEnaAntiStall_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bDeacAntiStall_out;AR_IF_GLOBAL_BOOLEAN 
Boolean FARSp_bEnaAntiStall_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z11c53e6d6666c600b304def100a81a1c;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z95c853edf8ce65d68f350d127ed1f130;static UInt16 
z7c6b5ee63b716dad2b6afe8d07a0d634;static UInt16 
z04e23977ed6b2938c68c799f510a4b9e;static UInt16 
z4253c5089853223b739bebf184bfe4b1;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
static SInt32 zb8f0d8f5ec631489ed21d14925c61159;static UInt32 
z42ada44d4808e503d6b8f9e2a52fe450;static UInt32 
z31b0fd721d47b9cf5be57d96e06d9faa;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
static Boolean z7049a3643ee3c0078a0d614f197ccf5a;static Boolean 
z09b5d045aa5b6c23f16dc9dfe06bc473;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 zbb1952b9fc613d596f3ffa05132fd735;static UInt8 
z3bcf98ecd02c463e615446ef5cbb87c8;static UInt8 za74e74ccb1da36fb614afd4f2f5d264a
;static UInt8 ze5c221ed9352b5260c915a688fe41f0a;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_023_MSE_ini(Void){FARSp_024_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_024_TEV_fct(Void){Boolean ze441d2d1cf9a79dade0f07c16fb9ac63;
FARSp_rMixtSpAntiStallPrev=z31b0fd721d47b9cf5be57d96e06d9faa;
ze441d2d1cf9a79dade0f07c16fb9ac63=z31b0fd721d47b9cf5be57d96e06d9faa!=16777216;
FARSp_bEnaAntiStall_out=FARSp_RE024_IdlSys_bAcvAntiStall_in||
ze441d2d1cf9a79dade0f07c16fb9ac63;FARSp_bDeacAntiStall_out=(!(
ze441d2d1cf9a79dade0f07c16fb9ac63))&&FARSp_RE024_IdlSys_bAcvAntiStall_in&&
z09b5d045aa5b6c23f16dc9dfe06bc473;FARSp_bEnaClcAntiStall=
FARSp_RE024_IdlSys_bEnaAntiStall_in||ze441d2d1cf9a79dade0f07c16fb9ac63;if(
FARSp_bEnaClcAntiStall){UInt32 z833cd066384e70b482fd1bd40e44b951;SInt32 
z61bfda0d229b21c3e8a20362b2732bd3;SInt32 zd468cba3d2668f5e045e88b404101f85;
SInt32 z835f57c4927bae6283fb5405d5d9e5de;SInt32 
zbc2df093db52b55d471687c1ff7aeca7;UInt32 zac5286688f3794ee799746832a0e4b9b;
UInt16 z6f9fb637120bbfd84b9581cfed003e9d;UInt16 
z76d9f495fdb145f5f4d92f5be533eb03;SInt32 zd468f45f7296e73fe1291d4b933ffed7;
SInt32 z06f32ff761b03af45c9f63ba6e33e8d9;UInt32 
z21fed86397a19bfad54bda2cfdaa9d19;UInt32 z598fc83d17c7afbb99b61c2115312c40;if(
FARSp_RE024_IdlSys_bAcvAntiStall_in){z6f9fb637120bbfd84b9581cfed003e9d=(UInt16)(
z11c53e6d6666c600b304def100a81a1c+1);}else{z6f9fb637120bbfd84b9581cfed003e9d=0;}
TabIdxS50T516((const SInt16*)FARSp_tCoMes_tiAntiStallX_A,8,
FARSp_RE024_Ext_tCoMes_in,&(zbb1952b9fc613d596f3ffa05132fd735),&(
z95c853edf8ce65d68f350d127ed1f130));FARSp_tiAntiStall_MP=Tab1DIntp2I1T65((const 
UInt16*)FARSp_tiAntiStall_T,zbb1952b9fc613d596f3ffa05132fd735,
z95c853edf8ce65d68f350d127ed1f130);z76d9f495fdb145f5f4d92f5be533eb03=(UInt16)(
FARSp_tiAntiStall_MP/FARSp_tiSdlFARSp_C);FARSp_bToutAntiStall_MP=
FARSp_RE024_IdlSys_bAcvAntiStall_in&&(z6f9fb637120bbfd84b9581cfed003e9d>
z76d9f495fdb145f5f4d92f5be533eb03);FARSp_bAcvrMixtSpAntiStall=
FARSp_RE024_IdlSys_bAcvAntiStall_in&&(!(FARSp_bToutAntiStall_MP));if(
FARSp_bAcvrMixtSpAntiStall){TabIdxS50T512((const UInt8*)IdlSys_noGearX_A,8,
FARSp_RE024_CoPt_noEgdGearCord_in,&(za74e74ccb1da36fb614afd4f2f5d264a),&(
z04e23977ed6b2938c68c799f510a4b9e));TabIdxS50T516((const SInt16*)
FARSp_tCoMes_rMixtSpASY_A,8,FARSp_RE024_Ext_tCoMes_in,&(
z3bcf98ecd02c463e615446ef5cbb87c8),&(z7c6b5ee63b716dad2b6afe8d07a0d634));
FARSp_rMixtSpAcvAntiStall_MP=Tab2DIntp2I1T33281((const UInt16*)&(
FARSp_rMixtSpAntiStall_M[0][0]),8,za74e74ccb1da36fb614afd4f2f5d264a,
z04e23977ed6b2938c68c799f510a4b9e,z3bcf98ecd02c463e615446ef5cbb87c8,
z7c6b5ee63b716dad2b6afe8d07a0d634);FARSp_rMixtSpRawAntiStall=
FARSp_rMixtSpAcvAntiStall_MP;}else{FARSp_rMixtSpRawAntiStall=4096;}if(
z6f9fb637120bbfd84b9581cfed003e9d<z76d9f495fdb145f5f4d92f5be533eb03){
z11c53e6d6666c600b304def100a81a1c=z6f9fb637120bbfd84b9581cfed003e9d;}else{
z11c53e6d6666c600b304def100a81a1c=z76d9f495fdb145f5f4d92f5be533eb03;}if(
z7049a3643ee3c0078a0d614f197ccf5a){zac5286688f3794ee799746832a0e4b9b=
z42ada44d4808e503d6b8f9e2a52fe450;}else{zac5286688f3794ee799746832a0e4b9b=(
UInt32)(((UInt32)FARSp_rMixtSpRawAntiStall)<<15);}
zd468cba3d2668f5e045e88b404101f85=(SInt32)(((UInt32)(SInt32)(((UInt32)
FARSp_rMixtSpRawAntiStall)<<15))-zac5286688f3794ee799746832a0e4b9b);
TabIdxS50T516((const SInt16*)FARSp_tCoMesFARSpGrdNegX_A,8,
FARSp_RE024_Ext_tCoMes_in,&(ze5c221ed9352b5260c915a688fe41f0a),&(
z4253c5089853223b739bebf184bfe4b1));FARSp_rMixtSpGrdNeg_MP=Tab1DIntp2I1T68((
const SInt16*)FARSp_rMixtSpGrdNeg_T,ze5c221ed9352b5260c915a688fe41f0a,
z4253c5089853223b739bebf184bfe4b1);z61bfda0d229b21c3e8a20362b2732bd3=((SInt32)((
(SInt32)FARSp_tiSdlFARSp_C)*((SInt32)FARSp_rMixtSpGrdNeg_MP)))*83886;
z833cd066384e70b482fd1bd40e44b951=((UInt32)(((UInt16)FARSp_tiSdlFARSp_C)*
FARSp_rMixtSpGrdPos_C))*83886;C__I64COPYU32(z833cd066384e70b482fd1bd40e44b951,
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19);
C__I64COPYI32(zd468cba3d2668f5e045e88b404101f85,
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19);if(
zd468cba3d2668f5e045e88b404101f85>z61bfda0d229b21c3e8a20362b2732bd3){
z835f57c4927bae6283fb5405d5d9e5de=zd468cba3d2668f5e045e88b404101f85;}else{
z835f57c4927bae6283fb5405d5d9e5de=z61bfda0d229b21c3e8a20362b2732bd3;}
C__I64COPYU32(z833cd066384e70b482fd1bd40e44b951,
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19);
C__I64COPYI32(z835f57c4927bae6283fb5405d5d9e5de,
z06f32ff761b03af45c9f63ba6e33e8d9,z598fc83d17c7afbb99b61c2115312c40);if(C__LT64(
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19,
z06f32ff761b03af45c9f63ba6e33e8d9,z598fc83d17c7afbb99b61c2115312c40)){
zbc2df093db52b55d471687c1ff7aeca7=(SInt32)z21fed86397a19bfad54bda2cfdaa9d19;}
else{zbc2df093db52b55d471687c1ff7aeca7=z835f57c4927bae6283fb5405d5d9e5de;}
zb8f0d8f5ec631489ed21d14925c61159=(SInt32)(((UInt32)
zbc2df093db52b55d471687c1ff7aeca7)+zac5286688f3794ee799746832a0e4b9b);
z7049a3643ee3c0078a0d614f197ccf5a=1;z42ada44d4808e503d6b8f9e2a52fe450=(UInt32)
zb8f0d8f5ec631489ed21d14925c61159;}z09b5d045aa5b6c23f16dc9dfe06bc473=
FARSp_RE024_IdlSys_bAcvAntiStall_in;FARSp_rMixtSpAntiStall_out=(UInt16)(SInt16)(
zb8f0d8f5ec631489ed21d14925c61159>>15);z31b0fd721d47b9cf5be57d96e06d9faa=(UInt32
)(SInt32)(zb8f0d8f5ec631489ed21d14925c61159>>3);}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_024_FctVarInit(Void){FARSp_RE024_IdlSys_bEnaAntiStall_in=0;
FARSp_rMixtSpAntiStall_out=4096;zb8f0d8f5ec631489ed21d14925c61159=0;
z95c853edf8ce65d68f350d127ed1f130=0;zbb1952b9fc613d596f3ffa05132fd735=0;
z7c6b5ee63b716dad2b6afe8d07a0d634=0;z3bcf98ecd02c463e615446ef5cbb87c8=0;
z04e23977ed6b2938c68c799f510a4b9e=0;za74e74ccb1da36fb614afd4f2f5d264a=0;
z4253c5089853223b739bebf184bfe4b1=0;ze5c221ed9352b5260c915a688fe41f0a=0;
z42ada44d4808e503d6b8f9e2a52fe450=0;z7049a3643ee3c0078a0d614f197ccf5a=0;
z31b0fd721d47b9cf5be57d96e06d9faa=0;z09b5d045aa5b6c23f16dc9dfe06bc473=0;
z11c53e6d6666c600b304def100a81a1c=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

