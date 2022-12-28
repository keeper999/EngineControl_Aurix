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
* %name: TPM_code.c %
*
* %version: 3.3 %
*
* %date_modified: Thu May  2 11:28:51 2013 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC4.3 %
* %full_filespec: TPM_code.c-3.3:csrc:2 %
*
*******************************************************************************/


#ifndef _TPM_CODE_C_
#define _TPM_CODE_C_
#include "TPM_code.h"
#include "TPM_calibrations.h"
#include "Library_lut.h"
#include "dsfxp.h"
#include "TPM_nvm.h"
#include "SC.h"
#define TPM_START_SEC_VAR_16BIT
#include "TPM_MemMap.h"
ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev1_0;ISV_SRSS11_0_tp 
subIsv16_TPM_SRSS11_Dev2_0;ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev3_0;
ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev4_0;ISV_SRSS11_0_tp 
subIsv16_TPM_SRSS11_Dev_0;ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev_0_a;
ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev_0_b;
#define TPM_STOP_SEC_VAR_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_8BIT
#include "TPM_MemMap.h"
ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev1_1;ISV_SRSS11_1_tp 
subIsv8_TPM_SRSS11_Dev2_1;ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev3_1;
ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev4_1;ISV_SRSS11_1_tp 
subIsv8_TPM_SRSS11_Dev_1;ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev_1_a;
ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev_1_b;
#define TPM_STOP_SEC_VAR_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_CONST_UNSPECIFIED
#include "TPM_MemMap.h"
static z96bf6e11bd3fedb6ee335df77cb350d3 z2d8a6c86d69f4c6c1082bad2a59f66ab={&(
subIsv16_TPM_SRSS11_Dev1_0),&(subIsv8_TPM_SRSS11_Dev1_1)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 z15befb9620efcd0b4ec01fca8fbe34e1={&(
subIsv16_TPM_SRSS11_Dev2_0),&(subIsv8_TPM_SRSS11_Dev2_1)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 z40561b610ce58d69fd87e27e440660f5={&(
subIsv16_TPM_SRSS11_Dev3_0),&(subIsv8_TPM_SRSS11_Dev3_1)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 zd5a90cac76f6404e94334badc803b2be={&(
subIsv16_TPM_SRSS11_Dev4_0),&(subIsv8_TPM_SRSS11_Dev4_1)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 z85d72b3a21ad48f72bacac76d313f63c={&(
subIsv16_TPM_SRSS11_Dev_0),&(subIsv8_TPM_SRSS11_Dev_1)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 zfa2f99f2a2ccc50c31415022f1f5f138={&(
subIsv16_TPM_SRSS11_Dev_0_a),&(subIsv8_TPM_SRSS11_Dev_1_a)};static 
z96bf6e11bd3fedb6ee335df77cb350d3 za44d00fffc2f28b5684d46d9e66f06b6={&(
subIsv16_TPM_SRSS11_Dev_0_b),&(subIsv8_TPM_SRSS11_Dev_1_b)};
#define TPM_STOP_SEC_CONST_UNSPECIFIED
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 PhyMSI_pwrCylHdEstim_out;AR_IF_GLOBAL_16BIT UInt16 
PhyMSI_tExMnfEstim_out;AR_IF_GLOBAL_16BIT UInt16 PhyMSI_tTrbCaseEstim_out;
AR_IF_GLOBAL_16BIT UInt16 RE004_TPM_mfAirScvLimMax_in;AR_IF_GLOBAL_16BIT UInt16 
RE004_TPM_tRefTWCScvMax_in;AR_IF_GLOBAL_16BIT UInt16 RE005_TPM_tTWC_in;
AR_IF_GLOBAL_16BIT UInt16 RE006_TPM_rAirLdReqRbl_in;AR_IF_GLOBAL_16BIT UInt16 
RE006_TPM_rAirLdReq_in;AR_IF_GLOBAL_16BIT UInt16 
RE006_TPM_tExCurAcvThermoProtDev_in;AR_IF_GLOBAL_16BIT UInt16 
RE007_TPM_rAirLdReqRbl_in;AR_IF_GLOBAL_16BIT UInt16 TEMP_PhyMSI_tExMnfEstim_NV;
AR_IF_GLOBAL_16BIT UInt16 TEMP_PhyMSI_tTrbCaseEstim_NV;AR_IF_GLOBAL_16BIT UInt16
 TPM_RE002_EngM_mfAirCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE002_ExM_mfEgTot_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE002_ExM_prm_tEg_in[12];AR_IF_GLOBAL_16BIT UInt16
 TPM_RE002_ExM_prm_tWall_in[12];AR_IF_GLOBAL_16BIT UInt16 TPM_RE002_Ext_nEng_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE002_FARSp_rMixtCylSp_in;AR_IF_GLOBAL_16BIT 
UInt16 TPM_RE003_ExM_prm_tEg_in[12];AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_ExM_prm_tWall_in[12];AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_FARSp_rMixtCylSp_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_PhyMSI_tExMnfEstim_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_PhyMSI_tTrbCaseEstim_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_EngM_mfAirScvCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE004_Ext_nEng_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE004_UsThrM_facPresAltiCor_in;AR_IF_GLOBAL_16BIT 
UInt16 TPM_RE005_EngM_mfAirCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE005_EngM_mfAirScvCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE005_FARSp_rMixtCylSp_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_EngMTrb_rLdMax_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE006_ExM_mfEgTot_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE006_ExM_tExStatAfs_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE006_FARSp_rMixtCylSp_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE006_FARSp_rMixtThermoProtSp_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE006_TPM_tTarAcvThermoProtDev_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE007_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_facCorIgProtComp_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_mfEgTot_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE007_ExM_prm_facFlex_in[
5];AR_IF_GLOBAL_16BIT UInt16 TPM_RE007_ExM_prm_facGas_in[5];AR_IF_GLOBAL_16BIT 
UInt16 TPM_RE007_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_IgSys_rStatIgSpEfc_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_TPM_rAirLdReqGas_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE007_TPM_tExReq_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_EngM_rAirLdCor_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_ExM_mfEgWoutEGR_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_ExM_tExMnfEstim_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_Ext_nEng_in;
AR_IF_GLOBAL_16BIT SInt16 TPM_RE008_Ext_tCoMes_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_FARSp_rMixtCylSp_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_PhyMSI_tExMnfEstim_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_PhyMSI_tTrbCaseEstim_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_Veh_spdVeh_in;AR_IF_GLOBAL_16BIT UInt16 TPM_RE009_EngM_rAirLdCor_in;
AR_IF_GLOBAL_16BIT UInt16 TPM_RE009_Ext_nEng_in;AR_IF_GLOBAL_16BIT UInt16 
TPM_mfAirScvLimMaxCor_out;AR_IF_GLOBAL_16BIT UInt16 TPM_rLdProtExThermo_out;
AR_IF_GLOBAL_16BIT UInt16 TPM_rMixtLimMaxAflScv_out;AR_IF_GLOBAL_16BIT UInt16 
TPM_tExReq_out;AR_IF_GLOBAL_16BIT UInt16 TPM_tTarAcvThermoProtDev_out;
#define TPM_STOP_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_32BIT
#include "TPM_MemMap.h"
AR_IF_GLOBAL_32BIT UInt32 PhyMSI_pCylMaxEstim_out;AR_IF_GLOBAL_32BIT UInt32 
TPM_RE001_EOM_tiEngStop_in;AR_IF_GLOBAL_32BIT UInt32 TPM_RE005_ExM_lamTot_in;
#define TPM_STOP_SEC_GLOBAL_32BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_8BIT
#include "TPM_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 ExM_stO2HcStgTWC_out;AR_IF_GLOBAL_8BIT UInt8 
RE006_TPM_noAcvThermoProtDev_in;AR_IF_GLOBAL_8BIT SInt8 TPM_RE001_Ext_tAir_in;
AR_IF_GLOBAL_8BIT UInt8 TPM_RE002_ExM_stO2HcStgTWC_in;AR_IF_GLOBAL_8BIT UInt8 
TPM_RE003_IgSys_agIgMinThermo_in;AR_IF_GLOBAL_8BIT UInt8 
TPM_RE003_IgSys_prm_agIgSpCyl_in[6];AR_IF_GLOBAL_8BIT UInt8 
TPM_RE004_ExM_stO2HcStgTWC_in;AR_IF_GLOBAL_8BIT UInt8 TPM_RE005_Ext_uLsDsMes_in;
AR_IF_GLOBAL_8BIT UInt8 TPM_RE008_Ext_rSpdFanAct_in;AR_IF_GLOBAL_8BIT SInt8 
TPM_RE008_Ext_tAir_in;
#define TPM_STOP_SEC_GLOBAL_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_BOOLEAN
#include "TPM_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean RE006_TPM_bAcvProtExScv_in;AR_IF_GLOBAL_BOOLEAN 
Boolean RE007_TPM_bAcvProtExScv_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_DmgMSI_bLdLimReq_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_DmgMSI_bMPMInh_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_FARSp_bRichScvThermoInvld_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_FARSp_bSatMaxRatMixt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_FARSp_bThermoProtReqNotAuth_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_FRM_bAcvEcpHeatProt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_TPM_bRichLimScv_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE003_ThMgt_bAcvR1234Mgt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE004_FARSp_bRichScvThermoInvld_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE004_FRM_bAcvLimScv_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE004_FRM_bAcvTPMDecTMaxDev_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE005_FRM_bAcvTPMDecTMaxDev_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE005_FRM_bInhCutOff_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_FARSp_bSatMaxRatMixt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_FARSp_bThermoProtReqNotAuth_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_FRM_bAcvTPMDecTMaxDev_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_TPM_bAcvRichProtOxdTWC_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_TPM_bAcvRichThermoProt_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE006_TPM_bAirLdLimTExMgr_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_RE007_TPM_bAirLdLimTExMgr_in;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bAcvRichProtOxdTWC_out;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bAcvRichThermoProt_out;AR_IF_GLOBAL_BOOLEAN Boolean TPM_bAirLdLimTExMgr_out;
AR_IF_GLOBAL_BOOLEAN Boolean TPM_bExThermoProt_out;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bInhInjCutOff_out;AR_IF_GLOBAL_BOOLEAN Boolean TPM_bInhInjSelCutOff_out;
AR_IF_GLOBAL_BOOLEAN Boolean TPM_bInhOvbReq_out;AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bRichLimScv_out;
#define TPM_STOP_SEC_GLOBAL_BOOLEAN
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_16BIT
#include "TPM_MemMap.h"
static UInt16 z06e9c80106c61f0fa8272b129cf851cd;static UInt16 
z7610faa7f7dd8d83a84a693ccc2b264f;static UInt16 
z149e4e954877623f0025a17d41f58f80;static UInt16 
z3bbc2b5f4f525e241eb407fd4357b48c;static UInt16 
zd5d55425a9124e825d981a7d8c2cf789;static UInt16 
z424016e8f4c95386cc9bfbf3b005c872;static UInt16 
zaea03dac07973206d10a78d25774ca5c;static UInt16 
zcd43b690230d13f06a3e0010edbd62a3;static UInt16 
z694e56cfbb611871ab99e3c363cb8e24;static UInt16 
z212637ecea88234c6b95ffc69854b91c;static UInt16 
zd09180c7dd667c635fe7618879d1fd31;static UInt16 
ze168a0c5e7742fed41d599a2886d858c;static UInt16 
zbe2c80059de365a15784ffa4bafabd10;static UInt16 
z657502ca7ebf6e6021571853b02d5185;static UInt16 
z229525ae0d1ffd7362172ea64ef77ea1;static UInt16 
zbb15cebec5277be27be297f647facacb;
#define TPM_STOP_SEC_VAR_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_16BIT
#include "TPM_MemMap.h"
static UInt16 z3d26d4a85063ecb268f95a58308ab171;static SInt16 
zeb0ecda3e79d047b5d6439d219ae94c2;static SInt16 
z82af16d90f8310dac54595db7730cf6d;static SInt16 
z2db3e7a844f4fc306743bc386244745c;static SInt16 
z82b0b31d555204c1fe0f75036f69634d;static UInt16 
zadd9bc2091480845f6552a34ca4eda2f;static UInt16 
z0ac6bdc96f479a2298807f6007f6e575;static UInt16 
z61f702e660fc002cae41748aa0a44af6;static UInt16 
z5789054cbcc0eb263da5fa3d1270a2cf;static UInt16 
z8afa732dac1c3494e2be03ec09e7eb74;static UInt16 
za38b275d73d6010cf84de6261b1cac8e;static UInt16 
z6f71fda760a8ba9894ae0a9433ed9be1;static UInt16 
zbf75324abaf05eda53dbc931bbbe80a9;static UInt16 
z822ce74faba1cfcc86c02ca647fc7376;
#define TPM_STOP_SEC_VAR_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_16BIT
#include "TPM_MemMap.h"
static UInt16 z2073fea7712adde1aeab47a6c62c3696;static UInt16 
z751b528547dcef53601fdbbbd3fbaa9f;static UInt16 
zc392b71841ee68c18553c73642e6e9a0;static UInt16 
z0269c26ac184c8529467cfc37d2ec13f;static UInt16 
zf7b97cfa50f367b444d8f090f7a07f5c;static UInt16 
z38a7f1edbb2cd9238d01fb2e55628f77;static UInt16 
z56d1d206d1d220bfcf7bac7bc674b2bc;static UInt16 
z999e2ff6eccf0f03fc1d2c072b3551c7;static UInt16 
z8bc044e03fe786fadc6d6cd7ab4a1424;static UInt16 
z4df52fe517c6ce6eaf64521f0176b465;static UInt16 
zbf3d2a15eaf8a1bafd63dd685978ec2a;static UInt16 
zf6e1cc00b69ce6a8a30dda9884ab8ef8;static UInt16 
zb781d7d8150b0c8dc57418b4b5a151c4;static UInt16 
z459564cb29de6694fc422f50235bebff;static UInt16 
z42628718f74dc73dadb957e546d86dee;static UInt16 
zcae450bd13f7ebdb28389ee57eac9ecf;static UInt16 
ze87bafe4f5e46708f7b8aaac5bf48fd9;static UInt16 
zbe14ffeebbf5c20bec99431707f3a170;static UInt16 
z2fa9d32034c66af2b1002008884f5b2b;static UInt16 
z61639686d514d1bc75294417daf885e1;static UInt16 
z62821e632e249793771c8e17b23568b3;static UInt16 
zeb472c756e87614dad7dac0d5e69d20a;static UInt16 
z506dedaa45465471a38be4c154bc0f24;static UInt16 
z37194301e86fa1b76255496a16bb208f;static UInt16 
z31e3951fa8e12e0341d264dcf91bdd3c;static UInt16 
zee453e997508959edc8e61ecc7f1ff1b;static UInt16 
za7653f54f9cd8888a3dac4944a04dee9;static UInt16 
z508dd42316116c91160501d8dd9fa558;static UInt16 
z012b6c1ae8d05b5af762ff999f5382f6;static UInt16 
za8ffccb29850928b689e7bb7dacb5dd2;static UInt16 
z86806c86fa3a8cd4cd71deb332465b1c;static UInt16 
z101baa0885a8b9c8fca87590a876f65d;static UInt16 
ze6b63784b37107d27da156b3ff76f6b7;static UInt16 
z0fb436dc4d9a424271d9561523472fbb;static UInt16 
za2f97ce0c6526e204c6cebec85b8c08a;static UInt16 
za21850e6def46bf19025e659a2a99e9b;static UInt16 
zb857435c9402aa454a19415717e3e6b5;static UInt16 
z3ea1e38e46f4cc8965d595eef2c721d1;static UInt16 
zbd7050086212d78d8c19a3bec4f9c07e;
#define TPM_STOP_SEC_VAR_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_32BIT
#include "TPM_MemMap.h"
static UInt32 z3924675519b4fe318c4a8dda753406f3;static UInt32 
zeaba0127f6735e7ede2864d8def2c7ae;static SInt32 
zc2a33c76c54cadd7cb8ed332b9214311;static UInt32 
z5b9fc97212290211de831a6b5c996265;static UInt32 
z615af0db8952dccd3d33c89f6c74d78f;
#define TPM_STOP_SEC_VAR_32BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_32BIT
#include "TPM_MemMap.h"
static SInt32 z7c1e3da8683b717fdc571a1630ac0c46;static UInt32 
z8989133d93740c8f1c1077973b405856;static UInt32 
zba18a747dc27f22ec0342f1568c76289;static UInt32 
zf5b34358c5a6e71149eb304ab0efdc4f;static UInt32 
zaf63b714216ad8736266569557dd326e;static UInt32 
z8e73b2fdd2f29a123bf8d802578b41f1;static SInt32 
zf3208f619f38c5866e55f1d8b64b45b9;static SInt32 
zba77dde50534638bf758da37204ced21;static SInt32 
zabc29a3d4cdabd62d0b89f5259297006;static UInt32 
ze4938ff37c77cdff67c4d2dfe18044d8;static UInt32 
z320d20145d31ca1901fbeea7f3dcbb20;static UInt32 
zc68d065c4b4ff5330b7da46c9381734b;static UInt32 
zcf3ccb84663209a35029d94badab9f54[7];
#define TPM_STOP_SEC_VAR_32BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_8BIT
#include "TPM_MemMap.h"
static SInt8 z0018ca02008a7529d8fe840dd7b08f01;static UInt8 
z6db6b90ed3d73ee7f9530cafd9c4abcd;static UInt8 z96ed6e831041becc81a67c49f2955f72
;
#define TPM_STOP_SEC_VAR_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_8BIT
#include "TPM_MemMap.h"
#define TPM_STOP_SEC_VAR_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_BOOLEAN
#include "TPM_MemMap.h"
static Boolean zb3026ac91a9e667604ea0865427ac2c1;static Boolean 
zb9e0bbf5224a0cd2f391925391aec4e0;static Boolean 
zdd5f1f3dee657178ebe3dbc123d9900c;static Boolean 
z7a702e59268d760c3f1103a6fd6f1e62;static Boolean 
z3fada861cdf95110b6e04b1fe5883966;static Boolean 
z1d336274b8771934b34fef2f33bd5e2d;static Boolean 
z2c66e88595a50e0cb47734f02078a5ea;static Boolean 
zd44a61b2e95d9595a5b9e6898b8be6e4;static Boolean 
z0236c190df9df9ede94b1b7715a97dd5;static Boolean 
z937a9d18796810e9c591e7ed544d3417;static Boolean 
z63932db0640ab683e8069d110a030bcb;static Boolean 
z09f22c54a83008c7f0e6a9257e383094;static Boolean 
z8256e4b531f76057949727815e15bffc;static Boolean 
z9bc1fab8b3f8bb5978448812fda0a0b5;static Boolean 
zf89e3734b87119fb5b2cc8f4ea80a0d2;static Boolean 
z7e84a9459defeab4df370f72aa772ee2;static Boolean 
zb740ff4154c989352e0c0fb6c919d44c;static Boolean 
zd39a750fbcf3ea0eaf7246aee3eccf5a;static Boolean 
zc72a1c1d959fed6406f28fe5a965dd9a;static Boolean 
z41fa3d5ce3398afab5c003e48c481674;static Boolean 
z4ec787e92236bb7748dc3a85bb031d1e;static Boolean 
z2d07d203c34c561a8166fdae37c33bda;static Boolean 
ze119367927442a24e168287dc42c1419;static Boolean 
z9faaf4a97ab42e03fb785b9bf34265a6;static Boolean 
z72ce00e110723d4a019c24fc1e43f290;static Boolean 
z54beb4eb1364f48e07bb7e3620e5c522;static Boolean 
z46d85d13b727af93f15b4bed3277b1c9;static Boolean 
zd6256dc956d19116f3c133e11101744c;static Boolean 
z2b7cd2f6fc311ad968c13bd63dd05417;static Boolean 
z21d095369b9b5aa53db6f41a202e6df1;static Boolean 
z90b540ab8a74466d49971cdff8af2f95;static Boolean 
zf779a5f75e4029bf1478433d3133291a;static Boolean 
z07bd6ad0b035f5784d3c8f087a753755;static Boolean 
zeffbd27d014ac6a46ed446a65e03493d;
#define TPM_STOP_SEC_VAR_BOOLEAN
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_8BIT
#include "TPM_MemMap.h"
static UInt8 z83e6e8e7443d0d47afcbb1d6ee1905a0;static UInt8 
za4e562df19791d83709676cddb0b8028;static UInt8 za53491f9e7fc20dfb59fb341ccaca186
;static UInt8 z5c62cb7bb3dd9c3cd91dac2c5abd7fc9;static UInt8 
z53360e0c96f2e5df1239cdf4a834fa60;static UInt8 zd0dca0a9fddb230bee7c91132fa3890e
;static UInt8 z68dd5ef6ca619b751814bc81cf3b0285;static UInt8 
zb4a28b6d16f52566ff7feef4361efd75;static UInt8 zdd44e6bdbcdda5c66e839f2a9889d87c
;static UInt8 zb498d899cfa965de278bcc9a92086e13;static UInt8 
zbce73f872e4d34b5157b4d06ed2891e4;static UInt8 z9b923c74f7e83cb82e6aae10406a9350
;static UInt8 z488e38854283bb9a6bcc49d8b78ab5a1;static UInt8 
zade34fef6c50bfb037cabc6681437549;static UInt8 z535ddc9e9989b251662caf9306e11f0f
;static UInt8 z67cbaad2dca13f407bf0e26e2a4a345f;static UInt8 
z5679d88a7df62720c532227da2f27f03;static UInt8 zb3210f69c294b795a9014d1b265eb97d
;static UInt8 z7ea1447b7b4593821e61e37d9dbbbe5e;static UInt8 
z80028e992b391f40eac2a72a07fe3466;static UInt8 zfe840e7b3060275a301f19eccd02f641
;static UInt8 zaf84b598eb7e6ccafd22bec08c4e8517;static UInt8 
z12928cf7d33fd08f08cb514080390dce;static UInt8 zb56a24ebf57076f0e75283f82cfeb5bd
;static UInt8 zeccd7b4a5eee45178daebe27fbc25ae7;static UInt8 
za02ab45d7184a5969785fdb1e3c56a57;static UInt8 zf569b8ac6a053fdff6ae7e9db2af8b35
;static UInt8 z37b0b5f9350985dbdecd85a5f023e77e;static UInt8 
z4bd435887ee597dd0985584449435063;static UInt8 ze374164a558733ef12261b5d878df60c
;static UInt8 z17658853cd0a1cc88ce15854dbe6d420;static UInt8 
z9bfbbc50a6feb4e0b2cf2da945bde25b;static UInt8 z05984fcf2d7dbb03202309a281558061
;static UInt8 z7afbb36daf6c307137171f65651737fd;static UInt8 
zf5f3a58e0312d1090436047e52dfc413;static UInt8 z1fafea4e38b1d32f62e3cb9594f0ed92
;static UInt8 za87bb83c61b06587cb4227ed85752f64;static UInt8 
z71bea8e23ecc68d5e1cc405c6d8bcc28;static UInt8 z2620ff8d81062a04ccb024dd3fd223ee
;static UInt8 z072f7056b773256c69e596594b65c0a9;static UInt8 
z9d54d1e1a0319a30be30d1f3692559e0;static UInt8 z40a72ebc94864c7eec36f2bb285c6626
;static UInt8 zda8a07ef6f3c9e6b9bde0f98f9c9474d;
#define TPM_STOP_SEC_VAR_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
AR_EXT_VAR_SAVED_Z1CST_16BIT TPM_SNV_Z1_CST_16BIT TPM_sNV_Z1_CST_16BIT;
#define TPM_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_002_TEV_fct(Void){SInt32 zd468f45f7296e73fe1291d4b933ffed7;SInt32 
z06f32ff761b03af45c9f63ba6e33e8d9;SInt32 z91d6bd6fb6e014158f04ff5ae654b748;
SInt32 zda1f01f865fd1b51e129ca10fa784b66;UInt32 
z21fed86397a19bfad54bda2cfdaa9d19;UInt32 z598fc83d17c7afbb99b61c2115312c40;
UInt32 ze7aaa232278aa4bfdf744ffb64ef0932;UInt32 
z73d2b71b576f4a88f55f370afa9fe86f;UInt32 za4b585c36c9215a2cb2eccf272d20fd4;
UInt16 ze5aed13a5b01444f5678c6825a5c30fc;UInt16 
z0b07bfb92c95c708197ebf260276e235;Boolean zdd4e44469c7ba977522b67d97628ca58;
TPM_tEgTWCInp=TPM_RE002_ExM_prm_tEg_in[(UInt8)(SInt16)(UInt8)(
TPM_idxSelTEgTWCInp_C-1)];zd468f45f7296e73fe1291d4b933ffed7=((SInt32)(((UInt32)(
SInt32)(((UInt32)TPM_tMaxOxdTWCScvMax_C)-((UInt32)TPM_tEgTWCInp)))-14272))+7136;
if(zd468f45f7296e73fe1291d4b933ffed7>0){ze5aed13a5b01444f5678c6825a5c30fc=(
UInt16)zd468f45f7296e73fe1291d4b933ffed7;}else{ze5aed13a5b01444f5678c6825a5c30fc
=0;}if(TPM_bSelTRefTWCScvMax_C){z06e9c80106c61f0fa8272b129cf851cd=
TPM_tSelTRefTWCScvMax_C;}else{if(TPM_bSelTWallTWCScvMax_C){
z06e9c80106c61f0fa8272b129cf851cd=TPM_RE002_ExM_prm_tWall_in[(UInt8)(SInt16)(
UInt8)(TPM_idxSelTWallTWCScvMax_C-1)];}else{z06e9c80106c61f0fa8272b129cf851cd=
TPM_RE002_ExM_prm_tEg_in[(UInt8)(SInt16)(UInt8)(TPM_idxSelTEgTWCScvMax_C-1)];}}
RE002_TPM_tRefTWCScvMax_out=z06e9c80106c61f0fa8272b129cf851cd;
z21fed86397a19bfad54bda2cfdaa9d19=((UInt32)TPM_facEOxdEmiGsl_C)*((UInt32)
TPM_concO2Air_C);if(TPM_facFildeltaTExoScvMax_C){
z0b07bfb92c95c708197ebf260276e235=TPM_facFildeltaTExoScvMax_C;}else{
z0b07bfb92c95c708197ebf260276e235=0;}if(z4ec787e92236bb7748dc3a85bb031d1e){
z598fc83d17c7afbb99b61c2115312c40=zc68d065c4b4ff5330b7da46c9381734b;}else{
z598fc83d17c7afbb99b61c2115312c40=(UInt32)(((UInt32)
ze5aed13a5b01444f5678c6825a5c30fc)<<15);}F__U64MULU32U32((UInt32)(UInt16)(((
UInt16)(-z0b07bfb92c95c708197ebf260276e235))+16384),
z598fc83d17c7afbb99b61c2115312c40,&(ze7aaa232278aa4bfdf744ffb64ef0932),&(
z73d2b71b576f4a88f55f370afa9fe86f));zd468f45f7296e73fe1291d4b933ffed7=(SInt32)((
((UInt32)((((UInt32)ze5aed13a5b01444f5678c6825a5c30fc)*((UInt32)
z0b07bfb92c95c708197ebf260276e235))<<1))+C__U32SHRU64C6_LT32(
ze7aaa232278aa4bfdf744ffb64ef0932,z73d2b71b576f4a88f55f370afa9fe86f,14,18))>>4);
TabIdxS50T513((const UInt16*)TPM_tEg_A,8,(UInt16)(TPM_tEgTWCInp+7136),&(
zb56a24ebf57076f0e75283f82cfeb5bd),&(z37194301e86fa1b76255496a16bb208f));
z657502ca7ebf6e6021571853b02d5185=Tab1DIntp2I1T65((const UInt16*)TPM_cppEg_T,
zb56a24ebf57076f0e75283f82cfeb5bd,z37194301e86fa1b76255496a16bb208f);
zdd4e44469c7ba977522b67d97628ca58=z21fed86397a19bfad54bda2cfdaa9d19!=0;if(
zdd4e44469c7ba977522b67d97628ca58){if(z41fa3d5ce3398afab5c003e48c481674){
z598fc83d17c7afbb99b61c2115312c40=(UInt32)(zd468f45f7296e73fe1291d4b933ffed7<<4)
;}else{z598fc83d17c7afbb99b61c2115312c40=(UInt32)(((UInt32)
ze5aed13a5b01444f5678c6825a5c30fc)<<15);}TPM_tDeltaTExoScvTWCAuth_MP=(UInt16)(
z598fc83d17c7afbb99b61c2115312c40>>15);z598fc83d17c7afbb99b61c2115312c40=((
UInt32)TPM_tDeltaTExoScvTWCAuth_MP)*((UInt32)TPM_RE002_ExM_mfEgTot_in);
F__U64MULU32U32(z598fc83d17c7afbb99b61c2115312c40,(UInt32)
z657502ca7ebf6e6021571853b02d5185,&(ze7aaa232278aa4bfdf744ffb64ef0932),&(
z73d2b71b576f4a88f55f370afa9fe86f));zaf63b714216ad8736266569557dd326e=
C__U32SHRU64C6_LT32(ze7aaa232278aa4bfdf744ffb64ef0932,
z73d2b71b576f4a88f55f370afa9fe86f,12,20)/z21fed86397a19bfad54bda2cfdaa9d19;}if(
zdd4e44469c7ba977522b67d97628ca58){z21fed86397a19bfad54bda2cfdaa9d19=
zaf63b714216ad8736266569557dd326e;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}
C__U64SHLU32C6_LT32(z21fed86397a19bfad54bda2cfdaa9d19,2,30,
z598fc83d17c7afbb99b61c2115312c40,ze7aaa232278aa4bfdf744ffb64ef0932);
TPM_mfAirScvLimMaxAfrScv_MP=(UInt32)C__U16FITU64_SATu(
z598fc83d17c7afbb99b61c2115312c40,ze7aaa232278aa4bfdf744ffb64ef0932,65535);
zdd4e44469c7ba977522b67d97628ca58=TPM_RE002_EngM_mfAirCor_in!=0;if(
zdd4e44469c7ba977522b67d97628ca58){z8e73b2fdd2f29a123bf8d802578b41f1=((UInt32)(
TPM_mfAirScvLimMaxAfrScv_MP<<12))/TPM_RE002_EngM_mfAirCor_in;}if(
zdd4e44469c7ba977522b67d97628ca58){z21fed86397a19bfad54bda2cfdaa9d19=
z8e73b2fdd2f29a123bf8d802578b41f1;}else{z21fed86397a19bfad54bda2cfdaa9d19=0;}
z598fc83d17c7afbb99b61c2115312c40=(UInt32)(UInt16)(((UInt16)C__U32SATU32_SATu(
z21fed86397a19bfad54bda2cfdaa9d19,57344))+4096);if(TPM_RE002_FARSp_rMixtCylSp_in
>=((UInt16)z598fc83d17c7afbb99b61c2115312c40)){TPM_mfAirScvLimMaxIvsMdlTWC=(
UInt16)TPM_mfAirScvLimMaxAfrScv_MP;}else{TPM_mfAirScvLimMaxIvsMdlTWC=
TPM_mfAirScvUnLim_C;}TabIdxS50T513((const UInt16*)TPM_rMixtCyl_mEgCmbMol_A,8,
TPM_RE002_FARSp_rMixtCylSp_in,&(ze374164a558733ef12261b5d878df60c),&(
za8ffccb29850928b689e7bb7dacb5dd2));TPM_mEgCmbMol=Tab1DIntp2I1T64((const UInt8*)
TPM_mEgCmbMol_T,ze374164a558733ef12261b5d878df60c,
za8ffccb29850928b689e7bb7dacb5dd2);TabIdxS50T513((const UInt16*)
TPM_tTWCconcO2EgTotLimMax_A,8,z06e9c80106c61f0fa8272b129cf851cd,&(
z37b0b5f9350985dbdecd85a5f023e77e),&(z508dd42316116c91160501d8dd9fa558));
TabIdxS50T513((const UInt16*)TPM_rMixtconcO2EgTotLimMax_A,8,
TPM_RE002_FARSp_rMixtCylSp_in,&(zf569b8ac6a053fdff6ae7e9db2af8b35),&(
za7653f54f9cd8888a3dac4944a04dee9));TPM_concO2EgTotLimMaxReq=Tab2DIntp2I1T33280(
(const UInt8*)&(TPM_concO2EgTotLimMax_M[0][0]),8,
z37b0b5f9350985dbdecd85a5f023e77e,z508dd42316116c91160501d8dd9fa558,
zf569b8ac6a053fdff6ae7e9db2af8b35,za7653f54f9cd8888a3dac4944a04dee9);
z06f32ff761b03af45c9f63ba6e33e8d9=((SInt32)TPM_mEgCmbMol)*((SInt32)(SInt16)(((
UInt16)TPM_concO2Air_C)-((UInt16)TPM_concO2EgTotLimMaxReq)));
TPM_fac1AirMfScvLimMax_MP=C__U16SATI32_SATb(z06f32ff761b03af45c9f63ba6e33e8d9,
53248,0);z21fed86397a19bfad54bda2cfdaa9d19=((UInt32)(((UInt32)
TPM_RE002_EngM_mfAirCor_in)<<2))+((((UInt32)TPM_RE002_EngM_mfAirCor_in)*((UInt32
)TPM_RE002_FARSp_rMixtCylSp_in))/TPM_facStoichGsl_C);TabIdxS50T513((const UInt16
*)TPM_nEngconcO2EgCmb_A,8,TPM_RE002_Ext_nEng_in,&(
za02ab45d7184a5969785fdb1e3c56a57),&(zee453e997508959edc8e61ecc7f1ff1b));
TabIdxS50T513((const UInt16*)TPM_rAirLdCorconcO2EgCmb_A,8,
TPM_RE002_EngM_rAirLdCor_in,&(zeccd7b4a5eee45178daebe27fbc25ae7),&(
z31e3951fa8e12e0341d264dcf91bdd3c));z6db6b90ed3d73ee7f9530cafd9c4abcd=
Tab2DIntp2I1T33280((const UInt8*)&(TPM_concO2EgCmb_M[0][0]),8,
za02ab45d7184a5969785fdb1e3c56a57,zee453e997508959edc8e61ecc7f1ff1b,
zeccd7b4a5eee45178daebe27fbc25ae7,z31e3951fa8e12e0341d264dcf91bdd3c);
TabIdxS50T513((const UInt16*)TPM_rMixtconcO2EgCmb_A,8,
TPM_RE002_FARSp_rMixtCylSp_in,&(z4bd435887ee597dd0985584449435063),&(
z012b6c1ae8d05b5af762ff999f5382f6));z96ed6e831041becc81a67c49f2955f72=
Tab1DIntp2I1T64((const UInt8*)TPM_facconcO2EgCmbCor_T,
z4bd435887ee597dd0985584449435063,z012b6c1ae8d05b5af762ff999f5382f6);
TPM_concO2EgCmb=((UInt16)z6db6b90ed3d73ee7f9530cafd9c4abcd)*((UInt16)
z96ed6e831041becc81a67c49f2955f72);z06f32ff761b03af45c9f63ba6e33e8d9=(((SInt32)
TPM_mAirMol_C)*((SInt32)(((UInt32)TPM_concO2EgCmb)-((UInt32)(SInt32)(((UInt32)
TPM_concO2EgTotLimMaxReq)<<6)))))+((SInt32)((((SInt32)(SInt16)(((UInt16)
TPM_concO2Air_C)-((UInt16)TPM_concO2EgTotLimMaxReq)))*((SInt32)TPM_mEgCmbMol))<<
6));F__I64MULU32I32(z21fed86397a19bfad54bda2cfdaa9d19,
z06f32ff761b03af45c9f63ba6e33e8d9,&(z91d6bd6fb6e014158f04ff5ae654b748),&(
ze7aaa232278aa4bfdf744ffb64ef0932));z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(
C__I32SHRI64C6_LT32(z91d6bd6fb6e014158f04ff5ae654b748,
ze7aaa232278aa4bfdf744ffb64ef0932,25,7)<<9);TPM_fac2AirMfScvLimMax_MP=
C__U32SATI32_SATb(z06f32ff761b03af45c9f63ba6e33e8d9,1992294,0);F__I64MULU32U32(
TPM_fac2AirMfScvLimMax_MP,TPM_fac2AirMfScvLimMax_MP,&(
z06f32ff761b03af45c9f63ba6e33e8d9),&(ze7aaa232278aa4bfdf744ffb64ef0932));
F__U64MULU32U32(z21fed86397a19bfad54bda2cfdaa9d19,
z21fed86397a19bfad54bda2cfdaa9d19,&(z73d2b71b576f4a88f55f370afa9fe86f),&(
za4b585c36c9215a2cb2eccf272d20fd4));z21fed86397a19bfad54bda2cfdaa9d19=
C__U32SHRU64C6_LT32(z73d2b71b576f4a88f55f370afa9fe86f,
za4b585c36c9215a2cb2eccf272d20fd4,18,14)*((UInt32)TPM_mAirMol_C);
z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)(((UInt32)TPM_concO2EgCmb)-((UInt32)(
SInt32)(((UInt32)TPM_concO2EgTotLimMaxReq)<<6)));F__I64MULU32I32(
z21fed86397a19bfad54bda2cfdaa9d19,z91d6bd6fb6e014158f04ff5ae654b748,&(
zda1f01f865fd1b51e129ca10fa784b66),&(z73d2b71b576f4a88f55f370afa9fe86f));
z91d6bd6fb6e014158f04ff5ae654b748=C__I32SHRI64C6_LT32(
zda1f01f865fd1b51e129ca10fa784b66,z73d2b71b576f4a88f55f370afa9fe86f,18,14);
TPM_fac3AirMfScvLimMax_MP=C__I32SATI32_SATb(z91d6bd6fb6e014158f04ff5ae654b748,
5976,-29150);zc2a33c76c54cadd7cb8ed332b9214311=(SInt32)(((UInt32)
C__I32SHRI64C6_LT32(z06f32ff761b03af45c9f63ba6e33e8d9,
ze7aaa232278aa4bfdf744ffb64ef0932,26,6))-((UInt32)(SInt32)((((SInt32)(SInt16)(
TPM_fac3AirMfScvLimMax_MP>>1))*((SInt32)TPM_fac1AirMfScvLimMax_MP))>>13)));
TabIdxS50T514((const UInt32*)TPM_facSqrtAirMfScvLimMax_A,29,(UInt32)
zc2a33c76c54cadd7cb8ed332b9214311,&(z17658853cd0a1cc88ce15854dbe6d420),&(
z86806c86fa3a8cd4cd71deb332465b1c));z5b9fc97212290211de831a6b5c996265=
Tab1DIntp2I1T66((const UInt32*)TPM_facSqrtAirMfScvLimMax_T,
z17658853cd0a1cc88ce15854dbe6d420,z86806c86fa3a8cd4cd71deb332465b1c);
zdd4e44469c7ba977522b67d97628ca58=TPM_fac1AirMfScvLimMax_MP!=0;if(
zdd4e44469c7ba977522b67d97628ca58){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((
UInt32)(SInt32)(z5b9fc97212290211de831a6b5c996265<<5))-TPM_fac2AirMfScvLimMax_MP
);C__I64SHLI32C6_LT32(z06f32ff761b03af45c9f63ba6e33e8d9,7,25,
z91d6bd6fb6e014158f04ff5ae654b748,z21fed86397a19bfad54bda2cfdaa9d19);
C__I32DIVI64U32(z91d6bd6fb6e014158f04ff5ae654b748,
z21fed86397a19bfad54bda2cfdaa9d19,(UInt32)TPM_fac1AirMfScvLimMax_MP,
zf3208f619f38c5866e55f1d8b64b45b9);}if(TPM_fac1AirMfScvLimMax_MP!=0){if(
zdd4e44469c7ba977522b67d97628ca58){z06f32ff761b03af45c9f63ba6e33e8d9=
zf3208f619f38c5866e55f1d8b64b45b9;}else{z06f32ff761b03af45c9f63ba6e33e8d9=0;}
TPM_mfAirScvLimMaxConcO2lim=C__U16FITI32_SAT(z06f32ff761b03af45c9f63ba6e33e8d9,
65535);}else{TPM_mfAirScvLimMaxConcO2lim=TPM_mfAirScvUnLim_C;}if(
TPM_RE002_ExM_stO2HcStgTWC_in==1){TPM_mfAirScvLimMaxHcLd=
TPM_mfAirScvLimMaxHcLdTWC_C;}else{TPM_mfAirScvLimMaxHcLd=TPM_mfAirScvUnLim_C;}if
(TPM_mfAirScvLimMaxIvsMdlTWC<TPM_mfAirScvLimMaxConcO2lim){
ze5aed13a5b01444f5678c6825a5c30fc=TPM_mfAirScvLimMaxIvsMdlTWC;}else{
ze5aed13a5b01444f5678c6825a5c30fc=TPM_mfAirScvLimMaxConcO2lim;}if(
TPM_mfAirScvLimMaxHcLd<ze5aed13a5b01444f5678c6825a5c30fc){
ze5aed13a5b01444f5678c6825a5c30fc=TPM_mfAirScvLimMaxHcLd;}if(
TPM_bSelMfAirScvLimMax_C){RE002_TPM_mfAirScvLimMax_out=TPM_mfSelMfAirScvLimMax_C
;}else{if(ze5aed13a5b01444f5678c6825a5c30fc){z0b07bfb92c95c708197ebf260276e235=
ze5aed13a5b01444f5678c6825a5c30fc;}else{z0b07bfb92c95c708197ebf260276e235=0;}if(
TPM_mfAirScvUnLim_C<z0b07bfb92c95c708197ebf260276e235){
RE002_TPM_mfAirScvLimMax_out=TPM_mfAirScvUnLim_C;}else{
RE002_TPM_mfAirScvLimMax_out=z0b07bfb92c95c708197ebf260276e235;}}if(
TPM_bSelRatMixtMaxAflScv_C){TPM_rMixtLimMaxAflScv_out=(UInt16)(UInt32)
TPM_rSelRatMixtMaxAflScv_C;}else{TPM_rMixtLimMaxAflScv_out=(UInt16)
z598fc83d17c7afbb99b61c2115312c40;}z4ec787e92236bb7748dc3a85bb031d1e=1;
zc68d065c4b4ff5330b7da46c9381734b=(UInt32)(zd468f45f7296e73fe1291d4b933ffed7<<4)
;z41fa3d5ce3398afab5c003e48c481674=1;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_003_TEV_fct(Void){UInt32 z7737fcbb8d606eb682f34548eb3e2908;UInt32 
z9bf5a95a0cde06e9951499086edce202;UInt32 zd15c0d58f0982c995c965ea77be8cc3e;
UInt32 z81494cf0f4b23e1650f2382322794e7f;UInt32 
z5cdc66b71fac542d12e3e97aa04a2112;UInt32 zec04e4a9ee5926e7bdb8e2ce4b1f8e8f;
UInt32 z9a5f9b298f4d00ad0706f1f6e999f60d;SInt32 
zc188eb4ff0a0879dce3165c5b4cbc186[7];SInt32 z0152ecffcd002eecf4395fb10518ac67[7]
;SInt32 zca0df17c4c83eed77d02965a271eaecf[7];SInt32 
z83f73e196f1abd67d8b996977b753686[7];SInt32 z9e3dc4675aa3b5f7027556b3424d0b01[7]
;SInt32 zd749de94135865b92808570b96074bee[7];SInt16 
z785b8ac15c48ec25b0fe340738a9f602[6];UInt16 zac40a68198d83fbd727ad9d1e3537de3[7]
;UInt16 zd7fcb8035aacf569cc5334590eba45a8[7];UInt8 
zef0f27452458924c39a72972774939e0[6];Boolean z2e5dca6b607d13605d1ce74156acc2f8;
Boolean zf61e6c561a27e803724384b4f76d04c0;Boolean 
z31e86dbddcf771dbd7e8b74f19c6f4e2;Boolean zdd4a636878d832efff2d29f82fac2282;
Boolean z9619584b965b4e31aa3549c39212f70a;Boolean 
za657b557242aec9ca59599685f5c686d;Boolean zb43eefb0d803d5c5b87a159a151194a8;
Boolean z5c37d1dfdd4449638b790854784f29c7;Boolean 
z9bea36c6ea632eb56f5f82e58c3c84ed;Boolean ze931c03f6e60eae45f91a495aec5436c;
Boolean z513d17c9a9287a224cb22b6eb0742c9e;Boolean 
z6240e9f1b64e5034365da171d02e16fd;Boolean z946e8f70bfdb07e6e4050c085bc23543;
Boolean z90efd7c73ed23dff5f6df3d33e2e76b7;Boolean 
z61802c5b363524d159c1c446717954a3;SInt32 zd468f45f7296e73fe1291d4b933ffed7;
SInt32 z06f32ff761b03af45c9f63ba6e33e8d9;SInt32 
z91d6bd6fb6e014158f04ff5ae654b748;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
SInt16 z083933e535293d75bb743b103b9f75c1;UInt16 
ze5aed13a5b01444f5678c6825a5c30fc;UInt16 z0b07bfb92c95c708197ebf260276e235;
UInt16 z269f16ec85c290b0c12845fa8679d3d3;UInt16 
zbbb13bd99f6808b124b13f2699cefcc9;UInt16 zd256c1c781273ba4b4c0d61231800328;
UInt16 zd906ea63a238a7925d2aeec41c3a31ba;UInt16 
z689d9d920555d9697e075e53154e7810;SInt16 z8a32e8d845d1f17c84c918e08dcfca18[7];
UInt8 z9fa28a9bfa43562a13245ecfa3963a8c;Boolean 
ze71c61f3b2a2b0f266072d3f488902ef;Boolean z503ce7914bcc31bb02dc4dbd6f9c3f43;
Boolean z9f69b105c811399c6c000a83fe6bac03;Boolean 
zb6d18d311a5ea5f88b4e4a0377548342;Boolean z535511cf2a529890828f5a8cdffcfdd5;
switch(Ext_noCylEng_SC){case 1:{zef0f27452458924c39a72972774939e0[0]=0;for(
zd468f45f7296e73fe1291d4b933ffed7=1;zd468f45f7296e73fe1291d4b933ffed7<=5;(
zd468f45f7296e73fe1291d4b933ffed7)++){zef0f27452458924c39a72972774939e0[
zd468f45f7296e73fe1291d4b933ffed7]=160;}break;}case 2:{
zef0f27452458924c39a72972774939e0[0]=0;zef0f27452458924c39a72972774939e0[1]=0;
zef0f27452458924c39a72972774939e0[2]=160;zef0f27452458924c39a72972774939e0[3]=
160;zef0f27452458924c39a72972774939e0[4]=160;zef0f27452458924c39a72972774939e0[5
]=160;break;}case 3:{zef0f27452458924c39a72972774939e0[0]=0;
zef0f27452458924c39a72972774939e0[1]=0;zef0f27452458924c39a72972774939e0[2]=0;
zef0f27452458924c39a72972774939e0[3]=160;zef0f27452458924c39a72972774939e0[4]=
160;zef0f27452458924c39a72972774939e0[5]=160;break;}case 4:{
zef0f27452458924c39a72972774939e0[0]=0;zef0f27452458924c39a72972774939e0[1]=0;
zef0f27452458924c39a72972774939e0[2]=0;zef0f27452458924c39a72972774939e0[3]=0;
zef0f27452458924c39a72972774939e0[4]=160;zef0f27452458924c39a72972774939e0[5]=
160;break;}case 5:{for(zd468f45f7296e73fe1291d4b933ffed7=0;
zd468f45f7296e73fe1291d4b933ffed7<=4;(zd468f45f7296e73fe1291d4b933ffed7)++){
zef0f27452458924c39a72972774939e0[zd468f45f7296e73fe1291d4b933ffed7]=0;}
zef0f27452458924c39a72972774939e0[5]=160;break;}case 6:{for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=5;(
zd468f45f7296e73fe1291d4b933ffed7)++){zef0f27452458924c39a72972774939e0[
zd468f45f7296e73fe1291d4b933ffed7]=0;}break;}default:{}}for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=5;(
zd468f45f7296e73fe1291d4b933ffed7)++){z785b8ac15c48ec25b0fe340738a9f602[
zd468f45f7296e73fe1291d4b933ffed7]=(SInt16)(((UInt16)(SInt16)(((UInt16)
TPM_RE003_IgSys_prm_agIgSpCyl_in[zd468f45f7296e73fe1291d4b933ffed7])+((UInt16)
zef0f27452458924c39a72972774939e0[zd468f45f7296e73fe1291d4b933ffed7])))-96);}if(
TPM_bAcvNotAgIgMin_C){SInt16 z481820d7d94655deff64e055e9fc8f29[6];for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=5;(
zd468f45f7296e73fe1291d4b933ffed7)++){if(z785b8ac15c48ec25b0fe340738a9f602[
zd468f45f7296e73fe1291d4b933ffed7]>-96){z481820d7d94655deff64e055e9fc8f29[
zd468f45f7296e73fe1291d4b933ffed7]=z785b8ac15c48ec25b0fe340738a9f602[
zd468f45f7296e73fe1291d4b933ffed7];}else{z481820d7d94655deff64e055e9fc8f29[
zd468f45f7296e73fe1291d4b933ffed7]=-96;}if(160<z481820d7d94655deff64e055e9fc8f29
[zd468f45f7296e73fe1291d4b933ffed7]){TPM_prm_agIgKnkSatMax_MP[
zd468f45f7296e73fe1291d4b933ffed7]=160;}else{TPM_prm_agIgKnkSatMax_MP[
zd468f45f7296e73fe1291d4b933ffed7]=z481820d7d94655deff64e055e9fc8f29[
zd468f45f7296e73fe1291d4b933ffed7];}}z083933e535293d75bb743b103b9f75c1=32767;for
(zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=5;(
zd468f45f7296e73fe1291d4b933ffed7)++){if(TPM_prm_agIgKnkSatMax_MP[
zd468f45f7296e73fe1291d4b933ffed7]<z083933e535293d75bb743b103b9f75c1){
z083933e535293d75bb743b103b9f75c1=TPM_prm_agIgKnkSatMax_MP[
zd468f45f7296e73fe1291d4b933ffed7];}}TPM_bNotAgIgMin=
z083933e535293d75bb743b103b9f75c1>=((SInt16)(((UInt16)(SInt16)(((UInt16)
TPM_RE003_IgSys_agIgMinThermo_in)+TPM_agIgMinThermoOfs_C))-96));}else{
TPM_bNotAgIgMin=1;}TPM_bRichLimScvCor=TPM_RE003_TPM_bRichLimScv_in&&
TPM_bAcvRichLimScv_C;TPM_bRichScvThermoInvldCor=
TPM_RE003_FARSp_bRichScvThermoInvld_in&&TPM_bAcvRichScvThermoInvld_C;
TPM_bThermoProtReqNotAuth=TPM_RE003_FARSp_bThermoProtReqNotAuth_in&&
TPM_bAcvTPReqNotAuth_C;zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)(((
UInt32)TPM_tiSdlTPM_C)<<12))/125);z0152ecffcd002eecf4395fb10518ac67[0]=(SInt32)(
(((UInt32)zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncDev1_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[1]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncDev2_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[2]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncDev3_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[3]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncDev4_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[4]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncTWC3_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[5]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncTWC2_C)>>1);
z0152ecffcd002eecf4395fb10518ac67[6]=(SInt32)((((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)*TPM_facRampIncTWC1_C)>>1);
z9f69b105c811399c6c000a83fe6bac03=ze119367927442a24e168287dc42c1419;if(
z9f69b105c811399c6c000a83fe6bac03){zac40a68198d83fbd727ad9d1e3537de3[0]=
TPM_tDeltaLamDev1_C;zac40a68198d83fbd727ad9d1e3537de3[1]=TPM_tDeltaLamDev2_C;
zac40a68198d83fbd727ad9d1e3537de3[2]=TPM_tDeltaLamDev3_C;
zac40a68198d83fbd727ad9d1e3537de3[3]=TPM_tDeltaLamDev4_C;
zac40a68198d83fbd727ad9d1e3537de3[4]=TPM_tDeltaLamTWC3_C;
zac40a68198d83fbd727ad9d1e3537de3[5]=TPM_tDeltaLamTWC2_C;
zac40a68198d83fbd727ad9d1e3537de3[6]=TPM_tDeltaLamTWC1_C;}else{for(
z06f32ff761b03af45c9f63ba6e33e8d9=0;z06f32ff761b03af45c9f63ba6e33e8d9<=6;(
z06f32ff761b03af45c9f63ba6e33e8d9)++){zac40a68198d83fbd727ad9d1e3537de3[
z06f32ff761b03af45c9f63ba6e33e8d9]=0;}}if(z72ce00e110723d4a019c24fc1e43f290){for
(z06f32ff761b03af45c9f63ba6e33e8d9=0;z06f32ff761b03af45c9f63ba6e33e8d9<=6;(
z06f32ff761b03af45c9f63ba6e33e8d9)++){zd749de94135865b92808570b96074bee[
z06f32ff761b03af45c9f63ba6e33e8d9]=(SInt32)zcf3ccb84663209a35029d94badab9f54[
z06f32ff761b03af45c9f63ba6e33e8d9];}}else{for(z06f32ff761b03af45c9f63ba6e33e8d9=
0;z06f32ff761b03af45c9f63ba6e33e8d9<=6;(z06f32ff761b03af45c9f63ba6e33e8d9)++){
zd749de94135865b92808570b96074bee[z06f32ff761b03af45c9f63ba6e33e8d9]=0;}}for(
z06f32ff761b03af45c9f63ba6e33e8d9=0;z06f32ff761b03af45c9f63ba6e33e8d9<=6;(
z06f32ff761b03af45c9f63ba6e33e8d9)++){z83f73e196f1abd67d8b996977b753686[
z06f32ff761b03af45c9f63ba6e33e8d9]=(SInt32)(((UInt32)(SInt32)(((UInt32)
zac40a68198d83fbd727ad9d1e3537de3[z06f32ff761b03af45c9f63ba6e33e8d9])<<16))-((
UInt32)zd749de94135865b92808570b96074bee[z06f32ff761b03af45c9f63ba6e33e8d9]));}
zc188eb4ff0a0879dce3165c5b4cbc186[0]=-((SInt32)TPM_facRampDecDev1_C);
zc188eb4ff0a0879dce3165c5b4cbc186[1]=-((SInt32)TPM_facRampDecDev2_C);
zc188eb4ff0a0879dce3165c5b4cbc186[2]=-((SInt32)TPM_facRampDecDev3_C);
zc188eb4ff0a0879dce3165c5b4cbc186[3]=-((SInt32)TPM_facRampDecDev4_C);
zc188eb4ff0a0879dce3165c5b4cbc186[4]=-((SInt32)TPM_facRampDecTWC3_C);
zc188eb4ff0a0879dce3165c5b4cbc186[5]=-((SInt32)TPM_facRampDecTWC2_C);
zc188eb4ff0a0879dce3165c5b4cbc186[6]=-((SInt32)TPM_facRampDecTWC1_C);for(
z06f32ff761b03af45c9f63ba6e33e8d9=0;z06f32ff761b03af45c9f63ba6e33e8d9<=6;(
z06f32ff761b03af45c9f63ba6e33e8d9)++){F__I64MULI32I32(
zd468f45f7296e73fe1291d4b933ffed7,zc188eb4ff0a0879dce3165c5b4cbc186[
z06f32ff761b03af45c9f63ba6e33e8d9],&(z91d6bd6fb6e014158f04ff5ae654b748),&(
z21fed86397a19bfad54bda2cfdaa9d19));zca0df17c4c83eed77d02965a271eaecf[
z06f32ff761b03af45c9f63ba6e33e8d9]=C__I32SHRI64C6_LT32(
z91d6bd6fb6e014158f04ff5ae654b748,z21fed86397a19bfad54bda2cfdaa9d19,1,31);}if(!(
z9f69b105c811399c6c000a83fe6bac03&&(!(z9faaf4a97ab42e03fb785b9bf34265a6)))){
SInt32 z199569d2cef2dab371b58e7490b721e0[7];SInt32 
z923abe0ef4ebd3af673b306497aae8df[7];SInt32 z57a98adcceb4a34f081e5d89abf97a04[7]
;for(zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){if(z83f73e196f1abd67d8b996977b753686[
zd468f45f7296e73fe1291d4b933ffed7]>zca0df17c4c83eed77d02965a271eaecf[
zd468f45f7296e73fe1291d4b933ffed7]){z923abe0ef4ebd3af673b306497aae8df[
zd468f45f7296e73fe1291d4b933ffed7]=z83f73e196f1abd67d8b996977b753686[
zd468f45f7296e73fe1291d4b933ffed7];}else{z923abe0ef4ebd3af673b306497aae8df[
zd468f45f7296e73fe1291d4b933ffed7]=zca0df17c4c83eed77d02965a271eaecf[
zd468f45f7296e73fe1291d4b933ffed7];}if(z0152ecffcd002eecf4395fb10518ac67[
zd468f45f7296e73fe1291d4b933ffed7]<z923abe0ef4ebd3af673b306497aae8df[
zd468f45f7296e73fe1291d4b933ffed7]){z57a98adcceb4a34f081e5d89abf97a04[
zd468f45f7296e73fe1291d4b933ffed7]=z0152ecffcd002eecf4395fb10518ac67[
zd468f45f7296e73fe1291d4b933ffed7];}else{z57a98adcceb4a34f081e5d89abf97a04[
zd468f45f7296e73fe1291d4b933ffed7]=z923abe0ef4ebd3af673b306497aae8df[
zd468f45f7296e73fe1291d4b933ffed7];}z199569d2cef2dab371b58e7490b721e0[
zd468f45f7296e73fe1291d4b933ffed7]=z57a98adcceb4a34f081e5d89abf97a04[
zd468f45f7296e73fe1291d4b933ffed7]+zd749de94135865b92808570b96074bee[
zd468f45f7296e73fe1291d4b933ffed7];if((z57a98adcceb4a34f081e5d89abf97a04[
zd468f45f7296e73fe1291d4b933ffed7]>=0)&&(zd749de94135865b92808570b96074bee[
zd468f45f7296e73fe1291d4b933ffed7]>=0)&&(z199569d2cef2dab371b58e7490b721e0[
zd468f45f7296e73fe1291d4b933ffed7]<0)){z199569d2cef2dab371b58e7490b721e0[
zd468f45f7296e73fe1291d4b933ffed7]=2147483647;}else{if((
z57a98adcceb4a34f081e5d89abf97a04[zd468f45f7296e73fe1291d4b933ffed7]<0)&&(
zd749de94135865b92808570b96074bee[zd468f45f7296e73fe1291d4b933ffed7]<0)&&(
z199569d2cef2dab371b58e7490b721e0[zd468f45f7296e73fe1291d4b933ffed7]>=0)){
z199569d2cef2dab371b58e7490b721e0[zd468f45f7296e73fe1291d4b933ffed7]=(-
2147483647L-1L);}}z9e3dc4675aa3b5f7027556b3424d0b01[
zd468f45f7296e73fe1291d4b933ffed7]=z199569d2cef2dab371b58e7490b721e0[
zd468f45f7296e73fe1291d4b933ffed7];}}else{for(zd468f45f7296e73fe1291d4b933ffed7=
0;zd468f45f7296e73fe1291d4b933ffed7<=6;(zd468f45f7296e73fe1291d4b933ffed7)++){
z9e3dc4675aa3b5f7027556b3424d0b01[zd468f45f7296e73fe1291d4b933ffed7]=0;}}for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){z083933e535293d75bb743b103b9f75c1=(SInt16)
(z9e3dc4675aa3b5f7027556b3424d0b01[zd468f45f7296e73fe1291d4b933ffed7]>>16);if(
z083933e535293d75bb743b103b9f75c1>0){z8a32e8d845d1f17c84c918e08dcfca18[
zd468f45f7296e73fe1291d4b933ffed7]=(SInt16)(SInt32)
z083933e535293d75bb743b103b9f75c1;}else{z8a32e8d845d1f17c84c918e08dcfca18[
zd468f45f7296e73fe1291d4b933ffed7]=(SInt16)0;}if(16000<
z8a32e8d845d1f17c84c918e08dcfca18[zd468f45f7296e73fe1291d4b933ffed7]){
zd7fcb8035aacf569cc5334590eba45a8[zd468f45f7296e73fe1291d4b933ffed7]=16000;}else
{zd7fcb8035aacf569cc5334590eba45a8[zd468f45f7296e73fe1291d4b933ffed7]=(UInt16)
z8a32e8d845d1f17c84c918e08dcfca18[zd468f45f7296e73fe1291d4b933ffed7];}}
TPM_tDeltaLamDev2Tar=zd7fcb8035aacf569cc5334590eba45a8[1];if(
TPM_bSelTWallCritDev2_C){TPM_tDev2=(UInt16)(TPM_RE003_PhyMSI_tExMnfEstim_in+
58400);}else{if(TPM_bSelTWallDev2_C){TPM_tDev2=TPM_RE003_ExM_prm_tWall_in[(UInt8
)(SInt16)(UInt8)(TPM_idxSelTWallDev2_C-1)];}else{TPM_tDev2=
TPM_RE003_ExM_prm_tEg_in[(UInt8)(SInt16)(UInt8)(TPM_idxSelTEgDev2_C-1)];}}if(
TPM_RE003_DmgMSI_bMPMInh_in){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev2Step3_C;}else{if(TPM_RE003_DmgMSI_bLdLimReq_in){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev2Step2_C;}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev2_C;}}
zb6d18d311a5ea5f88b4e4a0377548342=((TPM_bAcvR1234Mg_C&&
TPM_RE003_ThMgt_bAcvR1234Mgt_in)||TPM_RE003_FRM_bAcvEcpHeatProt_in)&&(!(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in));if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvDev2EcpHeatProt_C){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)((
(UInt32)z06f32ff761b03af45c9f63ba6e33e8d9)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{zd468f45f7296e73fe1291d4b933ffed7=z06f32ff761b03af45c9f63ba6e33e8d9;}
TPM_tMaxDev2=C__U32SATI32_SATl(zd468f45f7296e73fe1291d4b933ffed7,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxDev2Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxDev2TmpAirLd_C;TPM_tiTMaxDevTmpAirLd_C_in
=TPM_tiTMaxDev2ThermoProt_C;TPM_tiTMaxDevTmp_C_in=TPM_tiTMaxDev2Tmp_C;DevTPM((
UInt32)(((UInt32)TPM_tDev2)+7136),TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxDev2
,TPM_bNotAgIgMin,TPM_bThermoProtReqNotAuth,TPM_tDeltaLamDev2Tar,
TPM_tMaxDeltaHysAirLdLim_C,TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdDev2Tmp_C,&(
z9bf5a95a0cde06e9951499086edce202),&(TPM_bRichDev2),&(
zf61e6c561a27e803724384b4f76d04c0),&(TPM_tExDev2Delta),&(
z9bea36c6ea632eb56f5f82e58c3c84ed),&(TPM_tExDev2Delta_MP),&(
TPM_bAcvTMaxRichDev2_MP),&(TPM_bTMaxDeltaHysRichDev2_MP),&(
z61802c5b363524d159c1c446717954a3),&(TPM_bAcvDsTmpTMaxRichDev2_MP),&(
TPM_bAirLdLimDev2UsTmp_MP),&(z15befb9620efcd0b4ec01fca8fbe34e1),
TPM_bRichLimScvCor);TPM_tDeltaLamTWC1Tar=zd7fcb8035aacf569cc5334590eba45a8[6];if
(TPM_bSelTWallTWC1_C){TPM_tTWC1=TPM_RE003_ExM_prm_tWall_in[(UInt8)(SInt16)(UInt8
)(TPM_idxSelTWallTWC1_C-1)];}else{TPM_tTWC1=TPM_RE003_ExM_prm_tEg_in[(UInt8)(
SInt16)(UInt8)(TPM_idxSelTEgTWC1_C-1)];}if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvTWC1EcpHeatProt_C){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(
TPM_tMaxTWC1_C-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxTWC1_C;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)((
(UInt32)zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxTWC1=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxTWC1Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxTWC1ThermoProt_C;
TPM_tiTMaxDevTmpAirLd_C_in=TPM_tiTMaxTWC1TmpAirLd_C;TPM_tiTMaxDevTmp_C_in=
TPM_tiTMaxTWC1Tmp_C;DevTPM((UInt32)(((UInt32)TPM_tTWC1)+7136),
TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxTWC1,TPM_bNotAgIgMin,
TPM_bThermoProtReqNotAuth,TPM_tDeltaLamTWC1Tar,TPM_tMaxDeltaHysAirLdLim_C,
TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdTWC1Tmp_C,&(
z9a5f9b298f4d00ad0706f1f6e999f60d),&(TPM_bRichTWC1),&(
zb43eefb0d803d5c5b87a159a151194a8),&(TPM_tExTWC1Delta),&(
z90efd7c73ed23dff5f6df3d33e2e76b7),&(TPM_tTWC1Delta_MP),&(
TPM_bAcvTMaxRichTWC1_MP),&(TPM_bTMaxDeltaHysRichTWC1_MP),&(
TPM_bTMaxRAirLdLimTWC1_MP),&(TPM_bAcvDsTmpTMaxRichTWC1_MP),&(
TPM_bAirLdLimTWC1UsTmp_MP),&(za44d00fffc2f28b5684d46d9e66f06b6),
TPM_bRichLimScvCor);TPM_tDeltaLamTWC2Tar=zd7fcb8035aacf569cc5334590eba45a8[5];if
(TPM_bSelTWallTWC2_C){TPM_tTWC2=TPM_RE003_ExM_prm_tWall_in[(UInt8)(SInt16)(UInt8
)(TPM_idxSelTWallTWC2_C-1)];}else{TPM_tTWC2=TPM_RE003_ExM_prm_tEg_in[(UInt8)(
SInt16)(UInt8)(TPM_idxSelTEgTWC2_C-1)];}if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvTWC2EcpHeatProt_C){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(
TPM_tMaxTWC2_C-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxTWC2_C;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)((
(UInt32)zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxTWC2=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxTWC2Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxTWC2ThermoProt_C;
TPM_tiTMaxDevTmpAirLd_C_in=TPM_tiTMaxTWC2TmpAirLd_C;TPM_tiTMaxDevTmp_C_in=
TPM_tiTMaxTWC2Tmp_C;DevTPM((UInt32)(((UInt32)TPM_tTWC2)+7136),
TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxTWC2,TPM_bNotAgIgMin,
TPM_bThermoProtReqNotAuth,TPM_tDeltaLamTWC2Tar,TPM_tMaxDeltaHysAirLdLim_C,
TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdTWC2Tmp_C,&(
zec04e4a9ee5926e7bdb8e2ce4b1f8e8f),&(TPM_bRichTWC2),&(
za657b557242aec9ca59599685f5c686d),&(TPM_tExTWC2Delta),&(
z946e8f70bfdb07e6e4050c085bc23543),&(TPM_tTWC2Delta_MP),&(
TPM_bAcvTMaxRichTWC2_MP),&(TPM_bTMaxDeltaHysRichTWC2_MP),&(
TPM_bTMaxRAirLdLimTWC2_MP),&(TPM_bAcvDsTmpTMaxRichTWC2_MP),&(
TPM_bAirLdLimTWC2UsTmp_MP),&(zfa2f99f2a2ccc50c31415022f1f5f138),
TPM_bRichLimScvCor);TPM_tDeltaLamTWC3Tar=zd7fcb8035aacf569cc5334590eba45a8[4];if
(TPM_bSelTWallTWC3_C){TPM_tTWC3=TPM_RE003_ExM_prm_tWall_in[(UInt8)(SInt16)(UInt8
)(TPM_idxSelTWallTWC3_C-1)];}else{TPM_tTWC3=TPM_RE003_ExM_prm_tEg_in[(UInt8)(
SInt16)(UInt8)(TPM_idxSelTEgTWC3_C-1)];}if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvTWC3EcpHeatProt_C){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(
TPM_tMaxTWC3_C-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxTWC3_C;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)((
(UInt32)zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxTWC3=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxTWC3Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxTWC3ThermoProt_C;
TPM_tiTMaxDevTmpAirLd_C_in=TPM_tiTMaxTWC3TmpAirLd_C;TPM_tiTMaxDevTmp_C_in=
TPM_tiTMaxTWC3Tmp_C;DevTPM((UInt32)(((UInt32)TPM_tTWC3)+7136),
TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxTWC3,TPM_bNotAgIgMin,
TPM_bThermoProtReqNotAuth,TPM_tDeltaLamTWC3Tar,TPM_tMaxDeltaHysAirLdLim_C,
TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdTWC3Tmp_C,&(
z5cdc66b71fac542d12e3e97aa04a2112),&(TPM_bRichTWC3),&(
z9619584b965b4e31aa3549c39212f70a),&(TPM_tExTWC3Delta),&(
z6240e9f1b64e5034365da171d02e16fd),&(TPM_tTWC3Delta_MP),&(
TPM_bAcvTMaxRichTWC3_MP),&(TPM_bTMaxDeltaHysRichTWC3_MP),&(
TPM_bTMaxRAirLdLimTWC3_MP),&(TPM_bAcvDsTmpTMaxRichTWC3_MP),&(
TPM_bAirLdLimTWC3UsTmp_MP),&(z85d72b3a21ad48f72bacac76d313f63c),
TPM_bRichLimScvCor);TPM_tDeltaLamDev1Tar=zd7fcb8035aacf569cc5334590eba45a8[0];if
(TPM_bSelTWallDev1_C){TPM_tDev1=TPM_RE003_ExM_prm_tWall_in[(UInt8)(SInt16)(UInt8
)(TPM_idxSelTWallDev1_C-1)];}else{TPM_tDev1=TPM_RE003_ExM_prm_tEg_in[(UInt8)(
SInt16)(UInt8)(TPM_idxSelTEgDev1_C-1)];}if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvDev1EcpHeatProt_C){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(
TPM_tMaxDev1_C-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev1_C;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)((
(UInt32)zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxDev1=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxDev1Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxDev1TmpAirLd_C;TPM_tiTMaxDevTmpAirLd_C_in
=TPM_tiTMaxDev1ThermoProt_C;TPM_tiTMaxDevTmp_C_in=TPM_tiTMaxDev1Tmp_C;DevTPM((
UInt32)(((UInt32)TPM_tDev1)+7136),TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxDev1
,TPM_bNotAgIgMin,TPM_bThermoProtReqNotAuth,TPM_tDeltaLamDev1Tar,
TPM_tMaxDeltaHysAirLdLim_C,TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdDev1Tmp_C,&(
z7737fcbb8d606eb682f34548eb3e2908),&(TPM_bRichDev1),&(
z2e5dca6b607d13605d1ce74156acc2f8),&(TPM_tExDev1Delta),&(
z5c37d1dfdd4449638b790854784f29c7),&(TPM_tExDev1Delta_MP),&(
TPM_bAcvTMaxRichDev1_MP),&(TPM_bTMaxDeltaHysRichDev1_MP),&(
TPM_bTMaxRAirLdLimDev1_MP),&(TPM_bAcvDsTmpTMaxRichDev1_MP),&(
TPM_bAirLdLimDev1UsTmp_MP),&(z2d8a6c86d69f4c6c1082bad2a59f66ab),
TPM_bRichLimScvCor);TPM_tDeltaLamDev4Tar=zd7fcb8035aacf569cc5334590eba45a8[3];if
(TPM_bSelTWallDev4_C){TPM_tDev4=TPM_RE003_ExM_prm_tWall_in[(UInt8)(SInt16)(UInt8
)(TPM_idxSelTWallDev4_C-1)];}else{TPM_tDev4=TPM_RE003_ExM_prm_tEg_in[(UInt8)(
SInt16)(UInt8)(TPM_idxSelTEgDev4_C-1)];}if(zb6d18d311a5ea5f88b4e4a0377548342&&
TPM_bAcvDev4EcpHeatProt_C){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(
TPM_tMaxDev4_C-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev4_C;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)((
(UInt32)zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxDev4=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxDev4Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxDev4ThermoProt_C;
TPM_tiTMaxDevTmpAirLd_C_in=TPM_tiTMaxDev4TmpAirLd_C;TPM_tiTMaxDevTmp_C_in=
TPM_tiTMaxDev4Tmp_C;DevTPM((UInt32)(((UInt32)TPM_tDev4)+7136),
TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxDev4,TPM_bNotAgIgMin,
TPM_bThermoProtReqNotAuth,TPM_tDeltaLamDev4Tar,TPM_tMaxDeltaHysAirLdLim_C,
TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdDev4Tmp_C,&(
z81494cf0f4b23e1650f2382322794e7f),&(TPM_bRichDev4),&(
zdd4a636878d832efff2d29f82fac2282),&(TPM_tExDev4Delta),&(
z513d17c9a9287a224cb22b6eb0742c9e),&(TPM_tExDev4Delta_MP),&(
TPM_bAcvTMaxRichDev4_MP),&(TPM_bTMaxDeltaHysRichDev4_MP),&(
TPM_bTMaxRAirLdLimDev4_MP),&(TPM_bAcvDsTmpTMaxRichDev4_MP),&(
TPM_bAirLdLimDev4UsTmp_MP),&(zd5a90cac76f6404e94334badc803b2be),
TPM_bRichLimScvCor);TPM_tDeltaLamDev3Tar=zd7fcb8035aacf569cc5334590eba45a8[2];if
(TPM_bSelTWallCritDev3_C){TPM_tDev3=(UInt16)(TPM_RE003_PhyMSI_tTrbCaseEstim_in+
58400);}else{if(TPM_bSelTWallDev3_C){TPM_tDev3=TPM_RE003_ExM_prm_tWall_in[(UInt8
)(SInt16)(UInt8)(TPM_idxSelTWallDev3_C-1)];}else{TPM_tDev3=
TPM_RE003_ExM_prm_tEg_in[(UInt8)(SInt16)(UInt8)(TPM_idxSelTEgDev3_C-1)];}}if(
TPM_RE003_DmgMSI_bMPMInh_in){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev3Step3_C;}else{if(TPM_RE003_DmgMSI_bLdLimReq_in){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev3Step2_C;}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxDev3_C;}}if(
zb6d18d311a5ea5f88b4e4a0377548342&&TPM_bAcvDev3EcpHeatProt_C){
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tEcpHeatProtDelta_C));}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}if(
TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)((
(UInt32)z06f32ff761b03af45c9f63ba6e33e8d9)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));
}else{zd468f45f7296e73fe1291d4b933ffed7=z06f32ff761b03af45c9f63ba6e33e8d9;}
TPM_tMaxDev3=C__U32SATI32_SATl(zd468f45f7296e73fe1291d4b933ffed7,7136);
TPM_tMaxDeltaHys_in=TPM_tMaxDeltaHys_C;TPM_tMaxDevDelta_in=TPM_tMaxDev3Delta_C;
TPM_tiTMaxDevThermoProt_C_in=TPM_tiTMaxDev3ThermoProt_C;
TPM_tiTMaxDevTmpAirLd_C_in=TPM_tiTMaxDev3TmpAirLd_C;TPM_tiTMaxDevTmp_C_in=
TPM_tiTMaxDev3Tmp_C;DevTPM((UInt32)(((UInt32)TPM_tDev3)+7136),
TPM_RE003_FARSp_bSatMaxRatMixt_in,TPM_tMaxDev3,TPM_bNotAgIgMin,
TPM_bThermoProtReqNotAuth,TPM_tDeltaLamDev3Tar,TPM_tMaxDeltaHysAirLdLim_C,
TPM_bRichScvThermoInvldCor,TPM_bAcvAirLdDev3Tmp_C,&(
zd15c0d58f0982c995c965ea77be8cc3e),&(TPM_bRichDev3),&(
z31e86dbddcf771dbd7e8b74f19c6f4e2),&(TPM_tExDev3Delta),&(
ze931c03f6e60eae45f91a495aec5436c),&(TPM_tExDev3Delta_MP),&(
TPM_bAcvTMaxRichDev3_MP),&(TPM_bTMaxDeltaHysRichDev3_MP),&(
TPM_bTMaxRAirLdLimDev3_MP),&(TPM_bAcvDsTmpTMaxRichDev3_MP),&(
TPM_bAirLdLimDev3UsTmp_MP),&(z40561b610ce58d69fd87e27e440660f5),
TPM_bRichLimScvCor);if(TPM_bSelTTWC_C){RE003_TPM_tTWC_out=TPM_tSelTTWC_C;}else{
if(TPM_bAcvTWC2_C){ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(TPM_tTWC2+7136);}
else{ze5aed13a5b01444f5678c6825a5c30fc=0;}if(TPM_bAcvTWC3_C){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(TPM_tTWC3+7136);}else{
z0b07bfb92c95c708197ebf260276e235=0;}z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(
((UInt32)TPM_tTWC1)+7136);if(z21fed86397a19bfad54bda2cfdaa9d19>((UInt32)
ze5aed13a5b01444f5678c6825a5c30fc)){z269f16ec85c290b0c12845fa8679d3d3=(UInt16)
z21fed86397a19bfad54bda2cfdaa9d19;}else{z269f16ec85c290b0c12845fa8679d3d3=
ze5aed13a5b01444f5678c6825a5c30fc;}if(z0b07bfb92c95c708197ebf260276e235>
z269f16ec85c290b0c12845fa8679d3d3){z269f16ec85c290b0c12845fa8679d3d3=
z0b07bfb92c95c708197ebf260276e235;}if(z269f16ec85c290b0c12845fa8679d3d3<7136){
RE003_TPM_tTWC_out=0;}else{RE003_TPM_tTWC_out=(UInt16)(
z269f16ec85c290b0c12845fa8679d3d3-7136);}}z535511cf2a529890828f5a8cdffcfdd5=
TPM_bRichDev1||TPM_bRichDev2||TPM_bRichDev3||TPM_bRichDev4||TPM_bRichTWC3||
TPM_bRichTWC2||TPM_bRichTWC1;if(TPM_bSelInhOvbReq_C){TPM_bInhOvbReq_out=
TPM_bInhSelInhOvbReq_C;}else{TPM_bInhOvbReq_out=
z535511cf2a529890828f5a8cdffcfdd5&&(TPM_RE003_FARSp_rMixtCylSp_in>
TPM_rMixtMaxInhOvb_C);}if(TPM_bSelExThermoProt_C){TPM_bExThermoProt_out=
TPM_bAcvSelExThermoProt_C;}else{TPM_bExThermoProtDev1=
z5c37d1dfdd4449638b790854784f29c7;TPM_bExThermoProtDev2=
z9bea36c6ea632eb56f5f82e58c3c84ed;TPM_bExThermoProtDev3=
ze931c03f6e60eae45f91a495aec5436c;TPM_bExThermoProtDev4=
z513d17c9a9287a224cb22b6eb0742c9e;TPM_bExThermoProtTWC3=
z6240e9f1b64e5034365da171d02e16fd;TPM_bExThermoProtTWC2=
z946e8f70bfdb07e6e4050c085bc23543;TPM_bExThermoProtTWC1=
z90efd7c73ed23dff5f6df3d33e2e76b7;TPM_bExThermoProt_out=TPM_bExThermoProtDev1||
TPM_bExThermoProtDev2||TPM_bExThermoProtDev3||TPM_bExThermoProtDev4||
TPM_bExThermoProtTWC3||TPM_bExThermoProtTWC2||TPM_bExThermoProtTWC1;}if(
zb6d18d311a5ea5f88b4e4a0377548342&&TPM_bTWC1StoichEcpHeatProt_C){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxStoichTWC1_C-((UInt32)
TPM_tEcpHeatProtDelta_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxStoichTWC1_C;}if(TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxStoichTWC1=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
ze71c61f3b2a2b0f266072d3f488902ef=((UInt32)(((UInt32)TPM_tTWC1)+7136))>=
TPM_tMaxStoichTWC1;if(ze71c61f3b2a2b0f266072d3f488902ef){
ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(z5789054cbcc0eb263da5fa3d1270a2cf+1);
}else{ze5aed13a5b01444f5678c6825a5c30fc=0;}z0b07bfb92c95c708197ebf260276e235=(
UInt16)(TPM_tiTMaxStoichTWC1Tmp_C/TPM_tiSdlTPM_C);if(
zb6d18d311a5ea5f88b4e4a0377548342&&TPM_bTWC2StoichEcpHeatProt_C){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxStoichTWC2_C-((UInt32)
TPM_tEcpHeatProtDelta_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxStoichTWC2_C;}if(TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxStoichTWC2=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
z503ce7914bcc31bb02dc4dbd6f9c3f43=((UInt32)(((UInt32)TPM_tTWC2)+7136))>=
TPM_tMaxStoichTWC2;if(z503ce7914bcc31bb02dc4dbd6f9c3f43){
z269f16ec85c290b0c12845fa8679d3d3=(UInt16)(z61f702e660fc002cae41748aa0a44af6+1);
}else{z269f16ec85c290b0c12845fa8679d3d3=0;}zbbb13bd99f6808b124b13f2699cefcc9=(
UInt16)(TPM_tiTMaxStoichTWC2Tmp_C/TPM_tiSdlTPM_C);if(
zb6d18d311a5ea5f88b4e4a0377548342&&TPM_bTWC3StoichEcpHeatProt_C){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxStoichTWC3_C-((UInt32)
TPM_tEcpHeatProtDelta_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxStoichTWC3_C;}if(TPM_RE003_FRM_bAcvTPMDecTMaxDev_in){
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{
z06f32ff761b03af45c9f63ba6e33e8d9=zd468f45f7296e73fe1291d4b933ffed7;}
TPM_tMaxStoichTWC3=C__U32SATI32_SATl(z06f32ff761b03af45c9f63ba6e33e8d9,7136);
zb6d18d311a5ea5f88b4e4a0377548342=((UInt32)(((UInt32)TPM_tTWC3)+7136))>=
TPM_tMaxStoichTWC3;if(zb6d18d311a5ea5f88b4e4a0377548342){
zd256c1c781273ba4b4c0d61231800328=(UInt16)(z0ac6bdc96f479a2298807f6007f6e575+1);
}else{zd256c1c781273ba4b4c0d61231800328=0;}zd906ea63a238a7925d2aeec41c3a31ba=(
UInt16)(TPM_tiTMaxStoichTWC3Tmp_C/TPM_tiSdlTPM_C);if(TPM_bSelAcvRichProtOxdTWC_C
){TPM_bAcvRichProtOxdTWC_out=TPM_bAcvSelRichProtOxdTWC_C;}else{
TPM_bAcvRichProtOxdTWC1T_MP=((SInt32)(((UInt32)TPM_tTWC1)+7136))>=((SInt32)(
TPM_tMaxStoichTWC1+((UInt32)TPM_tMaxStoichTWC1Delta_C)));
TPM_bAcvRichProtOxdTWC1_MP=ze71c61f3b2a2b0f266072d3f488902ef&&(
ze5aed13a5b01444f5678c6825a5c30fc>z0b07bfb92c95c708197ebf260276e235);
TPM_bAcvRichProtOxdTWC1=TPM_bAcvRichProtOxdTWC1T_MP||TPM_bAcvRichProtOxdTWC1_MP
||TPM_bRichTWC1;TPM_bAcvRichProtOxdTWC2T_MP=((SInt32)(((UInt32)TPM_tTWC2)+7136))
>=((SInt32)(TPM_tMaxStoichTWC2+((UInt32)TPM_tMaxStoichTWC2Delta_C)));
TPM_bAcvRichProtOxdTWC2_MP=z503ce7914bcc31bb02dc4dbd6f9c3f43&&(
z269f16ec85c290b0c12845fa8679d3d3>zbbb13bd99f6808b124b13f2699cefcc9);
TPM_bAcvRichProtOxdTWC2=(TPM_bAcvRichProtOxdTWC2T_MP||TPM_bAcvRichProtOxdTWC2_MP
||TPM_bRichTWC2)&&TPM_bAcvTWC2_C;TPM_bAcvRichProtOxdTWC3T_MP=((SInt32)(((UInt32)
TPM_tTWC3)+7136))>=((SInt32)(TPM_tMaxStoichTWC3+((UInt32)
TPM_tMaxStoichTWC3Delta_C)));TPM_bAcvRichProtOxdTWC3_MP=
zb6d18d311a5ea5f88b4e4a0377548342&&(zd256c1c781273ba4b4c0d61231800328>
zd906ea63a238a7925d2aeec41c3a31ba);TPM_bAcvRichProtOxdTWC3=(
TPM_bAcvRichProtOxdTWC3T_MP||TPM_bAcvRichProtOxdTWC3_MP||TPM_bRichTWC3)&&
TPM_bAcvTWC3_C;TPM_bAcvRichProtOxdTWC_out=TPM_bAcvRichProtOxdTWC1||
TPM_bAcvRichProtOxdTWC2||TPM_bAcvRichProtOxdTWC3;}if(TPM_tExDev1Delta>
TPM_tExDev2Delta){TPM_tDifMin_MP=TPM_tExDev1Delta;}else{TPM_tDifMin_MP=
TPM_tExDev2Delta;}if(TPM_tExDev3Delta>TPM_tDifMin_MP){TPM_tDifMin_MP=
TPM_tExDev3Delta;}if(TPM_tExDev4Delta>TPM_tDifMin_MP){TPM_tDifMin_MP=
TPM_tExDev4Delta;}if(TPM_tExTWC3Delta>TPM_tDifMin_MP){TPM_tDifMin_MP=
TPM_tExTWC3Delta;}if(TPM_tExTWC2Delta>TPM_tDifMin_MP){TPM_tDifMin_MP=
TPM_tExTWC2Delta;}if(TPM_tExTWC1Delta>TPM_tDifMin_MP){TPM_tDifMin_MP=
TPM_tExTWC1Delta;}if(-32000==TPM_tDifMin_MP){z9fa28a9bfa43562a13245ecfa3963a8c=0
;}else{UInt8 z764023faa138f38ff107d9e4721878f5;UInt8 
z651b6b77a646c0db2a6db198338cda33;UInt8 zacb85758001f3ec63717cf3a88bdd3bd;UInt8 
z5793fb425949203804adac2bb0e00286;UInt8 zeec326d3ded51429d48a1a117d4c5b01;UInt8 
z685b743ede36165f1c2c0383f53b147b;UInt8 z62482c2d08503efb3be86b190a415781;
zb6d18d311a5ea5f88b4e4a0377548342=TPM_tExDev1Delta==TPM_tDifMin_MP;if(
TPM_tExDev2Delta==TPM_tDifMin_MP){z764023faa138f38ff107d9e4721878f5=2;}else{
z764023faa138f38ff107d9e4721878f5=0;}if(TPM_tExDev3Delta==TPM_tDifMin_MP){
z651b6b77a646c0db2a6db198338cda33=3;}else{z651b6b77a646c0db2a6db198338cda33=0;}
if(TPM_tExDev4Delta==TPM_tDifMin_MP){zacb85758001f3ec63717cf3a88bdd3bd=4;}else{
zacb85758001f3ec63717cf3a88bdd3bd=0;}if(TPM_tExTWC3Delta==TPM_tDifMin_MP){
z5793fb425949203804adac2bb0e00286=5;}else{z5793fb425949203804adac2bb0e00286=0;}
if(TPM_tExTWC2Delta==TPM_tDifMin_MP){zeec326d3ded51429d48a1a117d4c5b01=6;}else{
zeec326d3ded51429d48a1a117d4c5b01=0;}if(TPM_tExTWC1Delta==TPM_tDifMin_MP){
z685b743ede36165f1c2c0383f53b147b=7;}else{z685b743ede36165f1c2c0383f53b147b=0;}
if(zb6d18d311a5ea5f88b4e4a0377548342>z764023faa138f38ff107d9e4721878f5){
z62482c2d08503efb3be86b190a415781=zb6d18d311a5ea5f88b4e4a0377548342;}else{
z62482c2d08503efb3be86b190a415781=z764023faa138f38ff107d9e4721878f5;}if(
z651b6b77a646c0db2a6db198338cda33>z62482c2d08503efb3be86b190a415781){
z62482c2d08503efb3be86b190a415781=z651b6b77a646c0db2a6db198338cda33;}if(
zacb85758001f3ec63717cf3a88bdd3bd>z62482c2d08503efb3be86b190a415781){
z62482c2d08503efb3be86b190a415781=zacb85758001f3ec63717cf3a88bdd3bd;}if(
z5793fb425949203804adac2bb0e00286>z62482c2d08503efb3be86b190a415781){
z62482c2d08503efb3be86b190a415781=z5793fb425949203804adac2bb0e00286;}if(
zeec326d3ded51429d48a1a117d4c5b01>z62482c2d08503efb3be86b190a415781){
z62482c2d08503efb3be86b190a415781=zeec326d3ded51429d48a1a117d4c5b01;}if(
z685b743ede36165f1c2c0383f53b147b>z62482c2d08503efb3be86b190a415781){
z62482c2d08503efb3be86b190a415781=z685b743ede36165f1c2c0383f53b147b;}
z9fa28a9bfa43562a13245ecfa3963a8c=z62482c2d08503efb3be86b190a415781;}if(
TPM_bSelTTarThermoProtDev_C){z689d9d920555d9697e075e53154e7810=
TPM_tSelTTarThermoProtDev_C;}else{switch(z9fa28a9bfa43562a13245ecfa3963a8c){case
 0:{zd468f45f7296e73fe1291d4b933ffed7=48736;break;}case 1:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev1;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxDev1-((
UInt32)TPM_tDeltaLamDev1Tar));}break;}case 2:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev2;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxDev2-((
UInt32)TPM_tDeltaLamDev2Tar));}break;}case 3:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev3;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxDev3-((
UInt32)TPM_tDeltaLamDev3Tar));}break;}case 4:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxDev4;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxDev4-((
UInt32)TPM_tDeltaLamDev4Tar));}break;}case 5:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxTWC3;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxTWC3-((
UInt32)TPM_tDeltaLamTWC3Tar));}break;}case 6:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxTWC2;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxTWC2-((
UInt32)TPM_tDeltaLamTWC2Tar));}break;}case 7:{if(
z2d07d203c34c561a8166fdae37c33bda){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tMaxTWC1;}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(TPM_tMaxTWC1-((
UInt32)TPM_tDeltaLamTWC1Tar));}break;}}z689d9d920555d9697e075e53154e7810=(UInt16
)(C__U16SATI32_SATb(zd468f45f7296e73fe1291d4b933ffed7,48736,7136)+58400);}
TPM_tTarAcvThermoProtDev_out=(UInt16)(z689d9d920555d9697e075e53154e7810+7136);if
(TPM_bSelAcvRichThermoProt_C){TPM_bAcvRichThermoProt_out=
TPM_bAcvSelRichThermoProt_C;}else{TPM_bAcvRichThermoProt_out=
z535511cf2a529890828f5a8cdffcfdd5;}if(TPM_bSelAirLdLimTExMgr_C){
zb6d18d311a5ea5f88b4e4a0377548342=TPM_bAcvSelAirLdLimTExMgr_C;}else{
TPM_bAirLdLimDev1=z2e5dca6b607d13605d1ce74156acc2f8;TPM_bAirLdLimDev2=
zf61e6c561a27e803724384b4f76d04c0;TPM_bAirLdLimDev3=
z31e86dbddcf771dbd7e8b74f19c6f4e2;TPM_bAirLdLimDev4=
zdd4a636878d832efff2d29f82fac2282;TPM_bAirLdLimTWC3=
z9619584b965b4e31aa3549c39212f70a;TPM_bAirLdLimTWC2=
za657b557242aec9ca59599685f5c686d;TPM_bAirLdLimTWC1=
zb43eefb0d803d5c5b87a159a151194a8;zb6d18d311a5ea5f88b4e4a0377548342=
TPM_bAirLdLimDev1||TPM_bAirLdLimDev2||TPM_bAirLdLimDev3||TPM_bAirLdLimDev4||
TPM_bAirLdLimTWC3||TPM_bAirLdLimTWC2||TPM_bAirLdLimTWC1;}TPM_bAirLdLimTExMgr_out
=zb6d18d311a5ea5f88b4e4a0377548342;if(TPM_bSelTCurThermoProtDev_C){
RE003_TPM_tExCurAcvThermoProtDev_out=(UInt16)(TPM_tSelTCurThermoProtDev_C+58400)
;}else{switch(z9fa28a9bfa43562a13245ecfa3963a8c){case 0:{
z689d9d920555d9697e075e53154e7810=56864;break;}case 1:{TPM_tExDev1=
z7737fcbb8d606eb682f34548eb3e2908;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExDev1)+58400);break;}case 2:{TPM_tExDev2=
z9bf5a95a0cde06e9951499086edce202;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExDev2)+58400);break;}case 3:{TPM_tExDev3=
zd15c0d58f0982c995c965ea77be8cc3e;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExDev3)+58400);break;}case 4:{TPM_tExDev4=
z81494cf0f4b23e1650f2382322794e7f;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExDev4)+58400);break;}case 5:{TPM_tExTWC3=
z5cdc66b71fac542d12e3e97aa04a2112;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExTWC3)+58400);break;}case 6:{TPM_tExTWC2=
zec04e4a9ee5926e7bdb8e2ce4b1f8e8f;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExTWC2)+58400);break;}case 7:{TPM_tExTWC1=
z9a5f9b298f4d00ad0706f1f6e999f60d;z689d9d920555d9697e075e53154e7810=(UInt16)(((
UInt16)TPM_tExTWC1)+58400);break;}}RE003_TPM_tExCurAcvThermoProtDev_out=
z689d9d920555d9697e075e53154e7810;}if(TPM_bSelNbAcvThermoProtDev_C){
RE003_TPM_noAcvThermoProtDev_out=TPM_noSelAcvThermoProtDev_C;}else{
RE003_TPM_noAcvThermoProtDev_out=z9fa28a9bfa43562a13245ecfa3963a8c;}if(
ze5aed13a5b01444f5678c6825a5c30fc<z0b07bfb92c95c708197ebf260276e235){
z5789054cbcc0eb263da5fa3d1270a2cf=ze5aed13a5b01444f5678c6825a5c30fc;}else{
z5789054cbcc0eb263da5fa3d1270a2cf=z0b07bfb92c95c708197ebf260276e235;}if(
z269f16ec85c290b0c12845fa8679d3d3<zbbb13bd99f6808b124b13f2699cefcc9){
z61f702e660fc002cae41748aa0a44af6=z269f16ec85c290b0c12845fa8679d3d3;}else{
z61f702e660fc002cae41748aa0a44af6=zbbb13bd99f6808b124b13f2699cefcc9;}if(
zd256c1c781273ba4b4c0d61231800328<zd906ea63a238a7925d2aeec41c3a31ba){
z0ac6bdc96f479a2298807f6007f6e575=zd256c1c781273ba4b4c0d61231800328;}else{
z0ac6bdc96f479a2298807f6007f6e575=zd906ea63a238a7925d2aeec41c3a31ba;}
ze119367927442a24e168287dc42c1419=z2d07d203c34c561a8166fdae37c33bda;
z72ce00e110723d4a019c24fc1e43f290=1;for(zd468f45f7296e73fe1291d4b933ffed7=0;
zd468f45f7296e73fe1291d4b933ffed7<=6;(zd468f45f7296e73fe1291d4b933ffed7)++){
zcf3ccb84663209a35029d94badab9f54[zd468f45f7296e73fe1291d4b933ffed7]=(UInt32)
z9e3dc4675aa3b5f7027556b3424d0b01[zd468f45f7296e73fe1291d4b933ffed7];}
z9faaf4a97ab42e03fb785b9bf34265a6=z9f69b105c811399c6c000a83fe6bac03;
z2d07d203c34c561a8166fdae37c33bda=zb6d18d311a5ea5f88b4e4a0377548342;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_004_TEV_fct(Void){UInt16 ze5aed13a5b01444f5678c6825a5c30fc;UInt16 
z0b07bfb92c95c708197ebf260276e235;UInt16 z269f16ec85c290b0c12845fa8679d3d3;
UInt16 zbbb13bd99f6808b124b13f2699cefcc9;UInt16 
zd256c1c781273ba4b4c0d61231800328;UInt16 zd906ea63a238a7925d2aeec41c3a31ba;
Boolean z8a32e8d845d1f17c84c918e08dcfca18;Boolean 
z9e8893cbbbf79c6c88d6ce42c26ffe2b;Boolean z6e734a09d7304fa17b93518ecee7e65d;
Boolean zd62d8fce3a37db7b665c4375b5b76dc8;TPM_bRichScvIn_MP=((UInt32)
TPM_RE004_EngM_mfAirScvCor_in)>=(TPM_mfAirScvOfs_C+((UInt32)
RE004_TPM_mfAirScvLimMax_in));if(TPM_bRichScvIn_MP){
ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(za38b275d73d6010cf84de6261b1cac8e+1);
}else{ze5aed13a5b01444f5678c6825a5c30fc=0;}z0b07bfb92c95c708197ebf260276e235=(
UInt16)(TPM_tiRichScvTmp_C/TPM_tiSdlTPM_C);z8a32e8d845d1f17c84c918e08dcfca18=
TPM_bRichScvIn_MP&&(ze5aed13a5b01444f5678c6825a5c30fc>
z0b07bfb92c95c708197ebf260276e235);TPM_bBfTiScvTmp_MP=
TPM_RE004_FARSp_bRichScvThermoInvld_in&&z8a32e8d845d1f17c84c918e08dcfca18;if(
TPM_bBfTiScvTmp_MP){z269f16ec85c290b0c12845fa8679d3d3=(UInt16)(
z6f71fda760a8ba9894ae0a9433ed9be1+1);}else{z269f16ec85c290b0c12845fa8679d3d3=0;}
zbbb13bd99f6808b124b13f2699cefcc9=(UInt16)(TPM_tiScvTmp_C/TPM_tiSdlTPM_C);
TPM_bAfterTiScvTmp_MP=TPM_bBfTiScvTmp_MP&&(z269f16ec85c290b0c12845fa8679d3d3>
zbbb13bd99f6808b124b13f2699cefcc9);if(TPM_bAfterTiScvTmp_MP){
zd256c1c781273ba4b4c0d61231800328=0;}else{zd256c1c781273ba4b4c0d61231800328=(
UInt16)(z8afa732dac1c3494e2be03ec09e7eb74+1);}zd906ea63a238a7925d2aeec41c3a31ba=
(UInt16)(TPM_tiLimScvTmp_C/TPM_tiSdlTPM_C);TabIdxS50T513((const UInt16*)
TPM_nEngRblX_A,16,TPM_RE004_Ext_nEng_in,&(z05984fcf2d7dbb03202309a281558061),&(
ze6b63784b37107d27da156b3ff76f6b7));z229525ae0d1ffd7362172ea64ef77ea1=
Tab1DIntp2I1T65((const UInt16*)TPM_rAirLdLimRbl_T,
z05984fcf2d7dbb03202309a281558061,ze6b63784b37107d27da156b3ff76f6b7);
z9e8893cbbbf79c6c88d6ce42c26ffe2b=TPM_RE004_EngM_rAirLdCor_in>=
z229525ae0d1ffd7362172ea64ef77ea1;if(z2b7cd2f6fc311ad968c13bd63dd05417){SInt32 
zd468f45f7296e73fe1291d4b933ffed7;zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((
UInt32)(SInt32)(((UInt32)RE004_TPM_tRefTWCScvMax_in)-((UInt32)TPM_tRefTWC_C)))-
7136);z6e734a09d7304fa17b93518ecee7e65d=(zd6256dc956d19116f3c133e11101744c||(
zd468f45f7296e73fe1291d4b933ffed7>=-7136))&&(!(zd468f45f7296e73fe1291d4b933ffed7
<=((SInt32)(-((SInt16)TPM_tHysRbl_C)))));}else{z6e734a09d7304fa17b93518ecee7e65d
=0;}if(z46d85d13b727af93f15b4bed3277b1c9){Boolean 
z5213e430c4516eeb20925e0e3195cd78;z5213e430c4516eeb20925e0e3195cd78=
TPM_RE004_FRM_bAcvLimScv_in||((TPM_bAfterTiScvTmp_MP||(
zd256c1c781273ba4b4c0d61231800328<=zd906ea63a238a7925d2aeec41c3a31ba))&&
TPM_bAcvProtLimScv_C);zd62d8fce3a37db7b665c4375b5b76dc8=(
z54beb4eb1364f48e07bb7e3620e5c522||z5213e430c4516eeb20925e0e3195cd78||(
z9e8893cbbbf79c6c88d6ce42c26ffe2b&&z6e734a09d7304fa17b93518ecee7e65d))&&(
z5213e430c4516eeb20925e0e3195cd78||(z6e734a09d7304fa17b93518ecee7e65d&&((
TPM_stTWCRbl_C==TPM_RE004_ExM_stO2HcStgTWC_in)||(TPM_RE004_ExM_stO2HcStgTWC_in==
TPM_stTWCRbl2_C)||(TPM_RE004_ExM_stO2HcStgTWC_in==TPM_stTWCRbl3_C)||
TPM_bInhStTWCRbl_C)));}else{zd62d8fce3a37db7b665c4375b5b76dc8=1;}if(
TPM_bSelAirScvLimMaxCor_C){TPM_mfAirScvLimMaxCor_out=TPM_mfSelAirScvLimMaxCor_C;
}else{if(TPM_RE004_FRM_bAcvTPMDecTMaxDev_in){TPM_mfAirScvLimMaxCor_out=
TPM_mfAirScvMax_C;}else{if(z9e8893cbbbf79c6c88d6ce42c26ffe2b){
TPM_mfAirScvLimMaxCor_out=64881;}else{TPM_mfAirScvLimMaxCor_out=
RE004_TPM_mfAirScvLimMax_in;}}}TabIdxS50T514((const UInt32*)
TPM_facPresAltiCorX_A,16,(UInt32)TPM_RE004_UsThrM_facPresAltiCor_in,&(
z9bfbbc50a6feb4e0b2cf2da945bde25b),&(z101baa0885a8b9c8fca87590a876f65d));
z615af0db8952dccd3d33c89f6c74d78f=Tab1DIntp2I1T66((const UInt32*)
TPM_facPresAltiCor_T,z9bfbbc50a6feb4e0b2cf2da945bde25b,
z101baa0885a8b9c8fca87590a876f65d);TabIdxS50T513((const UInt16*)TPM_nEngRblX_A,
16,TPM_RE004_Ext_nEng_in,&(z7afbb36daf6c307137171f65651737fd),&(
z0fb436dc4d9a424271d9561523472fbb));zbb15cebec5277be27be297f647facacb=
Tab1DIntp2I1T65((const UInt16*)TPM_rAirLdMaxRbl_T,
z7afbb36daf6c307137171f65651737fd,z0fb436dc4d9a424271d9561523472fbb);
z9e8893cbbbf79c6c88d6ce42c26ffe2b=TPM_RE004_FRM_bAcvTPMDecTMaxDev_in||
zd62d8fce3a37db7b665c4375b5b76dc8;if(TPM_bSelRatAirLdReqRbl_C){
RE004_TPM_rAirLdReqRbl_out=(UInt16)(((UInt16)TPM_rSelRatAirLdReqRbl_C)<<8);}else
{if(z9e8893cbbbf79c6c88d6ce42c26ffe2b){UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
UInt32 z598fc83d17c7afbb99b61c2115312c40;UInt32 
ze7aaa232278aa4bfdf744ffb64ef0932;F__U64MULU32U32(
z615af0db8952dccd3d33c89f6c74d78f,(UInt32)zbb15cebec5277be27be297f647facacb,&(
z21fed86397a19bfad54bda2cfdaa9d19),&(z598fc83d17c7afbb99b61c2115312c40));
ze7aaa232278aa4bfdf744ffb64ef0932=C__U32SHRU64C6_LT32(
z21fed86397a19bfad54bda2cfdaa9d19,z598fc83d17c7afbb99b61c2115312c40,15,17);
RE004_TPM_rAirLdReqRbl_out=C__U16SATU32_SATu(ze7aaa232278aa4bfdf744ffb64ef0932,
49152);}else{RE004_TPM_rAirLdReqRbl_out=49152;}}if(TPM_bSelAcvProtExScv_C){
RE004_TPM_bAcvProtExScv_out=TPM_bAcvSelAcvProtExScv_C;}else{
RE004_TPM_bAcvProtExScv_out=z9e8893cbbbf79c6c88d6ce42c26ffe2b;}if(
TPM_bSelRichLimScv_C){TPM_bRichLimScv_out=TPM_bAcvSelRichLimScv_C;}else{
TPM_bRichLimScv_out=z8a32e8d845d1f17c84c918e08dcfca18;}if(
z269f16ec85c290b0c12845fa8679d3d3<zbbb13bd99f6808b124b13f2699cefcc9){
z6f71fda760a8ba9894ae0a9433ed9be1=z269f16ec85c290b0c12845fa8679d3d3;}else{
z6f71fda760a8ba9894ae0a9433ed9be1=zbbb13bd99f6808b124b13f2699cefcc9;}if(
ze5aed13a5b01444f5678c6825a5c30fc<z0b07bfb92c95c708197ebf260276e235){
za38b275d73d6010cf84de6261b1cac8e=ze5aed13a5b01444f5678c6825a5c30fc;}else{
za38b275d73d6010cf84de6261b1cac8e=z0b07bfb92c95c708197ebf260276e235;}if(
zd256c1c781273ba4b4c0d61231800328<zd906ea63a238a7925d2aeec41c3a31ba){
z8afa732dac1c3494e2be03ec09e7eb74=zd256c1c781273ba4b4c0d61231800328;}else{
z8afa732dac1c3494e2be03ec09e7eb74=zd906ea63a238a7925d2aeec41c3a31ba;}
z2b7cd2f6fc311ad968c13bd63dd05417=1;zd6256dc956d19116f3c133e11101744c=
z6e734a09d7304fa17b93518ecee7e65d;z46d85d13b727af93f15b4bed3277b1c9=1;
z54beb4eb1364f48e07bb7e3620e5c522=zd62d8fce3a37db7b665c4375b5b76dc8;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_005_TEV_fct(Void){SInt32 zd468f45f7296e73fe1291d4b933ffed7;SInt32 
z06f32ff761b03af45c9f63ba6e33e8d9;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
UInt32 z598fc83d17c7afbb99b61c2115312c40;UInt16 
ze5aed13a5b01444f5678c6825a5c30fc;UInt8 z9fa28a9bfa43562a13245ecfa3963a8c;
Boolean zd62d8fce3a37db7b665c4375b5b76dc8;Boolean 
z8e51e4591fcc685001532289e452bd62;z21fed86397a19bfad54bda2cfdaa9d19=((UInt32)
TPM_RE005_EngM_mfAirScvCor_in)+((UInt32)TPM_RE005_EngM_mfAirCor_in);
zd62d8fce3a37db7b665c4375b5b76dc8=z21fed86397a19bfad54bda2cfdaa9d19!=0;if(
zd62d8fce3a37db7b665c4375b5b76dc8){zba77dde50534638bf758da37204ced21=(SInt32)(((
UInt32)(((UInt32)TPM_RE005_EngM_mfAirCor_in)<<16))/
z21fed86397a19bfad54bda2cfdaa9d19);}if(zd62d8fce3a37db7b665c4375b5b76dc8){
zd468f45f7296e73fe1291d4b933ffed7=zba77dde50534638bf758da37204ced21;}else{
zd468f45f7296e73fe1291d4b933ffed7=65536;}if(z21d095369b9b5aa53db6f41a202e6df1){
ze5aed13a5b01444f5678c6825a5c30fc=z822ce74faba1cfcc86c02ca647fc7376;}else{
ze5aed13a5b01444f5678c6825a5c30fc=TPM_rMixtTWCStMin_C;}
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)(SInt32)((((UInt32)
C__U16SATI32_SATb(zd468f45f7296e73fe1291d4b933ffed7,65535,43691))*((UInt32)
TPM_RE005_FARSp_rMixtCylSp_in))>>16))-((UInt32)ze5aed13a5b01444f5678c6825a5c30fc
));F__I64MULU32I32(z21fed86397a19bfad54bda2cfdaa9d19,
z06f32ff761b03af45c9f63ba6e33e8d9,&(zd468f45f7296e73fe1291d4b933ffed7),&(
z598fc83d17c7afbb99b61c2115312c40));z06f32ff761b03af45c9f63ba6e33e8d9=
C__I32SHRI64C6_LT32(zd468f45f7296e73fe1291d4b933ffed7,
z598fc83d17c7afbb99b61c2115312c40,2,30);F__I64MULI32U32(
z06f32ff761b03af45c9f63ba6e33e8d9,(UInt32)TPM_facCorTWCSt_C,&(
zd468f45f7296e73fe1291d4b933ffed7),&(z21fed86397a19bfad54bda2cfdaa9d19));
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((SInt32)(C__I32SHRI64C6_LT32(
zd468f45f7296e73fe1291d4b933ffed7,z21fed86397a19bfad54bda2cfdaa9d19,18,14)>>4))+
((UInt32)ze5aed13a5b01444f5678c6825a5c30fc));zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)TPM_rMixtTWCStMin_C;if(z06f32ff761b03af45c9f63ba6e33e8d9>
zd468f45f7296e73fe1291d4b933ffed7){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)
z06f32ff761b03af45c9f63ba6e33e8d9;}else{z21fed86397a19bfad54bda2cfdaa9d19=(
UInt32)zd468f45f7296e73fe1291d4b933ffed7;}if(((UInt32)TPM_rMixtTWCStMax_C)<
z21fed86397a19bfad54bda2cfdaa9d19){TPM_rMixtTWCSt=TPM_rMixtTWCStMax_C;}else{
TPM_rMixtTWCSt=(UInt16)z21fed86397a19bfad54bda2cfdaa9d19;}if(
TPM_bSelStO2HcStgTWC_C){z9fa28a9bfa43562a13245ecfa3963a8c=
TPM_stSelStO2HcStgTWC_C;}else{TPM_bTWCO2FullSt=((!(
TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in))&&(TPM_RE005_Ext_uLsDsMes_in<=
TPM_uLsDsMesThdTWCO2Full_C))||(TPM_rMixtTWCSt<=TPM_rMixtThdTWCO2Full_C);
TPM_bTWCHcFullSt=((TPM_RE005_Ext_uLsDsMes_in>=TPM_uLsDsMesThdTWCHcFull_C)&&(!(
TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in)))||(TPM_rMixtTWCSt>=TPM_rMixtThdTWCHcFull_C)
;if(TPM_bTWCHcFullSt||TPM_bTWCO2FullSt){if(TPM_RE005_FRM_bAcvTPMDecTMaxDev_in){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)TPM_tThdTWCSt_C)-((UInt32)
TPM_tDeltaTDevMaxLihTEx_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)
TPM_tThdTWCSt_C;}zd62d8fce3a37db7b665c4375b5b76dc8=((SInt32)(UInt16)(
RE005_TPM_tTWC_in+7136))>=zd468f45f7296e73fe1291d4b933ffed7;if(TPM_bTWCO2FullSt)
{if(zd62d8fce3a37db7b665c4375b5b76dc8){z9fa28a9bfa43562a13245ecfa3963a8c=2;}else
{z9fa28a9bfa43562a13245ecfa3963a8c=4;}}else{if(zd62d8fce3a37db7b665c4375b5b76dc8
){z9fa28a9bfa43562a13245ecfa3963a8c=1;}else{z9fa28a9bfa43562a13245ecfa3963a8c=3;
}}}else{z9fa28a9bfa43562a13245ecfa3963a8c=0;}}zd62d8fce3a37db7b665c4375b5b76dc8=
(1==z9fa28a9bfa43562a13245ecfa3963a8c)||(z9fa28a9bfa43562a13245ecfa3963a8c==3);
if(TPM_bSelInhInjSelCutOff_C){TPM_bInhInjSelCutOff_out=
TPM_bInhSelInhInjSelCutOff_C;}else{if(TPM_RE005_FRM_bAcvTPMDecTMaxDev_in){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)TPM_tOxdTWCSelCutOff_C)-((
UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)TPM_tOxdTWCSelCutOff_C;}TPM_bInhInjSelCutOff_out=(
zd62d8fce3a37db7b665c4375b5b76dc8&&TPM_bAcvStTWCSelCutOff_C)||(
TPM_RE005_ExM_lamTot_in<=TPM_lamThdSelCutOff_C)||(((SInt32)(UInt16)(
RE005_TPM_tTWC_in+7136))>=zd468f45f7296e73fe1291d4b933ffed7)||(
TPM_RE005_EngM_mfAirScvCor_in>((UInt16)TPM_mfAirScvThdSelCutOff_C))||
TPM_RE005_FRM_bInhCutOff_in;}if(z90b540ab8a74466d49971cdff8af2f95){
z8e51e4591fcc685001532289e452bd62=zf779a5f75e4029bf1478433d3133291a;}else{
z8e51e4591fcc685001532289e452bd62=0;}if((81920==TPM_RE005_ExM_lamTot_in)&&(!(
z8e51e4591fcc685001532289e452bd62))&&TPM_bAcvHisTWCCutOff_C){
z8e51e4591fcc685001532289e452bd62=0;}else{if(TPM_RE005_FRM_bAcvTPMDecTMaxDev_in)
{zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)TPM_tMaxStoichTWC_C)-((
UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)TPM_tMaxStoichTWC_C;}TPM_bMaxStoichTWC_MP=((SInt32)(UInt16)(
RE005_TPM_tTWC_in+7136))>=zd468f45f7296e73fe1291d4b933ffed7;if(
TPM_RE005_FRM_bAcvTPMDecTMaxDev_in){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)((
(UInt32)TPM_tMaxRichCutOffTWC_C)-((UInt32)TPM_tDeltaTDevMaxLihTEx_C));}else{
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)TPM_tMaxRichCutOffTWC_C;}
TPM_bMaxRichTWC_MP=((SInt32)(UInt16)(RE005_TPM_tTWC_in+7136))>=
zd468f45f7296e73fe1291d4b933ffed7;TPM_bMaxRichStO2HcLdTWCOk_MP=
TPM_bMaxRichTWC_MP&&((TPM_RE005_ExM_lamTot_in<=TPM_lamThdCutOff_C)||(
zd62d8fce3a37db7b665c4375b5b76dc8&&TPM_bAcvStTWCCutOff_C));
z8e51e4591fcc685001532289e452bd62=TPM_RE005_FRM_bInhCutOff_in||
TPM_bMaxStoichTWC_MP||TPM_bMaxRichStO2HcLdTWCOk_MP;}if(TPM_bSelInhInjCutOff_C){
TPM_bInhInjCutOff_out=TPM_bInhSelInhInjCutOff_C;}else{TPM_bInhInjCutOff_out=
z8e51e4591fcc685001532289e452bd62;}ExM_stO2HcStgTWC_out=
z9fa28a9bfa43562a13245ecfa3963a8c;z21d095369b9b5aa53db6f41a202e6df1=1;
z822ce74faba1cfcc86c02ca647fc7376=TPM_rMixtTWCSt;
z90b540ab8a74466d49971cdff8af2f95=1;zf779a5f75e4029bf1478433d3133291a=
z8e51e4591fcc685001532289e452bd62;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_006_TEV_fct(Void){UInt32 z21fed86397a19bfad54bda2cfdaa9d19;UInt16 
ze5aed13a5b01444f5678c6825a5c30fc;UInt8 z9fa28a9bfa43562a13245ecfa3963a8c;UInt8 
z764023faa138f38ff107d9e4721878f5;Boolean z3da27aec5682a60504c205c59823dc29;
TPM_bAcvReg=RE006_TPM_noAcvThermoProtDev_in!=0;if(TPM_bAcvReg){UInt16 
z0b07bfb92c95c708197ebf260276e235;TabIdxS50T0((const UInt8*)TPM_noDevOpl_A,7,
RE006_TPM_noAcvThermoProtDev_in,&(z9d54d1e1a0319a30be30d1f3692559e0),&(
z072f7056b773256c69e596594b65c0a9));if(z072f7056b773256c69e596594b65c0a9>=128){
z9fa28a9bfa43562a13245ecfa3963a8c=(UInt8)(z9d54d1e1a0319a30be30d1f3692559e0+1);}
else{z9fa28a9bfa43562a13245ecfa3963a8c=z9d54d1e1a0319a30be30d1f3692559e0;}
z764023faa138f38ff107d9e4721878f5=C__U8SATU8_SATu(
z9fa28a9bfa43562a13245ecfa3963a8c,6);TPM_noAcvThermoProtDevSelOpl=
TPM_idxGrpDevOpl_T[z764023faa138f38ff107d9e4721878f5];if(
TPM_RE006_TPM_bAirLdLimTExMgr_in){TabIdxS50T513((const UInt16*)TPM_nEngTEgOpl_A,
6,TPM_RE006_Ext_nEng_in,&(z2620ff8d81062a04ccb024dd3fd223ee),&(
zbd7050086212d78d8c19a3bec4f9c07e));switch(TPM_noAcvThermoProtDevSelOpl){case 0:
{ze5aed13a5b01444f5678c6825a5c30fc=Tab1DIntp2I1T65((const UInt16*)
TPM_tEgOplReqAirLdDev1_T,z2620ff8d81062a04ccb024dd3fd223ee,
zbd7050086212d78d8c19a3bec4f9c07e);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqAirLdDev1_C));TPM_tEgOplReqAirLdSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqAirLdSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 1:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab1DIntp2I1T65((const UInt16*)
TPM_tEgOplReqAirLdDev2_T,z2620ff8d81062a04ccb024dd3fd223ee,
zbd7050086212d78d8c19a3bec4f9c07e);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqAirLdDev2_C));TPM_tEgOplReqAirLdSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqAirLdSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 2:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab1DIntp2I1T65((const UInt16*)
TPM_tEgOplReqAirLdDev3_T,z2620ff8d81062a04ccb024dd3fd223ee,
zbd7050086212d78d8c19a3bec4f9c07e);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqAirLdDev3_C));TPM_tEgOplReqAirLdSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqAirLdSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 3:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab1DIntp2I1T65((const UInt16*)
TPM_tEgOplReqAirLdDev4_T,z2620ff8d81062a04ccb024dd3fd223ee,
zbd7050086212d78d8c19a3bec4f9c07e);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqAirLdDev4_C));TPM_tEgOplReqAirLdSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqAirLdSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}default:{}}TPM_tAddCmdOpl=
TPM_tEgOplReqAirLdSel;}else{TabIdxS50T513((const UInt16*)TPM_nEngTEgOpl_A,6,
TPM_RE006_Ext_nEng_in,&(z71bea8e23ecc68d5e1cc405c6d8bcc28),&(
z3ea1e38e46f4cc8965d595eef2c721d1));TabIdxS50T513((const UInt16*)
TPM_rAirLdCorTEgOpl_A,8,TPM_RE006_EngM_rAirLdCor_in,&(
za87bb83c61b06587cb4227ed85752f64),&(zb857435c9402aa454a19415717e3e6b5));switch(
TPM_noAcvThermoProtDevSelOpl){case 0:{ze5aed13a5b01444f5678c6825a5c30fc=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_tEgOplReqRlamDev1_M[0][0]),8,
z71bea8e23ecc68d5e1cc405c6d8bcc28,z3ea1e38e46f4cc8965d595eef2c721d1,
za87bb83c61b06587cb4227ed85752f64,zb857435c9402aa454a19415717e3e6b5);if(
TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){z0b07bfb92c95c708197ebf260276e235=(UInt16)(
ze5aed13a5b01444f5678c6825a5c30fc-((UInt16)TPM_tEgOplOfsReqRlamDev1_C));
TPM_tEgOplReqRlamSel=C__U16SATU16_SATb(z0b07bfb92c95c708197ebf260276e235,700,450
);}else{TPM_tEgOplReqRlamSel=ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 1:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_tEgOplReqRlamDev2_M[0][0]),8,z71bea8e23ecc68d5e1cc405c6d8bcc28,
z3ea1e38e46f4cc8965d595eef2c721d1,za87bb83c61b06587cb4227ed85752f64,
zb857435c9402aa454a19415717e3e6b5);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqRlamDev2_C));TPM_tEgOplReqRlamSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqRlamSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 2:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_tEgOplReqRlamDev3_M[0][0]),8,z71bea8e23ecc68d5e1cc405c6d8bcc28,
z3ea1e38e46f4cc8965d595eef2c721d1,za87bb83c61b06587cb4227ed85752f64,
zb857435c9402aa454a19415717e3e6b5);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqRlamDev3_C));TPM_tEgOplReqRlamSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqRlamSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}case 3:{
ze5aed13a5b01444f5678c6825a5c30fc=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_tEgOplReqRlamDev4_M[0][0]),8,z71bea8e23ecc68d5e1cc405c6d8bcc28,
z3ea1e38e46f4cc8965d595eef2c721d1,za87bb83c61b06587cb4227ed85752f64,
zb857435c9402aa454a19415717e3e6b5);if(TPM_RE006_FRM_bAcvTPMDecTMaxDev_in){
z0b07bfb92c95c708197ebf260276e235=(UInt16)(ze5aed13a5b01444f5678c6825a5c30fc-((
UInt16)TPM_tEgOplOfsReqRlamDev4_C));TPM_tEgOplReqRlamSel=C__U16SATU16_SATb(
z0b07bfb92c95c708197ebf260276e235,700,450);}else{TPM_tEgOplReqRlamSel=
ze5aed13a5b01444f5678c6825a5c30fc;}break;}default:{}}TPM_tAddCmdOpl=
TPM_tEgOplReqRlamSel;}}z3da27aec5682a60504c205c59823dc29=
z07bd6ad0b035f5784d3c8f087a753755;TPM_bAcvCllRegClc=
zeffbd27d014ac6a46ed446a65e03493d||TPM_bAcvReg;if(TPM_bAcvCllRegClc){SInt32 
zd468f45f7296e73fe1291d4b933ffed7;SInt32 z06f32ff761b03af45c9f63ba6e33e8d9;
SInt32 z91d6bd6fb6e014158f04ff5ae654b748;SInt32 
zda1f01f865fd1b51e129ca10fa784b66;SInt32 ze88ecf65778b5ec9c76429e26477419e;
SInt16 z083933e535293d75bb743b103b9f75c1;Boolean 
zf3c7f0aba83acc2c1b87e32b60c76a08;TPM_tExReqPrev=
zbf75324abaf05eda53dbc931bbbe80a9;TabIdxS50T513((const UInt16*)
TPM_rMixtIniThermoProt_A,11,TPM_RE006_FARSp_rMixtCylSp_in,&(
za4e562df19791d83709676cddb0b8028),&(z751b528547dcef53601fdbbbd3fbaa9f));
TabIdxS50T514((const UInt32*)TPM_mfEgTotAirEstim_A,9,(UInt32)
TPM_RE006_ExM_mfEgTot_in,&(z83e6e8e7443d0d47afcbb1d6ee1905a0),&(
z2073fea7712adde1aeab47a6c62c3696));z3924675519b4fe318c4a8dda753406f3=
Tab2DIntp2I1T33282((const UInt32*)&(TPM_facEgEstimRlamIni_M[0][0]),9,
za4e562df19791d83709676cddb0b8028,z751b528547dcef53601fdbbbd3fbaa9f,
z83e6e8e7443d0d47afcbb1d6ee1905a0,z2073fea7712adde1aeab47a6c62c3696);
TPM_tErrCmdReg=(SInt32)(((UInt32)(SInt32)(((UInt32)
TPM_RE006_TPM_tTarAcvThermoProtDev_in)-((UInt32)
RE006_TPM_tExCurAcvThermoProtDev_in)))-7136);z083933e535293d75bb743b103b9f75c1=
C__I16SATI32_SATb(TPM_tErrCmdReg,32000,-32000);TabIdxS50T0((const UInt8*)
TPM_noDevCll_A,7,RE006_TPM_noAcvThermoProtDev_in,&(
zda8a07ef6f3c9e6b9bde0f98f9c9474d),&(z40a72ebc94864c7eec36f2bb285c6626));if(
z40a72ebc94864c7eec36f2bb285c6626>=128){z9fa28a9bfa43562a13245ecfa3963a8c=(UInt8
)(zda8a07ef6f3c9e6b9bde0f98f9c9474d+1);}else{z9fa28a9bfa43562a13245ecfa3963a8c=
zda8a07ef6f3c9e6b9bde0f98f9c9474d;}z764023faa138f38ff107d9e4721878f5=
C__U8SATU8_SATu(z9fa28a9bfa43562a13245ecfa3963a8c,6);
TPM_noAcvThermoProtDevSelCll=TPM_idxGrpDevCll_T[
z764023faa138f38ff107d9e4721878f5];TabIdxS50T513((const UInt16*)TPM_nEngTEgOpl_A
,6,TPM_RE006_Ext_nEng_in,&(zf5f3a58e0312d1090436047e52dfc413),&(
za2f97ce0c6526e204c6cebec85b8c08a));TabIdxS50T513((const UInt16*)
TPM_rAirLdCorTEgOpl_A,8,TPM_RE006_EngM_rAirLdCor_in,&(
z1fafea4e38b1d32f62e3cb9594f0ed92),&(za21850e6def46bf19025e659a2a99e9b));if(
TPM_RE006_TPM_bAirLdLimTExMgr_in){switch(TPM_noAcvThermoProtDevSelCll){case 0:{
TPM_facPropCoefAirLdSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facPropCoefAirLdDev1_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 1:{TPM_facPropCoefAirLdSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facPropCoefAirLdDev2_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 2:{TPM_facPropCoefAirLdSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facPropCoefAirLdDev3_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 3:{TPM_facPropCoefAirLdSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facPropCoefAirLdDev4_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}
default:{}}TPM_facPropCoefRun=TPM_facPropCoefAirLdSel;}else{switch(
TPM_noAcvThermoProtDevSelCll){case 0:{TPM_facPropCoefRlamSel=Tab2DIntp2I1T33281(
(const UInt16*)&(TPM_facPropCoefRlamDev1_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 1:{TPM_facPropCoefRlamSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facPropCoefRlamDev2_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 2:{TPM_facPropCoefRlamSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facPropCoefRlamDev3_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 3:{TPM_facPropCoefRlamSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facPropCoefRlamDev4_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}default:{}}TPM_facPropCoefRun=
TPM_facPropCoefRlamSel;}TPM_tActPropCmd=((SInt32)
z083933e535293d75bb743b103b9f75c1)*((SInt32)TPM_facPropCoefRun);
zd468f45f7296e73fe1291d4b933ffed7=C__I32SATI32_SATb(TPM_tActPropCmd,128000,-
128000);zf3c7f0aba83acc2c1b87e32b60c76a08=((SInt16)
RE006_TPM_noAcvThermoProtDev_in)!=z82b0b31d555204c1fe0f75036f69634d;
TPM_bEnaSpcIniIntReg=(((!(TPM_RE006_TPM_bAirLdLimTExMgr_in))&&
z7a702e59268d760c3f1103a6fd6f1e62&&TPM_bEnaIniAirLdFall_C)||(
TPM_bEnaIniRichChgDev_C&&(!(TPM_RE006_TPM_bAirLdLimTExMgr_in))&&
zf3c7f0aba83acc2c1b87e32b60c76a08)||(zf3c7f0aba83acc2c1b87e32b60c76a08&&
TPM_RE006_TPM_bAirLdLimTExMgr_in&&TPM_bEnaIniAirLdChgDev_C))&&(!(
TPM_RE006_TPM_bAcvRichThermoProt_in&&(!(z3fada861cdf95110b6e04b1fe5883966))&&
TPM_bInhIniRichRise_C));if(TPM_bEnaSpcIniIntReg){TPM_bSelTIniIntReg=((!(
TPM_RE006_TPM_bAirLdLimTExMgr_in))&&zdd5f1f3dee657178ebe3dbc123d9900c)||((!(
TPM_RE006_TPM_bAirLdLimTExMgr_in))&&(((SInt16)RE006_TPM_noAcvThermoProtDev_in)!=
z2db3e7a844f4fc306743bc386244745c));if(TPM_bSelTIniIntReg){if(((!(
TPM_RE006_TPM_bAirLdLimTExMgr_in))&&zb3026ac91a9e667604ea0865427ac2c1)||(
TPM_RE006_TPM_bAcvRichThermoProt_in&&(!(zb9e0bbf5224a0cd2f391925391aec4e0)))){
UInt32 z598fc83d17c7afbb99b61c2115312c40;F__U64MULU32U32((UInt32)
TPM_RE006_ExM_tExStatAfs_in,z3924675519b4fe318c4a8dda753406f3,&(
z21fed86397a19bfad54bda2cfdaa9d19),&(z598fc83d17c7afbb99b61c2115312c40));
ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)((((UInt32)C__U32SHRU64C6_LT32(
z21fed86397a19bfad54bda2cfdaa9d19,z598fc83d17c7afbb99b61c2115312c40,1,31))+((
UInt32)(z3924675519b4fe318c4a8dda753406f3*3568)))>>16);TPM_tIniRichIntReg=
C__U16SATU16_SATb(ze5aed13a5b01444f5678c6825a5c30fc,48736,7136);}else{
TPM_tIniRichIntReg=zbf75324abaf05eda53dbc931bbbe80a9;}
ze5aed13a5b01444f5678c6825a5c30fc=TPM_tIniRichIntReg;}else{TPM_tIniAirLdIntReg=
zbf75324abaf05eda53dbc931bbbe80a9;ze5aed13a5b01444f5678c6825a5c30fc=
TPM_tIniAirLdIntReg;}if(TPM_bInhIniWiPropAct_C){
z06f32ff761b03af45c9f63ba6e33e8d9=0;}else{z06f32ff761b03af45c9f63ba6e33e8d9=
zd468f45f7296e73fe1291d4b933ffed7;}TPM_tIniIntRegThermoProt=(SInt32)(((UInt32)(
SInt32)(((SInt32)(((UInt32)ze5aed13a5b01444f5678c6825a5c30fc)-((UInt32)(SInt32)(
((UInt32)TPM_tAddCmdOpl)<<6))))<<4))-((UInt32)z06f32ff761b03af45c9f63ba6e33e8d9)
);}else{TPM_tIniIntRegThermoProt=(SInt32)(((SInt32)TPM_tIniIntRegThermoProt_C)<<
2);}if(TPM_bEnaIniInt_C&&((TPM_RE006_TPM_bAcvRichThermoProt_in&&(!(
zd44a61b2e95d9595a5b9e6898b8be6e4)))||((!(TPM_RE006_TPM_bAcvRichThermoProt_in))
&&z2c66e88595a50e0cb47734f02078a5ea)||(TPM_RE006_TPM_bAirLdLimTExMgr_in&&(!(
z937a9d18796810e9c591e7ed544d3417)))||((!(TPM_RE006_TPM_bAirLdLimTExMgr_in))&&
z0236c190df9df9ede94b1b7715a97dd5)||(((SInt16)RE006_TPM_noAcvThermoProtDev_in)!=
z82af16d90f8310dac54595db7730cf6d))){z06f32ff761b03af45c9f63ba6e33e8d9=
TPM_tIniIntRegThermoProt;}else{if(z1d336274b8771934b34fef2f33bd5e2d){
TPM_tAddIntRun_MP=zabc29a3d4cdabd62d0b89f5259297006;}else{TPM_tAddIntRun_MP=
TPM_tIniIntRegThermoProt;}zf3c7f0aba83acc2c1b87e32b60c76a08=
TPM_RE006_TPM_bAcvRichThermoProt_in&&(!(TPM_RE006_TPM_bAirLdLimTExMgr_in));
TPM_bHldIntRegThermoProt=((((zf3c7f0aba83acc2c1b87e32b60c76a08&&(
TPM_RE006_FARSp_bSatMaxRatMixt_in||TPM_RE006_FARSp_bThermoProtReqNotAuth_in||(
TPM_RE006_FARSp_rMixtThermoProtSp_in>TPM_RE006_FARSp_rMixtCylSp_in)))||((
RE006_TPM_rAirLdReq_in<TPM_RE006_EngMTrb_rLdMax_in)&&
TPM_RE006_TPM_bAirLdLimTExMgr_in))&&(z083933e535293d75bb743b103b9f75c1<0))||((0<
z083933e535293d75bb743b103b9f75c1)&&((((TPM_RE006_FARSp_rMixtCylSp_in>
TPM_RE006_FARSp_rMixtThermoProtSp_in)||(TPM_RE006_FARSp_rMixtCylSp_in<=4096)||((
TPM_RE006_FARSp_rMixtCylSp_in<=((UInt16)(TPM_rMixtProtOxdTWCMin_C<<2)))&&
TPM_RE006_TPM_bAcvRichProtOxdTWC_in))&&zf3c7f0aba83acc2c1b87e32b60c76a08)||(
TPM_RE006_TPM_bAirLdLimTExMgr_in&&((RE006_TPM_bAcvProtExScv_in&&(
RE006_TPM_rAirLdReq_in>RE006_TPM_rAirLdReqRbl_in))||(TPM_RE006_EngMTrb_rLdMax_in
<RE006_TPM_rAirLdReq_in))))))&&TPM_bEnaHldIntReg_C;if(TPM_bHldIntRegThermoProt){
z91d6bd6fb6e014158f04ff5ae654b748=0;}else{if(TPM_RE006_TPM_bAirLdLimTExMgr_in){
switch(TPM_noAcvThermoProtDevSelCll){case 0:{TPM_facIntCoefAirLdSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facIntCoefAirLdDev1_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 1:{TPM_facIntCoefAirLdSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facIntCoefAirLdDev2_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 2:{TPM_facIntCoefAirLdSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facIntCoefAirLdDev3_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 3:{TPM_facIntCoefAirLdSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facIntCoefAirLdDev4_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}default:{}}TPM_facIntCoefRun=
TPM_facIntCoefAirLdSel;}else{switch(TPM_noAcvThermoProtDevSelCll){case 0:{
TPM_facIntCoefRlamSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facIntCoefRlamDev1_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 1:{TPM_facIntCoefRlamSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facIntCoefRlamDev2_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}case
 2:{TPM_facIntCoefRlamSel=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facIntCoefRlamDev3_M[0][0]),8,zf5f3a58e0312d1090436047e52dfc413,
za2f97ce0c6526e204c6cebec85b8c08a,z1fafea4e38b1d32f62e3cb9594f0ed92,
za21850e6def46bf19025e659a2a99e9b);break;}case 3:{TPM_facIntCoefRlamSel=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_facIntCoefRlamDev4_M[0][0]),8,
zf5f3a58e0312d1090436047e52dfc413,za2f97ce0c6526e204c6cebec85b8c08a,
z1fafea4e38b1d32f62e3cb9594f0ed92,za21850e6def46bf19025e659a2a99e9b);break;}
default:{}}TPM_facIntCoefRun=TPM_facIntCoefRlamSel;}
z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)((((((SInt32)TPM_tiSdlTPM_C)*((SInt32)
z083933e535293d75bb743b103b9f75c1))/((SInt32)1000))*((SInt32)TPM_facIntCoefRun))
>>2);}TPM_tCurIntRun_MP=(SInt32)(((UInt32)TPM_tAddIntRun_MP)+((UInt32)
z91d6bd6fb6e014158f04ff5ae654b748));z06f32ff761b03af45c9f63ba6e33e8d9=
TPM_tCurIntRun_MP;}z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)(((SInt32)
TPM_tSatMinInt_C)<<2);if(z06f32ff761b03af45c9f63ba6e33e8d9>
z91d6bd6fb6e014158f04ff5ae654b748){zda1f01f865fd1b51e129ca10fa784b66=
z06f32ff761b03af45c9f63ba6e33e8d9;}else{zda1f01f865fd1b51e129ca10fa784b66=
z91d6bd6fb6e014158f04ff5ae654b748;}z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)(((
SInt32)TPM_tSatMaxInt_C)<<2);if(z91d6bd6fb6e014158f04ff5ae654b748<
zda1f01f865fd1b51e129ca10fa784b66){ze88ecf65778b5ec9c76429e26477419e=
z91d6bd6fb6e014158f04ff5ae654b748;}else{ze88ecf65778b5ec9c76429e26477419e=
zda1f01f865fd1b51e129ca10fa784b66;}if(zeb0ecda3e79d047b5d6439d219ae94c2!=0){
TPM_tActIntCmd=ze88ecf65778b5ec9c76429e26477419e;}else{
z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)(((SInt32)TPM_tSatMinInt_C)<<2);if(
TPM_tIniIntRegThermoProt>z91d6bd6fb6e014158f04ff5ae654b748){
zda1f01f865fd1b51e129ca10fa784b66=TPM_tIniIntRegThermoProt;}else{
zda1f01f865fd1b51e129ca10fa784b66=z91d6bd6fb6e014158f04ff5ae654b748;}
z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)(((SInt32)TPM_tSatMaxInt_C)<<2);if(
z91d6bd6fb6e014158f04ff5ae654b748<zda1f01f865fd1b51e129ca10fa784b66){
TPM_tActIntCmd=z91d6bd6fb6e014158f04ff5ae654b748;}else{TPM_tActIntCmd=
zda1f01f865fd1b51e129ca10fa784b66;}}z91d6bd6fb6e014158f04ff5ae654b748=(SInt32)((
(SInt32)(((UInt32)TPM_tActIntCmd)+((UInt32)zd468f45f7296e73fe1291d4b933ffed7)))
>>2);TPM_tAddCmdCll=C__I16SATI32_SATb(z91d6bd6fb6e014158f04ff5ae654b748,32000,-
32000);TPM_bLimMinInt=z06f32ff761b03af45c9f63ba6e33e8d9<=((SInt32)(((SInt32)
TPM_tSatMinInt_C)<<2));TPM_bLimMaxInt=((SInt32)(((SInt32)TPM_tSatMaxInt_C)<<2))
<=z06f32ff761b03af45c9f63ba6e33e8d9;zd44a61b2e95d9595a5b9e6898b8be6e4=
TPM_RE006_TPM_bAcvRichThermoProt_in;z2c66e88595a50e0cb47734f02078a5ea=
TPM_RE006_TPM_bAcvRichThermoProt_in;z937a9d18796810e9c591e7ed544d3417=
TPM_RE006_TPM_bAirLdLimTExMgr_in;z0236c190df9df9ede94b1b7715a97dd5=
TPM_RE006_TPM_bAirLdLimTExMgr_in;z82af16d90f8310dac54595db7730cf6d=(SInt16)
RE006_TPM_noAcvThermoProtDev_in;z7a702e59268d760c3f1103a6fd6f1e62=
TPM_RE006_TPM_bAirLdLimTExMgr_in;z82b0b31d555204c1fe0f75036f69634d=(SInt16)
RE006_TPM_noAcvThermoProtDev_in;z3fada861cdf95110b6e04b1fe5883966=
TPM_RE006_TPM_bAcvRichThermoProt_in;zdd5f1f3dee657178ebe3dbc123d9900c=
TPM_RE006_TPM_bAirLdLimTExMgr_in;z2db3e7a844f4fc306743bc386244745c=(SInt16)
RE006_TPM_noAcvThermoProtDev_in;zb3026ac91a9e667604ea0865427ac2c1=
TPM_RE006_TPM_bAirLdLimTExMgr_in;zb9e0bbf5224a0cd2f391925391aec4e0=
TPM_RE006_TPM_bAcvRichThermoProt_in;z1d336274b8771934b34fef2f33bd5e2d=1;
zabc29a3d4cdabd62d0b89f5259297006=ze88ecf65778b5ec9c76429e26477419e;
zeb0ecda3e79d047b5d6439d219ae94c2=1;}if(TPM_bAcvBypReg_C){
ze5aed13a5b01444f5678c6825a5c30fc=TPM_tBypReg_C;}else{if(TPM_bAcvReg){
z21fed86397a19bfad54bda2cfdaa9d19=((UInt32)(((UInt32)TPM_tAddCmdOpl)<<6))+((
UInt32)(SInt32)(TPM_tAddCmdCll>>2));if(z21fed86397a19bfad54bda2cfdaa9d19<((
UInt32)TPM_tExNotReq_C)){ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)
z21fed86397a19bfad54bda2cfdaa9d19;}else{ze5aed13a5b01444f5678c6825a5c30fc=
TPM_tExNotReq_C;}}else{ze5aed13a5b01444f5678c6825a5c30fc=TPM_tExNotReq_C;}}
TPM_tExReq_out=ze5aed13a5b01444f5678c6825a5c30fc;
z07bd6ad0b035f5784d3c8f087a753755=TPM_bAcvReg;zeffbd27d014ac6a46ed446a65e03493d=
z3da27aec5682a60504c205c59823dc29;zbf75324abaf05eda53dbc931bbbe80a9=
ze5aed13a5b01444f5678c6825a5c30fc;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_007_TEV_fct(Void){UInt32 zea9f7cef523d50a32c7cff29217b8ea8[2];SInt32 
zd468f45f7296e73fe1291d4b933ffed7;SInt32 z06f32ff761b03af45c9f63ba6e33e8d9;
SInt32 z91d6bd6fb6e014158f04ff5ae654b748;SInt32 
zda1f01f865fd1b51e129ca10fa784b66;UInt32 z21fed86397a19bfad54bda2cfdaa9d19;
UInt32 z598fc83d17c7afbb99b61c2115312c40;UInt32 
ze7aaa232278aa4bfdf744ffb64ef0932;UInt32 z73d2b71b576f4a88f55f370afa9fe86f;
UInt32 za4b585c36c9215a2cb2eccf272d20fd4;UInt16 
ze5aed13a5b01444f5678c6825a5c30fc;UInt16 z0b07bfb92c95c708197ebf260276e235;
UInt16 z269f16ec85c290b0c12845fa8679d3d3;Boolean 
z3da27aec5682a60504c205c59823dc29;TabIdxS50T513((const UInt16*)
TPM_rStatIgSpEfcX_A,6,TPM_RE007_IgSys_rStatIgSpEfc_in,&(
z5c62cb7bb3dd9c3cd91dac2c5abd7fc9),&(z0269c26ac184c8529467cfc37d2ec13f));
TabIdxS50T513((const UInt16*)TPM_mfTotExCorY_A,9,TPM_RE007_ExM_mfEgTot_in,&(
za53491f9e7fc20dfb59fb341ccaca186),&(zc392b71841ee68c18553c73642e6e9a0));
z0018ca02008a7529d8fe840dd7b08f01=(SInt8)(Tab2DIntp2I1T33281((const UInt16*)&(
TPM_facIgCorGsl_M[0][0]),9,z5c62cb7bb3dd9c3cd91dac2c5abd7fc9,
z0269c26ac184c8529467cfc37d2ec13f,za53491f9e7fc20dfb59fb341ccaca186,
zc392b71841ee68c18553c73642e6e9a0)>>7);z21fed86397a19bfad54bda2cfdaa9d19=((
UInt32)TPM_RE007_ExM_facCorIgProtComp_in)*((UInt32)
z0018ca02008a7529d8fe840dd7b08f01);if(TPM_RE007_TPM_bAirLdLimTExMgr_in&&(!(
z09f22c54a83008c7f0e6a9257e383094))){z598fc83d17c7afbb99b61c2115312c40=(UInt32)(
z21fed86397a19bfad54bda2cfdaa9d19<<13);}else{if(TPM_facFilFacCorProtComp_C){
ze5aed13a5b01444f5678c6825a5c30fc=TPM_facFilFacCorProtComp_C;}else{
ze5aed13a5b01444f5678c6825a5c30fc=0;}if(zf89e3734b87119fb5b2cc8f4ea80a0d2){
ze7aaa232278aa4bfdf744ffb64ef0932=ze4938ff37c77cdff67c4d2dfe18044d8;}else{
ze7aaa232278aa4bfdf744ffb64ef0932=(UInt32)(z21fed86397a19bfad54bda2cfdaa9d19<<13
);}F__U64MULU32U32((UInt32)(UInt16)(((UInt16)(-ze5aed13a5b01444f5678c6825a5c30fc
))+8192),ze7aaa232278aa4bfdf744ffb64ef0932,&(z73d2b71b576f4a88f55f370afa9fe86f),
&(za4b585c36c9215a2cb2eccf272d20fd4));z598fc83d17c7afbb99b61c2115312c40=(
z21fed86397a19bfad54bda2cfdaa9d19*((UInt32)ze5aed13a5b01444f5678c6825a5c30fc))+
C__U32SHRU64C6_LT32(z73d2b71b576f4a88f55f370afa9fe86f,
za4b585c36c9215a2cb2eccf272d20fd4,13,19);}if(z9bc1fab8b3f8bb5978448812fda0a0b5){
ze7aaa232278aa4bfdf744ffb64ef0932=(UInt32)(z598fc83d17c7afbb99b61c2115312c40>>13
);}else{ze7aaa232278aa4bfdf744ffb64ef0932=z21fed86397a19bfad54bda2cfdaa9d19;}
z3da27aec5682a60504c205c59823dc29=ze7aaa232278aa4bfdf744ffb64ef0932!=0;if(
z3da27aec5682a60504c205c59823dc29){z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(
ze7aaa232278aa4bfdf744ffb64ef0932>>1);z7c1e3da8683b717fdc571a1630ac0c46=(SInt32)
(((UInt32)(((UInt32)TPM_RE007_TPM_tExReq_in)<<13))/C__I32SATU32_SATb(
z21fed86397a19bfad54bda2cfdaa9d19,65535,1));}if(
z3da27aec5682a60504c205c59823dc29){zd468f45f7296e73fe1291d4b933ffed7=
z7c1e3da8683b717fdc571a1630ac0c46;}else{zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)TPM_RE007_TPM_tExReq_in;}TPM_tExBasReqStep1_MP=C__U32SATI32_SATb(
zd468f45f7296e73fe1291d4b933ffed7,72672,7136);if(
TPM_RE007_TPM_bAirLdLimTExMgr_in&&(!(z8256e4b531f76057949727815e15bffc))){
z21fed86397a19bfad54bda2cfdaa9d19=(UInt32)(TPM_tExBasReqStep1_MP<<13);}else{if(
TPM_facFilTExBasReq_C){ze5aed13a5b01444f5678c6825a5c30fc=TPM_facFilTExBasReq_C;}
else{ze5aed13a5b01444f5678c6825a5c30fc=0;}if(zb740ff4154c989352e0c0fb6c919d44c){
ze7aaa232278aa4bfdf744ffb64ef0932=z320d20145d31ca1901fbeea7f3dcbb20;}else{
ze7aaa232278aa4bfdf744ffb64ef0932=(UInt32)(TPM_tExBasReqStep1_MP<<13);}
F__U64MULU32U32((UInt32)(UInt16)(((UInt16)(-ze5aed13a5b01444f5678c6825a5c30fc))+
8192),ze7aaa232278aa4bfdf744ffb64ef0932,&(z73d2b71b576f4a88f55f370afa9fe86f),&(
za4b585c36c9215a2cb2eccf272d20fd4));z21fed86397a19bfad54bda2cfdaa9d19=(
TPM_tExBasReqStep1_MP*((UInt32)ze5aed13a5b01444f5678c6825a5c30fc))+
C__U32SHRU64C6_LT32(z73d2b71b576f4a88f55f370afa9fe86f,
za4b585c36c9215a2cb2eccf272d20fd4,13,19);}if(z7e84a9459defeab4df370f72aa772ee2){
TPM_tExBasReq=(UInt32)(z21fed86397a19bfad54bda2cfdaa9d19>>13);}else{
TPM_tExBasReq=TPM_tExBasReqStep1_MP;}TabIdxS50T513((const UInt16*)TPM_nEng18X_A,
18,TPM_RE007_Ext_nEng_in,&(zb4a28b6d16f52566ff7feef4361efd75),&(
z999e2ff6eccf0f03fc1d2c072b3551c7));TabIdxS50T514((const UInt32*)
TPM_tExBasReqY_A,16,TPM_tExBasReq,&(z68dd5ef6ca619b751814bc81cf3b0285),&(
z56d1d206d1d220bfcf7bac7bc674b2bc));z3bbc2b5f4f525e241eb407fd4357b48c=
Tab2DIntp2I1T33281((const UInt16*)&(TPM_rAirLdReqFlex_M[0][0]),16,
zb4a28b6d16f52566ff7feef4361efd75,z999e2ff6eccf0f03fc1d2c072b3551c7,
z68dd5ef6ca619b751814bc81cf3b0285,z56d1d206d1d220bfcf7bac7bc674b2bc);
TabIdxS50T513((const UInt16*)TPM_nEng18X_A,18,TPM_RE007_Ext_nEng_in,&(
zd0dca0a9fddb230bee7c91132fa3890e),&(z38a7f1edbb2cd9238d01fb2e55628f77));
TabIdxS50T514((const UInt32*)TPM_tExBasReqY_A,16,TPM_tExBasReq,&(
z53360e0c96f2e5df1239cdf4a834fa60),&(zf7b97cfa50f367b444d8f090f7a07f5c));
z149e4e954877623f0025a17d41f58f80=Tab2DIntp2I1T33281((const UInt16*)&(
TPM_rAirLdReqMid_M[0][0]),16,zd0dca0a9fddb230bee7c91132fa3890e,
z38a7f1edbb2cd9238d01fb2e55628f77,z53360e0c96f2e5df1239cdf4a834fa60,
zf7b97cfa50f367b444d8f090f7a07f5c);if(TPM_bSelRatAirLdReq_C){
z7610faa7f7dd8d83a84a693ccc2b264f=(UInt16)(((UInt16)TPM_rSelRatAirLdReq_C)<<8);}
else{if(TPM_RE007_ExM_prm_facGas_in[0]){ze5aed13a5b01444f5678c6825a5c30fc=
TPM_RE007_ExM_prm_facGas_in[0];}else{ze5aed13a5b01444f5678c6825a5c30fc=0;}if(
TPM_RE007_ExM_prm_facFlex_in[0]){z0b07bfb92c95c708197ebf260276e235=
TPM_RE007_ExM_prm_facFlex_in[0];}else{z0b07bfb92c95c708197ebf260276e235=0;}
TPM_rAirLdReqFlex=z3bbc2b5f4f525e241eb407fd4357b48c;TPM_rAirLdReqMid=
z149e4e954877623f0025a17d41f58f80;ze7aaa232278aa4bfdf744ffb64ef0932=((UInt32)(
SInt32)((((SInt32)z0b07bfb92c95c708197ebf260276e235)*((SInt32)(((UInt32)
TPM_rAirLdReqFlex)-((UInt32)TPM_rAirLdReqMid))))>>14))+((UInt32)TPM_rAirLdReqMid
);TPM_rAirLdGslFlex_MP=(UInt32)C__U16SATU32_SATu(
ze7aaa232278aa4bfdf744ffb64ef0932,49152);if(TPM_bAcvGas_C){
zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)
TPM_RE007_TPM_rAirLdReqGas_in)<<12);}else{zd468f45f7296e73fe1291d4b933ffed7=(
SInt32)((((UInt32)TPM_RE007_TPM_rAirLdReqGas_in)+TPM_rAirLdGslFlex_MP)<<12);}
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(((UInt32)
zd468f45f7296e73fe1291d4b933ffed7)-((UInt32)(SInt32)(TPM_rAirLdGslFlex_MP<<12)))
;F__I64MULU32I32((UInt32)ze5aed13a5b01444f5678c6825a5c30fc,
z06f32ff761b03af45c9f63ba6e33e8d9,&(zd468f45f7296e73fe1291d4b933ffed7),&(
ze7aaa232278aa4bfdf744ffb64ef0932));z73d2b71b576f4a88f55f370afa9fe86f=((UInt32)(
SInt32)(C__I32SHRI64C6_LT32(zd468f45f7296e73fe1291d4b933ffed7,
ze7aaa232278aa4bfdf744ffb64ef0932,14,18)>>12))+TPM_rAirLdGslFlex_MP;
z7610faa7f7dd8d83a84a693ccc2b264f=C__U16SATU32_SATu(
z73d2b71b576f4a88f55f370afa9fe86f,49152);}z3da27aec5682a60504c205c59823dc29=
TPM_RE007_TPM_bAirLdLimTExMgr_in||RE007_TPM_bAcvProtExScv_in;if(
z3da27aec5682a60504c205c59823dc29){ze5aed13a5b01444f5678c6825a5c30fc=
TPM_RE007_EngM_rAirLdCor_in;}else{ze5aed13a5b01444f5678c6825a5c30fc=
TPM_rAirLdMax_C;}if(z63932db0640ab683e8069d110a030bcb){if(
TPM_RE007_TPM_bAirLdLimTExMgr_in){z0b07bfb92c95c708197ebf260276e235=
z7610faa7f7dd8d83a84a693ccc2b264f;}else{z0b07bfb92c95c708197ebf260276e235=
TPM_rAirLdMax_C;}if(z0b07bfb92c95c708197ebf260276e235<RE007_TPM_rAirLdReqRbl_in)
{z269f16ec85c290b0c12845fa8679d3d3=z0b07bfb92c95c708197ebf260276e235;}else{
z269f16ec85c290b0c12845fa8679d3d3=RE007_TPM_rAirLdReqRbl_in;}}else{
z269f16ec85c290b0c12845fa8679d3d3=ze5aed13a5b01444f5678c6825a5c30fc;}
RE007_TPM_rAirLdReq_out=z7610faa7f7dd8d83a84a693ccc2b264f;if(
z3da27aec5682a60504c205c59823dc29&&(!(zd39a750fbcf3ea0eaf7246aee3eccf5a))){
zea9f7cef523d50a32c7cff29217b8ea8[0]=12800;zea9f7cef523d50a32c7cff29217b8ea8[1]=
12800;}else{zea9f7cef523d50a32c7cff29217b8ea8[0]=(UInt32)(TPM_facRampInc_C>>23);
zea9f7cef523d50a32c7cff29217b8ea8[1]=(UInt32)(TPM_facRampDec_C>>23);}
C__U64SHLU32C6_LT32(((UInt32)TPM_tiSdlTPM_C)*zea9f7cef523d50a32c7cff29217b8ea8[0
],15,17,ze7aaa232278aa4bfdf744ffb64ef0932,z73d2b71b576f4a88f55f370afa9fe86f);
C__U32DIVU64U32(ze7aaa232278aa4bfdf744ffb64ef0932,
z73d2b71b576f4a88f55f370afa9fe86f,(UInt32)125,za4b585c36c9215a2cb2eccf272d20fd4)
;if(zc72a1c1d959fed6406f28fe5a965dd9a){z0b07bfb92c95c708197ebf260276e235=
zadd9bc2091480845f6552a34ca4eda2f;}else{z0b07bfb92c95c708197ebf260276e235=
ze5aed13a5b01444f5678c6825a5c30fc;}zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((
UInt32)z269f16ec85c290b0c12845fa8679d3d3)-((UInt32)
z0b07bfb92c95c708197ebf260276e235));C__I64SHLI32C6_LT32(((SInt32)TPM_tiSdlTPM_C)
*(-((SInt32)zea9f7cef523d50a32c7cff29217b8ea8[1])),14,18,
z06f32ff761b03af45c9f63ba6e33e8d9,ze7aaa232278aa4bfdf744ffb64ef0932);
C__I32DIVI64U32(z06f32ff761b03af45c9f63ba6e33e8d9,
ze7aaa232278aa4bfdf744ffb64ef0932,(UInt32)125,z91d6bd6fb6e014158f04ff5ae654b748)
;z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(z91d6bd6fb6e014158f04ff5ae654b748>>
10);if(zd468f45f7296e73fe1291d4b933ffed7>z06f32ff761b03af45c9f63ba6e33e8d9){
z91d6bd6fb6e014158f04ff5ae654b748=zd468f45f7296e73fe1291d4b933ffed7;}else{
z91d6bd6fb6e014158f04ff5ae654b748=z06f32ff761b03af45c9f63ba6e33e8d9;}
z06f32ff761b03af45c9f63ba6e33e8d9=(SInt32)(UInt32)(
za4b585c36c9215a2cb2eccf272d20fd4>>11);if(z06f32ff761b03af45c9f63ba6e33e8d9<
z91d6bd6fb6e014158f04ff5ae654b748){zda1f01f865fd1b51e129ca10fa784b66=
z06f32ff761b03af45c9f63ba6e33e8d9;}else{zda1f01f865fd1b51e129ca10fa784b66=
z91d6bd6fb6e014158f04ff5ae654b748;}ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(((
UInt16)zda1f01f865fd1b51e129ca10fa784b66)+z0b07bfb92c95c708197ebf260276e235);if(
TPM_bSelRatLdProtExThermo_C){TPM_rLdProtExThermo_out=(UInt16)(((UInt16)
TPM_rSelRatLdProtExThermo_C)<<8);}else{TPM_rLdProtExThermo_out=
ze5aed13a5b01444f5678c6825a5c30fc;}C__I64SHLI32C6_LT32(
zd468f45f7296e73fe1291d4b933ffed7,11,21,z06f32ff761b03af45c9f63ba6e33e8d9,
ze7aaa232278aa4bfdf744ffb64ef0932);C__I64COPYU32(
za4b585c36c9215a2cb2eccf272d20fd4,zd468f45f7296e73fe1291d4b933ffed7,
ze7aaa232278aa4bfdf744ffb64ef0932);z8256e4b531f76057949727815e15bffc=
TPM_RE007_TPM_bAirLdLimTExMgr_in;z09f22c54a83008c7f0e6a9257e383094=
TPM_RE007_TPM_bAirLdLimTExMgr_in;zf89e3734b87119fb5b2cc8f4ea80a0d2=1;
ze4938ff37c77cdff67c4d2dfe18044d8=z598fc83d17c7afbb99b61c2115312c40;
z9bc1fab8b3f8bb5978448812fda0a0b5=1;zb740ff4154c989352e0c0fb6c919d44c=1;
z320d20145d31ca1901fbeea7f3dcbb20=z21fed86397a19bfad54bda2cfdaa9d19;
z7e84a9459defeab4df370f72aa772ee2=1;z63932db0640ab683e8069d110a030bcb=
z3da27aec5682a60504c205c59823dc29;zd39a750fbcf3ea0eaf7246aee3eccf5a=
z3da27aec5682a60504c205c59823dc29;zc72a1c1d959fed6406f28fe5a965dd9a=1;
zadd9bc2091480845f6552a34ca4eda2f=ze5aed13a5b01444f5678c6825a5c30fc;}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_008_TEV_fct(Void){UInt32 z21fed86397a19bfad54bda2cfdaa9d19;UInt32 
z598fc83d17c7afbb99b61c2115312c40;UInt32 ze7aaa232278aa4bfdf744ffb64ef0932;
UInt32 z73d2b71b576f4a88f55f370afa9fe86f;UInt32 
za4b585c36c9215a2cb2eccf272d20fd4;UInt32 zc448fdb238f1f5441dacdcbbe8b48216;
UInt16 ze5aed13a5b01444f5678c6825a5c30fc;UInt16 
z0b07bfb92c95c708197ebf260276e235;if(PhyMSI_bAcvTTrbCase_C){
PhyMSI_tTrbCaseEstimPrev=TPM_RE008_PhyMSI_tTrbCaseEstim_in;
z21fed86397a19bfad54bda2cfdaa9d19=(((UInt32)PhyMSI_tTrbCaseEstimPrev)*((UInt32)
PhyMSI_rCppTrbCase_C))+((UInt32)(((UInt32)PhyMSI_cppTrbCase_C)<<12));
TabIdxS50T514((const UInt32*)PhyMSI_mfEg_facEgTrbCase_A,8,(UInt32)
TPM_RE008_ExM_mfEgWoutEGR_in,&(z535ddc9e9989b251662caf9306e11f0f),&(
z42628718f74dc73dadb957e546d86dee));zcd43b690230d13f06a3e0010edbd62a3=
Tab1DIntp2I1T65((const UInt16*)PhyMSI_facEgTrbCaseHeatExg_T,
z535ddc9e9989b251662caf9306e11f0f,z42628718f74dc73dadb957e546d86dee);
ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)((((UInt32)
zcd43b690230d13f06a3e0010edbd62a3)*52429)>>14);TabIdxS50T512((const UInt8*)
PhyMSI_rSpdFan_facExtTrbCaseX_A,8,(UInt8)(TPM_RE008_Veh_spdVeh_in>>8),&(
z5679d88a7df62720c532227da2f27f03),&(ze87bafe4f5e46708f7b8aaac5bf48fd9));
TabIdxS50T513((const UInt16*)PhyMSI_spdVeh_facExtTrbCaseY_A,10,(UInt16)(((UInt16
)TPM_RE008_Ext_rSpdFanAct_in)<<8),&(z67cbaad2dca13f407bf0e26e2a4a345f),&(
zcae450bd13f7ebdb28389ee57eac9ecf));z694e56cfbb611871ab99e3c363cb8e24=
Tab2DIntp2I1T33281((const UInt16*)&(PhyMSI_facExtTrbCaseHeatExg_M[0][0]),10,
z5679d88a7df62720c532227da2f27f03,ze87bafe4f5e46708f7b8aaac5bf48fd9,
z67cbaad2dca13f407bf0e26e2a4a345f,zcae450bd13f7ebdb28389ee57eac9ecf);
z0b07bfb92c95c708197ebf260276e235=z694e56cfbb611871ab99e3c363cb8e24*51;
z598fc83d17c7afbb99b61c2115312c40=((UInt32)(z21fed86397a19bfad54bda2cfdaa9d19<<2
))+((UInt32)(((UInt32)(UInt16)((((UInt32)ze5aed13a5b01444f5678c6825a5c30fc)+((
UInt32)z0b07bfb92c95c708197ebf260276e235))>>2))<<7));
ze7aaa232278aa4bfdf744ffb64ef0932=(UInt32)(UInt8)(1<<2);if(
ze7aaa232278aa4bfdf744ffb64ef0932>z598fc83d17c7afbb99b61c2115312c40){
z73d2b71b576f4a88f55f370afa9fe86f=ze7aaa232278aa4bfdf744ffb64ef0932;}else{
z73d2b71b576f4a88f55f370afa9fe86f=z598fc83d17c7afbb99b61c2115312c40;}if(
z73d2b71b576f4a88f55f370afa9fe86f!=0){z598fc83d17c7afbb99b61c2115312c40=((UInt32
)(((UInt16)(((SInt16)TPM_RE008_Ext_tAir_in)+273))*((UInt16)
PhyMSI_rAirRatTrbCase_C)))+((UInt32)(((UInt16)PhyMSI_rCoRatTrbCase_C)*((UInt16)(
TPM_RE008_Ext_tCoMes_in+273))));F__U64MULU32U32((UInt32)
z0b07bfb92c95c708197ebf260276e235,z598fc83d17c7afbb99b61c2115312c40,&(
ze7aaa232278aa4bfdf744ffb64ef0932),&(za4b585c36c9215a2cb2eccf272d20fd4));
F__U64MULU32U32((UInt32)PhyMSI_tTrbCaseEstimPrev,
z21fed86397a19bfad54bda2cfdaa9d19,&(z598fc83d17c7afbb99b61c2115312c40),&(
zc448fdb238f1f5441dacdcbbe8b48216));z21fed86397a19bfad54bda2cfdaa9d19=
C__U32SHRU64C6_LT32(z598fc83d17c7afbb99b61c2115312c40,
zc448fdb238f1f5441dacdcbbe8b48216,9,23)+((UInt32)((((UInt32)((((UInt32)
TPM_RE008_ExM_tExMnfEstim_in)*((UInt32)ze5aed13a5b01444f5678c6825a5c30fc))>>1))+
((UInt32)(((UInt32)ze5aed13a5b01444f5678c6825a5c30fc)*3568))+((UInt32)(
C__U32SHRU64C6_LT32(ze7aaa232278aa4bfdf744ffb64ef0932,
za4b585c36c9215a2cb2eccf272d20fd4,1,31)>>2)))>>5));C__U64SHLU32C6_LT32(
z21fed86397a19bfad54bda2cfdaa9d19,20,12,z598fc83d17c7afbb99b61c2115312c40,
ze7aaa232278aa4bfdf744ffb64ef0932);C__U32DIVU64U32(
z598fc83d17c7afbb99b61c2115312c40,ze7aaa232278aa4bfdf744ffb64ef0932,
z73d2b71b576f4a88f55f370afa9fe86f,z21fed86397a19bfad54bda2cfdaa9d19);}else{
z21fed86397a19bfad54bda2cfdaa9d19=4294967295U;}z598fc83d17c7afbb99b61c2115312c40
=(UInt32)(z21fed86397a19bfad54bda2cfdaa9d19>>9);if(
z598fc83d17c7afbb99b61c2115312c40>7136){z21fed86397a19bfad54bda2cfdaa9d19=
z598fc83d17c7afbb99b61c2115312c40;}else{z21fed86397a19bfad54bda2cfdaa9d19=7136;}
if(48736<z21fed86397a19bfad54bda2cfdaa9d19){zba18a747dc27f22ec0342f1568c76289=
48736;}else{zba18a747dc27f22ec0342f1568c76289=z21fed86397a19bfad54bda2cfdaa9d19;
}}if(PhyMSI_bAcvTExMnf_C){PhyMSI_tExMnfEstimPrev=TPM_RE008_PhyMSI_tExMnfEstim_in
;z21fed86397a19bfad54bda2cfdaa9d19=(((UInt32)PhyMSI_tExMnfEstimPrev)*((UInt32)
PhyMSI_rCppExMnf_C))+((UInt32)(((UInt32)PhyMSI_cppExMnf_C)<<12));TabIdxS50T514((
const UInt32*)PhyMSI_mfEg_facEgExMnf_A,8,(UInt32)TPM_RE008_ExM_mfEgWoutEGR_in,&(
z9b923c74f7e83cb82e6aae10406a9350),&(zf6e1cc00b69ce6a8a30dda9884ab8ef8));
z424016e8f4c95386cc9bfbf3b005c872=Tab1DIntp2I1T65((const UInt16*)
PhyMSI_facEgExMnfHeatExg_T,z9b923c74f7e83cb82e6aae10406a9350,
zf6e1cc00b69ce6a8a30dda9884ab8ef8);ze5aed13a5b01444f5678c6825a5c30fc=(UInt16)(((
UInt32)(((UInt32)z424016e8f4c95386cc9bfbf3b005c872)<<4))/5);TabIdxS50T512((const
 UInt8*)PhyMSI_rSpdFan_facExtExMnfX_A,8,TPM_RE008_Ext_rSpdFanAct_in,&(
zade34fef6c50bfb037cabc6681437549),&(z459564cb29de6694fc422f50235bebff));
TabIdxS50T513((const UInt16*)PhyMSI_spdVeh_facExtExMnfY_A,10,
TPM_RE008_Veh_spdVeh_in,&(z488e38854283bb9a6bcc49d8b78ab5a1),&(
zb781d7d8150b0c8dc57418b4b5a151c4));zaea03dac07973206d10a78d25774ca5c=
Tab2DIntp2I1T33281((const UInt16*)&(PhyMSI_facExtExMnfHeatExg_M[0][0]),10,
zade34fef6c50bfb037cabc6681437549,z459564cb29de6694fc422f50235bebff,
z488e38854283bb9a6bcc49d8b78ab5a1,zb781d7d8150b0c8dc57418b4b5a151c4);
z0b07bfb92c95c708197ebf260276e235=(UInt16)(((UInt32)(((UInt32)
zaea03dac07973206d10a78d25774ca5c)<<8))/5);z598fc83d17c7afbb99b61c2115312c40=((
UInt32)(z21fed86397a19bfad54bda2cfdaa9d19<<2))+((UInt32)(((UInt32)(UInt16)((((
UInt32)ze5aed13a5b01444f5678c6825a5c30fc)+((UInt32)
z0b07bfb92c95c708197ebf260276e235))>>2))<<7));ze7aaa232278aa4bfdf744ffb64ef0932=
(UInt32)(UInt8)(1<<2);if(ze7aaa232278aa4bfdf744ffb64ef0932>
z598fc83d17c7afbb99b61c2115312c40){z73d2b71b576f4a88f55f370afa9fe86f=
ze7aaa232278aa4bfdf744ffb64ef0932;}else{z73d2b71b576f4a88f55f370afa9fe86f=
z598fc83d17c7afbb99b61c2115312c40;}if(z73d2b71b576f4a88f55f370afa9fe86f!=0){
z598fc83d17c7afbb99b61c2115312c40=((UInt32)(((UInt16)(((SInt16)
TPM_RE008_Ext_tAir_in)+273))*((UInt16)PhyMSI_rAirRatExMnf_C)))+((UInt32)(((
UInt16)PhyMSI_rCoRatExMnf_C)*((UInt16)(TPM_RE008_Ext_tCoMes_in+273))));
F__U64MULU32U32((UInt32)z0b07bfb92c95c708197ebf260276e235,
z598fc83d17c7afbb99b61c2115312c40,&(ze7aaa232278aa4bfdf744ffb64ef0932),&(
za4b585c36c9215a2cb2eccf272d20fd4));F__U64MULU32U32((UInt32)
PhyMSI_tExMnfEstimPrev,z21fed86397a19bfad54bda2cfdaa9d19,&(
z598fc83d17c7afbb99b61c2115312c40),&(zc448fdb238f1f5441dacdcbbe8b48216));
z21fed86397a19bfad54bda2cfdaa9d19=C__U32SHRU64C6_LT32(
z598fc83d17c7afbb99b61c2115312c40,zc448fdb238f1f5441dacdcbbe8b48216,9,23)+((
UInt32)((((UInt32)((((UInt32)TPM_RE008_ExM_tExMnfEstim_in)*((UInt32)
ze5aed13a5b01444f5678c6825a5c30fc))>>1))+((UInt32)(((UInt32)
ze5aed13a5b01444f5678c6825a5c30fc)*3568))+((UInt32)(C__U32SHRU64C6_LT32(
ze7aaa232278aa4bfdf744ffb64ef0932,za4b585c36c9215a2cb2eccf272d20fd4,1,31)>>2)))
>>5));C__U64SHLU32C6_LT32(z21fed86397a19bfad54bda2cfdaa9d19,20,12,
z598fc83d17c7afbb99b61c2115312c40,ze7aaa232278aa4bfdf744ffb64ef0932);
C__U32DIVU64U32(z598fc83d17c7afbb99b61c2115312c40,
ze7aaa232278aa4bfdf744ffb64ef0932,z73d2b71b576f4a88f55f370afa9fe86f,
z21fed86397a19bfad54bda2cfdaa9d19);}else{z21fed86397a19bfad54bda2cfdaa9d19=
4294967295U;}z598fc83d17c7afbb99b61c2115312c40=(UInt32)(
z21fed86397a19bfad54bda2cfdaa9d19>>9);if(z598fc83d17c7afbb99b61c2115312c40>7136)
{z21fed86397a19bfad54bda2cfdaa9d19=z598fc83d17c7afbb99b61c2115312c40;}else{
z21fed86397a19bfad54bda2cfdaa9d19=7136;}if(48736<
z21fed86397a19bfad54bda2cfdaa9d19){z8989133d93740c8f1c1077973b405856=48736;}else
{z8989133d93740c8f1c1077973b405856=z21fed86397a19bfad54bda2cfdaa9d19;}}
PhyMSI_tTrbCaseEstim_out=(UInt16)zba18a747dc27f22ec0342f1568c76289;
PhyMSI_tExMnfEstim_out=(UInt16)z8989133d93740c8f1c1077973b405856;if(
PhyMSI_bAcvPwrCylHd_C){TabIdxS50T514((const UInt32*)PhyMSI_rAirLd_pwrCylHdX_A,16
,(UInt32)TPM_RE008_EngM_rAirLdCor_in,&(zbce73f872e4d34b5157b4d06ed2891e4),&(
zbf3d2a15eaf8a1bafd63dd685978ec2a));TabIdxS50T513((const UInt16*)
PhyMSI_nEng_pwrCylHdY_A,20,TPM_RE008_Ext_nEng_in,&(
zb498d899cfa965de278bcc9a92086e13),&(z4df52fe517c6ce6eaf64521f0176b465));
zd5d55425a9124e825d981a7d8c2cf789=(UInt16)(Tab2DIntp2I1T33281((const UInt16*)&(
PhyMSI_pwrCylHdEstim_M[0][0]),20,zbce73f872e4d34b5157b4d06ed2891e4,
zbf3d2a15eaf8a1bafd63dd685978ec2a,zb498d899cfa965de278bcc9a92086e13,
z4df52fe517c6ce6eaf64521f0176b465)<<7);TabIdxS50T513((const UInt16*)
PhyMSI_rMixtCylPwrHd_A,8,TPM_RE008_FARSp_rMixtCylSp_in,&(
zdd44e6bdbcdda5c66e839f2a9889d87c),&(z8bc044e03fe786fadc6d6cd7ab4a1424));
zeaba0127f6735e7ede2864d8def2c7ae=Tab1DIntp2I1T66((const UInt32*)
PhyMSI_facPwrCylHdCor_T,zdd44e6bdbcdda5c66e839f2a9889d87c,
z8bc044e03fe786fadc6d6cd7ab4a1424);if(zeaba0127f6735e7ede2864d8def2c7ae>512){
z21fed86397a19bfad54bda2cfdaa9d19=zeaba0127f6735e7ede2864d8def2c7ae;}else{
z21fed86397a19bfad54bda2cfdaa9d19=512;}ze5aed13a5b01444f5678c6825a5c30fc=(UInt16
)(((UInt32)(((UInt32)zd5d55425a9124e825d981a7d8c2cf789)<<8))/
z21fed86397a19bfad54bda2cfdaa9d19);z3d26d4a85063ecb268f95a58308ab171=
C__U16SATU16_SATu(ze5aed13a5b01444f5678c6825a5c30fc,320);}
PhyMSI_pwrCylHdEstim_out=z3d26d4a85063ecb268f95a58308ab171;TPM_sNV_Z1_CST_16BIT.
PhyMSI_tTrbCaseEstim_NV=(UInt16)(((UInt16)(((UInt16)(
zba18a747dc27f22ec0342f1568c76289>>1))<<1))+58400);TPM_sNV_Z1_CST_16BIT.
PhyMSI_tExMnfEstim_NV=(UInt16)(((UInt16)(((UInt16)(
z8989133d93740c8f1c1077973b405856>>1))<<1))+58400);}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_009_DRE_fct(Void){if(PhyMSI_bAcvPCylMax_C){TabIdxS50T514((const UInt32*
)PhyMSI_rAirLd_pCylMaxX_A,16,(UInt32)TPM_RE009_EngM_rAirLdCor_in,&(
z7ea1447b7b4593821e61e37d9dbbbe5e),&(z2fa9d32034c66af2b1002008884f5b2b));
TabIdxS50T513((const UInt16*)PhyMSI_nEng_pCylMaxY_A,20,TPM_RE009_Ext_nEng_in,&(
zb3210f69c294b795a9014d1b265eb97d),&(zbe14ffeebbf5c20bec99431707f3a170));
zf5b34358c5a6e71149eb304ab0efdc4f=(UInt32)(Tab2DIntp2I1T33282((const UInt32*)&(
PhyMSI_pCylMaxEstim_M[0][0]),20,z7ea1447b7b4593821e61e37d9dbbbe5e,
z2fa9d32034c66af2b1002008884f5b2b,zb3210f69c294b795a9014d1b265eb97d,
zbe14ffeebbf5c20bec99431707f3a170)<<15);}PhyMSI_pCylMaxEstim_out=(UInt32)(
zf5b34358c5a6e71149eb304ab0efdc4f>>15);}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_Init_MSE_fct(Void){SInt32 zd468f45f7296e73fe1291d4b933ffed7;SInt32 
z06f32ff761b03af45c9f63ba6e33e8d9;SInt32 z91d6bd6fb6e014158f04ff5ae654b748;
PhyMSI_pwrCylHdEstim_out=PhyMSI_pwrCylHdEstimIni_C;
z212637ecea88234c6b95ffc69854b91c=(UInt16)(((SInt16)TPM_RE001_Ext_tAir_in)+273);
TabIdxS50T514((const UInt32*)PhyMSI_tiEngStop_tExMnfIniX_A,8,
TPM_RE001_EOM_tiEngStop_in,&(zfe840e7b3060275a301f19eccd02f641),&(
z62821e632e249793771c8e17b23568b3));TabIdxS50T513((const UInt16*)
PhyMSI_tAir_tExMnfIniY_A,10,z212637ecea88234c6b95ffc69854b91c,&(
z80028e992b391f40eac2a72a07fe3466),&(z61639686d514d1bc75294417daf885e1));
ze168a0c5e7742fed41d599a2886d858c=Tab2DIntp2I1T33281((const UInt16*)&(
PhyMSI_tDeltaExMnfIni_M[0][0]),10,zfe840e7b3060275a301f19eccd02f641,
z62821e632e249793771c8e17b23568b3,z80028e992b391f40eac2a72a07fe3466,
z61639686d514d1bc75294417daf885e1);if(TPM_RE001_EOM_tiEngStop_in>=((UInt32)
PhyMSI_tiExMnfThd_C)){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)
z212637ecea88234c6b95ffc69854b91c)<<5);}else{zd468f45f7296e73fe1291d4b933ffed7=(
(SInt32)(((UInt32)TEMP_PhyMSI_tExMnfEstim_NV)-((UInt32)(SInt32)(
ze168a0c5e7742fed41d599a2886d858c>>1))))+7136;}z06f32ff761b03af45c9f63ba6e33e8d9
=(SInt32)(UInt32)(((UInt32)z212637ecea88234c6b95ffc69854b91c)<<5);if(
z06f32ff761b03af45c9f63ba6e33e8d9>zd468f45f7296e73fe1291d4b933ffed7){
z91d6bd6fb6e014158f04ff5ae654b748=z06f32ff761b03af45c9f63ba6e33e8d9;}else{
z91d6bd6fb6e014158f04ff5ae654b748=zd468f45f7296e73fe1291d4b933ffed7;}
PhyMSI_tExMnfEstim_out=C__U16SATI32_SATb(z91d6bd6fb6e014158f04ff5ae654b748,48736
,7136);zd09180c7dd667c635fe7618879d1fd31=(UInt16)(((SInt16)TPM_RE001_Ext_tAir_in
)+273);TabIdxS50T514((const UInt32*)PhyMSI_tiEngStop_tTrbCaseIniX_A,8,
TPM_RE001_EOM_tiEngStop_in,&(z12928cf7d33fd08f08cb514080390dce),&(
z506dedaa45465471a38be4c154bc0f24));TabIdxS50T513((const UInt16*)
PhyMSI_tAir_tTrbCaseIniY_A,10,zd09180c7dd667c635fe7618879d1fd31,&(
zaf84b598eb7e6ccafd22bec08c4e8517),&(zeb472c756e87614dad7dac0d5e69d20a));
zbe2c80059de365a15784ffa4bafabd10=Tab2DIntp2I1T33281((const UInt16*)&(
PhyMSI_tDeltaTrbCaseIni_M[0][0]),10,z12928cf7d33fd08f08cb514080390dce,
z506dedaa45465471a38be4c154bc0f24,zaf84b598eb7e6ccafd22bec08c4e8517,
zeb472c756e87614dad7dac0d5e69d20a);if(TPM_RE001_EOM_tiEngStop_in>=((UInt32)
PhyMSI_tiTrbCaseThd_C)){zd468f45f7296e73fe1291d4b933ffed7=(SInt32)(((UInt32)
zd09180c7dd667c635fe7618879d1fd31)<<5);}else{zd468f45f7296e73fe1291d4b933ffed7=(
(SInt32)(((UInt32)TEMP_PhyMSI_tTrbCaseEstim_NV)-((UInt32)(SInt32)(
zbe2c80059de365a15784ffa4bafabd10>>1))))+7136;}z06f32ff761b03af45c9f63ba6e33e8d9
=(SInt32)(UInt32)(((UInt32)zd09180c7dd667c635fe7618879d1fd31)<<5);if(
z06f32ff761b03af45c9f63ba6e33e8d9>zd468f45f7296e73fe1291d4b933ffed7){
z91d6bd6fb6e014158f04ff5ae654b748=z06f32ff761b03af45c9f63ba6e33e8d9;}else{
z91d6bd6fb6e014158f04ff5ae654b748=zd468f45f7296e73fe1291d4b933ffed7;}
PhyMSI_tTrbCaseEstim_out=C__U16SATI32_SATb(z91d6bd6fb6e014158f04ff5ae654b748,
48736,7136);}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
Void TPM_FctVarInit(Void){SInt32 zd468f45f7296e73fe1291d4b933ffed7;
ExM_stO2HcStgTWC_out=0;PhyMSI_pCylMaxEstim_out=0;PhyMSI_pwrCylHdEstim_out=0;
PhyMSI_tExMnfEstim_out=7136;PhyMSI_tTrbCaseEstim_out=7136;
RE002_TPM_mfAirScvLimMax_out=0;RE002_TPM_tRefTWCScvMax_out=0;
RE003_TPM_noAcvThermoProtDev_out=0;RE003_TPM_tExCurAcvThermoProtDev_out=0;
RE003_TPM_tTWC_out=0;RE004_TPM_bAcvProtExScv_out=0;RE004_TPM_rAirLdReqRbl_out=0;
RE007_TPM_rAirLdReq_out=0;z2073fea7712adde1aeab47a6c62c3696=0;
z83e6e8e7443d0d47afcbb1d6ee1905a0=0;z751b528547dcef53601fdbbbd3fbaa9f=0;
za4e562df19791d83709676cddb0b8028=0;zc392b71841ee68c18553c73642e6e9a0=0;
za53491f9e7fc20dfb59fb341ccaca186=0;z0269c26ac184c8529467cfc37d2ec13f=0;
z5c62cb7bb3dd9c3cd91dac2c5abd7fc9=0;z7c1e3da8683b717fdc571a1630ac0c46=0;
zf7b97cfa50f367b444d8f090f7a07f5c=0;z53360e0c96f2e5df1239cdf4a834fa60=0;
z38a7f1edbb2cd9238d01fb2e55628f77=0;zd0dca0a9fddb230bee7c91132fa3890e=0;
z56d1d206d1d220bfcf7bac7bc674b2bc=0;z68dd5ef6ca619b751814bc81cf3b0285=0;
z999e2ff6eccf0f03fc1d2c072b3551c7=0;zb4a28b6d16f52566ff7feef4361efd75=0;
z3d26d4a85063ecb268f95a58308ab171=0;z8bc044e03fe786fadc6d6cd7ab4a1424=0;
zdd44e6bdbcdda5c66e839f2a9889d87c=0;z4df52fe517c6ce6eaf64521f0176b465=0;
zb498d899cfa965de278bcc9a92086e13=0;zbf3d2a15eaf8a1bafd63dd685978ec2a=0;
zbce73f872e4d34b5157b4d06ed2891e4=0;zf6e1cc00b69ce6a8a30dda9884ab8ef8=0;
z9b923c74f7e83cb82e6aae10406a9350=0;zb781d7d8150b0c8dc57418b4b5a151c4=0;
z488e38854283bb9a6bcc49d8b78ab5a1=0;z459564cb29de6694fc422f50235bebff=0;
zade34fef6c50bfb037cabc6681437549=0;z8989133d93740c8f1c1077973b405856=7136;
z42628718f74dc73dadb957e546d86dee=0;z535ddc9e9989b251662caf9306e11f0f=0;
zcae450bd13f7ebdb28389ee57eac9ecf=0;z67cbaad2dca13f407bf0e26e2a4a345f=0;
ze87bafe4f5e46708f7b8aaac5bf48fd9=0;z5679d88a7df62720c532227da2f27f03=0;
zba18a747dc27f22ec0342f1568c76289=7136;zf5b34358c5a6e71149eb304ab0efdc4f=0;
zbe14ffeebbf5c20bec99431707f3a170=0;zb3210f69c294b795a9014d1b265eb97d=0;
z2fa9d32034c66af2b1002008884f5b2b=0;z7ea1447b7b4593821e61e37d9dbbbe5e=0;
z61639686d514d1bc75294417daf885e1=0;z80028e992b391f40eac2a72a07fe3466=0;
z62821e632e249793771c8e17b23568b3=0;zfe840e7b3060275a301f19eccd02f641=0;
zeb472c756e87614dad7dac0d5e69d20a=0;zaf84b598eb7e6ccafd22bec08c4e8517=0;
z506dedaa45465471a38be4c154bc0f24=0;z12928cf7d33fd08f08cb514080390dce=0;
z37194301e86fa1b76255496a16bb208f=0;zb56a24ebf57076f0e75283f82cfeb5bd=0;
zaf63b714216ad8736266569557dd326e=0;z8e73b2fdd2f29a123bf8d802578b41f1=0;
z31e3951fa8e12e0341d264dcf91bdd3c=0;zeccd7b4a5eee45178daebe27fbc25ae7=0;
zee453e997508959edc8e61ecc7f1ff1b=0;za02ab45d7184a5969785fdb1e3c56a57=0;
za7653f54f9cd8888a3dac4944a04dee9=0;zf569b8ac6a053fdff6ae7e9db2af8b35=0;
z508dd42316116c91160501d8dd9fa558=0;z37b0b5f9350985dbdecd85a5f023e77e=0;
z012b6c1ae8d05b5af762ff999f5382f6=0;z4bd435887ee597dd0985584449435063=0;
za8ffccb29850928b689e7bb7dacb5dd2=0;ze374164a558733ef12261b5d878df60c=0;
z86806c86fa3a8cd4cd71deb332465b1c=0;z17658853cd0a1cc88ce15854dbe6d420=0;
zf3208f619f38c5866e55f1d8b64b45b9=0;z101baa0885a8b9c8fca87590a876f65d=0;
z9bfbbc50a6feb4e0b2cf2da945bde25b=0;ze6b63784b37107d27da156b3ff76f6b7=0;
z05984fcf2d7dbb03202309a281558061=0;z0fb436dc4d9a424271d9561523472fbb=0;
z7afbb36daf6c307137171f65651737fd=0;zba77dde50534638bf758da37204ced21=0;
za2f97ce0c6526e204c6cebec85b8c08a=0;zf5f3a58e0312d1090436047e52dfc413=0;
za21850e6def46bf19025e659a2a99e9b=0;z1fafea4e38b1d32f62e3cb9594f0ed92=0;
zb857435c9402aa454a19415717e3e6b5=0;za87bb83c61b06587cb4227ed85752f64=0;
z3ea1e38e46f4cc8965d595eef2c721d1=0;z71bea8e23ecc68d5e1cc405c6d8bcc28=0;
zbd7050086212d78d8c19a3bec4f9c07e=0;z2620ff8d81062a04ccb024dd3fd223ee=0;
z072f7056b773256c69e596594b65c0a9=0;z9d54d1e1a0319a30be30d1f3692559e0=0;
z40a72ebc94864c7eec36f2bb285c6626=0;zda8a07ef6f3c9e6b9bde0f98f9c9474d=0;
TPM_bAcvRichProtOxdTWC_out=0;TPM_bAcvRichThermoProt_out=0;
TPM_bAirLdLimTExMgr_out=0;TPM_bExThermoProt_out=0;TPM_bInhInjCutOff_out=0;
TPM_bInhInjSelCutOff_out=0;TPM_bInhOvbReq_out=0;TPM_bRichLimScv_out=0;
TPM_mfAirScvLimMaxCor_out=0;TPM_rLdProtExThermo_out=0;TPM_rMixtLimMaxAflScv_out=
0;TPM_tAddCmdCll=0;TPM_tAddCmdOpl=0;TPM_tExReq_out=7136;
TPM_tTarAcvThermoProtDev_out=7136;zeb0ecda3e79d047b5d6439d219ae94c2=0;
z82af16d90f8310dac54595db7730cf6d=0;z2db3e7a844f4fc306743bc386244745c=0;
z82b0b31d555204c1fe0f75036f69634d=0;zb3026ac91a9e667604ea0865427ac2c1=0;
zb9e0bbf5224a0cd2f391925391aec4e0=0;zdd5f1f3dee657178ebe3dbc123d9900c=0;
z7a702e59268d760c3f1103a6fd6f1e62=0;z3fada861cdf95110b6e04b1fe5883966=0;
z1d336274b8771934b34fef2f33bd5e2d=0;zabc29a3d4cdabd62d0b89f5259297006=0;
z2c66e88595a50e0cb47734f02078a5ea=0;zd44a61b2e95d9595a5b9e6898b8be6e4=0;
z0236c190df9df9ede94b1b7715a97dd5=0;z937a9d18796810e9c591e7ed544d3417=0;
z63932db0640ab683e8069d110a030bcb=0;z09f22c54a83008c7f0e6a9257e383094=0;
z8256e4b531f76057949727815e15bffc=0;z9bc1fab8b3f8bb5978448812fda0a0b5=0;
zf89e3734b87119fb5b2cc8f4ea80a0d2=0;ze4938ff37c77cdff67c4d2dfe18044d8=0;
z7e84a9459defeab4df370f72aa772ee2=0;zb740ff4154c989352e0c0fb6c919d44c=0;
z320d20145d31ca1901fbeea7f3dcbb20=0;zd39a750fbcf3ea0eaf7246aee3eccf5a=0;
zadd9bc2091480845f6552a34ca4eda2f=0;zc72a1c1d959fed6406f28fe5a965dd9a=0;
z41fa3d5ce3398afab5c003e48c481674=0;z4ec787e92236bb7748dc3a85bb031d1e=0;
zc68d065c4b4ff5330b7da46c9381734b=0;z2d07d203c34c561a8166fdae37c33bda=0;
ze119367927442a24e168287dc42c1419=0;z9faaf4a97ab42e03fb785b9bf34265a6=0;
z72ce00e110723d4a019c24fc1e43f290=0;z0ac6bdc96f479a2298807f6007f6e575=0;
z61f702e660fc002cae41748aa0a44af6=0;z5789054cbcc0eb263da5fa3d1270a2cf=0;
z54beb4eb1364f48e07bb7e3620e5c522=1;z46d85d13b727af93f15b4bed3277b1c9=0;
z8afa732dac1c3494e2be03ec09e7eb74=65534;za38b275d73d6010cf84de6261b1cac8e=0;
z6f71fda760a8ba9894ae0a9433ed9be1=0;zd6256dc956d19116f3c133e11101744c=0;
z2b7cd2f6fc311ad968c13bd63dd05417=0;zbf75324abaf05eda53dbc931bbbe80a9=7136;
z21d095369b9b5aa53db6f41a202e6df1=0;z822ce74faba1cfcc86c02ca647fc7376=0;
z90b540ab8a74466d49971cdff8af2f95=0;zf779a5f75e4029bf1478433d3133291a=0;
z07bd6ad0b035f5784d3c8f087a753755=0;zeffbd27d014ac6a46ed446a65e03493d=0;
subIsv16_TPM_SRSS11_Dev1_0.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev1_0.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev1_0.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev2_0.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev2_0.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev2_0.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev3_0.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev3_0.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev3_0.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev4_0.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev4_0.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev4_0.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev_0.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev_0.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev_0.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev_0_a.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev_0_a.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev_0_a.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv16_TPM_SRSS11_Dev_0_b.z9c22b3fc7b69e4d50c4413feee838b09=0;
subIsv16_TPM_SRSS11_Dev_0_b.zbf2cde9bf24fda796514dc71de3d5aa0=0;
subIsv16_TPM_SRSS11_Dev_0_b.z8a5b80e6c238a0ef64f585912a44bd5f=0;
subIsv8_TPM_SRSS11_Dev1_1.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev1_1.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev1_1.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev1_1.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev1_1.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev1_1.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev1_1.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev1_1.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev2_1.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev2_1.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev2_1.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev2_1.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev2_1.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev2_1.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev2_1.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev2_1.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev3_1.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev3_1.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev3_1.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev3_1.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev3_1.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev3_1.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev3_1.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev3_1.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev4_1.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev4_1.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev4_1.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev4_1.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev4_1.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev4_1.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev4_1.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev4_1.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev_1.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev_1.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev_1.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev_1.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev_1.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev_1.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev_1.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev_1.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev_1_a.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev_1_a.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev_1_a.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev_1_a.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev_1_a.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev_1_a.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev_1_a.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev_1_a.ze0513f3327af7cfe152280b22d133f5e=0;
subIsv8_TPM_SRSS11_Dev_1_b.zea53ee8bdcd8a469b10a4414f309493c=0;
subIsv8_TPM_SRSS11_Dev_1_b.z7dd5ac9b6fdfcc47ab66316db2ba449b=0;
subIsv8_TPM_SRSS11_Dev_1_b.z671c0d3c30fb526e3081cf8a31db6869=0;
subIsv8_TPM_SRSS11_Dev_1_b.z7dce700f8285c7daebd7cfc8a514fc86=0;
subIsv8_TPM_SRSS11_Dev_1_b.zb7f03f9aa4ddd669061935963d4dd0f1=0;
subIsv8_TPM_SRSS11_Dev_1_b.z6bdc06b5a0728b913061dd7ca4dec378=0;
subIsv8_TPM_SRSS11_Dev_1_b.z0ccfb322a7690cef6e789b1f16f17693=0;
subIsv8_TPM_SRSS11_Dev_1_b.ze0513f3327af7cfe152280b22d133f5e=0;for(
zd468f45f7296e73fe1291d4b933ffed7=0;zd468f45f7296e73fe1291d4b933ffed7<=6;(
zd468f45f7296e73fe1291d4b933ffed7)++){zcf3ccb84663209a35029d94badab9f54[
zd468f45f7296e73fe1291d4b933ffed7]=0;}}
#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"
#endif

