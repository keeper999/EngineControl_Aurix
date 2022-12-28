/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR R4.0 component                */
/*                                                                            */
/*!Module          : LinIf_PBcfg                                             */
/*!Description     : The LinIf Post-Build time configuration values          */
/*                                                                            */
/*!\File             LinIf_PBcfg.c                                           */
/* \par              The LinIf Post-Build time configuration values          */
/*!Scope           : Private                                                 */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.6      $$Author::   mnabil         $$Date::   Nov 02 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0838]: Multiple Inclusion prevention      */
/*              macros solve this issue                                       */
/* PRQA S 0838 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0850]: The value for the macros are       */
/*              redefined in the QAC for comptability with ANSI C             */
/* PRQA S 0850 L1                                                             */
/*!Deviation : Inhibit MISRA rule [2213, 3132]: Configuration file, no need  */
/*              to do this.                                                   */
/* PRQA S 2213, 3132 L1                                                       */
/*!Deviation : Inhibit MISRA rule [0862]: The MemMap.h is used to assign     */
/*              memory segments                                               */
/* PRQA S 0862 L1                                                             */

#include "LinIf_PBcfg.h"
#include "LinSM_Cbk.h"
#include "PduR_LinIf.h"


#include "LinIf_Lcfg.h"

#if (LinIf_u8TP_SUPPORTED == STD_ON)
#include "PduR_LinTp.h"
#endif


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description   The number of Tx Pdus controlled by the Lin Interface      */
/*   \Range         0..65535                                                  */
/* Configuration: Number of all LinIfTxPdus */
#define u16NUMBER_OF_TX_PDUS                            1U
/******************************************************************************/
/*! \Description   The number of Rx Pdus controlled by the Lin Interface      */
/*   \Range         0..65535                                                  */
/* Configuration: Number of all LinIfRxPdus */
#define u16NUMBER_OF_RX_PDUS                            2U 
/******************************************************************************/
/*! \Description    The number of Frames that have Dem error LINIF_E_RESPONSE 
                    configured*/
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfFrames that have 
                    LinIfFrameDemEventParameterRefs sub-container             */
#define u16NUMBER_OF_DEM_E_RES                          0U 
/******************************************************************************/
/*! \Description    The number of Frames that have LinIfFixedFrameSdu 
                    configured */
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfFrames that have 
                    LinIfFixedFrameSdu sub-container                          */
#define u16NUMBER_OF_FIXED_FRMS                         0U
/******************************************************************************/
/*! \Description    The number of bytes in a fixed frame configured */
/*   \Range         8                                                  */
/* Configuration:   Not configurable                          */
#define u16BYTES_IN_FIXED_FRM                           8U
/******************************************************************************/
/*! \Description    The number of Substitution frames configured for all 
                    sporadic slots */
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfSubstitutionFrame containers configured*/
#define u16NUMBER_OF_SUBST_FRMS                         0U
/******************************************************************************/
/*! \Description    The number of LinIfFrames Configured */
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfFrame containers configured*/
#define u16NUMBER_OF_FRAMES                             3U
/******************************************************************************/
/*! \Description    The number of frames referenced in all 
                    LinIfSubstitutionFrameRef */
/*   \Range         0..65535                                                  */
/* Configuration:   The number of frames referenced in all 
                    LinIfSubstitutionFrameRef*/
#define u16NUMBER_OF_SPOR_FRMS                          0U
/******************************************************************************/
/*! \Description    The number of LinIfScheduleTables Configured */
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfScheduleTable containers configured*/
#define u16NUMBER_OF_SCH_TAB                            1U
/******************************************************************************/
/*! \Description    The number of LinIfScheduleEntries Configured */
/*   \Range         0..65535                                                  */
/* Configuration:   Number of all LinIfScheduleEntry containers configured*/
#define u16NUMBER_OF_SCH_ENT                            21U


