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
/* !File            :  NvM.c                                                  */
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
/* $Header:   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/PATCH/NvM.c_v   1.0   14 Oct 2014 17:34:42   ynicaise  $/Data/pvcs65/CEE-SW/B01H01067-GroupSwStdDev/archives/02-R&D/02-Project/01-Modules/02-Services/04-NvM/02-Dev/01-SRC_NvM/NvM.c-arc   1.17   Aug 11 2008 22:25:42   abazaraa  $
                                                                              */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/* TFR        : None                                                          */
/* Rev        : 1.31   R1.1.0    AR4.0_Rev2                                   */
/* Done by    : M.Wadid                             Date : 24/03/13           */
/* Description: -Modify vidSwapJobInImdtQ                                     */
/******************************************************************************/
/*            Inclusions of  header Files                                     */
/* !Trace_To        : GSCSW-NVM-SDD-001-0126                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0129                                  */
/******************************************************************************/
#include "NvM.h"
#include "NvM_Cbk.h"
#include "Crc_Cfg.h"

/* !Trace_To        : GSCSW-NVM-SDD-001-0097                                  */
#include "SchM_NvM.h"

/* !Deviation : Inhibit MISRA rule [0537]: Because repeated file inclusion of */
/*              Std_Types.h could occur due to Autosar file architecture.     */
/*lint -save -vo -e537 -v */

/* !Trace_To        : GSCSW-NVM-SDD-001-0003                                  */
#include "MemIf.h"
#if (NVM_DEV_ERROR_DETECT == STD_ON)
/* !Trace_To        : GSCSW-NVM-SDD-001-0008                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0124                                  */
  #include "Det.h"
#endif /* (NVM_DEV_ERROR_DETECT == STD_ON)  */

/* !Deviation : Inhibit MISRA rule [0537]: Because repeated file inclusion of */
/*              Std_Types.h could occur due to Autosar file architecture.     */
/*lint -save -vo -e537 -v */
/* !Trace_To        : GSCSW-NVM-SDD-001-0004                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0009                                  */
#include "Dem.h"

/* !Trace_To        : GSCSW-NVM-SDD-001-0403                                  */
#include "Crc.h"
/*lint -restore                                                               */


/******************************************************************************/
/*                       Symbolic Constants (#defines)                        */
/******************************************************************************/
/**********************      Version Checking       ***************************/
#define u8C_SW_MAJOR_VERSION    (1U)
#define u8C_SW_MINOR_VERSION    (1U)
/******************************************************************************/
/*                    Implementation version checking                         */
/******************************************************************************/
/*                    Intra Module Checking                                   */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != NVM_SW_MAJOR_VERSION)
	#error Incompatible NvM SW major version between C & H files.
#endif

#if (u8C_SW_MINOR_VERSION != NVM_SW_MINOR_VERSION)
	#error Incompatible NvM SW minor version between C & H files..
#endif
/******************************************************************************/
/*                      Inter Module checking                                 */
/******************************************************************************/
/* !Trace_To        : GSCSW-NVM-SDD-001-0002                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0302                                  */


/******************************************************************************/
/*                                   Queues                                   */
/******************************************************************************/

/* !MComment:Buffer Status                                                    */
#define u8EMPTY ((uint8)0)
#define u8PEND_BUTNOT_STARTED  ((uint8)1)
#define u8STARTED  ((uint8)2)

/* !Comment: Empty entry in the Queue. It corrosponds to a Service ID of (255)*/
#define u8EMPTYSLOT ((uint8)(0xFF))

/* !Comment: Lowest Priority a Job can take in the Standard Job Queue.        */
#define u8LOWEST_PRIORITY ((uint8)(0xFF))
/******************************************************************************/
/*                                 CRC                                        */
/******************************************************************************/


/* !MComment: Number of bytes consumed by CRC                                 */
#if (NVM_USE_CRC8 == STD_ON)
#define u8CRC8_NUM_OF_BYTES ((uint8)(0x01))
#endif

#if (NVM_USE_CRC16 == STD_ON)
#define u8CRC16_NUM_OF_BYTES ((uint8)(0x02))
#endif

#if (NVM_USE_CRC32 == STD_ON)
#define u8CRC32_NUM_OF_BYTES ((uint8)(0x04))
#endif

/******************************************************************************/
/*                       Masks                                                */
/******************************************************************************/

/* Macro to extract bit 0 of u8GeneralBlocksatus indicates whether block 
   protection is enabled or not
   value 1: Block protected
   value 0: Block not protected                                                */
#define u8PROTECTION_ENABLE           0x01
#define u8PROTECTION_DISABLE          0xFE  

/* Macro to extract bit 1 of u8GeneralBlocksatus indicates whether the block 
   is locked or not
   value 1: Block Locked
   value 0: Block not Locked                                                 */
#define u8BLOCK_LOCKED                 0x02
#define u8BLOCK_UNLOCKED               0xFD  

/* Macro to extract bit 2 of u8GeneralBlocksatus indicates whether the block 
   is canceled or not
   value 1: Block Canceled 
   value 0: Block not Canceled                                                */
#define u8BLOCK_CANCELED                 0x04
#define u8BLOCK_NOT_CANCELED             0xFB 


/******************************************************************************/
/*                       Miscellaneous                                        */
/******************************************************************************/
/* !MComment: State of NVRAM block                                            */
#define u8INVALID ((uint8)(0))
#define u8VALID_UNCHANGED ((uint8)(1))
#define u8VALID_CHANGED ((uint8)(2))


/* !Comment: Multi Block Reserved ID                                          */
#define udtMULTI_BLOCK_ID ((NvM_BlockIdType)(0))
/* !Comment: Configuration Block Reserved ID                                  */
#define udtCONFIG_BLOCK_ID ((NvM_BlockIdType)(1))

/* !Trace_To        : GSCSW-NVM-SDD-001-0017                                  */
/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to MemIf API implementation                      */
/*lint -save -vo -e750 -v                             */

/* !Comment: Broad Cast ID of MemIf                                           */

#define u8MEMIF_BROADCAST_ID ((uint8)0xFF)
/*lint -restore                                                               */

/* !MComment: Types of ReadAll Runtime preparation                            */
#define u8NORMAL_RUN ((uint8)0x00)
#define u8EXTENDED_RUN ((uint8)0x01)

/* !Comment: Immediate priority Job                                           */

#define u8IMMEDIATE_PRIORITY ((uint8)0x00)


#if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Comment: Indicates that this function didn't make any DET error         */
  #define u8NO_DET_ERROR ((uint8)(0xFF))
#endif /* (NVM_DEV_ERROR_DETECT == STD_ON)  */

/* !Comment: Mask used to identify if the block is pending in general.
i.e. SB or MB, it doesn't matter.                                             */
#define u8PENDING_MASK ((uint8)(0x0F))

/* !Comment: Block is pending by Single Block Job                             */
#define u8PEND_SINGLEBLK_JOB ((uint8)(0x12))
/* !Comment: Block is pending by Multiple Block Job                           */
#define u8PEND_MULTIBLK_JOB ((uint8)(0x22))
/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/
/******************************************************************************/
/*  !Description : Macros used to Set, Clear and Check bits of 
                   u8GeneralBlocksatus defined in  NvM_astrAdminBlock 
				   for each block                                             */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3453]: Reason: Optimization. It is more   */
/*              efficient to implement it as a Macro not as a function.       */
/* PRQA S 3453 ++                                                             */ 
#define u8SET_GENERAL_BLOCK(blockid, bitmask) \
  ((NvM_astrAdminBlock[blockid].u8GeneralBlocksatus) |= ((uint8)(bitmask)))
#define u8CLEAR_GENERAL_BLOCK(blockid, bitmask) \
  ((NvM_astrAdminBlock[blockid].u8GeneralBlocksatus) &= ((uint8)(bitmask)))
  
#define u8CHECK_GENERAL_BLOCK(blockid, bitmask) \
  (((NvM_astrAdminBlock[blockid].u8GeneralBlocksatus) & ((uint8)(bitmask))) == ((uint8)(bitmask)))
  
/* PRQA S 3453 --                                                             */ 
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/*  !Description : Macro used to call the write block process incase of Imdt SB
                   Job is under process. In the future if different process than
				   the write can be assigned to immediate priority then this
                   Macro can be easily replaced by a function                 */
/******************************************************************************/
#define vidMFNIMDTSBJOB() vidWriteBlkPrcs()
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  */


#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* !Description : Macro that initializes invalid block process.It initializes */
/*                the state of the invalid process. It calls the erase block  */
/*                process initialization function                             */
/******************************************************************************/

#define vidINVALIDBLKPRCSINIT() vidEraseBlkPrcsInit()

/******************************************************************************/
/* !Description : Macro for Invalidate NV Block process. It is called at every
                  Mnf cycle if it is in progress. It calls the Erase Block
				  process.                                                    */

/******************************************************************************/


#define vidINVALIDBLKPRCS() vidEraseBlkPrcs()
#endif /*  (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)  */


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : Macros used to map the standard queue functions to the
                  immediate Job Q Functions incase of Job Priority is disabled,
				          this is because immediate Q is a FCFS Q             */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [3453]: Reason: Optimization. It is more   */
/*              efficient to implement it as a Macro not as a function.       */
/* !Trace_To        : GSCSW-NVM-SDD-001-0019                                  */
/* PRQA S 3453 ++                                                             */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  #define u8ENQ_IN_STDJOBQ(u8JobIdentifier,udtBlockIden,pu8RamBlkAddress)\
    u8EnqInStdJobQ(u8JobIdentifier,udtBlockIden,pu8RamBlkAddress)
  #define vidFETCHJOB_IN_STDJOBQ() vidFetchJobInStdJobQ()
  #define vidDEQ_OUT_STDJOBQ() NvM_vidDeqOutStdJobQ()
  #define bIS_STDJOBQ_EMPTY()  bIsStdJobQEmpty()
#else
  #define u8ENQ_IN_STDJOBQ(u8JobIdentifier,udtBlockIden,pu8RamBlkAddress)\
    u8EnqInImdtJobQ(u8JobIdentifier,udtBlockIden,pu8RamBlkAddress)
  #define vidDEQ_OUT_STDJOBQ() vidDeqOutImdtJobQ()
  #define vidFETCHJOB_IN_STDJOBQ() vidFetchJobInImdtJobQ()
  #define bIS_STDJOBQ_EMPTY()  bIsImdtJobQEmpty()
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  */

/******************************************************************************/
/*  !Description : Macro used to check if the passed block ID is in the valid
                   range                                                      */
/******************************************************************************/

#if (NVM_DEV_ERROR_DETECT == STD_ON)
  #define bIS_BLKID_INUSERRANGE(udtBlockId)\
  (((udtBlockId) != udtMULTI_BLOCK_ID) && ((udtBlockId ) <= \
  ((NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS)))
#endif /* (NVM_DEV_ERROR_DETECT == STD_ON)  */

/******************************************************************************/
/*  !Description : Macro used to access the CRC slot in Ram                   */
/******************************************************************************/

#define pu8RAM_BLK_CRC_PTR(udtBlockId)\
  (NvM_akstreBlockDescriptor[udtBlockId].pu8RamBlockCrcAddress)

/******************************************************************************/
/*  !Description : Macro used check if an NvM block is pending                */
/******************************************************************************/
#define bIS_BLOCK_PENDING(udtBlockId)\
  (((NvM_astrAdminBlock[(udtBlockId)].u8ErrorStatus) & u8PENDING_MASK) == NVM_REQ_PENDING)

/* PRQA S 3453 --                                                             */


/******************************************************************************/
/******************************************************************************/
/*                            Type Definitions                                */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* !Comment: Type of container used to store adminstrative block of NVRAM     */
/*           blocks                                                           */
/* !Trace_To: GSCSW-NVM-SDD-001-0433                                           */
/******************************************************************************/
typedef struct
{
  /* !Comment: Internal validity/modification state of the NVRAM block.       */
  /* !Range: [u8INVALID, u8VALID_UNCHANGED, u8VALID_CHANGED]                  */
  /* NotProtected (Not the responsiblity of the NvM to protect it)            */
  uint8 u8State;
  /* !Trace_To: GSCSW-NVM-SDD-001-0503                                        */
  /* !Comment: Error status of the last requested job on the block.           */
  /* !Range: [0..8]                                                           */
  /* Protected using Critical Section (NVM_ACCESS_001)                        */
  NvM_RequestResultType u8ErrorStatus;
  /*!Comment:General Block status used for Block protection, block locked 
  and block canceled flags */
  /* !Range: [0..8]                                                           */
  /* Protected using Critical Section (NVM_ACCESS_001)                        */
  uint8 u8GeneralBlocksatus;
  /* !Comment: Index of the current DataSet pointed in the NVRAM block.       */
  /* !Range: [0..255]                                                         */
  /* NotProtected (Not the responsiblity of the NvM to protect it)            */
  uint8 u8DataSetIndex;
}tstrAdminBlockType;

/******************************************************************************/
/*                                  States Types                              */
/******************************************************************************/
/******************************************************************************/
/* !Comment: Type define for the State of SB process                          */
typedef enum
{
  WRB_CALC_RAM_BLK_CRC = 0,
  WRB_WAIT_MEMIF_WRT,
  WRB_WAIT_WRITE_END,
#if(NVM_u16VERIFY_BUFFER_SIZE != 0U)
  WRB_WAIT_WRT_VERIFY,
#endif
#if(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
  WRB_CALL_APP_COPY,
#endif
  #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
    RDB_PRE_CALC_RAM_CRC,
  #endif  /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */
  RDB_WAIT_MEMIF_READ,
  RDB_WAIT_READ_END,
  RDB_CALC_CRC_AND_CMP,
#if(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
  RDB_CALL_APP_COPY,
#endif
  RDB_WRT_RDDT_BLK,
  RDB_RSTR_BLK_PRCS
  #if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
    ,
    ERS_WAIT_MEMIF_ERS,
    ERS_WAIT_ERASE_END
  #endif
}tenuSBPrcsStateType;

/******************************************************************************/
/* !Comment: Type define for the State of writing of the first redundant Block
             to restore redundancy                                            */
typedef enum
{
  RDB_WAIT_MEMIF_IDLE,
  RDB_WAIT_WRITE_END
}tenuWrtRddtBlkStateType;

#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
/******************************************************************************/
/* !Comment: Type define for the State of write verification of the block     */
typedef enum
{
  WRB_WAIT_MEMIF_IDLE,
  WRT_WAIT_READ_END
}tenuWrtVerifyStateType;
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

/******************************************************************************/
/* !Comment: Type define for the State of MB process                          */
typedef enum
{
  WRA_XWRITE_CFG_ID = 0,
  WRA_WAIT_MEMIF_IDLE,
  WRA_XCALL_WRB,
  WRA_DEINIT_IF_IDLE,
  RDA_XREAD_CFG_ID,
  RDA_WAIT_MEMIF_IDLE,
  RDA_XCALL_RDB,
 #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
  RDA_XCALL_RSTRB_DFTS,
 #endif
  RDA_DEINIT_IF_IDLE
}tenuMBlkPrcsStateType;

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/******************************************************************************/
/* !Comment: Type define for the State of Back Ground CRC process             */
typedef enum
{
  BGD_CRC_IDLE = 0,
  BGD_CRC_ACTIVE
}tenuBGndCrcPrcsStateType;
#endif  /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )) */
/******************************************************************************/

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/*                                Queue Management Types                      */
/******************************************************************************/

/******************************************************************************/
/* !Comment: Type of Immediate Job Queue adminstration structure.             */
typedef struct
{
  /* !Comment: Enqueue index of Immediate Job Queue. It will be used
  by the Write API to know the index of the new entry                         */
  uint8 u8EnqInIndex;

  /* !Comment: Dequeue index of Immediate Job Queue. It will be used
  by the Write API to know the index of the next dequeue index                */
  uint8 u8DeqOutIndex;

  /* !Comment: Number of Queued Jobs                                          */
  uint8 u8NumOfQuedJobs;
}tstrImdtQAdmintype;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/* !Comment: Type of Immediate Job Queue adminstration structure.             */
typedef struct
{
  /* !Comment: Dequeue index of Standard Job Queue. It contains the index of the
  currently processed Job                                                     */
  uint8 u8DeqOutIndex;

  /* !Comment: Number of Queued Jobs                                          */
  uint8 u8NumOfQuedJobs;
}tstrStdQAdmintype;
#endif  /*  (NVM_JOB_PRIORITIZATION == STD_ON)   */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/* !Comment: Type of Immediate Job structure.                                 */
typedef struct
{
#if (NVM_JOB_PRIORITIZATION == STD_OFF)
  /* !Comment: Job ID                                                         */
  uint8 u8JobID;
#endif
/* !Comment: Block ID */
  NvM_BlockIdType udtBlockID;
/* !Comment: Ram Block Address                                                */
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddr;
}tstrImdtJobtype;

/******************************************************************************/
#if (NVM_JOB_PRIORITIZATION == STD_ON)
/* !Comment: Type of Standard Job structure.                                  */

typedef struct
{
/* !Comment: Job ID                                                           */
  uint8 u8JobID;
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockID;
/* !Comment: Ram Block Address                                                */
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddr;
}tstrStdJobtype;

#if( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
/* !Comment: Type for explicit Sync Delayed job.                              */
typedef struct
{
/* !Comment: Delayed job not served yet                                       */
  boolean bTimeToServeExpJob;
/* !Comment: Job ID                                                           */
  uint8 u8JobID;
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockID;
/* !Comment: Ram Block Address                                                */
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddr;
}tstrExpSyncDelJobtype;
#endif /*( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#endif /*  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  */

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/******************************************************************************/
/* !Comment: Type of Background CRC Queue adminstration structure.            */

typedef struct
{
  /* !Comment: Enqueue index of Immediate Job Queue. It will be used
               by the Write API to know the index of the new entry            */
  uint8 u8EnqInIndex;

  /* !Comment: Dequeue index of Immediate Job Queue. It will be used
               by the Write API to know the index of the next dequeue index   */
  uint8 u8DeqOutIndex;

  /* !Comment: Number of Queued Jobs                                          */
  uint8 u8NumOfQuedJobs;
}tstrBGndCrcQAdmintype;
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0)) */


/******************************************************************************/
/* !Comment: Type of Multi Block Job Buffer structure.                        */

typedef struct
{
/* !Comment: State of Multi Block Job Buffer.                                 */
/* !Range: [u8STARTED,u8PEND_BUTNOT_STARTED, u8EMPTY]                         */
  uint8 u8State;
/* !Comment: Job ID                                                           */
  uint8 u8JobID;
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockID;

}tstrMBJobBfrtype;
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/*                              Functions Prototypes                          */
/******************************************************************************/
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

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_CODE
/* !Trace_To        : GSCSW-NVM-SDD-001-0066                                  */
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* !Trace_To        : GSCSW-NVM-SDD-001-0014                                  */
static FUNC(Std_ReturnType, NVM_CODE) u8EnqInImdtJobQ
(
#if (NVM_JOB_PRIORITIZATION == STD_OFF)
  uint8 u8JobIdentifier,
#endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */
NvM_BlockIdType udtBlockIden,
P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddress
);

static FUNC(void, NVM_CODE) vidFetchJobInImdtJobQ(void);

static FUNC(void, NVM_CODE) vidDeqOutImdtJobQ(void);

#if ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
static FUNC(void, NVM_CODE) vidSwapJobInImdtQ(void);
#endif/*( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

static FUNC(boolean, NVM_CODE) bIsImdtJobQEmpty(void);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
static FUNC(Std_ReturnType, NVM_CODE) u8EnqInStdJobQ
( uint8 u8JobIdentifier,
  NvM_BlockIdType udtBlockIden,
  P2VAR(uint8,AUTOMATIC,NVM_APPL_DATA) pu8RamBlkAddress
);

static FUNC(void, NVM_CODE) vidFetchJobInStdJobQ(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidDeqOutStdJobQ(void);

static FUNC(boolean, NVM_CODE) bIsStdJobQEmpty(void);

#if( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
LOCAL_INLINE FUNC(uint8, NVM_CODE) NvM_u8SearchDeqOutStdQIdx(
                                 NvM_BlockIdType udtBlockID);
#endif /*( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

#endif  /*  (NVM_JOB_PRIORITIZATION == STD_ON)  */

#endif /*  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  */

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bIsStaticBlkIdConsis(void);

static FUNC(uint16, NVM_CODE) u16CalcTotalBlkLength(NvM_BlockIdType udtBlockIden);

static FUNC(uint8, NVM_CODE)  u8CalcBlkNumHdrBytes(void);

static FUNC(void, NVM_CODE) vidCopyCrc(uint16 u16BlockLength,
                                       uint8 u8NumHeadIdBytes,boolean bFromIntToRam);

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidEnqInBGndCrcQ(NvM_BlockIdType udtBlockIden);

LOCAL_INLINE FUNC(NvM_BlockIdType, NVM_CODE) NvM_udtFetchBGndCrcQ(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidDeqOutBGndCrcQ(void);

static FUNC(boolean, NVM_CODE) bIsBGndCrcQEmpty(void);
#endif  /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
             (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0)) */

static FUNC(void, NVM_CODE) vidUpdatStIfPermanenRAM( uint8 u8NewState );

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)

  #if (NVM_JOB_PRIORITIZATION == STD_ON)
    LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnCrashSBJob(void);

    LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnFreezeMBJob(void);
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

  LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnStdSBJob(void);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
  LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnImdtSBJobInit(void);
#endif

  LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnStdSBJobInit(void);
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidScanThenCancelJobs(void);
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

static FUNC(void, NVM_CODE) vidMfnJobsScanThenStart(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnMBJob(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnMBJobInit(void);

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
  static FUNC(void, NVM_CODE) vidEraseBlkPrcsInit(void);

  static FUNC(void, NVM_CODE) vidEraseBlkPrcs(void);

  static FUNC(void, NVM_CODE) vidStErsWaitMemIfAndErs(void);

  LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStErsWaitEraseEnd(void);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

static FUNC(void, NVM_CODE) vidRstrBlkDftsPrcsInit(void);

static FUNC(void, NVM_CODE) vidRstrBlkDftsPrcs(void);

static FUNC(void, NVM_CODE) vidReadBlkPrcsInit(void);

static FUNC(void, NVM_CODE) vidReadBlkPrcs(void);

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
static FUNC(void, NVM_CODE) vidRdBCallAppCopy(void);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1) */

static FUNC(void, NVM_CODE) vidStRdBWaitMemIfAndRd(void);

static FUNC(void, NVM_CODE) vidStRdBWaitReadEnd(void);

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStPreCalcCrcThenCmp(void);
#endif  /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

static FUNC(void, NVM_CODE) vidStRdBCalcCrcThenCmp(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdBWrtRddtBlk(void);

static FUNC(void, NVM_CODE) vidReadBErrorHook(void);

static FUNC(void, NVM_CODE) vidRdBPrcsDeInit(boolean bPrcsSuceeded);

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bRdBIsConfigIdConsis(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidReadAllPrcsInit(void);

static FUNC(void, NVM_CODE) vidReadAllPrcs(void);

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStRdARdBConfigID(void);

static FUNC(boolean, NVM_CODE) bStWaitMemIfIdle(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdACrossRdB(void);

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdACrossRstrBDfts(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidRdAHandleDynConfig(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidRdAUpdateConfigID(void);
#endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON)  */

static FUNC(void, NVM_CODE) vidWrBlkSelectNextSt(void);

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
static FUNC(Std_ReturnType, NVM_CODE) u8WrBCallAppCopy(void);
#endif

static FUNC(void, NVM_CODE) vidWriteBlkPrcsInit(void);

static FUNC(void, NVM_CODE) vidWriteBlkPrcs(void);

static FUNC(void, NVM_CODE) vidStWrBWaitMemIfAndWrt(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStWrBWaitWriteEnd(void);

#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
static FUNC(void, NVM_CODE) vidStWrBWriteVerify(void);
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

static FUNC(void, NVM_CODE) vidWrBErrorHook(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidWriteAllPrcsInit(void);

static FUNC(void, NVM_CODE) vidWriteAllPrcs(void);

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStWrAWrBConfigID(void);

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStWrACrossWrB(void);

static FUNC(void, NVM_CODE) vidWrAHookCancelRequest(void);

static FUNC(void, NVM_CODE) vidUpdateMBErrorStatus(void);

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
static FUNC(void, NVM_CODE) vidBckGndCrcPrcs(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStBgdCrcIdle(void);

static FUNC(void, NVM_CODE) vidStBgdCrcActive(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidBgdUpdateRamBlkCRC(void);
#endif  /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
            (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0)) */

static FUNC(void, NVM_CODE) vidServeNextBlk(void);

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidInitNextState(void);

static FUNC(boolean, NVM_CODE) bCompareRamBlkCRC(void);

static FUNC(void, NVM_CODE) vidStCalcRamCRCInit(void);

static FUNC(Std_ReturnType, NVM_CODE) u8StCalcRamBlkCRC(void);

static FUNC(void, NVM_CODE) vidUpdateRamBlkCRC(void);

static FUNC(void, NVM_CODE) vidSBPrcsDeInit(
  NvM_RequestResultType u8JobResult);

static FUNC(void, NVM_CODE) vidStMBPrcsDeInit(boolean bFreezeMBJob);

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
static FUNC(boolean, NVM_CODE) bIsDataSetIndexValid(
  NvM_BlockIdType udtBlockId,uint8 u8DataIndex);

static FUNC(boolean, NVM_CODE) bWillBlkBeServedByWA(NvM_BlockIdType udtBlockIden);
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
static FUNC(Std_ReturnType, NVM_CODE) u8EraseOrInvalidateBlk
(
 NvM_BlockIdType udtBlockId, uint8 u8JobId
);
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

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

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_CODE
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */


/******************************************************************************/
/******************************************************************************/
/*                           Private Shared Variables                         */
/******************************************************************************/
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

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

/* !Comment: Main Function State. (Major State of Mfn).
             Initialized after every reset to NvM_MFN_NOT_INIT                    */
/* !Range:  [NvM_MFN_NOT_INIT, NvM_MFN_JOBS_SCAN, NvM_MFN_IMDT_SB_JOB, NvM_MFN_STD_SB_JOB,
            NvM_MFN_MB_JOB]                                                       */
/* Not Protected (Accessed Only by Main Fn)                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0098                                  */
VAR(NvM_tenuMainFnStateType, NVM_VAR) NvM_enueMainFnState = NvM_MFN_NOT_INIT;


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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */


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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

/* !Comment: State of Single Block Job Process (Minor State of Mfn)           */
/* NotProtected (Accessed Only by Main Fn) */
static VAR(tenuSBPrcsStateType, NVM_VAR) NvM_enuSBPrcsState;

/* !Comment: State of Write operation of the first redundant block (the first
             redundant block is written because it failed during read
            (this is done to restore redundancy)                              */
static VAR(tenuWrtRddtBlkStateType,NVM_VAR) NvM_enuRdBlkWrtRddtBlkSt;

#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
static VAR(tenuWrtVerifyStateType,NVM_VAR) NvM_enuWrtVefifyState;
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

/* !Comment: State of MB process (Minor State of Mfn)                         */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(tenuMBlkPrcsStateType, NVM_VAR) NvM_enuMBlkPrcsState;

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/* !Comment: State of Back Ground CRC process                                 */
/* !Range:  [BGD_CRC_IDLE, BGD_CRC_ACTIVE]                                    */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(tenuBGndCrcPrcsStateType, NVM_VAR) NvM_enuBGndCrcPrcsState;

/* !Comment: Pointer to data buffer under back ground CRC calculation.        */
/* NotProtected (Accessed Only by Main Fn) but shared with external module API*/
static P2VAR(uint8,NVM_VAR,NVM_APPL_DATA) NvM_pu8BgndRamDataPtr;
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
          (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */

#if (NVM_POLLING_MODE == STD_OFF)
/* !Comment: Used by callbacks functions to signal the end of MemIf Job       */
/* NotProtected (No Simultaneous write access by Main Fn and Callbacks Fns)   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0201                                  */
  static VAR(MemIf_JobResultType, NVM_VAR) NvM_udtMemIfJobEndClBck;
#endif

/* !Comment: Pointer to data buffer under CRC calculation.                    */
/* NotProtected (Accessed Only by Main Fn)                                    */

static P2VAR(uint8, NVM_VAR, NVM_APPL_DATA) NvM_pu8RamDataPtrCrc;

/* !Comment: Current Ram Block Address                                        */
/* NotProtected (Accessed Only by Main Fn) but shared with external module API*/
static P2VAR(uint8, NVM_VAR, NVM_APPL_DATA) NvM_pu8CurrentRamBlkAddr;

/* !Comment: Declaration of adminstrative blocks of NVRAM blocks              */
/* Only Error Status is Protected by Critical Section (NVM_ACCESS_001)        */
/* !Trace_To: GSCSW-NVM-SDD-001-0433                                           */
static VAR(tstrAdminBlockType, NVM_VAR) NvM_astrAdminBlock[
  ((NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS) + (NvM_BlockIdType)1];


/* !Comment: Structure for storing incoming one multi block job request       */
/* !Trace_To        : GSCSW-NVM-SDD-001-0063                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0064                                  */
/* Protected using Critical Section (NVM_ACCESS_001)                          */

static VAR(tstrMBJobBfrtype, NVM_VAR) NvM_strMBJobBfr;

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

/* !Comment: Flag to be raised if cancellation of current write all job is
             requested.                                                       */
/* !Range:  [TRUE, FALSE]                                                     */
/* Protected using Critical Section (NVM_ACCESS_001)                          */
static VAR(boolean, NVM_VAR) NvM_bCancelWrtAllReq;

/* !Comment: Flag to be raised if first redundant block can't be read.        */
/* !Range:  [TRUE, FALSE]                                                     */
/*  Not Protected                                                             */
static VAR(boolean, NVM_VAR) NvM_bFrstRddtBlkFailed;

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* !Comment: Flag to be raised if any job is requested to be canceled for
             any block                                                        */
/* !Range:  [TRUE, FALSE]                                                     */
/* Protected using Critical Section (NVM_ACCESS_001)                          */
static VAR(boolean, NVM_VAR) NvM_bAnyCancelJobReq;
#endif

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON              )
/* !Comment: Flag is raised if an immediate job crashes a standard job        */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(boolean, NVM_VAR) NvM_bStdJobCrashed;
#endif

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON              ) && \
    (NVM_u16RAM_MIRROR_BUF_SIZE != 0U              )
/* !Comment: Flag is raised to indicate an explicit job is delayed            */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(boolean, NVM_VAR) NvM_bExpStdJobDelayed;
#endif
/* !Comment: Flag is raised to indicate that this is the first CRC call       */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(boolean, NVM_VAR) NvM_bIsFirstCrcCall;

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_8
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

/* !Comment: Single Block Job pre-error status .It is used to store the
             error status of the SB process and at the end of the process it
             updates the error status in the Admin Block                      */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(NvM_RequestResultType, NVM_VAR) NvM_u8SBPreErrorStatus;


/* !Comment: Multi Block pre-error status. It is used to store the error
             status of the MB process and at the end of the process it updates
             the error status in the Admin Block                              */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(NvM_RequestResultType, NVM_VAR) NvM_u8MBlkPreErrorStatus;

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/* !Comment: Background Pre Error status. Used to restore back the block error
             status after finishing the bgnd CRC calculation .                */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(NvM_RequestResultType, NVM_VAR) NvM_u8BgndPreErrorStatus;
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))                                 */


#if (NVM_udtNUM_OF_NVRAM_BLOCKS < (255U))
/* !Deviation : Bug in QAC */
/* PRQA S 3406 ++ */
  /* !Comment: Current Block ID                                               */
  /* !Range:  [0..255]                                                        */
  /* NotProtected (Accessed Only by Main Fn)                                  */
  VAR(NvM_BlockIdType, NVM_VAR) NvM_udteCurrentBlockID;
/* PRQA S 3406 -- */

  #if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
       (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
  /* !Comment: Block ID under Background CRC calculation.                     */
  /* !Range:  [0..65535]                                                      */
  /* NotProtected (Accessed Only by Main Fn)                                  */

  static VAR(NvM_BlockIdType, NVM_VAR) NvM_udtBgndBlkID;

  #endif /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
  (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */

#endif /* (NVM_udtNUM_OF_NVRAM_BLOCKS < (255U)) */


#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/* !Comment: Identify the ReadAll RunTime Preparation                         */
/* !Range: [u8NORMAL_RUN, u8EXTENDED_RUN]                                     */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint8, NVM_VAR) NvM_u8RdARunTimeMode;
#endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON) */

/* !Comment: Counter of write block retry recoveries.                         */
/* !Range:  [0..NVM_MAX_NUM_OF_WRITE_RETRIES]                                 */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(uint8, NVM_VAR) NvM_u8WriteRetriesCtr;

/* !Comment: Counter of read block retry recoveries.                          */
/* !Range:  [0..NVM_MAX_NUM_OF_READ_RETRIES]                                  */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint8, NVM_VAR) NvM_u8ReadRetriesCtr;

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
   && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
/* !Comment: Counter of Repeat Mirror Operation.                              */
/* !Range:  [0..NVM_REPEAT_MIRROR_OPERATIONS]                                 */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint8, NVM_VAR) NvM_u8RepeatMirrorOp;
#endif /*(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
        && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

/* !Comment: Current Job ID. It contains the current running job. Incase of
             cross called jobs it shall contain the original job not the cross
			       called one                                                 */
/* NotProtected (Accessed Only by Main Fn)                                    */


/* !Deviation : Bug in QAC */
/* PRQA S 3406 ++ */
VAR(uint8, NVM_VAR) NvM_u8eCurrentJobID;
/* PRQA S 3406 -- */
#if(NVM_USE_CRC8 == STD_ON)
/* !Comment:  Current value of the calculated CRC (8 bit).                    */
/* !Range:  [0..255]                                                          */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(uint8, NVM_VAR) NvM_u8Crc8Value;
#endif
#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))

#if(NVM_USE_CRC8 == STD_ON)
/* !Comment: Return Value CRC API for one calculation cycle.(For CRC type 8)  */
/* !Range:  [0..255]                                                          */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint8, NVM_VAR) NvM_u8BgndCrc8Value;
#endif
#endif /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
            (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_8
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_16
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
/* !Deviation : Bug in QAC */
/* PRQA S 3406 ++ */
  /* !Comment: Current Block ID                                               */
  /* !Range:  [0..65535]                                                      */
  /* NotProtected (Accessed Only by Main Fn)                                  */
  VAR(NvM_BlockIdType, NVM_VAR) NvM_udteCurrentBlockID;
/* PRQA S 3406 -- */

  #if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
       (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
  /* !Comment: Block ID under Background CRC calculation.                     */
  /* !Range:  [0..65535]                                                      */
  /* NotProtected (Accessed Only by Main Fn)                                  */

  static VAR(NvM_BlockIdType, NVM_VAR) NvM_udtBgndBlkID;

  #endif /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
  (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */

#endif /* (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U)) */

/* !Comment: Length of data buffer under CRC calculation.                     */
/* !Range:  [0..NVM_CRC_NUM_OF_BYTES]                                         */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(uint16, NVM_VAR) NvM_u16DataLengthCrc;

#if(NVM_u16VERIFY_BUFFER_SIZE != 0U)
/* !Comment: Number of remaining bytes that need to be verified for a block.  */
/* !Range:  [1..65535]                                                        */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16RemBlockLength;

/* !Comment: Block offset passed to MemIf in case of multiple write verification
             cycles.                                                          */
/* !Range:  [1..65535]                                                        */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16BlockOffset;

/* !Comment: Current write verification cycle                                 */
/* !Range:  [0..65535]                                                        */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16CurrentVerifCycle;

#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

/* !Comment: Pre DEM Error .It is used to store the
             reported DEM error and at the end of the process it is reported
             to DEM                                                           */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16PreDemError;
#if(NVM_USE_CRC16 == STD_ON)
/* !Comment:  Current value of the calculated CRC (16 bit).                   */
/* !Range:  [0..65535]                                                        */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(uint16, NVM_VAR) NvM_u16Crc16Value;
#endif
#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))

/* !Comment: Remaining Block Data Length  that Background CRC calculation is not
             performed on it yet.                                             */
/* !Range:  [0..NVM_CRC_NUM_OF_BYTES]                                         */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16BgndDataLengthCrc;

#if(NVM_USE_CRC16 == STD_ON)
/* !Comment: Return Value CRC API for one calculation cycle. (For CRC type 16)*/
/* !Range:  [0..65535]                                                        */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint16, NVM_VAR) NvM_u16BgndCrc16Value;
#endif

#endif /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
(NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */

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

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_16
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_32
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

#if(NVM_USE_CRC32 == STD_ON)
/* !Comment:  Current value of the calculated CRC (32 bit).                   */
/* NotProtected (Accessed Only by Main Fn)                                    */

static VAR(uint32, NVM_VAR) NvM_u32Crc32Value;
#endif
#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))

#if(NVM_USE_CRC32 == STD_ON)
/* !Comment: Return Value CRC API for one calculation cycle.(For CRC type 32) */
/* NotProtected (Accessed Only by Main Fn)                                    */
static VAR(uint32, NVM_VAR) NvM_u32BgndCrc32Value;
#endif
#endif /*  ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
            (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0))  */


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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_32
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */


#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
   &&(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
/* !Comment: Ram mirror buffer used for explicit synchronization mechanism.   */
/* NotProtected (Accessed Only by Main Fn)                                    */
/* !Trace_To        :                                  */
static VAR(uint8,NVM_VAR) NvM_au8RamMirrorBuffer[NVM_u16RAM_MIRROR_BUF_SIZE];
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)\
        &&(NVM_u16RAM_MIRROR_BUF_SIZE !=0U) */

/* !Comment: Internal Ram Buffer to combine the BlockId(if configured),Data and
             CRC (if configured).                                             */
/* NotProtected (Accessed Only by Main Fn)                                    */
/* !Trace_To        :                                                         */

/* !Deviation : inhibit MISRA rule [0612]: The size of internal RAM buffer    */
/*              depends on the configuration.                                 */
/* PRQA S 0612 ++                                                             */
/* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is    */
/*              already casted to uint16.                                     */
/* PRQA S 1255 ++                                                             */
static VAR(uint8,NVM_VAR) NvM_au8InternalRamBuffer[NVM_u16INTERNAL_RAM_BUF_SIZE];
/* PRQA S 1255 --                                                             */
/* PRQA S 0612 --                                                             */

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/*                             Queues Management                              */
/******************************************************************************/

/******************************************************************************/
/* !Comment: Immediate Single Block Job Queue                                 */
/* Protected using Critical Section (NVM_ACCESS_001)                          */

#if (NVM_JOB_PRIORITIZATION == STD_ON)

  static VAR(tstrImdtJobtype, NVM_VAR)
    NvM_astrImdtQ[NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#else
  static VAR(tstrImdtJobtype, NVM_VAR)
    NvM_astrImdtQ[NVM_SIZE_STANDARD_JOB_QUEUE];
#endif /* (NVM_JOB_PRIORITIZATION == STD_OFF)  */

/******************************************************************************/
/* !Comment: Immediate Job Queue adminstration structure */
/* Protected using Critical Section (NVM_ACCESS_001) */
static VAR(tstrImdtQAdmintype, NVM_VAR) NvM_strImdtQAdmin;

  #if (NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/*    !Comment: Standard Single Block Job Queue                               */
/*    Protected using Critical Section (NVM_ACCESS_001)                       */


     static VAR(tstrStdJobtype, NVM_VAR)
        NvM_astrStdSBJobQ[NVM_SIZE_STANDARD_JOB_QUEUE];

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
/******************************************************************************/
/*    !Comment: Information about delayed Explicit sycn. job                  */
/*    Not Protected                                                           */
static VAR(tstrExpSyncDelJobtype, NVM_VAR) NvM_strExpSyncDelayedJob;
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U ) */

/******************************************************************************/
/*    !Comment: Standard Job Queue adminstration structure                    */
/*    Protected using Critical Section (NVM_ACCESS_001)                       */
     static VAR(tstrStdQAdmintype, NVM_VAR) NvM_strStdQAdmin;

/******************************************************************************/
/*    !Comment: Standard Job Queue priority. It stores the priorities of the
                block IDs stored in the Std Job Queue. It reduces the
                searching time for the highest priority block ID              */
/*    Protected using Critical Section (NVM_ACCESS_001)                       */
     static VAR(uint8, NVM_VAR)
       NvM_au8StdQPriority[NVM_SIZE_STANDARD_JOB_QUEUE];

  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON)  */

#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/******************************************************************************/
/* !Comment: Background CRC Queue adminstration structure.                    */
/* Protected using Critical Section (NVM_ACCESS_002)                          */


static VAR(tstrBGndCrcQAdmintype, NVM_VAR) NvM_strBGndCrcQAdmin;

/******************************************************************************/
/* !Comment: Background CRC Queue                                             */
/* Protected using Critical Section (NVM_ACCESS_002)                          */

static VAR(NvM_BlockIdType, NVM_VAR)
NvM_audtBGndCrcQ[NVM_u8SIZE_BCKGND_CRC_QUEUE];
/******************************************************************************/
#endif /* (NVM_SET_RAM_BLOCK_STATUS_API)&&(NVM_u8SIZE_BCKGND_CRC_QUEUE)       */

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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */

/******************************************************************************/



/******************************************************************************/
/******************************************************************************/
/*                              Private Functions                             */
/******************************************************************************/
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
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_START_SEC_CODE
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* Functions used for Queue Management. Immediate , Standard Job or Background
Queues. Used by APIs and Processes                                            */
/******************************************************************************/

/* If NVM_JOB_PRIORITIZATION is OFF then Immediate Q shall be used as Standard
    Q (because its FCFS Q) and the Standard Priority Q will be disabled.
    This is done to avoid redundant code.                                     */

/******************************************************************************/
/* !Description : Function to Enqueue a Job in the Immediate Job Queue.       */
/******************************************************************************/

static FUNC(Std_ReturnType, NVM_CODE) u8EnqInImdtJobQ
(
#if (NVM_JOB_PRIORITIZATION == STD_OFF)
/* !Comment: Job ID                                                           */
  uint8 u8JobIdentifier,
#endif
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockIden,
/* !Comment: Ram Block Address                                                */
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddress
)
{
   P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs = 
                                       &NvM_strImdtQAdmin.u8NumOfQuedJobs;
   P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8EnqInIndex = 
                                       &NvM_strImdtQAdmin.u8EnqInIndex;
   P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtBlockID =
                    &NvM_astrImdtQ[NvM_strImdtQAdmin.u8EnqInIndex].udtBlockID;	
   #if (NVM_JOB_PRIORITIZATION == STD_OFF)
   P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8JobID =
                    &NvM_astrImdtQ[NvM_strImdtQAdmin.u8EnqInIndex].u8JobID;
   #endif			
					  
   /* !Pseudo: Return Value = NOT OK                                          */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
  #if (NVM_DEV_ERROR_DETECT == STD_ON)
    uint8 u8DetTypeOfError = u8NO_DET_ERROR;
  #endif
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo:  Open Critical Section */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */
  /* !Pseudo: if identified block is already pending */
  /* !Trace_To        : GSCSW-NVM-SDD-001-0073                                */
  if (bIS_BLOCK_PENDING(udtBlockIden))
  {
    #if (NVM_DEV_ERROR_DETECT == STD_ON)
    /* !Pseudo: Store DET Error                                               */
    u8DetTypeOfError = NVM_E_BLOCK_PENDING;
    #else
    /* !Pseudo: Report error to the DEM                                       */
    Dem_ReportErrorStatus(NVM_udtE_BLK_PENDING_PROD, DEM_EVENT_STATUS_FAILED);
    #endif
  }
  /* !Pseudo: Else if queue is full                                           */
  else
  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  if(*(pu8NumOfQuedJobs) >= NVM_SIZE_IMMEDIATE_JOB_QUEUE)
  #else
  if(*(pu8NumOfQuedJobs) >= NVM_SIZE_STANDARD_JOB_QUEUE)
  #endif
  {
    /* !Pseudo: Report error to the DEM                                       */
    /* !Trace_To: GSCSW-NVM-SDD-001-0310                                      */
    Dem_ReportErrorStatus(NVM_E_QUEUE_OVERFLOW, DEM_EVENT_STATUS_FAILED);
  }
  #if (NVM_JOB_PRIORITIZATION == STD_OFF)
  /* !Pseudo: Else if WriteAll Job is pending and not started and this block
  will be served by it            */
  else if (bWillBlkBeServedByWA(udtBlockIden) == (boolean)TRUE)
  {
     /* !Pseudo: Leave the Return Value as  NOT OK                            */
  }
  #endif
  /* !Pseudo: Else (Queue is not full)                                        */
  else
  {
    /* !Pseudo: Enqueue data element on current push index                    */
    *pudtBlockID = udtBlockIden;
    NvM_astrImdtQ[NvM_strImdtQAdmin.u8EnqInIndex].pu8RamBlkAddr = pu8RamBlkAddress;
    #if (NVM_JOB_PRIORITIZATION == STD_OFF)
    *pu8JobID = u8JobIdentifier;
    #endif

    /* !Pseudo: Tag block as pending                                          */
    NvM_astrAdminBlock[udtBlockIden].u8ErrorStatus = u8PEND_SINGLEBLK_JOB;

    /* !Pseudo: Update Enqueue index for next entry in queue                  */
    (*pu8EnqInIndex)++;

  #if (NVM_JOB_PRIORITIZATION == STD_ON)
    if (*(pu8EnqInIndex) >= NVM_SIZE_IMMEDIATE_JOB_QUEUE)
  #else
    if (*(pu8EnqInIndex) >= NVM_SIZE_STANDARD_JOB_QUEUE)
  #endif
    {
      *pu8EnqInIndex = (uint8)0;
    }

    /* !Pseudo: Increment Number of Queued Jobs                               */
    (*pu8NumOfQuedJobs)++;

    /* !Pseudo: Return Value = OK                                             */
    u8ReturnValue = E_OK;

  }
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo:  Close Critical Section                                         */
  SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */

  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Report stored DET Errors                                        */
  if(u8DetTypeOfError != u8NO_DET_ERROR)
  {
     #if (NVM_JOB_PRIORITIZATION == STD_OFF)
        (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
          u8JobIdentifier,u8DetTypeOfError);
     #else
        (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
          NvM_u8WRITE_BLOCK_ID,u8DetTypeOfError);
     #endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */
  }
  #endif

  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}

/******************************************************************************/
/* !Description : Function to Fetch the the First Come Job in the Imediate    */
/*                Job Queue.                                                  */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidFetchJobInImdtJobQ(void)
{
  /* This Fn is not protected by critical sections because its Deqout Index
  can't be accessed at the same time running this Fn                          */
  /* !Trace_To: GSCSW-NVM-SDD-001-0496                                        */
  /*  !Pseudo:   Using the dequeue index update the current Job parameters    */
  NvM_udteCurrentBlockID =
   NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].udtBlockID;

  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  NvM_u8eCurrentJobID = NvM_u8WRITE_BLOCK_ID;
  #else
  NvM_u8eCurrentJobID = NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].u8JobID;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  NvM_pu8CurrentRamBlkAddr =
   NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].pu8RamBlkAddr;
}

/******************************************************************************/
/* !Description : Function to Dequeue a Job from the Immediate Job Queue.     */
/******************************************************************************/

static FUNC(void, NVM_CODE) vidDeqOutImdtJobQ(void)
{
   P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8DeqOutIndex = 
                                    &NvM_strImdtQAdmin.u8DeqOutIndex;
	P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs = 
                                	&NvM_strImdtQAdmin.u8NumOfQuedJobs;
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo:  Open Critical Section                                          */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */

  /* !Pseudo:  Update Dequeue index for next output from queue                */
  (*pu8DeqOutIndex)++;
  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  if((*pu8DeqOutIndex) >= NVM_SIZE_IMMEDIATE_JOB_QUEUE)
  #else
  if((*pu8DeqOutIndex) >= NVM_SIZE_STANDARD_JOB_QUEUE)
  #endif
  {
    *pu8DeqOutIndex = (uint8)0;
  }

  /* !Pseudo:  Decrement Number of Queued Jobs                                */
  (*pu8NumOfQuedJobs)--;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo:  Close Critical Section                                         */
  SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
}

#if ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
/******************************************************************************/
/* !Description : Function to swap the current job with the next job in the
                  Imdt Q (this is done in case repeat mirror operation over-run
                  for jobs with explicit synchrounization                     */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidSwapJobInImdtQ(void)
{
  NvM_BlockIdType udtBlockId;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8CurrentRamAdd;
  uint8 u8NextDeqOutIndex;
  #if (NVM_JOB_PRIORITIZATION == STD_OFF)
  uint8 u8CurrentJobId;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */

  /*  !Pseudo:   Save the current served job     */
  udtBlockId =
   NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].udtBlockID;

  #if (NVM_JOB_PRIORITIZATION == STD_OFF)
  u8CurrentJobId = NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].u8JobID;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */

  pu8CurrentRamAdd =
   NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].pu8RamBlkAddr;

  
  u8NextDeqOutIndex = NvM_strImdtQAdmin.u8DeqOutIndex + (uint8)1 ;

  #if (NVM_JOB_PRIORITIZATION == STD_ON)

 if(u8NextDeqOutIndex >= NVM_SIZE_IMMEDIATE_JOB_QUEUE  )
#else

  if(u8NextDeqOutIndex >= NVM_SIZE_STANDARD_JOB_QUEUE  )
#endif
  {
   u8NextDeqOutIndex = (uint8)0;
  }
  else
  {
	/* Do nothing */
  }
  /*  !Pseudo:   Shift next job to be the first job in queue    */
  NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].udtBlockID =
    NvM_astrImdtQ[u8NextDeqOutIndex].udtBlockID;

  #if (NVM_JOB_PRIORITIZATION == STD_OFF)
  NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].u8JobID =
    NvM_astrImdtQ[u8NextDeqOutIndex].u8JobID;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */

  NvM_astrImdtQ[NvM_strImdtQAdmin.u8DeqOutIndex].pu8RamBlkAddr =
   NvM_astrImdtQ[u8NextDeqOutIndex].pu8RamBlkAddr;

  /*  !Pseudo:   Shift old job to be the next job in queue    */
  NvM_astrImdtQ[u8NextDeqOutIndex].udtBlockID = udtBlockId;

  #if (NVM_JOB_PRIORITIZATION == STD_OFF)
    NvM_astrImdtQ[u8NextDeqOutIndex].u8JobID = u8CurrentJobId;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_OFF) */

 NvM_astrImdtQ[u8NextDeqOutIndex].pu8RamBlkAddr = pu8CurrentRamAdd ;
}
#endif /*( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

