/***************************************************************************
;**
;** FILE NAME      : VLVACTINCLN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINCLN_H
#define VLVACTINCLN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_INFRSTCLNCMD_M_COLS             ( 21 )
#define VLVACT_INHEALCLNCMD_M_COLS             ( 21 )
#define VLVACT_INNORMCLNCMD_M_COLS             ( 21 )
#define VLVACT_TIINFRSTCLNIDC_T_COLS           ( 21 )
#define VLVACT_TIINHEALCLNIDC_T_COLS           ( 21 )
#define VLVACT_TIINNORMCLNIDC_T_COLS           ( 21 )

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

extern const boolean  VlvAct_bInhInHealClnDoneCt_C;
extern const boolean  VlvAct_bInhInNormClnDoneCt_C;
extern const boolean  VlvAct_bInSelTypCmdProfTyp_C;
extern const uint8  VlvAct_ctInFrstClnCycThd_C;
extern const uint8  VlvAct_ctInHealClnDoneThd_C;
extern const uint8  VlvAct_ctInNormClnDoneThd_C;
extern const uint8  VlvAct_InFrstClnCmd_M[VLVACT_INFRSTCLNCMD_M_COLS];
extern const uint8  VlvAct_InHealClnCmd_M[VLVACT_INHEALCLNCMD_M_COLS];
extern const uint8  VlvAct_InNormClnCmd_M[VLVACT_INNORMCLNCMD_M_COLS];
extern const uint8  VlvAct_noHealClnActInDftThd_C;
extern const uint8  VlvAct_tiInClnEndThd_C;
extern const uint8  VlvAct_tiInFrstClnIdc_T[VLVACT_TIINFRSTCLNIDC_T_COLS];
extern const uint8  VlvAct_tiInHealClnIdc_T[VLVACT_TIINHEALCLNIDC_T_COLS];
extern const uint8  VlvAct_tiInNormClnIdc_T[VLVACT_TIINNORMCLNIDC_T_COLS];
extern const uint16  VlvAct_AgInHealClnErrThd_C;
extern const uint16  VlvAct_AgInNormClnThd_C;
extern const uint16  VlvAct_InClnCmdMax_C;
extern const uint16  VlvAct_InClnCmdMin_C;
extern const uint16  VlvAct_tiHealClnActInDly_C;
extern const uint16  VlvAct_tiInHealClnMonErrDly_C;
extern const uint16  VlvAct_tiInNormClnDly_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bInFrstClnDone;
extern boolean VlvAct_bInMngClnStReq;
extern uint16 VlvAct_InClnStCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveKOf_InCln(void);
void VlvAct_EveRst_InCln(void);
void VlvAct_SdlFast_InCln(void);


#endif /* VLVACTINCLN_H */

/*-------------------------------- end of file -------------------------------*/
