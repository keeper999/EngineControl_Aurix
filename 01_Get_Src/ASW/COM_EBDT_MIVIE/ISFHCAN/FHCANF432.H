/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF432.H */

#ifndef FHCANF432_H
#define FHCANF432_H

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

extern void FHCAN_vidInit_Rx_432(void);
extern void FHCANF432_vidFrameReceived(void);
extern void FHCANF432_vidFrameNotReceived(void);
extern void FHCAN432_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN432_vidMonInvldP214Update(void);
extern void FHCAN432_vidMonFrbdP249Update(void);
extern void FHCAN432_vidMonFrbdP251Update(void);
extern void FHCAN432_vidMonFrbdP402Update(void);
extern void FHCAN432_vidMonFrbdP368Update(void);
extern void FHCAN432_vidMonFrbdP369Update(void);
extern void FHCAN432_vidMonFrbdPM1424Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif