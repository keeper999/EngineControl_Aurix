/***************************************************************************
;**
;** FILE NAME      : OILPROPPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILPROPPRESACQ_H
#define OILPROPPRESACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_OILCOEF_NENG_A_COLS                ( 3 )
#define EXT_OILCOEF_TOILMES_A_COLS             ( 3 )
#define EXT_UPOILMESCOEF_M_LNS                ( 3 )
#define EXT_UPOILMESCOEF_M_COLS                ( 3 )
#define Oil_pMax_SC                       10000
#define Oil_pMin_SC                       500
#define OIL_POILPRESACQ_UOILMES_A_COLS         ( 2 )
#define OIL_PRM_NOACQOILPRESLSTSAMPLE_T_COLS   ( 12 )
#define OIL_UPOILMESLNR_T_COLS                 ( 2 )

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

extern const boolean  Oil_bSelTypOilMesDiag_C;
extern const boolean  Oil_pres_alertTypProp_C;
extern const uint8  Ext_upOilMesCoef_M[EXT_UPOILMESCOEF_M_LNS][EXT_UPOILMESCOEF_M_COLS];
extern const uint8  Oil_prm_noAcqOilPresLstSample_T[OIL_PRM_NOACQOILPRESLSTSAMPLE_T_COLS];
extern const uint16  Ext_nEngOilPresAcqHiThd_C;
extern const uint16  Ext_nEngOilPresAcqLoThd_C;
extern const uint16  Ext_noOilPresDetecDeltThd_C;
extern const uint16  Ext_noOilPresDetecLoThd_C;
extern const uint16  Ext_OilCoef_nEng_A[EXT_OILCOEF_NENG_A_COLS];
extern const uint16  Ext_OilCoef_tOilMes_A[EXT_OILCOEF_TOILMES_A_COLS];
extern const uint16  Oil_pOilMesDft_C;
extern const uint16  Oil_pOilPresAcq_uOilMes_A[OIL_POILPRESACQ_UOILMES_A_COLS];
extern const uint16  Oil_uDgoScg_pOilMes_C;
extern const uint16  Oil_uDgoScp_pOilMes_C;
extern const uint16  Oil_upOilMesLnr_T[OIL_UPOILMESLNR_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bOilPresProp;
extern boolean Ext_bRawOilPresProp;
extern boolean Oil_Pres_alertProp;
extern uint16 Ext_pOilMesRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Oil_Eve14TDC_OilPropPresAcq(void);
void Oil_EveRst_OilPropPresAcq(void);
void Oil_SdlFast_OilPropPresAcq(void);


#endif /* OILPROPPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
