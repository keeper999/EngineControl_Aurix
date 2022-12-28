/***************************************************************************
;**
;** FILE NAME      : VLVINSPMGT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVINSPMGT_H
#define VLVINSPMGT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVSYS_AGCKOPINCAL1_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL1_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL10_M_LNS            ( 16 )
#define VLVSYS_AGCKOPINCAL10_M_COLS            ( 16 )
#define VLVSYS_AGCKOPINCAL11_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL11_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL12_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL12_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL13_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL13_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL14_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL14_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL15_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL15_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL16_M_LNS            ( 8 )
#define VLVSYS_AGCKOPINCAL16_M_COLS            ( 8 )
#define VLVSYS_AGCKOPINCAL2_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL2_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL3_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL3_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL4_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL4_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL5_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL5_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL6_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL6_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL7_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL7_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL8_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL8_M_COLS             ( 16 )
#define VLVSYS_AGCKOPINCAL9_M_LNS             ( 16 )
#define VLVSYS_AGCKOPINCAL9_M_COLS             ( 16 )

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

extern const sint8  VlvSys_agCkOpInCal17_C;
extern const sint8  VlvSys_agCkOpInCal18_C;
extern const uint8  VlvSys_agCkOpInCal1_M[VLVSYS_AGCKOPINCAL1_M_LNS][VLVSYS_AGCKOPINCAL1_M_COLS];
extern const uint8  VlvSys_agCkOpInCal10_M[VLVSYS_AGCKOPINCAL10_M_LNS][VLVSYS_AGCKOPINCAL10_M_COLS];
extern const uint8  VlvSys_agCkOpInCal11_M[VLVSYS_AGCKOPINCAL11_M_LNS][VLVSYS_AGCKOPINCAL11_M_COLS];
extern const uint8  VlvSys_agCkOpInCal12_M[VLVSYS_AGCKOPINCAL12_M_LNS][VLVSYS_AGCKOPINCAL12_M_COLS];
extern const uint8  VlvSys_agCkOpInCal13_M[VLVSYS_AGCKOPINCAL13_M_LNS][VLVSYS_AGCKOPINCAL13_M_COLS];
extern const uint8  VlvSys_agCkOpInCal14_M[VLVSYS_AGCKOPINCAL14_M_LNS][VLVSYS_AGCKOPINCAL14_M_COLS];
extern const uint8  VlvSys_agCkOpInCal15_M[VLVSYS_AGCKOPINCAL15_M_LNS][VLVSYS_AGCKOPINCAL15_M_COLS];
extern const uint8  VlvSys_agCkOpInCal16_M[VLVSYS_AGCKOPINCAL16_M_LNS][VLVSYS_AGCKOPINCAL16_M_COLS];
extern const uint8  VlvSys_agCkOpInCal2_M[VLVSYS_AGCKOPINCAL2_M_LNS][VLVSYS_AGCKOPINCAL2_M_COLS];
extern const uint8  VlvSys_agCkOpInCal3_M[VLVSYS_AGCKOPINCAL3_M_LNS][VLVSYS_AGCKOPINCAL3_M_COLS];
extern const uint8  VlvSys_agCkOpInCal4_M[VLVSYS_AGCKOPINCAL4_M_LNS][VLVSYS_AGCKOPINCAL4_M_COLS];
extern const uint8  VlvSys_agCkOpInCal5_M[VLVSYS_AGCKOPINCAL5_M_LNS][VLVSYS_AGCKOPINCAL5_M_COLS];
extern const uint8  VlvSys_agCkOpInCal6_M[VLVSYS_AGCKOPINCAL6_M_LNS][VLVSYS_AGCKOPINCAL6_M_COLS];
extern const uint8  VlvSys_agCkOpInCal7_M[VLVSYS_AGCKOPINCAL7_M_LNS][VLVSYS_AGCKOPINCAL7_M_COLS];
extern const uint8  VlvSys_agCkOpInCal8_M[VLVSYS_AGCKOPINCAL8_M_LNS][VLVSYS_AGCKOPINCAL8_M_COLS];
extern const uint8  VlvSys_agCkOpInCal9_M[VLVSYS_AGCKOPINCAL9_M_LNS][VLVSYS_AGCKOPINCAL9_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint8 VlvSys_agCkOpInVlvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvSys_EveIni_VlvIn(void);
void VlvSys_SdlFast_VlvIn(void);


#endif /* VLVINSPMGT_H */

/*-------------------------------- end of file -------------------------------*/
