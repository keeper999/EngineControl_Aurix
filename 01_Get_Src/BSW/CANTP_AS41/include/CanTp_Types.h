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
/* !File            : CanTp_Types.h                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/*! \file CanTp_Types.h
*
* \par
*   This file contains the public types -exported by the CanTp Component-     \n
    which are needed by the CanTp user                                        */
/******************************************************************************/
#ifndef CANTP_TYPES_H
#define CANTP_TYPES_H


#include "Std_Types.h"
#include "ComStack_Types.h"


/******************************************************************************/
/*! \Description    A type that defines the post-build time parameters for    
                    each CanTpTxNSdu.                                         /n
*******************************************************************************/
typedef struct
{
    /*! \Description            Timeout value of the N_As timeout.            \n
                                N_As is the time for transmission of a CAN 
                                frame (any N_PDU) on the part of the sender.  \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NAs;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpTxNSdu\CanTpNas and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNas (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            Timeout value of the N_Bs timeout.            \n
                                N_Bs is the time of transmission until 
                                reception of the next Flow Control N_PDU      \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NBs;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpTxNSdu\CanTpNbs and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNbs (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            Timeout value of the N_Cs timeout.            \n
                                N_Cs is the time which elapses between the 
                                transmit request of a CF N-PDU until the 
                                transmit request of the next CF N-PDU.        \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NCs;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpTxNSdu\CanTpNcs and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNcs (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            A member of type PduIdType that defines an ID 
                                that will be used while calling CanIf_Transmit 
                                API to transmit a Single Frame, a First Frame,
                                or a Consecutive Frame                        */
    VAR(PduIdType, AUTOMATIC)   udtTxLSduId;
    /* \ConfigTool              -udtTxLSduId shall be configured with the
                                 symbolic name value of the CanIfTxPdu 
                                 referenced through CanTpConfig\CanTpChannel\
                                 CanTpTxNSdu\CanTpTxNPdu\CanTpTxNPduRef       */
    /**************************************************************************/

    /*! \Description            A member of type PduIdType that defines an ID 
                                that will be used while calling 
                                PduR_CanTpTxConfirmation callback to inform the
                                PduR about the I-PDU transmission result.     */
    VAR(PduIdType, AUTOMATIC)   udtTxIPduId;
    /* \ConfigTool              -udtTxIPduId shall be configured with the
                                 symbolic name value of the PduR Pdu referenced
                                 through CanTpConfig\CanTpChannel\CanTpTxNSdu\
                                 CanTpTxNSduRef                               */
    /**************************************************************************/
}
CanTp_tstrTxNSduPBCfgType;


/******************************************************************************/
/*! \Description    A type that defines the post-build time parameters for   
                    each CanTpRxNSdu.                                         /n
*******************************************************************************/
typedef struct
{
    /*! \Description            A member of type uint8 that defines the number
                                of N-PDUs the CanTp receiver allows the sender
                                to send before waiting for an authorization to
                                continue transmission of the following N-PDUs.\n
                                The meaning of this parameter differs according
                                to the configuration parameter 
                                CanTp_bDYNAMIC_RX_BLOCKSIZE:                  \n
                                -If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured
                                 with STD_ON, then u8BlockSize represents the
                                 maximum number of N-PDUs that can be received
                                 before waiting for a new flow control        \n
                                -If CanTp_bDYNAMIC_RX_BLOCKSIZE is configured
                                 with STD_OFF, then u8BlockSize represents the
                                 fixed number of N-PDUs that must be received
                                 before waiting for a new flow control        \n
        \Range                  0..255                                        */
    VAR(uint8, AUTOMATIC)        u8BlockSize;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpBs                          */
    /**************************************************************************/

    /*! \Description            Timeout value of the N_Ar timeout.            \n
                                N_Ar is the time for transmission of a CAN 
                                frame (any N_PDU) on the receiver side        \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NAr;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpNar and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNar (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            Timeout value of the N_Br timeout.            \n
                                N_Br is the elapsed time between the receiving
                                indication of a FF or CF or the transmit
                                confirmation of a FC, until the transmit request
                                of the next FC                                \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NBr;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpNbr and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNbr (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            Timeout value of the N_Cr timeout.            \n
                                N_Cr is the time until reception of the next 
                                Consecutive Frame N_PDU                       \n
                                The value of this parameter is defined as 
                                multiples of CanTp MainFunction period.       \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16NCr;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpNcr and CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod using the
                                 following formula:                           \n
                                 CanTpNbr (in micro seconds) / 
                                 CanTpMainFunctionPeriod (in micro seconds)   \n
                                 The result shall be approximated to the upper
                                 integer value                                */
    /**************************************************************************/

    /*! \Description            A member of type uint16 that defines the number
                                of Flow Control (Wait) N-PDUs that can be 
                                consecutively transmitted by the receiver.    \n
        \Range                  0..65535                                      */
    VAR(uint16, AUTOMATIC)      u16RxWftMax;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpRxWftMax                    */
    /**************************************************************************/

    /*! \Description            A member of type uint8 that defines the minimum
                                time duration that the CanTp sender shall wait
                                between the transmissions of two Consecutive 
                                frame N-PDUs.                                 \n
                                The allowed units are:                        \n
                                -Absolute milli seconds (0 to 127 ms)         \n
                                -Units of 100 micro seconds (100, 200, 300,
                                 400, 500, 600, 600, 700, 800, and 900 micro
                                 seconds                                      \n
        \Range                  0..127, 241..249                              */
    VAR(uint8, AUTOMATIC)       u8STmin;
    /* \ConfigTool              -Derived from CanTpConfig\CanTpChannel\ 
                                 CanTpRxNSdu\CanTpSTmin                       \n
                                -If the milli seconds units are used then
                                 u8STmin is normally configured with the value
                                 of milli seconds.                            \n
                                -If the 100 micro seconds units are used then
                                 100 micro seconds corresponds to the value 241,
                                 200 micro seconds corresponds to the value 242,
                                 and 900 micro seconds corresponds to the value
                                 249, etc ...                                 */
    /**************************************************************************/

    /*! \Description            A member of type PduIdType that defines an ID 
                                that will be used while calling
                                PduR_CanTpRxIndication callback to inform the 
                                PduR about the I-PDU reception status.        */
    VAR(PduIdType, AUTOMATIC)   udtRxIPduId;
    /* \ConfigTool              -udtRxIPduId shall be configured with the
                                 symbolic name value of the PduR Pdu referenced
                                 through CanTpConfig\CanTpChannel\CanTpRxNSdu\
                                 CanTpRxNSduRef                               */
    /**************************************************************************/

    /*! \Description            A member of type PduIdType that defines an ID 
                                that will be used while calling CanIf_Transmit
                                API to transmit the Flow Control frame during
                                the reception process.                        */
    VAR(PduIdType, AUTOMATIC)   udtTxFcLSduId;
    /* \ConfigTool              -udtTxFcLSduId shall be configured with the
                                 symbolic name value of the CanIfTxPdu
                                 referenced through CanTpConfig\CanTpChannel\
                                 CanTpRxNSdu\CanTpTxFcNPdu\CanTpTxFcNPduRef   */
    /**************************************************************************/
}
CanTp_tstrRxNSduPBCfgType;


/******************************************************************************/
/*! \Description    A type that holds references to all post-build 
                    configurations defined, in addition to any general
                    configuration parameters                                  /n
*******************************************************************************/
typedef struct
{
    /*! \Description            A member of type uint32 that defines the 
                                periodicity of the MainFunction in micro
                                seconds.                                      \n
                                This period shall be the same as the cycle time
                                of the periodic task where CanTp Main function
                                is called                                     \n
        \Range                  0..4294967295                                 */
    VAR(uint32, AUTOMATIC)      u32MainFunctionPeriod;
    /* \ConfigTool              -Derived from CanTpConfig\
                                 CanTpGeneral\CanTpMainFunctionPeriod then
                                 converted to micro seconds                   */
    /**************************************************************************/

    /*! \Description            Pointer to the array containing post-build
                                time configuration parameters of CanTpRxNSdus */
    P2CONST(CanTp_tstrRxNSduPBCfgType, AUTOMATIC, CANTP_CALIB_CONST)
                                pkstrRxNSduCfg;
    /* \ConfigTool              -Configured with the address 
                                 of akstrRxNSduPBCfg                          */
    /**************************************************************************/

    /*! \Description            Pointer to the array containing post-build
                                time configuration parameters of CanTpTxNSdus */
    P2CONST(CanTp_tstrTxNSduPBCfgType, AUTOMATIC, CANTP_CALIB_CONST) 
                                pkstrTxNSduCfg;
    /* \ConfigTool              -Configured with the address 
                                 of akstrTxNSduPBCfg                          */
    /**************************************************************************/
}
CanTp_ConfigType;


#endif /* CANTP_TYPES_H */

/*-------------------------------- end of file -------------------------------*/