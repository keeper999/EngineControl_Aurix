/***************************************************************************
;**
;** FILE NAME      : BATTVOLTACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BATTVOLTACQ.H"
#include "BATTVOLTACQ_L.H"
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
const boolean  Pwr_bEnaEve2ms_C = 0;
const boolean  Pwr_bEnaEveInj_C = 0;
const uint8  BATTVOLTACQ_u8Inhib = 0;
const uint8  Gain_tension_batterie_filt = 0;
const uint8  Pwr_rSample1_C = 0;
const uint8  Pwr_rSample2_C = 0;
const uint8  Pwr_rSample3_C = 0;
const uint8  Pwr_rSample4_C = 0;
const uint8  Pwr_rSample5_C = 0;
const uint8  Seuil_filtre_anti_progression = 0;
const uint8  Seuil_regime_batterie_batt_basse = 0;
const uint16  B_v_slew_variation = 0;
const uint16  Pwr_nEngHysThd_uBattFil_C = 0;
const uint16  Pwr_nEngThd_uBattFil_C = 0;
const uint16  Pwr_uBattMinSpc_C = 0;
const uint16  Pwr_uBattOfsSpc_C = 0;
const uint16  Tension_batterie_brute_max = 0;
const uint16  Tension_batterie_brute_min = 0;
const uint16  Tension_batterie_par_defaut = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoHi_uBattMes;
boolean Ext_bDgoLo_uBattMes;
boolean Ext_bDgoLo_uBattSpc;
boolean Ext_bMonRunHi_uBattMes;
boolean Ext_bMonRunLo_uBattMes;
boolean Ext_bMonRunLo_uBattSpc;
boolean Pwr_bAcvEveInjStra;
boolean Pwr_bHysVoltAcqFil;
uint32 BATTVOLTACQ_u32FiltPosErrorMem;
uint16 Pwr_uBattDiagAcq;
uint16 Pwr_uBattEveInjAcq;
uint16 Pwr_uBattFilAcq;
uint16 Pwr_uBattRaw1;
uint16 Pwr_uBattRaw2;
uint16 Pwr_uBattRaw3;
uint16 Pwr_uBattRaw4;
uint16 Pwr_uBattRaw5;
uint16 Tension_batterie;
uint16 Tension_batterie_acq_prec;
uint16 Tension_batterie_brute;
uint16 Tension_batterie_filtree;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

