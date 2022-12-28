/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF30D_PRIVATE.H */

#ifndef FHCANF30D_PRIVATE_H
#define FHCANF30D_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN30D_vidCalcMonWindow(void);
extern void FHCAN30D_vidCalcMonFP263Window(void);
extern void FHCANF30D_vidUpdateSignalP263(void);
extern void FHCAN30D_vidCalcMonFP264Window(void);
extern void FHCANF30D_vidUpdateSignalP264(void);
extern void FHCAN30D_vidCalcMonFP265Window(void);
extern void FHCANF30D_vidUpdateSignalP265(void);
extern void FHCAN30D_vidCalcMonFP266Window(void);
extern void FHCANF30D_vidUpdateSignalP266(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
