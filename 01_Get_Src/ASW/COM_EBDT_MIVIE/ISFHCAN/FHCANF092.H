/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF092.H */

#ifndef FHCANF092_H
#define FHCANF092_H

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

extern void FHCAN_vidInit_Rx_092(void);
extern void FHCANF092_vidFrameReceived(void);
extern void FHCANF092_vidFrameNotReceived(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif