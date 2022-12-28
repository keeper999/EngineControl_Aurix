
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_PBCfg.h                                          */
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
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.14     $$Author::   sedrees        $$Date::   Aug 21 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_PBCFG_H
#define PDUR_PBCFG_H

#include "PduR_Cfg.h"
#include "PduR_LocalCfg.h"


/******************************************************************************/
/*! \Description    Identification of a configuration set in the PduR module \n
*******************************************************************************/
#define PduR_u16CONFIGURATION_ID_1          0UL


/******************************************************************************/
/*! \Description    Number of PB PduR configuration structures \n
    \Range          0..255 \n
*******************************************************************************/

#define PduR_u8NUMBER_OF_PB_CONFIGS         1U

#define    PduRRoutingTables    (*(PduR_akpkstreConfigArray[0]))

#define PDUR_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/*! \Description    Exporting the PB configuration array of the PduR module \n
*******************************************************************************/
#if(PduR_u8NUMBER_OF_PB_CONFIGS > 0U)
extern CONSTP2CONST(PduR_PBConfigType, PDUR_CALIB_CONST, PDUR_CALIB_CONST)
                          PduR_akpkstreConfigArray[PduR_u8NUMBER_OF_PB_CONFIGS];
#endif

#define PDUR_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"
    

/******************************************************************************/
/*! \Description    Routing Paths Definitions                                \n
*******************************************************************************/

/* Routing Table: CanIf_PduRRoutingTable */

#define    PduR_BSI_572    0
#define    PduR_CLIM_50E    1
#define    PduR_V2_BSI_552    2
#define    PduR_DIRA_495    3
#define    PduR_BSI_4F2    4
#define    PduR_V2_BV_3C9    5
#define    PduR_CONTEXTE_1_7F2    6
#define    PduR_CRASH_4C8    7
#define    PduR_BSI_412    8
#define    PduR_DAT_BSI_532    9
#define    PduR_NEW_JDD_55F    10
#define    PduR_VDS_BSI_492    11
#define    PduR_V2_BV_489    12
#define    PduR_ABR_50D    13
#define    PduR_CONTEXTE_1_5B2    14
#define    PduR_BSI_592    15
#define    PduR_CDS_34D    16
#define    PduR_BSI_792    17
#define    PduR_FRE_30D    18
#define    PduR_ELECTRON_BSI_092    19
#define    PduR_VIS_BSI_4B2    20
#define    PduR_BSI_432    21
#define    PduR_ABR_38D    22
#define    PduR_ABR_44D    23
#define    PduR_VOL_305    24
#define    PduR_BSI_612    25
#define    PduR_BSI_CMM_0A8    26
#define    PduR_UCC_CMM_0E0    27
#define    PduR_STT_BV_329    28
#define    PduR_FRE_3CD    29
#define    PduR_JDD_CAN_BSI_772    30
#define    PduR_V2_BVA_349    31
#define    PduR_DMTR_57C    32
#define    PduR_EASY_MOVE_3AD    33
#define    PduR_WMI_BSI_4D2    34


/* Routing Table: CanTp_PduRRoutingTable */

#define    PduR_EOBD_ON_CAN_7DF    0
#define    PduR_UDS_ON_CAN_7FF    1
#define    PduR_DIAG_ON_CAN_6A8    2
#define    PduR_EOBD_ON_CAN_7E0    3


/* Routing Table: Com_PduRRoutingTable */

#define    PduR_CMM_BV_2E8    0
#define    PduR_CMM_588    1
#define    PduR_CMM_608    2
#define    PduR_CMM_3B8    3
#define    PduR_STT_CMM_3C8    4
#define    PduR_CMM_788    5
#define    PduR_CMM_108    6
#define    PduR_CMM_348    7
#define    PduR_CMM_7A8    8
#define    PduR_CMM_488    9
#define    PduR_EAC_CMM_BSI_072    10
#define    PduR_RQD_CMM_UCC_0E8    11
#define    PduR_CMM_438    12
#define    PduR_EAC_CMM_UCC_0E8    13
#define    PduR_JDD_CAN_CMM_768    14
#define    PduR_CMM_5F8    15
#define    PduR_CMM_228    16
#define    PduR_CMM_1E8    17
#define    PduR_CMM_388    18
#define    PduR_CMM_468    19
#define    PduR_NEW_JDD_CMM_768    20
#define    PduR_CMM_208    21
#define    PduR_RQD_CMM_BSI_072    22
#define    PduR_EOBD_ON_CAN_7E8    23
#define    PduR_DIAG_ON_CAN_688    24
#define    PduR_CDE_ALT    25


/* Routing Table: LinIf_PduRRoutingTable */

#define    PduR_ETA_ALT1    0
#define    PduR_ETA_ALT2    1


#endif /* PDUR_PBCFG_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
