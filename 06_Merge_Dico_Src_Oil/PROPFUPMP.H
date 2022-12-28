/***************************************************************************
;**
;** FILE NAME      : PROPFUPMP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROPFUPMP_H
#define PROPFUPMP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_FLOWFUTNKPMP_A_COLS                ( 3 )
#define EXT_FLOWFUTNKPMP_T_COLS                ( 3 )

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

extern const uint8  Ext_stDftFuPmpRcv_C;
extern const uint8  FuPmp_tiInhDiag_C;
extern const uint16  Ext_FlowFuTnkPmp_A[EXT_FLOWFUTNKPMP_A_COLS];
extern const uint16  Ext_FlowFuTnkPmp_T[EXT_FLOWFUTNKPMP_T_COLS];
extern const uint16  FuPmp_rFlowFuTnkPmpDft_C;
extern const uint16  FuPmp_rFlowFuTnkPmpIni_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ext_stDftFuTnkPmp;
extern uint16 Ext_rFlowFuTnkPmp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FuPmp_EveRst_PropFuPmp(void);
void FuPmp_SdlFast_PropFuPmp(void);
void FuPmp_SdlSlow_PropFuPmp(void);


#endif /* PROPFUPMP_H */

/*-------------------------------- end of file -------------------------------*/
