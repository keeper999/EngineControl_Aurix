
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
/* !File            : CanTp_LocalCfg.h                                        */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
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
/* $Revision::   1.0      $$Author::   madel          $$Date::   Nov 22 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_LocalCfg.h
*
* \par
*   This file contains the types used by the pre-compile time configuration
    parameters of the CanTp Component. These types are used locally by the
    CanTp Component, thus shall not be exported to CanTp users                */
/******************************************************************************/
#ifndef CANTP_LOCALCFG_H
#define CANTP_LOCALCFG_H


#include "Std_Types.h"
#include "CanTp_Cfg.h"
#include "ComStack_Types.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of CanTpChannels                                   \n
*******************************************************************************/

#define CanTp_u8NUM_OF_TP_CHANNELS      4
/*  \ConfigTool     -Shall be configured with the number of instances created
                     from CanTpChannel sub-container                          */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of CanTpConnections (CanTpChannelResources) needed \n
*******************************************************************************/
#define CanTp_u16NUM_OF_TP_RESOURCES    4
/*  \ConfigTool     -Derived from the number of instances created from 
                     CanTpChannel container where 2 CanTpConnections are needed
                     for each CanTpChannel with CanTpChannelMode 
                     CANTP_MODE_FULL_DUPLEX, and 1 CanTpConnection is needed for
                     each CanTpChannel with CanTpChannelMode 
                     CANTP_MODE_HALF_DUPLEX. So the formula used to derive the
                     value can be = (2 * No. of full-duplex channels) + No. of
                     half-duplex channels                                     */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of CanTpRxNSdus                                    \n
*******************************************************************************/

#define CanTp_u16NUM_OF_RX_NSDUS        4
/*  \ConfigTool     -Shall be configured with the number of instances created
                     from CanTpRxNSdu sub-container                           */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of CanTpTxNSdus                                    \n
*******************************************************************************/

#define CanTp_u16NUM_OF_TX_NSDUS        4
/*  \ConfigTool     -Shall be configured with the number of instances created
                     from CanTpTxNSdu sub-container                           */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of unique RxNPduIds configured for reception.      \n
                    An RxNPduId can be either an RxFcNPduId within a TxNSdu   
                    (used for FC reception) or an RxNPduId within an RxNSdu   
                    (used for SF,FF, or CF reception)                         \n
*******************************************************************************/

#define CanTp_u16NUM_OF_RX_PDU_IDS      4
/*  \ConfigTool     -The parameter shall be configured with the number of unique
                     RxPduIds including either RxFcNPduId of TxNSdu 
                     (udtRxFcNPduId)or RxNPduId of RxNSdu(udtRxNPduId)
                    -RxPduIds can be duplicated under certain conditions 
                     defined by Configuration Rule-Checks section in the CDD, so
                     this parameter must contain the number of only unique
                     RxPduIds                                                 */
/******************************************************************************/                    

/******************************************************************************/
/*! \Description    Number of unique TxNPduIds configured for transmission    
                    confirmation.                                             \n
                    A TxNPduId can be either an CanTpTxFcNPduConfirmationPduId
                    within an RxNSdu (used for FC transmission confirmation)  
                    or a CanTpTxNPduConfirmationPduId within a TxNSdu         
                    (used for SF,FF, or CF transmission confirmation)         \n
*******************************************************************************/

  
#define CanTp_u16NUM_OF_TX_PDU_IDS      4
/*  \ConfigTool     -The parameter shall be configured with the number of unique
                     TxPduIds including either CanTpTxFcNPduConfirmationPduId of
                     RxNSdu (udtTxFcConfPduId) or CanTpTxNPduConfirmationPduId 
                     of TxNSdu(udtTxConfPduId)
                    -TxPduIds can be duplicated under certain conditions 
                     defined by Configuration Rule-Checks section in the CDD, so
                     this parameter must contain the number of only unique
                     TxPduIds                                                 */
/******************************************************************************/  

/******************************************************************************/
/*! \Description    Number of NSdus that will handle a transmission           
                    confirmation operation which include:                     \n
                    -All CanTpTxNSdus                                         \n
                    -CanTpRxNSdus that will handle multiple frame reception   
                     (flow control frame will be transmitted so transmission  
                     confirmation is needed)                                  \n
*******************************************************************************/
#define CanTp_u16SIZE_OF_TXPDU_LIST     8
/*  \ConfigTool     -The parameter shall be configured with the number of NSdus
                     that will handle transmission confirmation operations.
                     The NSdus that will transmission confirmation operations
                     are:
                     1-All CanTpTxNSdus
                     2-CanTpRxNSdus whose optional sub-container CanTpTxFcNPdu
                       was created.                                           */
/******************************************************************************/ 

/******************************************************************************/
/*! \Description    Number of NSdus that will handle receive operations which 
                    include:                                                  \n
                    -All CanTpRxNSdus                                         \n
                    -CanTpTxNSdus that will handle multiple frame reception   
                     (flow control frames will be received)                   \n
*******************************************************************************/
#define CanTp_u16SIZE_OF_RXPDU_LIST     8
/*  \ConfigTool     -The parameter shall be configured with the number of NSdus
                     that will handle receive operations. The NSdus that will 
                     handle receive operations are:
                     1-All CanTpRxNSdus
                     2-CanTpTxNSdus whose optional sub-container CanTpRxFcNPdu
                       was created.                                           */
