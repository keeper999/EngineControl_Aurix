/***************************************************************************
;**
;** FILE NAME      : ACQDGOHAL_DT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQDGOHAL_DT_L_H
#define ACQDGOHAL_DT_L_H

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

extern const uint8  ACQDGOHAL_DT_u8Inhib;

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

void ACQDGOHAL_DT_vidDgoHalASICGDI(void);
void ACQDGOHAL_DT_vidDgoHalCmdWgc(void);
void ACQDGOHAL_DT_vidDgoHalCtlPmpReq(void);
void ACQDGOHAL_DT_vidDgoHalCTP(void);
void ACQDGOHAL_DT_vidDgoHalDmpVlvCmd(void);
void ACQDGOHAL_DT_vidDgoHalInit(void);
void ACQDGOHAL_DT_vidDgoHalOilLvlAcq(void);
void ACQDGOHAL_DT_vidDgoHalTrbWaPmp(void);
void ACQDGOHAL_DT_vidDgoHlHPPmpActCmd(void);


#endif /* ACQDGOHAL_DT_L_H */

/*-------------------------------- end of file -------------------------------*/
