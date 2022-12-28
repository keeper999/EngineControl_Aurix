/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF495.H */

#ifndef FHCANF495_H
#define FHCANF495_H

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

extern void FHCAN_vidInit_Rx_495(void);
extern void FHCANF495_vidFrameReceived(void);
extern void FHCANF495_vidFrameNotReceived(void);
extern void FHCAN_vidCheckUC_DIRAWindow(void);
extern void FHCAN495_vidMonShoUpdate(uint8 Dlc);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif