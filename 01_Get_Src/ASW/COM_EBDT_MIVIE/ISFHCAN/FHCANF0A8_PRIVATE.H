/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF0A8_PRIVATE.H */

#ifndef FHCANF0A8_PRIVATE_H
#define FHCANF0A8_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCANF0A8_vidUpdateSignalP822(void);
extern void FHCANF0A8_vidUpdateSignalP823(void);
extern void FHCANF0A8_vidUpdateSignalP824(void);
extern void FHCANF0A8_vidUpdateSignalP825(void);
extern void FHCANF0A8_vidUpdateSignalP826(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
