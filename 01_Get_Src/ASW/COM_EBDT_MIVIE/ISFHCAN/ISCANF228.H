/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISCANF228.H */
#ifndef ISCANF228_H
#define ISCANF228_H

#include "STD_TYPES.H"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

extern void ISCAN_vidInit_Tx_228(void);
extern void ISCAN_vidEve_Tx_228(void);
extern boolean ISCAN_EveTxF228_Callout (PduIdType PduId, PduInfoType* PduInfoPtr);

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/******************************************************************************/
/* DATAS                                                                      */
/******************************************************************************/
#define ISFHCAN_START_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

extern boolean Ext_bDgoCMMAbsent;
extern boolean Ext_bMonRunCMMAbsent;

#define ISFHCAN_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "ISFHCAN_MemMap.h"

#endif
