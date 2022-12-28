/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF612.H */

#ifndef FHCANF612_H
#define FHCANF612_H

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

extern void FHCAN_vidInit_Rx_612(void);
extern void FHCANF612_vidFrameReceived(void);
extern void FHCANF612_vidFrameNotReceived(void);
extern void FHCAN612_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN612_vidMonFrbdP927Update(void);
extern void FHCAN612_vidMonInvldP260Update(void);
extern void FHCAN612_vidMonInvldP436Update(void);
extern void FHCAN612_vidMonFrbdP436Update(void);
extern void FHCAN612_vidMonInvldP705Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif