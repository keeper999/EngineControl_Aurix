/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF489.H */

#ifndef FHCANF489_H
#define FHCANF489_H

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

extern void FHCAN_vidInit_Rx_489(void);
extern void FHCANF489_vidFrameReceived(void);
extern void FHCANF489_vidFrameNotReceived(void);
extern void FHCAN_vidCheckBVWindow(void);
extern void FHCAN489_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN489_vidMonInvldP102Update(void);
extern void FHCAN489_vidMonInvldP254Update(void);
extern void FHCAN489_vidMonFrbdP254Update(void);
extern void FHCAN489_vidMonInvldP218Update(void);
extern void FHCAN489_vidMonFrbdP218Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif