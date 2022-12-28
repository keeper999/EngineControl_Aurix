/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF4F2.H */

#ifndef FHCANF4F2_H
#define FHCANF4F2_H

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

extern void FHCAN_vidInit_Rx_4F2(void);
extern void FHCANF4F2_vidFrameReceived(void);
extern void FHCANF4F2_vidFrameNotReceived(void);
extern void FHCAN4F2_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN4F2_vidMonInvldP434Update(void);
extern void FHCAN4F2_vidMonFrbdP434Update(void);
extern void FHCAN4F2_vidMonInvldP438Update(void);
extern void FHCAN4F2_vidMonFrbdP438Update(void);
extern void FHCAN4F2_vidMonInvldP429Update(void);
extern void FHCAN4F2_vidMonInvldP437Update(void);
extern void FHCAN4F2_vidMonFrbdP437Update(void);
extern void FHCAN4F2_vidMonInvldP490Update(void);
extern void FHCAN4F2_vidMonFrbdP490Update(void);
extern void FHCAN4F2_vidMonFrbdP493Update(void);
extern void FHCAN4F2_vidMonInvldP491Update(void);
extern void FHCAN4F2_vidMonFrbdP491Update(void);
extern void FHCAN4F2_vidMonFrbdP494Update(void);
extern void FHCAN4F2_vidMonInvldP492Update(void);
extern void FHCAN4F2_vidMonFrbdP492Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif