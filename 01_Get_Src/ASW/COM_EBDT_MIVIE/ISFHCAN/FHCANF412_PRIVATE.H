/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF412_PRIVATE.H */

#ifndef FHCANF412_PRIVATE_H
#define FHCANF412_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN412_vidCalcMonWindow(void);
extern void FHCANF412_vidUpdateSignalPM1436(void);
extern void FHCANF412_vidUpdateSignalP013(void);
extern void FHCANF412_vidUpdateSignalPM1437(void);
extern void FHCANF412_vidUpdateSignalPM1339(void);
extern void FHCANF412_vidUpdateSignalP103(void);
extern void FHCAN412_vidCalcMonFP040Window(void);
extern void FHCANF412_vidUpdateSignalP040(void);
extern void FHCANF412_vidUpdateSignalP298(void);
extern void FHCANF412_vidUpdateSignalP277(void);
extern void FHCANF412_vidUpdateSignalP104(void);
extern void FHCANF412_vidUpdateSignalP086(void);
extern void FHCANF412_vidUpdateSignalP012(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
