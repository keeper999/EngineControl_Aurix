/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : INJHAL Component                                        */
/*                                                                            */
/* !File            : INJHAL.h                                                */
/* !Description     : Data Definition of INJHAL Component                     */
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
 * %PID: P2017_BSW:A26587.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef INJHAL_H
#define INJHAL_H

#include "Std_Types.h"
#include "INJHAL_Cfg_E.h"
#include "INJHAL_TYP.h"
#include "TYPE.h"

#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"
#include "IfxGtm_Typ.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define INJHAL_bfENABLE_ALL_INJ           0u    /* 0x00 */
#define INJHAL_bfINHIB_ALL_INJ            255u  /* 0xFF */
#define INJHAL_bfSEQ_PRE_INJ_DONE         2u    /* 0x02 */
#define INJHAL_bfSEQ_PRE_INJ_NOT_DONE     0u    /* 0x00 */
#define INJHAL_bfSEQ_PRE_INJ_RUNNING      1u    /* 0x01 */
#define INJHAL_enuPREINJ_ACT              1u    /* 0x01 */
#define INJHAL_enuPREINJ_END              2u    /* 0x02 */
#define INJHAL_enuPREINJ_NONE             0u    /* 0x00 */
#define INJHAL_u8ALL_CYLINDERS            255u  /* 255 */


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/
/* enum st10A */
#define INJHAL_enuCOMP_INIT               1u
#define INJHAL_enuCOMP_BEFORE_PRE_INJ     2u
#define INJHAL_enuCOMP_FG_PRE_INJ         4u
#define INJHAL_enuCOMP_SEQ_PRE_INJ        8u
#define INJHAL_enuCOMP_WAITING_SYNCHRO    16u
#define INJHAL_enuCOMP_SEQ_INJ            32u
/* extern uint8 INJHAL_aenuInjComponentStatus; */

/* enum st10B */
#define INJHAL_enuINJ_MODE_INIT           1u
#define INJHAL_enuINJ_MODE_NORMAL         2u
#define INJHAL_enuINJ_MODE_PREINJ_SEQ     4u
#define INJHAL_enuINJ_MODE_DISABLED       8u
/* extern uint8 INJHAL_aenuInjectorMode; */


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

INJHAL_tbfSeqPreInjStatus INJHAL_bfReadSeqPreInjStatus(uint8 u8InstanceId);
INJHAL_tbfUpdateStatus    INJHAL_bfUpdate(uint8 u8InstanceId);
boolean                   INJHAL_bInjectionStarted(uint8 u8InstanceId);
INJHAL_tenuFGPreInjStatus INJHAL_enuReadFGPreInjStatus(uint8 u8InstanceId);

void INJHAL_GtmEnable(void);
void INJHAL_GtmDisable(void);
void INJHAL_vidCancelInjGroupAlarms(uint8 u8InstanceId);
void INJHAL_vidCrkSyncFoundEntry(uint8 u8InstanceId);
void INJHAL_vidCrkSyncLostEntry(uint8 u8InstanceId);
void INJHAL_vidDisable(uint8 u8InstanceId);
void INJHAL_vidDisableFGPreInj(uint8 u8InstanceId);
void INJHAL_vidDisableSeqPreInj(uint8 u8InstanceId);
void INJHAL_vidEnable(uint8 u8InstanceId);
void INJHAL_vidEnableFG (uint32 u32FGAngle);
void INJHAL_vidEnableFGImmediate (void);
void INJHAL_vidEnableFGPreInj(uint8 u8InstanceId);
void INJHAL_vidEnableSeqPreInj(uint8 u8InstanceId);
void INJHAL_vidGtmInit(void);
void INJHAL_vidInhibit(uint8 u8InstanceId, INJHAL_tbfInhibitMask bfInhibitMask);
void INJHAL_vidInit(void);
void INJHAL_vidResetInjectionStarted(uint8 u8InstanceId);
void INJHAL_vidTestModeEntry(void);
void INJHAL_vidTestModeExit(void);
void INJHAL_vidWriteAngle(uint8  u8Channel,
                          uint8  u8PulseNumber,
                          uint16 u16InjectionAngle);
void INJHAL_vidWriteAngleBeforePreInj(uint8  u8InstanceId,
                                      uint16 u16InjectionAngle);
void INJHAL_vidWriteFGPreInjTime(uint8 u8InstanceId, uint32 u32InjectionTime);
void INJHAL_vidWriteMode(uint8 u8InstanceId,
                         uint8 u8Channel,
                         uint8 u8InjectionMode);
void INJHAL_vidWriteSeqPreInjAngle(uint8  u8InstanceId,
                                   uint8  u8Channel,
                                   uint16 u16InjectionAngle);
void INJHAL_vidWriteSeqPreInjTime(uint8 u8InstanceId,
                                  uint8 u8Channel,
                                  uint32 u32InjectionTime);
void INJHAL_vidWriteTime(uint8 u8Channel,
                         uint8 u8PulseNumber,
                         uint32 u32InjectionTime);
void INJHAL_vidWriteTestTime(uint8 u8Channel, uint32 u32InjTestTime);

Std_ReturnType INJHAL_udtGetFGPreInjEndAngle(uint8 u8InstanceId,
                                             uint16 *pu16FGPreInjEndAngle);
Std_ReturnType INJHAL_udtGetFGPreInjStartAngle(uint8 u8InstanceId,
                                               uint16 *pu16FGPreInjStartAngle);
Std_ReturnType INJHAL_udtSwitchGdiProfile(uint8 u8InstanceId,
                                          uint8 u8GdiProfileId);
Std_ReturnType INJHAL_udtStopGdiHw(uint8 u8InstanceId);
Std_ReturnType INJHAL_udtRestartGdiHw(uint8 u8InstanceId);

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

#endif /* INJHAL_H */

/*-------------------------------- end of file -------------------------------*/
