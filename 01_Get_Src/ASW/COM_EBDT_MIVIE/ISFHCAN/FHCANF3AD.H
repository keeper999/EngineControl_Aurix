/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3AD.H */

#ifndef FHCANF3AD_H
#define FHCANF3AD_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
#define ISFHCAN_START_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

extern const uint8 Ext_noCks3ADIniCks_C;

#define ISFHCAN_STOP_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean ISCAN_bSecuChkOKF3AD;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#define ISFHCAN_START_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

extern uint8 ISCAN_u8SecuResultF3AD;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_3AD(void);
extern void FHCANF3AD_vidFrameReceived(void);
extern void FHCANF3AD_vidFrameNotReceived(void);
extern void FHCAN3AD_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN3AD_vidMonChkUpdate(void);
extern void FHCAN3AD_vidMonCntUpdate(void);
extern void FHCAN3AD_vidMonFrbdP337Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif