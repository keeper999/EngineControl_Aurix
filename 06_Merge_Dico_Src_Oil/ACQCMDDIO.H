/***************************************************************************
;**
;** FILE NAME      : ACQCMDDIO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQCMDDIO_H
#define ACQCMDDIO_H

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

void Brk_SdlMid_DiagBrkPedDio(void);
void Clu_SdlFast_AcqnCluPedDio(void);
void CoFan_SdlMid_AcqCmdCoFan(void);
void EcuSt_SdlFast_AcqWkuSigDio(void);
void EngSt_EveRst_AuthStrtSTTDio(void);
void EngSt_EveRst_EngStOutIdcDio(void);
void EngSt_SdlFast_AuthStrtSTTDio(void);
void EngSt_SdlFast_EngStOutIdcDio(void);
void Ext_EveRst_AcqCmdDio(void);
void Gear_SdlFast_StrtLockAcqDio(void);
void HeatSenO2_EveKOf_DrvrSenO2DsDio(void);
void HeatSenO2_EveKOf_DrvrSenO2UsDio(void);
void HeatSenO2_SdlFast_DrvrSenO2DsDio(void);
void HeatSenO2_SdlFast_DrvrSenO2UsDio(void);
void Oil_SdlMid_OilPresAcqDio(void);
void Oil_SdlSlow_BlowByCmdDio(void);
void Pwr_SdlMid_VoltHldDevDio(void);
void PwrlRly_EveKOf_IfCmdDiagDio(void);
void PwrlRly_EveKOn_IfCmdDiagDio(void);
void PwrlRly_EveRst_IfCmdDiagDio(void);
void PwrlRly_EveRxnIdDaRcdDmlDio(void);
void PwrlRly_SdlMid_IfCmdDiagDio(void);
void PwrRly_EveCkOn_IfCmdDiagDio(void);
void PwrRly_EveKOn_IfCmdDiagDio(void);
void PwrRly_EveRst_IfCmdDiagDio(void);
void PwrRly_SdlMid_IfCmdDiagDio(void);
void Strtr_EveRst_IfCmdDiagDio(void);
void Strtr_SdlMid_IfCmdDiagDio(void);
void STT_SdlFast_KeyPushInfoDio(void);


#endif /* ACQCMDDIO_H */

/*-------------------------------- end of file -------------------------------*/
