/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF349_PRIVATE.H */

#ifndef FHCANF349_PRIVATE_H
#define FHCANF349_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN349_vidCalcMonWindow(void);
extern void FHCANF349_vidUpdateSignalPM1433(void);
extern void FHCAN349_vidCalcMonFP360Window(void);
extern void FHCANF349_vidUpdateSignalP360(void);
extern void FHCANF349_vidUpdateSignalP030(void);
extern void FHCAN349_vidCalcMonFP057Window(void);
extern void FHCANF349_vidUpdateSignalP057(void);
extern void FHCANF349_vidUpdateSignalP361(void);
extern void FHCANF349_vidUpdateSignalP167(void);
extern void FHCANF349_vidUpdateSignalP085(void);
extern void FHCANF349_vidUpdateSignalP087(void);
extern void FHCANF349_vidUpdateSignalP362(void);
extern void FHCANF349_vidUpdateSignalP009(void);
extern void FHCAN349_vidCalcMonFP008Window(void);
extern void FHCANF349_vidUpdateSignalP008(void);
extern void FHCAN349_vidCalcMonFP007Window(void);
extern void FHCANF349_vidUpdateSignalP007(void);
extern void FHCAN349_vidCalcMonFP055Window(void);
extern void FHCANF349_vidUpdateSignalP055(void);
extern void FHCAN349_vidCalcMonFP287Window(void);
extern void FHCANF349_vidUpdateSignalP287(void);
extern void FHCAN349_vidCalcMonFPM1434Window(void);
extern void FHCANF349_vidUpdateSignalPM1434(void);
extern void FHCANF349_vidUpdateSignalPM1435(void);
extern void FHCANF349_vidUpdateSignalPM2853(void);
extern void FHCANF349_vidUpdateSignalPM2842(void);
extern void FHCAN349_vidCalcMonFP166Window(void);
extern void FHCANF349_vidUpdateSignalP166(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
