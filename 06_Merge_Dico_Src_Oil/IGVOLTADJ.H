/***************************************************************************
;**
;** FILE NAME      : IGVOLTADJ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGVOLTADJ_H
#define IGVOLTADJ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGVOLTADJ_BVOLTADJ_M_LNS              ( 9 )
#define IGVOLTADJ_BVOLTADJ_M_COLS              ( 8 )
#define IGVOLTADJ_NENG_BVOLTADJX_A_COLS        ( 9 )
#define IGVOLTADJ_RAIR_BVOLTADJY_A_COLS        ( 8 )

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

extern const boolean  IgVoltAdj_bActVoltAdj_C;
extern const boolean  IgVoltAdj_bVoltAdj_M[IGVOLTADJ_BVOLTADJ_M_LNS][IGVOLTADJ_BVOLTADJ_M_COLS];
extern const uint32  IgVoltAdj_dstVehMinVoltAdj_C;
extern const uint8  IgVoltAdj_rIcdBstReqHiThd_C;
extern const uint8  IgVoltAdj_rIcdBstReqLoThd_C;
extern const uint16  IgVoltAdj_nEng_bVoltAdjX_A[IGVOLTADJ_NENG_BVOLTADJX_A_COLS];
extern const uint16  IgVoltAdj_rAir_bVoltAdjY_A[IGVOLTADJ_RAIR_BVOLTADJY_A_COLS];
extern const uint16  IgVoltAdj_tiActDly_C;
extern const uint16  IgVoltAdj_tiDeacDly_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgVoltAdj_bVoltAdj;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGVOLTADJ_vidEntryInit(void);
void Volt_SdlFast_IgVoltAdj(void);


#endif /* IGVOLTADJ_H */

/*-------------------------------- end of file -------------------------------*/
