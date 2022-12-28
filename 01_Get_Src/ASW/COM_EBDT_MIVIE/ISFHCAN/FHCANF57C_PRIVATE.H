/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF57C_PRIVATE.H */

#ifndef FHCANF57C_PRIVATE_H
#define FHCANF57C_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN57C_vidCalcMonDMTRWindow(void);
extern void FHCAN57C_vidCalcMonWindow(void);
extern void FHCAN57C_vidCalcMonFPM1418Window(void);
extern void FHCANF57C_vidUpdateSignalPM1418(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
