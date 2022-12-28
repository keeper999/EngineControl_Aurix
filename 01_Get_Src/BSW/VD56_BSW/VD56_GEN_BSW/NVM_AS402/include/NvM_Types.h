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
/* !File            :  NvM_Types.h                                            */
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
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/12_NVM/02_Development/02_Source_Code/03_Header_Files/NvM_Types.h-arc   1.9   Oct 07 2013 14:39:00   aalaa  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM_Types.h-arc   1.9   Aug 11 2008 22:25:42   abazaraa  $
                                                                              */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.2    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 21/07/11    */
/* Description: - Modified NvM_tkpfvidMultiBlkClBkType                        */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.1    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 29/06/11    */
/* Description: - Modified NvM_tpfu8WriteRamBlkToNvm                          */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.0    R1.0.0    AR4.0_Rev2                                   */
/* Done by    : M.El-Ashmawy                               Date : 26/06/11    */
/* Description: - Initial Revision                                            */
/******************************************************************************/

#ifndef NVM_TYPES_H
#define NVM_TYPES_H

/* !Deviation : Inhibit MISRA rule [0537]: Because repeated file inclusion of */
/*              Std_Types.h could occur due to Autosar file architecture.     */
/*lint -save -vo -e537 -v */
/* !Trace_To        : GSCSW-NVM-SDD-001-0203                                  */
#include "Std_Types.h"
/*lint -restore */
#include "NvM_Cfg.h"

#if (NvM_bRTE_USED == STD_ON)
#include "Rte_NvM_Type.h"
#endif
/******************************************************************************/
/* !MComment: Used to configure the NVM_API_CONFIG_CLASS parameter.           */
/* !Trace_To        : GSCSW-NVM-SDD-001-0027                                  */

#define NVM_API_CONFIG_CLASS_1 (0U)
#define NVM_API_CONFIG_CLASS_2 (1U)
#define NVM_API_CONFIG_CLASS_3 (2U)


/* !MComment: Used to configure block management type.                        */
/* !Trace_To        : GSCSW-NVM-SDD-001-0022                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0028                                  */
#define NVM_BLOCK_NATIVE ((uint8)0)
#define NVM_BLOCK_REDUNDANT ((uint8)1)
#define NVM_BLOCK_DATASET ((uint8)2)

/* !MComment: Used to configure CRC type.                                     */
/* !Trace_To        : GSCSW-NVM-SDD-001-0029                                  */
#if (NVM_USE_CRC8 == STD_ON)
#define NVM_CRC8  ((uint8)0)
#endif
#if (NVM_USE_CRC16 == STD_ON)
#define NVM_CRC16 ((uint8)1)
#endif
#if (NVM_USE_CRC32 == STD_ON)
#define NVM_CRC32 ((uint8)2)
#endif

/******************************************************************************/
/* !MComment: Constant values of request result can take                      */
/*            NvM_RequestResultType.                                          */
/* !Trace_To : GSCSW-NVM-SDD-001-0035					      */
/* !Trace_To        : GSCSW-NVM-SDD-001-0030                                  */
#ifndef NVM_REQ_OK
#define NVM_REQ_OK                 ((NvM_RequestResultType)0)
#endif
#ifndef NVM_REQ_NOT_OK
#define NVM_REQ_NOT_OK             ((NvM_RequestResultType)1)
#endif
#ifndef NVM_REQ_PENDING
#define NVM_REQ_PENDING            ((NvM_RequestResultType)2)
#endif
#ifndef NVM_REQ_INTEGRITY_FAILED
#define NVM_REQ_INTEGRITY_FAILED   ((NvM_RequestResultType)3)
#endif
#ifndef NVM_REQ_BLOCK_SKIPPED
#define NVM_REQ_BLOCK_SKIPPED      ((NvM_RequestResultType)4)
#endif
#ifndef NVM_REQ_NV_INVALIDATED
#define NVM_REQ_NV_INVALIDATED     ((NvM_RequestResultType)5)
#endif
#ifndef NVM_REQ_CANCELED
#define NVM_REQ_CANCELED           ((NvM_RequestResultType)6)
#endif
#ifndef NVM_REQ_REDUNDANCY_FAILED
#define NVM_REQ_REDUNDANCY_FAILED  ((NvM_RequestResultType)7)
#endif
#ifndef NVM_REQ_RESTORED_FROM_ROM
#define NVM_REQ_RESTORED_FROM_ROM  ((NvM_RequestResultType)8)
#endif
/******************************************************************************/
/* !Comment: Type define of request result. This is an asynchronous request
result returned by the API service NvM_GetErrorStatus. The availability of a
request result can be also signaled via a callback function  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0035                                  */
#ifndef RTE_TYPE_NvM_RequestResultType
#define RTE_TYPE_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
#endif
/******************************************************************************/
/* !Comment: Type define for the State of Main Function                       */
typedef enum
{
  NvM_MFN_NOT_INIT = 0,
  NvM_MFN_JOBS_SCAN,
  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    #if (NVM_JOB_PRIORITIZATION == STD_ON)
      NvM_MFN_IMDT_SB_JOB,
    #endif
    NvM_MFN_STD_SB_JOB,
  #endif /*  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  */
  NvM_MFN_MB_JOB
}NvM_tenuMainFnStateType;



/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */


/******************************************************************************/
/* Pointers Types*/
/******************************************************************************/
/* !Comment: Type define for the pointer a RAM block . */
/* !Trace_To        : GSCSW-NVM-SDD-001-0036                                  */
typedef P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_tpvidRamBlkDataAddrtype;

/******************************************************************************/
/* !Comment: Type define for the pointer to Ram Crc address .                 */
/* !Trace_To        :  GSCSW-NVM-SDD-001-0369                                 */
typedef P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_tpu8RamBlkCrcAddrtype;

/******************************************************************************/
/* !Comment: Type define for the pointer a ROM block . */
/* !Trace_To        : GSCSW-NVM-SDD-001-0037                                  */
typedef P2CONST(uint8, AUTOMATIC, NVM_APPL_CONST) NvM_tpku8RomBlkDataAddrtype;

/******************************************************************************/
/* !Comment: Type define for Pointer to the callback routine which shall be
called by the NvM if no ROM data is available for initialization of the NVRAM
block.   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0038                                  */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_tpfu8InitBlkClBkType)(void);
/******************************************************************************/
/* !Comment: Type define for Pointer to the callback routine which shall be
             called by the NvM to let the application copy data from the NvM
			       module's mirror to RAM block.                                    */
/* !Trace_To        : GSCSW-NVM-SDD-001-0370                                  */
typedef P2FUNC(Std_ReturnType,NVM_APPL_CODE, NvM_tpfu8ReadRamBlkFromNvm)
  (P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvMBuffer);
/******************************************************************************/
/* !Comment: Type define for Pointer to the callback routine which shall be
             called by the NvM to let the application copy data from RAM block
			       to NvM module's mirror.                                          */
/* !Trace_To        : GSCSW-NVM-SDD-001-0371                                  */
typedef P2FUNC(Std_ReturnType,NVM_APPL_CODE, NvM_tpfu8WriteRamBlkToNvm)
  (P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvMBuffer);
/******************************************************************************/
/* !Comment: Type define for Pointer to the callback routine which shall be
called by the NvM after termination of each asynchronous single block request.*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0039                                  */
typedef P2FUNC(Std_ReturnType,NVM_APPL_CODE, NvM_tpfu8SingleBlkClBkType)
  (uint8 NvM_u8CurrentJobID,NvM_RequestResultType u8JobResult);
/******************************************************************************/
/* !Comment: Type define for the the pointer to the Multi block callback
             routine which shall be called by the NvM after termination of
             each asynchronous multi block request. */
/* !Trace_To        : GSCSW-NVM-SDD-001-0040                                  */
typedef P2FUNC(void, NVM_APPL_CODE,
  NvM_tpfvidMultiBlkClBkType)(uint8 ServiceId,
  NvM_RequestResultType JobResult);

/* PRQA S 0850 --                                                             */

/******************************************************************************/
/* Type of Block Descriptor Configuration Structure.                          */
/******************************************************************************/

/******************************************************************************/
/* !Comment: Type of container used for configuration of each NVRAM block
             managed by NvM. */
/* It is put in this file because it has to be seen by the NvM_Cfg.c and
   NvM.c */
/* !Trace_To        : GSCSW-NVM-SDD-001-0020                                  */
/* !Trace_To        : GSCSW-NVM-SRS-102-0???                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0041                                  */

/******************************************************************************/
typedef struct
{
/* !Trace_To        : GSCSW-NVM-SDD-001-0221                                 */
/* !Comment: Defines CRC usage for the NVRAM and RAM block . NV memory space
             for CRC shouldn't be taken into account while configuring the
             NV block length but while declaring the RAM block in the
             application. It should reserve 2 or 4 bytes at the end of the
             RAM block */
/* !Range: [TRUE, FALSE]   */
  boolean bBlockUseCrc;

#if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
/* !Trace_To        : GSCSW-NVM-SDD-001-0123                                  */
/* !Comment: Defines CRC re-calculation for the permanent RAM block upon a
             NvM_SetRamBlockStatus request. It can be set to TRUE only if
             bBlockUseCrc is set to TRUE */
/* !Range: [TRUE, FALSE]   */
  boolean bCalcRamBlockCrc;
#endif

/* !Trace_To        : GSCSW-NVM-SDD-001-0222                                 */
/* !Comment: Defines CRC data width for the NVRAM block.  */
/* !Range: [NVM_CRC8,NVM_CRC16, NVM_CRC32]   */
  uint8 u8BlockCrcType;

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* !Trace_To        : GSCSW-NVM-SDD-001-0386                                 */
/* !Comment: Defines whether an explicit synchronization mechanism with a
             RAMmirror and callback routiness for transferring data to and
			 from NvMmodule's RAM mirror is used for NV block. true if
			 synchronizationmechanism is used, false otherwise.              */
/* !Range: [TRUE, FALSE]   */
  boolean bBlkUseSyncMechanism;
#endif

/* !Trace_To        : GSCSW-NVM-SDD-001-0223                                 */
/* !Comment: Defines an initial write protection of the NV block */
/* !Range: [TRUE, FALSE]   */
  boolean bBlockWriteProtection;

/* !Trace_To        : GSCSW-NVM-SDD-001-0224                                 */
/* !Comment: Defines write protection after first write. If TRUE, the NVM will
             never permit erase nor replace with the default ROM data after
             first initialization */
/* !Range: [TRUE, FALSE]   */
  boolean bWriteBlockOnce;

/* !Trace_To        : GSCSW-NVM-SDD-001-0387, GSCSW-NVM-SDD-001-0362          */
/* !Comment: Defines if the Static Block ID check is enabled. false: Static
             Block IDcheck is disabled. true: Static Block ID check is
			 enabled.                                                        */
/* !Range: [TRUE, FALSE]   */
  boolean bStaticBlockIDCheck;


#if (NVM_DYNAMIC_CONFIGURATION != STD_OFF)
/* !Trace_To        : GSCSW-NVM-SDD-001-0225                                 */
/* !Comment: Defines whether a NVRAM block shall be treated resistant to
             configuration changes or not. If FALSE and configuration mismatch
             occurs, NvM shall load the ROM default data to the corresponding
             RAM block, else it shall load the NV block as normal*/
/* !Range: [TRUE, FALSE]   */
  boolean bResistToChangedSW;
#endif

/* !Trace_To        : GSCSW-NVM-SDD-001-0388                                  */
/* !Comment: Defines if Write Verification is enabled. false: Write
             verification isdisabled. true: Write Verification is enabled.    */
/* !Range: [TRUE, FALSE]   */
  boolean bWriteVerification;

/* !Trace_To        : GSCSW-NVM-SDD-001-0389                                  */
/* !Comment: Defines the number of bytes to compare in each step when
             comparing the content of a RAM Block and a block read back.      */
/* !Range: [0..65535]  */
  uint16 u16WriteVerifDataSize;

/* !Trace_To        : GSCSW-NVM-SDD-001-0226                                  */
/* !Comment: Defines the NVRAM device ID where the NV block is located.       */
/*  Calculation Formula: "value = TargetBlockReference.[Ea/Fee]               */
/*  BlockConfiguration. [Ea/Fee]DeviceIndex" . And this means that the        */
/*  value of this paramter should be consistent with the value configured in  */
/*  Ea/Fee modules.	*/
/* !Range: [0..254]   */
  uint8 u8NvRamDeviceId;

/* !Trace_To        : GSCSW-NVM-SDD-001-0227                                 */
/* !Comment: : Defines the block management type for the NVRAM block. If
               NVM_DATASET_SELECTION_BITS is configured to 0 then this
               parameter can't take the value of NVM_BLOCK_DATASET .  */
/* !Range: [NVM_BLOCK_NATIVE, NVM_BLOCK_REDUNDANT, NVM_BLOCK_DATASET]   */
  uint8 u8BlockManagementType;

/* !Trace_To        : GSCSW-NVM-SDD-001-0228, GSCSW-NVM-SDD-001-0431          */
/* !Comment: Defines the number of multiple NV blocks according to block
             management type. Should be 1 if block management type is
             NVM_BLOCK_NATIVE, 2 if NVM_BLOCK_REDUNDANT and 1...255 if
             NVM_BLOCK_DATASET . */
/* !Range: [1..255] */
  uint8 u8NvBlockNum;

/* !Trace_To        : GSCSW-NVM-SDD-001-0229, GSCSW-NVM-SDD-001-0432          */
/* !Comment: Defines the number of multiple ROM blocks according to block
             management type. Should be 0...1 if block management type is
             NVM_BLOCK_NATIVE or NVM_BLOCK_REDUNDANT and 0...255 if block
             management type is NVM_BLOCK_DATASET */
/* !Range: [0..255] */
  uint8 u8RomBlockNum;

#if (NVM_JOB_PRIORITIZATION != STD_OFF             ) && \
    (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* !Trace_To        : GSCSW-NVM-SDD-001-0230, GSCSW-NVM-SDD-001-0434          */
/* !Comment: Defines the job priority for a NVRAM block. If configured to "0"
             this means that NvM_WriteBlock shall have immediate priority.
             As value goes higher priority decreases.  */
/* !Range: [0..255] */
  uint8 u8BlockJobPriority;
#endif

/* !Trace_To        : GSCSW-NVM-SDD-001-0231                                 */
/* !Comment: Defines the NV block data length in bytes. CRC bytes are not
             added */
/* !Range: [1..65535] */
  uint16 u16NvBlockLength;

/* !Trace_To        : GSCSW-NVM-SDD-001-0390                                 */
/* !Comment: Defines the maximum number of read retries.                     */
/* !Range: [0..7] */
  uint8 u8MaxNumOfReadRetries;

/* !Trace_To        : GSCSW-NVM-SDD-001-0391                                 */
/* !Comment: Defines the maximum number of write retries.                    */
/* !Range: [0..7] */
  uint8 u8MaxNumOfWriteRetries;

/* !Trace_To        : GSCSW-NVM-SDD-001-0232                                 */
/* !Comment: Defines the NV block identifier that shall be used to access a
             certain block via the memory abstraction interface. It consists
             of the "block number" in the MemIf addressing scheme with dataset
             index fixed to 0 (i.e. "block identifier" left-shifted with
             NVM_DATASET_SELECTION_BITS). This parameter is different than
             the Block ID that is passed by the application to the NvM APIs.  */
/* !Range: [0..65535] */
  uint16 u16NvBlockBaseNumber;

/* !Trace_To        : GSCSW-NVM-SDD-001-0233, GSCSW-NVM-SDD-001-0430          */
/* !Comment: Defines the start address of the RAM block data. This RAM block
             is declared and defined by the application. If configured to
             NULL_PTR, temporary RAM block will be assigned to the selected
             block management type. */
  NvM_tpvidRamBlkDataAddrtype pvidRamBlockDataAddress;

/* !Trace_To        : GSCSW-NVM-SDD-001-0393, GSCSW-NVM-SDD-001-0365          */
/* !Comment: Defines the start address of the RAM block Crc. It is declared
             and defined by the configuration tool. it will be configured to
             NULL_PTR if the block doesn't use Crc.                           */
  NvM_tpu8RamBlkCrcAddrtype pu8RamBlockCrcAddress;

/* !Trace_To        : GSCSW-NVM-SDD-001-0234                                  */
/* !Comment: Defines the start address of the ROM block data. This ROM block
             is declared and defined by the application. If configured to
             NULL_PTR, no ROM block will be available for the selected block
             management type. If u8RomBlockNum is configured to 0, this
             parameter shall be fixed at NULL_PTR and the user can't
             change it. */
/* !Deviation : Inhibit MISRA rule [8018]: because the input parameter of
                the call back is a const                                      */
/* PRQA S 8018, 8218, 8418, 8518 ++ */
  NvM_tpku8RomBlkDataAddrtype pku8RomBlkDataAddress;
/* PRQA S 8018, 8218, 8418, 8518 -- */

/* !Trace_To        : GSCSW-NVM-SDD-001-0235                                 */
/* !Comment: Pointer to the callback routine which shall be called by the NvM
             if no ROM data is available for initialization of the NVRAM
             block. If configured to NULL_PTR, no callback routine shall be
             called for initialization of the NVRAM block with default data.  */
  NvM_tpfu8InitBlkClBkType    pfu8InitBlockCallBack;

/* !Trace_To        : GSCSW-NVM-SDD-001-0236                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0405                                  */
/* !Comment: Pointer to the callback routine which shall be called by the NvM
             after termination of each asynchronous single block request.     */
  NvM_tpfu8SingleBlkClBkType  pfu8SingleBlockCallBack;

/* !Trace_To        : GSCSW-NVM-SDD-001-0237                                  */
/* !Comment: Defines whether a NVRAM block shall be processed during
             NvM_ReadAll or not. This configuration parameter has only
             influence on NVRAM blocks with permanent RAM block.              */
/* !Range: [TRUE, FALSE]   */
  boolean bSelectBlockForRdAll;

/* !Trace_To        : GSCSW-NVM-SDD-001-0396                                  */
/* !Comment: Defines whether a NVRAM block shall be processed during
             NvM_WriteAll or not. This configuration parameter has only
             influence on NVRAM blocks with permanent RAM block.              */
/* !Range: [TRUE, FALSE]   */
  boolean bSelectBlockForWrtAll;

/* !Trace_To        : GSCSW-NVM-SDD-001-0394                                  */
/* !Comment: Entry address of a block specific callback routine which shall
             be called inorder to let the application copy data from the NvM
			       module's mirror to RAM block                                     */

/* !Deviation : Inhibit MISRA rule [8018]: because the input parameter of
                the call back is a const                                      */
/* PRQA S 8018, 8218, 8418, 8518 ++ */
  NvM_tpfu8ReadRamBlkFromNvm   pfu8ReadRamBlkFromNvCbk;
/* PRQA S 8018, 8218, 8418, 8518 -- */

/* !Trace_To        : GSCSW-NVM-SDD-001-0395                                  */
/* !Comment: Entry address of a block specific callback routine which shall
             be called inorder to let the application copy data from RAM block
			       to NvM module's mirror.                                          */
  NvM_tpfu8WriteRamBlkToNvm    pfu8WriteRamBlkToNvCbk;

} NvM_tstrBlockDescriptorType ;

/******************************************************************************/
/* !Comment: Type define of the NVRAM block identifier
Reserved NVRAM block IDs:
0 -> to derive multi block request results via NvM_GetErrorStatus
1 -> redundant NVRAM block which holds the configuration ID     */
/* !Trace_To        : GSCSW-NVM-SDD-001-0034                                  */
#ifndef RTE_TYPE_NvM_BlockIdType
#define RTE_TYPE_NvM_BlockIdType

#if (NVM_udtNUM_OF_NVRAM_BLOCKS < (255U))
typedef uint8 NvM_BlockIdType;
#else
typedef uint16 NvM_BlockIdType;
#endif /* (NVM_udtNUM_OF_NVRAM_BLOCKS < (255U)) */
#endif /*RTE_TYPE_NvM_BlockIdType*/

#endif /* NVM_TYPES_H */
/*==== End of file ===========================================================*/

