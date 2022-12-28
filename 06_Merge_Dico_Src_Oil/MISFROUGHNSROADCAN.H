/***************************************************************************
;**
;** FILE NAME      : MISFROUGHNSROADCAN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFROUGHNSROADCAN_H
#define MISFROUGHNSROADCAN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MISF_AROUGHNROADDETTHD_M_LNS          ( 7 )
#define MISF_AROUGHNROADDETTHD_M_COLS          ( 16 )
#define TRA_NOGEARMAN_BKPT_MAP_COLS            ( 7 )
#define VITESSE_VEHICULE_BKPT_MAP_COLS         ( 16 )

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

extern const uint8  Tra_noGearMan_bkpt_map[TRA_NOGEARMAN_BKPT_MAP_COLS];
extern const uint8  Vitesse_vehicule_bkpt_map[VITESSE_VEHICULE_BKPT_MAP_COLS];
extern const uint16  Misf_aRoughnRoadDetThd_M[MISF_AROUGHNROADDETTHD_M_LNS][MISF_AROUGHNROADDETTHD_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Misf_bAcvRoughnsRoadMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_SdlFast_MisfRoughnsRoadCan(void);
void MISFROUGHNSROADCAN_vidEntryInit(void);


#endif /* MISFROUGHNSROADCAN_H */

/*-------------------------------- end of file -------------------------------*/
