/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF329.H */

#ifndef FHCANF329_H
#define FHCANF329_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
#define ISFHCAN_START_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

extern const uint8 Ext_noCks329IniCks_C;

#define ISFHCAN_STOP_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean ISCAN_bSecuChkOKF329;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#define ISFHCAN_START_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

extern uint8 ISCAN_u8SecuResultF329;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_329(void);
extern void FHCANF329_vidFrameReceived(void);
extern void FHCANF329_vidFrameNotReceived(void);
extern void FHCAN329_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN329_vidMonChkUpdate(void);
extern void FHCAN329_vidMonCntUpdate(void);
extern void FHCAN329_vidMonInvldP445Update(void);
extern void FHCAN329_vidMonFrbdP445Update(void);
extern void FHCAN329_vidMonFrbdP397Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif