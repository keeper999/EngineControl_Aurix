/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PTMHAL                                                  */
/* !Description     : Precise Teeth Measurement HAL Service Layer             */
/*                                                                            */
/* !File            : PTMHAL_Def.c                                            */
/* !Description     : Data definition of the PTMHAL component                 */
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
 * %PID: P2017_BSW:0A149682.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "PTMHAL_L.h"


/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/

#define PTMHAL_START_SEC_CALIB_16BIT
#include "PTMHAL_MemMap.h"

const uint16 PTMHAL_kau16AlarmAngle[PTMHAL_u8MAX_ALARM_NB_PER_CYCLE] =
{
   0
};

#define PTMHAL_STOP_SEC_CALIB_16BIT
#include "PTMHAL_MemMap.h"


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define PTMHAL_START_SEC_VAR_CLEARED_32BIT
#include "PTMHAL_MemMap.h"

/* !MComment: definition of PTMHAL_au32DurationPack in PTMHAL_Def.c file   */
/*            because if the size is 1 the dico will generate it as a      */
/*            variable not an array                                        */

VAR(uint32, PTMHAL_VAR) PTMHAL_au32DurationPack[PTMHAL_u8MAX_NB_PACKS];

#define PTMHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "PTMHAL_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