/******************************************************************************/
/* !Description : Function to check if the immediate Q is empty.              */
/******************************************************************************/
static FUNC(boolean, NVM_CODE) bIsImdtJobQEmpty(void)
{

  /* !Pseudo: If queue state is empty return TRUE                             */
  /* !Pseudo: Else return FALSE                                               */
  boolean bReturnValue = (boolean)FALSE;
  if((NvM_strImdtQAdmin.u8NumOfQuedJobs) == (uint8)0)
  {
    bReturnValue = (boolean)TRUE;
  }

  return(bReturnValue);
}

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/* !Description : Function to Enqueue a Job in the Standard Job Queue.        */
/******************************************************************************/
/* !Comment : OK if Job is queued in the Queue and Not OK if the Queue is full*/
/* !Trace_To        : GSCSW-NVM-SDD-001-0074                                  */

static FUNC(Std_ReturnType, NVM_CODE) u8EnqInStdJobQ
( uint8 u8JobIdentifier,
  NvM_BlockIdType udtBlockIden,
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddress )
{
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs = 
                                         &NvM_strStdQAdmin.u8NumOfQuedJobs;
  uint8 u8SearchIndex;
  boolean bEmtySlotFound;
  /* !Pseudo: Return Value = NOT OK                                           */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  uint8 u8DetTypeOfError = u8NO_DET_ERROR;
  #endif

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo:  Open Critical Section                                          */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */
  u8SearchIndex = (uint8)0;
  bEmtySlotFound = (boolean)FALSE;

  /* !Pseudo: if identified block is already pending
     or WriteAll Job is pending and the block will be served by it            */
/* !Trace_To        : GSCSW-NVM-SDD-001-0073                                  */
  if (bIS_BLOCK_PENDING(udtBlockIden))
  {
    #if (NVM_DEV_ERROR_DETECT == STD_ON)
    /* !Pseudo: Store DET Error                                               */
    u8DetTypeOfError = NVM_E_BLOCK_PENDING;
    #else
    /* !Pseudo: Report error to the DEM                                       */

    Dem_ReportErrorStatus(NVM_udtE_BLK_PENDING_PROD, DEM_EVENT_STATUS_FAILED);
    #endif
  }

  /* !Pseudo: Else if queue is full                                           */
  else if((*pu8NumOfQuedJobs) >= NVM_SIZE_STANDARD_JOB_QUEUE)
  {
    /* !Pseudo: Report error to the DEM                                       */
    /* !Trace_To: GSCSW-NVM-SDD-001-0310                                      */
    Dem_ReportErrorStatus(NVM_E_QUEUE_OVERFLOW, DEM_EVENT_STATUS_FAILED);
  }
  /* !Pseudo: Else if WriteAll Job is pending and not started and this block
  will be served by it            */
  else if (bWillBlkBeServedByWA(udtBlockIden) == (boolean)TRUE)
  {
     /* !Pseudo: Leave the Return Value as  NOT OK                            */
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: Search for 1st empty slot                                     */
    while(bEmtySlotFound != (boolean)TRUE)
    {
      /* !Pseudo: if empty slot found                                         */
      if (NvM_astrStdSBJobQ[u8SearchIndex].u8JobID == u8EMPTYSLOT)
      {
        /*  !Pseudo: Enqueue data element on current enqueue index            */
        NvM_au8StdQPriority[u8SearchIndex] =
        NvM_akstreBlockDescriptor[udtBlockIden].u8BlockJobPriority;
        NvM_astrStdSBJobQ[u8SearchIndex].u8JobID = u8JobIdentifier;
        NvM_astrStdSBJobQ[u8SearchIndex].udtBlockID = udtBlockIden;
        NvM_astrStdSBJobQ[u8SearchIndex].pu8RamBlkAddr = pu8RamBlkAddress;
        /* !Pseudo: Raise found empty slot flag to stop searching             */
        bEmtySlotFound = (boolean)TRUE;
      }
      /* !Pseudo: Increment search index                                      */
      u8SearchIndex++;
    }
    /* !Pseudo:  Tag block as pending                                         */
    NvM_astrAdminBlock[udtBlockIden].u8ErrorStatus = u8PEND_SINGLEBLK_JOB;

    /* !Pseudo: Increment Number of Queued Jobs                               */
    (*pu8NumOfQuedJobs)++;

    /* !Pseudo: Return Value = E_OK                                           */
    u8ReturnValue = E_OK;

  }

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* !Pseudo:  Close Critical Section                                         */
  SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */

  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Report stored DET Errors                                        */
  if(u8DetTypeOfError != u8NO_DET_ERROR)
  {
     /* !Trace_To: GSCSW-NVM-SDD-001-0334, GSCSW-NVM-SDD-001-0338,
                   GSCSW-NVM-SDD-001-0342, GSCSW-NVM-SDD-001-0347,
                   GSCSW-NVM-SDD-001-0352*/
     (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
        u8JobIdentifier,u8DetTypeOfError);
  }
  #endif

  return(u8ReturnValue);
}

/******************************************************************************/
/* !Description : Function to Fetch the higher priority Job in the Standard Job
                  Queue.                                                      */
/* !Trace_To : GSCSW-NVM-SDD-001-0074                                         */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidFetchJobInStdJobQ(void)
{

  uint8_least u8Ctr;
  uint8_least u8HPrJobIdx;
#if ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtExpSyncBlockID = 
                                         &NvM_strExpSyncDelayedJob.udtBlockID;
#endif
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8DeqOutIndex = 
										 &NvM_strStdQAdmin.u8DeqOutIndex;
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo:  Open Critical Section                                          */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */

  /* !Pseudo: If not restaring a crashed job by an Immediate job              */
  if(NvM_bStdJobCrashed != (boolean)TRUE)
  {
     /* !Pseudo: Search for the Higher Priority Job in the Non Empty Slots    */

     /* Assume that the 1st non empty slot has the higher priority            */
     for(u8HPrJobIdx = (uint8)0; ((NvM_astrStdSBJobQ[u8HPrJobIdx].u8JobID ==
        u8EMPTYSLOT)
#if (NVM_JOB_PRIORITIZATION == STD_ON) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
        || (NvM_astrStdSBJobQ[u8HPrJobIdx].udtBlockID == *pudtExpSyncBlockID)
#endif
        ); u8HPrJobIdx++)
     {
        /* Do Nothing */
     }

     for(u8Ctr = (uint8)0; u8Ctr < NVM_SIZE_STANDARD_JOB_QUEUE; u8Ctr++)
     {
       if( (NvM_au8StdQPriority[u8Ctr] < NvM_au8StdQPriority[u8HPrJobIdx] )
#if (NVM_JOB_PRIORITIZATION == STD_ON) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
         && (NvM_astrStdSBJobQ[u8Ctr].udtBlockID != *pudtExpSyncBlockID)
#endif
         )
       {
         /* !Deviation : Inhibit MISRA rule [3212]: uint8_least can be        */
         /*              different than uint8 in different Hardware           */
         /* PRQA S 3212 ++                                                    */	   
         u8HPrJobIdx = (uint8)u8Ctr;
		 /* PRQA S 3212 --                                                    */
       }
     }
     /* !Pseudo: Update the Dequeue Index                                     */
	 /* !Deviation : Inhibit MISRA rule [3212]: uint8_least can be            */
     /*              different than uint8 in different Hardware               */
     /* PRQA S 3212 ++                                                        */
     *pu8DeqOutIndex = (uint8)u8HPrJobIdx;
	 /* PRQA S 3212 --                                                        */
  }
  /* !Trace_To: GSCSW-NVM-SDD-001-0491                                        */
  /* !Trace_To: GSCSW-NVM-SDD-001-0495                                        */
  else
  {
     /* !Pseudo: Restore the last crashed job Index in the queue. Note that   */
     /* dequeue out index didn't change since the job has been crashed        */
     u8HPrJobIdx = *pu8DeqOutIndex;
     /* !Pseudo: Reset Standard job crashed flag                              */
     NvM_bStdJobCrashed = (boolean)FALSE;
  }
  /*  !Pseudo:   Using the dequeue index update the current Job parameters    */
  NvM_udteCurrentBlockID = NvM_astrStdSBJobQ[u8HPrJobIdx].udtBlockID;
  NvM_u8eCurrentJobID = NvM_astrStdSBJobQ[u8HPrJobIdx].u8JobID;
  NvM_pu8CurrentRamBlkAddr = NvM_astrStdSBJobQ[u8HPrJobIdx].pu8RamBlkAddr;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo:  Close Critical Section                                         */
  SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
}

/******************************************************************************/
/* !Description : Function to Dequeue a Job from the Standard Job Queue.      */
/******************************************************************************/

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidDeqOutStdJobQ(void)
{
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs
                                         = &NvM_strStdQAdmin.u8NumOfQuedJobs;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8JobID
            = &NvM_astrStdSBJobQ[NvM_strStdQAdmin.u8DeqOutIndex].u8JobID;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8DeqOutIndex
            = &NvM_au8StdQPriority[NvM_strStdQAdmin.u8DeqOutIndex];
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo:  Open Critical Section                                          */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */

  /* !Pseudo:  Dequeue data element by marking it as empty slot               */
  *pu8JobID = u8EMPTYSLOT;
  /* This instruction makes searching faster (in Fetch Job Fn )using the
  priority entry only because empty slots are with the lowest priority (255)  */
  *pu8DeqOutIndex = u8LOWEST_PRIORITY;

  /* !Pseudo:  Decrement Number of Queued Jobs                                */
  (*pu8NumOfQuedJobs)--;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo:  Close Critical Section                                         */
  SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
}

/******************************************************************************/
/* !Description : Function to check if the standard Q is empty.               */
/******************************************************************************/
static FUNC(boolean, NVM_CODE) bIsStdJobQEmpty(void)
{

  boolean bReturnValue = (boolean)FALSE;
  /* !Pseudo: If queued jobs = 0 then return TRUE                             */
  /* !Pseudo: Else return false                                               */
  if((NvM_strStdQAdmin.u8NumOfQuedJobs) == (uint8)0)
  {
    bReturnValue = (boolean)TRUE;
  }
  return(bReturnValue);
}

#if ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
/******************************************************************************/
/* !Description : Function to check if the standard Q is empty.               */
/* !Comment : Return the block index inside the Sdt Q                         */
/******************************************************************************/

LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_u8SearchDeqOutStdQIdx
(
/* !Comment : Block ID  */
  NvM_BlockIdType udtBlockID
 )
{
  uint8 u8RetValue=(uint8)0;
  uint8_least u8Ctr;

  for(u8Ctr = (uint8)0; u8Ctr < NVM_SIZE_STANDARD_JOB_QUEUE; u8Ctr++)
  {
    if (NvM_astrStdSBJobQ[u8Ctr].udtBlockID == udtBlockID)
    {
	 /* !Deviation : Inhibit MISRA rule [3212]: uint8_least can be        */
     /*              different than uint8 in different Hardware           */
     /* PRQA S 3212 ++                                                    */	
      u8RetValue = (uint8)u8Ctr;
	 /* PRQA S 3212 --                                                    */
    }
  }
  return u8RetValue;
}
#endif /*( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

#endif /* (NVM_JOB_PRIORITIZATION == STD_ON)  */

#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

/******************************************************************************/
/* !Description : Compare the Read Static block ID with the stored one.       */
/******************************************************************************/
/* !Comment : Return TRUE if the static block ID match, Else , return FALSE   */
LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bIsStaticBlkIdConsis(void)
{
  boolean bReturnValue = (boolean)TRUE;
  uint8 u8BlockHeadId;
#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  uint16 u16BlkHeaderId=(uint16)0;
  uint8 au8BlkStaticId[2];
#endif  /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U) )*/

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  if ( NvM_udteCurrentBlockID < (NvM_BlockIdType) 255 )
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U) )*/
  {
/* !Deviation : Inhibit MISRA rule [3212]: The casting to uint8 is needed   */
/*              in case NVM_udtNUM_OF_NVRAM_BLOCKS >=255U                   */
/* PRQA S 3212 ++                                                           */
    u8BlockHeadId = (uint8)NvM_udteCurrentBlockID;
/* PRQA S 3212 --                                                           */
  }

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  else
  {
    u16BlkHeaderId = NvM_udteCurrentBlockID;
  }
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))*/

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  /* !Pseudo: If the current processed block ID is less than 255              */
  if ( NvM_udteCurrentBlockID < (NvM_BlockIdType) 255 )
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))*/
  {
    /* !Deviation : inhibit MISRA rule [3353]: u8BlockHeadId will always be set
                    before it is used                                         */
    /* PRQA S 3353 ++                                                         */
    /* !Pseudo: If the Read Static Block Id is not equal to the stored one    */
    if (u8BlockHeadId != NvM_au8InternalRamBuffer[0])
    {
      /* !Pseudo: Set The Return Value to FALSE                                 */
      bReturnValue = (boolean)FALSE;
    }
    /* PRQA S 3353 --                                                         */
  }
#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  /* !Pseudo: Else, ( current processed block ID is >= 255 )                    */
  else
  {
    au8BlkStaticId[0] = (uint8)u16BlkHeaderId;
    au8BlkStaticId[1] = (uint8)(u16BlkHeaderId >> 8);
    /* !Pseudo: If the Read Static Block Id is not equal to the stored one      */
    if( (au8BlkStaticId[0] != NvM_au8InternalRamBuffer[0]) ||
      (au8BlkStaticId[1] != NvM_au8InternalRamBuffer[1]) )
    {
      /* !Pseudo: Set The Return Value to FALSE                                 */
      bReturnValue = (boolean)FALSE;
    }
  }
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))*/

  return(bReturnValue);
}

/******************************************************************************/
/* !Description : Function to calculate the total block length including
                  CRC bytes and block ID Header Bytes.                        */
/******************************************************************************/
/* !Comment : Return the Total length of the block                            */
static FUNC(uint16, NVM_CODE) u16CalcTotalBlkLength
(
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockIden
)
{
  uint8  u8BlkIdHeaderBytes = (uint8)0;
  uint8  u8NumOfCrcBytes = (uint8)0;
  uint16 u16RetValue;

  /* !Pseudo: If the block uses Static Block ID check                         */
  if ( NvM_akstreBlockDescriptor[udtBlockIden].bStaticBlockIDCheck
         == (boolean)TRUE )
  {
#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
    if ( udtBlockIden < (uint16)255)
#endif
    {
      /* !Pseudo: If the block Identifier < 255 then set the number of Block
                  ID Header bytes to 1                                        */
      u8BlkIdHeaderBytes = (uint8)1;
    }
#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
    else
    {
      /* !Pseudo: If the block Identifier >= 255 then set the number of Block
                  ID Header bytes to 2                                        */
      u8BlkIdHeaderBytes = (uint8)2;
    }
#endif
  }

  /* !Pseudo: If the block uses CRC                                           */
  if(NvM_akstreBlockDescriptor[udtBlockIden].bBlockUseCrc
      == (boolean)TRUE)
  {
/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */

    /* !Pseudo: calculate the number of CRC bytes based on the CRC type
                (CRC8 , CRC16 or CRC32)                                       */
    switch (NvM_akstreBlockDescriptor[udtBlockIden].u8BlockCrcType)
    {
#if (NVM_USE_CRC8 == STD_ON)
	    case NVM_CRC8:
	    {
	      u8NumOfCrcBytes = u8CRC8_NUM_OF_BYTES;
	      break;
	    }
#endif

#if (NVM_USE_CRC16 == STD_ON)
	    case NVM_CRC16:
	    {
	      u8NumOfCrcBytes = u8CRC16_NUM_OF_BYTES;
	      break;
	    }
#endif

#if (NVM_USE_CRC32 == STD_ON)
	   case NVM_CRC32:
     {
       u8NumOfCrcBytes = u8CRC32_NUM_OF_BYTES;
       break;
     }
#endif
	   default:
         break;
   }
/* PRQA S 3352 --                                                           */
  }
  /* !Pseudo: calculate total length of the block
              ( BlockId Header length + block length + CRC length )           */
  u16RetValue = NvM_akstreBlockDescriptor[udtBlockIden].u16NvBlockLength
                + (uint16)(u8BlkIdHeaderBytes + u8NumOfCrcBytes);

 /* !Pseudo: Return the total length of the block                             */
  return(u16RetValue);
}

/******************************************************************************/
/* !Description : Function to calculate the number of header bytes used for
                  the given block                                             */
/******************************************************************************/
/* !Comment : Return the number of bytes used for Block Id Check              */
static FUNC(uint8, NVM_CODE)  u8CalcBlkNumHdrBytes(void)
{
  uint8 u8ReturnValue;

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  if ( NvM_udteCurrentBlockID < (NvM_BlockIdType) 255 )
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U) )*/
  {
    u8ReturnValue = 1U;
  }

#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
  else
  {
    u8ReturnValue = 2U;
  }
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))*/

  return(u8ReturnValue);
}


/******************************************************************************/
/* !Description : Copy Crc Data From Internal Buffer to Ram Block Crc
                  Address OR from RAM Block CRC to Internal Buffer            */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidCopyCrc
(
/* !Comment: Block Length                                                     */
  uint16 u16BlockLength,
/* !Comment: Number of Block Header ID Bytes for this block                   */
 uint8 u8NumHeadIdBytes,
/* !Comment: From Internal RAM to Block RAM CRC Address                       */
  boolean bFromIntToRam
)
{
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8CrcAddPtr;

  pu8CrcAddPtr = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                                                        .pu8RamBlockCrcAddress;
  /* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
  /*                execution paths due to certain configurations             */
  /* PRQA S 3352 ++                                                           */
  switch (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockCrcType)
  {
    #if (NVM_USE_CRC8 == STD_ON)
    case NVM_CRC8:
    {
      if ( bFromIntToRam == (boolean) TRUE )
      {
        pu8CrcAddPtr[(uint8)0] =
          NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)];
      }
      else
      {
        NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)] =
           pu8CrcAddPtr[(uint8)0];
      }
      break;
    }
    #endif

    #if (NVM_USE_CRC16 == STD_ON)
    case NVM_CRC16:
    {
      if ( bFromIntToRam == (boolean) TRUE )
      {
        pu8CrcAddPtr[(uint8)0]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)];

        pu8CrcAddPtr[1]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 1)];
      }
      else
      {
        NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)]
          = pu8CrcAddPtr[(uint8)0];

        NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 1)]
          = pu8CrcAddPtr[1];
      }
      break;
    }
    #endif

    #if (NVM_USE_CRC32 == STD_ON)
    case NVM_CRC32:
      {
        if ( bFromIntToRam == (boolean) TRUE )
        {
          pu8CrcAddPtr[0]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)];

          pu8CrcAddPtr[1]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 1)];

          pu8CrcAddPtr[2]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 2)];

          pu8CrcAddPtr[3]=
            NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 3)];
        }
        else
        {
          NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes)]
            = pu8CrcAddPtr[0];

           NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 1)]
            = pu8CrcAddPtr[1];

          NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 2)]
           = pu8CrcAddPtr[2];

          NvM_au8InternalRamBuffer[(uint16)(u16BlockLength + u8NumHeadIdBytes + 3)]
           = pu8CrcAddPtr[3];
        }
        break;
      }
    #endif

    default:
    break;
  }
/* PRQA S 3352 --                                                           */
}

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
     (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      ))
/******************************************************************************/
/* !Description : Function to Enqueue a back ground CRC request in its Queue. */
/******************************************************************************/

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidEnqInBGndCrcQ
(
/* !Comment: Block ID                                                         */
  NvM_BlockIdType udtBlockIden
)
{
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs 
             = &NvM_strBGndCrcQAdmin.u8NumOfQuedJobs;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8EnqInIndex 
             = &NvM_strBGndCrcQAdmin.u8EnqInIndex;
  P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtBGndQEnqBlockId
             = &NvM_audtBGndCrcQ[NvM_strBGndCrcQAdmin.u8EnqInIndex];
  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  boolean bBlkAlreadyQued = (boolean)FALSE;
  uint8_least u8Index;
  uint8_least u8Ctr;
  uint8 u8DetTypeOfError = u8NO_DET_ERROR;
  #endif


  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo: Open (BGnd CRC Q) Critical Section                              */
  SchM_Enter_NvM_NVM_ACCESS_002();
  /* PRQA S 3141 --                                                           */
   /* lint -restore                                                           */

   /* !Pseudo: If queue is  full                                              */
  if((*pu8NumOfQuedJobs) >=
     ((uint8)NVM_u8SIZE_BCKGND_CRC_QUEUE  ))
  {
    /* !Pseudo: Report error to the DEM                                       */

    Dem_ReportErrorStatus(NVM_udtE_BGND_OVERFLOW_PROD, DEM_EVENT_STATUS_FAILED);
  }
  /* !Pseudo: Else (Queue is not full)                                        */
  else
  {
    #if (NVM_DEV_ERROR_DETECT == STD_ON)
    u8Index = NvM_strBGndCrcQAdmin.u8DeqOutIndex;
    for(u8Ctr = (uint8)0;((u8Ctr < *pu8NumOfQuedJobs)
    && (bBlkAlreadyQued != (boolean)TRUE) ); u8Ctr++)
    {
      if(NvM_audtBGndCrcQ[u8Index] == udtBlockIden)
      {
        bBlkAlreadyQued = (boolean)TRUE;
        /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
        /* !Pseudo: If BlockId is already in the Q then Store DET Error       */
        u8DetTypeOfError = NVM_E_ABNORMAL_BRANCH;
      }
      else
      {
        u8Index++;
		 /* PRQA S 3355, 3358 ++                                                     */

         /* !Deviation : Depending on the configuration the Condition is always True */
         /*               if and only if NVM_u8SIZE_BCKGND_CRC_QUEUE =1              */	
        if (u8Index >= ((uint8)NVM_u8SIZE_BCKGND_CRC_QUEUE))
         /* PRQA S 3355, 3358 --                                                     */		 
        {
          u8Index = (uint8)0;
        }
      }
    }
    /* !Pseudo: If BlockId is not already in queue                            */
    if(bBlkAlreadyQued == (boolean)FALSE)
    #endif
    {
      /* !Pseudo: Enqueue data element on current push index                  */
      *pudtBGndQEnqBlockId = udtBlockIden;

      /* !Pseudo: Update Enqueue index for next entry in queue                */
      (*pu8EnqInIndex)++;
      if ((*pu8EnqInIndex) >=
        ((uint8)NVM_u8SIZE_BCKGND_CRC_QUEUE))
      {
        *pu8EnqInIndex = (uint8)0;
      }
      /* !Pseudo: Increment Number of Queued Jobs                             */
      (*pu8NumOfQuedJobs)++;
    }
  }

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo: Close (BGnd CRC Q) Critical Section                             */
  SchM_Exit_NvM_NVM_ACCESS_002();
  /* PRQA S 3141 --                                                           */

  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Report stored DET Errors                                        */
  if(u8DetTypeOfError != u8NO_DET_ERROR)
  {
    (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
      NvM_u8SET_RAM_BLK_STAT_ID,u8DetTypeOfError);
  }
  #endif
}

/******************************************************************************/
/* !Description : Function to Dequeue a back ground CRC request from its Queue*/
/******************************************************************************/
LOCAL_INLINE FUNC(NvM_BlockIdType, NVM_CODE) NvM_udtFetchBGndCrcQ(void)
{
  /* This Fn is not protected by critical sections because its Deqout Index
  can't be accessed at the same time running this Fn */

  /* !Pseudo: Using the dequeue index return the first request block ID */
  return(NvM_audtBGndCrcQ[NvM_strBGndCrcQAdmin.u8DeqOutIndex]);

}

/******************************************************************************/
/* !Description : Function to Dequeue a back ground CRC request from its Queue*/
/******************************************************************************/

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidDeqOutBGndCrcQ(void)
{
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs 
             = &NvM_strBGndCrcQAdmin.u8NumOfQuedJobs;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8DeqOutIndex 
             = &NvM_strBGndCrcQAdmin.u8DeqOutIndex;
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

  /* !Pseudo: Open BGnd CRC Q Critical Section                                */
  SchM_Enter_NvM_NVM_ACCESS_002();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */

  /* !Pseudo:  Update Dequeue index for next output from queue                */
  (*pu8DeqOutIndex)++;
  if ((*pu8DeqOutIndex) >=
    ((uint8)NVM_u8SIZE_BCKGND_CRC_QUEUE))
  {
    *pu8DeqOutIndex = (uint8)0;
  }

  /* !Pseudo:  Decrement Number of Queued Jobs                                */
  (*pu8NumOfQuedJobs)--;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo: Close BGnd CRC Q Critical Section                               */
  SchM_Exit_NvM_NVM_ACCESS_002();
  /* PRQA S 3141 --                                                           */
}

/******************************************************************************/
/* !Description : Function to check if the back ground CRC Q is empty.        */
/******************************************************************************/
static FUNC(boolean, NVM_CODE) bIsBGndCrcQEmpty(void)
{

  boolean bReturnValue = (boolean)FALSE;

  /* !Pseudo: if queue state is empty return TRUE                             */
  /* !Pseudo: else return FALSE                                               */


  if((NvM_strBGndCrcQAdmin.u8NumOfQuedJobs) == (uint8)0)
  {
    bReturnValue = (boolean)TRUE;
  }

  return(bReturnValue);

}
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
&&(NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)) */


/******************************************************************************/
/* !Description : Function used to update the validity state of the current
                  block. This update is done only when the calling API was
				  called with a permanent RAM block.                          */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidUpdatStIfPermanenRAM
(
  /* !Comment: Target state                                                   */
  uint8 u8NewState
)
{
  /* !Pseudo: If the calling API was called with a permanent RAM
  block.                                                                      */
  if (
       ( NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
         .pvidRamBlockDataAddress != NULL_PTR ) &&
       ( NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
         .pvidRamBlockDataAddress == NvM_pu8CurrentRamBlkAddr )
     )
  {
    /* !Pseudo: Set Block Status to Valid and Unchanged                       */
    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8State = u8NewState;
  }
}


/******************************************************************************/
/*  Functions Used by MainFn                                                  */
/******************************************************************************/

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON              )
/******************************************************************************/
/* !Description : Crash Single Block Job                                      */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnCrashSBJob(void)
{
/* !Deviation : inhibit MISRA rule [550]: because depending of MemIf APIs
                definition, their arguments might not be used.                */
/* lint -save -vo -e550 -v                                                    */

/* !Deviation : Inhibit MISRA rule [3199]: This variable might be             */
/*              unused in this function, depending of the actual              */
/*              definition of the macro or function that uses it.             */
/* !Deviation : Inhibit MISRA rule [3203]: This variable might be             */
/*              unused in this function, depending of the actual              */
/*              definition of the macro or function that uses it.             */
/* PRQA S 3199, 3203 ++                                                       */

  uint8 u8DeviceId;

  u8DeviceId = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId;
  /*  !Pseudo: If MemIf is Idle */
  if( MemIf_GetStatus(u8DeviceId) != MEMIF_IDLE )
  {
   /* !Pseudo: Cancel running job */
   MemIf_Cancel(u8DeviceId);

  }
  /*  !Pseudo: Reset State of Main Function to serve the Immediate Job */
  NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;

  /*  !Pseudo: Raise a flag indicating SB job crashed */
  NvM_bStdJobCrashed = (boolean)TRUE;


}
/*lint -restore                                                               */
/* PRQA S 3199, 3203 --                                                       */


/******************************************************************************/
/* !Description : Freeze Multi Block Job                                      */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnFreezeMBJob(void)
{
/* !Deviation : inhibit MISRA rule [550]: because depending of MemIf APIs
                definition, their arguments might not be used.                */
/* lint -save -vo -e550 -v                                                    */

/* !Deviation : Inhibit MISRA rule [3199]: This variable might be             */
/*              unused in this function, depending of the actual              */
/*              definition of the macro or function that uses it.             */
/* !Deviation : Inhibit MISRA rule [3203]: This variable might be             */
/*              unused in this function, depending of the actual              */
/*              definition of the macro or function that uses it.             */
/* PRQA S 3199, 3203 ++                                                       */

  uint8 u8DeviceId;
  tenuMBlkPrcsStateType enuDeInitState;

  u8DeviceId = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId;
  if(NvM_strMBJobBfr.u8JobID == NvM_u8WRITE_ALL_ID)
  {
    enuDeInitState = WRA_DEINIT_IF_IDLE;
  }
  else
  {
    enuDeInitState = RDA_DEINIT_IF_IDLE;
  }
  /*  !Pseudo: If  Last state in MB Job                                       */
  if(NvM_enuMBlkPrcsState == enuDeInitState)
  {
    /*  !Pseudo: DeInit MB Job (Normal deinitialization)                      */
    vidStMBPrcsDeInit((boolean)FALSE);
  }
  /*  !Pseudo: Else (Not Last state in MB Job)                                */
  else
  {
    /*  !Pseudo: If  MemIf is not Idle                                        */
    if( MemIf_GetStatus(u8DeviceId) != MEMIF_IDLE )
    {
      /* !Pseudo: Cancel running job                                          */
      MemIf_Cancel(u8DeviceId);
    }
    /*  !Pseudo: Move to last state in MB Job                                 */
    NvM_enuMBlkPrcsState = enuDeInitState;
    /*  !Pseudo: DeInit MB Job (Freeze it)                                    */
    vidStMBPrcsDeInit((boolean)TRUE);
  }

}
/* lint -restore                                                              */
/* PRQA S 3199, 3203 --                                                       */


#endif /* ((NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) &&
           (NVM_JOB_PRIORITIZATION == STD_ON)) */

/******************************************************************************/
/* !Description : Function to scan if there are any jobs in any queue to      */
/*                modify the state of the Mfn according to the kind of the    */
/*                queued job (Main Fn State)                                  */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidMfnJobsScanThenStart(void)
{

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)


  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  /* !Pseudo:  If there is Imediate Job Pending                               */
  if(bIsImdtJobQEmpty() == (boolean)FALSE)
  {
    /* !Pseudo:  Initialize the corresponding Job (write) then start it       */
    NvM_enueMainFnState = NvM_MFN_IMDT_SB_JOB;
    NvM_vidMfnImdtSBJobInit();
  }

  else
  #endif /*  (NVM_JOB_PRIORITIZATION == STD_ON)  */


  if(bIS_STDJOBQ_EMPTY() == (boolean)FALSE)
  {
    /* !Pseudo:  Else If there is Standard Job pending                        */
    /* !Pseudo:  Initialize the corresponding standard Job then start it      */
    NvM_enueMainFnState = NvM_MFN_STD_SB_JOB;
    NvM_vidMfnStdSBJobInit();
  }
  else
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */


  if(NvM_strMBJobBfr.u8State != u8EMPTY)
  {
  /* !Pseudo:  Else If there is MBJ pending and Back ground queue is empty    */
  #if  (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
       (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
    if ( (bIsBGndCrcQEmpty() == (boolean)TRUE) ||
		 ( (NvM_strMBJobBfr.u8JobID == NvM_u8WRITE_ALL_ID)
         && (NvM_bCancelWrtAllReq == (boolean)TRUE) ) )
  #endif
    {
      /* !Pseudo:  Initialize the corresponding multiblock Job then start it  */
      NvM_enueMainFnState = NvM_MFN_MB_JOB;
      NvM_vidMfnMBJobInit();
    }
  }
  /* !Trace_To: GSCSW-NVM-SDD-001-0492                                        */
  /* !Pseudo:   Else Do Nothing in this main function cycle                   */
  else
  {
  }
}

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : Function to scan if there are any jobs Queued in any block  */
/*                that were requested to be canceled by NvM_CancelJobs        */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidScanThenCancelJobs(void)
{
  uint8_least u8Ctr;

  /* !Pseudo:  If there is Imediate Job Pending                               */
  if(bIsImdtJobQEmpty() == (boolean)FALSE)
  {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    NvM_enueMainFnState = NvM_MFN_IMDT_SB_JOB;
#else
   NvM_enueMainFnState = NvM_MFN_STD_SB_JOB;
#endif/*(NVM_JOB_PRIORITIZATION == STD_ON)*/

    /* !Pseudo:  Search All Blocks pending in Queue                           */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    for(u8Ctr = (uint8)0; u8Ctr < NVM_SIZE_IMMEDIATE_JOB_QUEUE; u8Ctr++)
#else
    for(u8Ctr = (uint8)0; u8Ctr < NVM_SIZE_STANDARD_JOB_QUEUE; u8Ctr++)
#endif /*(NVM_JOB_PRIORITIZATION == STD_ON)*/
    {
      /* !Pseudo:  If the block was requested to be canceled by NvM_CancelJobs*/
	  if(u8CHECK_GENERAL_BLOCK((NvM_astrImdtQ[u8Ctr].udtBlockID), u8BLOCK_CANCELED))
      {
        /* !Pseudo:  Set NvM_udteCurrentBlockID to the ID of the canceled block*/
        NvM_udteCurrentBlockID = NvM_astrImdtQ[u8Ctr].udtBlockID;
        /* !Pseudo:  Call Prcs vidSBPrcsDeInit(NVM_REQ_CANCELED)              */
        vidSBPrcsDeInit(NVM_REQ_CANCELED);
      }
    }
  }
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  if(bIS_STDJOBQ_EMPTY() == (boolean)FALSE)
  {
    NvM_enueMainFnState = NvM_MFN_STD_SB_JOB;
    /* !Pseudo:  Search All Blocks pending in Queue                           */
    for(u8Ctr = (uint8)0; u8Ctr < NVM_SIZE_STANDARD_JOB_QUEUE; u8Ctr++)
    {
      /* !Pseudo:  If the block was requested to be canceled by NvM_CancelJobs*/
      if(u8CHECK_GENERAL_BLOCK((NvM_astrStdSBJobQ[u8Ctr].udtBlockID), u8BLOCK_CANCELED))
      {
        /* !Pseudo:  Set NvM_udteCurrentBlockID to the ID of the canceled block*/
	      NvM_udteCurrentBlockID = NvM_astrStdSBJobQ[u8Ctr].udtBlockID;
        /* !Pseudo:  Call Prcs vidSBPrcsDeInit(NVM_REQ_CANCELED)              */
        vidSBPrcsDeInit(NVM_REQ_CANCELED);
      }
    }
  }
#endif /*  (NVM_JOB_PRIORITIZATION == STD_ON)  */

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */
  SchM_Enter_NvM_NVM_ACCESS_001();
  /* !Pseudo:   Set The global cancel flag to false and return                */
  NvM_bAnyCancelJobReq = (boolean)FALSE;
  SchM_Exit_NvM_NVM_ACCESS_001(); 
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : Function for standard single block job handeling. According */
/*                to the current running job, it calls the corresponding job  */
/*                process                                                     */



/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnStdSBJob(void)
{
  /* !Pseudo:  According to the current running job ID Run the corresponding
  standard job process                                                        */
  switch (NvM_u8eCurrentJobID)
  {
  case NvM_u8READ_BLOCK_ID:
    vidReadBlkPrcs();
    break;

  case NvM_u8WRITE_BLOCK_ID:
    vidWriteBlkPrcs();
    break;

  case NvM_u8RESTORE_BLK_DFTS_ID:
    vidRstrBlkDftsPrcs();
    break;

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  case NvM_u8ERASE_NV_BLOCK_ID:
    vidEraseBlkPrcs();
    break;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

  case NvM_u8INVALIDATE_NVBLK_ID:
    vidINVALIDBLKPRCS();
    break;
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)  */

  default:
#if (NVM_DEV_ERROR_DETECT == STD_ON)
   /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
   /* !Pseudo: Case (Invalid Job ID) then Report to Det Abnormal Branch       */
   (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
     NVM_E_ABNORMAL_BRANCH);

#else
   /* !Pseudo: Report error to the DEM                                        */
   Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD, DEM_EVENT_STATUS_FAILED);

#endif
    break;
  }
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
/******************************************************************************/
/* !Description : Function for Multi block job handeling. According to the
                  current running job, it calls the corresponding job process
				  (Main Fn State)                                             */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnMBJob(void)
{

  /* !Pseudo:  According to the current running job ID Run the corresponding
               Multi block job process                                        */
  switch (NvM_u8eCurrentJobID)
  {
  case NvM_u8READ_ALL_ID:
    vidReadAllPrcs();
    break;

  case NvM_u8WRITE_ALL_ID:
    vidWriteAllPrcs();
    break;

  default:
#if (NVM_DEV_ERROR_DETECT == STD_ON)
   /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
   /* !Pseudo: Case (Invalid Job ID) then Report to Det Abnormal Branch       */
   (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
     NVM_E_ABNORMAL_BRANCH);
#else
   /* !Pseudo: Report error to the DEM                                        */
   Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD, DEM_EVENT_STATUS_FAILED);

#endif
    break;
  }
}


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
#if (NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/* !Description : Function that fetchs the write block job from the immediate */
/*                Qand call the init fn of the write block process            */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnImdtSBJobInit(void)
{

  /* !Pseudo:  Read the job to be processed from the Imdt queue               */
  vidFetchJobInImdtJobQ();

  /* !Pseudo:  Start the Write Block Process                                  */
  vidWriteBlkPrcsInit();
  vidWriteBlkPrcs();
}
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON)                                  */

/******************************************************************************/
/* !Description : Function that fetchs the job from the standard Q and call the
                  init fn of the corresponding process                        */

/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnStdSBJobInit(void)
{
#if (NVM_JOB_PRIORITIZATION == STD_ON)
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8DeqOutIndex
                   = &NvM_strStdQAdmin.u8DeqOutIndex;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8NumOfQuedJobs
                   = &NvM_strStdQAdmin.u8NumOfQuedJobs;
#if ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  P2VAR(boolean, AUTOMATIC, NVM_APPL_DATA) pbTimeToServeExpJob 
                   = &NvM_strExpSyncDelayedJob.bTimeToServeExpJob;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8JobID
                   = &NvM_strExpSyncDelayedJob.u8JobID;
  P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtBlockID
                   = &NvM_strExpSyncDelayedJob.udtBlockID;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8RamBlkAddress
                   = NvM_strExpSyncDelayedJob.pu8RamBlkAddr;
#endif /* ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U ) */
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

#if (NVM_JOB_PRIORITIZATION == STD_ON) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  /* !Pseudo:  If there is an explicit job delayed                            */
 
  if ((NvM_bExpStdJobDelayed == (boolean)TRUE) && (NvM_bStdJobCrashed != (boolean)TRUE))
  {
    /* !Pseudo:  If the explicit job should be served now                     */
    if ((*pbTimeToServeExpJob == (boolean)TRUE)
        || (*pu8NumOfQuedJobs == (uint8)1))
    {
      /* !Pseudo:  Reset the Explicit job delayed flag                        */
      NvM_bExpStdJobDelayed = (boolean)FALSE;
      /* !Pseudo: Reset the marking of serving the explicit job               */
      *pbTimeToServeExpJob = (boolean)FALSE;

  /* !Pseudo:  If there is an explicit job delayed                            */
  
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

      /* !Pseudo:  Open Critical Section                                      */
  SchM_Enter_NvM_NVM_ACCESS_001(); 
/* PRQA S 3141 --                                                           */
/* lint -restore                                                            */
      /* !Pseudo: Update the dequeue out index of the std Q                 */
       *pu8DeqOutIndex = NvM_u8SearchDeqOutStdQIdx(
                                         NvM_strExpSyncDelayedJob.udtBlockID);
       /*  !Pseudo: Update the current job parameters with the explicit
                   sync. delayed parameters                                 */
       NvM_udteCurrentBlockID = *pudtBlockID;
       NvM_u8eCurrentJobID = *pu8JobID;
       NvM_pu8CurrentRamBlkAddr = pu8RamBlkAddress;

/* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
/*              during integration phase                                    */
/* PRQA S 3141 ++                                                           */

      /* !Pseudo:  Close Critical Section                                     */
      SchM_Exit_NvM_NVM_ACCESS_001();
/* PRQA S 3141 --                                                           */
      /*  !Pseudo: Reset the block ID of the explicit job                     */
      *pudtBlockID = (uint8)0;
    }
    /* !Pseudo:  Else, the explicit job should not be served now              */
    else
    {
      /* !Pseudo: Mark the explicit sync. job to be served next               */
      NvM_strExpSyncDelayedJob.bTimeToServeExpJob = (boolean)TRUE;
      /* !Pseudo: Read the job parameters from the standard queue and store
                  it in current Job container                                 */
      vidFetchJobInStdJobQ();
    }
  }
  /* !Pseudo: Else, no explicit sync. job delayed                             */
  else
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U ) */
  {
    /* !Pseudo:  Read the job parameters from the standard queue and store it in
                 current Job container                                        */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0023                              */
    vidFETCHJOB_IN_STDJOBQ();
  }

  /* !Pseudo:  According to Current Job ID, Start the corresponding standard
               job                                                            */
  switch (NvM_u8eCurrentJobID)
  {
    case NvM_u8READ_BLOCK_ID:
      vidReadBlkPrcsInit();
      vidReadBlkPrcs();
      break;

    case NvM_u8WRITE_BLOCK_ID:
      vidWriteBlkPrcsInit();
      vidWriteBlkPrcs();
      break;

    case NvM_u8RESTORE_BLK_DFTS_ID:
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    case NvM_u8READ_BLK_DFT_DSET_ID:
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
      vidRstrBlkDftsPrcsInit();
      vidRstrBlkDftsPrcs();
      break;

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
  #if (NVM_JOB_PRIORITIZATION == STD_ON)
      case NvM_u8ERASE_NV_BLOCK_ID:
        vidEraseBlkPrcsInit();
        vidEraseBlkPrcs();
        break;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

      case NvM_u8INVALIDATE_NVBLK_ID:
        vidINVALIDBLKPRCSINIT();
        vidINVALIDBLKPRCS();
        break;
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */

    default:
#if (NVM_DEV_ERROR_DETECT == STD_ON)
       /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
       /* !Pseudo: Case (Invalid Job ID) then Report to Det Abnormal Branch   */
       (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
         NVM_E_ABNORMAL_BRANCH);
#else
       /* !Pseudo: Report error to the DEM                                    */
       Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
               DEM_EVENT_STATUS_FAILED);
#endif
      break;

  }

}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
/******************************************************************************/
/* !Description : Function that reads the requested Multi block job and call
                  the init fn of the corresponding process                    */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidMfnMBJobInit(void)
{

  /* !Pseudo:  Read the job parameters from the Multi block Buffer and store
  it in current Job container                                                 */
  /* Restore the block ID you stopped on it last time                         */
  NvM_udteCurrentBlockID = NvM_strMBJobBfr.udtBlockID;
  NvM_u8eCurrentJobID = NvM_strMBJobBfr.u8JobID;

  /* !Pseudo:  Check the current Job ID                                       */
  switch (NvM_u8eCurrentJobID)
  {
  /* !Pseudo:  Case (Read All Block Id)                                       */
    case NvM_u8READ_ALL_ID:
      /* !Pseudo:  Initialize and run the read all process                    */
      NvM_vidReadAllPrcsInit();
      vidReadAllPrcs();
      break;

    /* !Pseudo:  Case (Write All Block Id)                                    */
    case NvM_u8WRITE_ALL_ID:
      /* !Pseudo:  Initialize and run the write all process                   */
      NvM_vidWriteAllPrcsInit();
      vidWriteAllPrcs();
      break;


    default:
      #if (NVM_DEV_ERROR_DETECT == STD_ON)
        /* !Pseudo: Case (Invalid Job ID) then Report to Det Abnormal Branch  */
        /* !Trace_To        : GSCSW-NVM-SDD-001-0007                          */
        (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
          NVM_E_ABNORMAL_BRANCH);
      #else
        /* !Pseudo: Report error to the DEM                                   */
        Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                        DEM_EVENT_STATUS_FAILED);
      #endif
      break;
  }
}


#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* Functions used by Erase/Invalidate block process.                          */
/******************************************************************************/

/******************************************************************************/
/* !Description : Function that initializes erase block process.              */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidEraseBlkPrcsInit(void)
{
  /* !Trace_To: GSCSW-NVM-SDD-001-0470                                        */
  /* !Pseudo: Set state to ERS_WAIT_MEMIF_ERS                                 */
  NvM_enuSBPrcsState = ERS_WAIT_MEMIF_ERS;

  /* !Pseudo: If block to be erased is not
  dataset-typed  Force dataset index to zero                                  */
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
    .u8BlockManagementType != NVM_BLOCK_DATASET)
  {
    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)0;
  }
  /* !Pseudo: Else If block to be erased is of invalid dataset                */
  else if( NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex >=
    NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvBlockNum )
  {
    /* !Pseudo: Report to DEM and Call Process DeInit (Failed Job)            */
    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
    Dem_ReportErrorStatus(NVM_E_REQ_FAILED, DEM_EVENT_STATUS_FAILED);
    vidSBPrcsDeInit(NVM_REQ_NOT_OK);
    /* !Pseudo: Set the state to an invalid state (Read Block state!!).
    To cause a DET report (Abnormal branch) in the vidEraseBlkPrcs function   */
    NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;
  }
  /* !Pseudo: Else Don't modify the data set index and continue the erase
  process normally*/
  else
  {
  }
}

/******************************************************************************/
/* !Description : Erase block process. It is called at every Mnf cycle if there
                  is an Erase block process in progress                       */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidEraseBlkPrcs(void)
{

  /*  !Pseudo: Call corresponding state Function                              */

  switch (NvM_enuSBPrcsState)
  {
    case ERS_WAIT_MEMIF_ERS :
      vidStErsWaitMemIfAndErs();
      break;

    case ERS_WAIT_ERASE_END :
      NvM_vidStErsWaitEraseEnd();
      if(NvM_enuSBPrcsState == ERS_WAIT_MEMIF_ERS)
      {
        vidStErsWaitMemIfAndErs();
      }
      break;

    case WRB_CALC_RAM_BLK_CRC :
    case WRB_WAIT_MEMIF_WRT :
    case WRB_WAIT_WRITE_END :
    #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
    case RDB_PRE_CALC_RAM_CRC:
    #endif
    case RDB_WAIT_MEMIF_READ :
    case RDB_WAIT_READ_END :
    case RDB_CALC_CRC_AND_CMP :
    case RDB_RSTR_BLK_PRCS :
    default:
     #if (NVM_DEV_ERROR_DETECT == STD_ON)
      /* !Pseudo: Case (Invalid State) then Report to Det Abnormal Branch     */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0007                            */
      (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID, NvM_u8MAIN_FUNCTION_ID,
        NVM_E_ABNORMAL_BRANCH);
     #else
      /* !Pseudo: Report error to the DEM */
      Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                      DEM_EVENT_STATUS_FAILED);
     #endif
      break;
  }
}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf to be
                  Idle then starts erasing the block (Note that the MemIf can be
				  internal busy).                                             */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStErsWaitMemIfAndErs(void)
{
  Std_ReturnType u8MemIfReturnResult;
  MemIf_StatusType udtMemIfStatus;
  uint16 u16BlockNumber;

/* !Trace_To        : GSCSW-NVM-SDD-001-0200                                  */
  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  udtMemIfStatus = MemIf_GetStatus
    (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId);

  /* !Pseudo: If MemIf is Idle                                                */
  if(udtMemIfStatus == MEMIF_IDLE)
  {
    u16BlockNumber = (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
      .u16NvBlockBaseNumber) + (uint16)(NvM_astrAdminBlock
      [NvM_udteCurrentBlockID].u8DataSetIndex);

    #if (NVM_POLLING_MODE == STD_OFF)
    /* !Pseudo:  Reset Job end Call back flag                                 */

    NvM_udtMemIfJobEndClBck = MEMIF_JOB_PENDING;
    #endif

    #if (NVM_JOB_PRIORITIZATION == STD_ON)
    /* !Pseudo: If Erase Process state                                        */
    if(NvM_u8eCurrentJobID == NvM_u8ERASE_NV_BLOCK_ID)
    {
    /* !Pseudo: Call Erase Immediate Block of MemIf                           */

      u8MemIfReturnResult = MemIf_EraseImmediateBlock(NvM_akstreBlockDescriptor
        [NvM_udteCurrentBlockID].u8NvRamDeviceId, u16BlockNumber);
    }
     /* !Pseudo: Else                                                         */
    else
    #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
    {
      /* !Pseudo: Call Invalidate Block of MemIf                              */
      u8MemIfReturnResult = MemIf_InvalidateBlock(NvM_akstreBlockDescriptor
        [NvM_udteCurrentBlockID].u8NvRamDeviceId, u16BlockNumber);
    }
    /* !Pseudo: If request is Accepted Go to Wait for Erase State             */
    if(u8MemIfReturnResult == E_OK)
    {
      NvM_enuSBPrcsState = ERS_WAIT_ERASE_END;
    }
    /* !Pseudo: Else Report to DEM  and Call Process DeInit (Failed Job)      */
    else
    {
      #if (NVM_POLLING_MODE == STD_OFF)
      NvM_udtMemIfJobEndClBck = MEMIF_JOB_FAILED;
      #endif
	    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0582                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0471                                    */
      Dem_ReportErrorStatus(NVM_E_REQ_FAILED, DEM_EVENT_STATUS_FAILED);
      vidSBPrcsDeInit(NVM_REQ_NOT_OK);
    }
  }

#if(NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Else if MEMIF is not initialized								  */
  else if(udtMemIfStatus == MEMIF_UNINIT)
  {
	  (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8eCurrentJobID,
          NVM_E_MEMIF_UNINIT);
  }
#endif
  /* !Pseudo: Else (Not Idle and already initialized)					      */
  else
  {
    /* !Pseudo:  Do Nothing in this main function cycle                       */
  }

}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf finish
                  erasing the block                                           */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStErsWaitEraseEnd(void)
{
/* !Trace_To        : GSCSW-NVM-SDD-001-0201                                  */
  MemIf_JobResultType udtMemIfJobResult;

  /* !Pseudo:  Get Job Result of MemIf                                        */
  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  #if (NVM_POLLING_MODE == STD_ON)
  udtMemIfJobResult = MemIf_GetJobResult(NvM_akstreBlockDescriptor
             [NvM_udteCurrentBlockID].u8NvRamDeviceId);
  #else
  udtMemIfJobResult = NvM_udtMemIfJobEndClBck;
  #endif

  /* !Pseudo:  If Pending                                                     */
  if(udtMemIfJobResult == MEMIF_JOB_PENDING)
  {
   /* !Pseudo:  Do Nothing in this main function cycle                        */
  }

  /* !Pseudo:  Else If OK                                                     */
  else if(udtMemIfJobResult == MEMIF_JOB_OK)

  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0481                                      */
    /* !Pseudo:  If Block Type Redundant and 2nd block not processed yet */
    if( (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex == (uint8)0)
       &&
        (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockManagementType
        == NVM_BLOCK_REDUNDANT))
    {
      /* !Pseudo:  Set data Index to 1                                        */
      NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)1u;
      /* !Pseudo: Set state to ERS_WAIT_MEMIF_ERS                             */
      NvM_enuSBPrcsState = ERS_WAIT_MEMIF_ERS;
    }
    /* !Pseudo: Else (Native or Redundant with Both blocks erased
    correctly )                                                               */
    else
    {
      /* !Pseudo: Call Process DeInit (Successful Job)                        */
      vidSBPrcsDeInit(NVM_REQ_OK);
    }
  }

  /* !Pseudo: Else (   MEMIF_JOB_FAILED,  MEMIF_JOB_CANCELED,
  MEMIF_BLOCK_INCONSISTENT,  MEMIF_BLOCK_INVALID)                             */
  else
  {
      /* !Trace_To: GSCSW-NVM-SDD-001-0582                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0471                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0472                                    */
      /* !Pseudo: Report to DEM and Call Process DeInit (Failed Job)          */
	    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
      Dem_ReportErrorStatus(NVM_E_REQ_FAILED, DEM_EVENT_STATUS_FAILED);
      /* !Trace_To: GSCSW-NVM-SDD-001-0481                                    */
      vidSBPrcsDeInit(NVM_REQ_NOT_OK);
  }
}
#endif /*  (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)  */

/******************************************************************************/
/* Functions used by restore block defaults process                           */
/******************************************************************************/


/******************************************************************************/
/* !Description : Function that initializes restore block defaults process    */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidRstrBlkDftsPrcsInit(void)
{
  uint16_least u16Ctr;


  uint32 u32RomOffset = 0;


  /* !Pseudo: If the RAM buffer used in the API call is the same
  as the configured Ram buffer of the NVRAM block and if it is
  not NULL                                                                    */
  /* !Pseudo: Then update the state of the current block to
  u8INVALID                                                                   */
  /* !Trace_To: GSCSW-NVM-SDD-001-0487,GSCSW-NVM-SDD-001-0589                 */
  vidUpdatStIfPermanenRAM(u8INVALID);

  /* !Pseudo:  If configured ROM data ptr is not Null                         */

  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].pku8RomBlkDataAddress
           != NULL_PTR)
  {
    #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    /* !Pseudo:   If Data Set Block type                                      */
    if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
      u8BlockManagementType == NVM_BLOCK_DATASET)
    {
      /* !Pseudo: Using Dataset Index calculate the place of the required Rom
      block                                                                   */
      u32RomOffset =
      (
        (
          (uint32)(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                     u16NvBlockLength)
         *(
            (uint32)(NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex)
            - (uint32)(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                     u8NvBlockNum)
          )
        )
      );
    }
    #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

    /* !Pseudo:   Execute direct copying from Rom to Ram block                */
	/* !Trace_To: GSCSW-NVM-SDD-001-0526                                      */

    for(u16Ctr = (uint16)0; u16Ctr < (NvM_akstreBlockDescriptor
      [NvM_udteCurrentBlockID].u16NvBlockLength); u16Ctr++)
    {
      NvM_pu8CurrentRamBlkAddr[u16Ctr] = NvM_akstreBlockDescriptor[
        NvM_udteCurrentBlockID].pku8RomBlkDataAddress[u32RomOffset +
        (uint32)u16Ctr];
    }
  }
  /* !Pseudo:  Else if Init Callback is configured for this block             */
  else if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
            pfu8InitBlockCallBack != NULL_PTR)

  {
    /* !Pseudo:     Call Init Callback function                               */
/* !Trace_To        : GSCSW-NVM-SDD-001-0062                                  */


    (void) NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
             pfu8InitBlockCallBack();
  }
  else
  {

    /* This branch shouldn't be entered except if restore defaults API is
    called for a Ram block than has no defaults. Note this can happen only in
    production mode because in development this error will be detected in the
    restore API itself                                                        */
  }
  #if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
  /* !Pseudo:  If CRC shall not be calculated by the write block service      */
  /* !Trace_To: GSCSW-NVM-SDD-001-0489                                        */
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bCalcRamBlockCrc
      == (boolean)TRUE)
  {
    /* !Pseudo:   Call Init fn of Calc Ram Block CRC state                    */

    vidStCalcRamCRCInit();
  }
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API !=STD_OFF) */
}

/******************************************************************************/
/* !Description : Restore Block Defaults process. It is called at every Mnf
                  cycle if it is in progress                                  */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidRstrBlkDftsPrcs(void)
{
  #if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
  Std_ReturnType u8StateReturnValue;
  #endif

  #if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
  /* !Pseudo: If CRC shall be calculated by the write block service           */
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bCalcRamBlockCrc
      != (boolean)TRUE)
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF) */
  {

    /* !Pseudo: If the RAM buffer used in the API call is the same
    as the configured Ram buffer of the NVRAM block and if it is
    not NULL                                                                  */
    /* !Pseudo: Then update the state of the current block to
    u8VALID_CHANGED                                                           */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0512                                      */
    /* !Trace_To: GSCSW-NVM-SDD-001-0486, GSCSW-NVM-SDD-001-0589              */
    vidUpdatStIfPermanenRAM(u8VALID_CHANGED);

    /* !Pseudo:    Call SB Process DeInit 			                          */
/* !Pseudo: 	If current job is read block or read all 				      */
	if ((NvM_u8eCurrentJobID == NvM_u8READ_ALL_ID)
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
		 ||
        (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID)
#endif
	   )
	{
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)	&& (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlkUseSyncMechanism
           == (boolean)TRUE) && (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID) )
    {
      /* !Pseudo: 	Set NvM_u8SBPreErrorStatus to NVM_REQ_RESTORED_FROM_ROM   */
      NvM_u8SBPreErrorStatus = NVM_REQ_RESTORED_FROM_ROM;
     /* !Pseudo: 	Set State to RDB_CALL_APP_COPY               		      */
     /* !Trace_To: GSCSW-NVM-SDD-001-0524                                     */
      NvM_enuSBPrcsState = RDB_CALL_APP_COPY;
      /* !Pseudo: Call vidRdBCallAppCopy() */
      vidRdBCallAppCopy();
    }
    else
#endif

    {
      /* !Pseudo: 	Call SB Process DeInit (Defaults Restored)				  */
		  vidSBPrcsDeInit(NVM_REQ_RESTORED_FROM_ROM);
    }
	}
/* !Pseudo: 	Else, Call SB Process DeInit (Successful)		      		  */
	else
	{
		vidSBPrcsDeInit(NVM_REQ_OK);
	}

  }
  #if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
  /* !Pseudo:  Else                                                           */
  else
  {
    /* !Pseudo:    Call State fn of Calc ram Blk CRC (Shared fn between
    processes)                                                                */

    u8StateReturnValue = u8StCalcRamBlkCRC();
    /* !Pseudo: If return Value is OK                                         */
    if(u8StateReturnValue == E_OK)
    {

      /* !Pseudo:  Update the Ram CRC                                         */
      vidUpdateRamBlkCRC();

      /* !Trace_To: GSCSW-NVM-SDD-001-0589                                    */
      /* !Pseudo: If the RAM buffer used in the API call is the same
      as the configured Ram buffer of the NVRAM block and if it is
      not NULL                                                                */
      /* !Pseudo: Then update the state of the current block to
      u8VALID_CHANGED                                                         */
      vidUpdatStIfPermanenRAM(u8VALID_CHANGED);

      /* !Pseudo:    Call SB Process DeInit (Successful)                      */


/* !Pseudo: 	If current job is read block or read all 	    		              */

	if ((NvM_u8eCurrentJobID == NvM_u8READ_ALL_ID)
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
		||
       (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID)
#endif
	   )
	{
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)	&& (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlkUseSyncMechanism
           == (boolean)TRUE) && (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID))
    {
      /* !Pseudo: 	Set NvM_u8SBPreErrorStatus to NVM_REQ_RESTORED_FROM_ROM   */
      NvM_u8SBPreErrorStatus = NVM_REQ_RESTORED_FROM_ROM;
      /* !Pseudo: 	Set State to RDB_CALL_APP_COPY               		      */
      NvM_enuSBPrcsState = RDB_CALL_APP_COPY;
      /* !Pseudo: Call vidRdBCallAppCopy() */
      vidRdBCallAppCopy();
    }
    else
#endif
    {
      /* !Pseudo: 	Call SB Process DeInit (Defaults Restored)				        */
		  vidSBPrcsDeInit(NVM_REQ_RESTORED_FROM_ROM);
    }
	}
/* !Pseudo: 	Else, Call SB Process DeInit (Successful)		      		          */
	else

	{
		vidSBPrcsDeInit(NVM_REQ_OK);
	}
    }
  }
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF) */
}

/******************************************************************************/
/* Functions used by Read block process.                                      */
/******************************************************************************/

/******************************************************************************/
/* !Description : Function that initializes Read block process.               */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidReadBlkPrcsInit(void)
{
  /* !Pseudo:  Reset read retires counter                                     */
  NvM_u8ReadRetriesCtr = (uint8)0;
 /* !Pseudo:  Initialize pre-error status to failed.                          */
	NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
  /* !Pseudo:  Reset Mirror Operation retires counter                         */
  #if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  \
   && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  NvM_u8RepeatMirrorOp = (uint8)0;
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  \
            && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U ) */

  #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
  /* !Pseudo: If the block to be read has to be read directly in
  NV memory, discarding the content of the RAM block.                         */
/* !Trace_To        : GSCSW-NVM-SDD-001-0056                                  */
  if (
       (   NvM_enueMainFnState  != NvM_MFN_MB_JOB             ) ||
       (  (NvM_astrAdminBlock[NvM_udteCurrentBlockID]
                      .u8State != u8VALID_UNCHANGED ) &&
          (NvM_astrAdminBlock[NvM_udteCurrentBlockID]
                      .u8State != u8VALID_CHANGED   )    ) ||
       (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
             .bCalcRamBlockCrc != (boolean)TRUE                   )
     #if(NVM_DYNAMIC_CONFIGURATION == STD_ON)
                                                           ||
       (NvM_u8RdARunTimeMode   == u8EXTENDED_RUN         )
     #endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON)  */
     )
  {
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

    /* !Pseudo: If the RAM buffer used in the API call is the same
    as the configured Ram buffer of the NVRAM block and if it is
    not NULL                                                                  */
    /* !Pseudo: Then update the state of the current block to
    u8INVALID                                                                 */
	/* !Trace_To        : GSCSW-NVM-SDD-001-0508                              */
    /*  !Trace_To: GSCSW-NVM-SDD-001-0566, GSCSW-NVM-SDD-001-0589           */
    vidUpdatStIfPermanenRAM(u8INVALID);


    /*  !Pseudo: Initialize the state                                         */
    NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;

  #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
  }
  /* !Trace_To        : GSCSW-NVM-SDD-001-0572, GSCSW-NVM-SDD-001-0573        */
  /* !Pseudo: Else first calculate the CRC of the RAM block.                  */
  else
  {
    /* !Pseudo: Call the init function of the state                           */
    vidStCalcRamCRCInit();
    /*  !Pseudo: Initialize the state */
    NvM_enuSBPrcsState = RDB_PRE_CALC_RAM_CRC;
  }
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
  /* !Pseudo: If block to be read is not
  dataset-typed  Force dataset index to zero                                  */
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
    .u8BlockManagementType != NVM_BLOCK_DATASET)
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
  {
    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)0;
  }
  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
  /* !Pseudo: Else If block to be read is of invalid dataset                  */
  else if( NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex >=
    NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvBlockNum )
  {
    /* !Pseudo: Report to DEM and Call Process DeInit (Failed Job) */
    /* !Trace_To: GSCSW-NVM-SDD-001-0307,GSCSW-NVM-SDD-001-0510               */
    Dem_ReportErrorStatus(NVM_E_REQ_FAILED, DEM_EVENT_STATUS_FAILED);
    vidSBPrcsDeInit(NVM_REQ_NOT_OK);
    /* !Pseudo: Set the state to an invalid state (Write Block state!!).
    To cause a DET report (Abnormal branch) in the vidReadBlkPrcs function    */
    NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
  }
  /* !Pseudo: Else Don't modify the data set index                            */
  else
  {
  }
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
}


/******************************************************************************/
/* !Description : Read block process. It is called at every Mnf cycle if there
                  is a read block process in progress                         */



/******************************************************************************/
static FUNC(void, NVM_CODE) vidReadBlkPrcs(void)
{

  switch (NvM_enuSBPrcsState)
  {
    #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
    /* !Pseudo: case  RDB_PRE_CALC_RAM_CRC                                    */
    case RDB_PRE_CALC_RAM_CRC:
      /* !Pseudo: Calculate the Ram Crc then compare the read one             */
      NvM_vidStPreCalcCrcThenCmp();
       /* As soon as CRC calculation is ended go to the next state.
      (Saves one Mfn Cycle and saves stack by not calling the fn from
       inside the previous state fn)                                          */
      /* !Pseudo:  If Prcs State is RDB_WAIT_MEMIF_READ                       */
      if(NvM_enuSBPrcsState == RDB_WAIT_MEMIF_READ)
      {
         /* !Pseudo:  Wait till MemIf is Idle then start Reading              */
         vidStRdBWaitMemIfAndRd();
      }
      break;
    #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

    /* !Pseudo: case  RDB_WAIT_MEMIF_READ                                     */

    case RDB_WAIT_MEMIF_READ:
      /* !Pseudo:  Wait till MemIf is Idle then start Reading                 */
      vidStRdBWaitMemIfAndRd();
      break;

    /* !Pseudo:  case RDB_WAIT_READ_END:                                      */

    case RDB_WAIT_READ_END:
      /* !Pseudo:  Wait till reading is finished                              */
      vidStRdBWaitReadEnd();

      /* !Pseudo: As soon as Read is ended go to the next state.
      (Saves one Mfn Cycle and saves stack by not calling the fn from
       inside the previous state fn)                                          */
      /* !Pseudo:  If Prcs State is RDB_CALC_CRC_AND_CMP                      */
      if(NvM_enuSBPrcsState == RDB_CALC_CRC_AND_CMP)
      {
         /* !Pseudo: Call the init function of the state                      */
         vidStCalcRamCRCInit();
         /* !Pseudo: Calculate the Ram Crc then compare the read one          */
         vidStRdBCalcCrcThenCmp();
      }
      break;

    /* !Pseudo:  case RDB_CALC_CRC_AND_CMP:                                   */
    case RDB_CALC_CRC_AND_CMP:
      /* !Pseudo:  Calculate the Ram Crc then compare the read one            */
      vidStRdBCalcCrcThenCmp();
      break;

    /* !Pseudo:  case RDB_WRT_RDDT_BLK:                                       */
    case RDB_WRT_RDDT_BLK:
      NvM_vidStRdBWrtRddtBlk();
      break;


#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    /* !Pseudo:  case RDB_CALL_APP_COPY:                                      */
    case RDB_CALL_APP_COPY:
      /* !Pseudo:  Call corresponding State fn                                */
      vidRdBCallAppCopy();
      break;
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

    /* !Pseudo:  case RDB_RSTR_BLK_PRCS:                                      */

    case RDB_RSTR_BLK_PRCS:
      /* !Pseudo:  Run the Restore Block Defaults Process                     */
      vidRstrBlkDftsPrcs();
      break;
    /* !Pseudo:  Default: (Invalid State) then report to Det Abnormal Branch  */
    case WRB_CALC_RAM_BLK_CRC:
    case WRB_WAIT_MEMIF_WRT :
    case WRB_WAIT_WRITE_END :
    #if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
    case ERS_WAIT_MEMIF_ERS :
    case ERS_WAIT_ERASE_END :
    #endif
    default:
      #if (NVM_DEV_ERROR_DETECT == STD_ON)
        /* !Trace_To        : GSCSW-NVM-SDD-001-0007                         */
        (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
          NVM_E_ABNORMAL_BRANCH);
      #else
        /* !Pseudo: Report error to the DEM                                   */
        Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                        DEM_EVENT_STATUS_FAILED);
      #endif
      break;
  }
}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf to be
                  Idle then starts reading the block (Note that the MemIf can be
				  internal busy).                                             */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStRdBWaitMemIfAndRd(void)
{
  Std_ReturnType u8MemIfReturnResult;
  MemIf_StatusType udtMemIfStatus;
  uint16 u16BlockNumber;
  uint16 u16PassedLength;

  /* !Pseudo: Call Get Status of MemIf                                        */
  /* !Trace_To        : GSCSW-NVM-SDD-001-0200                                  */
  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  udtMemIfStatus = MemIf_GetStatus(NvM_akstreBlockDescriptor[
    NvM_udteCurrentBlockID].u8NvRamDeviceId);
  if(udtMemIfStatus == MEMIF_IDLE)

  {
    /* !Pseudo: If Idle                                                       */

    u16BlockNumber = (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
      .u16NvBlockBaseNumber) + (uint16)(NvM_astrAdminBlock[
      NvM_udteCurrentBlockID].u8DataSetIndex);

    #if (NVM_POLLING_MODE == STD_OFF)
    /* !Pseudo:  Reset Job end Call back flag                                 */

    NvM_udtMemIfJobEndClBck = MEMIF_JOB_PENDING;
    #endif

    u16PassedLength = u16CalcTotalBlkLength(NvM_udteCurrentBlockID);

/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */
      /* !Pseudo: Call Read Block of MemIf with address
                  NvM_au8InternalRamBuffer                                    */
	if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc == (boolean)TRUE ) || 
	 (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck == (boolean)TRUE))
	 {
      u8MemIfReturnResult = MemIf_Read(
              NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId,
             u16BlockNumber,(uint16)0,NvM_au8InternalRamBuffer,u16PassedLength);
     }
	 else 
	 	 /* !Pseudo: Call Read Block of MemIf with address NvM_pu8CurrentRamBlkAddr*/
	 {
      u8MemIfReturnResult = MemIf_Read(
              NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId,
             u16BlockNumber,(uint16)0,NvM_pu8CurrentRamBlkAddr,u16PassedLength);	 
	 }
/*lint -restore                                                               */

    /* !Pseudo: If request is Accepted Go to Wait for Read End State  */
    if(u8MemIfReturnResult == E_OK)

    {
      NvM_enuSBPrcsState = RDB_WAIT_READ_END;
    }
    /* !Pseudo: Else store initial DEM error and set Pre Error Status
                to Not OK and Call Read Error Hook                            */
    else

    {
     #if (NVM_POLLING_MODE == STD_OFF)
      NvM_udtMemIfJobEndClBck = MEMIF_JOB_FAILED;
     #endif
      /* !Pseudo: store initial DEM error NVM_E_REQ_FAILED                    */
	    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0568                                    */
      NvM_u16PreDemError = NVM_E_REQ_FAILED;
      NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
      vidReadBErrorHook();
    }
  }

#if(NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Else if MEMIF is not initialized								  */
  else if(udtMemIfStatus == MEMIF_UNINIT)
	{
	  (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8eCurrentJobID,
               NVM_E_MEMIF_UNINIT);
	}
#endif
    /* !Pseudo: Else (Not Idle and already initialized)                       */
  else
  {

      /* !Pseudo:  Do Nothing in this main cycle call                         */
  }

}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf finish
                  reading the block                                           */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidStRdBWaitReadEnd(void)
{
/* !Trace_To        : GSCSW-NVM-SDD-001-0201                                  */
  MemIf_JobResultType udtMemIfJobResult;

  uint16 u16BlockLength;
  uint16_least u16LengthCount;
  uint8 u8NumOfBlkHdrBytes;

  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  /* !Pseudo:  Get Job Result of MemIf                                        */
  #if (NVM_POLLING_MODE == STD_OFF)
  if((NvM_udtMemIfJobEndClBck == MEMIF_JOB_PENDING) ||
    (NvM_udtMemIfJobEndClBck == MEMIF_JOB_OK))
  {
    udtMemIfJobResult = NvM_udtMemIfJobEndClBck;
  }
  else
  #endif /* (NVM_POLLING_MODE == STD_OFF)  */
  {
    udtMemIfJobResult = MemIf_GetJobResult(NvM_akstreBlockDescriptor
     [NvM_udteCurrentBlockID].u8NvRamDeviceId);
  }
  switch(udtMemIfJobResult)
  {
    /* !Pseudo:  Case Job Pending                                             */
    case MEMIF_JOB_PENDING:
      /* !Pseudo:  Do Nothing in this main function cycle                     */
      break;

    /* !Pseudo: Case Job OK                                                   */
    case MEMIF_JOB_OK:

      /* !Pseudo: Set Pre Error Status to NVM_REQ_OK                          */
	  /* !Trace_To        : GSCSW-NVM-SDD-001-0529                            */
      NvM_u8SBPreErrorStatus = NVM_REQ_OK;

      u16BlockLength = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                             u16NvBlockLength;

      /* !Pseudo: If The block uses Static Block Id Check                     */
      if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck
               == (boolean)TRUE)
      {
        /* !Pseudo: Compare the static block Id Check                         */
        /* !Pseudo: If the static block Id match                              */
		/* !Trace_To: GSCSW-NVM-SDD-001-0518                                  */
        if( NvM_bIsStaticBlkIdConsis() == (boolean)TRUE )
        {
          /* !Pseudo: Copy the Nv Data from the internal Ram Buffer to the
                      Application buffer (Temp or Permanent)                  */
          u8NumOfBlkHdrBytes = u8CalcBlkNumHdrBytes();
          for(u16LengthCount=0;u16LengthCount<NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
          .u16NvBlockLength;u16LengthCount++)
          {
            NvM_pu8CurrentRamBlkAddr[u16LengthCount] =
              NvM_au8InternalRamBuffer[(uint16)(u16LengthCount + u8NumOfBlkHdrBytes)];
          }
          /* !Pseudo: If the Block Uses CRC                                   */
		  /* !Trace_To: GSCSW-NVM-SDD-001-0521                                */
          if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
            == (boolean)TRUE)
          {
            /* !Pseudo: Copy Crc Data From Internal Buffer to Ram Block Crc
                        Address                                               */
            vidCopyCrc(u16BlockLength,u8NumOfBlkHdrBytes,(boolean)TRUE);
            /* !Pseudo: Set State to RDB_CALC_CRC_AND_CMP */
            NvM_enuSBPrcsState = RDB_CALC_CRC_AND_CMP;
          }
          /* !Pseudo: Else, CRC is not configured for this block              */
          else
          {
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
            /* !Pseudo: If the block uses Block Sync. Mechanism && Current job
                      ID is NvM_u8READ_BLOCK_ID                               */
            if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                               .bBlkUseSyncMechanism ==(boolean)TRUE) &&
                 (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID) )
            {
              /* !Pseudo: Set State to RDB_CALL_APP_COPY */
              NvM_enuSBPrcsState = RDB_CALL_APP_COPY;
              /* !Pseudo: Call vidRdBCallAppCopy() */
              vidRdBCallAppCopy();
            }
            /* !Pseudo: Else                                                  */
            else
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
            {

              /* !Pseudo: Enable write protection if write block once is configured   */
              /* !Trace_To        : GSCSW-NVM-SDD-001-0527                    */
              if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
                   == (boolean)TRUE)
              {
			     /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
                 /*              during integration phase                                    */
                 /* PRQA S 3141 ++                                                           */
				  SchM_Enter_NvM_NVM_ACCESS_001();
				  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
				  SchM_Exit_NvM_NVM_ACCESS_001();
                 /* PRQA S 3141 --                                                           */
              }
              /* !Trace_To: GSCSW-NVM-SDD-001-0589                            */
              /* !Pseudo: If the RAM buffer used in the API call is the same
              as the configured Ram buffer of the NVRAM block and if it is
              not NULL                                                        */
              /* !Pseudo: Then update the state of the current block to
              u8VALID_UNCHANGED                                               */
              vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);

              /* !Pseudo: If the block is redundant and first block failed    */
              if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                          .u8BlockManagementType == NVM_BLOCK_REDUNDANT) &&
                   (NvM_bFrstRddtBlkFailed == (boolean)TRUE ) )
              {
			    /* !Trace_To: GSCSW-NVM-SDD-001-0588                          */
                /* !Pseudo: Set NvM_enuSBPrcsState to RDB_WRT_RDDT_BLK        */
                NvM_enuSBPrcsState = RDB_WRT_RDDT_BLK;
                NvM_enuRdBlkWrtRddtBlkSt = RDB_WAIT_MEMIF_IDLE;
              }
              /* !Pseudo: Else, block not redundant or first block passed     */
              else
              {
                /* !Pseudo: Call Read Block Prcs DeInit (Successful)          */
                vidRdBPrcsDeInit((boolean)TRUE);
              }
            }
          }
        }
        /* !Pseudo: If the static block Id doesn't match                      */
		/* !Trace_To: GSCSW-NVM-SDD-001-0519                                  */
        else
        {
          /* !Pseudo: store initial DEM error NVM_E_WRONG_BLOCK_ID            */
		  /* !Trace_To: GSCSW-NVM-SDD-001-0308                                */
          NvM_u16PreDemError = NVM_E_WRONG_BLOCK_ID;
          /* !Pseudo: set Pre Error Status to NVM_REQ_NOT_OK                  */
          NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
          /* !Pseudo: Call vidReadBErrorHook to initiate read error recovery  */
		  /* !Trace_To: GSCSW-NVM-SDD-001-0520                                */
          vidReadBErrorHook();
        }
      }
      /* Else, Block Doesn't use Static Block Id Check but the Block Uses CRC */
      else if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
          == (boolean)TRUE)
      {
        u8NumOfBlkHdrBytes = (uint8)0;
        /* !Pseudo: Copy the Nv Data from the internal Ram Buffer to the
                    Application buffer (Temp or Permanent)                    */
        for(u16LengthCount=0;u16LengthCount<NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
        .u16NvBlockLength;u16LengthCount++)
        {
          NvM_pu8CurrentRamBlkAddr[u16LengthCount] =
            NvM_au8InternalRamBuffer[u16LengthCount];
        }
		
          /* !Pseudo: Copy Crc Data From Internal Buffer to Ram Block Crc
                        Address                                               */
            vidCopyCrc(u16BlockLength,u8NumOfBlkHdrBytes,(boolean)TRUE);
            /* !Pseudo: Set State to RDB_CALC_CRC_AND_CMP */
            /* !Trace_To: GSCSW-NVM-SDD-001-0400                              */
            NvM_enuSBPrcsState = RDB_CALC_CRC_AND_CMP;
        }
        /* !Pseudo: Else, CRC is not configured for this block                */
        else
        {
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
          /* !Pseudo: If the block uses Block Sync. Mechanism && Current job
                      ID is NvM_u8READ_BLOCK_ID                               */
          if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                               .bBlkUseSyncMechanism ==(boolean)TRUE) &&
              (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID) )
          {
            /* !Pseudo: Set State to RDB_CALL_APP_COPY */
            NvM_enuSBPrcsState = RDB_CALL_APP_COPY;
            /* !Pseudo: Call vidRdBCallAppCopy() */
            vidRdBCallAppCopy();
          }
          /* !Pseudo: Else                                                    */
          else
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
          {
            /* !Pseudo: Enable write protection if write block once is configured   */
			/* !Trace_To        : GSCSW-NVM-SDD-001-0527                    */
            if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
                 == (boolean)TRUE)
            {
				 /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
                 /*              during integration phase                                    */
                 /* PRQA S 3141 ++                                                           */
				SchM_Enter_NvM_NVM_ACCESS_001();
				u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
				SchM_Exit_NvM_NVM_ACCESS_001();
                /* PRQA S 3141 --                                                           */
            }

            /* !Pseudo: If the RAM buffer used in the API call is the same
            as the configured Ram buffer of the NVRAM block and if it is
            not NULL                                                          */
            /* !Pseudo: Then update the state of the current block to
            u8VALID_UNCHANGED                                                 */
			     /* !Trace_To: GSCSW-NVM-SDD-001-0512,GSCSW-NVM-SDD-001-0589        */
            vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);
            /* !Pseudo: If the block is redundant and first block failed    */
            if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                        .u8BlockManagementType == NVM_BLOCK_REDUNDANT) &&
                 (NvM_bFrstRddtBlkFailed == (boolean)TRUE ) )
            {
              /* !Pseudo: Set NvM_enuSBPrcsState to RDB_WRT_RDDT_BLK        */
              NvM_enuSBPrcsState = RDB_WRT_RDDT_BLK;
              NvM_enuRdBlkWrtRddtBlkSt = RDB_WAIT_MEMIF_IDLE;
            }
            /* !Pseudo: Else, block not redundant or first block passed     */
            else
            {
              /* !Pseudo: Call Read Block Prcs DeInit (Successful)          */
              vidRdBPrcsDeInit((boolean)TRUE);
            }
          }
        }
      break;

    /* !Pseudo: Case Block Invalid                                            */
    case MEMIF_BLOCK_INVALID:
      /* !Pseudo: Set Pre Error Status to NVM_REQ_NV_INVALIDATED              */
      NvM_u8SBPreErrorStatus = NVM_REQ_NV_INVALIDATED;
      /* !Pseudo: Call Read Block Error Hook                                  */
      vidReadBErrorHook();
      break;

    /* !Pseudo: Case Block Inconsistent                                       */
    case MEMIF_BLOCK_INCONSISTENT:

      /* !Pseudo: Enable write protection if write block once is configured   */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
        == (boolean)TRUE)
      {
	     /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
         /*              during integration phase                                    */
         /* PRQA S 3141 ++                                                           */
		  SchM_Enter_NvM_NVM_ACCESS_001();
		  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
		  SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                           */
      }
      /* !Trace_To: GSCSW-NVM-SDD-001-0522                                    */
      /* !Pseudo:   Call DEM */
      /* !Pseudo: store initial DEM error NVM_E_INTEGRITY_FAILED              */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0306                                    */
      NvM_u16PreDemError = NVM_E_INTEGRITY_FAILED;
      /* !Pseudo: Set Pre Error Status to NVM_REQ_INTEGRITY_FAILED            */
      NvM_u8SBPreErrorStatus = NVM_REQ_INTEGRITY_FAILED;
      /* !Pseudo: Call Read Block Error Hook                                  */
      vidReadBErrorHook();
      break;

    /* !Pseudo: Default (  MEMIF_JOB_FAILED,  MEMIF_JOB_CANCELED )           */
    case MEMIF_JOB_FAILED:
    case MEMIF_JOB_CANCELED:
    default:

      /* !Pseudo: Enable write protection if write block once is configured   */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
        == (boolean)TRUE)
      {   
	     /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
		/*              during integration phase                                    */
		/* PRQA S 3141 ++                                                           */
          SchM_Enter_NvM_NVM_ACCESS_001();
		  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
		  SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                          */
      }
      /* !Pseudo: store initial DEM error NVM_E_REQ_FAILED                    */
	    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
	    /* !Trace_To: GSCSW-NVM-SDD-001-0516                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0568                                    */
      NvM_u16PreDemError = NVM_E_REQ_FAILED;
      /* !Pseudo: set Pre Error Status to NVM_REQ_NOT_OK                      */
      NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
      /* !Pseudo: Call Read Block Error Hook                                  */
      vidReadBErrorHook();
      break;
  }

}

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
/******************************************************************************/
/* !Description : Function that calls NvMReadRamBlockFromNvM of the block
                  ,waits for the completion of the copying of data and perform
                  retries (NvMRepeatMirrorOperations) times                   */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidRdBCallAppCopy(void)
{
  Std_ReturnType u8Return;

/* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */

/* !Deviation : inhibit MISRA rule [3359]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */

/* !Deviation : inhibit MISRA rule [3201]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */
/* PRQA S 3201 ++                                                           */
/* PRQA S 3356 ++                                                           */
/* PRQA S 3359 ++                                                           */

  /* !Pseudo:If Repeat Mirror Operation Counter <= NVM_REPEAT_MIRROR_OPERATIONS*/
  /* !Trace_To: GSCSW-NVM-SDD-001-0525                                        */
  if ( NvM_u8RepeatMirrorOp <= NVM_REPEAT_MIRROR_OPERATIONS )
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0524                                      */
    /* !Trace_To: GSCSW-NVM-SDD-001-0378                                      */
    /* !Pseudo: Call the NvMReadRamBlockFromNvM callback of the block         */
    u8Return = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                   .pfu8ReadRamBlkFromNvCbk(NvM_au8RamMirrorBuffer);
    /* !Pseudo: If the Application completed copying the data (E_OK Returned) */
    if( u8Return == E_OK )
    {
      if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                        .u8BlockManagementType == NVM_BLOCK_REDUNDANT) &&
                 (NvM_bFrstRddtBlkFailed == (boolean)TRUE ) )
      {
        /* !Pseudo: Set NvM_enuSBPrcsState to RDB_WRT_RDDT_BLK        */
        NvM_enuSBPrcsState = RDB_WRT_RDDT_BLK;
        NvM_enuRdBlkWrtRddtBlkSt = RDB_WAIT_MEMIF_IDLE;
      }
      /* !Pseudo: Else, block not redundant or first block passed     */
      else
      {
        /* !Pseudo: Call Read Block Prcs DeInit (Successful)          */
        vidRdBPrcsDeInit((boolean)TRUE);
      }
    }
    /* !Pseudo: Else, return is E_NOT_OK                                      */
    else
    {
	  /* !Trace_To: GSCSW-NVM-SDD-001-0525                                    */
      /* !Pseudo: Increment the Repeat Mirror Operation Counter               */
      NvM_u8RepeatMirrorOp++;
    }
  }
/* PRQA S 3201 --                                                           */
/* PRQA S 3356 --                                                           */
/* PRQA S 3359 --                                                           */

  /* !Pseudo: Else, mirror operation counter overrun                          */
  /* !Trace_To: GSCSW-NVM-SDD-001-0525                                        */
  else
  {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    /* !Pseudo: If the current job is immediate job                           */
    if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockJobPriority
               == (uint8)0 )
          #if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
          && (NvM_u8eCurrentJobID == NvM_u8WRITE_BLOCK_ID)
          #endif
		)
#endif /*(NVM_JOB_PRIORITIZATION == STD_ON)*/
    {
      /* !Pseudo: If more than one job exist in the Imdt Q                    */
      if((NvM_strImdtQAdmin.u8NumOfQuedJobs) > (uint8)1 )
      {
        /* !Pseudo: Swap the current job with the next job in Imdt Q          */
        vidSwapJobInImdtQ();
      }
    }
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    /* !Pseudo: Else, the current job is standard job                         */
    else
    {
	  /* !Trace_To: GSCSW-NVM-SDD-001-0422                                    */
	  /*  !Pseudo: If there are no explicit jobs delayed                      */
      if ( NvM_bExpStdJobDelayed != (boolean)TRUE )
      {
        NvM_bExpStdJobDelayed = (boolean)TRUE;
        /* !Pseudo: Store the current job information                           */
        NvM_strExpSyncDelayedJob.bTimeToServeExpJob = (boolean)FALSE;
        NvM_strExpSyncDelayedJob.u8JobID = NvM_u8eCurrentJobID;
        NvM_strExpSyncDelayedJob.udtBlockID = NvM_udteCurrentBlockID;
        NvM_strExpSyncDelayedJob.pu8RamBlkAddr = NvM_pu8CurrentRamBlkAddr;
      }
    }
#endif /*(NVM_JOB_PRIORITIZATION == STD_ON)*/

    /*  !Pseudo: Reset State of Main Function to serve the next job           */
    NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;
    /* !Pseudo: Search for next job in queue and start serving it             */
    vidMfnJobsScanThenStart();
  }
}

#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
/******************************************************************************/
/* !Description : Function that calculates Ram Block CRC and decides whether
                  actual reading in NV memory is required or not.             */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStPreCalcCrcThenCmp(void)
{
  Std_ReturnType u8StateReturnVal;

  /* !Pseudo:  Call corresponding State fn                                    */
  u8StateReturnVal = u8StCalcRamBlkCRC();
  /* !Pseudo: If return Value is OK ( ie. CRC calculation is finished)        */
  if(u8StateReturnVal == E_OK)
  {
    /* !Pseudo: Call Compare CRCs Fn                                          */
    /* !Pseudo: If mismatching                                                */
    /* !Trace_To: GSCSW-NVM-SDD-001-0586                                      */
    if(bCompareRamBlkCRC() == (boolean)FALSE)
    {
      /* No check for temporary or permanent RAM buffer
      is necessary here, because this function is called during
      the Read All process. So permanent RAM buffer is implied.               */

      /* Restoring from NV memory                                             */
      /* !Pseudo:  Set the Admin Block state to invalid                       */
      NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8State = u8INVALID;

      /* !Pseudo:  Initialize pre-error status to failed.                     */
      NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;

      /*  !Pseudo: Initialize the state                                       */
      NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;
    }
    /* !Pseudo: Else (CRC matching)                                           */
    /* !Trace_To: GSCSW-NVM-SDD-001-0574                                      */
    else
    {
      /* !Pseudo: No check for temporary or permanent RAM buffer
      is necessary here, because this function is called during
      the Read All process. So permanent RAM buffer is implied.               */
      /* !Pseudo: Set the Admin Block state to Valid and Unchanged            */
      NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8State = u8VALID_UNCHANGED;
      /* !Pseudo:  Initialize pre-error status to OK.                         */
	  /* !Trace_To        : GSCSW-NVM-SDD-001-0529                            */
      NvM_u8SBPreErrorStatus = NVM_REQ_OK;
      /* !Pseudo: Call RdB Process DeInit (Successful)                        */
      vidRdBPrcsDeInit((boolean)TRUE);
    }
  }
}
#endif  /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)                           */


/******************************************************************************/
/* !Description : Function that calculates Ram Block CRC then compare it with
                  the NV CRC.                                                 */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStRdBCalcCrcThenCmp(void)
{
  Std_ReturnType u8StateReturnVal;

  /* !Pseudo:  Call corresponding State fn                                    */
  u8StateReturnVal = u8StCalcRamBlkCRC();
  /* !Pseudo: If return Value is OK ( ie. CRC calculation is finished)        */
  if(u8StateReturnVal == E_OK)
  {
    /* !Pseudo: Call Compare CRCs Fn                                          */
    /* !Pseudo: If mismatching                                                */
	/* !Trace_To: GSCSW-NVM-SDD-001-0570                                      */
    if(bCompareRamBlkCRC() == (boolean)FALSE)
    {
      /* !Pseudo: Call Dem */
      /* !Pseudo: store initial DEM error NVM_E_INTEGRITY_FAILED              */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0306                                    */
      NvM_u16PreDemError = NVM_E_INTEGRITY_FAILED;
      /* !Pseudo: set Pre Error Status to NVM_REQ_INTEGRITY_FAILED            */
      NvM_u8SBPreErrorStatus = NVM_REQ_INTEGRITY_FAILED;
      /* !Pseudo: Call Read Block Error Hook                                  */
      /* !Trace_To: GSCSW-NVM-SDD-001-0523                                    */
	  /* !Trace_To        : GSCSW-NVM-SDD-001-0528                            */
      vidReadBErrorHook();
    }
    /* !Pseudo: Else (CRC matching)                                           */
    else
    {
#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
      /* !Pseudo: If the block uses Block Sync. Mechanism && Current job
                      ID is NvM_u8READ_BLOCK_ID                               */
      if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                        .bBlkUseSyncMechanism ==(boolean)TRUE) &&
           (NvM_u8eCurrentJobID == NvM_u8READ_BLOCK_ID) )
      {
        /* !Pseudo: Set State to RDB_CALL_APP_COPY */
		/* !Trace_To: GSCSW-NVM-SDD-001-0524                              */
        NvM_enuSBPrcsState = RDB_CALL_APP_COPY;
        /* !Pseudo: Call vidRdBCallAppCopy() */
        vidRdBCallAppCopy();
      }
      /* !Pseudo: Else                                                    */
      else
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

      {
        /* !Pseudo: Enable write protection if write block once is configured   */
		/* !Trace_To        : GSCSW-NVM-SDD-001-0527                    */
        if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
          == (boolean)TRUE)
        {   
		  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
          /*              during integration phase                                    */
          /* PRQA S 3141 ++                                                           */
            SchM_Enter_NvM_NVM_ACCESS_001();
			u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
			SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                           */
        }
        /* !Trace_To: GSCSW-NVM-SDD-001-0589                                    */
        /* !Pseudo: If the RAM buffer used in the API call is the same
        as the configured Ram buffer of the NVRAM block and if it is
        not NULL                                                          */
        /* !Pseudo: Then update the state of the current block to
        u8VALID_UNCHANGED                                                 */
        vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);
        if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                        .u8BlockManagementType == NVM_BLOCK_REDUNDANT) &&
                 (NvM_bFrstRddtBlkFailed == (boolean)TRUE ) )
        {
          /* !Pseudo: Set NvM_enuSBPrcsState to RDB_WRT_RDDT_BLK        */
          NvM_enuSBPrcsState = RDB_WRT_RDDT_BLK;
          NvM_enuRdBlkWrtRddtBlkSt = RDB_WAIT_MEMIF_IDLE;
        }
        /* !Pseudo: Else, block not redundant or first block passed     */
        else
        {
		  /* !Trace_To: GSCSW-NVM-SDD-001-0587                          */
          /* !Pseudo: Call Read Block Prcs DeInit (Successful)          */
          vidRdBPrcsDeInit((boolean)TRUE);
        }
      }
    }
  }
}


/******************************************************************************/
/* !Description : Function that writes the redundant block in case one of them
                  failed to be read (to restore redundancy).                  */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdBWrtRddtBlk(void)
{
  Std_ReturnType u8MemIfReturnResult;
  MemIf_StatusType udtMemIfStatus;
  MemIf_JobResultType udtMemIfJobResult;
  uint16 u16BlockNumber;

  switch (NvM_enuRdBlkWrtRddtBlkSt)
  {
    case RDB_WAIT_MEMIF_IDLE:
    /* !Pseudo: Call Get Status of MemIf                                      */
    udtMemIfStatus = MemIf_GetStatus(NvM_akstreBlockDescriptor
      [NvM_udteCurrentBlockID].u8NvRamDeviceId);
    /* !Pseudo: If Idle */
    if(udtMemIfStatus == MEMIF_IDLE)
    {
      u16BlockNumber = (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                                         .u16NvBlockBaseNumber) + (uint16)0 ;

      /* !Pseudo: Call Write Block of MemIf */
      if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc == (boolean)TRUE ) ||
	  (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteVerification == (boolean)TRUE )|| 
      (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck == (boolean)TRUE))
	  {
      u8MemIfReturnResult = MemIf_Write(NvM_akstreBlockDescriptor
        [NvM_udteCurrentBlockID].u8NvRamDeviceId,u16BlockNumber,
        NvM_au8InternalRamBuffer);
	  }
      else
	  {
      u8MemIfReturnResult = MemIf_Write(NvM_akstreBlockDescriptor
        [NvM_udteCurrentBlockID].u8NvRamDeviceId,u16BlockNumber,
        NvM_pu8CurrentRamBlkAddr);
      } 
      /* !Pseudo: If request is Accepted Go to Wait for Write completion      */
      if ( u8MemIfReturnResult == E_OK )
      {
        NvM_enuRdBlkWrtRddtBlkSt = RDB_WAIT_WRITE_END;
      }
       /* !Pseudo: If request is not accepted                                 */
      else
      {
         /* !Pseudo: Report DEM error NVM_E_LOSS_OF_REDUNDANCY                */
		 /* !Trace_To: GSCSW-NVM-SDD-001-0312                                 */
        Dem_ReportErrorStatus(NVM_E_LOSS_OF_REDUNDANCY,DEM_EVENT_STATUS_FAILED);
        /* !Pseudo: Call Read Block Prcs DeInit (Successful)                  */
        vidRdBPrcsDeInit((boolean)TRUE);
      }
    }

    /* !Pseudo: Else Do nothing                                               */
    else
    {
    }
    break;

    case RDB_WAIT_WRITE_END:
    /* !Pseudo:  Get Job Result of MemIf */
    /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
#if (NVM_POLLING_MODE == STD_ON)
    udtMemIfJobResult = MemIf_GetJobResult(NvM_akstreBlockDescriptor
   [NvM_udteCurrentBlockID].u8NvRamDeviceId);
#else
    udtMemIfJobResult = NvM_udtMemIfJobEndClBck;
  #endif

    /* !Pseudo:  If Pending                                                   */
    if(udtMemIfJobResult == MEMIF_JOB_PENDING)
    {
    /* !Pseudo:  Do Nothing in this main function cycle                       */
    }
    /* !Pseudo:  Else If OK                                                   */
    else if(udtMemIfJobResult == MEMIF_JOB_OK)
    {
      /* !Pseudo: Call Read Block Prcs DeInit (Successful)                    */
      vidRdBPrcsDeInit((boolean)TRUE);
    }
    /* !Pseudo: Else (Job Failed)                                             */
    else
    {
      /* !Pseudo: Report DEM error NVM_E_LOSS_OF_REDUNDANCY                   */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0312                                    */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0588                                    */
      Dem_ReportErrorStatus(NVM_E_LOSS_OF_REDUNDANCY,DEM_EVENT_STATUS_FAILED);
      /* !Pseudo: Call Read Block Prcs DeInit (Successful)                    */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0421                                    */
      vidRdBPrcsDeInit((boolean)TRUE);
    }
    break;

    /* !Deviation : Inhibit MISRA rule [2018]: Reason: Another Misra Rule     */
    /* PRQA S 2018 ++                                                         */
    default:
      break;
    /* PRQA S 2018 --                                                         */
  }
}

/******************************************************************************/
/* !Description : Read Block Error Hook. It takes neccessary actions
                  (load redundant block or load rom defaults or DeInit)       */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidReadBErrorHook(void)
{
  /* !Pseudo: If read retries counter < configured read retries               */
  /* !Trace_To: GSCSW-NVM-SDD-001-0513                                        */
  if( NvM_u8ReadRetriesCtr < NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                                  u8MaxNumOfReadRetries )
  {
    /* !Pseudo: Increment the read retries coutner                            */
    NvM_u8ReadRetriesCtr++;
	/* !Pseudo: Set NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ                  */
    NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;
  }
  /* !Trace_To: GSCSW-NVM-SDD-001-0513                                        */
  else
  /* !Pseudo: If Block type is redundant and 2nd block is not yet processed   */
  if(  (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                            u8BlockManagementType == NVM_BLOCK_REDUNDANT     )
    && (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex == (uint8)0) )
  {
    /* !Pseudo:  Set Data Index to 1                                          */

    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)1u;
    /* !Pseudo: Set state to RDB_WAIT_MEMIF_READ                              */
    NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;
    NvM_u8ReadRetriesCtr = (uint8)0;
    NvM_bFrstRddtBlkFailed = (boolean)TRUE;
  }
  else if(
           ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                              pku8RomBlkDataAddress != NULL_PTR) ||
             (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                              pfu8InitBlockCallBack != NULL_PTR) )
         )
  {
  /* !Pseudo: Else if Loading Rom Defaults possible                           */
  /* !Trace_To: GSCSW-NVM-SDD-001-0569, GSCSW-NVM-SDD-001-0509                */
  /* !Pseudo: if NvM_u8SBPreErrorStatus != NVM_REQ_NV_INVALIDATED           */
	if (NvM_u8SBPreErrorStatus != NVM_REQ_NV_INVALIDATED)
	{
	/* !Pseudo: Report the stored DEM error to DEM                          */
	Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
	}
	/* !Pseudo: Set state to RDB_RSTR_BLK_PRCS                                */
	/* !Trace_To: GSCSW-NVM-SDD-001-0517                                      */
	NvM_enuSBPrcsState = RDB_RSTR_BLK_PRCS;
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
	if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                       u8BlockManagementType == NVM_BLOCK_DATASET)
	{	
		if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
				pfu8InitBlockCallBack != NULL_PTR)
		{
		/* !Pseudo:     Call Init Callback function                               */
			(void) NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
				pfu8InitBlockCallBack();
		}
		#if (NVM_SET_RAM_BLOCK_STATUS_API != STD_OFF)
		/* !Pseudo:  If CRC shall not be calculated by the write block service      */
		/* !Trace_To: GSCSW-NVM-SDD-001-0489                                        */
		if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bCalcRamBlockCrc
			== (boolean)TRUE)
		{
			/* !Pseudo:   Call Init fn of Calc Ram Block CRC state                    */
			vidStCalcRamCRCInit();
		}
		#endif /* (NVM_SET_RAM_BLOCK_STATUS_API !=STD_OFF) */
	}
	else
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */
	{
		/* !Pseudo: Call the Init Fn of the Restore Blk Dfts Process              */
		/* !Trace_To: GSCSW-NVM-SDD-001-0581                                    */
		vidRstrBlkDftsPrcsInit();
	}
		/* !Pseudo: Call the Restore Blk Dfts Process and if it finishes then
		it will deinit the read block process by deinit of the retore process     */
		vidRstrBlkDftsPrcs();
  }
  else
  {
      /* !Trace_To: GSCSW-NVM-SDD-001-0515                                    */
    /* !Pseudo: if NvM_u8SBPreErrorStatus != NVM_REQ_NV_INVALIDATED           */
    if (NvM_u8SBPreErrorStatus != NVM_REQ_NV_INVALIDATED)
    {

      /* !Pseudo: Report the stored DEM error to DEM                          */
      Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
    }
    /* !Pseudo: Call RdB Process DeInit (Failed)                              */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0514                                    */
    vidRdBPrcsDeInit((boolean)FALSE);
  }

}

/******************************************************************************/
/* !Description : Read Block DeInit.                                          */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidRdBPrcsDeInit(boolean bPrcsSuceeded)
{
  /* !Pseudo: If block Id under process is the reserved config ID             */
  if(NvM_udteCurrentBlockID == udtCONFIG_BLOCK_ID)
  {
  /* !Pseudo: If Process Failed                                               */
    if(bPrcsSuceeded == (boolean)FALSE)
    {
       /* !Pseudo: If the pre error status is not equal to
       NVM_REQ_NV_INVALIDATED                                                 */
      if(NvM_u8SBPreErrorStatus != NVM_REQ_NV_INVALIDATED)
      {
        /* !Pseudo:   Set Pre Error Status to NVM_REQ_INTEGRITY_FAILED        */
        NvM_u8SBPreErrorStatus = NVM_REQ_INTEGRITY_FAILED;
      }

    }
    /* !Pseudo: Else */
    else
    {
      /* !Pseudo: If the read block is not equal to the compiled config ID    */
      if((NvM_bRdBIsConfigIdConsis()) == (boolean)FALSE)
      {
        /* !Pseudo:    Set Pre Error Status to NVM_REQ_NOT_OK                 */
        NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
      }
    }
  }
  /* !Pseudo: Call Process DeInit                                             */
  vidSBPrcsDeInit(NvM_u8SBPreErrorStatus);
}

/******************************************************************************/
/* !Description : Compare the Read Config ID with the Compiled Config ID.     */
/******************************************************************************/
LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bRdBIsConfigIdConsis(void)
{
  boolean bReturnValue = (boolean)TRUE;

  /* !Pseudo:  Compare the RAM Block with the compiled ID ,
  Return True if equal                                                        */

  /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to     */
  /*              deal with 2 different variable types.                       */
  /* PRQA S 0310 ++                                                           */

  /* PRQA S 0310 --                                                           */
  if((NvM_pu8CurrentRamBlkAddr[0] != (uint8) NVM_COMPILED_CONFIG_ID) ||
     (NvM_pu8CurrentRamBlkAddr[1] != (uint8) (NVM_COMPILED_CONFIG_ID >> 8)) )
  {
    bReturnValue = (boolean)FALSE;
  }
  return(bReturnValue);
}

/******************************************************************************/
/* Functions used by Read All process.                                        */
/******************************************************************************/

/******************************************************************************/
/* !Description : Function that initializes Read All process.                 */
/******************************************************************************/

LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidReadAllPrcsInit(void)
{
  /* !Pseudo: Restore the context of multi block job, in order to resume the
     multiblock action from the current block processed                       */

  /* Initialize current block ID with the saved one                           */
  NvM_udteCurrentBlockID = NvM_strMBJobBfr.udtBlockID;

  /* !Pseudo: If entering the Read All process for the 1st time
  (ie. Not resuming a frozen one)                                             */
  if(NvM_udteCurrentBlockID == udtCONFIG_BLOCK_ID)
  {
    /*  !Pseudo:  Initialize MB pre-error status to successful                */
    NvM_u8MBlkPreErrorStatus = NVM_REQ_OK;
    /*  !Pseudo: Set Multi Block state to RDA_XREAD_CFG_ID                    */
    NvM_enuMBlkPrcsState = RDA_XREAD_CFG_ID ;
    /*  !Pseudo: Save the Ram Block Address of the Configuration block ID     */
    NvM_pu8CurrentRamBlkAddr = NvM_akstreBlockDescriptor[udtCONFIG_BLOCK_ID].
      pvidRamBlockDataAddress;
    /*  !Pseudo: Initialize Read Block process of the config ID               */
    vidReadBlkPrcsInit();
  }
  /* !Pseudo: Else (Resuming frozen Job due to Immediate Job)                 */
  else
  {
    /* !Pseudo: Set Multi Block state to RDA_WAIT_MEMIF_IDLE                  */
    NvM_enuMBlkPrcsState = RDA_WAIT_MEMIF_IDLE ;
  }

}
/******************************************************************************/
/* !Description : Read All process. It is called at every Mnf cycle if there
                  is a read all process in progress                           */



