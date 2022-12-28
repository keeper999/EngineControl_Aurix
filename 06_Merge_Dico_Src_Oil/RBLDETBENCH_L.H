/***************************************************************************
;**
;** FILE NAME      : RBLDETBENCH_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RBLDETBENCH_L_H
#define RBLDETBENCH_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_MOY_RBL_CYL_PREV_COLS            ( 4 )
#define RBL_GAIN_FOR_TEST_BED_UAVN1_COLS       ( 4 )
#define RBLDETBENCH_u16ARRAY_LENGTH       4
#define RBLDETBENCH_u32ARRAY_LENGTH       4
#define RBLDETBENCH_u8ARRAY_LENGTH        16

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

extern const uint8  RBLDETBENCH_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Detection_rbl_test_bed_uavn0;
extern uint8 Rbl_gain_for_test_bed_uavn1[RBL_GAIN_FOR_TEST_BED_UAVN1_COLS];
extern uint16 Bruit_inst_rbl_test_bed_uavn0;
extern uint16 Bruit_moy_rbl_cyl_prev[BRUIT_MOY_RBL_CYL_PREV_COLS];
extern uint16 Bruit_moy_rbl_for_test_bed_uavn0;
extern uint16 Rbl_test_bed_delay_0_uavn0;
extern uint16 Rbl_test_bed_delay_1_uavn0;
extern uint16 Rbl_test_bed_delay_2_uavn0;
extern uint16 Rbl_test_bed_delay_3_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RBLDETBENCH_vidcalc_variables(void);
void RBLDETBENCH_vidInitOutput(void);
void RBLDETBENCH_vidRbl_Test_bed(void);
void RBLDETBENCH_vidretard(void);


#endif /* RBLDETBENCH_L_H */

/*-------------------------------- end of file -------------------------------*/
