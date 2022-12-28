/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_Def.c                                            */
/* !Description     : Data definition of the PWLHAL component                 */
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
 * %PID: P2017_BSW:A11985.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "PWLHAL_Def.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define PWLHAL_START_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

uint8 PWLHAL_u8MainRlyCutReq;

#define PWLHAL_STOP_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_16BIT
#include "PWLHAL_MemMap.h"

uint16  PWLHAL_u16ShutdownCnt;

#define PWLHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

uint8   PWLHAL_enuEcuPowerState;

#define PWLHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "PWLHAL_MemMap.h"

#define PWLHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "PWLHAL_MemMap.h"

boolean PWLHAL_bIgnitionKeyAtReset;

#define PWLHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "PWLHAL_MemMap.h"


/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/

#define PWLHAL_START_SEC_CALIB_16BIT
#include "PWLHAL_MemMap.h"

const uint16 PWLHAL_ku16ActRlyShutdownDly;
const uint16 PWLHAL_ku16ShutdownDly;

#define PWLHAL_STOP_SEC_CALIB_16BIT
#include "PWLHAL_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
