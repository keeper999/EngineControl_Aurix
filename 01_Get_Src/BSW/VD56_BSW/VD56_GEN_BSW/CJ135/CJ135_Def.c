/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Def.c                                                                                     */
/* !Description     : Data declaration                                                                                */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A188659.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "CJ135_Private.h"
#include "CJ135_Types.h"

/**********************************************************************************************************************/
/* CALIBRATIONS                                                                                                       */
/**********************************************************************************************************************/

#define CJ135_START_SEC_CALIB_16BIT
#include "CJ135_MemMap.h"

const uint16 CJ135_ku16RegConfigDsp = 0;
const uint16 CJ135_ku16RegIpOff = 0;
const uint16 CJ135_ku16RegMode = 0;
const uint16 CJ135_ku16RegRefpat = 0;
const uint16 CJ135_ku16RegSteerpat = 0;
const uint16 CJ135_ku16RegTrim = 0;
const uint16 CJ135_ku16RegUnset = 0;
const uint16 CJ135_ku16RegUego0 = 0;
const uint16 CJ135_ku16RegUego1 = 0;
const uint16 CJ135_ku16RegUego2 = 0;
const uint16 CJ135_ku16RegUego3 = 0;
const uint16 CJ135_ku16RegUego4 = 0;
const uint16 CJ135_ku16RegUego5 = 0;
const uint16 CJ135_ku16RegUp0lean = 0;
const uint16 CJ135_ku16RegUp0rich = 0;
const uint16 CJ135_ku16RegFree = 0;

#define CJ135_STOP_SEC_CALIB_16BIT
#include "CJ135_MemMap.h"

/**********************************************************************************************************************/
/* VARIABLES                                                                                                          */
/**********************************************************************************************************************/
#define CJ135_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CJ135_MemMap.h"

CJ135_strData CJ135_astrData[CJ135_u8NB_OF_DEVICE];

#define CJ135_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