/******************************************************************************/ 

/******************************************************************************/
/*! \Description    Number of unique Exclusive Areas referenced by
                    CanTpChannelBswSchExclAreaIdRef for all CanTpChannels     \n
*******************************************************************************/
#define CanTp_u8NUM_OF_EXC_AREAS        1
/*  \ConfigTool     -Shall be configured with the number of unique exclusive
                     area IDs referenced by CanTpChannelBswSchExclAreaIdRef
                     of all CanTpChannels                                     */
/******************************************************************************/




/******************************************************************************/
/*! \Description    Value of the element u8ChannelType of the configuration   
                    structure of type CanTp_tstrChannelCfgType when           
                    a CanTpChannel is configured as a full-duplex channel     \n
*******************************************************************************/
#define CanTp_u8FULL_DUPLEX_CHANNEL     (uint8)0x0
/******************************************************************************/
/*! \Description    Value of the element u8ChannelType of the configuration   
                    structure of type CanTp_tstrChannelCfgType when           
                    a CanTpChannel is configured as a half-duplex channel     \n
*******************************************************************************/
#define CanTp_u8HALF_DUPLEX_CHANNEL     (uint8)0x1


/******************************************************************************/
/*! \Description    Value of the elements u8RxAddressingFormat/               
                    u8TxAddressingFormat of the configuration structures      
                    of type CanTp_tstrRxNSduPCCfgType\                        
                    CanTp_tstrTxNSduPCCfgType when  a CanTpRxNSdu/CanTpTxNsdu 
                    is configured with Standard addressing format             \n
*******************************************************************************/
#define CanTp_u8STANDARD_ADDRESSING     (uint8)0x0
/******************************************************************************/
/*! \Description    Value of the elements u8RxAddressingFormat/               
                    u8TxAddressingFormat of the configuration structures      
                    of type CanTp_tstrRxNSduPCCfgType\                        
                    CanTp_tstrTxNSduPCCfgType when a CanTpRxNSdu/CanTpTxNsdu  
                    is configured with Extended addressing format             \n
*******************************************************************************/
#define CanTp_u8EXTENDED_ADDRESSING     (uint8)0x01
/******************************************************************************/
/*! \Description    Value of the elements u8RxAddressingFormat/               
                    u8TxAddressingFormat of the configuration structures      
                    of type CanTp_tstrRxNSduPCCfgType\                        
                    CanTp_tstrTxNSduPCCfgType when a CanTpRxNSdu/CanTpTxNsdu  
                    is configured with Mixed addressing format                \n
*******************************************************************************/
#define CanTp_u8MIXED_ADDRESSING        (uint8)0x02


/******************************************************************************/
/*! \Description    Value of the elements u8RxPaddingActivation/              
                    u8TxPaddingActivation of the configuration structures     
                    of type CanTp_tstrRxNSduPCCfgType\                        
                    CanTp_tstrTxNSduPCCfgType when a CanTpRxNSdu/CanTpTxNsdu  
                    is configured with padding disabled                       \n
*******************************************************************************/
#define CanTp_u8PADDING_OFF             (uint8)0x0
/******************************************************************************/
/*! \Description    Value of the elements u8RxPaddingActivation/              
                    u8TxPaddingActivation of the configuration structures     
                    of type CanTp_tstrRxNSduPCCfgType\                        
                    CanTp_tstrTxNSduPCCfgType when a CanTpRxNSdu/CanTpTxNsdu  
                    is configured with padding enabled                        \n
*******************************************************************************/
#define CanTp_u8PADDING_ON              (uint8)0x01


/******************************************************************************/
/*! \Description    Value of the elements u8RxTaType/u8RxTaType of the        
                    configuration structures of type                          
                    CanTp_tstrRxNSduPCCfgType\CanTp_tstrTxNSduPCCfgType when  
                    a CanTpRxNSdu/CanTpTxNsdu is configured with Functional   
                    request type                                              \n
*******************************************************************************/
#define CanTp_u8FUNCTIONAL_ADDRESS      (uint8)0x0
/******************************************************************************/
/*! \Description    Value of the elements u8RxTaType/u8RxTaType of the        
                    configuration structures of type                          
                    CanTp_tstrRxNSduPCCfgType\CanTp_tstrTxNSduPCCfgType when  
                    a CanTpRxNSdu/CanTpTxNsdu is configured with Physical     
                    request type                                              \n
*******************************************************************************/
#define CanTp_u8PHYSICAL_ADDRESS        (uint8)0x01


/******************************************************************************/
/*! \Description    Value of the element u8NSduDirection of the               
                    configuration structure of type CanTp_tstrNPduListType\   
                    when this entry is referring to a CanTpRxNSdu             \n
*******************************************************************************/
#define CanTp_u8RX_NSDU                 (uint8)0x0
/******************************************************************************/
/*! \Description    Value of the element u8NSduDirection of the               
                    configuration structure of type CanTp_tstrNPduListType\   
                    when this entry is referring to a CanTpTxNSdu             \n
*******************************************************************************/
#define CanTp_u8TX_NSDU                 (uint8)0x01


/******************************************************************************/
/*! \Description    Size of the local buffer used by a CanTpConnection        \n
*******************************************************************************/
#define CanTp_u8LOCAL_BUFFER_SIZE       (uint8)8




