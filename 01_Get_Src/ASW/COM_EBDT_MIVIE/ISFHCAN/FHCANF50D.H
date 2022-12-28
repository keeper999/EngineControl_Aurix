/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50D.H */

#ifndef FHCANF50D_H
#define FHCANF50D_H

#include "STD_TYPES.H"

/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/
#define ISFHCAN_START_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

extern const uint8 Ext_noCks50DIniCks_C;

#define ISFHCAN_STOP_SEC_CALIB_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean ISCAN_bSecuChkOKF50D;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#define ISFHCAN_START_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

extern uint8 ISCAN_u8SecuResultF50D;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_8BIT
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void FHCAN_vidInit_Rx_50D(void);
extern void FHCANF50D_vidFrameReceived(void);
extern void FHCANF50D_vidFrameNotReceived(void);
extern void FHCAN50D_vidMonShoUpdate(uint8 Dlc);
extern void FHCAN50D_vidMonChkUpdate(void);
extern void FHCAN50D_vidMonCntUpdate(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

#endif