
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !File            : PduR_Callout.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
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
/* $Revision::   1.4      $$Author::   sedrees        $$Date::   Aug 24 2014 $*/
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

/* !Deviation : Inhibit MISRA rule [0553]: File might be included but with no */
/*              external linkage due to disabling the gatewaying feature      */
/* PRQA S 0553 L1                                                             */

#include "Std_Types.h"
#include "PduR_Types.h"

#include "PduR_Callout.h"
#include "PduR_Cfg.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

#define PDUR_START_SEC_CALLOUT_CODE
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#if(PduR_bCALLOUT_SUPPORTED == STD_ON)

/* !Deviation : Inhibit MISRA rule [3206]: Parameters of functions are not    */
/*              used because this file is to be filled by the PduR user       */
/* PRQA S 3206 L1                                                             */



#endif /* PduR_bCALLOUT_SUPPORTED == STD_ON */

#define PDUR_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
