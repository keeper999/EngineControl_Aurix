/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF0E0.H */

#ifndef FHCANF0E0_H
#define FHCANF0E0_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_0E0(void);
extern void FHCANF0E0_vidFrameReceived(void);
extern void FHCANF0E0_vidFrameNotReceived(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif