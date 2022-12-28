/***************************************************************************
;**
;** FILE NAME      : TELECODAGE_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TELECODAGE_L_H
#define TELECODAGE_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TELECODAGE_u8BufferSize           2

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

extern const uint8  TELECODAGE_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Srv_bDaVld;
extern boolean Srv_bDgoInv_VarCod;
extern boolean Srv_bMonRunInv_VarCod;
extern boolean Tele_program_add_heat_vld;
extern boolean Tele_program_alternator_vld;
extern boolean Tele_program_car_vld;
extern boolean Tele_program_fric_vld;
extern boolean Tele_program_gear_box_vld;
extern boolean Tele_program_press_clim_vld;
extern uint32 TELECODAGE_u32Info_UC;
extern uint8 Tele_program_add_heat_int;
extern uint8 Tele_program_car_int;
extern uint8 Tele_program_fric_int;
extern uint8 Tele_program_gear_box_int;
extern uint8 Tele_program_press_clim_int;
extern uint8 TELECODAGE_u8SrvStTeleEcuStaPrev;
extern uint16 Srv_tiWaitDelayTele;
extern uint16 Tele_program_alternator_int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TELECODAGE_NVMSRV_vidInit(void);
void TELECODAGE_vidAddHeatConfVerif(void);
void TELECODAGE_vidAlternConfVerif(void);
void TELECODAGE_vidCarConfVerif(void);
void TELECODAGE_vidDataVerification(void);
void TELECODAGE_vidFricConfVerif(void);
void TELECODAGE_vidGearBoxConfVerif(void);
void TELECODAGE_vidInfoWrite(void);
void TELECODAGE_vidInitDftBeforeTel(void);
void TELECODAGE_vidInitOutput(void);
void TELECODAGE_vidPressClimConfVerif(void);
void TELECODAGE_vidReInit(void);
void TELECODAGE_vidVarCodDftMng(void);
void TELECODAGE_vidVarCodMng(void);
void TELECODAGE_vidWrite(void);


#endif /* TELECODAGE_L_H */

/*-------------------------------- end of file -------------------------------*/
