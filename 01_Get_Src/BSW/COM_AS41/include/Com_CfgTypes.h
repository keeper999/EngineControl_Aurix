/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_CfgTypes.h                                          */
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
/* $Revision::   1.11                                                        $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \file Com_CfgTypes.h
*
* \par
*   Declarations of Com Pre-compile parameters data types                     */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/

#ifndef COM_CFGTYPES_H
#define COM_CFGTYPES_H

#include "ComStack_Types.h"

/******************************************************************************/
/*! \Description Definitions for COM_FILTER_SIDE pre-compile parameter \n */
/******************************************************************************/
#define COM_u8FILTER_SIDE_RX 0U
#define Com_u8FILTER_SIDE_TX 1U

/******************************************************************************/
/* Pre-compile Configuration Data Types                                       */
/******************************************************************************/
/******************************************************************************/
/*! \Description Defines a type of Pointer to Rx I-PDU Callout  function  \n */
/******************************************************************************/
typedef P2FUNC(boolean, AUTOMATIC, Com_tpfbRxIpduCallout)
                                    (PduIdType Id,
                                     P2VAR(PduInfoType,AUTOMATIC,
                                             COM_MAX_CALIB_APPL_CFGCONST)
                                            PduInfoPtr);

/******************************************************************************/
/*! \Description Defines a type of Pointer to Tx I-PDU Callout  function  \n */
/******************************************************************************/
typedef P2FUNC(boolean, AUTOMATIC, Com_tpfbTxIpduCallout)
                                    (PduIdType Id,
                                     P2VAR(PduInfoType,AUTOMATIC,
                                           COM_MAX_CALIB_APPL_CFGCONST)
                                          PduInfoPtr);

/******************************************************************************/
/*! \Description Defines a type of ComIPduCounter ROM Structure. \n */
/******************************************************************************/
typedef struct
{
   /**************************************************************************/
    /*! \Description Size of PDU Counter expressed in bits \n
                     calculation method: equals ComIPduCounterSize \n
        \Range 1..8    \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8IPduCounterSize;

    /**************************************************************************/
    /*! \Description Position of PDU counter expressed in bits from \n
                     start position of data content of I-PDU . \n
                     calculation method: equals ComIPduCounterStartPosition \n
        \Range 0..2031    \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16IPduCounterStartPos;

    /**************************************************************************/
    /*! \Description Threshold value of I-PDU counter algorithm  \n
                     calculation method: equals ComIPduCounterThreshold \n
        \Range 0..255    \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8IPduCounterThreshold;
} Com_tstrIPduCounter;

/******************************************************************************/
/*! \Description Defines a type of I-PDU Run-time RAM Counter  \n
                 calculation method: RAM Allocation \n
    \Range 0..255    \n */
/******************************************************************************/
typedef uint8 Com_tu8IPduCounterRam;

/******************************************************************************/
/*! \Description Defines a type of ComIPduReplication ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description The number of identical I-PDUs needed for successful \n
                     voting. \n
                     calculation method: equals to ComIPduReplicationQuorum \n
        \Range 1..3    \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8IPduReplicaQuorum;

    /**************************************************************************/
    /*! \Description The number of Replicas \n
                     calculation method: count the no. of ComIPduReplicaRef \n
        \Range 1..2    \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC) u8NoOfReplicas;

    /**************************************************************************/
    /*! \Description  Index to the Ram buffer of the replicas. 1st replica \n
                      starts from ReplicasBufferIndex to ComRxIPdu. \n
                      ComIPduLength - 1. 2nd replica starts from \n
                      ReplicasBufferIndex + ComRxIPdu. ComIPduLength to \n
                      ReplicasBufferIndex + 2 * ComRxIPdu. ComIPduLength -1  \n
        \Range 0..65,535    \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16ReplicasBufferIndex;
} Com_tstrIPduReplication;

/******************************************************************************/
/*! \Description Defines a type of Replicas Run-time RAM Counter  \n
                 holds the number of replicas received \n
                 calculation method: RAM Allocation \n
    \Range 0..3    \n */
/******************************************************************************/
typedef uint8 Com_tu8ReplicasCounter;

#endif /* COM_CFGTYPES_H */
/* PRQA S 0850 --                                                             */
/** \} */ /* end of Com module group */
