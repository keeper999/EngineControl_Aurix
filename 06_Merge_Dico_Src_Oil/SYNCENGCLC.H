/***************************************************************************
;**
;** FILE NAME      : SYNCENGCLC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCENGCLC_H
#define SYNCENGCLC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define NB_ACTIVE_ZONE                    20

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

extern const sint8  Sync_MaxCorBody1_C;
extern const sint8  Sync_MaxCorBody2_C;
extern const sint8  Sync_MaxCorBody3_C;
extern const sint8  Sync_MaxCorBody4_C;
extern const sint8  Sync_MaxCorBody5_C;
extern const uint8  Sync_no_GearLrnCornEngClc_C;
extern const uint8  Sync_NrSampleMin_C;
extern const uint8  Sync_ThdCorHys_C;
extern const uint8  Sync_TiCutOffLrnCornEngClc_C;
extern const sint16  Sync_tCo_LrnCornEngClc_C;
extern const uint16  Sync_ThdMvCorMin_C;
extern const uint16  Sync_ThdnEngClcMax_C;
extern const uint16  Sync_ThdnEngClcMin_C;

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

void Sync_EveBDC_NEngClc(void);
void Sync_EveRst_NEngClc(void);
void Sync_EveTDC_NEngClc(void);
void Sync_EveWrAdaptSpdTar_NEngClc(void);
void Sync_SdlMid_NEngClc(void);
void Sync_SdlSlow_NEngClc(void);


#endif /* SYNCENGCLC_H */

/*-------------------------------- end of file -------------------------------*/
