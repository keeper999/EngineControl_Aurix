/***************************************************************************
;**
;** FILE NAME      : COMINL_L.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef COMINL_L_H
#define COMINL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COMINL_i.h"
#include "COMINL_PduR.h"
#include "ComStack_Types.h"
#include "OSEK_COM.h"
#include "TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COMINL_ABMSGBUSY_COLS                  ( 43 )
#define COMINL_AU16MSGINDEX_COLS               ( 43 )
#define COMINL_BACTIVATEDMDT_COLS              ( 43 )
#define COMINL_UDTMDTALARMID_COLS              ( 43 )
#define COMINL_UDTMSGMINIMUMDELAYTIME_COLS     ( 43 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COMINL_vidGetUsdtMessageStatus(SymbolicName udtMessageId, StatusType* pudtStatus);
void COMINL_vidGetUudtMessageStatus(SymbolicName udtMessageId, StatusType* pudtStatus);
void COMINL_vidMessageNotification(SymbolicName udtMessageId);
void COMINL_vidReceiveMessage(SymbolicName udtMessageId, uint8 *pu8MsgPtr, uint8 *pu8Status);
void COMINL_vidSendMessageUudt(SymbolicName udtMessageId, uint8 * pu8MsgPtr, uint16 u16MsgLength, uint8* pu8Status);


#endif /* COMINL_L_H */

/*-------------------------------- end of file -------------------------------*/
