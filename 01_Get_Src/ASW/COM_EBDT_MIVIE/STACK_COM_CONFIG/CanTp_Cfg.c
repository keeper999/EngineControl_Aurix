
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
/* !File            : CanTp_Cfg.c                                             */
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
/* $Revision::   1.1      $$Author::   madel          $$Date::   Nov 22 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_Cfg.c
*
* \par
*   This file contains pre-compile time configuration parameters of the CanTp 
    Component                                                                 */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0838]: Empty macros of memory classes     */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */

#include "Std_Types.h"
#include "CanTp_LocalCfg.h"
#include "SchM_CanTp.h"


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define CANTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"




/******************************************************************************/
/*! \Description    Array that contains the enter and exit services needed for
                    protecting the critical regions defined by the designed,
                    for each different Exclusive Area configured              */
/******************************************************************************/
CONST (CanTp_tstrCriticalSectionsType, CANTP_CFG_CONST)
                        CanTp_akstreCriticalSections[CanTp_u8NUM_OF_EXC_AREAS] =
{
/******************************************************************************/
/*************************** Exclusive Area 00000 *****************************/
/******************************************************************************/
    {
        /*  pfvidEnterCriticalSec001    */  SchM_Enter_CanTp_CS00000_001_42,
        /*  pfvidExitCriticalSec001     */  SchM_Exit_CanTp_CS00000_001_42,
        /*  pfvidEnterCriticalSec001    */  SchM_Enter_CanTp_CS00000_001_03,
        /*  pfvidExitCriticalSec001     */  SchM_Exit_CanTp_CS00000_001_03,
        /*  pfvidEnterCriticalSec001    */  SchM_Enter_CanTp_CS00000_001_06,
        /*  pfvidExitCriticalSec001     */  SchM_Exit_CanTp_CS00000_001_06,		
        /*  pfvidEnterCriticalSec002    */  SchM_Enter_CanTp_CS00000_002_42,
        /*  pfvidExitCriticalSec002     */  SchM_Exit_CanTp_CS00000_002_42,
        /*  pfvidEnterCriticalSec002    */  SchM_Enter_CanTp_CS00000_002_40,
        /*  pfvidExitCriticalSec002     */  SchM_Exit_CanTp_CS00000_002_40,
        /*  pfvidEnterCriticalSec002    */  SchM_Enter_CanTp_CS00000_002_08,
        /*  pfvidExitCriticalSec002     */  SchM_Exit_CanTp_CS00000_002_08,
        /*  pfvidEnterCriticalSec002    */  SchM_Enter_CanTp_CS00000_002_06,
        /*  pfvidExitCriticalSec002     */  SchM_Exit_CanTp_CS00000_002_06,			
        /*  pfvidEnterCriticalSec003    */  SchM_Enter_CanTp_CS00000_003_42,
        /*  pfvidExitCriticalSec003     */  SchM_Exit_CanTp_CS00000_003_42,
        /*  pfvidEnterCriticalSec003    */  SchM_Enter_CanTp_CS00000_003_40,
        /*  pfvidExitCriticalSec003     */  SchM_Exit_CanTp_CS00000_003_40,
        /*  pfvidEnterCriticalSec003    */  SchM_Enter_CanTp_CS00000_003_09,
        /*  pfvidExitCriticalSec003     */  SchM_Exit_CanTp_CS00000_003_09,
        /*  pfvidEnterCriticalSec003    */  SchM_Enter_CanTp_CS00000_003_06,
        /*  pfvidExitCriticalSec003     */  SchM_Exit_CanTp_CS00000_003_06		
    }
    
};

#define CANTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define CANTP_START_CONFIG_DATA_16
#include "MemMap.h"
/******************************************************************************/
/*! \Description    Array that contains the parameters of each CanTpChannel   
                    including:                                                \n
                    - CanTpChannelMode [half-duplex/full-duplex]              \n
                    - Reference to the CanTpResources used by each            
                      CanTpConnection of the CanTpChannel                     */
