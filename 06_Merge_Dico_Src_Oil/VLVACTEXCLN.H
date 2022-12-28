/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCLN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXCLN_H
#define VLVACTEXCLN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_EXFRSTCLNCMD_M_COLS             ( 21 )
#define VLVACT_EXHEALCLNCMD_M_COLS             ( 21 )
#define VLVACT_EXNORMCLNCMD_M_COLS             ( 21 )
#define VLVACT_TIEXFRSTCLNIDC_T_COLS           ( 21 )
#define VLVACT_TIEXHEALCLNIDC_T_COLS           ( 21 )
#define VLVACT_TIEXNORMCLNIDC_T_COLS           ( 21 )

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

extern const boolean  VlvAct_bExSelTypCmdProfTyp_C;
extern const boolean  VlvAct_bInhExHealClnDoneCt_C;
extern const boolean  VlvAct_bInhExNormClnDoneCt_C;
extern const uint8  VlvAct_ctExFrstClnCycThd_C;
extern const uint8  VlvAct_ctExHealClnDoneThd_C;
extern const uint8  VlvAct_ctExNormClnDoneThd_C;
extern const uint8  VlvAct_ExFrstClnCmd_M[VLVACT_EXFRSTCLNCMD_M_COLS];
extern const uint8  VlvAct_ExHealClnCmd_M[VLVACT_EXHEALCLNCMD_M_COLS];
extern const uint8  VlvAct_ExNormClnCmd_M[VLVACT_EXNORMCLNCMD_M_COLS];
extern const uint8  VlvAct_noHealClnActExDftThd_C;
extern const uint8  VlvAct_tiExClnEndThd_C;
extern const uint8  VlvAct_tiExFrstClnIdc_T[VLVACT_TIEXFRSTCLNIDC_T_COLS];
extern const uint8  VlvAct_tiExHealClnIdc_T[VLVACT_TIEXHEALCLNIDC_T_COLS];
extern const uint8  VlvAct_tiExNormClnIdc_T[VLVACT_TIEXNORMCLNIDC_T_COLS];
extern const uint16  VlvAct_AgExHealClnErrThd_C;
extern const uint16  VlvAct_AgExNormClnThd_C;
extern const uint16  VlvAct_ExClnCmdMax_C;
extern const uint16  VlvAct_ExClnCmdMin_C;
extern const uint16  VlvAct_tiExHealClnMonErrDly_C;
extern const uint16  VlvAct_tiExNormClnDly_C;
extern const uint16  VlvAct_tiHealClnActExDly_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bExFrstClnDone;
extern boolean VlvAct_bExMngClnStReq;
extern uint16 VlvAct_ExClnStCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveKOf_ExCln(void);
void VlvAct_EveRst_ExCln(void);
void VlvAct_SdlFast_ExCln(void);


#endif /* VLVACTEXCLN_H */

/*-------------------------------- end of file -------------------------------*/
