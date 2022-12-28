/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF432_PRIVATE.H */

#ifndef FHCANF432_PRIVATE_H
#define FHCANF432_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN432_vidCalcMonWindow(void);
extern void FHCANF432_vidUpdateSignalP276(void);
extern void FHCAN432_vidCalcMonFP214Window(void);
extern void FHCANF432_vidUpdateSignalP214(void);
extern void FHCANF432_vidUpdateSignalP216(void);
extern void FHCAN432_vidCalcMonFP249Window(void);
extern void FHCANF432_vidUpdateSignalP249(void);
extern void FHCAN432_vidCalcMonFP251Window(void);
extern void FHCANF432_vidUpdateSignalP251(void);
extern void FHCAN432_vidCalcMonFP402Window(void);
extern void FHCANF432_vidUpdateSignalP402(void);
extern void FHCANF432_vidUpdateSignalP289(void);
extern void FHCANF432_vidUpdateSignalP350(void);
extern void FHCANF432_vidUpdateSignalP403(void);
extern void FHCANF432_vidUpdateSignalP367(void);
extern void FHCAN432_vidCalcMonFP368Window(void);
extern void FHCANF432_vidUpdateSignalP368(void);
extern void FHCAN432_vidCalcMonFP369Window(void);
extern void FHCANF432_vidUpdateSignalP369(void);
extern void FHCAN432_vidCalcMonFPM1424Window(void);
extern void FHCANF432_vidUpdateSignalPM1424(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
