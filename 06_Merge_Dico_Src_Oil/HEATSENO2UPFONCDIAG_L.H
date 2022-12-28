/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPFONCDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2UPFONCDIAG_L_H
#define HEATSENO2UPFONCDIAG_L_H

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

extern const uint8  HEATSENO2UPFONCDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HEATSENO2UPFONCDIAG_bEnTCataPrev;
extern boolean Ldsd_am_diag_cond;
extern boolean Ldsd_am_diag_norm_cond;
extern boolean Ldsd_am_ena_mode_defaut;
extern boolean Ldsd_am_fco;
extern boolean Ldsd_am_fld;
extern boolean Ldsd_am_fld_confirm;
extern boolean Ldsd_am_fld_failure;
extern boolean Ldsd_am_fld_or_fco;
extern boolean LsMon_bThdSenO2UsDiag;
extern boolean SenO2Us_bDgoORng_UsPlausFco;
extern boolean SenO2Us_bDgoORng_UsPlausFld;
extern boolean SenO2Us_bMonRunORng_UsPlausFco;
extern boolean SenO2Us_bMonRunORng_UsPlausFld;
extern boolean SenO2Us_bMonRunRaw_UsPlausFco;
extern boolean SenO2Us_bMonRunRaw_UsPlausFld;
extern boolean SenO2Us_bMonWaitORng_UsPlausFco;
extern boolean SenO2Us_bMonWaitORng_UsPlausFld;
extern boolean SenO2Us_bMonWaitRaw_UsPlausFco;
extern boolean SenO2Us_bMonWaitRaw_UsPlausFld;
extern uint32 HEATSENO2UPFONCDIAG_u32MfAirCor;
extern uint8 HEATSENO2UPFONCDIAG_u8SysGasPrev;
extern uint8 LsMon_mfAirCorIntSenO2Us;
extern uint16 Ldsd_am_diag_ai_count;
extern uint16 Ldsd_am_f_diag_confirm_count;
extern uint16 Ldsd_am_f_diag_count;
extern uint16 LsMon_tiCfmSenO2UsDiag;
extern uint16 SenO2Us_FcoPlausFacMaxRaw;
extern uint16 SenO2Us_FcoPlausFacMesRaw;
extern uint16 SenO2Us_FldPlausFacMesRaw;
extern uint16 SenO2Us_FldPlausFacMinRaw;
extern uint16 SenO2Us_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2UPFONCDIAG_vidAmFDiag(void);
void HEATSENO2UPFONCDIAG_vidCalcDiag(void);
void HEATSENO2UPFONCDIAG_vidCondDiag(void);
void HEATSENO2UPFONCDIAG_vidDecTConfD(void);
void HEATSENO2UPFONCDIAG_vidDecTempo(void);
void HEATSENO2UPFONCDIAG_vidDiag(void);
void HEATSENO2UPFONCDIAG_vidDiagCount(void);
void HEATSENO2UPFONCDIAG_vidFcoMdEr6(void);
void HEATSENO2UPFONCDIAG_vidFcoObd6M(void);
void HEATSENO2UPFONCDIAG_vidFldMdEr6(void);
void HEATSENO2UPFONCDIAG_vidFldObd6M(void);
void HEATSENO2UPFONCDIAG_vidFldOrFco(void);
void HEATSENO2UPFONCDIAG_vidIncCtDiag(void);
void HEATSENO2UPFONCDIAG_vidIniAmDiag(void);
void HEATSENO2UPFONCDIAG_vidIniTConfD(void);
void HEATSENO2UPFONCDIAG_vidInitDiag(void);
void HEATSENO2UPFONCDIAG_vidInitModTr(void);
void HEATSENO2UPFONCDIAG_vidInitTempo(void);
void HEATSENO2UPFONCDIAG_vidIntmpDiag(void);
void HEATSENO2UPFONCDIAG_vidMode6(void);
void HEATSENO2UPFONCDIAG_vidModTran(void);
void HEATSENO2UPFONCDIAG_vidNormDiag(void);
void HEATSENO2UPFONCDIAG_vidNormMod06(void);
void HEATSENO2UPFONCDIAG_vidSeqFld(void);


#endif /* HEATSENO2UPFONCDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
