/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_L                                                                                           */
/* !Description     : Local data of the Component                                                                     */
/*                                                                                                                    */
/* !File            : CCP_L.h                                                                                         */
/*                                                                                                                    */
/* !Scope           : PrivateComponent                                                                                */
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
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#ifndef CCP_L_H
#define CCP_L_H

#include "CCP_Typ.h"
#include "CCP_Srv.h"
#include "CCP_Cfg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coMSB_FIRST
   #error CCP_coMSB_FIRST not defined
#endif
#ifndef CCP_coCPU_BYTE_ORDER
   #error CCP_coCPU_BYTE_ORDER not defined
#endif
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE
   #error CCP_coOPT_SRV_MOVE not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coASYNC_RESP
   #error CCP_coASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coSRV_DNLD_ASYNC_RESP
   #error CCP_coSRV_DNLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coSRV_UPLD_ASYNC_RESP
   #error CCP_coSRV_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_TEST
   #error CCP_coOPT_SRV_TEST not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6
   #error CCP_coOPT_SRV_DNLD6 not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6_ASYNC_RESP
   #error CCP_coOPT_SRV_DNLD6_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD
   #error CCP_coOPT_SRV_SHO_UPLD not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP
   #error CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CAL_PAGE
   #error CCP_coOPT_SRV_CAL_PAGE not defined
#endif
#ifndef CCP_coOPT_SRV_CKS
   #error CCP_coOPT_SRV_CKS not defined
#endif
#ifndef CCP_coOPT_SRV_CKS_ASYNC_RESP
   #error CCP_coOPT_SRV_CKS_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE_ASYNC_RESP
   #error CCP_coOPT_SRV_MOVE_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_PROG
   #error CCP_coOPT_SRV_PROG not defined
#endif
#ifndef CCP_coOPT_SRV_PROG_ASYNC_RESP
   #error CCP_coOPT_SRV_PROG_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP
   #error CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP not defined
#endif

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !MComment: version of the CCP protocol                                                                             */
#define CCP_u8MAI_PTCL_CCP_VERS   2
#define CCP_u8RLEAS_PTCL_CCP_VERS 1

/* !Comment: number of services managed by CCP monitor                                                                */
#define CCP_udtNO_SRVS 36

/* !MComment: list of commands code                                                                                   */
#define CCP_udtCMD_CNCT                0x01
#define CCP_udtCMD_SET_MTA             0x02
#define CCP_udtCMD_DNLOAD              0x03
#define CCP_udtCMD_UPLOAD              0x04
#define CCP_udtCMD_TEST                0x05
#define CCP_udtCMD_START_STOP          0x06
#define CCP_udtCMD_DCNCT               0x07
#define CCP_udtCMD_STOP_START_ALL      0x08
#define CCP_udtCMD_GET_ACTIVE_CAL_PAGE 0x09
#define CCP_udtCMD_SET_S_STS           0x0C
#define CCP_udtCMD_GET_S_STS           0x0D
#define CCP_udtCMD_BUILD_CHKSUM        0x0E
#define CCP_udtCMD_SHORT_UPLOAD        0x0F
#define CCP_udtCMD_CLEAR_MEMORY        0x10
#define CCP_udtCMD_SELECT_CAL_PAGE     0x11
#define CCP_udtCMD_GET_SEED            0x12
#define CCP_udtCMD_UNLOCK              0x13
#define CCP_udtCMD_GET_DAQ_SIZE        0x14
#define CCP_udtCMD_SET_DAQ_PTR         0x15
#define CCP_udtCMD_WRITE_DAQ           0x16
#define CCP_udtCMD_EXCHANGE_ID         0x17
#define CCP_udtCMD_PROGRAM             0x18
#define CCP_udtCMD_MOVE                0x19
#define CCP_udtCMD_GET_CCP_VERS        0x1B
/* #define CCP_udtCMD_DIAG_SRV            0x20 - Not implemented */
/* #define CCP_udtCMD_ACTION_SRV          0x21 - Not implemented */
#define CCP_udtCMD_PROGRAM_6           0x22
#define CCP_udtCMD_DNLOAD_6            0x23

