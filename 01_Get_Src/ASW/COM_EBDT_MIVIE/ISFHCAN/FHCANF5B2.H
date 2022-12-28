/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF5B2.H */

#ifndef FHCANF5B2_H
#define FHCANF5B2_H

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

extern void FHCAN_vidInit_Rx_5B2(void);
extern void FHCANF5B2_vidFrameReceived(void);
extern void FHCANF5B2_vidFrameNotReceived(void);
extern void FHCAN5B2_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN5B2_vidMonInvldP146Update(void);
extern void FHCAN5B2_vidMonFrbdP146Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif