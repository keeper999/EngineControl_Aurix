/***************************************************************************
;**
;** FILE NAME      : MISFSUCDET_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFSUCDET_L_H
#define MISFSUCDET_L_H

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

extern const uint8  MISFSUCDET_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_2_misfire_norm_detected_uavb0;
extern boolean Mf_misfire1_detected_uavb0;
extern boolean Mf_misfire2_detected_uavb0;
extern boolean MISFSUCDET_bEnablePrev;
extern sint16 Mf_comb1_algo_out_corr_uavn0;
extern sint16 Mf_comb1_algo_trust_uavn0;
extern sint16 Mf_comb2_algo_out_corr_uavn0;
extern sint16 Mf_comb2_algo_trust_uavn0;
extern sint16 Mf_p_filt1_algo_out_uavn0;
extern sint16 Mf_p_filt1_algo_trust_uavn0;
extern sint16 Mf_p_filt2_algo_out_uavn0;
extern sint16 Mf_p_filt2_algo_trust_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFSUCDET_vidAlgorithme(void);
void MISFSUCDET_vidDecision(void);
void MISFSUCDET_vidDetTwoMisfNotChckd(void);
void MISFSUCDET_vidFirstAlgoTrust(void);
void MISFSUCDET_vidFirstCombDetection(void);
void MISFSUCDET_vidFirstFilter(void);
void MISFSUCDET_vidFirstFilterMain(void);
void MISFSUCDET_vidFirstMisfDetection(void);
void MISFSUCDET_vidFstMisfDecision(void);
void MISFSUCDET_vidFstPfiltDetection(void);
void MISFSUCDET_vidInitOutput(void);
void MISFSUCDET_vidSecondFilter(void);
void MISFSUCDET_vidSndAlgoTrust(void);
void MISFSUCDET_vidSndCombDetection(void);
void MISFSUCDET_vidSndFilterMain(void);
void MISFSUCDET_vidSndMisfDecision(void);
void MISFSUCDET_vidSndMisfDetection(void);
void MISFSUCDET_vidSndPfiltDetect(void);
void MISFSUCDET_vidSuccessiveMisfires(void);
void MISFSUCDET_vidSucMisfDetection(void);
void MISFSUCDET_vidSucMisfDetectMain(void);


#endif /* MISFSUCDET_L_H */

/*-------------------------------- end of file -------------------------------*/
