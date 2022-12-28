/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : COM                                                     */
/*                                                                            */
/* !Component       : OSEK_COM                                                */
/* !Description     : Osek internal APIs                                      */
/*                                                                            */
/* !Module          : OSEK_COM                                                */
/* !Description     : OSEK_COM Configuration                                  */
/*                                                                            */
/* !File            : Osek_com_i.h                                            */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2005-2009 VALEO                                                  */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/Osek_com_i.h_v              $*/
/* $Revision::   1.0                                                         $*/
/* $Author::   croche2                                $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#ifndef OSEK_COM_I_H
#define OSEK_COM_I_H


#include "STD_TYPES.h"
#include "osek_com_typ.h"
#include "osek_com_cfg.h"




/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  To recover the Frame Identifier Buffer used for            */
/*                 send/receive a Message on the Bus                          */
/* !Number      :  0x00                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_003.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtFrameIdRead( \
\
   udtMessageId \
\
) \
   (OSEK_COM_tudtFrameId)(udtMessageId) /*now messageID is same as FrameID*/



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns the last status code writted by OSEK_COM_enuFrame  */
/*                 StatusWrite on the frame                                   */
/* !Number      :  0x01                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_004.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_enuFrameStatusRead( \
\
   udtFrameId \
\
) \
   (Acces_message_objet[udtFrameId].enuFrameStatus)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Updates the status code of the specified frame             */
/* !Number      :  0x02                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_005.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_vidFrameStatusWrite( \
\
   udtFrameId, \
   enuNewFrameStatus \
\
) \
   do \
   { \
      Acces_message_objet[udtFrameId].enuFrameStatus = enuNewFrameStatus; \
   }while(0)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns the last frame length writted by                   */
/*                 OSEK_COM_vidFrameLengthWrite                               */
/* !Number      :  0x03                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_010.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtFrameLengthRead( \
\
   udtFrameId \
\
) \
   (Acces_message_objet[udtFrameId].udtFrameLength)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Set the number of valid data to transmit or receive        */
/* !Number      :  0x04                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_011.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_vidFrameLengthWrite( \
\
   udtFrameId, \
   udtNewFrameLength \
\
) \
   do \
   { \
      Acces_message_objet[udtFrameId].udtFrameLength = udtNewFrameLength; \
   }while(0)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns the pointer to the first element of the data       */
/*                 regarding the object selected by the Frame Identifier      */
/* !Number      :  0x05                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_013.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_pau8FrameDataPtrRead( \
\
   udtFrameId \
\
) \
   (Acces_message_objet[udtFrameId].Ptr)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns the identifier of the bus used with specfied       */
/*                 message                                                    */
/* !Number      :  0x06                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_014.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtBusIdRead( \
\
   udtMessageId \
\
) \
   (Table_config_message[udtMessageId].Bus_id)



/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns TRUE if the message is configured as  QUEUED and   */
/*                 FALSE if it is UNQUEUED                                    */
/* !Number      :  0x07                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_015.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_bIsMsgQueuedMode( \
\
   udtMessageId \
\
) \
   (((Table_config_message[udtMessageId].Conf_queue \
    & (uint8)OSEK_COM_bfQUEUED) == 0) ?  FALSE : TRUE  )


/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Returns the length of the buffer should be read.           */
/* !Number      :  0x08                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_020.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtMsgBufferLengthRead( \
\
   udtMessageId \
\
) \
   (Table_config_message[udtMessageId].Dlc)





/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Read the Network ID of the specfied Message ID             */
/* !Number      :  0x09                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_021.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtMsgNwlIdRead( \
\
   udtMessageId \
\
) \
   (Table_config_message[udtMessageId].Nwl_id)




/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Check the configuraion of this message is it USDT or not   */
/* !Number      :  0x0A                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_022.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_bIsMsgUsdtMode( \
\
   udtMessageId \
\
) \
   (((uint8)(Table_config_message[udtMessageId].Conf & \
            (uint8)OSEK_COM_bfDT_CONF)      \
     == (uint8)OSEK_COM_bfUSDT) ?  TRUE : FALSE)




/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  Check the transmitt dirction of this message               */
/* !Number      :  0x0B                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_023.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_bIsMsgTxDirection( \
\
   udtMessageId \
\
) \
   (((Table_config_message[udtMessageId].Conf \
    & (uint8)OSEK_COM_bfTRA) == 0) ?  FALSE : TRUE )


/*************************** <AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !Description :  To recover the Message Identifier Buffer that this Frame ID*/
/*                 belongs to it.                                             */
/* !Number      :  0x0C                                                       */
/* !Reference   :  V01 NT 09 01073 / 1                                        */
/*                                                                            */
/* !Trace_To :  VEES_R_09_01073_024.01                                        */
/************************** </AUTO_MACRO_HEADER> ******************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */

/*************************** <AUTO_MACRO_PROTOTYPE> ***************************/
#define OSEK_COM_udtMessageIdRead( \
\
   udtFrameId \
\
) \
   (SymbolicName)(udtFrameId)  /* For now the message ID is same as FrameID*/


#endif /* OSEK_COM_I_H */

/*-------------------------------- END OF FILE -------------------------------*/

