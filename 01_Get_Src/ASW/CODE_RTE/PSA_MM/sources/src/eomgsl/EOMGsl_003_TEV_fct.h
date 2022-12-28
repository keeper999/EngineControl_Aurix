
#ifndef _EOMGSL_003_TEV_FCT_H_
#define _EOMGSL_003_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define EOMGSL_START_SEC_GLOBAL_16BIT
#include "EOMGsl_MemMap.h"
extern AR_IF_GLOBAL_16BIT SInt16 EOMGsl_RE003_Ext_tCoMes_in;extern 
AR_IF_GLOBAL_16BIT SInt16 EOMGsl_RE003_Ext_tCoStrtMes_in;extern 
AR_IF_GLOBAL_16BIT UInt16 EOMGsl_RE003_Ext_tiStrt_in;
#define EOMGSL_STOP_SEC_GLOBAL_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_32BIT
#include "EOMGsl_MemMap.h"
extern AR_IF_GLOBAL_32BIT UInt32 EOMGsl_RE003_EOM_tiEngStop_in;
#define EOMGSL_STOP_SEC_GLOBAL_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_8BIT
#include "EOMGsl_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 EOM_prm_facBasModCur_out[16];extern 
AR_IF_GLOBAL_8BIT UInt8 EOM_prm_facBasModTar_out[16];extern AR_IF_GLOBAL_8BIT 
UInt8 EOM_prm_facTranMod_out[16];extern AR_IF_GLOBAL_8BIT UInt8 
EOM_prm_idxBas1ModCur_out[16];extern AR_IF_GLOBAL_8BIT UInt8 
EOM_prm_idxBas1ModTar_out[16];extern AR_IF_GLOBAL_8BIT UInt8 
EOM_prm_idxBas2ModCur_out[16];extern AR_IF_GLOBAL_8BIT UInt8 
EOM_prm_idxBas2ModTar_out[16];
#define EOMGSL_STOP_SEC_GLOBAL_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean EOMGsl_RE003_FRM_bAcvTCoMesDft_in;
#define EOMGSL_STOP_SEC_GLOBAL_BOOLEAN
#include "EOMGsl_MemMap.h"
extern Void EOMGsl_003_TEV_fct(Void);extern Void EOMGsl_003_TEV_ini(Void);extern
 Void EOMGsl_003_FctVarInit(Void);
#endif

