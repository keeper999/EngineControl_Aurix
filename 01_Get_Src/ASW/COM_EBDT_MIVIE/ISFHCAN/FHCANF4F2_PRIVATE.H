/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4F2_PRIVATE.H */

#ifndef FHCANF4F2_PRIVATE_H
#define FHCANF4F2_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN4F2_vidCalcMonWindow(void);
extern void FHCAN4F2_vidCalcMonFP434Window(void);
extern void FHCANF4F2_vidUpdateSignalP434(void);
extern void FHCAN4F2_vidCalcMonFP438Window(void);
extern void FHCANF4F2_vidUpdateSignalP438(void);
extern void FHCAN4F2_vidCalcMonFP429Window(void);
extern void FHCANF4F2_vidUpdateSignalP429(void);
extern void FHCANF4F2_vidUpdateSignalP703(void);
extern void FHCAN4F2_vidCalcMonFP437Window(void);
extern void FHCANF4F2_vidUpdateSignalP437(void);
extern void FHCAN4F2_vidCalcMonFP490Window(void);
extern void FHCANF4F2_vidUpdateSignalP490(void);
extern void FHCAN4F2_vidCalcMonFP493Window(void);
extern void FHCANF4F2_vidUpdateSignalP493(void);
extern void FHCAN4F2_vidCalcMonFP491Window(void);
extern void FHCANF4F2_vidUpdateSignalP491(void);
extern void FHCAN4F2_vidCalcMonFP494Window(void);
extern void FHCANF4F2_vidUpdateSignalP494(void);
extern void FHCAN4F2_vidCalcMonFP492Window(void);
extern void FHCANF4F2_vidUpdateSignalP492(void);
extern void FHCANF4F2_vidUpdateSignalP702(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
