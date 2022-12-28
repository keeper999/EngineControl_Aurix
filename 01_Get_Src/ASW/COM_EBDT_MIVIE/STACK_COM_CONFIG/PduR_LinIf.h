
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
/* !File            : PduR_LinIf.h                                              */
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

#ifndef PDUR_LINIF_H
#define PDUR_LINIF_H

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

#define     PduR_u8LINIFRXINDICATION           0x51
#define     PduR_u8LINIFTXCONFIRMATION         0x52
#define     PduR_u8LINIFTRIGGERTRANSMIT        0x53

/******************************************************************************/
/* FUNCTIONS DECLARATIONS                                                     */
/******************************************************************************/

#define PDUR_START_SEC_CODE
#include "Memmap.h"


extern FUNC(void, PDUR_CODE) PduR_LinIfRxIndication(
    VAR(PduIdType, AUTOMATIC)                       RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   PduInfoPtr);
    
extern FUNC(void, PDUR_CODE) PduR_LinIfTxConfirmation(
    VAR(PduIdType, AUTOMATIC)                       TxPduId);
    
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LinIfTriggerTransmit(
    VAR(PduIdType, AUTOMATIC)                       TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   PduInfoPtr);
    

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PDUR_LINIF_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
