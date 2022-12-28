/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : Precise Teeth Measurement HAL Service Layer             */
/*                                                                            */
/* !File            : PTMHAL_I.h                                              */
/* !Description     : Contains internal macro functions and defines of the    */
/*                    PTMHAL component                                        */
/*                                                                            */
/* !Reference       : V03 NT 11 07330 / 02                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A149684.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PTMHAL_I_H
#define PTMHAL_I_H

#include "Std_Types.h"
#include "Std_Limits.h"
#include "PTMHAL_L.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define PTMHAL_START_SEC_CALIB_16BIT
#include "PTMHAL_MemMap.h"

extern const uint16 PTMHAL_kau16AlarmAngle[PTMHAL_u8MAX_ALARM_NB_PER_CYCLE];

#define PTMHAL_STOP_SEC_CALIB_16BIT
#include "PTMHAL_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define PTMHAL_START_SEC_VAR_CLEARED_32BIT
#include "PTMHAL_MemMap.h"

/* !MComment: declaration of PTMHAL_au32DurationPack in PTMHAL_Def.c file  */
/*            because if the size is 1 the dico will generate it as a      */
/*            variable not an array                                        */
extern VAR(uint32, PTMHAL_VAR) PTMHAL_au32DurationPack[PTMHAL_u8MAX_NB_PACKS];

#define PTMHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "PTMHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PTMHAL_START_SEC_CODE
#include "PTMHAL_MemMap.h"

void PTMHAL_vidGeneralInitialization(void);

#ifdef PTMHAL_bPSA_3CYL_CFG_EN
void PTMHAL_vidPSA3CylCfgManager(void);
#endif

#ifdef PTMHAL_bPSA_4CYL_CFG1_EN
void PTMHAL_vidPSA4CylCfg1Manager(void);
#endif

#ifdef PTMHAL_bPSA_4CYL_CFG2_EN
void PTMHAL_vidPSA4CylCfg2Manager(void);
#endif

#ifdef PTMHAL_bEVLV_CFG_EN
void PTMHAL_vidEvlvCfgManager(void);
#endif

#ifdef PTMHAL_bRSA_3CYL_CFG_EN
void PTMHAL_vidRSA3CylCfgManager(uint8 u8PackDurationCalc);
#endif

#define PTMHAL_STOP_SEC_CODE
#include "PTMHAL_MemMap.h"


#endif /* PTMHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
