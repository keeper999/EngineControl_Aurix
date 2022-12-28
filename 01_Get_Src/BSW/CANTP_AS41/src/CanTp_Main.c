/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_Main.c                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.15     $$Author::   AELSOHBY       $$Date::   May 05 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Main.c
*
* \par
*   This file contains the implementation of the Main sub-componet.           \n
    The Main sub-component contains APIs that are not directly related to either
    transmission or reception (CanTp_Init, CanTp_GetVersionInfo, 
    CanTp_MainFunction, etc .....)                                            \n
    The Main sub-component is considered as the main controller of the CanTp, by
    communicating with both Reception and Transmission sub-components and acting
    as a user of both of them                                                 */
/******************************************************************************/


/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0838]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */
/* PRQA S 5087 L1                                                             */

#include "CanTp_Utilities.h"
#include "CanTp_Reception.h"
#include "CanTp_Transmission.h"
#include "CanTp_Main.h"
#include "CanTp_Cbk.h"
#include "CanTp.h"



/******************************************************************************/
/****************************** Version Checking ******************************/
/******************************************************************************/
#include "Compiler.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "ComStack_Types.h"
#include "CanIf.h"
#include "PduR.h"

#define u8C_SW_MAJOR_VERSION    (2)
#define u8C_SW_MINOR_VERSION    (0)
/******************************************************************************/
/* Intra-Module Checking - Module Header Files and Module C Files             */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != CANTP_SW_MAJOR_VERSION)
    #error Incompatible CanTp SW major version between C & H files.
#endif

#if (u8C_SW_MINOR_VERSION != CANTP_SW_MINOR_VERSION)
    #error Incompatible CanTp SW minor version between C & H files.
#endif
/******************************************************************************/
/* Inter-Module Checking - Module Header Files and Module C Files             */
/******************************************************************************/

#if (CanTp_bINTER_MOD_VER_CHECK == STD_ON)

#if (CANTP_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif

#if (CANTP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif

#if (CANTP_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif

#if (CANTP_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION)
    #error ComStackType AR RELEASE MAJOR VERSION is not compatible with CanTp \
           AR RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION < COMSTACKTYPE_AR_RELEASE_MINOR_VERSION)
    #error ComStackType AR RELEASE MINOR VERSION is not compatible with CanTp \
           AR RELEASE MINOR VERSION.
#endif


#if (CANTP_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)
    #error CanIf AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)
    #error CanIf AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif

#if (CANTP_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION)
    #error PduR AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION)
    #error PduR AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
#if (CANTP_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with CanTp AR \
           RELEASE MAJOR VERSION.
#endif
#if (CANTP_AR_RELEASE_MINOR_VERSION < DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with CanTp AR \
           RELEASE MINOR VERSION.
#endif
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

#endif /* #if (CanTp_bINTER_MOD_VER_CHECK == STD_ON) */


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
#define CANTP_START_SEC_VAR_8
#include "Memmap.h"

VAR(uint8, CANTP_VAR) CanTp_u8eCanTpGlobalState = CANTP_OFF;

#define CANTP_STOP_SEC_VAR_8
#include "Memmap.h"
/******************************************************************************/

/******************************************************************************/

#define CANTP_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

P2CONST(CanTp_ConfigType, CANTP_VAR, CANTP_APPL_CONST) 
                                                       CanTp_pkstreGlobalConfig;

#define CANTP_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/




/******************************************************************************/
/* LOCAL FUNCTIONS DECLARATION                                                */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    A local main function called by CanTp_MainFunction in     \n
                    order to handle each CanTpConnection resources separately \n
    \param[in]      u16IndexOfResources Index of the CanTpConnection resources\n
                    structure within the array CanTp_astreChannelsResources   \n
*******************************************************************************/
static FUNC(void, CANTP_CODE) vidLocalMainTask (
    VAR(uint16, AUTOMATIC) u16IndexOfResources);


/******************************************************************************/
/*! \Description    A function that searches for the corresponding CanTpNSdu  \n
                    by using the received RxPduId                             \n
    \param[in]      udtRxPduId      ID of the received NPDU                   \n
                    \Range          0 .. CanTp_u16NUM_OF_RX_PDU_IDS-1         \n
    \param[in]      pkudtPduInfoPtr A pointer to a structure that contains the\n
                                    received data and its length              \n
    \param[in]      u8NSduType      Determines whether the NPdu received      \n
                                    belongs to a CanTpTxNSdu or a CanTpRxNSdu \n
                    \Range          CanTp_u8RX_NSDU\CanTp_u8TX_NSDU           \n
    \param[out]     pudtNSduId      A pointer to a variable to store the 
                                    CanTpNSduId in case it was found          \n
    \return         A flag to determine if a CanTpNSdu was found or not       \n
*******************************************************************************/
LOCAL_INLINE FUNC(boolean, CANTP_CODE) bRxPduIdFound (
    VAR(PduIdType, AUTOMATIC)                           udtRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)    pkudtPduInfoPtr,
    VAR(uint8, AUTOMATIC)                               u8NSduType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)              pudtNSduId);


