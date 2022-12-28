/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50E.H */

#ifndef FHCANF50E_H
#define FHCANF50E_H

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

extern void FHCAN_vidInit_Rx_50E(void);
extern void FHCANF50E_vidFrameReceived(void);
extern void FHCANF50E_vidFrameNotReceived(void);
extern void FHCAN_vidCheckBSIWindow(void);
extern void FHCAN50E_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN50E_vidMonInvldPM1386Update(void);
extern void FHCAN50E_vidMonInvldP046Update(void);
extern void FHCAN50E_vidMonFrbdP046Update(void);
extern void FHCAN50E_vidMonFrbdP417Update(void);
extern void FHCAN50E_vidMonInvldP210Update(void);
extern void FHCAN50E_vidMonFrbdP208Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif