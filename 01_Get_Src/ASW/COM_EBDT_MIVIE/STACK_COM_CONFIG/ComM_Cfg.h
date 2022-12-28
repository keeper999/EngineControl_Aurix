/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AutOSAR requirements */
/* !Deviation: [3453] Violates MISRA rule 93: "A function should be used in
    preference to a function-like macro." but these function-like macros are
    only to abbreviate long function calls to make the code more readable and to
    avoid breaking the 80 characters mark.
*/
/* PRQA S 3453 ++ */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : ComM_Cfg.h                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
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

/******************************************************************************/
/*! \file ComM_Cfg.h
*
* \par
*   Configurables of the module ComM.
*   This file contains the Configurable externals of the module ComM. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module ComM
* This is the grouping of the ComM module members.
* \{
*/
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*
$Header::
*/
/* PRQA S 0288 --*/
/******************************************************************************/
#ifndef  COMM_CFG_H
#define  COMM_CFG_H





/******************************************************************************/
/*! \Description Configuration Parameter ComMVersionInfoApi.                  \n
                 Switches the possibility to read the published information with
                 the service ComM_GetPublishedInformation().                  \n
                 STD_ON:  Enabled                                             \n
                 STD_OFF: Disabled                                          \n\n
    \Range TRUE, FALSE                                                      \n\n
    \Unit boolean                                                           \n\n
*******************************************************************************/

/* ComMGeneral --> ComMVersionInfoApi */
#define ComM_bVERSION_INFO_API       STD_OFF
/*! ComMGeneral --> ComMSynchronousWakeUp */
#define ComM_bSYNCHRONOUS_WAKE_UP    FALSE

/*! Rte is Used or not */
/*! ComMGeneral --> ComMRteUsed */
#define ComM_bRTE_USED               STD_OFF

/******************************************************************************/
/*! \Description  Determines whether version check is to be made between 
 *                ComM and other interfaced modules or not.
*******************************************************************************/
#define ComM_bINTER_MOD_VER_CHECK          STD_OFF
  
/*! Det Error Reporting */
/*! ComMGeneral --> ComMDevErrorDetect */
#define ComM_bDEV_ERROR_DETECT       STD_OFF

/*! Multiplicity of ComMChannel container */
#define ComM_u16NO_OF_CHANNELS       3

/******************************************************************************/
/*! \Description    ComM Channels Definitions                                 \n
*******************************************************************************/

#define    ComM_u8ComMChannel_CanIS    0
#define    ComM_u8ComMChannel_Cpp_Devaid    1
#define    ComM_u8ComMChannel_Lin_1    2

/*! ComMGeneral --> ComMModeLimitationEnabled */
#define ComM_bMODE_LIMIT_ENABLE FALSE
/*! ComMGeneral --> ComMWakeupInhibitionEnabled */
#define ComM_bWAKEUP_INH_ENABLE FALSE

/*! ComMGeneral --> ComMDcmEnabled */
#define ComM_bCOMM_DCM_ENABLED FALSE
/*! ComMGeneral --> ComMPncSupport */
#define ComM_bPNC_SUPPORT FALSE
/*! ComMGeneral --> ComMPncGatewayEnabled */
#define ComM_bPNC_GW_ENABLED FALSE




/*! This is an indicator of the presence of any fullComRequestors SRI*/
#define ComM_bANY_FCOM_SRI_ENABLE FALSE



/*! Multiplicity of ComMUser container */
#define ComM_u8NO_OF_USERS 2

/******************************************************************************/
/*! \Description    ComM Users Definitions                                    \n
*******************************************************************************/

#define    ComM_u8ComMUser_Can    0


#define    ComM_u8ComMUser_Lin    1



/* Any ComMNmVariant==FULL */
#define ComM_bANY_FULL_CHANNEL     FALSE

/* Any ComMNmVariant==PASSIVE */
#define ComM_bANY_PASSIVE_CHANNEL  FALSE

/* Any ComMNmVariant==LIGHT */
#define ComM_bANY_LIGHT_CHANNEL    FALSE

/* Any ComMNmVariant==NONE */
#define ComM_bANY_NONE_CHANNEL     TRUE

/* Any ComMBusType!=COMM_BUS_TYPE_INTERNAL and ComMNmVariant==NONE */
#define ComM_bANY_NI_NONE          TRUE

#define ComM_bANY_INTERNAL_CHANNEL FALSE
/*! Counts before minimum FULL_COM duration is passed, calculated for all
    channels but only used in LIGHT and NONE ComMNmVariants */
/* Ceiling( (ComMGeneral --> ComMTMinFullComModeDuration)
           /(ComMChannel --> ComMMainFunctionPeriod))  */

#define ComM_u32MIN_FULL_COUNT_000  (uint32)250
#define ComM_u32MIN_FULL_COUNT_001  (uint32)250
#define ComM_u32MIN_FULL_COUNT_002  (uint32)250


#define ComM_u8NMVARIANT_PASSIVE 0
#define ComM_u8NMVARIANT_FULL    1
#define ComM_u8NMVARIANT_LIGHT   2
#define ComM_u8NMVARIANT_NONE    3


/*! ComMChannel --> ComMNetworkManagement --> ComMNmVariant */
#define ComM_u8NM_VARIANT_000  ComM_u8NMVARIANT_NONE
#define ComM_u8NM_VARIANT_001  ComM_u8NMVARIANT_NONE
#define ComM_u8NM_VARIANT_002  ComM_u8NMVARIANT_NONE
/*! ComMChannel --> ComMBusType */
#define ComM_bINTERNAL_BUS_000 FALSE
#define ComM_bINTERNAL_BUS_001 FALSE
#define ComM_bINTERNAL_BUS_002 FALSE

/*! Counts before LightTimeout duration is passed, calculated for all channels
    but only used in LIGHT ComMNmVariant */
/* Ceiling ( (ComMChannel --> ComMNetworkManagement --> ComMNmLightTimeout)
            /(ComMChannel --> ComMMainFunctionPeriod))*/


/*! ComMChannel --> ComMFullCommRequestNotificationEnabled */
#define ComM_bFULL_COM_REQ_SRI_000 (FALSE)
#define ComM_bFULL_COM_REQ_SRI_001 (FALSE)
#define ComM_bFULL_COM_REQ_SRI_002 (FALSE)
/*! ComMGeneral --> ComMEcuGroupClassification */
#define ComM_u8ECUG_CLASSIFICATION 0x00

#define ComM_bCAN_USED TRUE

#define ComM_bLIN_USED TRUE

#define ComM_bFR_USED  FALSE

#define ComM_bETH_USED FALSE

#define ComM_bALL_INTERNAL FALSE

#define ComM_bMULTI_BUS_MODE TRUE

#define ComM_pfu8GCCOM_MODE(u8Channel, pu8ComMode)\
    ComM_akpfu8eGCurComModeArray[(u8Channel)]((u8Channel), (pu8ComMode))

#define ComM_pfu8RCOM_MODE(u8Channel, u8ComMode)\
    ComM_akpfu8eRequestComModeArray[(u8Channel)]((u8Channel), (u8ComMode))


/* PRQA S 3453 -- */
#endif /* COMM_CFG_H */
/** \} */ /* end of ComM module group */

