/***************************************************************************
;**
;** FILE NAME      : ACTRTSTMEAP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTMEAP_H
#define ACTRTSTMEAP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MEAP_SampleTiMid_SC               1000

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

extern const uint8  ActrTstMeap_Tempo_C;
extern const uint8  ActrTstMeap_tiDlyClos_C;
extern const uint8  ActrTstMeap_tiDlyOpen_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Meap_bActrTstCmpl;
extern boolean Meap_bActrTstInProgs;
extern boolean Meap_bFlapBlockOp;
extern boolean Meap_bFlapFaild;
extern boolean Meap_bFlapStayOp;
extern uint8 ThMgt_stPosnFSF;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MEAP_EveRst_ActrTstMEAP(void);
void MEAP_SdlMid_ActrTstMEAP(void);


#endif /* ACTRTSTMEAP_H */

/*-------------------------------- end of file -------------------------------*/
