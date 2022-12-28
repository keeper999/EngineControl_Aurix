
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_PBCfg.c                                            */
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
/* $Revision::   1.88      $$Author::   sedrees       $$Date::   Aug 24 2014 $*/
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

/* !Deviation : Inhibit MISRA rule [0850]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [2213]: Better readability encountered     */
/*              when having all configuration parameters on same line         */
/* PRQA S 2213 L1                                                             */

/* !Deviation : Inhibit MISRA rule [3132]: Magic numbers are auto-generated   */
/*              the configuration tool as this is a configuration file        */
/* PRQA S 3132 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0553]: File might be included but with no */
/*              external linkage due to usage of minimum routing only         */
/* PRQA S 0553 L1                                                             */

/* !Deviation: Inhibit MISRA rule [0857] Under certain configurations, PduR   */
/*             may have more than 1024 definitions, so the compiler should be */
/*             able to handle more than 1024 definitions.                     */
/* PRQA S 857 ++                                                              */

#include "Compiler.h"

#include "Std_Types.h"
#include "ComStack_Types.h"
#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR_Cfg.h"
#include "PduR_LocalCfg.h"

#include "PduR_PBCfg.h"
#include "PduR_UserIf.h"
#include "PduR_UserTp.h"
#include "PduR_UserUp.h"
#include "PduR_Gate.h"

#include "PduR_CanTp.h"

#include "PduR_CanIf.h"

#include "PduR_LinIf.h"

#include "Com_Cfg.h"

    
#if(PduR_bCALLOUT_SUPPORTED == STD_ON)
#include "PduR_Callout.h"
#endif


#if(PduR_u8NUMBER_OF_PB_CONFIGS > 0UL)
/******************************************************************************/
/* Auto-Generated RAM arrays configured at Post-Build time                    */
/******************************************************************************/

#define PDUR_START_SEC_CALIB_DATA_16
#include "Memmap.h"


#define PDUR_STOP_SEC_CALIB_DATA_16
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_DATA_UNSPECIFIED
#include "Memmap.h"



#define PDUR_STOP_SEC_CALIB_DATA_UNSPECIFIED
#include "Memmap.h"


/******************************************************************************/
/* PDUR Post Build Configurations                                             */
/******************************************************************************/

#define PDUR_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

/*------------------------- Functions Pointers Tables ------------------------*/

/* !Deviation : Inhibit MISRA rule: Parameter identifiers in functions are    */
/*              specified by the user of the module and cannot be changed     */
/* PRQA S 1334 ++                                                             */

#if(PduR_bIFLO_ENABLED == STD_ON)

