/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50E_PRIVATE.H */

#ifndef FHCANF50E_PRIVATE_H
#define FHCANF50E_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN50E_vidCalcMonBSIWindow(void);
extern void FHCAN50E_vidCalcMonWindow(void);
extern void FHCANF50E_vidUpdateSignalP232(void);
extern void FHCAN50E_vidCalcMonFPM1386Window(void);
extern void FHCANF50E_vidUpdateSignalPM1386(void);
extern void FHCANF50E_vidUpdateSignalP209(void);
extern void FHCAN50E_vidCalcMonFP046Window(void);
extern void FHCANF50E_vidUpdateSignalP046(void);
extern void FHCANF50E_vidUpdateSignalPM1425(void);
extern void FHCANF50E_vidUpdateSignalP189(void);
extern void FHCANF50E_vidUpdateSignalPM1388(void);
extern void FHCAN50E_vidCalcMonFP417Window(void);
extern void FHCANF50E_vidUpdateSignalP417(void);
extern void FHCAN50E_vidCalcMonFP210Window(void);
extern void FHCANF50E_vidUpdateSignalP210(void);
extern void FHCAN50E_vidCalcMonFP208Window(void);
extern void FHCANF50E_vidUpdateSignalP208(void);
extern void FHCANF50E_vidUpdateSignalP219(void);
extern void FHCANF50E_vidUpdateSignalP220(void);
extern void FHCANF50E_vidUpdateSignalP221(void);
extern void FHCANF50E_vidUpdateSignalP222(void);
extern void FHCANF50E_vidUpdateSignalP231(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
