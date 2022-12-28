
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : Autosar Com module                                      */
/*                                                                            */
/* !Module          : Com_Cbk                                                 */
/* !Description     : Com_Cbk                                                 */
/*                                                                            */
/* !File            : Com_Cbk.c                                               */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/PATCH/Com_Cbk.c_v           $*/
/* $Revision::   1.0      $$Author::   ynicaise       $$Date::   14 Oct 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#include "Com_Cbk.h"
#include "Com_LCfg.h"


#define COM_START_SEC_CODE
#include "MemMap.h"  

/******************************************************************************/
/* IPdu Notification
    Generation method:
      static generation 
- Function definition for Ipdu notification of ComIPdu                       */
/******************************************************************************/

/*
FUNC(void, COM_CODE) Com_vidIPduNotification_21(void)
{
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();
FHCAN_EveTxF208_AckClbk();


}

  */

/******************************************************************************/
/* IPdu TimeOut Notification
    Generation method:
      static generation 
- Function definition for Ipdu TimeOut notifications of ComIPdu               */
/******************************************************************************/
/*
FUNC(void, COM_CODE) Com_vidIPduTimeOutNotification_21(void)
{
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();
FHCAN_EveTxF208_TOutClbk();

}
*/

/******************************************************************************/
/* IPdu Error Notification
    Generation method:
      static generation 
- Function definition for Ipdu Error notifications of ComIPdu               */
/******************************************************************************/


#define COM_STOP_SEC_CODE
#include "MemMap.h"


