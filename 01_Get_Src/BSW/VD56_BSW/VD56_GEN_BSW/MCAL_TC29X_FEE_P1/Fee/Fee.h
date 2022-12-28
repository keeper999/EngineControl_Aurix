/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fee.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\12 $                                                 **
**                                                                           **
**  $DATE       : 2013-11-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports the                                     **
**                 - functionality of Flash EEPROM Emulation driver          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
    TRACEABILITY: [cover parentID = DS_NAS_PR746,
                   SAS_AS_FEE060_FEE069_FEE002,DS_NAS_PR892,
                   DS_AS_FEE010_FEE048_FEE012_1]
                  [/cover]
*******************************************************************************/

#ifndef  FEE_H
#define  FEE_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Std_Types.h  */
#include "Std_Types.h"

#include "Mcal.h"

/* Fee Module Configuration header file */
#include "Fee_Cfg.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (FEE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Published parameters */

/* FEE Vendor ID */
#define FEE_VENDOR_ID                  ((uint16)17)

/* FEE Module ID */
#define FEE_MODULE_ID                  ((uint16)21)

/* FEE instance ID */
#define FEE_INSTANCE_ID                ((uint8)0)

#if (FEE_DEV_ERROR_DETECT  == STD_ON)

/* Development error values - DET's */
/* API service called with wrong parameter */
#define FEE_E_UNINIT                 ((uint8)0x01)
#define FEE_E_INVALID_BLOCK_NO       ((uint8)0x02)
#define FEE_E_INVALID_BLOCK_OFS      ((uint8)0x03)
#define FEE_E_INVALID_DATA_PTR       ((uint8)0x04)
#define FEE_E_INVALID_BLOCK_LEN      ((uint8)0x05)
#define FEE_E_BUSY                   ((uint8)0x06)
#define FEE_E_BUSY_INTERNAL          ((uint8)0x07)
#define FEE_E_INVALID_CANCEL         ((uint8)0x08)

/* API Service ID's */
#define FEE_SID_INIT                 ((uint8)0)
#define FEE_SID_SETMODE              ((uint8)1)
#define FEE_SID_READ                 ((uint8)2)
#define FEE_SID_WRITE                ((uint8)3)
#define FEE_SID_CANCEL               ((uint8)4)
#define FEE_SID_GETSTATUS            ((uint8)5)
#define FEE_SID_GETJOBRESULT         ((uint8)6)
#define FEE_SID_INVALIDATEBLOCK      ((uint8)7)
#define FEE_SID_GETVERSIONINFO       ((uint8)8)
#define FEE_SID_JOBENDNOTIF          ((uint8)16)
#define FEE_SID_JOBERRORNOTIF        ((uint8)17)
#endif 
/* FEE_DEV_ERROR_DETECT */

#define FEE_UNCONFIG_BLOCK_IGNORE    (0U)
#define FEE_UNCONFIG_BLOCK_KEEP      (1U)

#define FEE_CACHE_EXTRA_BUFFER_COUNT (10U)
#define FEE_TOTAL_BLOCK_COUNT        ((FEE_MAX_BLOCK_COUNT) + \
                                      (FEE_CACHE_EXTRA_BUFFER_COUNT))

#define FEE_GC_RESTART_INIT          (0U)
#define FEE_GC_RESTART_WRITE         (1U)

#define FEE_ERASE_SUSPEND_ENABLED    (1U)
#define FEE_ERASE_SUSPEND_DISABLED   (0U)

#define FEE_DATA_PAGE_COUNT          (FLS_SECTOR_SIZE/FLS_PAGE_SIZE)
#define FEE_DFLASH_PAGE_SIZE         (FLS_PAGE_SIZE)
#define FEE_MARKPAGE_ARR_COUNT       (uint8)(FEE_DATA_PAGE_COUNT/32U)
#define FEE_SECTORS                  (2U)

/* Repair result values */
#define FEE_REPAIR_FAILED            (0U)
#define FEE_REPAIR_SUCCESSFUL        (1U)
#define FEE_REPAIR_ONGOING           (2U)

