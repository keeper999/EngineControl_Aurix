/***************************************************************************
;**
;** FILE NAME      : ACTRTSTMEAP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACTRTSTMEAP.H"
#include "ACTRTSTMEAP_L.H"
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
const uint8  ActrTstMeap_Tempo_C = 0;
const uint8  ActrTstMeap_tiDlyClos_C = 0;
const uint8  ActrTstMeap_tiDlyOpen_C = 0;
const uint8  ACTRTSTMEAP_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Meap_stActrTst;
boolean Meap_bActrTstCmpl;
boolean Meap_bActrTstInProgs;
boolean Meap_bFlapBlockOp;
boolean Meap_bFlapFaild;
boolean Meap_bFlapStayOp;
uint8 ActrTstMeap_ClosTime;
uint8 ActrTstMeap_OpenTime;
uint8 ActrTstMeap_Tempo;
uint8 ThMgt_stPosnFSF;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