/* !MComment: list of command status code                                                                             */
#define CCP_udtCMD_STS_NO_ERR             ((CCP_tudtCmdSts)0x00)
#define CCP_udtCMD_STS_DAQ_PROCESSOR_OVLD ((CCP_tudtCmdSts)0x01)
#define CCP_udtCMD_STS_CMD_PROCESSOR_BUSY ((CCP_tudtCmdSts)0x10)
#define CCP_udtCMD_STS_DAQ_PROCESSOR_BUSY ((CCP_tudtCmdSts)0x11)
#define CCP_udtCMD_STS_INT_TIMEOUT        ((CCP_tudtCmdSts)0x12)
#define CCP_udtCMD_STS_KEY_REQ            ((CCP_tudtCmdSts)0x18)
#define CCP_udtCMD_STS_SSN_STS_REQ        ((CCP_tudtCmdSts)0x19)
#define CCP_udtCMD_STS_COLD_STRT_REQ      ((CCP_tudtCmdSts)0x20)
#define CCP_udtCMD_STS_CAL_DATA_ININ_REQ  ((CCP_tudtCmdSts)0x21)
#define CCP_udtCMD_STS_DAQ_LIST_ININ_REQ  ((CCP_tudtCmdSts)0x22)
#define CCP_udtCMD_STS_CODE_UPD_REQ       ((CCP_tudtCmdSts)0x23)
#define CCP_udtCMD_STS_WRG_SEQ            ((CCP_tudtCmdSts)0x29)
#define CCP_udtCMD_STS_UNKNOWN_CMD        ((CCP_tudtCmdSts)0x30)
#define CCP_udtCMD_STS_CMD_SYNTAX         ((CCP_tudtCmdSts)0x31)
#define CCP_udtCMD_STS_PRM_OUT_OF_RNG     ((CCP_tudtCmdSts)0x32)
#define CCP_udtCMD_STS_ACS_DENIED         ((CCP_tudtCmdSts)0x33)
#define CCP_udtCMD_STS_OVLD               ((CCP_tudtCmdSts)0x34)
#define CCP_udtCMD_STS_ACS_LOCKD          ((CCP_tudtCmdSts)0x35)
#define CCP_udtCMD_STS_FCN_NOT_AVL        ((CCP_tudtCmdSts)0x36)
#define CCP_udtCMD_STS_RESP_PND           ((CCP_tudtCmdSts)0xFE)
#define CCP_udtCMD_STS_NO_RESP            ((CCP_tudtCmdSts)0xFF)

/* !MComment: list of packed ids                                                                                      */
#define CCP_u8PID_EVT_MSG 0xFE
#define CCP_u8PID_ACK_MSG 0xFF

/* !MComment: calculate station address (little endian)                                                               */
#if (CCP_coCPU_BYTE_ORDER == CCP_coMSB_FIRST)
   #define CCP_u16STN_ADR (uint16)((CCP_u8STN_ADR_LSB << 8) + CCP_u8STN_ADR_MSB)
#else
   #define CCP_u16STN_ADR (uint16)((CCP_u8STN_ADR_MSB << 8) + CCP_u8STN_ADR_LSB)
#endif

/* !MComment: resources                                                                                               */
#define CCP_u8CAL_RES 0x01
#define CCP_u8DAQ_RES 0x02
#define CCP_u8PGM_RES 0x40

/* !MComment: resource availability                                                                                   */
#define CCP_u8CAL_AVL   CCP_u8CAL_RES
#define CCP_u8CAL_UNAVL 0x00
#define CCP_u8DAQ_AVL   CCP_u8DAQ_RES
#define CCP_u8DAQ_UNAVL 0x00
#define CCP_u8PGM_AVL   CCP_u8PGM_RES
#define CCP_u8PGM_UNAVL 0x00

/* !MComment: resource protection                                                                                     */
#define CCP_u8CAL_PROTD   CCP_u8CAL_RES
#define CCP_u8CAL_UNPROTD 0x00
#define CCP_u8DAQ_PROTD   CCP_u8DAQ_RES
#define CCP_u8DAQ_UNPROTD 0x00
#define CCP_u8PGM_PROTD   CCP_u8PGM_RES
#define CCP_u8PGM_UNPROTD 0x00

#define CCP_u8DNLD_MAX_DA_SIZE 5
#define CCP_u8DNLD6_DA_SIZE    6
#define CCP_u8UPLD_MAX_DA_SIZE 5
#define CCP_u8PROG_MAX_DA_SIZE 5
#define CCP_u8PROG6_DA_SIZE    6

#define CCP_u8CAL_INID     0x01
#define CCP_u8DAQ_INID     0x02
#define CCP_u8RESU_REQ     0x04
#define CCP_u8STORE_REQ    0x40
#define CCP_u8SSN_IN_PROGS 0x80

#define CCP_u8UNKNOWN_SSN_STS_MASK (uint8)(~( CCP_u8CAL_INID \
                                            | CCP_u8DAQ_INID \
                                            | CCP_u8SSN_IN_PROGS \
                                            | CCP_u8RESU_REQ \
                                            | CCP_u8STORE_REQ))

#define CCP_u8RES_UNLCKD 0
#define CCP_u8RES_LOCKD  1

#if (CCP_coOPT_SRV_MOVE == CCP_coACVD)
   #define CCP_u8NO_MTA 2
#else
   #define CCP_u8NO_MTA 1
#endif