/* Minimum block size is 2 pages (16 bytes) for invalidated block */
#define FEE_MIN_BLK_SIZE             (16U)
/* Maximum number of blocks which can be accommodated in a wordline */
#define FEE_MAX_NUM_OF_BLKS_IN_WL    (FEE_DFLASH_WORDLINE_SIZE/FEE_MIN_BLK_SIZE)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

typedef uint16  Fee_PageType;

typedef enum Fee_Data
{
  FEE_NORMAL_DATA = 0U,
  FEE_IMMEDIATE_DATA
} Fee_DataType;

/* Type:Fee_NotifFunctionPtrType                         */
/* Funtion pointer for JobEnd and JobError Notification  */
typedef void (*Fee_NotifFunctionPtrType)(void);

typedef struct Fee_Block
{
  /* Block Cycle count */
  unsigned_int  CycleCountLimit:24;

  /* Data type : Immediate or Normal */
  unsigned_int  FeeImmediateData:8;

  /* Logical Block number */
  unsigned_int  BlockNumber:16;

  /* Size of the logical block */
  unsigned_int  Size:16;

} Fee_BlockType;

/********************   Fee_CacheType  ****************************************/
/*
  This is the type of FEE Cache data structure containing 
  the overall information about a particular logical block 
*/

typedef union Fee_CacheStatus
{
  struct
  { 
    /* Valid: Indicates if the DFLASH contains Valid information for block */
    unsigned_int  Valid              : 1;
    /* Consistent: Indicates if the DFLASH contents of the block is consistent*/
    unsigned_int  Consistent         : 1;
    /* Copied: Indicates if the block contents are copied during GC */
    unsigned_int  Copied             : 1;
    /* PrevCopyValid: 'Valid' info for Previous Copy */
    unsigned_int  PrevCopyValid      : 1;
    /* PrevCopyConsistent: 'Consistent' info for Previous Copy */
    unsigned_int  PrevCopyConsistent : 1;
    /* PrevCopyCopied: 'Copied' info for Previous Copy */
    unsigned_int  PrevCopyCopied     : 1;
    /* Unsed */
    unsigned_int  Reserved           : 10;
  } B;
  struct
  { 
    /* Latest Copy Status */
    unsigned_int  LatestCopyStatus : 3;
    /* Pervious Copy Status */
    unsigned_int  PrevCopyStatus   : 3;
    /* Unsed */
    unsigned_int  Reserved         : 10;
  } St;
  uint16 U;
} Fee_CacheStatusType;

typedef struct Fee_Cache 
{  
  /* Physical Address of the latest copy of logical block */
  uint32  Address;

  /* Logical block number */
  uint16 BlockNumber;
  
  /* Status information of the latest copy of logical block */
  Fee_CacheStatusType Status;

  #if (FEE_GET_PREV_DATA_API == STD_ON)
  /* Physical Address of the previous copy of logical block */
  uint32  PrevCopyAddress;
  #endif
} Fee_CacheType;

/********************   FeePendReqInfo_Buf  ***********************************/
/*
  This structure will hold the details of the Fee pending request. 
*/
typedef struct FeePendReqInfo_Buf
{
  uint8  *DataBufferPtr;
  uint16 BlockNumber;
  uint16 BlockOffset;
  uint16 Length;
  #if (FEE_GET_PREV_DATA_API == STD_ON)
  uint8 GetPrevCopy;
  #endif
} Fee_PendReqBufType;

