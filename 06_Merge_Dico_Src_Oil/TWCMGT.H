/***************************************************************************
;**
;** FILE NAME      : TWCMGT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TWCMGT_H
#define TWCMGT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TWCMGT_DSTVEH_TIPHA1KM_A_COLS          ( 12 )
#define TWCMGT_MO2STG_TIPHA_A_COLS             ( 12 )
#define TWCMGT_NENGTODRVREQ_A_COLS             ( 12 )
#define TWCMGT_NORATEFCLSUSPER_A_COLS          ( 12 )
#define TWCMGT_RESLSUSHEAT_A_COLS              ( 12 )
#define TWCMGT_RMISFOBD_TPHA1MISF_A_COLS       ( 12 )
#define TWCMGT_STACVHEATPHA_T_COLS             ( 12 )
#define TWCMGT_TCOACVHEATPHA_A_COLS            ( 12 )
#define TWCMGT_TIHEATCASEDEAC_A_COLS           ( 12 )
#define TWCMGT_TIHEATCASEDEACLIOFF_T_COLS      ( 12 )
#define TWCMGT_TIHEATHIAR_A_COLS               ( 12 )
#define TWCMGT_TILIOFFDONE_T_COLS              ( 12 )
#define TWCMGT_TIPHA1_TITRBPOSN_A_COLS         ( 12 )
#define TWCMGT_TIPHA1KM_T_COLS                 ( 12 )
#define TWCMGT_TIPHA1MISF_T_COLS               ( 12 )
#define TWCMGT_TIPHA3ACV_T_COLS                ( 12 )
#define TWCMGT_TIPHAO2STG_T_COLS               ( 12 )
#define TWCMGT_TIPHARATEFCLSUSPER_T_COLS       ( 12 )
#define TWCMGT_TIRESLSUSHEAT_T_COLS            ( 12 )
#define TWCMGT_TITRBCLSPOSN_T_COLS             ( 12 )
#define TWCMGT_TITRBOPPOSN_T_COLS              ( 12 )
#define TWCMGT_TITWCHEATDEAC_T_COLS            ( 12 )
#define TWCMGT_TQNENGDRVREQ_T_COLS             ( 12 )

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

extern const boolean  TWCMgt_bInhAcvExServoCdn_C;
extern const boolean  TWCMgt_bInhAcvInServoCdn_C;
extern const boolean  TWCMgt_bInhCtlTrbPosn_C;
extern const boolean  TWCMgt_bInhReGearHeatDeac_C;
extern const boolean  TWCMgt_bRstETBTiPha1_C;
extern const uint8  TWCMgt_facFilRatEfcLsUsPer_C;
extern const uint8  TWCMgt_rAccePedDrvReq_C;
extern const uint8  TWCMgt_stAcvHeatPha_T[TWCMGT_STACVHEATPHA_T_COLS];
extern const uint8  TWCMgt_stModLiOffClc_C;
extern const uint8  TWCMgt_tCoAcvHeatPha_A[TWCMGT_TCOACVHEATPHA_A_COLS];
extern const sint16  TWCMgt_tThdDifMaxTInTCo_C;
extern const sint16  TWCMgt_tThdDifTCo_C;
extern const sint16  TWCMgt_tTWCHeatDeacThd_C;
extern const sint16  TWCMgt_tTWCHeatPha3Acv_C;
extern const sint16  TWCMgt_tTWCLiOff_C;
extern const sint16  TWCMgt_tTWCMaxHeatAcvT_C;
extern const uint16  TWCMgt_dstDftKmOldVeh_C;
extern const uint16  TWCMgt_dstVeh_tiPha1Km_A[TWCMGT_DSTVEH_TIPHA1KM_A_COLS];
extern const uint16  TWCMgt_mO2Stg_tiPha_A[TWCMGT_MO2STG_TIPHA_A_COLS];
extern const uint16  TWCMgt_nEngToDrvReq_A[TWCMGT_NENGTODRVREQ_A_COLS];
extern const uint16  TWCMgt_nEngTWCStrtThd_C;
extern const uint16  TWCMgt_noRatEfcLsUsPer_A[TWCMGT_NORATEFCLSUSPER_A_COLS];
extern const uint16  TWCMgt_pThrMinAmbPres_C;
extern const uint16  TWCMgt_resLsUsHeat_A[TWCMGT_RESLSUSHEAT_A_COLS];
extern const uint16  TWCMgt_rMisfOBD_tPha1Misf_A[TWCMGT_RMISFOBD_TPHA1MISF_A_COLS];
extern const uint16  TWCMgt_tiDlyAcvCdnAcvHiAr_C;
extern const uint16  TWCMgt_tiDlyAcvCdnAcvLoAr_C;
extern const uint16  TWCMgt_tiDlyGearIdl_C;
extern const uint16  TWCMgt_tiDlyIdlHeatPhaThd_C;
extern const uint16  TWCMgt_tiDlyPha3_C;
extern const uint16  TWCMgt_tiDlyTWCHeatDeac_C;
extern const uint16  TWCMgt_tiDlyTWCLiOff_C;
extern const uint16  TWCMgt_tiHeatCaseDeac_A[TWCMGT_TIHEATCASEDEAC_A_COLS];
extern const uint16  TWCMgt_tiHeatCaseDeacLiOff_T[TWCMGT_TIHEATCASEDEACLIOFF_T_COLS];
extern const uint16  TWCMgt_tiHeatHiAr_A[TWCMGT_TIHEATHIAR_A_COLS];
extern const uint16  TWCMgt_tiLiOffDone_T[TWCMGT_TILIOFFDONE_T_COLS];
extern const uint16  TWCMgt_tiMaxHeatThdLoAr_C;
extern const uint16  TWCMgt_tiPha1_tiTrbPosn_A[TWCMGT_TIPHA1_TITRBPOSN_A_COLS];
extern const uint16  TWCMgt_tiPha1ETB_C;
extern const uint16  TWCMgt_tiPha1Km_T[TWCMGT_TIPHA1KM_T_COLS];
extern const uint16  TWCMgt_tiPha1Misf_T[TWCMGT_TIPHA1MISF_T_COLS];
extern const uint16  TWCMgt_tiPha3Acv_T[TWCMGT_TIPHA3ACV_T_COLS];
extern const uint16  TWCMgt_tiPhaO2Stg_T[TWCMGT_TIPHAO2STG_T_COLS];
extern const uint16  TWCMgt_tiPhaRatEfcLsUsPer_T[TWCMGT_TIPHARATEFCLSUSPER_T_COLS];
extern const uint16  TWCMgt_tiResLsUsHeat_T[TWCMGT_TIRESLSUSHEAT_T_COLS];
extern const uint16  TWCMgt_tiSdlFast_C;
extern const uint16  TWCMgt_tiThdMinEngStopRst_C;
extern const uint16  TWCMgt_tiTrbClsPosn_T[TWCMGT_TITRBCLSPOSN_T_COLS];
extern const uint16  TWCMgt_tiTrbClsPosnThdLoAr_C;
extern const uint16  TWCMgt_tiTrbOpPosn_T[TWCMGT_TITRBOPPOSN_T_COLS];
extern const uint16  TWCMgt_tiTrbOpPosnThdLoAr_C;
extern const uint16  TWCMgt_tiTWCHeatDeac_T[TWCMGT_TITWCHEATDEAC_T_COLS];
extern const uint16  TWCMgt_tiTWCLiOffHeatLoAr_C;
extern const uint16  TWCMgt_tqNEngDrvReq_T[TWCMGT_TQNENGDRVREQ_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean OxC_bIntrHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TWCMgt_EveIni_TWCMgt(void);
void TWCMgt_SdlFast_TWCMgt(void);


#endif /* TWCMGT_H */

/*-------------------------------- end of file -------------------------------*/
