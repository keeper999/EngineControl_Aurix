/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_Main                                              */
/*!Description     : The "Main" subcomponent header file.                    */
/*                                                                            */
/*!\File             LinIf_Main.h                                            */
/* \par              The "Main" subcomponent header file.                    */
/*!Scope           : Private component                                       */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.8      $$Author::   AELSOHBY       $$Date::   Mar 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_MAIN_H
#define LINIF_MAIN_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Cfg.h"

/* !Deviation : Inhibit MISRA rule [0857]: Number of Macro definitions exce-  */
/*              eds 1024 - Program is non-conforming                          */
/* PRQA S 0857 ++                                                             */

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description    The UNINIT LinIf State. \n
    \Range          0x00 \n                                                   */
/******************************************************************************/
#define LinIf_u8STATE_UNINIT            ((uint8)0)
/******************************************************************************/
/*! \Description    The INIT LinIf State. \n
    \Range          0x01 \n                                                   */
/******************************************************************************/
#define LinIf_u8STATE_INIT              ((uint8)1)

/******************************************************************************/
/*! \Description    The OPERATIONAL Channel State. \n
    \Range          0x01 \n                                                   */
/******************************************************************************/
#define LinIf_u8CHANNEL_OPERATIONAL     ((uint8)1)
/******************************************************************************/
/*! \Description    The SLEEP Channel State. \n
    \Range          0x02 \n                                                   */
/******************************************************************************/
#define LinIf_u8CHANNEL_SLEEP           ((uint8)2)


/******************************************************************************/
/*! \Description    The IDLE Channel Comm. State. \n
    \Range          0x00 \n                                                   */
/******************************************************************************/
#define LinIf_u8IF_STATE_IDLE           ((uint8)0)
/******************************************************************************/
/*! \Description    The SEND_FRAME Channel Comm. State. \n
    \Range          0x01 \n                                                   */
/******************************************************************************/
#define LinIf_u8IF_STATE_SEND_FRAME     ((uint8)1)
/******************************************************************************/
/*! \Description    The WAIT Channel Comm. State. \n
    \Range          0x02 \n                                                   */
/******************************************************************************/
#define LinIf_u8IF_STATE_WAIT           ((uint8)2)
/******************************************************************************/
/*! \Description    The CHK_BUSY Channel Comm. State. \n
    \Range          0x03 \n                                                   */
/******************************************************************************/
#define LinIf_u8IF_STATE_CHK_BUSY       ((uint8)3)



/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define LINIF_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern P2CONST(LinIf_ConfigType, LINIF_VAR, LINIF_CALIB_CONST)
                                                    LinIf_pkstreGlobalConfig;


#define LINIF_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"



#define LINIF_START_SEC_VAR_8
#include "Memmap.h"

extern VAR(uint8, LINIF_VAR) LinIf_u8eLinIfState;

#define LINIF_STOP_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/


#define LINIF_START_SEC_CODE
#include "Memmap.h"

/******************************************************************************/
/* Description : Sends a LIN frame on the specified channel with the specified
                 length                                                       */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_vidIFSendFrame
(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    VAR(uint8, AUTOMATIC) u8FrameLength
);

/******************************************************************************/
/* Description : The function that is called by the schedule table manager when
                 a new schedule entry is due                                  */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_vidIFNewSchEntryCallout(
    VAR(uint8, AUTOMATIC) u8ChannelIndex
);

/******************************************************************************/
/* Description : Returns the index of the  of the channel whose Id is the  
                    input                                                     */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_udtGetChannelIndexById(
    VAR(NetworkHandleType, AUTOMATIC) u8ChannelId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8ChannelIndex);



/******************************************************************************/
/* Description : Returns Id of the input channel index that can be 
                    communicated to the upper layers                          */
/******************************************************************************/
extern FUNC(NetworkHandleType, LINIF_CODE) LinIf_udtGetChannelIdByIndex(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

#define LINIF_STOP_SEC_CODE
#include "Memmap.h"
#endif /* LINIF_MAIN_H */

/*-------------------------------- end of file -------------------------------*/
/* PRQA S 0857 --                                                             */
