/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : TLF35584                                                */
/* !Description     : TLF35584 safe supply device management                  */
/*                                                                            */
/* !File            : TLF35584_Def.c                                          */
/* !Description     : Data definition of TLF35584 component.                  */
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
 * %PID: P2017_BSW:A53913.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "TLF35584.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define TLF35584_START_SEC_CONST_16BIT
#include "TLF35584_MemMap.h"

const uint16 TLF35584_kau16SpiFramesInit[TLF35584_u8NB_FRAME_SEQ_INIT] =
{
   TLF35584_u16UNLOCK_FRAME1,
   /* #1 Unlock protected Register  (P.13 Appnote
      TLF35584(A-step))  */
   TLF35584_u16UNLOCK_FRAME2,
   /* #2 Unlock protected Register */
   TLF35584_u16UNLOCK_FRAME3,
   /* #3 Unlock protected Register */
   TLF35584_u16UNLOCK_FRAME4,
   /* #4 Unlock protected Register */
   TLF35584_u16DISABLE_WATCHDOGS,
   /* Disable Window & Functional Watchdogs */
   TLF35584_u16DISABLE_ERR_MON,
   /* Disable ERR monitoring */
   TLF35584_u16LOCK_FRAME1,
   /* #1 Lock protected Register */
   TLF35584_u16LOCK_FRAME2,
   /* #2 Lock protected Register */
   TLF35584_u16LOCK_FRAME3,
   /* #3 Lock protected Register */
   TLF35584_u16LOCK_FRAME4,
   /* #4 Lock protected Register */
   TLF35584_u16GO_TO_NORMAL
   /* "Go to normal" frame */
};
#define TLF35584_STOP_SEC_CONST_16BIT
#include "TLF35584_MemMap.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define TLF35584_START_SEC_VAR_CLEARED_8BIT
#include "TLF35584_MemMap.h"

uint8 TLF35584_u8IndexFrame;

#define TLF35584_STOP_SEC_VAR_CLEARED_8BIT
#include "TLF35584_MemMap.h"


#define TLF35584_START_SEC_VAR_CLEARED_16BIT
#include "TLF35584_MemMap.h"

uint16 TLF35584_au16SpiFrameReceived[TLF35584_u8NB_FRAME_SEQ_INIT];

#define TLF35584_STOP_SEC_VAR_CLEARED_16BIT
#include "TLF35584_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
