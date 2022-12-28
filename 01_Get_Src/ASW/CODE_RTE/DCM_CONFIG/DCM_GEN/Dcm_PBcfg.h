
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm_PBcfg.h                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_PBcfg.h_v$*/
/* $Revision::   1.15     $$Author::   pbakabad       $$Date::   Mar 11 2013 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/




#ifndef DCM_PBCFG_H
#define DCM_PBCFG_H


#include "Dcm.h"




/******************************************************************************/
/*!  \Description Dcm_ProtocolAddrType  \n
*******************************************************************************/
typedef uint8 Dcm_ProtocolAddrType;
#define DCM_FUNC_ADDR     0x01
#define DCM_PHYS_ADDR     0x02

/******************************************************************************/
/*!  \Description Dcm_ProtocolTransType  \n
*******************************************************************************/
typedef uint8 Dcm_ProtocolTransType;
#define DCM_PROTOCOL_TYPE1    0x00
#define DCM_PROTOCOL_TYPE2    0x01

/******************************************************************************/
/********                 POST BUILD Dcm_ConfigType              **************/
/******************************************************************************/

/******************************************************************************/
/*!  \Description Dcm_DslResponseOnEvent post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description  DcmDslTxConfirmPduId  \n
      \Range        0..65535              \n
      \Unit         PduIdType             */
  PduIdType udtDcmDslTxConfirmPduId;
  
  /*! \Description  Index to Roe Protocol Row  \n
      \Range        0..255                     \n
      \Unit         Index                      */
  uint8 u8RoeProtocolRowIndex;
}Dcm_DslResponseOnEventType;

/******************************************************************************/
/*!  \Description Dcm_DslPeriodicTransmission post-build container \n
                  it will contain the list of Transmission PduIds  \n
*******************************************************************************/
typedef struct
{
  /*! \Description   DcmDslTxConfirmPduId    \n
      \Range         Not Null                \n
      \Unit          Pointer to PduIdType    */
  P2CONST(PduIdType,TYPEDEF,DCM_APPL_CONST) pudtDcmDslTxConfirmPduIds;
  
  /*! \Description  Number of TX Confirm PduIds    \n
      \Range        0..255                         \n
      \Unit         PduId                          */
  uint8 u8NumOfTxConfirmPduIds;
  
  /*! \Description  Index to Periodic Protocol Row  \n
      \Range        0..255                          \n
      \Unit         Index                           */
  uint8 u8PeriodicPrtclRowIdx;
}Dcm_DslPeriodicTransmissionType;

/******************************************************************************/
/*!  \Description Dcm_DslPeriodicTransmission post-build container \n
                  it will contain the list of Transmission PduIds \n
*******************************************************************************/  
typedef struct  
{
  /*! \Description  DcmDslPeriodicTransmissionConRef            \n
      \Range        Not Null                                    \n
      \Unit         Pointer to Dcm_DslPeriodicTransmissionType  */
  P2CONST(Dcm_DslPeriodicTransmissionType,TYPEDEF,DCM_APPL_CONST)
                                          pkstrDcmDslPeriodicTransmissionConRef;
 
  /*! \Description  DcmDslPeriodicTransmissionConRef    \n
      \Range        Not Null                            \n
      \Unit         Pointer to DcmDslROEConnectionRef   */
  P2CONST(Dcm_DslResponseOnEventType,TYPEDEF,DCM_APPL_CONST)
                                                    pkstrDcmDslROEConnectionRef;
}Dcm_DslMainConnectionType;

/******************************************************************************/
/*! \Description Dcm_DslProtocolRow post-build type \n\n
    \Range       Structure \n\n
    \Unit        Dcm_PbDslProtocolRowType
*******************************************************************************/
typedef struct Dcm_PbDslProtocolRowType1 Dcm_PbDslProtocolRowType;

/******************************************************************************/
/*!  \Description Dcm_DslConnection post-build container \n
*******************************************************************************/  
typedef struct 
{
  /*! \Description  DcmDslMainConnection container   \n
      \Range        Not Null         \n
      \Unit         Pointer to   Dcm_DslMainConnectionType  */
  P2CONST(Dcm_DslMainConnectionType,TYPEDEF,DCM_APPL_CONST)
                                                      pkstrDcmDslMainConnection;

  /*! \Description  Dcm_DslPeriodicTransmission container   \n
      \Range        Not Null         \n
      \Unit         Pointer to   Dcm_DslPeriodicTransmissionType  */
  P2CONST(Dcm_DslPeriodicTransmissionType,TYPEDEF,DCM_APPL_CONST)
                                                pkstrDcmDslPeriodicTransmission;

  /*! \Description  Dcm_DslResponseOnEvent container   \n
      \Range        Not Null         \n
      \Unit         Pointer to   Dcm_DslResponseOnEventType  */
  P2CONST(Dcm_DslResponseOnEventType,TYPEDEF,DCM_APPL_CONST)
                                                     pkstrDcmDslResponseOnEvent;
}Dcm_DslConnectionType; 

/******************************************************************************/
/*!  \Description Dcm_DslConnection post-build type \n\n
     \Range       Not Null \n\n
     \Unit        Pointer to Dcm_DslConnection
*******************************************************************************/
typedef P2CONST(Dcm_DslConnectionType,TYPEDEF,DCM_APPL_CONST)
                                                    Dcm_tpkstrDslConnectionType;

/******************************************************************************/
/*!  \Description Dcm_DslProtocolRow post-build container \n
*******************************************************************************/
struct Dcm_PbDslProtocolRowType1
{
  /*! \Description   parameter DcmDslProtocolID   \n
      \Range         0..11, 240..254              \n
      \Unit          Dcm_ProtocolType             */
  Dcm_ProtocolType      u8DcmDslProtocolID;
  
  /*! \Description   DcmDslProtocolPreemptTimeout   \n
      \Range         0..1000/DCM_TASK_TIME_IN_MS    \n
      \Unit          uint16                         */
  uint16             u16DcmDslProtocolPreemptTimeout;
  
  /*! \Description   DcmDslProtocolPriority   \n
      \Range         0.255                    \n
      \Unit          uint8                    */
  uint8              u8DcmDslProtocolPriority;
  
  /*! \Description  DcmDslProtocolTransType    \n
      \Range        0..1                       \n
      \Unit         Dcm_ProtocolTransType      */
  Dcm_ProtocolTransType u8DcmDslProtocolTransType;
  
  /*! \Description  DcmDslProtocolRxBufferID \n
      \Range        0..255                   \n
      \Unit         uint8                    */
  uint8                 u8DcmDslProtocolRxBufferID;
  
  /*! \Description  DcmDslProtocolTxBufferID    \n
      \Range        0..255                      \n
      \Unit         uint8                       */
  uint8                 u8DcmDslProtocolTxBufferID;
  
  /*! \Description   DcmDslProtocolSIDTable    \n
      \Range         0..255                    \n
      \Unit          uint8                     */
  uint8                 u8DcmDslProtocolSIDTable;
  
  /*! \Description   DcmDslConnection   \n
      \Range        NotNull             \n
      \Unit                             */
  P2CONST(Dcm_tpkstrDslConnectionType,TYPEDEF,DCM_APPL_CONST)
                                                         ppkstrDcmDslConnection;

  /*! \Description  Number of Connections   \n
      \Range        0..255                  \n
      \Unit                                 */
  uint8             u8NumOfConnec;
  
  /*! \Description   DcmTimStrP2ServerAdjust      \n
      \Range         0..1000/DCM_TASK_TIME_IN_MS  \n
      \Unit          uint16                       */
  uint16            u16DcmTimStrP2ServerAdjust;
  