/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/*! \Description    Defines a pointer to Enter Critical Section service
*******************************************************************************/
typedef P2FUNC(void, CANTP_APPL_CODE, CanTp_tpfvidEnterCriticalSec)(void);

/******************************************************************************/
/*! \Description    Defines a pointer to Exit Critical Section service
*******************************************************************************/
typedef P2FUNC(void, CANTP_APPL_CODE, CanTp_tpfvidExitCriticalSec)(void);




/******************************************************************************/
/*! \Description    Defines the critical sections needed for each exclusive
                    area ID                                                   /n
*******************************************************************************/
typedef struct
{
    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec001_42;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec001_42;

	/*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec001_03;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec001_03;

	/*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec001_06;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 001                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec001_06;

    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec002_42;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec002_42;

    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec002_40;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec002_40;
    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec002_08;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec002_08;
    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec002_06;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 002                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec002_06;

    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec003_42;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec003_42;

    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec003_40;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec003_40;
	
    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec003_09;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec003_09;
	
    /*! \Description    Pointer to Enter Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidEnterCriticalSec, AUTOMATIC) pfvidEnterCriticalSec003_06;

    /*! \Description    Pointer to Exit Critical Section service to protect
                        the critical region defined by 003                    */
    VAR(CanTp_tpfvidExitCriticalSec, AUTOMATIC)  pfvidExitCriticalSec003_06;
}CanTp_tstrCriticalSectionsType;
/******************************************************************************/