/* !MComment: Disconnect modes                                                                                        */
#define CCP_u8DCNCT_MOD_TMP   0x00
#define CCP_u8DCNCT_MOD_PRMNT 0x01

/* !MComment: DAQ list start/stop modes                                                                               */
#define CCP_u8DAQ_MOD_STOP       0x00
#define CCP_u8DAQ_MOD_STRT       0x01
#define CCP_u8DAQ_MOD_SYNCD_STRT 0x02

/* !MComment: Format of DAQ list CAN identifier                                                                       */
#define CCP_udtDAQ_CAN_ID_IS_EXTD 0x80000000UL
#define CCP_udtDAQ_CAN_ID_MASK    0x7FFFFFFFUL
#define CCP_udtSTD_CAN_ID_MAX_ID  0x000007FFUL
#define CCP_udtEXTD_CAN_ID_MAX_ID 0x1FFFFFFFUL


/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"

extern CONST(CCP_tpfudtSrvFcn, CCP_CONST)       CCP_kapfudtSrvFcn[CCP_udtNO_SRVS];
extern CONST(CCP_tstrDaqListStatCfg, CCP_CONST) CCP_kastrDaqListStatCfg[CCP_u8DAQ_NO_LISTS];

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"


/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/
#define CCP_START_SEC_VAR_UNSPECIFIED
#include "CCP_MemMap.h"

extern VAR(CCP_tudtState, CCP_VAR) CCP_udtState;

extern VAR(CCP_tuniPtclMsgBuf, CCP_VAR) CCP_uniBuf;

extern VAR(CCP_tstrMta, CCP_VAR) CCP_astrMta[CCP_u8NO_MTA];

#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   extern VAR(uint8, CCP_VAR) CCP_u8SsnSts;
#endif

#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   extern VAR(uint8, CCP_VAR) CCP_u8ProtnSts;
   extern VAR(uint8, CCP_VAR) CCP_u8UnlckResReq;
#endif

#if (CCP_coASYNC_RESP == CCP_coACVD)
   extern VAR(boolean,         CCP_VAR) CCP_bAsyncRespPnd;
   extern VAR(CCP_tudtCmdCode, CCP_VAR) CCP_udtAsyncRespCmdCode;
#endif

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   extern VAR(CCP_tstrDaqListSeldElm, CCP_VAR) CCP_strDaqListSeldElm;

   extern VAR(uint8, CCP_VAR) CCP_u8DaqNoStrtdList;

   extern VAR(CCP_tstrDaqListDynCfg, CCP_VAR) CCP_astrDaqListDynCfg[CCP_u8DAQ_NO_LISTS];
#endif

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "CCP_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/* !MComment: private functions from CCP_MON                                                                          */
FUNC(void, CCP_CODE) CCP_vidSsnIni(void);
/* !MComment: private functions from CCP_SRV                                                                          */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtCnct(void);
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetCcpVers(void);
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtExchId(void);
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetMta(void);
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld(void);
#if (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnldAsyncResp(void);
#endif
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUpld(void);
#if (CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUpldAsyncResp(void);
#endif
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDcnct(void);
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtFcnNotAvl(void);
/* !MComment: private functions from CCP_OPT                                                                          */
#if (CCP_coOPT_SRV_TEST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtTest(void);
#endif
#if (CCP_coOPT_SRV_DNLD6 == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld6(void);
#endif
#if (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld6AsyncResp(void);
#endif
#if (CCP_coOPT_SRV_SHO_UPLD == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtShoUpld(void);
#endif
#if (CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtShoUpldAsyncResp(void);
#endif
#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetSsnSts(void);
#endif
#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetSsnSts(void);
#endif
#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetSeed(void);
#endif
#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUnlck(void);
#endif
#if (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSelCalPage(void);
#endif
#if (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetAcvCalPage(void);
#endif
#if (CCP_coOPT_SRV_CKS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtBldCks(void);
#endif
#if (CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtBldCksAsyncResp(void);
#endif
#if (CCP_coOPT_SRV_MOVE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtMove(void);
#endif
#if (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtMoveAsyncResp(void);
#endif
/* !MComment: private functions from CCP_PRG                                                                          */
#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg6(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtClrMem(void);
#endif
#if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProgAsyncResp(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg6AsyncResp(void);
#endif
#if (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtClrMemAsyncResp(void);
#endif
/* !MComment: private functions from CCP_DAQ                                                                          */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListIni(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetDaqSize(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetDaqPtr(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtWrDaqElmCfg(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtStrtStop(void);
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtStrtStopAll(void);
   FUNC(void, CCP_CODE)           CCP_vidDaqListStop(uint8_least u8ListIdx);
   FUNC(void, CCP_CODE)           CCP_vidDaqListStrt(uint8_least u8ListIdx, uint8_least u8Mod);
#endif

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

#endif /* CCP_L_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
