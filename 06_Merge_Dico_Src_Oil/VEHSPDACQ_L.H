/***************************************************************************
;**
;** FILE NAME      : VEHSPDACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHSPDACQ_L_H
#define VEHSPDACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BUFVEHSPDACQ_COLS                      ( 8 )
#define VEHSPDACQ_AU8ACCELFILAIRERAW_COLS      ( 8 )

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

extern const uint8  VEHSPDACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Vehicle_stopped;
extern boolean VehSpd_bBattVoltOK;
extern boolean VehSpd_bCntrChg;
extern boolean VehSpd_bInfoAvl;
extern boolean VEHSPDACQ_bBattVoltOKPrev;
extern boolean VEHSPDACQ_bFallingHystOutput;
extern boolean VEHSPDACQ_bFilterAnRebond;
extern boolean VEHSPDACQ_bRisingHystOutput;
extern boolean VEHSPDACQ_bTimeOut;
extern uint32 Cumul_PlsTiIntr;
extern uint32 Distance_fil_precise;
extern uint32 VehSpd_PlsDate;
extern uint32 VehSpd_PrevPlsDate;
extern uint32 VEHSPDACQ_u32AccelFiltredMem;
extern uint32 VEHSPDACQ_u32FirstOrderFilterMem;
extern uint8 Acceleration_filaire_consolide;
extern uint8 Acceleration_filaireAcq;
extern uint8 Acceleration_filaireRaw;
extern uint8 AccMoyen_index;
extern uint8 BufVEHSPDACQ_index;
extern uint8 Compteur_arret_vehicule;
extern uint8 Ext_AccBuf;
extern uint8 Ext_VehSpdBuf;
extern uint8 VEHSPDACQ_au8AccelfilaireRaw[VEHSPDACQ_AU8ACCELFILAIRERAW_COLS];
extern uint8 VEHSPDACQ_u8InputFilter;
extern uint16 BufVEHSPDACQ[BUFVEHSPDACQ_COLS];
extern uint16 Ext_MeanSpdVehRaw;
extern uint16 Ext_spdVehRawAcq;
extern uint16 Ext_spdVehRawAcqPrev;
extern uint16 Ext_spdVehTreat;
extern uint16 Ext_VehSpdOvfPlsTiIntl;
extern uint16 Ext_VehSpdPlsTiIntl;
extern uint16 VehSpd_ctPls;
extern uint16 VEHSPDACQ_u16CounterAntiRebond;
extern uint16 VEHSPDACQ_u16CtPlsPrev;
extern uint16 Vitesse_vehicule_consolide;
extern uint16 Vitesse_vehicule_fil_preciseAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VEHSPDACQ_vidAccelComputation(void);
void VEHSPDACQ_vidAccelMoyenCompt(void);
void VEHSPDACQ_vidAcvEveVSTopCall(void);
void VEHSPDACQ_vidAcvSdlFastCall(void);
void VEHSPDACQ_vidChkBatt(void);
void VEHSPDACQ_vidChkCondCalc(void);
void VEHSPDACQ_vidCoveredDistance(void);
void VEHSPDACQ_vidDataAcquisition(void);
void VEHSPDACQ_vidDateOvfMng(void);
void VEHSPDACQ_vidDynFil(void);
void VEHSPDACQ_vidInit(void);
void VEHSPDACQ_vidInitDistance(void);
void VEHSPDACQ_vidInitOutput(void);
void VEHSPDACQ_vidMeanComputation(void);
void VEHSPDACQ_vidReadCtrAndDate(void);
void VEHSPDACQ_vidSpdComputation(void);
void VEHSPDACQ_vidSPDHALAcq(void);
void VEHSPDACQ_vidSPDHALDis(void);
void VEHSPDACQ_vidSPDHALEna(void);
void VEHSPDACQ_vidStopDetection(void);
void VEHSPDACQ_vidTiIntlComputation(void);
void VEHSPDACQ_vidTransmission(void);
void VEHSPDACQ_vidVehSpdBuf(void);
void VEHSPDACQ_vidVehSpdComputation(void);


#endif /* VEHSPDACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