static CONST(PduR_tstrIf2UpRxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrIf2UpFnPtRxT[3] =
{
    {   /* pfvidUpIfRxIndication    */  Com_RxIndication, },

    #if(PduR_bGATEWAYING_IF == STD_ON)
    {   /* pfvidUpIfRxIndication    */  PduR_vidGateRxIndication, },
    #else
    {   /* pfvidUpIfRxIndication    */  NULL_PTR, },
    #endif
    #if(PduR_bIFUP_ENABLED == STD_ON)
    {   /* pfvidUpIfRxIndication    */  PduR_vidMultiUpRxIndication, },
    #else
    {   /* pfvidUpIfRxIndication    */  NULL_PTR, },
    #endif
};

static CONST(PduR_tstrIfTxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrUp2IfTxFnPtT[4] =
{
    {
        /* pfu8IfTransmit           */  CanIf_Transmit,
        /* pfu8IfCancelTransmit     */  CanIf_CancelTransmit,
    },
    {
        /* pfu8IfTransmit           */  LinIf_Transmit,
        /* pfu8IfCancelTransmit     */  LinIf_CancelTransmit,
    },
    #if(PduR_bMULTICASTING_IF == STD_ON)
    {
        /* pfu8IfTransmit           */  PduR_u8MultiIfTransmit,
        /* pfu8IfCancelTransmit     */  PduR_u8MultiCancelTransmit,
    },
    #else
    {
        /* pfu8IfTransmit           */  NULL_PTR,
        /* pfu8IfCancelTransmit     */  NULL_PTR,
    },
    #endif
    
    {
        #if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_IF == STD_ON)
        /* pfu8IfTransmit           */  PduR_u8GtComRxInd,
        #else
        /* pfu8IfTransmit           */  NULL_PTR,
        #endif
        /* pfu8IfCancelTransmit     */  NULL_PTR,
    },
};

static CONST(PduR_tstrIf2UpTxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrIf2UpFnPtTxT[3] =
{
    {
        /* pfvidUpIfTxConf          */  Com_TxConfirmation,
        /* pfu8UpIfTriggerTx        */  Com_TriggerTransmit,
    },
    #if(PduR_bGATEWAYING_IF == STD_ON)
    {
        /* pfvidUpIfTxConf          */  PduR_vidGateTxConfirmation,
        /* pfu8UpIfTriggerTx        */  PduR_u8GateTriggerTransmit,
    },
    #else
    {
        /* pfvidUpIfTxConf          */  NULL_PTR,
        /* pfu8UpIfTriggerTx        */  NULL_PTR,
    },
    #endif
    #if(PduR_bMULTICASTING_IF == STD_ON)
    {
        /* pfvidUpIfTxConf          */  PduR_vidMultiTxConfirmation,
        /* pfu8UpIfTriggerTx        */  PduR_u8MultiTriggerTransmit,
    },
    #else
    {
        /* pfvidUpIfTxConf          */  NULL_PTR,
        /* pfu8UpIfTriggerTx        */  NULL_PTR,
    },
    #endif
};

#endif

#if(PduR_bTPLO_ENABLED == STD_ON)

static CONST(PduR_tstrTp2UpRxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrTp2UpFnPtRxT[2] =
{
    {
        /* pfvidUpTpRxIndication    */  Com_TpRxIndication,
        /* pfenuUpTpCopyRxData      */  Com_CopyRxData,
        /* pfenuUpTpStartOfRx       */  Com_StartOfReception
    },
    #if(PduR_bGATEWAYING_TP == STD_ON)
    {
        /* pfvidUpTpRxIndication    */  PduR_vidGateTpRxIndication,
        /* pfenuUpTpCopyRxData      */  PduR_enuGateTpCopyRxData,
        /* pfenuUpTpStartOfRx       */  PduR_enuGateTpStartOfRx
    },
    #else
    {
        /* pfvidUpTpRxIndication    */  NULL_PTR,
        /* pfenuUpTpCopyRxData      */  NULL_PTR,
        /* pfenuUpTpStartOfRx       */  NULL_PTR
    },
    #endif
};

static CONST(PduR_tstrTpTxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrUp2TpTxFnPtT[3] =
{
    {
        /* pfu8TpTransmit           */  CanTp_Transmit,
        
        /* pfu8TpCancelRxReq        */  CanTp_CancelReceive,
        /* pfu8TpCancelTxReq        */  CanTp_CancelTransmit,
        /* pfu8TpChangeParamReq     */  NULL_PTR,
    },
    #if(PduR_bMULTICASTING_TP == STD_ON)
    {
        /* pfu8TpTransmit           */  PduR_u8MultiTpTransmit,
        /* pfu8TpCancelRxReq        */  NULL_PTR,
        /* pfu8TpCancelTxReq        */  PduR_u8MultiCancelTxRequest,
        /* pfu8TpChangeParamReq     */  NULL_PTR,
    },
    #else
    {
        /* pfu8TpTransmit           */  NULL_PTR,
        /* pfu8TpCancelRxReq        */  NULL_PTR,
        /* pfu8TpCancelTxReq        */  NULL_PTR,
        /* pfu8TpChangeParamReq     */  NULL_PTR,
    },
    #endif
    {
        #if(PduR_bCOM_PRESENT == STD_ON && PduR_bGATEWAYING_TP == STD_ON)
        /* pfu8TpTransmit           */  PduR_u8GtComTpRxInd,
        #else
        /* pfu8TpTransmit           */  NULL_PTR,
        #endif
        /* pfu8TpCancelRxReq        */  NULL_PTR,
        /* pfu8TpCancelTxReq        */  NULL_PTR,
        /* pfu8TpChangeParamReq     */  NULL_PTR,
    },
};

static CONST(PduR_tstrTp2UpTxFuncPtrType, PDUR_CALIB_CONST)
                                                        akstrTp2UpFnPtTxT[3] =
{
    {
        /* pfvidUpTpTxConf          */  Com_TpTxConfirmation,
        /* pfenuUpTpCopyTxData      */  Com_CopyTxData,
    },
    #if(PduR_bGATEWAYING_TP == STD_ON)
    {
        /* pfvidUpTpTxConf          */  PduR_vidGateTpTxConfirm,
        /* pfenuUpTpCopyTxData      */  PduR_enuGateTpCopyTxData,
    },
    #else
    {
        /* pfvidUpTpTxConf          */  NULL_PTR,
        /* pfenuUpTpCopyTxData      */  NULL_PTR,
    },
    #endif
    #if(PduR_bMULTICASTING_TP == STD_ON)
    {
        /* pfvidUpTpTxConf          */  PduR_vidMultiTpTxConfirm,
        /* pfenuUpTpCopyTxData      */  PduR_enuMultiTpCopyTxData,
    },
    #else
    {
        /* pfvidUpTpTxConf          */  NULL_PTR,
        /* pfenuUpTpCopyTxData      */  NULL_PTR,
    },
    #endif
};

#endif

/* PRQA S 1334 --                                                             */

#define PDUR_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_CONST_16
#include "Memmap.h"

/*------------------------- Rx Indication over CanIf -------------------------*/
static CONST(PduR_tstrLoIfRxRTableType, PDUR_CALIB_CONST) akstrCanIfRxRT[35] =
{
    /* Routing Path: BSI_572  */
      
    {
        /* BSI_572_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_572,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: CLIM_50E  */
      
    {
        /* CLIM_50E_Dest */
        
        /* udtUpPduRefId    */  Com_CLIM_50E,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: V2_BSI_552  */
      
    {
        /* V2_BSI_552_Dest */
        
        /* udtUpPduRefId    */  Com_V2_BSI_552,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: DIRA_495  */
      
    {
        /* DIRA_495_Dest */
        
        /* udtUpPduRefId    */  Com_DIRA_495,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_4F2  */
      
    {
        /* BSI_4F2_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_4F2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: V2_BV_3C9  */
      
    {
        /* V2_BV_3C9_Dest */
        
        /* udtUpPduRefId    */  Com_V2_BV_3C9,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: CONTEXTE_1_7F2  */
      
    {
        /* CONTEXTE_1_7F2_Dest */
        
        /* udtUpPduRefId    */  Com_CONTEXTE_1_7F2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: CRASH_4C8  */
      
    {
        /* CRASH_4C8_Dest */
        
        /* udtUpPduRefId    */  Com_CRASH_4C8,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_412  */
      
    {
        /* BSI_412_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_412,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: DAT_BSI_532  */
      
    {
        /* DAT_BSI_532_Dest */
        
        /* udtUpPduRefId    */  Com_DAT_BSI_532,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: NEW_JDD_55F  */
      
    {
        /* NEW_JDD_55F_Dest */
        
        /* udtUpPduRefId    */  Com_NEW_JDD_55F,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: VDS_BSI_492  */
      
    {
        /* VDS_BSI_492_Dest */
        
        /* udtUpPduRefId    */  Com_VDS_BSI_492,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: V2_BV_489  */
      
    {
        /* V2_BV_489_Dest */
        
        /* udtUpPduRefId    */  Com_V2_BV_489,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: ABR_50D  */
      
    {
        /* ABR_50D_Dest */
        
        /* udtUpPduRefId    */  Com_ABR_50D,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: CONTEXTE_1_5B2  */
      
    {
        /* CONTEXTE_1_5B2_Dest */
        
        /* udtUpPduRefId    */  Com_CONTEXTE_1_5B2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_592  */
      
    {
        /* BSI_592_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_592,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: CDS_34D  */
      
    {
        /* CDS_34D_Dest */
        
        /* udtUpPduRefId    */  Com_CDS_34D,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_792  */
      
    {
        /* BSI_792_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_792,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: FRE_30D  */
      
    {
        /* FRE_30D_Dest */
        
        /* udtUpPduRefId    */  Com_FRE_30D,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: ELECTRON_BSI_092  */
      
    {
        /* ELECTRON_BSI_092_Dest */
        
        /* udtUpPduRefId    */  Com_ELECTRON_BSI_092,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: VIS_BSI_4B2  */
      
    {
        /* VIS_BSI_4B2_Dest */
        
        /* udtUpPduRefId    */  Com_VIS_BSI_4B2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_432  */
      
    {
        /* BSI_432_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_432,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: ABR_38D  */
      
    {
        /* ABR_38D_Dest */
        
        /* udtUpPduRefId    */  Com_ABR_38D,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: ABR_44D  */
      
    {
        /* ABR_44D_Dest */
        
        /* udtUpPduRefId    */  Com_ABR_44D,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: VOL_305  */
      
    {
        /* VOL_305_Dest */
        
        /* udtUpPduRefId    */  Com_VOL_305,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_612  */
      
    {
        /* BSI_612_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_612,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: BSI_CMM_0A8  */
      
    {
        /* BSI_CMM_0A8_Dest */
        
        /* udtUpPduRefId    */  Com_BSI_CMM_0A8,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: UCC_CMM_0E0  */
      
    {
        /* UCC_CMM_0E0_Dest */
        
        /* udtUpPduRefId    */  Com_UCC_CMM_0E0,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: STT_BV_329  */
      
    {
        /* STT_BV_329_Dest */
        
        /* udtUpPduRefId    */  Com_STT_BV_329,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: FRE_3CD  */
      
    {
        /* FRE_3CD_Dest */
        
        /* udtUpPduRefId    */  Com_FRE_3CD,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: JDD_CAN_BSI_772  */
      
    {
        /* JDD_CAN_BSI_772_Dest */
        
        /* udtUpPduRefId    */  Com_JDD_CAN_BSI_772,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: V2_BVA_349  */
      
    {
        /* V2_BVA_349_Dest */
        
        /* udtUpPduRefId    */  Com_V2_BVA_349,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: DMTR_57C  */
      
    {
        /* DMTR_57C_Dest */
        
        /* udtUpPduRefId    */  Com_DMTR_57C,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: EASY_MOVE_3AD  */
      
    {
        /* EASY_MOVE_3AD_Dest */
        
        /* udtUpPduRefId    */  Com_EASY_MOVE_3AD,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: WMI_BSI_4D2  */
      
    {
        /* WMI_BSI_4D2_Dest */
        
        /* udtUpPduRefId    */  Com_WMI_BSI_4D2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
};

/*------------------------- Rx Indication over LinIf -------------------------*/
static CONST(PduR_tstrLoIfRxRTableType, PDUR_CALIB_CONST) akstrLinIfRxRT[2] =
{
    /* Routing Path: ETA_ALT1  */
      
    {
        /* ETA_ALT1_Dest */
        
        /* udtUpPduRefId    */  Com_ETA_ALT1,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
    /* Routing Path: ETA_ALT2  */
      
    {
        /* ETA_ALT2_Dest */
        
        /* udtUpPduRefId    */  Com_ETA_ALT2,
        /* u8UpPduDeviceId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        
        /* u16RPathGrpId    */  1,
        #endif
    },
};

/*------------------------ Tx Confirmation over CanIf ------------------------*/
static CONST(PduR_tstrLoIfTxRTableType, PDUR_CALIB_CONST)  akstrCanIfTxRT[23] =
{
    /* CMM_BV_2E8_Dest */
    {
        /* udtUpPduRefId    */  0,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  20,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_588_Dest */
    {
        /* udtUpPduRefId    */  1,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  15,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_608_Dest */
    {
        /* udtUpPduRefId    */  2,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  17,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_3B8_Dest */
    {
        /* udtUpPduRefId    */  3,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  11,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* STT_CMM_3C8_Dest */
    {
        /* udtUpPduRefId    */  4,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  29,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_788_Dest */
    {
        /* udtUpPduRefId    */  5,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  18,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_108_Dest */
    {
        /* udtUpPduRefId    */  6,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  5,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_348_Dest */
    {
        /* udtUpPduRefId    */  7,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  9,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_7A8_Dest */
    {
        /* udtUpPduRefId    */  8,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  19,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_488_Dest */
    {
        /* udtUpPduRefId    */  9,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  14,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* EAC_CMM_BSI_072_Dest */
    {
        /* udtUpPduRefId    */  10,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  22,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* PduRDestPdu_0 */
    {
        /* udtUpPduRefId    */  55,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  28,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_438_Dest */
    {
        /* udtUpPduRefId    */  12,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  12,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* EAC_CMM_UCC_0E8_Dest */
    {
        /* udtUpPduRefId    */  13,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  23,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* JDD_CAN_CMM_768_Dest */
    {
        /* udtUpPduRefId    */  14,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  25,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_5F8_Dest */
    {
        /* udtUpPduRefId    */  15,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  16,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_228_Dest */
    {
        /* udtUpPduRefId    */  16,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  8,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_1E8_Dest */
    {
        /* udtUpPduRefId    */  17,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  6,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_388_Dest */
    {
        /* udtUpPduRefId    */  18,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  10,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_468_Dest */
    {
        /* udtUpPduRefId    */  19,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  13,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* NEW_JDD_CMM_768_Dest */
    {
        /* udtUpPduRefId    */  34,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  26,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* CMM_208_Dest */
    {
        /* udtUpPduRefId    */  21,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  7,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
    /* RQD_CMM_BSI_072_Dest */
    {
        /* udtUpPduRefId    */  43,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  27,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
};

/*------------------------ Tx Confirmation over LinIf ------------------------*/
static CONST(PduR_tstrLoIfTxRTableType, PDUR_CALIB_CONST)  akstrLinIfTxRT[1] =
{
    /* CDE_ALT_Dest */
    {
        /* udtUpPduRefId    */  64,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  4,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  3,
        
        #endif
        #if(PduR_bDEV_ERROR_DETECT == STD_ON)
        /* u8DataProvision  */  PduR_u8TRIGGERED,
        /* bTxConfirmation  */  TRUE,
        #endif
    },
};

#define PDUR_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_CONST_8
#include "Memmap.h"

/*------------------------ Trigger Transmit Defaults -------------------------*/


  
  
  
  

#define PDUR_STOP_SEC_CALIB_CONST_8
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_CONST_16
#include "Memmap.h"


/*--------------------------- If Gatewaying Table ----------------------------*/



    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    

/*-------------------------- If Mulicasting Table ----------------------------*/

#define PDUR_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_CONST_8
#include "Memmap.h"


#define PDUR_STOP_SEC_CALIB_CONST_8
#include "Memmap.h"


#define PDUR_START_SEC_CALIB_CONST_16
#include "Memmap.h"


/*------------------------- Rx Indication over CanTp -------------------------*/
static CONST(PduR_tstrLoTpRxRTableType, PDUR_CALIB_CONST) akstrCanTpRxRT[4] = 
{
    {
        /* EOBD_ON_CAN_7DF_Dest */
        /* udtUpPduRefId    */  42,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  1,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  1,
        #endif
        
    },
    {
        /* UDS_ON_CAN_7FF_Dest */
        /* udtUpPduRefId    */  44,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  3,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  1,
        #endif
        
    },
    {
        /* DIAG_ON_CAN_6A8_Dest */
        /* udtUpPduRefId    */  47,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  0,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  1,
        #endif
        
    },
    {
        /* EOBD_ON_CAN_7E0_Dest */
        /* udtUpPduRefId    */  61,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  2,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  1,
        #endif
        
    },
};


/*--------------------------- Tp Gatewaying Table ----------------------------*/


/******************************************************************************/
/*! \Description    Holds the index from which a gatewaying operation over TP
                    started (the Id/index used to enter the TP GW table) \n
    \Size           # of TRUEs in TP Gateway PB Table \n
--------------------------------------------------------------------------------
    \Configuration  Auto-generated by the configuration tool, no containers
*******************************************************************************/
/*------------------------ Tx Confirmation over CanTp ------------------------*/
/******************************************************************************/
/*! \Description    Routing table that holds (for each lower TP BswModule) the 
                    information of the source that this module will communicate
                    with (e.g.: forward the confirmation to) \n
*******************************************************************************/
static CONST(PduR_tstrLoTpTxRTableType, PDUR_CALIB_CONST)  akstrCanTpTxRT[2] =
{
    {
        /*EOBD_ON_CAN_7E8*/
        
        /* udtUpPduRefId    */  Com_EOBD_ON_CAN_7E8,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  24,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  2,
        #endif
    },
    {
        /*DIAG_ON_CAN_688*/
        
        /* udtUpPduRefId    */  Com_DIAG_ON_CAN_688,
        /* u8UpPduDeviceId  */  0,
        /* u16IPduGlobalId  */  21,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  2,
        #endif
    },
};


/*-------------------------- Tp Mulicasting Table ----------------------------*/

#define PDUR_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"


#define PDUR_START_SEC_CALIB_CONST_8
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Holds the index from which a multicasting operation over TP
                    started (the Id/index used to enter the TP MC table) \n
    \Size           # of TRUEs in TP Multicasting PB Table \n
--------------------------------------------------------------------------------
    \Configuration  Auto-generated by the configuration tool, no containers
*******************************************************************************/

#define PDUR_STOP_SEC_CALIB_CONST_8
#include "Memmap.h"

#define PDUR_START_SEC_CALIB_CONST_16
#include "Memmap.h"

/*--------------------------- Com Transmit Tables ----------------------------*/
static CONST(PduR_tstrUpTxRTableType, PDUR_CALIB_CONST) akstrComRT[26] =
{
    {
        /*  CMM_BV_2E8_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_BV_2E8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  20,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_588_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_588,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  15,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_608_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_608,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  17,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_3B8_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_3B8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  11,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  STT_CMM_3C8_Dest */
        /* udtDstPduRefId   */  CanIf_STT_CMM_3C8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  29,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_788_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_788,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  18,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_108_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_108,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  5,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_348_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_348,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  9,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_7A8_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_7A8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  19,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_488_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_488,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  14,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  EAC_CMM_BSI_072_Dest */
        /* udtDstPduRefId   */  CanIf_EAC_CMM_BSI_072,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  22,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  PduRDestPdu_0 */
        /* udtDstPduRefId   */  CanIf_RQD_CMM_UCC_0E8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  28,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_438_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_438,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  12,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  EAC_CMM_UCC_0E8_Dest */
        /* udtDstPduRefId   */  CanIf_EAC_CMM_UCC_0E8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  23,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  JDD_CAN_CMM_768_Dest */
        /* udtDstPduRefId   */  CanIf_JDD_CAN_CMM_768,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  25,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_5F8_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_5F8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  16,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_228_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_228,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  8,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_1E8_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_1E8,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  6,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_388_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_388,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  10,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_468_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_468,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  13,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  NEW_JDD_CMM_768_Dest */
        /* udtDstPduRefId   */  CanIf_NEW_JDD_CMM_768,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  26,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CMM_208_Dest */
        /* udtDstPduRefId   */  CanIf_CMM_208,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  7,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  RQD_CMM_BSI_072_Dest */
        /* udtDstPduRefId   */  CanIf_RQD_CMM_BSI_072,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  27,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  0,
        #endif
        /* u8DataProvision  */  PduR_u8DIRECT,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  EOBD_ON_CAN_7E8_Dest */
        /* udtDstPduRefId   */  CanTp_OBD_FUNCTIONNAL_7DF_Tx,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  24,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  2,
        #endif
        /* u8DataProvision  */  PduR_u8NONINTERFACE,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  DIAG_ON_CAN_688_Dest */
        /* udtDstPduRefId   */  CanTp_UDS_Functional_7FF_Tx,
        /* u8DstPduDeviceId */  0,
        /* u16IPduGlobalId  */  21,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  2,
        #endif
        /* u8DataProvision  */  PduR_u8NONINTERFACE,
        /* bTxConfirmation  */  TRUE,
    },
    {
        /*  CDE_ALT_Dest */
        /* udtDstPduRefId   */  LinIf_CDE_ALT,
        /* u8DstPduDeviceId */  1,
        /* u16IPduGlobalId  */  4,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId    */  3,
        #endif
        /* u8DataProvision  */  PduR_u8TRIGGERED,
        /* bTxConfirmation  */  TRUE,
    },
};

/******************************************************************************/
/*! \Description    Routing table that holds (for each TP upper BswModule) the 
                    reverse information used when a cancellation operation or
                    change parameter operation are invoked \n
*******************************************************************************/
static CONST(PduR_tstrUpTpRevTableType, PDUR_CALIB_CONST) akstrComRevRT[4] =
{
    {/* EOBD_ON_CAN_7DF_Dest */
        /* udtDstPduRefId       */  Com_EOBD_ON_CAN_7DF,
        /* u8DstPduDeviceRefId  */  0,
        /* udtLowPduRefId       */  CanTp_OBD_FUNCTIONNAL_7DF_Rx,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId        */  1,
        #endif
    },
    {/* UDS_ON_CAN_7FF_Dest */
        /* udtDstPduRefId       */  Com_UDS_ON_CAN_7FF,
        /* u8DstPduDeviceRefId  */  0,
        /* udtLowPduRefId       */  CanTp_UDS_Functional_7FF_Rx,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId        */  1,
        #endif
    },
    {/* DIAG_ON_CAN_6A8_Dest */
        /* udtDstPduRefId       */  Com_DIAG_ON_CAN_6A8,
        /* u8DstPduDeviceRefId  */  0,
        /* udtLowPduRefId       */  CanTp_UDS_PHYSICAL_6A8_RX,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId        */  1,
        #endif
    },
    {/* EOBD_ON_CAN_7E0_Dest */
        /* udtDstPduRefId       */  Com_EOBD_ON_CAN_7E0,
        /* u8DstPduDeviceRefId  */  0,
        /* udtLowPduRefId       */  CanTp_OBD_PHYSICAL_7E0_Rx,
        #if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
        /* u16RPathGrpId        */  1,
        #endif
    },
};


#define PDUR_STOP_SEC_CALIB_CONST_16
#include "Memmap.h"

/******************************************************************************/
/* Main PduR Configuration Structure                                          */
/******************************************************************************/

#define PDUR_START_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

static CONST(PduR_PBConfigType, PDUR_CALIB_CONST) kstrPduRPBConfig = 
{
    /*----------------------- Function Pointers Tables -----------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bIFLO_ENABLED == STD_ON)
    /* pkstrIfTxFuncTable           */  akstrUp2IfTxFnPtT,
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    /* pkstrTpTxFuncTable           */  akstrUp2TpTxFnPtT,
    #endif
    /*------------------------------------------------------------------------*/
    #if(PduR_bIFLO_ENABLED == STD_ON)
    /* pkstrIf2UpRxFuncTable        */  akstrIf2UpFnPtRxT,
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    /* pkstrTp2UpRxFuncTable        */  akstrTp2UpFnPtRxT,
    #endif
    /*------------------------------------------------------------------------*/
    #if(PduR_bIFLO_ENABLED == STD_ON)
    /* pkstrIf2UpTxFuncTable        */  akstrIf2UpFnPtTxT,
    #endif
    #if(PduR_bTPLO_ENABLED == STD_ON)
    /* pkstrTp2UpTxFuncTable        */  akstrTp2UpFnPtTxT,
    #endif
    /*------------------------------------------------------------------------*/

    /*----------------------------- Up Tx Tables -----------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bCOM_PRESENT == STD_ON)
    /* pkstrComUpTxRTable             */  akstrComRT,
    /* u16ComUpTxRTSize               */  26UL,
    #endif

    /*--------------------------- Up Tx Rev Tables ---------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bCOM_PRESENT == STD_ON)
    /* pkstrComRevRTable            */  akstrComRevRT,
    /* u16ComRevRTSize              */  4UL,
    #endif

    /*----------------------------- IF Tx Tables -----------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bCANIF_PRESENT == STD_ON)
    /* pkstrCanIfTxRTable           */  akstrCanIfTxRT,
    /* u16CanIfTxRTSize             */  23UL,
    #endif

    #if(PduR_bLINIF_PRESENT == STD_ON)
    /* pkstrLinIfTxRTable           */  akstrLinIfTxRT,
    /* u16LinIfTxRTSize             */  1UL,
    #endif

    /*----------------------------- IF Rx Tables -----------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bIFLO_ENABLED == STD_ON)
    /* pkstrMultiUpRxRTable         */  NULL_PTR,
    /* u16MultiUpRxRTSize           */  0UL,
    #endif


    #if(PduR_bCANIF_PRESENT == STD_ON)
    /* pkstrCanIfRxRTable           */  akstrCanIfRxRT,
    /* u16CanIfRxRTSize             */  35UL,
    #endif

    #if(PduR_bLINIF_PRESENT == STD_ON)
    /* pkstrLinIfRxRTable           */  akstrLinIfRxRT,
    /* u16LinIfRxRTSize             */  2UL,
    #endif

    /*----------------------------- TP Tx Tables -----------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bCANTP_PRESENT == STD_ON)
    /* pkstrCanTpTxRTable           */  akstrCanTpTxRT,
    /* u16CanTpTxRTSize             */  2UL,
    #endif


    /*----------------------------- TP Rx Tables -----------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bCANTP_PRESENT == STD_ON)
    /* pkstrCanTpRxRTable           */  akstrCanTpRxRT,
    /* u16CanTpRxRTSize             */  4UL,
    #endif


    /*------------------------- Multicasting Tables --------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bMULTICASTING_IF == STD_ON)
    /* pkstrMultiIfRTable           */  NULL_PTR,
    /* pkstrMultiIfSubRT            */  NULL_PTR,
    /* udtMultiIfRTSize             */  0UL,
    #endif

    #if(PduR_bMULTICASTING_TP == STD_ON)
    /* pkstrMultiTpRTable           */  NULL_PTR,
    /* pkstrMultiTpSubRT            */  NULL_PTR,
    /* udtMultiTpRTSize             */  0UL,
    #endif

    /*-------------------------- Gatewaying Tables ---------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bGATEWAYING_IF == STD_ON)
    /* pkstrGateIfRTable            */  NULL_PTR,
    /* udtGateIfRTSize              */  0UL,
    #endif

    #if(PduR_bGATEWAYING_TP == STD_ON)
    /* pkstrGateTpRTable            */  NULL_PTR,
    /* pkstrGateTpSubRT             */  NULL_PTR,
    /* udtGateTpRTSize              */  0UL,
    /* pkstrTpBuffRef               */  NULL_PTR,
    #endif

    /*------------------------------- Others ---------------------------------*/
    /*------------------------------------------------------------------------*/
    /* u16NumOfGlobalPdus           */  PduR_u16MAX_GLBL_IPDUS_NMBR,
    /* u16ConfigurationId           */  PduR_u16CONFIGURATION_ID_1,

    /*------------------------------ RAM Arrays ------------------------------*/
    /*------------------------------------------------------------------------*/
    #if(PduR_bMULTICASTING_TP == STD_ON)
    /* pstrMultiTpCntrl             */  NULL_PTR,
    /* pu16MultiTpCopyTxIdx         */  NULL_PTR,
    #endif

    #if(PduR_bGATEWAYING_TP == STD_ON)
    /* pstrGateTpCntrl              */  NULL_PTR,
    #endif
};

/* !Deviation : Inhibit MISRA rule: Configuration pointer has external linkage*/
/*              to files that are not part of the project                     */
/* PRQA S 3408 ++                                                             */
/******************************************************************************/
/* ! \Description   Array of PduR configuration structures exported to users  */
/******************************************************************************/
CONSTP2CONST(PduR_PBConfigType, PDUR_CALIB_CONST, PDUR_CALIB_CONST) 
                        PduR_akpkstreConfigArray[PduR_u8NUMBER_OF_PB_CONFIGS] = 
{
    &kstrPduRPBConfig,
};

/* PRQA S 3408 --                                                             */

#define PDUR_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "Memmap.h"

#endif
    
/* PRQA S 857 --                                                              */
/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
