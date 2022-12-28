/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3AD_PRIVATE.H */

#ifndef FHCANF3AD_PRIVATE_H
#define FHCANF3AD_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN3AD_vidCalcMonWindow(void);
extern void FHCANF3AD_vidUpdateSignalP299(void);
extern void FHCANF3AD_vidUpdateSignalP599(void);
extern void FHCAN3AD_vidCalcMonFP337Window(void);
extern void FHCANF3AD_vidUpdateSignalP337(void);
extern void FHCANF3AD_vidUpdateSignalFP0604(void);
extern void FHCANF3AD_vidUpdateSignalFP0603(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
