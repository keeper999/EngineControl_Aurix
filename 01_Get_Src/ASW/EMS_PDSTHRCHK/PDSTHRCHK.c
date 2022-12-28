/***************************************************************************
;**
;** FILE NAME      : PDSTHRCHK.C75
;**
;** FILE AUTHOR    : MBENFRADJ (VEES)
;**
;**************************************************************************/

#include "STD_TYPES.h"
#include "PDSTHRCHK.h"
#include "PDSTHRCHK_l.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bInhDftAirExt_C = 0;
const boolean  SftyMgt_bInhDftGrdAirExt_C = 0;
const boolean  SftyMgt_bInhDftPresDsThr_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  PDSTHRCHK_u8Inhib = 0;
const uint8  SftyMgt_facAirExtCor_T[SFTYMGT_FACAIREXTCOR_T_COLS] = {0};
const uint8  SftyMgt_tiAirExtFil_C = 0;
const uint8  SftyMgt_tiDlyAirExtDft_C = 0;
const uint8  SftyMgt_tiDlyGrdAirExtDft_C = 0;
const uint8  SftyMgt_tiDlyPresDsThrOn_C = 0;
const uint8  SftyMgt_tiOpTrbActFil_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftyMgt_nCkFilSftyPresX_A[SFTYMGT_NCKFILSFTYPRESX_A_COLS] = {0};
const uint16  SftyMgt_nCkFilTrbActX_A[SFTYMGT_NCKFILTRBACTX_A_COLS] = {0};
const uint16  SftyMgt_nPresOffsSfty_A[SFTYMGT_NPRESOFFSSFTY_A_COLS] = {0};
const uint16  SftyMgt_pAirExt_A[SFTYMGT_PAIREXT_A_COLS] = {0};
const uint16  SftyMgt_pAirExtDftThd_C = 0;
const uint16  SftyMgt_pDsThrEstimBas1_M[SFTYMGT_PDSTHRESTIMBAS1_M_LNS][SFTYMGT_PDSTHRESTIMBAS1_M_COLS] = {0};
const uint16  SftyMgt_pDsThrEstimBas2_M[SFTYMGT_PDSTHRESTIMBAS2_M_LNS][SFTYMGT_PDSTHRESTIMBAS2_M_COLS] = {0};
const uint16  SftyMgt_pDsThrOfs_M[SFTYMGT_PDSTHROFS_M_LNS][SFTYMGT_PDSTHROFS_M_COLS] = {0};
const uint16  SftyMgt_pGrdAirExtDftThd_C = 0;
const uint16  SftyMgt_pOffsSfty_T[SFTYMGT_POFFSSFTY_T_COLS] = {0};
const uint16  SftyMgt_posnThrSftyPresY_A[SFTYMGT_POSNTHRSFTYPRESY_A_COLS] = {0};
const uint16  SftyMgt_pTrbActCorBas1_M[SFTYMGT_PTRBACTCORBAS1_M_LNS][SFTYMGT_PTRBACTCORBAS1_M_COLS] = {0};
const uint16  SftyMgt_pTrbActCorBas2_M[SFTYMGT_PTRBACTCORBAS2_M_LNS][SFTYMGT_PTRBACTCORBAS2_M_COLS] = {0};
const uint16  SftyMgt_rOpTrbActFilY_A[SFTYMGT_ROPTRBACTFILY_A_COLS] = {0};
const uint16  SftyMgt_rOpTrbActReqGrdThd_C = 0;
const uint16  SftyMgt_tiOpTrbActFilDown_C = 0;
const uint16  SftyMgt_tiOpTrbActFilUp_C = 0;
const uint16  SftyMgt_tiPosnThrFil_C = 0;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean PDSTHRCHK_bFiltredExtMesSI;
boolean SftyMgt_bDftAirExt;
boolean SftyMgt_bDftGrdAirExt;
boolean SftyMgt_bDftPresDsThr_MP;
boolean SftyMgt_bDftThdAirExt_MP;
boolean SftyMgt_bDftThdGrdAirExt_MP;
boolean SftyMgt_bDgoAirExt_MP;
boolean SftyMgt_bDgoGrdAirExt_MP;
boolean SftyMgt_bDgoPresDsThr;
boolean SftyMgt_bDgoPresDsThr_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16 PDSTHRCHK_u16OutputFilter2;
uint16 PDSTHRCHK_u16SftyMgtAcReqFilPrev;
uint16 PDSTHRCHK_u16tiDlyAirExtDft;
uint16 PDSTHRCHK_u16tiDlyGrdAirExtDft;
uint16 PDSTHRCHK_u16tiDlyPresDsThrOn;
uint16 SftyMgt_pAirExtMesSIFil_MP;
uint16 SftyMgt_pDsThrEstim;
uint16 SftyMgt_pDsThrOfs;
uint16 SftyMgt_pPosnThr_MP;
uint16 SftyMgt_pTrbActCor_MP;
uint16 SftyMgt_rOpTrbActReqFil_MP;
uint16 SftyMgt_rOpTrbActReqGrd_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
uint32 PDSTHRCHK_u32FiltredExtMesSIMem;
uint32 PDSTHRCHK_u32FiltredposnThrMem;
uint32 PDSTHRCHK_u32FiltredTrbActReqMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

