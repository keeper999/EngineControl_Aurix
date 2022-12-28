/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS_Def.c                                                                                       */
/* !Description     : Parameters definition                                                                           */
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
 * %PID: LIBEMB:MOS DEF C-99055675X1544X41.A-SRC;1.9 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "MOS_TYPES.h"
#include "MOS.h"
#include "MOS_Cfg.h"
#include "MOS_Private.h"
#include "HOD.h"
#include "Gpt.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define MOS_START_SEC_VAR_UNSPECIFIED
#include "MOS_MemMap.h"

/* !MComment: Array to enable the diagnosis for each instance                 */
VAR (boolean, MOS_VAR) MOS_abDiagnosisAuthorized[MOS_udtINSTANCE_NB];

/* !MComment: Array which save the last Dio command applied to a component    */
VAR (boolean, MOS_VAR) MOS_abDioLastCommand[MOS_udtINSTANCE_NB];

/* !MComment: Array which indicates if a transition was done since last diag  */
VAR (boolean, MOS_VAR) MOS_abTransition[MOS_udtINSTANCE_NB];

/* !MComment: Boolean which indicates the current state of the Dio output of  */
/*            each MOS component                                              */
VAR (boolean, MOS_VAR) MOS_abDioCurrentState[MOS_udtINSTANCE_NB];

/* !MComment: Array of current mode set for the udtInstance                   */
VAR (HOD_tenuMode, MOS_VAR) MOS_aenuCurrentMode[MOS_udtINSTANCE_NB];

/* !MComment: Array of time of state transition                               */
VAR (Gpt_ValueType, MOS_VAR) MOS_audtTransitionTime[MOS_udtINSTANCE_NB];

/* !MComment: Array of mask time to apply: high mask time or low mask time    */
VAR (Gpt_ValueType, MOS_VAR) MOS_audtMaskTimeToApply[MOS_udtINSTANCE_NB];

/* !MComment: Array of software counter for diagnosis (only if an instance    */
/*            is configured to execute edge diagnosis                         */
VAR (Gpt_ValueType, MOS_VAR) MOS_audtDownCounter[MOS_udtINSTANCE_NB];

/* !MComment: Boolean which indicates if the running diagnosis is an edge one */
VAR (boolean, MOS_VAR) MOS_bDiagOnEdgeRunning;

#define MOS_STOP_SEC_VAR_UNSPECIFIED
#include "MOS_MemMap.h"


#define MOS_START_SEC_VAR_8BIT
#include "MOS_MemMap.h"

/* !MComment: Array which count the number of Vbat short circuit in order to  */
/*            compare with MOS_aku8ShortCircuitDetectionNb array              */
VAR (uint8, MOS_VAR) MOS_au8ShortCircuitCounter[MOS_udtINSTANCE_NB];

/* !MComment: Array which count the number of diagnosis period since the      */
/*            deacivation of the component (after a detection of a SCVbat)    */
VAR (uint8, MOS_VAR) MOS_au8ReactivationRemainDelay[MOS_udtINSTANCE_NB];

/* !MComment: Array to enable the command for each instance                   */
VAR (uint8, MOS_VAR) MOS_au8CmdAuthorized[MOS_udtINSTANCE_NB];

#define MOS_STOP_SEC_VAR_8BIT
#include "MOS_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
