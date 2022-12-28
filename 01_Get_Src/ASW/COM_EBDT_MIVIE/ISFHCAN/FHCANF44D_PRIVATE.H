/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF44D_PRIVATE.H */

#ifndef FHCANF44D_PRIVATE_H
#define FHCANF44D_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN44D_vidCalcMonWindow(void);
extern void FHCAN44D_vidCalcMonFFP0535Window(void);
extern void FHCANF44D_vidUpdateSignalFP0535(void);
extern void FHCAN44D_vidCalcMonFP330Window(void);
extern void FHCANF44D_vidUpdateSignalP330(void);
extern void FHCAN44D_vidCalcMonFP331Window(void);
extern void FHCANF44D_vidUpdateSignalP331(void);
extern void FHCAN44D_vidCalcMonFP354Window(void);
extern void FHCANF44D_vidUpdateSignalP354(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
