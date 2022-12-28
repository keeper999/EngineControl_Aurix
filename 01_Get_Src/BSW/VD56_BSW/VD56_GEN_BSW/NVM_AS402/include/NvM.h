/******************************************************************************/
/*                                                                            */
/* !Layer           :  Services Layer                                         */
/*                                                                            */
/* !Component       :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !Module          :  NvM                                                    */
/* !Description     :  Non Volatile RAM Manager                               */
/*                                                                            */
/* !File            :  NvM.h                                                  */
/*                                                                            */
/* !Scope           :  Public                                                 */
/*                                                                            */
/* !Target          :  Any                                                    */
/*                                                                            */
/* !Vendor          :  Valeo                                                  */
/*                                                                            */
/* Coding language  :  C                                                      */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/*                                                                            */
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/12_NVM/02_Development/02_Source_Code/03_Header_Files/NvM.h-arc   1.16   Mar 21 2013 11:26:20   aalaa  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM.h-arc   1.13   Sep 10 2008 10:55:18   pjannet  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM.h-arc   1.12   Aug 11 2008 22:25:44   abazaraa  $
                                                                              */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.11    R1.1.0    AR4.0_Rev2                                  */
/* Done by    : Ahmed Alaa	                               Date : 21/03/13    */
/* Description: - Update SW version	for release NvM_STD_AR4.0.2_SW1.1.0       */
/******************************************************************************/

/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.11    R1.0.0    AR4.0_Rev2                                  */
/* Done by    : M.El-Ashmawy                               Date : 18/09/12    */
/* Description: - Modified NvM_kpfvideMultiBlockCallBack                      */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.10    R1.0.0    AR4.0_Rev2                                  */
/* Done by    : M.El-AShmawy                               Date : 28/08/12    */
/* Description: - Updated NVM_SW_MINOR_VERSION and NVM_SW_PATCH_VERSION       */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.9    R1.1.0    AR4.0_Rev2                                   */
/* Done by    : M.El-AShmawy                               Date : 28/08/12    */
/* Description: - Updated NVM_SW_MINOR_VERSION and NVM_SW_PATCH_VERSION       */
/*              - Changed NVM_VAR_NOINIT to NVM_VAR                           */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.8    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.Amroussy                               Date : 09/05/12      */
/* Description: - Updated NVM_SW_PATCH_VERSION                                */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.7    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.Amroussy                               Date : 08/05/12      */
/* Description: - added GSCSW-NVM-SDD-001-0332                                */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.6    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.Amroussy                               Date : 02/05/12      */
/* Description: - Edit NvM_GetVersionInfo                                     */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.5    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.Amroussy                               Date : 30/04/12      */
/* Description: - Fixed Bug 48864                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.3    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 03/10/11    */
/* Description: - Changed Memory sections for MemMap.h (V1.9 on PVCS)         */
/*               "This is done for Phase 2 of the project and must not be used*/
/*               for Phase 1"                              				      */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.2    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 21/07/11    */
/* Description: - Fixed Bug 39944 by adding coverage to GSCSW-NVM-SDD-001-0619*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.1    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 28/06/11    */
/* Description: - Added DET error NVM_E_POINTER_SYNC_USED                     */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.0    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 26/06/11    */
/* Description: - Initial Revision                                            */
/******************************************************************************/

#ifndef NVM_H
#define NVM_H

/* !Trace_To        : GSCSW-NVM-SDD-001-0032                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0067                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0127                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0065                                  */

#include "NvM_Cfg.h"
#include "NvM_Types.h"


/*============================================================================*/
/*=== Published information ==================================================*/
/*============================================================================*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0026                                  */

/* !Comment : Vendor ID of the dedicated implementation of this module
              according to the AUTOSAR vendor list.                           */
#define NVM_VENDOR_ID ((uint16)(38))

/* !Comment : Module ID of the 'NvM' module from Module List.                 */
#define NVM_MODULE_ID ((uint16)(20))

/* !Comment : Major version number of AUTOSAR specification on which the      */
/*            appropriate implementation is based on.                         */
#define NVM_AR_RELEASE_MAJOR_VERSION (4U)

/* !Comment : Minor version number of AUTOSAR specification on which the      */
/*            appropriate implementation is based on.                         */
#define NVM_AR_RELEASE_MINOR_VERSION (0U)

/* !Comment : Revision version number of AUTOSAR specification on which       */
/*            the appropriate implementation is based on.                     */
#define NVM_AR_RELEASE_REVISION_VERSION (2U)

/* !Comment : Major version number of the vendor specific implementation of   */
/*            the module. The numbering is vendor specific.                   */
#define NVM_SW_MAJOR_VERSION (1U)

/* !Comment : Minor version number of the vendor specific implementation of   */
/*            the module. The numbering is vendor specific.                   */
#define NVM_SW_MINOR_VERSION (1U)

/* !Comment : Patch level version number of the vendor specific               */
/*            implementation of the module. The numbering is vendor specific. */
#define NVM_SW_PATCH_VERSION (1U)

/* !Comment: The instance ID of the NVM component. Here we have always one
             instance so it will be fixed to 0                                */
#define NvM_u8INSTANCE_ID ((uint8)0)

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/*============================================================================*/
/*=== Debugging Variables ====================================================*/
/*============================================================================*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0583                                  */
#define NVM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
extern VAR(NvM_tenuMainFnStateType, NVM_VAR) NvM_enueMainFnState;
#define NVM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define NVM_START_SEC_VAR_8
#include "MemMap.h"
#if (NVM_udtNUM_OF_NVRAM_BLOCKS < (255U))
 extern VAR(NvM_BlockIdType, NVM_VAR) NvM_udteCurrentBlockID;
#endif
 extern VAR(uint8, NVM_VAR) NvM_u8eCurrentJobID;
#define NVM_STOP_SEC_VAR_8
#include "MemMap.h"


#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
#define NVM_START_SEC_VAR_16
#include "MemMap.h"
 extern VAR(NvM_BlockIdType, NVM_VAR) NvM_udteCurrentBlockID;
#define NVM_STOP_SEC_VAR_16
#include "MemMap.h"
#endif /* (NVM_udtNUM_OF_NVRAM_BLOCKS > (255U)) */

/* PRQA S 0850 --                                                             */

/*============================================================================*/
/*=== Implementation version checking ========================================*/
/*============================================================================*/

/* Check this component version information toward configured one             */
#ifdef NVM_CFG_MAJOR_VERSION
  #ifdef NVM_CFG_MINOR_VERSION

    /* Major version of the vendor specific implementation of NVM module */
    #if (NVM_SW_MAJOR_VERSION != NVM_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif

    /* Minor version of the vendor specific implementation of NVM module */
    #if (NVM_SW_MINOR_VERSION > NVM_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif

  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* NVM_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* NVM_CFG_MAJOR_VERSION */


/******************************************************************************/
/*                         ERRORS IDS Reported to DET                         */
/* !Trace_To        : GSCSW-NVM-SDD-001-0031                                  */
/******************************************************************************/
/* !MComment: API requests called with wrong parameter */
#if (NVM_DEV_ERROR_DETECT == STD_ON)
/* !Trace_To        : GSCSW-NVM-SDD-001-0005                                  */

  #define   NVM_E_PARAM_BLOCK_ID   ((uint8)(0x0A))


  #define   NVM_E_PARAM_BLOCK_TYPE   ((uint8)(0x0B))


  #define   NVM_E_PARAM_BLOCK_DATA_IDX   ((uint8)(0x0C))


  #define   NVM_E_PARAM_ADDRESS  ((uint8)(0x0D))


  #define   NVM_E_PARAM_DATA     ((uint8)(0x0E))

/* !Trace_To        :                                                         */
  #define   NVM_E_PARAM_POINTER     ((uint8)(0x0F))

/* !Trace_To        : GSCSW-NVM-SDD-001-0303                                  */
  /* !Comment: NVRAM manager is still not initialized */
  #define   NVM_E_NOT_INITIALIZED ((uint8)(0x14))

  /* !Comment: API read/write/control request failed because a block with the
  same ID is already listed or currently in progress */
/* !Trace_To        : GSCSW-NVM-SDD-001-0304                                  */
  #define   NVM_E_BLOCK_PENDING  ((uint8)(0x15))

  /* !Comment: The service is not possible with this block configuration.*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0305                                  */
  #define   NVM_E_BLOCK_CONFIG   ((uint8)(0x18))

  /* !Comment: This service has entered an abnormal branch due to wrong
  configuration or wrong usage or a SW bug*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0007                                  */
  #define   NVM_E_ABNORMAL_BRANCH  ((uint8)(0x19))

/* !Comment: The MEMIF component is still not initialized                     */

#define   NVM_E_MEMIF_UNINIT  ((uint8)(0x20))

/* !Comment: The block is locked                                              */
/* !Trace_To        :                                                         */
#define   NVM_E_BLOCK_LOCKED  ((uint8)(0x21))

/* !Comment: Block uses sync. mechanism and pointer is passed                 */
#define   NVM_E_POINTER_SYNC_USED  ((uint8)(0x22))

#endif /* (NVM_DEV_ERROR_DETECT == STD_ON)  */

