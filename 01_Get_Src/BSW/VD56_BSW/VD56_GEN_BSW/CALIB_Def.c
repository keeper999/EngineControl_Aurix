/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : CALIB                                                   */
/* !Description     : Calibration management                                  */
/*                                                                            */
/* !File            : CALIB_Def.c                                             */
/* !Description     : Contains the first and the last calibration             */
/*                    in CALIB section                                        */
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
 * %PID: P2017_BSW:0A192418.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#define CALIB_START_SEC_CALIB_BEG
#include "CALIB_MemMap.h"

const uint16 Calibration_debut = 0;

#define CALIB_STOP_SEC_CALIB_BEG
#include "CALIB_MemMap.h"

#define CALIB_START_SEC_CALIB_END
#include "CALIB_MemMap.h"

const uint16 Calibration_fin = 0;

#define CALIB_STOP_SEC_CALIB_END
#include "CALIB_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
