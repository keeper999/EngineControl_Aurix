
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
/* !File            : PduR_LocalLCfg.h                                        */
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
/* $Revision::   1.10      $$Author::   sedrees       $$Date::   Aug 01 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef PDUR_LOCALLCFG_H
#define PDUR_LOCALLCFG_H

/* !Deviation : Inhibit MISRA rule [3132]: Magic numbers are auto-generated   */
/*              the configuration tool as this is a configuration file        */
/* PRQA S 3132 L1                                                             */

#include "PduR_LocalCfg.h"

    
/******************************************************************************/
/* Local Defines                                                              */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Number of entries in the CanTp module's Tx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16CANTP_TX_MINRT_SIZE         0UL

/******************************************************************************/
/*! \Description    Number of entries in the CanTp module's Rx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16CANTP_RX_MINRT_SIZE         0UL


/******************************************************************************/
/*! \Description    Number of entries in the Com module's UP routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16COM_MINRT_SIZE              0UL


/******************************************************************************/
/*! \Description    Number of entries in the Com module's REV routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16COM_REV_MINRT_SIZE          0UL


/******************************************************************************/
/*! \Description    Number of entries in the CanIf module's Tx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16CANIF_TX_MINRT_SIZE         0UL

/******************************************************************************/
/*! \Description    Number of entries in the CanIf module's Rx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16CANIF_RX_MINRT_SIZE         0UL


/******************************************************************************/
/*! \Description    Number of entries in the LinIf module's Tx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16LINIF_TX_MINRT_SIZE         0UL

/******************************************************************************/
/*! \Description    Number of entries in the LinIf module's Rx routing table \n
    \Range          1..65635 \n
*******************************************************************************/
#define PduR_u16LINIF_RX_MINRT_SIZE         0UL



/******************************************************************************/
/* EXTERNED DATA                                                              */
/******************************************************************************/

/*------------------------------ Defined Sizes -------------------------------*/
#define PDUR_START_CONFIG_DATA_8
#include "Memmap.h"

extern CONST(uint8, PDUR_CFG_CONST)     PduR_ku8eNumOfGlobalPdus;

#define PDUR_STOP_CONFIG_DATA_8
#include "Memmap.h"

#define PDUR_START_CONFIG_DATA_16
#include "Memmap.h"


extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eComMinRTSize;
extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eComMinRevTSize;

extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eCanIfTxMinRTSize;
extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eCanIfRxMinRTSize;

extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eLinIfTxMinRTSize;
extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eLinIfRxMinRTSize;

extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eCanTpTxMinRTSize;
extern CONST(uint16, PDUR_CFG_CONST)    PduR_ku16eCanTpRxMinRTSize;

#if(PduR_u16COM_MINRT_SIZE > 0UL)
/*-------------------------------- UP - COM ----------------------------------*/
extern CONST(PduR_tstrUpTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreComMinRT[PduR_u16COM_MINRT_SIZE];
#endif

#if(PduR_u16COM_REV_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrUpTpRevTableType, PDUR_CFG_CONST)
                    PduR_akstreComMinRevT[PduR_u16COM_REV_MINRT_SIZE];
#endif

/*-------------------------------- LO - CANIF --------------------------------*/
#if(PduR_u16CANIF_TX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoIfTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanIfTxMinRT[PduR_u16CANIF_TX_MINRT_SIZE];
#endif

#if(PduR_u16CANIF_RX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoIfRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanIfRxMinRT[PduR_u16CANIF_RX_MINRT_SIZE];
#endif

/*-------------------------------- LO - LINIF --------------------------------*/
#if(PduR_u16LINIF_TX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoIfTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreLinIfTxMinRT[PduR_u16LINIF_TX_MINRT_SIZE];
#endif

#if(PduR_u16LINIF_RX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoIfRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreLinIfRxMinRT[PduR_u16LINIF_RX_MINRT_SIZE];
#endif

/*-------------------------------- LO - CANTP --------------------------------*/
#if(PduR_u16CANTP_TX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoTpTxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanTpTxMinRT[PduR_u16CANTP_TX_MINRT_SIZE];
#endif

#if(PduR_u16CANTP_RX_MINRT_SIZE > 0UL)
extern CONST(PduR_tstrLoTpRxRTableType, PDUR_CFG_CONST)
                    PduR_akstreCanTpRxMinRT[PduR_u16CANTP_RX_MINRT_SIZE];
#endif



#define PDUR_STOP_CONFIG_DATA_16
#include "Memmap.h"

#define PDUR_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

/*---------------------------- Fn Pointer Tables -----------------------------*/
#if(PduR_bIFLO_ENABLED == STD_ON)
extern CONST(PduR_tstrIfTxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreUp2IfTxMinFnPtT[2];
#endif
#if(PduR_bTPLO_ENABLED == STD_ON)
extern CONST(PduR_tstrTpTxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreUp2TpTxMinFnPtT[1];
#endif


extern CONST(PduR_tstrTp2UpTxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreTp2UpMinFnPtTxT[1];

extern CONST(PduR_tstrIf2UpRxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreIf2UpMinFnPtRxT[1];

extern CONST(PduR_tstrTp2UpRxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreTp2UpMinFnPtRxT[1];

extern CONST(PduR_tstrIf2UpTxFuncPtrType, PDUR_CFG_CONST)
                    PduR_akstreIf2UpMinFnPtTxT[1];


#define PDUR_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"
    

#endif /* PDUR_LOCALLCFG_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
