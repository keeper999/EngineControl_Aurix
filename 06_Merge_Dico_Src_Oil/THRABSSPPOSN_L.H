/***************************************************************************
;**
;** FILE NAME      : THRABSSPPOSN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRABSSPPOSN_L_H
#define THRABSSPPOSN_L_H

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

extern const uint8  THRABSSPPOSN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Tpac_ecu_temp_protect_mode;
extern uint16 Ssm_closed_throttle_pos_tmp;
extern uint16 Ssm_open_throttle_pos_tmp;
extern uint16 Tpac_throttle_open_thresh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRABSSPPOSN_vidCompOpenThresh(void);
void THRABSSPPOSN_vidComputeAbsRef(void);
void THRABSSPPOSN_vidInitOutput(void);
void THRABSSPPOSN_vidInitThrotPosRef(void);
void THRABSSPPOSN_vidModifThrustPos(void);


#endif /* THRABSSPPOSN_L_H */

/*-------------------------------- end of file -------------------------------*/
