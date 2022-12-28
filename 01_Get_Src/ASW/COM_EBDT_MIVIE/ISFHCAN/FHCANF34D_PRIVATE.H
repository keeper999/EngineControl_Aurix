/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF34D_PRIVATE.H */

#ifndef FHCANF34D_PRIVATE_H
#define FHCANF34D_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN34D_vidCalcMonWindow(void);
extern void FHCANF34D_vidUpdateSignalP147(void);
extern void FHCAN34D_vidCalcMonFP047Window(void);
extern void FHCANF34D_vidUpdateSignalP047(void);
extern void FHCAN34D_vidCalcMonFP043Window(void);
extern void FHCANF34D_vidUpdateSignalP043(void);
extern void FHCAN34D_vidCalcMonFP044Window(void);
extern void FHCANF34D_vidUpdateSignalP044(void);
extern void FHCAN34D_vidCalcMonFP045Window(void);
extern void FHCANF34D_vidUpdateSignalP045(void);
extern void FHCAN34D_vidCalcMonFFP0593Window(void);
extern void FHCANF34D_vidUpdateSignalFP0593(void);
extern void FHCANF34D_vidUpdateSignalP157(void);
extern void FHCANF34D_vidUpdateSignalP624(void);
extern void FHCANF34D_vidUpdateSignalP353(void);
extern void FHCANF34D_vidUpdateSignalP352(void);
extern void FHCAN34D_vidCalcMonFPM1413Window(void);
extern void FHCANF34D_vidUpdateSignalPM1413(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
