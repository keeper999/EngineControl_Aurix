/***************************************************************************
;**
;** FILE NAME      : ACQADC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQADC_H
#define ACQADC_H

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

void AC_EveRst_ACPresAcqAdc(void);
void AC_SdlFast_ACPresAcqAdc(void);
void AccP_EveRst_AcqPosnAdc(void);
void AccP_SdlFast_AcqPosnAdc(void);
void AccP_SdlFast_SwtAcqDiagAdc(void);
void AirPres_Eve14TDC_InMnfPresAcqAdc(void);
void AirPres_SdlFast_AirExtPresAcqAdc(void);
void AirPres_SdlFast_BrkAsiAcqAdc(void);
void AirPres_SdlFast_InMnfPresDiagAdc(void);
void AirPres_SdlFast_RelBrkAsiAcqAdc(void);
void AirPres_SdlMid_InMnfPresAcqAdc(void);
void AirPres_SdlSlow_AirExtPresAcqAdc(void);
void AirT_EveRst_AcqAirTAdc(void);
void AirT_SdlMid_AcqAirTAdc(void);
void CoT_EveRst_AcqCoTAdc(void);
void CoT_EveStTR_AcqCoTAdc(void);
void CoT_SdlMid_AcqCoTAdc(void);
void EngSt_SdlFast_DftStaCmdAdc(void);
void Ext_EveRst_AcqAdc(void);
void HeatSenO2_SdlFast_DrvrSenO2DsAdc(void);
void HeatSenO2_SdlFast_DrvrSenO2UsAdc(void);
void Pwr_EveInj_BattVotlAcqAdc(void);
void Pwr_EveRst_AcqAdc(void);
void Pwr_EveRst_BattVoltAcqAdc(void);
void Pwr_Sdl2ms_BattVotlAcqAdc(void);
void Pwr_SdlFast_AcqAdc(void);
void Pwr_SdlFast_BattVoltAcqAdc(void);
void Pwr_SdlMid_AcqAdc(void);
void SenO2Ds_SdlFast_DsLsAcqAdc(void);
void SenO2Us_SdlFast_UpLsAcqAdc(void);
void Thr_EveClcnServo_AcqAdcThr(void);
void Thr_EveRst_AcqAdcThr(void);


#endif /* ACQADC_H */

/*-------------------------------- end of file -------------------------------*/
