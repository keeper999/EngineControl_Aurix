/***************************************************************************
;**
;** FILE NAME      : ACCPLRNPOS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPLRNPOS_L_H
#define ACCPLRNPOS_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ACCP_SDLMID_FLRNG                 10

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

extern const uint8  ACCPLRNPOS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ACCPLRNPOS_bAutoris_1_app_pl_pc;
extern boolean ACCPLRNPOS_bAutoris_2_app_pl_pc;
extern boolean Dv_app_pc_eng_spd_enable;
extern boolean Dv_app_pl_eng_spd_enable;
extern boolean Dv_init_1_app_pc_tempo1;
extern boolean Dv_init_1_app_pc_tempo1_prev;
extern boolean Dv_init_1_app_pc_tempo2;
extern boolean Dv_init_1_app_pc_tempo2_prev;
extern boolean Dv_init_1_app_pl_tempo1;
extern boolean Dv_init_1_app_pl_tempo1_prev;
extern boolean Dv_init_1_app_pl_tempo2;
extern boolean Dv_init_1_app_pl_tempo2_prev;
extern boolean Dv_init_2_app_pc_tempo1;
extern boolean Dv_init_2_app_pc_tempo1_prev;
extern boolean Dv_init_2_app_pc_tempo2;
extern boolean Dv_init_2_app_pc_tempo2_prev;
extern boolean Dv_init_2_app_pl_tempo1;
extern boolean Dv_init_2_app_pl_tempo1_prev;
extern boolean Dv_init_2_app_pl_tempo2;
extern boolean Dv_init_2_app_pl_tempo2_prev;
extern uint8 Dv_1_app_pc_tempo1;
extern uint8 Dv_1_app_pc_tempo2;
extern uint8 Dv_1_app_pl_tempo1;
extern uint8 Dv_1_app_pl_tempo2;
extern uint8 Dv_2_app_pc_tempo1;
extern uint8 Dv_2_app_pc_tempo2;
extern uint8 Dv_2_app_pl_tempo1;
extern uint8 Dv_2_app_pl_tempo2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPLRNPOS_NVMSRV_vidInit(void);
void ACCPLRNPOS_vidCalculation(void);
void ACCPLRNPOS_vidDvLrnFootFullDown1(void);
void ACCPLRNPOS_vidDvLrnFootFullDown2(void);
void ACCPLRNPOS_vidDvLrnFootUp1(void);
void ACCPLRNPOS_vidDvLrnFootUp1D(void);
void ACCPLRNPOS_vidDvLrnFootUp1M(void);
void ACCPLRNPOS_vidDvLrnFootUp2(void);
void ACCPLRNPOS_vidDvLrnFootUp2D(void);
void ACCPLRNPOS_vidDvLrnFootUp2M(void);
void ACCPLRNPOS_vidDvLrnFtFlDown1D(void);
void ACCPLRNPOS_vidDvLrnFtFlDown1M(void);
void ACCPLRNPOS_vidDvLrnFtFlDown2D(void);
void ACCPLRNPOS_vidDvLrnFtFlDown2M(void);
void ACCPLRNPOS_vidFreeLearningMgt(void);
void ACCPLRNPOS_vidInitDiagsrv(void);
void ACCPLRNPOS_vidInitOutput(void);
void ACCPLRNPOS_vidLrnMgtDetectorHigh(void);
void ACCPLRNPOS_vidLrnMgtDetectorLow(void);


#endif /* ACCPLRNPOS_L_H */

/*-------------------------------- end of file -------------------------------*/
