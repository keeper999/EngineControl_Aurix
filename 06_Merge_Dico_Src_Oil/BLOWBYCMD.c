/***************************************************************************
;**
;** FILE NAME      : BLOWBYCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BLOWBYCMD.H"
#include "BLOWBYCMD_L.H"
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
const sint8  BlowByHw_tAirExtHi_C = 0;
const sint8  BlowByHw_tAirExtLo_C = 0;
const sint8  BlowByHw_uBattMesMin_C = 0;
const uint8  BLOWBYCMD_u8Inhib = 0;
const uint16  BlowByHw_tiHeat_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 BlowByHw_stCtl;
boolean BlowBy1Hw_bReq;
boolean BlowBy2Hw_bReq;
boolean BlowByHw_bReq;
boolean OilSys_bDgoOc_BlowBy1;
boolean OilSys_bDgoOc_BlowBy2;
boolean OilSys_bDgoScg_BlowBy1;
boolean OilSys_bDgoScg_BlowBy2;
boolean OilSys_bDgoScp_BlowBy1;
boolean OilSys_bDgoScp_BlowBy2;
boolean OilSys_bMonRunOc_BlowBy1;
boolean OilSys_bMonRunOc_BlowBy2;
boolean OilSys_bMonRunScg_BlowBy1;
boolean OilSys_bMonRunScg_BlowBy2;
boolean OilSys_bMonRunScp_BlowBy1;
boolean OilSys_bMonRunScp_BlowBy2;
uint16 BlowByHw_tiHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

