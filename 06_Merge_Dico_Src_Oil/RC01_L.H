/***************************************************************************
;**
;** FILE NAME      : RC01_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RC01_L_H
#define RC01_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
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

extern const boolean  Rdy_bDftValCat_C;
extern const boolean  Rdy_bDftValClim_C;
extern const boolean  Rdy_bDftValCpt_C;
extern const boolean  Rdy_bDftValEVAP_C;
extern const boolean  Rdy_bDftValHeatCat_C;
extern const boolean  Rdy_bDftValHeatO2_C;
extern const boolean  Rdy_bDftValIAE_C;
extern const boolean  Rdy_bDftValLfbk_C;
extern const boolean  Rdy_bDftValMisf_C;
extern const boolean  Rdy_bDftValO2S_C;
extern const boolean  Rdy_bDftValVVT_C;
extern const uint8  RC01_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Rdy_u8ClasRdyLSB;
extern uint8 Rdy_u8ClasRdyMSB;
extern uint16 Rdy_u16ClasRdy_EEPROM_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RC01_vidF00_Def_Prio_Init(void);
void RC01_vidF01_Rdy_Init(void);
void RC01_vidF02_Rdy_ValRdy(void);
void RC01_vidF03_Rdy_ReinitRdy(void);
void RC01_vidF04_Rdy_ValClasRdy(void);
void RC01_vidF06_Rdy_ValClasRdyCfOBD(uint16 u16IdxDft);


#endif /* RC01_L_H */

/*-------------------------------- end of file -------------------------------*/
