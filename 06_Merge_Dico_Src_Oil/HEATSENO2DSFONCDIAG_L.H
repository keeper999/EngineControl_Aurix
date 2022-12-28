/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSFONCDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSFONCDIAG_L_H
#define HEATSENO2DSFONCDIAG_L_H

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

extern const uint8  HEATSENO2DSFONCDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HEATSENO2DSFONCDIAG_bAcvItDsDiag;
extern boolean HEATSENO2DSFONCDIAG_bAvItDsDgBva;
extern boolean HEATSENO2DSFONCDIAG_bEnTCataPrev;
extern boolean Ldsd_av_diag_cond;
extern boolean Ldsd_av_diag_intru_cond;
extern boolean Ldsd_av_ena_mode_defaut;
extern boolean Ldsd_av_fco;
extern boolean Ldsd_av_fco_no_failure;
extern boolean Ldsd_av_fld;
extern boolean Ldsd_av_fld_confirm;
extern boolean Ldsd_av_fld_failure;
extern boolean Ldsd_av_fld_no_failure;
extern boolean Ldsd_av_fld_or_fco;
extern boolean LsMon_bItrsvSenO2DsDiagDoneFco;
extern boolean LsMon_bItrsvSenO2DsDiagDoneFld;
extern boolean LsMon_bThdSenO2DsDiagFco;
extern boolean LsMon_bThdSenO2DsDiagFld;
extern boolean SenO2Ds_bDgoORng_DsPlausFco;
extern boolean SenO2Ds_bDgoORng_DsPlausFld;
extern boolean SenO2Ds_bMonRunORng_DsPlausFco;
extern boolean SenO2Ds_bMonRunORng_DsPlausFld;
extern boolean SenO2Ds_bMonRunRaw_DsPlausFco;
extern boolean SenO2Ds_bMonRunRaw_DsPlausFld;
extern boolean SenO2Ds_bMonWaitORng_DsPlausFco;
extern boolean SenO2Ds_bMonWaitORng_DsPlausFld;
extern boolean SenO2Ds_bMonWaitRaw_DsPlausFco;
extern boolean SenO2Ds_bMonWaitRaw_DsPlausFld;
extern uint32 HEATSENO2DSFONCDIAG_u32mAirCor;
extern uint8 HEATSENO2DSFONCDIAG_u8SysGasPrev;
extern uint8 LsMon_mfAirCorIntSenO2Ds;
extern uint16 Ldsd_av_diag_ai_count;
extern uint16 Ldsd_av_f_diag_confirm_count;
extern uint16 Ldsd_av_f_diag_count;
extern uint16 LsMon_tiCfmSenO2DsDiagFco;
extern uint16 LsMon_tiCfmSenO2DsDiagFld;
extern uint16 LsMon_tiRStrtItrsvFco;
extern uint16 LsMon_tiRStrtItrsvFld;
extern uint16 SenO2Ds_FcoPlausFacMaxRaw;
extern uint16 SenO2Ds_FcoPlausFacMesRaw;
extern uint16 SenO2Ds_FldPlausFacMesRaw;
extern uint16 SenO2Ds_FldPlausFacMinRaw;
extern uint16 SenO2Ds_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2DSFONCDIAG_vidAcvDgBva(void);
void HEATSENO2DSFONCDIAG_vidAcvDiag(void);
void HEATSENO2DSFONCDIAG_vidAvFDiag(void);
void HEATSENO2DSFONCDIAG_vidCalcDiag(void);
void HEATSENO2DSFONCDIAG_vidCheckrMCy(void);
void HEATSENO2DSFONCDIAG_vidChMCyBva(void);
void HEATSENO2DSFONCDIAG_vidCondDiag(void);
void HEATSENO2DSFONCDIAG_vidDecTConfD(void);
void HEATSENO2DSFONCDIAG_vidDecTempo(void);
void HEATSENO2DSFONCDIAG_vidDgCntBva(void);
void HEATSENO2DSFONCDIAG_vidDgInDnBva(void);
void HEATSENO2DSFONCDIAG_vidDgIntrBva(void);
void HEATSENO2DSFONCDIAG_vidDiag(void);
void HEATSENO2DSFONCDIAG_vidDiagCount(void);
void HEATSENO2DSFONCDIAG_vidDiagIhBva(void);
void HEATSENO2DSFONCDIAG_vidDiagInDon(void);
void HEATSENO2DSFONCDIAG_vidDiagInInh(void);
void HEATSENO2DSFONCDIAG_vidDiagIntru(void);
void HEATSENO2DSFONCDIAG_vidDsDgOKBva(void);
void HEATSENO2DSFONCDIAG_vidDsDiagOK(void);
void HEATSENO2DSFONCDIAG_vidFcoMdEr6(void);
void HEATSENO2DSFONCDIAG_vidFcoObd6M(void);
void HEATSENO2DSFONCDIAG_vidFldMdEr6(void);
void HEATSENO2DSFONCDIAG_vidFldObd6M(void);
void HEATSENO2DSFONCDIAG_vidFldOrFco(void);
void HEATSENO2DSFONCDIAG_vidIncCtDiag(void);
void HEATSENO2DSFONCDIAG_vidIniAvDiag(void);
void HEATSENO2DSFONCDIAG_vidIniTConfD(void);
void HEATSENO2DSFONCDIAG_vidInitDiag(void);
void HEATSENO2DSFONCDIAG_vidInitDiag1(void);
void HEATSENO2DSFONCDIAG_vidInitTempo(void);
void HEATSENO2DSFONCDIAG_vidInMod6Bva(void);
void HEATSENO2DSFONCDIAG_vidIntrMode6(void);
void HEATSENO2DSFONCDIAG_vidIsDgNOKBv(void);
void HEATSENO2DSFONCDIAG_vidIsDgOKBva(void);
void HEATSENO2DSFONCDIAG_vidItrsvFco(void);
void HEATSENO2DSFONCDIAG_vidItrsvFld(void);
void HEATSENO2DSFONCDIAG_vidItsDiaNOK(void);
void HEATSENO2DSFONCDIAG_vidItsDiaOK(void);
void HEATSENO2DSFONCDIAG_vidMode6(void);
void HEATSENO2DSFONCDIAG_vidModTran(void);
void HEATSENO2DSFONCDIAG_vidSeqFld(void);
void HEATSENO2DSFONCDIAG_vidtrsvCount(void);
void HEATSENO2DSFONCDIAG_vidtrsvCtBva(void);


#endif /* HEATSENO2DSFONCDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
