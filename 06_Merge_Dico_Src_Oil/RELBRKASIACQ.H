/***************************************************************************
;**
;** FILE NAME      : RELBRKASIACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RELBRKASIACQ_H
#define RELBRKASIACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_PRELBRKASI_T_COLS              ( 2 )
#define AIRPRES_URELBRKASI_A_COLS              ( 2 )

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

extern const uint8  AirPres_nDecCpt_ScgRelBrkAsi_C;
extern const uint8  AirPres_nDecCpt_ScpRelBrkAsi_C;
extern const uint8  AirPres_nDownTranThd_ScgRelAsi_C;
extern const uint8  AirPres_nDownTranThd_ScpRelAsi_C;
extern const uint8  AirPres_nInitCptConf_ScgRelAsi_C;
extern const uint8  AirPres_nInitCptConf_ScpRelAsi_C;
extern const uint8  AirPres_noAcvGrdDiag_C;
extern const uint8  AirPres_nUpTranThd_ScgRelAsi_C;
extern const uint8  AirPres_nUpTranThd_ScpRelAsi_C;
extern const uint8  AirPres_pRelBrkAsi_T[AIRPRES_PRELBRKASI_T_COLS];
extern const uint8  Ext_pRelBrkAsiIni_C;
extern const uint8  Ext_pRelBrkAsiRcv_C;
extern const uint16  AirPres_uRelBrkAsi_A[AIRPRES_URELBRKASI_A_COLS];
extern const uint16  Ext_facRelBrkAsiFilCoef_C;
extern const uint16  Ext_uDgoGrd_pRelBrkAsi_C;
extern const uint16  Ext_uDgoScg_pRelBrkAsi_C;
extern const uint16  Ext_uDgoScp_pRelBrkAsi_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirPres_bDftSftyScg_pRelBrkAsi;
extern boolean AirPres_bDftSftyScp_pRelBrkAsi;
extern uint8 Ext_pRelBrkAsiMes;
extern uint8 Ext_pRelBrkAsiMesSI;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_EveRst_RelBrkAsiAcq(void);
void AirPres_SdlFast_RelBrkAsiAcq(void);
void AirPres_SdlSfty_RelBrkAsiAcq(void);


#endif /* RELBRKASIACQ_H */

/*-------------------------------- end of file -------------------------------*/
