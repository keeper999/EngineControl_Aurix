/***************************************************************************
;**
;** FILE NAME      : VEHMUX_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHMUX_L_H
#define VEHMUX_L_H

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

extern const uint8  VEHMUX_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 Km_vehicle_mux_prev;
extern uint8 Esp_frame_nb_per_sec_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VEHMUX_vidAcquisFrame552(void);
void VEHMUX_vidAcquisFrame7F2(void);
void VEHMUX_vidAcquisition38D(void);
void VEHMUX_vidAcquisSpeedAccelMux(void);
void VEHMUX_vidCalcDist552(void);
void VEHMUX_vidCalcDist7F2(void);
void VEHMUX_vidTravaledDistanceCalc(void);
void VEHMUX_vidVehSpdMuxInit(void);


#endif /* VEHMUX_L_H */

/*-------------------------------- end of file -------------------------------*/
