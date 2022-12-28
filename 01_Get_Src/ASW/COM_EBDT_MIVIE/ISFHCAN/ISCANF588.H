/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF588.H */
#ifndef ISCANF588_H
#define ISCANF588_H

#include "STD_TYPES.H"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void ISCAN_vidInit_Tx_588(void);
extern void ISCAN_vidEve_Tx_588(void);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATAS                                                                      */
/******************************************************************************/

#endif
