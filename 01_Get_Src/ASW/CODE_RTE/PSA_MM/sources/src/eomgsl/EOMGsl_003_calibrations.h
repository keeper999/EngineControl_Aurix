
#ifndef _EOMGSL_003_CALIBRATIONS_H_
#define _EOMGSL_003_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define EOMGSL_START_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT SInt16 EOM_tCoCold_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 EOM_tCoDft_C;extern AR_MERGEABLE_CALIB_16BIT 
SInt16 EOM_tCoHysBand_C;extern AR_MERGEABLE_CALIB_16BIT SInt16 EOM_tCoOfs_C;
#define EOMGSL_STOP_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bSeltCotyp_C;
#define EOMGSL_STOP_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_16BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT SInt16 EOM_tCoCor_A[9];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 EOM_tCoCor_idxMod_A[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 EOM_tCoThd_M[9][9];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 EOM_tiStrtThd_M[9][9];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 Ext_tCoStrtMes_A[9];
#define EOMGSL_STOP_SEC_CARTO_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_32BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT UInt32 EOM_tiEngStop_A[9];
#define EOMGSL_STOP_SEC_CARTO_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_8BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_facColdTCoBas_M[16][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_facTCoBas_M[16][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_facTCoFdoutBas_M[16][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_facTCoIdlBas_M[16][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_facTCoIdlFdoutBas_M[16][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxBas1_T[16];extern AR_MERGEABLE_CARTO_8BIT 
UInt8 EOM_idxBas2_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxBlbydilution1Mod_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxBlbydilution2Mod_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxColdBas1_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxDftMod1_T[16];
extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxDftMod2_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxFdoutBas1_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxFdoutBas2_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxGasMod_T[16];extern AR_MERGEABLE_CARTO_8BIT
 UInt8 EOM_idxIdlBas1_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxIdlBas2_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxIdlFdoutBas1_T[
16];extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxIdlFdoutBas2_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxIdlHeatPha1Cold_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxIdlHeatPha1Warm_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxIdlHeatPha2Warm_T[16];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxSTTEs_T[16];extern AR_MERGEABLE_CARTO_8BIT 
UInt8 EOM_idxSpcInjMod_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxTWCHeatPha1Cold_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxTWCHeatPha1Warm_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxTWCHeatPha2Warm_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 
EOM_idxTWCHeatPha3Warm_T[16];extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_idxTran_T[
16];
#define EOMGSL_STOP_SEC_CARTO_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_16BIT
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 EOM_tCoCor;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_8BIT
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facBasModCurNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facBasModTarNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facColdTCoBas[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facTCoBas[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facTCoFdoutBas[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facTCoIdlBas[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_facTCoIdlFdoutBas[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas1ModCurNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas1ModTarNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas2[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas2ModCurNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBas2ModTarNotSync[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBlbydilution1ModBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxBlbydilution2ModBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxColdBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxColdBas2[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxDftMod1Bas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxDftMod2Bas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxFdoutBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxFdoutBas2[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxGasModBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlBas2[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlFdoutBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlFdoutBas2[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlHeatPha1CBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlHeatPha1WBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxIdlHeatPha2WBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxSTTEsBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxSpcInjModBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxTWCHeatPha1CBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxTWCHeatPha1WBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxTWCHeatPha2WBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxTWCHeatPha3WBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_prm_idxTranBas1[16];extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_01_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_02_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_03_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_04_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_05_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_06_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_07_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_08_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_09_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_10_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_11_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_12_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_13_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_14_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_15_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_prm_facTranModNotSync_16_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_stCmbModCur_in;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE003_EOM_stCmbModTar_in;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_8BIT
#include "EOMGsl_MemMap.h"
#endif

