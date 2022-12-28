/***************************************************************************
;**
;** FILE NAME      : WKU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WKU_L_H
#define WKU_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define U16MAX_TIME_DEC_RANGE             62500

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

extern const uint8  WKU_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Clef_de_contact_ss_coh;
extern boolean EcuSt_bDgoF432Lost;
extern boolean EcuSt_bDgoMainWkuDisrd;
extern boolean EcuSt_bDgoMainWkuIncst;
extern boolean EcuSt_bEngFanReq;
extern boolean EcuSt_bEngPrep;
extern boolean EcuSt_bImmoUnlockReq;
extern boolean EcuSt_bMonRunF432Lost;
extern boolean EcuSt_bMonRunMainWkuDisrd;
extern boolean EcuSt_bMonRunMainWkuIncst;
extern boolean EcuSt_bOilMesEng;
extern boolean EcuSt_bWkuMain;
extern boolean Ext_bDgoRCDLineScg;
extern boolean Ext_bMonRunRCDLineScg;
extern boolean Rcd_demand_anticip_adc;
extern boolean Rcd_demand_mes_huile_moteur;
extern boolean Rcd_demand_post_ventil_mot;
extern boolean Rcd_demand_prepa_moteur;
extern boolean Temp_panne_coh_1;
extern boolean Temp_panne_coh_2;
extern uint8 Rcd_anticipation_adc_count;
extern uint8 Rcd_autoris_surveil_trame_compt;
extern uint8 Rcd_clef_off_default_count;
extern uint8 Rcd_mes_huile_moteur_count;
extern uint8 Rcd_post_ventil_mot_count;
extern uint8 Rcd_preparation_moteur_count;
extern uint8 Rcd_reception_trame_compteur;
extern uint8 Rcd_reveil_principal_count;
extern uint16 Rcd_anticipation_adc_max_count;
extern uint16 Rcd_bascule_vers_principal_count;
extern uint16 Rcd_mes_huile_moteur_max_count;
extern uint16 Rcd_post_ventil_mot_max_count;
extern uint16 Rcd_prepa_mot_max_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void WKU_vidAPCFirstKeyOn(void);
void WKU_vidBlcPartWkADCAntCase(void);
void WKU_vidBlcPartWkEngOilMesPrep(void);
void WKU_vidBlcPartWkEngPostVent(void);
void WKU_vidBlcPartWkEngStartPrep(void);
void WKU_vidBlocPartWkEngOilMeas(void);
void WKU_vidCaseRcdSignalEqual0(void);
void WKU_vidCaseRcdSignalEqual1(void);
void WKU_vidElectronicIntegration(void);
void WKU_vidForcMainWkAtReqDiag(void);
void WKU_vidFrameMonitoring(void);
void WKU_vidFrameReception(void);
void WKU_vidInitWku(void);
void WKU_vidInterface(void);
void WKU_vidMainGradToPass(void);
void WKU_vidMainWkCohDmdWku(void);
void WKU_vidMainWkIncoh(void);
void WKU_vidMainWkPassCANOutOfOrd(void);
void WKU_vidMainWku(void);
void WKU_vidMgmtCntPowerOnDefault(void);
void WKU_vidPartWkADCAnticip(void);
void WKU_vidPartWkEngPostVent(void);
void WKU_vidPartWkEngStartPrep(void);
void WKU_vidRstRcdCount(void);
void WKU_vidTimerFlow(void);


#endif /* WKU_L_H */

/*-------------------------------- end of file -------------------------------*/
