/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF572_PRIVATE.H */

#ifndef FHCANF572_PRIVATE_H
#define FHCANF572_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN572_vidCalcMonWindow(void);
extern void FHCANF572_vidUpdateSignalPM1359(void);
extern void FHCANF572_vidUpdateSignalPM1357(void);
extern void FHCANF572_vidUpdateSignalPM1358(void);
extern void FHCANF572_vidUpdateSignalPM1446(void);
extern void FHCAN572_vidCalcMonFPM1360Window(void);
extern void FHCANF572_vidUpdateSignalPM1360(void);
extern void FHCANF572_vidUpdateSignalPM1377(void);
extern void FHCANF572_vidUpdateSignalPM1378(void);
extern void FHCANF572_vidUpdateSignalPM1379(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
