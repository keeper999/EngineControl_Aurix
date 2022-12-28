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
* %name: TPM_Library.h %
*
* %version: 3.0 %
*
* %date_modified: Mon Dec  3 09:47:27 2012 %
*
*
* %derived_by: u260001 %
* %release: EPflex/Vf %
* %full_filespec: TPM_Library.h-3.0:incl:2 %
*
*******************************************************************************/


#ifndef _TPM_LIBRARY_H_
#define _TPM_LIBRARY_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
typedef struct z33079f02f78ec749dca813d510be8f7b{UInt16 
z9c22b3fc7b69e4d50c4413feee838b09;UInt16 zbf2cde9bf24fda796514dc71de3d5aa0;
UInt16 z8a5b80e6c238a0ef64f585912a44bd5f;}ISV_SRSS11_0_tp;typedef struct 
z4c48bd97b0086b036a31ce74859562d1{Boolean zea53ee8bdcd8a469b10a4414f309493c;
Boolean z7dd5ac9b6fdfcc47ab66316db2ba449b;Boolean 
z671c0d3c30fb526e3081cf8a31db6869;Boolean z7dce700f8285c7daebd7cfc8a514fc86;
Boolean zb7f03f9aa4ddd669061935963d4dd0f1;Boolean 
z6bdc06b5a0728b913061dd7ca4dec378;Boolean z0ccfb322a7690cef6e789b1f16f17693;
Boolean ze0513f3327af7cfe152280b22d133f5e;}ISV_SRSS11_1_tp;typedef struct 
zb6bbece896023c5b451e9bd5dd43be59{ISV_SRSS11_0_tp*
z13a0b08e825940c71b73ae7af8ad2f52;ISV_SRSS11_1_tp*
z31221b2f56fd413897ac232321d65807;}z96bf6e11bd3fedb6ee335df77cb350d3;
#define TPM_START_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 TPM_tMaxDeltaHys_in;extern AR_IF_GLOBAL_16BIT 
UInt16 TPM_tMaxDevDelta_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_tiTMaxDevThermoProt_C_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_tiTMaxDevTmpAirLd_C_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_tiTMaxDevTmp_C_in;
#define TPM_STOP_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
extern Void DevTPM(UInt32 TPM_tDev_in,Boolean FARSp_bSatMaxRatMixt_in,UInt32 
TPM_tMaxDev_in,Boolean z82155a018e89024f0d6abccc862ed244,Boolean 
z08543bef32b05b9a9b4e55d7fdb425c2,UInt16 zf296b6e152ca53e19ee01f9e62fc8b93,
UInt16 zd6bcaf415b6fc9929bb2504381a00f59,Boolean 
z5d0b8420156688f793f6eb7b45cebbd8,Boolean z6b457d07e89ab453ba6bf1b91e774221,
UInt32*z7737fcbb8d606eb682f34548eb3e2908,Boolean*
z415d90d83937945342a7de478bb0e916,Boolean*z2e5dca6b607d13605d1ce74156acc2f8,
SInt16*z34dd2a97f0220f1e3861841483437374,Boolean*
z5c37d1dfdd4449638b790854784f29c7,SInt16*z27aace4e6714198a5dc5eb823506b75c,
Boolean*z03946e1fbd655bf5a5d959daddb9392c,Boolean*
z83b3050f3a8676bdf1ac10ee9f9fff75,Boolean*z78733eaa72758f50fccad88c647846a9,
Boolean*zbc8aa1309996ebc9916be1f151986508,Boolean*
zd7cc02032999ebf1d8a4193a618987d2,z96bf6e11bd3fedb6ee335df77cb350d3*
z1dc3a5e2c8d81740a16858d250d00755,Boolean ze8445a6b29fc0080cf5364cc7ab37cd6);
#endif

