/***************************************************************************
;**
;** FILE NAME      : SENO2DLYGENR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SENO2DLYGENR.H"
#include "SENO2DLYGENR_L.H"
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
const boolean  Up_oxy_cfg_test_bed_enable_c0 = 0;
const uint32  Up_oxy_tb_lean_vs_rich_delay_c0 = 0;
const uint32  Up_oxy_tb_rich_vs_lean_delay_c0 = 0;
const uint8  SENO2DLYGENR_u8Inhib = 0;
const uint16  Up_oxy_tb_high_rich_thresh_c0 = 0;
const uint16  Up_oxy_tb_lean_voltage_value_c0 = 0;
const uint16  Up_oxy_tb_low_rich_thresh_c0 = 0;
const uint16  Up_oxy_tb_rich_voltage_value_c0 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Up_oxy_tb_rich_state_v;
uint32 Up_oxy_tb_lean_vs_rich_count_v;
uint32 Up_oxy_tb_rich_vs_lean_count_v;
uint16 Up_oxy_test_bed_voltage_v;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

