
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
/* !File            : PduR_Cfg.h                                              */
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
/* $Revision::   1.49      $$Author::   sedrees       $$Date::   Aug 21 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_CFG_H
#define PDUR_CFG_H


/*! Auto-generated includes based on the configured upper/lower modules       */

  #include "CanTp.h"

  #include "Com_Cbk.h"

  #include "CanIf.h"

  #include "LinIf.h"


/******************************************************************************/
/* Configuration Version Information                                          */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Configuration's Major Version \n
*******************************************************************************/

#define PDUR_CFG_MAJOR_VERSION              0x02

/******************************************************************************/
/*! \Description    Configuration's Minor Version \n
*******************************************************************************/

#define PDUR_CFG_MINOR_VERSION              0x00

/******************************************************************************/
/* SUPPORTED CONFIGURED MODULES STATUS                                        */
/******************************************************************************/

#define PduR_bCOM_PRESENT                   STD_ON
#define PduR_bDCM_PRESENT                   STD_OFF
#define PduR_bIPDUM_PRESENT                   STD_OFF
#define PduR_bDBG_PRESENT                   STD_OFF

#define PduR_bCANIF_PRESENT                 STD_ON
#define PduR_bLINIF_PRESENT                 STD_ON
#define PduR_bFRIF_PRESENT                  STD_OFF
#define PduR_bCANNM_PRESENT                  STD_OFF
#define PduR_bFRNM_PRESENT                  STD_OFF

#define PduR_bCANTP_PRESENT                 STD_ON
#define PduR_bLINTP_PRESENT                 STD_OFF
#define PduR_bFRTP_PRESENT                  STD_OFF

#define PduR_bSOAD_PRESENT                  STD_OFF

#define PduR_bJ1939TP_PRESENT                  STD_OFF

#define PduR_bCANTP_RETRY                   STD_ON

/******************************************************************************/
/*! Description    Switch to Enable/Disable Routing to Lower If Modules \n
    \Range         STD_ON / STD_OFF \n
    \Trace_To      PduR-SRS-0247(0)
*******************************************************************************/
#define PduR_bIFLO_ENABLED                  STD_ON

/******************************************************************************/
/*! Description    Switch to Enable/Disable Routing to Lower TP Modules \n
    \Range         STD_ON / STD_OFF \n
    \Trace_To      PduR-SRS-0247(0)
*******************************************************************************/
#define PduR_bTPLO_ENABLED                  STD_ON

/******************************************************************************/
/*! Description    Switch to Enable/Disable Routing between LoIf and Upper Modules \n
    \Range         STD_ON / STD_OFF \n
    \Trace_To      PduR-SRS-0247(0)
*******************************************************************************/

#define PduR_bIFUP_ENABLED                  STD_ON

/******************************************************************************/
/*! Description    Switch to Enable/Disable Routing between LoTP and Upper Modules \n
    \Range         STD_ON / STD_OFF \n
    \Trace_To      PduR-SRS-0247(0)
*******************************************************************************/
#define PduR_bTPUP_ENABLED                  STD_ON

/******************************************************************************/
/*! \Description    Switch to Enable/Disable IF Gatewaying Operations \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bGATEWAYING_IF                 STD_OFF

/******************************************************************************/
/*! \Description    Switch to Enable/Disable TP Gatewaying Operations \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bGATEWAYING_TP                 STD_OFF

/******************************************************************************/
/*! \Description    Switch to Enable/Disable IF Multicasting Operations \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bMULTICASTING_IF               STD_OFF

/******************************************************************************/
/*! \Description    Switch to Enable/Disable TP Multicasting Operations \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bMULTICASTING_TP               STD_OFF

/******************************************************************************/
/*! Description    Switch to Enable/Disable CancelTransmit operation \n
    \Range         STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bCANCEL_TX_ENABLED             STD_ON

/******************************************************************************/
/*! Description    Switch to Enable/Disable CancelReceive operation \n
    \Range         STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bCANCEL_RX_ENABLED             STD_OFF

/******************************************************************************/
/*! Description    Switch to Enable/Disable ChangeParameter operation \n
    \Range         STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bCHANGE_PARAM_ENABLED          STD_OFF

/******************************************************************************/
/* CONSTANT CONFIGURATION PARAMETERS (not auto-generation based on modules)   */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Maximum number of IF buffers available in the PDUR module \n
    \Range          0..65535 \n
    \Trace_to       PduR-CDD-5235(0)
*******************************************************************************/

#define PduR_u16MAX_TX_BUFFER_NUMBER        0UL

/******************************************************************************/
/*! \Description    Maximum number of TP buffers available in the PDUR module \n
    \Range          0..65535 \n
*******************************************************************************/

#define PduR_u16MAX_TP_BUFFER_NUMBER        0UL

/******************************************************************************/
/*! \Description    Maximum number of routing groups configured by integrator \n
    \Range          0..65535 \n
*******************************************************************************/

#define PduR_u16MAX_ROUTE_GRP_NUMBER        4UL

/******************************************************************************/
/*! \Description    Maximum number of unique messages that shall be transmitted
                    or received by all modules in the system (upper or lower) \n
    \Range          1..65535 \n
*******************************************************************************/

#define PduR_u16MAX_GLBL_IPDUS_NMBR         30UL

/******************************************************************************/
/*! \Description    Switch to Enable/Disable Development Errors Detection \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/

#define PduR_bDEV_ERROR_DETECT              STD_OFF

/******************************************************************************/
/*! \Description    Switch to Enable/Disable PduR_GetVersionInfo API \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/

#define PduR_bVERSION_INFO_API              STD_OFF
/* !Deviation : Inhibit MISRA rule [0857]: Number of macro definitions exce-  */
/*              eds 1024 - program is non-conforming                          */
/* PRQA S 0857 ++                                                             */
/******************************************************************************/
/*! \Description    Switch to Enable/Disable Routing Path Group checking \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bROUTING_GROUPS_PRESENT        STD_ON

/******************************************************************************/
/*! \Description    Switch to Enable/Disable call-outs support in gatewaying \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bCALLOUT_SUPPORTED             STD_OFF

/******************************************************************************/
/*! \Description    Switch to Enable/Disable byte stuffing option for LinIf \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/
#define PduR_bSTUFFING_SUPPORTED            STD_OFF

/******************************************************************************/
/* CONFIGURATION PARAMETERS                                                   */
/******************************************************************************/

/******************************************************************************/
/*! \Description  Determines whether version check is to be made between 
 *                PduR and other interfaced modules or not.
*******************************************************************************/
#define PduR_bINTER_MOD_VER_CHECK          STD_OFF
  

/******************************************************************************/
/*! \Description    Octet used for byte stuffing in case gatewaying to LinIf \n
    \Default        0x00 {if not configured} \n
    \Range          0..255 \n
*******************************************************************************/
#define PduR_u8STUFFING_VALUE               0x00

/******************************************************************************/
/*! \Description    Switch to Enable/Disable Zero Cost Operation \n
    \Range          STD_ON / STD_OFF \n
*******************************************************************************/

#define PduR_bZERO_COST_OPERATION           STD_OFF



#endif /* PDUR_CFG_H */

/* PRQA S 0857 --                                                             */
/*------------------------------- end of file --------------------------------*/
