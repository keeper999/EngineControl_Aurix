/***************************************************************************
;**
;** FILE NAME      : KNKBENCHMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKBENCHMOD_L_H
#define KNKBENCHMOD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_MOYEN_CYL_PREV_COLS              ( 4 )
#define KNK_GAIN_FOR_TEST_BED_UAVN1_COLS       ( 4 )
#define KNKBENCHMOD_u32ARRAY_LENGTH       4

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

extern const uint8  KNKBENCHMOD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Detection_cliq_test_bed_uavn0;
extern uint8 Knk_gain_for_test_bed_uavn1[KNK_GAIN_FOR_TEST_BED_UAVN1_COLS];
extern uint16 Bruit_instantane_test_bed_uavn0;
extern uint16 Bruit_moyen_cyl_prev[BRUIT_MOYEN_CYL_PREV_COLS];
extern uint16 Bruit_moyen_for_test_bed_uavn0;
extern uint16 Knk_test_bed_delay_0_uavn0;
extern uint16 Knk_test_bed_delay_1_uavn0;
extern uint16 Knk_test_bed_delay_2_uavn0;
extern uint16 Knk_test_bed_delay_3_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKBENCHMOD_vidCalcDelay(void);
void KNKBENCHMOD_vidCalcVariables(void);
void KNKBENCHMOD_vidInitialization(void);
void KNKBENCHMOD_vidTestBed(void);


#endif /* KNKBENCHMOD_L_H */

/*-------------------------------- end of file -------------------------------*/
