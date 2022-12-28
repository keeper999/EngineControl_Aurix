/***************************************************************************
;**
;** FILE NAME      : RBLDETBENCH.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "RBLDETBENCH.H"
#include "RBLDETBENCH_L.H"
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
const boolean  Rbl_test_bed_uacb0 = 0;
const uint8  Rbl_test_bed_mode_uacn0 = 0;
const uint8  RBLDETBENCH_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Detection_rbl_test_bed_uavn0;
uint8 Rbl_gain_for_test_bed_uavn1[RBL_GAIN_FOR_TEST_BED_UAVN1_COLS];
uint16 Bruit_inst_rbl_test_bed_uavn0;
uint16 Bruit_moy_rbl_cyl_prev[BRUIT_MOY_RBL_CYL_PREV_COLS];
uint16 Bruit_moy_rbl_for_test_bed_uavn0;
uint16 Rbl_test_bed_delay_0_uavn0;
uint16 Rbl_test_bed_delay_1_uavn0;
uint16 Rbl_test_bed_delay_2_uavn0;
uint16 Rbl_test_bed_delay_3_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

