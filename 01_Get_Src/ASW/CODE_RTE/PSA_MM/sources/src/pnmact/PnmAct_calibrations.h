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
* %name: PnmAct_calibrations.h %
*
* %version: 1.0.build1 %
*
* %date_modified: Mon Jan  7 10:52:37 2013 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC4 %
* %full_filespec: PnmAct_calibrations.h-1.0.build1:incl:2 %
*
*******************************************************************************/


#ifndef _PNMACT_CALIBRATIONS_H_
#define _PNMACT_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "Library_lut.h"
#define PNMACT_START_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_FacdGain_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_FaciGain_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_mfAirOutMax_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 PnmAct_pDifTrbEstimMin_C;extern 
AR_MERGEABLE_CALIB_16BIT SInt16 PnmAct_pVacRef_C;extern AR_MERGEABLE_CALIB_16BIT
 SInt16 PnmAct_rRCOCorMax_C;extern AR_MERGEABLE_CALIB_16BIT SInt16 
PnmAct_rRCOCorMin_C;extern AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_rRCOHiThd_C;
extern AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_rRCOLoThd_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_rRCOMax_C;extern AR_MERGEABLE_CALIB_16BIT
 UInt16 PnmAct_rRCOMin_C;
#define PNMACT_STOP_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CALIB_32BIT
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT UInt32 PnmAct_FacpGain_C;extern 
AR_MERGEABLE_CALIB_32BIT SInt32 PnmAct_mfAirInMin_C;
#define PNMACT_STOP_SEC_CALIB_32BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CALIB_8BIT
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 PnmAct_facFilGainTrbAct_C;
#define PNMACT_STOP_SEC_CALIB_8BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean PnmAct_bSelPresAirExt_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean PnmAct_bTrbActCf_C;
#define PNMACT_STOP_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CARTO_16BIT
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_mfAirInDB_M[8][10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_mfAirIn_M[8][10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_mfAirOut_M[9][10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_pAirExt_A[8];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 PnmAct_pDifTrbActEstim2_A[9];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 PnmAct_pDifTrbActEstim_A[16];extern 
AR_MERGEABLE_CARTO_16BIT SInt16 PnmAct_pDifTrbEstim_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rOpTrbActEstim_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rOpTrbActEstim_M[16][16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rPresExtTrbAct_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rPresVacTrbAct_A[10];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rRCODB_T[9];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_rRCO_M[9][8];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 PnmAct_volPnmAct_T[16];
#define PNMACT_STOP_SEC_CARTO_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_CONST_UNSPECIFIED
#include "PnmAct_MemMap.h"
extern const MAP_Tab1DS2I2T521 SPnmAct11_PnmAct_volPnmAct_T_map;extern const 
MAP_Tab2DS34I2T4196 SPnmAct12_TrbAct_rOpTrbActEstim_M_map;extern const 
MAP_Tab2DS34I2T4172 SPnmAct8_PnmAct_mfAirOut_M_map;
#define PNMACT_STOP_SEC_CONST_UNSPECIFIED
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_INTERNAL_VAR_16BIT
#include "PnmAct_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 PnmAct_rOpTrbAct_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 PnmAct_rRCOReqPrev_MP;
#define PNMACT_STOP_SEC_INTERNAL_VAR_16BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_INTERNAL_VAR_32BIT
#include "PnmAct_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_mfAirInRaw_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_mfAirIn_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 PnmAct_mfAirOutRaw_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 PnmAct_mfAirOut_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_mfAirTot_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_pDeltaPnmAct_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_pDifErr_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_rRCOdCor_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_rRCOiCor_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT SInt32 PnmAct_rRCOpCor_MP;
#define PNMACT_STOP_SEC_INTERNAL_VAR_32BIT
#include "PnmAct_MemMap.h"
#define PNMACT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "PnmAct_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean PnmAct_bDB_MP;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean PnmAct_bInhICtl_MP;
#define PNMACT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "PnmAct_MemMap.h"
#endif

