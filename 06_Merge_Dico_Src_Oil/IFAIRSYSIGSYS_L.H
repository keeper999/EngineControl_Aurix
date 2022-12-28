/***************************************************************************
;**
;** FILE NAME      : IFAIRSYSIGSYS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFAIRSYSIGSYS_L_H
#define IFAIRSYSIGSYS_L_H

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

extern const uint8  IFAIRSYSIGSYS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IFAIRSYSIGSYS_vidAFAInit(void);
void IFAIRSYSIGSYS_vidAFASyncIf(void);
void IFAIRSYSIGSYS_vidAFAThrIf(void);
void IFAIRSYSIGSYS_vidAntiFlood(void);
void IFAIRSYSIGSYS_vidBattVolt(void);
void IFAIRSYSIGSYS_vidCkMngIf(void);
void IFAIRSYSIGSYS_vidCmdCoFan(void);
void IFAIRSYSIGSYS_vidCptrTempsEcuSt(void);
void IFAIRSYSIGSYS_vidCptrTempsEngSt(void);
void IFAIRSYSIGSYS_vidCstr(void);
void IFAIRSYSIGSYS_vidCtTDC(void);
void IFAIRSYSIGSYS_vidDetInstMisf(void);
void IFAIRSYSIGSYS_vidDiag_Trim(void);
void IFAIRSYSIGSYS_vidDsLsAcqIf(void);
void IFAIRSYSIGSYS_vidDuree_Fctmt(void);
void IFAIRSYSIGSYS_vidECU(void);
void IFAIRSYSIGSYS_vidECU1(void);
void IFAIRSYSIGSYS_vidEndDiagDsHeat(void);
void IFAIRSYSIGSYS_vidFrstCrk(void);
void IFAIRSYSIGSYS_vidFuTnk(void);
void IFAIRSYSIGSYS_vidInit_tOil(void);
void IFAIRSYSIGSYS_vidInitOutput(void);
void IFAIRSYSIGSYS_vidInjCtlIf2(void);
void IFAIRSYSIGSYS_vidInjCtlIf3(void);
void IFAIRSYSIGSYS_vidInjrMSys1(void);
void IFAIRSYSIGSYS_vidInputVlvActExIf(void);
void IFAIRSYSIGSYS_vidInputVlvActInIf(void);
void IFAIRSYSIGSYS_vidInterfacCstrIf(void);
void IFAIRSYSIGSYS_vidInterfacCstrIf1(void);
void IFAIRSYSIGSYS_vidInterfEngStrt(void);
void IFAIRSYSIGSYS_vidInterfISLin(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf1(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf14(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf15(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf16(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf17(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf2(void);
void IFAIRSYSIGSYS_vidIntfacIsCanIf5(void);
void IFAIRSYSIGSYS_vidISLinInterf(void);
void IFAIRSYSIGSYS_vidKnk(void);
void IFAIRSYSIGSYS_vidmFuSpIf(void);
void IFAIRSYSIGSYS_vidMFuTranCor(void);
void IFAIRSYSIGSYS_vidOutAmbPressEep(void);
void IFAIRSYSIGSYS_vidOutAtmphPress(void);
void IFAIRSYSIGSYS_vidOutbCtlPmpReq(void);
void IFAIRSYSIGSYS_vidOutbElecltgr(void);
void IFAIRSYSIGSYS_vidOutBrakePedInp(void);
void IFAIRSYSIGSYS_vidOutEngStopAuth(void);
void IFAIRSYSIGSYS_vidOutfacVlvOvlp(void);
void IFAIRSYSIGSYS_vidOutFHCanF4F2AV(void);
void IFAIRSYSIGSYS_vidOutFHCanF7F2AV(void);
void IFAIRSYSIGSYS_vidOutInjCutOffPtl(void);
void IFAIRSYSIGSYS_vidOutMainOxCEstim(void);
void IFAIRSYSIGSYS_vidOutMaxPrevAdpCy(void);
void IFAIRSYSIGSYS_vidOutN3F34DPM1413(void);
void IFAIRSYSIGSYS_vidOutNotAvlBatMes(void);
void IFAIRSYSIGSYS_vidOutOCHeatPhaReq(void);
void IFAIRSYSIGSYS_vidOutput_bStaReq(void);
void IFAIRSYSIGSYS_vidOutput_bTqReq(void);
void IFAIRSYSIGSYS_vidOutput_iBattMes(void);
void IFAIRSYSIGSYS_vidOutput_IdlLim(void);
void IFAIRSYSIGSYS_vidOutput_nEng(void);
void IFAIRSYSIGSYS_vidOutput_OxC(void);
void IFAIRSYSIGSYS_vidOutput_pFuMes(void);
void IFAIRSYSIGSYS_vidOutput_tFuMes(void);
void IFAIRSYSIGSYS_vidOutput_tiAst(void);
void IFAIRSYSIGSYS_vidOutput_tOilChk(void);
void IFAIRSYSIGSYS_vidOutput_tOilMes(void);
void IFAIRSYSIGSYS_vidOutputbDft(void);
void IFAIRSYSIGSYS_vidOutputCrash(void);
void IFAIRSYSIGSYS_vidOutputFHCanF572(void);
void IFAIRSYSIGSYS_vidOutputGearRatio(void);
void IFAIRSYSIGSYS_vidOutputInMnfReq(void);
void IFAIRSYSIGSYS_vidOutputLoad(void);
void IFAIRSYSIGSYS_vidOutputObdSrv(void);
void IFAIRSYSIGSYS_vidOutputpAC(void);
void IFAIRSYSIGSYS_vidOutputStrtEnd(void);
void IFAIRSYSIGSYS_vidOutputThMgt(void);
void IFAIRSYSIGSYS_vidOutSlaveWkuReq(void);
void IFAIRSYSIGSYS_vidPhyM(void);
void IFAIRSYSIGSYS_vidrapEngaMeca349(void);
void IFAIRSYSIGSYS_vidSTTIf(void);
void IFAIRSYSIGSYS_vidTDsThr(void);
void IFAIRSYSIGSYS_vidtEcuAct(void);
void IFAIRSYSIGSYS_vidTqCurSfty(void);
void IFAIRSYSIGSYS_vidTqRes(void);
void IFAIRSYSIGSYS_vidTqSys(void);
void IFAIRSYSIGSYS_vidTqSys_2(void);


#endif /* IFAIRSYSIGSYS_L_H */

/*-------------------------------- end of file -------------------------------*/
