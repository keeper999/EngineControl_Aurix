/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : INL                                                     */
/*                                                                            */
/* !Component       : COMINL                                                  */
/* !Description     : Communication Layer                                     */
/*                                                                            */
/* !Module          : COMINL                                                  */
/* !Description     : API of the COMINL Component                             */
/*                                                                            */
/* !File            : COMINL_.C                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/*  1 / SendMessage                                                           */
/*  2 / ReceiveMessage                                                        */
/*  3 / GetMessageResource                                                    */
/*  4 / ReleaseMessageResource                                                */
/*  5 / GetMessageStatus                                                      */
/*  6 / StartCOM                                                              */
/*  7 / MessageInit                                                           */
/*  8 / SendMessageTo                                                         */
/*  9 / ReceiveMessageFrom                                                    */
/*  10 / StartPeriodical                                                      */
/*  11 / StopPeriodical                                                       */
/**************************** </AUTO_FILE_HEADER> *****************************/


#include "STD_TYPES.h"
// #include "MATHSRV.h"
#include "osek_com.h"
// #include "os_api.h"
// #include "osek_com_typ.h"

//#include "CANBSL.h"
// #include "COMDLL.h"
// #include "COMNWL.h"
// #include "COMNWL_c.h"
// #include "SWFAIL.h"

// #include "COMINL_l.h"
// #include "COMINL_c.h"
// #include "COMINL.h"
// #include "osek_com_typ.h"

/******************************************************************************/
/* Check that used define for conditionnal compilation exist                  */
/******************************************************************************/
// #ifndef NB_TRAMES_PERIODIQUES_TX
   // #error The define NB_TRAMES_PERIODIQUES_TX is undefined
// #endif
// #ifndef COMINL_coMDT_MANAGEMENT
   // #error The macro-constant COMINL_coMDT_MANAGEMENT shall be defined
// #endif
// #ifndef COMINL_coENABLED
   // #error The macro-constant COMINL_coENABLED shall be defined
// #endif