#if (LinIf_u8TP_SUPPORTED == STD_ON)
/******************************************************************************/
/*! \Description   The number of Tx Nsdus controlled by the Lin Tp            */
/*   \Range         0..65535                                                  */
/* Configuration: LinTpNumberOfTxNSdu */
#define u16NUMBER_OF_TX_NSDUS                            U
/******************************************************************************/
/*! \Description   The number of Rx Nsdus controlled by the Lin Tp            */
/*   \Range         0..65535                                                  */
/* Configuration: LinTpNumberOfRxNSdu */
#define u16NUMBER_OF_RX_NSDUS                            U
#endif


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
/* PRQA L:L2  */

#if (LinIf_u8NUMBER_OF_CHANNELS > 0U)
  
/* Represents the Post-Build time Conf of LinIfChannel */
static CONST(LinIf_tstrChannelPBConf, LINIF_CALIB_CONST) akstrChannelsPB[1] = 
{
    
    {
        /* Index in the array 0,1,2,3... (incremental) */
        0,                      /* u8ChannelIndx            */
        
        /* Number of LinIfScheduleTable attache to this LinIfChannel*/
        1,                      /* u8NumberOfSchTabs        */

        /* Start index of LinIfScheduleTable attached to this LinIfChannel in 
           akstrScheduleTables*/
        0,                      /* u16ScheduleTablesIndex   */

        /* LinIfScheduleRequestConfirmationUL */
        LinSM_ScheduleRequestConfirmation,       /* pfvidSchReqConfrm        */

        /* LinIfGotoSleepConfirmationUL */
        LinSM_GotoSleepConfirmation,    /* pfvidGotoSleepConfrm     */

        /* LinIfWakeupConfirmationUL */
        LinSM_WakeupConfirmation,       /* pfvidWakeUpConfrm        */

        /* Number of LinIfFrame containers attached to this LinIfChannel */
        3,                      /* u8NumberOfFrames         */

        /* Start index of LinIfFrame containers attached to this LinIfChannel
           in staticakstrFrames */
        0,                      /* u16FramesIndex           */
#if (LinIf_u8TP_SUPPORTED == STD_ON)        
        /* Start index of LinTpTxNSdu in staticakstrTxNsdus which have the 
           LinTpTxNSduChannelRef set to u8ChannelIndx of this LinIfChannel */
        0,                      /* u16TpTransNsdusIndex     */
        /* Number of LinTpTxNSdu in akstrTxNsdus which have the 
           LinTpTxNSduChannelRef set to u8ChannelIndx of this LinIfChannel */
        0,                      /* u16NumberOfTransTp       */
        /* Start index of LinTpRxNSdu in akstrRecNsdus which have the 
           LinTpRxNSduChannelRef set to u8ChannelIndx of this LinIfChannel */
        0,                      /* u16TpRecNsdusIndex       */
        /* Number of LinTpRxNSdu in akstrRecNsdus which have the 
           LinTpRxNSduChannelRef set to u8ChannelIndx of this LinIfChannel */
        0,                      /* u16NumberOfRecTp         */
#endif
        /* Ceiling((((48+ (14*(8+1)))*(1000000/LinIfChannelBaudRate))
            /1000)/LinIfTimeBase in milliseconds) minimum 1*/
        4,                      /* u8GotoSleepCmdTime       */
        /* Ceiling(5/LinIfTimeBase in milliseconds) minimum 1 */
        1                       /* u8WakeupCmdTime          */
    }
};
#endif


#if (u16NUMBER_OF_TX_PDUS > 0U)  
/* Represents all LinIfTxPdu parameter*/
static CONST(LinIf_tstrTxPduParams, LINIF_CALIB_CONST) akstrTxPdusParams[1] = 
{
    {   
        /* Combination of LinIfUserTxUL, pfudtTxTriggerTransmit, and 
           LinIfTriggerTransmitUL*/
        PduR_LinIfTriggerTransmit,        /* pfudtTxTriggerTransmit */

        /* Combination of LinIfUserTxUL and pfvidTxConfirmationUL */
        PduR_LinIfTxConfirmation,        /* pfvidTxConfirmationUL  */

        /* LinIfTxPduId  */
        0,                      /* udtLinIfTxPduId        */

        /* udtLinIfTxPduRef */
        0                      /* udtLinIfTxPduRef       */
    }
};
#endif

