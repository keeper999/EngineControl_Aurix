/***************************************************************************
;**
;** FILE NAME      : DIAGASICGDI.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DIAGASICGDI.H"
#include "DIAGASICGDI_L.H"
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
const uint8  DIAGASICGDI_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bdftComSpi_Diagasicgdi;
boolean Ext_bDftOverVbat_Diagasicgdi;
boolean Ext_bDftOverVboost_Diagasicgdi;
boolean Ext_bDftUnderVbat_Diagasicgdi;
boolean Ext_bDftUnderVboost_Diagasicgdi;
boolean Ext_bDftVbat_Diagasicgdi;
boolean Ext_bDftVboost_Diagasicgdi;
boolean Ext_bDgoAsicGdiFailure;
boolean Ext_bMonRunAsicGdiFailure;
boolean Ext_bMonRunComSpi_Diagasicgdi;
boolean Ext_bMonRunOverVbat_Diagasicgdi;
boolean Ext_bMonRunOverVboost_Diagasic;
boolean Ext_bMonRunUnderVbat_Diagasicgdi;
boolean Ext_bMonRunUnderVboost_Diagasic;
boolean Ext_bMonRunVbat_Diagasicgdi;
boolean Ext_bMonRunVboost_Diagasicgdi;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

