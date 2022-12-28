
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
/* !File            : PduR_Com.h                                              */
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

#ifndef PDUR_COM_H
#define PDUR_COM_H

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

#define     PduR_u8COMTRANSMIT            0x89
#define     PduR_u8COMCANCELTRANSMIT      0x8A
#define     PduR_u8COMCANCELRXREQUST      0x8C
#define     PduR_u8COMCHNGEPRMREQUST      0x8B
            

#define PDUR_START_SEC_CODE
#include "Memmap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
    
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(
    VAR(PduIdType, AUTOMATIC)                               id,
    /* !Deviation : Inhibit MISRA rule: Prototype is indirectly inforced by   */
    /*              AUTOSAR to comply to PduR_<Up>Transmit prototype          */
    /* PRQA S 3673 ++                                                         */
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)           info);
    /* PRQA S 3673 --                                                         */
        
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ComCancelTransmit(
    VAR(PduIdType, AUTOMATIC)                               id);
        
extern FUNC(void, PDUR_CODE) PduR_vidComInit(void);


#define PDUR_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PDUR_COM_H */

/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                  */
