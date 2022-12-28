/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3CD_PRIVATE.H */

#ifndef FHCANF3CD_PRIVATE_H
#define FHCANF3CD_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN3CD_vidCalcMonWindow(void);
extern void FHCANF3CD_vidUpdateSignalP224(void);
extern void FHCAN3CD_vidCalcMonFP225Window(void);
extern void FHCANF3CD_vidUpdateSignalP225(void);
extern void FHCAN3CD_vidCalcMonFPM1387Window(void);
extern void FHCANF3CD_vidUpdateSignalPM1387(void);
extern void FHCAN3CD_vidCalcMonFP515Window(void);
extern void FHCANF3CD_vidUpdateSignalP515(void);
extern void FHCANF3CD_vidUpdateSignalP226(void);
extern void FHCAN3CD_vidCalcMonFP319Window(void);
extern void FHCANF3CD_vidUpdateSignalP319(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
