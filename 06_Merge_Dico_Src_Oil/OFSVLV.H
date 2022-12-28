/***************************************************************************
;**
;** FILE NAME      : OFSVLV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OFSVLV_H
#define OFSVLV_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVSYS_AGCKGRDDECCLSEXVLV_M_LNS       ( 16 )
#define VLVSYS_AGCKGRDDECCLSEXVLV_M_COLS       ( 16 )
#define VLVSYS_AGCKGRDDECOPINVLV_M_LNS        ( 16 )
#define VLVSYS_AGCKGRDDECOPINVLV_M_COLS        ( 16 )
#define VLVSYS_AGCKGRDINCCLSEXVLV_M_LNS       ( 16 )
#define VLVSYS_AGCKGRDINCCLSEXVLV_M_COLS       ( 16 )
#define VLVSYS_AGCKGRDINCOPINVLV_M_LNS        ( 16 )
#define VLVSYS_AGCKGRDINCOPINVLV_M_COLS        ( 16 )
#define VLVSYS_AGCKVLVOVLPMAX_M_LNS           ( 8 )
#define VLVSYS_AGCKVLVOVLPMAX_M_COLS           ( 16 )
#define VLVSYS_FACCMDLIMSCV_M_LNS             ( 8 )
#define VLVSYS_FACCMDLIMSCV_M_COLS             ( 8 )
#define VLVSYS_MFAIRSCVRED_A_COLS              ( 16 )
#define VLVSYS_RFILGAINCLSEXVLV_T_COLS         ( 8 )
#define VLVSYS_RFILGAINOPINVLV_T_COLS          ( 8 )
#define VlvSys_tiSampleFast_SC            10

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

extern const boolean  VlvSys_bAcvBedModLimScv_C;
extern const boolean  VlvSys_bAcvClsExVlvRateLim_C;
extern const boolean  VlvSys_bAcvDftPosLocLop_C;
extern const boolean  VlvSys_bAcvExVlvBedMod_C;
extern const boolean  VlvSys_bAcvInVlvBedMod_C;
extern const boolean  VlvSys_bAcvOpInVlvRateLim_C;
extern const boolean  VlvSys_bAcvTPMBedMod_C;
extern const boolean  VlvSys_bMassAirScvSel_C;
extern const boolean  VlvSys_bPresTrb_C;
extern const sint8  VlvSys_agCkClsExVlvReqRef0Max_C;
extern const sint8  VlvSys_agCkOpInVlvReqRef0Min_C;
extern const uint8  VlvSys_agCkClsExVlvBedMod_C;
extern const uint8  VlvSys_agCkOpInVlvBedMod_C;
extern const uint8  VlvSys_agCkVlvOvlpMax_C;
extern const uint8  VlvSys_agCkVlvOvlpMax_M[VLVSYS_AGCKVLVOVLPMAX_M_LNS][VLVSYS_AGCKVLVOVLPMAX_M_COLS];
extern const sint16  VlvSys_agCkPosnVlvOvlpOfs_C;
extern const sint16  VlvSys_agCkVlvOvlpOfs_C;
extern const uint16  VlvSys_agCkGrdDecClsExVlv_M[VLVSYS_AGCKGRDDECCLSEXVLV_M_LNS][VLVSYS_AGCKGRDDECCLSEXVLV_M_COLS];
extern const uint16  VlvSys_agCkGrdDecOpInVlv_M[VLVSYS_AGCKGRDDECOPINVLV_M_LNS][VLVSYS_AGCKGRDDECOPINVLV_M_COLS];
extern const uint16  VlvSys_agCkGrdIncClsExVlv_M[VLVSYS_AGCKGRDINCCLSEXVLV_M_LNS][VLVSYS_AGCKGRDINCCLSEXVLV_M_COLS];
extern const uint16  VlvSys_agCkGrdIncOpInVlv_M[VLVSYS_AGCKGRDINCOPINVLV_M_LNS][VLVSYS_AGCKGRDINCOPINVLV_M_COLS];
extern const uint16  VlvSys_facCmdLimScv_M[VLVSYS_FACCMDLIMSCV_M_LNS][VLVSYS_FACCMDLIMSCV_M_COLS];
extern const uint16  VlvSys_facTranFilStepAcvServo_C;
extern const uint16  VlvSys_mfAirScvLimMaxBedMod_C;
extern const uint16  VlvSys_mfAirScvRed_A[VLVSYS_MFAIRSCVRED_A_COLS];
extern const uint16  VlvSys_rFilGainClsExVlv_T[VLVSYS_RFILGAINCLSEXVLV_T_COLS];
extern const uint16  VlvSys_rFilGainOpInVlv_T[VLVSYS_RFILGAINOPINVLV_T_COLS];
extern const uint16  VlvSys_rThdLimScv_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvSys_bDetExServoDftPos;
extern boolean VlvSys_bDetInServoDftPos;
extern uint8 VlvSys_agCkClsExVlvAcvCorReq;
extern uint8 VlvSys_agCkOpInVlvAcvCorReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvSys_EveIni_VlvArb(void);
void VlvSys_SdlFast_VlvArb(void);


#endif /* OFSVLV_H */

/*-------------------------------- end of file -------------------------------*/
