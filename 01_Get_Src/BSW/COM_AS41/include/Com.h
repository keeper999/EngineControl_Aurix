/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.67                                                        $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file Com.h
*
* \par
*   Declarations of Com API and external types                                */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/

#ifndef COM_H
#define COM_H

/*******************************************************************************
  Includes
*******************************************************************************/
#include "ComStack_Types.h"
/* !Deviation: [0838]  Multiple Com_Cfg.h inclusion is required by AUTOSAR */
/* PRQA S 0838, 5087 L1 */
#include "Com_Cfg.h"
/* PRQA L:L1 */
#if (Com_bRCV_SIG_GEN_ENABLE == STD_ON)
    #include "Com_GenApi.h"
#endif
#include "Com_Types.h"

#include "Com_PBCfg.h"

#if (COM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/*******************************************************************************
  Published Information
*******************************************************************************/
#define     COM_VENDOR_ID                       (uint16)(38)
#define     COM_MODULE_ID                       (uint16)(50)
#define     COM_INSTANCE_ID                     (0U)
#define     COM_AR_RELEASE_MAJOR_VERSION        (4U)
#define     COM_AR_RELEASE_MINOR_VERSION        (1U)
#define     COM_AR_RELEASE_REVISION_VERSION     (2U)
#define     COM_SW_MAJOR_VERSION                (2U)
#define     COM_SW_MINOR_VERSION                (0U)
#define     COM_SW_PATCH_VERSION                (1U)

/*******************************************************************************
  Compatibility Checks
*******************************************************************************/
#if (COM_bINTER_MOD_VER_CHECK == STD_ON)
/* ComStack_Types.h Compatibility Check */
#if ( COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION )
 #error "Com: COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION incompatable with COM_AR_RELEASE_MAJOR_VERSION!"
#endif
#if ( COMSTACKTYPE_AR_RELEASE_MINOR_VERSION > COM_AR_RELEASE_MINOR_VERSION )
 #error "Com: COMSTACKTYPE_AR_RELEASE_MINOR_VERSION incompatable with COM_AR_RELEASE_MINOR_VERSION!"
#endif
#endif

/* Com_Cfg.h Compatibility Check */
#if ( COM_CFG_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION )
 #error "Com: COM_CFG_AR_RELEASE_MAJOR_VERSION incompatable with COM_AR_RELEASE_MAJOR_VERSION!"
#endif
#if ( COM_CFG_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION )
 #error "Com: COM_CFG_AR_RELEASE_MINOR_VERSION incompatable with COM_AR_RELEASE_MINOR_VERSION!"
#endif
#if ( COM_CFG_AR_RELEASE_REVISION_VERSION != COM_AR_RELEASE_REVISION_VERSION )
 #error "Com: COM_CFG_AR_RELEASE_REVISION_VERSION incompatable with COM_AR_RELEASE_REVISION_VERSION!"
#endif
#if ( COM_CFG_MAJOR_VERSION != COM_SW_MAJOR_VERSION )
 #error "Com: COM_CFG_MAJOR_VERSION incompatable with COM_SW_MAJOR_VERSION!"
#endif
#if ( COM_CFG_MINOR_VERSION != COM_SW_MINOR_VERSION )
 #error "Com: COM_CFG_MINOR_VERSION incompatable with COM_SW_MINOR_VERSION!"
#endif


/*******************************************************************************
  Data Types Definitions
*******************************************************************************/

/******************************************************************************/
/* !Comment: The AUTOSAR COM module's signal group object identifier.         */
/* !Range: 0..<SignalGroupIdmax>                                              */
/* !Trace_To:                                                                 */
/******************************************************************************/
typedef uint16        Com_SignalGroupIdType;

/******************************************************************************/
/* !Comment: The AUTOSAR COM I-PDU module's group object identifier.          */
/* !Range: 0..<IpduGroupIdmax>                                                */
/* !Trace_To:                                                                 */
/******************************************************************************/
typedef uint16        Com_IpduGroupIdType;


/* calculation method COM_SUPPORTED_IPDU_GROUPS-1)/8)+1 */
#if (COM_SUPPORTED_IPDU_GROUPS > 0 )

#define Com_u16IPDU_GROUP_V_SIZE (((COM_SUPPORTED_IPDU_GROUPS-1U)/8U)+1U)

#else

#define Com_u16IPDU_GROUP_V_SIZE 1
 #endif


/******************************************************************************/
/* !Comment: This type can be used to store a flag (bit) for each I-PDU group
           within the system. It is used for setting the activation state and
           deadline monitoring state for I-PDU groups within one function call*/
/* !Range: 0..<IpduGroupIdmax>                                                */
/* !Trace_To:                                                                 */
/******************************************************************************/
typedef uint8         Com_IpduGroupVector[Com_u16IPDU_GROUP_V_SIZE];

