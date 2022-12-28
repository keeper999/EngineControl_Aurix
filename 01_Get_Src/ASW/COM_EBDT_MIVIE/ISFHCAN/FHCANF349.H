/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF349.H */

#ifndef FHCANF349_H
#define FHCANF349_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
#define ISFHCAN_START_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

extern const uint8 Ext_noCks349IniCks_C;

#define ISFHCAN_STOP_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean ISCAN_bSecuChkOKF349;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#define ISFHCAN_START_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

extern uint8 ISCAN_u8SecuResultF349;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_349(void);
extern void FHCANF349_vidFrameReceived(void);
extern void FHCANF349_vidFrameNotReceived(void);
extern void FHCAN349_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN349_vidMonChkUpdate(void);
extern void FHCAN349_vidMonCntUpdate(void);
extern void FHCAN349_vidMonFrbdP360Update(void);
extern void FHCAN349_vidMonFrbdP057Update(void);
extern void FHCAN349_vidMonFrbdP008Update(void);
extern void FHCAN349_vidMonInvldP007Update(void);
extern void FHCAN349_vidMonFrbdP007Update(void);
extern void FHCAN349_vidMonInvldP055Update(void);
extern void FHCAN349_vidMonFrbdP287Update(void);
extern void FHCAN349_vidMonFrbdPM1434Update(void);
extern void FHCAN349_vidMonFrbdP166Update(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif