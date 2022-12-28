
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_LCfg.c                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS - VALEO Egypt                                      */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.41      $$Author::   sedrees       $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */
/* PRQA S 5087 L1                                                             */

/* !Deviation : Inhibit MISRA rule [2213]: Better readability encountered     */
/*              when having all configuration parameters on same line         */
/* PRQA S 2213 L1                                                             */

/* !Deviation : Inhibit MISRA rule [3132]: Magic numbers are auto-generated   */
/*              the configuration tool as this is a configuration file        */
/* PRQA S 3132 L1                                                             */

/* !Deviation: Inhibit MISRA rule [0857] Under certain configurations, PduR   */
/*             may have more than 1024 definitions, so the compiler should be */
/*             able to handle more than 1024 definitions.                     */
/* PRQA S 857 ++                                                              */

/* !Deviation : Inhibit MISRA rule [0850]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

#include "Std_Types.h"
#include "PduR_LocalTypes.h"
#include "PduR_Types.h"
#include "CanTp.h"

#include "Com_Cbk.h"

#include "Com_Cfg.h"

#include "CanIf.h"
#include "LinIf.h"

#include "PduR.h"
#include "PduR_LocalCfg.h"
#include "PduR_LocalLcfg.h"

/******************************************************************************/
/* CONFIGURATION PARAMETERS                                                   */
/******************************************************************************/

#define PDUR_START_CONFIG_DATA_8
#include "Memmap.h"

/******************************************************************************/
/* Number of Elements                                                         */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of unique global PDU IDs used in minimum routing \n
    \Range          0..255 \n
*******************************************************************************/
CONST(uint8, PDUR_CFG_CONST)    PduR_ku8eNumOfGlobalPdus = 0;
    

#define PDUR_STOP_CONFIG_DATA_8
#include "Memmap.h"

#define PDUR_START_CONFIG_DATA_16
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Number of entries in the CanTp module's Tx routing table \n
    \Range          PduR_u16CANTP_TX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eCanTpTxMinRTSize = PduR_u16CANTP_TX_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the CanTp module's Rx routing table \n
    \Range          PduR_u16CANTP_RX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eCanTpRxMinRTSize = PduR_u16CANTP_RX_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the Com module's UP routing table \n
    \Range          PduR_u16COM_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eComMinRTSize = PduR_u16COM_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the Com module's REV routing table \n
    \Range          PduR_u16COM_REV_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eComMinRevTSize = PduR_u16COM_REV_MINRT_SIZE;


/******************************************************************************/
/*! \Description    Number of entries in the CanIf module's Tx routing table \n
    \Range          PduR_u16CANIF_TX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eCanIfTxMinRTSize = PduR_u16CANIF_TX_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the CanIf module's Rx routing table \n
    \Range          PduR_u16CANIF_RX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eCanIfRxMinRTSize = PduR_u16CANIF_RX_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the LinIf module's Tx routing table \n
    \Range          PduR_u16LINIF_TX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eLinIfTxMinRTSize = PduR_u16LINIF_TX_MINRT_SIZE;

/******************************************************************************/
/*! \Description    Number of entries in the LinIf module's Rx routing table \n
    \Range          PduR_u16LINIF_RX_MINRT_SIZE \n
*******************************************************************************/
CONST(uint16, PDUR_CFG_CONST)
                    PduR_ku16eLinIfRxMinRTSize = PduR_u16LINIF_RX_MINRT_SIZE;


/******************************************************************************/
/* Configured Upper Layers Minimum Routing Arrays                             */
/******************************************************************************/

/******************************************************************************/
/*----------------------------------- COM ------------------------------------*/
/******************************************************************************/
#if(PduR_u16COM_MINRT_SIZE > 0UL)
/******************************************************************************/
/*! \Description    ComTransmit minimum routing table \n
    \Size           PduR_u16COM_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/

CONST(PduR_tstrUpTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreComMinRT[PduR_u16COM_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*! \Description    Com_CnclRxReq/Com_ChngPrmReq minimum routing table \n
    \Size           PduR_u16COM_REV_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16COM_REV_MINRT_SIZE > 0UL)
CONST(PduR_tstrUpTpRevTableType, PDUR_CFG_CONST)
                    PduR_akstreComMinRevT[PduR_u16COM_REV_MINRT_SIZE] =
{
};
#endif
  
/******************************************************************************/
/* Configured Lower Layers Minimum Routing Arrays                             */
/******************************************************************************/


