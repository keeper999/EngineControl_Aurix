/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF532.H */

#ifndef FHCANF532_H
#define FHCANF532_H

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

extern void FHCAN_vidInit_Rx_532(void);
extern void FHCANF532_vidFrameReceived(void);
extern void FHCANF532_vidFrameNotReceived(void);
extern void FHCAN532_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN532_vidMonInvldPM1414Update(void);
extern void FHCAN532_vidMonFrbdPM1414Update(void);
extern void FHCAN532_vidMonInvldPM1415Update(void);
extern void FHCAN532_vidMonFrbdPM1415Update(void);
extern void FHCAN532_vidMonInvldPM1416Update(void);
extern void FHCAN532_vidMonFrbdPM1416Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif