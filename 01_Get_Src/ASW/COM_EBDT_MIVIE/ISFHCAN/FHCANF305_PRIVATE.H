/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF305_PRIVATE.H */

#ifndef FHCANF305_PRIVATE_H
#define FHCANF305_PRIVATE_H

#include "STD_TYPES.H"
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN305_vidCalcMonCAPT_VOLWindow(void);
extern void FHCAN305_vidCalcMonWindow(void);
extern void FHCAN305_vidCalcMonFP537Window(void);
extern void FHCANF305_vidUpdateSignalP537(void);
extern void FHCAN305_vidCalcMonFP538Window(void);
extern void FHCANF305_vidUpdateSignalP538(void);
extern void FHCANF305_vidUpdateSignalP846(void);
extern void FHCANF305_vidUpdateSignalP871(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
#endif