/******************************************************************************/
static FUNC(void, NVM_CODE) vidReadAllPrcs(void)
{
  /*  !Comment: Variable used as a function return. It indicates if the next
                state shall be executed immediately(ie. within the same main
				function cycle)                                               */
  boolean bExecuteNextState;

  /*  !Pseudo: Do until no states need to be executed in this main function
  cycle                                                                       */
  do
  {
    /*  !Pseudo: Reset "Execute Next State" Flag                              */
    bExecuteNextState = (boolean)FALSE;
    /* !Pseudo: Switch (MB process state)                                     */
    switch (NvM_enuMBlkPrcsState)
    {
       /* !Pseudo: case  RDA_XREAD_CFG_ID                                     */
       /* !Trace_To: GSCSW-NVM-SDD-001-0118                                   */
      case RDA_XREAD_CFG_ID:
        bExecuteNextState = NvM_bStRdARdBConfigID();
        break;

       /* !Pseudo: case  RDA_WAIT_MEMIF_IDLE                                  */
      case RDA_WAIT_MEMIF_IDLE:
        /* !Pseudo:  Set the Memory Interface to fast mode if it is Idle      */
        bExecuteNextState = bStWaitMemIfIdle();
        break;

       /* !Pseudo:  case RDA_XCALL_RDB                                        */
      case RDA_XCALL_RDB:
        /*  !Pseudo: Cross Call of read block process                         */
        NvM_vidStRdACrossRdB();
        break;

     #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
       /* !Pseudo:  case RDA_XCALL_RSTRB_DFTS                                 */
      case RDA_XCALL_RSTRB_DFTS:
        /*  !Pseudo: Cross Call of restore block defaults block process       */
        NvM_vidStRdACrossRstrBDfts();
        break;
     #endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON)                          */

       /* !Pseudo:  case RDA_DEINIT_IF_IDLE                                   */
      case RDA_DEINIT_IF_IDLE:
        /* !Pseudo:  DeInit Read All process if MemIf is Idle ( Pass False to
        the Fn to indicate that this is a normal End of MB Job , not freezing)*/
        vidStMBPrcsDeInit((boolean)FALSE);
        break;

      /* !Pseudo:  Default (Invalid Process State then call Det with abnormal
      branch)                                                                 */
      case WRA_XWRITE_CFG_ID :
      case WRA_WAIT_MEMIF_IDLE :
      case WRA_XCALL_WRB :
      case WRA_DEINIT_IF_IDLE :
      default:
        #if (NVM_DEV_ERROR_DETECT == STD_ON)
        /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
          (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
                NvM_u8MAIN_FUNCTION_ID, NVM_E_ABNORMAL_BRANCH);
        #else
          /* !Pseudo: Report error to the DEM                                 */
          Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                          DEM_EVENT_STATUS_FAILED);
        #endif
        break;
    }
  } while (bExecuteNextState == (boolean)TRUE);
}



/******************************************************************************/
/* !Description : State of Read config ID                                     */
/******************************************************************************/
LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStRdARdBConfigID(void)
{
  /*  !Pseudo: Reset "Execute Next State" Flag                                */
  boolean bExecuteNextState = (boolean)FALSE;

  /* !Pseudo:  Call read block process                                        */
  vidReadBlkPrcs();

  /* !Pseudo:  If read block is finished                                      */
  if(NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus != u8PEND_MULTIBLK_JOB)
  {
    /*  !Pseudo: Set MB state to be RDA_WAIT_MEMIF_IDLE                       */
    NvM_enuMBlkPrcsState = RDA_WAIT_MEMIF_IDLE;

    #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
    /*  !Pseudo: Update the config ID (if needed) and set the runtime mode
    to Normal or Extended                                                     */
    NvM_vidRdAHandleDynConfig();
    #endif

    /*  !Pseudo: Increment the current block ID. To begin searching from
    block 2 because block 1 is served.                                        */
    NvM_udteCurrentBlockID++;

    /*  !Pseudo: Set "Execute Next State" Flag to TRUE                        */
    bExecuteNextState = (boolean)TRUE;
  }

  /*  !Pseudo: Return "Execute Next State" Flag                               */
  return(bExecuteNextState);
}




/******************************************************************************/
/* !Description : State of Cross call of the read block process               */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdACrossRdB(void)
{

  /* !Pseudo:  Call read block process                                        */
  vidReadBlkPrcs();
  /* !Pseudo:  If Read block is finished                                      */
  if(NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus
    != u8PEND_MULTIBLK_JOB)
  {
    /* !Pseudo:  Update MB error status and find next blk to be processed     */
    vidUpdateMBErrorStatus();
    vidServeNextBlk();

  }
}


/******************************************************************************/
/* Functions only used in case of Dynamic Configuration is configured(ReadAll)*/
/******************************************************************************/

#if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
/******************************************************************************/
/* !Description : State of Cross call of the restore block defaults process   */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStRdACrossRstrBDfts(void)
{

  /* !Pseudo:  Call restore block defaults process                            */
  vidRstrBlkDftsPrcs();
  /* !Pseudo:  If Restore block defaults is finished                          */
  if(NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus
    != u8PEND_MULTIBLK_JOB)
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0577                                      */
    /* !Pseudo:  If  block configured as write block once, then disable the
    protection to allow rewriting of the block                                */
    if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
              == (boolean)TRUE)
    {
	  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
      /*              during integration phase                                    */
      /* PRQA S 3141 ++                                                           */
        SchM_Enter_NvM_NVM_ACCESS_001();
		u8CLEAR_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_DISABLE);
		SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                           */
    }
    /* !Pseudo:  Update MB error status and find next blk to be processed     */
    vidUpdateMBErrorStatus();

    vidServeNextBlk();
  }
}


/******************************************************************************/
/* !Description :  Update the config ID (if needed) and set the runtime mode to
                  Normal or Extended                                          */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidRdAHandleDynConfig(void)
{

  /* !Pseudo:  If Read Config ID Job result is not equal to NVM_REQ_OK        */

  if(NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus != NVM_REQ_OK)
  {
    /* !Pseudo:  Update the RAM Block with the compiled ID and Mark as Valid
    and Changed                                                               */
    NvM_vidRdAUpdateConfigID();
    /* !Pseudo:  If Read Config ID Job result is equal to
    NVM_REQ_NV_INVALIDATED                                                    */

    if(NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus ==
         NVM_REQ_NV_INVALIDATED)
    {
      /* !Pseudo:  Set runtime mode to Normal                                 */

      NvM_u8RdARunTimeMode = u8NORMAL_RUN;
    }
    /* !Pseudo:  Else set runtime mode to Extended                            */
    else
    {

      NvM_u8RdARunTimeMode = u8EXTENDED_RUN;
    }
  }
  /* !Pseudo:  Else  (Read Config ID Job result is equal to NVM_REQ_OK)       */
  else
  {
  /* !Pseudo:  Set runtime mode to Normal                                     */

    NvM_u8RdARunTimeMode = u8NORMAL_RUN;
  }
}

/******************************************************************************/
/* !Description : Updates the RAM Block with the compiled ID and Mark it as
                  Valid and Changed                                           */

/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidRdAUpdateConfigID(void)
{

  NvM_pu8CurrentRamBlkAddr[0] = (uint8) NVM_COMPILED_CONFIG_ID;
  NvM_pu8CurrentRamBlkAddr[1] = (uint8) (NVM_COMPILED_CONFIG_ID >> 8) ;

  /* !Pseudo:  Update the RAM Block CRC                                       */

  /* Call corresponding (Calculate CRC API) according to configured CRC type  */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */
  switch(NvM_akstreBlockDescriptor[udtCONFIG_BLOCK_ID].u8BlockCrcType)
  {
  #if (NVM_USE_CRC8 == STD_ON)
    case NVM_CRC8:
/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */
  NvM_u8Crc8Value = Crc_CalculateCRC8(NvM_pu8CurrentRamBlkAddr,
      ((uint32)(2)),CRC_INITIAL_VALUE8,(boolean)TRUE);
	  break;
  #endif

  #if (NVM_USE_CRC16 == STD_ON)
    case NVM_CRC16:
/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */
      NvM_u16Crc16Value = Crc_CalculateCRC16(NvM_pu8CurrentRamBlkAddr,
      ((uint32)(2)),CRC_INITIAL_VALUE16,(boolean)TRUE);
	 break;
  #endif

  #if (NVM_USE_CRC32 == STD_ON)
    case NVM_CRC32:
/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */

      NvM_u32Crc32Value = Crc_CalculateCRC32(NvM_pu8CurrentRamBlkAddr,
       ((uint32)(2)),CRC_INITIAL_VALUE32,(boolean)TRUE);
      break;
  #endif
	default:
		break;
  }
/* PRQA S 3352 --                                                           */
/*lint -restore                                                               */
  vidUpdateRamBlkCRC();

  /* No check for temporary or permanent RAM buffer
  is necessary here, because this function is called during
  the Read All process. So permanent RAM buffer is implied.                   */

  /* !Pseudo:  Mark Block as Valid and Changed                                */
  NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8State = u8VALID_CHANGED;
}
#endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON)  */

/******************************************************************************/
/* Functions used by the Write Block Process                                  */
/******************************************************************************/

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
/******************************************************************************/
/* !Description : Function that calls NvMWriteRamBlockToNvM of the block
                  ,waits for the completion of the copying of data and perform
                  retries (NvMRepeatMirrorOperations) times                   */
/******************************************************************************/
static FUNC(Std_ReturnType, NVM_CODE) u8WrBCallAppCopy(void)
{
   Std_ReturnType u8Return = E_NOT_OK;

/* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */

/* !Deviation : inhibit MISRA rule [3359]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */

/* !Deviation : inhibit MISRA rule [3201]: The violation only occur         */
/*              when NVM_REPEAT_MIRROR_OPERATIONS is equal to 0U            */
/* PRQA S 3201 ++                                                           */
/* PRQA S 3356 ++                                                           */
/* PRQA S 3359 ++                                                           */

  /* !Pseudo:If Repeat Mirror Operation Counter <= NVM_REPEAT_MIRROR_OPERATIONS*/
   if ( NvM_u8RepeatMirrorOp <= NVM_REPEAT_MIRROR_OPERATIONS )
   {
     /* !Trace_To: GSCSW-NVM-SDD-001-0377                                     */
     /* !Pseudo: Call the NvMWriteRamBlockToNvM callback of the block         */
     u8Return = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                  pfu8WriteRamBlkToNvCbk(NvM_au8RamMirrorBuffer);
     /* !Pseudo: If the Application completed copying the data (E_OK Returned)*/
     if( u8Return == E_OK )
     {
       /* !Pseudo: Call vidWrBlkSelectNextSt to select next state           */
       vidWrBlkSelectNextSt();
     }
     /* !Pseudo: Else,                                                        */
     else
     {
       /* !Trace_To        : GSCSW-NVM-SDD-001-0538                           */
       /* !Pseudo: Increment the Repeat Mirror Operation Counter              */
       NvM_u8RepeatMirrorOp++;
     }
   }
/* PRQA S 3201 --                                                           */
/* PRQA S 3356 --                                                           */
/* PRQA S 3359 --                                                           */

   /* !Pseudo: Else, (repeat mirror operation overrun)                        */
   /* !Trace_To        : GSCSW-NVM-SDD-001-0538                               */
   else
   {
#if (NVM_JOB_PRIORITIZATION == STD_ON)
     /* !Pseudo: If the current job is immediate job                           */
     if ( NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockJobPriority
               == (uint8)0 )
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
     {
       /* !Pseudo: If more than one job exist in the Imdt Q                    */
       if((NvM_strImdtQAdmin.u8NumOfQuedJobs) > (uint8)1)
       {
         /* !Pseudo: Swap the current job with the next job in Imdt Q          */
         vidSwapJobInImdtQ();
       }
     }
#if (NVM_JOB_PRIORITIZATION == STD_ON)
     /* !Pseudo: Else, the current job is standard job                         */
     else
     {
       /* !Trace_To        : GSCSW-NVM-SDD-001-0423                           */
       /* !Pseudo: If there is no explicit job delayed                        */
       if (NvM_bExpStdJobDelayed != (boolean)TRUE)
       {
         NvM_bExpStdJobDelayed = (boolean)TRUE;
         NvM_strExpSyncDelayedJob.bTimeToServeExpJob = (boolean)FALSE;
         NvM_strExpSyncDelayedJob.udtBlockID = NvM_udteCurrentBlockID;
         NvM_strExpSyncDelayedJob.u8JobID = NvM_u8eCurrentJobID;
         NvM_strExpSyncDelayedJob.pu8RamBlkAddr = NvM_pu8CurrentRamBlkAddr;
       }
     }
#endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

    /*  !Pseudo: Reset State of Main Function to serve the next job           */
    NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;
    /* !Pseudo: Search for next job in queue and start serving it             */
    vidMfnJobsScanThenStart();
   }
   return u8Return;
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)&&(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/

/******************************************************************************/
/* !Description : Function that selects the next state of the Write block
                  (either CRC calculation or waiting for MemIF to be idle     */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidWrBlkSelectNextSt(void)
{
  /* !Pseudo:  If CRC is configured And( if SB job is running
	             or Calc RAM block CRC is OFF) then set state to
               WRB_CALC_RAM_BLK_CRC                                           */
  /* !Trace_To: GSCSW-NVM-SDD-001-0544                                        */
  /* !Trace_To: GSCSW-NVM-SDD-001-0560                                        */
#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
  if((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
      == (boolean)TRUE)
    && ( (NvM_enueMainFnState != NvM_MFN_MB_JOB)||(NvM_akstreBlockDescriptor
  [NvM_udteCurrentBlockID].bCalcRamBlockCrc == (boolean)FALSE) ) )
#else
  if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
      == (boolean)TRUE)
  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0585, GSCSW-NVM-SDD-001-0401              */
    vidStCalcRamCRCInit();
    NvM_enuSBPrcsState = WRB_CALC_RAM_BLK_CRC;
  }
  /* !Pseudo:  Else set state to WRB_WAIT_MEMIF_WRT                         */
  else
  {
    /* !Pseudo:  Set state to WRB_WAIT_MEMIF_WRT                            */
    NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
  }
}

/******************************************************************************/
/* !Description : Function that initializes write block process. It initializes
                  the state of the write process. It is called before starting
				  the write process                                           */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidWriteBlkPrcsInit(void)
{
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
  Std_ReturnType u8StateReturnVal;
#endif
  /* !Pseudo:  Reset write retires counter                                    */
  NvM_u8WriteRetriesCtr = (uint8)0;
  #if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  \
   && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  /* !Pseudo:  Reset Mirror Operation retires counter                         */
  NvM_u8RepeatMirrorOp = (uint8)0;
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
            && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U ) */

  /* !Pseudo:  Initialize pre-error status to failed                          */
  NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;


  /* !Pseudo: If the RAM buffer used in the API call is the same
  as the configured Ram buffer of the NVRAM block and if it is
  not NULL                                                                    */
  /* !Pseudo: Then update the state of the current block to
  u8VALID_CHANGED                                                             */
/* !Trace_To        : GSCSW-NVM-SDD-001-0539, GSCSW-NVM-SDD-001-0589          */
  vidUpdatStIfPermanenRAM(u8VALID_CHANGED);

  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
    .u8BlockManagementType != NVM_BLOCK_DATASET)
  {
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

    /* !Pseudo: If block to be written is not
    dataset-typed then Force dataset index to zero                            */
    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)0;
  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
  }
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

  /* !Pseudo: If block to be written is of invalid dataset                    */
  if( NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex >=
    NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvBlockNum )
  {
    /* !Pseudo: Report to DEM and Call Process DeInit (Failed Job)            */
    /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
    Dem_ReportErrorStatus(NVM_E_REQ_FAILED, DEM_EVENT_STATUS_FAILED);
    vidSBPrcsDeInit(NVM_REQ_NOT_OK);
    /* !Pseudo: Set the state to an invalid state (Read Block state!!).
    To cause a DET report (Abnormal branch) in the vidWriteBlkPrcs function   */
    NvM_enuSBPrcsState = RDB_WAIT_MEMIF_READ;
  }
  /* !Pseudo: Else (Valid Data set) */
  else
  {
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    /* !Pseudo:If the block uses Sync Mechanism and Current Job ID is
               NvM_u8WRITE_BLOCK_ID                                           */
    if ( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlkUseSyncMechanism
           == (boolean)TRUE) && (NvM_u8eCurrentJobID == NvM_u8WRITE_BLOCK_ID) )
    {
      NvM_enuSBPrcsState = WRB_CALL_APP_COPY;
      u8StateReturnVal = u8WrBCallAppCopy();
      if(u8StateReturnVal == E_OK)
      {
        vidWrBlkSelectNextSt();
      }
    }
    else
    {
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U) */
      vidWrBlkSelectNextSt();

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    }
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U) */
  }
}

/******************************************************************************/
/* !Description : Write block process. It is called at every Mnf cycle if there
                  is a write block process in progress                        */



/******************************************************************************/
static FUNC(void, NVM_CODE) vidWriteBlkPrcs(void)
{
  Std_ReturnType u8StateReturnVal;

  /* !Pseudo: Switch (SB process state)                                       */
  switch (NvM_enuSBPrcsState)
  {
  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    /* !Pseudo: case  WRB_CALL_APP_COPY                                       */
    case WRB_CALL_APP_COPY:
      /* !Pseudo:  Call corresponding State fn                                */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0537                           */
      u8StateReturnVal = u8WrBCallAppCopy();
      /* !Pseudo:  As soon as state is finished go to the next state. This saves
                   one Mfn Cycle.                                             */
      if(u8StateReturnVal == E_OK)
      {
        vidWrBlkSelectNextSt();
      }
    break;

    #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/
     /* !Pseudo: case  WRB_CALC_RAM_BLK_CRC                                   */

    case WRB_CALC_RAM_BLK_CRC:
     /* !Pseudo:  Call corresponding State fn                                 */
      u8StateReturnVal = u8StCalcRamBlkCRC();
     /* !Pseudo: If return Value is OK (ie. CRC calculation has finished)     */

      if(u8StateReturnVal == E_OK)
      {
         /* !Pseudo: Update Ram Blk CRC with the calculated one               */
         vidUpdateRamBlkCRC();
         /* !Pseudo: Set state to WRB_WAIT_MEMIF_WRT                          */
         NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;

         /* As soon as CRC is calculated start to the next state.
          (Saves one Mfn Cycle and saves stack by not calling the fn from inside
          the previous state fn)                                              */
         /* !Pseudo: Call the state function wait for MemIf then Write        */
         vidStWrBWaitMemIfAndWrt();
      }
      break;

     /* !Pseudo:  case WRB_WAIT_MEMIF_WRT:                                    */
    case WRB_WAIT_MEMIF_WRT:

      /* !Pseudo:  Call corresponding State fn                                */
      vidStWrBWaitMemIfAndWrt();
      break;

     /* !Pseudo:  case WRB_WAIT_WRITE_END:                                    */

    case WRB_WAIT_WRITE_END:
      /* !Pseudo:  Call corresponding State fn                                */
      NvM_vidStWrBWaitWriteEnd();
      /* !Pseudo:  As soon as state is finished and there another write needed
                   (write retry or redundant) go to the next state. This saves
                   one Mfn Cycle.                                             */
      if(NvM_enuSBPrcsState == WRB_WAIT_MEMIF_WRT)
      {
         /* !Pseudo:  Call the state function wait for MemIf then Write       */
         vidStWrBWaitMemIfAndWrt();
      }
#if(NVM_u16VERIFY_BUFFER_SIZE != 0U)
      /* !Pseudo:  As soon as state is finished and write verification needed
                   go to the next state. This saves one Mfn Cycle.            */
      else if (NvM_enuSBPrcsState == WRB_WAIT_WRT_VERIFY)
      {
         /* !Pseudo:  Call the state function write verify                    */
         vidStWrBWriteVerify();
      }
#endif /* (NVM_u16VERIFY_BUFFER_SIZE != 0U) */
      else
      {
      }

      break;

#if(NVM_u16VERIFY_BUFFER_SIZE != 0U)
      case WRB_WAIT_WRT_VERIFY:
      /* !Pseudo:  Call corresponding State fn                                */
      vidStWrBWriteVerify();
      /* !Pseudo:  If the current cycle was to compare data                   */
      if(NvM_enuWrtVefifyState == WRB_WAIT_MEMIF_IDLE)
      {
         /* !Pseudo:  Call the state function write verify to read data
                      (to save one main function cycle)                       */
         vidStWrBWriteVerify();
      }
      /* !Pseudo:  As soon as state is finished and there another write needed
                   (write retry or redundant) go to the next state. This saves
                   one Mfn Cycle.                                             */
      if(NvM_enuSBPrcsState == WRB_WAIT_MEMIF_WRT)
      {
         /* !Pseudo:  Call the state function wait for MemIf then Write       */
         vidStWrBWaitMemIfAndWrt();
      }
      break;

#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

      /* !Pseudo:  Default (Invalid Process State then call Det with
      abnormal branch)                                                        */
    #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
    case RDB_PRE_CALC_RAM_CRC:
    #endif
    case RDB_WAIT_MEMIF_READ :
    case RDB_WAIT_READ_END :
    case RDB_CALC_CRC_AND_CMP :
    case RDB_RSTR_BLK_PRCS :
    #if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
    case ERS_WAIT_MEMIF_ERS :
    case ERS_WAIT_ERASE_END :
    #endif
    default:
      #if (NVM_DEV_ERROR_DETECT == STD_ON)
      /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
        (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8MAIN_FUNCTION_ID,
               NVM_E_ABNORMAL_BRANCH);
      #else
        /* !Pseudo: Report error to the DEM                                   */
        Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                        DEM_EVENT_STATUS_FAILED);
      #endif
      break;

  }
}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf to be
                  Idle then starts writing the block (Note that the MemIf can
				  be internal busy).                                          */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStWrBWaitMemIfAndWrt(void)
{
  Std_ReturnType u8MemIfReturnResult;
  MemIf_StatusType udtMemIfStatus;
  uint16 u16BlockNumber;
  uint16 u16LengthCount;
  uint8 u8NumOfBlkHdrBytes;

  /* !Pseudo: Call Get Status of MemIf                                        */
  /* !Trace_To        : GSCSW-NVM-SDD-001-0200                                */
  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  udtMemIfStatus = MemIf_GetStatus(NvM_akstreBlockDescriptor
    [NvM_udteCurrentBlockID].u8NvRamDeviceId);
  /* !Pseudo: If Idle */
  if(udtMemIfStatus == MEMIF_IDLE)
  {
    /* !Trace_To        : GSCSW-NVM-SDD-001-0540, GSCSW-NVM-SDD-001-0567      */
    u16BlockNumber = (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
      .u16NvBlockBaseNumber) + (uint16)(NvM_astrAdminBlock[
      NvM_udteCurrentBlockID].u8DataSetIndex);
    #if (NVM_POLLING_MODE == STD_OFF)
    /* !Pseudo:  Reset Job end Call back flag                                 */

    NvM_udtMemIfJobEndClBck = MEMIF_JOB_PENDING;
    #endif
    /* !Pseudo: If block uses Static Block Id Check                           */
    /* !Trace_To: GSCSW-NVM-SDD-001-0543, GSCSW-NVM-SDD-001-0363,
                  GSCSW-NVM-SDD-001-0366, GSCSW-NVM-SDD-001-0366,
                  GSCSW-NVM-SDD-001-0417                                     */
    if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck
               == (boolean)TRUE)
    {
      /* !Pseudo: Obtain Number of header bytes for the block                 */
      u8NumOfBlkHdrBytes = u8CalcBlkNumHdrBytes();
      /* !Pseudo: If Number of header bytes == 1                              */
      if( u8NumOfBlkHdrBytes == 1U )
      {
/* !Deviation : Inhibit MISRA rule [3212]: The casting to uint8 is needed   */
/*              in case NVM_udtNUM_OF_NVRAM_BLOCKS >=255U                   */
/* PRQA S 3212 ++                                                           */
        /* !Pseudo: Copy block ID Header byte to Internal RAM buffer          */
        NvM_au8InternalRamBuffer[(uint16)0] = (uint8) NvM_udteCurrentBlockID;
/* PRQA S 3212 --                                                           */
      }
#if (NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))
      /* !Pseudo: Else, (Number of header bytes == 2)                         */
      else
      {
        /* !Pseudo: Copy block ID Header bytes to Internal RAM buffer         */
        NvM_au8InternalRamBuffer[(uint16)0] = (uint8) NvM_udteCurrentBlockID;
        NvM_au8InternalRamBuffer[(uint16)1] = (uint8) (NvM_udteCurrentBlockID >> 8);
      }
#endif /*(NVM_udtNUM_OF_NVRAM_BLOCKS >= (255U))*/

      /* !Pseudo: If the Block Uses CRC                                       */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
        == (boolean)TRUE)
      {
        /* !Pseudo: Copy Crc Data From Ram Block Crc Address to Internal
                    Buffer                                                    */
        vidCopyCrc(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                     .u16NvBlockLength,u8NumOfBlkHdrBytes,(boolean)FALSE);
      }
    }
    /* !Pseudo: Else (Block doesn't use static Block Id Check)                */
    else
    {
      u8NumOfBlkHdrBytes = (uint8)0;
      /* !Pseudo: If the Block Uses CRC                                       */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc
        == (boolean)TRUE)
      {
        /* !Pseudo: Copy Crc Data From Ram Block Crc Address to Internal
                    Buffer                                                    */
        vidCopyCrc(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                     .u16NvBlockLength,u8NumOfBlkHdrBytes,(boolean)FALSE);
      }
    }

    /* !Pseudo: If the current block Id != udtCONFIG_BLOCK_ID                 */
    if ( NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID )
    {
	  if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc == (boolean)TRUE ) 
	  || (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteVerification == (boolean)TRUE ) 
      || (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck == (boolean)TRUE))
	  {
      /* !Pseudo: Copy Data from RAM block to Internal buffer                 */
      for(u16LengthCount=0;u16LengthCount<NvM_akstreBlockDescriptor
                    [NvM_udteCurrentBlockID].u16NvBlockLength;u16LengthCount++)
      {
        NvM_au8InternalRamBuffer[(uint16)(u16LengthCount + u8NumOfBlkHdrBytes)] =
            NvM_pu8CurrentRamBlkAddr[u16LengthCount];
       }
	  }
	  else
	  {
	  /*do nothing*/
	  }
    }
    /* !Pseudo: Else, the current block Id == udtCONFIG_BLOCK_ID              */
    else
    {
      /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is*/
      /*              already casted to uint16.                               */
      /* PRQA S 1255 ++                                                       */
      /* !Pseudo: Copy NVM_COMPILED_CONFIG_ID to NvM_au8InternalRamBuffer     */
      NvM_au8InternalRamBuffer[(uint16)(u8NumOfBlkHdrBytes)] =
                            (uint8) NVM_COMPILED_CONFIG_ID;

      NvM_au8InternalRamBuffer[(uint16)(u8NumOfBlkHdrBytes + 1)] =
                            (uint8) (NVM_COMPILED_CONFIG_ID >> 8) ;
    /* PRQA S 1255 --                                                         */
    }


/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */

    /* !Pseudo: Call Write Block of MemIf */
    /* !Trace_To: GSCSW-NVM-SDD-001-0367                                     */
	if ((NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bBlockUseCrc == (boolean)TRUE ) || 
	(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteVerification == (boolean)TRUE ) 
    || (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bStaticBlockIDCheck == (boolean)TRUE))
	{
    u8MemIfReturnResult = MemIf_Write(NvM_akstreBlockDescriptor
      [NvM_udteCurrentBlockID].u8NvRamDeviceId,u16BlockNumber,
      NvM_au8InternalRamBuffer);
    }
	else
	{
	 u8MemIfReturnResult = MemIf_Write(NvM_akstreBlockDescriptor
      [NvM_udteCurrentBlockID].u8NvRamDeviceId,u16BlockNumber,
      NvM_pu8CurrentRamBlkAddr);
	}
/*lint -restore                                                               */

    /* !Pseudo: If request is Accepted Go to Wait for Write State             */
    if(u8MemIfReturnResult == E_OK)
    {

     NvM_enuSBPrcsState = WRB_WAIT_WRITE_END;
    }
    /* !Pseudo: Else,                                                         */
    else
    {

      #if (NVM_POLLING_MODE == STD_OFF)
      NvM_udtMemIfJobEndClBck = MEMIF_JOB_FAILED;
      #endif
      /* !Pseudo: Set pre DEM error to NVM_E_REQ_FAILED                       */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0307                                    */
      /* !Trace_To: GSCSW-NVM-SDD-001-0546                                  */
      NvM_u16PreDemError = NVM_E_REQ_FAILED;
      /* !Pseudo: Call Wrt Error Hook                                         */
      vidWrBErrorHook();
    }
  }

#if(NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Else if MEMIF is not initialized								  */
    else if(udtMemIfStatus == MEMIF_UNINIT)
	{
	  (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8eCurrentJobID,
               NVM_E_MEMIF_UNINIT);
	}
#endif

  /* !Pseudo: Else Do nothing                                                 */
    else
    {

    }

}

/******************************************************************************/
/* !Description : Function Representing the state of waiting for MemIf to finish
                  writing the block                                           */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStWrBWaitWriteEnd(void)
{
/* !Trace_To        : GSCSW-NVM-SDD-001-0201                                  */
  MemIf_JobResultType udtMemIfJobResult;

  /* !Trace_To: GSCSW-NVM-SDD-001-0497                                        */
  /* !Pseudo:  Get Job Result of MemIf */
  #if (NVM_POLLING_MODE == STD_ON)
  udtMemIfJobResult = MemIf_GetJobResult(NvM_akstreBlockDescriptor
   [NvM_udteCurrentBlockID].u8NvRamDeviceId);
  #else
  udtMemIfJobResult = NvM_udtMemIfJobEndClBck;
  #endif

  /* !Pseudo:  If Pending                                                     */
  if(udtMemIfJobResult == MEMIF_JOB_PENDING)
  {
  /* !Pseudo:  Do Nothing in this main function cycle                         */
  }
  /* !Pseudo:  Else If OK                                                     */
  else if(udtMemIfJobResult == MEMIF_JOB_OK)
  {
    /* !Pseudo:  If Block Type Redundant and 2nd block not processed yet      */
    if( (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex == (uint8)0)
     && (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockManagementType
          == NVM_BLOCK_REDUNDANT) )
    {
#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
      /* !Pseudo: If the block use write verification                         */
      if (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteVerification
          == (boolean)TRUE)
      {
        NvM_u16RemBlockLength = u16CalcTotalBlkLength(NvM_udteCurrentBlockID);
        NvM_u16BlockOffset = (uint16)0;
        NvM_u16CurrentVerifCycle = (uint16)0;
        NvM_enuWrtVefifyState = WRB_WAIT_MEMIF_IDLE;
        /* !Pseudo: Set NvM_enuSBPrcsState to WRB_WAIT_WRT_VERIFY             */
        NvM_enuSBPrcsState = WRB_WAIT_WRT_VERIFY;
      }
      /* !Pseudo: Else, (block doesn't use write verification)                */
      else
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/
      {
        /* !Pseudo:  Initialize Redundant block processing parameters
                 (Data Index=1, Write Retry Counter=0, Pre Error=OK)            */
        NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)1u;
        NvM_u8WriteRetriesCtr = (uint8)0;
        NvM_u8SBPreErrorStatus = NVM_REQ_OK;
        /* !Pseudo: Set state to WRB_WAIT_MEMIF_WRT                             */
        NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
      }
    }
    /* !Pseudo: Else (Native or Redundant with 2nd or Both blocks written
    correctly )                                                               */
    else
    {
#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
      /* !Pseudo: If the block use write verification                         */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteVerification
          == (boolean)TRUE)
      {
        NvM_u16RemBlockLength = u16CalcTotalBlkLength(NvM_udteCurrentBlockID);
        NvM_u16BlockOffset = (uint16)0;
        NvM_u16CurrentVerifCycle = (uint16)0;
        NvM_enuWrtVefifyState = WRB_WAIT_MEMIF_IDLE;
        /* !Pseudo: Set NvM_enuSBPrcsState to WRB_WAIT_WRT_VERIFY             */
        NvM_enuSBPrcsState = WRB_WAIT_WRT_VERIFY;
      }
      /* !Pseudo: Else, (block doesn't use write verification)                */
      else
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/
      {
        /* !Pseudo: Enable write protection if write block once is configured */

      /* !Trace_To: GSCSW-NVM-SDD-001-0541                                  */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
          == (boolean)TRUE)
      {
         /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
         /*              during integration phase                                    */
         /* PRQA S 3141 ++                                                           */
		  SchM_Enter_NvM_NVM_ACCESS_001();
		  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
		  SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                         */
      }
        /* !Trace_To: GSCSW-NVM-SDD-001-0545, GSCSW-NVM-SDD-001-0589          */
        /* !Pseudo: Update the RAM block state (if permanant)to Valid Unchanged */
        vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);
        /* !Pseudo: Call Process DeInit (Successful Job)                      */
        /* !Trace_To: GSCSW-NVM-SDD-001-0542                                  */
        vidSBPrcsDeInit(NVM_REQ_OK);
      }
    }
  }
  /* !Pseudo: Else (Job Failed)                                               */
  else

  {
    /* !Pseudo: Set pre DEM error to NVM_E_REQ_FAILED                         */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0307                                      */
    /* !Trace_To: GSCSW-NVM-SDD-001-0546                                      */
    NvM_u16PreDemError = NVM_E_REQ_FAILED;
    /* !Pseudo: Call Wrt Error Hook                                           */
    vidWrBErrorHook();
  }

}

#if (NVM_u16VERIFY_BUFFER_SIZE != 0U)
/******************************************************************************/
/* !Description : Function called after write operation completed on the HW ,
                  it is used to verify the data written to the NV memort      */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStWrBWriteVerify(void)
{
  Std_ReturnType u8MemIfReturnResult;
  MemIf_StatusType udtMemIfStatus;
  MemIf_JobResultType udtMemIfJobResult;
  uint16 u16BlockNumber;
  uint16_least u16CompareCounter;
  boolean bVerifyFailed;
  static uint16 LOC_u16PassedLength;
  static uint16 LOC_u16TempOffset;
  static uint8 LOC_au8VerifyBuffer[NVM_u16VERIFY_BUFFER_SIZE];

  switch (NvM_enuWrtVefifyState)
  {
  case WRB_WAIT_MEMIF_IDLE:

    /* !Pseudo: Call Get Status of MemIf                                      */
    udtMemIfStatus = MemIf_GetStatus(NvM_akstreBlockDescriptor[
      NvM_udteCurrentBlockID].u8NvRamDeviceId);
    if(udtMemIfStatus == MEMIF_IDLE)
    {
      /* !Pseudo: If Idle                                                     */
      u16BlockNumber = (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
        .u16NvBlockBaseNumber) + (uint16)(NvM_astrAdminBlock[
        NvM_udteCurrentBlockID].u8DataSetIndex);

      NvM_u16CurrentVerifCycle++;

      #if (NVM_POLLING_MODE == STD_OFF)
      /* !Pseudo:  Reset Job end Call back flag                               */

      NvM_udtMemIfJobEndClBck = MEMIF_JOB_PENDING;
      #endif

      /* !Pseudo: If remaining bytes to be verified is larger than
                  Write verification size                                     */
      if ( NvM_u16RemBlockLength>
                        NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                                                .u16WriteVerifDataSize )
      {
        /* !Trace_To: GSCSW-NVM-SDD-001-0548                                  */
        LOC_u16PassedLength = NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                                                .u16WriteVerifDataSize;
/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */
        /* !Pseudo: Call Read Block of MemIf with address
                    NvM_au8InternalRamBuffer and length write verification
                    max size                                                  */
        u8MemIfReturnResult = MemIf_Read(
                NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId,
               u16BlockNumber,NvM_u16BlockOffset,LOC_au8VerifyBuffer,LOC_u16PassedLength);
/*lint -restore                                                               */

        LOC_u16TempOffset = NvM_u16BlockOffset;
        NvM_u16BlockOffset = NvM_u16BlockOffset + NvM_akstreBlockDescriptor
                            [NvM_udteCurrentBlockID].u16WriteVerifDataSize;
        /* !Pseudo: update the number of remaining bytes to be verified       */
        NvM_u16RemBlockLength = NvM_u16RemBlockLength -
                                NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
                                     .u16WriteVerifDataSize;
      }
      /* !Pseudo: Else, remaining bytes to be verified is smaller than
                  Write verification size                                     */
      else
      {
        LOC_u16PassedLength = NvM_u16RemBlockLength;
        /* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
        /*              the usage of __far keyword in the same way as the compiler    */
        /* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
        /*              the usage of __far keyword in the same way as the compiler    */
        /*lint -save -vo -e918 -e619 -v                                               */
        /* !Pseudo: Call Read Block of MemIf with address
                    NvM_au8InternalRamBuffer                                  */
        u8MemIfReturnResult = MemIf_Read(
                NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8NvRamDeviceId,
               u16BlockNumber,NvM_u16BlockOffset,LOC_au8VerifyBuffer,LOC_u16PassedLength);
        /*lint -restore                                                       */
        LOC_u16TempOffset = NvM_u16BlockOffset;
      }
      /* !Pseudo: If request is Accepted Go to Wait for Read End State        */
      if(u8MemIfReturnResult == E_OK)
      {
        NvM_enuWrtVefifyState = WRT_WAIT_READ_END;
      }
      /* !Pseudo: Else,(request not Accepted)                                 */
      /* !Trace_To: GSCSW-NVM-SDD-001-0425                                    */
      else
      {
        /* !Pseudo: Set pre DEM error to NVM_E_VERIFY_FAILED                  */
		    /* !Trace_To: GSCSW-NVM-SDD-001-0311                                  */
        /* !Trace_To: GSCSW-NVM-SDD-001-0549                                  */
        NvM_u16PreDemError = NVM_E_VERIFY_FAILED;
        /* !Trace_To: GSCSW-NVM-SDD-001-0550                                  */
        /* !Pseudo: Call Write Error Hook                                     */
        vidWrBErrorHook();
      }
    }

      break;

    case WRT_WAIT_READ_END:
      /* !Trace_To: GSCSW-NVM-SDD-001-0497                                    */
      /* !Pseudo:  Get Job Result of MemIf */
      #if (NVM_POLLING_MODE == STD_ON)
      udtMemIfJobResult = MemIf_GetJobResult(NvM_akstreBlockDescriptor
       [NvM_udteCurrentBlockID].u8NvRamDeviceId);
      #else
      udtMemIfJobResult = NvM_udtMemIfJobEndClBck;
      #endif

      /* !Pseudo:  If Pending                                                 */
      if(udtMemIfJobResult == MEMIF_JOB_PENDING)
      {
      /* !Pseudo:  Do Nothing in this main function cycle                     */
      }
      /* !Pseudo:  Else If OK                                                 */
      else if(udtMemIfJobResult == MEMIF_JOB_OK)
      {
        /* !Pseudo: Compare the read data with the data written               */
        u16CompareCounter = (uint16)0;
        bVerifyFailed = (boolean)FALSE;
        while ( (u16CompareCounter < LOC_u16PassedLength) &&
                (bVerifyFailed != TRUE ) )
        {
          if( LOC_au8VerifyBuffer[u16CompareCounter]!=
              NvM_au8InternalRamBuffer[(uint16)(LOC_u16TempOffset+u16CompareCounter)] )
          {
            bVerifyFailed = (boolean)TRUE;
          }
          u16CompareCounter++;
        }
        /* !Pseudo: If data read != written data (i.e.verify failed)          */
        if( bVerifyFailed == (boolean)TRUE )
        {
          /* !Pseudo: Set pre DEM error to NVM_E_VERIFY_FAILED                */
		  /* !Trace_To: GSCSW-NVM-SDD-001-0311                                */
          NvM_u16PreDemError = NVM_E_VERIFY_FAILED;
          /* !Pseudo: Call write block error hook function                    */
          vidWrBErrorHook();
        }
        /* !Pseudo: Else, If data read == written data (i.e.verify passed for
                    this verification cycle)                                  */
        else
        {
          /* !Pseudo: If this is not the last cycle of verification           */
          if ( NvM_u16CurrentVerifCycle <=
          ((u16CalcTotalBlkLength(NvM_udteCurrentBlockID)) /
          (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u16WriteVerifDataSize)))
          {
            /* !Pseudo: Set write verify state to WRB_WAIT_MEMIF_IDLE         */
            NvM_enuWrtVefifyState = WRB_WAIT_MEMIF_IDLE;
          }
          /* !Pseudo: Else, this is the last cycle of verification            */
          else
          {
            /* !Trace_To: GSCSW-NVM-SDD-001-0426                              */
            /* !Pseudo:  If Block Type Redundant and 2nd block not processed yet      */
            if( (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex == (uint8)0)
                && (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockManagementType
                 == NVM_BLOCK_REDUNDANT) )
            {
              /* !Pseudo:  Initialize Redundant block processing parameters
                 (Data Index=1, Write Retry Counter=0, Pre Error=OK)          */
              NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)1u;
              NvM_u8WriteRetriesCtr = (uint8)0;
              NvM_u8SBPreErrorStatus = NVM_REQ_OK;
              /* !Pseudo: Set state to WRB_WAIT_MEMIF_WRT                     */
              NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
            }
            /* !Pseudo: Else (Native or Redundant with 2nd or Both blocks written
                        correctly )                                           */
            else
            {
              /* !Pseudo: Enable write protection if write block once is configured */
              if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
                == (boolean)TRUE)
              {
                  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
                  /*              during integration phase                                    */
                  /* PRQA S 3141 ++                                                          */
				  SchM_Enter_NvM_NVM_ACCESS_001();
				  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
				  SchM_Exit_NvM_NVM_ACCESS_001();
				   /* PRQA S 3141 --                                                          */
              }
              /* !Trace_To: GSCSW-NVM-SDD-001-0589                                    */
		          /* !Pseudo: Update the RAM block state (if permanant)to Valid Unchanged */
              vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);
              /* !Pseudo: Call Process DeInit (Successful Job)                */
              /* !Trace_To: GSCSW-NVM-SDD-001-0551                            */
              vidSBPrcsDeInit(NVM_REQ_OK);
            }

          }
        }
      }
      /* !Pseudo: Else (Job Failed)                                           */
      /* !Trace_To: GSCSW-NVM-SDD-001-0425                                    */
      else
      {
        /* !Pseudo: Set pre DEM error to NVM_E_VERIFY_FAILED                  */
		    /* !Trace_To: GSCSW-NVM-SDD-001-0311                                  */
        /* !Trace_To: GSCSW-NVM-SDD-001-0549                                  */
        NvM_u16PreDemError = NVM_E_VERIFY_FAILED;
        /* !Trace_To: GSCSW-NVM-SDD-001-0550                                  */
        /* !Pseudo: Call Wrt Error Hook                                       */
        vidWrBErrorHook();
      }
        break;

    /* !Deviation : Inhibit MISRA rule [2018]: Reason: Another Misra Rule     */
    /* PRQA S 2018 ++                                                         */
    default:
      break;
    /* PRQA S 2018 --                                                         */
  }
}
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

/******************************************************************************/
/* !Description : Function called when a negative result recieved by the MemIf
                  Write. It takes the corrective action either initiating write
				  retry or writing to redundant block                         */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidWrBErrorHook(void)
{
  /* !Pseudo:  If write retries possible                                      */
  /* !Trace_To: GSCSW-NVM-SDD-001-0546                                        */
  if( NvM_u8WriteRetriesCtr < NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
	                                u8MaxNumOfWriteRetries)
  {
    /* !Pseudo:  Increment retry counter                                      */
    NvM_u8WriteRetriesCtr++;
    /* !Pseudo: Set state to WRB_WAIT_MEMIF_WRT                               */
    NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
  }
  /* !Pseudo: Else (Write retries over-run)                                   */
  else
  /* !Pseudo: If Block type is redundant                                      */
  if( (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockManagementType)
            == NVM_BLOCK_REDUNDANT )
  {
    /* !Pseudo: If 2nd block is not yet processed (implicitly 1st failed)*/

    if(NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex == (uint8)0)
    {
      /* !Pseudo:  Set Pre Error Status to Not OK                             */
      /* !Pseudo:  Initialize Redundant block processing parameters
      (Data Index=1, Write Retry Counter=0)                                   */
      NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
      NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8DataSetIndex = (uint8)1u;
      NvM_u8WriteRetriesCtr = (uint8)0;
      /* !Pseudo: Set state to WRB_WAIT_MEMIF_WRT                             */
      NvM_enuSBPrcsState = WRB_WAIT_MEMIF_WRT;
      /* !Pseudo: Report to DEM (1st NV block can't be written)               */
      Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
    }
    /* !Pseudo: Else If 1st block was written correctly (implicitly 2nd
                failed)*/

    else if(NvM_u8SBPreErrorStatus == NVM_REQ_OK)
    {
      /* !Pseudo: Enable write protection if write block once is configured   */
      if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bWriteBlockOnce
           == (boolean)TRUE)
      { 
	     /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
         /*              during integration phase                                    */
         /* PRQA S 3141 ++                                                           */
          SchM_Enter_NvM_NVM_ACCESS_001();
		  u8SET_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8PROTECTION_ENABLE);
		  SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                           */
      }
      /* !Pseudo: Report to DEM (2nd NV block can't be written)               */
      Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
      /* !Pseudo: Update the RAM block state (if permanant)to Valid Unchanged */
      /* !Trace_To: GSCSW-NVM-SDD-001-0589                                    */
      vidUpdatStIfPermanenRAM(u8VALID_UNCHANGED);
      /* !Pseudo: Call Process DeInit (Successful Job)                        */
      /* !Trace_To: GSCSW-NVM-SDD-001-0551                                    */
      vidSBPrcsDeInit(NVM_REQ_OK);
	}
    /* !Pseudo: Else (implicitly 1st and 2nd failed)                          */
    else
    {
      /* !Pseudo: Report to DEM (2nd NV block can't be written)               */
      /* !Trace_To: GSCSW-NVM-SDD-001-0546                                    */
      Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
      /* !Pseudo: Call Process DeInit (Failed Job)                            */
      vidSBPrcsDeInit(NVM_REQ_NOT_OK);
    }
  }
  /* !Pseudo: Else (Native can't be written)                                  */
  else

  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0546                                      */
    /* !Pseudo: Report to DEM */
    Dem_ReportErrorStatus(NvM_u16PreDemError, DEM_EVENT_STATUS_FAILED);
    /* !Pseudo: Call Process DeInit (Failed Job)                              */
    vidSBPrcsDeInit(NVM_REQ_NOT_OK);
  }

}


/******************************************************************************/
/* Functions used by write all process.                                       */
/******************************************************************************/

/******************************************************************************/
/* !Description : Function that initializes write all process.                */

/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidWriteAllPrcsInit(void)
{
  NvM_BlockIdType udtCounter;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8State
                  = &NvM_strMBJobBfr.u8State;
  /* !Pseudo: Set Multi Block state to WRA_WAIT_MEMIF_IDLE                    */
  NvM_enuMBlkPrcsState = WRA_WAIT_MEMIF_IDLE ;

  /* !Pseudo: Restore the context of multi block job, in order to resume the
     multiblock action from the current block processed                       */

  /* Initialize current block ID with the saved one                           */
  NvM_udteCurrentBlockID = NvM_strMBJobBfr.udtBlockID;

  /* !Pseudo: If not resuming a frozen job                                    */
  if(NvM_udteCurrentBlockID == udtMULTI_BLOCK_ID)
  {
    /* This part is protected to prevent the occurance of the below scenario: */
    /* SB job interrupts this function just before marking the block as
       skipped and this will lead to mark the block as skipped                */

  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented      */
    /*              during integration phase                                  */
    /*lint -save -vo -e960 -v                                                 */

    /*  !Pseudo: Open Critical Section                                        */
    SchM_Enter_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
    /* lint -restore                                                          */
  #endif  /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */


    /*  !Pseudo: Update MB Buffer State to be started                         */
    *pu8State = u8STARTED;
    /*  !Pseudo:
                Tag all NVRAM blocks as pending for MB job , if they are :
                      - Configured as permanent
                      - Marked as not write protected
                      - Any block marked as "valid and changed" state or
                        redundant block seen as "valid and unchanged"         */

    /* !Trace_To: GSCSW-NVM-SDD-001-0554                                      */
    for(udtCounter = udtCONFIG_BLOCK_ID; udtCounter <=
      (NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS; udtCounter++)
    {

      if (!(bIS_BLOCK_PENDING(udtCounter)) )
		  {
         /* !Trace_To: GSCSW-NVM-SDD-001-0557                                 */
		   if( (!(u8CHECK_GENERAL_BLOCK(udtCounter, u8PROTECTION_ENABLE)))
             &&
             (NvM_akstreBlockDescriptor[udtCounter].pvidRamBlockDataAddress != NULL_PTR)
             &&
             (NvM_akstreBlockDescriptor[udtCounter].bSelectBlockForWrtAll == (boolean)TRUE)
             #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
             &&
             (NvM_astrAdminBlock[udtCounter].u8State == u8VALID_CHANGED)
             #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */
           )
         {
            /* !Trace_To: GSCSW-NVM-SDD-001-0555                              */
            NvM_astrAdminBlock[udtCounter].u8ErrorStatus = u8PEND_MULTIBLK_JOB;
         }

         /* Don't mark a pending immediate write block as skipped             */
         else
         {
            /* !Trace_To: GSCSW-NVM-SDD-001-0556                              */
            NvM_astrAdminBlock[udtCounter].u8ErrorStatus = NVM_REQ_BLOCK_SKIPPED;
         }
       }
    }

  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */

    /*  !Pseudo: Close Critical Section  */
    SchM_Exit_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
  #endif  /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

    /* !Pseudo: setting the block ID to the first user block Id (blockId 2)   */
    NvM_udteCurrentBlockID = udtCONFIG_BLOCK_ID + (NvM_BlockIdType)1;
    /*  !Pseudo:  Initialize MB pre-error status to successful                */
    NvM_u8MBlkPreErrorStatus = NVM_REQ_OK;
  }

  /* !Pseudo: If (NvM_bCancelWrtAllReq == TRUE)                               */
  if (NvM_bCancelWrtAllReq == (boolean)TRUE)
  {

    /* !Pseudo: Handle the cancel write all request.                          */
    vidWrAHookCancelRequest();
  }
  /* !Pseudo: Else */
  else
  {
  }
}

/******************************************************************************/
/* !Description : Write All process. It is called at every Mnf cycle if there
                  is a write all process in progress                          */



/******************************************************************************/
static FUNC(void, NVM_CODE) vidWriteAllPrcs(void)
{
  /*  !Comment: Variable used as a function return. It indicates if the next
                state shall be executed immediately (ie. within the same main
                function cycle)*/
  boolean bExecuteNextState;


  /*  !Pseudo: Do until no states need to be executed in this main function
               cycle*/
  do
  {
    /*  !Pseudo: Reset "Execute Next State" Flag                              */
    bExecuteNextState = (boolean)FALSE;

    /* !Pseudo: Switch (MB process state)                                     */
    switch (NvM_enuMBlkPrcsState)
    {

      /* !Pseudo: case  WRA_XWRITE_CFG_ID                                     */
      case WRA_XWRITE_CFG_ID:
        bExecuteNextState = NvM_bStWrAWrBConfigID();
        break;

      /* !Pseudo: case  WRA_WAIT_MEMIF_IDLE                                   */

      case WRA_WAIT_MEMIF_IDLE:
        /* !Pseudo:  Set the Memory Interface to fast mode if it is Idle */
        bExecuteNextState = bStWaitMemIfIdle();
        break;

      /* !Pseudo:  case WRA_XCALL_WRB                                         */
      case WRA_XCALL_WRB:
        /*  !Pseudo: Cross Call of write block process                        */
        bExecuteNextState = NvM_bStWrACrossWrB();
        break;

      /* !Pseudo:  case WRA_DEINIT_IF_IDLE                                    */
      case WRA_DEINIT_IF_IDLE:
        /* !Pseudo:  DeInit Write All process if MemIf is Idle ( Pass False to
                     the Fn to indicate that this is a normal End of MB Job,
                     not freezing)                                            */
        vidStMBPrcsDeInit((boolean)FALSE);
        break;

      /* !Pseudo:  Default (Invalid Process State then call Det with abnormal
      branch)                                                                 */
      case RDA_XREAD_CFG_ID :
      case RDA_WAIT_MEMIF_IDLE :
      case RDA_XCALL_RDB :
      #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
      case RDA_XCALL_RSTRB_DFTS :
      #endif
      case RDA_DEINIT_IF_IDLE :
      default:
        #if (NVM_DEV_ERROR_DETECT == STD_ON)
        /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
        (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8MAIN_FUNCTION_ID, NVM_E_ABNORMAL_BRANCH);
        #else
        /* !Pseudo: Report error to the DEM */
        Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                        DEM_EVENT_STATUS_FAILED);
        #endif
        break;
    }
  } while (bExecuteNextState == (boolean)TRUE);
}

/******************************************************************************/
/* !Description : State of Write config ID                                    */
/******************************************************************************/
LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStWrAWrBConfigID(void)
{
  /*  !Pseudo: Reset "Execute Next State" Flag                                */
  boolean bExecuteNextState = (boolean)FALSE;

  /* !Pseudo:  Set Current block Id to udtCONFIG_BLOCK_ID                     */
  NvM_udteCurrentBlockID = udtCONFIG_BLOCK_ID;
  NvM_pu8CurrentRamBlkAddr = NvM_akstreBlockDescriptor[udtCONFIG_BLOCK_ID].
      pvidRamBlockDataAddress;
  /* !Pseudo:  If udtCONFIG_BLOCK_ID error status = u8PEND_MULTIBLK_JOB
                  && cancel flag is not raised                                */
  if ((NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus
    == u8PEND_MULTIBLK_JOB) && (NvM_bCancelWrtAllReq == (boolean)FALSE))
  {
    /* !Pseudo:  Call write block process                                     */
    vidWriteBlkPrcsInit();
    /*  !Pseudo: Set MB state to be WRA_XCALL_WRB                             */
    NvM_enuMBlkPrcsState = WRA_XCALL_WRB;
    /*  !Pseudo: Set "Execute Next State" Flag to TRUE                        */
    bExecuteNextState = (boolean)TRUE;
  }

  /* !Pseudo:  If cancel flag is raised                                       */
  else if (NvM_bCancelWrtAllReq == (boolean)TRUE)
  {

    /* !Pseudo: Else handle the cancel write all request.                     */
    vidWrAHookCancelRequest();
    /* !Pseudo: If cancellation of pending blocks is done then
               Set "Execute Next State" Flag to TRUE                          */
    if (NvM_enuMBlkPrcsState == WRA_DEINIT_IF_IDLE)
	  {
      bExecuteNextState = (boolean)TRUE;
    }
  }

  else
  {
    NvM_enuMBlkPrcsState = WRA_DEINIT_IF_IDLE;
    bExecuteNextState = (boolean)TRUE;
  }

  /*  !Pseudo: Return "Execute Next State" Flag                               */
  return(bExecuteNextState);
}


/******************************************************************************/
/* !Description : State of Cross call of the write block process              */
/******************************************************************************/
LOCAL_INLINE FUNC(boolean, NVM_CODE) NvM_bStWrACrossWrB(void)
{
  /*  !Pseudo: Reset "Execute Next State" Flag                                */
  boolean bExecuteNextState = (boolean)FALSE;

  /* !Pseudo:  If cancel flag is not raised                                 */
  if (NvM_bCancelWrtAllReq == (boolean)FALSE)
  {
    /* !Pseudo:  Call write block process                                       */
    vidWriteBlkPrcs();
  }
  /* !Pseudo:  Else, cancel flag is raised                                    */
  else
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0561                                      */
    /* !Pseudo:  If MemIf is not idle                                         */
    if( MemIf_GetStatus(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                                  u8NvRamDeviceId) != MEMIF_IDLE )
    {
     /* !Pseudo: Cancel running job */
     MemIf_Cancel(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
                                  u8NvRamDeviceId);
    }
    /* !Pseudo:  Set current block error status to NVM_REQ_CANCELED           */
    NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus = NVM_REQ_CANCELED;
  }

  /* !Pseudo:  If write block is finished                                     */


  if(NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus
    != u8PEND_MULTIBLK_JOB)
  {
    /* !Pseudo: Update MB error status and find next blk to be processed      */
    vidUpdateMBErrorStatus();

    /* !Pseudo:  If cancel flag is not raised                                 */
    if (NvM_bCancelWrtAllReq == (boolean)FALSE)
    {
      #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
          (NVM_JOB_PRIORITIZATION == STD_ON)
      /* !Pseudo:  If no Imdt Job pending (No need to begin writing the next
      block if imdt write will interrupt it)                                  */
      if(bIsImdtJobQEmpty() == (boolean)TRUE)
      {
      #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
        (NVM_JOB_PRIORITIZATION == STD_ON)                                    */
        /* !Pseudo: If NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID            */
        if (NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID)
        {
           /* !Pseudo: Call vidServeNextBlk()                                 */
          vidServeNextBlk();
        }
        /* !Pseudo: Else NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID          */
        else
        {
          /* !Pseudo: Set NvM_enuMBlkPrcsState to WRA_DEINIT_IF_IDLE          */
          NvM_enuMBlkPrcsState = WRA_DEINIT_IF_IDLE;
        }
        /* !Pseudo: Set "Execute Next State" Flag to TRUE                     */
        bExecuteNextState = (boolean)TRUE;

      #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
          (NVM_JOB_PRIORITIZATION == STD_ON)
      }
      #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
                (NVM_JOB_PRIORITIZATION == STD_ON) */
    }
    /* !Pseudo: Else                                                          */
    else
    {

      /* !Pseudo: Else handle the cancel write all request.                   */
      vidWrAHookCancelRequest();

      /* !Pseudo: If cancellation of pending blocks is done then
           Set "Execute Next State" Flag to TRUE                              */
      if (NvM_enuMBlkPrcsState == WRA_DEINIT_IF_IDLE)
      {
        bExecuteNextState = (boolean)TRUE;
      }
    }
  }
  /*  !Pseudo: Return "Execute Next State" Flag                               */
  return(bExecuteNextState);
}


/******************************************************************************/
/* !Description : Do nessecary actions if cancel write all API is requested   */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidWrAHookCancelRequest(void)
{
  NvM_BlockIdType udtBlockCounter;


    /* !Pseudo: Tag all remaining blocks as cancelled .                       */
    for(udtBlockCounter = NvM_udteCurrentBlockID;
        (udtBlockCounter <= ((NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS));
        udtBlockCounter++)
    {
      if(NvM_astrAdminBlock[udtBlockCounter].u8ErrorStatus == u8PEND_MULTIBLK_JOB)
      {
        NvM_astrAdminBlock[udtBlockCounter].u8ErrorStatus = NVM_REQ_CANCELED;
      }
    }
    if(NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus == u8PEND_MULTIBLK_JOB)
    {
      NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus = NVM_REQ_CANCELED;
    }
    /* !Pseudo:  Set MB Pre Error Status to NVM_REQ_CANCELED                  */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0465                              */
    NvM_u8MBlkPreErrorStatus = NVM_REQ_CANCELED;

    /* !Pseudo:  Reset Cancel Write All Flag                                  */
    NvM_bCancelWrtAllReq = (boolean)FALSE;

    /* !Pseudo:  Set state to WRA_DEINIT_IF_IDLE                              */
    NvM_enuMBlkPrcsState = WRA_DEINIT_IF_IDLE;
}


/******************************************************************************/
/* !Description : Update the MB error status according to the cross call of SB
                  job and increment the current block ID                      */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidUpdateMBErrorStatus(void)
{
  /*  !Pseudo: If cross called SB job error status is not OK                  */
  if( (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus != NVM_REQ_OK)
	  &&
	  (NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus
       != NVM_REQ_RESTORED_FROM_ROM)
	  )

  {
    /*  !Trace_To: GSCSW-NVM-SDD-001-0562                                     */
    /* !Trace_To:  GSCSW-NVM-SDD-001-0579                                     */
    /*  !Pseudo: Set the MB error status to NOT OK                            */
    NvM_u8MBlkPreErrorStatus = NVM_REQ_NOT_OK;
  }
  /*  !Pseudo: If NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID                   */
  if (NvM_udteCurrentBlockID != udtCONFIG_BLOCK_ID)
  {
    /*  !Pseudo: Increment the current block ID                                 */
    NvM_udteCurrentBlockID++;
  }

}


/******************************************************************************/
/* Function used by Back ground CRC process.                                  */
/******************************************************************************/

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
    (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)
/******************************************************************************/
/* !Description : Back ground CRC process. It is called at every Mnf cycle if
module is initialized                                                         */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidBckGndCrcPrcs(void)
{

  /*  !Pseudo: Call corresponding state Function                              */
  if (NvM_enuBGndCrcPrcsState == BGD_CRC_IDLE)
  {
    NvM_vidStBgdCrcIdle();
    if(NvM_enuBGndCrcPrcsState == BGD_CRC_ACTIVE)
    {
      vidStBgdCrcActive();
    }
  }
  else
  {
    vidStBgdCrcActive();
  }
}

/******************************************************************************/
/* !Description : Function Represents the state of back ground process is idle*/

/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidStBgdCrcIdle(void)
{
  /* !Pseudo:  If there is queued jobs in the BGnd CRC Q                      */
  if(bIsBGndCrcQEmpty() == (boolean)FALSE)
  {

    /* !Pseudo: Fetch the block to be served from the BGnd Q                  */
    NvM_udtBgndBlkID = NvM_udtFetchBGndCrcQ();
    /* No need to protect this is part if no queues are implemented           */
    #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented        */
  /*              during integration phase                                    */
  /*lint -save -vo -e960 -v                                                   */

    /* !Pseudo: Open Critical Section                                         */
    SchM_Enter_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
  /* lint -restore                                                            */
    #endif

    /* !Pseudo: If block is not pending                                       */

    if (!(bIS_BLOCK_PENDING(NvM_udtBgndBlkID)) )
    {

      /* !Pseudo: Store Error Status to restore it after finishing the CRC
      calculation */
      NvM_u8BgndPreErrorStatus = NvM_astrAdminBlock[NvM_udtBgndBlkID].
         u8ErrorStatus;
      /* !Pseudo: Mark block as pending                                       */
      NvM_astrAdminBlock[NvM_udtBgndBlkID].u8ErrorStatus = u8PEND_SINGLEBLK_JOB;

      /*  !Pseudo: Initialize Data Ptr to configured Ram Block Address        */
      NvM_pu8BgndRamDataPtr = NvM_akstreBlockDescriptor[NvM_udtBgndBlkID].
         pvidRamBlockDataAddress;
      /*  !Pseudo: Initialize Data Length to configured Block Length          */
      NvM_u16BgndDataLengthCrc = NvM_akstreBlockDescriptor
            [NvM_udtBgndBlkID].u16NvBlockLength;
      /*  !Pseudo: Set NvM_bIsFirstCrcCall to TRUE                            */
      NvM_bIsFirstCrcCall = (boolean)TRUE;
      /* !Pseudo: Initialize CRC Value according to configured CRC type
      with the value coming from CRC configuration                            */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */
     switch (NvM_akstreBlockDescriptor[NvM_udtBgndBlkID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
		   NvM_u8BgndCrc8Value = CRC_INITIAL_VALUE8;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
		   NvM_u16BgndCrc16Value = CRC_INITIAL_VALUE16;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
         {
           NvM_u32BgndCrc32Value = CRC_INITIAL_VALUE32;
           break;
         }
     #endif
		 default:
         break;
	 }
/* PRQA S 3352 --                                                           */

      /*    !Pseudo: Set State to BGnd CRC Active                             */
      NvM_enuBGndCrcPrcsState = BGD_CRC_ACTIVE;
    }
    #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */

  /* !Pseudo: Close Critical Section                                          */
    SchM_Exit_NvM_NVM_ACCESS_001();
  /* PRQA S 3141 --                                                           */
    #endif
  }

}
/******************************************************************************/
/* !Description : Function Representing the state of back ground calculation of
                  CRC on the block (in many steps if required).               */


/******************************************************************************/
static FUNC(void, NVM_CODE) vidStBgdCrcActive(void)
{

  /*  !Pseudo: Passed Data Length  =  NVM_CRC_NUM_OF_BYTES                    */
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  uint16 u16PassedDataLength = NVM_CRC_NUM_OF_BYTES;
  /* PRQA S 1255 --                                                           */

  /* !Deviation : inhibit MISRA rule [3355]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /* PRQA S 3355 ++                                                           */
  /* !Deviation : inhibit MISRA rule [3358]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /* PRQA S 3358 ++                                                           */

  /* !Deviation : inhibit MISRA rule [685]: The violation only occur          */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /*lint -save -vo -e685 -v                                                   */

  /*  !Pseudo: If Data Length > NVM_CRC_NUM_OF_BYTES (Last Calculation Cycle) */
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  if(NvM_u16BgndDataLengthCrc <= NVM_CRC_NUM_OF_BYTES)
  {
    /*  !Pseudo: Passed Data Length  = Data Length (NvM_u16BgndDataLengthCrc) */
    u16PassedDataLength = NvM_u16BgndDataLengthCrc;
  }
  /* PRQA S 1255 --                                                           */
  /* PRQA S 3355 --                                                           */
  /* PRQA S 3358 --                                                           */
  /*lint -restore                                                             */
/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */

  /* !Pseudo: Call CRC API according to configured CRC type                   */

     switch (NvM_akstreBlockDescriptor[NvM_udtBgndBlkID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
		   NvM_u8BgndCrc8Value = Crc_CalculateCRC8(NvM_pu8BgndRamDataPtr,
              (uint32)u16PassedDataLength,NvM_u8BgndCrc8Value,NvM_bIsFirstCrcCall);
		   break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
		   NvM_u16BgndCrc16Value = Crc_CalculateCRC16(NvM_pu8BgndRamDataPtr,
              (uint32)u16PassedDataLength,NvM_u16BgndCrc16Value,NvM_bIsFirstCrcCall);
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
         {
           NvM_u32BgndCrc32Value = Crc_CalculateCRC32(NvM_pu8BgndRamDataPtr,
              (uint32)u16PassedDataLength,NvM_u32BgndCrc32Value,NvM_bIsFirstCrcCall);
           break;
         }
     #endif
		 default:
         break;
	 }
/* PRQA S 3352 --                                                           */

/*lint -restore                                                               */

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /* PRQA S 3356 ++                                                           */
  /* PRQA S 3359 ++                                                           */

  /* !Deviation : inhibit MISRA rule [685]: The violation only occur          */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /*lint -save -vo -e685 -v                                                   */

  /*  !Pseudo: If Data Length > NVM_CRC_NUM_OF_BYTES                          */
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  if(NvM_u16BgndDataLengthCrc > NVM_CRC_NUM_OF_BYTES)

  /* !Deviation : inhibit MISRA rule [3201]: The statement is unreachable only*/
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /* PRQA S 3201 ++                                                           */
  {
  /* PRQA S 3201 --                                                           */
  /* PRQA S 3356 --                                                           */
  /* PRQA S 3359 --                                                           */
  /*lint -restore                                                             */

    /* !Pseudo:  Update Data Pointer for next calculation                     */
    NvM_pu8BgndRamDataPtr = &(NvM_pu8BgndRamDataPtr[NVM_CRC_NUM_OF_BYTES]);
    /* !Pseudo:  Update Data Length for next calculation                      */
    NvM_u16BgndDataLengthCrc = NvM_u16BgndDataLengthCrc - NVM_CRC_NUM_OF_BYTES;
    /* !Pseudo:  Set NvM_bIsFirstCrcCall to FALSE                             */
    NvM_bIsFirstCrcCall = (boolean)FALSE;
  }
  /* PRQA S 1255 --                                                           */
  /* !Pseudo: Else (Last Calculation Cycle)                                   */
  else
  {
    /* !Pseudo:  Move to the Ram CRC Block location                           */
    NvM_pu8BgndRamDataPtr = pu8RAM_BLK_CRC_PTR(NvM_udtBgndBlkID);
    /* !Pseudo: Update Ram CRC                                                */
    NvM_vidBgdUpdateRamBlkCRC();
    /* !Pseudo: Dequeue request from the Bgnd Q                               */
    NvM_vidDeqOutBGndCrcQ();
    /* !Pseudo: Restore the job error status to its prior value               */
    NvM_astrAdminBlock[NvM_udtBgndBlkID].u8ErrorStatus =
      NvM_u8BgndPreErrorStatus;


    /* !Pseudo: Set state to BGD_CRC_IDLE                                     */
    NvM_enuBGndCrcPrcsState = BGD_CRC_IDLE;
  }

}


/******************************************************************************/
/* !Description : Function that writes the calculated Ram Block CRC into the
                  Ram CRC slot in the Background.                             */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidBgdUpdateRamBlkCRC(void)
{
  /*  !Comment: Temporary Counter                                             */
  uint8_least u8Counter;
  /* !Pseudo: Use local variables to cover far issues                         */
#if(NVM_USE_CRC8 == STD_ON)
  uint8 u8BgndCrc8Value = NvM_u8BgndCrc8Value;
#endif
#if(NVM_USE_CRC16 == STD_ON)
  uint16 u16BgndCrc16Value = NvM_u16BgndCrc16Value;
#endif
#if(NVM_USE_CRC32 == STD_ON)
  uint32 u32BgndCrc32Value = NvM_u32BgndCrc32Value;
#endif
  /*  !Comment: Pointer to calculcated CRC value                              */
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8CrcValuePtr;
  uint8 u8NumOfCrcBytes;

  /* !Pseudo: Update Ram CRC with the calculated CRC                          */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */

     switch (NvM_akstreBlockDescriptor[NvM_udtBgndBlkID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
           /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
           /*              deal with 2 different variable types.                     */
           /* PRQA S 0310 ++                                                         */
           pu8CrcValuePtr = &u8BgndCrc8Value;
           /* PRQA S 0310 --                                                         */
           u8NumOfCrcBytes = u8CRC8_NUM_OF_BYTES;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
		   /* Very Dangerous Type Casting. Need to be checked at integeration phase
           on the target                                                       */
           /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
           /*              deal with 2 different variable types.                     */
           /* PRQA S 0310 ++                                                         */
           pu8CrcValuePtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))(&u16BgndCrc16Value);
           /* PRQA S 0310 --                                                         */
           u8NumOfCrcBytes = u8CRC16_NUM_OF_BYTES;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
     {
       /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
       /*              deal with 2 different variable types.                     */
       /* PRQA S 0310 ++                                                         */
       pu8CrcValuePtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))(&u32BgndCrc32Value);
       /* PRQA S 0310 --                                                         */
       u8NumOfCrcBytes = u8CRC32_NUM_OF_BYTES;
       break;
     }
     #endif
     default:
	   pu8CrcValuePtr  = NULL_PTR;
       u8NumOfCrcBytes = (uint8)0;
     break;
	 }
/* PRQA S 3352 --                                                           */

  for(u8Counter = (uint8)0 ; u8Counter < u8NumOfCrcBytes ; u8Counter++)
  {
     /* !Deviation : inhibit MISRA rule [3353]: because The default case in the*/
     /*              switch case is un-reachable. So, the pointer is always set*/
     /* PRQA S 3353, 0505 ++                                                         */
     NvM_pu8BgndRamDataPtr[u8Counter] = pu8CrcValuePtr[u8Counter];
     /* PRQA S 3353, 0505 --                                                         */
  }

}
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)) */


/******************************************************************************/
/* Functions shared between different Processes                               */
/******************************************************************************/

/******************************************************************************/
/* !Description :  State of Wait till MemIf is Idle then Set the Memory
                  Interface to fast mode                                      */
/******************************************************************************/
static FUNC(boolean, NVM_CODE) bStWaitMemIfIdle(void)
{
  /*  !Pseudo: Reset "Execute Next State" Flag                                */
  boolean bExecuteNextState ;

  #if (NVM_DRV_MODE_SWITCH == STD_ON)
  bExecuteNextState = (boolean)FALSE;
  /*  !Pseudo: If  MemIf is Idle                                              */
  if( MemIf_GetStatus(u8MEMIF_BROADCAST_ID) == MEMIF_IDLE )
  {
    /*  !Pseudo: Set underlying MemIf mode to fast                            */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0202                              */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0558                              */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0571                              */
    MemIf_SetMode(MEMIF_MODE_FAST);
    /*  !Pseudo: Search for the next block and initialize the corresponding
                 process                                                      */
    vidServeNextBlk();
    /*  !Pseudo: Set "Execute Next State" Flag to TRUE                        */
    bExecuteNextState = (boolean)TRUE;
  }
  #if(NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: Else if MEMIF is not initialized								                */
  else if(MemIf_GetStatus(u8MEMIF_BROADCAST_ID) == MEMIF_UNINIT)
  {
	  (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,NvM_u8eCurrentJobID,
          NVM_E_MEMIF_UNINIT);
  }
  #endif /*(NVM_DEV_ERROR_DETECT == STD_ON)*/
  /* !Pseudo: Else (Not Idle and already initialized)					      */
  else
  {
    /* !Pseudo:  Do Nothing in this main function cycle                       */
  }

#else
  /*  !Pseudo: Search for the next block and initialize the corresponding
               process                                                      */
  vidServeNextBlk();
  /*  !Pseudo: Set "Execute Next State" Flag to TRUE                        */
  bExecuteNextState = (boolean)TRUE;
#endif /* (NVM_DRV_MODE_SWITCH == STD_ON)                                 */

  /*  !Pseudo: Return "Execute Next State" Flag                               */
  return(bExecuteNextState);

}


/******************************************************************************/
/* !Description : Find Next Block to be written then initialize the           */
/*                corresponding process                                       */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidServeNextBlk(void)
{
  NvM_BlockIdType udtBlockCounter;
  boolean bBlockFound = (boolean)FALSE;

  /* !Pseudo: Search for next block pending block                             */
  for(udtBlockCounter = NvM_udteCurrentBlockID; (udtBlockCounter <=
      (NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS) && (bBlockFound != (boolean)TRUE);
      udtBlockCounter++)
  {
    /* !Pseudo: If block found                                                */
    if(NvM_astrAdminBlock[udtBlockCounter].u8ErrorStatus == u8PEND_MULTIBLK_JOB)
    {
      /* !Pseudo: Save current block ID and current Ram block Address         */
      bBlockFound = (boolean)TRUE;
      NvM_udteCurrentBlockID = udtBlockCounter;
      NvM_pu8CurrentRamBlkAddr = NvM_akstreBlockDescriptor[udtBlockCounter].
      pvidRamBlockDataAddress;
      /* !Pseudo: Set the next state and Initialize the write or read or the
        restore process                                                       */
      NvM_vidInitNextState();
    }
  }
  /* !Pseudo: If block is not found                                           */
  if(bBlockFound == (boolean)FALSE)
  {
    /* !Pseudo: If passed Job ID is Write All                                 */
    if(NvM_u8eCurrentJobID == NvM_u8WRITE_ALL_ID)
    {
      /* !Trace_To        : GSCSW-NVM-SDD-001-0559                            */
      /* !Pseudo: Set state to WRA_XWRITE_CFG_ID                              */
      NvM_enuMBlkPrcsState = WRA_XWRITE_CFG_ID;
    }
    /* !Pseudo: Else (Read All)                                               */
    else
    {
      /* !Pseudo: Set state to RDA_DEINIT_IF_IDLE                             */
      NvM_enuMBlkPrcsState = RDA_DEINIT_IF_IDLE;
    }
  }
}


/******************************************************************************/
/* !Description :  Set the next state and Initialize the write or read or the
                   restore process                                            */
/******************************************************************************/
LOCAL_INLINE FUNC(void, NVM_CODE) NvM_vidInitNextState(void)
{
  /* !Pseudo: If current Job ID is Write All                                  */
  if(NvM_u8eCurrentJobID == NvM_u8WRITE_ALL_ID)
  {
    /* !Pseudo: Set state to WRA_XCALL_WRB and initialize write block process */
    NvM_enuMBlkPrcsState = WRA_XCALL_WRB;
    vidWriteBlkPrcsInit();
  }
  /* !Pseudo: Else (Read All)                                                 */
  else
  {
    /* !Pseudo:  If Dynamic Config is configured                              */
    #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
    /* !Pseudo: If Extended Run and block going to be processed is not
    configured as Resistant to changed SW                                     */
    if( (NvM_u8RdARunTimeMode == u8EXTENDED_RUN) &&

        (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].bResistToChangedSW
                                       == (boolean)FALSE) )
    {
      /* !Pseudo: Set state to RDA_XCALL_RSTRB_DFTS and initialize Restore
      block defaults process                                                  */
      NvM_enuMBlkPrcsState = RDA_XCALL_RSTRB_DFTS;
      vidRstrBlkDftsPrcsInit();
    }
    /* !Pseudo: Else                                                          */
    else
    #endif /* (NVM_DYNAMIC_CONFIGURATION == STD_ON)                           */
    {
      /* !Pseudo: Set state to RDA_XCALL_RDB and initialize read block
      process                                                                 */
      NvM_enuMBlkPrcsState = RDA_XCALL_RDB;
      vidReadBlkPrcsInit();
    }

  }

}

/******************************************************************************/
/* !Description : Function that compares the calculated Ram Block CRC with the
                  NV CRC.                                                     */

/******************************************************************************/
static FUNC(boolean, NVM_CODE) bCompareRamBlkCRC(void)
{

  /*  !Comment: Pointer to calculcated CRC value                              */
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8CrcValuePtr;
  boolean bReturnValue = (boolean)TRUE;
  uint8 u8NumOfCrcBytes;
  uint8 u8Counter;
  /* !Pseudo: Use local variables to cover far issues                         */
#if (NVM_USE_CRC8 == STD_ON)
  uint8 u8Crc8Value = NvM_u8Crc8Value;
#endif
#if (NVM_USE_CRC16 == STD_ON)
  uint16 u16Crc16Value = NvM_u16Crc16Value;
#endif
#if (NVM_USE_CRC32 == STD_ON)
  uint32 u32Crc32Value = NvM_u32Crc32Value;
#endif

  /* !Pseudo: Compare Ram CRC with the calculated CRC                         */
  /* !Pseudo: Return True if matching else return False                       */

  /* Move to the end to the Ram Block , to the CRC position                   */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */

     switch (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
           /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
           /*              deal with 2 different variable types.                     */
           /* PRQA S 0310 ++                                                         */
           pu8CrcValuePtr = &u8Crc8Value;
           /* PRQA S 0310 --                                                         */
           u8NumOfCrcBytes = u8CRC8_NUM_OF_BYTES;
           break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
           /*  Very Dangerous Type Casting. Need to be checked at integeration phase
           on the target                                                             */
           /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
           /*              deal with 2 different variable types.                     */
           /* PRQA S 0310 ++                                                         */
           pu8CrcValuePtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))(&u16Crc16Value);
           /* PRQA S 0310 --                                                         */
           u8NumOfCrcBytes = u8CRC16_NUM_OF_BYTES;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
     {
       /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
       /*              deal with 2 different variable types.                     */
       /* PRQA S 0310 ++                                                         */
       pu8CrcValuePtr = (P2VAR(uint8,AUTOMATIC,AUTOMATIC))(&u32Crc32Value);
       /* PRQA S 0310 --                                                         */
       u8NumOfCrcBytes = u8CRC32_NUM_OF_BYTES;
       break;
     }
     #endif
		 default:
	   pu8CrcValuePtr  = NULL_PTR;
       u8NumOfCrcBytes = (uint8)0;
     break;
	 }
/* PRQA S 3352 --                                                           */

  for (u8Counter = (uint8)0;
       (u8Counter < u8NumOfCrcBytes) && (bReturnValue != (boolean)FALSE);
       u8Counter++)
  {
    /* !Deviation : inhibit MISRA rule [3353]: because The default case in the*/
    /*              switch case is un-reachable. So, the pointer is always set*/
    /* PRQA S 3353, 0505 ++                                                         */
    if(pu8RAM_BLK_CRC_PTR(NvM_udteCurrentBlockID)[u8Counter] !=
         pu8CrcValuePtr[u8Counter])
    {
      bReturnValue = (boolean)FALSE;
    }
    /* PRQA S 3353, 0505 --                                                         */
  }

  return(bReturnValue);
}


/******************************************************************************/
/* !Description : Function that will be called for one time before entering
                  the state of calculation of CRC on the block . It will
				  initialize the variables of this state.                     */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidStCalcRamCRCInit(void)
{
  /*  !Pseudo: Set Data Ptr to configured Ram Block Address                   */
  NvM_pu8RamDataPtrCrc = NvM_pu8CurrentRamBlkAddr;
  /*  !Pseudo: Set Data Length to configured Block Length                     */
  NvM_u16DataLengthCrc = NvM_akstreBlockDescriptor
                     [NvM_udteCurrentBlockID].u16NvBlockLength;
  /* !Pseudo:  Set NvM_bIsFirstCrcCall to FALSE                             */
    NvM_bIsFirstCrcCall = (boolean)TRUE;
  /*  !Pseudo: Set CRC Value to configured initial value according to CRC type*/
/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */
     switch (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
           NvM_u8Crc8Value = CRC_INITIAL_VALUE8;
           break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
           NvM_u16Crc16Value = CRC_INITIAL_VALUE16;
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
         {
           NvM_u32Crc32Value = CRC_INITIAL_VALUE32;
           break;
         }
     #endif
		 default:
         break;
	 }
/* PRQA S 3352 --                                                           */
}

/******************************************************************************/
/* !Description : Function Representing the state of calculation of CRC on the
                  block (in many steps if required).                          */

/******************************************************************************/
static FUNC(Std_ReturnType, NVM_CODE) u8StCalcRamBlkCRC(void)
{
  /*  !Comment: Return Value                                                  */
  Std_ReturnType u8ReturnValue;


  /*  !Comment: Data Length passed to CRC API                                 */
  uint16 u16PassedDataLength;

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */
  /* PRQA S 3356 ++                                                           */
  /* PRQA S 3359 ++                                                           */

  /* !Deviation : inhibit MISRA rule [685]: The violation only occur          */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /*lint -save -vo -e685 -v                                                   */

  /*  !Pseudo: If Data Length > NVM_CRC_NUM_OF_BYTES                          */
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  if(NvM_u16DataLengthCrc > NVM_CRC_NUM_OF_BYTES)
  /* !Deviation : inhibit MISRA rule [3201]: The statement is unreachable only*/
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */
  /* PRQA S 3201 ++                                                           */
  {
    /* PRQA S 3356 --                                                         */
    /* PRQA S 3359 --                                                         */
    /* PRQA S 3201 --                                                         */
    /*lint -restore                                                           */

    /*  !Pseudo: Passed Data Length  = NVM_CRC_NUM_OF_BYTES                   */
    u16PassedDataLength = NVM_CRC_NUM_OF_BYTES;
  }
  /* PRQA S 1255 --                                                           */

  /* !Pseudo: Else (Last Calculation Cycle)                                   */
  else
  {
    /*  !Pseudo: Passed Data Length  = Data Length (NvM_u16DataLengthCrc)     */
    u16PassedDataLength = NvM_u16DataLengthCrc;
  }

/* !Deviation : inhibit MISRA rule [918]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e918 -e619 -v                                               */


  /* !Pseudo: Call corresponding (Calculate CRC API) according to configured
  CRC type                                                                    */

/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */
     switch (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockCrcType)
	 {
     #if (NVM_USE_CRC8 == STD_ON)
		 case NVM_CRC8:
		 {
           NvM_u8Crc8Value = Crc_CalculateCRC8(NvM_pu8RamDataPtrCrc,
              ((uint32)u16PassedDataLength), NvM_u8Crc8Value,NvM_bIsFirstCrcCall);
           break;
		 }
     #endif

     #if (NVM_USE_CRC16 == STD_ON)
		 case NVM_CRC16:
		 {
           NvM_u16Crc16Value = Crc_CalculateCRC16(NvM_pu8RamDataPtrCrc,
              ((uint32)u16PassedDataLength), NvM_u16Crc16Value,NvM_bIsFirstCrcCall);
		   break;
		 }
     #endif

     #if (NVM_USE_CRC32 == STD_ON)
		 case NVM_CRC32:
         {
           NvM_u32Crc32Value = Crc_CalculateCRC32(NvM_pu8RamDataPtrCrc,
              ((uint32)u16PassedDataLength), NvM_u32Crc32Value,NvM_bIsFirstCrcCall);
           break;
         }
     #endif
		 default:
         break;
	 }
/* PRQA S 3352 --                                                           */
/*lint -restore                                                               */

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */

  /* !Deviation : inhibit MISRA rule [3356]: The violation only occur         */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */
  /* PRQA S 3356 ++                                                           */
  /* PRQA S 3359 ++                                                           */

  /* !Deviation : inhibit MISRA rule [685]: The violation only occur          */
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16BgndDataLengthCrc is UINT16_MAX           */
  /*lint -save -vo -e685 -v                                                   */

  /*  !Pseudo: If Data Length > NVM_CRC_NUM_OF_BYTES                          */
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  if (NvM_u16DataLengthCrc > NVM_CRC_NUM_OF_BYTES)

  /* !Deviation : inhibit MISRA rule [3201]: The statement is unreachable only*/
  /*              when NVM_CRC_NUM_OF_BYTES is equal to UINT16_MAX because the*/
  /*              maximum of NvM_u16DataLengthCrc is UINT16_MAX               */
  /* PRQA S 3201 ++                                                           */
  {
    /* PRQA S 3356 --                                                         */
    /* PRQA S 3359 --                                                         */
    /* PRQA S 3201 --                                                         */
    /*lint -restore                                                           */
    /* !Pseudo:  Update Data Pointer for next calculation                     */
    NvM_pu8RamDataPtrCrc = &(NvM_pu8RamDataPtrCrc[NVM_CRC_NUM_OF_BYTES]);
    /* !Pseudo:  Update Data Length for next calculation                      */
    NvM_u16DataLengthCrc = NvM_u16DataLengthCrc - NVM_CRC_NUM_OF_BYTES;
    /* PRQA S 1255 --                                                         */
    /* !Pseudo:  Set NvM_bIsFirstCrcCall to FALSE                             */
    NvM_bIsFirstCrcCall = (boolean)FALSE;


    /* !Pseudo:Set Return Value to NOT_OK (ie State has not finished calculating
               CRC yet)                                                       */
    u8ReturnValue = E_NOT_OK;
  }
  /* !Pseudo: Else (Last Calculation Cycle has finished)                      */
  else
  {
    /* !Pseudo: Set Return Value to OK (ie State has finished calculating
    CRC)                                                                      */

    u8ReturnValue = E_OK;
  }
  /* !Pseudo: Retrun Value                                                    */
  return(u8ReturnValue);

}

/******************************************************************************/
/* !Description : Function that writes the calculated Ram Block CRC into the
                  Ram CRC slot.                                               */
/******************************************************************************/
static FUNC(void, NVM_CODE) vidUpdateRamBlkCRC(void)
{

  /*  !Comment: Pointer to calculcated CRC value                              */
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8CrcValuePtr;

  uint8 u8NumOfCrcBytes;
  uint8 u8Counter;
  /* !Pseudo: Use local variables to cover far issues                         */
#if(NVM_USE_CRC8 == STD_ON)
  uint8 u8Crc8Value = NvM_u8Crc8Value;
#endif
#if(NVM_USE_CRC16 == STD_ON)
  uint16 u16Crc16Value = NvM_u16Crc16Value;
#endif

#if(NVM_USE_CRC32 == STD_ON)
  uint32 u32Crc32Value = NvM_u32Crc32Value;
#endif


  /* !Pseudo: Update Ram CRC with the calculated CRC                          */
  /* Move to the end to the Ram Block , to the CRC position                   */
/* !Deviation : Inhibit MISRA rule [3352]: The switch case only contains 2  */
/*                execution paths due to certain configurations             */
/* PRQA S 3352 ++                                                           */
 switch (NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].u8BlockCrcType)
 {
   #if (NVM_USE_CRC8 == STD_ON)
	 case NVM_CRC8:
	 {
     /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
     /*              deal with 2 different variable types.                     */
     /* PRQA S 0310 ++                                                         */
     pu8CrcValuePtr = &u8Crc8Value;
     /* PRQA S 0310 --                                                         */
     u8NumOfCrcBytes = u8CRC8_NUM_OF_BYTES;
     break;
	 }
   #endif

   #if (NVM_USE_CRC16 == STD_ON)
	 case NVM_CRC16:
	 {
     /*  Very Dangerous Type Casting. Need to be checked at integeration phase
     on the target                                                             */
     /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
     /*              deal with 2 different variable types.                     */
     /* PRQA S 0310 ++                                                         */
     pu8CrcValuePtr = (P2VAR(uint8, AUTOMATIC, AUTOMATIC))(&u16Crc16Value);
     /* PRQA S 0310 --                                                         */
     u8NumOfCrcBytes = u8CRC16_NUM_OF_BYTES;
     break;
	 }
   #endif

#if (NVM_USE_CRC32 == STD_ON)
	 case NVM_CRC32:
   {
     /* !Deviation : inhibit MISRA rule [0310]: because it's the only way to   */
     /*              deal with 2 different variable types.                     */
     /* PRQA S 0310 ++                                                         */
     pu8CrcValuePtr = (P2VAR(uint8, AUTOMATIC, AUTOMATIC))(&u32Crc32Value);
     /* PRQA S 0310 --                                                         */
     u8NumOfCrcBytes = u8CRC32_NUM_OF_BYTES;
     break;
   }
#endif
	  default:
	 pu8CrcValuePtr  = NULL_PTR;
     u8NumOfCrcBytes = (uint8)0;
    break;
  }
/* PRQA S 3352 --                                                           */

  for (u8Counter = (uint8)0; u8Counter < u8NumOfCrcBytes; u8Counter++)
  {
    /* !Deviation : inhibit MISRA rule [3353]: because The default case in the*/
    /*              switch case is un-reachable. So, the pointer is always set*/
    /* PRQA S 3353, 0505 ++                                                         */
    pu8RAM_BLK_CRC_PTR(NvM_udteCurrentBlockID)[u8Counter] =
        pu8CrcValuePtr[u8Counter];
    /* PRQA S 3353, 0505 --                                                         */
  }
}

/******************************************************************************/
/* !Description : Function that deinitializes the process. It dequeues the job
                  from its Queue then sets the correct main Fn State or the
				  Multi Block Process state (incase of cross call)            */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidSBPrcsDeInit(NvM_RequestResultType u8JobResult)
{
  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
  /*  !Pseudo:  Check Main Function State and remove Job from corresponding
                Queue                                                         */
  switch(NvM_enueMainFnState)
  {
    #if (NVM_JOB_PRIORITIZATION == STD_ON)
    /* !Pseudo: If Imdt Job remove from Imdt Q and Set MFn State to Jobs Scan */
    case NvM_MFN_IMDT_SB_JOB:
      vidDeqOutImdtJobQ();
      NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;
      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */
      /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented    */
      /*              during integration phase                                */
      /*lint -save -vo -e960 -v                                               */
      SchM_Enter_NvM_NVM_ACCESS_001();
      /*  !Pseudo: Set The cancel flag of this block to false                 */
      u8CLEAR_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8BLOCK_NOT_CANCELED);
      SchM_Exit_NvM_NVM_ACCESS_001() ;
      /* PRQA S 3141 --                                                       */
      /*lint -restore                                                         */
      break;
    #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

    /* !Pseudo: Else If Std Job remove from Std Q and Set MFn State to Jobs
                Scan                                                          */
    case NvM_MFN_STD_SB_JOB:
      vidDEQ_OUT_STDJOBQ();
      NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;
      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */
      /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented    */
      /*              during integration phase                                */
      /*lint -save -vo -e960 -v                                               */
      SchM_Enter_NvM_NVM_ACCESS_001();
      /*  !Pseudo: Set The cancel flag of this block to false                 */
      u8CLEAR_GENERAL_BLOCK(NvM_udteCurrentBlockID, u8BLOCK_NOT_CANCELED);
	  SchM_Exit_NvM_NVM_ACCESS_001() ;
      /* PRQA S 3141 --                                                       */
      /*lint -restore                                                         */
      break;
    /* !Pseudo: Else If (MB request ie. Cross-called job ) Don't dequeue job
    from queue because it's not queued                                        */
    case NvM_MFN_MB_JOB:
      break;
     /* !Pseudo: Else Report to DET                                           */
    case NvM_MFN_NOT_INIT:
    case NvM_MFN_JOBS_SCAN:
    default:
      #if (NVM_DEV_ERROR_DETECT == STD_ON)
      /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
        (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
               NvM_u8MAIN_FUNCTION_ID, NVM_E_ABNORMAL_BRANCH);
      #else
        /* !Pseudo: Report error to the DEM                                   */
        Dem_ReportErrorStatus(NVM_udtE_INVALID_STATE_PROD,
                        DEM_EVENT_STATUS_FAILED);
      #endif
      break;
  }

  /* !Pseudo: If the current Job Id is NvM_u8READ_BLK_DFT_DSET_ID                 */
  if (NvM_u8eCurrentJobID == NvM_u8READ_BLK_DFT_DSET_ID)
  {
    /* !Pseudo: Then set it to NvM_u8READ_BLOCK_ID                                */
    NvM_u8eCurrentJobID = NvM_u8READ_BLOCK_ID;
  }
  /* !Pseudo: Else do nothing                                                 */
  else
  {
  }
  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)                  */

  NvM_bFrstRddtBlkFailed = (boolean)FALSE;
  /*  !Pseudo: Save Job result in Admin Block                                 */
  NvM_astrAdminBlock[NvM_udteCurrentBlockID].u8ErrorStatus = u8JobResult;

  /* !Pseudo: Notify upper layer with callback if configured for this block   */
  /* !Trace_To: GSCSW-NVM-SDD-001-0580                                        */
  if(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID]
    .pfu8SingleBlockCallBack != NULL_PTR)
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0498                                      */
/* !Trace_To        : GSCSW-NVM-SDD-001-0060                                  */
     (void)(NvM_akstreBlockDescriptor[NvM_udteCurrentBlockID].
        pfu8SingleBlockCallBack(NvM_u8eCurrentJobID, u8JobResult));
  }
}


/******************************************************************************/
/* !Description : State to Deinitialize the MB Process and switch the memory
                  driver mode to slow again                                   */

/******************************************************************************/
static FUNC(void, NVM_CODE) vidStMBPrcsDeInit(boolean bFreezeMBJob
/* !Comment:  TRUE if freezing the MB job due to Immediate Job and False if
Normal End */)
{
  /*  !Pseudo: If  MemIf is Idle                                              */
  /* !Trace_To        : GSCSW-NVM-SDD-001-0499                                */
  if ( MemIf_GetStatus(u8MEMIF_BROADCAST_ID) == MEMIF_IDLE )
  {
    #if (NVM_DRV_MODE_SWITCH == STD_ON)
/* !Trace_To        : GSCSW-NVM-SDD-001-0202                                  */
    /*  !Pseudo: Set back underlying MemIf mode to slow if configured         */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0563                              */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0571                              */
    MemIf_SetMode(MEMIF_MODE_SLOW);
    #endif /* (NVM_DRV_MODE_SWITCH == STD_ON)                                 */

    /*  !Pseudo: If not feezing the MB request by an immediate job            */
    if (bFreezeMBJob == (boolean)FALSE)
    {
      /*  !Pseudo: Multi-block job result is set to pre-error status          */
      NvM_astrAdminBlock[udtMULTI_BLOCK_ID].u8ErrorStatus =
        NvM_u8MBlkPreErrorStatus;
      /*  !Pseudo: Notify upper layer with callback if configured             */
      if(NvM_kpfvideMultiBlockCallBack != NULL_PTR)
      {
/* !Trace_To        : GSCSW-NVM-SDD-001-0061                                  */

        NvM_kpfvideMultiBlockCallBack(NvM_strMBJobBfr.u8JobID,
          NvM_u8MBlkPreErrorStatus);
      }
      /*  !Pseudo: Remove job from buffer                                     */
      NvM_strMBJobBfr.u8State = u8EMPTY;
    }
    #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
        (NVM_JOB_PRIORITIZATION == STD_ON              )
    /*  !Pseudo: Else (Freezing the Job by Imdt Job)                          */
    else
    {
      /*  !Pseudo: Save the block the MB job stopped at it , so when resuming
                   the MB job it will begin searching from it directly        */
      NvM_strMBJobBfr.udtBlockID = NvM_udteCurrentBlockID;
    }
    #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
              (NVM_JOB_PRIORITIZATION == STD_ON)                              */

    /*  !Pseudo: Change Main Function state to scan for new jobs              */
    NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;
  }
}



/******************************************************************************/
/*  Functions Used Only by NvM_SetDataIndex API                               */
/******************************************************************************/

/******************************************************************************/
/* !Description : Checks if Data Set Index is in the Valid Range              */
/******************************************************************************/
#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)

static FUNC(boolean, NVM_CODE) bIsDataSetIndexValid
(NvM_BlockIdType udtBlockId,uint8 u8DataIndex)
{
  boolean bReturnValue;

  /* !Pseudo: If data set index in the Nv range                               */

  if(u8DataIndex < NvM_akstreBlockDescriptor[udtBlockId].u8NvBlockNum)
  {
    /* !Pseudo: Return true                                                   */
    bReturnValue = (boolean)TRUE;
  }
  /* !Pseudo: Else If data set index is in the Rom range,                     */

  /* !Pseudo:   and Rom Blck address is not configured to Null                */
  else if( (u8DataIndex < (NvM_akstreBlockDescriptor[udtBlockId].u8NvBlockNum +
            NvM_akstreBlockDescriptor[udtBlockId].u8RomBlockNum)) &&
            (NvM_akstreBlockDescriptor[udtBlockId].pku8RomBlkDataAddress
            != NULL_PTR)
         )
  {
    /* !Pseudo: return true                                                   */
    bReturnValue = (boolean)TRUE;
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: return false */
    bReturnValue = (boolean)FALSE;
  }
  return(bReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */


/******************************************************************************/
/*  Functions Used Only by Erase and Invalidate APIs                          */
/******************************************************************************/

/******************************************************************************/
/* !Description :  Function to erase or Invalidate NV block according to the
                   passed Job ID                                              */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
static FUNC(Std_ReturnType, NVM_CODE) u8EraseOrInvalidateBlk
(
  NvM_BlockIdType udtBlockId, uint8 u8JobId
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */

  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0346, GSCSW-NVM-SDD-001-0351              */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID, u8JobId,
        NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(udtBlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0348, GSCSW-NVM-SDD-001-0353              */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID, u8JobId,
        NVM_E_PARAM_BLOCK_ID);
  }
  #if (NVM_JOB_PRIORITIZATION == STD_ON)
  /* !Pseudo: Else if NV block is required while it is not of immediate
              priority                                                        */
  /* !Trace_To: GSCSW-NVM-SDD-001-0475                                        */
  else if( (u8JobId == NvM_u8ERASE_NV_BLOCK_ID) && (NvM_akstreBlockDescriptor
       [udtBlockId].u8BlockJobPriority != u8IMMEDIATE_PRIORITY) )
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0349                                      */
    (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
        NvM_u8ERASE_NV_BLOCK_ID,NVM_E_BLOCK_CONFIG);
  }
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */
  /* !Pseudo: Else                                                            */
  else
  /* !Pseudo: #endif                                                          */
 #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */

  /* !Pseudo: If identified block is write protected or
   a ROM block of a dataset NVRAM block is referenced                         */
   /* !Trace_To: GSCSW-NVM-SDD-001-0475, GSCSW-NVM-SDD-001-0469               */
   /* !Trace_To: GSCSW-NVM-SDD-001-0476, GSCSW-NVM-SDD-001-0468               */
  if( u8CHECK_GENERAL_BLOCK (udtBlockId, u8PROTECTION_ENABLE) ||
	  (NvM_astrAdminBlock[udtBlockId].u8DataSetIndex >=
        NvM_akstreBlockDescriptor[udtBlockId].u8NvBlockNum      ) )
  {
    /* !Pseudo: Report error to the DEM                                       */
	/* !Trace_To: GSCSW-NVM-SDD-001-0309                                      */
    Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED,
                    DEM_EVENT_STATUS_FAILED);
    /* !Pseudo: #endif                                                        */
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo:  Enqueue the job request in standard queue                    */
    /* !Pseudo:   Set Return Value to Enqueue Result                          */
    /* !Trace_To: GSCSW-NVM-SDD-001-0479, GSCSW-NVM-SDD-001-0467              */
    /* !Trace_To: GSCSW-NVM-SDD-001-0502                                      */
    u8ReturnValue = u8ENQ_IN_STDJOBQ(u8JobId, udtBlockId , NULL_PTR);

  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */



#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/*  Function Used by APIs                                                     */
/******************************************************************************/

/******************************************************************************/
/* !Description :  Function to check if WriteAll job is pending and if the
 passed block will served by the WriteAll                                     */
/* !Comment   :  Block will be served or not                                  */
/******************************************************************************/
 static FUNC(boolean, NVM_CODE)  bWillBlkBeServedByWA (NvM_BlockIdType udtBlockIden)
  {
     /* !Pseudo: Initialize return Value to False                             */
     boolean bReturnValue = (boolean)FALSE;

     /* !Pseudo: If "WriteAll job is pending"
                 AND Blk is "Configured as permanent"
                 AND Marked as not write protected
                 AND Marked as "valid and changed" OR redundant
				     "valid and unchanged" block                              */
     /* !Pseudo:    Set Return Value to TRUE                                  */
     if ( (bIS_BLOCK_PENDING(udtMULTI_BLOCK_ID))
     && (NvM_strMBJobBfr.u8State == u8PEND_BUTNOT_STARTED)
     && (NvM_strMBJobBfr.u8JobID == NvM_u8WRITE_ALL_ID)
     &&(!(u8CHECK_GENERAL_BLOCK(udtBlockIden, u8PROTECTION_ENABLE)))
	 && (NvM_akstreBlockDescriptor[udtBlockIden].pvidRamBlockDataAddress != NULL_PTR)
#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
     && ( (NvM_astrAdminBlock[udtBlockIden].u8State == u8VALID_CHANGED)
        || ( (NvM_astrAdminBlock[udtBlockIden].u8State == u8VALID_UNCHANGED)
           && (NvM_akstreBlockDescriptor[udtBlockIden].u8BlockManagementType == NVM_BLOCK_REDUNDANT))
        )
#endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */
         )
     {
        bReturnValue = (boolean)TRUE;
     }
     /* !Pseudo: Return Value                                                 */
     return(bReturnValue);
  }
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)                    */

/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/*                              APIs  (Global Functions)                      */
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/* !Description :  API to Initialize a NV block                               */
/* !Trace_To        : GSCSW-NVM-SDD-001-0042                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0435                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0437                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_Init(void)
{
  NvM_BlockIdType udtBlockCtr;
  uint16_least u16DataCtr;

  #if  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
       (NVM_JOB_PRIORITIZATION == STD_ON)
  uint8_least u8QueueCtr;
  #endif

  /* This function is protected using the state of the Main Function
  (NvM_MFN_NOT_INIT).                                                             */

/* !Deviation : Inhibit MISRA rule [3198]: Because this redundant assignment  */
/*              ensures that the value of the main function state was         */
/*              correctly initialized.                                        */
/* PRQA S 3198 ++                                                             */

  /* This instruction is not needed but its only for safety incase of reset
  didn't reset the Main Fn state to Not init .                                */
  NvM_enueMainFnState = NvM_MFN_NOT_INIT;
/* PRQA S 3198 --                                                             */

  /* !Pseudo: Initialize administrative blocks and Cancel jobs array          */
  /* !Trace_To: GSCSW-NVM-SDD-001-0439                                        */
  for(udtBlockCtr = (uint8)0; udtBlockCtr <= (NvM_BlockIdType)
        NVM_udtNUM_OF_NVRAM_BLOCKS; udtBlockCtr++)
  {
    if (NvM_akstreBlockDescriptor[udtBlockCtr].bBlockWriteProtection == TRUE)
	{
	  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
      /*              during integration phase                                    */
      /* PRQA S 3141 ++                                                           */

    u8SET_GENERAL_BLOCK(udtBlockCtr, u8PROTECTION_ENABLE);

     /* PRQA S 3141 --                                                           */
	}
    else
	{
	  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
      /*              during integration phase                                    */
      /* PRQA S 3141 ++                                                           */

    u8CLEAR_GENERAL_BLOCK(udtBlockCtr, u8PROTECTION_DISABLE);

     /* PRQA S 3141 --                                                           */
	}
    NvM_astrAdminBlock[udtBlockCtr].u8ErrorStatus = NVM_REQ_NOT_OK;
	/* !Trace_To: GSCSW-NVM-SDD-001-0436                                      */
    NvM_astrAdminBlock[udtBlockCtr].u8DataSetIndex = (uint8)0;
    /* !Pseudo: #If (NVM_SET_RAM_BLOCK_STATUS_API==STD_OFF)
    then initialize the RAM block state as Invalid.                           */
    #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_OFF)
    NvM_astrAdminBlock[udtBlockCtr].u8State = u8INVALID;
    #else
    /* !Pseudo: Else don't initialize the state of the block to
    enable the hot reset recovery mechanism of the RAM block.                 */
    #endif /* (NVM_SET_RAM_BLOCK_STATUS_API==STD_OFF)                         */
    /* !Pseudo: Initialize the lock status of the block to unlocked          
	TRUE:  Mark RAM block as locked
    FALSE: Mark RAM block as unlocked                            */
	  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
      /*              during integration phase                                    */
      /* PRQA S 3141 ++                                                           */

	u8CLEAR_GENERAL_BLOCK(udtBlockCtr, u8BLOCK_UNLOCKED);

      /* PRQA S 3141 --                                                           */
#if  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    /* !Pseudo: Initialize Cancel requested to FALSE                          */
	/* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
    /*              during integration phase                                    */
    /* PRQA S 3141 ++                                                           */

	u8CLEAR_GENERAL_BLOCK(udtBlockCtr, u8BLOCK_NOT_CANCELED);

    /* PRQA S 3141 --                                                           */
#endif
  }
  /* !Deviation : inhibit MISRA rule [1255]: Suffix not needed because it is  */
  /*              already casted to uint16.                                   */
  /* PRQA S 1255 ++                                                           */
  for(u16DataCtr = (uint16)0;u16DataCtr<NVM_u16INTERNAL_RAM_BUF_SIZE;
      u16DataCtr++)
  {
/* (NvM_au8InternalRamBuffer) to reserve a place where we can concatinate
   the content of the RAM with it calculated CRC to be read as one block     */
    NvM_au8InternalRamBuffer[u16DataCtr] = 0;
  }
  /* PRQA S 1255 --                                                           */

#if  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
     && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
  for(u16DataCtr = (uint16)0;u16DataCtr<NVM_u16RAM_MIRROR_BUF_SIZE;
      u16DataCtr++)
  {
/* (NvM_au8RamMirrorBuffer) to reserve a place where save RAM Mirror    */
    NvM_au8RamMirrorBuffer[u16DataCtr] = 0;
  }
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)\
     && (NVM_u16RAM_MIRROR_BUF_SIZE !=0U) */

  /*  !Pseudo: Initialize permenant variables                                 */
  NvM_bCancelWrtAllReq = (boolean)FALSE;
  #if (NVM_POLLING_MODE == STD_OFF)
  NvM_udtMemIfJobEndClBck = MEMIF_JOB_FAILED;
  #endif

#if  (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)  \
   && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )
  /* (NvM_bAnyCancelJobReq): Flag raised if at least one SB job is requested to be canceled
  (NvM_u8RepeatMirrorOp): Counter of Mirror operation retries*/
  NvM_bAnyCancelJobReq = (boolean)FALSE;
  NvM_u8RepeatMirrorOp = (uint8)0;
#endif /*(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) \
        && ( NVM_u16RAM_MIRROR_BUF_SIZE != 0U )*/

  /*  !Pseudo: All these permenant variables are initialized here for safety
  reasons,but they shall be overwritten without using the initialized values  */
  NvM_pu8RamDataPtrCrc = NULL_PTR;
  NvM_u16DataLengthCrc = (uint16)0;

#if(NVM_u16VERIFY_BUFFER_SIZE != 0U)
 /* This parameter shall publish the size of the verification buffer.
 used for write verification process, 
 the read back data is stored in this buffer
 and then compared to the written data. */

  NvM_u16RemBlockLength = (uint16)0;
#endif /*(NVM_u16VERIFY_BUFFER_SIZE != 0U)*/

#if(NVM_USE_CRC8 == STD_ON)
  NvM_u8Crc8Value = (uint8)0;
#endif

#if(NVM_USE_CRC16 == STD_ON)
  NvM_u16Crc16Value = (uint16)0;
#endif

#if(NVM_USE_CRC32 == STD_ON)
  NvM_u32Crc32Value = 0;
#endif


  NvM_u8SBPreErrorStatus = NVM_REQ_NOT_OK;
  NvM_u8MBlkPreErrorStatus = NVM_REQ_NOT_OK;
  NvM_u8WriteRetriesCtr = (uint8)0;
  NvM_u8ReadRetriesCtr = (uint8)0;
  /*(NvM_bFrstRddtBlkFailed): Flag to be raised if first redundant block can't be read */
  NvM_bFrstRddtBlkFailed = (boolean)FALSE;
  #if (NVM_DYNAMIC_CONFIGURATION == STD_ON)
    NvM_u8RdARunTimeMode = u8NORMAL_RUN;
  #endif


  #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
    /*  !Pseudo:  Initialize all queues to Empty state                        */
  NvM_strImdtQAdmin.u8EnqInIndex = (uint8)0;
  NvM_strImdtQAdmin.u8DeqOutIndex = (uint8)0;
  NvM_strImdtQAdmin.u8NumOfQuedJobs = (uint8)0;

  #if (NVM_JOB_PRIORITIZATION == STD_ON)

  NvM_strStdQAdmin.u8DeqOutIndex = (uint8)0;
  NvM_strStdQAdmin.u8NumOfQuedJobs = (uint8)0;


  /*  !Pseudo: Mark all slots in the standard Queue as Empty                  */
  for(u8QueueCtr = (uint8)0; u8QueueCtr < NVM_SIZE_STANDARD_JOB_QUEUE;
      u8QueueCtr++)
  {
     NvM_astrStdSBJobQ[u8QueueCtr].u8JobID = u8EMPTYSLOT;
     /* This instruction makes searching faster (in Fetch Job Fn )using the
        priority entry only because empty slots will be with the lowest
        priority (255)                                                        */
     NvM_au8StdQPriority[u8QueueCtr] = u8LOWEST_PRIORITY;
  }

  /*  !Pseudo:  Reset Std job crased flag                                     */
  NvM_bStdJobCrashed = (boolean)FALSE;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON) */

  #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

  #if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
      (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
  NvM_strBGndCrcQAdmin.u8EnqInIndex = (uint8)0;
  NvM_strBGndCrcQAdmin.u8DeqOutIndex = (uint8)0;
  NvM_strBGndCrcQAdmin.u8NumOfQuedJobs = (uint8)0;
  NvM_enuBGndCrcPrcsState = BGD_CRC_IDLE;

  #endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) &&
  (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)                                          */

  /*  !Pseudo: Initialize Multi Block Buffer to Empty state                   */
  NvM_strMBJobBfr.u8State = u8EMPTY;

  /*  !Pseudo:  Set the Main Fn state to Job scanning                         */
  NvM_enueMainFnState = NvM_MFN_JOBS_SCAN;

}          

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) && \
    (NVM_JOB_PRIORITIZATION == STD_ON)
/******************************************************************************/
/* !Description :  API to erase a NV block                                    */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0051, GSCSW-NVM-SDD-001-0473,
                      GSCSW-NVM-SDD-001-0474, GSCSW-NVM-SDD-001-0480          */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock
(
 /* !Comment: Block ID                                                        */
 NvM_BlockIdType BlockId
)
{
  Std_ReturnType u8ReturnValue;

  /* !Pseudo: Enqueue Erase Request in the standard Queue                     */
  u8ReturnValue = u8EraseOrInvalidateBlk(BlockId, NvM_u8ERASE_NV_BLOCK_ID);

  return(u8ReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) &&
          (NVM_JOB_PRIORITIZATION == STD_ON) */


#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* !Description :  API to invalidate a NV block                               */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0052 , GSCSW-NVM-SDD-001-0466,
                      GSCSW-NVM-SDD-001-0467                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock
(
 /* !Comment: Block ID                                                        */
 NvM_BlockIdType BlockId
)
{
  Std_ReturnType u8ReturnValue;

  /* !Pseudo: Enqueue Erase Request in the standard Queue                     */
  u8ReturnValue = u8EraseOrInvalidateBlk(BlockId, NvM_u8INVALIDATE_NVBLK_ID);

  return(u8ReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) */


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API to restore the default data to corresponding RAM block  */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0050, GSCSW-NVM-SDD-001-0482          */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
 /* !Comment: Block ID                                                        */
 NvM_BlockIdType BlockId,
 /* !Comment: Pointer to the RAM data block                                   */
 P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0341                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0345                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If no permanent RAM block is configured and the block doesn't
              use explicit synchronization and a NULL pointer is passed via the
              parameter NvM_DstPtr                                            */
  else if( (NvM_DstPtr == NULL_PTR) && (NvM_akstreBlockDescriptor[BlockId]
                                           .pvidRamBlockDataAddress == NULL_PTR))
  {
    /* !Pseudo: Report to the DET                                             */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0344                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_PARAM_ADDRESS);
  }
  /*  !Pseudo: Else If block is not configured with a ROM block and with no
  INIT BLOCK callback                                                         */
  else if((NvM_akstreBlockDescriptor[BlockId].pku8RomBlkDataAddress == NULL_PTR)
    && (NvM_akstreBlockDescriptor[BlockId].pfu8InitBlockCallBack == NULL_PTR))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0343                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_BLOCK_CONFIG);
  }
  /* !Pseudo: Else If NV block (not a rom block) of a dataset NVRAM block is
              referenced                                                      */
  /* !Trace_To: GSCSW-NVM-SDD-001-0488                                        */
  else if(
    (NvM_akstreBlockDescriptor[BlockId].pku8RomBlkDataAddress != NULL_PTR) &&
    (NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType ==
                                                        NVM_BLOCK_DATASET) &&
    (NvM_astrAdminBlock[BlockId].u8DataSetIndex <
                          NvM_akstreBlockDescriptor[BlockId].u8NvBlockNum) )
  {
    /* !Pseudo: Report to the DET                                             */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
            NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_ABNORMAL_BRANCH);
  }
    /* !Pseudo: Else If the referenced block is locked and the permanent RAM
              address is passed via parameter NvM_DstPtr                      */
    /* !Trace_To: GSCSW-NVM-SDD-001-0419, GSCSW-NVM-SDD-001-0414            */
    else if ( (u8CHECK_GENERAL_BLOCK (BlockId, u8BLOCK_LOCKED))
           && ((NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)FALSE)
              && (( NvM_DstPtr == NULL_PTR )
                 ||
                 (NvM_DstPtr == NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress)) ))

  {
    /* !Pseudo: Report to the DET                                             */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8RESTORE_BLK_DFTS_ID, NVM_E_BLOCK_LOCKED);
  }
  /* !Pseudo: Else                                                            */
  else
  /* !Pseudo: #Else                                                           */
  #else
  /* !Pseudo: If NV block (not a rom block) of a dataset NVRAM block is
              referenced */
  if( (NvM_akstreBlockDescriptor[BlockId].pku8RomBlkDataAddress != NULL_PTR) &&
      (NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType ==
                                                          NVM_BLOCK_DATASET) &&
      (NvM_astrAdminBlock[BlockId].u8DataSetIndex <
                            NvM_akstreBlockDescriptor[BlockId].u8NvBlockNum) )
  {
    /* !Pseudo: Report error to the DEM                                       */
    Dem_ReportErrorStatus(NVM_udtE_NV_BLK_ACCESS_PROD,
                    DEM_EVENT_STATUS_FAILED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
 /* !Pseudo: #endif  */
  {
    /* !Pseudo:  Enqueue the job request in standard queue                    */
    /* !Pseudo:  Set Return Value to Enqueue Result                           */
    /* !Trace_To: GSCSW-NVM-SDD-001-0484                                      */
    if(NvM_DstPtr != NULL_PTR)
    {
      /* !Trace_To: GSCSW-NVM-SDD-001-0485                                    */
      u8ReturnValue = u8ENQ_IN_STDJOBQ(NvM_u8RESTORE_BLK_DFTS_ID, BlockId,
        NvM_DstPtr);
    }
    else
    /* !Trace_To: GSCSW-NVM-SDD-001-0483                                      */
    {
      /* !Trace_To: GSCSW-NVM-SDD-001-0485                                    */
      u8ReturnValue = u8ENQ_IN_STDJOBQ(NvM_u8RESTORE_BLK_DFTS_ID, BlockId,
        NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress);
    }
  }

  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}


/******************************************************************************/
/* !Description : API that get the current index of a dataset NVRAM block     */
/* !Comment     :  Request is accepted or not                                 */
/* !Trace_To        : GSCSW-NVM-SDD-001-0044                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
  NvM_BlockIdType BlockId,
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0318                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_DATA_IND_ID, NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else If DataIndexPtr is a NULL pointer                          */
  else if(DataIndexPtr == NULL_PTR)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0321                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_DATA_IND_ID, NVM_E_PARAM_DATA);
  }
  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0320                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_DATA_IND_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If block management type is not DATASET                    */
  else if(NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType
             != NVM_BLOCK_DATASET)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0319                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_DATA_IND_ID, NVM_E_PARAM_BLOCK_TYPE);
    /* !Pseudo: Return Zero                                                   */
    (*DataIndexPtr) = (uint8)0;
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: Return block dataset index                                    */
    (*DataIndexPtr) = NvM_astrAdminBlock[BlockId].u8DataSetIndex;
    u8ReturnValue = E_OK;

  }
  /* !Pseudo: #else DET is disabled                                           */
  #else
  /* !Pseudo: If block management type is not DATASET                         */
  if(NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType
             != NVM_BLOCK_DATASET)
  {
    /* !Pseudo: Return Zero                                                   */
    (*DataIndexPtr) = (uint8)0;
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: Return block dataset index                                    */
	/* !Trace_To: GSCSW-NVM-SDD-001-0459                                      */
    (*DataIndexPtr) = NvM_astrAdminBlock[BlockId].u8DataSetIndex;
    u8ReturnValue = E_OK;
  }

  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}


