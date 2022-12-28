/***************************************************************************
;**
;** FILE NAME      : PWRSEN_ACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PWRSEN_ACQ_H
#define PWRSEN_ACQ_H

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

extern const uint8  Conf_alimentation_ac;
extern const uint8  Conf_alimentation_air_pts;
extern const uint8  Conf_alimentation_aps;
extern const uint8  Conf_alimentation_pmast;
extern const uint8  Conf_alimentation_thr;
extern const uint8  Ext_idxAccP2Cf_C;
extern const uint8  Ext_idxBoostPresCf_C;
extern const uint8  Ext_idxCluPosnCf_C;
extern const uint8  Ext_idxExCmCf_C;
extern const uint8  Ext_idxInCmCf_C;
extern const uint8  Ext_idxnEngCf_C;
extern const uint8  Ext_idxNeutCf_C;
extern const uint8  Ext_idxPfuCf_C;
extern const uint8  Ext_idxptOilCf_C;
extern const uint8  Ext_idxTrbActCf_C;
extern const uint16  Tension_alim_capteur_maxi;
extern const uint16  Tension_alim_capteur_maxi_sdf;
extern const uint16  Tension_alim_capteur_mini;
extern const uint16  Tension_alim_capteur_mini_sdf;
extern const uint16  Tension_alim_par_defaut;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_uAccP1SenPwr;
extern uint16 Ext_uAccP2SenPwr;
extern uint16 Ext_uCluPosnSenPwr;
extern uint16 Ext_uExCmSenPwr;
extern uint16 Ext_uInCmSenPwr;
extern uint16 Ext_unEngSenPwr;
extern uint16 Ext_uNeutSenPwr;
extern uint16 Ext_upAcSenPwr;
extern uint16 Ext_upBoostSenPwr;
extern uint16 Ext_uPfuSenPwr;
extern uint16 Ext_upMastSenPwr;
extern uint16 Ext_uptAirSenPwr;
extern uint16 Ext_uptOilSenPwr;
extern uint16 Ext_uThrSenPwr;
extern uint16 Ext_uTrbActSenPwr;
extern uint16 Tension_alimentation_1;
extern uint16 Tension_alimentation_1_brute;
extern uint16 Tension_alimentation_1_mesuree;
extern uint16 Tension_alimentation_2;
extern uint16 Tension_alimentation_2_brute;
extern uint16 Tension_alimentation_2_mesuree;
extern uint16 Tension_alimentation_3;
extern uint16 Tension_alimentation_3_brute;
extern uint16 Tension_alimentation_3_mesuree;
extern uint16 Tension_alimentation_4;
extern uint16 Tension_alimentation_4_brute;
extern uint16 Tension_alimentation_4_mesuree;
extern uint16 Tension_alimentation_ac;
extern uint16 Tension_alimentation_air_pts;
extern uint16 Tension_alimentation_aps;
extern uint16 Tension_alimentation_pmast;
extern uint16 Tension_alimentation_thr;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Pwr_EveRst_Acq(void);
void Pwr_SdlFast_Acq(void);
void Pwr_SdlMid_Acq(void);


#endif /* PWRSEN_ACQ_H */

/*-------------------------------- end of file -------------------------------*/