/********************   Fee_StatusFlagsType  **********************************/
/*
  This structure will have Fee status Flags which will have values with in the
  range of 0 and 1.
*/
typedef  struct FeeStatusFlags_t
{
  /* FeeBlkModified : This variable will indicate if the block contents were */
  /*                modified during Step GC operation                        */
  unsigned_int   FeeBlkModified                  : 1;
  /* FeeStartInitGC : This variable will indicate if the InitGC              */
  /*             can be invoked                                              */
  /* Value - 0   InitGC       cannot be invoked                              */
  /* Value - 1   InitGC       can be invoked                                 */
  unsigned_int   FeeStartInitGC                     : 1;
  /* FeeCurrSector: Stores the current sector on which blocks write          */
  /* operation will be done                                                  */
  /* Value - 0   Current sector is Sector 0                                  */
  /* Value - 1   Current sector is Sector 1                                  */
  unsigned_int   FeeCurrSector            : 1;
  /* FeeInitAPICalled: Flag to indicate if Fee_Init API is called            */
  /* Value - 0   Fee_Init API is NOT called                                  */
  /* Value - 1   Fee_Init API is called                                      */
  unsigned_int   FeeInitAPICalled                 : 1;
  /* FeeBlkInvalidStatus: Stores if the Invalidate request for a             */
  /* block is initiated                                                      */
  unsigned_int   FeeBlkInvalidStatus        : 1;
  /* FeeWriteInvldAPICalled: Stores the status if an Fee_Write is executed   */
  /* Value - 0   Fee_Write is not called                                     */
  /* Value - 1   Fee_Write is executed once already                          */
  unsigned_int   FeeWriteInvldAPICalled              : 1;

  unsigned_int   unused                        : 2;
} Fee_StatusFlagsType;


/*
  This structure will have Fee status Flags which will have values with in the
  range of 0 and 1.
*/
typedef  struct Fee_SectorStatus_t
{
  /* Dirty : This variable will indicate if the state page is clean / dirty  */
  unsigned_int   Dirty                 : 1;

  /* Used : This variable will indicate if the sector is empty / used        */
  unsigned_int   Used                  : 1;

  unsigned_int   unused                : 6;
} Fee_SectorStatusType;

/*
  This structure will have the information regarding a DFLASH sector
*/
typedef struct Fee_SectorInfo_t
{  
  /* state count of the sector */
  uint32 StateCount;

  /* UnerasableWLAddr: Unerasable WL Addr in the sector */
  uint32 UnerasableWLAddr;

  /* NonZeroWLAddr: Non Zero WL Addr encountered during Init */
  uint32 NonZeroWLAddr[2];

  /* NonZeroWLCount: Non Zero WL count encountered during Init */
  uint32 NonZeroWLCount;

  /* StatePageAddr: State Page Addr in the sector */
  uint32 StatePageAddr;

  /* NextFreeWLAddr: Addr of the next free WL in the sector */
  uint32 NextFreeWLAddr;

  /* UnerasableWLCount: Unerasable WL count in the sector */
  uint8 UnerasableWLCount;

  /* State: Sector state: Valid / Erased / Stateless */
  uint8 State;

  /* Status information of the sector: 
    Sector Empty / Used
    StatePage Clean/Dirty */
  Fee_SectorStatusType Status;
} Fee_SectorInfoType;


typedef struct Fee_LastWrittenBlkInfo_t
{
  /* Logical Block address in DFlash */
  uint32  Addr;
  /* Logical Block size in pages */
  Fee_PageType  PageCount;
  /* Logical Block number */
  uint16  BlockNumber;
  /* Status information of the logical block */
  Fee_CacheStatusType Status;
} Fee_LastWrittenBlkInfoType;

typedef struct Fee_GcBlkInfo_t
{
  /* Logical Block address in DFlash */
  uint32  Addr;
  /* Logical Block size in pages */
  Fee_PageType  PageCount;
  /* Logical Block number */
  uint16  BlockNumber;
  /* Logical Block Consistent or not */
  uint8   Consistent;
} Fee_GcBlkInfoType;



