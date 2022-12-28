
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm_PBcfg.c                                             */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_PBcfg.c_v$*/
/* $Revision::   1.20     $$Author::   pbakabad         $$Date::   Jun 27 2013$*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/


/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#include "Dcm.h"
/* PRQA L:L1 */
#include "PduR_Dcm.h"
#include "Dcm_Cfg.h"
#include "Dcm_PBcfg.h"


#define DCM_START_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"


/* !Deviation : inhibit MISRA rule [3132]: The automated configuration tool  */ 
/*              writes the array size directly in files. no manual editing in*/
/*              files required.                                              */
/* PRQA S 3132 L1 */
CONST(Dcm_PbDspDidType,DCM_CFG_CONST) akstrPbDspDid[282] =
/* PRQA L:L1 */
{
  /* DID1 Used */
  {
    TRUE
  },
  /* DID2 Used */
  {
    TRUE
  },
  /* DID3 Used */
  {
    TRUE
  },
  /* DID4 Used */
  {
    TRUE
  },
  /* DID5 Used */
  {
    TRUE
  },
  /* DID6 Used */
  {
    TRUE
  },
  /* DID7 Used */
  {
    TRUE
  },
  /* DID8 Used */
  {
    TRUE
  },
  /* DID9 Used */
  {
    TRUE
  },
  /* DID10 Used */
  {
    TRUE
  },
  /* DID11 Used */
  {
    TRUE
  },
  /* DID12 Used */
  {
    TRUE
  },
  /* DID13 Used */
  {
    TRUE
  },
  /* DID14 Used */
  {
    TRUE
  },
  /* DID15 Used */
  {
    TRUE
  },
  /* DID16 Used */
  {
    TRUE
  },
  /* DID17 Used */
  {
    TRUE
  },
  /* DID18 Used */
  {
    TRUE
  },
  /* DID19 Used */
  {
    TRUE
  },
  /* DID20 Used */
  {
    TRUE
  },
  /* DID21 Used */
  {
    TRUE
  },
  /* DID22 Used */
  {
    TRUE
  },
  /* DID23 Used */
  {
    TRUE
  },
  /* DID24 Used */
  {
    TRUE
  },
  /* DID25 Used */
  {
    TRUE
  },
  /* DID26 Used */
  {
    TRUE
  },
  /* DID27 Used */
  {
    TRUE
  },
  /* DID28 Used */
  {
    TRUE
  },
  /* DID29 Used */
  {
    TRUE
  },
  /* DID30 Used */
  {
    TRUE
  },
  /* DID31 Used */
  {
    TRUE
  },
  /* DID32 Used */
  {
    TRUE
  },
  /* DID33 Used */
  {
    TRUE
  },
  /* DID34 Used */
  {
    TRUE
  },
  /* DID35 Used */
  {
    TRUE
  },
  /* DID36 Used */
  {
    TRUE
  },
  /* DID37 Used */
  {
    TRUE
  },
  /* DID38 Used */
  {
    TRUE
  },
  /* DID39 Used */
  {
    TRUE
  },
  /* DID40 Used */
  {
    TRUE
  },
  /* DID41 Used */
  {
    TRUE
  },
  /* DID42 Used */
  {
    TRUE
  },
  /* DID43 Used */
  {
    TRUE
  },
  /* DID44 Used */
  {
    TRUE
  },
  /* DID45 Used */
  {
    TRUE
  },
  /* DID46 Used */
  {
    TRUE
  },
  /* DID47 Used */
  {
    TRUE
  },
  /* DID48 Used */
  {
    TRUE
  },
  /* DID49 Used */
  {
    TRUE
  },
  /* DID50 Used */
  {
    TRUE
  },
  /* DID51 Used */
  {
    TRUE
  },
  /* DID52 Used */
  {
    TRUE
  },
  /* DID53 Used */
  {
    TRUE
  },
  /* DID54 Used */
  {
    TRUE
  },
  /* DID55 Used */
  {
    TRUE
  },
  /* DID56 Used */
  {
    TRUE
  },
  /* DID57 Used */
  {
    TRUE
  },
  /* DID58 Used */
  {
    TRUE
  },
  /* DID59 Used */
  {
    TRUE
  },
  /* DID60 Used */
  {
    TRUE
  },
  /* DID61 Used */
  {
    TRUE
  },
  /* DID62 Used */
  {
    TRUE
  },
  /* DID63 Used */
  {
    TRUE
  },
  /* DID64 Used */
  {
    TRUE
  },
  /* DID65 Used */
  {
    TRUE
  },
  /* DID66 Used */
  {
    TRUE
  },
  /* DID67 Used */
  {
    TRUE
  },
  /* DID68 Used */
  {
    TRUE
  },
  /* DID69 Used */
  {
    TRUE
  },
  /* DID70 Used */
  {
    TRUE
  },
  /* DID71 Used */
  {
    TRUE
  },
  /* DID72 Used */
  {
    TRUE
  },
  /* DID73 Used */
  {
    TRUE
  },
  /* DID74 Used */
  {
    TRUE
  },
  /* DID75 Used */
  {
    TRUE
  },
  /* DID76 Used */
  {
    TRUE
  },
  /* DID77 Used */
  {
    TRUE
  },
  /* DID78 Used */
  {
    TRUE
  },
  /* DID79 Used */
  {
    TRUE
  },
  /* DID80 Used */
  {
    TRUE
  },
  /* DID81 Used */
  {
    TRUE
  },
  /* DID82 Used */
  {
    TRUE
  },
  /* DID83 Used */
  {
    TRUE
  },
  /* DID84 Used */
  {
    TRUE
  },
  /* DID85 Used */
  {
    TRUE
  },
  /* DID86 Used */
  {
    TRUE
  },
  /* DID87 Used */
  {
    TRUE
  },
  /* DID88 Used */
  {
    TRUE
  },
  /* DID89 Used */
  {
    TRUE
  },
  /* DID90 Used */
  {
    TRUE
  },
  /* DID91 Used */
  {
    TRUE
  },
  /* DID92 Used */
  {
    TRUE
  },
  /* DID93 Used */
  {
    TRUE
  },
  /* DID94 Used */
  {
    TRUE
  },
  /* DID95 Used */
  {
    TRUE
  },
  /* DID96 Used */
  {
    TRUE
  },
  /* DID97 Used */
  {
    TRUE
  },
  /* DID98 Used */
  {
    TRUE
  },
  /* DID99 Used */
  {
    TRUE
  },
  /* DID100 Used */
  {
    TRUE
  },
  /* DID101 Used */
  {
    TRUE
  },
  /* DID102 Used */
  {
    TRUE
  },
  /* DID103 Used */
  {
    TRUE
  },
  /* DID104 Used */
  {
    TRUE
  },
  /* DID105 Used */
  {
    TRUE
  },
  /* DID106 Used */
  {
    TRUE
  },
  /* DID107 Used */
  {
    TRUE
  },
  /* DID108 Used */
  {
    TRUE
  },
  /* DID109 Used */
  {
    TRUE
  },
  /* DID110 Used */
  {
    TRUE
  },
  /* DID111 Used */
  {
    TRUE
  },
  /* DID112 Used */
  {
    TRUE
  },
  /* DID113 Used */
  {
    TRUE
  },
  /* DID114 Used */
  {
    TRUE
  },
  /* DID115 Used */
  {
    TRUE
  },
  /* DID116 Used */
  {
    TRUE
  },
  /* DID117 Used */
  {
    TRUE
  },
  /* DID118 Used */
  {
    TRUE
  },
  /* DID119 Used */
  {
    TRUE
  },
  /* DID120 Used */
  {
    TRUE
  },
  /* DID121 Used */
  {
    TRUE
  },
  /* DID122 Used */
  {
    TRUE
  },
  /* DID123 Used */
  {
    TRUE
  },
  /* DID124 Used */
  {
    TRUE
  },
  /* DID125 Used */
  {
    TRUE
  },
  /* DID126 Used */
  {
    TRUE
  },
  /* DID127 Used */
  {
    TRUE
  },
  /* DID128 Used */
  {
    TRUE
  },
  /* DID129 Used */
  {
    TRUE
  },
  /* DID130 Used */
  {
    TRUE
  },
  /* DID131 Used */
  {
    TRUE
  },
  /* DID132 Used */
  {
    TRUE
  },
  /* DID133 Used */
  {
    TRUE
  },
  /* DID134 Used */
  {
    TRUE
  },
  /* DID135 Used */
  {
    TRUE
  },
  /* DID136 Used */
  {
    TRUE
  },
  /* DID137 Used */
  {
    TRUE
  },
  /* DID138 Used */
  {
    TRUE
  },
  /* DID139 Used */
  {
    TRUE
  },
  /* DID140 Used */
  {
    TRUE
  },
  /* DID141 Used */
  {
    TRUE
  },
  /* DID142 Used */
  {
    TRUE
  },
  /* DID143 Used */
  {
    TRUE
  },
  /* DID144 Used */
  {
    TRUE
  },
  /* DID145 Used */
  {
    TRUE
  },
  /* DID146 Used */
  {
    TRUE
  },
  /* DID147 Used */
  {
    TRUE
  },
  /* DID148 Used */
  {
    TRUE
  },
  /* DID149 Used */
  {
    TRUE
  },
  /* DID150 Used */
  {
    TRUE
  },
  /* DID151 Used */
  {
    TRUE
  },
  /* DID152 Used */
  {
    TRUE
  },
  /* DID153 Used */
  {
    TRUE
  },
  /* DID154 Used */
  {
    TRUE
  },
  /* DID155 Used */
  {
    TRUE
  },
  /* DID156 Used */
  {
    TRUE
  },
  /* DID157 Used */
  {
    TRUE
  },
  /* DID158 Used */
  {
    TRUE
  },
  /* DID159 Used */
  {
    TRUE
  },
  /* DID160 Used */
  {
    TRUE
  },
  /* DID161 Used */
  {
    TRUE
  },
  /* DID162 Used */
  {
    TRUE
  },
  /* DID163 Used */
  {
    TRUE
  },
  /* DID164 Used */
  {
    TRUE
  },
  /* DID165 Used */
  {
    TRUE
  },
  /* DID166 Used */
  {
    TRUE
  },
  /* DID167 Used */
  {
    TRUE
  },
  /* DID168 Used */
  {
    TRUE
  },
  /* DID169 Used */
  {
    TRUE
  },
  /* DID170 Used */
  {
    TRUE
  },
  /* DID171 Used */
  {
    TRUE
  },
  /* DID172 Used */
  {
    TRUE
  },
  /* DID173 Used */
  {
    TRUE
  },
  /* DID174 Used */
  {
    TRUE
  },
  /* DID175 Used */
  {
    TRUE
  },
  /* DID176 Used */
  {
    TRUE
  },
  /* DID177 Used */
  {
    TRUE
  },
  /* DID178 Used */
  {
    TRUE
  },
  /* DID179 Used */
  {
    TRUE
  },
  /* DID180 Used */
  {
    TRUE
  },
  /* DID181 Used */
  {
    TRUE
  },
  /* DID182 Used */
  {
    TRUE
  },
  /* DID183 Used */
  {
    TRUE
  },
  /* DID184 Used */
  {
    TRUE
  },
  /* DID185 Used */
  {
    TRUE
  },
  /* DID186 Used */
  {
    TRUE
  },
  /* DID187 Used */
  {
    TRUE
  },
  /* DID188 Used */
  {
    TRUE
  },
  /* DID189 Used */
  {
    TRUE
  },
  /* DID190 Used */
  {
    TRUE
  },
  /* DID191 Used */
  {
    TRUE
  },
  /* DID192 Used */
  {
    TRUE
  },
  /* DID193 Used */
  {
    TRUE
  },
  /* DID194 Used */
  {
    TRUE
  },
  /* DID195 Used */
  {
    TRUE
  },
  /* DID196 Used */
  {
    TRUE
  },
  /* DID197 Used */
  {
    TRUE
  },
  /* DID198 Used */
  {
    TRUE
  },
  /* DID199 Used */
  {
    TRUE
  },
  /* DID200 Used */
  {
    TRUE
  },
  /* DID201 Used */
  {
    TRUE
  },
  /* DID202 Used */
  {
    TRUE
  },
  /* DID203 Used */
  {
    TRUE
  },
  /* DID204 Used */
  {
    TRUE
  },
  /* DID205 Used */
  {
    TRUE
  },
  /* DID206 Used */
  {
    TRUE
  },
  /* DID207 Used */
  {
    TRUE
  },
  /* DID208 Used */
  {
    TRUE
  },
  /* DID209 Used */
  {
    TRUE
  },
  /* DID210 Used */
  {
    TRUE
  },
  /* DID211 Used */
  {
    TRUE
  },
  /* DID212 Used */
  {
    TRUE
  },
  /* DID213 Used */
  {
    TRUE
  },
  /* DID214 Used */
  {
    TRUE
  },
  /* DID215 Used */
  {
    TRUE
  },
  /* DID216 Used */
  {
    TRUE
  },
  /* DID217 Used */
  {
    TRUE
  },
  /* DID218 Used */
  {
    TRUE
  },
  /* DID219 Used */
  {
    TRUE
  },
  /* DID220 Used */
  {
    TRUE
  },
  /* DID221 Used */
  {
    TRUE
  },
  /* DID222 Used */
  {
    TRUE
  },
  /* DID223 Used */
  {
    TRUE
  },
  /* DID224 Used */
  {
    TRUE
  },
  /* DID225 Used */
  {
    TRUE
  },
  /* DID226 Used */
  {
    TRUE
  },
  /* DID227 Used */
  {
    TRUE
  },
  /* DID228 Used */
  {
    TRUE
  },
  /* DID229 Used */
  {
    TRUE
  },
  /* DID230 Used */
  {
    TRUE
  },
  /* DID231 Used */
  {
    TRUE
  },
  /* DID232 Used */
  {
    TRUE
  },
  /* DID233 Used */
  {
    TRUE
  },
  /* DID234 Used */
  {
    TRUE
  },
  /* DID235 Used */
  {
    TRUE
  },
  /* DID236 Used */
  {
    TRUE
  },
  /* DID237 Used */
  {
    TRUE
  },
  /* DID238 Used */
  {
    TRUE
  },
  /* DID239 Used */
  {
    TRUE
  },
  /* DID240 Used */
  {
    TRUE
  },
  /* DID241 Used */
  {
    TRUE
  },
  /* DID242 Used */
  {
    TRUE
  },
  /* DID243 Used */
  {
    TRUE
  },
  /* DID244 Used */
  {
    TRUE
  },
  /* DID245 Used */
  {
    TRUE
  },
  /* DID246 Used */
  {
    TRUE
  },
  /* DID247 Used */
  {
    TRUE
  },
  /* DID248 Used */
  {
    TRUE
  },
  /* DID249 Used */
  {
    TRUE
  },
  /* DID250 Used */
  {
    TRUE
  },
  /* DID251 Used */
  {
    TRUE
  },
  /* DID252 Used */
  {
    TRUE
  },
  /* DID253 Used */
  {
    TRUE
  },
  /* DID254 Used */
  {
    TRUE
  },
  /* DID255 Used */
  {
    TRUE
  },
  /* DID256 Used */
  {
    TRUE
  },
  /* DID257 Used */
  {
    TRUE
  },
  /* DID258 Used */
  {
    TRUE
  },
  /* DID259 Used */
  {
    TRUE
  },
  /* DID260 Used */
  {
    TRUE
  },
  /* DID261 Used */
  {
    TRUE
  },
  /* DID262 Used */
  {
    TRUE
  },
  /* DID263 Used */
  {
    TRUE
  },
  /* DID264 Used */
  {
    TRUE
  },
  /* DID265 Used */
  {
    TRUE
  },
  /* DID266 Used */
  {
    TRUE
  },
  /* DID267 Used */
  {
    TRUE
  },
  /* DID268 Used */
  {
    TRUE
  },
  /* DID269 Used */
  {
    TRUE
  },
  /* DID270 Used */
  {
    TRUE
  },
  /* DID271 Used */
  {
    TRUE
  },
  /* DID272 Used */
  {
    TRUE
  },
  /* DID273 Used */
  {
    TRUE
  },
  /* DID274 Used */
  {
    TRUE
  },
  /* DID275 Used */
  {
    TRUE
  },
  /* DID276 Used */
  {
    TRUE
  },
  /* DID277 Used */
  {
    TRUE
  },
  /* DID278 Used */
  {
    TRUE
  },
  /* DID279 Used */
  {
    TRUE
  },
  /* DID280 Used */
  {
    TRUE
  },
  /* DID281 Used */
  {
    TRUE
  },
  /* DID282 Used */
  {
    TRUE
  }
};

