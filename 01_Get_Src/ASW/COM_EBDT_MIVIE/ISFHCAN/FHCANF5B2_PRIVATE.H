/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF5B2_PRIVATE.H */

#ifndef FHCANF5B2_PRIVATE_H
#define FHCANF5B2_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN5B2_vidCalcMonWindow(void);
extern void FHCAN5B2_vidCalcMonFP146Window(void);
extern void FHCANF5B2_vidUpdateSignalP146(void);
extern void FHCANF5B2_vidUpdateSignalP301(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
