/***************************************************************************
;**
;** FILE NAME      : ADCHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADCHAL_L_H
#define ADCHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADCHAL_Cfg.h"
#include "ADCHAL_Typ_Cfg.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ADCHAL_AKPFU32SCALINGFUNCTION_COLS     ( 37 )
#define ADCHAL_AKPFVIDREADRAW_COLS             ( 40 )
#define ADCHAL_AKUDTCHANNELTOPIN_COLS          ( 37 )
#define ADCHAL_AKUDTRESULTDESIREDMAX_COLS      ( 37 )
#define ADCHAL_AUDTACQUISITIONSRAW_COLS        ( 40 )
#define ADCHAL_udtNUMBER_OF_CHANNELS      37
#define ADCHAL_udtNUMBER_OF_PINS          40

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

Std_ReturnType ADCHAL_udtPrivateDisableNotification(ADCHAL_tudtChannelType udtChannel);
Std_ReturnType ADCHAL_udtPrivateEnableNotification(ADCHAL_tudtChannelType udtChannel);
Std_ReturnType ADCHAL_udtPrivateRead(ADCHAL_tudtChannelType udtChannel, ADCHAL_tudtResultValue  *pudtResultValue);


#endif /* ADCHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
