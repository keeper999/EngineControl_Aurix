/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF492_PRIVATE.H */

#ifndef FHCANF492_PRIVATE_H
#define FHCANF492_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN492_vidCalcMonWindow(void);
extern void FHCANF492_vidUpdateSignalPM1475(void);
extern void FHCANF492_vidUpdateSignalPM1476(void);
extern void FHCANF492_vidUpdateSignalPM1477(void);
extern void FHCANF492_vidUpdateSignalPM1478(void);
extern void FHCANF492_vidUpdateSignalPM1479(void);
extern void FHCANF492_vidUpdateSignalPM1480(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
