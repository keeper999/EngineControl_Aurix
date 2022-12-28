/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF552.H */

#ifndef FHCANF552_H
#define FHCANF552_H

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

extern void FHCAN_vidInit_Rx_552(void);
extern void FHCAN_BSI_552_vidFrameReceived(void);
extern void FHCAN_BSI_552_vidFrameNotReceived(void);
extern void FHCAN_V2_BSI_552_vidFrameReceived(void);
extern void FHCAN_V2_BSI_552_vidFrameNotReceived(void);
extern void FHCANBSI_552_vidMonShoUpdate(uint8 Dlc);
extern void FHCANV2_BSI_552_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN552_vidMonInvldP255Update(void);
extern void FHCAN552_vidMonFrbdP255Update(void);
extern void FHCAN552_vidMonInvldP256Update(void);
extern void FHCAN552_vidMonFrbdP256Update(void);
extern void FHCAN552_vidMonInvldP257Update(void);
extern void FHCAN552_vidMonFrbdP257Update(void);
extern void FHCAN552_vidMonInvldP325Update(void);
extern void FHCAN552_vidMonInvldP015Update(void);
extern void FHCAN552_vidMonInvldP326Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif