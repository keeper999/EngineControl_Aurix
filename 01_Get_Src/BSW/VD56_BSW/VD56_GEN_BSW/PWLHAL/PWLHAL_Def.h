/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_Def.h                                            */
/* !Description     : Data declaration of the PWLHAL component                */
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
 * %PID: P2017_BSW:A11987.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PWLHAL_DEF_H
#define PWLHAL_DEF_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define PWLHAL_u16ONE_SECOND          100      /* 100 * 10ms = 1s */

/* !Comment: PWLHAL_u8MainRlyCutReq states                                    */
#define PWLHAL_u8PWDWN_NO_CUT_REQ     1
#define PWLHAL_u8PWDWN_CUT_REQ        2

/* !Comment: PWLHAL_enuEcuPowerState states                                   */
#define PWLHAL_MAIN_RLY_CUT_OFF_DELAY 0
#define PWLHAL_ECU_POWER_ON           1
#define PWLHAL_ECU_POWER_DOWN         2
#define PWLHAL_ACTR_CUT_OFF_DELAY     4


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define PWLHAL_START_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

extern uint8 PWLHAL_u8MainRlyCutReq;

#define PWLHAL_STOP_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_16BIT
#include "PWLHAL_MemMap.h"

extern uint16 PWLHAL_u16ShutdownCnt;

#define PWLHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

extern uint8 PWLHAL_enuEcuPowerState;

#define PWLHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "PWLHAL_MemMap.h"

extern boolean PWLHAL_bIgnitionKeyAtReset;

#define PWLHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "PWLHAL_MemMap.h"


/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define PWLHAL_START_SEC_CALIB_16BIT
#include "PWLHAL_MemMap.h"

extern const uint16 PWLHAL_ku16ActRlyShutdownDly;
extern const uint16 PWLHAL_ku16ShutdownDly;

#define PWLHAL_STOP_SEC_CALIB_16BIT
#include "PWLHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

extern void PWLHAL_vidPowerDownManagement(void);

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"


#endif /* PWLHAL_DEF_H */

/*-------------------------------- end of file -------------------------------*/
