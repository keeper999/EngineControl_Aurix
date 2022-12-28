
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Cfg                                               */
/*!\file            : CanIf_Cfg.h                                             \n
    \Description    :It contain Pre-Compile Configuration for the CanIf       */
/*                                                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.7      $$Author::   mamroussy      $$Date::   Jun 18 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/******************************************************************************/
/*!  \Description Configuration versions
*******************************************************************************/

#define CANIF_CFG_MAJOR_VERSION     0x02
#define CANIF_CFG_MINOR_VERSION     0x00

/******************************************************************************/
/*!  \Description Pre-Compile Configurations
*******************************************************************************/

/******************************************************************************/
/*!  \Description development Error Detection 
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicDevErrorDetect*/

#define CanIf_bDEV_ERR_DETECT                     STD_ON

/******************************************************************************/
/*!  \Description Dem Error Detection 
*******************************************************************************/
#define CanIf_bDEM_ERR_DETECT                      STD_OFF

/******************************************************************************/
/*! \Description Configuration parameter used to enable/disable      \n
                 version check between CanIf and other interfaced modules\n
*******************************************************************************/
#define CanIf_bINTER_MOD_VER_CHECK    STD_OFF
  

/******************************************************************************/
/*!  \Description Multiple Driver Support
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicMultipleDrvSupport*/

#define CanIf_bMULTI_DRV_SUPPORT                      STD_OFF
/******************************************************************************/
/*!  \Description Number of Can Drivers
*******************************************************************************/
/* CanIf_u8NUM_OF_CAN_DRVS value is configured with the number of instances 
   created from the sub-container CanIfCtrlDrvCfg*/
#define CanIf_u8NUM_OF_CAN_DRVS                     1
/******************************************************************************/
/*!  \Description Transmission Buffering
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicTxBuffering*/

#define CanIf_bTX_BUFFERING                       STD_ON
/******************************************************************************/
/*!  \Description Number Transceivers
*******************************************************************************/
/* CanIf_u8NUM_OF_TRCVS value is configured with the number of instances 
   created from the sub-container CanIfTrcvCfg*/
#define CanIf_u8NUM_OF_TRCVS                        0
/******************************************************************************/
/*!  \Description Number Transceivers Drivers
*******************************************************************************/
/* CanIf_u8NUM_OF_TRCV_DRVS value is configured with the number of instances 
   created from the sub-container CanIfTrcvDrvCfg*/
#define CanIf_u8NUM_OF_TRCV_DRVS                    0
/******************************************************************************/
/*!  \Description CanIf_ReadRxPduData API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicReadRxPduDataApi*/

#define CanIf_bREAD_RX_PDU_DATA_API                 STD_OFF
/******************************************************************************/
/*!  \Description CanIf_ReadTxNotifStatus API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicReadTxPduNotifyStatusApi*/

#define CanIf_bREAD_TX_NOTIF_API                    STD_OFF
/******************************************************************************/
/*!  \Description CanIf_GetVersionInfo API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicVersionInfoApi*/

#define CanIf_bVERSIONINFO_API                      STD_OFF
/******************************************************************************/
/*!  \Description CanIf_SetDynamicTxId API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicSetDynamicTxIdApi*/

#define CanIf_bSET_DYNAMIC_TXID_API                 STD_OFF
/******************************************************************************/
/*!  \Description CanIf_CheckValidation API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicWakeupCheckValidApi*/

#define CanIf_bWAKUP_CHK_VALID_API                  STD_OFF
/******************************************************************************/
/*!  \Description CanIf_GetTxConfirmationState API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicTxConfirmPollingSupport*/

#define CanIf_bTXCONF_POLL_SUPPORT                  STD_OFF
/******************************************************************************/
/*!  \Description CanIf_ReadRxNotifStatus API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicReadRxPduNotifyStatusApi*/ 

#define CanIf_bREAD_RX_NOTIF_API                    STD_OFF


#define CanIf_u8BINARY                              1
#define CanIf_u8LINEAR                              0
/******************************************************************************/
/*!  \Description Selects the desired software filter mechanism for reception 
                  only
*******************************************************************************/
/*CanIfPrivateCfg-->CanIfPrivateSoftwareFilterType*/

#define CanIf_udtSW_FILTER                          CanIf_u8BINARY
/******************************************************************************/
/*!  \Description CanIf_CancelTransmit API Configuration
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicCancelTransmitSupport*/

#define CanIf_bCANCEL_TRANSMIT                      STD_ON
/******************************************************************************/
/*!  \Description  Selects if desired Dlc for reception
*******************************************************************************/
/*CanIfPrivateCfg-->CanIfPrivateDlcCheck*/

#define CanIf_bDLC_CHECK                            STD_OFF
/******************************************************************************/
/*!  \Description  Selects if HRH   Ranges Configured
*******************************************************************************/
/*if at least one CanIfHrhCfg-->CanIfHrhSoftwareFilter is true this Config 
  should be STD_ON*/

#define CanIf_bHRH_SW_FILTER                        STD_OFF

/******************************************************************************/
/*!  \Description  Selects if Check Wakeup Validation is done only for 
                   NM messages
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicWakeupCheckValidByNM */

#define CanIf_bWAKEUP_VALID_BY_NM                   STD_OFF

