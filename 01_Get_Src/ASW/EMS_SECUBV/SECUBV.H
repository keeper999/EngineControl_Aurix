/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SECUBV                                                   */
/*                                                                            */
/* !Module         : SECUBV                                                   */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : SECUBV.H                                                 */
/*                                                                            */
/* !Scope          : Public                                                   */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV.H_v     $*/
/* $Revision::   1.3      $$Author::   MBENFRAD       $$Date::   Oct 20 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SECUBV_H
#define SECUBV_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_SPDDFTDELTATQ_A_COLS           (6)
#define SFTYMGT_SPDDFTTQI_A_COLS               (6)
#define SFTYMGT_TQDELTATQ_T_COLS               (6)
#define SFTYMGT_TQTIDFTTQI_T_COLS              (6)

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
extern const boolean  SftyMgt_bActDftDeltaTqIPos_C;
extern const boolean  SftyMgt_bInhCluNotOp_C;
extern const boolean  SftyMgt_bInhDgoDeltaTq_C;
extern const boolean  SftyMgt_bInhDgoDeltaTqI_C;
extern const boolean  SftyMgt_bInhDgoSIPFRM_C;
extern const boolean  SftyMgt_bInhDgoSIPInvld_C;
extern const boolean  SftyMgt_bInhDgoSIPNotIp_C;
extern const boolean  SftyMgt_bInhDgoSIPORng_C;
extern const boolean  SftyMgt_bInhNbTarGearDeltaTqI_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_noTraTypAL4_C;
extern const uint8  SftyMgt_noTraTypAM6_C;
extern const uint8  SftyMgt_noTraTypMAP_C;
extern const uint8  SftyMgt_noTraTypMCP_C;
extern const uint8  SftyMgt_spdDftDeltaTq_A[SFTYMGT_SPDDFTDELTATQ_A_COLS];
extern const uint8  SftyMgt_spdDftTqI_A[SFTYMGT_SPDDFTTQI_A_COLS];
extern const uint8  SftyMgt_tiDlyOnDgoDeltaTq_C;
extern const uint8  SftyMgt_tiDlyOnDgoDeltaTqI_C;
extern const uint8  SftyMgt_tiDlyOnDgoSIPNotIp_C;
extern const uint8  SftyMgt_tiDlyOnDgoTqGBx_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqOfsGbxSIPNotIp_C;
extern const sint16  SftyMgt_tqtiDftDeltaTqIMax_C;
extern const sint16  SftyMgt_tqtiDftDeltaTqIMin_C;
extern const uint16  SftyMgt_tiMaxGearBxIntv_C;
extern const uint16  SftyMgt_tqDeltaTq_T[SFTYMGT_TQDELTATQ_T_COLS];
extern const uint16  SftyMgt_tqTiDftTqI_T[SFTYMGT_TQTIDFTTQI_T_COLS];
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
extern boolean SftyMgt_bDeac0TqGBx;
extern boolean SftyMgt_bDgoTqGBx;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SECUBV_vidEntryInit(void);
void SftyMgt_Sdl40ms_GBxChk(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* SECUBV_H */

/*-------------------------------- end of file -------------------------------*/
