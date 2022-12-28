/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF3C9.H */

#ifndef FHCANF3C9_H
#define FHCANF3C9_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
#define ISFHCAN_START_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

extern const uint8 Ext_noCks3C9IniCks_C;

#define ISFHCAN_STOP_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean ISCAN_bSecuChkOKF3C9;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#define ISFHCAN_START_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

extern uint8 ISCAN_u8SecuResultF3C9;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_3C9(void);
extern void FHCANF3C9_vidFrameReceived(void);
extern void FHCANF3C9_vidFrameNotReceived(void);
extern void FHCAN3C9_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN3C9_vidMonChkUpdate(void);
extern void FHCAN3C9_vidMonCntUpdate(void);
extern void FHCAN3C9_vidMonInvldP363Update(void);
extern void FHCAN3C9_vidMonFrbdP481Update(void);
extern void FHCAN3C9_vidMonInvldP364Update(void);
extern void FHCAN3C9_vidMonFrbdP364Update(void);
extern void FHCAN3C9_vidMonInvldP482Update(void);
extern void FHCAN3C9_vidMonFrbdP482Update(void);
extern void FHCAN3C9_vidMonInvldP483Update(void);
extern void FHCAN3C9_vidMonFrbdP483Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif