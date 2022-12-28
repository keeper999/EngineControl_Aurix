/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF768.H */
#ifndef ISCANF768_H
#define ISCANF768_H

#include "STD_TYPES.H"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void ISCAN_vidInit_Tx_768(void);
extern void ISCAN_vidEve_Tx_JDD_CAN_CMM_768(void);
extern void ISCAN_vidEve_Tx_NEW_JDD_CMM_768(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATAS                                                                      */
/******************************************************************************/

#endif