/******************************************************************************/
/*! \Description    A function that searches for the corresponding CanTpNSdu  \n
                    by using the confirmation ID of the transmitted NPDU      \n
    \param[in]      udtTxPduId      Confirmation ID of the transmitted NPDU   \n
                    \Range          0 .. CanTp_u16NUM_OF_TX_PDU_IDS-1         \n
    \param[out]     pu8NSduType     A variable to store the CanTpNSdu type    \n
                                    the awaited transmission confirmation     \n
                                    belongs                                   \n
    \param[out]     pudtNSduId      A pointer to a variable to store the 
                                    CanTpNSduId in case it was found          \n
    \return         A flag to determine if a CanTpNSdu was found or not       \n
*******************************************************************************/
LOCAL_INLINE FUNC(boolean, CANTP_CODE) bTxPduIdFound (
    VAR(PduIdType, AUTOMATIC)   udtTxPduId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8NSduType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) pudtNSduId);


/******************************************************************************/
/* LOCAL FUNCTIONS DEFINITION                                                 */
/******************************************************************************/

static FUNC(void, CANTP_CODE) vidLocalMainTask (
    VAR(uint16, AUTOMATIC) u16IndexOfResources)
{
    
    VAR(uint8, AUTOMATIC)       u8LocalChannelId;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pstrChannelResources;

    P2VAR(uint8, AUTOMATIC,AUTOMATIC)	pu8ConnectionState;
	P2VAR(uint16, AUTOMATIC,AUTOMATIC)	pu16TimeoutCounter;
    /*! Assign the local pointer to the address of the CanTpConnection        
        resources                                                             */
    pstrChannelResources = &CanTp_astreChannelsResources[u16IndexOfResources];
    /*! If the TimeoutCounter did not yet expire:                             */
    /*! \Trace_To   CanTp-CDD-5017(0), CanTp-CDD-5033(0), CanTp-CDD-5020(0)   */
    /*! \Trace_To   CanTp-CDD-5025(0)                                         */
    if(((pstrChannelResources->u8ConnectionState != CanTp_u8IDLE_STATE))
                              && (pstrChannelResources->u16TimeoutCounter != 0))
    {
        /*! Decrement the TimeoutCounter                                      */
        pstrChannelResources->u16TimeoutCounter--;
    }
        

    /*! Call the function responsible for handling the transmission operation */
    CanTp_vidManageTxState(pstrChannelResources);
    

    /*! Call the function responsible for handling the reception operation    */
    CanTp_vidManageRxState(pstrChannelResources);

	pu8ConnectionState = &(pstrChannelResources->u8ConnectionState);
	pu16TimeoutCounter = &(pstrChannelResources->u16TimeoutCounter);
    /*! If the CanTpConnection is currently handling a transmission operation:*/
    if((CanTp_u8GET_DIRECTION(pstrChannelResources)) 
                                                  == CanTp_u8DIR_TX)
    {
        u8LocalChannelId = 
            CanTp_akstreTxNSduPCCfg[pstrChannelResources->udtHandledNSduId].
                                                                u8ChannelNumber;
        CanTp_akstreCriticalSections
			[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													 pfvidEnterCriticalSec002_06();
        
        /*! If the TimeoutCounter expired (reached the value 0) AND that the 
            CanTpConnection state was not re-initialized (due to abortion 
            or completion) in CanTp_vidManageTxState:                         */
        if((*pu8ConnectionState != CanTp_u8IDLE_STATE)
                              && (*pu16TimeoutCounter == 0))
        {
            /*! Call the function responsible for handling the transmission
                timeout                                                       */
            CanTp_vidHandleTxTimeout(pstrChannelResources);
        }

        CanTp_akstreCriticalSections
			[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
												      pfvidExitCriticalSec002_06();
    }
    /*! If the CanTpConnection is currently handling a reception operation:   */
    else
    {
        u8LocalChannelId = 
            CanTp_akstreRxNSduPCCfg[pstrChannelResources->udtHandledNSduId].
                                                                u8ChannelNumber;

        CanTp_akstreCriticalSections
			[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
												     pfvidEnterCriticalSec003_06();

        /*! If the TimeoutCounter expired (reached the value 0) AND that the 
            CanTpConnection state was not re-initialized (due to abortion 
            or completion) in CanTp_vidManageTxState:                         */
        if((*pu8ConnectionState != CanTp_u8IDLE_STATE)
                              && (*pu16TimeoutCounter == 0))
        {
            /*! Call the function responsible for handling the reception
                timeout                                                       */
            CanTp_vidHandleRxTimeout(pstrChannelResources);
        }

        CanTp_akstreCriticalSections
			[CanTp_akstreTpChannels[u8LocalChannelId].u8IndexOfCriticalSec].
													  pfvidExitCriticalSec003_06();
    }

}

/******************************************************************************/

LOCAL_INLINE FUNC(boolean, CANTP_CODE) bRxPduIdFound (
    VAR(PduIdType, AUTOMATIC)                           udtRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)    pkudtPduInfoPtr,
    VAR(uint8, AUTOMATIC)                               u8NSduType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC)              pudtNSduId)
{
    VAR(uint16, AUTOMATIC)      u16StartSearchIndex;
    VAR(uint16, AUTOMATIC)      u16EndSearchIndex;
    VAR(boolean, AUTOMATIC)     bPduIdFound = FALSE;
    VAR(PduIdType, AUTOMATIC)   udtLocalNSduId;
    VAR(uint8, AUTOMATIC)       u8AddressFormat;

    /*! Use the mapping table CanTp_aku16eRxNPduMappingTable to determine the
        start index of the searching process within CanTp_akstreRxNPduList    */
    u16StartSearchIndex = 
                CanTp_akstreRxNPduMappingTable[udtRxPduId].u16IndexInRxNPduList;

    /*! Determine the end index at which the searching process will stop      */
    if(udtRxPduId == (CanTp_u16NUM_OF_RX_PDU_IDS-1))
    {
        u16EndSearchIndex = CanTp_u16SIZE_OF_RXPDU_LIST;
    }
    else
    {
        u16EndSearchIndex = 
              CanTp_akstreRxNPduMappingTable[udtRxPduId+1].u16IndexInRxNPduList;
    }

    /*! Loop on CanTp_akstreRxNPduList entries from the start index till the  
        end index is reached or till the NSdu is found                        */
    while((bPduIdFound != TRUE) && (u16StartSearchIndex < u16EndSearchIndex))
    {
        /*! Get the NSduId that this entry refers to                          */
        udtLocalNSduId = 
                CanTp_akstreRxNPduList[u16StartSearchIndex].u16IndexInNSduArray;

        /*! If the received NPDU belongs to a CanTpTxNSdu:                    */
        if(u8NSduType == CanTp_u8TX_NSDU)
        {
            /*! If this entry refers to a CanTpTxNSdu:                        */
            if(CanTp_akstreRxNPduList[u16StartSearchIndex].u8NSduDirection 
                                                             == CanTp_u8TX_NSDU)
            {
                /*! Get the addressing format linked to the received RxPduId  */
                u8AddressFormat = 
                    CanTp_akstreRxNPduMappingTable[udtRxPduId].
                                                     u8NPduAddressingFormat;

                /*! If the addressing format linked to the received RxPduId is
                    of type STANDARD, then the CanTpTxNSdu is found           */
                /*! If the addressing format linked to the received RxPduId is
                    of type EXTENDED, AND the Source Address of the referred
                    CanTpTxNSdu matches the data at the 1st received byte,
                    then the CanTpTxNSdu is found                             */
                /*! If the addressing format linked to the received RxPduId
                    is of type MIXED, AND the Address Extension of the
                    referred CanTpTxNSdu matches the data at the 1st received
                    byte, then the CanTpTxNSdu is found                       */

                /*! \Trace_To   CanTp-CDD-5095(0), CanTp-CDD-5097(0)          */
                if((u8AddressFormat == CanTp_u8STANDARD_ADDRESSING)
                    || 
                    ((u8AddressFormat == CanTp_u8EXTENDED_ADDRESSING)
                    && (CanTp_akstreTxNSduPCCfg[udtLocalNSduId].
                    u8NSourceAddress == pkudtPduInfoPtr->SduDataPtr[0]))
                    ||
                    ((u8AddressFormat == CanTp_u8MIXED_ADDRESSING)
                    && (CanTp_akstreTxNSduPCCfg[udtLocalNSduId].
                    u8NAddressExtension == pkudtPduInfoPtr->SduDataPtr[0])))
                {
                    bPduIdFound = TRUE;
                    *pudtNSduId = udtLocalNSduId;
                }
                
            }
        }
        /*! If the received NPDU belongs to a CanTpRxNSdu:                    */
        else
        {
            /*! If this entry refers to a CanTpRxNSdu:                        */
            if(CanTp_akstreRxNPduList[u16StartSearchIndex].u8NSduDirection 
                                                             == CanTp_u8RX_NSDU)
            {
                /*! Get the addressing format linked to the received RxPduId  */
                u8AddressFormat = 
                    CanTp_akstreRxNPduMappingTable[udtRxPduId].
                                                         u8NPduAddressingFormat;

                /*! If the addressing format linked to the received RxPduId is
                    of type STANDARD, then the CanTpRxNSdu is found           */
                /*! If the addressing format linked to the received RxPduId is
                    of type EXTENDED, AND the Source Address of the referred 
                    CanTpRxNSdu matches the data at the 1st received byte,
                    then the CanTpRxNSdu is found                             */
                /*! If the addressing format linked to the received RxPduId is
                    of type MIXED, AND the Address Extension of the referred
                    CanTpRxNSdu matches the data at the 1st received byte,
                    then the CanTpRxNSdu is found                             */

                /*! \Trace_To   CanTp-CDD-0095(0), CanTp-CDD-0096(0)          */
                if(
                    
                (u8AddressFormat == CanTp_u8STANDARD_ADDRESSING)
                ||
                ((u8AddressFormat == CanTp_u8EXTENDED_ADDRESSING) 
                && (CanTp_akstreRxNSduPCCfg[udtLocalNSduId].
                u8NSourceAddress == pkudtPduInfoPtr->SduDataPtr[0] ))
                ||
                ((u8AddressFormat == CanTp_u8MIXED_ADDRESSING) 
                && (CanTp_akstreRxNSduPCCfg[udtLocalNSduId].
                u8NAddressExtension == pkudtPduInfoPtr->SduDataPtr[0] )))
                {
                    bPduIdFound = TRUE;
                    *pudtNSduId = udtLocalNSduId;
                }              
            }
        }
        u16StartSearchIndex++;
    }

    return bPduIdFound;
}

/******************************************************************************/

LOCAL_INLINE FUNC(boolean, CANTP_CODE) bTxPduIdFound (
    VAR(PduIdType, AUTOMATIC)   udtTxPduId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  pu8NSduType,
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) pudtNSduId)
{
    VAR(uint16, AUTOMATIC)      u16StartSearchIndex;
    VAR(uint16, AUTOMATIC)      u16EndSearchIndex;
    VAR(boolean, AUTOMATIC)     bPduIdFound = FALSE;
    VAR(uint8, AUTOMATIC)       u8LocalNSduType;
    VAR(PduIdType, AUTOMATIC)   udtLocalNSduId;
    VAR(uint16, AUTOMATIC)      u16IndexOfResources;
    VAR(uint8, AUTOMATIC)       u8LocalOperation;
	VAR(uint8, AUTOMATIC)		u8LocalDirection;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pstrChannelResources;

    /*! Use the mapping table CanTp_aku16eTxNPduMappingTable to determine the
        start index of the searching process within CanTp_akstreTxNPduList    */
    u16StartSearchIndex = CanTp_aku16eTxNPduMappingTable[udtTxPduId];

    /*! Determine the end index at which the searching process will stop      */
    if(udtTxPduId == (CanTp_u16NUM_OF_TX_PDU_IDS-1))
    {
        u16EndSearchIndex = CanTp_u16SIZE_OF_TXPDU_LIST;
    }
    else
    {
        u16EndSearchIndex = CanTp_aku16eTxNPduMappingTable[udtTxPduId+1];
    }

    /*! Loop on CanTp_akstreTxNPduList entries from the start index till the  
        end index is reached or till the NSdu is found                        */
    while((bPduIdFound != TRUE) && (u16StartSearchIndex < u16EndSearchIndex))
    {
        /*! Get the NSduId that this entry refers to                          */
        udtLocalNSduId =
                CanTp_akstreTxNPduList[u16StartSearchIndex].u16IndexInNSduArray;
        
        /*! Get the NSdu type that this entry refers to                       */
        u8LocalNSduType =
                    CanTp_akstreTxNPduList[u16StartSearchIndex].u8NSduDirection;

        /*! If this entry refers to a CanTpTxNSdu:                            */
        if(u8LocalNSduType == CanTp_u8TX_NSDU)
        {
            /*! Get the index of the CanTpConnection resources -responsible for 
                handling the transmission operations- of the CanTpChannel that 
                the referred CanTpTxNSdu belongs to                           */
            u16IndexOfResources = 
                CanTp_akstreTpChannels[CanTp_akstreTxNSduPCCfg[udtLocalNSduId].
                                         u8ChannelNumber].u16IndexOfTxResources;
        }
        /*! If this entry refers to a CanTpRxNSdu                             */
        else
        {
            /*! Get the index of the CanTpConnection resources -responsible for 
                handling the reception operations- of the CanTpChannel that 
                the referred CanTpRxNSdu belongs to                           */
            u16IndexOfResources = 
                CanTp_akstreTpChannels[CanTp_akstreRxNSduPCCfg[udtLocalNSduId].
                                         u8ChannelNumber].u16IndexOfRxResources;
        }

        /*! Assign the local pointer to the address of the CanTpConnection     
            resources                                                         */
        pstrChannelResources = 
                             &CanTp_astreChannelsResources[u16IndexOfResources];

        /*! Get the operation that is currently taking place on the 
            CanTpConnection                                                   */
        u8LocalOperation = CanTp_u8GET_OPERATION(pstrChannelResources);

		u8LocalDirection = CanTp_u8GET_DIRECTION(pstrChannelResources);

        /*! If the CanTpConnection is waiting for transmission confirmation:  */
        if((((u8LocalNSduType == CanTp_u8TX_NSDU) && 
										   (u8LocalDirection == CanTp_u8DIR_TX))
										   ||
			   ((u8LocalNSduType == CanTp_u8RX_NSDU) && 
										  (u8LocalDirection == CanTp_u8DIR_RX)))
			&&
			(u8LocalOperation == CanTp_u8OPERATION_WAITCONF)
			&&
            (udtLocalNSduId == pstrChannelResources->udtHandledNSduId))
        {
            /*! The NSdu waiting for transmission confirmation was identified */
            bPduIdFound = TRUE;

            /*! Return the NSduId and its type (CanTpTxNSdu or CanTpRxNSdu)   */
            *pu8NSduType = u8LocalNSduType;
            *pudtNSduId = udtLocalNSduId;
        }

        /*! Increment the loop counter and process the next entry             */
        u16StartSearchIndex++;
    }

    return bPduIdFound;
}

