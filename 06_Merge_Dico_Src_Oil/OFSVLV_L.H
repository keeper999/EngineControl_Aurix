/***************************************************************************
;**
;** FILE NAME      : OFSVLV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OFSVLV_L_H
#define OFSVLV_L_H

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

/* enum st124 */
#define VVT_ADM_EN_BUTEE                  5
#define VVT_ADM_ET_ECH_EN_BUTEE           6
#define VVT_ECH_EN_BUTEE                  7
#define PAS_DE_VVT_EN_BUTEE               8
/*extern uint8 OFSVLV_u8PilotageCroismntMax;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  OFSVLV_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 OFSVLV_u8PilotageCroismntMax;
extern boolean VlvSys_bAcvBedModLimScv;
extern boolean VlvSys_bPresExServo;
extern boolean VlvSys_bPresInServo;
extern uint32 OFSVLV_u32AirEfcPresEngX;
extern sint8 VlvSys_agCkClsExVlvReqRef0Max;
extern sint8 VlvSys_agCkOpInVlvReqRef0Min;
extern uint8 VlvSys_agCkClsExVlvBedModCorReq;
extern uint8 VlvSys_agCkClsExVlvEstimIni;
extern uint8 VlvSys_agCkClsExVlvLocLopCorReq;
extern uint8 VlvSys_agCkClsExVlvMax;
extern uint8 VlvSys_agCkClsExVlvReqRef0Min;
extern uint8 VlvSys_agCkClsExVlvScvCorReq;
extern uint8 VlvSys_agCkOpInVlvBedModCorReq;
extern uint8 VlvSys_agCkOpInVlvEstimIni;
extern uint8 VlvSys_agCkOpInVlvLocLopCorReq;
extern uint8 VlvSys_agCkOpInVlvMin;
extern uint8 VlvSys_agCkOpInVlvReqRef0Max;
extern uint8 VlvSys_agCkOpInVlvScvCorReq;
extern uint8 VlvSys_agCkVlvOvlpMax;
extern sint16 OFSVLV_s16AirCkPosnVlvOvlpX;
extern sint16 OFSVLV_s16OutFilterEx;
extern sint16 OFSVLV_s16OutFilterIn;
extern sint16 VlvSys_agCkOpExVlvSatCorReq_MP;
extern sint16 VlvSys_agCkOpInVlvSatCorReq_MP;
extern uint16 ExM_pExMnfEstimRef;
extern uint16 InM_pDsThrPred_facVlvOvlpRef;
extern uint16 VlvSys_facChrExp_MP;
extern uint16 VlvSys_facCmdLimScv;
extern uint16 VlvSys_facMassFlowCor_MP;
extern uint16 VlvSys_facTInSqrt_MP;
extern uint16 VlvSys_mfAirScvRed_MP;
extern uint16 VlvSys_mfAirScvTotLimMax_MP;
extern uint16 VlvSys_rTranAcvVlvSys;
extern sint32 OFSVLV_s32Filtre1Mem;
extern sint32 OFSVLV_s32Filtre2Mem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OFSVLV_vidActAdmission(void);
void OFSVLV_vidActEchappement(void);
void OFSVLV_vidActivation(void);
void OFSVLV_vidBalayage_maximum(void);
void OFSVLV_vidBalayage_maximumCalc(void);
void OFSVLV_vidBalayageMaxParDft(void);
void OFSVLV_vidBanc_Admission(void);
void OFSVLV_vidBanc_Echappement(void);
void OFSVLV_vidCalcConsigLimit(void);
void OFSVLV_vidDefinition_butee(void);
void OFSVLV_vidDevectorisation(void);
void OFSVLV_vidInit(void);
void OFSVLV_vidInitOutput(void);
void OFSVLV_vidLimitation_consignes(void);
void OFSVLV_vidLimitation_du_balayage(void);
void OFSVLV_vidMode_banc(void);
void OFSVLV_vidPanne(void);
void OFSVLV_vidPanneAdmission(void);
void OFSVLV_vidPanneEchappement(void);
void OFSVLV_vidPilotAdmission(void);
void OFSVLV_vidPilotage_VVT_en_butee(void);
void OFSVLV_vidPilotageCroimntMaxInit(void);
void OFSVLV_vidPilotageCroisemntMax(void);
void OFSVLV_vidPilotEchappement(void);
void OFSVLV_vidSatAdmission(void);
void OFSVLV_vidSatEchappement(void);
void OFSVLV_vidSatNot_Admission(void);
void OFSVLV_vidSatNot_Echappement(void);
void OFSVLV_vidSaturations(void);
void OFSVLV_vidTranfDebitBalyCroismnt(void);
void OFSVLV_vidTransition_activation(void);
void OFSVLV_vidVerification_balayage(void);
void OFSVLV_vidVlvArb(void);


#endif /* OFSVLV_L_H */

/*-------------------------------- end of file -------------------------------*/