/******************************************************************************/
CONST (CanTp_tstrChannelCfgType, CANTP_CFG_CONST)
                            CanTp_akstreTpChannels[CanTp_u8NUM_OF_TP_CHANNELS] =
{
/******************************************************************************/
/****************************** CanTpChannel 00 *******************************/
/******************************************************************************/
    {
        /*  u8ChannelMode           */  CanTp_u8HALF_DUPLEX_CHANNEL,
        /*  u16IndexOfTxResources   */  0,
        /*  u16IndexOfRxResources   */  0,
        /*  u8IndexOfCriticalSec    */  0
    }
    ,
/******************************************************************************/
/****************************** CanTpChannel 01 *******************************/
/******************************************************************************/
    {
        /*  u8ChannelMode           */  CanTp_u8HALF_DUPLEX_CHANNEL,
        /*  u16IndexOfTxResources   */  1,
        /*  u16IndexOfRxResources   */  1,
        /*  u8IndexOfCriticalSec    */  0
    }
    ,
/******************************************************************************/
/****************************** CanTpChannel 02 *******************************/
/******************************************************************************/
    {
        /*  u8ChannelMode           */  CanTp_u8HALF_DUPLEX_CHANNEL,
        /*  u16IndexOfTxResources   */  2,
        /*  u16IndexOfRxResources   */  2,
        /*  u8IndexOfCriticalSec    */  0
    }
    ,
/******************************************************************************/
/****************************** CanTpChannel 03 *******************************/
/******************************************************************************/
    {
        /*  u8ChannelMode           */  CanTp_u8HALF_DUPLEX_CHANNEL,
        /*  u16IndexOfTxResources   */  3,
        /*  u16IndexOfRxResources   */  3,
        /*  u8IndexOfCriticalSec    */  0
    }
    
};

/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_akstreTpChannels shall be created for 
                     each instance of CanTpChannel
                    -The entries are ordered ascendingly based on the 
                     CanTpChannel number, and the channel number is used as the
                     index of this array                                      */
/******************************************************************************/
#define CANTP_STOP_CONFIG_DATA_16
#include "MemMap.h"




#define CANTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*! \Description    Array that contains the pre-compile time configuration    
                    parameters for each CanTpTxNSdu                           */