#if (u16NUMBER_OF_RX_PDUS > 0U)
/* Represents all LinIfRxPdu parameters */

static CONST(LinIf_tstrRxPduParams, LINIF_CALIB_CONST) akstrRxPdusParams[2] = 
{
    {
        /* Combination of LinIfUserRxIndicationUL and pfvidRxIndication */
        PduR_LinIfRxIndication,     /* pfvidRxIndication */

        /* udtLinIfRxPduRef */
        0                      /* udtLinIfRxPduRef  */
    },
    {
        /* Combination of LinIfUserRxIndicationUL and pfvidRxIndication */
        PduR_LinIfRxIndication,     /* pfvidRxIndication */

        /* udtLinIfRxPduRef */
        1                      /* udtLinIfRxPduRef  */
    }
};
#endif

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
/* PRQA L:L2  */


#if (u16NUMBER_OF_DEM_E_RES > 0U)
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_START_SEC_CALIB_CONST_16
#include "Memmap.h"

/* PRQA L:L2  */

/* Represents all LinIfFrameDemEventParameterRefs*/

static CONST(Dem_EventIdType, LINIF_CALIB_CONST) audtDemEventIds[3] = 
{
    0,                                               /* LINIF_E_RESPONSE */
    0,                                               /* LINIF_E_RESPONSE */
    0                                               /* LINIF_E_RESPONSE */
    
};

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"
/* PRQA L:L2  */

#endif

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_START_SEC_CALIB_CONST_8
#include "Memmap.h"
/* PRQA L:L2  */

#if (u16NUMBER_OF_FIXED_FRMS > 0U)
/* Configuration: Represents all LinIfFixedFrameSdu 
                  the value of a byte whose position is 
                  LinIfFixedFrameSduBytePos = LinIfFixedFrameSduByteVal */


static CONST(uint8, LINIF_CALIB_CONST) aku8FixedFrames[0][8] =
{
};
#endif

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_STOP_SEC_CALIB_CONST_8
#include "Memmap.h"
/* PRQA L:L2  */


#if (u16NUMBER_OF_SPOR_FRMS > 0U)
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_START_SEC_CALIB_DATA_BOOLEAN
#include "Memmap.h"
/* PRQA L:L2  */

/* the size of this array is equal to the number of frames referenced in all 
   LinIfSubstitutionFrameRef */
static VAR(boolean, LINIF_CALIB_DATA) LinIf_abSporadicFrameFlags[0] =
{
    
};

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_STOP_SEC_CALIB_DATA_BOOLEAN
#include "Memmap.h"
/* PRQA L:L2  */
#endif



/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_START_SEC_CALIB_CONST_16
#include "Memmap.h"
/* PRQA L:L2  */



static CONST(uint16, LINIF_CALIB_CONST) aku16TxMappingTable[1] =
{
  
    /*CDE_ALT*/
    0,
        
};


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"
/* PRQA L:L2  */



/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
/* PRQA L:L2  */
#if (u16NUMBER_OF_FRAMES > 0U)
/* Represents all LinIfFrame */


