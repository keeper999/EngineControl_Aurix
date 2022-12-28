/***************************************************************************
;**
;** FILE NAME      : WGCCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGCCMD_H
#define WGCCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define WGCCMD_FRQTRBACT_RCTL_T_COLS           ( 24 )
#define WGCCMD_NENG_A_COLS                     ( 24 )

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

extern const boolean  Ext_bAcv_Trb_rCtlBattCor_C;
extern const boolean  Ext_bAcv_Trb_rCtlCurCor_C;
extern const uint16  Ext_resLoSideTrb_C;
extern const uint16  WgcCmd_frqTrbAct_rCtl_T[WGCCMD_FRQTRBACT_RCTL_T_COLS];
extern const uint16  WgcCmd_nEng_A[WGCCMD_NENG_A_COLS];
extern const uint16  WgcCmd_TrbAct_DrvMax_C;
extern const uint16  WgcCmd_TrbAct_DrvMin_C;

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

void Wg_EveRst_WgcCmd(void);
void Wg_SdlMid_WgcCmd(void);


#endif /* WGCCMD_H */

/*-------------------------------- end of file -------------------------------*/
