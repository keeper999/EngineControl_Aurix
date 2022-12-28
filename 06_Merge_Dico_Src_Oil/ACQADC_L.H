/***************************************************************************
;**
;** FILE NAME      : ACQADC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQADC_L_H
#define ACQADC_L_H

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

extern const uint8  ACQADC_u8Inhib;

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

void ACQADC_vidAcqAdcAccP1(void);
void ACQADC_vidAcqAdcAccP2(void);
void ACQADC_vidAcqAdcAirT(void);
void ACQADC_vidAcqAdcAlim(void);
void ACQADC_vidAcqAdcBatt(void);
void ACQADC_vidAcqAdcCoT(void);
void ACQADC_vidAcqAdcEngSt(void);
void ACQADC_vidAcqAdcPresAC(void);
void ACQADC_vidAcqAdcThr(void);
void ACQADC_vidAcqSenO2Ds(void);
void ACQADC_vidAcqSenO2Us(void);
void ACQADC_vidAirExtPresAcq(void);
void ACQADC_vidBrkAsiAcq(void);
void ACQADC_vidHeatSenO2Ds(void);
void ACQADC_vidHeatSenO2Us(void);
void ACQADC_vidInit(void);
void ACQADC_vidInMnfPresAcq(void);
void ACQADC_vidRelBrkAsiAcq(void);


#endif /* ACQADC_L_H */

/*-------------------------------- end of file -------------------------------*/
