
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_LocalCfg.h                                         */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.25      $$Author::   sedrees       $$Date::   Aug 21 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef PDUR_LOCALCFG_H
#define PDUR_LOCALCFG_H

/* !Deviation : Inhibit MISRA rule [3132]: Magic numbers are auto-generated   */
/*              the configuration tool as this is a configuration file        */
/* PRQA S 3132 L1                                                             */

#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR_Cfg.h"


/******************************************************************************/
/* MISCELLANEOUS #DEFINES                                                     */
/******************************************************************************/

#if(PduR_bGATEWAYING_IF == STD_ON)

/******************************************************************************/
/*! \Description    Maximum size of a message being gatewayed over IF layers \n
    \Range          1..255 \n
*******************************************************************************/

#define PduR_u8GTWYIF_MAX_SIZE              2UL

#else
/******************************************************************************/
/*! \Description    Maximum size of a message being gatewayed over IF layers \n
    \Range          1..255 \n
*******************************************************************************/
#define PduR_u8GTWYIF_MAX_SIZE              1UL

#endif

/******************************************************************************/
/*! \Description    Maximum number of messages that the CANTP module will Tx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_CANTP_TX_MSGS             3UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the CANTP module will Rx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_CANTP_RX_MSGS             4UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the COM module will Tx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_COM_TX_MSGS             33UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the COM module will Rx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_COM_RX_MSGS             46UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the CANIF module will Tx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_CANIF_TX_MSGS             30UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the CANIF module will Rx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_CANIF_RX_MSGS             44UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the LINIF module will Tx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_LINIF_TX_MSGS             2UL

/******************************************************************************/
/*! \Description    Maximum number of messages that the LINIF module will Rx \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_LINIF_RX_MSGS             2UL


/******************************************************************************/
/*---------------------Main PduR Configuration Structure----------------------*/
typedef struct
{
    /*----------------------- Function Pointers Tables -----------------------*/
    #if(PduR_bIFLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrIfTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrIfTxFuncTable;
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrTpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrTpTxFuncTable;
    #endif
    #if(PduR_bIFLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrIf2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrIf2UpRxFuncTable;
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrTp2UpRxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrTp2UpRxFuncTable;
    #endif
    #if(PduR_bIFLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrIf2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrIf2UpTxFuncTable;
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrTp2UpTxFuncPtrType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrTp2UpTxFuncTable;
    #endif

    /*----------------------------- Up Tx Tables -----------------------------*/
    
    P2CONST(PduR_tstrUpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrComUpTxRTable;
    VAR(uint16, AUTOMATIC)                              u16ComUpTxRTSize;
    

    /*--------------------------- Up Tx Rev Tables ---------------------------*/
    
    P2CONST(PduR_tstrUpTpRevTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrComRevRTable;
    VAR(uint16, AUTOMATIC)                              u16ComRevRTSize;
    

    /*----------------------------- IF Tx Tables -----------------------------*/
    
    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrCanIfTxRTable;
    VAR(uint16, AUTOMATIC)                              u16CanIfTxRTSize;
    
    P2CONST(PduR_tstrLoIfTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrLinIfTxRTable;
    VAR(uint16, AUTOMATIC)                              u16LinIfTxRTSize;
    

    /*----------------------------- IF Rx Tables -----------------------------*/
    #if ( PduR_bIFLO_ENABLED == STD_ON)
    P2CONST(PduR_tstrLoIfMulRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrMultiUpRxRTable;
    VAR(uint16, AUTOMATIC)                              u16MultiUpRxRTSize;
    #endif
    
    P2CONST(PduR_tstrLoIfRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrCanIfRxRTable;
    VAR(uint16, AUTOMATIC)                              u16CanIfRxRTSize;
    
    P2CONST(PduR_tstrLoIfRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrLinIfRxRTable;
    VAR(uint16, AUTOMATIC)                              u16LinIfRxRTSize;
    
    /*----------------------------- TP Tx Tables -----------------------------*/
    
    P2CONST(PduR_tstrLoTpTxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrCanTpTxRTable;
    VAR(uint16, AUTOMATIC)                              u16CanTpTxRTSize;
    

    /*----------------------------- TP Rx Tables -----------------------------*/
    
    P2CONST(PduR_tstrLoTpRxRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrCanTpRxRTable;
    VAR(uint16, AUTOMATIC)                              u16CanTpRxRTSize;
    

    /*------------------------- Multicasting Tables --------------------------*/
    #if(PduR_bMULTICASTING_IF == STD_ON)
    P2CONST(PduR_tstrMultiIfRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrMultiIfRTable;
    P2CONST(PduR_tstrMultiIfSubRTType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrMultiIfSubRT;
    VAR(PduIdType, AUTOMATIC)                           udtMultiIfRTSize;
    #endif

    #if(PduR_bMULTICASTING_TP == STD_ON)
    P2CONST(PduR_tstrMultiTpRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrMultiTpRTable;
    P2CONST(PduR_tstrMultiTpSubRTType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrMultiTpSubRT;
    VAR(PduIdType, AUTOMATIC)                           udtMultiTpRTSize;
    #endif

    /*-------------------------- Gatewaying Tables ---------------------------*/
    #if(PduR_bGATEWAYING_IF == STD_ON)
    P2CONST(PduR_tstrGateIfRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrGateIfRTable;
    VAR(PduIdType, AUTOMATIC)                           udtGateIfRTSize;
    #endif

    #if(PduR_bGATEWAYING_TP == STD_ON)
    P2CONST(PduR_tstrGateTpRTableType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrGateTpRTable;
    P2CONST(PduR_tstrGateTpSubRTType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrGateTpSubRT;
    VAR(PduIdType, AUTOMATIC)                           udtGateTpRTSize;
    P2CONST(PduR_tstrTpBuffPCCfgType, AUTOMATIC, PDUR_CALIB_CONST)
                                                        pkstrTpBuffRef;
    #endif

    /*------------------------------- Others ---------------------------------*/
    VAR(uint16, AUTOMATIC)                             u16NumOfGlobalPdus;
    VAR(uint16, AUTOMATIC)                             u16ConfigurationId;

    /*------------------------------ RAM Arrays ------------------------------*/
    #if(PduR_bMULTICASTING_TP == STD_ON)
    P2VAR(PduR_tstrMultiTpCntrlType, AUTOMATIC, PDUR_CALIB_DATA)
                                                        pstrMultiTpCntrl;
    P2VAR(uint16, AUTOMATIC, PDUR_CALIB_DATA)           pu16MultiTpCopyTxIdx;
    #endif

    #if(PduR_bGATEWAYING_TP == STD_ON)
    P2VAR(PduR_tstrGateTpCntrlType, AUTOMATIC, PDUR_CALIB_DATA)
                                                        pstrGateTpCntrl;
    #endif

} PduR_PBConfigType;

/******************************************************************************/
/* EXTERNED DATA (found in PduR_Cfg.c)                                        */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
#define PDUR_START_SEC_VAR_8
#include "Memmap.h"





#if(PduR_u16MAX_TX_BUFFER_NUMBER > 0UL)
extern VAR(PduR_tstrTxCntrlType, PDUR_VAR)
                            PduR_astreTxBuffCtrl[PduR_u16MAX_TX_BUFFER_NUMBER];
#endif
#if(PduR_u16MAX_GLBL_IPDUS_NMBR > 0UL)
extern VAR(PduR_tu8PduStateType, PDUR_VAR)
                            PduR_au8eGlblPduState[PduR_u16MAX_GLBL_IPDUS_NMBR];
#else
/* work around  */
extern VAR(PduR_tu8PduStateType, PDUR_VAR) PduR_au8eGlblPduState[1];
#endif


#define PDUR_STOP_SEC_VAR_8
#include "Memmap.h"
/*----------------------------------------------------------------------------*/
#define PDUR_START_SEC_VAR_16
#include "Memmap.h"



#define PDUR_STOP_SEC_VAR_16
#include "Memmap.h"
/*----------------------------------------------------------------------------*/
#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
#define PDUR_START_CONFIG_DATA_BOOLEAN
#include "Memmap.h"

extern CONST(boolean, PDUR_CFG_CONST)
                    PduR_akbeRGrpStatusPC[PduR_u16MAX_ROUTE_GRP_NUMBER + 1UL];

#define PDUR_STOP_CONFIG_DATA_BOOLEAN
#include "Memmap.h"
#endif
/*----------------------------------------------------------------------------*/
#define PDUR_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"



extern CONST(PduR_tstrBswModInitFuncPtrType, PDUR_CALIB_CONST)
                            PduR_akstreBswModuleInitFnPtT[3];

#define PDUR_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"
/*----------------------------------------------------------------------------*/


/******************************************************************************/
/* EXTERNED DATA (generic)                                                    */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
#define PDUR_START_SEC_VAR_8
#include "Memmap.h"

extern VAR(PduR_StateType, PDUR_VAR) PduR_u8eState;

#define PDUR_STOP_SEC_VAR_8
#include "Memmap.h"
/* ---------------------------------------------------------------------------*/
#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
#define PDUR_START_SEC_VAR_BOOLEAN
#include "Memmap.h"

extern VAR(boolean, PDUR_VAR)
                        PduR_abeRGrpStatus[PduR_u16MAX_ROUTE_GRP_NUMBER + 1UL];

#define PDUR_STOP_SEC_VAR_BOOLEAN
#include "Memmap.h"
#endif
/* ---------------------------------------------------------------------------*/
#define PDUR_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern P2CONST(PduR_PBConfigType, PDUR_VAR, PDUR_APPL_CONST)
                                                            PduR_pkstrePbCfg;

#define PDUR_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/* \Description Macro to enter a critical region towards the OS.              */
/******************************************************************************/
#define SchM_Enter_PduR(                                                       \
          /* \param Critical access region ID */                               \
          ExclusiveArea)                                                       \
  SchM_Enter_ ## ExclusiveArea ()

/******************************************************************************/
/* \Description Macro to exit a critical region towards the OS.               */
/******************************************************************************/
#define SchM_Exit_PduR(                                                        \
          /* \param Critical access region ID */                               \
          ExclusiveArea)                                                       \
  SchM_Exit_ ## ExclusiveArea ()


/*============================================================================*/
/*=== Vendor specific OS abstraction attributes ==============================*/
/*============================================================================*/

/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abCanTpRxIndAPI from multiple access in 
                 case of API re-entrancy in PduR_CanTpRxIndication
*******************************************************************************/
#define PduR_CANTP_ACCESS_001

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abCanTpStartOfRxAPIStatus from multiple
                 access in case of API re-entrancy in PduR_CanTpStartOfReception
*******************************************************************************/
#define PduR_CANTP_ACCESS_002

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abCanTpCopyRxDataAPI from multiple access
                 in case of API re-entrancy in PduR_CanTpCopyRxData
*******************************************************************************/
#define PduR_CANTP_ACCESS_003

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abCanTpCopyTxDataAPI from multiple access
                 in case of API re-entrancy in PduR_CanTpCopyTxData
*******************************************************************************/
#define PduR_CANTP_ACCESS_004

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abBswModTxConfAPI from multiple access
                 in case of API re-entrancy in PduR_CanTpTxConfirmation
*******************************************************************************/
#define PduR_CANTP_ACCESS_005

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abCanTpChngPrmConfAPI from multiple access
                 in case of API re-entrancy in PduR_CanTpChngPrmCnf
*******************************************************************************/
#define PduR_CANTP_ACCESS_006


/*----------------------------------------------------------------------------*/


/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abComTransmitAPI from multiple access in 
                 case of API re-entrancy in PduR_ComTransmit
*******************************************************************************/
#define PduR_COM_ACCESS_001

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abComCancelTxAPI from multiple access in 
                 case of API re-entrancy in PduR_ComCancelTransmit
*******************************************************************************/
#define PduR_COM_ACCESS_002


/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abComCancelTxReqAPI from multiple access in
                 case of API re-entrancy in PduR_ComCancelTransmitRequest
*******************************************************************************/
#define PduR_COM_ACCESS_003

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abComCancelRxReqAPI from multiple access in
                 case of API re-entrancy in PduR_ComCancelReceiveRequest
*******************************************************************************/
#define PduR_COM_ACCESS_004

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 protection of PduR_abComChngePrmReqAPI from multiple access in
                 case of API re-entrancy in PduR_ComChangeParamRequest
*******************************************************************************/
#define PduR_COM_ACCESS_005


/*----------------------------------------------------------------------------*/

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 TP buffers protection against any multiple accesses
*******************************************************************************/
#define PduR_TP_BUFF_CTRL_COPYRX

#define PduR_TP_BUFF_CTRL_COPYTX

#define PduR_TP_BUFF_CTRL_START_OF_RX

/******************************************************************************/
/*! \Description Defines the ID of PDUR module's critical region to be used for
                 IF buffers protection against any multiple accesses
*******************************************************************************/
#define PduR_TX_BUFF_CTRL_RX

#define PduR_TX_BUFF_CTRL_TX
    

#endif /* PDUR_LOCALCFG_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
