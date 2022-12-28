/***************************************************************************
;**
;** FILE NAME      : ACQCMDDIO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQCMDDIO_L_H
#define ACQCMDDIO_L_H

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

extern const uint8  ACQCMDDIO_u8Inhib;

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

void ACQCMDDIO_vidAcqCmdCoFan(void);
void ACQCMDDIO_vidAcqDioBrk(void);
void ACQCMDDIO_vidAcqDioClu(void);
void ACQCMDDIO_vidAcqDioCoFan(void);
void ACQCMDDIO_vidAcqDioCoFanB1(void);
void ACQCMDDIO_vidAcqDioCoFanB2(void);
void ACQCMDDIO_vidAcqDioGear(void);
void ACQCMDDIO_vidAcqDioKey(void);
void ACQCMDDIO_vidAcqDioOil(void);
void ACQCMDDIO_vidAcqDioSTT(void);
void ACQCMDDIO_vidAuthStrtSTT(void);
void ACQCMDDIO_vidBlowBy1(void);
void ACQCMDDIO_vidBlowBy2(void);
void ACQCMDDIO_vidCmdDioCoFanB1(void);
void ACQCMDDIO_vidCmdDioCoFanB2(void);
void ACQCMDDIO_vidCmdDioPwr(void);
void ACQCMDDIO_vidFCmdDml(void);
void ACQCMDDIO_vidInit(void);
void ACQCMDDIO_vidInitCoFan(void);
void ACQCMDDIO_vidMainRly(void);
void ACQCMDDIO_vidOutpIdc(void);
void ACQCMDDIO_vidPowerRly(void);
void ACQCMDDIO_vidSenO2Ds(void);
void ACQCMDDIO_vidSenO2Us(void);


#endif /* ACQCMDDIO_L_H */

/*-------------------------------- end of file -------------------------------*/
