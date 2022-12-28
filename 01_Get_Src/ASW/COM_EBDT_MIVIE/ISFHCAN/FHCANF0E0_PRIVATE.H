/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF0E0_PRIVATE.H */

#ifndef FHCANF0E0_PRIVATE_H
#define FHCANF0E0_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCANF0E0_vidUpdateSignalP822(void);
extern void FHCANF0E0_vidUpdateSignalPM1426(void);
extern void FHCANF0E0_vidUpdateSignalPM1427(void);
extern void FHCANF0E0_vidUpdateSignalPM1428(void);
extern void FHCANF0E0_vidUpdateSignalPM1429(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
