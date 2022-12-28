/***************************************************************************
;**
;** FILE NAME      : DGOHAL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DGOHAL_H
#define DGOHAL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DGOHAL_CFG.h"
#include "DGOHAL_Def.h"
#include "DGOHAL_Types.h"
#include "Std_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DGO_COIL_CYLINDER_1               24
#define DGO_COIL_CYLINDER_2               22
#define DGO_COIL_CYLINDER_3               23
#define DGO_COIL_CYLINDER_4               20
#define DGOHAL_bfFAULT_CAM_PATTERN        2
#define DGOHAL_bfFAULT_CJ135_HWSC         128
#define DGOHAL_bfFAULT_CJ135_I_LIMIT      8
#define DGOHAL_bfFAULT_CJ135_OPEN_LOAD    32
#define DGOHAL_bfFAULT_CJ135_OVER_CURRENT  2
#define DGOHAL_bfFAULT_CJ135_OVER_TEMPERATURE  8
#define DGOHAL_bfFAULT_CJ135_OVERLOAD     128
#define DGOHAL_bfFAULT_CJ135_SPI_ERROR    32
#define DGOHAL_bfFAULT_CJ135_SUPPLY_VOLTAGE  2
#define DGOHAL_bfFAULT_CRK_LTOO           2
#define DGOHAL_bfFAULT_CRK_LTOO1          8
#define DGOHAL_bfFAULT_CRK_TOO_EXCESS     32
#define DGOHAL_bfFAULT_CRK_TOO_MISS       128
#define DGOHAL_bfFAULT_EXCAM_PATTERN      2
#define DGOHAL_bfFAULT_GROUND             8
#define DGOHAL_bfFAULT_INCAM_PATTERN      2
#define DGOHAL_bfFAULT_L9960_HWSC         128
#define DGOHAL_bfFAULT_L9960_I_LIMIT      8
#define DGOHAL_bfFAULT_L9960_OPEN_LOAD    32
#define DGOHAL_bfFAULT_L9960_OVER_CURRENT  2
#define DGOHAL_bfFAULT_L9960_OVER_TEMPERATURE  8
#define DGOHAL_bfFAULT_L9960_OVERLOAD     128
#define DGOHAL_bfFAULT_L9960_SPI_ERROR    32
#define DGOHAL_bfFAULT_L9960_SUPPLY_VOLTAGE  2
#define DGOHAL_bfFAULT_MCP_FLASH_CKS      8
#define DGOHAL_bfFAULT_MCP_RAM_TEST       2
#define DGOHAL_bfFAULT_MCW_COMPUTED_CKS   32
#define DGOHAL_bfFAULT_MCW_FUNCTIONAL_TESTS  2
#define DGOHAL_bfFAULT_MCW_INIT_SAFETY_RESULTS  128
#define DGOHAL_bfFAULT_MCW_OUT1_DIAG_ELEC  2
#define DGOHAL_bfFAULT_MCW_OUT2_DIAG_ELEC  8
#define DGOHAL_bfFAULT_MCWDG_ALGO         32
#define DGOHAL_bfFAULT_MCWDG_CLOCK        128
#define DGOHAL_bfFAULT_MCWDG_COMSPI       2
#define DGOHAL_bfFAULT_MCWDG_DACSIG1      8
#define DGOHAL_bfFAULT_MCWDG_DACSIG2      2
#define DGOHAL_bfFAULT_MCWDG_MONIT        32
#define DGOHAL_bfFAULT_MCWDG_TIMEOUT      8
#define DGOHAL_bfFAULT_MMCDGN_CKS         2
#define DGOHAL_bfFAULT_OPEN               32
#define DGOHAL_bfFAULT_OVERLOAD           128
#define DGOHAL_bfFAULT_SPI_FAILURE        32
#define DGOHAL_bfFAULT_SUPPLY             2
#define DGOHAL_bfFAULT_TMS_CALIB          2
#define DGOHAL_bfFAULT_TMS_CODE           8
#define DGOHAL_bfFAULT_TMSDGN_CALIB_CKS   2
#define DGOHAL_bfFAULT_TMSDGN_CODE_CKS    8
#define DGOHAL_bfFAULT_VBAT_OVER_VOLTAGE  2
#define DGOHAL_bfFAULT_VBAT_UNDER_VOLT    8
#define DGOHAL_bfFAULT_VBAT_UNDER_VOLTAGE  8
#define DGOHAL_bfFAULT_VBOOST_OVER_VOLT   2
#define DGOHAL_bfFAULT_VBOOST_OVER_VOLTAGE  2
#define DGOHAL_bfFAULT_VBOOST_UNDER_VOLT  8
#define DGOHAL_bfFAULT_VBOOST_UNDER_VOLTAGE  8
#define DGOHAL_bfNO_DIAGNOSTIC            0
#define DGOHAL_bfNO_FAULT_CAM_PATTERN     0
#define DGOHAL_bfNO_FAULT_CJ135_HWSC      0
#define DGOHAL_bfNO_FAULT_CJ135_I_LIMIT   0
#define DGOHAL_bfNO_FAULT_CJ135_OPEN_LOAD  0
#define DGOHAL_bfNO_FAULT_CJ135_OVER_CURRENT  0
#define DGOHAL_bfNO_FAULT_CJ135_OVER_TEMPERATURE  0
#define DGOHAL_bfNO_FAULT_CJ135_OVERLOAD  0
#define DGOHAL_bfNO_FAULT_CJ135_SPI_ERROR  0
#define DGOHAL_bfNO_FAULT_CJ135_SUPPLY_VOLTAGE  0
#define DGOHAL_bfNO_FAULT_CRK_LTOO        0
#define DGOHAL_bfNO_FAULT_CRK_LTOO1       0
#define DGOHAL_bfNO_FAULT_CRK_TOO_EXCESS  0
#define DGOHAL_bfNO_FAULT_CRK_TOO_MISS    0
#define DGOHAL_bfNO_FAULT_EXCAM_PATTERN   0
#define DGOHAL_bfNO_FAULT_GROUND          0
#define DGOHAL_bfNO_FAULT_INCAM_PATTERN   0
#define DGOHAL_bfNO_FAULT_L9960_HWSC      0
#define DGOHAL_bfNO_FAULT_L9960_I_LIMIT   0
#define DGOHAL_bfNO_FAULT_L9960_OPEN_LOAD  0
#define DGOHAL_bfNO_FAULT_L9960_OVER_CURRENT  0
#define DGOHAL_bfNO_FAULT_L9960_OVER_TEMPERATURE  0
#define DGOHAL_bfNO_FAULT_L9960_OVERLOAD  0
#define DGOHAL_bfNO_FAULT_L9960_SPI_ERROR  0
#define DGOHAL_bfNO_FAULT_L9960_SUPPLY_VOLTAGE  0
#define DGOHAL_bfNO_FAULT_MCP_FLASH_CKS   0
#define DGOHAL_bfNO_FAULT_MCP_RAM_TEST    0
#define DGOHAL_bfNO_FAULT_MCW_COMPUTED_CKS  0
#define DGOHAL_bfNO_FAULT_MCW_FUNCTIONAL_TESTS  0
#define DGOHAL_bfNO_FAULT_MCW_INIT_SAFETY_RESULTS  0
#define DGOHAL_bfNO_FAULT_MCW_OUT1_DIAG_ELEC  0
#define DGOHAL_bfNO_FAULT_MCW_OUT2_DIAG_ELEC  0
#define DGOHAL_bfNO_FAULT_MCWDG_ALGO      0
#define DGOHAL_bfNO_FAULT_MCWDG_CLOCK     0
#define DGOHAL_bfNO_FAULT_MCWDG_COMSPI    0
#define DGOHAL_bfNO_FAULT_MCWDG_DACSIG1   0
#define DGOHAL_bfNO_FAULT_MCWDG_DACSIG2   0
#define DGOHAL_bfNO_FAULT_MCWDG_MONIT     0
#define DGOHAL_bfNO_FAULT_MCWDG_TIMEOUT   0
#define DGOHAL_bfNO_FAULT_MMCDGN_CKS      0
#define DGOHAL_bfNO_FAULT_OPEN            0
#define DGOHAL_bfNO_FAULT_OVERLOAD        0
#define DGOHAL_bfNO_FAULT_SPI_FAILURE     0
#define DGOHAL_bfNO_FAULT_SUPPLY          0
#define DGOHAL_bfNO_FAULT_TMS_CALIB       0
#define DGOHAL_bfNO_FAULT_TMS_CODE        0
#define DGOHAL_bfNO_FAULT_TMSDGN_CALIB_CKS  0
#define DGOHAL_bfNO_FAULT_TMSDGN_CODE_CKS  0
#define DGOHAL_bfNO_FAULT_VBAT_OVER_VOLTAGE  0
#define DGOHAL_bfNO_FAULT_VBAT_UNDER_VOLT  0
#define DGOHAL_bfNO_FAULT_VBAT_UNDER_VOLTAGE  0
#define DGOHAL_bfNO_FAULT_VBOOST_OVER_VOLT  0
#define DGOHAL_bfNO_FAULT_VBOOST_OVER_VOLTAGE  0
#define DGOHAL_bfNO_FAULT_VBOOST_UNDER_VOLT  0
#define DGOHAL_bfNO_FAULT_VBOOST_UNDER_VOLTAGE  0
#define DGOHAL_bfVALID_CAM_PATTERN        1
#define DGOHAL_bfVALID_CJ135_HWSC         64
#define DGOHAL_bfVALID_CJ135_I_LIMIT      4
#define DGOHAL_bfVALID_CJ135_OPEN_LOAD    16
#define DGOHAL_bfVALID_CJ135_OVER_CURRENT  1
#define DGOHAL_bfVALID_CJ135_OVER_TEMPERATURE  4
#define DGOHAL_bfVALID_CJ135_OVERLOAD     64
#define DGOHAL_bfVALID_CJ135_SPI_ERROR    16
#define DGOHAL_bfVALID_CJ135_SUPPLY_VOLTAGE  1
#define DGOHAL_bfVALID_CRK_LTOO           1
#define DGOHAL_bfVALID_CRK_LTOO1          4
#define DGOHAL_bfVALID_CRK_TOO_EXCESS     16
#define DGOHAL_bfVALID_CRK_TOO_MISS       64
#define DGOHAL_bfVALID_EXCAM_PATTERN      1
#define DGOHAL_bfVALID_GROUND             4
#define DGOHAL_bfVALID_INCAM_PATTERN      1
#define DGOHAL_bfVALID_L9960_HWSC         64
#define DGOHAL_bfVALID_L9960_I_LIMIT      4
#define DGOHAL_bfVALID_L9960_OPEN_LOAD    16
#define DGOHAL_bfVALID_L9960_OVER_CURRENT  1
#define DGOHAL_bfVALID_L9960_OVER_TEMPERATURE  4
#define DGOHAL_bfVALID_L9960_OVERLOAD     64
#define DGOHAL_bfVALID_L9960_SPI_ERROR    16
#define DGOHAL_bfVALID_L9960_SUPPLY_VOLTAGE  1
#define DGOHAL_bfVALID_MCP_FLASH_CKS      4
#define DGOHAL_bfVALID_MCP_RAM_TEST       1
#define DGOHAL_bfVALID_MCW_COMPUTED_CKS   16
#define DGOHAL_bfVALID_MCW_FUNCTIONAL_TESTS  1
#define DGOHAL_bfVALID_MCW_INIT_SAFETY_RESULTS  64
#define DGOHAL_bfVALID_MCW_OUT1_DIAG_ELEC  1
#define DGOHAL_bfVALID_MCW_OUT2_DIAG_ELEC  4
#define DGOHAL_bfVALID_MCWDG_ALGO         16
#define DGOHAL_bfVALID_MCWDG_CLOCK        64
#define DGOHAL_bfVALID_MCWDG_COMSPI       1
#define DGOHAL_bfVALID_MCWDG_DACSIG1      4
#define DGOHAL_bfVALID_MCWDG_DACSIG2      1
#define DGOHAL_bfVALID_MCWDG_MONIT        16
#define DGOHAL_bfVALID_MCWDG_TIMEOUT      4
#define DGOHAL_bfVALID_MMCDGN_CKS         1
#define DGOHAL_bfVALID_OPEN               16
#define DGOHAL_bfVALID_OVERLOAD           64
#define DGOHAL_bfVALID_SPI_FAILURE        16
#define DGOHAL_bfVALID_SUPPLY             1
#define DGOHAL_bfVALID_TMS_CALIB          1
#define DGOHAL_bfVALID_TMS_CODE           4
#define DGOHAL_bfVALID_TMSDGN_CALIB_CKS   1
#define DGOHAL_bfVALID_TMSDGN_CODE_CKS    4
#define DGOHAL_bfVALID_VBAT_OVER_VOLTAGE  1
#define DGOHAL_bfVALID_VBAT_UNDER_VOLT    4
#define DGOHAL_bfVALID_VBAT_UNDER_VOLTAGE  4
#define DGOHAL_bfVALID_VBOOST_OVER_VOLT   1
#define DGOHAL_bfVALID_VBOOST_OVER_VOLTAGE  1
#define DGOHAL_bfVALID_VBOOST_UNDER_VOLT  4
#define DGOHAL_bfVALID_VBOOST_UNDER_VOLTAGE  4
#define DGOHAL_udt_AUTORISATION_REDEM_STT  44
#define DGOHAL_udt_FUEL_JAUGE             29
#define DGOHAL_udtACTR_RLY                41
#define DGOHAL_udtASIC_GDI                18
#define DGOHAL_udtCAMEXHAL                38
#define DGOHAL_udtCAMHAL                  47
#define DGOHAL_udtCAMSHAFT                47
#define DGOHAL_udtCAMSHAFTEX              38
#define DGOHAL_udtCANISTER_PURGE_VALVE    37
#define DGOHAL_udtCHAUFFAGE_BLOW_BY       36
#define DGOHAL_udtCJ135_U2450_ACT_CH      6
#define DGOHAL_udtCJ135_U2450_ECU_CH      5
#define DGOHAL_udtCMD_THR                 21
#define DGOHAL_udtCRANKSHAFT              25
#define DGOHAL_udtCRKHAL                  25
#define DGOHAL_udtDMTR_HOLD_EN            46
#define DGOHAL_udtDUMP_VALVE              39
#define DGOHAL_udtENGINE_RUNNING_OUT      45
#define DGOHAL_udtEXH_CAM_POS             38
#define DGOHAL_udtEXHAUST_VVT             32
#define DGOHAL_udtFUEL_PUMP_BP            48
#define DGOHAL_udtGMV_1                   42
#define DGOHAL_udtGMV_2                   43
#define DGOHAL_udtIGNITION_COIL_1         24
#define DGOHAL_udtIGNITION_COIL_2         23
#define DGOHAL_udtIGNITION_COIL_3         22
#define DGOHAL_udtIGNITION_COIL_4         20
#define DGOHAL_udtINJ_1                   14
#define DGOHAL_udtINJ_2                   15
#define DGOHAL_udtINJ_3                   16
#define DGOHAL_udtINTAKE_VVT              34
#define DGOHAL_udtINTK_CAM_POS            47
#define DGOHAL_udtL9781_ASIC_GDI          18
#define DGOHAL_udtL9781_FUEL_PUMP         17
#define DGOHAL_udtL9781_INJECTOR_1        14
#define DGOHAL_udtL9781_INJECTOR_2        15
#define DGOHAL_udtL9781_INJECTOR_3        16
#define DGOHAL_udtL9781_VBOOST            19
#define DGOHAL_udtL9960_U2000_ACT_CH      21
#define DGOHAL_udtL9960_U2000_ECU_CH      11
#define DGOHAL_udtL9960_U2002_ACT_CH      9
#define DGOHAL_udtL9960_U2002_ECU_CH      10
#define DGOHAL_udtLOW_PRES_FUEL_PUMP      29
#define DGOHAL_udtMAIN_DWN_LBDA_SNS_HEAT  33
#define DGOHAL_udtMAIN_RLY                26
#define DGOHAL_udtMAIN_UPS_LBDA_SNS_HEAT  31
#define DGOHAL_udtMCWDG_DAC_CHECK         27
#define DGOHAL_udtMCWDG_ELEC_TESTS        0
#define DGOHAL_udtMCWDG_FUNCTIONAL_TESTS  2
#define DGOHAL_udtMCWDG_INIT_SAFETY       1
#define DGOHAL_udtMCWDG_MICRO_CHECK       28
#define DGOHAL_udtMMCDGN                  12
#define DGOHAL_udtOIL_VAR_PUMP_VALVE      40
#define DGOHAL_udtPWL_MAIN_RELAY          26
#define DGOHAL_udtRTMCKS_TMS              13
#define DGOHAL_udtSO2_HEAT_DOWN           33
#define DGOHAL_udtSO2_HEAT_UP             31
#define DGOHAL_udtSPILL_VALVE             17
#define DGOHAL_udtSTARTER_ACTIVATION      35
#define DGOHAL_udtTHERMOSTAT_PILOTE       30
#define DGOHAL_udtTLE8718_OUT1            31
#define DGOHAL_udtTLE8718_OUT10           40
#define DGOHAL_udtTLE8718_OUT11           41
#define DGOHAL_udtTLE8718_OUT12           42
#define DGOHAL_udtTLE8718_OUT13           43
#define DGOHAL_udtTLE8718_OUT14           44
#define DGOHAL_udtTLE8718_OUT15           45
#define DGOHAL_udtTLE8718_OUT16           46
#define DGOHAL_udtTLE8718_OUT17           3
#define DGOHAL_udtTLE8718_OUT18           48
#define DGOHAL_udtTLE8718_OUT2            32
#define DGOHAL_udtTLE8718_OUT3            33
#define DGOHAL_udtTLE8718_OUT4            34
#define DGOHAL_udtTLE8718_OUT5            35
#define DGOHAL_udtTLE8718_OUT6            36
#define DGOHAL_udtTLE8718_OUT7            37
#define DGOHAL_udtTLE8718_OUT8            4
#define DGOHAL_udtTLE8718_OUT9            39
#define DGOHAL_udtTMS                     13
#define DGOHAL_udtVBOOST                  19
#define DGOHAL_udtVNS1_Q1504_1            8
#define DGOHAL_udtVNS1_Q1504_2            7
#define STUB_DGOHAL_udtTHERMOSTAT_PILOTE  30

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DGOHAL_vidInit(void);
void DGOHAL_vidWrite(DGOHAL_tudtChannel udtChannel, DGOHAL_tbfStatus bfDiagDone, DGOHAL_tbfStatus bfFailResult);
DGOHAL_tbfStatus DGOHAL_bfRead(DGOHAL_tudtChannel udtChannel);


#endif /* DGOHAL_H */

/*-------------------------------- end of file -------------------------------*/