typedef struct Fee_State_Data_t
{
  /* FeeSectorInfo : Sector information is stored */
  Fee_SectorInfoType      FeeSectorInfo[FEE_SECTORS];

  /* Fee cache : Block information is stored */
  Fee_CacheType           FeeBlockInfo[FEE_TOTAL_BLOCK_COUNT];

  /* Fee Fee_LastWrittenBlkInfo : Last Written Block information is stored */
  /* This is used to rewrite the affected previous block during Fee_Write
     because of BLWL issue */
  Fee_LastWrittenBlkInfoType      FeeLastWrittenBlkInfo;

  /* Fee FeeGcCurrBlkInfo : Current Block being written during GC, 
     the addr is from prev sector */
  Fee_GcBlkInfoType       FeeGcCurrBlkInfo;

  /* FeePendReqInfo: Fee pending request details are stored */
  Fee_PendReqBufType      FeePendReqInfo;                       
  
  /* FeeGcLWBGcSrcAddr: Source address of the LWB during GC */
  uint32                  FeeGcLWBGcSrcAddr[FEE_MAX_NUM_OF_BLKS_IN_WL];

  /* FeeStateCount: Stores the state count from the latest state page 
     in DFLASH */
  uint32                  FeeStateCount;

  /* FeeUserReadWriteBuffer: buffer to pass to the Flash driver        */
  /* NOTE: The array is intentionally placed here so that it is 
   * word aligned due to the previous uint32 member
   */
  uint8                   FeeReadWriteBuffer[FEE_DFLASH_WORDLINE_SIZE];

  /* FeeGcReadWriteBuffer: buffer to pass to the Flash driver        */
  /* NOTE: The array is intentionally placed here so that it is 
   * word aligned due to the previous uint32 member
   */
  uint8                   FeeGcReadWriteBuffer[FEE_DFLASH_WORDLINE_SIZE];

  /* FeeLastWrittenBlkBuffer: Stores the content of last page of 
     previous data block. This is used while re-writing the affected
     previous data block because of BLWL */
  uint8                   FeeLastWrittenBlkBuffer[FEE_DFLASH_WORDLINE_SIZE - 
                                                  FEE_DFLASH_PAGE_SIZE];

  /* FeeGcDestAddr: Destination Addr for copying data during GC              */
  uint32                  FeeGcDestAddr;

  /* FeeGcSrcAddr: Source Addr from which data needs to be copied during GC  */
  uint32                  FeeGcSrcAddr;

  /* FeeNextFreePageAddr: Stores the next available DFLASH address for       */
  /* next block write                                                        */
  uint32                  FeeNextFreePageAddr;

  /* FeeWriteAffectedAddr: Write affected address */
  uint32                  FeeWriteAffectedAddr;

  /* FeeBlockStartAddr: Stores the start page address of the data block 
     during user write / during copy in GC - This is used for cache update
     after successful completion of block write / copy                     */
  uint32                  FeeBlockStartAddr;

  /* FeeCurrSectSrcAddr: Used during InitGc, Cache update and GC to read the 
     entire sector and for reading the previous block data during rewrite of
     previous block because of BLWL   */             
  uint32                  FeeCurrSectSrcAddr;

  /* FeeUserReadDestPtr: Stores the address of the buffer during read job  */
  uint8*                  FeeUserReadDestPtr;

  /* FeeJobResult: Stores the job result of the ongoing/finished job        */
  MemIf_JobResultType     FeeJobResult;

  /* FeeLastWriteSize: Last write size */
  Fls_LengthType          FeeLastWriteSize;

  /* FeeLastReadSize: Last read size */
  Fls_LengthType          FeeLastReadSize;

  /* FeeBlkPageCount: Tracks number of DFLASH pages read/written during   */
  /* Fee Write / GC process                                               */
  Fee_PageType            FeeBlkPageCount;

  /* FeeUserWriteBytesCount: Keeps track of the number of bytes written     */
  uint16                  FeeUserWriteBytesCount;

  /* FeeCurrReqBlockNum: Block number of the current request */
  uint16                  FeeCurrReqBlockNum;
  
  /* FeeIntrCurrReqPageCount: Page count of the current internal request */
  uint16                  FeeIntrCurrReqPageCount;

  /* FeeGCCopyIndex: Tracks the Index of logical blocks covered during      */
  /* GC process                                                             */
  uint16                  FeeGCCopyIndex;

  /* Index of the current un-configured block in cache table */
  uint16                  FeeGCUnconfigBlkCopyIndex;

  /* Number of un-configured blocks in cache table */
  uint16                  FeeUnConfigBlockCount;
  
  /* FeeGcPrevBlockNumber: Previous block number during GC */
  uint16                  FeeGcPrevBlockNumber;
  
  /* FeeGcFirstBlkNumInWL: Index of the first block number in the WL */
  uint16                  FeeGcFirstBlkNumInWL;

  /* FeeStatusFlags: This structure will have Fee status Flags which will   */
  /* have values with in the range of 0 and 1.                              */
  Fee_StatusFlagsType     FeeStatusFlags;
  
  /* FeeLastWrittenBlockDirty: Dirty status of the last block in the sector */
  uint8                   FeeLastWrittenBlockDirty;

  /* FeePendReqStatus: Stores the status of the pending request             */
  uint8                   FeePendReqStatus;

  /* FeeGcState: Garbage Collection State variable to keep track of the    */
  /* current state of of the garbage collection procedure                  */
  uint8                   FeeGcState;

  /* FeeGcResumeState: Indicates the state at which GC was interrupted, 
     this helps in deciding the state from which GC shall be resumed       */
  uint8                   FeeGcResumeState;     
  
  /* FeeGcBlkIndexInWL: Block index within WL during GC */
  uint8                   FeeGcBlkIndexInWL;

  /* FeeInitGCState: Stores the current state for Fee initialization process*/
  uint8                   FeeInitGCState;
 
  /* FeePrepDFLASHState: Stores current state of the preparation of DFLASH  */
  uint8                   FeePrepDFLASHState;
 
  /* FeeCacheState: Stores current state of the cache update process        */
  uint8                   FeeCacheState;
 
  /* FeeRepairStep: Stores State page repair status */
  uint8                   FeeRepairStep;

  /* FeeWLAffectedType: Type of corruption */
  uint8                   FeeWLAffectedType;

  /* FeeIntrJob: Stores the current Internal Job */
  uint8                   FeeIntrJob;

  /* FeeIntrJobStatus: Stores the Job status of internal job */
  uint8                   FeeIntrJobStatus;

  /* FeeUserJobStatus: Stores the Job status of user job */
  uint8                   FeeUserJobStatus;

  /* FeeIntrJobResult: Stores the Job result of internal job */
  uint8                   FeeIntrJobResult;

  /* FeeUserJobResult: Stores the Job result of user job */
  uint8                   FeeUserJobResult;

  /* FeeMainJob: Stores the current Main Job */
  uint8                   FeeMainJob;

  /* FeeUserJobFailCount: Stores the number of times the 
     comparison during User write failed   */
  uint8                   FeeUserJobFailCount;
  
  /* FeeIntrJobFailCount: Stores the number of times the 
     comparison during GC failed   */
  uint8                   FeeIntrJobFailCount;

  /* FeeUncfgBlksExceeded: Stores the status whether the number of 
     un-configured blocks exceeded the configured limit */
  uint8                   FeeUncfgBlksExceeded;
  
  #if (FEE_FLS_SUPPORTS_ERASE_SUSPEND == STD_ON)
  /* FeeEraseSuspendStatus: Status of Erase suspend */
  uint8                   FeeEraseSuspendStatus;

  /* FeeEraseResumeDemReported: Status of Erase-Resume failure DEM report */
  uint8                   FeeEraseResumeDemReported;
  #endif

  /* FeeDisableGCStart: GC Enable/Disable */
  boolean                 FeeDisableGCStart;
  
} Fee_StateDataType;

typedef struct Fee_Other_Config_t
{
  /* Flag to configure if configured blocks should be copied       */
  /* Value : FEE_UNCONFIG_BLOCK_IGNORE -> Do not copy              */
  /*         FEE_UNCONFIG_BLOCK_KEEP   -> Copy unconfigured        */
  /*                                      block to the next sector */
  unsigned_int FeeUnconfigBlock   : 1;

  /* Garbage Collection restarting point                           */
  /* Value : FEE_GC_RESTART_INIT   -> Restart GC at Initialization */
  /*         FEE_GC_RESTART_WRITE  -> Restart GC at First Write    */
  unsigned_int FeeGcRestartPoint : 1;

  /* Erase Suspend Feature ON/OFF */
  unsigned_int FeeUseEraseSuspend:1;

  unsigned_int unused : 5;
} Fee_GCConfigType;

/*
  This is the type of FEE external data structure containing 
  the overall initialization data for the FEE Driver 
*/
typedef struct Fee_Config 
{
  /* Pointer to the state variable data structure */
  Fee_StateDataType       *FeeStatePtr;

  /* Pointer to logical block configurations */
  Fee_BlockType            *FeeBlockConfigPtr;

  /* Job End Notification Call back routine */
  Fee_NotifFunctionPtrType  FeeNvmJobEndNotification;

  /* Job Error Notification Call back routine */
  Fee_NotifFunctionPtrType  FeeNvmJobErrorNotification;

  /* Fee Threshold Limit */
  uint32                    FeeThresholdLimit;
  
  /* Derived Config parameter : No. of configured blocks */
  uint16                    FeeBlkCnt;

  /* Fee settings for unconfigured blocks and GC restart */
  Fee_GCConfigType     FeeGCConfigSetting;

  /* Notification pointer in case of Illegal State */
  Fee_NotifFunctionPtrType  FeeIllegalStateNotification;

  /* TRUE/FALSE Config parameter for Erase All behaviour */  
  boolean FeeEraseAllEnable;

} Fee_ConfigType;

