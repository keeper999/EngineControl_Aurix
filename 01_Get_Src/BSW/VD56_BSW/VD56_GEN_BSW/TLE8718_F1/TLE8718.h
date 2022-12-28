/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718.h                                                                                       */
/* !Description     : Public definitions of TLE8718 Component                                                         */
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
 * %PID: P2017_BSW:0A133933.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_H
#define TLE8718_H

#include "Std_Types.h"

#include "HOD.h"
#include "TLE8718_Cfg_E.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* !MComment: TLE8718 Channels ID */
#define TLE8718_udtOUT_1                 0u
#define TLE8718_udtOUT_2                 1u 
#define TLE8718_udtOUT_3                 2u 
#define TLE8718_udtOUT_4                 3u 
#define TLE8718_udtOUT_5                 4u 
#define TLE8718_udtOUT_6                 5u 
#define TLE8718_udtOUT_7                 6u 
#define TLE8718_udtOUT_8                 7u 
#define TLE8718_udtOUT_9                 8u 
#define TLE8718_udtOUT_10                9u 
#define TLE8718_udtOUT_11                10u
#define TLE8718_udtOUT_12                11u
#define TLE8718_udtOUT_13                12u
#define TLE8718_udtOUT_14                13u
#define TLE8718_udtOUT_15                14u
#define TLE8718_udtOUT_16                15u
#define TLE8718_udtOUT_17                16u
#define TLE8718_udtOUT_18                17u

/**********************************************************************************************************************/
/* APIs DECLARATION                                                                                                   */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

void TLE8718_vidInit(void);
void TLE8718_vidEnable(HOD_tudtInstance udtInstance);
void TLE8718_vidEnableCmd(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, HOD_tenuCutMode  enuCutMode);
void TLE8718_vidDisableCmd(HOD_tudtInstance udtInstance,
                           HOD_tudtChannel udtChannel,
                           HOD_tenuCutMode  enuCutMode);
boolean TLE8718_bDioRead(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel);
void TLE8718_vidDioWrite(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, boolean bState);
void TLE8718_vidPwmWriteDutyCycle(HOD_tudtInstance udtInstance,
                                  HOD_tudtChannel udtChannel,
                                  HOD_tudtDutyCycle udtDutyCycle);
void TLE8718_vidPwmWritePeriodAndDuty(HOD_tudtInstance udtInstance,
                                      HOD_tudtChannel udtChannel,
                                      HOD_tudtPeriod udtPeriod,
                                      HOD_tudtDutyCycle udtDutyCycle);
void TLE8718_vidPwmSetOutputToIdle(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel);
void TLE8718_vidCpxOutStateChangeHook(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, boolean bState);
Std_ReturnType TLE8718_udtGetComponentVersion(HOD_tudtInstance udtInstance, uint8 *pu8Tle8718HwVersion);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
