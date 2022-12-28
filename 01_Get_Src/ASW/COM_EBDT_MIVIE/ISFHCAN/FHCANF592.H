/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF592.H */

#ifndef FHCANF592_H
#define FHCANF592_H

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

extern void FHCAN_vidInit_Rx_592(void);
extern void FHCANF592_vidFrameReceived(void);
extern void FHCANF592_vidFrameNotReceived(void);
extern void FHCAN592_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN592_vidMonInvldP272Update(void);
extern void FHCAN592_vidMonFrbdP272Update(void);
extern void FHCAN592_vidMonInvldP273Update(void);
extern void FHCAN592_vidMonFrbdP273Update(void);
extern void FHCAN592_vidMonInvldP349Update(void);
extern void FHCAN592_vidMonFrbdP349Update(void);
extern void FHCAN592_vidMonInvldP418Update(void);
extern void FHCAN592_vidMonFrbdP418Update(void);
extern void FHCAN592_vidMonInvldP419Update(void);
extern void FHCAN592_vidMonFrbdP419Update(void);
extern void FHCAN592_vidMonInvldP420Update(void);
extern void FHCAN592_vidMonInvldP421Update(void);
extern void FHCAN592_vidMonFrbdP421Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif