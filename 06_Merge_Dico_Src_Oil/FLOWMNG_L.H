/***************************************************************************
;**
;** FILE NAME      : FLOWMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FLOWMNG_L_H
#define FLOWMNG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DCM_AEE2004                       1
#define DCM_MAINTENU                      0
#define DML_IMPULSIONNEL                  2
#define DML_MAINTENU                      3

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

extern const uint8  FLOWMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CMMPropSnsrOnly_PTT;
extern boolean CMMPropSnsrOnly_TT;
extern boolean CMMSwtOnly;
extern boolean ESPPropSnsr_CMMPropSnsr;
extern boolean ESPPropSnsr_CMMSwt;
extern boolean Ext_bdftCoBatt;
extern boolean Ext_bPosAT_FrstCases;
extern boolean Fgigb_b_VsctlDiagIniGb;
extern boolean FLOWMNG_bFgigb_T1;
extern boolean FLOWMNG_bFgigb_T2;
extern boolean FLOWMNG_bFgigb_T3;
extern boolean FLOWMNG_bFgigb_T4;
extern boolean FlowMng_bFirstTiCntMng;
extern boolean FLOWMNG_bTime1Out;
extern boolean FLOWMNG_bTime2Out;
extern boolean FLOWMNG_bTimeOut;
extern boolean FLOWMNG_bTimer_prev;
extern boolean FLOWMNG_bTimer1_prev;
extern boolean FLOWMNG_bTimer2_prev;
extern boolean NoCluSnsr;
extern uint32 Ext_ctSecEngStop2004;
extern uint32 Ext_ctSecTot;
extern uint32 Ext_tiCurVeh_prev;
extern uint32 Ext_tiCurVeh2004;
extern uint32 FLOWMNG_u32Ext_ctSec_Prev;
extern uint32 FLOWMNG_u32Ext_ctSec_Prev_2;
extern uint32 FLOWMNG_u32Ext_ctSecEngStop_Prev;
extern uint32 FLOWMNG_u32TiCtctSecStopEng_Prev;
extern uint32 TiCt_ctSecEng;
extern uint32 Tict_nbSec;
extern uint32 TiCt_tiDelta;
extern uint8 FLOWMNG_u8Ext_ctInt;
extern uint8 FLOWMNG_u8Ext_ctInt_prev;
extern uint8 FLOWMNG_u8Ext_ctYr;
extern uint8 FLOWMNG_u8Ext_ctYr_Prev;
extern uint8 FLOWMNG_u8Ext_ctYr_Prev_2;
extern uint8 FLOWMNG_u8Timer;
extern uint8 FLOWMNG_u8Timer1;
extern uint8 FLOWMNG_u8Timer2;
extern uint8 Tra_posnATLevExtSecu_prev;
extern sint16 Ext_tAirExtMesFineResl_prev;
extern uint16 Ext_ctDayTot;
extern uint16 Fgigb_ti_VsctlDiagIniGb;
extern uint16 FLOWMNG_u16Ext_ctDay;
extern uint16 FLOWMNG_u16Ext_ctDay_Prev;
extern uint16 FLOWMNG_u16Ext_ctDay_Prev_2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FLOWMNG_CtCoBatt(void);
void FLOWMNG_vidAlt_Bss_Load_Time(void);
void FLOWMNG_vidAlt_Cpt_Dem_Redem(void);
void FLOWMNG_vidAlt_Current(void);
void FLOWMNG_vidAlt_Duty_Cycle(void);
void FLOWMNG_vidAlt_ID_Supplier(void);
void FLOWMNG_vidAlt_Load_Time(void);
void FLOWMNG_vidAlt_Shut_Off(void);
void FLOWMNG_vidAlt_Voltage(void);
void FLOWMNG_vidAltFlowMng_Init(void);
void FLOWMNG_vidAltFlowMng_Processing(void);
void FLOWMNG_vidBrk_CAN_Info(void);
void FLOWMNG_vidBrkDiagBVH2P(void);
void FLOWMNG_vidBrkHorsDiagBVH2P(void);
void FLOWMNG_vidBrkPush(void);
void FLOWMNG_vidCANSeln(void);
void FLOWMNG_vidClu(void);
void FLOWMNG_vidClu2(void);
void FLOWMNG_vidCtInitUpDate(void);
void FLOWMNG_vidCtInitUpDate2004(void);
void FLOWMNG_vidDAGMP_Traction(void);
void FLOWMNG_vidDay_InitUpDate(void);
void FLOWMNG_vidDay_UpDate(void);
void FLOWMNG_vidDayCtMng(void);
void FLOWMNG_vidDayCtMng_Calc1(void);
void FLOWMNG_vidDayCtMng_Calc2(void);
void FLOWMNG_vidDayCtMng_EEPROM(void);
void FLOWMNG_vidDstVeh(void);
void FLOWMNG_vidFirst_DayCtMng(void);
void FLOWMNG_vidFirstCases(void);
void FLOWMNG_vidFirstDayCtMngInit(void);
void FLOWMNG_vidGMV(void);
void FLOWMNG_vidHorsDiagBVH2P_ABS(void);
void FLOWMNG_vidInit_EEPROM(void);
void FLOWMNG_vidInit_InitUpDate(void);
void FLOWMNG_vidInit_UpDate(void);
void FLOWMNG_vidInitOutput(void);
void FLOWMNG_vidLoFuPmp(void);
void FLOWMNG_vidOil(void);
void FLOWMNG_vidOutput_GBxLev1(void);
void FLOWMNG_vidOutput_GBxLev2(void);
void FLOWMNG_vidOutput_posnGBxLev(void);
void FLOWMNG_vidPMastervac(void);
void FLOWMNG_vidPosGearLev(void);
void FLOWMNG_vidPosGearSel(void);
void FLOWMNG_vidPosGearTempo(void);
void FLOWMNG_vidSec_InitUpDate(void);
void FLOWMNG_vidSec_UpDate(void);
void FLOWMNG_vidTemporisation(void);
void FLOWMNG_vidTExtMng(void);
void FLOWMNG_vidTOilMng(void);
void FLOWMNG_vidTqSel(void);
void FLOWMNG_vidUpDate2004(void);
void FLOWMNG_vidYr_InitUpDate(void);
void FLOWMNG_vidYr_UpDate(void);


#endif /* FLOWMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
