/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF7F2.H */

#ifndef FHCANF7F2_H
#define FHCANF7F2_H

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

extern void FHCAN_vidInit_Rx_7F2(void);
extern void FHCANF7F2_vidFrameReceived(void);
extern void FHCANF7F2_vidFrameNotReceived(void);
extern void FHCAN7F2_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN7F2_vidMonFrbdP849Update(void);
extern void FHCAN7F2_vidMonInvldP146Update(void);
extern void FHCAN7F2_vidMonFrbdP146Update(void);
extern void FHCAN7F2_vidMonInvldP015Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif