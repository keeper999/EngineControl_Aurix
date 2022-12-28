/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF7F2_PRIVATE.H */

#ifndef FHCANF7F2_PRIVATE_H
#define FHCANF7F2_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN7F2_vidCalcMonWindow(void);
extern void FHCAN7F2_vidCalcMonFP849Window(void);
extern void FHCANF7F2_vidUpdateSignalP849(void);
extern void FHCAN7F2_vidCalcMonFP146Window(void);
extern void FHCANF7F2_vidUpdateSignalP146(void);
extern void FHCAN7F2_vidCalcMonFP015Window(void);
extern void FHCANF7F2_vidUpdateSignalP015(void);
extern void FHCANF7F2_vidUpdateSignalP301(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
