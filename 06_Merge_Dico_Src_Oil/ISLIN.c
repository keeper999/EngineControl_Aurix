/***************************************************************************
;**
;** FILE NAME      : ISLIN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ISLIN.H"
#include "ISLIN_L.H"
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
const uint8  IsLin_SDConfFrameNb = 0;
const uint8  ISLIN_u8Inhib = 0;
const uint8  IsLin_WUConfFrameNb = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Class;
boolean AltCtl_bFctlDft;
boolean AltCtl_dftComAlt;
boolean AltCtl_dftElecAlt;
boolean AltCtl_dftHiTAlt;
boolean AltCtl_dftMecAlt;
boolean Clef_de_contact_prev;
boolean Defaut_Com_Alt;
boolean Defaut_Elec_Alt;
boolean Defaut_Ht_Alt;
boolean Defaut_Meca_Alt;
boolean ISLIN_Freeze;
boolean Tof;
uint8 AltCtl_iAlt;
uint8 AltCtl_idxAltProv;
uint8 AltCtl_rAltCycOpRate;
uint8 Fnr;
uint8 I_Lim;
uint8 I_Rot;
uint8 IsLin_idxAltClas;
uint8 IsLin_nbSDFrameSent;
uint8 IsLin_nbWUFrameSent;
uint8 Lrc_Off_On;
uint8 Rco;
uint8 T_Lrc;
uint8 V_Reg;
uint8 VoltCtl_tiAltPrgCh_Rescaled;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