/******************************************************************************/
/* !Description : API that sets the index to access a certain dataset of a
                  NVRAM block (with/without ROM blocks)                       */
/* !Comment     :  Request is accepted or not                                 */
/* !Trace_To        : GSCSW-NVM-SDD-001-0043                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
  NvM_BlockIdType BlockId,
  uint8 DataIndex
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0313                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8SET_DATA_INDEX_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0317                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8SET_DATA_INDEX_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If block management type is not DATASET                    */
  else if(NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType
             != NVM_BLOCK_DATASET)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0316                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_DATA_INDEX_ID, NVM_E_PARAM_BLOCK_TYPE);
  }
  /* !Pseudo: Else if Data Set Index is not in the Valid Range                */
  else if((bIsDataSetIndexValid(BlockId,DataIndex)) != (boolean)TRUE)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0315                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_DATA_INDEX_ID, NVM_E_PARAM_BLOCK_DATA_IDX);
  }
  /* !Pseudo: Else if identified block is already pending                     */
  else if (bIS_BLOCK_PENDING(BlockId))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0314                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_DATA_INDEX_ID, NVM_E_BLOCK_PENDING);
  }
  /* !Pseudo: Else */
  else
  {
    /* !Pseudo: Update block dataset index                                    */
    NvM_astrAdminBlock[BlockId].u8DataSetIndex = DataIndex;
    u8ReturnValue = E_OK;
  }

  /* !Pseudo: #else DET is disabled                                           */
  #else
  /* !Pseudo: If identified block is already pending                     */
  if (bIS_BLOCK_PENDING(BlockId))
  {
    /* !Pseudo: Report error to the DEM                                       */
    Dem_ReportErrorStatus(NVM_udtE_BLK_PENDING_PROD, DEM_EVENT_STATUS_FAILED);
  }
  /* !Pseudo: Else if referenced block is not of type dataset                 */
  /* !Trace_To: GSCSW-NVM-SDD-001-0455                                        */
  else if (NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType
             != NVM_BLOCK_DATASET)
  {
  }
  /* !Pseudo: Else if Data Set Index is not in the Valid Range                */
  else if ((bIsDataSetIndexValid(BlockId,DataIndex)) != (boolean)TRUE)
  {
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: Update block dataset index                                    */
	/* !Trace_To: GSCSW-NVM-SDD-001-0454, GSCSW-NVM-SDD-001-0456              */
    NvM_astrAdminBlock[BlockId].u8DataSetIndex = DataIndex;
    u8ReturnValue = E_OK;
  }
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */


#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/******************************************************************************/
/* !Description : API to set/reset the write protection for a NV block        */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0045                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
  NvM_BlockIdType BlockId,
  boolean ProtectionEnabled
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0322                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_BLK_PROTECT_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0325                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_BLK_PROTECT_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If block is configured to write block once                 */
  else if(NvM_akstreBlockDescriptor[BlockId].bWriteBlockOnce == (boolean)TRUE)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0324                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_BLK_PROTECT_ID, NVM_E_BLOCK_CONFIG);
  }

  /* !Pseudo: Else If block is already pending                                */
  else if (bIS_BLOCK_PENDING(BlockId))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0323                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_BLK_PROTECT_ID, NVM_E_BLOCK_PENDING);
  }
  /* !Pseudo: Else                                                            */
  else
  {
    /* !Pseudo: Enable or Disable the protection according to the passed
    parameter */
	/* !Trace_To: GSCSW-NVM-SDD-001-0457                                      */
	 if(ProtectionEnabled == TRUE)
	  {
	   /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
       /*              during integration phase                                    */
       /* PRQA S 3141 ++                                                           */
	  SchM_Enter_NvM_NVM_ACCESS_001();
	  u8SET_GENERAL_BLOCK(BlockId, u8PROTECTION_ENABLE);
	  SchM_Exit_NvM_NVM_ACCESS_001();
     /* PRQA S 3141 --                                                           */
      }
     else
      {
	   /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
       /*              during integration phase                                    */
       /* PRQA S 3141 ++                                                           */
	  SchM_Enter_NvM_NVM_ACCESS_001();
      u8CLEAR_GENERAL_BLOCK(BlockId, u8PROTECTION_DISABLE); 
	  SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                           */
      }
    u8ReturnValue = E_OK;
  }

  /* !Pseudo: #else DET is disabled                                           */
  #else
  /* !Pseudo: If block is configured to write block once                      */
  /* !Trace_To: GSCSW-NVM-SDD-001-0458                                        */
  if(NvM_akstreBlockDescriptor[BlockId].bWriteBlockOnce != (boolean)TRUE)
  {
    /* !Pseudo: Enable or Disable the protection according to the passed
    parameter */
	  if(ProtectionEnabled == TRUE)
	  {
	    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
        /*              during integration phase                                    */
        /* PRQA S 3141 ++                                                           */
	  SchM_Enter_NvM_NVM_ACCESS_001();
	  u8SET_GENERAL_BLOCK(BlockId, u8PROTECTION_ENABLE);
	  SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                           */
      }
     else
      {
	    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
        /*              during integration phase                                    */
        /* PRQA S 3141 ++                                                           */
	  SchM_Enter_NvM_NVM_ACCESS_001();
      u8CLEAR_GENERAL_BLOCK(BlockId, u8PROTECTION_DISABLE); 
	  SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                         */
      }
    u8ReturnValue = E_OK;
  }
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /*  (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)  */

/******************************************************************************/
/* !Description : API to read a NVRAM block error/status information          */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0046                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
  NvM_BlockIdType BlockId,
  P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
)
{
  /* !Deviation : Inhibit MISRA rule [3141]: The initialization is needed     */
  /*              in case DET is enabled                                      */
  /* PRQA S 3197 ++                                                         */
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
  /* PRQA S 3197 --                                                         */

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0326                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_ERROR_STATUS_ID, NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else If RequestResultPtr is a NULL pointer                      */
  else if(RequestResultPtr == NULL_PTR)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0328                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_ERROR_STATUS_ID, NVM_E_PARAM_DATA);
  }
  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if (BlockId > (NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0327                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8GET_ERROR_STATUS_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else                                                            */
  else
  /* !Pseudo: #endif                                                          */
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* !Pseudo: Return the error status                                       */
	/* !Trace_To: GSCSW-NVM-SDD-001-0460                                      */
    (*RequestResultPtr) = ((NvM_astrAdminBlock[BlockId].u8ErrorStatus)& u8PENDING_MASK);
    u8ReturnValue = E_OK;
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
/******************************************************************************/
/* !Description : API to set the RAM block status to changed or unchanged     */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0048                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
 NvM_BlockIdType BlockId,
 boolean BlockChanged
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0356                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8SET_RAM_BLK_STAT_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0358                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8SET_RAM_BLK_STAT_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If referenced block is not associated to a permanent RAM
  block                                                                       */
  else if(NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress == NULL_PTR)
  {
    /* !Pseudo: Report to the DET                                             */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8SET_RAM_BLK_STAT_ID, NVM_E_BLOCK_CONFIG);
  }
  /* !Pseudo: Else If MB Job is running                                       */
  else if(NvM_astrAdminBlock[udtMULTI_BLOCK_ID].u8ErrorStatus
    == u8PEND_MULTIBLK_JOB)
  {
    /* !Pseudo: Report to the DET                                             */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0007                              */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID, NvM_u8SET_RAM_BLK_STAT_ID,
      NVM_E_ABNORMAL_BRANCH);
  }
  /* !Pseudo: Else if identified block is already pending                     */
  else if (bIS_BLOCK_PENDING(BlockId))
  {
    /* !Pseudo: Report to the DET                                             */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0357                              */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
          NvM_u8SET_RAM_BLK_STAT_ID, NVM_E_BLOCK_PENDING);
  }
  /* !Pseudo: Else                                                            */
  else
  /* !Pseudo: #Else                                                           */
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* !Pseudo: If referenced block is associated to a permanent RAM
    block                                                                     */
	/* !Trace_To: GSCSW-NVM-SDD-001-0461                                      */
    if (NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress != NULL_PTR)
    {
      /* !Pseudo:  If block changed input parameter is True                   */
      if (BlockChanged == (boolean)TRUE)
      {
        /* !Pseudo:  Update  Ram block state to valid and changed             */
        NvM_astrAdminBlock[BlockId].u8State = u8VALID_CHANGED;

        #if (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)
        /* !Pseudo: If Calc Ram Block CRC is configured for this block        */
/* !Trace_To        : GSCSW-NVM-SDD-001-0123                                  */
        if (NvM_akstreBlockDescriptor[BlockId].bCalcRamBlockCrc == (boolean)TRUE)
        {
          /* !Pseudo: Enqueue the block in the Background Queue               */
          NvM_vidEnqInBGndCrcQ(BlockId);
        }
        #endif /* (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U)                          */
      }
      /* !Pseudo: Else  (BlockChanged=FALSE)                                  */
      else
      {
        /* !Pseudo:  Update  Ram block state to valid and unchanged           */
        NvM_astrAdminBlock[BlockId].u8State = u8INVALID;
      }
      u8ReturnValue = E_OK;
    }
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /* (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) */

/******************************************************************************/
/* !Description : API to set the lock status of a permanent RAM block of an
                  NVRAM block.                                                */
/* !Trace_To        : GSCSW-NVM-SDD-001-0375                                  */
/* !Comment   :  Request is accepted or not                                   */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockLockStatus
(
  NvM_BlockIdType BlockId,
  boolean BlockLocked
)
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)
  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0329                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8BLOCK_LOCK_STAT_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0331                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8BLOCK_LOCK_STAT_ID, NVM_E_PARAM_BLOCK_ID);
  }

  /* !Pseudo: Else if identified block is already pending                     */
  else if (bIS_BLOCK_PENDING(BlockId))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0590                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8BLOCK_LOCK_STAT_ID, NVM_E_BLOCK_PENDING);
  }

  /* !Pseudo: Else if identified block is configured to be write once only.   */
  else if(NvM_akstreBlockDescriptor[BlockId].bWriteBlockOnce
        == (boolean)TRUE)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0330                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8BLOCK_LOCK_STAT_ID, NVM_E_BLOCK_CONFIG);
  }

  /* !Pseudo: Else                                                            */
  else
  /* !Pseudo: #Else                                                           */
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* !Pseudo: If referenced block is associated to a permanent RAM
    block                                                                     */
    if( NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress != NULL_PTR )
    {
      /* !Pseudo: Set the lock state of the block accroding to the passed
                  parameter                                                   */
		if(BlockLocked == TRUE)
		{
		  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
          /*              during integration phase                                    */
          /* PRQA S 3141 ++                                                           */
		SchM_Enter_NvM_NVM_ACCESS_001();
        u8SET_GENERAL_BLOCK(BlockId, u8BLOCK_LOCKED);
		SchM_Exit_NvM_NVM_ACCESS_001();
        /* PRQA S 3141 --                                                          */
		}
		else
		{
		  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
          /*              during integration phase                                    */
          /* PRQA S 3141 ++                                                           */
		SchM_Enter_NvM_NVM_ACCESS_001();
        u8CLEAR_GENERAL_BLOCK(BlockId, u8BLOCK_UNLOCKED);
		SchM_Exit_NvM_NVM_ACCESS_001();
         /* PRQA S 3141 --                                                           */
		}
      /* !Pseudo: Set the return value to E_OK                                */
      u8ReturnValue = E_OK;
    }
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}


#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API  to copy the data of the NV block to its corresponding  */
/*                RAM block.                                                  */
/* !Comment   :  Request is accepted or not                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0049                                  */


/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
  NvM_BlockIdType BlockId,
  P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
)
{
  /* !Pseudo: Define a local variable for the return value                    */
  Std_ReturnType u8ReturnValue;

  /* !Pseudo: local variable that stores the type of memory to read.          */
  uint8 u8ReadMemory;

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: Initialize return value to NOT OK                               */
  u8ReturnValue = E_NOT_OK;

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0333                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8READ_BLOCK_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0336                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8READ_BLOCK_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If no permanent RAM block is configured and the block doesn't
              use explicit synchronization and a NULL pointer is passed via the
              parameter NvM_DstPtr                                            */
  else if( (NvM_DstPtr == NULL_PTR) &&
   (NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress == NULL_PTR) &&
   (NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)FALSE))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0335                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8READ_BLOCK_ID, NVM_E_PARAM_ADDRESS);
  }
  /* !Pseudo: Else If the referenced block is locked and the permanent RAM
              address is passed                                               */
  /* !Trace_To        : GSCSW-NVM-SDD-001-0418, GSCSW-NVM-SDD-001-0414        */
  else if ( ( u8CHECK_GENERAL_BLOCK (BlockId, u8BLOCK_LOCKED) )
           && ((NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)FALSE)
              && (( NvM_DstPtr == NULL_PTR )
                 ||
                 (NvM_DstPtr == NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress)) ))

  {
    /* !Pseudo: Report to the DET                                             */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8READ_BLOCK_ID, NVM_E_BLOCK_LOCKED);
  }
  /* !Pseudo: Else If block uses sync. mechanism and a pointer is passed
              via parameter NvM_SrcPtr                                        */
  else if ((NvM_DstPtr != NULL_PTR) &&
          (NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)TRUE))
  {
    /* !Pseudo: Report to the DET                                             */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8READ_BLOCK_ID, NVM_E_POINTER_SYNC_USED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON)                                  */
  /* !Pseudo: #endif DET is enabled                                           */
  {
    /* !Pseudo: If the dataset index points in NV range                       */
    if(NvM_astrAdminBlock[BlockId].u8DataSetIndex  <
          NvM_akstreBlockDescriptor[BlockId].u8NvBlockNum)
    {
      u8ReadMemory = NvM_u8READ_BLOCK_ID;
    }
    /* !Pseudo: Else the dataset index should point in ROM range              */
    else
    {
      /* !Pseudo: In this case restoring defaults should be called            */
	  /* !Trace_To: GSCSW-NVM-SDD-001-0511                                      */
      u8ReadMemory = NvM_u8READ_BLK_DFT_DSET_ID;
    }
#if (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    /* !Pseudo: If the block uses sync. mechanism                             */
    if(NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism
             ==(boolean)TRUE)
    {
      /* !Pseudo:  Enqueue the job request in standard queue                  */
      /* !Pseudo:  Set Return Value to Enqueue Result                         */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0507                            */
      u8ReturnValue = u8ENQ_IN_STDJOBQ(u8ReadMemory, BlockId,
        NvM_au8RamMirrorBuffer);
    }
    /* !Pseudo: Else,                                                         */
    else
    {
#endif /*(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/
      /* !Trace_To        : GSCSW-NVM-SDD-001-0504                            */
      if(NvM_DstPtr != NULL_PTR)
      {
        /* !Pseudo:  Enqueue the job request in standard queue                */
        /* !Pseudo:  Set Return Value to Enqueue Result                       */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0506                            */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0507                            */
        u8ReturnValue = u8ENQ_IN_STDJOBQ(u8ReadMemory, BlockId, NvM_DstPtr);
      }
      /* !Trace_To        : GSCSW-NVM-SDD-001-0505                            */
      else
      {
        /* !Pseudo:  Enqueue the job request in standard queue                */
        /* !Pseudo:  Set Return Value to Enqueue Result                       */
        /* !Trace_To        : GSCSW-NVM-SDD-001-0507                          */
        u8ReturnValue = u8ENQ_IN_STDJOBQ(u8ReadMemory, BlockId,
          NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress);
      }
#if (NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
    }
#endif /*(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);

}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */



/******************************************************************************/
/* !Description : API to load and validate the content of configured permanent
                  RAM blocks during start-up                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0055, GSCSW-NVM-SDD-001-0564          */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_ReadAll (void)
{
  NvM_BlockIdType udtCounter;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBState 
             = &NvM_strMBJobBfr.u8State;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBErrorStatus 
             = &NvM_astrAdminBlock[udtMULTI_BLOCK_ID].u8ErrorStatus;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8CfgErrorStatus 
             = &NvM_astrAdminBlock[udtCONFIG_BLOCK_ID].u8ErrorStatus;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBu8JobID 
             = &NvM_strMBJobBfr.u8JobID;
  P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtBlockID 
             = &NvM_strMBJobBfr.udtBlockID;
			   
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0359                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
                NvM_u8READ_ALL_ID, NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  /* !Pseudo: #endif                                                          */
  {
    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented      */
    /*              during integration phase                                  */
    /*lint -save -vo -e960 -v                                                 */
    /*  !Pseudo: Open Critical Section                                        */
    SchM_Enter_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
    /* lint -restore                                                          */

    /*  !Pseudo: If a multi-block request is not already pending              */
    if(*pu8MBState == u8EMPTY)
    {
      /* !Pseudo: Tag reserved Multi-block Request and Config Id block state
      as pending                                                              */
      /*  !Trace_To: GSCSW-NVM-SDD-001-0575                                   */
      *pu8MBErrorStatus = u8PEND_MULTIBLK_JOB;
      *pu8CfgErrorStatus = u8PEND_MULTIBLK_JOB;

      /* This part is protected to prevent from accepting a SB Job then marking
       it as skipped                                                          */

      /* This part is inserted here not in the Main Fn as the Write All
      because it is a Requirement.                                            */

      /*  !Pseudo:
                  Tag all NVRAM blocks as pending for MB job, if they are:
				  , if they are :
                  - Configured as permanent
                  - Configured as selected for Read All
                  - Not locked                                                */
      /*  !Trace_To: GSCSW-NVM-SDD-001-0427, GSCSW-NVM-SDD-001-0414           */
      for(udtCounter = (udtCONFIG_BLOCK_ID + (NvM_BlockIdType)1); udtCounter <=
        (NvM_BlockIdType)NVM_udtNUM_OF_NVRAM_BLOCKS; udtCounter++)
      {
        if( (NvM_akstreBlockDescriptor[udtCounter].
                                      bSelectBlockForRdAll == (boolean)TRUE) &&
            (NvM_akstreBlockDescriptor[udtCounter].
                                      pvidRamBlockDataAddress != NULL_PTR)    &&
		   (!( u8CHECK_GENERAL_BLOCK (udtCounter, u8BLOCK_LOCKED) )))
        {
          NvM_astrAdminBlock[udtCounter].u8ErrorStatus = u8PEND_MULTIBLK_JOB;
        }
          /* Don't mark a pending immediate write block as skipped. This will
          happen if the user called any API (Std/Imdt) before calling the
          ReadAll (Wrong usage)                                               */
        else
           #if (NVM_JOB_PRIORITIZATION == STD_ON) && \
               (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
        if (!(bIS_BLOCK_PENDING(udtCounter)))
           #endif
        {
          NvM_astrAdminBlock[udtCounter].u8ErrorStatus = NVM_REQ_BLOCK_SKIPPED;
        }
           #if (NVM_JOB_PRIORITIZATION == STD_ON              ) && \
               (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
        else
        {
        }
           #endif
      }

      /* Reset the block ID to config block ID so the read all process shall
      begin searching for pending blocks starting from it                     */
      *pudtBlockID = udtCONFIG_BLOCK_ID;
      /*  !Pseudo: Push request in multi-block request buffer and update
      buffer state                                                            */
      *pu8MBu8JobID = NvM_u8READ_ALL_ID;
      /* The update of the state should be here at the end of the API to
        prevent the Mfn from begin serving the MB request before finishing
        the API                                                               */
      /*  !Trace_To: GSCSW-NVM-SDD-001-0565                                   */
      *pu8MBState = u8STARTED;

      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */

      /*  !Pseudo: Close Critical Section                                     */
      SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                       */
    }
    else
    {
      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */

      /* !Pseudo: Close Critical Section                                      */
      SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                       */

      #if (NVM_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
                  NvM_u8READ_ALL_ID, NVM_E_BLOCK_PENDING);
      #endif
    }
  }
}

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description : API to copy the data of the RAM block to its corresponding  */
/*                NV block.                                                   */
/* !Trace_To        : GSCSW-NVM-SDD-001-0099, GSCSW-NVM-SDD-001-0530,
                      GSCSW-NVM-SDD-001-0547                                  */
/******************************************************************************/
 FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
 NvM_BlockIdType BlockId,
 P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
)
{
/* !Deviation : inhibit MISRA rule [625]: because PC-Lint doesn't understand  */
/*              the usage of __far keyword in the same way as the compiler    */
/*lint -save -vo -e625 -v                                                     */

  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
/* PRQA S 8018,8318,8518 ++ */
  P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) pku8SourcePtr;
/* PRQA S 8018,8318,8518 -- */
/*lint -restore                                                               */

  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0337                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
             NvM_u8WRITE_BLOCK_ID, NVM_E_NOT_INITIALIZED);
  }

  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0340                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
             NvM_u8WRITE_BLOCK_ID, NVM_E_PARAM_BLOCK_ID);
  }
  /* !Pseudo: Else If no permanent RAM block is configured and a NULL pointer
  is passed via the parameter NvM_SrcPtr                                      */
  else if ( (NvM_SrcPtr == NULL_PTR) &&
  (NvM_akstreBlockDescriptor[BlockId].pvidRamBlockDataAddress == NULL_PTR) &&
  (NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)FALSE))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0339                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8WRITE_BLOCK_ID, NVM_E_PARAM_ADDRESS);
  }
  /* !Pseudo: Else If block uses sync. mechanism and a pointer is passed
              via parameter NvM_SrcPtr                                        */
  else if ((NvM_SrcPtr != NULL_PTR) &&
          (NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)TRUE))
  {
    /* !Pseudo: Report to the DET                                             */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
      NvM_u8WRITE_BLOCK_ID, NVM_E_POINTER_SYNC_USED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON)                                  */
  /* !Pseudo: #endif                                                          */
  {
    /* !Pseudo: If identified block is write protected or
                a ROM block of a dataset NVRAM block is referenced            */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0533, GSCSW-NVM-SDD-001-0535      */
    if((u8CHECK_GENERAL_BLOCK (BlockId, u8PROTECTION_ENABLE))
       || ( (NvM_akstreBlockDescriptor[BlockId].u8BlockManagementType
                                                  == NVM_BLOCK_DATASET) &&
            (NvM_astrAdminBlock[BlockId].u8DataSetIndex >=
                       NvM_akstreBlockDescriptor[BlockId].u8NvBlockNum) ))
    {
      /* !Pseudo: Report error to the DEM                                     */
      /* !Trace_To: GSCSW-NVM-SDD-001-0309                                    */
      Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED,DEM_EVENT_STATUS_FAILED);
      /* !Pseudo: #endif                                                      */
    }
    else
    {
#if(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
      /* !Pseudo: If block uses sync. mechanism                               */
      if(NvM_akstreBlockDescriptor[BlockId].bBlkUseSyncMechanism ==(boolean)TRUE)
      {
        pku8SourcePtr = NvM_au8RamMirrorBuffer;
      }
      else
      {
#endif /*(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/
        if(NvM_SrcPtr != NULL_PTR)
        {
          /* !Trace_To        : GSCSW-NVM-SDD-001-0532                        */
          pku8SourcePtr = NvM_SrcPtr;
        }
        else
        {
          /* !Trace_To        : GSCSW-NVM-SDD-001-0531                        */
          pku8SourcePtr = NvM_akstreBlockDescriptor[BlockId].
            pvidRamBlockDataAddress;
        }
#if(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)
      }
#endif /*(NVM_u16RAM_MIRROR_BUF_SIZE !=0U)*/

      #if (NVM_JOB_PRIORITIZATION == STD_ON)
      /* !Pseudo: If Immediate Job                                            */
      if(NvM_akstreBlockDescriptor[BlockId].u8BlockJobPriority
                == u8IMMEDIATE_PRIORITY)
      {
        /* !Pseudo:  Enqueue the job request in immediate queue               */
        /* !Pseudo:  Set Return Value to Enqueue Result                       */

        /* !Deviation : inhibit MISRA rule [0311]: because the Queue can hold */
        /*              Source (constant) and destination pointers (Modifiable).*/
        /* PRQA S 0311 ++                                                     */
        /* !Deviation : inhibit MISRA rule [3353]: because pku8SourcePtr will */
        /*              will always be set even if NVM_u16RAM_MIRROR_BUF_SIZE */
        /*              = 0                                                   */
       /* PRQA S 3353 ++                                                      */
       /* !Trace_To        : GSCSW-NVM-SDD-001-0534                           */
        u8ReturnValue = u8EnqInImdtJobQ(BlockId,
           (P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA))pku8SourcePtr);
        /* PRQA S 0311 --                                                     */
        /* PRQA S 3353 --                                                     */
      }
       /* !Pseudo: Else (Standard Job)                                        */
      else
      #endif /*  (NVM_JOB_PRIORITIZATION == STD_ON)                           */
      {

        /* !Pseudo:  Enqueue the job request in standard queue                */
        /* !Pseudo:  Set Return Value to Enqueue Result                       */

        /* !Deviation : inhibit MISRA rule [0311]: because the Queue can hold */
        /*              Source (constant) and destination pointers(Modifiable)*/
        /* PRQA S 0311 ++                                                     */
        /* !Trace_To        : GSCSW-NVM-SDD-001-0534                          */
        u8ReturnValue = u8ENQ_IN_STDJOBQ(NvM_u8WRITE_BLOCK_ID, BlockId,
           (P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)) pku8SourcePtr);
        /* PRQA S 0311 --                                                     */
      }
    }
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)                    */

/******************************************************************************/
/* !Description : API to synchronize the contents of permanent RAM blocks to  */
/*                their corresponding NV blocks on shutdown.                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0054, GSCSW-NVM-SDD-001-0552          */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_WriteAll (void)
{
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBState 
             = &NvM_strMBJobBfr.u8State;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBErrorStatus 
             = &NvM_astrAdminBlock[udtMULTI_BLOCK_ID].u8ErrorStatus;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBu8JobID 
             = &NvM_strMBJobBfr.u8JobID;
  P2VAR(NvM_BlockIdType, AUTOMATIC, NVM_APPL_DATA) pudtBlockID 
             = &NvM_strMBJobBfr.udtBlockID;
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

   /* !Pseudo: If NVM is uninitialized                                        */
  if (NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0360                                      */
    (void)Det_ReportError(NVM_MODULE_ID,NvM_u8INSTANCE_ID,
    NvM_u8WRITE_ALL_ID,NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON)                                  */
  /* !Pseudo: #endif                                                          */
  {
    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */

    /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented      */
    /*              during integration phase                                  */
    /*lint -save -vo -e960 -v                                                 */

    /*  !Pseudo: Open Critical Section                                        */
   SchM_Enter_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
    /* lint -restore                                                          */

    /*  !Pseudo: If a multi-block request is not already pending              */
    /* !Trace_To: GSCSW-NVM-SDD-001-0553                                      */
    if (*pu8MBState == u8EMPTY)
    {

      /*  !Pseudo: Tag reserved Multi-block Request block state as pending    */
      *pu8MBErrorStatus = u8PEND_MULTIBLK_JOB;

      /*  !Pseudo: Reset cancellation flag                                    */
      NvM_bCancelWrtAllReq = (boolean)FALSE;

      /*  !Pseudo: Reset the block ID to multi block ID so the write all
      process shall begin searching for pending blocks starting from it       */
      *pudtBlockID = udtMULTI_BLOCK_ID;

      /*  !Pseudo: Push request in multi-block request buffer and update buffer
      state                                                                   */
      *pu8MBu8JobID = NvM_u8WRITE_ALL_ID;
      /* The update of the state should be here at the end of the API to
      prevent the Mfn from begin serving the MB request before finishing
      the API and also to prevent Cancel write all from being accepted
      before finishing this API                                               */
      *pu8MBState = u8PEND_BUTNOT_STARTED;

      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */

      /*  !Pseudo: Close Critical Section                                     */
      SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                       */
    }
    else
    {
      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 3141 ++                                                       */

      /* !Pseudo: Close Critical Section                                      */
      SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                       */

      /* !Pseudo: #if DET is enabled                                          */
      #if (NVM_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
                 NvM_u8WRITE_ALL_ID, NVM_E_BLOCK_PENDING);
      /* !Pseudo: EndIf */
      #endif
    }
  }
}

/******************************************************************************/
/* !Description :  API  to cancel a running NvM_WriteAll  request.            */
/* !Trace_To        : GSCSW-NVM-SDD-001-0053, GSCSW-NVM-SDD-001-0462          */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void)
{

  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBState 
             = &NvM_strMBJobBfr.u8State;
  P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) pu8MBu8JobID 
             = &NvM_strMBJobBfr.u8JobID;
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0350                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
        NvM_u8CANCEL_WRITE_ALL_ID, NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON)                                  */
  /* !Pseudo: #endif                                                          */
  {
    /* !Pseudo: Open Critical Section                                         */
    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */

    /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented      */
    /*              during integration phase                                  */
    /*lint -save -vo -e960 -v                                                 */

   SchM_Enter_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
    /* lint -restore                                                          */

    /* !Pseudo: If a Write All multi-block request is pending and Cancel is not
    requested without serving it                                              */
    /* !Trace_To        : GSCSW-NVM-SDD-001-0464                              */
    if( (NvM_bCancelWrtAllReq == (boolean)FALSE)
        && (*pu8MBState != u8EMPTY)
        && (*pu8MBu8JobID == NvM_u8WRITE_ALL_ID) )
    {
      /* !Pseudo: Raise cancellation of Write All Flag                        */
      /* !Trace_To        : GSCSW-NVM-SDD-001-0463                              */
      NvM_bCancelWrtAllReq = (boolean)TRUE;
    }

    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */

    /* !Pseudo: Close MB Buffer Critical Section                              */
    SchM_Exit_NvM_NVM_ACCESS_001();
    /* PRQA S 3141 --                                                         */
  }

}

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/******************************************************************************/
/* !Description :  API  to cancel all jobs pending for a NV block.            */
/* !Trace_To        : GSCSW-NVM-SDD-001-0376                                  */
/******************************************************************************/
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs( NvM_BlockIdType BlockId )
{
  /* !Pseudo: Set return value to NOT OK                                      */
  Std_ReturnType u8ReturnValue = E_NOT_OK;
  /* !Pseudo: #if DET is enabled                                              */
  #if (NVM_DEV_ERROR_DETECT == STD_ON)

  /* !Pseudo: If NVM is uninitialized                                         */
  if(NvM_enueMainFnState == NvM_MFN_NOT_INIT)
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0354                                      */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
        NvM_u8CANCEL_JOB_BLOCK_ID, NVM_E_NOT_INITIALIZED);
  }
  /* !Pseudo: Else If BlockId input parameter is invalid                      */
  else if(!(bIS_BLKID_INUSERRANGE(BlockId)))
  {
    /* !Pseudo: Report to the DET                                             */
	/* !Trace_To: GSCSW-NVM-SDD-001-0355                                        */
    (void)Det_ReportError(NVM_MODULE_ID, NvM_u8INSTANCE_ID,
        NvM_u8CANCEL_JOB_BLOCK_ID, NVM_E_PARAM_BLOCK_ID);
  }

  /* !Pseudo: Else                                                            */
  else
  #endif /* (NVM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* !Pseudo: If the block is pending in SB job                             */
    if(NvM_astrAdminBlock[BlockId].u8ErrorStatus == u8PEND_SINGLEBLK_JOB)
    {
      /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
      /*              during integration phase                                  */
      /* PRQA S 3141 ++                                                         */
      /* !Deviation : Inhibit MISRA rule [960]: Macro is to be implemented      */
      /*              during integration phase                                  */
      /*lint -save -vo -e960 -v                                                 */
      SchM_Enter_NvM_NVM_ACCESS_001();
      /* !Trace_To: GSCSW-NVM-SDD-001-0364                                      */
	   u8SET_GENERAL_BLOCK(BlockId, u8BLOCK_CANCELED);
	    NvM_bAnyCancelJobReq = (boolean)TRUE;
      SchM_Exit_NvM_NVM_ACCESS_001();
      /* PRQA S 3141 --                                                         */
      /*lint -restore                                                           */
      u8ReturnValue = E_OK;
    }
  }
  /* !Pseudo: Return Value                                                    */
  return(u8ReturnValue);
}
#endif /*(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) */

/******************************************************************************/
/* !Description : Main cyclic function that performs the processing of NVRAM
                  Manager jobs                                                */
/* !Trace_To        : GSCSW-NVM-SDD-001-0057                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0072                                  */
/* !Trace_To        : GSCSW-NVM-SDD-001-0490                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) NvM_MainFunction(void)
{

  /* !Pseudo: Check Main Fn State                                             */
  switch(NvM_enueMainFnState)
  {
    /* !Trace_To: GSCSW-NVM-SDD-001-0493                                      */
    /* !Pseudo: Case (Non Init)                                               */
    case NvM_MFN_NOT_INIT:
      /* !Pseudo: Do Nothing in this main function cycle                      */
      break;

    /* !Pseudo: Case (Jobs Scanning)                                          */
    case NvM_MFN_JOBS_SCAN:

#if ( NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1 )
      /* !Pseudo: If any job is requested to be canceled                      */
      if (NvM_bAnyCancelJobReq == (boolean)TRUE)
	    {
        /* !Pseudo: Scan for Jobs in different Queues and cancel the blocks
	                  requested by NvM_CancelJobs                               */
        NvM_vidScanThenCancelJobs();
	    }
#endif /*( NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1 ) */

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
          (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
       /* !Pseudo: Run the Back ground CRC Process                            */
       vidBckGndCrcPrcs();
#endif

      /* !Pseudo: Scan for Jobs in different Queues then initialize and start
      the corresponding process                                               */
      vidMfnJobsScanThenStart();
      break;

#if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)

  #if (NVM_JOB_PRIORITIZATION == STD_ON)
    /* !Pseudo: Case (Immediate SB Job)                                       */


    case NvM_MFN_IMDT_SB_JOB:
      #if  (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
       /* !Pseudo: Run the Back ground CRC Process                            */
       vidBckGndCrcPrcs();
      #endif
      /* !Pseudo: Run the immediate write process                             */
      vidMFNIMDTSBJOB();
      break;
  #endif /* (NVM_JOB_PRIORITIZATION == STD_ON)                                */

    /* !Pseudo: Case (Standard SB Job)                                        */

    case NvM_MFN_STD_SB_JOB:
      #if  (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
       /* !Pseudo: Run the Back ground CRC Process                            */
       vidBckGndCrcPrcs();
      #endif
      #if (NVM_JOB_PRIORITIZATION == STD_ON)
        /* !Pseudo: If Imdt Queue is not Empty                                */
        if (bIsImdtJobQEmpty() != (boolean)TRUE)
        {
           /* !Pseudo: Crash SB job                                           */
           /* !Trace_To        : GSCSW-NVM-SDD-001-0024                       */
           /* !Trace_To        : GSCSW-NVM-SDD-001-0536                       */
           NvM_vidMfnCrashSBJob();
           vidMfnJobsScanThenStart();
        }
        else
      #endif /* (NVM_JOB_PRIORITIZATION == STD_ON)                            */
        {
             /* !Pseudo: Run the corresponding standard process               */
             NvM_vidMfnStdSBJob();
        }
      break;
#endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)                    */

    /* !Pseudo: Case (Multi Block Job)                                        */


    case NvM_MFN_MB_JOB:
      #if  (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && \
           (NVM_u8SIZE_BCKGND_CRC_QUEUE > 0U      )
       /* !Pseudo: Run the Back ground CRC Process                            */
       /* !Trace_To: GSCSW-NVM-SDD-001-0553                                   */
       vidBckGndCrcPrcs();
      #endif

    #if (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
        (NVM_JOB_PRIORITIZATION == STD_ON)
       /* !Pseudo: If Imdt Job is Queued                                      */
       /* !Trace_To: GSCSW-NVM-SDD-001-0494                                   */
      if (bIsImdtJobQEmpty() != (boolean)TRUE)
      {
         /* !Trace_To: GSCSW-NVM-SDD-001-0495                                 */
         /* !Pseudo: Freeze the MB job                                        */
         NvM_vidMfnFreezeMBJob();
         /* !Pseudo: If MB job is frozen, start the immediate job immediatly */
         if (NvM_enueMainFnState == NvM_MFN_JOBS_SCAN)
         {
           vidMfnJobsScanThenStart();
         }
      }
      /* !Pseudo: Else                                                        */
      else
    #endif /* (NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) &&
              (NVM_JOB_PRIORITIZATION == STD_ON) */
      {
        /* !Pseudo: Run the corresponding multi block process                 */
        NvM_vidMfnMBJob();
      }
      break;

    /* !Deviation : Inhibit MISRA rule [2018]: Reason: Another Misra Rule     */
    /* PRQA S 2018 ++                                                         */

    default:
      break;
    /* PRQA S 2018 --                                                         */

  }
}


#if (NVM_POLLING_MODE == STD_OFF)
/******************************************************************************/
/* !Description : Function to be used by the underlying memory abstraction to
                  signal end of job without error                             */
/* !Trace_To        : GSCSW-NVM-SDD-001-0058                                  */

/******************************************************************************/
FUNC(void, NVM_CODE) NvM_JobEndNotification(void)
{
  /* !Pseudo:  Set the MemIf Job End Flag to OK                               */
/* !Trace_To        : GSCSW-NVM-SDD-001-0025                                  */
  NvM_udtMemIfJobEndClBck = MEMIF_JOB_OK;
}

/******************************************************************************/
/* !Description : Function to be used by the underlying memory abstraction to
                  signal end of job with error.                               */
/* !Trace_To        : GSCSW-NVM-SDD-001-0059                                  */

/******************************************************************************/
FUNC(void, NVM_CODE) NvM_JobErrorNotification(void)
{
  /* !Pseudo:  Set the MemIf Job End Flag to Failed                           */
/* !Trace_To        : GSCSW-NVM-SDD-001-0025                                  */
  NvM_udtMemIfJobEndClBck = MEMIF_JOB_FAILED;
}
#endif /* (NVM_POLLING_MODE == STD_OFF) */

/* PRQA S 0850 --                                                             */
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

/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define NVM_STOP_SEC_CODE
#include "MemMap.h"
/*lint -restore                                                               */
/* PRQA L:L1                                                                  */


/* !Deviation : inhibit MISRA rule [750]: because local non referenced macro  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [766] because inclusion of Memmap is       */
/*              is according to AUTOSAR specifications                        */
/*lint -vo -e750 -e766 -v                                                     */


/*==== End of file ===========================================================*/
