/***************************************************************************
;**
;** FILE NAME      : TARIDLSTA_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TARIDLSTA_L_H
#define TARIDLSTA_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


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

extern const uint8  TARIDLSTA_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TARIDLSTA_bATCunFlipFlopOut;
extern boolean TARIDLSTA_bEnableRateLimiter;
extern boolean TARIDLSTA_bEngAsiReqTrvPrev;
extern boolean TARIDLSTA_bIdlTarExtRisingEdge;
extern boolean TARIDLSTA_bNegHysTarIdlAC;
extern boolean TARIDLSTA_bPosHysGBxOut;
extern boolean TARIDLSTA_bPosHysLihPedOut;
extern boolean TARIDLSTA_bPosHysNeutOut;
extern boolean TARIDLSTA_bTarIdlACFlipFlopOut;
extern boolean TARIDLSTA_bTarIdlAltFlipFlopOut;
extern boolean TARIDLSTA_bTarIdlWaHtFlipFlopOut;
extern boolean TARIDLSTA_bTurnOffDlyRisingEdge;
extern boolean TARIDLSTA_bTurnOffDlyStgPmp;
extern boolean TqSys_bAcvBrkTarIdl;
extern boolean TqSys_bAcvSpdCdnTarIdlAlt;
extern boolean TqSys_bAcvTarIdlAC_MP;
extern boolean TqSys_bAcvTarIdlAltCmpReq_MP;
extern boolean TqSys_bAcvTarIdlATBas_MP;
extern boolean TqSys_bAcvTarIdlATEgd_MP;
extern boolean TqSys_bAcvTarIdlATInc_MP;
extern boolean TqSys_bAcvTarIdlBatt_MP;
extern boolean TqSys_bAcvTarIdlCanPurg_MP;
extern boolean TqSys_bAcvTarIdlLihPed_MP;
extern boolean TqSys_bAcvTarIdlSpdLim_MP;
extern boolean TqSys_bAcvTarIdlStgPmp_MP;
extern boolean TqSys_bAcvTarIdlTqAC;
extern boolean TqSys_bAcvTarIdlTqAlt;
extern boolean TqSys_bAcvTarIdlVacPmp_MP;
extern boolean TqSys_bAcvTarIdlWaHt_MP;
extern boolean TqSys_bAuthTarIdlCus;
extern boolean TqSys_bTarIdlSpd;
extern boolean TqSys_stTarIdlBatt_MP;
extern boolean TqSys_stTarIdlNorm_MP;
extern uint32 TARIDLSTA_u32TqACFilTarIdlMem;
extern uint8 TARIDLSTA_u8DragRedPrev;
extern uint8 TqSys_noGearTarIdl;
extern sint16 TARIDLSTA_s16BaryCentreOut;
extern sint16 TqSys_tAltTarIdl_MP;
extern sint16 TqSys_tEngTarIdl_MP;
extern sint16 TqSys_tqAltFilTarIdl_MP;
extern uint16 TARIDLSTA_u16ATEngTrnOffDlyCntr;
extern uint16 TARIDLSTA_u16EngSpdLimSlewOut;
extern uint16 TARIDLSTA_u16LihPedSlewOut;
extern uint16 TARIDLSTA_u16NeutSlewInput;
extern uint16 TARIDLSTA_u16NeutSlewOut;
extern uint16 TARIDLSTA_u16NormSlewInput;
extern uint16 TARIDLSTA_u16StgPmpTrnOffDlyCntr;
extern uint16 TqSys_ctTarIdlBatt_MP;
extern uint16 TqSys_nGBxOut;
extern uint16 TqSys_nTarIdlAC;
extern uint16 TqSys_nTarIdlAlt;
extern uint16 TqSys_nTarIdlATBas;
extern uint16 TqSys_nTarIdlATEgd;
extern uint16 TqSys_nTarIdlATInc;
extern uint16 TqSys_nTarIdlATReq;
extern uint16 TqSys_nTarIdlBatt;
extern uint16 TqSys_nTarIdlCanPurg;
extern uint16 TqSys_nTarIdlCus;
extern uint16 TqSys_nTarIdlDft;
extern uint16 TqSys_nTarIdlDsl;
extern uint16 TqSys_nTarIdlEng;
extern uint16 TqSys_nTarIdlGsl;
extern uint16 TqSys_nTarIdlNorm;
extern uint16 TqSys_nTarIdlPrev;
extern uint16 TqSys_nTarIdlStgPmp;
extern uint16 TqSys_nTarIdlTOil;
extern uint16 TqSys_nTarIdlUH;
extern uint16 TqSys_nTarIdlVacPmp;
extern uint16 TqSys_nTarIdlWaHt;
extern uint16 TqSys_tqACFilTarIdl_MP;
extern sint32 TARIDLSTA_s32TqAltFilTarIdlMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TARIDLSTA_vidCalc_Idl_tar(void);
void TARIDLSTA_vidCalc_Idl_tar_ac(void);
void TARIDLSTA_vidCalc_Idl_tar_alt(void);
void TARIDLSTA_vidCalc_Idl_tar_AT(void);
void TARIDLSTA_vidCalc_Idl_tar_AT_bas(void);
void TARIDLSTA_vidCalc_Idl_tar_AT_Cun(void);
void TARIDLSTA_vidCalc_Idl_tar_AT_inc(void);
void TARIDLSTA_vidCalc_Idl_tar_consum(void);
void TARIDLSTA_vidCalc_Idl_tar_Dsl(void);
void TARIDLSTA_vidCalc_Idl_tar_engine(void);
void TARIDLSTA_vidCalc_Idl_tar_fault(void);
void TARIDLSTA_vidCalc_Idl_tar_Gsl(void);
void TARIDLSTA_vidCalc_Idl_tar_lo_bat(void);
void TARIDLSTA_vidCalc_Idl_tar_normal(void);
void TARIDLSTA_vidCalc_Idl_tar_spd_ex(void);
void TARIDLSTA_vidCalc_Idl_tar_ss(void);
void TARIDLSTA_vidCalc_Idl_tar_thp(void);
void TARIDLSTA_vidCalc_Idl_tar_Toil(void);
void TARIDLSTA_vidCalc_Idl_tar_UH(void);
void TARIDLSTA_vidCalc_idl_target_ext(void);
void TARIDLSTA_vidCalc_Idl_target_max(void);
void TARIDLSTA_vidCalc_Idl_trq_req(void);
void TARIDLSTA_vidCalc_Idlle_target(void);
void TARIDLSTA_vidCalc_info(void);
void TARIDLSTA_vidCalc_spd_gbx_output(void);
void TARIDLSTA_vidCalcTarNorSlewInput(void);
void TARIDLSTA_vidClc_Idl_tar_vac_pmp(void);
void TARIDLSTA_vidFrze_Idl_tar_AT_eng(void);
void TARIDLSTA_vidIdl_tar_Canister(void);
void TARIDLSTA_vidInitOutput(void);


#endif /* TARIDLSTA_L_H */

/*-------------------------------- end of file -------------------------------*/
