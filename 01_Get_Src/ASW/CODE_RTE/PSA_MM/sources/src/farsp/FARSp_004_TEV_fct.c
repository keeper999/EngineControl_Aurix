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
* %name: FARSp_004_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:47 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_004_TEV_fct.c-3.0:csrc:4 %
*
*******************************************************************************/


#ifndef _FARSP_004_TEV_FCT_C_
#define _FARSP_004_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_004_TEV_fct.h"
#include "FARSp_004_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_EngM_mfTotExCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE004_ExM_tExStatAfs_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE004_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE004_TPM_rMixtLimMaxAflScv_in;AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE004_TPM_tExReq_in;AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtMaxThermoProt_out
;AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtThermoProtSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE004_ExM_stO2HcStgTWC_in;AR_IF_GLOBAL_8BIT UInt8 
FARSp_RE004_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAcvRichProtOxdTWC_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAcvRichThermoProt_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAirLdLimTExMgr_in;
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bRichLimScv_in;AR_IF_GLOBAL_BOOLEAN
 Boolean FARSp_bInvldThermoProt_out;AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bThermoProtAuth_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static SInt16 zae4f31ec20c8596b7f61d9c3734e6cfa;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 ze5570b56805174b5a7aebd8a69fc8ca6;static UInt16 
z25de16413867e0eea17ab9809e390806;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
static UInt32 z2c43fec0801ec35564ad0f62a77e9c90;
#define FARSP_STOP_SEC_VAR_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z526d80608cdd52b0b819ee8c6a7fe7c7;static UInt8 
z3608b316c565325d909889cc91cc6a89;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
AR_SEC_VAR_BOOLEAN Boolean z3079b6523bfdd0be1349159c1e11c148;AR_SEC_VAR_BOOLEAN 
Boolean zca73febf28288e58a780edfd7f3873a6;
#define FARSP_STOP_SEC_VAR_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_003_MSE_ini(Void){FARSp_004_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_004_TEV_fct(Void){UInt32 z08b7a6c58b9a2d7bf5a6bbea01455dba;UInt32 
z7facecb48bf76e476610babc3ab8f9ae;UInt32 zbe1fd3609a1df273d5dc2f37d033157b;
SInt32 z68f98b71c7ffbca55da4e7228d8ea167;UInt32 
za3428a59a64bd97cce18a33e555ff23b;UInt32 zf52f6f0f89f0fdacce9c4cf02ff24bad;
UInt16 zb1eced78c9ef4b79440a64a75d2505ff;UInt16 
zab3b9d7ca50e083836463286b2f1834f;UInt16 z8d923658357684f028f459950d7d36f7;
UInt16 zd7b95c8dc7267f354c04358bf94571e3;SInt32 
zd468f45f7296e73fe1291d4b933ffed7;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;UInt8
 z9fa28a9bfa43562a13245ecfa3963a8c;FARSp_facThermoProtSpGas=
