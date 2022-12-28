/***************************************************************************
;**
;** FILE NAME      : ADCHAL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADCHAL_H
#define ADCHAL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADCHAL_Cfg.h"
#include "ADCHAL_Typ_Cfg.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ADCHAL_BICD_FBACK_INFO            24
#define ADCHAL_EGR_PRS                    30
#define ADCHAL_EGR_THR_POS                26
#define ADCHAL_FAN1_DIAG                  32
#define ADCHAL_IGN_BATT_VOLTAGE           27
#define ADCHAL_INT_ATMO_PRS_P0            20
#define ADCHAL_INTK_AIR_TMP_T2            35
#define ADCHAL_MAIN_SUP                   29
#define ADCHAL_PED_POS_SNS_2_REDUNDANT    23
#define ADCHAL_SPARE_2                    34
#define ADCHAL_TURBO_INTK_AIR_TMP_T1      25
#define ADCHAL_VDD3A_CJ135                33
#define ADCHAL_WASTEGATE_POS_COPY         36
#define CH_ADC_AC_PRS_V                   17
#define CH_ADC_BAT_RLY_V                  10
#define CH_ADC_BICD                       21
#define CH_ADC_HT_DW_O2_CUR               5
#define CH_ADC_HT_DW_O2_VOLT              4
#define CH_ADC_HT_UP_O2_CUR               7
#define CH_ADC_HT_UP_O2_VOLT              6
#define CH_ADC_LBDW_V                     9
#define CH_ADC_LBUP_V                     8
#define CH_ADC_MAP_V                      19
#define CH_ADC_MSTRVAC_PRS                1
#define CH_ADC_OILPROPPRESACQ             28
#define CH_ADC_PDL_PT_DUR                 0
#define CH_ADC_PDL_V_1                    14
#define CH_ADC_PDL_V_2                    15
#define CH_ADC_PRESS_RAMPE                31
#define CH_ADC_PRESS_TURBO                18
#define CH_ADC_PWRS_V_1                   11
#define CH_ADC_PWRS_V_2                   13
#define CH_ADC_PWRS_V_3                   12
#define CH_ADC_TCO_V                      16
#define CH_ADC_THR_V_1                    2
#define CH_ADC_THR_V_2                    3
#define CH_ADC_TIA_V                      22

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

extern const uint16  ADCHAL_ku16HeatingMosOffsDWN;
extern const uint16  ADCHAL_ku16HeatingMosOffsUPS;
extern const uint16  ADCHAL_ku16ShuntResistorDWN;
extern const uint16  ADCHAL_ku16ShuntResistorUPS;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern sint8 ADCHAL_s8BatTrimGain;
extern sint8 ADCHAL_s8BatTrimOffset;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADCHAL_vidInit(void);


#endif /* ADCHAL_H */

/*-------------------------------- end of file -------------------------------*/