/******************************************************************************/
/* !Comment: Unique identifier of an AUTOSAR COM module's service.            */
/* !Range: 0x01..0x42                                                */
/* !Trace_To:                                                                 */
/******************************************************************************/
typedef uint8         Com_ServiceIdType;

#define COMServiceId_Init                       (Com_ServiceIdType) 0x01
#define COMServiceId_DeInit                     (Com_ServiceIdType) 0x02
#define COMServiceId_IpduGroupControl           (Com_ServiceIdType) 0x03
#define COMServiceId_ReceptionDMControl         (Com_ServiceIdType) 0x06
#define COMServiceId_GetStatus                  (Com_ServiceIdType) 0x07
#define COMServiceId_GetConfigurationId         (Com_ServiceIdType) 0x08
#define COMServiceId_GetVersionInfo             (Com_ServiceIdType) 0x09
#define COMServiceId_SendSignal                 (Com_ServiceIdType) 0x0A
#define COMServiceId_ReceiveSignal              (Com_ServiceIdType) 0x0B
#define COMServiceId_UpdateShadowSignal         (Com_ServiceIdType) 0x0C
#define COMServiceId_SendSignalGroup            (Com_ServiceIdType) 0x0D
#define COMServiceId_ReceiveSignalGroup         (Com_ServiceIdType) 0x0E
#define COMServiceId_ReceiveShadowSignal        (Com_ServiceIdType) 0x0F
#define COMServiceId_InvalidateSignal           (Com_ServiceIdType) 0x10
#define COMServiceId_InvalidateShadowSignal     (Com_ServiceIdType) 0x16
#define COMServiceId_TriggerIPDUSend            (Com_ServiceIdType) 0x17
#define COMServiceId_MainFunctionRx             (Com_ServiceIdType) 0x18
#define COMServiceId_MainFunctionTx             (Com_ServiceIdType) 0x19
#define COMServiceId_MainFunctionRouteSignals   (Com_ServiceIdType) 0x1A
#define COMServiceId_InvalidateSignalGroup      (Com_ServiceIdType) 0x1B
#define COMServiceId_ClearIpduGroupVector       (Com_ServiceIdType) 0x1C
#define COMServiceId_SetIpduGroup               (Com_ServiceIdType) 0x1D
#define COMServiceId_TpRxIndication             (Com_ServiceIdType) 0x1E
#define COMServiceId_SendDynSignal              (Com_ServiceIdType) 0x21
#define COMServiceId_ReceiveDynSignal           (Com_ServiceIdType) 0x22
#define COMServiceId_CopyRxData                 (Com_ServiceIdType) 0x23
#define COMServiceId_CopyTxData                 (Com_ServiceIdType) 0x24
#define COMServiceId_StartOfReception           (Com_ServiceIdType) 0x25
#define COMServiceId_TpTxConfirmation           (Com_ServiceIdType) 0x26
#define COMServiceId_TxConfirmation             (Com_ServiceIdType) 0x40
#define COMServiceId_TriggerTransmit            (Com_ServiceIdType) 0x41
#define COMServiceId_RxIndication               (Com_ServiceIdType) 0x42
#define COMServiceId_SwitchIpduTxMode           (Com_ServiceIdType) 0x27
/******************************************************************************/
/* !Comment: Return codes of AUTOSAR COM module's service.                    */
/* !Range:                                                                    */
/* !Trace_To:                                                                 */
/******************************************************************************/
#define COM_SERVICE_NOT_AVAILABLE                0x80
#define COM_BUSY                                 0x81

/******************************************************************************/
/* API Prototype                                                              */
/******************************************************************************/
/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838, 5087 L1 */
#if (Com_bRCV_SIG_GEN_ENABLE == STD_ON)
#define COM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
extern P2CONST(Com_ConfigType,AUTOMATIC,COM_CALIB_CONST) Com_pkstreMainConfig;
#define COM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif

#define COM_START_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */

extern FUNC(void, COM_CODE)
    Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_CFG_CONST) config);

extern FUNC(void, COM_CODE) Com_DeInit(void);

extern FUNC(void, COM_CODE)
    Com_IpduGroupControl(Com_IpduGroupVector ipduGroupVector,
                         VAR(boolean, AUTOMATIC) initialize );

extern FUNC(void, COM_CODE)
    Com_ReceptionDMControl(Com_IpduGroupVector ipduGroupVector);

extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus(void);

extern FUNC(uint32, COM_CODE) Com_GetConfigurationId(void);

extern FUNC(void, COM_CODE)
    Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector);

extern FUNC(void, COM_CODE)
    Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector,
                     Com_IpduGroupIdType ipduGroupId,
                     VAR(boolean, AUTOMATIC) bitval);

