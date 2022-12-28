/***************************************************************************
;**
;** FILE NAME      : COMINL.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef COMINL_H
#define COMINL_H

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

#define COM_BUSY                          1
#define COM_LOCKED                        2
#define COM_LOST_MSG                      6
#define COM_NEW_MSG                       4
#define COM_NOMSG                         3
#define COM_OK                            0
#define COM_OLD_MSG                       5
#define COM_WAIT                          8
#define COMINL_BMSGWAITINGTRANSMISSION_COLS    ( 43 )

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

void COMINL_vidUsdataInd(SymbolicName udtMessageId,uint8 u8Sender, uint8 * pu8Data, uint16 u16Length, uint8 u8UsdtResult);
void COMINL_vidUudataConf(SymbolicName udtMessageId);
void COMINL_vidUudataInd(SymbolicName udtMessageId,PduInfoType * pudtPduInfo);
void COMINL_vidUudataReq(SymbolicName udtMessageId, uint8 *pu8PtrMsg);


#endif /* COMINL_H */

/*-------------------------------- end of file -------------------------------*/
