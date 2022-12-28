/***************************************************************************
;**
;** FILE NAME      : CANTXMIXMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CANTXMIXMOD_L_H
#define CANTXMIXMOD_L_H

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

extern const uint8  CANTXMIXMOD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CANTXMIXMOD_bCoPtUHbRStrtAntPrev;
extern boolean CANTXMIXMOD_bThMgtbPosnFSFPrev;
extern boolean ISCAN_bFastTxn1E8Req;
extern boolean ISCAN_bFastTxn468Req;
extern boolean ISCAN_bTxnSlow1E8Req;
extern uint8 CANTXMIXMOD_u8CoEmSTTstTypEmPrev;
extern uint8 CANTXMIXMOD_u8CoOptmElstElEPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CANTXMIXMOD_vidFastCheck(void);
void CANTXMIXMOD_vidInitOutput(void);
void CANTXMIXMOD_vidSlowCheck(void);


#endif /* CANTXMIXMOD_L_H */

/*-------------------------------- end of file -------------------------------*/
