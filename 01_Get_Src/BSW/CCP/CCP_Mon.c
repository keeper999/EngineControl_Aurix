/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_MON                                                                                         */
/* !Description     : CCP monitor                                                                                     */
/*                                                                                                                    */
/* !File            : CCP_Mon.c                                                                                       */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT 2009 VALEO                                                                                               */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/* 1 / CCP_vidIni                                                                                                     */
/* 2 / CCP_vidSsnIni                                                                                                  */
/* 3 / CCP_vidMonr                                                                                                    */
/* 4 / CCP_vidAsyncRespMonr                                                                                           */
/* 5 / CCP_udtGetState                                                                                                */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#include "CCP.h"
#include "CCP_L.h"
#include "CCP_Cfg.h"
#include "CCP_Usr.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coOPT_SRV_TEST
   #error CCP_coOPT_SRV_TEST not defined
#endif
#ifndef CCP_coASYNC_RESP
   #error CCP_coASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CKS_ASYNC_RESP
   #error CCP_coOPT_SRV_CKS_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE_ASYNC_RESP
   #error CCP_coOPT_SRV_MOVE_ASYNC_RESP not defined
#endif
#ifndef CCP_coSRV_DNLD_ASYNC_RESP
   #error CCP_coSRV_DNLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6_ASYNC_RESP
   #error CCP_coOPT_SRV_DNLD6_ASYNC_RESP not defined
#endif
#ifndef CCP_coSRV_UPLD_ASYNC_RESP
   #error CCP_coSRV_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP
   #error CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_PROG_ASYNC_RESP
   #error CCP_coOPT_SRV_PROG_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP
   #error CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP not defined
#endif