/******************************************************************************/
CONST (CanTp_tstrTxNSduPCCfgType, CANTP_CFG_CONST) 
                             CanTp_akstreTxNSduPCCfg[CanTp_u16NUM_OF_TX_NSDUS] =
{
/******************************************************************************/
/********************* CanTpTxNSdu 000 - CanTpChannel 03 **********************/
/******************************************************************************/
    {
        /*  bTransmitCancellation   */  TRUE,
        /*  u8TxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16TxDataLengthCode     */  8,
        /*  u8TxPaddingActivation   */  CanTp_u8PADDING_ON,
        /*  u8TxTaType              */  CanTp_u8PHYSICAL_ADDRESS,
        /*  udtTxConfPduId          */  0,
        /*  udtRxFcNPduId           */  0,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  3
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 001 - CanTpChannel 02 **********************/
/******************************************************************************/
    {
        /*  bTransmitCancellation   */  FALSE,
        /*  u8TxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16TxDataLengthCode     */  8,
        /*  u8TxPaddingActivation   */  CanTp_u8PADDING_ON,
        /*  u8TxTaType              */  CanTp_u8FUNCTIONAL_ADDRESS,
        /*  udtTxConfPduId          */  1,
        /*  udtRxFcNPduId           */  1,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  2
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 002 - CanTpChannel 00 **********************/
/******************************************************************************/
    {
        /*  bTransmitCancellation   */  FALSE,
        /*  u8TxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16TxDataLengthCode     */  8,
        /*  u8TxPaddingActivation   */  CanTp_u8PADDING_OFF,
        /*  u8TxTaType              */  CanTp_u8FUNCTIONAL_ADDRESS,
        /*  udtTxConfPduId          */  2,
        /*  udtRxFcNPduId           */  2,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  0
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 003 - CanTpChannel 01 **********************/
/******************************************************************************/
    {
        /*  bTransmitCancellation   */  FALSE,
        /*  u8TxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16TxDataLengthCode     */  8,
        /*  u8TxPaddingActivation   */  CanTp_u8PADDING_OFF,
        /*  u8TxTaType              */  CanTp_u8PHYSICAL_ADDRESS,
        /*  udtTxConfPduId          */  3,
        /*  udtRxFcNPduId           */  3,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  1
    }
    
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_akstreTxNSduPCCfg shall be created for 
                     each instance of CanTpTxNSdu
                    -The entries are ordered ascendingly based on the 
                     configuration parameter CanTpTxNSduId of each CanTpTxNSdu.
                     The CanTpTxNSduId is considered as the index of the
                     CanTpTxNSdu within this array, so the range of the
                     CanTpTxNSduIds shall start from 0 till 
                     CanTp_u16NUM_OF_TX_NSDUS                                 */                          
/******************************************************************************/





/******************************************************************************/
/*! \Description    Array that contains the pre-compile time configuration    
                    parameters for each CanTpRxNSdu                           */
/******************************************************************************/
CONST (CanTp_tstrRxNSduPCCfgType, CANTP_CFG_CONST)
                             CanTp_akstreRxNSduPCCfg[CanTp_u16NUM_OF_RX_NSDUS] =
{
/******************************************************************************/
/********************* CanTpRxNSdu 000 - CanTpChannel 03 **********************/
/******************************************************************************/
    {
        /*  u8RxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16RxDataLengthCode     */  1,
        /*  u8RxPaddingActivation   */  CanTp_u8PADDING_ON,
        /*  u8RxTaType              */  CanTp_u8PHYSICAL_ADDRESS,
        /*  udtRxNPduId             */  0,
        /*  udtTxFcConfPduId        */  0,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  3
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 001 - CanTpChannel 02 **********************/
/******************************************************************************/
    {
        /*  u8RxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16RxDataLengthCode     */  2,
        /*  u8RxPaddingActivation   */  CanTp_u8PADDING_ON,
        /*  u8RxTaType              */  CanTp_u8FUNCTIONAL_ADDRESS,
        /*  udtRxNPduId             */  1,
        /*  udtTxFcConfPduId        */  1,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  2
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 002 - CanTpChannel 00 **********************/
/******************************************************************************/
    {
        /*  u8RxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16RxDataLengthCode     */  3,
        /*  u8RxPaddingActivation   */  CanTp_u8PADDING_OFF,
        /*  u8RxTaType              */  CanTp_u8FUNCTIONAL_ADDRESS,
        /*  udtRxNPduId             */  2,
        /*  udtTxFcConfPduId        */  2,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  0
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 003 - CanTpChannel 01 **********************/
/******************************************************************************/
    {
        /*  u8RxAddressingFormat    */  CanTp_u8STANDARD_ADDRESSING,
        /*  u16RxDataLengthCode     */  8,
        /*  u8RxPaddingActivation   */  CanTp_u8PADDING_OFF,
        /*  u8RxTaType              */  CanTp_u8PHYSICAL_ADDRESS,
        /*  udtRxNPduId             */  3,
        /*  udtTxFcConfPduId        */  3,
        /*  u8NTargetAddress        */  0xFF,
        /*  u8NSourceAddress        */  0xFF,
        /*  u8NAddressExtension     */  0xFF,
        /*  u8ChannelNumber         */  1
    }
    
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_akstreRxNSduPCCfg shall be created for 
                     each instance of CanTpRxNSdu
                    -The entries are ordered ascendingly based on the 
                     configuration parameter CanTpRxNSduId of each CanTpRxNSdu.
                     The CanTpRxNSduId is considered as the index of the
                     CanTpRxNSdu within this array, so the range of the
                     CanTpRxNSduIds shall start from 0 till 
                     CanTp_u16NUM_OF_RX_NSDUS                                 */
/******************************************************************************/
#define CANTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"



#define CANTP_START_CONFIG_DATA_16
#include "MemMap.h"
/******************************************************************************/
/*! \Description    Array that contains references to CanTpNSdus that will    
                    handle transmission confirmation operations.              \n
                    These CanTpNSdus are:                                     \n
                    -All CanTpTxNSdus                                         \n
                    -CanTpRxNSdus that will handle multiple frame reception   
                     (flow control frame will be transmitted so transmission  
                     confirmation is needed)                                  \n
                    This TxNPduList is used to determine the CanTpNSdu -whose 
                    transmission confirmation was received- by using the      
                    TxPduId                                                   */
/******************************************************************************/

CONST (CanTp_tstrNPduListType, CANTP_CFG_CONST)
                           CanTp_akstreTxNPduList[CanTp_u16SIZE_OF_TXPDU_LIST] =
{
/******************************************************************************/
/******************************** TxPduId 000 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  0
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  0
    }
    ,
/******************************************************************************/
/******************************** TxPduId 001 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  1
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  1
    }
    ,
/******************************************************************************/
/******************************** TxPduId 002 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  2
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  2
    }
    ,
/******************************************************************************/
/******************************** TxPduId 003 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  3
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  3
    }
    ,
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_akstreTxNPduList shall be created for 
                     each CanTpNSdu that will handle transmission confirmation
                     operations. The CanTpNSdus that will handle transmission
                     confirmation operations are:
                     1-All CanTpTxNSdus
                     2-CanTpRxNSdus whose optional sub-container CanTpTxFcNPdu
                       was created.  
                    -The entries are ordered ascendingly based on the TxPduId
                     which can be either CanTpTxFcNPduConfirmationPduId of
                     RxNSdu (udtTxFcConfPduId) or CanTpTxNPduConfirmationPduId 
                     of TxNSdu(udtTxConfPduId) so the entries shall be grouped
                     into a number of groups equal to 
                     CanTp_u16NUM_OF_TX_PDU_IDS                               */
/******************************************************************************/




/******************************************************************************/
/*! \Description    Array that contains references to CanTpNSdus that will    
                    handle reception operations.                              \n
                    These CanTpNSdus are:                                     \n
                    -All CanTpRxNSdus                                         \n
                    -CanTpTxNSdus that will handle multiple frame reception   
                     (flow control frames will be received)                   \n
                    This RxNPduList is used to determine the CanTpNSdu -whose 
                    frame was received- by using the RxPduId                  */
/******************************************************************************/
CONST (CanTp_tstrNPduListType, CANTP_CFG_CONST)
                           CanTp_akstreRxNPduList[CanTp_u16SIZE_OF_RXPDU_LIST] =
{
/******************************************************************************/
/******************************** RxPduId 000 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  0
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  0
    }
    ,
/******************************************************************************/
/******************************** RxPduId 001 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  1
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  1
    }
    ,
/******************************************************************************/
/******************************** RxPduId 002 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  2
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  2
    }
    ,
/******************************************************************************/
/******************************** RxPduId 003 *********************************/
/******************************************************************************/
    {
        /*  u8NSduDirection     */  CanTp_u8TX_NSDU,
        /*  u16IndexInNSduArray */  3
    }
    ,
    {
        /*  u8NSduDirection     */  CanTp_u8RX_NSDU,
        /*  u16IndexInNSduArray */  3
    }
    ,
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_akstreRxNPduList shall be created for 
                     each CanTpNSdu that will handle reception operations. 
                     The CanTpNSdus that will handle reception operations are:
                     1-All CanTpRxNSdus
                     2-CanTpTxNSdus whose optional sub-container CanTpRxFcNPdu
                       was created.   
                    -The entries are ordered ascendingly based on the RxPduId
                     which can be either RxFcNPduId of TxNSdu (udtRxFcNPduId)or 
                     RxNPduId of RxNSdu(udtRxNPduId) so the entries shall be 
                     grouped into a number of groups equal to 
                     CanTp_u16NUM_OF_RX_PDU_IDS                               */
/******************************************************************************/





/******************************************************************************/
/*! \Description    A mapping table used to optimize the searching process    
                    within CanTp_akstreTxNPduList by determining the index    
                    from which the searching process shall start from         */
/******************************************************************************/

CONST (uint16, CANTP_CFG_CONST)
                    CanTp_aku16eTxNPduMappingTable[CanTp_u16NUM_OF_TX_PDU_IDS] =
{
/******************************************************************************/
/******************************** TxPduId 000 *********************************/
/******************************************************************************/
    /*  u16IndexInTxNPduList    */  0,
/******************************************************************************/
/******************************** TxPduId 001 *********************************/
/******************************************************************************/
    /*  u16IndexInTxNPduList    */  2,
/******************************************************************************/
/******************************** TxPduId 002 *********************************/
/******************************************************************************/
    /*  u16IndexInTxNPduList    */  4,
/******************************************************************************/
/******************************** TxPduId 003 *********************************/
/******************************************************************************/
    /*  u16IndexInTxNPduList    */  6,
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_aku16eTxNPduMappingTable shall be 
                     created for each unique TxPduId
                    -For each entry in this array, the start index of its
                     corresponding group in CanTp_akstreTxNPduList shall be
                     specified.                                               */
/******************************************************************************/





/******************************************************************************/
/*! \Description    A mapping table used to optimize the searching process    
                    within CanTp_akstreRxNPduList by determining the index    
                    from which the searching process shall start from         */
/******************************************************************************/

CONST (CanTp_tstrRxNPduMappingType, CANTP_CFG_CONST)
                    CanTp_akstreRxNPduMappingTable[CanTp_u16NUM_OF_RX_PDU_IDS] =
{
/******************************************************************************/
/******************************** RxPduId 000 *********************************/
/******************************************************************************/
    {
        /*  u16IndexInRxNPduList    */  0,
        /*  u8NPduAddressingFormat  */  CanTp_u8STANDARD_ADDRESSING
    }
    ,
/******************************************************************************/
/******************************** RxPduId 001 *********************************/
/******************************************************************************/
    {
        /*  u16IndexInRxNPduList    */  2,
        /*  u8NPduAddressingFormat  */  CanTp_u8STANDARD_ADDRESSING
    }
    ,
/******************************************************************************/
/******************************** RxPduId 002 *********************************/
/******************************************************************************/
    {
        /*  u16IndexInRxNPduList    */  4,
        /*  u8NPduAddressingFormat  */  CanTp_u8STANDARD_ADDRESSING
    }
    ,
/******************************************************************************/
/******************************** RxPduId 003 *********************************/
/******************************************************************************/
    {
        /*  u16IndexInRxNPduList    */  6,
        /*  u8NPduAddressingFormat  */  CanTp_u8STANDARD_ADDRESSING
    }
    ,
};
/******************************************************************************/
/*  \ConfigTool     -An entry in CanTp_aku16eRxNPduMappingTable shall be 
                     created for each unique RxPduId
                    -For each entry in this array, the start index of its
                     corresponding group in CanTp_akstreRxNPduList shall be
                     specified as well as the addressing format used          */
/******************************************************************************/
#define CANTP_STOP_CONFIG_DATA_16
#include "MemMap.h"




/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


#define CANTP_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Array that holds the CanTp resources (State machines,     
                    variables, etc..) used for each CanTpConnection for       
                    each configured CanTpChannel                              */
/******************************************************************************/
VAR(CanTp_tstrChannelResources, CANTP_VAR) 
                     CanTp_astreChannelsResources[CanTp_u16NUM_OF_TP_RESOURCES];

#define CANTP_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"


#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)

#define CANTP_START_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Array that holds the recent STmin value of each            
                    CanTpRxNSdu.                                              \n
                    This array is created only if the configuration parameter 
                    CanTp_bCHANGE_PARAMETER_API is configured ith STD_ON      */
/******************************************************************************/
VAR(uint8, CANTP_VAR) CanTp_au8eCurrentSTmin[CanTp_u16NUM_OF_RX_NSDUS];

/******************************************************************************/
/*! \Description    Array that holds the recent Block Size value of each       
                    CanTpRxNSdu.                                              \n
                    This array is created only if the configuration parameter 
                    CanTp_bCHANGE_PARAMETER_API is configured ith STD_ON      */
/******************************************************************************/
VAR(uint8, CANTP_VAR)
                           CanTp_au8eCurrentBlockSize[CanTp_u16NUM_OF_RX_NSDUS];

#define CANTP_STOP_SEC_VAR_8
#include "Memmap.h"

#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */


/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */
