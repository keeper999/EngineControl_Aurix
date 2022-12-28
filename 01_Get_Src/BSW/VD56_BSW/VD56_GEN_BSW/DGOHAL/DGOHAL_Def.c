/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : DGOHAL                                                                                          */
/* !Description     : Diagnostics of the ECU                                                                          */
/*                                                                                                                    */
/* !File            : DGOHAL_Def.c                                                                                    */
/* !Description     : Data definition of the DGOHAL Component                                                         */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5395989                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:DGOHAL DEF C-99052624X1608X75.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "DGOHAL_Types.h"
#include "DGOHAL_Cfg.h"
#include "DGOHAL_Def.h"
#include "DGOHAL_Co.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation define are defined                     */
/**********************************************************************************************************************/

#ifndef DGOHAL_coENABLED
   #error The macro-constant DGOHAL_coENABLED shall be defined
#endif
#ifndef DGOHAL_coFAULT_FILTERING
   #error The macro-constant DGOHAL_coFAULT_FILTERING shall be defined
#endif

/**********************************************************************************************************************/
/* CALIBRATIONS DEFINITION                                                                                            */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* CONSTANTS DEFINITION                                                                                               */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/

#define DGOHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "DGOHAL_MemMap.h"

#if DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED
/* !MComment: Declaration of the diagnostic and status arrays                 */
VAR(boolean, DGOHAL_VAR) DGOHAL_abNotificationStatus[DGOHAL_udtCALLBACK_TABLE_SIZE];
#endif /*  DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED */

#define DGOHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "DGOHAL_MemMap.h"


#define DGOHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "DGOHAL_MemMap.h"

VAR(DGOHAL_tbfStatus, DGOHAL_VAR) DGOHAL_abfStatusTable[DGOHAL_udtCHANNEL_NB];

#define DGOHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "DGOHAL_MemMap.h"
/*-------------------------------------------------- end of file -----------------------------------------------------*/
