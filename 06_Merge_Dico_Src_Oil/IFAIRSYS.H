/***************************************************************************
;**
;** FILE NAME      : IFAIRSYS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFAIRSYS_H
#define IFAIRSYS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CrkMgt_stStrtArIni_SC             2
#define INJSYS_PRM_BINJCUTOFFCYL_COLS          ( 6 )

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

extern const uint8  Ext_nEngGrdGain_C;

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

void AccP_SdlFast_StIf(void);
void AirPres_Eve14TDC_SpgPresAcqif(void);
void AirPres_EveRst_SpgPresAcqif(void);
void AirPres_SdlMid_SpgPresAcqif(void);
void AirSys_SdlFast_nEngGrdIf(void);
void AirT_EveRst_AcqAirTIfAir(void);
void AirT_SdlMid_AcqAirTIfAir(void);
void CrkMgt_EveRst_AirTqStructMngtIf(void);
void Crkmgt_sdlFast_tqStructMngtIf(void);
void Crkmgt_sdlFast_tqStructMngtIf2(void);
void EngSt_EveRst_EngrunStIfAir(void);
void EngSt_SdlFast_EngrunStIfAir(void);
void IFAIRSYS_vidEntryInit(void);
void Inj_EveRst_FuTiRunIf2(void);
void Inj_SdlFast_FuTiRunIf2(void);
void Sync_EveRst_CkMngIfIfAir(void);
void Thr_EveClcnServo_CorrdPosnIf2(void);
void VehSpd_SdlFast_VehMngIf(void);


#endif /* IFAIRSYS_H */

/*-------------------------------- end of file -------------------------------*/
