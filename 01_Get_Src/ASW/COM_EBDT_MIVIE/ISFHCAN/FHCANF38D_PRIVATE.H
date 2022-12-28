/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF38D_PRIVATE.H */

#ifndef FHCANF38D_PRIVATE_H
#define FHCANF38D_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN38D_vidCalcMonUC_FREINWindow(void);
extern void FHCAN38D_vidCalcMonWindow(void);
extern void FHCAN38D_vidCalcMonFP010Window(void);
extern void FHCANF38D_vidUpdateSignalP010(void);
extern void FHCAN38D_vidCalcMonFP052Window(void);
extern void FHCANF38D_vidUpdateSignalP052(void);
extern void FHCANF38D_vidUpdateSignalPM2849(void);
extern void FHCANF38D_vidUpdateSignalP607(void);
extern void FHCANF38D_vidUpdateSignalP688(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