/* !Deviation : inhibit MISRA rule [3132]: The automated configuration tool  */ 
/*              writes the array size directly in files. no manual editing in*/
/*              files required.                                              */
/* PRQA S 3132 L1 */
CONST(Dcm_PbDspPidType,DCM_CFG_CONST) akstrPbDspPid[36] =
/* PRQA L:L1 */
{
  /* PID1 Used */
  {
    TRUE
  },
  /* PID2 Used */
  {
    TRUE
  },
  /* PID3 Used */
  {
    TRUE
  },
  /* PID4 Used */
  {
    TRUE
  },
  /* PID5 Used */
  {
    TRUE
  },
  /* PID6 Used */
  {
    TRUE
  },
  /* PID7 Used */
  {
    TRUE
  },
  /* PID8 Used */
  {
    TRUE
  },
  /* PID9 Used */
  {
    TRUE
  },
  /* PID10 Used */
  {
    TRUE
  },
  /* PID11 Used */
  {
    TRUE
  },
  /* PID12 Used */
  {
    TRUE
  },
  /* PID13 Used */
  {
    TRUE
  },
  /* PID14 Used */
  {
    TRUE
  },
  /* PID15 Used */
  {
    TRUE
  },
  /* PID16 Used */
  {
    TRUE
  },
  /* PID17 Used */
  {
    TRUE
  },
  /* PID18 Used */
  {
    TRUE
  },
  /* PID19 Used */
  {
    TRUE
  },
  /* PID20 Used */
  {
    TRUE
  },
  /* PID21 Used */
  {
    TRUE
  },
  /* PID22 Used */
  {
    TRUE
  },
  /* PID23 Used */
  {
    TRUE
  },
  /* PID24 Used */
  {
    TRUE
  },
  /* PID25 Used */
  {
    TRUE
  },
  /* PID26 Used */
  {
    TRUE
  },
  /* PID27 Used */
  {
    TRUE
  },
  /* PID28 Used */
  {
    TRUE
  },
  /* PID29 Used */
  {
    TRUE
  },
  /* PID30 Used */
  {
    TRUE
  },
  /* PID31 Used */
  {
    TRUE
  },
  /* PID32 Used */
  {
    TRUE
  },
  /* PID33 Used */
  {
    TRUE
  },
  /* PID34 Used */
  {
    TRUE
  },
  /* PID35 Used */
  {
    TRUE
  },
  /* PID36 Used */
  {
    TRUE
  }
};


