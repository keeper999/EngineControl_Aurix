/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TLF35584                                                */
/* !Description     : TLF35584 safe supply device management                  */
/*                                                                            */
/* !File            : TLF35584.h                                              */
/* !Description     : Header file for TLF35584 component                      */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  :  C                                                      */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A53914.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TLF35584_H
#define TLF35584_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define TLF35584_u8NB_FRAME_SEQ_INIT  11
#define TLF35584_u16UNLOCK_FRAME1     0x8756
#define TLF35584_u16UNLOCK_FRAME2     0x87DE
#define TLF35584_u16UNLOCK_FRAME3     0x86AD
#define TLF35584_u16UNLOCK_FRAME4     0x8625
#define TLF35584_u16DISABLE_WATCHDOGS 0x8D27
#define TLF35584_u16DISABLE_ERR_MON   0x8811
#define TLF35584_u16LOCK_FRAME1       0x87BE
#define TLF35584_u16LOCK_FRAME2       0x8668
#define TLF35584_u16LOCK_FRAME3       0x877D
#define TLF35584_u16LOCK_FRAME4       0x8795
#define TLF35584_u16GO_TO_NORMAL      0x9DD5


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

#define TLF35584_START_SEC_CONST_16BIT
#include "TLF35584_MemMap.h"

extern const uint16 TLF35584_kau16SpiFramesInit[TLF35584_u8NB_FRAME_SEQ_INIT];

#define TLF35584_STOP_SEC_CONST_16BIT
#include "TLF35584_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define TLF35584_START_SEC_VAR_CLEARED_8BIT
#include "TLF35584_MemMap.h"

extern uint8 TLF35584_u8IndexFrame;

#define TLF35584_STOP_SEC_VAR_CLEARED_8BIT
#include "TLF35584_MemMap.h"


#define TLF35584_START_SEC_VAR_CLEARED_16BIT
#include "TLF35584_MemMap.h"

extern uint16 TLF35584_au16SpiFrameReceived[TLF35584_u8NB_FRAME_SEQ_INIT];

#define TLF35584_STOP_SEC_VAR_CLEARED_16BIT
#include "TLF35584_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define TLF35584_START_SEC_CODE
#include "TLF35584_MemMap.h"

extern void TLF35584_vidInit(void);
extern void TLF35584_vidSpiEndNotification(void);

#define TLF35584_STOP_SEC_CODE
#include "TLF35584_MemMap.h"

#endif /* TLF35584_H */

/*-------------------------------- end of file -------------------------------*/
