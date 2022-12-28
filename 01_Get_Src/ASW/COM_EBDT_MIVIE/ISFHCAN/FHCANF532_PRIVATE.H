/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF532_PRIVATE.H */

#ifndef FHCANF532_PRIVATE_H
#define FHCANF532_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN532_vidCalcMonWindow(void);
extern void FHCAN532_vidCalcMonFPM1414Window(void);
extern void FHCANF532_vidUpdateSignalPM1414(void);
extern void FHCAN532_vidCalcMonFPM1415Window(void);
extern void FHCANF532_vidUpdateSignalPM1415(void);
extern void FHCAN532_vidCalcMonFPM1416Window(void);
extern void FHCANF532_vidUpdateSignalPM1416(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
