/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                      */
/*                                                                            */
/*!Component       : LinIf                                                    */
/*!Description     : The Lin Interface AutoSAR R4.0 component                 */
/*                                                                            */
/*!Module          : LinIf_Lcfg                                               */
/*!Description     : The Link-Time Configuration parameter of the LinIf       */
/*                                                                            */
/*!\File             LinIf_Lcfg.c                                             */
/* \par              The Link-Time Configuration parameter of the LinIf       */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : All                                                      */
/*                                                                            */
/*!Vendor          : VIAS                                                     */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-   */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.3      $$Author::   mnabil         $$Date::   Oct 20 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0838]: Multiple Inclusion prevention       */
/*              macros solve this issue                                       */
/* PRQA S 0838 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0850]: The value for the macros are        */
/*              redefined in the QAC for comptability with ANSI C             */
/* PRQA S 0850 L1                                                             */
/*!Deviation : Inhibit MISRA rule [2213, 3132]: Configuration file, no need   */
/*              to do this.                                                   */
/* PRQA S 2213, 3132 L1                                                       */
/*!Deviation : Inhibit MISRA rule [0862]: The MemMap.h is used to assign      */
/*              memory segments                                               */
/* PRQA S 0862 L1                                                             */

#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"
#include "LinIf_Lcfg.h"
#include "SchM_LinIf.h"
#include "LinIf_Cfg.h"
#include "Lin.h"

#if (LinIf_u8NUMBER_OF_TRCVS > 0U)
#include "LinTrcv.h"
#endif


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_START_CONFIG_DATA_8
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */

/*! \Description  The number of channels controlled by the Lin Interface      */
/*   \Range        0..255                                                     */
CONST(uint8, LINIF_CFG_CONST) LinIf_ku8eNumberOfChannels =
                                                    LinIf_u8NUMBER_OF_CHANNELS;

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */


#define LINIF_STOP_CONFIG_DATA_8
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */



/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_START_CONFIG_DATA_16
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */


/* \Description   The array containing the Dem_EventIds of the Slaves         */
/* Configuration: The array containing the Dem_EventIds of the LinIfSlaves
                  size = number of all the Dem_EventIds configured to all
                  LinIfSlaves. Errors are put under each other and referenced
                  later.*/
/*!Deviation : inhibit MISRA rule [3072]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */
/* PRQA S 3207 L2                                                             */


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_STOP_CONFIG_DATA_16
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_START_CONFIG_DATA_UNSPECIFIED
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */


/*! \Description   The array Representing all slaves controled by LinIf they
                    are ordered by the channel */
/* Configuration: The array contains all LinIfSlaves ordered by Index of the
                  channel in LinIf_akstreChannelsLT */
CONST(LinIf_tstrChannelSlaveParams, LINIF_CFG_CONST) 
                                    LinIf_akstreSlaves [1]=
{
    {
        /* LinIfResponseErrorBitPos */
        14,                            /* u8ResponseErrorBitPos        */

        /* LINIF_E_CHANNEL_X_SLAVE_Y */
        NULL_PTR,          /* pkudtE_ResponseErrorDetected */

        /* LINIF_E_NC_NO_RESPONSE_CHANNEL_X_SLAVE_Y */
        NULL_PTR           /* pkudtE_NC_No_Response        */
        
    }
    
};


/*! \Description  The Link time data of the channels                          */
/*   \Size         LinIf_ku8eNumberOfChannels                                 */
/* Configuration: The array contains all Link-Time conf. of LinIfChannel ordered
                  by akstrChannelsPB.u8ChannelIndx */


CONST(LinIf_tstrChannelStaticConf, LINIF_CFG_CONST) 
                            LinIf_akstreChannelsLT[LinIf_u8NUMBER_OF_CHANNELS]=
{
    {
        /* LinIfChannelId */
        2,              /* u8LinIfChannelId     */

        /* LinIfChannelRef */
        0,              /* u8LinChannelId       */
        /* Index of LinIfDrvFunctions in the array LinIf_akstreLinDrvConf */
        &LinIf_akstreLinDrvConf[0],              /* pkstrDrvRef        */

        /* If Multiplicity of LinIfTransceiverDrvConfig in this LinIfChannel
           is 0 this parameter has to be FALSE, else TRUE*/
        FALSE,           /* bTrcvPresent         */

        /* Index of LinIfTransceiverDrvConfig in the array
           LinIf_akstreLinTrcvDrvConf */
        0,              /* u8TrcvDrvConfIndex   */

        /* LinIfStartupState */
        LinIf_NORMAL,   /* enuStartupState      */

        /* LinIfComMNetworkHandleRef */
        2,              /* u8ComMChannelId      */

        /* Start index of LinIfSlaves attached to this LinIfChannel in */
        0,              /* u8SlavesIndex        */

        /* Number of LinIfSlaves attached to this LinIfChannel
           LinIf_akstreSlaves */
        1,               /* u8NumberOfSlaves     */

        /* WakeUp Source Type Ref */
        0           /* u32WakeupSourceType */
    }
};

