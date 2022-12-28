/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF44D.H */

#ifndef FHCANF44D_H
#define FHCANF44D_H

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

extern void FHCAN_vidInit_Rx_44D(void);
extern void FHCANF44D_vidFrameReceived(void);
extern void FHCANF44D_vidFrameNotReceived(void);
extern void FHCAN44D_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN44D_vidMonInvldFP0535Update(void);
extern void FHCAN44D_vidMonInvldP330Update(void);
extern void FHCAN44D_vidMonInvldP331Update(void);
extern void FHCAN44D_vidMonInvldP354Update(void);
extern void FHCAN44D_vidMonFrbdP354Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif