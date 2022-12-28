/***************************************************************************
;**
;** FILE NAME      : LAYERSYNC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef LAYERSYNC_H
#define LAYERSYNC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COUNTER_EDGECK_MAX                255
#define ENGINE_POSITION_MAX               720
#define ENGINE_ROTATION_DIR               0
#define LAYERSYNC_u8MAX_TAB_SIZE          5
#define TIME_CGT_MAX                      5000000
#define TIME_CGTLST_MAX                   5000000

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

extern const boolean  Sync_bEnaFastSync_C;
extern const uint8  Sync_nAcvAgEng_C;
extern const uint8  Sync_nEngThdDiBwdRot_C;
extern const uint8  Sync_noMaxTableSize_C;

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

void Sync_EveBDC_AcqCkMngIf(void);
void Sync_EveCkLTo_AcqSyncSTT(void);
void Sync_EveCkOff_AcqSyncSTT(void);
void Sync_EveCkSnOf_AcqSyncSTT(void);
void Sync_EveCkSnOn_AcqCkMngIf(void);
void Sync_EveCkTo_AcqSyncSTT(void);
void Sync_EveExCamEdge_AcqSyncSTT(void);
void Sync_EveExCmToo_AcqExCmSts(void);
void Sync_EveInCamEdge_AcqSyncSTT(void);
void Sync_EveInCmToo_AcqInCmSts(void);
void Sync_EveKOn_AcqCkMngIf(void);
void Sync_EveNInvOff_AcqSyncSTT(void);
void Sync_EveRst_AcqSyncSTT(void);
void Sync_EveRst_ExCmStsIf(void);
void Sync_EveRst_InCmStsIf(void);
void Sync_EveStTR_AcqCkMngIf(void);
void Sync_EveSyncAccu_AcqSyncSTT(void);
void Sync_EveTDC_AcqCkMngIf(void);
void Sync_EveTestEnd_AcqCkMngIf(void);
void Sync_SdlFast_AcqCkMngIf(void);
void Sync_SdlMid_AcqSyncSTT(void);
void Sync_SdlSlow_AcqExCmSts(void);
void Sync_SdlSlow_AcqInCmSts(void);
void VlVAct_EveExCmToo_AcqVlVActPos(void);
void VlVAct_EveInCmToo_AcqVlVActPos(void);
void VlvAct_EveRst_AcqVlVActPos(void);


#endif /* LAYERSYNC_H */

/*-------------------------------- end of file -------------------------------*/
