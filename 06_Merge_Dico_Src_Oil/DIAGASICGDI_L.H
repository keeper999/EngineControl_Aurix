/***************************************************************************
;**
;** FILE NAME      : DIAGASICGDI_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGASICGDI_L_H
#define DIAGASICGDI_L_H

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

extern const uint8  DIAGASICGDI_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bdftComSpi_Diagasicgdi;
extern boolean Ext_bDftOverVbat_Diagasicgdi;
extern boolean Ext_bDftOverVboost_Diagasicgdi;
extern boolean Ext_bDftUnderVbat_Diagasicgdi;
extern boolean Ext_bDftUnderVboost_Diagasicgdi;
extern boolean Ext_bDftVbat_Diagasicgdi;
extern boolean Ext_bDftVboost_Diagasicgdi;
extern boolean Ext_bDgoAsicGdiFailure;
extern boolean Ext_bMonRunAsicGdiFailure;
extern boolean Ext_bMonRunComSpi_Diagasicgdi;
extern boolean Ext_bMonRunOverVbat_Diagasicgdi;
extern boolean Ext_bMonRunOverVboost_Diagasic;
extern boolean Ext_bMonRunUnderVbat_Diagasicgdi;
extern boolean Ext_bMonRunUnderVboost_Diagasic;
extern boolean Ext_bMonRunVbat_Diagasicgdi;
extern boolean Ext_bMonRunVboost_Diagasicgdi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DIAGASICGDI_vidDiag_ASICGDI(void);


#endif /* DIAGASICGDI_L_H */

/*-------------------------------- end of file -------------------------------*/
