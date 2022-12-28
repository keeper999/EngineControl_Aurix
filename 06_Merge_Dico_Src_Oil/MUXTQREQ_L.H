/***************************************************************************
;**
;** FILE NAME      : MUXTQREQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MUXTQREQ_L_H
#define MUXTQREQ_L_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bCdnEngSpdLimHiEfc;
extern boolean Ext_bCdnEngSpdLimLoEfc;
extern boolean Ext_bCdnTqLimEfc;
extern boolean MUXTQREQ_bHysEngHi;
extern boolean MUXTQREQ_bHysEngLo;
extern boolean MUXTQREQ_bHysTqLimEfc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MUXTQREQ_vidEngSpdLimHiEfc(void);
void MUXTQREQ_vidEngSpdLimLoEfc(void);
void MUXTQREQ_vidEngStOpm(void);
void MUXTQREQ_vidInit(void);
void MUXTQREQ_vidInitOutput(void);
void MUXTQREQ_vidTqLimEfc(void);


#endif /* MUXTQREQ_L_H */

/*-------------------------------- end of file -------------------------------*/
