/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS_Private.h                                                                                   */
/* !Description     : Mos internal data                                                                               */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5012137 01                                                                              */
/* !Reference       : PTS_DOC_5199248 01                                                                              */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A2542.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef MOS_PRIVATE_H
#define MOS_PRIVATE_H

#include "Std_Types.h"
#include "MOS_TYPES.h"
#include "MOS_Cfg.h"
#include "DGOHAL.h"
#include "HOD.h"
#include "Dio.h"
#include "Gpt.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !MComment: Number of samples, for the diagnosis filter                     */
#define MOS_u8SAMPLES 3


/******************************************************************************/
/* MACROS DECLARATION                                                         */
/******************************************************************************/

/* !MComment: Defines the macro functions to call according to the diag       */
/*            management                                                      */
#if (MOS_coINHIB_SCG_DIAG_MNGT == MOS_coARRAY)
#define MOS_vidSCG_DIAG_INHIBITION(snInstance, bResult) \
do \
{ \
   if(MOS_akpfbInhibScgDiag[snInstance] != NULL_PTR) \
   { \
      (bResult) = MOS_akpfbInhibScgDiag[snInstance](); \
   } \
   else \
   { \
      (bResult) = FALSE; \
   } \
} \
while (0)
#endif

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/
#define MOS_START_SEC_CONST_UNSPECIFIED
#include "MOS_MemMap.h"

extern CONST (MOS_tbfMode, MOS_CONST) MOS_akbfModeAvailable[MOS_udtINSTANCE_NB];
extern CONST (HOD_tenuMode, MOS_CONST) MOS_akenuDefaultMode[MOS_udtINSTANCE_NB];

extern CONST (Dio_ChannelType, MOS_CONST)
                MOS_akudtDioMcalChannel[MOS_udtINSTANCE_NB];

extern CONST (Dio_ChannelType, MOS_CONST)
                MOS_akudtDioForDiagMcalChannel[MOS_udtINSTANCE_NB];

extern CONST (DGOHAL_tudtChannel, MOS_CONST)
                MOS_akudtDgohalChannel[MOS_udtINSTANCE_NB];

extern CONSTP2CONST (Gpt_ValueType, MOS_CALIB, MOS_CONST)
                MOS_akpudtHighMaskTime[MOS_udtINSTANCE_NB];

extern CONSTP2CONST (Gpt_ValueType, MOS_CALIB, MOS_CONST)
                MOS_akpudtLowMaskTime[MOS_udtINSTANCE_NB];

extern CONST (boolean, MOS_CONST) MOS_akbEdgeDiag[MOS_udtINSTANCE_NB];
extern CONST (boolean, MOS_CONST) MOS_akbSchedDiag[MOS_udtINSTANCE_NB];
extern CONST (boolean, MOS_CONST)
                MOS_akbSwitchModeAvailable[MOS_udtINSTANCE_NB];

extern CONST (Gpt_ValueType, MOS_CONST)
                MOS_akudtOvfProtectionValue[MOS_udtINSTANCE_NB];

#if (MOS_coINHIB_SCG_DIAG_MNGT == MOS_coARRAY)
extern boolean (* const MOS_akpfbInhibScgDiag[MOS_udtINSTANCE_NB])(void);
#endif

#define MOS_STOP_SEC_CONST_UNSPECIFIED
#include "MOS_MemMap.h"


#define MOS_START_SEC_CONST_8BIT
#include "MOS_MemMap.h"

extern CONST (uint8, MOS_CONST)
                MOS_aku8ShortCircuitDetectionNb[MOS_udtINSTANCE_NB];
extern CONST (uint8, MOS_CONST) MOS_aku8ReactivationDelay[MOS_udtINSTANCE_NB];

#define MOS_STOP_SEC_CONST_8BIT
#include "MOS_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define MOS_START_SEC_VAR_UNSPECIFIED
#include "MOS_MemMap.h"

/* !MComment: Array to enable the diagnosis for each instance                 */
extern VAR (boolean, MOS_VAR) MOS_abDiagnosisAuthorized[MOS_udtINSTANCE_NB];

/* !MComment: Array which save the last Dio command applied to a component    */
extern VAR (boolean, MOS_VAR) MOS_abDioLastCommand[MOS_udtINSTANCE_NB];

/* !MComment: Array which indicates if a transition was done since last diag  */
extern VAR (boolean, MOS_VAR) MOS_abTransition[MOS_udtINSTANCE_NB];

/* !MComment: Array of current mode set for the udtInstance                   */
extern VAR (HOD_tenuMode, MOS_VAR) MOS_aenuCurrentMode[MOS_udtINSTANCE_NB];

/* !MComment: Array of time of state transition                               */
extern VAR (Gpt_ValueType, MOS_VAR) MOS_audtTransitionTime[MOS_udtINSTANCE_NB];

/* !MComment: Array of mask time to apply: high mask time or low mask time    */
extern VAR (Gpt_ValueType, MOS_VAR) MOS_audtMaskTimeToApply[MOS_udtINSTANCE_NB];

/* !MComment: Array of software counter for diagnosis                         */
extern VAR (Gpt_ValueType, MOS_VAR) MOS_audtDownCounter[MOS_udtINSTANCE_NB];

/* !MComment: Boolean which indicates if the running diagnosis is an edge one */
extern VAR (boolean, MOS_VAR) MOS_bDiagOnEdgeRunning;

#define MOS_STOP_SEC_VAR_UNSPECIFIED
#include "MOS_MemMap.h"


#define MOS_START_SEC_VAR_8BIT
#include "MOS_MemMap.h"

/* !MComment: Array which count the number of Vbat short circuit in order to  */
/*            compare with MOS_aku8ShortCircuitDetectionNb array              */
extern VAR (uint8, MOS_VAR) MOS_au8ShortCircuitCounter[MOS_udtINSTANCE_NB];

/* !MComment: Array which count the number of diagnosis period since the      */
/*            deacivation of the component (after a detection of a SCVbat)    */
extern VAR (uint8, MOS_VAR) MOS_au8ReactivationRemainDelay[MOS_udtINSTANCE_NB];

/* !MComment: Array to enable the Command for each instance                   */
extern VAR (uint8, MOS_VAR) MOS_au8CmdAuthorized[MOS_udtINSTANCE_NB];

#define MOS_STOP_SEC_VAR_8BIT
#include "MOS_MemMap.h"

/******************************************************************************/
/* Prototypes                                                                 */
/******************************************************************************/
extern FUNC(void, MOS_CODE)  MOS_vidDioDiagByDigitalReadBack(HOD_tudtInstance udtInstance);
extern FUNC(void, MOS_CODE)  MOS_vidShortCircuitProtection(HOD_tudtInstance udtInstance);

#endif /* MOS_PRIVATE_H  */

/*------------------------------ end of file ---------------------------------*/
