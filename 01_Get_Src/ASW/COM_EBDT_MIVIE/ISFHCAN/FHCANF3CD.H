/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3CD.H */

#ifndef FHCANF3CD_H
#define FHCANF3CD_H

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

extern void FHCAN_vidInit_Rx_3CD(void);
extern void FHCANF3CD_vidFrameReceived(void);
extern void FHCANF3CD_vidFrameNotReceived(void);
extern void FHCAN3CD_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN3CD_vidMonInvldP225Update(void);
extern void FHCAN3CD_vidMonFrbdPM1387Update(void);
extern void FHCAN3CD_vidMonInvldP515Update(void);
extern void FHCAN3CD_vidMonInvldP319Update(void);
extern void FHCAN3CD_vidMonFrbdP319Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif