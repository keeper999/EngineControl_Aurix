/***************************************************************************
;**
;** FILE NAME      : HOTSENO2FLG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HOTSENO2FLG_L_H
#define HOTSENO2FLG_L_H

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

extern const uint8  HOTSENO2FLG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HOTSENO2FLG_bInitTimer1Prev;
extern boolean HOTSENO2FLG_bInitTimer2Prev;
extern boolean HOTSENO2FLG_bInitTimer3Prev;
extern boolean HOTSENO2FLG_bInitTimer4Prev;
extern boolean Lshd_dnstr_lbda_sens_hot_prv;
extern boolean LsSys_bLsDsHeatOk;
extern boolean LsSys_bLsUsHeatOk;
extern uint32 HOTSENO2FLG_u32VoltageDsFiltMem;
extern uint32 HOTSENO2FLG_u32VoltageUsFiltMem;
extern uint8 HOTSENO2FLG_u8DsMainOxCHeatPrev;
extern uint8 HOTSENO2FLG_u8UsMainOxCHeatPrev;
extern uint16 LsSys_tiLsDsDlyHeat;
extern uint16 LsSys_tiLsUsDlyHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HOTSENO2FLG_vidDetHotLsDs(void);
void HOTSENO2FLG_vidDetHotLsUS(void);
void HOTSENO2FLG_vidDetHotLsUsdiagOK(void);
void HOTSENO2FLG_vidDetSenO2Ds(void);
void HOTSENO2FLG_vidDetSenO2DsCold(void);
void HOTSENO2FLG_vidDetSenO2DsHot(void);
void HOTSENO2FLG_vidDetSenO2Us(void);
void HOTSENO2FLG_vidDetSenO2UsCold(void);
void HOTSENO2FLG_vidDetSenO2UsHot(void);
void HOTSENO2FLG_vidDsHotdiagFlgInit(void);
void HOTSENO2FLG_vidDsTiStHeatOkdiag(void);
void HOTSENO2FLG_vidHotSenO2Fil(void);
void HOTSENO2FLG_vidHotSenO2Heatst(void);
void HOTSENO2FLG_vidHotSenO2Volt(void);
void HOTSENO2FLG_vidInitCrTR(void);
void HOTSENO2FLG_vidInitEveRst(void);
void HOTSENO2FLG_vidInitHotSenO2DsFlg(void);
void HOTSENO2FLG_vidInitHotSenO2UsFlg(void);
void HOTSENO2FLG_vidInitOutput(void);
void HOTSENO2FLG_vidSenO2DsHot(void);
void HOTSENO2FLG_vidSenO2DsTiStHeat(void);
void HOTSENO2FLG_vidSenO2UsHot(void);
void HOTSENO2FLG_vidSenO2UsTiStHeat(void);
void HOTSENO2FLG_vidUsHotdiagFlgInit(void);
void HOTSENO2FLG_vidUsTiStHeatOkdiag(void);


#endif /* HOTSENO2FLG_L_H */

/*-------------------------------- end of file -------------------------------*/
