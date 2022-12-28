/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF572.H */

#ifndef FHCANF572_H
#define FHCANF572_H

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

extern void FHCAN_vidInit_Rx_572(void);
extern void FHCANF572_vidFrameReceived(void);
extern void FHCANF572_vidFrameNotReceived(void);
extern void FHCAN572_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN572_vidMonInvldPM1360Update(void);
extern void FHCAN572_vidMonFrbdPM1360Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif