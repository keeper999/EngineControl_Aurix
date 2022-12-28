/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SECUBV                                                   */
/*                                                                            */
/* !Module         : SECUBV                                                   */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : SECUBV.C75                                               */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV.c7v     $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SECUBV.h"
#include "SECUBV_l.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bActDftDeltaTqIPos_C = 0;
const boolean  SftyMgt_bInhCluNotOp_C = 0;
const boolean  SftyMgt_bInhDgoDeltaTq_C = 0;
const boolean  SftyMgt_bInhDgoDeltaTqI_C = 0;
const boolean  SftyMgt_bInhDgoSIPFRM_C = 0;
const boolean  SftyMgt_bInhDgoSIPInvld_C = 0;
const boolean  SftyMgt_bInhDgoSIPNotIp_C = 0;
const boolean  SftyMgt_bInhDgoSIPORng_C = 0;
const boolean  SftyMgt_bInhNbTarGearDeltaTqI_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SECUBV_u8Inhib = 0;
const uint8  SftyMgt_noTraTypAL4_C = 0;
const uint8  SftyMgt_noTraTypAM6_C = 0;
const uint8  SftyMgt_noTraTypMAP_C = 0;
const uint8  SftyMgt_noTraTypMCP_C = 0;
const uint8  SftyMgt_spdDftDeltaTq_A[SFTYMGT_SPDDFTDELTATQ_A_COLS] = {0};
const uint8  SftyMgt_spdDftTqI_A[SFTYMGT_SPDDFTTQI_A_COLS] = {0};
const uint8  SftyMgt_tiDlyOnDgoDeltaTq_C = 0;
const uint8  SftyMgt_tiDlyOnDgoDeltaTqI_C = 0;
const uint8  SftyMgt_tiDlyOnDgoSIPNotIp_C = 0;
const uint8  SftyMgt_tiDlyOnDgoTqGBx_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqOfsGbxSIPNotIp_C = 0;
const sint16  SftyMgt_tqtiDftDeltaTqIMax_C = 0;
const sint16  SftyMgt_tqtiDftDeltaTqIMin_C = 0;
const uint16  SftyMgt_tiMaxGearBxIntv_C = 0;
const uint16  SftyMgt_tqDeltaTq_T[SFTYMGT_TQDELTATQ_T_COLS] = {0};
const uint16  SftyMgt_tqTiDftTqI_T[SFTYMGT_TQTIDFTTQI_T_COLS] = {0};
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean SECUBV_bEnaDftDeltaTqIRunPrev;
boolean SECUBV_bEnaSIPCntRun_Prev;
boolean SftyMgt_bDeac0TqGBx;
boolean SftyMgt_bDeac0TqGBxATAMTCf;
boolean SftyMgt_bDeac0TqGBxMTCf;
boolean SftyMgt_bDftDeltaTq;
boolean SftyMgt_bDftDeltaTqI;
boolean SftyMgt_bDftSIPFRM;
boolean SftyMgt_bDftSIPInvld;
boolean SftyMgt_bDftSIPORng;
boolean SftyMgt_bDgoDeltaTq;
boolean SftyMgt_bDgoDeltaTqCord;
boolean SftyMgt_bDgoDeltaTqCordAL4;
boolean SftyMgt_bDgoDeltaTqCordNotAL4;
boolean SftyMgt_bDgoDeltaTqI;
boolean SftyMgt_bDgoSIPCord;
boolean SftyMgt_bDgoSIPNotIp;
boolean SftyMgt_bDgoTqGBx;
boolean SftyMgt_bDgoTqGBxATAMTCf;
boolean SftyMgt_bDgoTqGBxMTCf;
boolean SftyMgt_bEnaAL4;
boolean SftyMgt_bEnaATAMTCf;
boolean SftyMgt_bEnaDftDeltaTqIRst;
boolean SftyMgt_bEnaDftDeltaTqIRun;
boolean SftyMgt_bEnaMTCf;
boolean SftyMgt_bEnaNbTarGearChgSIPRst;
boolean SftyMgt_bEnaNbTarGearChgSIPRun;
boolean SftyMgt_bEnaNbTarGearChgTqIRst;
boolean SftyMgt_bEnaNbTarGearChgTqIRun;
boolean SftyMgt_bEnaNotAL4;
boolean SftyMgt_bEnaNRegReqChgSIPRst;
boolean SftyMgt_bEnaNRegReqChgSIPRun;
boolean SftyMgt_bEnaSIPCntRst;
boolean SftyMgt_bEnaSIPCntRun;
boolean SftyMgt_bInhSIPCord_MP;
boolean SftyMgt_bNbTarGearChgSIP;
boolean SftyMgt_bNbTarGearChgSIPRst;
boolean SftyMgt_bNbTarGearChgSIPRun;
boolean SftyMgt_bNbTarGearChgTqI;
boolean SftyMgt_bNbTarGearChgTqIRst;
boolean SftyMgt_bNbTarGearChgTqIRun;
boolean SftyMgt_bNRegReqChgSIP;
boolean SftyMgt_bNRegReqChgSIPRst;
boolean SftyMgt_bNRegReqChgSIPRun;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 SECUBV_u8SftyMgt_bDgoSIPNotIpCnt;
uint8 SECUBV_u8tiDlyOnDgoDeltaTq_Cnt;
uint8 SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqTiDeltaTqI;
sint16 SftyMgt_tqTiDeltaTqIRst;
sint16 SftyMgt_tqTiDeltaTqIRun;
uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt;
uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1;
uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2;
uint16 SftyMgt_tiSIPCnt;
uint16 SftyMgt_tiSIPCntRst;
uint16 SftyMgt_tiSIPCntRun;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