/* Fee_ConfigPtr_Type: Defined as a pointer to type Fee_ConfigType */
typedef Fee_ConfigType * Fee_ConfigPtrType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define FEE_START_SEC_SPL_VAR_32BIT
#include "MemMap.h"
extern Fee_ConfigPtrType Fee_CfgPtr;
#define FEE_STOP_SEC_SPL_VAR_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** TRACEABILITY: [cover parentID=DS_AS_FEE093,DS_AS_FEE082,
                   DS_AS_FEE064_FEE147,DS_AS_FEE016_FEE084_FEE015]
**                                                                            **
** Syntax : void Fee_GetVersionInfo( Std_VersionInfoType *VersionInfoPtr )    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:      0x08                                                      **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      non reentrant                                             **
**                                                                            **
** Parameters (out): versioninfo : Pointer to where to store the version      **
**                                information of this module.                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description :    This service returns the version information of           **
**                  this module.                                              **
**                  The version information includes:                         **
**                  Module Id, Vendor Id, Vendor specific version numbers     **
**                                                                            **
*******************************************************************************/
#if ((FEE_VERSION_INFO_API == STD_ON) && (FEE_DEV_ERROR_DETECT == STD_ON))
#define Fee_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
  if (VersionInfoPtr == NULL_PTR)                                              \
  {                                                                            \
    /* Report to DET */                                                        \
    Det_ReportError(                                                           \
                     FEE_MODULE_ID,                                            \
                     FEE_INSTANCE_ID,                                          \
                     FEE_SID_GETVERSIONINFO,                                   \
                     FEE_E_INVALID_DATA_PTR                                    \
                   );                                                          \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* FEE Module ID */                                                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FEE_MODULE_ID;        \
    /* FEE Vendor ID */                                                        \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FEE_VENDOR_ID;        \
    /* major version of FEE */                                                 \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                    (uint8)FEE_SW_MAJOR_VERSION;               \
    /* minor version of FEE */                                                 \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                    (uint8)FEE_SW_MINOR_VERSION;               \
    /* patch version of FEE */                                                 \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                    (uint8)FEE_SW_PATCH_VERSION;               \
  }                                                                            \
}
#elif ((FEE_VERSION_INFO_API == STD_ON) && (FEE_DEV_ERROR_DETECT == STD_OFF))
#define Fee_GetVersionInfo(VersionInfoPtr)                                     \
{                                                                              \
  /* FEE Module ID */                                                          \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FEE_MODULE_ID;          \
  /* FEE vendor ID */                                                          \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FEE_VENDOR_ID;          \
  /* major version of FEE */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                  (uint8)FEE_SW_MAJOR_VERSION;                 \
  /* minor version of FEE */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                  (uint8)FEE_SW_MINOR_VERSION;                 \
  /* patch version of FEE */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                  (uint8)FEE_SW_PATCH_VERSION;                 \
}
#else
#define Fee_GetVersionInfo(VersionInfo) ERROR_Fee_GetVersionInfo_NOT_SELECTED
#endif 