CONST(LinIf_tstrChannelCriticalSec, LINIF_CFG_CONST)
                    LinIf_akstreChannelsCritSec[LinIf_u8NUMBER_OF_CHANNELS]=
{
    {
        /*SchM_Enter_LinIf_BuffSchTab_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_BuffSchTab_000_000,
        /*SchM_Exit_LinIf_BuffSchTab_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_BuffSchTab_000_000,

        /*SchM_Enter_LinIf_BuffSchTab_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_BuffSchTab_001_000,
        /*SchM_Exit_LinIf_BuffSchTab_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_BuffSchTab_001_000,

        /*SchM_Enter_LinIf_GotoSleep_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_GotoSleep_000_000,
        /*SchM_Exit_LinIf_GotoSleep_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_GotoSleep_000_000,

        /*SchM_Enter_LinIf_GotoSleep_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_GotoSleep_001_000,
        /*SchM_Exit_LinIf_GotoSleep_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_GotoSleep_001_000,

        /*SchM_Enter_LinIf_GotoSleep_002_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_GotoSleep_002_000,
        /*SchM_Exit_LinIf_GotoSleep_002_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_GotoSleep_002_000,

        /*SchM_Enter_LinIf_GotoSleep_003_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_GotoSleep_003_000,
        /*SchM_Exit_LinIf_GotoSleep_003_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_GotoSleep_003_000,

        /*SchM_Enter_LinIf_SendWakeup_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_SendWakeup_000_000,
        /*SchM_Exit_LinIf_SendWakeup_000_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_SendWakeup_000_000,

        /*SchM_Enter_LinIf_SendWakeup_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_SendWakeup_001_000,
        /*SchM_Exit_LinIf_SendWakeup_001_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_SendWakeup_001_000,

        /*SchM_Enter_LinIf_SendWakeup_002_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Enter_LinIf_SendWakeup_002_000,
        /*SchM_Exit_LinIf_SendWakeup_002_XXX, where XXX is the order of LinIfChannel in the configuration*/
        SchM_Exit_LinIf_SendWakeup_002_000

    }
    ,

};

/*! \Description   The array of function pointers for each Lin driver         */
/*   \Size          Number of Lin drivers                                     */
/* Configuration: The array contains all LinIfDrvFunctions */

CONST(LinIf_tstrLinDrvRef, LINIF_CFG_CONST) LinIf_akstreLinDrvConf[1] =
{
    {
        /* LinIfSendFrameFunc */
        Lin_17_AscLin_SendFrame,          /* pfudtSendFrame          */

        /* LinIfGotoSleepFunc */
        Lin_17_AscLin_GoToSleep,          /* pfudtGotoSleep          */

        /* LinIfGotoSleepInternalFunc */
        Lin_17_AscLin_GoToSleepInternal,  /* pfudtGotoSleepInternal  */

        /* LinIfWakeupFunc */
        NULL_PTR,             /* pfudtWakeup             */

        /* LinIfGetStatusFunc */
        Lin_17_AscLin_GetStatus,          /* pfenuGetStatus          */

        /* LinIfWakeupValidationFunc */
        NULL_PTR    /* pfvidWakeupValidation   */
    }
};


#if (LinIf_u8NUMBER_OF_TRCVS > 0U)
/*! \Description   The array of Trcv Driver configurations defined in LinIf  */
/*   \Size          Number of transceiver drivers                             */
/* Configuration: The array contains all LinIfTransceiverDrvConfig */

CONST(LinIf_tstrTransceiverDrvConfig, LINIF_CFG_CONST)
                                            LinIf_akstreLinTrcvDrvConf[0] =
{
};
#endif



/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_STOP_CONFIG_DATA_UNSPECIFIED
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_START_SEC_VAR_UNSPECIFIED
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */

/*  \Description    The global vars of the channels                           */
/*  \Size           LinIf_ku8NumberOfChannels                                 */
VAR(LinIf_tstrChannelVars, LINIF_VAR)
                        LinIf_astreChannelsVars [LinIf_u8NUMBER_OF_CHANNELS];

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */

#define LINIF_STOP_SEC_VAR_UNSPECIFIED
/* PRQA S 5087 L2                                                             */
#include "MemMap.h"
/* PRQA L:L2                                                                  */

/*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */
