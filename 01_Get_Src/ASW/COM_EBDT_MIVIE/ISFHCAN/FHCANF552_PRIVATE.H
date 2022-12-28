/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF552_PRIVATE.H */

#ifndef FHCANF552_PRIVATE_H
#define FHCANF552_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN552_vidCalcMonWindow(void);
extern void FHCAN552_vidCalcMonFP255Window(void);
extern void FHCANF552_vidUpdateSignalP255(void);
extern void FHCAN552_vidCalcMonFP256Window(void);
extern void FHCANF552_vidUpdateSignalP256(void);
extern void FHCAN552_vidCalcMonFP257Window(void);
extern void FHCANF552_vidUpdateSignalP257(void);
extern void FHCAN552_vidCalcMonFP325Window(void);
extern void FHCANF552_vidUpdateSignalP325(void);
extern void FHCAN552_vidCalcMonFP015Window(void);
extern void FHCANF552_vidUpdateSignalP015(void);
extern void FHCAN552_vidCalcMonFP326Window(void);
extern void FHCANF552_vidUpdateSignalP326(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
