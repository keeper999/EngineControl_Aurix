/***************************************************************************
;**
;** FILE NAME      : VEHSPDACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VEHSPDACQ.H"
#include "VEHSPDACQ_L.H"
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
const boolean  VehSpd_bDeadzone_C = 0;
const boolean  VehSpd_bEnaChkBattVolt_C = 0;
const uint8  VehSpd_AccMoyIndex_C = 0;
const uint8  VehSpd_tiDlyVehStopCmpl_C = 0;
const uint8  VEHSPDACQ_u8Inhib = 0;
const uint16  Acc_AntiRebond_Down_C = 0;
const uint16  VehSpd_dstIntlPls_C = 0;
const uint16  VehSpd_facAccelFilGain_C = 0;
const uint16  VehSpd_facFilterGain_C = 0;
const uint16  VehSpd_spdMinForClamp_C = 0;
const uint16  VehSpd_spdMinSat_C = 0;
const uint16  VehSpd_uBattVoltHiThd_C = 0;
const uint16  VehSpd_uBattVoltHysThd_C = 0;
const uint16  VehSpd_uBattVoltLoThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Vehicle_stopped;
boolean VehSpd_bBattVoltOK;
boolean VehSpd_bCntrChg;
boolean VehSpd_bInfoAvl;
boolean VEHSPDACQ_bBattVoltOKPrev;
boolean VEHSPDACQ_bFallingHystOutput;
boolean VEHSPDACQ_bFilterAnRebond;
boolean VEHSPDACQ_bRisingHystOutput;
boolean VEHSPDACQ_bTimeOut;
uint32 Cumul_PlsTiIntr;
uint32 Distance_fil_precise;
uint32 VehSpd_PlsDate;
uint32 VehSpd_PrevPlsDate;
uint32 VEHSPDACQ_u32AccelFiltredMem;
uint32 VEHSPDACQ_u32FirstOrderFilterMem;
uint8 Acceleration_filaire;
uint8 Acceleration_filaire_consolide;
uint8 Acceleration_filaireAcq;
uint8 Acceleration_filaireRaw;
uint8 AccMoyen_index;
uint8 BufVEHSPDACQ_index;
uint8 Compteur_arret_vehicule;
uint8 Ext_AccBuf;
uint8 Ext_VehSpdBuf;
uint8 VEHSPDACQ_au8AccelfilaireRaw[VEHSPDACQ_AU8ACCELFILAIRERAW_COLS];
uint8 VEHSPDACQ_u8InputFilter;
uint16 BufVEHSPDACQ[BUFVEHSPDACQ_COLS];
uint16 Distance_parcourue_fil;
uint16 Ext_MeanSpdVehRaw;
uint16 Ext_spdVehRaw;
uint16 Ext_spdVehRawAcq;
uint16 Ext_spdVehRawAcqPrev;
uint16 Ext_spdVehTreat;
uint16 Ext_VehSpdOvfPlsTiIntl;
uint16 Ext_VehSpdPlsTiIntl;
uint16 VehSpd_ctPls;
uint16 VEHSPDACQ_u16CounterAntiRebond;
uint16 VEHSPDACQ_u16CtPlsPrev;
uint16 Vitesse_vehicule_consolide;
uint16 Vitesse_vehicule_fil_precise;
uint16 Vitesse_vehicule_fil_preciseAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