#define FEE_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Fee_Init(void)                                               **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function                        **
**         This service shall initialize the Flash EEPROM Emulation module    **
** using the values provided in the configuration set.                        **
*******************************************************************************/
extern void Fee_Init(void);

/*******************************************************************************
** Syntax : void Fee_SetMode( MemIf_ModeType Mode )                           **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  MemIf_ModeType    Desired mode for the underlying flash **
**                                      driver.                               **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This API sets the mode of the underelying flash driver       **
**                                                                            **
*******************************************************************************/
extern void Fee_SetMode( MemIf_ModeType Mode );

/*******************************************************************************
** Syntax : Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset,   **
**          uint8 *DataBufferPtr, uint16 Length )                             **
**                                                                            **
** Service ID: 0x02                                                           **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BlockNumber - Logical Block Number                      **
**                    BlockOffset - Read address offset inside the block      **
**                    Length - Number of bytes to read                        **
**                                                                            **
** Parameters (out):  DataBufferPtr - Pointer to data buffer                  **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This function shall take the block start address and         **
** offset and calculate the corresponding memory read address. The address    **
** offset and length parameter can take any value within the given block      **
** this allows reading of an arbitrary number of bytes from an arbitrary start**
** address inside a logical block                                             **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_Read(uint16 BlockNumber, 
                               uint16 BlockOffset, 
                               uint8 *DataBufferPtr, 
                               uint16 Length);

/*******************************************************************************
** Syntax : Std_ReturnType Fee_Write(uint16 BlockNumber,                      **
**          uint8 *DataBufferPtr)                                             **
**                                                                            **
** Service ID: 0x03                                                           **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BlockNumber - Logical Block Number                      **
**                    DataBufferPtr - Pointer to data buffer                  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This function shall take the logical block number and        **
** determine the corresponding memory write address. This routine will        **
** perform the block write operation on DFLASH (DF_EEPROM).                   **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_Write(uint16 BlockNumber, uint8 *DataBufferPtr);


/*******************************************************************************
** Syntax : void Fee_Cancel(void)                                             **
**                                                                            **
** Service ID: 0x04                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This functions shall cancel a pending request.               **
** Note: An ongoing write request is not cancelled. However, a queued         **
** write request is cancelled. Any read request either queued or under        **
** execution is cancelled.                                                    **
**                                                                            **
*******************************************************************************/
extern void Fee_Cancel(void);

/*******************************************************************************
** Syntax : MemIf_StatusType Fee_GetStatus(void)                              **
**                                                                            **
** Service ID: 0x05                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  MemIf_StatusType                                        **
**                                                                            **
** Description : This function returns the status of the FEE driver           **
**                                                                            **
*******************************************************************************/
extern MemIf_StatusType Fee_GetStatus(void);


/*******************************************************************************
** Syntax : MemIf_JobResultType Fee_GetJobResult(void)                        **
**                                                                            **
** Service ID: 0x06                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  MemIf_JobResultType                                     **
**                                                                            **
** Description : This function shall return the result of the last job that   **
** that was executed.                                                         **
**                                                                            **
*******************************************************************************/
extern MemIf_JobResultType Fee_GetJobResult(void);


