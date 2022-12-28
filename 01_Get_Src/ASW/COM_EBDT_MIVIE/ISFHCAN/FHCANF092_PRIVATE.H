/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF092_PRIVATE.H */

#ifndef FHCANF092_PRIVATE_H
#define FHCANF092_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCANF092_vidUpdateSignalP895(void);
extern void FHCANF092_vidUpdateSignalP928(void);
extern void FHCANF092_vidUpdateSignalP896(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