static CONST(LinIf_tstrFrame, LINIF_CALIB_CONST) akstrFrames[3] =
{
    
    /*CDE_ALT*/
    {
        /* LinIfPid */
        41,                              /* u8Pid                */

        /* LinIfFrameDemEventParameterRefs */
        NULL_PTR,            /* pkudtLinIf_E_Response*/
        
        /* LinIfLength */
        4,                              /* u8Length             */

        /* Ceiling((((48+ (14*(LinIfLength+1)))*(1000000/LinIfChannelBaudRate))
           /1000)/LinIfTimeBase in milliseconds)*/
        3,                              /* u8MaxFrameTime       */

        /* LinIfFrameType */
        LinIf_UNCONDITIONAL,            /* enuFrameType         */

        /* LinIfChecksumType */
        LinIf_CLASSIC,                  /* enuChecksumType      */

        /* Names of choices of LinIfPduDirection */
        LinIf_TX_PDU,                   /* enuFrameDirection    */

        /* Pointer to an element in akstrTxPdusParams if 
           LinIfPduDirection = LinIfTxPdu else it is NULL_PTR*/
        &akstrTxPdusParams[0],          /* pkstrTxParams        */

        /* Pointer to an element in akstrRxPdusParams if 
           LinIfPduDirection = LinIfRxPdu else it is NULL_PTR*/
        NULL_PTR,                       /* pkstrRxParams        */

        /* Pointer to an element in apku8FixedFrames if LinIfPduDirection = 
           LinIfInternalPdu and LinIfFrameType is NOT LinIf_MRF or LinIf_SRF 
           else it is NULL_PTR*/
        NULL_PTR,                       /* pku8FixedFrameData   */

        /* Number of LinIfSubstitutionFrames attached to this frame if 
           LinIfFrameType = LinIf_SPORADIC */
        0,                              /* u8NumberOfSubFrames  */

        /* Index of LinIfSubstitutionFrames attached to this frame in the
           akstrSubstFrmArray if LinIfFrameType = LinIf_SPORADIC*/
        0,                              /* u16SubFramesIndex    */

        /* Flag set to one if if LinIfFrameType = LinIf_UNCONDITIONAL and
           this frame is referenced in any LinIfSubstitutionFrameRef */
        FALSE,                           /* bIsSporadic          */

        /* If bIsSporadic = true this value should be incremental */
        NULL_PTR,                              /* pkstrSporadic     */

        /* Index of LinIfSlave in LinIf_akstreSlaves where 
           LinIfResponseErrorFrameRef is this LinIfFrame - 
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        0xFF,                              /* u8ErrorSlaveIndex    */
          
        /* Index of LinIfSlave in LinIf_akstreSlaves where
           this frame is a node configuration cmd for it -
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        
        0xFF                            /* u8NCSlaveIdx         */
    },
    
    /*ETA_ALT1*/
    {
        /* LinIfPid */
        17,                              /* u8Pid                */

        /* LinIfFrameDemEventParameterRefs */
        NULL_PTR,            /* pkudtLinIf_E_Response*/
        
        /* LinIfLength */
        2,                              /* u8Length             */

        /* Ceiling((((48+ (14*(LinIfLength+1)))*(1000000/LinIfChannelBaudRate))
           /1000)/LinIfTimeBase in milliseconds)*/
        2,                              /* u8MaxFrameTime       */

        /* LinIfFrameType */
        LinIf_UNCONDITIONAL,            /* enuFrameType         */

        /* LinIfChecksumType */
        LinIf_CLASSIC,                  /* enuChecksumType      */

        /* Names of choices of LinIfPduDirection */
        LinIf_RX_PDU,                   /* enuFrameDirection    */

        /* Pointer to an element in akstrTxPdusParams if 
           LinIfPduDirection = LinIfTxPdu else it is NULL_PTR*/
        NULL_PTR,          /* pkstrTxParams        */

        /* Pointer to an element in akstrRxPdusParams if 
           LinIfPduDirection = LinIfRxPdu else it is NULL_PTR*/
        &akstrRxPdusParams[0],                       /* pkstrRxParams        */

        /* Pointer to an element in apku8FixedFrames if LinIfPduDirection = 
           LinIfInternalPdu and LinIfFrameType is NOT LinIf_MRF or LinIf_SRF 
           else it is NULL_PTR*/
        NULL_PTR,                       /* pku8FixedFrameData   */

        /* Number of LinIfSubstitutionFrames attached to this frame if 
           LinIfFrameType = LinIf_SPORADIC */
        0,                              /* u8NumberOfSubFrames  */

        /* Index of LinIfSubstitutionFrames attached to this frame in the
           akstrSubstFrmArray if LinIfFrameType = LinIf_SPORADIC*/
        0,                              /* u16SubFramesIndex    */

        /* Flag set to one if if LinIfFrameType = LinIf_UNCONDITIONAL and
           this frame is referenced in any LinIfSubstitutionFrameRef */
        FALSE,                           /* bIsSporadic          */

        /* If bIsSporadic = true this value should be incremental */
        NULL_PTR,                              /* pkstrSporadic     */

        /* Index of LinIfSlave in LinIf_akstreSlaves where 
           LinIfResponseErrorFrameRef is this LinIfFrame - 
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        0,                              /* u8ErrorSlaveIndex    */
        /* Index of LinIfSlave in LinIf_akstreSlaves where
           this frame is a node configuration cmd for it -
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        
        0xFF                            /* u8NCSlaveIdx         */
    },
    
    /*ETA_ALT2*/
    {
        /* LinIfPid */
        18,                              /* u8Pid                */

        /* LinIfFrameDemEventParameterRefs */
        NULL_PTR,            /* pkudtLinIf_E_Response*/
        
        /* LinIfLength */
        2,                              /* u8Length             */

        /* Ceiling((((48+ (14*(LinIfLength+1)))*(1000000/LinIfChannelBaudRate))
           /1000)/LinIfTimeBase in milliseconds)*/
        2,                              /* u8MaxFrameTime       */

        /* LinIfFrameType */
        LinIf_UNCONDITIONAL,            /* enuFrameType         */

        /* LinIfChecksumType */
        LinIf_CLASSIC,                  /* enuChecksumType      */

        /* Names of choices of LinIfPduDirection */
        LinIf_RX_PDU,                   /* enuFrameDirection    */

        /* Pointer to an element in akstrTxPdusParams if 
           LinIfPduDirection = LinIfTxPdu else it is NULL_PTR*/
        NULL_PTR,          /* pkstrTxParams        */

        /* Pointer to an element in akstrRxPdusParams if 
           LinIfPduDirection = LinIfRxPdu else it is NULL_PTR*/
        &akstrRxPdusParams[1],                       /* pkstrRxParams        */

        /* Pointer to an element in apku8FixedFrames if LinIfPduDirection = 
           LinIfInternalPdu and LinIfFrameType is NOT LinIf_MRF or LinIf_SRF 
           else it is NULL_PTR*/
        NULL_PTR,                       /* pku8FixedFrameData   */

        /* Number of LinIfSubstitutionFrames attached to this frame if 
           LinIfFrameType = LinIf_SPORADIC */
        0,                              /* u8NumberOfSubFrames  */

        /* Index of LinIfSubstitutionFrames attached to this frame in the
           akstrSubstFrmArray if LinIfFrameType = LinIf_SPORADIC*/
        0,                              /* u16SubFramesIndex    */

        /* Flag set to one if if LinIfFrameType = LinIf_UNCONDITIONAL and
           this frame is referenced in any LinIfSubstitutionFrameRef */
        FALSE,                           /* bIsSporadic          */

        /* If bIsSporadic = true this value should be incremental */
        NULL_PTR,                              /* pkstrSporadic     */

        /* Index of LinIfSlave in LinIf_akstreSlaves where 
           LinIfResponseErrorFrameRef is this LinIfFrame - 
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        0xFF,                              /* u8ErrorSlaveIndex    */
          
        /* Index of LinIfSlave in LinIf_akstreSlaves where
           this frame is a node configuration cmd for it -
           LinIf_akstreChannelsLT[CurrenChannel.Index].u8SlavesIndex if there
           is no such slave the value is 0xFF*/
        
        0xFF                            /* u8NCSlaveIdx         */
    }
};
#endif