/*******************************************************************************
** Syntax : Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber)            **
**                                                                            **
** Service ID: 0x07                                                           **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BlockNumber : Logical Block Number                      **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This function shall invalidate the given logical             **
** block                                                                      **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber);


/*******************************************************************************
** Syntax : Std_ReturnType Fee_EraseImmediateBlock( uint16 BlockNumber )      **
**                                                                            **
** Service ID: 0x09                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BlockNumber - Logical Block Number                      **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : Since double-sector algorithm is used with threshold limit   **
** for triggering GC, immediate block’s write requests during GC can be       **
** accommodated within the pre-erased threshold area of the active FEE sector.**
** Hence, this API is implemented as a dummy function returning E_NOT_OK.     **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_EraseImmediateBlock( uint16 BlockNumber );


#if (FEE_GET_CYCLE_COUNT_API == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Fee_17_GetCycleCount(uint16 BlockNumber,           **
**                                              uint32 * const CountPtr)      **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in):  BlockNumber - Logical Block Number                       **
**                                                                            **
** Parameters (out) :  CountPtr - Pointer to the variable to which the Erase  **
**                               cycle count is to be updated                 **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : When called with BlockNumber = 0, this routine delivers the  **
** FEE sector erase cycle count. When called with a configured BlockNumber,   **
** the write cycle count of the given block is returned.                      **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_17_GetCycleCount
(
  uint16 BlockNumber, 
  uint32 * const CountPtr
);

#else

#define Fee_17_GetCycleCount(BlockNumber,CountPtr)    \
ERROR_FeeGetCycleCountApi_NOT_SELECTED 

#endif /* Fee_17_GetCycleCount */


/*******************************************************************************
** Syntax : void  Fee_17_EnableGcStart( void )                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This service allows enabling the trigger of GC, if GC was    **
** disabled earlier by calling the API Fee_17_DisableGcStart. This service    **
** allows the FEE to trigger the GC if the sector is filled up to the         **
** threshold level                                                            **
**                                                                            **
*******************************************************************************/
extern void Fee_17_EnableGcStart( void );

/*******************************************************************************
** Syntax : void  Fee_17_DisableGcStart( void )                               **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This API prevents the GC from being started in case the      **
** threshold is crossed in the active FEE sector. This API does not stop an   **
** ongoing GC but only prevents the GC from being triggered by the            **
** Write/Invalidate request issued by the user.                               **
** Note: This API will disable the GC from starting only if,                  **
** 1. GC is not ongoing                                                       **
** 2. Initialisation activities are complete (i.e. the state pages are read   **
** and the GC state is determined)                                            **
**                                                                            **
*******************************************************************************/
extern void Fee_17_DisableGcStart( void );

/*******************************************************************************
** Syntax : void Fee_MainFunction(void)                                       **
**                                                                            **
** Service ID: 0x12                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This function asynchronously handles the requested read      **
** / write / invalidate jobs and their internal management operations.        **
** It determines the job to be executed and executes the same.                **
**                                                                            **
*******************************************************************************/
extern void Fee_MainFunction(void);

#if (FEE_GET_PREV_DATA_API == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Fee_17_GetPrevData(uint16 BlockNumber,             **
**                                            uint16 BlockOffset,             **
**                                            uint8 *DataBufferPtr,           **
**                                            uint16 Length)                  **
**                                                                            **
** Service ID: NA                                                             **
**                                                                            **
** Sync/Async: Asynchronous                                                   **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) :  BlockNumber - Logical Block Number                      **
**                    BlockOffset - Read address offset inside the block      **
**                    Length - Number of bytes to read                        **
**                                                                            **
** Parameters (out):  DataBufferPtr - Pointer to data buffer                  **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This API shall read one occurance previous version of the    **
** given logical block                                                        **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fee_17_GetPrevData(uint16 BlockNumber,
                                         uint16 BlockOffset,
                                         uint8 *DataBufferPtr,
                                         uint16 Length );
#else

#define Fee_17_GetPrevData(BlockNumber,CountPtr,DataBufferPtr,Length)    \
ERROR_FeeGetPrevDataApi_NOT_SELECTED
#endif

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define FEE_STOP_SEC_CODE
#include "MemMap.h"

#endif /* FEE_H */
