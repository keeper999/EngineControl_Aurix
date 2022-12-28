/***************************************************************************
;**
;** FILE NAME      : PWRSEN_ACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PWRSEN_ACQ_L_H
#define PWRSEN_ACQ_L_H

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

extern const uint8  PWRSEN_ACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Pwr_bDgoORng_vMes1;
extern boolean Pwr_bDgoORng_vMes1_Sfty;
extern boolean Pwr_bDgoORng_vMes2;
extern boolean Pwr_bDgoORng_vMes2_Sfty;
extern boolean Pwr_bDgoORng_vMes3;
extern boolean Pwr_bDgoORng_vMes3_Sfty;
extern boolean Pwr_bDgoORng_vMes4;
extern boolean Pwr_bDgoORng_vMes4_Sfty;
extern boolean Pwr_bMonRunORng_vMes1;
extern boolean Pwr_bMonRunORng_vMes1_Sfty;
extern boolean Pwr_bMonRunORng_vMes2;
extern boolean Pwr_bMonRunORng_vMes2_Sfty;
extern boolean Pwr_bMonRunORng_vMes3;
extern boolean Pwr_bMonRunORng_vMes3_Sfty;
extern boolean Pwr_bMonRunORng_vMes4;
extern boolean Pwr_bMonRunORng_vMes4_Sfty;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PWRSEN_ACQ_vidAccP2Cf(void);
void PWRSEN_ACQ_vidAcqDiagVRawMeas1(void);
void PWRSEN_ACQ_vidAcqDiagVRawMeas2(void);
void PWRSEN_ACQ_vidAcqDiagVRawMeas3(void);
void PWRSEN_ACQ_vidAcqDiagVRawMeas4(void);
void PWRSEN_ACQ_vidAcquisition1(void);
void PWRSEN_ACQ_vidAcquisition2(void);
void PWRSEN_ACQ_vidAcquisition3(void);
void PWRSEN_ACQ_vidAcquisition4(void);
void PWRSEN_ACQ_vidAlimAc(void);
void PWRSEN_ACQ_vidAlimAirPts(void);
void PWRSEN_ACQ_vidAlimAps(void);
void PWRSEN_ACQ_vidAlimPmast(void);
void PWRSEN_ACQ_vidAlimSchSdlFastAcq(void);
void PWRSEN_ACQ_vidAlimSchSdlMidAcq(void);
void PWRSEN_ACQ_vidAlimSwitchSdlFast(void);
void PWRSEN_ACQ_vidBoostPresCf(void);
void PWRSEN_ACQ_vidCluPosnCf(void);
void PWRSEN_ACQ_vidDegradModePwSp1Sdf(void);
void PWRSEN_ACQ_vidDegradModePwSp2Sdf(void);
void PWRSEN_ACQ_vidDegradModePwSp3Sdf(void);
void PWRSEN_ACQ_vidDegradModePwSp4Sdf(void);
void PWRSEN_ACQ_vidDetectFailPwSp1Sdf(void);
void PWRSEN_ACQ_vidDetectFailPwSp2Sdf(void);
void PWRSEN_ACQ_vidDetectFailPwSp3Sdf(void);
void PWRSEN_ACQ_vidDetectFailPwSp4Sdf(void);
void PWRSEN_ACQ_vidDiagVRawMes1(void);
void PWRSEN_ACQ_vidDiagVRawMes2(void);
void PWRSEN_ACQ_vidDiagVRawMes3(void);
void PWRSEN_ACQ_vidDiagVRawMes4(void);
void PWRSEN_ACQ_vidExCmCf(void);
void PWRSEN_ACQ_vidInCmCf(void);
void PWRSEN_ACQ_vidInitVEndValMeas1(void);
void PWRSEN_ACQ_vidInitVEndValMeas2(void);
void PWRSEN_ACQ_vidInitVEndValMeas3(void);
void PWRSEN_ACQ_vidInitVEndValMeas4(void);
void PWRSEN_ACQ_vidnEngCf(void);
void PWRSEN_ACQ_vidNeutCf(void);
void PWRSEN_ACQ_vidPfuCf(void);
void PWRSEN_ACQ_vidptOilCf(void);
void PWRSEN_ACQ_vidTrbActCf(void);
void PWRSEN_ACQ_vidVEndValMeas1(void);
void PWRSEN_ACQ_vidVEndValMeas2(void);
void PWRSEN_ACQ_vidVEndValMeas3(void);
void PWRSEN_ACQ_vidVEndValMeas4(void);


#endif /* PWRSEN_ACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