/******************************************************************************/
/*---------------------------------- CANIF -----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*! \Description    CanIf_TxConfirmation minimum routing table \n
    \Size           PduR_u16CANIF_TX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16CANIF_TX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoIfTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanIfTxMinRT[PduR_u16CANIF_TX_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*! \Description    CanIf_RxIndication minimum routing table \n
    \Size           PduR_u16CANIF_RX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16CANIF_RX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoIfRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanIfRxMinRT[PduR_u16CANIF_RX_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*---------------------------------- LINIF -----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*! \Description    LinIf_TxConfirmation minimum routing table \n
    \Size           PduR_u16LINIF_TX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16LINIF_TX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoIfTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreLinIfTxMinRT[PduR_u16LINIF_TX_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*! \Description    LinIf_RxIndication minimum routing table \n
    \Size           PduR_u16LINIF_RX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16LINIF_RX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoIfRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreLinIfRxMinRT[PduR_u16LINIF_RX_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*---------------------------------- CANTP -----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*! \Description    CanTp_CopyTxData/CanTp_TxConfirm minimum routing table \n
    \Size           PduR_u16CANTP_TX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16CANTP_TX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoTpTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanTpTxMinRT[PduR_u16CANTP_TX_MINRT_SIZE] =
{
};
#endif

/******************************************************************************/
/*! \Description    CanTp_StartRx/CopyRxData/RxInd minimum routing table \n
    \Size           PduR_u16CANTP_RX_MINRT_SIZE \n
    \Trace_to       PduR-CDD-0220(0)
*******************************************************************************/
#if(PduR_u16CANTP_RX_MINRT_SIZE > 0UL)
CONST(PduR_tstrLoTpRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanTpRxMinRT[PduR_u16CANTP_RX_MINRT_SIZE] =
{
};
#endif


#define PDUR_STOP_CONFIG_DATA_16
#include "Memmap.h"

/******************************************************************************/
/* Configured Function Pointers Arrays for Minimum Routing                    */
/******************************************************************************/

#define PDUR_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

/* !Deviation : Inhibit MISRA rule: Parameter identifiers in functions are    */
/*              specified by the user of the module and cannot be changed     */
/* PRQA S 1334 ++                                                             */

/*----------------------------- LO Tx Functions ------------------------------*/
#if(PduR_bIFLO_ENABLED == STD_ON)
CONST(PduR_tstrIfTxFuncPtrType, PDUR_CFG_CONST) PduR_akstreUp2IfTxMinFnPtT[2] =
{
    {
        /* pfu8IfTransmit           */  CanIf_Transmit,
        /* pfu8IfCancelTransmit     */  CanIf_CancelTransmit,
                                        
    },
    {
        /* pfu8IfTransmit           */  LinIf_Transmit,
        /* pfu8IfCancelTransmit     */  LinIf_CancelTransmit,
                                        
    },
};
#endif

#if(PduR_bTPLO_ENABLED == STD_ON)
CONST(PduR_tstrTpTxFuncPtrType, PDUR_CFG_CONST) PduR_akstreUp2TpTxMinFnPtT[1] =
{
    {
        /* pfu8TpTransmit           */  CanTp_Transmit,
        
        /* pfu8TpCancelRxReq        */  CanTp_CancelReceive,
        /* pfu8TpCancelTxReq        */  CanTp_CancelTransmit,
        /* pfu8TpChangeParamReq     */  NULL_PTR,
    },
};
#endif

/*---------------------------- IF Conf Functions -----------------------------*/
#if(PduR_bIFUP_ENABLED == STD_ON)
CONST(PduR_tstrIf2UpTxFuncPtrType, PDUR_CFG_CONST) PduR_akstreIf2UpMinFnPtTxT[1] =
{
    {
        /* pfvidUpIfTxConf          */  Com_TxConfirmation,
        /* pfu8UpIfTriggerTx        */  Com_TriggerTransmit,
    },
};


/*----------------------------- IF Rx Functions ------------------------------*/
CONST(PduR_tstrIf2UpRxFuncPtrType, PDUR_CFG_CONST) PduR_akstreIf2UpMinFnPtRxT[1] =
{
    {   /* pfvidUpIfRxIndication    */  Com_RxIndication, },
};
#endif

/*---------------------------- TP Conf Functions -----------------------------*/
#if(PduR_bTPUP_ENABLED == STD_ON)
CONST(PduR_tstrTp2UpTxFuncPtrType, PDUR_CFG_CONST) PduR_akstreTp2UpMinFnPtTxT[1] =
{
    {
        /* pfvidUpTpTxConf          */  Com_TpTxConfirmation,
        /* pfenuUpTpCopyTxData      */  Com_CopyTxData,
    },
};

/*----------------------------- TP Rx Functions ------------------------------*/
CONST(PduR_tstrTp2UpRxFuncPtrType, PDUR_CFG_CONST) PduR_akstreTp2UpMinFnPtRxT[1] =
{
    {
        /* pfvidUpTpRxIndication    */  Com_TpRxIndication,
        /* pfenuUpTpCopyRxData      */  Com_CopyRxData,
        /* pfenuUpTpStartOfRx       */  Com_StartOfReception
    },
};
#endif

/* PRQA S 1334 --                                                             */

#define PDUR_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"
    
/* PRQA S 857 --                                                              */
/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
