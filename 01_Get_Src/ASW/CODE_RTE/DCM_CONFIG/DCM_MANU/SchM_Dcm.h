/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : SchM_Dcm.h                                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : SchM_Dcm.h                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Sch$*/
/* $Revision::   1.1      $$Author::   pbakabad        $$Date::   22 May 2014$*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
        
#ifndef SCHM_DCM_H
#define SCHM_DCM_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "STD_TYPES.h"
#include "Dcm_Cfg.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/******************************************************************************/
/*! \Description Autosar Release Major Version      \n
    \Range       4                                  \n
*******************************************************************************/
#define SCHM_AR_RELEASE_MAJOR_VERSION     (4U)
/******************************************************************************/
/*! \Description Autosar Release Minor Version      \n
    \Range       0                                  \n
*******************************************************************************/
#define SCHM_AR_RELEASE_MINOR_VERSION     (0U)


/*============================================================================*/
/*=== OS Abstraction Macros ==================================================*/
/*============================================================================*/

/*! \Description Defines the OS wrapping macros */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsp_u8Status from multiple access in
                 DspInternal_Main and DspInternal_<Service>
*******************************************************************************/
#define SchM_Enter_Dcm_Access_001()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsp_u8Status from multiple access in
                 DspInternal_Main and DspInternal_<Service>
*******************************************************************************/
#define SchM_Exit_Dcm_Access_001()
#endif

/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsp_au16DelayOnBootTimer and
                 Dsp_u16NumAttDelayTimer from multiple access in
                 DspInternal_SecurityAccess and Dcm_MainFunction
*******************************************************************************/
#define SchM_Enter_Dcm_Access_002()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsp_au16DelayOnBootTimer and
                 Dsp_u16NumAttDelayTimer from multiple access in
                 DspInternal_SecurityAccess and Dcm_MainFunction
*******************************************************************************/
#define SchM_Exit_Dcm_Access_002()

/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of bPbTimerOn from multiple access in
                 Dcm_TpRxIndication and Dcm_MainFunction
*******************************************************************************/
#define SchM_Enter_Dcm_Access_020()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of bPbTimerOn from multiple access in
                 Dcm_TpRxIndication and Dcm_MainFunction
*******************************************************************************/
#define SchM_Exit_Dcm_Access_020()

/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of u16PbCount and bPbTimerOn from multiple access
                 in Dcm_CopyTxData and Dcm_MainFunction
*******************************************************************************/
#define SchM_Enter_Dcm_Access_021()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of u16PbCount and bPbTimerOn from multiple access
                 in Dcm_CopyTxData and Dcm_MainFunction
*******************************************************************************/
#define SchM_Exit_Dcm_Access_021()

/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16P2Counter from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_051()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16P2Counter from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_051()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16S3Counter from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_052()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16S3Counter from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_052()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16S3Reload from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_053()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16S3Reload from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_053()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16P2Reload from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_054()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16P2Reload from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_054()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16P2StarReload from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_055()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16P2StarReload from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_055()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16P2Adjust from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_056()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16P2Adjust from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_056()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_u16RoeInterMsgCounter from multiple access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_057()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_u16RoeInterMsgCounter from multiple access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_057()
/******************************************************************************/
/*! \Description Enters DCM critical region used for
                 protection of Dsl_bRoeTransQueStatus from multiple
                 access
*******************************************************************************/
#define SchM_Enter_Dcm_Access_058()
/******************************************************************************/
/*! \Description Exits DCM critical region used for
                 protection of Dsl_bRoeTransQueStatus from multiple
                 access
*******************************************************************************/
#define SchM_Exit_Dcm_Access_058()


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_DefaultSessionModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_ExtendedDiagnosticSessionModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_SafteySystemDiagnosticSessionModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_ProgrammingSessionModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_VALEOSessionModeEntry(void);

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_NoResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_ResetExecutionModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_HardResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_SoftResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_BootloaderResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_SsBootloaderResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRapidPowerShutdownResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_DisableRapidPowerShutdownResetModeEntry(void);
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_KeyOnOffResetModeEntry(void);
/* Pas encore de session fournisseur de configuré */
/*extern FUNC(Std_ReturnType,DCM_CODE) Dcm_PSASpecificSessionModeEntry(void);*/

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SCHM_DCM_H */

/*==== End of file ==========================================================*/