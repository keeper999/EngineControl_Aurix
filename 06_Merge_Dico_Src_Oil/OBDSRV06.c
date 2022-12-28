/***************************************************************************
;**
;** FILE NAME      : OBDSRV06.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OBDSRV06.H"
#include "OBDSRV06_L.H"
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
const boolean  Manu_inh_mode_6_scantool = 0;
const boolean  Manu_inh_obdmid_01 = 0;
const boolean  Manu_inh_obdmid_02 = 0;
const boolean  Manu_inh_obdmid_21 = 0;
const boolean  Manu_inh_obdmid_41 = 0;
const boolean  Manu_inh_obdmid_42 = 0;
const boolean  Manu_inh_obdmid_A2 = 0;
const boolean  Manu_inh_obdmid_A3 = 0;
const boolean  Manu_inh_obdmid_A4 = 0;
const boolean  Manu_inh_obdmid_A5 = 0;
const boolean  Mode_6_obdmid_21_tid_81 = 0;
const boolean  Mode_6_obdmid_41_tid_D0 = 0;
const boolean  Mode_6_obdmid_42_tid_DA = 0;
const boolean  Mode_6_obdmid_A2_tid_0B = 0;
const boolean  Mode_6_obdmid_A2_tid_0C = 0;
const boolean  Mode_6_obdmid_A3_tid_0B = 0;
const boolean  Mode_6_obdmid_A3_tid_0C = 0;
const boolean  Mode_6_obdmid_A4_tid_0B = 0;
const boolean  Mode_6_obdmid_A4_tid_0C = 0;
const boolean  Mode_6_obdmid_A5_tid_0B = 0;
const boolean  Mode_6_obdmid_A5_tid_0C = 0;
const uint8  Mode_6_s1_01_data_a = 0;
const uint8  Mode_6_s1_01_data_b = 0;
const uint8  Mode_6_s1_81_data_d = 0;
const uint8  Mode_6_s1_A1_data_a = 0;
const uint8  Mode_6_s2_01_data_a = 0;
const uint8  Mode_6_s2_A1_data_d = 0;
const uint8  Mode_6_s2_C1_data_a = 0;
const uint8  OBDSRV06_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bCondDiag_Cat;
boolean Ext_bCondDiag_DsHeat;
boolean Ext_bCondDiag_DsPlausFco;
boolean Ext_bCondDiag_DsPlausFld;
boolean Ext_bCondDiag_Misf;
boolean Ext_bCondDiag_OxySensPerd;
boolean Ext_bCondDiag_SigGrdDiag;
boolean Ext_bCondDiag_uDsLs;
boolean Ext_bCondDiag_UsHeat;
boolean Ext_bCondDiag_UsPlausFco;
boolean Ext_bCondDiag_UsPlausFld;
boolean Ext_bCondDiag_uUpLs;
uint8 GD_stEventStatus_prev[GD_STEVENTSTATUS_PREV_LNS];
uint16 SenO2Ds_SigGrd_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

