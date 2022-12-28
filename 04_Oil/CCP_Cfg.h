/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CCP                                                     */
/*                                                                            */
/* !Module          : CCP_CFG                                                 */
/* !Description     : Configuration of the Component                          */
/*                                                                            */
/* !File            : CCP_CFG.h                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::                                                               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* Generated on 11/10/14, 10:16:14 by Genecode v2.6.0.0                       */
/******************************************************************************/

#ifndef CCP_CFG_H
#define CCP_CFG_H

#include "CCP_Typ.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !MComment: optional services activation                                    */
#define CCP_coOPT_SRV_DAQ_LIST CCP_coACVD
#define CCP_coOPT_SRV_SEED_KEY CCP_coDEACVD
#define CCP_coOPT_SRV_TEST     CCP_coACVD
#define CCP_coOPT_SRV_DNLD6    CCP_coACVD
#define CCP_coOPT_SRV_SHO_UPLD CCP_coACVD
#define CCP_coOPT_SRV_SSN_STS  CCP_coACVD
#define CCP_coOPT_SRV_CAL_PAGE CCP_coACVD
#define CCP_coOPT_SRV_CKS      CCP_coACVD
#define CCP_coOPT_SRV_MOVE     CCP_coDEACVD
#define CCP_coOPT_SRV_PROG     CCP_coDEACVD

/* !MComment: asynchronous response activation                                */
#define CCP_coOPT_SRV_CKS_ASYNC_RESP  CCP_coDEACVD
#define CCP_coOPT_SRV_MOVE_ASYNC_RESP CCP_coDEACVD
#define CCP_coSRV_DNLD_ASYNC_RESP CCP_coDEACVD
#define CCP_coOPT_SRV_DNLD6_ASYNC_RESP CCP_coDEACVD
#define CCP_coSRV_UPLD_ASYNC_RESP CCP_coDEACVD
#define CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP CCP_coDEACVD
#define CCP_coOPT_SRV_PROG_ASYNC_RESP CCP_coDEACVD
#define CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP CCP_coDEACVD
#define CCP_coASYNC_RESP CCP_coDEACVD

/* !MComment: features activation                                             */
#define CCP_coCAL_STORE_FEATURE CCP_coACVD
#define CCP_coDAQ_RESU_FEATURE  CCP_coDEACVD

/* !Comment: additional status information requested                          */
#define CCP_coADDL_STS CCP_coDEACVD

/* !MComment: station address                                                 */
#define CCP_u8STN_ADR_MSB 0x00
#define CCP_u8STN_ADR_LSB 0x039
#define CCP_coSLAVE_STN_ADR_USR CCP_coDEACVD

/* !MComment: device identifier                                               */
#define CCP_u8SLAVE_DEV_ID_TYPE 2
#define CCP_coSLAVE_DEV_ID_USR  CCP_coDEACVD
#define CCP_u8SLAVE_DEV_ID_LEN  ((uint8)sizeof(CCP_kaudtDevId))
#define CCP_u32SLAVE_DEV_ID_ADR ((uint32)(&CCP_kaudtDevId[0]))
#define CCP_u8SLAVE_DEV_ID_EXTN 0

/* !Comment: resources availability                                           */
#define CCP_u8RES_CFG \
   (CCP_u8CAL_AVL | CCP_u8DAQ_AVL | CCP_u8PGM_UNAVL)

/* !Comment: resources protection                                             */
#define CCP_u8PROTN_CFG \
   (CCP_u8CAL_UNPROTD | CCP_u8DAQ_UNPROTD | CCP_u8PGM_UNPROTD)

/* !Comment: check of DAQ list initialization status                          */
#define CCP_coDAQ_ININ_STS_CHK CCP_coDEACVD

/* !Comment: manage DAQ list dynamic CAN identifier                           */
#define CCP_coDAQ_DYN_CAN_ID CCP_coDEACVD

/* !Comment: manage DAQ list extended CAN identifier                          */
#define CCP_coDAQ_MNG_EXTD_CAN_ID CCP_coDEACVD

/* !Comment: select 1 DAQ list per Event/1 Event per DAQ list                 */
#define CCP_coDAQ_LIST_ID_EQ_EVT_ID CCP_coDEACVD

#define CCP_u8DAQ_NO_EVE_CHNS 4

/* !Comment: List of DAQ list                                                 */
#define CCP_u8DAQ_LST_DAQ_10MS 0
#define CCP_u8DAQ_LST_DAQ_100MS 1
#define CCP_u8DAQ_LST_DAQ_1000MS 2
#define CCP_u8DAQ_LST_DAQ_PMH 3

/* !Comment: List of DAQ list events                                          */
#define CCP_u8DAQ_EVT_EVENT_10MS 0
#define CCP_u8DAQ_EVT_EVENT_100MS 1
#define CCP_u8DAQ_EVT_EVENT_1000MS 2
#define CCP_u8DAQ_EVT_EVENT_PMH 3

#define CCP_u8DAQ_NO_LISTS 4

#define CCP_u16DAQ_NO_ELMS 224

/* !Comment: maximum size of ODT elements                                     */
#define CCP_coDAQ_ELM_SIZE_MAX CCP_coDAQ_ELM_SIZE_MAX_32_BITS

/* !Comment: data acquisition method (whole list or per ODT)                  */
#define CCP_coDAQ_FILL_WHOLE_LIST CCP_coACVD


/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"

/* !Comment: device identifier                                                */
extern CONST(uint8, CCP_CONST) CCP_kaudtDevId[sizeof("P2017_BSW")];

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"


#endif /* CCP_CFG_H */

/*-------------------------------- end of file -------------------------------*/