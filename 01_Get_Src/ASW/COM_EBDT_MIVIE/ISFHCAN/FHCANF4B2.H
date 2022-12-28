/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4B2.H */

#ifndef FHCANF4B2_H
#define FHCANF4B2_H

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

extern void FHCAN_vidInit_Rx_4B2(void);
extern void FHCANF4B2_vidFrameReceived(void);
extern void FHCANF4B2_vidFrameNotReceived(void);
extern void FHCAN4B2_vidMonShoUpdate(uint8 Dlc);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif