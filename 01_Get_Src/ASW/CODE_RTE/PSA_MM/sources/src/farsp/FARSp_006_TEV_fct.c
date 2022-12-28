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
* %name: FARSp_006_TEV_fct.c %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:49 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_006_TEV_fct.c-3.0:csrc:3 %
*
*******************************************************************************/


#ifndef _FARSP_006_TEV_FCT_C_
#define _FARSP_006_TEV_FCT_C_
#include "Library_lut.h"
#include "FARSp_006_TEV_fct.h"
#include "FARSp_006_calibrations.h"
#include "dsfxp.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE006_EngM_mfTotExCor_in;AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE006_FARSp_prm_rMixtGasFlexSp_in[24];AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtSelCutOffSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE006_FARSp_prm_facGasFlexSp_in[24];
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE006_InjSys_noCylCutOff_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bAcvSelCutOffSpcMixt_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z6e09edeb6040427412cf7225c69ee6d6;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
static UInt16 z3cf51bf824d7cf18aa4ee99a9ac407bb;static UInt16 
zee78dc265496b4f082952fc089839bc8;
#define FARSP_STOP_SEC_VAR_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
static UInt8 z98e05431c363acf061a73b73d522aeee;static UInt8 
z20b46e6edfa1de36a13f7209ac801f7c;
#define FARSP_STOP_SEC_VAR_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_005_MSE_ini(Void){FARSp_006_FctVarInit();}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_006_TEV_fct(Void){Boolean zaf2e7f10b7e0189db9c72e073dd54588;
zaf2e7f10b7e0189db9c72e073dd54588=FARSp_RE006_InjSys_noCylCutOff_in!=0;
FARSp_bAcvSelCutOffSpcMixt=zaf2e7f10b7e0189db9c72e073dd54588;if(!(
zaf2e7f10b7e0189db9c72e073dd54588)){z6e09edeb6040427412cf7225c69ee6d6=4096;}if(
zaf2e7f10b7e0189db9c72e073dd54588){SInt32 zdd1b81814e83a6d002bb8e7cde97fb02;
SInt32 z907470d9540636c5e6b1dcbd010ef4eb;UInt8 z22a3cc9473d24817f6713c9e4f2551f8
;UInt8 zea864e66dc2733f6f611aa90b0690ea9;FARSp_facSelCutOffSpGas=
FARSp_RE006_FARSp_prm_facGasFlexSp_in[2];FARSp_facSelCutOffSpFlex=
FARSp_RE006_FARSp_prm_facGasFlexSp_in[3];if(FARSp_facSelCutOffSpGas){
zea864e66dc2733f6f611aa90b0690ea9=FARSp_facSelCutOffSpGas;}else{
zea864e66dc2733f6f611aa90b0690ea9=0;}FARSp_rMixtSelCutOffSpGas=
FARSp_RE006_FARSp_prm_rMixtGasFlexSp_in[2];if(FARSp_facSelCutOffSpFlex){
z22a3cc9473d24817f6713c9e4f2551f8=FARSp_facSelCutOffSpFlex;}else{
z22a3cc9473d24817f6713c9e4f2551f8=0;}FARSp_rMixtSelCutOffSpFlex=
FARSp_RE006_FARSp_prm_rMixtGasFlexSp_in[3];TabIdxS50T514((const UInt32*)
FARSp_mfEgTotSelCutOffX_A,6,(UInt32)FARSp_RE006_EngM_mfTotExCor_in,&(
z20b46e6edfa1de36a13f7209ac801f7c),&(zee78dc265496b4f082952fc089839bc8));
TabIdxS50T512((const UInt8*)FARSp_noCylCutOffY_A,6,
FARSp_RE006_InjSys_noCylCutOff_in,&(z98e05431c363acf061a73b73d522aeee),&(
z3cf51bf824d7cf18aa4ee99a9ac407bb));FARSp_rMixtSelCutOffSpGsl=Tab2DIntp2I1T33281
((const UInt16*)&(FARSp_rMixtSelCutOffSpGsl_M[0][0]),6,
z20b46e6edfa1de36a13f7209ac801f7c,zee78dc265496b4f082952fc089839bc8,
z98e05431c363acf061a73b73d522aeee,z3cf51bf824d7cf18aa4ee99a9ac407bb);
zdd1b81814e83a6d002bb8e7cde97fb02=(SInt32)(((SInt32)((((SInt32)
z22a3cc9473d24817f6713c9e4f2551f8)*((SInt32)(((UInt32)FARSp_rMixtSelCutOffSpFlex
)-((UInt32)FARSp_rMixtSelCutOffSpGsl))))>>7))+((UInt32)FARSp_rMixtSelCutOffSpGsl
));FARSp_rMixtSelCutOffFlex_MP=C__U16SATI32_SATb(
zdd1b81814e83a6d002bb8e7cde97fb02,61440,0);z907470d9540636c5e6b1dcbd010ef4eb=(
SInt32)(((SInt32)((((SInt32)zea864e66dc2733f6f611aa90b0690ea9)*((SInt32)(((
UInt32)FARSp_rMixtSelCutOffSpGas)-((UInt32)FARSp_rMixtSelCutOffFlex_MP))))>>7))+
((UInt32)FARSp_rMixtSelCutOffFlex_MP));z6e09edeb6040427412cf7225c69ee6d6=
C__U16SATI32_SATb(z907470d9540636c5e6b1dcbd010ef4eb,61440,0);}
FARSp_rMixtSelCutOffSp=C__U16SATU16_SATu(z6e09edeb6040427412cf7225c69ee6d6,61440
);FARSp_bAcvSelCutOffSpcMixt_out=FARSp_bAcvSelCutOffSpcMixt;
FARSp_rMixtSelCutOffSp_out=FARSp_rMixtSelCutOffSp;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
Void FARSp_006_FctVarInit(Void){FARSp_rMixtSelCutOffSp_out=4096;
z6e09edeb6040427412cf7225c69ee6d6=0;z3cf51bf824d7cf18aa4ee99a9ac407bb=0;
z98e05431c363acf061a73b73d522aeee=0;zee78dc265496b4f082952fc089839bc8=0;
z20b46e6edfa1de36a13f7209ac801f7c=0;}
#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"
#endif