/* !Deviation : inhibit MISRA rule [3132]: The automated configuration tool  */ 
/*              writes the array size directly in files. no manual editing in*/
/*              files required.                                              */
/* PRQA S 3132 L1 */
static CONST(Dcm_DslProtocolRxType,DCM_CFG_CONST) akstrProtocolRx[4] =
/* PRQA L:L1 */
{
  {
    /*u8DcmDslProtocolIndex*/
    0,
    /*u8DcmDslProtocolRxAddrType*/
    DCM_PHYS_ADDR,
    /*u16DcmDslProtocolRxTesterSourceAddr*/
    0,
    /*u8DcmDslProtocolRxChannelId*/
    0,
    /*u8DcmDslConnectionRef*/
    0,
        
    /*udtDcmDslProtocolTxPduRef*/
    0
  },
  {
    /*u8DcmDslProtocolIndex*/
    0,
    /*u8DcmDslProtocolRxAddrType*/
    DCM_FUNC_ADDR,
    /*u16DcmDslProtocolRxTesterSourceAddr*/
    1,
    /*u8DcmDslProtocolRxChannelId*/
    1,
    /*u8DcmDslConnectionRef*/
    0,
        
    /*udtDcmDslProtocolTxPduRef*/
    0
  },
  {
    /*u8DcmDslProtocolIndex*/
    1,
    /*u8DcmDslProtocolRxAddrType*/
    DCM_PHYS_ADDR,
    /*u16DcmDslProtocolRxTesterSourceAddr*/
    2,
    /*u8DcmDslProtocolRxChannelId*/
    2,
    /*u8DcmDslConnectionRef*/
    1,
        
    /*udtDcmDslProtocolTxPduRef*/
    1
  },
  {
    /*u8DcmDslProtocolIndex*/
    1,
    /*u8DcmDslProtocolRxAddrType*/
    DCM_FUNC_ADDR,
    /*u16DcmDslProtocolRxTesterSourceAddr*/
    3,
    /*u8DcmDslProtocolRxChannelId*/
    3,
    /*u8DcmDslConnectionRef*/
    1,
        
    /*udtDcmDslProtocolTxPduRef*/
    1
  }
};