// #define COMINL_START_SEC_CODE
// #include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  1                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret OSEK_COM_tudtMsgBufferLength                                  */
/*  OSEK_COM_udtMsgBufferLengthRead(argin SymbolicName udtMessageId);         */
/*  extf argret void COMINL_vidSendMessageUudt(argin SymbolicName             */
/* udtMessageId, argio uint8 * pu8MsgPtr, argin uint16 u16MsgLength, argout   */
/* uint8* pu8Status);                                                         */
/*  extf argret void COMINL_vidSendMessageUsdt(argin SymbolicName             */
/* udtMessageId, argio uint8 *pu8MsgPtr, argin uint16 u16MsgLength, argout    */
/* uint8 *pu8Status);                                                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void COMINL_vidSendLocalMessage(argin SymbolicName            */
/* udtMessageId, argio uint8 *pu8MsgPtr, argin uint16 u16MsgLength, argout    */
/* uint8 *pu8Status);                                                         */
/*                                                                            */
/*  input ub Table_config_message[(8*25)];                                    */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType SendMessage
(
   SymbolicName udtMessageId,
   AccessName* pudtMessagePtr
)
{
    uint8  u8LocalStatusMsg;
   // uint16 u16LocalLength;
   // uint8  u8LocalConf;

   // if (udtMessageId < OSEK_COM_u8NB_MESSAGES)
   // {
      // u16LocalLength = OSEK_COM_udtMsgBufferLengthRead(udtMessageId);
      // u8LocalConf    = Table_config_message[udtMessageId].Conf;
      // if ((uint8)(u8LocalConf & (uint8)COMINL_bfSCOPE)
              // == (uint8)COMINL_bfEXTERNAL)
      // {
         // switch (u8LocalConf & (uint8)OSEK_COM_bfDT_CONF)
         // {
         // case OSEK_COM_bfUUDT:
            // COMINL_vidSendMessageUudt(udtMessageId,pudtMessagePtr,
                                      // u16LocalLength,&u8LocalStatusMsg);
            // break;
         // case OSEK_COM_bfUSDT:
            // COMINL_vidSendMessageUsdt(udtMessageId,pudtMessagePtr,
                                      // u16LocalLength,&u8LocalStatusMsg);
            // break;
         // default:
            // u8LocalStatusMsg = E_COM_ID;
            // SWFAIL_vidSoftwareErrorHook();
            // break;
         // }
      // }
      // else
      // {
         // COMINL_vidSendLocalMessage(udtMessageId,pudtMessagePtr,
                                    // u16LocalLength,&u8LocalStatusMsg);
      // }
   // }
   // else
   // {
      // u8LocalStatusMsg = E_COM_ID;
   //}

   return( (StatusType)u8LocalStatusMsg);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  2                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMINL_vidReceiveMessage(argin SymbolicName udtMessageId,*/
/*  argout uint8 *pu8MsgPtr, argout uint8 *pu8Status);                        */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType ReceiveMessage
(
   SymbolicName udtMessageId,
   AccessName* pudtMessagePtr
)
{
   uint8 u8LocalStatusMsg;

   // if (udtMessageId < OSEK_COM_u8NB_MESSAGES)
   // {
      // COMINL_vidReceiveMessage(udtMessageId,pudtMessagePtr,
                               // &u8LocalStatusMsg);
   // }
   // else
   // {
      // u8LocalStatusMsg = E_COM_ID;
   // }
   return( (StatusType)u8LocalStatusMsg);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  3                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType GetMessageResource
(
   SymbolicName udtMessageId
)
{

   return(E_COM_BUSY);

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  4                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType ReleaseMessageResource
(
   SymbolicName udtMessageId
)
{

   return(E_COM_ID);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  5                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  OSEK_COM_bIsMsgUsdtMode(argin SymbolicName           */
/*  udtMessageId);                                                            */
/*  extf argret void COMINL_vidGetUsdtMessageStatus(argin SymbolicName        */
/* udtMessageId, argout StatusType* pudtStatus);                              */
/*  extf argret void COMINL_vidGetUudtMessageStatus(argin SymbolicName        */
/* udtMessageId, argout StatusType* pudtStatus);                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType GetMessageStatus
(
   SymbolicName udtMessageId
)
{
   StatusType udtLocalStatusMsg;

   // if (udtMessageId < OSEK_COM_u8NB_MESSAGES)
   // {
      // if(OSEK_COM_bIsMsgUsdtMode(udtMessageId) != FALSE )
      // {
         // COMINL_vidGetUsdtMessageStatus(udtMessageId,&udtLocalStatusMsg);
      // }
      // else
      // {
         // COMINL_vidGetUudtMessageStatus(udtMessageId,&udtLocalStatusMsg);
      // }
   // }
   // else
   // {
      // udtLocalStatusMsg = E_COM_ID;
   // }
   return(udtLocalStatusMsg);

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  6                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMDLL_vidInit();                                        */
/*  extf argret StatusType  COMDLL_udtBusStateManagement(argin                */
/* OSEK_COM_tudtBusId u8BusId, argin COMDLL_tenuBusState snBusState);         */
/*  extf argret void COMDLL_vidOnline(argin OSEK_COM_tudtBusId udtBusId);     */
/*  extf argret StatusType  MessageInit();                                    */
/*  extf argret void COMNWL_vidInit();                                        */
/*  extf argret StatusType  StartPeriodical();                                */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType StartCOM(void)
{
   // StatusType     udtLocalBusAccessError;
   // uint8          u8LocalBusId;
   // uint8_least    u8LocalBusInitError;
   StatusType     udtLocalStatus;

   // u8LocalBusInitError = 0;

   // COMDLL_vidInit();
   // for (u8LocalBusId =0; u8LocalBusId < COMDLL_udtNB_NETWORK; u8LocalBusId++)
   // {
      // udtLocalBusAccessError =
         // COMDLL_udtBusStateManagement(u8LocalBusId, COMDLL_BUS_INIT);
      // if(udtLocalBusAccessError == E_OK)
      // {
         // COMDLL_vidOnline(u8LocalBusId);
      // }
      // else
      // {
         // u8LocalBusInitError = 1;
      // }
   // }

   // (void)MessageInit();
   // COMNWL_vidInit();
   // (void)StartPeriodical();

   // if(u8LocalBusInitError == 0)
   // {
      // udtLocalStatus = E_OK;
   // }
   // else
   // {
      // udtLocalStatus = E_COM_SYS_BUS_INIT_FAILED;
   // }
   return(udtLocalStatus);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  7                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMDLL_vidMessageInit(SymbolicName udtMessageId);        */
/*  extf argret void OSEK_COM_vidFrameStatusWrite(OSEK_COM_tudtFrameId        */
/* udtFrameId, OSEK_COM_tenuMsgStatus enuFrameStatus);                        */
/*  extf argret OSEK_COM_tudtFrameId  OSEK_COM_udtFrameIdRead(argin           */
/* SymbolicName udtMessageId);                                                */
/*                                                                            */
/*  input ub Table_config_message[(8*25)];                                    */
/*                                                                            */
/*  output boolean COMINL_bActivatedMDT[OSEK_COM_u8NB_MESSAGES];              */
/*  output boolean COMINL_bMsgWaitingTransmission[OSEK_COM_u8NB_MESSAGES];    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType MessageInit(void)
{
   // uint8_least    u8LocalInd;
   // uint8          u8LocalConf;

   // for (u8LocalInd =0 ; u8LocalInd<OSEK_COM_u8NB_MESSAGES; u8LocalInd++)
   // {
      // #if (COMINL_coMDT_MANAGEMENT == COMINL_coENABLED)
         // COMINL_bActivatedMDT[u8LocalInd] = FALSE;
         // COMINL_bMsgWaitingTransmission[u8LocalInd] = FALSE;
      // #endif /* (COMINL_coMDT_MANAGEMENT == COMINL_coENABLED) */
      // u8LocalConf = Table_config_message[u8LocalInd].Conf;
      // if(   (uint8)(u8LocalConf & (uint8)COMINL_bfSCOPE)
         // == (uint8)COMINL_bfEXTERNAL)
      // {
         // COMDLL_vidMessageInit((SymbolicName)u8LocalInd);
      // }
      // OSEK_COM_vidFrameStatusWrite(OSEK_COM_udtFrameIdRead(u8LocalInd),
                                   // OSEK_COM_NOMSG);
   // }
   return(E_OK);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  8                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret OSEK_COM_tudtMsgBufferLength                                  */
/*  OSEK_COM_udtMsgBufferLengthRead(argin SymbolicName udtMessageId);         */
/*  extf argret void COMINL_vidSendMessageKL(argin SymbolicName udtMessageId, */
/* argio uint8 *pu8MsgPtr, argin uint16 u16MsgLength, argout uint8            */
/* *pu8Status);                                                               */
/*  extf argret void COMINL_vidSendMessageUudt(argin SymbolicName             */
/* udtMessageId, argio uint8 * pu8MsgPtr, argin uint16 u16MsgLength, argout   */
/* uint8* pu8Status);                                                         */
/*  extf argret void COMINL_vidSendMessageUsdt(argin SymbolicName             */
/* udtMessageId, argio uint8 *pu8MsgPtr, argin uint16 u16MsgLength, argout    */
/* uint8 *pu8Status);                                                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void COMINL_vidSendLocalMessageTo(argin SymbolicName          */
/* udtMessageId, argio uint8 *pu8MsgPtr, argin uint16 u16MsgLength, argin     */
/* uint8 u8Recipient, argout uint8 *pu8Status);                               */
/*                                                                            */
/*  input ub Table_config_message[(8*25)];                                    */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType SendMessageTo
(
   SymbolicName udtMessageId,
   AccessName* pudtMessagePtr,
   Length udtLength,
   AddressType udtRecipient
 )
 {
    uint8 u8LocalStatusMsg;
   // uint8 u8LocalConf;

   // if (udtMessageId < OSEK_COM_u8NB_MESSAGES)
   // {
      // if (udtLength <= OSEK_COM_udtMsgBufferLengthRead(udtMessageId))
      // {
        // u8LocalConf = Table_config_message[udtMessageId].Conf;
        // if ((uint8)(u8LocalConf & (uint8)COMINL_bfSCOPE)
            // == (uint8)COMINL_bfEXTERNAL)
        // {
           // if (udtRecipient == LIGNE_KL_NWL)
           // {
              // COMINL_vidSendMessageKL(udtMessageId,pudtMessagePtr,
                                      // udtLength,&u8LocalStatusMsg);
           // }
           // else
           // {
              // switch (u8LocalConf & (uint8)OSEK_COM_bfDT_CONF)
              // {
              // case OSEK_COM_bfUUDT:
                 // COMINL_vidSendMessageUudt(udtMessageId,pudtMessagePtr,
                                           // udtLength,&u8LocalStatusMsg);
                 // break;
              // case OSEK_COM_bfUSDT:
                 // COMINL_vidSendMessageUsdt(udtMessageId,pudtMessagePtr,
                                           // udtLength,&u8LocalStatusMsg);
                 // break;
              // default:
                 // u8LocalStatusMsg = E_COM_ID;
                 // SWFAIL_vidSoftwareErrorHook();
                 // break;
              // }
           // }
        // }
        // else
        // {
           // COMINL_vidSendLocalMessageTo(udtMessageId,pudtMessagePtr,
                                        // udtLength,udtRecipient,
                                        // &u8LocalStatusMsg);
        // }
      // }
      // else
      // {
         // u8LocalStatusMsg = E_COM_SYS_LENGTH;
      // }
   // }
   // else
   // {
      // u8LocalStatusMsg = E_COM_ID;
   // }
   return( (StatusType)u8LocalStatusMsg);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  9                                                          */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COMINL_vidReceiveMessage(argin SymbolicName udtMessageId,*/
/*  argout uint8 *pu8MsgPtr, argout uint8 *pu8Status);                        */
/*                                                                            */
/*  input ub Table_config_message[(8*25)];                                    */
/*  input ub Access_message_info[4*4];                                        */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType ReceiveMessageFrom
(
   SymbolicName udtMessageId,
   AccessName* pudtMessagePtr,
   Length* pudtLength,
   AddressType* pudtSender
)
{
   uint8 u8LocalStatusMsg;
   // uint8 u8LocalMessInfoId;

   // if (udtMessageId < OSEK_COM_u8NB_MESSAGES)
   // {
      // COMINL_vidReceiveMessage(udtMessageId,pudtMessagePtr,
                               // &u8LocalStatusMsg);

      // if ( (u8LocalStatusMsg == E_OK) ||
           // (u8LocalStatusMsg == E_COM_SYS_LENGTH) )
      // {
         // u8LocalMessInfoId = Table_config_message[udtMessageId].Message_info_id;
         // *pudtSender = Access_message_info[u8LocalMessInfoId].Sender;
         // *pudtLength = Access_message_info[u8LocalMessInfoId].Message_size;
      // }
   // }
   // else
   // {
      // u8LocalStatusMsg = E_COM_ID;
   // }
   return( (StatusType)u8LocalStatusMsg);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  10                                                         */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SetRelAlarm(argin AlarmType AlarmID, argin TickType      */
/*  Increment, argin TickType Cycle);                                         */
/*                                                                            */
/*  input uint8 NB_TRAMES_PERIODIQUES_TX;                                     */
/*  input st Table_config_emission_periodique;                                */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType StartPeriodical(void)
{
/* Fonction implementee uniquement s il existe au moins un message periodique */
// #if (NB_TRAMES_PERIODIQUES_TX > 0)
   // uint8_least u8LocalInd;

   // for (u8LocalInd=0;u8LocalInd<NB_TRAMES_PERIODIQUES_TX;u8LocalInd++)
   // {
      // (void)SetRelAlarm(
               // Table_config_emission_periodique[u8LocalInd].Alarmeid,
               // Table_config_emission_periodique[u8LocalInd].Increment_alarme,
               // Table_config_emission_periodique[u8LocalInd].Periode);
   // }
// #endif /* NB_TRAMES_PERIODIQUE_TX == 0 */
   return(E_OK);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  11                                                         */
/* !Reference   :  V01 NT 08 05905 / 02                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CancelAlarm(argin AlarmType AlarmID);                    */
/*                                                                            */
/*  input uint8 NB_TRAMES_PERIODIQUES_TX;                                     */
/*  input st Table_config_emission_periodique;                                */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType StopPeriodical(void)
{
/* Fonction implementee uniquement s il existe au moins un message periodique */
// #if (NB_TRAMES_PERIODIQUES_TX > 0)
   // uint8_least u8LocalInd;

   // for (u8LocalInd=0;u8LocalInd<NB_TRAMES_PERIODIQUES_TX;u8LocalInd++)
   // {
      // (void)CancelAlarm(Table_config_emission_periodique[u8LocalInd].Alarmeid);
   // }
// #endif /* NB_TRAMES_PERIODIQUE_TX == 0 */
   return(E_OK);
}



// #define COMINL_STOP_SEC_CODE
// #include "MemMap.h"

/*------------------------------ end of file -------------------------------*/
