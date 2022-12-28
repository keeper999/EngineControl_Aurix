/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3C9_PRIVATE.H */

#ifndef FHCANF3C9_PRIVATE_H
#define FHCANF3C9_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN3C9_vidCalcMonWindow(void);
extern void FHCAN3C9_vidCalcMonFP363Window(void);
extern void FHCANF3C9_vidUpdateSignalP363(void);
extern void FHCAN3C9_vidCalcMonFP481Window(void);
extern void FHCANF3C9_vidUpdateSignalP481(void);
extern void FHCANF3C9_vidUpdateSignalPM2854(void);
extern void FHCANF3C9_vidUpdateSignalPM2843(void);
extern void FHCAN3C9_vidCalcMonFP364Window(void);
extern void FHCANF3C9_vidUpdateSignalP364(void);
extern void FHCAN3C9_vidCalcMonFP482Window(void);
extern void FHCANF3C9_vidUpdateSignalP482(void);
extern void FHCAN3C9_vidCalcMonFP483Window(void);
extern void FHCANF3C9_vidUpdateSignalP483(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
