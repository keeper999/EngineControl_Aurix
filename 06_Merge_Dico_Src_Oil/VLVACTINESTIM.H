/***************************************************************************
;**
;** FILE NAME      : VLVACTINESTIM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINESTIM_H
#define VLVACTINESTIM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_INPOSNESTIMINVTO_M_LNS         ( 5 )
#define VLVACT_INPOSNESTIMINVTO_M_COLS         ( 5 )
#define VLVACT_INPOSNESTIMK_M_LNS             ( 5 )
#define VLVACT_INPOSNESTIMK_M_COLS             ( 5 )
#define VLVACT_NINPOSNESTIM_T_COLS             ( 5 )
#define VLVACT_TOILINPOSNESTIM_T_COLS          ( 5 )

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

extern const boolean  VlvAct_bInPosnEstimCmdOfsSel_C;
extern const boolean  VlvAct_bInPosnEstimInh_C;
extern const uint8  VlvAct_InPosnEstimCmdDb_C;
extern const uint8  VlvAct_InPosnEstimInvTo_M[VLVACT_INPOSNESTIMINVTO_M_LNS][VLVACT_INPOSNESTIMINVTO_M_COLS];
extern const uint8  VlvAct_InPosnEstimK_M[VLVACT_INPOSNESTIMK_M_LNS][VLVACT_INPOSNESTIMK_M_COLS];
extern const uint8  VlvAct_InPosnEstimMax_C;
extern const uint8  VlvAct_InPosnEstimMin_C;
extern const uint8  VlvAct_nInPosnEstim_T[VLVACT_NINPOSNESTIM_T_COLS];
extern const uint8  VlvAct_nInPosnEstimEnaMax_C;
extern const uint8  VlvAct_tOilInPosnEstim_T[VLVACT_TOILINPOSNESTIM_T_COLS];
extern const uint16  VlvAct_InPosnEstimCmdOfs_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 VlvAct_agCmInSpdEstim;
extern uint16 VlvAct_agCmInEstimVar;
extern uint16 VlvAct_agCmInMesVar;
extern uint16 VlvAct_agCmInPosnEstim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveInCmToo_InEstim(void);
void VlvAct_SdlFast_InEstim(void);
void VLVACTINESTIM_vidEntryInit(void);


#endif /* VLVACTINESTIM_H */

/*-------------------------------- end of file -------------------------------*/
