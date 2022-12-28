/***************************************************************************
;**
;** FILE NAME      : COES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COES_H
#define COES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COES_NENDINTRSTTES_T_COLS              ( 8 )
#define COES_NLIMINTRSTTES_T_COLS              ( 8 )
#define COES_NLIMLOINTRSTTES_T_COLS            ( 8 )
#define COES_TCO_NLIMINTR_A_COLS               ( 8 )

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

extern const boolean  CoEs_bAcvClsCanPurgSTTEs_C;
extern const boolean  CoEs_bAcvIgCutOffSTTEs_C;
extern const boolean  CoEs_bAcvIgSysSTTEs_C;
extern const boolean  CoEs_bAcvInjCutOffSTTEs_C;
extern const boolean  CoEs_bAcvIntrCdnEngRun_C;
extern const boolean  CoEs_bAcvIntrCdnNStall_C;
extern const boolean  CoEs_bAcvIntrSTTEs_C;
extern const boolean  CoEs_bAcvOilPmpSysSTTEs_C;
extern const boolean  CoEs_bAcvThrSysSTTEs_C;
extern const boolean  CoEs_bAcvVlvSysLockPosnSTTEs_C;
extern const boolean  CoEs_bAcvVlvSysRiseSTTEs_C;
extern const boolean  CoEs_bCdnExVlvLockPosn_C;
extern const boolean  CoEs_bCdnInVlvLockPosn_C;
extern const boolean  CoEs_bCfCdnIntrSTT_C;
extern const boolean  CoEs_bCfNEngIntrSTTEs_C;
extern const boolean  CoEs_bDeacCdnCanPurg_C;
extern const uint8  CoEs_rCmdLimCanPurg_C;
extern const uint8  CoEs_tCo_nLimIntr_A[COES_TCO_NLIMINTR_A_COLS];
extern const uint8  CoEs_tiCutIg_C;
extern const uint8  CoEs_tiDlyVldNNull_C;
extern const uint16  CoEs_facFilNEngTth_C;
extern const uint16  CoEs_nEndIntrSTTEs_T[COES_NENDINTRSTTES_T_COLS];
extern const uint16  CoEs_nLimIntrSTTEs_T[COES_NLIMINTRSTTES_T_COLS];
extern const uint16  CoEs_nLimLoIntrSTTEs_T[COES_NLIMLOINTRSTTES_T_COLS];
extern const uint16  CoEs_tiDlyCanPurgCls_C;
extern const uint16  CoEs_tiDlyCmdCanPurgIntrSTTEs_C;
extern const uint16  CoEs_tiDlyCmdVlvSysIntrSTTEs_C;
extern const uint16  CoEs_tiDlyIntrSTTEsHiEngSpd_C;
extern const uint16  CoEs_tiDlyIntrSTTEsLoEngSpd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoEs_bAcvClsCanPurgSTTEs;
extern boolean CoEs_bAcvIgCutOffSTTEs;
extern boolean CoEs_bAcvOilPmpSysSTTEs;
extern boolean CoEs_bAcvThrSysSTTEs;
extern boolean CoEs_bAcvVlvSysRiseSTTEs;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoEs_SdlFast_STTEs(void);
void COES_vidEntryInit(void);


#endif /* COES_H */

/*-------------------------------- end of file -------------------------------*/
