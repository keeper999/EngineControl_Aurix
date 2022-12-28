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
* %name: MPM_Aftrs.c %
*
* %version: 2.4_OBS %
*
* %date_modified: Wed Jul 31 09:11:08 2013 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC4.3 %
* %full_filespec: MPM_Aftrs.c-2.4_OBS:csrc:3 %
*
*******************************************************************************/


#include "MPM_Aftrs.h"
#define MPM_START_SEC_VAR_16BIT
#include "MPM_MemMap.h"
MPM_SNV_Z1_CST_16BIT zbd700454f9510756b9657ed9ce99b9f1;
#define MPM_STOP_SEC_VAR_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_32BIT
#include "MPM_MemMap.h"
MPM_SNV_Z1_CST_32BIT MPM_sNV_Z1_CST_32BIT_cpy;MPM_SNV_Z1_CST_32BIT_1 
z612f8a939491133236935bc23e3ca174;MPM_SNV_Z1_CST_32BIT_2 
zd9cca22017535a95a4e31a3c1137c702;
#define MPM_STOP_SEC_VAR_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_8BIT
#include "MPM_MemMap.h"
AR_INTERNAL_VAR_DISP_8BIT UInt8 MPM_ctLockRqAftsNvm;AR_INTERNAL_VAR_DISP_8BIT 
UInt8 MPM_stAftsNvm;AR_INTERNAL_VAR_DISP_8BIT UInt8 MPM_IDAftsNvm;
AR_INTERNAL_VAR_DISP_8BIT UInt8 MPM_stRstNvmRtn[MPM_NVMID_END];
#define MPM_STOP_SEC_INTERNAL_VAR_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_BOOLEAN
#include "MPM_MemMap.h"
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MPM_LockedAftsNvm;
#define MPM_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "MPM_MemMap.h"
#define MPM_START_SEC_CONST_UNSPECIFIED
#include "MPM_MemMap.h"
static const Boolean zde0c608c8fc85d92f6f9d51a544176c5[MPM_NVMID_END]={0x06,0x06
,0x01,0x01,0x06,0x06,0x01,0x01,};
#define MPM_STOP_SEC_CONST_UNSPECIFIED
#include "MPM_MemMap.h"
#define MPM_START_SEC_CODE
#include "MPM_MemMap.h"
FUNC(void,AUTOMATIC)MPM_Nvm_To_Cpy(void){zbd700454f9510756b9657ed9ce99b9f1=
MPM_sNV_Z1_CST_16BIT;MPM_sNV_Z1_CST_32BIT_cpy=MPM_sNV_Z1_CST_32BIT;
z612f8a939491133236935bc23e3ca174=MPM_sNV_Z1_CST_32BIT_1;
zd9cca22017535a95a4e31a3c1137c702=MPM_sNV_Z1_CST_32BIT_2;}FUNC(void,AUTOMATIC)
MPM_Cpy_To_Nvm_And_Reinit(UInt8 MPM_Nvmid){
switch(MPM_Nvmid){case MPM_NVMID01:MPM_sNV_Z1_CST_16BIT=
zbd700454f9510756b9657ed9ce99b9f1;
break;case MPM_NVMID02:MPM_sNV_Z1_CST_32BIT=MPM_sNV_Z1_CST_32BIT_cpy;


break;case MPM_NVMID05:MPM_sNV_Z1_CST_32BIT_1=z612f8a939491133236935bc23e3ca174;
break;case MPM_NVMID06:MPM_sNV_Z1_CST_32BIT_2=zd9cca22017535a95a4e31a3c1137c702;
break;case MPM_NVMID_RESERVED:MPM_sNV_Z1_CST_16BIT=
zbd700454f9510756b9657ed9ce99b9f1;
MPM_sNV_Z1_CST_32BIT=MPM_sNV_Z1_CST_32BIT_cpy;


MPM_sNV_Z1_CST_32BIT_1=z612f8a939491133236935bc23e3ca174;
MPM_sNV_Z1_CST_32BIT_2=zd9cca22017535a95a4e31a3c1137c702;
break;default:break;}}FUNC(void,AUTOMATIC)MPM_Recovery_To_Nvm_And_Reinit(UInt8 
MPM_Nvmid){
switch(MPM_Nvmid){case MPM_NVMID03:MPM_sNV_Z1_CST_16BIT=MPM_sNV_Z1_CST_16BIT_r;
break;case MPM_NVMID04:MPM_sNV_Z1_CST_32BIT=MPM_sNV_Z1_CST_32BIT_r;


break;case MPM_NVMID07:MPM_sNV_Z1_CST_32BIT_1=MPM_sNV_Z1_CST_32BIT_1_r;
break;case MPM_NVMID08:MPM_sNV_Z1_CST_32BIT_2=MPM_sNV_Z1_CST_32BIT_2_r;
break;case MPM_NVMID_RESERVED:MPM_sNV_Z1_CST_16BIT=MPM_sNV_Z1_CST_16BIT_r;
MPM_sNV_Z1_CST_32BIT=MPM_sNV_Z1_CST_32BIT_r;


MPM_sNV_Z1_CST_32BIT_1=MPM_sNV_Z1_CST_32BIT_1_r;
MPM_sNV_Z1_CST_32BIT_2=MPM_sNV_Z1_CST_32BIT_2_r;
break;default:break;}}FUNC(Std_ReturnType,RTE_APPL_CODE)RE_MPM_AftsSesChgInd(
Dcm_SesCtrlType SesCtrlTypeOld,Dcm_SesCtrlType SesCtrlTypeNew){UInt32 
RtnId_index;P2VAR(UInt8,AUTOMATIC,AUTOMATIC)MPM_stRstNvmRtn_ptr;
MPM_stRstNvmRtn_ptr=(P2VAR(UInt8,AUTOMATIC,AUTOMATIC))
Rte_IrvRead_RE_MPM_AftsSesChgInd_MPM_stRstNvmRtn();SesCtrlTypeNew=SesCtrlTypeOld
;for(RtnId_index=0;RtnId_index<MPM_NVMID_END;RtnId_index++){MPM_stRstNvmRtn_ptr[
RtnId_index]=RTN_ST_NOT_STARTED;}Rte_IrvWrite_RE_MPM_AftsSesChgInd_MPM_IDAftsNvm
(MPM_NVMID_RESERVED);return E_OK;}FUNC(Std_ReturnType,RTE_APPL_CODE)
RE_MPM_AftsGetSesChgPerm(Dcm_SesCtrlType SesCtrlTypeActive,Dcm_SesCtrlType 
SesCtrlTypeNew){SesCtrlTypeNew=SesCtrlTypeActive;return E_OK;}FUNC(Void,
RTE_APPL_CODE)RE_MPM_AftrsInit(void){UInt32 z7d5c281effb8fcbf9f4be00720fe0671;
MPM_Nvm_To_Cpy();for(z7d5c281effb8fcbf9f4be00720fe0671=0;
z7d5c281effb8fcbf9f4be00720fe0671<MPM_NVMID_END;
z7d5c281effb8fcbf9f4be00720fe0671++){MPM_stRstNvmRtn[
z7d5c281effb8fcbf9f4be00720fe0671]=RTN_ST_NOT_STARTED;}MPM_LockedAftsNvm=0;
MPM_stAftsNvm=CST_NOAFTERSALEREQUEST;MPM_IDAftsNvm=MPM_NVMID_RESERVED;
MPM_ctLockRqAftsNvm=0;Rte_IrvWrite_RE_MPM_AftrsInit_MPM_IDAftsNvm(MPM_IDAftsNvm)
;Rte_IrvWrite_RE_MPM_AftrsInit_MPM_LockedAftsNvm(MPM_LockedAftsNvm);
Rte_IrvWrite_RE_MPM_AftrsInit_MPM_ctLockRqAftsNvm(MPM_ctLockRqAftsNvm);
Rte_IrvWrite_RE_MPM_AftrsInit_MPM_stAftsNvm(MPM_stAftsNvm);
Rte_IrvWrite_RE_MPM_AftrsInit_MPM_stRstNvmRtn((UInt32)&MPM_stRstNvmRtn[0]);}FUNC
(void,RTE_APPL_CODE)RE_MPM_AftsNvm(void){UInt8 z22bdb733a9b83aa8dcbdd46bf3a5ea9e
;UInt8 zf1fc67c1cea2085338919c8e9ff3086e;UInt8 z3581687dc9332484bddb18eddd42d10d
;UInt8 zcfc786aeb7bb5bd53e83bd9933de9907;UInt16 
z63fdd992f9de36de5dd31f80cd382314;z22bdb733a9b83aa8dcbdd46bf3a5ea9e=
Rte_IrvRead_RE_MPM_AftsNvm_MPM_LockedAftsNvm();zf1fc67c1cea2085338919c8e9ff3086e
=Rte_IrvRead_RE_MPM_AftsNvm_MPM_ctLockRqAftsNvm();
z3581687dc9332484bddb18eddd42d10d=Rte_IrvRead_RE_MPM_AftsNvm_MPM_stAftsNvm();
zcfc786aeb7bb5bd53e83bd9933de9907=Rte_IrvRead_RE_MPM_AftsNvm_MPM_IDAftsNvm();
Rte_Read_R_Ext_nEng_Ext_nEng(&z63fdd992f9de36de5dd31f80cd382314);if(
z3581687dc9332484bddb18eddd42d10d==CST_WRITE_OK||
z3581687dc9332484bddb18eddd42d10d==CST_READWRITE_NOK){if((((MPM_NVMID_START<=
zcfc786aeb7bb5bd53e83bd9933de9907)&&(zcfc786aeb7bb5bd53e83bd9933de9907<=
MPM_NVMID_END))||(zcfc786aeb7bb5bd53e83bd9933de9907==MPM_NVMID_RESERVED))&&(
z3581687dc9332484bddb18eddd42d10d==CST_WRITE_OK)){MPM_Cpy_To_Nvm_And_Reinit(
zcfc786aeb7bb5bd53e83bd9933de9907);}else{}z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;
zf1fc67c1cea2085338919c8e9ff3086e=0;z3581687dc9332484bddb18eddd42d10d=
CST_NOAFTERSALEREQUEST;}else{if(zf1fc67c1cea2085338919c8e9ff3086e>0){if(
z22bdb733a9b83aa8dcbdd46bf3a5ea9e==0){z22bdb733a9b83aa8dcbdd46bf3a5ea9e=1;
MPM_Nvm_To_Cpy();}else{}}else{z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;}
if(z3581687dc9332484bddb18eddd42d10d==CST_RESET){

if((MPM_NVMID_START<=zcfc786aeb7bb5bd53e83bd9933de9907)&&(
zcfc786aeb7bb5bd53e83bd9933de9907<=MPM_NVMID_END)){
if((UInt32)z63fdd992f9de36de5dd31f80cd382314!=0){
zf1fc67c1cea2085338919c8e9ff3086e=0;z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;
z3581687dc9332484bddb18eddd42d10d=CST_RESET_NOK;}else{
if(z22bdb733a9b83aa8dcbdd46bf3a5ea9e==1){MPM_Recovery_To_Nvm_And_Reinit(
zcfc786aeb7bb5bd53e83bd9933de9907);z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;
zf1fc67c1cea2085338919c8e9ff3086e=0;z3581687dc9332484bddb18eddd42d10d=
CST_RESET_OK;}else{z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;
zf1fc67c1cea2085338919c8e9ff3086e=0;z3581687dc9332484bddb18eddd42d10d=
CST_NOAFTERSALEREQUEST;}}}else{z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;
zf1fc67c1cea2085338919c8e9ff3086e=0;z3581687dc9332484bddb18eddd42d10d=
CST_NOAFTERSALEREQUEST;}}}Rte_IrvWrite_RE_MPM_AftsNvm_MPM_LockedAftsNvm(
z22bdb733a9b83aa8dcbdd46bf3a5ea9e);
Rte_IrvWrite_RE_MPM_AftsNvm_MPM_ctLockRqAftsNvm(
zf1fc67c1cea2085338919c8e9ff3086e);Rte_IrvWrite_RE_MPM_AftsNvm_MPM_stAftsNvm(
z3581687dc9332484bddb18eddd42d10d);MPM_LockedAftsNvm=
z22bdb733a9b83aa8dcbdd46bf3a5ea9e;MPM_ctLockRqAftsNvm=
zf1fc67c1cea2085338919c8e9ff3086e;MPM_stAftsNvm=
z3581687dc9332484bddb18eddd42d10d;}FUNC(Std_ReturnType,RTE_APPL_CODE)
RE_MPM_AftsNvmRead(UInt8 zdc4f55dd9a6f46852fab1dd516106ce9,P2VAR(UInt8,AUTOMATIC
,RTE_APPL_DATA)data){UInt8 z3581687dc9332484bddb18eddd42d10d;UInt8 
z22bdb733a9b83aa8dcbdd46bf3a5ea9e;UInt8 zf1fc67c1cea2085338919c8e9ff3086e;
Std_ReturnType ze1abbb6890c010b125e234acd20cd772;UInt32 
z3d89a979ab995b024968c2b2f941051d;UInt32 z8651fc10c8bef3640dc1bce2a2e7d81f;
UInt32*z4c8b1d9f36706f2654358ce7e9e545ab;UInt16*
z9dacea0ec239176123612b011f2dce26;UInt8*z0ead1a766840d642a141585436903b37;
z3581687dc9332484bddb18eddd42d10d=Rte_IrvRead_RE_MPM_AftsNvmRead_MPM_stAftsNvm()
;z22bdb733a9b83aa8dcbdd46bf3a5ea9e=
Rte_IrvRead_RE_MPM_AftsNvmRead_MPM_LockedAftsNvm();
zf1fc67c1cea2085338919c8e9ff3086e=
Rte_IrvRead_RE_MPM_AftsNvmRead_MPM_ctLockRqAftsNvm();if(MPM_NVMID_START>
zdc4f55dd9a6f46852fab1dd516106ce9||zdc4f55dd9a6f46852fab1dd516106ce9>
MPM_NVMID_END||(0x04&(zde0c608c8fc85d92f6f9d51a544176c5[
zdc4f55dd9a6f46852fab1dd516106ce9-1])!=0)){ze1abbb6890c010b125e234acd20cd772=
E_NOT_OK;}else{if(z3581687dc9332484bddb18eddd42d10d==CST_READ){
z3d89a979ab995b024968c2b2f941051d=0;switch(zdc4f55dd9a6f46852fab1dd516106ce9){
case MPM_NVMID01:z9dacea0ec239176123612b011f2dce26=(UInt16*)&(
zbd700454f9510756b9657ed9ce99b9f1.DmgMSI_rCylHdInjDmgCnt_NV);
PSA_UInt16ToTabUInt8(*z9dacea0ec239176123612b011f2dce26,&data[
z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=2;break;
case MPM_NVMID02:z4c8b1d9f36706f2654358ce7e9e545ab=(UInt32*)&(
MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylBlockDmg_NV);PSA_UInt32ToTabUInt8(*
z4c8b1d9f36706f2654358ce7e9e545ab,&data[z3d89a979ab995b024968c2b2f941051d]);
z3d89a979ab995b024968c2b2f941051d+=4;z4c8b1d9f36706f2654358ce7e9e545ab=(UInt32*)
&(MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylHdInjDmgInter_NV);PSA_UInt32ToTabUInt8(*
z4c8b1d9f36706f2654358ce7e9e545ab,&data[z3d89a979ab995b024968c2b2f941051d]);
z3d89a979ab995b024968c2b2f941051d+=4;z4c8b1d9f36706f2654358ce7e9e545ab=(UInt32*)
&(MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylHdDmg_NV);PSA_UInt32ToTabUInt8(*
z4c8b1d9f36706f2654358ce7e9e545ab,&data[z3d89a979ab995b024968c2b2f941051d]);
z3d89a979ab995b024968c2b2f941051d+=4;break;case MPM_NVMID05:
z4c8b1d9f36706f2654358ce7e9e545ab=(UInt32*)&(z612f8a939491133236935bc23e3ca174.
DmgMSI_rTrbCaseDmg_NV);PSA_UInt32ToTabUInt8(*z4c8b1d9f36706f2654358ce7e9e545ab,&
data[z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
break;case MPM_NVMID06:z4c8b1d9f36706f2654358ce7e9e545ab=(UInt32*)&(
zd9cca22017535a95a4e31a3c1137c702.DmgMSI_rExMnfDmg_NV);PSA_UInt32ToTabUInt8(*
z4c8b1d9f36706f2654358ce7e9e545ab,&data[z3d89a979ab995b024968c2b2f941051d]);
z3d89a979ab995b024968c2b2f941051d+=4;break;}if(zf1fc67c1cea2085338919c8e9ff3086e
){zf1fc67c1cea2085338919c8e9ff3086e=zf1fc67c1cea2085338919c8e9ff3086e-1;}else{
return E_NOT_OK;}if(zf1fc67c1cea2085338919c8e9ff3086e==0){
z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;
z22bdb733a9b83aa8dcbdd46bf3a5ea9e=0;}else{}ze1abbb6890c010b125e234acd20cd772=
E_OK;}else{ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}
Rte_IrvWrite_RE_MPM_AftsNvmRead_MPM_ctLockRqAftsNvm(
zf1fc67c1cea2085338919c8e9ff3086e);Rte_IrvWrite_RE_MPM_AftsNvmRead_MPM_stAftsNvm
(z3581687dc9332484bddb18eddd42d10d);
Rte_IrvWrite_RE_MPM_AftsNvmRead_MPM_LockedAftsNvm(
z22bdb733a9b83aa8dcbdd46bf3a5ea9e);MPM_ctLockRqAftsNvm=
zf1fc67c1cea2085338919c8e9ff3086e;MPM_stAftsNvm=
z3581687dc9332484bddb18eddd42d10d;MPM_LockedAftsNvm=
z22bdb733a9b83aa8dcbdd46bf3a5ea9e;return ze1abbb6890c010b125e234acd20cd772;}FUNC
(Std_ReturnType,RTE_APPL_CODE)RE_MPM_AftsNvmChkRead(UInt8 
zdc4f55dd9a6f46852fab1dd516106ce9,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,
RTE_APPL_DATA)ErrorCode){Std_ReturnType ze1abbb6890c010b125e234acd20cd772;UInt8 
z3581687dc9332484bddb18eddd42d10d;UInt8 zcfc786aeb7bb5bd53e83bd9933de9907;P2VAR(
UInt8,AUTOMATIC,AUTOMATIC)MPM_stRstNvmRtn_ptr;UInt16 
z63fdd992f9de36de5dd31f80cd382314;UInt8 zf1fc67c1cea2085338919c8e9ff3086e;UInt8 
z22bdb733a9b83aa8dcbdd46bf3a5ea9e;z3581687dc9332484bddb18eddd42d10d=
Rte_IrvRead_RE_MPM_AftsNvmChkRead_MPM_stAftsNvm();
zcfc786aeb7bb5bd53e83bd9933de9907=
Rte_IrvRead_RE_MPM_AftsNvmChkRead_MPM_IDAftsNvm();MPM_stRstNvmRtn_ptr=(P2VAR(
UInt8,AUTOMATIC,AUTOMATIC))Rte_IrvRead_RE_MPM_AftsNvmChkRead_MPM_stRstNvmRtn();
Rte_Read_R_Ext_nEng_Ext_nEng(&z63fdd992f9de36de5dd31f80cd382314);
zf1fc67c1cea2085338919c8e9ff3086e=
Rte_IrvRead_RE_MPM_AftsNvmChkRead_MPM_ctLockRqAftsNvm();
z22bdb733a9b83aa8dcbdd46bf3a5ea9e=
Rte_IrvRead_RE_MPM_AftsNvmChkRead_MPM_LockedAftsNvm();if(MPM_NVMID_START>
zdc4f55dd9a6f46852fab1dd516106ce9||zdc4f55dd9a6f46852fab1dd516106ce9>
MPM_NVMID_END||ErrorCode==NULL||(0x04&(zde0c608c8fc85d92f6f9d51a544176c5[
zdc4f55dd9a6f46852fab1dd516106ce9-1])!=0)){ze1abbb6890c010b125e234acd20cd772=
E_NOT_OK;}else{if(z3581687dc9332484bddb18eddd42d10d==CST_WRITE){
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{if(
z3581687dc9332484bddb18eddd42d10d==CST_RESET||z3581687dc9332484bddb18eddd42d10d
==CST_WRITE_OK){*ErrorCode=DCM_E_CONDITIONSNOTCORRECT;
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{if(
z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK||
z3581687dc9332484bddb18eddd42d10d==CST_RESET_NOK){if(MPM_NVMID_START<=
zcfc786aeb7bb5bd53e83bd9933de9907&&zcfc786aeb7bb5bd53e83bd9933de9907<=
MPM_NVMID_END){if(z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK){
MPM_stRstNvmRtn_ptr[(UInt32)zcfc786aeb7bb5bd53e83bd9933de9907-1]=
RTN_ST_FINISHED_OK;}else{MPM_stRstNvmRtn_ptr[(UInt32)
zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_NOK;}
z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;}}if((UInt32)
z63fdd992f9de36de5dd31f80cd382314!=0){*ErrorCode=DCM_E_ENGINEISRUNNING;
z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;
zf1fc67c1cea2085338919c8e9ff3086e=0;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}
else{if(z3581687dc9332484bddb18eddd42d10d==CST_NOAFTERSALEREQUEST){if(
zf1fc67c1cea2085338919c8e9ff3086e==0){if(z22bdb733a9b83aa8dcbdd46bf3a5ea9e==1){
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{
zf1fc67c1cea2085338919c8e9ff3086e=1;ze1abbb6890c010b125e234acd20cd772=E_PENDING;
}}else{if(z22bdb733a9b83aa8dcbdd46bf3a5ea9e==1){
z3581687dc9332484bddb18eddd42d10d=CST_READ;ze1abbb6890c010b125e234acd20cd772=
E_OK;}else{ze1abbb6890c010b125e234acd20cd772=E_PENDING;}}}else{if(
z3581687dc9332484bddb18eddd42d10d==CST_READ){if(
zf1fc67c1cea2085338919c8e9ff3086e<255){zf1fc67c1cea2085338919c8e9ff3086e=
zf1fc67c1cea2085338919c8e9ff3086e+1;ze1abbb6890c010b125e234acd20cd772=E_OK;}else
{ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}else{
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}}}}}
Rte_IrvWrite_RE_MPM_AftsNvmChkRead_MPM_ctLockRqAftsNvm(
zf1fc67c1cea2085338919c8e9ff3086e);
Rte_IrvWrite_RE_MPM_AftsNvmChkRead_MPM_stAftsNvm(
z3581687dc9332484bddb18eddd42d10d);MPM_ctLockRqAftsNvm=
zf1fc67c1cea2085338919c8e9ff3086e;MPM_stAftsNvm=
z3581687dc9332484bddb18eddd42d10d;return ze1abbb6890c010b125e234acd20cd772;}FUNC
(Std_ReturnType,RTE_APPL_CODE)RE_MPM_AftsNvmRDL(UInt8 
zdc4f55dd9a6f46852fab1dd516106ce9,UInt16*DidLength){Std_ReturnType 
ze1abbb6890c010b125e234acd20cd772;if(((UInt32)zdc4f55dd9a6f46852fab1dd516106ce9<
MPM_NVMID_START)||(MPM_NVMID_END<(UInt32)zdc4f55dd9a6f46852fab1dd516106ce9)||(
DidLength==NULL)){ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{switch(
zdc4f55dd9a6f46852fab1dd516106ce9){case MPM_NVMID01:*DidLength=sizeof(
MPM_sNV_Z1_CST_16BIT);break;case MPM_NVMID02:*DidLength=sizeof(
MPM_sNV_Z1_CST_32BIT);break;case MPM_NVMID05:*DidLength=sizeof(
MPM_sNV_Z1_CST_32BIT_1);break;case MPM_NVMID06:*DidLength=sizeof(
MPM_sNV_Z1_CST_32BIT_2);break;}ze1abbb6890c010b125e234acd20cd772=E_OK;}return 
ze1abbb6890c010b125e234acd20cd772;}FUNC(Std_ReturnType,RTE_APPL_CODE)
RE_MPM_AftsNvmWrite(UInt8 zdc4f55dd9a6f46852fab1dd516106ce9,P2VAR(UInt8,
AUTOMATIC,RTE_APPL_DATA)data,UInt16 dataLength,P2VAR(
Dcm_NegativeResponseCodeType,AUTOMATIC,RTE_APPL_DATA)ErrorCode){UInt8 
z3581687dc9332484bddb18eddd42d10d;UInt32 z8651fc10c8bef3640dc1bce2a2e7d81f;
UInt32 z3d89a979ab995b024968c2b2f941051d;Std_ReturnType 
ze1abbb6890c010b125e234acd20cd772;z3581687dc9332484bddb18eddd42d10d=
Rte_IrvRead_RE_MPM_AftsNvmWrite_MPM_stAftsNvm();
z3d89a979ab995b024968c2b2f941051d=0;if(MPM_NVMID_START>
zdc4f55dd9a6f46852fab1dd516106ce9||zdc4f55dd9a6f46852fab1dd516106ce9>
MPM_NVMID_END||ErrorCode==NULL||(0x02&(zde0c608c8fc85d92f6f9d51a544176c5[
zdc4f55dd9a6f46852fab1dd516106ce9-1])!=0)){ze1abbb6890c010b125e234acd20cd772=
E_NOT_OK;}else{if(z3581687dc9332484bddb18eddd42d10d==CST_WRITE){switch(
zdc4f55dd9a6f46852fab1dd516106ce9){case MPM_NVMID01:if(dataLength==sizeof(
MPM_sNV_Z1_CST_16BIT)){zbd700454f9510756b9657ed9ce99b9f1.
DmgMSI_rCylHdInjDmgCnt_NV=PSA_TabUInt8ToUInt16(&data[
z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=2;
z3581687dc9332484bddb18eddd42d10d=CST_WRITE_OK;ze1abbb6890c010b125e234acd20cd772
=E_OK;}else{*ErrorCode=DCM_E_REQUESTOUTOFRANGE;z3581687dc9332484bddb18eddd42d10d
=CST_READWRITE_NOK;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}break;case 
MPM_NVMID02:if(dataLength==sizeof(MPM_sNV_Z1_CST_32BIT)){
MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylBlockDmg_NV=PSA_TabUInt8ToUInt32(&data[
z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylHdInjDmgInter_NV=PSA_TabUInt8ToUInt32(&data[
z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
MPM_sNV_Z1_CST_32BIT_cpy.DmgMSI_rCylHdDmg_NV=PSA_TabUInt8ToUInt32(&data[
z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
z3581687dc9332484bddb18eddd42d10d=CST_WRITE_OK;ze1abbb6890c010b125e234acd20cd772
=E_OK;}else{*ErrorCode=DCM_E_REQUESTOUTOFRANGE;z3581687dc9332484bddb18eddd42d10d
=CST_READWRITE_NOK;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}break;case 
MPM_NVMID05:if(dataLength==sizeof(MPM_sNV_Z1_CST_32BIT_1)){
z612f8a939491133236935bc23e3ca174.DmgMSI_rTrbCaseDmg_NV=PSA_TabUInt8ToUInt32(&
data[z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
z3581687dc9332484bddb18eddd42d10d=CST_WRITE_OK;ze1abbb6890c010b125e234acd20cd772
=E_OK;}else{*ErrorCode=DCM_E_REQUESTOUTOFRANGE;z3581687dc9332484bddb18eddd42d10d
=CST_READWRITE_NOK;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}break;case 
MPM_NVMID06:if(dataLength==sizeof(MPM_sNV_Z1_CST_32BIT_2)){
zd9cca22017535a95a4e31a3c1137c702.DmgMSI_rExMnfDmg_NV=PSA_TabUInt8ToUInt32(&data
[z3d89a979ab995b024968c2b2f941051d]);z3d89a979ab995b024968c2b2f941051d+=4;
z3581687dc9332484bddb18eddd42d10d=CST_WRITE_OK;ze1abbb6890c010b125e234acd20cd772
=E_OK;}else{*ErrorCode=DCM_E_REQUESTOUTOFRANGE;z3581687dc9332484bddb18eddd42d10d
=CST_READWRITE_NOK;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}break;}}else{
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}
Rte_IrvWrite_RE_MPM_AftsNvmWrite_MPM_stAftsNvm(z3581687dc9332484bddb18eddd42d10d
);MPM_stAftsNvm=z3581687dc9332484bddb18eddd42d10d;return 
ze1abbb6890c010b125e234acd20cd772;}FUNC(Std_ReturnType,RTE_APPL_CODE)
RE_MPM_AftsNvmChkWrite(UInt8 zdc4f55dd9a6f46852fab1dd516106ce9,
Dcm_NegativeResponseCodeType*ErrorCode){UInt16 z63fdd992f9de36de5dd31f80cd382314
;UInt8 z3581687dc9332484bddb18eddd42d10d;UInt8 zcfc786aeb7bb5bd53e83bd9933de9907
;UInt8 zf1fc67c1cea2085338919c8e9ff3086e;UInt8 z22bdb733a9b83aa8dcbdd46bf3a5ea9e
;P2VAR(UInt8,AUTOMATIC,AUTOMATIC)MPM_stRstNvmRtn_ptr;Std_ReturnType 
ze1abbb6890c010b125e234acd20cd772;Rte_Read_R_Ext_nEng_Ext_nEng(&
z63fdd992f9de36de5dd31f80cd382314);MPM_stRstNvmRtn_ptr=(P2VAR(UInt8,AUTOMATIC,
AUTOMATIC))Rte_IrvRead_RE_MPM_AftsNvmChkWrite_MPM_stRstNvmRtn();
z3581687dc9332484bddb18eddd42d10d=
Rte_IrvRead_RE_MPM_AftsNvmChkWrite_MPM_stAftsNvm();
zcfc786aeb7bb5bd53e83bd9933de9907=
Rte_IrvRead_RE_MPM_AftsNvmChkWrite_MPM_IDAftsNvm();
zf1fc67c1cea2085338919c8e9ff3086e=
Rte_IrvRead_RE_MPM_AftsNvmChkWrite_MPM_ctLockRqAftsNvm();
z22bdb733a9b83aa8dcbdd46bf3a5ea9e=
Rte_IrvRead_RE_MPM_AftsNvmChkWrite_MPM_LockedAftsNvm();if((MPM_NVMID_START>(
UInt32)zdc4f55dd9a6f46852fab1dd516106ce9)||((UInt32)
zdc4f55dd9a6f46852fab1dd516106ce9>MPM_NVMID_END)||ErrorCode==NULL||(0x02&(
zde0c608c8fc85d92f6f9d51a544176c5[zdc4f55dd9a6f46852fab1dd516106ce9-1])!=0)){
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else if((
z3581687dc9332484bddb18eddd42d10d==CST_READ)||(z3581687dc9332484bddb18eddd42d10d
==CST_WRITE)){

ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else if(
z3581687dc9332484bddb18eddd42d10d==CST_WRITE_OK){
ze1abbb6890c010b125e234acd20cd772=E_PENDING;}else if(
z3581687dc9332484bddb18eddd42d10d==CST_RESET){
*ErrorCode=DCM_E_CONDITIONSNOTCORRECT;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK
;}else{if((z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK)||(
z3581687dc9332484bddb18eddd42d10d==CST_RESET_NOK)){
if((MPM_NVMID_START<=zcfc786aeb7bb5bd53e83bd9933de9907)&&(
zcfc786aeb7bb5bd53e83bd9933de9907<=MPM_NVMID_END)){if(
z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK){MPM_stRstNvmRtn_ptr[(UInt32)
zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_OK;}else{
MPM_stRstNvmRtn_ptr[(UInt32)zcfc786aeb7bb5bd53e83bd9933de9907-1]=
RTN_ST_FINISHED_NOK;}z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;}}
if(z3581687dc9332484bddb18eddd42d10d==CST_NOAFTERSALEREQUEST){

if((UInt32)z63fdd992f9de36de5dd31f80cd382314!=0){*ErrorCode=
DCM_E_ENGINEISRUNNING;zf1fc67c1cea2085338919c8e9ff3086e=0;
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{if(
zf1fc67c1cea2085338919c8e9ff3086e==0){



if(z22bdb733a9b83aa8dcbdd46bf3a5ea9e==1){ze1abbb6890c010b125e234acd20cd772=
E_PENDING;}else{

zf1fc67c1cea2085338919c8e9ff3086e=1;zcfc786aeb7bb5bd53e83bd9933de9907=
zdc4f55dd9a6f46852fab1dd516106ce9;ze1abbb6890c010b125e234acd20cd772=E_PENDING;}}
else{

if(z22bdb733a9b83aa8dcbdd46bf3a5ea9e==1){z3581687dc9332484bddb18eddd42d10d=
CST_WRITE;ze1abbb6890c010b125e234acd20cd772=E_OK;}else{
ze1abbb6890c010b125e234acd20cd772=E_PENDING;}}}}else{

ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}
Rte_IrvWrite_RE_MPM_AftsNvmChkWrite_MPM_stAftsNvm(
z3581687dc9332484bddb18eddd42d10d);
Rte_IrvWrite_RE_MPM_AftsNvmChkWrite_MPM_IDAftsNvm(
zcfc786aeb7bb5bd53e83bd9933de9907);
Rte_IrvWrite_RE_MPM_AftsNvmChkWrite_MPM_ctLockRqAftsNvm(
zf1fc67c1cea2085338919c8e9ff3086e);
Rte_IrvWrite_RE_MPM_AftsNvmChkWrite_MPM_LockedAftsNvm(
z22bdb733a9b83aa8dcbdd46bf3a5ea9e);MPM_stAftsNvm=
z3581687dc9332484bddb18eddd42d10d;MPM_IDAftsNvm=
zcfc786aeb7bb5bd53e83bd9933de9907;MPM_ctLockRqAftsNvm=
zf1fc67c1cea2085338919c8e9ff3086e;MPM_LockedAftsNvm=
z22bdb733a9b83aa8dcbdd46bf3a5ea9e;return ze1abbb6890c010b125e234acd20cd772;}FUNC
(Std_ReturnType,RTE_APPL_CODE)RE_MPM_RstRqResults(UInt8 
zdc4f55dd9a6f46852fab1dd516106ce9,P2VAR(UInt8,AUTOMATIC,RTE_APPL_DATA)OutBuffer,
P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,RTE_APPL_DATA)ErrorCode){
Std_ReturnType ze1abbb6890c010b125e234acd20cd772;UInt8 
z3581687dc9332484bddb18eddd42d10d;UInt8 zcfc786aeb7bb5bd53e83bd9933de9907;P2VAR(
UInt8,AUTOMATIC,AUTOMATIC)MPM_stRstNvmRtn_ptr;z3581687dc9332484bddb18eddd42d10d=
Rte_IrvRead_RE_MPM_RstRqResults_MPM_stAftsNvm();
zcfc786aeb7bb5bd53e83bd9933de9907=Rte_IrvRead_RE_MPM_RstRqResults_MPM_IDAftsNvm(
);MPM_stRstNvmRtn_ptr=(P2VAR(UInt8,AUTOMATIC,AUTOMATIC))
Rte_IrvRead_RE_MPM_RstRqResults_MPM_stRstNvmRtn();if((MPM_NVMID_START>(UInt32)
zdc4f55dd9a6f46852fab1dd516106ce9)||((UInt32)zdc4f55dd9a6f46852fab1dd516106ce9>
MPM_NVMID_END)||ErrorCode==NULL||OutBuffer==NULL||(0x01&(
zde0c608c8fc85d92f6f9d51a544176c5[zdc4f55dd9a6f46852fab1dd516106ce9-1])==0)){
ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{if((
z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK)||(
z3581687dc9332484bddb18eddd42d10d==CST_RESET_NOK)){if((MPM_NVMID_START<=
zcfc786aeb7bb5bd53e83bd9933de9907)&&(zcfc786aeb7bb5bd53e83bd9933de9907<=
MPM_NVMID_END)){if(z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK){
MPM_stRstNvmRtn_ptr[zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_OK;}
else{
MPM_stRstNvmRtn_ptr[zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_NOK;}}
z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;}if(MPM_stRstNvmRtn_ptr
[zdc4f55dd9a6f46852fab1dd516106ce9-1]>RTN_ST_NOT_STARTED){OutBuffer[0]=
MPM_stRstNvmRtn_ptr[zdc4f55dd9a6f46852fab1dd516106ce9-1];
ze1abbb6890c010b125e234acd20cd772=E_OK;}else{*ErrorCode=
DCM_E_REQUESTSEQUENCEERROR;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}
Rte_IrvWrite_RE_MPM_RstRqResults_MPM_stAftsNvm(z3581687dc9332484bddb18eddd42d10d
);MPM_stAftsNvm=z3581687dc9332484bddb18eddd42d10d;return 
ze1abbb6890c010b125e234acd20cd772;}FUNC(Std_ReturnType,RTE_APPL_CODE)
RE_MPM_RstStart(UInt8 zdc4f55dd9a6f46852fab1dd516106ce9,UInt8*InBuffer,UInt8*
OutBuffer,Dcm_NegativeResponseCodeType*ErrorCode){Std_ReturnType 
ze1abbb6890c010b125e234acd20cd772;UInt8 z3581687dc9332484bddb18eddd42d10d;UInt8 
zcfc786aeb7bb5bd53e83bd9933de9907;P2VAR(UInt8,AUTOMATIC,AUTOMATIC)
MPM_stRstNvmRtn_ptr;UInt16 z63fdd992f9de36de5dd31f80cd382314;UInt8 
zf1fc67c1cea2085338919c8e9ff3086e;z3581687dc9332484bddb18eddd42d10d=
Rte_IrvRead_RE_MPM_RstStart_MPM_stAftsNvm();zcfc786aeb7bb5bd53e83bd9933de9907=
Rte_IrvRead_RE_MPM_RstStart_MPM_IDAftsNvm();MPM_stRstNvmRtn_ptr=(P2VAR(UInt8,
AUTOMATIC,AUTOMATIC))Rte_IrvRead_RE_MPM_RstStart_MPM_stRstNvmRtn();
Rte_Read_R_Ext_nEng_Ext_nEng(&z63fdd992f9de36de5dd31f80cd382314);
zf1fc67c1cea2085338919c8e9ff3086e=
Rte_IrvRead_RE_MPM_RstStart_MPM_ctLockRqAftsNvm();
if((MPM_NVMID_START>(UInt32)zdc4f55dd9a6f46852fab1dd516106ce9)||((UInt32)
zdc4f55dd9a6f46852fab1dd516106ce9>MPM_NVMID_END)||ErrorCode==NULL||OutBuffer==
NULL||(0x01&(zde0c608c8fc85d92f6f9d51a544176c5[zdc4f55dd9a6f46852fab1dd516106ce9
-1])==0)){ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}else{if((
z3581687dc9332484bddb18eddd42d10d==CST_RESET)||(
z3581687dc9332484bddb18eddd42d10d==CST_WRITE_OK)){

*ErrorCode=DCM_E_CONDITIONSNOTCORRECT;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK
;}else{
if((z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK)||(
z3581687dc9332484bddb18eddd42d10d==CST_RESET_NOK)){
if((MPM_NVMID_START<=zcfc786aeb7bb5bd53e83bd9933de9907)&&(
zcfc786aeb7bb5bd53e83bd9933de9907<=MPM_NVMID_END)){
if(z3581687dc9332484bddb18eddd42d10d==CST_RESET_OK){MPM_stRstNvmRtn_ptr[
zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_OK;}else{
MPM_stRstNvmRtn_ptr[zcfc786aeb7bb5bd53e83bd9933de9907-1]=RTN_ST_FINISHED_NOK;}
z3581687dc9332484bddb18eddd42d10d=CST_NOAFTERSALEREQUEST;}}if(
z3581687dc9332484bddb18eddd42d10d==CST_NOAFTERSALEREQUEST){
if((UInt32)z63fdd992f9de36de5dd31f80cd382314!=0){
*ErrorCode=DCM_E_ENGINEISRUNNING;ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}
else{
zf1fc67c1cea2085338919c8e9ff3086e=1;zcfc786aeb7bb5bd53e83bd9933de9907=
zdc4f55dd9a6f46852fab1dd516106ce9;z3581687dc9332484bddb18eddd42d10d=CST_RESET;
MPM_stRstNvmRtn_ptr[zdc4f55dd9a6f46852fab1dd516106ce9-1]=RTN_ST_RUNNING;
OutBuffer[0]=RTN_ST_RUNNING;ze1abbb6890c010b125e234acd20cd772=E_OK;}}else{


ze1abbb6890c010b125e234acd20cd772=E_NOT_OK;}}}
Rte_IrvWrite_RE_MPM_RstStart_MPM_ctLockRqAftsNvm(
zf1fc67c1cea2085338919c8e9ff3086e);Rte_IrvWrite_RE_MPM_RstStart_MPM_stAftsNvm(
z3581687dc9332484bddb18eddd42d10d);Rte_IrvWrite_RE_MPM_RstStart_MPM_IDAftsNvm(
zcfc786aeb7bb5bd53e83bd9933de9907);MPM_ctLockRqAftsNvm=
zf1fc67c1cea2085338919c8e9ff3086e;MPM_stAftsNvm=
z3581687dc9332484bddb18eddd42d10d;MPM_IDAftsNvm=
zcfc786aeb7bb5bd53e83bd9933de9907;return ze1abbb6890c010b125e234acd20cd772;}
#define MPM_STOP_SEC_CODE
#include "MPM_MemMap.h"

