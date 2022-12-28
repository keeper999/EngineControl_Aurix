/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF329_PRIVATE.H */

#ifndef FHCANF329_PRIVATE_H
#define FHCANF329_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN329_vidCalcMonWindow(void);
extern void FHCANF329_vidUpdateSignalPM2851(void);
extern void FHCANF329_vidUpdateSignalPM2839(void);
extern void FHCANF329_vidUpdateSignalP442(void);
extern void FHCANF329_vidUpdateSignalP443(void);
extern void FHCANF329_vidUpdateSignalP444(void);
extern void FHCANF329_vidUpdateSignalP441(void);
extern void FHCAN329_vidCalcMonFP445Window(void);
extern void FHCANF329_vidUpdateSignalP445(void);
extern void FHCAN329_vidCalcMonFP397Window(void);
extern void FHCANF329_vidUpdateSignalP397(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