static CONST(Dcm_DslProtocolTxType,DCM_CFG_CONST) akstrProtocolTx[2] =
{
  {
    /*udtDcmDslProtocolTxPduRef*/
    0,
    /*u8DcmDslProtocolIndex*/
    0,
    /*u8DcmDslTxPduType*/
    DCM_MAIN_PROTOCOL_MSGS
  },
  {
    /*udtDcmDslProtocolTxPduRef*/
    1,
    /*u8DcmDslProtocolIndex*/
    1,
    /*u8DcmDslTxPduType*/
    DCM_MAIN_PROTOCOL_MSGS
  }
};

static CONST(Dcm_DslConnectionType,DCM_CFG_CONST) akstrConnection[2] =
{
  {
    /*pkstrDcmDslMainConnection*/
    NULL_PTR,
    /*pkstrDcmDslPeriodicTransmission*/
    NULL_PTR,
    /*pkstrDcmDslResponseOnEvent*/
    NULL_PTR
  },
  {
    /*pkstrDcmDslMainConnection*/
    NULL_PTR,
    /*pkstrDcmDslPeriodicTransmission*/
    NULL_PTR,
    /*pkstrDcmDslResponseOnEvent*/
    NULL_PTR
  }
};


static CONST(Dcm_tpkstrDslConnectionType,DCM_CFG_CONST) akpkstrDcmDslProtocolRowUDSConn[1] =
{

  &akstrConnection[0]

};