extern FUNC(uint8, COM_CODE)
    Com_SendSignal( Com_SignalIdType SignalId,
                   P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                                SignalDataPtr);

extern FUNC(uint8, COM_CODE)
    Com_SendDynSignal(Com_SignalIdType SignalId,
                      P2CONST(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                            SignalDataPtr,
                      VAR(uint16, AUTOMATIC) Length );

extern FUNC(uint8, COM_CODE)
    Com_ReceiveSignal(Com_SignalIdType SignalId,
                      P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr );

extern FUNC(uint8, COM_CODE)
    Com_ReceiveDynSignal( Com_SignalIdType SignalId,
                         P2VAR(void, AUTOMATIC, COM_APPL_DATA)   SignalDataPtr,
                         P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length );

extern FUNC(void, COM_CODE)
    Com_UpdateShadowSignal( Com_SignalIdType SignalId,
                            P2CONST(void, AUTOMATIC,
                                    COM_MAX_CALIB_APPL_CFGCONST)
                                                                SignalDataPtr );
extern FUNC(uint8, COM_CODE)
    Com_SendSignalGroup( Com_SignalGroupIdType SignalGroupId );

extern FUNC(uint8, COM_CODE)
    Com_ReceiveSignalGroup( Com_SignalGroupIdType SignalGroupId );

extern FUNC(void, COM_CODE)
    Com_ReceiveShadowSignal( Com_SignalIdType SignalId,
                             P2VAR(void, AUTOMATIC, COM_APPL_DATA)
                                                              SignalDataPtr );
extern FUNC(uint8, COM_CODE)
    Com_InvalidateSignal( Com_SignalIdType SignalId );

extern FUNC(void, COM_CODE)
    Com_InvalidateShadowSignal( Com_SignalIdType SignalId );

extern FUNC(uint8, COM_CODE)
    Com_InvalidateSignalGroup( Com_SignalGroupIdType SignalGroupId );
extern FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType PduId);
extern FUNC(void, COM_CODE) Com_SwitchIpduTxMode(VAR(PduIdType, AUTOMATIC)
                                                                  PduId,
												 VAR(boolean, AUTOMATIC) 
												                  Mode);
extern FUNC(void, COM_CODE) Com_MainFunctionRx( void );
extern FUNC(void, COM_CODE) Com_MainFunctionTx( void );
extern FUNC(void, COM_CODE) Com_MainFunctionRouteSignals( void );

/* !Deviation: [0838]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 0838, 5087 L1 */
#define COM_STOP_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1 */

/* !Deviation: [3459]  Multiple Memmap.h inclusion is required by AUTOSAR */
/* PRQA S 3459 L1 */

#if (COM_VERSION_INFO_API == STD_ON)
/* !Trace_To: Com-CDD-0191(0) , Com-CDD-0192(0) , Com-CDD-0193(0) ,           */
  #if (COM_DEV_ERROR_DETECT == STD_ON)
    #define Com_GetVersionInfo(Versioninfo) do {                                \
      if ((P2VAR(void,AUTOMATIC,COM_APPL_DATA))(Versioninfo) == NULL_PTR)         \
      {                                                                         \
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COMServiceId_GetVersionInfo, COM_E_PARAM_POINTER);\
      }                                                                         \
      else                                                                      \
      {                                                                         \
      (Versioninfo)->vendorID = COM_VENDOR_ID;                                  \
      (Versioninfo)->moduleID = COM_MODULE_ID;                                  \
      (Versioninfo)->sw_major_version = COM_SW_MAJOR_VERSION;                   \
      (Versioninfo)->sw_minor_version = COM_SW_MINOR_VERSION;                   \
      (Versioninfo)->sw_patch_version = COM_SW_PATCH_VERSION;                   \
      }                                                                         \
    }while (0)
  
  #else
    #define Com_GetVersionInfo(Versioninfo) do {                                \
      (Versioninfo)->vendorID = COM_VENDOR_ID;                                  \
      (Versioninfo)->moduleID = COM_MODULE_ID;                                  \
      (Versioninfo)->sw_major_version = COM_SW_MAJOR_VERSION;                   \
      (Versioninfo)->sw_minor_version = COM_SW_MINOR_VERSION;                   \
      (Versioninfo)->sw_patch_version = COM_SW_PATCH_VERSION;                   \
      } while (0)
  #endif
#endif
/* PRQA L:L1 */
/******************************************************************************/
/* DET Errors                                                                 */
/******************************************************************************/
#define COM_E_PARAM           0x01
#define COM_E_UNINIT          0x02
#define COM_E_PARAM_POINTER   0x03
/* PRQA S 0850 --                                                             */
#endif /* COM_H */

/** \} */ /* end of Com module group */
