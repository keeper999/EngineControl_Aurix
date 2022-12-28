/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       : TST_CAN                                                 */
/* !Description     : Test of CAN component                                   */
/*                                                                            */
/* !File            : Dcm_stub.c                                              */
/* !Description     : stub of Dcm for boot loader purpose                     */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111916.A-SRC;6 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "Can.h"
#include "CanIf.h"
#include "Com.h"
#include "Com_Cbk.h"
#include "ComM.h"
#include "ComM_EcuMBswM.h"
#include "CanSM.h"
#include "Com.h"
#include "PduR.h"
#include "SUPSRV.h"

#define TST_START_SEC_TST_VAR
#include "TST_MemMap.h"

boolean DCMSTUB_bJumpToLoader;

#define TST_STOP_SEC_TST_VAR
#include "TST_MemMap.h"

#define TST_START_SEC_TST_CODE
#include "TST_MemMap.h"


/******************************************************************************/
/* !FuncName    : TST_CAN_vidInit                                             */
/* !Description : Initialises the TST_CAN data                                */
/*                                                                            */
/* !LastAuthor  : HMEL                                                        */
/******************************************************************************/
void TST_CAN_vidInit(void)
{
   DCMSTUB_bJumpToLoader          = FALSE;
}

/******************************************************************************/
/* !FuncName    : TST_COM_RxInd_DoC                           			      */
/* !Description : reception of Diag On can Frame                              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TST_COM_RxInd_DoC(PduIdType udtPduId, PduInfoType *pstrPduInfo)
{
   PduInfoType strLocPduInfo;
   uint8 au8MsgtoSend[8];

   COMPILER_UNUSED_PARAMETER(udtPduId);
   if (  (pstrPduInfo->SduDataPtr[0] == 0x02)
      && (pstrPduInfo->SduDataPtr[1] == 0x10)
      && (pstrPduInfo->SduDataPtr[2] == 0x01) )
   {  /* DiagnosticSessionControl DefaultSession request*/
      /* Replay Ack */
      
      au8MsgtoSend[0]= 0x06;
      au8MsgtoSend[1]= 0x50;
      au8MsgtoSend[2]= 0x01;         
      au8MsgtoSend[3]= 0x00;  
      au8MsgtoSend[4]= 0xFA;  
      au8MsgtoSend[5]= 0x01;  
      au8MsgtoSend[6]= 0xF4;
   
      strLocPduInfo.SduDataPtr = &au8MsgtoSend[0];
      strLocPduInfo.SduLength = 8;
      CanIf_Transmit(CanIf_CanTpTxNPdu_688, &strLocPduInfo);
   }

   if (  (pstrPduInfo->SduDataPtr[0] == 0x02)
      && (pstrPduInfo->SduDataPtr[1] == 0x10)
      && (pstrPduInfo->SduDataPtr[2] == 0x02) )
   {  /* DiagnosticSessionControl ProgrammingSession request*/
      /* Replay Nack 78 */
      
      au8MsgtoSend[0]= 0x03;
      au8MsgtoSend[1]= 0x7F;
      au8MsgtoSend[2]= 0x10;         
      au8MsgtoSend[3]= 0x78;  
      strLocPduInfo.SduDataPtr = &au8MsgtoSend[0];
      strLocPduInfo.SduLength = 8;
      CanIf_Transmit(CanIf_CanTpTxNPdu_688, &strLocPduInfo);
      
      /* Jump to loader after a well transmission of the frame */
      DCMSTUB_bJumpToLoader = TRUE;
   }
}

/******************************************************************************/
/* !FuncName    : TST_COM_TxConf_DoC                                          */
/* !Description : end of transmission of Diag On can Frame                    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void TST_COM_TxConf_DoC(PduIdType udtPduId)
{
   COMPILER_UNUSED_PARAMETER(udtPduId);
   if (DCMSTUB_bJumpToLoader == TRUE)
   {
      SUPSRV_vidEnterReprogMode(0);
   }
}

#define TST_STOP_SEC_TST_CODE
#include "TST_MemMap.h"

/*------------------------------- end of file --------------------------------*/
