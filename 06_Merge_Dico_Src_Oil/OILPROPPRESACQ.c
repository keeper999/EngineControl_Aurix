/***************************************************************************
;**
;** FILE NAME      : OILPROPPRESACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OILPROPPRESACQ.H"
#include "OILPROPPRESACQ_L.H"
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

#pragma section ".calib" a
const boolean  Oil_bSelTypOilMesDiag_C = 0;
const boolean  Oil_pres_alertTypProp_C = 0;
const uint8  Ext_upOilMesCoef_M[EXT_UPOILMESCOEF_M_LNS][EXT_UPOILMESCOEF_M_COLS] = {0};
const uint8  Oil_prm_noAcqOilPresLstSample_T[OIL_PRM_NOACQOILPRESLSTSAMPLE_T_COLS] = {0};
const uint8  OILPROPPRESACQ_u8Inhib = 0;
const uint16  Ext_nEngOilPresAcqHiThd_C = 0;
const uint16  Ext_nEngOilPresAcqLoThd_C = 0;
const uint16  Ext_noOilPresDetecDeltThd_C = 0;
const uint16  Ext_noOilPresDetecLoThd_C = 0;
const uint16  Ext_OilCoef_nEng_A[EXT_OILCOEF_NENG_A_COLS] = {0};
const uint16  Ext_OilCoef_tOilMes_A[EXT_OILCOEF_TOILMES_A_COLS] = {0};
const uint16  Oil_pOilMesDft_C = 0;
const uint16  Oil_pOilPresAcq_uOilMes_A[OIL_POILPRESACQ_UOILMES_A_COLS] = {0};
const uint16  Oil_uDgoScg_pOilMes_C = 0;
const uint16  Oil_uDgoScp_pOilMes_C = 0;
const uint16  Oil_upOilMesLnr_T[OIL_UPOILMESLNR_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoScg_pOilMes;
boolean Ext_bDgoScp_pOilMes;
boolean Ext_bMonRunScg_pOilMes;
boolean Ext_bMonRunScp_pOilMes;
boolean Ext_bOilPresProp;
boolean Ext_bRawOilPresProp;
boolean Oil_bAcvOilPresAcq;
boolean Oil_Pres_alertProp;
boolean OILPROPPRESACQ_bAcqCondHystOut;
boolean OILPROPPRESACQ_bHystOutput;
uint32 OILPROPPRESACQ_u32OilActFilMEM;
uint8 Ext_upOilMesCoef_MP;
uint16 Ext_pOilMesPrev;
uint16 Ext_pOilMesRaw;
uint16 Ext_pOilMesRaw_bornee;
uint16 Ext_prm_uPresOilMesMem[EXT_PRM_UPRESOILMESMEM_COLS];
uint16 Oil_upOilMesAct;
uint16 Oil_upOilMesMean;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