static CONST(Dcm_tpkstrDslConnectionType,DCM_CFG_CONST) akpkstrDcmDslProtocolRowOBDConn[1] =
{

  &akstrConnection[1]

};


        
static CONST(Dcm_PbDslProtocolRowType,DCM_CFG_CONST) akstrProtocolRow[2] =
{
  {
    /*u8DcmDslProtocolID*/
    DCM_UDS_ON_CAN,
    /*u16DcmDslProtocolPreemptTimeout*/
    
    (uint16)(1000/DCM_TASK_TIME_IN_MS),
    /*u8DcmDslProtocolPriority*/
    1,
    /*u8DcmDslProtocolTransType*/
    DCM_PROTOCOL_TYPE1,
    /*u8DcmDslProtocolRxBufferID*/
    0,
    /*u8DcmDslProtocolTxBufferID*/
    1,
    /*u8DcmDslProtocolSIDTable*/
    0,
    /*ppkstrDcmDslConnection*/
    &akpkstrDcmDslProtocolRowUDSConn[0],
    /* u8NumOfConnec */
    1,
    /* u16DcmTimStrP2ServerAdjust */
    (uint16)(0/DCM_TASK_TIME_IN_MS),
    /* u16DcmTimStrP2StarServerAdjust */
    
    (uint16)(0/DCM_TASK_TIME_IN_MS)
  },
  {
    /*u8DcmDslProtocolID*/
    DCM_OBD_ON_CAN,
    /*u16DcmDslProtocolPreemptTimeout*/
    
    (uint16)(1000/DCM_TASK_TIME_IN_MS),
    /*u8DcmDslProtocolPriority*/
    0,
    /*u8DcmDslProtocolTransType*/
    DCM_PROTOCOL_TYPE1,
    /*u8DcmDslProtocolRxBufferID*/
    0,
    /*u8DcmDslProtocolTxBufferID*/
    1,
    /*u8DcmDslProtocolSIDTable*/
    1,
    /*ppkstrDcmDslConnection*/
    &akpkstrDcmDslProtocolRowOBDConn[0],
    /* u8NumOfConnec */
    1,
    /* u16DcmTimStrP2ServerAdjust */
    (uint16)(0/DCM_TASK_TIME_IN_MS),
    /* u16DcmTimStrP2StarServerAdjust */
    
    (uint16)(0/DCM_TASK_TIME_IN_MS)
  }
};


