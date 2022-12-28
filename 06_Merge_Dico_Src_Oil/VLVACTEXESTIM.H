/***************************************************************************
;**
;** FILE NAME      : VLVACTEXESTIM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXESTIM_H
#define VLVACTEXESTIM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_EXPOSNESTIMINVTO_M_LNS         ( 5 )
#define VLVACT_EXPOSNESTIMINVTO_M_COLS         ( 5 )
#define VLVACT_EXPOSNESTIMK_M_LNS             ( 5 )
#define VLVACT_EXPOSNESTIMK_M_COLS             ( 5 )
#define VLVACT_NEXPOSNESTIM_T_COLS             ( 5 )
#define VLVACT_TOILEXPOSNESTIM_T_COLS          ( 5 )

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

extern const boolean  VlvAct_bExPosnEstimCmdOfsSel_C;
extern const boolean  VlvAct_bExPosnEstimInh_C;
extern const uint8  VlvAct_ExPosnEstimCmdDb_C;
extern const uint8  VlvAct_ExPosnEstimInvTo_M[VLVACT_EXPOSNESTIMINVTO_M_LNS][VLVACT_EXPOSNESTIMINVTO_M_COLS];
extern const uint8  VlvAct_ExPosnEstimK_M[VLVACT_EXPOSNESTIMK_M_LNS][VLVACT_EXPOSNESTIMK_M_COLS];
extern const uint8  VlvAct_ExPosnEstimMax_C;
extern const uint8  VlvAct_ExPosnEstimMin_C;
extern const uint8  VlvAct_nExPosnEstim_T[VLVACT_NEXPOSNESTIM_T_COLS];
extern const uint8  VlvAct_nExPosnEstimEnaMax_C;
extern const uint8  VlvAct_tOilExPosnEstim_T[VLVACT_TOILEXPOSNESTIM_T_COLS];
extern const uint16  VlvAct_ExPosnEstimCmdOfs_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 VlvAct_agCmExSpdEstim;
extern uint16 VlvAct_agCmExEstimVar;
extern uint16 VlvAct_agCmExMesVar;
extern uint16 VlvAct_agCmExPosnEstim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveExCmToo_ExEstim(void);
void VlvAct_SdlFast_ExEstim(void);
void VLVACTEXESTIM_vidEntryInit(void);


#endif /* VLVACTEXESTIM_H */

/*-------------------------------- end of file -------------------------------*/
