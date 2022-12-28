/***************************************************************************
;**
;** FILE NAME      : TARIDLSTA.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TARIDLSTA_H
#define TARIDLSTA_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_FACCORTARIDLSTRT_T_COLS          ( 8 )
#define TQSYS_FACTARIDLCANPURG_A_COLS          ( 8 )
#define TQSYS_NGBXOUT_A_COLS                   ( 12 )
#define TQSYS_NIDLATREQ_T_COLS                 ( 10 )
#define TQSYS_NOFSTARIDLPAIR_T_COLS            ( 8 )
#define TQSYS_NOFSTARIDLSTRT_M_LNS            ( 8 )
#define TQSYS_NOFSTARIDLSTRT_M_COLS            ( 8 )
#define TQSYS_NTARIDLAC_M_LNS                 ( 8 )
#define TQSYS_NTARIDLAC_M_COLS                 ( 9 )
#define TQSYS_NTARIDLACTQ_T_COLS               ( 8 )
#define TQSYS_NTARIDLALTCMP_T_COLS             ( 8 )
#define TQSYS_NTARIDLALTTQ_T_COLS              ( 8 )
#define TQSYS_NTARIDLATBAS1_M_LNS             ( 8 )
#define TQSYS_NTARIDLATBAS1_M_COLS             ( 12 )
#define TQSYS_NTARIDLATBAS2_M_LNS             ( 8 )
#define TQSYS_NTARIDLATBAS2_M_COLS             ( 12 )
#define TQSYS_NTARIDLATINC_M_LNS              ( 8 )
#define TQSYS_NTARIDLATINC_M_COLS              ( 12 )
#define TQSYS_NTARIDLCANPURG_T_COLS            ( 8 )
#define TQSYS_NTARIDLNORM1_M_LNS              ( 8 )
#define TQSYS_NTARIDLNORM1_M_COLS              ( 9 )
#define TQSYS_NTARIDLNORM2_M_LNS              ( 8 )
#define TQSYS_NTARIDLNORM2_M_COLS              ( 9 )
#define TQSYS_NTARIDLTOIL_T_COLS               ( 8 )
#define TQSYS_NTARIDLUH_T_COLS                 ( 8 )
#define TQSYS_PAIRTARIDL_A_COLS                ( 8 )
#define TQSYS_SPDVEHNIDLATREQ_A_COLS           ( 10 )
#define TQSYS_TAIRTARIDLAC_A_COLS              ( 8 )
#define TQSYS_TALTTARIDL_A_COLS                ( 8 )
#define TQSYS_TCOTARIDLUH_A_COLS               ( 8 )
#define TQSYS_TENGTARIDL_A_COLS                ( 8 )
#define TQSYS_TIENGRUNTARIDL_A_COLS            ( 8 )
#define TQSYS_TISTOPTARIDL_A_COLS              ( 8 )
#define TQSYS_TOILTARIDL_A_COLS                ( 8 )
#define TQSYS_TQACFILTARIDL_A_COLS             ( 8 )
#define TQSYS_TQALTFILTARIDL_A_COLS            ( 8 )

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

extern const boolean  TqSys_bAcvNIdlATReq_C;
extern const boolean  TqSys_bAcvTarIdlSpdAC_C;
extern const boolean  TqSys_bAcvTarIdlSpdAlt_C;
extern const boolean  TqSys_bAcvTarIdlSpdBatt_C;
extern const boolean  TqSys_bAcvTarIdlSpdWaHt_C;
extern const boolean  TqSys_bCfNTarIdlAC_C;
extern const boolean  TqSys_bCfTEngTarIdlNorm_C;
extern const boolean  TqSys_bCVC_C;
extern const boolean  TqSys_bIniNTarIdlStrt_C;
extern const sint8  TqSys_uErrMinTarIdlBatt_C;
extern const uint8  TqSys_ctHiTarIdlBatt_C;
extern const uint8  TqSys_ctLoTarIdlBatt_C;
extern const uint8  TqSys_ctMaxTarIdlBatt_C;
extern const uint8  TqSys_facCorTAltTarIdl_C;
extern const uint8  TqSys_facCorTarIdlBatt_C;
extern const uint8  TqSys_facCorTarIdlStrt_T[TQSYS_FACCORTARIDLSTRT_T_COLS];
extern const uint8  TqSys_facFilTqACTarIdl_C;
extern const uint8  TqSys_facFilTqAltTarIdl_C;
extern const uint8  TqSys_facPAirTarIdlVacPmp_C;
extern const uint8  TqSys_facTIdlAsiAlt_C;
extern const uint8  TqSys_noGearTarIdlDft_C;
extern const uint8  TqSys_pAirOfsTarIdlVacPmp_C;
extern const uint8  TqSys_pThdTarIdlStgPmp_C;
extern const uint8  TqSys_spdThdHiLihPed_C;
extern const uint8  TqSys_spdThdLoLihPed_C;
extern const uint8  TqSys_spdThdNeutHi_C;
extern const uint8  TqSys_spdThdNeutLo_C;
extern const uint8  TqSys_spdVehHiTarIdlAC_C;
extern const uint8  TqSys_spdVehHiTarIdlAlt_C;
extern const uint8  TqSys_spdVehLimIdl_C;
extern const uint8  TqSys_spdVehLoTarIdlAC_C;
extern const uint8  TqSys_spdVehLoTarIdlAlt_C;
extern const uint8  TqSys_spdVehNIdlATReq_A[TQSYS_SPDVEHNIDLATREQ_A_COLS];
extern const uint8  TqSys_spdVehTarIdlVacPmp_C;
extern const uint8  TqSys_spdVehThdAcvNIdlATReq_C;
extern const uint8  TqSys_tAirTarIdlAC_A[TQSYS_TAIRTARIDLAC_A_COLS];
extern const uint8  TqSys_tAltTarIdl_A[TQSYS_TALTTARIDL_A_COLS];
extern const uint8  TqSys_tCoTarIdlUH_A[TQSYS_TCOTARIDLUH_A_COLS];
extern const uint8  TqSys_tEngTarIdl_A[TQSYS_TENGTARIDL_A_COLS];
extern const uint8  TqSys_tOilTarIdl_A[TQSYS_TOILTARIDL_A_COLS];
extern const uint8  TqSys_uThdTarIdlBatt_C;
extern const sint16  TqSys_nDecMaxTarIdl_C;
extern const sint16  TqSys_nDecTarIdlAC_C;
extern const sint16  TqSys_nDecTarIdlAlt_C;
extern const sint16  TqSys_nDecTarIdlATBas_C;
extern const sint16  TqSys_nDecTarIdlATEgd_C;
extern const sint16  TqSys_nDecTarIdlATInc_C;
extern const sint16  TqSys_nDecTarIdlBatt_C;
extern const sint16  TqSys_nDecTarIdlCanPurg_C;
extern const sint16  TqSys_nDecTarIdlEngSpdLim_C;
extern const sint16  TqSys_nDecTarIdlLihPed_C;
extern const sint16  TqSys_nDecTarIdlNorm_C;
extern const sint16  TqSys_nDecTarIdlStgPmp_C;
extern const sint16  TqSys_nDecTarIdlUH_C;
extern const sint16  TqSys_nDecTarIdlVacPmp_C;
extern const sint16  TqSys_nDecTarIdlWaHt_C;
extern const sint16  TqSys_tEngDftTarIdl_C;
extern const uint16  TqSys_facFrntWhlGBxOut_C;
extern const uint16  TqSys_facSpdVehGBxOut_C;
extern const uint16  TqSys_facTarIdlCanPurg_A[TQSYS_FACTARIDLCANPURG_A_COLS];
extern const uint16  TqSys_nExtMaxTarIdlAC_C;
extern const uint16  TqSys_nExtMinTarIdlAC_C;
extern const uint16  TqSys_nGBxDftTarIdl_C;
extern const uint16  TqSys_nGBxOut_A[TQSYS_NGBXOUT_A_COLS];
extern const uint16  TqSys_nGBxOutThdHi_C;
extern const uint16  TqSys_nGBxOutThdLo_C;
extern const uint16  TqSys_nIdlATReq_T[TQSYS_NIDLATREQ_T_COLS];
extern const uint16  TqSys_nIncMaxTarIdl_C;
extern const uint16  TqSys_nIncTarIdlAC_C;
extern const uint16  TqSys_nIncTarIdlAlt_C;
extern const uint16  TqSys_nIncTarIdlATBas_C;
extern const uint16  TqSys_nIncTarIdlBatt_C;
extern const uint16  TqSys_nIncTarIdlCanPurg_C;
extern const uint16  TqSys_nIncTarIdlEngSpdLim_C;
extern const uint16  TqSys_nIncTarIdlLihPed_C;
extern const uint16  TqSys_nIncTarIdlNorm_C;
extern const uint16  TqSys_nIncTarIdlStgPmp_C;
extern const uint16  TqSys_nIncTarIdlUH_C;
extern const uint16  TqSys_nIncTarIdlVacPmp_C;
extern const uint16  TqSys_nIncTarIdlWaHt_C;
extern const uint16  TqSys_nOfsHiIdlClc_C;
extern const uint16  TqSys_nOfsLoIdlClc_C;
extern const uint16  TqSys_nOfsTarIdlPAir_T[TQSYS_NOFSTARIDLPAIR_T_COLS];
extern const uint16  TqSys_nOfsTarIdlStrt_M[TQSYS_NOFSTARIDLSTRT_M_LNS][TQSYS_NOFSTARIDLSTRT_M_COLS];
extern const uint16  TqSys_nTarIdlAC_M[TQSYS_NTARIDLAC_M_LNS][TQSYS_NTARIDLAC_M_COLS];
extern const uint16  TqSys_nTarIdlACTq_T[TQSYS_NTARIDLACTQ_T_COLS];
extern const uint16  TqSys_nTarIdlAltCmp_T[TQSYS_NTARIDLALTCMP_T_COLS];
extern const uint16  TqSys_nTarIdlAltTq_T[TQSYS_NTARIDLALTTQ_T_COLS];
extern const uint16  TqSys_nTarIdlATBas1_M[TQSYS_NTARIDLATBAS1_M_LNS][TQSYS_NTARIDLATBAS1_M_COLS];
extern const uint16  TqSys_nTarIdlATBas2_M[TQSYS_NTARIDLATBAS2_M_LNS][TQSYS_NTARIDLATBAS2_M_COLS];
extern const uint16  TqSys_nTarIdlATInc_M[TQSYS_NTARIDLATINC_M_LNS][TQSYS_NTARIDLATINC_M_COLS];
extern const uint16  TqSys_nTarIdlBatt_C;
extern const uint16  TqSys_nTarIdlCanPurg_T[TQSYS_NTARIDLCANPURG_T_COLS];
extern const uint16  TqSys_nTarIdlEngSpdLim_C;
extern const uint16  TqSys_nTarIdlIni_C;
extern const uint16  TqSys_nTarIdlLihPedRun_C;
extern const uint16  TqSys_nTarIdlLihPedRunBrk_C;
extern const uint16  TqSys_nTarIdlLihPedStop_C;
extern const uint16  TqSys_nTarIdlLihPedStopBrk_C;
extern const uint16  TqSys_nTarIdlMax_C;
extern const uint16  TqSys_nTarIdlMin_C;
extern const uint16  TqSys_nTarIdlNorm1_M[TQSYS_NTARIDLNORM1_M_LNS][TQSYS_NTARIDLNORM1_M_COLS];
extern const uint16  TqSys_nTarIdlNorm2_M[TQSYS_NTARIDLNORM2_M_LNS][TQSYS_NTARIDLNORM2_M_COLS];
extern const uint16  TqSys_nTarIdlStgPmp_C;
extern const uint16  TqSys_nTarIdlTOil_T[TQSYS_NTARIDLTOIL_T_COLS];
extern const uint16  TqSys_nTarIdlUH_T[TQSYS_NTARIDLUH_T_COLS];
extern const uint16  TqSys_nTarIdlVacPmp_C;
extern const uint16  TqSys_nTarIdlVacPmpDft_C;
extern const uint16  TqSys_nTarIdlWaHt_C;
extern const uint16  TqSys_pAirTarIdl_A[TQSYS_PAIRTARIDL_A_COLS];
extern const uint16  TqSys_tiAcvTarIdlATEgd_C;
extern const uint16  TqSys_tiAcvTarIdlStgPmp_C;
extern const uint16  TqSys_tiEngRunTarIdl_A[TQSYS_TIENGRUNTARIDL_A_COLS];
extern const uint16  TqSys_tiStopTarIdl_A[TQSYS_TISTOPTARIDL_A_COLS];
extern const uint16  TqSys_tiStrtDlyTarIdlCus_C;
extern const uint16  TqSys_tiStrtDlyTarIdlTakeOff_C;
extern const uint16  TqSys_tqACFilTarIdl_A[TQSYS_TQACFILTARIDL_A_COLS];
extern const uint16  TqSys_tqAltFilTarIdl_A[TQSYS_TQALTFILTARIDL_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqSys_bIdlClcReq;
extern uint16 TqSys_nTarIdlAT;
extern uint16 TqSys_nTarIdlSfty;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TARIDLSTA_vidEntryInit(void);
void TqSys_Sdl10ms_nTarIdl(void);


#endif /* TARIDLSTA_H */

/*-------------------------------- end of file -------------------------------*/
