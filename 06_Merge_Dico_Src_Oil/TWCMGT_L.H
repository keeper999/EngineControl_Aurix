/***************************************************************************
;**
;** FILE NAME      : TWCMGT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TWCMGT_L_H
#define TWCMGT_L_H

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

extern const uint8  TWCMGT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TWCMgt_bAcvHeatPha;
extern boolean TWCMGT_bAcvHeatPhaPrev;
extern boolean TWCMgt_bAcvNEngAcvCdn;
extern boolean TWCMgt_bAcvNEngBegCdnAcv;
extern boolean TWCMgt_bAfterEngStrtReqCdn;
extern boolean TWCMGT_bBasculRS1;
extern boolean TWCMgt_bDeacHeatPha;
extern boolean TWCMGT_bDeacHeatPhaPrev;
extern boolean TWCMGT_bInGearIdlTurnOnPrev;
extern boolean TWCMGT_bInHeatPhaTurnOnPrev;
extern boolean TWCMGT_bIntiDlyPha3TurnOnPrev;
extern boolean TWCMGT_bInTWCHeatTurnOnPrev;
extern boolean TWCMGT_bInTWCLiOffTurnOnPrev;
extern boolean TWCMgt_bLiOffClcAuth;
extern boolean TWCMgt_bLiOffDonePrev;
extern boolean TWCMGT_bLsMonbEndMonResHeatPrev;
extern boolean TWCMGT_bMonMisfbClcMisfOBDPrev;
extern boolean TWCMGT_bOutGearIdlTurnOnDelay;
extern boolean TWCMGT_bOutHeatPhaTurnOnDelay;
extern boolean TWCMGT_bOuttiDlyPha3TurnOnDelay;
extern boolean TWCMGT_bOutTurnOnDelay;
extern boolean TWCMGT_bOutTWCHeatTurnOnDelay;
extern boolean TWCMGT_bOutTWCLiOffTurnOnDelay;
extern boolean TWCMGT_bOxCbEndMonORngItrsvPrev;
extern boolean TWCMGT_bRstETBTiPha1Prev;
extern boolean TWCMgt_bTCoAr;
extern boolean TWCMgt_bTWCHeatPha3Acv;
extern boolean TWCMgt_bTWCHeatReq;
extern boolean TWCMgt_bTWCHeatReqPrev;
extern boolean TWCMGT_bTWCHeatReqPrev2;
extern boolean TWCMgt_bTWCMinStrtCdnReq;
extern boolean TWCMGT_bTWCMinStrtCdnReqPrev;
extern uint32 TWCMGT_u32FilterKMem;
extern uint8 TWCMgt_stHeatPhaReqBas;
extern uint8 TWCMgt_stTrbActPosnReqBas;
extern uint16 TWCMgt_dstVehMesLoResl_MP;
extern uint16 TWCMgt_tiHiTWCCurEstim_MP;
extern uint16 TWCMgt_tiHiTWCHiAr;
extern uint16 TWCMgt_tiHiTWCHiArPrev;
extern uint16 TWCMgt_tiLiOff;
extern uint16 TWCMgt_tiLiOffHeatDeac;
extern uint16 TWCMgt_tiLiOffNormCdn;
extern uint16 TWCMgt_tiOutStg_MP;
extern uint16 TWCMgt_tiPha1Km;
extern uint16 TWCMgt_tiPha1Misf;
extern uint16 TWCMgt_tiPhaO2Stg;
extern uint16 TWCMgt_tiPhaRatEfcLsUsPer;
extern uint16 TWCMgt_tiResLsUsHeat;
extern uint16 TWCMgt_tiTWC;
extern uint16 TWCMGT_u16AcvCdnAcvCount;
extern uint16 TWCMGT_u16GearIdlCount;
extern uint16 TWCMGT_u16HeatPhaCount;
extern uint16 TWCMGT_u16InputdstVehTiPha1Km;
extern uint16 TWCMGT_u16InputTtiHeatCaseDeac;
extern uint16 TWCMGT_u16OutPassFilterK;
extern uint16 TWCMGT_u16tiDlyPha3Count;
extern uint16 TWCMGT_u16tiLiOffOutMem;
extern uint16 TWCMGT_u16TWCHeatCount;
extern uint16 TWCMGT_u16TWCLiOffCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TWCMGT_VidAuthorizeActivCondCalc(void);
void TWCMGT_VidAuthorizeLightOffCompt(void);
void TWCMGT_VidCheckActivationCond(void);
void TWCMGT_VidCheckDeactivationCond(void);
void TWCMGT_VidCheckTheEveryTimeActCd(void);
void TWCMGT_VidCheckTheOnceActivCond(void);
void TWCMGT_VidCount_Light_Off_Time(void);
void TWCMGT_VidEstimAndSaveTimOfPhas1(void);
void TWCMGT_VidEstimate_Phase_Time_1(void);
void TWCMGT_VidEstNormCondLightOffTim(void);
void TWCMGT_VidInitOutput(void);
void TWCMGT_VidInitThreeWayCatHeatMng(void);
void TWCMGT_VidManage_Light_Off(void);
void TWCMGT_VidManage_Output(void);
void TWCMGT_VidManageActivationCond(void);
void TWCMGT_VidManageLightOff(void);
void TWCMGT_VidManageThresholdPhase3(void);
void TWCMGT_VidMng_Progressive_Heat(void);
void TWCMGT_VidMngActivAndDeactivCond(void);
void TWCMGT_VidMngHeatAuthorization(void);
void TWCMGT_VidMngWaste_Gate_Position(void);
void TWCMGT_VidSaveAndInitPhaseTime1(void);
void TWCMGT_VidSelect_Phase(void);
void TWCMGT_VidThreeWayCatHeatMngVal(void);
void TWCMGT_VidTWCEstHeatDeactLgOfTim(void);


#endif /* TWCMGT_L_H */

/*-------------------------------- end of file -------------------------------*/
