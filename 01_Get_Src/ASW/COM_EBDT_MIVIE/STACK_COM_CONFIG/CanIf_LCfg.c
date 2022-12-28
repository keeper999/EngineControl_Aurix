
/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                    */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_LCfg                                               */
/*!\file            : CanIf_LCfg.c                                            \n
    \Description    :It contain Link-Time Configuration for the CanIf         */
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
/* $Revision::   1.14     $$Author::   mamroussy      $$Date::   May 23 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* PRQA S 0838 EOF */
/*MISRA Msg justification:   MemMap mechanism is to be included after segment
                             definition*/
/* PRQA S 0862 EOF */
/*MISRA Msg justification:   Constants in header files are referenced
                             as  they are still subs*/
/* PRQA S 0850 EOF */
/*MISRA Msg justification:   Inhibit MISRA rule [0838]: AUTOMATIC keyword is    
                             defined as an empty macro                        */
#include "CanIf.h"
#include "CanIf_LocalLCfg.h"

#include "Can_17_MCanP_Cfg.h" 

#include "PduR_CanIf.h" 

#include "CanTp_Cbk.h" 

#include "CanSM_Cbk.h" 

#include "EcuM_Cbk.h" 

#include "CCPUSR_CanIf_Cfg.h" 

#include "EcuM_Cfg.h"   /*included by configuration for symbolic Names in  
                          CanIf_akstreCtrlLCfg */



#include "Dcm_stub.h" 
/*CanIfPublicCfg-->CanIfPublicCddHeaderFile*/
#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"
/******************************************************************************/
/*!  \Description Controllers.
*******************************************************************************/
/*size of CanIfCtrlCfg array*/
/* CanIf_ku8eNumOfControllers value is configured with the number of instances 
   created from the sub-container CanIfCtrlCfg*/

CONST(uint8, CANIF_CFG_CONST) CanIf_ku8eNumOfControllers=2;

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_8
#include "MemMap.h"


#define CANIF_START_CONFIG_DATA_16
#include "MemMap.h"
/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description Max number of HW Transmit Handles.
*******************************************************************************/
/*size of CanIfHthCfg array*/
CONST(uint16, CANIF_CFG_CONST) CanIf_ku16eNumOfHth=35;
/******************************************************************************/
/*!  \Description Max number of HW Receive Handles.
*******************************************************************************/
/*size of CanIfHrhCfg array*/

CONST(uint16, CANIF_CFG_CONST) CanIf_ku16eNumOfHrh=42;

/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_16
#include "MemMap.h"


#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"
/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description array contains the configuration (parameters) of an 
                  addressed CAN controller 
*******************************************************************************/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration             */
/*CanIfCtrlCfg*/
/*in case bWakeupSupport is configured to STD_OFF
  u8WkupEventIndex and u8WakupSourceIn and u8WakupSourceout will be 0         */

CONST(CanIf_tstrCtrlCfg, CANIF_CFG_CONST) CanIf_akstreCtrlLCfg[2]=
/* PRQA S 3132 -- */
{
/******************************************************************************/
/******************************* Controller CanIfCtrlDrvCfg/CanIf_Controller_Can_InterSystem *********************************/
/******************************************************************************/
    {
        /*u8CtrlIdRef                       */  1, 
        /*u8CanDrvId                        */  0,  
        /*u8HthStartIndex                   */  0,  
        /*u8NumOfHth                        */  30,  
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
        /*bWakeupSupport                    */  STD_OFF,
#if (CanIf_bWAKUP_CHK_VALID_API == STD_ON)
        /*u8WkupEventIndex                  */  0,
#endif
        /*u8WakupSourceIn                   */  0,    
        /*u8WakupSourceout                  */  0
#endif   
    },
  
/******************************************************************************/
/******************************* Controller CanIfCtrlDrvCfg/CanIf_Controller_Can_devaid *********************************/
/******************************************************************************/
    {
        /*u8CtrlIdRef                       */  2, 
        /*u8CanDrvId                        */  0,  
        /*u8HthStartIndex                   */  30,  
        /*u8NumOfHth                        */  5,  
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
        /*bWakeupSupport                    */  STD_OFF,
#if (CanIf_bWAKUP_CHK_VALID_API == STD_ON)
        /*u8WkupEventIndex                  */  0,
#endif
        /*u8WakupSourceIn                   */  0,    
        /*u8WakupSourceout                  */  0
#endif   
    },
  
};

