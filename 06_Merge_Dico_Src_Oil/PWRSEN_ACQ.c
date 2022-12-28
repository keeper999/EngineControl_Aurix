/***************************************************************************
;**
;** FILE NAME      : PWRSEN_ACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PWRSEN_ACQ.H"
#include "PWRSEN_ACQ_L.H"
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
const uint8  Conf_alimentation_ac = 0;
const uint8  Conf_alimentation_air_pts = 0;
const uint8  Conf_alimentation_aps = 0;
const uint8  Conf_alimentation_pmast = 0;
const uint8  Conf_alimentation_thr = 0;
const uint8  Ext_idxAccP2Cf_C = 0;
const uint8  Ext_idxBoostPresCf_C = 0;
const uint8  Ext_idxCluPosnCf_C = 0;
const uint8  Ext_idxExCmCf_C = 0;
const uint8  Ext_idxInCmCf_C = 0;
const uint8  Ext_idxnEngCf_C = 0;
const uint8  Ext_idxNeutCf_C = 0;
const uint8  Ext_idxPfuCf_C = 0;
const uint8  Ext_idxptOilCf_C = 0;
const uint8  Ext_idxTrbActCf_C = 0;
const uint8  PWRSEN_ACQ_u8Inhib = 0;
const uint16  Tension_alim_capteur_maxi = 0;
const uint16  Tension_alim_capteur_maxi_sdf = 0;
const uint16  Tension_alim_capteur_mini = 0;
const uint16  Tension_alim_capteur_mini_sdf = 0;
const uint16  Tension_alim_par_defaut = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Pwr_bDgoORng_vMes1;
boolean Pwr_bDgoORng_vMes1_Sfty;
boolean Pwr_bDgoORng_vMes2;
boolean Pwr_bDgoORng_vMes2_Sfty;
boolean Pwr_bDgoORng_vMes3;
boolean Pwr_bDgoORng_vMes3_Sfty;
boolean Pwr_bDgoORng_vMes4;
boolean Pwr_bDgoORng_vMes4_Sfty;
boolean Pwr_bMonRunORng_vMes1;
boolean Pwr_bMonRunORng_vMes1_Sfty;
boolean Pwr_bMonRunORng_vMes2;
boolean Pwr_bMonRunORng_vMes2_Sfty;
boolean Pwr_bMonRunORng_vMes3;
boolean Pwr_bMonRunORng_vMes3_Sfty;
boolean Pwr_bMonRunORng_vMes4;
boolean Pwr_bMonRunORng_vMes4_Sfty;
uint16 Ext_uAccP1SenPwr;
uint16 Ext_uAccP2SenPwr;
uint16 Ext_uCluPosnSenPwr;
uint16 Ext_uExCmSenPwr;
uint16 Ext_uInCmSenPwr;
uint16 Ext_unEngSenPwr;
uint16 Ext_uNeutSenPwr;
uint16 Ext_upAcSenPwr;
uint16 Ext_upBoostSenPwr;
uint16 Ext_uPfuSenPwr;
uint16 Ext_upMastSenPwr;
uint16 Ext_uptAirSenPwr;
uint16 Ext_uptOilSenPwr;
uint16 Ext_uThrSenPwr;
uint16 Ext_uTrbActSenPwr;
uint16 Tension_alimentation_1;
uint16 Tension_alimentation_1_brute;
uint16 Tension_alimentation_1_mesuree;
uint16 Tension_alimentation_2;
uint16 Tension_alimentation_2_brute;
uint16 Tension_alimentation_2_mesuree;
uint16 Tension_alimentation_3;
uint16 Tension_alimentation_3_brute;
uint16 Tension_alimentation_3_mesuree;
uint16 Tension_alimentation_4;
uint16 Tension_alimentation_4_brute;
uint16 Tension_alimentation_4_mesuree;
uint16 Tension_alimentation_ac;
uint16 Tension_alimentation_air_pts;
uint16 Tension_alimentation_aps;
uint16 Tension_alimentation_pmast;
uint16 Tension_alimentation_thr;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