CONST(Dcm_PbDspRoutineType,DCM_APPL_CONST) akstrPbRoutines[DCM_u8NUM_OF_ROUTINES] =
{
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  },
  {
    TRUE
  }
};



CONST(Dcm_ConfigType,DCM_CFG_CONST) Dcm_kstrPbConfig =
{
  /*pkstrPbDcmDslConfig*/
  {

    /*u8DcmDslDiagRespMaxNumRespPend*/
    
    0xFF,
    /*u8DcmDslNumProtocolRow*/
    2,
    /*u8DcmDslNumProtocolRx*/
    4,
    /*u8DcmDslNumProtocolTx*/
    2,
    akstrProtocolRow,
    akstrProtocolRx,
    akstrProtocolTx
  },
  /*pkstrPbDcmDspConfig*/
  {
    /*pkstrDcmDspDid*/
    akstrPbDspDid,
    /*u8NumOfDids*/
    282,
    /*pkstrDcmDspPid*/
    akstrPbDspPid,
    /*u8NumOfPids*/
    36,
    akstrPbRoutines
    
  }
};


#define DCM_STOP_SEC_CALIB_UNSPECIFIED
/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#include "MemMap.h"
/* PRQA L:L1 */

/* !Deviation : Inhibit MISRA rule [0862]: This is the way MemMap is used     */
/* PRQA S 0862 L1 */

/* PRQA L:L1 */
