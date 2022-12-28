/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF592_PRIVATE.H */

#ifndef FHCANF592_PRIVATE_H
#define FHCANF592_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN592_vidCalcMonWindow(void);
extern void FHCAN592_vidCalcMonFP272Window(void);
extern void FHCANF592_vidUpdateSignalP272(void);
extern void FHCAN592_vidCalcMonFP273Window(void);
extern void FHCANF592_vidUpdateSignalP273(void);
extern void FHCAN592_vidCalcMonFP349Window(void);
extern void FHCANF592_vidUpdateSignalP349(void);
extern void FHCAN592_vidCalcMonFP418Window(void);
extern void FHCANF592_vidUpdateSignalP418(void);
extern void FHCAN592_vidCalcMonFP419Window(void);
extern void FHCANF592_vidUpdateSignalP419(void);
extern void FHCAN592_vidCalcMonFP420Window(void);
extern void FHCANF592_vidUpdateSignalP420(void);
extern void FHCAN592_vidCalcMonFP421Window(void);
extern void FHCANF592_vidUpdateSignalP421(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
