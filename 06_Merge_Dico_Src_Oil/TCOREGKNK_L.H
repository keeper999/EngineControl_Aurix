/***************************************************************************
;**
;** FILE NAME      : TCOREGKNK_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TCOREGKNK_L_H
#define TCOREGKNK_L_H

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

extern const uint8  TCOREGKNK_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgSys_bAcvEngColdReq;
extern boolean IgSys_bAuthIgSysTCoColdReq;
extern boolean TCOREGKNK_bAcvCond;
extern boolean TCOREGKNK_bTmrOut;
extern sint8 IgSys_agIgDeltaEngColdReq_MP;
extern uint8 IgSys_facFilDeltaAgIg_MP;
extern uint16 TCOREGKNK_u16Cnt;
extern sint32 TCOREGKNK_s32FiltPosErrorMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TCOREGKNK_vidActiv_Condition(void);
void TCOREGKNK_vidCool_Req_Coord(void);
void TCOREGKNK_vidFlag_Generation(void);
void TCOREGKNK_vidInitOutput(void);


#endif /* TCOREGKNK_L_H */

/*-------------------------------- end of file -------------------------------*/
