
#ifndef _EOMGSL_002_CALIBRATIONS_H_
#define _EOMGSL_002_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define EOMGSL_START_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT SInt16 EOM_ColdMod_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 EOM_deltaAgCkHysExVlv_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 EOM_deltaAgCkHysInVlv_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_nEngThdHiModPrf_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_nEngThdLoModPrf_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_nIdlEngHiThd_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_nIdlEngLoThd_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 EOM_tCoHysBand1_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 EOM_tCoThdCmbModPrf_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffDeltaPosnExVlv_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffDeltaPosnInVlv_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffSpcInjModInjSys1_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffSpcInjModInjSys2_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffSpcInjModInjSys3_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffSpcInjModInjSys4_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffVlvRblModInjSys_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiDlyOffVlvVacModInjSys_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiSdlFast_C;
#define EOMGSL_STOP_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
AR_MERGEABLE_EXT_CALIB_16BIT SInt16 EOM_tCoDft_C;
#define EOMGSL_STOP_SEC_CALIB_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CALIB_32BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT SInt32 EOM_deltaPThdCmbModPrf_C;extern 
AR_MERGEABLE_CALIB_32BIT SInt32 EOM_deltaRatAirThdHysModPrf_C;extern 
AR_MERGEABLE_CALIB_32BIT UInt32 EOM_dstVehFoutMod_C;
#define EOMGSL_STOP_SEC_CALIB_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_idxIdlTypSel_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noAcvNomModPrio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noBlby_bdilution1Prio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noBlby_bdilution2Prio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noCoHeat_bAcvHeatPrio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noDeltaPosnVlvPrio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noDftPrio_C;extern AR_MERGEABLE_CALIB_8BIT 
UInt8 EOM_noGasPrio_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noHiLvlDftPrio_C;
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noSTTStopPrio_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_noSpcInjPrio_C;extern AR_MERGEABLE_CALIB_8BIT 
UInt8 EOM_noTWCHeatPhaPrio_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 
EOM_noVlvposnRblPrio_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 
EOM_noVlvposnVacPrio_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stCmbModManSel_C
;extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stCoHeat_bAcvHeatMod_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stDeltaPosnVlvMod_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stManEngModReq_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stVlvPosnRblMod_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_stVlvPosnVacMod_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_tiDlyInhCmbPrfMod_C;
#define EOMGSL_STOP_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bAcvCmbPrfMod_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bAcvTmpSecu_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bEnaCmbModManSel_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bEnaDiTranManSel_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bInhGasModReq_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bInhSpcInjModReq_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bInhVlvPosnRblModReq_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bInhVlvPosnVacModReq_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bManEngModReq_C;
#define EOMGSL_STOP_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_16BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT SInt16 EOM_agCkDeltaPosnExVlvReq_A[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 EOM_agCkDeltaPosnInVlvReq_A[8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 EOM_nEng_A[8];extern AR_MERGEABLE_CARTO_16BIT 
UInt16 EOM_rAirLdCor_A[8];
#define EOMGSL_STOP_SEC_CARTO_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_32BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT SInt32 EOM_deltaRatAirLdThdModPrf_M[8][8];
#define EOMGSL_STOP_SEC_CARTO_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_CARTO_8BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 EOM_bDeltaPosnExVlvReq_M[8][8];extern 
AR_MERGEABLE_CARTO_8BIT UInt8 EOM_bDeltaPosnInVlvReq_M[8][8];
#define EOMGSL_STOP_SEC_CARTO_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_16BIT
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT SInt16 EOM_agCkDeltaPosnExVlvReq_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT SInt16 EOM_agCkDeltaPosnInVlvReq_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT SInt16 EOM_tCoCor_Cold;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_16BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_32BIT
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 EOM_deltaRatAirLdThdPrf_MP;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_32BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_8BIT
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 EOMGSL_stEngModReq;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_noPrioMax_MP;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 EOM_stCmbModReqNotSel;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RE002_EOM_stCmbModReq_out;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_8BIT
#include "EOMGsl_MemMap.h"
#define EOMGSL_START_SEC_INTERNAL_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bAcvSpcInjModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bColdModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bDeltaPosnVlvModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bDiTranNotSel;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bGasModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bIdlModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bLdTranModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bLdTranModReqRaw_MP;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bTWCHeatPhaModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bVlvPosnRblModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean EOM_bVlvPosnVacModReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE002_EOM_bDiTran_out;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE002_EOM_bEnaCmbModChg_in;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RE002_EOM_bFdoutModReq_out;
#define EOMGSL_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "EOMGsl_MemMap.h"
#endif