/******************************************************************************/
/*!  \Description Contains the configuration (parameters) of an addressed CAN
                  Transceiver 
*******************************************************************************/
/*CanIfTrcvCfg*/
#if(CanIf_u8NUM_OF_TRCVS!=0)

CONST(CanIf_tstrCanIfTransLCfg, CANIF_CFG_CONST) 
                        CanIf_akstreTransLCfg
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
/*!  \Description Callback functions provided by upper layer modules of the 
                  CanIf. The callback functions defined in this Configuration
                  are common to all configured CAN Drivers / CAN Transceiver
                  Drivers modules. 
*******************************************************************************/
/*CanIfDispatchCfg                                                            */
CONST(CanIf_tstrDispatchLCfg, CANIF_CFG_CONST) CanIf_kstreDispatchLCfg=
{
    CanSM_ControllerBusOff,             /*pfvidControllerBusOff*/
#if(CanIf_bWAKUP_SUPPORT == STD_ON)
    EcuM_SetWakeupEvent,               /*pfvidSetWakeupEvent*/
#if (CanIf_bWAKUP_CHK_VALID_API == STD_ON)
    NULL_PTR,          /*pfvidValidWakeupEvent*/
#endif
#endif
    CanSM_ControllerModeIndication,       /*pfvidControllerModeIndic*/
#if(CanIf_u8NUM_OF_TRCVS!=0)
    CanSM_TransceiverModeIndication,            /*pfvidTrcvModeIndic*/
#endif
#if ((CanIf_bPUBLIC_PN_SUPPORT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
    NULL_PTR,          /*pfvidConfPnAvailability*/
NULL_PTR,          /*pfvidClearTrcvWuFlagIndic*/
NULL_PTR,          /*pfvidCheckTrcvWuFlagIndic*/
#endif
};
/******************************************************************************/
/*!  \Description array Contains Hths Configurations
*******************************************************************************/
/*CanIfHthCfg*/
/*Sorted according to CanIfCtrlCfg*/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

CONST(CanIf_tstrHthLCfg, CANIF_CFG_CONST) CanIf_akstreHthLCfg[35]=
/* PRQA S 3132 -- */
{
    
/******************************************************************************/
/******************************** HTH 0 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  63, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 1 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  65, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 2 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  56, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 3 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  57, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 4 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  64, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 5 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  59, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 6 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  60, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 7 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  61, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 8 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  62, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 9 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  67, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 10 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  70, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 11 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  69, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 12 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  66, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 13 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  72, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 14 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  68, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 15 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  51, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 16 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  73, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 17 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  74, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 18 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  75, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 19 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  49, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 20 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  46, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 21 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  47, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 22 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  52, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 23 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  48, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 24 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  1,   
        /*udtCanHthRef                      */  80, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 25 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  1,   
        /*udtCanHthRef                      */  77, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 26 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  1,   
        /*udtCanHthRef                      */  78, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 27 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  1,   
        /*udtCanHthRef                      */  79, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 28 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  53, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 29 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  1,   
        /*udtCanHthRef                      */  76, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 30 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  50, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 31 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  58, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 32 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  71, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 33 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  54, 
        /*enuHandleType                     */  CanIf_FULL
    },

/******************************************************************************/
/******************************** HTH 34 ************************************/
/******************************************************************************/
    {
        /*u8ControllerId                    */  0,   
        /*udtCanHthRef                      */  55, 
        /*enuHandleType                     */  CanIf_FULL
    },
      
};

/******************************************************************************/
/*!  \Description array Contains Hrhs Configurations
*******************************************************************************/
/*CanIfHrhCfg this array is sorted according to CanDrv*/
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number
                            used as it cant be Definition because it is
                            Link-Time or post-Build Configuration */

CONST(CanIf_tstrHrhLCfg, CANIF_CFG_CONST) CanIf_akstreHrhLCfg[42]=
/* PRQA S 3132 -- */
{
    
/******************************************************************************/
/******************************** HRH 0 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 1 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 2 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 3 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 4 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 5 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 6 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 7 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 8 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 9 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 10 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 11 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 12 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 13 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 14 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 15 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 16 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 17 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 18 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  1 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 19 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 20 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 21 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 22 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 23 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 24 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 25 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 26 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 27 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 28 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 29 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 30 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 31 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 32 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 33 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 34 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 35 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 36 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 37 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 38 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 39 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 40 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },

/******************************************************************************/
/******************************** HRH 41 ************************************/
/******************************************************************************/


    {
        /*u8ControllerId                    */  0 ,     
        /*enuHandleType                     */  CanIf_FULL    
#if(CanIf_bHRH_SW_FILTER==STD_ON)
        /*bHrhSwFilter                      */  ,STD_OFF
#endif
    },
        
};
#define CANIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_16
#include "MemMap.h"
/******************************************************************************/
/*!  \Description Structure to enable mapping from to the start index of 
                  all Hrhs that is assigned tothat CanDrv.}
*******************************************************************************/
/*start index in CanIf_tstrHrhLCfg array*/
/*CanIf_akstreCanDrvHrhMapLCfg*/

CONST(CanIf_tstrCanDrvHrhMap, CANIF_CFG_CONST) CanIf_akstreCanDrvHrhMapLCfg
        [CanIf_u8NUM_OF_CAN_DRVS]=
{

/******************************************************************************/
/******************************** Can Drv 0 **********************************/
/******************************************************************************/
    {
        
        /*u16HrhListStartindex              */  0
    },

};

/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_16
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description contains the pointer to functions that enables CanIf confirms 
                  the transmission of an I-PDU.                                 
*******************************************************************************/
/*size is derived fro number of upper layers configured                         
(each new CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL ) +1                 */
/*CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationName                            */
/*if CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL added new cell in this      
  array where this index is filled in                                           
  CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL and                            
  CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationName will be asked for user     */
  /*if OLd(used before)CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL added 
  no new cell in this array will be filled and index of this array              
  will be filled in CanIfTxPduCfg-->CanIfTxPduUserTxConfirmationUL            */
/* PRQA S 3132 ++ */                                                            
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
/*first elemet is alwayes NULL_PTR                                            */

CONST(CanIf_tpfudtTxConfirmation, CANIF_CFG_CONST)
        CanIf_akpfvideUlTxConfrimLTCfg[14]=
/* PRQA S 3132 -- */
{
    /*Not used for TxPdus with no Ul Configured */  NULL_PTR

    ,
    CCP_UsrTxConf_DAQ_1000MS
    ,
    CCP_UsrTxConf_DAQ_100MS
    ,
    CCP_UsrTxConf_DAQ_10MS
    ,
    CCP_UsrTxConf_Devaid_DAQ_1000MS
    ,
    CCP_UsrTxConf_Devaid_DAQ_100MS
    ,
    CCP_UsrTxConf_Devaid_DAQ_10MS
    ,
    CCP_UsrTxConf_Devaid_DTO
    ,
    CCP_UsrTxConf_Devaid_DAQ_PMH
    ,
    CCP_UsrTxConf_DTO
    ,
    CCP_UsrTxConf_DAQ_PMH
    ,
    TST_COM_TxConf_DoC
    ,
    CanTp_TxConfirmation
        
    ,
    PduR_CanIfTxConfirmation
        
};
/******************************************************************************/
/*!  \Description contains the pointer to functions that enables CanIf          
      indicate reception of an I-PDU and the Upper Layer Component.             
*******************************************************************************/
/*size is derived fro number of upper layers configured(each new                
  CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL ) +1                           */
/*CanIfRxPduCfg-->CanIfRxPduUserRxIndicationName                              */
/*if CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL added new cell in this array  
  where this index is filled in CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL    
  and CanIfRxPduCfg-->CanIfRxPduUserRxIndicationName will be asked for user   */
  /*if OLd(used before)CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL added       
  no new cell in this array will be filled and index of this array will be      
  filled in CanIfRxPduCfg-->CanIfRxPduUserRxIndicationUL                      */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
/*first elemet is alwayes NULL_PTR                                            */

CONST(CanIf_tstrRxULCfg, CANIF_CFG_CONST)
                        CanIf_akstreUlRxLTCfg
                                    [6]=
/* PRQA S 3132 -- */
{
/*      pfudtRxIndication
                                u8UpperComponent
                                                    */
    {
        NULL_PTR
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                                ,u8NO_UL_CONFIGURED
#endif
    }      /*Not used for TxPdus with no Ul*/

    ,
    {
        CCP_UsrRxInd_CRO
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                                ,u8CDD
#endif
    }
    ,
    {
        CCP_UsrRxInd_Devaid_CRO
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                                ,u8CDD
#endif
    }
    ,
    {
        TST_COM_RxInd_DoC
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                                ,u8CDD
#endif
    }
    ,
    {
        CanTp_RxIndication
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                                ,u8CAN_TP
#endif
    }
      
  ,
  {
      PduR_CanIfRxIndication
#if(CanIf_bWAKEUP_VALID_BY_NM==STD_ON)
                              ,u8PDUR
#endif
  }
      
};
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_CONFIG_DATA_8
#include "MemMap.h"

/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description contains parameters related to each CanDrv
*******************************************************************************/

CONST(CanIf_tstrCtrlDrvLCfg, CANIF_CFG_CONST)
                        CanIf_akstreCtrlDrvLCfg
                                    [CanIf_u8NUM_OF_CAN_DRVS]=
{
/******************************************************************************/
/******************************** Can Drv 0 **********************************/
/******************************************************************************/
    {
        /*bRxIndication                     */  STD_ON,
        /*bTxConfirmation                   */  STD_ON
    }, /*CanDrv0*/

};
#define CANIF_STOP_CONFIG_DATA_8
#include "MemMap.h"

#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description array that contains Status of the PDU channel group.          
                  Current mode of the channel defines its transmit or receive   
                  activity. Communication direction (transmission and           
                  /or reception) of the channel can be controlled separately    
                  or together by upper layers.                                  
*******************************************************************************/
/*size is CanIf_ku8eNumOfControllers                                          */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
VAR(CanIf_tstrPduMode, CANIF_VAR) CanIf_astreCurrPduChannelMode [2];
/* PRQA S 3132 -- */
/******************************************************************************/
/*!  \Description array contain Operating modes of the CAN Controllers          
*******************************************************************************/
/*size is CanIf_ku8eNumOfControllers                                          */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
VAR(CanIf_ControllerModeType, CANIF_VAR ) 
                CanIf_aenueCurrControllerMode [2];
/* PRQA S 3132 -- */

/******************************************************************************/
/*!  \Description array contain TX confirmation has been done for the           
                  whole CAN controller since the last CAN controller start.     
*******************************************************************************/
/*size is CanIf_ku8eNumOfControllers                                          */
/* PRQA S 3132 ++                                                             */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
VAR(CanIf_NotifStatusType, CANIF_VAR ) CanIf_aenueTxConfirmState [2];
#endif
/* PRQA S 3132 -- */
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_8
#include "MemMap.h"

/* PRQA L:L1 */ 
/******************************************************************************/
/*!  \Description array that carry wakeup events and wakeup events              
                  validation for each controller                                
*******************************************************************************/
/*one element will be created in this array for each                            
  CanIfCtrlCfg-->CanIfCtrlWakeupSupport=true and corressponding index will      
  be in u8WkupEventIndex                                                      */
/* PRQA S 3132 ++ */
/*MISRA Msg justification:  this message is disables as it Magic number         
                            used as it cant be Definition because it is         
                            Link-Time or post-Build Configuration             */
#if ((CanIf_bWAKUP_CHK_VALID_API == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
VAR(CanIf_tstrCtrlWakeup, CANIF_VAR ) CanIf_astreCtrlWakeup [0];
#endif
/* PRQA S 3132 -- */
/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_VAR_8
#include "MemMap.h"

/* PRQA L:L1 */ 
          
