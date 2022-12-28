/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF612_PRIVATE.H */

#ifndef FHCANF612_PRIVATE_H
#define FHCANF612_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN612_vidCalcMonWindow(void);
extern void FHCAN612_vidCalcMonFP927Window(void);
extern void FHCANF612_vidUpdateSignalP927(void);
extern void FHCAN612_vidCalcMonFP260Window(void);
extern void FHCANF612_vidUpdateSignalP260(void);
extern void FHCAN612_vidCalcMonFP436Window(void);
extern void FHCANF612_vidUpdateSignalP436(void);
extern void FHCAN612_vidCalcMonFP705Window(void);
extern void FHCANF612_vidUpdateSignalP705(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
