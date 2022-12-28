/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : SchM_Fls_17_Pmu.h $                                        **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports the exclusive area               **
**                  functions.                                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef SCHM_FLS_17_PMU_H
#define SCHM_FLS_17_PMU_H


/* Protection against other Fls API call pre-emption => needed if Fee call Fls under ISR */
/* Need protection ? */
#define SchM_Enter_Fls_17_Pmu_Init()
#define SchM_Exit_Fls_17_Pmu_Init()

/* Protection against other Fls API call pre-emption => needed if Fee call Fls under ISR */
/* Need protection ? */
#define SchM_Enter_Fls_17_Pmu_Erase()
#define SchM_Exit_Fls_17_Pmu_Erase()

/* Protection against other Fls API call pre-emption => needed if Fee call Fls under ISR */
/* Need protection ? */
#define SchM_Enter_Fls_17_Pmu_Write()
#define SchM_Exit_Fls_17_Pmu_Write()

/* Protection against Fls ISR */
#define SchM_Enter_Fls_17_Pmu_Main()
#define SchM_Exit_Fls_17_Pmu_Main()

/* Protection against Fls ISR */
#define SchM_Enter_Fls_17_Pmu_ResumeErase()
#define SchM_Exit_Fls_17_Pmu_ResumeErase()

#endif /* SCHM_FLS_H */