/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidIni                                                                                          */
/*                                                                                                                    */
/* !Description : Initialize the CCP                                                                                  */
/* !Number      : 1                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidIni                                                                                             */
/* !Trigger  : reset                                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
FUNC(void, CCP_CODE) CCP_vidIni
(
   /* !Comment: CPP initialization parameters (NULL_PTR: use default settings)                                        */
   P2CONST(CCP_tstrIniPrms, AUTOMATIC, CCP_APPL_DATA) pkstrIniPrms
)
{
   if ((pkstrIniPrms) != 0) {} /* Remove Compiler warning of unused parameter */
   
   CCP_vidSsnIni();

   #if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
      CCP_vidDaqListIni();
   #endif

   CCP_vidUsrIni();
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidSsnIni                                                                                       */
/*                                                                                                                    */
/* !Description : Initialize the CCP protocol data                                                                    */
/* !Number      : 2                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
FUNC(void, CCP_CODE) CCP_vidSsnIni(void)
{
   CCP_udtState = CCP_udtSTT_DCNCTD;

   CCP_uniBuf.au32Data[0] = 0;
   CCP_uniBuf.au32Data[1] = 0;

   #if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
      CCP_u8SsnSts = 0;
   #endif

   #if (CCP_coASYNC_RESP == CCP_coACVD)
      CCP_bAsyncRespPnd       = FALSE;
      CCP_udtAsyncRespCmdCode = 0;
   #endif

   #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
      CCP_u8ProtnSts    = CCP_u8PROTN_CFG;
      CCP_u8UnlckResReq = 0;
   #endif
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidMonr                                                                                         */
/*                                                                                                                    */
/* !Description : Manage the CCP protocol                                                                             */
/* !Number      : 3                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable    : CCP_vidMonr                                                                                         */
/* !Trigger     : Command CAN message received                                                                        */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
FUNC(void, CCP_CODE) CCP_vidMonr(void)
{
   CCP_tudtCmdSts   udtLocalCmdSts;
   CCP_tudtCmdCode  udtLocalCmdCode;
   CCP_tpfudtSrvFcn pfudtLocalSrvFcn;


   CCP_vidUsrRxCmd(&CCP_uniBuf.au8Data[0]);

   udtLocalCmdSts  = CCP_udtCMD_STS_FCN_NOT_AVL;
   udtLocalCmdCode = (CCP_tudtCmdCode)CCP_uniBuf.strReq.u8CmdCod;

   #if (CCP_coOPT_SRV_TEST == CCP_coACVD)
      if (  ((CCP_udtState & CCP_udtSTT_CNCTD) != 0)
         || (udtLocalCmdCode == CCP_udtCMD_CNCT)
         || (udtLocalCmdCode == CCP_udtCMD_TEST))
   #else
      if (  ((CCP_udtState & CCP_udtSTT_CNCTD) != 0)
         || (udtLocalCmdCode == CCP_udtCMD_CNCT))
   #endif
   {
      #if (CCP_coASYNC_RESP == CCP_coACVD)
         if (CCP_bAsyncRespPnd == FALSE)
      #endif
      {
         if (udtLocalCmdCode < CCP_udtNO_SRVS)
         {
            pfudtLocalSrvFcn = CCP_kapfudtSrvFcn[udtLocalCmdCode];
            udtLocalCmdSts   = (*pfudtLocalSrvFcn)();
            #if (CCP_coASYNC_RESP == CCP_coACVD)
               if (udtLocalCmdSts == CCP_udtCMD_STS_RESP_PND)
               {
                  CCP_bAsyncRespPnd       = TRUE;
                  CCP_udtAsyncRespCmdCode = udtLocalCmdCode;

                  udtLocalCmdSts = CCP_udtCMD_STS_NO_RESP;
               }
            #endif
         }
      }
      if (udtLocalCmdSts != CCP_udtCMD_STS_NO_RESP)
      {
         CCP_uniBuf.strResp.u8CmdCtr    = CCP_uniBuf.strReq.u8CmdCtr;
         CCP_uniBuf.strResp.u8PktId     = CCP_u8PID_ACK_MSG;
         CCP_uniBuf.strResp.u8CmdRtnCod = (uint8)udtLocalCmdSts;

         CCP_vidUsrTxCmdResp(&CCP_uniBuf.au8Data[0]);
      }
   }
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidAsyncRespMonr                                                                                */
/*                                                                                                                    */
/* !Description : Manage the asynchronous responses                                                                   */
/*                The CCP module doesn't manage the timeout of responses. So the caller shall guarantee that this     */
/*                function will be called before the timeout specified by protocol occurs                             */
/* !Number      : 4                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidAsyncRespMonr                                                                                   */
/* !Trigger  : can be called at the end of an action or periodically (period                                          */
/*             shall be compatible with timeout duration)                                                             */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coASYNC_RESP == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidAsyncRespMonr(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      if (CCP_bAsyncRespPnd == TRUE)
      {
         udtLocalCmdSts = CCP_udtCMD_STS_RESP_PND;
         switch(CCP_udtAsyncRespCmdCode)
         {
            #if (CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_BUILD_CHKSUM:
                  udtLocalCmdSts = CCP_udtBldCksAsyncResp();
                  break;
            #endif

            #if (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_MOVE:
                  udtLocalCmdSts = CCP_udtMoveAsyncResp();
                  break;
            #endif

            #if (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_DNLOAD:
                  udtLocalCmdSts = CCP_udtDnldAsyncResp();
                  break;
            #endif

            #if (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_DNLOAD_6:
                  udtLocalCmdSts = CCP_udtDnld6AsyncResp();
                  break;
            #endif

            #if (CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_UPLOAD:
                  udtLocalCmdSts = CCP_udtUpldAsyncResp();
                  break;
            #endif

            #if (CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_SHORT_UPLOAD:
                  udtLocalCmdSts = CCP_udtShoUpldAsyncResp();
                  break;
            #endif

            #if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_PROGRAM:
                  udtLocalCmdSts = CCP_udtProgAsyncResp();
                  break;

               case CCP_udtCMD_PROGRAM_6:
                  udtLocalCmdSts = CCP_udtProg6AsyncResp();
                  break;
            #endif

            #if (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD)
               case CCP_udtCMD_CLEAR_MEMORY:
                  udtLocalCmdSts = CCP_udtClrMemAsyncResp();
                  break;
            #endif

            default:
               /* Do nothing */
               break;
         }
         if (udtLocalCmdSts != CCP_udtCMD_STS_RESP_PND)
         {
            CCP_uniBuf.strResp.u8CmdCtr    = CCP_uniBuf.strReq.u8CmdCtr;
            CCP_uniBuf.strResp.u8PktId     = CCP_u8PID_ACK_MSG;
            CCP_uniBuf.strResp.u8CmdRtnCod = (uint8)udtLocalCmdSts;

            CCP_vidUsrTxCmdResp(&CCP_uniBuf.au8Data[0]);

            CCP_bAsyncRespPnd = FALSE;
         }
      }
   }
#endif /* CCP_coASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetState                                                                                     */
/*                                                                                                                    */
/* !Description : Returns the state of the CCP protocol                                                               */
/* !Number      : 5                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : state of the CCP protocol                                                                               */
/* !Range   : CCP_udtSTT_CNCTD, CCP_udtSTT_DCNCTD, CCP_udtSTT_TMP_DCNCTD                                              */
FUNC(CCP_tudtState, CCP_CODE) CCP_udtGetState(void)
{
   return(CCP_udtState);
}

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
