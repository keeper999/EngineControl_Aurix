/***************************************************************************
;**
;** FILE NAME      : OFSVLV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OFSVLV.H"
#include "OFSVLV_L.H"
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
const boolean  VlvSys_bAcvBedModLimScv_C = 0;
const boolean  VlvSys_bAcvClsExVlvRateLim_C = 0;
const boolean  VlvSys_bAcvDftPosLocLop_C = 0;
const boolean  VlvSys_bAcvExVlvBedMod_C = 0;
const boolean  VlvSys_bAcvInVlvBedMod_C = 0;
const boolean  VlvSys_bAcvOpInVlvRateLim_C = 0;
const boolean  VlvSys_bAcvTPMBedMod_C = 0;
const boolean  VlvSys_bMassAirScvSel_C = 0;
const boolean  VlvSys_bPresTrb_C = 0;
const sint8  VlvSys_agCkClsExVlvReqRef0Max_C = 0;
const sint8  VlvSys_agCkOpInVlvReqRef0Min_C = 0;
const uint8  OFSVLV_u8Inhib = 0;
const uint8  VlvSys_agCkClsExVlvBedMod_C = 0;
const uint8  VlvSys_agCkOpInVlvBedMod_C = 0;
const uint8  VlvSys_agCkVlvOvlpMax_C = 0;
const uint8  VlvSys_agCkVlvOvlpMax_M[VLVSYS_AGCKVLVOVLPMAX_M_LNS][VLVSYS_AGCKVLVOVLPMAX_M_COLS] = {0};
const sint16  VlvSys_agCkPosnVlvOvlpOfs_C = 0;
const sint16  VlvSys_agCkVlvOvlpOfs_C = 0;
const uint16  VlvSys_agCkGrdDecClsExVlv_M[VLVSYS_AGCKGRDDECCLSEXVLV_M_LNS][VLVSYS_AGCKGRDDECCLSEXVLV_M_COLS] = {0};
const uint16  VlvSys_agCkGrdDecOpInVlv_M[VLVSYS_AGCKGRDDECOPINVLV_M_LNS][VLVSYS_AGCKGRDDECOPINVLV_M_COLS] = {0};
const uint16  VlvSys_agCkGrdIncClsExVlv_M[VLVSYS_AGCKGRDINCCLSEXVLV_M_LNS][VLVSYS_AGCKGRDINCCLSEXVLV_M_COLS] = {0};
const uint16  VlvSys_agCkGrdIncOpInVlv_M[VLVSYS_AGCKGRDINCOPINVLV_M_LNS][VLVSYS_AGCKGRDINCOPINVLV_M_COLS] = {0};
const uint16  VlvSys_facCmdLimScv_M[VLVSYS_FACCMDLIMSCV_M_LNS][VLVSYS_FACCMDLIMSCV_M_COLS] = {0};
const uint16  VlvSys_facTranFilStepAcvServo_C = 0;
const uint16  VlvSys_mfAirScvLimMaxBedMod_C = 0;
const uint16  VlvSys_mfAirScvRed_A[VLVSYS_MFAIRSCVRED_A_COLS] = {0};
const uint16  VlvSys_rFilGainClsExVlv_T[VLVSYS_RFILGAINCLSEXVLV_T_COLS] = {0};
const uint16  VlvSys_rFilGainOpInVlv_T[VLVSYS_RFILGAINOPINVLV_T_COLS] = {0};
const uint16  VlvSys_rThdLimScv_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 OFSVLV_u8PilotageCroismntMax;
boolean VlvSys_bAcvBedModLimScv;
boolean VlvSys_bDetExServoDftPos;
boolean VlvSys_bDetInServoDftPos;
boolean VlvSys_bPresExServo;
boolean VlvSys_bPresInServo;
uint32 OFSVLV_u32AirEfcPresEngX;
sint8 VlvSys_agCkClsExVlvReqRef0Max;
sint8 VlvSys_agCkOpInVlvReqRef0Min;
uint8 VlvSys_agCkClsExVlvAcvCorReq;
uint8 VlvSys_agCkClsExVlvBedModCorReq;
uint8 VlvSys_agCkClsExVlvEstimIni;
uint8 VlvSys_agCkClsExVlvLocLopCorReq;
uint8 VlvSys_agCkClsExVlvMax;
uint8 VlvSys_agCkClsExVlvReqRef0Min;
uint8 VlvSys_agCkClsExVlvScvCorReq;
uint8 VlvSys_agCkOpInVlvAcvCorReq;
uint8 VlvSys_agCkOpInVlvBedModCorReq;
uint8 VlvSys_agCkOpInVlvEstimIni;
uint8 VlvSys_agCkOpInVlvLocLopCorReq;
uint8 VlvSys_agCkOpInVlvMin;
uint8 VlvSys_agCkOpInVlvReqRef0Max;
uint8 VlvSys_agCkOpInVlvScvCorReq;
uint8 VlvSys_agCkVlvOvlpMax;
sint16 OFSVLV_s16AirCkPosnVlvOvlpX;
sint16 OFSVLV_s16OutFilterEx;
sint16 OFSVLV_s16OutFilterIn;
sint16 VlvSys_agCkOpExVlvSatCorReq_MP;
sint16 VlvSys_agCkOpInVlvSatCorReq_MP;
uint16 ExM_pExMnfEstimRef;
uint16 InM_pDsThrPred_facVlvOvlpRef;
uint16 VlvSys_facChrExp_MP;
uint16 VlvSys_facCmdLimScv;
uint16 VlvSys_facMassFlowCor_MP;
uint16 VlvSys_facTInSqrt_MP;
uint16 VlvSys_mfAirScvRed_MP;
uint16 VlvSys_mfAirScvTotLimMax_MP;
uint16 VlvSys_rTranAcvVlvSys;
sint32 OFSVLV_s32Filtre1Mem;
sint32 OFSVLV_s32Filtre2Mem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

