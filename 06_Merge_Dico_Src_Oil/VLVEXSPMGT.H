/***************************************************************************
;**
;** FILE NAME      : VLVEXSPMGT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVEXSPMGT_H
#define VLVEXSPMGT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVSYS_AGCKCLSEXCAL1_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL1_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL10_M_LNS           ( 16 )
#define VLVSYS_AGCKCLSEXCAL10_M_COLS           ( 16 )
#define VLVSYS_AGCKCLSEXCAL11_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL11_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL12_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL12_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL13_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL13_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL14_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL14_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL15_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL15_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL16_M_LNS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL16_M_COLS           ( 8 )
#define VLVSYS_AGCKCLSEXCAL2_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL2_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL3_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL3_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL4_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL4_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL5_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL5_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL6_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL6_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL7_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL7_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL8_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL8_M_COLS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL9_M_LNS            ( 16 )
#define VLVSYS_AGCKCLSEXCAL9_M_COLS            ( 16 )

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

extern const sint8  VlvSys_agCkClsExCal17_C;
extern const sint8  VlvSys_agCkClsExCal18_C;
extern const uint8  VlvSys_agCkClsExCal1_M[VLVSYS_AGCKCLSEXCAL1_M_LNS][VLVSYS_AGCKCLSEXCAL1_M_COLS];
extern const uint8  VlvSys_agCkClsExCal10_M[VLVSYS_AGCKCLSEXCAL10_M_LNS][VLVSYS_AGCKCLSEXCAL10_M_COLS];
extern const uint8  VlvSys_agCkClsExCal11_M[VLVSYS_AGCKCLSEXCAL11_M_LNS][VLVSYS_AGCKCLSEXCAL11_M_COLS];
extern const uint8  VlvSys_agCkClsExCal12_M[VLVSYS_AGCKCLSEXCAL12_M_LNS][VLVSYS_AGCKCLSEXCAL12_M_COLS];
extern const uint8  VlvSys_agCkClsExCal13_M[VLVSYS_AGCKCLSEXCAL13_M_LNS][VLVSYS_AGCKCLSEXCAL13_M_COLS];
extern const uint8  VlvSys_agCkClsExCal14_M[VLVSYS_AGCKCLSEXCAL14_M_LNS][VLVSYS_AGCKCLSEXCAL14_M_COLS];
extern const uint8  VlvSys_agCkClsExCal15_M[VLVSYS_AGCKCLSEXCAL15_M_LNS][VLVSYS_AGCKCLSEXCAL15_M_COLS];
extern const uint8  VlvSys_agCkClsExCal16_M[VLVSYS_AGCKCLSEXCAL16_M_LNS][VLVSYS_AGCKCLSEXCAL16_M_COLS];
extern const uint8  VlvSys_agCkClsExCal2_M[VLVSYS_AGCKCLSEXCAL2_M_LNS][VLVSYS_AGCKCLSEXCAL2_M_COLS];
extern const uint8  VlvSys_agCkClsExCal3_M[VLVSYS_AGCKCLSEXCAL3_M_LNS][VLVSYS_AGCKCLSEXCAL3_M_COLS];
extern const uint8  VlvSys_agCkClsExCal4_M[VLVSYS_AGCKCLSEXCAL4_M_LNS][VLVSYS_AGCKCLSEXCAL4_M_COLS];
extern const uint8  VlvSys_agCkClsExCal5_M[VLVSYS_AGCKCLSEXCAL5_M_LNS][VLVSYS_AGCKCLSEXCAL5_M_COLS];
extern const uint8  VlvSys_agCkClsExCal6_M[VLVSYS_AGCKCLSEXCAL6_M_LNS][VLVSYS_AGCKCLSEXCAL6_M_COLS];
extern const uint8  VlvSys_agCkClsExCal7_M[VLVSYS_AGCKCLSEXCAL7_M_LNS][VLVSYS_AGCKCLSEXCAL7_M_COLS];
extern const uint8  VlvSys_agCkClsExCal8_M[VLVSYS_AGCKCLSEXCAL8_M_LNS][VLVSYS_AGCKCLSEXCAL8_M_COLS];
extern const uint8  VlvSys_agCkClsExCal9_M[VLVSYS_AGCKCLSEXCAL9_M_LNS][VLVSYS_AGCKCLSEXCAL9_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint8 VlvSys_agCkClsExVlvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvSys_EveIni_VlvEx(void);
void VlvSys_SdlFast_VlvEx(void);


#endif /* VLVEXSPMGT_H */

/*-------------------------------- end of file -------------------------------*/
