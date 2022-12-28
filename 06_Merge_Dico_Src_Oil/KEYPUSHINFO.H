/***************************************************************************
;**
;** FILE NAME      : KEYPUSHINFO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KEYPUSHINFO_H
#define KEYPUSHINFO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Ext_bInvDemLine_C;
extern const uint8  Ext_ctSdlStp_C;
extern const uint8  Ext_numDebHighKeyLine_C;
extern const uint8  Ext_numDebHighPushLine_C;
extern const uint8  Ext_numDebLowKeyLine_C;
extern const uint8  Ext_numDebLowPushLine_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDemLineRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STT_EveRst_KeyPushInfo(void);
void STT_SdlFast_KeyPushInfo(void);


#endif /* KEYPUSHINFO_H */

/*-------------------------------- end of file -------------------------------*/
