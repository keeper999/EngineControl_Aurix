
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_Cfg                                               */
/*!\file            : CanIf_Cfg.c                                             \n
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
/* $Revision::   1.6      $$Author::   mamroussy      $$Date::   Jun 18 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/* PRQA S 0838 EOF */
/*MISRA Msg justification:   MemMap mechanism is to be included after segment
                             definition                                       */
/* PRQA S 0862 EOF */
/*MISRA Msg justification:   Constants in header files are referenced
                             as  they are still subs                          */
/* PRQA S 0850 EOF */
/*MISRA Msg justification:   Inhibit MISRA rule [0838]: AUTOMATIC keyword is    
                             defined as an empty macro                        */

#include "EcuM_Cfg.h"   /*included by configuration for symbolic Names in  
                          CanIf_akstreCtrlLCfg */
#include "CanIf.h"

#include "Can_17_MCanP.h" 

#include "Cantrcv_Dummy.h" 


#include "SchM_CanIf.h"

#include "CanIf_LocalCfg.h"

#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array contains the PC configuration (parameters) of an       
                 addressed CAN Transceiver
*******************************************************************************/
/*CanIfTrcvCfg*/

/*in case bWakeupSupport in  CanIf_akstreCtrlLCfg is configured to STD_OFF
  u8WakupSourceIn and u8WakupSourceOut will be 0*/
#if(CanIf_u8NUM_OF_TRCVS!=0)
CONST(CanIf_tstrTrcvPCCfg, CANIF_CFG_CONST)
                       CanIf_akstreCanTrcvPCCfg
                                    [CanIf_u8NUM_OF_TRCVS]=
{
};
#endif
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_8
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description array contains The lower layer CanDrv pointers to its 
                  services.
*******************************************************************************/
/*derived from configuration parameters for each CanIfCtrlDrvCfg sub-container*/
CONST(CanIf_tstrCanDrvServicesPCCfg, CANIF_CFG_CONST)
                        CanIf_akstreCanServicesPCCfg
                                    [CanIf_u8NUM_OF_CAN_DRVS]=
{
    {
        Can_17_MCanP_SetControllerMode,
            Can_17_MCanP_Write,
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
                
#endif
    },
};

/******************************************************************************/
/*!  \Description array contains The lower layer Can transceiver Driver pointer
                  to its services.
*******************************************************************************/
/*derived from configuration parameters for each CanIfTrcvDrvCfg sub-container*/
#if(CanIf_u8NUM_OF_TRCV_DRVS!=0)
CONST(CanIf_tstrTrcvDrvServicesPCCfg, CANIF_CFG_CONST)
                        CanIf_akstreCanTrcvSrvcsPCCfg
                                    [CanIf_u8NUM_OF_TRCV_DRVS]=
{
};
#endif

/******************************************************************************/
/*!  \Description array contains The cirtical setction implemented to 
                  protect Tx buffer
*******************************************************************************/
/*CanIfTxPduCfg->CanIfTxPduBswSchExclAreaIdRef*/


#if(CanIf_coSAME_CRITIC_SEC_TX == STD_OFF)

#endif
#if(CanIf_coSAME_CRITIC_SEC_RX == STD_OFF)
/******************************************************************************/
/*!  \Description array contains The cirtical setction implemented to 
                  protect Rx buffer
*******************************************************************************/
/*CanIfRxPduCfg->CanIfRxPduBswSchExclAreaIdRef*/
/* PRQA S 3132 ++ */

/* PRQA S 3132 -- */
#endif
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
          