/******************************************************************************/
/*                       Symbolic Constants (#defines)                        */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* !MComment: Service ID                                                      */
/******************************************************************************/
#define NvM_u8INIT_ID                      ((uint8)(0x00))

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
#define NvM_u8SET_DATA_INDEX_ID            ((uint8)(0x01))
#define NvM_u8GET_DATA_IND_ID              ((uint8)(0x02))
#define NvM_u8READ_BLOCK_ID                ((uint8)(0x06))
#define NvM_u8WRITE_BLOCK_ID               ((uint8)(0x07))
#define NvM_u8RESTORE_BLK_DFTS_ID          ((uint8)(0x08))
#define NvM_u8CANCEL_JOB_BLOCK_ID          ((uint8)(0x10))
#define NvM_u8READ_BLK_DFT_DSET_ID         ((uint8)(0x14))
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
#define NvM_u8SET_BLK_PROTECT_ID           ((uint8)(0x03))
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_3) */

#define NvM_u8GET_ERROR_STATUS_ID           ((uint8)(0x04))
#define NvM_u8CANCEL_WRITE_ALL_ID           ((uint8)(0x0A))
#define NvM_u8READ_ALL_ID                   ((uint8)(0x0C))
#define NvM_u8WRITE_ALL_ID                  ((uint8)(0x0D))
#define NvM_u8MAIN_FUNCTION_ID              ((uint8)(0x0E))


#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
#define NvM_u8SET_RAM_BLK_STAT_ID          ((uint8)(0x05))
#endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

#define NvM_u8BLOCK_LOCK_STAT_ID           ((uint8)(0x13))

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
#if (NVM_JOB_PRIORITIZATION == STD_ON)
#define NvM_u8ERASE_NV_BLOCK_ID           ((uint8)(0x09))
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
#define NvM_u8INVALIDATE_NVBLK_ID          ((uint8)(0x0B))
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

#if (NVM_VERSION_INFO_API == STD_ON)
#define NvM_u8GET_VERSION_INFO_ID          ((uint8)(0x0F))
#endif /* (NVM_VERSION_INFO_API == STD_ON) */
/******************************************************************************/
/* Configuration Constants extern declarations (Variables defined in
NvM_Cfg.c )*/
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/*lint -restore */


/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/* !Comment: Exporting the Block Descriptor Structure to be used by the NVRAM
             Manager */
/* !Trace_To        : GSCSW-NVM-SDD-001-0033                                  */
extern CONST(NvM_tstrBlockDescriptorType, NVM_CFG_CONST)
  NvM_akstreBlockDescriptor[NVM_udtNUM_OF_NVRAM_BLOCKS + 1U];

/* !Trace_To        : GSCSW-NVM-SDD-001-0068                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0069                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0070                                  */
/* !Comment: Exporting the pointer to the Multi block callback routine to
             be used by the NVRAM Manager */
extern const NvM_tpfvidMultiBlkClBkType NvM_kpfvideMultiBlockCallBack;

/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/*lint -restore */

/******************************************************************************/
/* !Comment: Start of memory mapping for NvM code segment                     */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_START_SEC_CODE
#include "MemMap.h"
/*lint -restore */

/* !Trace_To        : GSCSW-NVM-SDD-001-0619                                  */

/******************************************************************************/
/* !Description : Main cyclic function that performs the processing of NVRAM
                  Manager jobs                                                */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_MainFunction(void);

/******************************************************************************/
/* !Description : API for NVM initialization                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_Init(void);

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API that sets the index to access a certain dataset of a
                  NVRAM block (with/without ROM blocks)                       */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
  /* !Comment:  Block ID */
  NvM_BlockIdType BlockId,
  /* !Comment:  Index position of a NV/ROM block  */
  uint8 DataIndex
);

/******************************************************************************/
/* !Description : API that get the current index of a dataset NVRAM block     */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
  /* !Comment:  Block ID */
  NvM_BlockIdType BlockId,
  /* !Comment: Pointer to where to store the current dataset index  */
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
);
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* !Description : API to set/reset the write protection for a NV block        */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
  /* !Comment:  Block ID */
  NvM_BlockIdType BlockId,
  /* !Comment: Write protection shall be enabled or disabled */
  boolean ProtectionEnabled
);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

/******************************************************************************/
/* !Description : API to read a NVRAM block error/status information          */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
  /* !Comment:  Block ID */
  NvM_BlockIdType BlockId,
  /* !Comment: Pointer to where to store the request result.  */
  P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);
/* !Trace_To        : GSCSW-NVM-SDD-001-0128                                  */
#if (NVM_VERSION_INFO_API == STD_ON)
/******************************************************************************/
/* !Description : API returns the version information of this module          */
/* !Trace_To        : GSCSW-NVM-SDD-001-0047                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0204                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0332                                  */
/******************************************************************************/
#if ( NVM_DEV_ERROR_DETECT == STD_OFF )
/* !Deviation: [3459] Requirement States that this function should be
    implemented as a macro if source code of caller is available and this is a
    minor rule */
/* PRQA S 3459 ++*/
#define NvM_GetVersionInfo(\
    /*! \param versionInfo Pointer to version information of NvM module.*/\
    versionInfo)\
    do\
    {\
      if ((versionInfo) != NULL_PTR)\
      {\
        (versionInfo)->moduleID         = NVM_MODULE_ID;\
        (versionInfo)->vendorID         = NVM_VENDOR_ID;\
        (versionInfo)->sw_major_version = NVM_SW_MAJOR_VERSION;\
        (versionInfo)->sw_minor_version = NVM_SW_MINOR_VERSION;\
        (versionInfo)->sw_patch_version = NVM_SW_PATCH_VERSION;\
      }\
    }\
    while(0)

#endif
#if ( NVM_DEV_ERROR_DETECT == STD_ON )
#define NvM_GetVersionInfo(\
    /*! \param versionInfo Pointer to version information of NvM module.*/\
    versionInfo)\
    do\
    {\
      if ((versionInfo) != NULL_PTR)\
      {\
        (versionInfo)->moduleID         = NVM_MODULE_ID;\
        (versionInfo)->vendorID         = NVM_VENDOR_ID;\
        (versionInfo)->sw_major_version = NVM_SW_MAJOR_VERSION;\
        (versionInfo)->sw_minor_version = NVM_SW_MINOR_VERSION;\
        (versionInfo)->sw_patch_version = NVM_SW_PATCH_VERSION;\
      }\
      else\
      {\
        (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,\
                         NvM_u8GET_VERSION_INFO_ID, NVM_E_PARAM_POINTER);\
      }\
    }\
    while(0)

#endif
/* PRQA S 3459 --*/
#endif /* (NVM_VERSION_INFO_API == STD_ON) */


#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
/******************************************************************************/
/* !Description : API to set the RAM block status to changed or unchanged     */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId,
  /* !Comment: Mark the RAM block as Changed or Unchanged */
  boolean BlockChanged
);
#endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

/******************************************************************************/
/* !Description : API to set the lock status of a permanent RAM block of an
                  NVRAM block.                                                */
/* !Comment     : Request is accepted or not                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockLockStatus
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId,
  /* !Comment: Block Lock shall be enabled or disabled */
  boolean BlockLocked
);

/******************************************************************************/
/* !Description : API  to copy the data of the NV block to its corresponding
                  RAM block.   */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId,
  /* !Comment: Pointer to the RAM data block  */
  P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);
#endif


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API to copy the data of the RAM block to its corresponding
                  NV block.                                                   */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId,
  /* !Comment: Pointer to the RAM data block  */
  P2CONST(void,AUTOMATIC,NVM_APPL_DATA) NvM_SrcPtr
);
#endif

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API to restore the default data to its corresponding RAM
                  block.                                                      */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId,
  /* !Comment: Pointer to the RAM data block  */
  P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);
#endif

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description :  API  to cancel all jobs pending for a NV block.            */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId
);
#endif

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) && \
(NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/* !Description :  API to erase a NV block                                    */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId
);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) &&
(NVM_JOB_PRIORITIZATION == STD_ON)*/

/******************************************************************************/
/* !Description :  API  to cancel a running NvM_WriteAll  request.            */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void);

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* !Description :  API to invalidate a NV block                               */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock
(
  /* !Comment: Block ID  */
  NvM_BlockIdType BlockId
);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

/******************************************************************************/
/* !Description :  Multi block request API used to load and validate the
                   content of configured permanent RAM blocks during start-up */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_ReadAll(void);

/******************************************************************************/
/* !Description :  Multi block request API used to synchronize the contents of
                   permanent RAM blocks to their corresponding NV blocks on
                   shutdown.              */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_WriteAll(void);

/* PRQA S 0850 --                                                             */


/******************************************************************************/
/* !Comment: End of memory mapping for NvM code segment                       */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [760]: because redundant macro defined is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [961]: because multiple use of #define is  */
/*              according to AUTOSAR specifications                           */
/* !Deviation : inhibit MISRA rule [537]: because repeated include for Memmap */
/*              is according to AUTOSAR specifications                        */
/* !Deviation : inhibit MISRA rule [960]: because use of #undef is according  */
/*              to AUTOSAR specifications                                     */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v */
#define NVM_STOP_SEC_CODE
#include "MemMap.h"
/*lint -restore */

#endif /* NVM_H */

/*==== End of file ===========================================================*/