  /*! \Description   DcmTimStrP2StarServerAdjust   \n
      \Range         0..1000/DCM_TASK_TIME_IN_MS   \n
      \Unit          uint16                        */
  uint16            u16DcmTimStrP2StarServerAdjust;
};

/******************************************************************************/
/*!  \Description Dcm_DslProtocolRx post-build container \n
*******************************************************************************/  
typedef struct 
{
  /*! \Description     u8DcmDslProtocolIndex   \n
      \Range           0..255                  \n
      \Unit            uint8                   */
  uint8                u8DcmDslProtocolIndex;
  
  /*! \Description     DcmDslProtocolRxAddrType   \n
      \Range           0..1                       \n
      \Unit            Dcm_ProtocolAddrType       */
  Dcm_ProtocolAddrType u8DcmDslProtocolRxAddrType;

  /*! \Description   DcmDslProtocolRxTesterSourceAddr   \n
      \Range         0..255                             \n
      \Unit          uint8                              */
  uint8              u8DcmDslProtocolRxTesterSourceAddr;
  
  /*! \Description   DcmDslProtocolRxChannelId   \n
      \Range         0..255                      \n
      \Unit          uint8                       */
  uint8              u8DcmDslProtocolRxChannelId;

  /*! \Description   DcmDslConnectionRef added to link back                  \n
                     to Connection as RX and TX are not in the same level of \n
                     MainConnection container                                \n
      \Range         0..255                                                  \n
      \Unit          uint8                                                   */
  uint8              u8DcmDslConnectionRef;

  /*! \Description   DcmDslProtocolTxPduRef   \n
      \Range         0..65535                 \n
      \Unit          uint16                   */
  PduIdType          udtDcmDslProtocolTxPduRef;  /* Not for Type 2 Protocols */
}Dcm_DslProtocolRxType ;

/******************************************************************************/
/*!  \Description Dcm_TxPduType  post-build type \n\n
     \Range       0..255                         \n\n
     \Unit        uint8
*******************************************************************************/
typedef uint8 Dcm_TxPduType;
#define DCM_MAIN_PROTOCOL_MSGS  0x00
#define DCM_ROE_MSGS            0x01
#define DCM_PERIODIC_MSGS       0x02

/******************************************************************************/
/*!  \Description Dcm_DslProtocolTx post-build container \n
*******************************************************************************/  
typedef struct
{
  /*! \Description   DcmDslProtocolTxPduRef   \n
      \Range          0..65535                \n
      \Unit           PduIdType               */
  PduIdType udtDcmDslProtocolTxPduRef; 

  /*! \Description   DcmDslProtocolIndex   \n
      \Range          0..255               \n
      \Unit           PduIdType            */
  uint8  u8DcmDslProtocolIndex;

  /*! \Description   u8DcmDslTxPduType: to determine the type of connection \n
   *                 for transmission                                       \n
      \Range        0..2                                                    \n
      \Unit          Dcm_TxPduType                                          */
  Dcm_TxPduType  u8DcmDslTxPduType;
}Dcm_DslProtocolTxType;

