/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF489_PRIVATE.H */

#ifndef FHCANF489_PRIVATE_H
#define FHCANF489_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN489_vidCalcMonBVWindow(void);
extern void FHCAN489_vidCalcMonWindow(void);
extern void FHCANF489_vidUpdateSignalP282(void);
extern void FHCANF489_vidUpdateSignalP029(void);
extern void FHCANF489_vidUpdateSignalP374(void);
extern void FHCANF489_vidUpdateSignalP048(void);
extern void FHCANF489_vidUpdateSignalP285(void);
extern void FHCANF489_vidUpdateSignalP376(void);
extern void FHCANF489_vidUpdateSignalPM1423(void);
extern void FHCANF489_vidUpdateSignalP375(void);
extern void FHCAN489_vidCalcMonFP102Window(void);
extern void FHCANF489_vidUpdateSignalP102(void);
extern void FHCAN489_vidCalcMonFP254Window(void);
extern void FHCANF489_vidUpdateSignalP254(void);
extern void FHCAN489_vidCalcMonFP218Window(void);
extern void FHCANF489_vidUpdateSignalP218(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