/******************************************************************************/
/*!  \Description  Enables and disables the support of Partial Network features
in CanIf.
*******************************************************************************/
/*CanIfPublicCfg-->CanIfPublicPnSupport */
#define CanIf_bPUBLIC_PN_SUPPORT    STD_OFF

#define CanIf_u8UINT32                              30  /*Default*/
#define CanIf_u8UINT16                              40

/******************************************************************************/
/*!  \Description  CanId Type is U32 or U16 to prevent un-proper Left Shift 
*******************************************************************************/
/*Configured according to Can_IdType if uint32=CanIf_u8UINT32 and if 
  uint16 =CanIf_u8UINT16*/
/*if at least one CanIfTxPduCfg-->CanIfTxPduCanIdType or 
  CanIfRxPduCfg-->CanIfRxPduCanIdType is configured as EXTENDED_CAN it
  should be CanIf_u8UINT32 else it should be CanIf_u8UINT16*/

#define CanIf_u8CANIDTYPE                           CanIf_u8UINT16
/******************************************************************************/
/*!  \Description  CtrlDrv Configuration (TxCancellation)DRV0
*******************************************************************************/
/*if CanIfCtrlDrvCfg-->CanIfCtrlDrvTxCancellation of CanIfCtrlDrvCfg Instance 
0 is true this Config should be STD_ON*/

#define CanIf_bCTRLDRV_0_TX_CANCEL                   STD_OFF

/******************************************************************************/
/*!  \Description  CanIfTxPduCfg Array Index Access by Short-Name
*******************************************************************************/


#define CanIf_CCP_1000MS    3

#define CanIf_CCP_100MS    20

#define CanIf_CCP_10MS    32

#define CanIf_CCP_DEVAID_1000MS    27

#define CanIf_CCP_DEVAID_100MS    28

#define CanIf_CCP_DEVAID_10MS    34

#define CanIf_CCP_DEVAID_DTO    33

#define CanIf_CCP_DEVAID_PMH    29

#define CanIf_CCP_DTO    26

#define CanIf_CCP_PMH    14

#define CanIf_CMM_108    8

#define CanIf_CMM_1E8    19

#define CanIf_CMM_208    24

#define CanIf_CMM_228    18

#define CanIf_CMM_348    9

#define CanIf_CMM_388    21

#define CanIf_CMM_3B8    5

#define CanIf_CMM_438    11

#define CanIf_CMM_468    22

#define CanIf_CMM_488    0

#define CanIf_CMM_588    2

#define CanIf_CMM_5F8    17

#define CanIf_CMM_608    4

#define CanIf_CMM_788    7

#define CanIf_CMM_7A8    10

#define CanIf_CMM_BV_2E8    1

#define CanIf_CanTpTxNPdu_688    23

#define CanIf_CanTpTxNPdu_7E8    13

#define CanIf_EAC_CMM_BSI_072    12

#define CanIf_EAC_CMM_UCC_0E8    15

#define CanIf_JDD_CAN_CMM_768    16

#define CanIf_NEW_JDD_CMM_768    25

#define CanIf_RQD_CMM_BSI_072    31

#define CanIf_RQD_CMM_UCC_0E8    30

#define CanIf_STT_CMM_3C8    6



/******************************************************************************/
/*!  \Description  CanIfRxPduCfg Array Index Access by Short-Name
*******************************************************************************/

#define CanIf_ABR_38D    34

#define CanIf_ABR_44D    20

#define CanIf_ABR_50D    11

#define CanIf_BSI_412    36

#define CanIf_BSI_432    37

#define CanIf_BSI_4F2    4

#define CanIf_BSI_572    0

#define CanIf_BSI_592    13

#define CanIf_BSI_612    32

#define CanIf_BSI_792    15

#define CanIf_BSI_CMM_0A8    23

#define CanIf_CCP_CRO    39

#define CanIf_CCP_DEVAID_CRO    40

#define CanIf_CDS_34D    14

#define CanIf_CLIM_50E    1

#define CanIf_CONTEXTE_1_5B2    12

#define CanIf_CONTEXTE_1_7F2    38

#define CanIf_CRASH_4C8    6

#define CanIf_CanTpRxNPdu_7DF    18

#define CanIf_CanTpRxNPdu_7E0    35

#define CanIf_CanTpRxNPdu_7FF    19

#define CanIf_DAT_BSI_532    7

#define CanIf_DIRA_495    3

#define CanIf_DMTR_57C    31

#define CanIf_EASY_MOVE_3AD    29

#define CanIf_ELECTRON_BSI_092    17

#define CanIf_FRE_30D    16

#define CanIf_FRE_3CD    26

#define CanIf_JDD_CAN_BSI_772    27

#define CanIf_NEW_JDD_55F    8

#define CanIf_RXCanTpRxNPdu_6A8    22

#define CanIf_STT_BV_329    25

#define CanIf_UCC_CMM_0E0    24

#define CanIf_V2_BSI_552    2

#define CanIf_V2_BVA_349    28

#define CanIf_V2_BV_3C9    5

#define CanIf_V2_BV_489    10

#define CanIf_VDS_BSI_492    9

#define CanIf_VIS_BSI_4B2    33

#define CanIf_VOL_305    21

#define CanIf_WMI_BSI_4D2    30

/*-------------------------------- end of file -------------------------------*/
#endif              /*CANIF_CFG_H*/
      
          