/******************************************************************************/
/*!  \Description DSL post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description  DcmDslDiagRespMaxNumRespPend    \n
      \Range         0..255                         \n
      \Unit          uint8                          */
  uint8 u8DcmDslDiagRespMaxNumRespPend;

  /*! \Description  DcmDslNumProtocolRow            \n
      \Range         0..255                         \n
      \Unit          uint8                          */
  uint8 u8DcmDslNumProtocolRow;

  /*! \Description  DcmDslNumProtocolRx             \n
      \Range         0..255                         \n
      \Unit          uint8                          */
  uint8 u8DcmDslNumProtocolRx;

  /*! \Description  DcmDslNumProtocolTx             \n
      \Range         0..255                         \n
      \Unit          uint8                          */
  uint8 u8DcmDslNumProtocolTx;
  
  /*! \Description  DcmDslProtocolRow               \n
      \Range        NotNull                         \n
      \Unit         Dcm_PbDslProtocolRowType        */
  P2CONST(Dcm_PbDslProtocolRowType,TYPEDEF,DCM_APPL_CONST)
                                                         pkstrDcmDslProtocolRow;
    
  /*! \Description  DcmDslProtocolRx    \n
                    Should be a part of DcmDslMainConnection container, but \n
                    it is added here to fast the access for this container. \n
      \Range          NotNull                                               \n
      \Unit           Dcm_DslProtocolRxType                                 */
  P2CONST(Dcm_DslProtocolRxType,TYPEDEF,DCM_APPL_CONST)
                                                          pkstrDcmDslProtocolRx;

  /*! \Description  DcmDslProtocolTx    \n
                    Should be a part of DcmDslMainConnection container, but it\n
                    is added here to fast the access for this container. \n
    \Range          NotNull        \n
    \Unit           Dcm_DslProtocolTxType   */
  P2CONST(Dcm_DslProtocolTxType,TYPEDEF,DCM_APPL_CONST)
                                                          pkstrDcmDslProtocolTx;
} Dcm_PbDslType;

/******************************************************************************/
/*!  \Description Dcm_DspPid post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description  DcmDspPidUsed    \n
      \Range         0..1            \n
      \Unit          boolean         */
  boolean bDcmDspPidUsed;
} Dcm_PbDspPidType;

/******************************************************************************/
/*!  \Description Dcm_DspDid post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description   DcmDspDidUsed    \n
      \Range         0..1             \n
      \Unit          boolean          */
  boolean bDcmDspDidUsed;
} Dcm_PbDspDidType;

/******************************************************************************/
/*!  \Description Dcm_DspRoutine post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description   DcmDspRoutineUsed    \n
      \Range         0..1                 \n
      \Unit          boolean              */
  boolean bDcmDspRoutineUsed;
} Dcm_PbDspRoutineType;

/******************************************************************************/
/*!  \Description Dcm_Dsp post-build container \n
*******************************************************************************/
typedef struct
{
  /*! \Description  DcmDspDid                      \n
      \Range         Not Null                      \n
      \Unit          Pointer to Dcm_PbDspDidType   */
  P2CONST(Dcm_PbDspDidType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspDid;
  
  /*! \Description  u16NumOfDids to determine the number of configured DIDs  \n
    \Range          0..65535                                                 \n
    \Unit           uint16                                                   */
  uint16 u16NumOfDids;

  /*! \Description  DcmDspPid                      \n
      \Range        Not Null                       \n
      \Unit         Pointer to Dcm_PbDspPidType    */
  P2CONST(Dcm_PbDspPidType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspPid;
  
  /*! \Description  u8NumOfPids to determine the number of configured PIDS   \n
      \Range        0..255                                                   \n
      \Unit         uint8                                                    */
  uint8 u8NumOfPids;
  
  /*! \Description   DcmDspRoutine                     \n
      \Range         Not Null                          \n
      \Unit          Pointer to Dcm_PbDspRoutineType   */
  P2CONST(Dcm_PbDspRoutineType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspRoutine;
} Dcm_PbDspType;

/******************************************************************************/
/*!  \Description Structure to group post-build configurations of Dcm \n
*******************************************************************************/
typedef struct 
{
  /*! \Description  strPbDcmDslConfig      \n
      \Range         Structure             \n
      \Unit          Dcm_PbDslType         */
  Dcm_PbDslType strPbDcmDslConfig;
  
  /*! \Description  strPbDcmDspConfig    \n
      \Range         Structure           \n
      \Unit          Dcm_PbDspType       */
  Dcm_PbDspType strPbDcmDspConfig;
}Dcm_ConfigType;



extern CONST(Dcm_ConfigType,DCM_CFG_CONST) Dcm_kstrPbConfig;

#endif /* DCM_PBCFG_H */


/*-------------------------------- end of file -------------------------------*/
    