#if (u16NUMBER_OF_SCH_TAB > 0U)


/* Represents all LinIfScheduleTable */

static CONST(LinIf_tstrScheduleTable, LINIF_CALIB_CONST)
                        akstrScheduleTables[1] =
{
    /* RUN_MAIN */
    {
        
        /* LinIfScheduleTableIndex starting from 1 incremental */
        1,                              /* udtIndex             */
        
        /* LinIfRunMode */
        LinIf_RUN_CONTINUOUS,           /* enuRunMode           */
        
        /* LinIfResumePosition */
        LinIf_START_FROM_BEGINNING,     /* enuResumePosition    */
        
        /* Number of LinIfEntry attached to this LinIfScheduleTable */
        21,                              /* u16NumberOfEntries   */
        
        /* Starting Index of the first LinIfEntry in that is attached to this 
           LinIfScheduleTable in akstrSchEntries*/
        0                               /* u16StartEntryIndex   */
    }
};
#endif

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
/* PRQA L:L2  */


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_START_SEC_CALIB_CONST_8
#include "Memmap.h"
/* PRQA L:L2  */


#if (u16NUMBER_OF_SUBST_FRMS > 0U)
/* Represents all LinIfSubstitutionFrames */

static CONST(LinIf_tstrSubstitutionFrame, LINIF_CALIB_CONST) 
                                                    akstrSubstFrmArray[0] =
{
};
#endif

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_STOP_SEC_CALIB_CONST_8
#include "Memmap.h"
/* PRQA L:L2  */

#if (u16NUMBER_OF_SCH_ENT > 0U)

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 
#define LINIF_START_SEC_CALIB_CONST_16
#include "Memmap.h"
/* PRQA L:L2  */




/* Represents all LinIfEntry */

static CONST(LinIf_tstrSchEntry, LINIF_CALIB_CONST) akstrSchEntries[21] =
{
    
    /* RUN_MAIN_Entry_00 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        0,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_00')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_01 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        1,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        2,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_01')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_02 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        2,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        8,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_02')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        2       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_03 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        3,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_03')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_04 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        4,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_04')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_05 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        5,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_05')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_06 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        6,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_06')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_07 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        7,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_07')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_08 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        8,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_08')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_09 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        9,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_09')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_10 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        10,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_10')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_11 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        11,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_11')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_12 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        12,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_12')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_13 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        13,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_13')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_14 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        14,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_14')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_15 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        15,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_15')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_16 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        16,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_16')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_17 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        17,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_17')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_18 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        18,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_18')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_19 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        19,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_19')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        0       /* u16FrameIndex            */
    },
    /* RUN_MAIN_Entry_20 */
    {
        /* LinIfEntryIndex incremental in one schedule table, when starting 
           a new schedule table start from 0*/
        20,      /* u8EntryIndex             */

        /* LinIfDelay / LinIfTimebase in milliseconds*/
        10,      /* u8Delay                  */
        
/* Warning!!!: This Check: Eval('LINIF-CRC-020','RUN_MAIN_Entry_20')  has an invalid ID */
        /* Index of the frame LinIfCollisionResolvingRef in
           akstrScheduleTables*/
        0,      /* u16ColResolvTabIndex    */
        
        /* Index of the frame LinIfFrameRef in akstrFrames */
        1       /* u16FrameIndex            */
    }
};

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"
/* PRQA L:L2  */
#endif


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */ 
/*!              for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L2  */ 

#define LINIF_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"
/* PRQA L:L2  */

/*! \Description The global LinIf configuration structure          */
/* Represents LinIfGlobalConfig */
CONST(LinIf_ConfigType, LINIF_CALIB_CONST) LinIf_kstrePBConfig = 
{
    /* Number of Transmit frames attached to this Channel */ 
    u16NUMBER_OF_TX_PDUS,
    &akstrChannelsPB[0],
    &akstrFrames[0],
    &akstrScheduleTables[0],
  
      &akstrSchEntries[0],
    
    NULL_PTR,
    
    NULL_PTR,
    

    &aku16TxMappingTable[0]
};

#define LINIF_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

 /*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */
  