FARSp_RE004_FARSp_prm_facGasFlexSp_in[0];z9fa28a9bfa43562a13245ecfa3963a8c=
FARSp_facThermoProtSpGas;if(z9fa28a9bfa43562a13245ecfa3963a8c){
zb1eced78c9ef4b79440a64a75d2505ff=(UInt16)z9fa28a9bfa43562a13245ecfa3963a8c;}
else{zb1eced78c9ef4b79440a64a75d2505ff=0;}FARSp_rMixtThermoProtSpGas=
FARSp_RE004_FARSp_prm_rMixtGasFlexSp_in[0];FARSp_facThermoProtSpFlex=
FARSp_RE004_FARSp_prm_facGasFlexSp_in[1];z9fa28a9bfa43562a13245ecfa3963a8c=
FARSp_facThermoProtSpFlex;if(z9fa28a9bfa43562a13245ecfa3963a8c){
zab3b9d7ca50e083836463286b2f1834f=(UInt16)z9fa28a9bfa43562a13245ecfa3963a8c;}
else{zab3b9d7ca50e083836463286b2f1834f=0;}FARSp_rMixtThermoProtSpFlex=
FARSp_RE004_FARSp_prm_rMixtGasFlexSp_in[1];zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)(((UInt32)(((UInt32)FARSp_RE004_TPM_tExReq_in)<<16))/((UInt16)(
FARSp_RE004_ExM_tExStatAfs_in+7136)));if(zd468f45f7296e73fe1291d4b933ffed7>0){
z08b7a6c58b9a2d7bf5a6bbea01455dba=(UInt32)zd468f45f7296e73fe1291d4b933ffed7;}
else{z08b7a6c58b9a2d7bf5a6bbea01455dba=0;}if(131072<
z08b7a6c58b9a2d7bf5a6bbea01455dba){FARSp_facTEgCorReq_MP=131072;}else{
FARSp_facTEgCorReq_MP=z08b7a6c58b9a2d7bf5a6bbea01455dba;}TabIdxS50T513((const 
UInt16*)FARSp_facTEgCorReqX_A,12,(UInt16)(FARSp_facTEgCorReq_MP>>2),&(
z3608b316c565325d909889cc91cc6a89),&(z25de16413867e0eea17ab9809e390806));
TabIdxS50T514((const UInt32*)FARSp_mfTotExCorY_A,12,(UInt32)
FARSp_RE004_EngM_mfTotExCor_in,&(z526d80608cdd52b0b819ee8c6a7fe7c7),&(
ze5570b56805174b5a7aebd8a69fc8ca6));FARSp_rMixtThermoProtSpGsl=
Tab2DIntp2I1T33282((const UInt32*)&(FARSp_rMixtThermoProtReq_M[0][0]),12,
z3608b316c565325d909889cc91cc6a89,z25de16413867e0eea17ab9809e390806,
z526d80608cdd52b0b819ee8c6a7fe7c7,ze5570b56805174b5a7aebd8a69fc8ca6);
z68f98b71c7ffbca55da4e7228d8ea167=(SInt32)(((UInt32)(SInt32)(((UInt32)
FARSp_rMixtThermoProtSpFlex)<<4))-FARSp_rMixtThermoProtSpGsl);F__I64MULU32I32((
UInt32)zab3b9d7ca50e083836463286b2f1834f,z68f98b71c7ffbca55da4e7228d8ea167,&(
zd468f45f7296e73fe1291d4b933ffed7),&(z21fed86397a19bfad54bda2cfdaa9d19));
FARSp_rMixtThermoProtFlex_MP=((UInt32)C__I32SHRI64C6_LT32(
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19,7,25))+
FARSp_rMixtThermoProtSpGsl;zbe1fd3609a1df273d5dc2f37d033157b=C__U32SATU32_SATu(
FARSp_rMixtThermoProtFlex_MP,983040);FARSp_rMixtThermoProtSpRaw=(UInt32)(((
SInt32)((((SInt32)zb1eced78c9ef4b79440a64a75d2505ff)*((SInt32)(((UInt32)(SInt32)
(((UInt32)FARSp_rMixtThermoProtSpGas)<<4))-zbe1fd3609a1df273d5dc2f37d033157b)))
>>7))+zbe1fd3609a1df273d5dc2f37d033157b);z7facecb48bf76e476610babc3ab8f9ae=
C__U32SATU32_SATu(FARSp_rMixtThermoProtSpRaw,983040);if((!(
FARSp_RE004_TPM_bAcvRichThermoProt_in))&&z3079b6523bfdd0be1349159c1e11c148){
za3428a59a64bd97cce18a33e555ff23b=(UInt32)(z7facecb48bf76e476610babc3ab8f9ae>>2)
;}else{UInt32 za4d10b852a4dcb06288957ee2b4fb69e;UInt16 
z6369bf1f0fcd8396432fcb27977aeaf4;UInt32 z598fc83d17c7afbb99b61c2115312c40;if(
FARSp_facFilThermoProt_C){z6369bf1f0fcd8396432fcb27977aeaf4=
FARSp_facFilThermoProt_C;}else{z6369bf1f0fcd8396432fcb27977aeaf4=0;}if(
zae4f31ec20c8596b7f61d9c3734e6cfa!=0){za4d10b852a4dcb06288957ee2b4fb69e=
z2c43fec0801ec35564ad0f62a77e9c90;}else{za4d10b852a4dcb06288957ee2b4fb69e=(
UInt32)(z7facecb48bf76e476610babc3ab8f9ae>>2);}F__U64MULU32U32((UInt32)(UInt16)(
((UInt16)(-z6369bf1f0fcd8396432fcb27977aeaf4))+16384),
za4d10b852a4dcb06288957ee2b4fb69e,&(z21fed86397a19bfad54bda2cfdaa9d19),&(
z598fc83d17c7afbb99b61c2115312c40));za3428a59a64bd97cce18a33e555ff23b=((UInt32)(
(((UInt32)FARSp_rMixtMinCmbSp_C)*((UInt32)z6369bf1f0fcd8396432fcb27977aeaf4))>>
12))+C__U32SHRU64C6_LT32(z21fed86397a19bfad54bda2cfdaa9d19,
z598fc83d17c7afbb99b61c2115312c40,14,18);}if(
FARSp_RE004_TPM_bAcvRichThermoProt_in){FARSp_rMixtThermoProtReq=
z7facecb48bf76e476610babc3ab8f9ae;}else{UInt16 z93a6dea10f1eff309d74296c7deaaafb
;if(zca73febf28288e58a780edfd7f3873a6){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32
)(za3428a59a64bd97cce18a33e555ff23b>>2);z93a6dea10f1eff309d74296c7deaaafb=
C__U16SATU32_SATu(z21fed86397a19bfad54bda2cfdaa9d19,61440);}else{
z93a6dea10f1eff309d74296c7deaaafb=(UInt16)(z7facecb48bf76e476610babc3ab8f9ae>>4)
;}FARSp_rMixtThermoProtReq=(UInt32)(((UInt32)z93a6dea10f1eff309d74296c7deaaafb)
<<4);}if(FARSp_RE004_TPM_bAcvRichProtOxdTWC_in){
zd7b95c8dc7267f354c04358bf94571e3=FARSp_rMixtProtTWCMin_C;}else{if(
FARSp_RE004_ExM_stO2HcStgTWC_in==1){zd7b95c8dc7267f354c04358bf94571e3=4096;}else
{zd7b95c8dc7267f354c04358bf94571e3=FARSp_rMixtMinCmbSp_C;}}
z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(((UInt32)
zd7b95c8dc7267f354c04358bf94571e3)<<4);if(FARSp_rMixtThermoProtReq>
z21fed86397a19bfad54bda2cfdaa9d19){zf52f6f0f89f0fdacce9c4cf02ff24bad=
FARSp_rMixtThermoProtReq;}else{zf52f6f0f89f0fdacce9c4cf02ff24bad=
z21fed86397a19bfad54bda2cfdaa9d19;}if(FARSp_RE004_TPM_bAirLdLimTExMgr_in){
z8d923658357684f028f459950d7d36f7=FARSp_rMixtMaxAuth_C;}else{
z8d923658357684f028f459950d7d36f7=(UInt16)(zf52f6f0f89f0fdacce9c4cf02ff24bad>>4)
;}if(FARSp_RE004_ExM_stO2HcStgTWC_in==2){FARSp_rMixtMaxThermoProt_irv_MP=
FARSp_rMixtSatO2Max_C;}else{if(FARSp_RE004_TPM_bRichLimScv_in){
FARSp_rMixtMaxThermoProt_irv_MP=FARSp_RE004_TPM_rMixtLimMaxAflScv_in;}else{
FARSp_rMixtMaxThermoProt_irv_MP=FARSp_rMixtMaxAuth_C;}}
FARSp_rMixtMaxThermoProt_out=FARSp_rMixtMaxThermoProt_irv_MP;
FARSp_bInvldThermoProt=zf52f6f0f89f0fdacce9c4cf02ff24bad>((UInt32)(((UInt32)
FARSp_RE004_TPM_rMixtLimMaxAflScv_in)<<4));FARSp_bInvldThermoProt_out=
FARSp_bInvldThermoProt;FARSp_bThermoProtAuth=z8d923658357684f028f459950d7d36f7>=
FARSp_rMixtThermoProtThd_C;FARSp_bThermoProtAuth_out=FARSp_bThermoProtAuth;if(
z8d923658357684f028f459950d7d36f7){FARSp_rMixtThermoProtSp_irv_MP=
z8d923658357684f028f459950d7d36f7;}else{FARSp_rMixtThermoProtSp_irv_MP=0;}
FARSp_rMixtThermoProtSp_out=FARSp_rMixtThermoProtSp_irv_MP;
z3079b6523bfdd0be1349159c1e11c148=FARSp_RE004_TPM_bAcvRichThermoProt_in;
zae4f31ec20c8596b7f61d9c3734e6cfa=16384;z2c43fec0801ec35564ad0f62a77e9c90=
za3428a59a64bd97cce18a33e555ff23b;zca73febf28288e58a780edfd7f3873a6=1;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_004_FctVarInit(Void){FARSp_rMixtThermoProtSp_out=4096;
ze5570b56805174b5a7aebd8a69fc8ca6=0;z526d80608cdd52b0b819ee8c6a7fe7c7=0;
z25de16413867e0eea17ab9809e390806=0;z3608b316c565325d909889cc91cc6a89=0;
z3079b6523bfdd0be1349159c1e11c148=0;zca73febf28288e58a780edfd7f3873a6=0;
zae4f31ec20c8596b7f61d9c3734e6cfa=0;z2c43fec0801ec35564ad0f62a77e9c90=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

