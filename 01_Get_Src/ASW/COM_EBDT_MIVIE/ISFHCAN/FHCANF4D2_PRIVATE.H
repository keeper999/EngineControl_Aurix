/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4D2_PRIVATE.H */

#ifndef FHCANF4D2_PRIVATE_H
#define FHCANF4D2_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN4D2_vidCalcMonWindow(void);
extern void FHCANF4D2_vidUpdateSignalPM1472(void);
extern void FHCANF4D2_vidUpdateSignalPM1473(void);
extern void FHCANF4D2_vidUpdateSignalPM1474(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
