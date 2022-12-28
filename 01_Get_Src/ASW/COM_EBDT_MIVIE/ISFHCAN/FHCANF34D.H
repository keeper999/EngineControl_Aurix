/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF34D.H */

#ifndef FHCANF34D_H
#define FHCANF34D_H

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

extern void FHCAN_vidInit_Rx_34D(void);
extern void FHCANF34D_vidFrameReceived(void);
extern void FHCANF34D_vidFrameNotReceived(void);
extern void FHCAN34D_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN34D_vidMonCntUpdate(void);
extern void FHCAN34D_vidMonFrbdP047Update(void);
extern void FHCAN34D_vidMonFrbdP043Update(void);
extern void FHCAN34D_vidMonFrbdP044Update(void);
extern void FHCAN34D_vidMonFrbdP045Update(void);
extern void FHCAN34D_vidMonInvldFP0593Update(void);
extern void FHCAN34D_vidMonFrbdFP0593Update(void);
extern void FHCAN34D_vidMonInvldPM1413Update(void);
extern void FHCAN34D_vidMonFrbdPM1413Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif