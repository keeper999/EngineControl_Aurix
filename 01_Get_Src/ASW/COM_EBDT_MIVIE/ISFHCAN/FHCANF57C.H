/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF57C.H */

#ifndef FHCANF57C_H
#define FHCANF57C_H

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

extern void FHCAN_vidInit_Rx_57C(void);
extern void FHCANF57C_vidFrameReceived(void);
extern void FHCANF57C_vidFrameNotReceived(void);
extern void FHCAN_vidCheckDMTRWindow(void);
extern void FHCAN57C_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN57C_vidMonInvldPM1418Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif