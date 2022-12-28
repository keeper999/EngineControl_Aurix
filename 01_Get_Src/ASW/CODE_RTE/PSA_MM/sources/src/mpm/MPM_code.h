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
* %name: MPM_code.h %
*
* %version: 2.0_OBS %
*
* %date_modified: Fri Aug 10 10:45:35 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM_code.h-2.0_OBS:incl:2 %
*
*******************************************************************************/


#ifndef _MPM_CODE_H_
#define _MPM_CODE_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "MPM_Library.h"
struct zc5d13e5e26f662155c9047328b533de6{unsigned int 
z0d8b1fce5f55c340f4d831f107fe6eee:3;unsigned int 
z5e0ed9cceb5ff930b492aa9e4e872518:1;unsigned int 
zac4f71dadd965695bc03119eb6d0f721:1;unsigned int 
zb545d23c50050ca6848fe03e609ad6d6:1;unsigned int 
z78c7f31d06bd4dd7be7650a427afd9ae:1;unsigned int 
z01127a1ce00540cff65c0623678e0a5a:1;unsigned int 
z6e4019b9009cb8853c5e7f3936d0174b:1;unsigned int 
z46020f8af7baf6f7576f6e2ba71447fd:1;unsigned int 
z68c9ded130edcaf96642e2f862315a2b:1;unsigned int 
z2ff74c2db8ae123e85be372daba69b11:1;unsigned int 
z30a1c30e65b0f9be4f082ccc1ea2a95b:1;unsigned int 
z6cce365e430b542e4e3e12d75b08883e:1;unsigned int 
ze5b578446aef4807453a0e3d84e75c21:1;unsigned int 
z17b270e1143f9e32e08cc36230a2c56c:1;unsigned int 
z05feea94d8df128b25f04c21e1b3fb8e:1;unsigned int 
zb2ccd46c3cadcaecfcc4a5124b2f3081:1;unsigned int 
z8725f04fdfaff99498b80f9c5ef5097f:1;unsigned int 
ze01e3888941107e2fa2c02e9556d98cd:1;unsigned int 
za3ea6fe197948f6b7082306bbb4e4451:1;unsigned int 
z17d8bb0e78f5edd0f049657d8de18bb0:1;unsigned int 
zeb15155cb833b9c5d8cfa0adf00e0835:1;unsigned int 
z4ec8b78e01225ea50e126dc9009c754d:1;unsigned int 
za205f83aa25799e05e391aa84af7c58f:1;unsigned int 
zc88ce6cd353f06460d9b64ab61970143:1;unsigned int 
z6bcb8134439057a526e378b22cc18862:1;};
#define MPM_START_SEC_GLOBAL_16BIT
#include "MPM_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 MPM_RE003_PhyMSI_tTrbCaseEstim_in;extern 
AR_IF_GLOBAL_16BIT UInt16 MPM_RE004_PhyMSI_tExMnfEstim_in;extern 
AR_IF_GLOBAL_16BIT UInt16 MPM_RE005_PhyMSI_pwrCylHdEstim_in;extern 
AR_IF_GLOBAL_16BIT UInt16 MPM_RE006_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT 
UInt16 MPM_RE006_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
MPM_RE006_PhyMSI_pwrCylHdEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
MPM_RE007_ExM_tExMnfEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
MPM_RE007_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
MPM_RE007_UsThrM_tThrMes_in;extern AR_IF_GLOBAL_16BIT UInt16 MPM_facOvbReq_out;
extern AR_IF_GLOBAL_16BIT UInt16 MPM_rLdMax_out;extern AR_IF_GLOBAL_16BIT UInt16
 RE002_DmgMSI_rCylHdInjDmgCnt_in;
#define MPM_STOP_SEC_GLOBAL_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_GLOBAL_32BIT
#include "MPM_MemMap.h"
extern AR_IF_GLOBAL_32BIT UInt32 MPM_RE002_Ext_dstVehTotMes_in;extern 
AR_IF_GLOBAL_32BIT UInt32 MPM_RE006_PhyMSI_pCylMaxEstim_in;extern 
AR_IF_GLOBAL_32BIT UInt32 RE002_DmgMSI_rCylBlockDmg_in;extern AR_IF_GLOBAL_32BIT
 UInt32 RE002_DmgMSI_rCylHdDmg_in;extern AR_IF_GLOBAL_32BIT UInt32 
