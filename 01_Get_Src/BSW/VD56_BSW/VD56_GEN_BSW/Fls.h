/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Fls                                                     */
/* !Description     : Fls Component                                           */
/*                                                                            */
/* !File            : Fls.h                                                   */
/* !Description     : Upper Layer of Fls_17_PMU component                     */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192490.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef FLS_H
#define FLS_H

#include "Fls_17_Pmu.h"

/******************************************************************************/
/* TYPDEF                                                                     */
/******************************************************************************/
#define Fls_ConfigType                  Fls_17_Pmu_ConfigType

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define Fls_Init                Fls_17_Pmu_Init
#define Fls_Erase               Fls_17_Pmu_Erase
#define Fls_Write               Fls_17_Pmu_Write
#define Fls_Compare             Fls_17_Pmu_Compare
#define Fls_Cancel              Fls_17_Pmu_Cancel
#define Fls_CancelNonEraseJobs  Fls_17_Pmu_CancelNonEraseJobs
#define Fls_GetStatus           Fls_17_Pmu_GetStatus
#define Fls_GetBankStatus       Fls_17_Pmu_GetBankStatus
#define Fls_GetJobResult        Fls_17_Pmu_GetJobResult
#define Fls_MainFunction        Fls_17_Pmu_MainFunction
#define Fls_SetMode             Fls_17_Pmu_SetMode
#define Fls_Read                Fls_17_Pmu_Read
#define Fls_ReadWordsSync       Fls_17_Pmu_ReadWordsSync
#define Fls_GetNotifCaller      Fls_17_Pmu_GetNotifCaller
#define Fls_CompareWordsSync    Fls_17_Pmu_CompareWordsSync
#define Fls_VerifyErase         Fls_17_Pmu_VerifyErase
#define Fls_SuspendErase        Fls_17_Pmu_SuspendErase
#define Fls_ResumeErase         Fls_17_Pmu_ResumeErase
#define Fls_GetOperStatus       Fls_17_Pmu_GetOperStatus

#endif  /* FLS_H */

/*------------------------------ end of file ---------------------------------*/
