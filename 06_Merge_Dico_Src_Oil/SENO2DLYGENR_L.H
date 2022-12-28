/***************************************************************************
;**
;** FILE NAME      : SENO2DLYGENR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2DLYGENR_L_H
#define SENO2DLYGENR_L_H

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

extern const uint8  SENO2DLYGENR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Up_oxy_tb_rich_state_v;
extern uint32 Up_oxy_tb_lean_vs_rich_count_v;
extern uint32 Up_oxy_tb_rich_vs_lean_count_v;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SENO2DLYGENR_vidInitOutput(void);
void SENO2DLYGENR_vidLeanRichInit(void);
void SENO2DLYGENR_vidLeanRichInitDly(void);
void SENO2DLYGENR_vidLeanStatus(void);
void SENO2DLYGENR_vidRichLeanInit(void);
void SENO2DLYGENR_vidRichLeanInitDly(void);
void SENO2DLYGENR_vidRichStatus(void);
void SENO2DLYGENR_vidStatusLean(void);
void SENO2DLYGENR_vidStatusRich(void);
void SENO2DLYGENR_vidUpOxyTestBed(void);
void SENO2DLYGENR_vidUpOxyTestBedMode(void);


#endif /* SENO2DLYGENR_L_H */

/*-------------------------------- end of file -------------------------------*/
