/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50D_PRIVATE.H */

#ifndef FHCANF50D_PRIVATE_H
#define FHCANF50D_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN50D_vidCalcMonWindow(void);
extern void FHCANF50D_vidUpdateSignalP351(void);
extern void FHCANF50D_vidUpdateSignalP415(void);
extern void FHCANF50D_vidUpdateSignalPM2850(void);
extern void FHCANF50D_vidUpdateSignalPM2857(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