RE002_DmgMSI_rExMnfDmg_in;extern AR_IF_GLOBAL_32BIT UInt32 
RE002_DmgMSI_rTrbCaseDmg_in;
#define MPM_STOP_SEC_GLOBAL_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_GLOBAL_8BIT
#include "MPM_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 MPM_RE003_Eng_stEru_in;extern AR_IF_GLOBAL_8BIT 
UInt8 MPM_RE004_Eng_stEru_in;extern AR_IF_GLOBAL_8BIT UInt8 
MPM_RE005_Eng_stEru_in;
#define MPM_STOP_SEC_GLOBAL_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_GLOBAL_BOOLEAN
#include "MPM_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean DmgMSI_bLdLimReq_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean DmgMSI_bMPMInh_out;extern AR_IF_GLOBAL_BOOLEAN 
Boolean MPM_RE003_Afts_bRstTrbCaseDmgReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE004_Afts_bRstExMnfDmgReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE005_Afts_bRstCylHdDmgReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE006_Afts_bRstCylBlockDmgReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE006_Afts_bRstCylHdDmgReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE007_DmgMSI_bLdLimReq_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE007_DmgMSI_bMPMInh_in;extern AR_IF_GLOBAL_BOOLEAN Boolean 
MPM_RE007_FRM_bInhMPM_in;extern AR_IF_GLOBAL_BOOLEAN Boolean MPM_bOvbStop_out;
#define MPM_STOP_SEC_GLOBAL_BOOLEAN
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_16BIT
#include "MPM_MemMap.h"
extern ISV_SRSS1_0_tp subIsv16_MPM_SRSS1_LibRFLDmg_0;extern ISV_SRSS1_9_tp 
subIsv16_MPM_SRSS1_LibRFLDmg_9;extern ISV_SRSS1_0_tp 
subIsv16_MPM_SRSS1_LibRFLDmg__a;extern ISV_SRSS1_9_tp 
subIsv16_MPM_SRSS1_LibRFLDmg__d;extern ISV_SRSS1_0_tp 
subIsv16_MPM_SRSS1_LibRFLDmg__e;extern ISV_SRSS1_9_tp 
subIsv16_MPM_SRSS1_LibRFLDmg__h;
#define MPM_STOP_SEC_VAR_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_32BIT
#include "MPM_MemMap.h"
extern ISV_SRSS1_5_tp subIsv32_MPM_SRSS1_LibRFLDmg_5;extern ISV_SRSS1_5_tp 
subIsv32_MPM_SRSS1_LibRFLDmg__b;extern ISV_SRSS1_5_tp 
subIsv32_MPM_SRSS1_LibRFLDmg__d;
#define MPM_STOP_SEC_VAR_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_8BIT
#include "MPM_MemMap.h"
extern ISV_SRSS1_2_tp subIsv8_MPM_SRSS1_LibRFLDmg_2;extern ISV_SRSS1_2_tp 
subIsv8_MPM_SRSS1_LibRFLDmg_2_a;extern ISV_SRSS1_2_tp 
subIsv8_MPM_SRSS1_LibRFLDmg_2_b;extern ISV_SRSS1_7_tp 
subIsv8_MPM_SRSS1_LibRFLDmg_7;extern ISV_SRSS1_7_tp 
subIsv8_MPM_SRSS1_LibRFLDmg_7_a;extern ISV_SRSS1_7_tp 
subIsv8_MPM_SRSS1_LibRFLDmg_7_b;
#define MPM_STOP_SEC_VAR_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_VAR_UNSPECIFIED
#include "MPM_MemMap.h"
extern ISV_SRSS1_11_tp subIsvOther_MP__S1_LibRFLDmg_11;extern ISV_SRSS1_11_tp 
subIsvOther_MP__S1_LibRFLDmg__b;extern ISV_SRSS1_11_tp 
subIsvOther_MP__S1_LibRFLDmg__d;
#define MPM_STOP_SEC_VAR_UNSPECIFIED
#include "MPM_MemMap.h"
extern Void MPM_002_TEV_fct(Void);extern Void MPM_003_TEV_fct(Void);extern Void 
MPM_004_TEV_fct(Void);extern Void MPM_005_TEV_fct(Void);extern Void 
MPM_006_DRE_fct(Void);extern Void MPM_007_TEV_fct(Void);extern Void 
MPM_FctVarInit(Void);
#endif