/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTIONS DEFINITION                                                */
/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_Init(
                   P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST)CfgPtr)
{
    /*! \Trace_To   CanTp-CDD-0028(0)                                         */

    VAR(uint16_least, AUTOMATIC)  u16LocalIndex;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                            pstrChannelResources;

    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    /*! If a NULL pointer is received:                                        */
    if(CfgPtr == (P2VAR(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_DATA))NULL_PTR)
    {
        /*! Report the corresponding DET error code                           */
        /*! \Trace_Tp   CanTp-CDD-0144(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8INIT_ID, CANTP_E_PARAM_POINTER);
    }
    else
    {
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */

        /*! Set CanTp_pkstreGlobalConfig to point to the passed configuration
            set                                                               */
        CanTp_pkstreGlobalConfig = CfgPtr;

        /*! Loop on all CanTpConnection resources and initialize them         */
        for(u16LocalIndex=0; u16LocalIndex < CanTp_u16NUM_OF_TP_RESOURCES; 
                                                                u16LocalIndex++)
        {
            pstrChannelResources = &CanTp_astreChannelsResources[u16LocalIndex];

            /*! \Trace_To   CanTp-CDD-0031(0), CanTp-CDD-0033(0)              */
            /*! \Trace_Tp   CanTp-CDD-0034(0)                                 */
            CanTp_vidInitChannelResources(pstrChannelResources);
            pstrChannelResources->strUnExpectedPdu.bUnExpPduReceived = FALSE;
            pstrChannelResources->strCFReceptionError.bCFReceptionError = FALSE;
            pstrChannelResources->strRxCancelRequest.bCancellationRequest = 
                                                                          FALSE;
            pstrChannelResources->strTxCancelRequest.bCancellationRequest =
                                                                          FALSE;
        }

        /*! If CanTp_bCHANGE_PARAMETER_API is configured with STD_ON:         */
#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)

        /*! Initialize CanTp_au8eCurrentSTmin and CanTp_au8eCurrentBlockSize
            entries with the initial values defined by the configuration set  */
        for(u16LocalIndex=0; u16LocalIndex < CanTp_u16NUM_OF_RX_NSDUS; 
                                                                u16LocalIndex++)
        {
            CanTp_au8eCurrentSTmin[u16LocalIndex] = 
                CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[u16LocalIndex].u8STmin;

            CanTp_au8eCurrentBlockSize[u16LocalIndex] = 
                CanTp_pkstreGlobalConfig->pkstrRxNSduCfg[u16LocalIndex].
                                                                    u8BlockSize;
        }

#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */
                
        /*! Set CanTp state to CANTP_ON                                       */
        /*! \Trace_To   CanTp-CDD-0029(0), CanTp-CDD-0126(0)                  */
        CanTp_u8eCanTpGlobalState = CANTP_ON;

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    
}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_Shutdown(void)
{
    VAR(uint16_least, AUTOMATIC)  u16LocalIndex;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                            pstrChannelResources;

    /*! \Trace_To   CanTp-CDD-0035(0)                                         */

    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5008(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8SHUTDOWN_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT */
    }
    /*! If the service was called while the CanTp is initialized:             */
    else
    {
        /*! Set CanTp state to CANTP_OFF                                      */
        CanTp_u8eCanTpGlobalState = CANTP_OFF;

        /*! Loop on all CanTpConnection resources and initialize them to abort
            any transmission or reception operations taking place             */
        for(u16LocalIndex=0; u16LocalIndex < CanTp_u16NUM_OF_TP_RESOURCES; 
                                                                u16LocalIndex++)
        {
            pstrChannelResources = &CanTp_astreChannelsResources[u16LocalIndex];
            /*! \Trace_Tp   CanTp-CDD-0152(0), CanTp-CDD-0153(0)              */
            CanTp_vidInitChannelResources(pstrChannelResources);
        }
    }

}

/******************************************************************************/

FUNC(void, CANTP_CODE) CanTp_MainFunction(void)
{
    /*! \Trace_To   CanTp-CDD-0178(0), CanTp-CDD-0179(0)                      */

    VAR(uint16_least, AUTOMATIC) u16LocalIndex;

    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5005(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5013(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8MAIN_FUNCTION_ID, CANTP_E_UNINIT);
#endif  /* CanTp_bDEV_ERROR_DETECT */
    }
    /*! If the service was called while the CanTp is initialized:             */
    else
    {
        /*! Loop on all CanToConnection resources and call vidLocalMainTask
            to handle each CanTpConnections one by one                        */
        for(u16LocalIndex = 0; u16LocalIndex < CanTp_u16NUM_OF_TP_RESOURCES; 
                                                                u16LocalIndex++)
        {
			/* !Deviation : Inhibit MISRA rule [3212]: U16LocalIndex variable cast might  */
			/*              be needed if platform changes and uint16_least doesn't become */
			/*              the same as uint16                                            */
			/* PRQA S 3212 ++                                                             */
            vidLocalMainTask((uint16)u16LocalIndex);
			/* PRQA S 3212 --                                                             */
        }
    }
}


/******************************************************************************/

/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric value out of threshold range*/
/*              The function might be called from an ISR context so there is  */
/*              no need to divide it into multiple functions as the execution */
/*              time shall be as short as possible                            */
/* PRQA S 4700 ++                                                             */

FUNC(void, CANTP_CODE) CanTp_RxIndication(
    VAR(PduIdType, AUTOMATIC) RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA)PduInfoPtr)
{
    VAR(uint8, AUTOMATIC)       u8FrameType;
    VAR(uint8, AUTOMATIC)       u8NSduType;
    VAR(boolean, AUTOMATIC)     bPduIdFound;
    VAR(PduIdType, AUTOMATIC)   udtNSduId;
    VAR(uint8, AUTOMATIC)       u8PciByteLocation;
    VAR(boolean, AUTOMATIC)     bHandleNewRx;
    VAR(uint16, AUTOMATIC)      u16IndexOfResources;
    VAR(uint8, AUTOMATIC)       u8LocalChannelId;
    P2VAR(CanTp_tstrChannelResources, AUTOMATIC, CANTP_VAR)
                                pstrChannelResources;

    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5006(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)

        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5014(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID, CANTP_E_UNINIT);

#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    /*! If a NULL pointer is received:                                        */
    else if((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
    {
        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-0183(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                         CANTP_E_PARAM_POINTER);
    }
    /*! If an invalid RxPduId is received                                     */
    /*! \Trace_To   CanTp-CDD-5060(0)                                         */
    else if(RxPduId >= CanTp_u16NUM_OF_RX_PDU_IDS)
    {
        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                         CANTP_E_INVALID_RX_ID);
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    
    /*! If the RxNPdu received with an invalid length                         */
    else if((PduInfoPtr->SduLength < 2) || (PduInfoPtr->SduLength > 8))
    {
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! Report the corresponding DET error code                           */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8RX_INDICATION_ID,
                                                     CANTP_E_INVALID_RX_LENGTH);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /*! If the service has passed all error checks and can be normally 
            executed:                                                         */

        /*! If the addressing format linked to the received RxPduId is of type
            STANDARD:                                                         */
        if(CanTp_akstreRxNPduMappingTable[RxPduId].u8NPduAddressingFormat 
                                                 == CanTp_u8STANDARD_ADDRESSING)
        {
            /*! The firt PCI byte is located at the first received byte       */
            u8PciByteLocation = 0;
        }
        /*! If the addressing format linked to the received RxPduId is of type
            EXTENDED or MIXED:                                                */
        else
        {
            /*! The firt PCI byte is located at the second received byte      */
            u8PciByteLocation = 1;
        }

        /*! Get the type of the received frame from the first PCI byte        */
        u8FrameType = 
              CanTp_u8PCI_FRAME_TYPE(PduInfoPtr->SduDataPtr[u8PciByteLocation]);

        /*! Check the received frame is one of the following defined frames:
            - Single Frame
            - First Frame
            - Consecutive Frame
            - Flow Control Frame                                              */
        /*! \Trace_To   CanTp-CDD-5043(0)                                     */
        if((u8FrameType == CanTp_u8SINGLE_FRAME)      ||
           (u8FrameType == CanTp_u8FIRST_FRAME)       ||
           (u8FrameType == CanTp_u8CONSECUTIVE_FRAME) ||
           (u8FrameType == CanTp_u8FLOW_CONTROL_FRAME))
        {
            /*! If a flow control frame received, then this frame belongs to a
                a CanTpTxNSdu                                                 */
            if(u8FrameType == CanTp_u8FLOW_CONTROL_FRAME)
            {
                u8NSduType = CanTp_u8TX_NSDU;
            }
            /*! If the frame received is a SF, FF, or a CF then this frame 
            belongs to a CanTpRxNSdu                                          */
            else
            {
                u8NSduType = CanTp_u8RX_NSDU;
            }
            
            /*! Search for the corresponding CanTpNSdu based on the RxPduId 
                received                                                      */
            bPduIdFound = bRxPduIdFound(RxPduId,
                                            PduInfoPtr, u8NSduType, &udtNSduId);

            /*! If the CanTpNSdu was found:                                   */
            if(bPduIdFound == TRUE)
            {

                u8LocalChannelId = 
                             CanTp_akstreRxNSduPCCfg[udtNSduId].u8ChannelNumber;

                /*! \Trace_To   CanTp-CDD-5149(0)                             */
                u16IndexOfResources = 
                      CanTp_akstreTpChannels[u8LocalChannelId].
														  u16IndexOfRxResources;
                pstrChannelResources = 
                             &CanTp_astreChannelsResources[u16IndexOfResources];

                if((u8FrameType == CanTp_u8SINGLE_FRAME) || 
                                           (u8FrameType == CanTp_u8FIRST_FRAME))
                {
                    CanTp_akstreCriticalSections
						[CanTp_akstreTpChannels[u8LocalChannelId].
							   u8IndexOfCriticalSec].pfvidEnterCriticalSec001_42();

                    bHandleNewRx = CanTp_bHandleNewReception(PduInfoPtr,
                                               udtNSduId, pstrChannelResources);

                    if(bHandleNewRx == TRUE)
                    {
                        if(u8FrameType == CanTp_u8SINGLE_FRAME)
                        {
                            /*! If the received frame is a single frame, call 
                            the function in the Reception sub-component 
                            responsible for handling single frames            */
                            CanTp_vidHandleSingleFrame(PduInfoPtr,
                                               udtNSduId, pstrChannelResources);
                        }
                        else
                        {
                            /*! If the received frame is a first frame, call 
                            the function in the Reception sub-component 
                            responsible for handling first frames             */
                            CanTp_vidHandleFirstFrame(PduInfoPtr,
                                               udtNSduId, pstrChannelResources);
                        }
                    }

                    CanTp_akstreCriticalSections
						[CanTp_akstreTpChannels[u8LocalChannelId].
								u8IndexOfCriticalSec].pfvidExitCriticalSec001_42();
                }
                else
                {
                    /*! If the received frame is a consecutive frame, call the
                        function in the Reception sub-component responsible for
                        handling consecutive frames                           */
                    if(u8FrameType == CanTp_u8CONSECUTIVE_FRAME)
                    {
                        CanTp_akstreCriticalSections
							[CanTp_akstreTpChannels[u8LocalChannelId].
							   u8IndexOfCriticalSec].pfvidEnterCriticalSec003_42();

                        CanTp_vidHandleConsecFrame(PduInfoPtr,
                                               udtNSduId, pstrChannelResources);
                        
                        CanTp_akstreCriticalSections
							[CanTp_akstreTpChannels[u8LocalChannelId].
							    u8IndexOfCriticalSec].pfvidExitCriticalSec003_42();
                    }
                    /*! If the received frame is a flow control frame, store the
                    flow control frame received in order to be handled in the
                    next main function call                                   */
                    else
                    {
                        CanTp_akstreCriticalSections
							[CanTp_akstreTpChannels[u8LocalChannelId].
							   u8IndexOfCriticalSec].pfvidEnterCriticalSec002_42();
                        
                        CanTp_vidStoreFCFrame(PduInfoPtr,udtNSduId);
                        
                        CanTp_akstreCriticalSections
							[CanTp_akstreTpChannels[u8LocalChannelId].
							    u8IndexOfCriticalSec].pfvidExitCriticalSec002_42();
                    }
                }

            }
        }
    }
    
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/


FUNC(void, CANTP_CODE) CanTp_TxConfirmation(
    VAR(PduIdType,AUTOMATIC) TxPduId )
{
    VAR(boolean, AUTOMATIC)     bPduIdFound;
    VAR(PduIdType, AUTOMATIC)   udtNSduId;
    VAR(uint8, AUTOMATIC)       u8NSduType;
    VAR(uint8, AUTOMATIC)       u8LocalChannelId;
    VAR(uint16, AUTOMATIC)      u16IndexOfResources;
	P2VAR(uint8, AUTOMATIC,AUTOMATIC)			pu8ConnectionState;
    /*! If the service was called while the CanTp is not initialized:         */
    /*! \Trace_To   CanTp-CDD-5007(0)                                         */
    if(CanTp_u8eCanTpGlobalState != CANTP_ON)
    {
    /*! If DET is enabled:                                                    */
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5015(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TX_CONFIRMATION_ID, CANTP_E_UNINIT);
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */
    }
#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
    /*! If an invalid TxPduId is received                                     */
    else if(TxPduId >= CanTp_u16NUM_OF_TX_PDU_IDS)
    {
        /*! Report the corresponding DET error code                           */
        /*! \Trace_To   CanTp-CDD-5134(0)                                     */
        CanTp_vidREPORT_DET_ERROR(CanTp_u8TX_CONFIRMATION_ID,
                                                         CANTP_E_INVALID_TX_ID);
    }
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */    
    else
    {
        /*! If the service has passed all error checks and can be normally 
            executed:                                                         */

        /*! Search for the corresponding CanTpNSdu based on the TxPduId 
            received                                                          */
        bPduIdFound = bTxPduIdFound(TxPduId, &u8NSduType, &udtNSduId);

        /*! If the CanTpNSdu was found:                                       */
        if(bPduIdFound!=FALSE)
        {
            /*! If the transmission confirmation belongs to a CanTpTxNSdu:    */
            if(u8NSduType == CanTp_u8TX_NSDU)
            {
                u8LocalChannelId = 
                             CanTp_akstreTxNSduPCCfg[udtNSduId].u8ChannelNumber;

                u16IndexOfResources = 
                      CanTp_akstreTpChannels[u8LocalChannelId].
														  u16IndexOfTxResources;
				pu8ConnectionState = &(CanTp_astreChannelsResources[u16IndexOfResources].u8ConnectionState);
                CanTp_akstreCriticalSections
					[CanTp_akstreTpChannels[u8LocalChannelId].
							   u8IndexOfCriticalSec].pfvidEnterCriticalSec002_40();

                if(((*pu8ConnectionState) & CanTp_u8OPERATION_MASK) == 
                                                     CanTp_u8OPERATION_WAITCONF)
                {
                    /*! Call the function in the Transmission sub-component
                        responsible for handling transmission confirmations of 
                        SF, FF, or CF                                         */
                    CanTp_vidConfHandlerTx(udtNSduId);
                }

                CanTp_akstreCriticalSections
					[CanTp_akstreTpChannels[u8LocalChannelId].
								u8IndexOfCriticalSec].pfvidExitCriticalSec002_40();
            }
            /*! If the transmission confirmation belongs to a CanTpRxNSdu:    */
            else
            {
                u8LocalChannelId = 
                             CanTp_akstreRxNSduPCCfg[udtNSduId].u8ChannelNumber;

                u16IndexOfResources = 
					CanTp_akstreTpChannels[u8LocalChannelId].
														  u16IndexOfRxResources;

				pu8ConnectionState = &(CanTp_astreChannelsResources[u16IndexOfResources].u8ConnectionState);
                
				CanTp_akstreCriticalSections
					[CanTp_akstreTpChannels[u8LocalChannelId].
							   u8IndexOfCriticalSec].pfvidEnterCriticalSec003_40();


                if(((*pu8ConnectionState) & CanTp_u8OPERATION_MASK) == 
                                                     CanTp_u8OPERATION_WAITCONF)
                {
                    /*! Call the function in the Reception sub-component
                        responsible for handling transmission confirmations of
                        flow control frames                                   */
                    CanTp_vidConfHandlerRx(udtNSduId);
                }

                CanTp_akstreCriticalSections
					[CanTp_akstreTpChannels[u8LocalChannelId].
								u8IndexOfCriticalSec].pfvidExitCriticalSec003_40();
            }
        }

    }
}

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */
