/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF0E8.H */
#ifndef ISCANF0E8_H
#define ISCANF0E8_H

#include "STD_TYPES.H"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void ISCAN_vidInit_Tx_0E8(void);
extern void ISCAN_vidEve_Tx_EAC_CMM_UCC_0E8(void);
extern void ISCAN_vidEve_Tx_RQD_CMM_UCC_0E8(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATAS                                                                      */
/******************************************************************************/

#endif
