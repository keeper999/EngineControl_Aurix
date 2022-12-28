/***************************************************************************
;**
;** FILE NAME      : NEUTPOSNACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef NEUTPOSNACQ_H
#define NEUTPOSNACQ_H

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

extern const boolean  Ext_bNeutFault_C;
extern const uint8  NeutPosnAcq_nDecCpt_ORng_C;
extern const uint8  NeutPosnAcq_nDecCpt_Scg_C;
extern const uint8  NeutPosnAcq_nDecCpt_Scp_C;
extern const uint8  NeutPosnAcq_nDownTranThd_ORng_C;
extern const uint8  NeutPosnAcq_nDownTranThd_Scg_C;
extern const uint8  NeutPosnAcq_nDownTranThd_Scp_C;
extern const uint8  NeutPosnAcq_nInitCptConf_ORng_C;
extern const uint8  NeutPosnAcq_nInitCptConf_Scg_C;
extern const uint8  NeutPosnAcq_nInitCptConf_Scp_C;
extern const uint8  NeutPosnAcq_nUpTranThd_ORng_C;
extern const uint8  NeutPosnAcq_nUpTranThd_Scg_C;
extern const uint8  NeutPosnAcq_nUpTranThd_Scp_C;
extern const uint16  Ext_frqMaxNeut_C;
extern const uint16  Ext_frqMinNeut_C;
extern const uint16  Ext_rDgoScg_bNeut_C;
extern const uint16  Ext_rDgoScp_bNeut_C;
extern const uint16  Ext_rThdNeut1_C;
extern const uint16  Ext_rThdNeut2_C;
extern const uint16  Ext_rThdNeut3_C;
extern const uint16  Ext_rThdNeut4_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean NeutPosnAcq_bDftSftyORng_bNeut;
extern boolean NeutPosnAcq_bDftSftyScg_bNeut;
extern boolean NeutPosnAcq_bDftSftyScp_bNeut;
extern uint8 Ext_tiPerNeut;
extern uint16 Ext_rNeut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Gear_EveRst_NeutPosnAcq(void);
void Gear_SdlFast_NeutPosnAcq(void);
void NeutPosnAcq_SdlSfty_SftyLvl2(void);


#endif /* NEUTPOSNACQ_H */

/*-------------------------------- end of file -------------------------------*/
