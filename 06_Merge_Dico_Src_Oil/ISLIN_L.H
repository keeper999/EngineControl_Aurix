/***************************************************************************
;**
;** FILE NAME      : ISLIN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ISLIN_L_H
#define ISLIN_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AUTRE                             7
#define BOSCH                             0
#define DELPHI                            2
#define DENSO                             4
#define HITACHI                           3
#define ISLIN_u8RX_BUFFER_LENGTH          2
#define ISLIN_u8TX_BUFFER_LENGTH          4
#define MELCO                             5
#define VALEO                             1
#define VISTEON                           6

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

extern const uint8  IsLin_SDConfFrameNb;
extern const uint8  ISLIN_u8Inhib;
extern const uint8  IsLin_WUConfFrameNb;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Clef_de_contact_prev;
extern boolean Defaut_Com_Alt;
extern boolean Defaut_Elec_Alt;
extern boolean Defaut_Ht_Alt;
extern boolean Defaut_Meca_Alt;
extern boolean ISLIN_Freeze;
extern boolean Tof;
extern uint8 Fnr;
extern uint8 I_Lim;
extern uint8 I_Rot;
extern uint8 IsLin_nbSDFrameSent;
extern uint8 IsLin_nbWUFrameSent;
extern uint8 Lrc_Off_On;
extern uint8 Rco;
extern uint8 T_Lrc;
extern uint8 V_Reg;
extern uint8 VoltCtl_tiAltPrgCh_Rescaled;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ISLIN_vidDiagEna(void);
void ISLIN_vidEtatAlt1(void);
void ISLIN_vidEtatAlt2(void);
void ISLIN_vidFreeze(void);
void ISLIN_vidInitCons(void);
void ISLIN_vidInitProd(void);
void ISLIN_vidLinStatus(void);
void ISLIN_vidShutDown(void);
void ISLIN_vidWakeUp(void);
void vidCmdeAltScale(void);
void vidLinStatusInit(void);
void vidLinStatusNormal(void);
void vidLinStatusShut(void);
void vidLinStatusWakeUp(void);
void vidSendTrame(void);


#endif /* ISLIN_L_H */

/*-------------------------------- end of file -------------------------------*/
