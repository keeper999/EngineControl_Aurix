/***************************************************************************
;**
;** FILE NAME      : WGCCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef WGCCMD_L_H
#define WGCCMD_L_H

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

extern const uint8  WgcCmd_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Wg_bDgoHi_WgcCmd;
extern boolean Wg_bDgoLo_WgcCmd;
extern boolean Wg_bMonRunHi_WgcCmd;
extern boolean Wg_bMonRunLo_WgcCmd;
extern uint8 Ext_uBattMes_Filt;
extern sint16 Ext_TrbAct_rCtlCor;
extern sint16 WGCCMD_s16Ext_uBattMesPrev;
extern uint16 Ext_TrbAct_rCtl;
extern uint16 Ext_TrbAct_rCtlLim;
extern uint16 Ext_uTrbAct;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void WgcCmd_vidBat_Volt_Filtering(void);
void WgcCmd_vidDiagnostic(void);
void WgcCmd_vidDuty_cycle_conversion(void);
void WgcCmd_vidInitOutput(void);
void WgcCmd_vidP_Trb_PwrSup_calcul(void);
void WgcCmd_vidRequest_CorrecLimit(void);
void WgcCmd_vidWgcCmdApplication(void);
void WgcCmd_vidWgcTreatment(void);


#endif /* WGCCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
