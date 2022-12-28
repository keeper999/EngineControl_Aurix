/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF30D.H */

#ifndef FHCANF30D_H
#define FHCANF30D_H

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

extern void FHCAN_vidInit_Rx_30D(void);
extern void FHCANF30D_vidFrameReceived(void);
extern void FHCANF30D_vidFrameNotReceived(void);
extern void FHCAN30D_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN30D_vidMonInvldP263Update(void);
extern void FHCAN30D_vidMonInvldP264Update(void);
extern void FHCAN30D_vidMonInvldP265Update(void);
extern void FHCAN30D_vidMonInvldP266Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif