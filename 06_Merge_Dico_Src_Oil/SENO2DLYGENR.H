/***************************************************************************
;**
;** FILE NAME      : SENO2DLYGENR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2DLYGENR_H
#define SENO2DLYGENR_H

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

extern const boolean  Up_oxy_cfg_test_bed_enable_c0;
extern const uint32  Up_oxy_tb_lean_vs_rich_delay_c0;
extern const uint32  Up_oxy_tb_rich_vs_lean_delay_c0;
extern const uint16  Up_oxy_tb_high_rich_thresh_c0;
extern const uint16  Up_oxy_tb_lean_voltage_value_c0;
extern const uint16  Up_oxy_tb_low_rich_thresh_c0;
extern const uint16  Up_oxy_tb_rich_voltage_value_c0;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Up_oxy_test_bed_voltage_v;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SENO2DLYGENR_vidEntryInit(void);
void SenO2Us_SdlFast_SenO2DlyGenr(void);


#endif /* SENO2DLYGENR_H */

/*-------------------------------- end of file -------------------------------*/
