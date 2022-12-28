/***************************************************************************
;**
;** FILE NAME      : PFCMNG.H
;**
;** FILE AUTHOR    : MBENFRADJ	 (VEES)
;**
;**************************************************************************/

#ifndef PFCMNG_H
#define PFCMNG_H

#include "STD_TYPES.h"
#include "WDGM.H"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define WDGM_NB_SEID                      1            /* 1 */

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  WDGM_NB_CHECKPOINT;
extern const uint8  WDGM_TIMEOUT;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean Sfty_bDgoSftyChkPt_PfcMng;
extern boolean Sfty_bMonRunSftyChkPt_PfcMng;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void Sfty_EveRst_PfcMng(void);
void Sfty_SdlMid_PfcMng(void);
void Sfty_SdlMid_PfcMng_Chk(WdgM_SupervisedEntityIdType u8LocalSEID,WdgM_CheckpointIdType u16LocalCheckpointID);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PFCMNG_H */

/*-------------------------------- end of file -------------------------------*/
