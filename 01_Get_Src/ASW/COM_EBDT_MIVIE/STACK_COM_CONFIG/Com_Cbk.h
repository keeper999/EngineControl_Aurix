
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com_Cbk                                                 */
/* !Description     : Com_Cbk                                                 */
/*                                                                            */
/* !File            : Com_Cbk.h                                               */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.5      $$Author::   osabry         $$Date::   Feb 22 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef COM_CBK_H
#define COM_CBK_H

#include "ComStack_Types.h"

#define COM_START_SEC_CODE
#include "MemMap.h"  

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/* Callback functions
    Generation method:
      static generation */
/******************************************************************************/
extern FUNC(Std_ReturnType, COM_CODE)
  Com_TriggerTransmit (
                        VAR(PduIdType, AUTOMATIC) TxPduId,
                        P2VAR(PduInfoType, AUTOMATIC,COM_APPL_DATA) PduInfoPtr
                      );
extern FUNC(void, COM_CODE)
  Com_RxIndication(
                   VAR(PduIdType, AUTOMATIC) RxPduId,
                   P2VAR(PduInfoType, AUTOMATIC,COM_APPL_DATA) PduInfoPtr
                   );


extern FUNC(void, COM_CODE)
  Com_TxConfirmation(
VAR(PduIdType, AUTOMATIC) TxPduId
);


extern FUNC(BufReq_ReturnType, COM_CODE) 
  Com_StartOfReception(
VAR(PduIdType, AUTOMATIC) ComRxPduId,
P2VAR( PduInfoType ,AUTOMATIC ,COM_APPL_DATA) TpSduInfoPtr,
VAR(PduLengthType, AUTOMATIC) TpSduLength,
P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
);

extern FUNC(BufReq_ReturnType, COM_CODE) 
  Com_CopyRxData(
VAR(PduIdType, AUTOMATIC) PduId,
/* Removed const from following parameter as per PDUR and DCM specs */
P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr);

extern FUNC(BufReq_ReturnType, COM_CODE) 
  Com_CopyTxData(
                VAR(PduIdType, AUTOMATIC) PduId,
P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr,
P2VAR(RetryInfoType, AUTOMATIC, COM_APPL_DATA) RetryInfoPtr,
P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) TxDataCntPtr);
extern FUNC(void, COM_CODE) 
  Com_TpRxIndication(
VAR(PduIdType, AUTOMATIC) PduId,
VAR(Std_ReturnType, AUTOMATIC) Result
);


extern FUNC(void, COM_CODE) 
  Com_TpTxConfirmation(
    VAR(PduIdType, AUTOMATIC) PduId,
VAR(Std_ReturnType, AUTOMATIC) Result
);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* Configurable Callouts Prototypes
    Generation method:
      - Prototypes are static
      - Function names are ComIPduCallout of ComIPdu                          */
/******************************************************************************/

extern FUNC(boolean, COM_CODE)
  ISCAN_EveTxF228_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) IpduData);


extern FUNC(boolean, COM_CODE)
  ISCAN_EveTxF388_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) IpduData);


extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF572_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF50E_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF552_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF495_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF4F2_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF3C9_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF7F2_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF532_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF492_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF489_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF50D_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF5B2_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF592_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF34D_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF792_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF30D_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF44D_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF305_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF329_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF3CD_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF349_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF3AD_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF4D2_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF57C_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF612_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF4B2_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF38D_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF412_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);

extern FUNC(boolean, COM_CODE)
  FHCAN_EveRxF432_Callout (
    VAR(PduIdType,AUTOMATIC) Id,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) IpduData);



/******************************************************************************/
/* Ipdu Notification functions Prototypes
    Generation method:
      - Prototypes are static
      - Function names are Ipdu notification of ComIPdu                       */
/******************************************************************************/

extern FUNC(void, COM_CODE) Com_vidIPduNotification_21(void);

extern FUNC(void, COM_CODE) Com_vidIPduNotification_64(void);


/******************************************************************************/
/* Ipdu TimeOut Notification functions Prototypes
    Generation method:
      - Prototypes are static
      - Function names are Ipdu TimeOut notification of ComIPdu               */
/******************************************************************************/

extern FUNC(void, COM_CODE) Com_vidIPduTimeOutNotification_21(void);

extern FUNC(void, COM_CODE) Com_vidIPduTimeOutNotification_64(void);


/******************************************************************************/
/* Ipdu Error Notification functions Prototypes
    Generation method:
      - Prototypes are static
      - Function names are Ipdu Error notification of ComIPdu                 */
/******************************************************************************/




#endif /* COM_CBK_H */

/* PRQA S 0850 --                                                             */