/******************************************************************************/
/*! \Description    Defines the CanTpChannel properties
*******************************************************************************/
typedef struct
{
    /*! \Description            Mode of the CanTpChannel                      \n
        \Range                  CanTp_u8FULL_DUPLEX_CHANNEL/                  
                                CanTp_u8HALF_DUPLEX_CHANNEL                   */
    VAR(uint8, AUTOMATIC)       u8ChannelMode;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpChannelMode
                                -CANTP_MODE_FULL_DUPLEX -> 
                                                   CanTp_u8FULL_DUPLEX_CHANNEL
                                -CANTP_MODE_HALF_DUPLEX -> 
                                                   CanTp_u8HALF_DUPLEX_CHANNEL*/
    /**************************************************************************/
    /*! \Description            Index of the CanTpConnection resources -within
                                the array CanTp_astreChannelsResources- that  
                                this CanTpChannel will use for transmission   \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16IndexOfTxResources;
    /* \ConfigTool              -This element shall be configured with the index
                                 of the first unused CanTpConnection resources
                                 within the array CanTp_astreChannelsResources
                                 starting from index 0 that shall be used for
                                 u16IndexOfTxResources of the first 
                                 CanTpChannel                                 */
    /**************************************************************************/

    /*! \Description            Index of the CanTpConnection resources -within
                                the array CanTp_astreChannelsResources- that  
                                this CanTpChannel will use for reception      \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16IndexOfRxResources;
    /* \ConfigTool              -If CanTpChannelMode of this CanTpChannel is
                                 configured with CANTP_MODE_HALF_DUPLEX, then
                                 this element shall be configured with the same
                                 value of u16IndexOfTxResources of this
                                 CanTpChannel as a single CanTpConnection will
                                 be shared between transmission and reception
                                -If CanTpChannelMode of this CanTpChannel is
                                 configured with CANTP_MODE_FULL_DUPLEX, then
                                 this element shall be configured with the index
                                 that directly follows the index used for 
                                 u16IndexOfTxResources of this CanTpChannel   */
    /**************************************************************************/

    /*! \Description            Index of the Critical Section Services of this
                                CanTpChannel in the array
                                CanTp_akstreCriticalSections                  \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8IndexOfCriticalSec;
}
CanTp_tstrChannelCfgType;
/******************************************************************************/

/******************************************************************************/
/*! \Description    Defines the pre-compile time configuration parameters for 
                    each CanTpRxNSdu                                          \n
*******************************************************************************/
typedef struct
{
    /*! \Description            Addressing Format                             \n
        \Range                  CanTp_u8STANDARD_ADDRESSING,                  
                                CanTp_u8EXTENDED_ADDRESSING,                  
                                CanTp_u8MIXED_ADDRESSING                      */
    VAR(uint8, AUTOMATIC)       u8RxAddressingFormat;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpRxAddressingFormat
                                -CANTP_EXTENDED -> CanTp_u8EXTENDED_ADDRESSING
                                -CANTP_MIXED    -> CanTp_u8MIXED_ADDRESSING
                                -CANTP_STANDARD -> CanTp_u8STANDARD_ADDRESSING*/
    /**************************************************************************/

    /*! \Description            Minimum Data Length for this CanTpRxNSdu      \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16RxDataLengthCode;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpRxDl                        */
    /**************************************************************************/

    /*! \Description            Padding Activation                            \n
        \Range                  CanTp_u8PADDING_OFF/CanTp_u8PADDING_ON        */
    VAR(uint8, AUTOMATIC)       u8RxPaddingActivation;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpRxPaddingActivation
                                -CANTP_OFF -> CanTp_u8PADDING_OFF
                                -CANTP_ON  -> CanTp_u8PADDING_OFN             */    
    /**************************************************************************/

    /*! \Description            Communication Request Type                    \n
        \Range                  CanTp_u8FUNCTIONAL_ADDRESS,                   
                                CanTp_u8PHYSICAL_ADDRESS                      */
    VAR(uint8, AUTOMATIC)       u8RxTaType;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpRxTaType
                                -CANTP_FUNCTIONAL -> CanTp_u8FUNCTIONAL_ADDRESS
                                -CANTP_PHYSICAL   -> CanTp_u8PHYSICAL_ADDRESS */    
    /**************************************************************************/

    /*! \Description            Handle Id to be used by the CanIf to indicate 
                                the reception of a CanTpRxNPdu (SF, FF,       
                                or CF)                                        \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtRxNPduId;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpRxNPdu\CanTpRxNPduId                
                                -Refer to Configuration Rule-Checks section in 
                                 the CDD for the rules that shall be followed
                                 while configuring this parameter             */
    /**************************************************************************/

    /*! \Description            Handle Id to be used by the CanIf to confirm  
                                the transmission of a Flow Control            
                                CanTpTxFcNPdu to the CanIf module             \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtTxFcConfPduId;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpTxFcNPdu\
                                 CanTpTxFcNPduConfirmationPduId         
                                -If the optional sub-container CanTpTxFcNPdu
                                 was not created then this handle Id shall be
                                 configured with the value 0
                                -Refer to Configuration Rule-Checks section in 
                                 the CDD for the rules that shall be followed
                                 while configuring this parameter             */
    /**************************************************************************/
    
    /*! \Description            Target Address value                          \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NTargetAddress;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpNTa\CanTpNTa                
                                -The sub-container CanTpNTa is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpRxAddressingFormat 
                                 for this CanTpRxNSdu is set to CANTP_EXTENDED.
                                 If the container is not created, 
                                 u8NTargetAddress shall be set to 0xFF        */
    /**************************************************************************/

    /*! \Description            Source Address value                          \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NSourceAddress;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpNSa\CanTpNSa                
                                -The sub-container CanTpNSa is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpRxAddressingFormat 
                                 for this CanTpRxNSdu is set to CANTP_EXTENDED.
                                 If the container is not created, 
                                 u8NSourceAddress shall be set to 0xFF        */
    /**************************************************************************/

    /*! \Description            Address Extension value                       \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NAddressExtension;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpNAe\CanTpNAe                
                                -The sub-container CanTpNAe is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpRxAddressingFormat 
                                 for this CanTpRxNSdu is set to CANTP_MIXED.
                                 If the container is not created, 
                                 u8NAddressExtension shall be set to 0xFF     */
    /**************************************************************************/

    /*! \Description            ID of the CanTpChannel that this CanTpRxNSdu  
                                belongs to                                    \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8ChannelNumber;
    /* \ConfigTool              -The value of u8ChannelNumber is not directly 
                                 derived from a configuration parameter, it is
                                 configured with the instance ID of CanTpChannel
                                 container in which this CanTpRxNSdu is
                                 contained. The CanTpChannel instances IDs are
                                 sequential starting from the value 0.        */
    /**************************************************************************/
}
CanTp_tstrRxNSduPCCfgType;
/******************************************************************************/


/******************************************************************************/
/*! \Description    Defines the pre-compile time configuration parameters for 
                    each CanTpTxNSdu                                          \n
*******************************************************************************/
typedef struct
{
    /*! \Description            Transmit Cancellation Support                 \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bTransmitCancellation;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpTxNSdu\CanTpTc                         
                                -true  -> TRUE
                                -false -> FALSE                               */
    /**************************************************************************/

    /*! \Description            Addressing Format                             \n
        \Range                  CanTp_u8STANDARD_ADDRESSING,                  
                                CanTp_u8EXTENDED_ADDRESSING,                  
                                CanTp_u8MIXED_ADDRESSING                      */
    VAR(uint8, AUTOMATIC)       u8TxAddressingFormat;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxAddressingFormat
                                -CANTP_EXTENDED -> CanTp_u8EXTENDED_ADDRESSING
                                -CANTP_MIXED    -> CanTp_u8MIXED_ADDRESSING
                                -CANTP_STANDARD -> CanTp_u8STANDARD_ADDRESSING*/
    /**************************************************************************/

    /*! \Description            Minimum Data Length for this CanTpTxNSdu      \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16TxDataLengthCode;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxDl                        */
    /**************************************************************************/

    /*! \Description            Padding Activation                            \n
        \Range                  CanTp_u8PADDING_OFF/CanTp_u8PADDING_ON        */
    VAR(uint8, AUTOMATIC)       u8TxPaddingActivation;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxPaddingActivation
                                -CANTP_OFF -> CanTp_u8PADDING_OFF
                                -CANTP_ON  -> CanTp_u8PADDING_OFN             */    
    /**************************************************************************/

    /*! \Description            Communication Request Type                    \n
        \Range                  CanTp_u8FUNCTIONAL_ADDRESS,                   
                                CanTp_u8PHYSICAL_ADDRESS                      */
    VAR(uint8, AUTOMATIC)       u8TxTaType;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxTaType
                                -CANTP_FUNCTIONAL -> CanTp_u8FUNCTIONAL_ADDRESS
                                -CANTP_PHYSICAL   -> CanTp_u8PHYSICAL_ADDRESS */    
    /**************************************************************************/

    /*! \Description            Handle Id to be used by the CanIf to confirm  
                                the transmission of a CanTpTxNPdu (SF, FF,    
                                or CF) to the CanIf module                    \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtTxConfPduId;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxNPdu\
                                 CanTpTxNPduConfirmationPduId                
                                -Refer to Configuration Rule-Checks section in 
                                 the CDD for the rules that shall be followed
                                 while configuring this parameter             */
    /**************************************************************************/

    /*! \Description            Handle Id to be used by the CanIf to indicate 
                                the reception of a Flow Control CanTpRxFcNPdu \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtRxFcNPduId;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpRxFcNPdu\CanTpRxFcNPduId
                                -If the optional sub-container CanTpRxFcNPduId
                                 was not created then this handle Id shall be
                                 configured with the value 0
                                -Refer to Configuration Rule-Checks section in 
                                 the CDD for the rules that shall be followed
                                 while configuring this parameter             */
    /**************************************************************************/

    /*! \Description            Target Address value                          \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NTargetAddress;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpNTa\CanTpNTa                
                                -The sub-container CanTpNTa is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpTxAddressingFormat 
                                 for this CanTpTxNSdu is set to CANTP_EXTENDED.
                                 If the container is not created, 
                                 u8NTargetAddress shall be set to 0xFF        */
    /**************************************************************************/
    
    /*! \Description            Source Address value                          \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NSourceAddress;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpNSa\CanTpNSa                
                                -The sub-container CanTpNSa is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpTxAddressingFormat 
                                 for this CanTpTxNSdu is set to CANTP_EXTENDED.
                                 If the container is not created, 
                                 u8NSourceAddress shall be set to 0xFF        */
    /**************************************************************************/

    /*! \Description            Address Extension value                       \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8NAddressExtension;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpNAe\CanTpNAe                
                                -The sub-container CanTpNAe is an optional      
                                 container that must be created only if the
                                 configuration parameter CanTpTxAddressingFormat 
                                 for this CanTpTxNSdu is set to CANTP_MIXED.
                                 If the container is not created, 
                                 u8NAddressExtension shall be set to 0xFF     */
    /**************************************************************************/

    /*! \Description            ID of the CanTpChannel that this CanTpTxNSdu  
                                belongs to                                    \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)       u8ChannelNumber;
    /* \ConfigTool              -The value of u8ChannelNumber is not directly 
                                 derived from a configuration parameter, it is
                                 configured with the instance ID of CanTpChannel
                                 container in which this CanTpTxNSdu is
                                 contained. The CanTpChannel instances IDs are
                                 sequential starting from the value 0.        */
    /**************************************************************************/
}
CanTp_tstrTxNSduPCCfgType;
/******************************************************************************/

/******************************************************************************/
/*! \Description    Defines references to CanTpTxNSdu/CanTpRxNSdu in order to 
                    determine the CanTpNSdu from the TxPduId (in case of      
                    tranmission confirmation) or from the RxPduId (in case    
                    of reception)                                             \n
*******************************************************************************/
typedef struct
{
    /*! \Description            Determines the type of the CanTpNSdu that this
                                entry refers to (whether it refers to a       
                                a CanTpTxNSdu or a CanTpRxNSdu                \n
        \Range                  CanTp_u8TX_NSDU/CanTp_u8RX_NSDU               */
    VAR(uint8, AUTOMATIC)       u8NSduDirection;
    /* \ConfigTool              -If this entry refers to a CanTpTxNSdu then
                                 the value of u8NSduDirection shall be 
                                 configured  with CanTp_u8TX_NSDU, while if this
                                 entry refers to a CanTpRxNSdu then the value
                                 of u8NSduDirection shall be configured with 
                                 CanTpRxNSdu                                  */
    /**************************************************************************/

    /*! \Description            Determines the index of the CanTpNSdu -that   
                                this entry refers- in its corresponding array 
                                (Index in CanTp_akstreTxNSduPCCfg if this     
                                entry refers to a CanTpTxNSdu and index in    
                                CanTp_akstreRxNSduPCCfg if this entry refers  
                                to a CanTpRxNSdu                              \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16IndexInNSduArray;
    /* \ConfigTool              -If this entry refers to a CanTpTxNSdu then
                                 the value of u16IndexInNSduArray shall be 
                                 configured  with the index of the CanTpTxNSdu
                                 in CanTp_akstreTxNSduPCCfg
                                -If this entry refers to a CanTpRxNSdu then
                                 the value of u16IndexInNSduArray shall be 
                                 configured  with the index of the CanTpRxNSdu
                                 in CanTp_akstreRxNSduPCCfg                   */
    /**************************************************************************/
}
CanTp_tstrNPduListType;




/******************************************************************************/
/*! \Description    Defines a mapping table entry used to optimize the        
                    searching process that will be performed to identify the  
                    CanTpNSdu from the RxPduId received                       */
/******************************************************************************/
typedef struct
{
    /*! \Description            Determines the start index in                 
                                CanTp_akstreRxNPduList that corresponds to    
                                this RxPduId                                  \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16IndexInRxNPduList;
    /* \ConfigTool              -Shall be configured with the start index of the
                                 group in CanTp_akstreRxNPduList that 
                                 corresponds to this RxPduId                  */
    /**************************************************************************/

    /*! \Description            Determines the addressing format used for this
                                RxPduId                                       \n
        \Range                  CanTp_u8STANDARD_ADDRESSING,                  
                                CanTp_u8EXTENDED_ADDRESSING,                  
                                CanTp_u8MIXED_ADDRESSING                      */
    VAR(uint8, AUTOMATIC)       u8NPduAddressingFormat;
    /* \ConfigTool              -Shall be configured with the addressing format
                                 type that this RxPduId is using              */
    /**************************************************************************/
}
CanTp_tstrRxNPduMappingType;





/******************************************************************************/
/*! \Description    A type that groups all the variables needed for saving
                    the un-expected PDU received on a certain CanTpConnection
                    in order to be handled in the next CanTp Main Function    */
/******************************************************************************/
typedef struct
{
    /*! \Description            A flag that determines whether an un-expected 
                                PDU was received on this CanTpConnection or
                                not                                           \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bUnExpPduReceived;

    /*! \Description            ID of the CanTpRxNSdu which the un-expected PDU
                                received belongs                              \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtRxNSduId;

    /*! \Description            Array to hold the un-expected PDU received 
                                in order to be handled on the next Main 
                                Function                                      */
    VAR(uint8, AUTOMATIC)       au8UnExpectedPdu[CanTp_u8LOCAL_BUFFER_SIZE];

    /*! \Description            Length of the un-expected PDU received        \n
        \Range                  2..8                                          */
    VAR(uint8, AUTOMATIC)       u8UnExpectedPduLen;
}
CanTp_tstrUnExpectedPduType;




/******************************************************************************/
/*! \Description    A type that groups all the variables needed for saving
                    a cancellation request received on a certain 
                    CanTpConnection in order to be handled in the next CanTp
                    Main Function                                             */
/******************************************************************************/
typedef struct
{
    /*! \Description            A flag that determines whether a cancellation 
                                request was received on this CanTpConnection 
                                or not                                        \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bCancellationRequest;
    
    /*! \Description            ID of the CanTpNSdu which the cancellation
                                request received belongs                      \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtCancelledNSduId;
}
CanTp_tstrCancelRequestType;




/******************************************************************************/
/*! \Description    A type that groups all the variables needed for saving
                    a Consecutive Frame reception error on a certain
                    CanTpConnection in order to be handled in the next CanTp
                    Main Function                                             */
/******************************************************************************/
typedef struct
{
    /*! \Description            A flag that determines whether a consecutive
                                frame reception error occurred on this 
                                CanTpConnection or not                        \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bCFReceptionError;

    /*! \Description            The error type that occurred during consecutive
                                frame reception on this CanTpConnection       */
    VAR(NotifResultType, AUTOMATIC)
                                udtNotificationresult;
}
CanTp_tstrCFReceptionErrorType;




/******************************************************************************/
/*! \Description    Defines the CanTp resources (State machines, variables,   
                    etc..) used for each CanTpConnection. A single            
                    CanTpConnection is needed for a half-duplex CanTpChannel  
                    to be shared between transmission and reception. While two
                    CanTpConnections are needed for a full-fuplex CanTpChannel
                    one for transmission and another for reception            \n
*******************************************************************************/
typedef struct
{
    /*! \Description            Current state of the CanTpConnection          \n
        \Range                  Refer to CanTp_Utilities.h for detailed       
                                explaination for the possible state values    */
    VAR(uint8, AUTOMATIC)       u8ConnectionState;

    /*! \Description            ID of the CanTpNSdu that is currently being   
                                handled.                                      \n
                                If the CanTpConnection is being used for      
                                transmission then this variable holds the     
                                CanTpTxNSduId of the CanTpTxNSdu being        
                                transmitted, while if the CanTpConnection is  
                                being used for reception then this variable   
                                holds the CanTpRxNSduId of the CanTpRxNSdu    
                                being received                                \n
        \Range                  0..65535                                      */
    VAR(PduIdType, AUTOMATIC)   udtHandledNSduId;

    /*! \Description            Remaining message length in bytes             \n
                                If the CanTpConnection is being used for      
                                transmission then this variable represents    
                                the number of bytes remaining to be           
                                transmitted to the CanIf out of the total     
                                message length requested for transmission.    \n
                                If the CanTpConnection is being used for      
                                reception then this variable represents the   
                                number of bytes remaining to be received from 
                                the CanIf out of the total message length to  
                                be received (specified by the First Frame)    \n                                 
        \Range                  0..4095                                       \n
        \Unit                   Bytes                                         */
    VAR(uint16, AUTOMATIC)      u16MessageLength;

    /*! \Description            Time remaining till timeout occurs.           \n
                                This time is represented as multiples of the  
                                main function periodicity, so it represents   
                                the number of main function calls remaining   
                                till timeout occurs. This variable is         
                                decremented on each main function call, and   
                                when it reaches the value 0 this means that   
                                a timeout shall occur and transmission or     
                                or reception process taking place shall be    
                                aborted.                                      \n
        \Range                  0..65535                                      \n
        \Unit                   Main Function Calls                           */
    VAR(uint16, AUTOMATIC)      u16TimeoutCounter;

    /*! \Description            A local buffer used to hold the frame data    \n
                                If the CanTpConnection is being used for      
                                transmission, then this local buffer is used  
                                to hold the data + PCI of the next frame to be
                                transmitted and this buffer is passed to the  
                                CanIf.                                        \n
                                If the CanTpConnection is being used for      
                                reception, then this local buffer is used to  
                                hold only the data of the last frame received 
                                from the CanIf.                               \n
                                In transmission 8 bytes are needed for the    
                                data + PCI while in reception only 7 bytes    
                                needed to hold the data, so the buffer is     
                                created with 8 bytes to be able to be used    \n
                                for both transmission and reception.          */
    VAR(uint8, AUTOMATIC)       au8LocalDataBuffer[CanTp_u8LOCAL_BUFFER_SIZE];

    /*! \Description            Number of data bytes currently in the local   
                                buffer.                                       \n
                                If the CanTpConnection is being used for      
                                transmission, then this variable represents   
                                the number of data bytes -of the next frame-  
                                that have been received from the upper layer  
                                in order to be transmitted to the CanIf.      \n
                                If the CanTpConnection is being used for      
                                reception, then this variable represents the  
                                number of data bytes -of the received frame-  
                                that have been copied by the upper layer      \n
        \Range                  0..7                                          \n
        \Unit                   Bytes                                         */
    VAR(uint8, AUTOMATIC)       u8BytesInLocalBuffer;

    /*! \Description            Number of consecutive frames remaining in the 
                                current block.                                \n
                                If the CanTpConnection is being used for      
                                transmission, then this variable represents   
                                the number of consecutive frames remaining to 
                                be transmitted in the current block.          \n
                                If the CanTpConnection is being used for      
                                reception, then this variable represents the  
                                number of consecutive frames remaining to be  
                                received in the current block                 \n
        \Range                  0..682                                        \n
        \Unit                   Frames                                        */
    VAR(uint16, AUTOMATIC)      u16BlockSize;

    /*! \Description            The sequence number of the last frame         \n
                                If the CanTpConnection is being used for      
                                transmission, then this variable represents   
                                the sequence number of the last transmitted   
                                frame.                                        \n
                                If the CanTpConnection is being used for      
                                reception, then this variable represents the  
                                sequence number of the last received frame    \n
        \Range                  0..15                                         */
    VAR(uint8, AUTOMATIC)       u8SequenceNumber;

    /*! \Description            A flag to indicate whether the next           \n
                                consecutive frame is the last frame in message
                                or not.                                       \n
                                If the CanTpConnection is being used for      
                                transmission, then this variable indicates    
                                whether the next consecutive frame to be      
                                transmitted is the last frame in the message  
                                or not.                                       \n
                                If the CanTpConnection is being used for      
                                reception, then this variable indicates       
                                whether the next consecutive frame to be      
                                received is the last frame in the message or  \n
                                not                                           \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bLastFrameInMsg;

#if(CanTp_bCANIF_TRANSMIT_RETRY == STD_ON)
    /*! \Description            A flag to indicate whether the first transmit 
                                retry was performed or not.                   \n
                                This variable is only available if the        
                                transmit retry feature is enabled(the config. 
                                parameter CanTp_bCANIF_TRANSMIT_RETRY is      
                                configured with STD_ON)                       \n
                                This variable is only used if the             
                                CanTpConnection is being used for transmission
                                while it is not used if the CanTpConnection is
                                being used for reception                      \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bFirstTransmitRetry;

    /*! \Description            The DLC of the frame to be transmitted(saved  
                                in order not to re-calculate it upon          
                                transmission retry.                           \n
                                This variable is only available if the        
                                transmit retry feature is enabled(the config. 
                                parameter CanTp_bCANIF_TRANSMIT_RETRY is      
                                configured with STD_ON)                       \n
                                This variable is only used if the             
                                CanTpConnection is being used for transmission
                                while it is not used if the CanTpConnection is
                                being used for reception                      \n
        \Range                  0..8                                          */
    VAR(uint8, AUTOMATIC)       u8FrameDlc;
#endif  /* CanTp_bCANIF_TRANSMIT_RETRY == STD_ON */
    
    /*! \Description            Time remaining till STmin passes.             \n
                                This time is represented as multiples of the  
                                main function periodicity, that when the value
                                of u16TimeoutCounter reaches then the STmin   
                                has passed                                    \n
                                This variable is only used if the             
                                CanTpConnection is being used for transmission
                                while it is not used if the CanTpConnection is
                                being used for reception                      \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16STminTimeoutValue;

    /*! \Description            A flag to indicate whether STmin has passed   
                                and the consecutive frame can be transmitted  
                                or not.                                       \n
                                This variable is only used if the             
                                CanTpConnection is being used for transmission
                                while it is not used if the CanTpConnection is
                                being used for reception                      \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bSTminPassed;
    
    /*! \Description            A structure that groups all the variables
                                needed for saving a transmission cancellation
                                request received on this CanTpConnection in 
                                order to be handled in the next CanTp Main 
                                Function                                      \n
                                This variable is only used if the             
                                CanTpConnection is being used for transmission   
                                while it is not used if the CanTpConnection is
                                being used for reception                      */
    VAR(CanTp_tstrCancelRequestType, AUTOMATIC)
                                strTxCancelRequest;
    
    /*! \Description            A flag to indicate whether a buffer has been  
                                allocated for reception by the upper layer or 
                                not yet. A buffer is not considered as        
                                allocated till PduR_CanTpStartOfReception     
                                returns BUFREQ_OK.                            \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bBufferAllocated;

    /*! \Description            Number of successive Flow Control frames with 
                                flow status = WAIT that have been transmitted.\n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is\n
                                being used for transmission                   */
    VAR(uint8, AUTOMATIC)       u8NumOfFCWaitFrames;

    /*! \Description            A flag to indicate whether all the data bytes 
                                received by the first frame have been copied  
                                successfully by the upper layer or not yet.   \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bFirstFrameReceived;
#if(CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON)
    /*! \Description            A flag to indicate whether the flow control   
                                frame will be transmitted with BS(Block Size) 
                                with value 0 or not.                          \n
                                This variable is only available if the        
                                dynamic block size feature is enabled         
                                (the configuration parameter                  
                                CanTp_bDYNAMIC_RX_BLOCKSIZE is configured with
                                STD_ON)                                       \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   \n
        \Range                  TRUE/FALSE                                    */
    VAR(boolean, AUTOMATIC)     bFCWithZeroBS;
#endif  /* CanTp_bDYNAMIC_RX_BLOCKSIZE == STD_ON */

    /*! \Description            A structure that groups all the variables
                                needed for saving an un-expected PDU received
                                on this CanTpConnection in order to be handled
                                in the next CanTp Main Function               \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   */
    VAR(CanTp_tstrUnExpectedPduType, AUTOMATIC)
                                strUnExpectedPdu;

    /*! \Description            A structure that groups all the variables
                                needed for saving a Consecutive Frame reception
                                error on this CanTpConnection in order to be 
                                handled in the next CanTp Main Function       \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   */
    VAR(CanTp_tstrCFReceptionErrorType, AUTOMATIC)
                                strCFReceptionError;

    /*! \Description            A structure that groups all the variables
                                needed for saving a reception cancellation
                                request received on this CanTpConnection in 
                                order to be handled in the next CanTp Main 
                                Function                                      \n
                                This variable is only used if the             
                                CanTpConnection is being used for reception   
                                while it is not used if the CanTpConnection is
                                being used for transmission                   */
    VAR(CanTp_tstrCancelRequestType, AUTOMATIC)
                                strRxCancelRequest;
}
CanTp_tstrChannelResources;
/******************************************************************************/




/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define CANTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST (CanTp_tstrCriticalSectionsType, CANTP_CFG_CONST)
                         CanTp_akstreCriticalSections[CanTp_u8NUM_OF_EXC_AREAS];

#define CANTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#define CANTP_START_CONFIG_DATA_16
#include "MemMap.h"

extern CONST (CanTp_tstrChannelCfgType, CANTP_CFG_CONST)
                             CanTp_akstreTpChannels[CanTp_u8NUM_OF_TP_CHANNELS];

#define CANTP_STOP_CONFIG_DATA_16
#include "MemMap.h"

/******************************************************************************/
#define CANTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern CONST (CanTp_tstrTxNSduPCCfgType, CANTP_CFG_CONST) 
                              CanTp_akstreTxNSduPCCfg[CanTp_u16NUM_OF_TX_NSDUS];
extern CONST (CanTp_tstrRxNSduPCCfgType, CANTP_CFG_CONST)
                              CanTp_akstreRxNSduPCCfg[CanTp_u16NUM_OF_RX_NSDUS];

#define CANTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/

#define CANTP_START_CONFIG_DATA_16
#include "MemMap.h"

extern CONST (CanTp_tstrNPduListType, CANTP_CFG_CONST)
                            CanTp_akstreTxNPduList[CanTp_u16SIZE_OF_TXPDU_LIST];
extern CONST (CanTp_tstrNPduListType, CANTP_CFG_CONST)
                            CanTp_akstreRxNPduList[CanTp_u16SIZE_OF_RXPDU_LIST];
extern CONST (uint16, CANTP_CFG_CONST)
                     CanTp_aku16eTxNPduMappingTable[CanTp_u16NUM_OF_TX_PDU_IDS];
extern CONST (CanTp_tstrRxNPduMappingType, CANTP_CFG_CONST)
                     CanTp_akstreRxNPduMappingTable[CanTp_u16NUM_OF_RX_PDU_IDS];

#define CANTP_STOP_CONFIG_DATA_16
#include "MemMap.h"





/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
#define CANTP_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern VAR(CanTp_tstrChannelResources, CANTP_VAR) 
                     CanTp_astreChannelsResources[CanTp_u16NUM_OF_TP_RESOURCES];

#define CANTP_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"
/******************************************************************************/

#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)

#define CANTP_START_SEC_VAR_8
#include "Memmap.h"

extern VAR(uint8, CANTP_VAR) 
                               CanTp_au8eCurrentSTmin[CanTp_u16NUM_OF_RX_NSDUS];

extern VAR(uint8, CANTP_VAR) 
                           CanTp_au8eCurrentBlockSize[CanTp_u16NUM_OF_RX_NSDUS];

#define CANTP_STOP_SEC_VAR_8
#include "Memmap.h"

#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */

/******************************************************************************/


#endif /* CANTP_LOCALCFG_H */

/*-------------------------------- end of file -------------------------------*/
