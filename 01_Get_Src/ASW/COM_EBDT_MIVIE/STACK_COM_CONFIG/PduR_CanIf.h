
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
/* !File            : PduR_CanIf.h                                              */
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
/* $Revision::   1.9      $$Author::   sedrees        $$Date::  13/04/2014   $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef PDUR_CANIF_H
#define PDUR_CANIF_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Std_Types.h"
#include "PduR_Types.h"

#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "ComStack_Cfg.h"

#include "PduR.h"

/******************************************************************************/
/* EXTERNED DATA                                                              */
/******************************************************************************/

/******************************************************************************/
/* SYMBOLIC DEFINES                                                           */
/******************************************************************************/

#define     PduR_u8CANIFRXINDICATION           0x01
#define     PduR_u8CANIFTXCONFIRMATION         0x02
#define     PduR_u8CANIFTRIGGERTRANSMIT        0x03

/******************************************************************************/
/* FUNCTIONS DECLARATIONS                                                     */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"


extern FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(
    VAR(PduIdType, AUTOMATIC)                       RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   PduInfoPtr);
    
extern FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       TxPduId);
    

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PDUR_CANIF_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
